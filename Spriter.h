#pragma once
#include <iostream>
#include <map>
#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory>

class Spriter : public sf::Drawable {
public:
    sf::Sprite sprite;
    std::shared_ptr<sf::Texture> texture;

    Spriter(const char* path);

    Spriter(const char* path, const sf::Vector2f& position);

    Spriter(const std::string& path, const sf::Vector2f& position);

    Spriter(const std::string& path);

    Spriter(const char* path, const sf::IntRect& rect);

    Spriter(const std::string& path, const sf::IntRect& rect);

    Spriter(const char* path, const sf::IntRect& rect, const sf::Vector2f& position);

    Spriter(const std::string& path, const sf::IntRect& rect, const sf::Vector2f& position);

    void setTextureRect(const sf::IntRect& rect);

    void setPosition(const sf::Vector2f& vector);

    void setOrigin(const sf::Vector2f& vector);

    void setRotation(float angle);

    void changeTexture(const std::string& path, const sf::IntRect& rect);

    float getRotation();

    void setScale(const sf::Vector2f& size);

    sf::Vector2f getScale();

    sf::Vector2u getSize();

    void setColor(const sf::Color& color);

    sf::Color getColor();

    sf::Vector2f getPosition();

    sf::Vector2f getOrigin();

    void setKeyRect(const std::string& key, const std::vector<sf::IntRect>& rects);

    void animate(const std::string& keyRect, float duration);

    void animate(float duration, uint32_t minRow);

    void animate(float duration, uint32_t minRow, uint32_t maxRow);

    sf::Sprite getSpriteFromMatrix(int num);

    sf::Vector2i getTileSize();

    void resetAnimation();

private:
    bool loadTexString(const std::string& path);

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

    bool loadTexChar(const char* path);
    sf::Clock clock;
    std::string currentRect;
    int currentFrame = 0;
    int currentNumSprite = 0;
    std::map<std::string, std::vector<sf::IntRect>> texturesRect;
    std::shared_ptr <std::vector<std::vector<sf::Sprite>>> matrixSprites;
    std::pair<std::string,std::shared_ptr <std::vector<std::vector<sf::Sprite>>>> minrowMatrixSpritesCache;
    std::pair< std::string,std::shared_ptr <std::vector<std::vector<sf::Sprite>>>> maxrowMatrixSpritesCache;
    std::shared_ptr<sf::Vector2i> tileSize;
    void setMatrixSprite(const sf::IntRect& rect);
};

