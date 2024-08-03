#include "Gui.h"

TextLabel::TextLabel(const std::string &fontAsset, const std::string& textName)
{
	font = std::make_shared<sf::Font>();
	font->loadFromFile(fontAsset);
	text.setFont(*font);
	text.setString(textName);
}

void TextLabel::changeFont(const std::string& fontAsset)
{
	font->loadFromFile(fontAsset);
	text.setFont(*font);
}

void TextLabel::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(text, states);
}

Button::Button(const sf::Vector2f& size)
{
	shape = std::make_shared<sf::RectangleShape>();
	shape->setSize(size);
}

Button::Button(const sf::Vector2f& size, const TextLabel textLabel)
{
	shape = std::make_shared<sf::RectangleShape>();
	shape->setSize(size);
	text = std::make_shared<TextLabel>(textLabel);
}

Button::Button(const sf::Vector2f& size, const sf::Vector2f& pos)
{
	shape = std::make_shared<sf::RectangleShape>();
	shape->setSize(size);
	shape->setPosition(pos);
}

Button::Button(const sf::Texture texture)
{

}

void Button::mouseButton1Click(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window)
{
	auto mousePos = sf::Mouse::getPosition(*window);
	auto worldPos = (*window).mapPixelToCoords(mousePos);
	if (shape != nullptr) {
		auto position = shape->getPosition();
		auto size = shape->getSize();
		if (event.type == sf::Event::MouseButtonPressed) 
			if (event.mouseButton.button == sf::Mouse::Left)
		if (worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y) {
			std::cout << "Click" << std::endl;
		}
	}
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (shape != nullptr)
	target.draw(*shape, states);
	else if (sprite != nullptr) target.draw(*sprite, states);
}
