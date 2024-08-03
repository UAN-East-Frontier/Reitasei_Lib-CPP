#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <memory>

class TextLabel: public sf::Drawable {
public:
		sf::Text text;
		TextLabel(const std::string& fontAsset,const std::string& textName);
		void changeFont(const std::string& fontAsset);
private:
		std::shared_ptr<sf::Font> font;
		virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};

class Button : public sf::Drawable {
public:
	Button(const sf::Vector2f& size);
	Button(const sf::Vector2f& size,const TextLabel textLabel);
	Button(const sf::Vector2f& size, const sf::Vector2f& pos);
	Button(const sf::Texture texture);

	void mouseButton1Click(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window);

private:
	std::shared_ptr<sf::Sprite> sprite;
	std::shared_ptr <sf::RectangleShape> shape;
	std::shared_ptr<sf::Texture> texture;
	std::shared_ptr<TextLabel> text;
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
};