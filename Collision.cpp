#include "Collision.h"


std::vector<Collision> Collision::collisions; 
uint32_t Collision::count;

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

void Collision::collisionsEvents() {
    for (size_t i = 0; i <  collisions.size(); ++i) {
        for (size_t j = i + 1; j < collisions.size(); ++j) {
            if (collisions[i].isIntersect(collisions[j])) {
                if (collisions[i].callbackCollision.has_value()) {
                    
                    
                }
            }
        }
    }

}


