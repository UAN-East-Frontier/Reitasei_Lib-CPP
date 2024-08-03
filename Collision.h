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
    Collision(const sf::Vector2f& size);
    Collision(const sf::Sprite& sprite);
    Collision(const sf::Sprite& sprite, const sf::FloatRect& rect);
    ~Collision();

    void setName(const std::string& newName);

    std::string getName();

    void disableGroup(const std::string& name);

    bool isIntersect(const Collision& otherCol);

    uint32_t getId();

    void setPosition(const sf::Vector2f& pos);

    sf::Vector2f getPosition();

    static void touchedCollisison(const std::string& name, const std::string& touchName);
    static void unTouchedCollisison(const std::string& name, const std::string& touchName);


    static void collisionsEvents();

    bool enterCollision(uint32_t touchId);
    bool enterCollision(Collision& col);

    bool stayCollision(uint32_t touchId);
    bool stayCollision(Collision& col);

    bool exitCollision(uint32_t touchId);
    bool exitCollision(Collision& col);

    sf::Vector2f getSize();

    void setSize(sf::Vector2f vec);

    void setCallbackCollision(const CallbackCollision& callback);

    bool operator==(const Collision& other) const;



private:
    std::string name;
    std::map<std::string, bool> group = std::map<std::string, bool>();
    static std::map<std::string, std::vector<Collision*>> groupsCollisions;
    static std::map<std::string, std::string> dictionaryCollisions;
    std::shared_ptr<sf::RectangleShape> shape;
    void removeElementGroup(const std::string& name);
    std::map<uint32_t, bool> isEnter;
    std::map<uint32_t, bool> isStay;
    std::map<uint32_t, bool> isExit;
    uint32_t id = 0;
    static uint32_t count;
    std::optional<CallbackCollision> callbackCollision;
    void initCollision();
    void callCollisionFunc(Collision& col1);



    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};