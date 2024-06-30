#include "Collision.h"

std::vector<Collision> Collision::collisions; 
uint32_t Collision::count;

bool Collision::operator==(const Collision& other) const
{
    return id == other.id;
}

Collision::Collision(sf::Sprite sprite) {
        sf::FloatRect rect = sprite.getGlobalBounds();
        shape = sf::RectangleShape(sf::Vector2f(rect.width, rect.height));
        shape.setPosition(sprite.getPosition());
        shape.setFillColor(sf::Color::Transparent);
        shape.setOutlineThickness(1.f);
        shape.setOutlineColor(sf::Color::Red);
        id = ++count;
        name = "Unknown";
        collisions.push_back(*this);
    }

Collision::Collision(sf::Sprite sprite, sf::FloatRect rect) {
    shape = sf::RectangleShape(sf::Vector2f(rect.width, rect.height));
    shape.setPosition(sprite.getPosition());
    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineThickness(1.f);
    shape.setOutlineColor(sf::Color::Red);
    id = ++count;
    name = "Unknown";
    collisions.push_back(*this);
}

bool Collision::isIntersect(Collision otherCol) {
      return this->shape.getGlobalBounds().intersects(otherCol.shape.getGlobalBounds());
}

uint32_t  Collision::getId() {
    return id;
}

void  Collision::setPosition(sf::Vector2f pos) {
    shape.setPosition(pos);
}

void Collision::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    target.draw(shape, states);
}

void Collision::setCallbackCollision(CallbackCollision callback)
{
    if (callbackCollision.has_value()) {
        std::cout << "Calback has value!!!" << std::endl;
        return;
    }
    Range collisionRange(collisions);
    auto index = collisionRange.findIndex(*this);
    if (!index.has_value()) {
        std::cout << "Collision not found!!!" << std::endl;
        return;
    }
    callbackCollision = callback;
    collisions[index.value()] = *this;
}


void Collision::collisionsEvents() {
    for (size_t i = 0; i <  collisions.size(); ++i) {
        for (size_t j = i + 1; j < collisions.size(); ++j) {
            if (collisions[i].isIntersect(collisions[j])) {
                if (collisions[i].callbackCollision.has_value())
                {
                    std::shared_ptr<Collision> colPtr1{ std::make_shared<Collision> (collisions[i]) };
                    std::shared_ptr<Collision> colPtr2{ std::make_shared<Collision>(collisions[j]) };
                    CollisionInfo colInfo(colPtr1, colPtr2);
                    collisions[i].callbackCollision.value() ({colInfo});
                }
                
            }
        }
    }

}


CollisionInfo::CollisionInfo(std::shared_ptr<Collision> col1, std::shared_ptr<Collision> col2)
{
    collision = col1;
    hitCollision = col2;
}
