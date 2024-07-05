#include "Collision.h"

std::vector<Collision*> Collision::collisions;

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
    name = "Default";
    collisions.push_back(this);
    std::cout << "Create " << id << std::endl;
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
    auto iter = collisions.begin();
    int index = 0;
    while (iter != collisions.end()) {
        auto& col = *iter;
        if (id == col->id) {
            collisions.erase(iter);
        }
        else {
            ++iter;
            ++index;
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

std::optional<int> Collision::getIndex()
{
    auto iter = collisions.begin();
    int i = 0;
    while (iter != collisions.end()) {
        auto& col = *iter;
        if (id == col->id) {
            return i;
        }
        else {
            ++iter;
            i++;
        }
    }
    return std::nullopt;
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


void Collision::callCollisionFunc(size_t i, size_t j)
{
    if ((*collisions[i]).callbackCollision.has_value()) {
        (*Collision::collisions[i]->callbackCollision)(*Collision::collisions[i], *Collision::collisions[j]);
    }
}

void Collision::collisionsEvents() {
    for (size_t i = 0; i < collisions.size(); ++i) {
        for (size_t j = i + 1; j < collisions.size(); ++j) {
            if ((*collisions[i]).name != (*collisions[j]).name)
                continue;
            if ((*collisions[i]).isIntersect(*collisions[j])) {
                if (!(*collisions[i]).isEnter && !(*collisions[i]).isStay) {  //Make map data type instead bool. It's break logic if will two or more collisions. 
                    (*collisions[i]).isEnter = true;
                }
                else if (!(*collisions[i]).isStay) {
                    (*collisions[i]).isStay = true;
                    (*collisions[i]).isEnter = false;
                }

                (*collisions[i]).callCollisionFunc(i, j);
            }
            else {
                if ((*collisions[i]).isExit) {
                    (*collisions[i]).isExit = false;
                    (*collisions[i]).callCollisionFunc(i, j);
                }
                else if ((*collisions[i]).isEnter || (*collisions[i]).isStay) {
                    (*collisions[i]).isExit = true;
                    (*collisions[i]).isStay = false;
                    (*collisions[i]).isEnter = false;
                    (*collisions[i]).callCollisionFunc(i, j);
                }
            }
        }
    }
}

bool Collision::enterCollision()
{
    return isEnter;
}

bool Collision::stayCollision()
{
    return isStay;
}

bool Collision::exitCollision()
{
    return isExit;
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
    for (int i = 0; i < collisions.size(); i++) {
        if (collisions[i]->id == id) {
            collisions[i]->callbackCollision = callback;
            return;
        }
    }
}

