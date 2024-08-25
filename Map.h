#include <fstream>
#include <string>
#include <SFML/Graphics.hpp>
#include "Spriter.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <memory>

class Map {
public:
    Map(const std::string& csvPath, const std::string& tilePath, const sf::Vector2i& size);
    Map(const std::vector<std::string>& cvssPath, const std::vector<std::string>& tilesPath, const sf::Vector2i& size);
    Map(const std::vector<std::string>& cvssPath, const std::vector<std::string>& tilesPath, const std::vector<sf::Vector2i>& sizes);

    void drawMap(std::shared_ptr<sf::RenderWindow> window);
    void changeTextureTile(const std::string& path, const sf::IntRect& rect, uint32_t layer, uint32_t row, uint32_t col);
    std::reference_wrapper<sf::Sprite> getSprite(uint32_t layer, uint32_t row, uint32_t col);
    void swapLayers(uint32_t layer1, uint32_t layer2);
    void animateTile(uint32_t layer, uint32_t row, uint32_t col, const std::string& texturePath, const sf::Vector2i& size, float duration);
    void animateTile(const std::vector<uint32_t>& layers, const std::vector<uint32_t>& rows, const std::vector<uint32_t>& cols, const std::vector<std::string>& texturesPath, const sf::Vector2i& size, float duration);
    void resetAnimateTile(uint32_t layer, uint32_t row, uint32_t col, const std::string& texturePath, sf::Vector2i size);
    void setColorTileMap(sf::Color color);
    void setColorLayerTileMap(uint32_t layer,sf::Color color);

private:
    std::vector<Spriter> layers;
    std::vector<std::vector<std::vector<sf::Sprite>>> layersMatrixSprite;
    std::map<std::string, std::shared_ptr<sf::Texture>> changedTileTextures;
    std::map<std::string, std::shared_ptr<sf::Texture>> tileAnimateTextures;
    std::map<std::string, int> tileAnimateCount;
    std::map<std::string, sf::Clock> tileAnimateClocks;
    void initLayerMatrix(const std::string& csvPath);
    void checkValidIndexes(uint32_t layer, uint32_t row, uint32_t col);
};