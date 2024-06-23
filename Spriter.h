#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>

namespace Graphic {
    class Spriter  {
    public:
        /*sf::Sprite sprite;
        sf::Texture texture;*/

        Spriter(std::string& path);

        Spriter(const char* path);

        Spriter(const char* path, sf::IntRect& rect);

        Spriter(std::string& path, sf::IntRect& rect);

        /*inline void setTextureRect(sf::IntRect& rect);

        inline void setPosition(const sf::Vector2f& vector);

        inline void setOrigin(const sf::Vector2f& vector);

        inline void setRotation(float angle);

        inline float getRotation();

        inline sf::Vector2f getPosition();

        inline sf::Vector2f getOrigin();*/

        void setKeyRect(const std::string& key, std::vector<sf::IntRect>& rects);

        void animate(const std::string& keyRect, float duration);

    private:
        void loadTexString(std::string& path);

        //inline virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

        void loadTexChar(const char* path);
        /*sf::Clock clock;
        int currentFrame = 0;
        std::map<std::string, std::vector<sf::IntRect>> texturesRect;*/
    };
}


