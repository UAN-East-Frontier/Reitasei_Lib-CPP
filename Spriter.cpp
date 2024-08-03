#include <SFML/Graphics.hpp>
#include "Spriter.h"


Spriter::Spriter(const std::string& path) {
    loadTexString(path);
}

Spriter::Spriter(const char* path) {
    loadTexChar(path);
}

Spriter::Spriter(const char* path, const sf::Vector2f& position)
{
    if (loadTexChar(path))
        sprite.setPosition(position);
}

Spriter::Spriter(const std::string& path, const sf::Vector2f& position)
{
    if (loadTexString(path))
        sprite.setPosition(position);
}

Spriter::Spriter(const char* path, const sf::IntRect& rect) {
    bool isLoad = loadTexChar(path);
    sprite.setTextureRect(rect);
    if (isLoad) {
        setMatrixSprite(rect);
    }
}

Spriter::Spriter(const std::string& path, const sf::IntRect& rect) {
    bool isLoad = loadTexString(path);
    sprite.setTextureRect(rect);
    if (isLoad) {
        setMatrixSprite(rect);
    }
}

Spriter::Spriter(const char* path, sf::IntRect& rect, const  sf::Vector2f& position)
{
    if (loadTexChar(path)) {
        sprite.setTextureRect(rect);
        sprite.setPosition(position);
        setMatrixSprite(rect);
    }
}

Spriter::Spriter(const std::string& path, sf::IntRect& rect, const sf::Vector2f& position)
{
    if (loadTexString(path)) {
        sprite.setTextureRect(rect);
        sprite.setPosition(position);
        setMatrixSprite(rect);
    }
}


void Spriter::setMatrixSprite(const sf::IntRect& rect) {
    int width = rect.width;
    int height = rect.height;
    int rows = texture->getSize().y / height;
    int cols = texture->getSize().x / width;
    tileSize = std::make_shared<sf::Vector2i>(rect.getSize());
    matrixSprites = std::make_shared<std::vector<std::vector<sf::Sprite>>>(std::vector<std::vector<sf::Sprite>>());
    for (size_t i = 0; i < rows; i++)
    {
        std::vector<sf::Sprite> sprites;
        for (size_t j = 0; j < cols; j++)
        {
            sf::Sprite sprite;
            sprite.setTexture(*texture);
            sprite.setTextureRect(sf::IntRect(j * width, i  * height, width, height));
            sprites.push_back(sprite);
        }
        matrixSprites->push_back(sprites);
    }
}

void  Spriter::setTextureRect(const sf::IntRect& rect) {
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

void Spriter::setScale(const sf::Vector2f& size)
{
    sprite.setScale(size);
}

sf::Vector2f Spriter::getScale()
{
    return sprite.getScale();
}

sf::Vector2u Spriter::getSize()
{
    return texture->getSize();
}

void Spriter::setColor(const sf::Color& color)
{
    sprite.setColor(color);
}

sf::Color Spriter::getColor()
{
    return sprite.getColor();
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

void Spriter::setKeyRect(const std::string& key, const std::vector<sf::IntRect>& rects) {
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

void Spriter::animate(float duration, uint32_t minRow) {
    if (matrixSprites == nullptr)
        return;
    if (clock.getElapsedTime().asSeconds() > duration) {
        if (minRow > matrixSprites->size() - 1) {
            std::cout << "Error: Minimal row out of range matrix sprites rows!" << std::endl;
            return;
        }

        if (minrowMatrixSpritesCache.second == nullptr) {
            auto newMatrixSprites = *matrixSprites;
            auto iter = newMatrixSprites.begin();
            for (size_t i = 0; i < minRow; i++)
            {
                newMatrixSprites.erase(iter);
                iter++;
            }
            minrowMatrixSpritesCache.first = std::to_string(minRow);
            minrowMatrixSpritesCache.second = std::make_shared< std::vector<std::vector<sf::Sprite>>>(newMatrixSprites);
        }
        else if (minrowMatrixSpritesCache.first != std::to_string(minRow)) {
            auto newMatrixSprites = *matrixSprites;
            newMatrixSprites.erase(newMatrixSprites.begin(), newMatrixSprites.begin() + minRow);
            minrowMatrixSpritesCache.first = std::to_string(minRow);
            minrowMatrixSpritesCache.second = std::make_shared< std::vector<std::vector<sf::Sprite>>>(newMatrixSprites);
        }
        auto newMatrixSprites = minrowMatrixSpritesCache.second;
        int rows = newMatrixSprites->size();
        int cols = (*newMatrixSprites)[rows - 1].size();
        int row = (currentNumSprite / cols) % rows;
        int col = currentNumSprite % cols;
        sprite.setTextureRect((*newMatrixSprites)[row][col].getTextureRect());
        currentNumSprite = (currentNumSprite + 1) % (rows * cols);
        clock.restart();
    }
}

void Spriter::animate(float duration, uint32_t minRow, uint32_t maxRow) {
    if (matrixSprites == nullptr)
        return;
    if (clock.getElapsedTime().asSeconds() > duration) {
        if (minRow > matrixSprites->size() - 1) {
            std::cout << "Error: Minimal row out of range matrix sprites rows!" << std::endl;
            return;
        }
        if (maxRow > matrixSprites->size() - 1) {
            std::cout << "Error: Maximal row out of range matrix sprites rows!" << std::endl;
            return;
        }
        if (minRow > maxRow)
        {
            auto temp = minRow;
            minRow = maxRow;
            maxRow = temp;
        }

        if (maxrowMatrixSpritesCache.second == nullptr) {
            auto newMatrixSprites = *matrixSprites;
            newMatrixSprites.erase(newMatrixSprites.begin() , newMatrixSprites.begin()+ minRow);
            newMatrixSprites.erase(newMatrixSprites.begin()+maxRow, newMatrixSprites.end());
            maxrowMatrixSpritesCache.first = std::to_string(minRow) + std::to_string(maxRow);
            maxrowMatrixSpritesCache.second = std::make_shared< std::vector<std::vector<sf::Sprite>>>(newMatrixSprites);
        }
        else if (maxrowMatrixSpritesCache.first != std::to_string(minRow) + std::to_string(maxRow)) {
            auto newMatrixSprites = *matrixSprites;
            newMatrixSprites.erase(newMatrixSprites.begin(), newMatrixSprites.begin() + minRow);
            newMatrixSprites.erase(newMatrixSprites.begin() + maxRow, newMatrixSprites.end());
            maxrowMatrixSpritesCache.first = std::to_string(minRow) + std::to_string(maxRow);
            maxrowMatrixSpritesCache.second = std::make_shared< std::vector<std::vector<sf::Sprite>>>(newMatrixSprites);
        }

        auto newMatrixSprites = maxrowMatrixSpritesCache.second;
        int rows = newMatrixSprites->size();
        int cols = (*newMatrixSprites)[rows - 1].size();
        int row = (currentNumSprite / cols) % rows;
        int col = currentNumSprite % cols;
        sprite.setTextureRect((*newMatrixSprites)[row][col].getTextureRect());
        currentNumSprite = (currentNumSprite + 1) % (rows * cols);
        clock.restart();
    }
}

sf::Sprite Spriter::getSpriteFromMatrix(int num)
{
    if (matrixSprites == nullptr) {
        std::cout << "Error: Matrix sprites not init! Use ctor with argument int rect for init." << std::endl;
        return sf::Sprite();
    }
    if (num == -1) {
        return sf::Sprite();
    }
    int rows = matrixSprites->size();
    int cols = (*matrixSprites)[rows - 1].size();
    int row = (num / cols) % rows;
    int col = num % cols;

    return (*matrixSprites)[row][col];
}

sf::Vector2i Spriter::getTileSize() {
    return *tileSize;
}

void Spriter::resetAnimation()
{
    currentNumSprite = 0;
    clock.restart();
    if (minrowMatrixSpritesCache.second != nullptr)
        sprite.setTextureRect((*minrowMatrixSpritesCache.second)[0][0].getTextureRect());
    if (maxrowMatrixSpritesCache.second != nullptr)
        sprite.setTextureRect((*maxrowMatrixSpritesCache.second)[0][0].getTextureRect());
}

void Spriter::changeTexture(const std::string& path, const sf::IntRect& rect) {
    texture.reset();
    texture = std::make_shared<sf::Texture>(sf::Texture());
    if (!texture->loadFromFile(path)) {
        return;
    }
    sprite.setTexture(*texture);
    sprite.setTextureRect(rect);
    setMatrixSprite(rect);
}

bool Spriter::loadTexString(const std::string& path) {
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
