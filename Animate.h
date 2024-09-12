#pragma once
#include <cmath>
#include <map>
#define PI 3.141592653589793223846
#include <SFML/Graphics.hpp>
#include "Gui.h"
#include <vector>

float getEaseNumber(float start, float end, float easingT);

std::pair<std::pair<float, float>, std::pair<float, float>> getCoordinates(sf::Vector2f& start, sf::Vector2f& end);

float getT(float duration, sf::Clock& clock);

float easeOutBounce(float t);

sf::Vector2f animateLinearVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateSineInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateSineOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateSineInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuadInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuadOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuadInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCubicInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCubicOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCubicInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuartInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuartOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuartInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuintInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuintOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateQuintInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateExponentialInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateExponentialOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateExponentialInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCircularInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCircularOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateCircularInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBackInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBackOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBackInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBounceInVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBounceOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

sf::Vector2f animateBounceInOutVector(sf::Vector2f& startPoint, sf::Vector2f& endPoint, float duration, sf::Clock& clock);

float animateLinearFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateSineInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateSineOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateSineInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuadInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuadOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuadInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateCubicInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateCubicOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateCubicInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuartInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuartOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuartInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuintInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuintOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateQuintInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateExponetialInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateExponetialOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateExponetialInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateCircularInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateCircularOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateCircularInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateBackInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateBackOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateBackInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateBounceInFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateBounceOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

float animateBounceInOutFloat(float startPoint, float endPoint, float duration, sf::Clock& clock);

class AnimateText: public sf::Drawable {

public:
    bool startAnimate(sf::Text& text, const std::string& str, float durtaionWaitNextSymbol);
    bool animateSizeText(const sf::Text& textParametr, const std::string& stroka, float duration);
    void resetAnimate();
    void setWidth(int width);
    void setHeight(int height);
    int getWidth();
    int getHeight();
    AnimateText();
    AnimateText(int width, int height);
    void resetSizeText();

private:
    sf::Clock clock;
    sf::Text symbol;
    std::vector<sf::Text> bufferText;
    uint32_t index = 0;
    int width;
    int height;
    bool isNotAnimateSymbol = true;;
    std::string word;
    sf::RectangleShape shape;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    void nextRowString(std::string& word, int& row);
};

class AnimateNumber : public sf::Drawable {
public:
    float duration = 0.05f;
    sf::Vector2f scale = sf::Vector2f(1, 1);
    void setNewNumberValue(int newValue);
    void updateNumberValue();
    void setPosition(const sf::Vector2f& pos);
    void setSpritesNumbers(const std::vector<std::string>& pathsTexture);
    void setCountZero(uint32_t countZero);
    int getNumber();

    AnimateNumber(const TextLabel& txt);
    AnimateNumber(const TextLabel& txt, float dur, int num);
    AnimateNumber(const TextLabel& txt, const std::vector<std::string>& pathsTexture);
    AnimateNumber(const TextLabel& txt, const std::vector<std::string>& pathsTexture, float dur, int num);

private:
    sf::Clock clock;
    int number = 0;
    int targetNumber = 0;
    TextLabel label;
    std::vector <sf::Sprite> numbers;
    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
    std::vector<sf::Sprite> spritesNumbers;
    std::vector<std::shared_ptr<sf::Texture>> texturesNumbers;
    std::string zeros = "";

};


