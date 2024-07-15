#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

    class Spriter: public sf::Drawable {
    public:
        sf::Sprite sprite;
        sf::Texture texture;

        Spriter(const char* path);

        Spriter(const char* path,sf::Vector2f& position);

        Spriter(std::string& path, sf::Vector2f& position);
        
        Spriter(std::string& path);

        Spriter(const char* path, sf::IntRect& rect);

        Spriter(std::string& path, sf::IntRect& rect);

        Spriter(const char* path, sf::IntRect& rect, sf::Vector2f& position);

        Spriter(std::string& path, sf::IntRect& rect, sf::Vector2f& position);


        void setTextureRect(sf::IntRect& rect);

        void setPosition(const sf::Vector2f& vector);

        void setOrigin(const sf::Vector2f& vector);

        void setRotation(float angle);

        float getRotation();

        sf::Vector2f getPosition();

        sf::Vector2f getOrigin();

        void setKeyRect(const std::string& key, std::vector<sf::IntRect>& rects);

        void animate(const std::string& keyRect, float duration);

    private:
       bool loadTexString(std::string& path);

        virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        bool loadTexChar(const char* path);
        sf::Clock clock;
        std::string currentRect;
        int currentFrame = 0;
        std::map<std::string, std::vector<sf::IntRect>> texturesRect;
    };


