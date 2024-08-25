#pragma once
#include <SFML/Graphics.hpp>
#include <memory>


class Location;

class Scene {
public:
    virtual std::unique_ptr<Location>  windowAction(std::unique_ptr<Location> loc, sf::Event& event, const float deltaTime) = 0;
    virtual std::unique_ptr<Location> gameAction(std::unique_ptr<Location> loc, sf::Event& event, float deltaTime) = 0;
    virtual std::unique_ptr<Location>  drawAction(std::unique_ptr<Location> loc) = 0;
};



