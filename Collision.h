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


class Collision;


using CallbackCollision = std::function<void(Collision& col1)>;
using TouchedCollisions = std::function<void(std::vector<Collision*> collisions, std::vector<Collision*> touchCollisions)>;


class Collision : public sf::Drawable {

public:
    Collision(sf::Vector2f size);
    Collision(sf::Sprite sprite);
    Collision(sf::Sprite sprite, sf::FloatRect rect);
    ~Collision();

    void setName(std::string newName);

    std::string getName();

    void disableGroup(std::string name);

    bool isIntersect(Collision& otherCol);

    uint32_t getId();

    void setPosition(sf::Vector2f pos);

    sf::Vector2f getPosition();

    static void touchedCollisison(std::string name, std::string touchName);
    static void unTouchedCollisison(std::string name, std::string touchName);


    static void collisionsEvents();

    bool enterCollision(uint32_t touchId);
    bool enterCollision(Collision& col);

    bool stayCollision(uint32_t touchId);
    bool stayCollision(Collision& col);

    bool exitCollision(uint32_t touchId);
    bool exitCollision(Collision& col);

    sf::Vector2f getSize();

    void setSize(sf::Vector2f vec);

    void setCallbackCollision(CallbackCollision callback);

    bool operator==(const Collision& other) const;



private:
    std::string name;
    std::map<std::string, bool> group = std::map<std::string, bool>();
    static std::map<std::string, std::vector<Collision*>> groupsCollisions;
    static std::map<std::string, std::string> dictionaryCollisions;
    sf::RectangleShape* shape;
    void removeElementGroup(std::string name);
    std::map<uint32_t, bool> isEnter;
    std::map<uint32_t, bool> isStay;
    std::map<uint32_t, bool> isExit;
    uint32_t id = 0;
    static uint32_t count;
    std::optional<CallbackCollision> callbackCollision;
    void initCollision();
    std::optional<int> getIndex();
    void callCollisionFunc(Collision& col1);



    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};