#include "Collision.h"

std::vector<Collision> Collision::collisions; 
uint32_t Collision::count;

bool Collision::operator==(const Collision& other) const
{
    return id == other.id;
}

void Collision::initCollision()
{
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::Red);
    id = ++count;
    name = "Default";
    collisions.push_back(*this);
}

Collision::Collision(sf::Vector2f size)
{
    shape = sf::RectangleShape(size);
    initCollision();
}

Collision::Collision(sf::Sprite sprite) {
        sf::FloatRect rect = sprite.getGlobalBounds();
        shape = sf::RectangleShape(sf::Vector2f(rect.width, rect.height));
        shape.setPosition(sprite.getPosition());
        initCollision();
    }

Collision::Collision(sf::Sprite sprite, sf::FloatRect rect) {
    shape = sf::RectangleShape(sf::Vector2f(rect.width, rect.height));
    shape.setPosition(sprite.getPosition());
    initCollision();
}

bool Collision::isIntersect(Collision otherCol) {
    return this->shape.getGlobalBounds().intersects(otherCol.shape.getGlobalBounds());
}

uint32_t  Collision::getId() {
    return id;
}

void  Collision::setPosition(sf::Vector2f pos) {
    Range collisionRange(collisions);
    auto index = collisionRange.findIndex(*this);
    if (!index.has_value()) {
        std::cout << "Collision not found!!!" << std::endl;
        return;
    }
    shape.setPosition(pos);
    collisions[index.value()].shape = shape;
}

sf::Vector2f Collision::getPosition()
{
    return shape.getPosition();
}

void Collision::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Collision::setCallbackCollision(CallbackCollision callback)
{
    if (callbackCollision != nullptr) {
        callbackCollision = nullptr;
    }
    Range collisionRange(collisions);
    auto index = collisionRange.findIndex(*this);
    if (!index.has_value()) {
        std::cout << "Collision not found!!!" << std::endl;
        return;
    }
    callbackCollision = std::make_shared<CallbackCollision>(callback);
    collisions[index.value()].callbackCollision = callbackCollision;
}

void Collision::callCollisionFunc(size_t i, size_t j)
{
    std::shared_ptr<Collision> colPtr1{ std::make_shared<Collision>(collisions[i]) };
    std::shared_ptr<Collision> colPtr2{ std::make_shared<Collision>(collisions[j]) };
    CollisionInfo colInfo(colPtr1, colPtr2);
    (*Collision::collisions[i].callbackCollision) ({ colInfo });
}

void Collision::collisionsEvents() {
    for (size_t i = 0; i < collisions.size(); ++i) {
        for (size_t j = i + 1; j < collisions.size(); ++j) {
            if (collisions[i].name != collisions[j].name)
                continue;

            if (collisions[i].isIntersect(collisions[j])) {
                if (!collisions[i].isEnter && !collisions[i].isStay) {  //Make map data type instead bool. It's break logic if will two or more collisions. 
                    collisions[i].isEnter = true;
                }
                else if (!collisions[i].isStay) {
                    collisions[i].isStay = true;
                    collisions[i].isEnter = false;
                }
                if (collisions[i].callbackCollision != nullptr )
                {
                    callCollisionFunc(i, j);
                }
            }
            else {
                if (collisions[i].isExit) {
                    collisions[i].isExit = false;
                    callCollisionFunc(i, j);
                }
                else if (collisions[i].isEnter || collisions[i].isStay) {
                    collisions[i].isExit = true;
                    collisions[i].isStay = false;
                    collisions[i].isEnter = false;
                    callCollisionFunc(i, j);
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
    return shape.getSize();
}

void Collision::setSize(sf::Vector2f vec)
{
    Range collisionRange(collisions);
    auto index = collisionRange.findIndex(*this);
    if (!index.has_value()) {
        std::cout << "Collision not found!!!" << std::endl;
        return;
    }
    shape.setSize(vec);
    collisions[index.value()] = *this;
}

CollisionInfo::CollisionInfo(std::shared_ptr<Collision> col1, std::shared_ptr<Collision> col2)
{
    collision = col1;
    hitCollision = col2;
}
