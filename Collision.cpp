#include "Collision.h"

std::vector<std::unique_ptr<Collision>> Collision::collisions;
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
    collisions.push_back(std::make_unique<Collision>(std::move(*this)));
}

Collision::Collision(sf::Vector2f size)
{
    shape = sf::RectangleShape(size);
    initCollision();
}

Collision::Collision(sf::Sprite sprite) {
    std::cout << "Constructor" << std::endl;
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



Collision::Collision(Collision&& other)  noexcept : name(std::move(other.name)),
shape(std::move(other.shape)),
id(other.id), isEnter(other.isEnter), isStay(other.isStay), isExit(other.isExit),callbackCollision(std::move(other.callbackCollision))
{

}


Collision& Collision::operator=(Collision&& other) noexcept
{
    if (this != &other) {
        name = std::move(other.name);
        shape = std::move(other.shape);
        id = other.id;
        isEnter = other.isEnter;
        isStay = other.isStay;
        isExit = other.isExit;
        callbackCollision = std::move(other.callbackCollision);
        other.id = 0;
        other.isEnter = false;
        other.isStay = false;
        other.isExit = false;
    }
    return *this;
}




Collision::~Collision()
{
    std::cout << "Destructor " << id << std::endl;
}

bool Collision::isIntersect(Collision otherCol) {
    return this->shape.getGlobalBounds().intersects(otherCol.shape.getGlobalBounds());
}

uint32_t  Collision::getId() {
    return id;
}


void  Collision::setPosition(sf::Vector2f pos) {
    this->shape.setPosition(pos);
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
    this->callbackCollision = callbackCollision;
}

void Collision::callCollisionFunc(size_t i, size_t j)
{
    CollisionInfo colInfo(std::move(collisions[i]), std::move(collisions[j]));
    auto& col = *collisions[i];
    (*col.callbackCollision) ({ colInfo });
}

void Collision::remove(uint32_t id)
{
    auto iter = collisions.begin(); 
    while (iter != collisions.end()) {
        auto& col = *iter; 

        if (id == col->id) {
            iter = collisions.erase(iter); 
            return;
        }
        else {
            ++iter; 
        }
    }
}



void Collision::collisionsEvents() {
    for (size_t i = 0; i < collisions.size(); ++i) {
        for (size_t j = i + 1; j < collisions.size(); ++j) {
            if ((*collisions[i]).name != (*collisions[j]).name)
                continue;
            if ((*collisions[i]).isIntersect(std::move(*collisions[j]))) {
                if (!(*collisions[i]).isEnter && !(*collisions[i]).isStay) {  //Make map data type instead bool. It's break logic if will two or more collisions. 
                    (*collisions[i]).isEnter = true;
                }
                else if (!(*collisions[i]).isStay) {
                    (*collisions[i]).isStay = true;
                    (*collisions[i]).isEnter = false;
                }
                if ((*collisions[i]).callbackCollision != nullptr )
                {
                    callCollisionFunc(i, j);
                }
            }
            else {
                if ((*collisions[i]).isExit) {
                    (*collisions[i]).isExit = false;
                    callCollisionFunc(i, j);
                }
                else if ((*collisions[i]).isEnter || (*collisions[i]).isStay) {
                    (*collisions[i]).isExit = true;
                    (*collisions[i]).isStay = false;
                    (*collisions[i]).isEnter = false;
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
    this->shape.setSize(vec);
}

CollisionInfo::CollisionInfo(std::unique_ptr<Collision> col1, std::unique_ptr<Collision> col2)
{
    collision = std::move(col1);
    hitCollision = std::move(col2);
}
