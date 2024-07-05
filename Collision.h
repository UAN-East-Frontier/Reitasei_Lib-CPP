#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <iostream>
#include <functional>
#include <optional>
#include <utility> 
#include <memory>
#include <map>
#include "Range.h"


class Collision;


using CallbackCollision = std::function<void(Collision& col1, Collision& col2)>;


class Collision : public sf::Drawable{

public:
    std::string name;

    Collision(sf::Vector2f size);
    Collision(sf::Sprite sprite);
    Collision(sf::Sprite sprite,sf::FloatRect rect);
    ~Collision();




    bool isIntersect(Collision& otherCol);

    uint32_t getId();

    void setPosition(sf::Vector2f pos);

    sf::Vector2f getPosition();

    static void collisionsEvents();

    bool enterCollision();

    bool stayCollision();

    bool exitCollision();

    sf::Vector2f getSize();

    void setSize(sf::Vector2f vec);

    void setCallbackCollision(CallbackCollision callback);

    bool operator==(const Collision& other) const;

    

private:
    sf::RectangleShape* shape;
    static std::vector<Collision*> collisions;
    bool isEnter;
    bool isStay ;
    bool isExit;
    uint32_t id = 0;
    static uint32_t count;
    std::optional<CallbackCollision> callbackCollision;
    void initCollision();
    std::optional<int> getIndex();
    void callCollisionFunc(size_t i, size_t j);
 


    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};


