#include <SFML/Graphics.hpp>
#include "Spriter.h"




    Spriter::Spriter(std::string& path)  {
        loadTexString(path);
    }

    Spriter::Spriter(const char* path) {
        loadTexChar(path);
    }

    Spriter::Spriter(const char* path, sf::Vector2f& position)
    {
        if (loadTexChar(path))
            sprite.setPosition(position);
    }

    Spriter::Spriter(std::string& path, sf::Vector2f& position)
    {
        if (loadTexString(path))
            sprite.setPosition(position);
    }

    Spriter::Spriter(const char* path, sf::IntRect& rect) {
        loadTexChar(path);
        sprite.setTextureRect(rect);
    }

    Spriter::Spriter(std::string& path, sf::IntRect& rect) {
        loadTexString(path);
        sprite.setTextureRect(rect);
    }

    Spriter::Spriter(const char* path, sf::IntRect& rect, sf::Vector2f& position)
    {
        if (loadTexChar(path))
            sprite.setPosition(position);
    }

    Spriter::Spriter(std::string& path, sf::IntRect& rect, sf::Vector2f& position)
    {
        if (loadTexString(path))
            sprite.setPosition(position);
    }

    void  Spriter::setTextureRect(sf::IntRect& rect) {
        sprite.setTextureRect(rect);
    }

    void Spriter::setPosition(const sf::Vector2f& vector) {
        sprite.setPosition(vector);
    }

    void Spriter::setOrigin(const sf::Vector2f& vector) {
        sprite.setOrigin(vector);
    }

    void Spriter::setRotation(float angle) {
        sprite.setRotation(angle);
    }

    float Spriter::getRotation() {
        return sprite.getRotation();
    }

    sf::Vector2f Spriter::getPosition() {
        return sprite.getPosition();
    }

    sf::Vector2f Spriter::getOrigin() {
        return sprite.getOrigin();
    }

    void Spriter::setKeyRect(const std::string& key, std::vector<sf::IntRect>& rects) {
        texturesRect[key] = rects;
    }

    void Spriter::animate(const std::string& keyRect, float duration) {
        if (!texturesRect.contains(keyRect))
        {
            std::cout << "Key is not found!" << std::endl;
            return;
        }
        if (clock.getElapsedTime().asSeconds() > duration) {
            currentFrame = (currentFrame + 1) % texturesRect[keyRect].size();
            sprite.setTextureRect(texturesRect[keyRect][currentFrame]);
            clock.restart();
        }
    }


    bool Spriter::loadTexString(std::string& path) {
        if (texture.loadFromFile(path)) {
            sprite.setTexture(texture);
            return true;
        }
        else std::cout << "Warning: Texture didn't load!" << std::endl;
        return false;
    }

   void Spriter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(sprite, states);
    }

    bool Spriter::loadTexChar(const char* path) {
        if (texture.loadFromFile(path)) {
            sprite.setTexture(texture);
            return true;
        }
        else std::cout << "Warning: Texture didn't load!" << std::endl;
        return false;
    }
