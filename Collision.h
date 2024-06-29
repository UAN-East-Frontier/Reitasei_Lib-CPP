#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>

class Collision : public sf::Drawable{
public:
    std::string name;
    Collision(sf::Sprite sprite);
    Collision(sf::Sprite sprite,sf::FloatRect rect);

    bool isIntersect(Collision otherCol);

    uint32_t getId();

    void setPosition(sf::Vector2f pos);

    static void collisionsEvents();

private:
    sf::RectangleShape shape;
    static std::vector<Collision> collisions;
    bool isEnter = false;
    bool isStay = false;
    bool isExit = false;
    uint32_t id = 0;
    static uint32_t count;

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};
