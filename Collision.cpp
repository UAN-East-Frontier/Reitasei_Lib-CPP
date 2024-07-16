#include "Collision.h"
#include <string.h>

std::map<std::string, std::vector<Collision*>> Collision::groupsCollisions; //Contains arrays groups collisions
std::map<std::string, std::string>  Collision::dictionaryCollisions; //Contains keys names groups collisions

uint32_t Collision::count;

bool Collision::operator==(const Collision& other) const
{
    return id == other.id;
}

void Collision::initCollision()
{
    shape->setFillColor(sf::Color::Transparent);
    shape->setOutlineThickness(1.f);
    shape->setOutlineColor(sf::Color::Red);
    id = ++count;
    group["Default"] = true;
    setName("Default");
}

Collision::Collision(sf::Vector2f size)
{
    shape = new sf::RectangleShape(size);
    initCollision();
}

Collision::Collision(sf::Sprite sprite) {
    sf::FloatRect rect = sprite.getGlobalBounds();
    shape = new sf::RectangleShape(sf::Vector2f(rect.width, rect.height));
    shape->setPosition(sprite.getPosition());
    initCollision();
}

Collision::Collision(sf::Sprite sprite, sf::FloatRect rect) {
    shape = new sf::RectangleShape(sf::Vector2f(rect.width, rect.height));
    shape->setPosition(sprite.getPosition());
    initCollision();
}



Collision::~Collision()
{
    delete shape;
    removeElementGroup(name);
}

void  Collision::setName(std::string newName) {
    std::string oldName = name;
    name = newName;
    removeElementGroup(oldName);
    group.erase(oldName);
    if (groupsCollisions.count(name) == 0)
        groupsCollisions[name] = std::vector<Collision*>();
    groupsCollisions[name].push_back(this);
}

void Collision::removeElementGroup(std::string name) {
    if (groupsCollisions.count(name) == 1) {
        auto iter = groupsCollisions[name].begin();
        while (iter != groupsCollisions[name].end()) {
            auto& col = *iter;
            if (this == col) {
                iter = groupsCollisions[name].erase(iter);
                break;
            }
            ++iter;
        }
        if (groupsCollisions[name].size() == 0)
            groupsCollisions.erase(name);
    }
}

std::string  Collision::getName() {
    return name;
}

void Collision::disableGroup(std::string groupName) {
    group[groupName] = false;
    auto* collisions = &groupsCollisions[name];
    for (size_t i = 0; i < (*collisions).size(); ++i) {
        if (this == (*collisions)[i]) {
            (*collisions)[i]->group[groupName] = false;
            return;
        }
    }

}

bool Collision::isIntersect(Collision& otherCol) {
    sf::FloatRect boundsA = this->shape->getGlobalBounds();
    sf::FloatRect boundsB = otherCol.shape->getGlobalBounds();
    return boundsA.intersects(boundsB);
}

uint32_t  Collision::getId() {
    return id;
}

void  Collision::setPosition(sf::Vector2f pos) {
    shape->setPosition(pos);
}

sf::Vector2f Collision::getPosition()
{
    return shape->getPosition();
}

void Collision::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(*shape, states);
}


void Collision::callCollisionFunc(Collision& col1)
{
    if (this->callbackCollision.has_value()) {
        this->callbackCollision.value() (col1);
    }
}

void Collision::touchedCollisison(std::string name, std::string touchName) {
    if (groupsCollisions.count(name) == 1) {
        if (groupsCollisions.count(touchName) == 1) {
            dictionaryCollisions[name + "_" + touchName] = touchName;
            for (size_t i = 0; i < groupsCollisions[name].size(); ++i) {
                groupsCollisions[name][i]->group[touchName] = true;
            }
        }
        else std::cout << "Group collision " << touchName << " not exists!" << std::endl;
    }
    else std::cout << "Group collision " << name << " not exists!" << std::endl;
}

void Collision::unTouchedCollisison(std::string name, std::string touchName) {
    if (groupsCollisions.count(name) == 1) {
        dictionaryCollisions.erase(name);
        for (size_t i = 0; i < groupsCollisions[name].size(); ++i) {
            groupsCollisions[name][i]->group.erase(touchName);
        }
    }
}

void Collision::collisionsEvents() {
    for (auto& element : dictionaryCollisions) {
        size_t pos = 0;
        std::string token;
        std::string first;
        std::string s = element.first;
        std::string delimiter = "_";
        while ((pos = s.find(delimiter)) != std::string::npos) {
            token = s.substr(0, pos);
            first = token;
            break;
        }
        if (groupsCollisions.count(first) == 0) {
            std::cout << "Group collision " << first << " not exists!" << std::endl;
            continue;;
        }
        if (groupsCollisions.count(element.second) == 0) {
            std::cout << "Group collision " << element.second << " not exists!" << std::endl;
            continue;
        }
        auto* collisions = &groupsCollisions[first];
        auto* touchCollisions = &groupsCollisions[element.second];
        for (size_t i = 0; i < (*collisions).size(); i++) {
            for (size_t j = 0; j < (*touchCollisions).size(); j++) {
                if ((*collisions)[i]->group[(*touchCollisions)[j]->name] == false)
                    continue;
                uint32_t touchId = (*touchCollisions)[j]->id;
                if ((*(*collisions)[i]).isIntersect(*(*touchCollisions)[j])) {
                    if (!(*(*collisions)[i]).isEnter[touchId] && !(*(*collisions)[i]).isStay[touchId])
                        (*(*collisions)[i]).isEnter[touchId] = true;

                    else if (!(*(*collisions)[i]).isStay[touchId]) {
                        (*(*collisions)[i]).isStay[touchId] = true;
                        (*(*collisions)[i]).isEnter[touchId] = false;
                    }

                    (*collisions)[i]->callCollisionFunc(*(*touchCollisions)[j]);
                }
                else {
                    if ((*(*collisions)[i]).isExit[touchId]) {
                        (*(*collisions)[i]).isExit[touchId] = false;
                        (*collisions)[i]->callCollisionFunc(*(*touchCollisions)[j]);
                    }
                    else if ((*(*collisions)[i]).isEnter[touchId] || (*(*collisions)[i]).isStay[touchId]) {
                        (*(*collisions)[i]).isExit[touchId] = true;
                        (*(*collisions)[i]).isStay[touchId] = false;
                        (*(*collisions)[i]).isEnter[touchId] = false;
                        (*collisions)[i]->callCollisionFunc(*(*touchCollisions)[j]);
                    }
                }
            }

        }

    }
}

bool Collision::enterCollision(uint32_t touchId)
{
    return isEnter[touchId];
}

bool Collision::enterCollision(Collision& col)
{
    return isEnter[col.id];
}

bool Collision::stayCollision(uint32_t touchId)
{
    return isStay[touchId];
}

bool Collision::stayCollision(Collision& col)
{
    return isStay[col.id];
}

bool Collision::exitCollision(uint32_t touchId)
{
    return isExit[touchId];
}

bool Collision::exitCollision(Collision& col)
{
    return isExit[col.id];
}

sf::Vector2f Collision::getSize()
{
    return shape->getSize();
}

void Collision::setSize(sf::Vector2f vec)
{
    shape->setSize(vec);
}

void Collision::setCallbackCollision(CallbackCollision callback)
{
    for (auto& arrayPair : groupsCollisions) {
        for (auto& col : arrayPair.second) {
            if (col == this) {
                col->callbackCollision = callback;
                return;
            }
        }
    }
}
