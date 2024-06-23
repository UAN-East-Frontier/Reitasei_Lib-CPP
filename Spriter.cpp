#include "Spriter.h"



    //Graphic::Spriter::Spriter(std::string& path)  {
    //    loadTexString(path);
    //}

    //Graphic::Spriter::Spriter(const char* path) {
        //loadTexChar(path);
    //}

    //Graphic::Spriter::Spriter(const char* path, sf::IntRect& rect) {
    //    loadTexChar(path);
    //    //sprite.setTextureRect(rect);
    //}

    //Graphic::Spriter::Spriter(std::string& path, sf::IntRect& rect) {
    //    loadTexString(path);
    //    //sprite.setTextureRect(rect);
    //}

   /* void  Graphic::Spriter::setTextureRect(sf::IntRect& rect) {
        sprite.setTextureRect(rect);
    }

    void Graphic::Spriter::setPosition(const sf::Vector2f& vector) {
        sprite.setPosition(vector);
    }

    void Graphic::Spriter::setOrigin(const sf::Vector2f& vector) {
        sprite.setOrigin(vector);
    }

    void Graphic::Spriter::setRotation(float angle) {
        sprite.setRotation(angle);
    }

    float Graphic::Spriter::getRotation() {
        return sprite.getRotation();
    }

    sf::Vector2f Graphic::Spriter::getPosition() {
        return sprite.getPosition();
    }

    sf::Vector2f Graphic::Spriter::getOrigin() {
        return sprite.getOrigin();
    }*/

    //void Graphic::Spriter::setKeyRect(const std::string& key, std::vector<sf::IntRect>& rects) {
    //    //texturesRect[key] = rects;
    //}

    //void Graphic::Spriter::animate(const std::string& keyRect, float duration) {
    //    /*if (!texturesRect.contains(keyRect))
    //    {
    //        std::cout << "Key is not found!" << std::endl;
    //        return;
    //    }
    //    if (clock.getElapsedTime().asSeconds() > duration) {
    //        currentFrame = (currentFrame + 1) % texturesRect[keyRect].size();
    //        sprite.setTextureRect(texturesRect[keyRect][currentFrame]);
    //        clock.restart();
    //    }*/
    //}



    //void Graphic::Spriter::loadTexString(std::string& path) {
    //   /* if (texture.loadFromFile(path)) {
    //        sprite.setTexture(texture);
    //    }
    //    else std::cout << "Warning: Texture didn't load!" << std::endl;*/
    //}

   void Graphic::Spriter::draw(sf::RenderTarget& target, sf::RenderStates states) const {
        target.draw(sprite, states);
    }

    //void Graphic::Spriter::loadTexChar(const char* path) {
    //    /*if (texture.loadFromFile(path)) {
    //        sprite.setTexture(texture);
    //    }
    //    else std::cout << "Warning: Texture didn't load!" << std::endl;*/
    //}
