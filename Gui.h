#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>
#include <functional>

using callbackButton = std::function<void()>;

class TextLabel : public sf::Drawable {
public:
	sf::Text text;
	TextLabel(const std::string& fontAsset, const std::string& textName);
	void changeFont(const std::string& fontAsset);
private:
	std::shared_ptr<sf::Font> font;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class Button : public sf::Drawable {
public:
	Button(const TextLabel& textLabel);
	Button(const sf::Texture& texture);

	void setShapeSize();
	void setBackgroundColor(const sf::Color& color);
	void mouseButton1Click(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& click);
	void mouseButton2Click(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& click);
	void mouseButtonHover(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& hover);
	void mouseButtonUnHover(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& hover);
	void addShapeSize(const sf::Vector2f& size);
	void setPosition(const sf::Vector2f& position);
	void setTextColor(const sf::Color& color);
	void setTextOutlineColor(const sf::Color& color);
	void setTextOutlineThickness(float thickness);
	void setShapeOutlineThickness(float thickness);
	void setTextFontSize(uint32_t size);
	void setText(const std::string& text);
	void setStyleText(sf::Uint32 style);
	void setShapeOutlineColor(const sf::Color& color);
	float getShapeOutlineThickness();
	float getTextOutlineThickness();
	sf::Color getShapeOutlineColor();
	sf::FloatRect getLocalBoundsText();
	sf::FloatRect getGlobalBoundsText();
	sf::Uint32 getStyleText();
	sf::Color getTextColor();
	uint32_t getTextFontSize();
	sf::Vector2f getPosition();
	sf::Vector2f getShapeSize();
	sf::Color getBackgroundColor();
	sf::Color getTextOutlineColor();
	std::string getText();

private:
	std::shared_ptr<sf::Sprite> sprite;
	std::shared_ptr<sf::Texture> texture;
	std::shared_ptr<sf::RectangleShape> shape;
	std::shared_ptr<TextLabel> textLabel;
	std::unique_ptr<sf::Vector2f> addedShapeSize;
	bool isHover = false;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};