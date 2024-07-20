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
        if (loadTexChar(path)) {
            sprite.setTextureRect(rect);
            sprite.setPosition(position);
        }
    }

    Spriter::Spriter(std::string& path, sf::IntRect& rect, sf::Vector2f& position)
    {
        if (loadTexString(path)) {
            sprite.setTextureRect(rect);
            sprite.setPosition(position);
        }
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
        if (currentRect != keyRect)
        {
            currentRect = keyRect;
            currentFrame = (currentFrame + 1) % texturesRect[currentRect].size();
            sprite.setTextureRect(texturesRect[currentRect][currentFrame]);
        }
        else if (clock.getElapsedTime().asSeconds() > duration) {
            currentFrame = (currentFrame + 1) % texturesRect[currentRect].size();
            sprite.setTextureRect(texturesRect[currentRect][currentFrame]);
            clock.restart();
        }
    }
    
    void Spriter::changeTexture(std::string path) {
        texture.reset();
        texture = std::make_shared<sf::Texture>(sf::Texture());
        if (!texture->loadFromFile(path)) {
            return;
        }
        sprite.setTextureRect(sf::IntRect(0, 0, texture->getSize().x, texture->getSize().y));
        sprite.setTexture(*texture);
    }

    bool Spriter::loadTexString(std::string& path) {
        texture = std::make_shared<sf::Texture>(sf::Texture());
        if (texture->loadFromFile(path)) {
            sprite.setTexture(*texture);
            return true;
        }
        else { 
            std::cout << "Warning: Texture didn't load!" << std::endl;
            texture.reset();
        }
        return false;
    }

   void Spriter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(sprite, states);
    }

    bool Spriter::loadTexChar(const char* path) {
        texture = std::make_shared<sf::Texture>(sf::Texture());
        if (texture->loadFromFile(path)) {
            sprite.setTexture(*texture);
            return true;
        }
        else {
            std::cout << "Warning: Texture didn't load!" << std::endl;
            texture.reset();
        }
        return false;
    }
