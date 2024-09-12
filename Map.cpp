#include "Map.h"

Map::Map(const std::string& csvPath, const std::string& tilePath, const sf::Vector2i& size) {
    layers.push_back(Spriter(tilePath, sf::IntRect(0, 0, size.x, size.y)));
    initLayerMatrix(csvPath);
}

Map::Map(const std::vector<std::string>& cvssPath, const std::vector<std::string>& tilesPath, const sf::Vector2i& size) {
    if (cvssPath.size() != tilesPath.size())
        throw std::invalid_argument("Size paths must be equal!");

    for (int i = 0; i < tilesPath.size(); i++)
    {
        layers.push_back(Spriter(tilesPath[i], sf::IntRect(0, 0, size.x, size.y)));
        initLayerMatrix(cvssPath[i]);
    }

}

Map::Map(const std::vector<std::string>& cvssPath, const std::vector<std::string>& tilesPath, const std::vector<sf::Vector2i>& sizes) {
    if (cvssPath.size() != tilesPath.size() || cvssPath.size() != sizes.size() || tilesPath.size() != sizes.size())
        throw std::invalid_argument("Size paths must be equal!");
    for (int i = 0; i < tilesPath.size(); i++)
    {
        layers.push_back(Spriter(tilesPath[i], sf::IntRect(0, 0, sizes[i].x, sizes[i].y)));
        initLayerMatrix(cvssPath[i]);
    }
}

void Map::setColorTileMap(sf::Color color) {
    for (size_t i = 0; i < layers.size(); i++)
    {
        auto layerMatrixIdSprites = layersMatrixSprite[i];
        for (size_t j = 0; j < layerMatrixIdSprites.size(); j++)
        {
            auto MatrixSprites = layersMatrixSprite[i][j];
            for (size_t k = 0; k < MatrixSprites.size(); k++)
            {
                if (MatrixSprites[k].getTexture() != nullptr) {
                    sf::Vector2i tileSize = layers[i].getTileSize();
                    layersMatrixSprite[i][j][k].setColor(color);
                }
            }
        }
    }
}

void Map::setColorLayerTileMap(uint32_t layer,sf::Color color) {
        auto layerMatrixIdSprites = layersMatrixSprite[layer];
        for (size_t j = 0; j < layerMatrixIdSprites.size(); j++)
        {
            auto MatrixSprites = layersMatrixSprite[layer][j];
            for (size_t k = 0; k < MatrixSprites.size(); k++)
            {
                if (MatrixSprites[k].getTexture() != nullptr) {
                    sf::Vector2i tileSize = layers[layer].getTileSize();
                    layersMatrixSprite[layer][j][k].setColor(color);
                }
            }
        }
}

void Map::initLayerMatrix(const std::string& csvPath) {
    std::string line;
    std::ifstream in(csvPath);
    std::vector<std::vector<sf::Sprite>> matrixSprites;

    if (in.is_open())
    {
        while (std::getline(in, line))
        {
            std::vector<std::string> strNumbers;
            std::vector<sf::Sprite> sprites;
            std::stringstream stream(line);
            std::string token;
            char delimiter = ',';

            while (std::getline(stream, token, delimiter))
                strNumbers.push_back(token);

            for (size_t i = 0; i < strNumbers.size(); i++)
            {
                sprites.push_back(layers[layers.size() - 1].getSpriteFromMatrix(std::stoi(strNumbers[i])));
            }

            matrixSprites.push_back(sprites);
        }
        layersMatrixSprite.push_back(matrixSprites);
    }
    in.close();
}

void Map::checkValidIndexes(uint32_t layer, uint32_t row, uint32_t col)
{
    if (layer > layersMatrixSprite.size() - 1)
        throw std::out_of_range("Layer index out of range");
    if (row > layersMatrixSprite[layer].size() - 1)
        throw std::out_of_range("Row index out of range");
    if (col > layersMatrixSprite[layer][row].size() - 1)
        throw std::out_of_range("Column index out of range");
}

void Map::drawMap(std::shared_ptr<sf::RenderWindow> window) {
    for (size_t i = 0; i < layers.size(); i++)
    {
        auto layerMatrixIdSprites = layersMatrixSprite[i];
        for (size_t j = 0; j < layerMatrixIdSprites.size(); j++)
        {
            auto MatrixSprites = layersMatrixSprite[i][j];
            for (size_t k = 0; k < MatrixSprites.size(); k++)
            {
                if (MatrixSprites[k].getTexture() != nullptr) {
                    sf::Vector2i tileSize = layers[i].getTileSize();
                    layersMatrixSprite[i][j][k].setPosition(sf::Vector2f(position.x + k * tileSize.x, position.y + j * tileSize.y));
                    window->draw(layersMatrixSprite[i][j][k]);
                }

            }
        }
    }
}

void Map::changeTextureTile(const std::string& path, const sf::IntRect& rect, uint32_t layer, uint32_t row, uint32_t col)
{
    checkValidIndexes(layer, row, col);
    std::string key = std::to_string(layer) + std::to_string(row) + std::to_string(col);
    std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
    if (!texture->loadFromFile(path))
    {
        return;
    }
    if (changedTileTextures.count(key) == 1)
        changedTileTextures.erase(key);
    changedTileTextures[key] = texture;
    layersMatrixSprite[layer][row][col].setTexture(*changedTileTextures[key]);
    layersMatrixSprite[layer][row][col].setTextureRect(rect);
}

std::reference_wrapper<sf::Sprite> Map::getSprite(uint32_t layer, uint32_t row, uint32_t col)
{
    checkValidIndexes(layer, row, col);
    return std::reference_wrapper<sf::Sprite>(layersMatrixSprite[layer][row][col]);
}

void Map::swapLayers(uint32_t layer1, uint32_t layer2)
{
    if (layer1 > layersMatrixSprite.size() - 1 || layer2 > layersMatrixSprite.size() - 1)
        throw std::out_of_range("Layer index out of range");
    layersMatrixSprite[layer1].swap(layersMatrixSprite[layer2]);
}

void Map::animateTile(uint32_t layer, uint32_t row, uint32_t col, const std::string& texturePath, const sf::Vector2i& size, float duration)
{
    checkValidIndexes(layer, row, col);
    std::string key = std::to_string(layer) + std::to_string(row) + std::to_string(col) + texturePath;
    if (tileAnimateTextures.count(key) == 0) {
        std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
        if (!texture->loadFromFile(texturePath))
            return;
        tileAnimateTextures[key] = texture;
        layersMatrixSprite[layer][row][col].setTexture(*tileAnimateTextures[key]);
        layersMatrixSprite[layer][row][col].setTextureRect(sf::IntRect(0, 0, size.x, size.y));
        tileAnimateClocks[key] = sf::Clock();
        tileAnimateCount[key] = 0;
    }
    if (tileAnimateClocks[key].getElapsedTime().asSeconds() > duration) {
        int height = size.y;
        int width = size.x;
        int rows = tileAnimateTextures[key]->getSize().y / height;
        int cols = tileAnimateTextures[key]->getSize().x / width;
        int top = (tileAnimateCount[key] / cols) % rows;
        int left = tileAnimateCount[key] % cols;
        layersMatrixSprite[layer][row][col].setTextureRect(sf::IntRect(left * width, top * height, width, height));
        tileAnimateCount[key] = (tileAnimateCount[key] + 1) % (rows * cols);
        tileAnimateClocks[key].restart();
    }
}

void Map::animateTile(const std::vector<uint32_t>& layers, const std::vector<uint32_t>& rows, const std::vector<uint32_t>& cols, const std::vector<std::string>& texturesPath, const sf::Vector2i& size, float duration) {
    if (layers.size() != texturesPath.size() || rows.size() != texturesPath.size() || cols.size() != texturesPath.size())
        throw std::invalid_argument("Size rows cols layer textures must be equal!");
    std::string keyTime = std::to_string(layers.size()) + std::to_string(rows.size()) + std::to_string(cols.size()) + std::to_string(texturesPath.size());
    if (tileAnimateClocks.count(keyTime) == 0 || tileAnimateCount.count(keyTime) == 0) {
        tileAnimateClocks[keyTime] = sf::Clock();
        tileAnimateCount[keyTime] = 0;
    }
    for (size_t i = 0; i < texturesPath.size(); i++)
    {
        checkValidIndexes(layers[i], rows[i], cols[i]);
        std::string key = std::to_string(layers[i]) + std::to_string(rows[i]) + std::to_string(cols[i]) + texturesPath[i];
        if (tileAnimateTextures.count(key) == 0) {
            std::shared_ptr<sf::Texture> texture = std::make_shared<sf::Texture>();
            if (!texture->loadFromFile(texturesPath[i]))
                return;
            tileAnimateTextures[key] = texture;
            layersMatrixSprite[layers[i]][rows[i]][cols[i]].setTexture(*tileAnimateTextures[key]);
            layersMatrixSprite[layers[i]][rows[i]][cols[i]].setTextureRect(sf::IntRect(0, 0, size.x, size.y));
        }
    }

    if (tileAnimateClocks[keyTime].getElapsedTime().asSeconds() > duration) {
        for (size_t i = 0; i < texturesPath.size(); i++)
        {
            std::string key = std::to_string(layers[i]) + std::to_string(rows[i]) + std::to_string(cols[i]) + texturesPath[i];
            int height = size.y;
            int width = size.x;
            int rows2 = tileAnimateTextures[key]->getSize().y / height;
            int cols2 = tileAnimateTextures[key]->getSize().x / width;
            int top = (tileAnimateCount[key] / cols2) % rows2;
            int left = tileAnimateCount[key] % cols2;
            layersMatrixSprite[layers[i]][rows[i]][cols[i]].setTextureRect(sf::IntRect(left * width, top * height, width, height));
            tileAnimateCount[keyTime] = (tileAnimateCount[keyTime] + 1) % (rows2 * cols2);
            tileAnimateClocks[keyTime].restart();
        }
    }


}

void Map::resetAnimateTile(uint32_t layer, uint32_t row, uint32_t col, const std::string& texturePath, sf::Vector2i size)
{
    checkValidIndexes(layer, row, col);
    std::string key = std::to_string(layer) + std::to_string(row) + std::to_string(col) + texturePath;
    if (tileAnimateTextures.count(key) == 0) {
        std::cout << "Error: Key doesn't exist" << std::endl;
        return;
    }
    tileAnimateClocks[key] = sf::Clock();
    tileAnimateCount[key] = 0;
    layersMatrixSprite[layer][row][col].setTextureRect(sf::IntRect(0, 0, size.x, size.y));
}

