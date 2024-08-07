#include "Gui.h"

TextLabel::TextLabel(const std::string& fontAsset, const std::string& textName)
{
	font = std::make_shared<sf::Font>();
	font->loadFromFile(fontAsset);
	text.setFont(*font);
	text.setString(textName);
	text.setFillColor(sf::Color(125, 125, 125));
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

Button::Button(const TextLabel& label)
{
	textLabel = std::make_shared<TextLabel>(label);
}

Button::Button(const sf::Texture& textureParamater)
{
	try {
		texture = std::make_shared<sf::Texture>(textureParamater);
		sprite = std::make_shared<sf::Sprite>();
		sprite->setTexture(*texture);
	}
	catch (std::exception) {
		std::cout << "Error: Texture not load" << std::endl;
	}
}

void Button::setShapeSize()
{
	if (sprite != nullptr) {
		std::cout << "Error: Shape size can't set on sprite button" << std::endl;
		return;
	}
	if (shape == nullptr)
		shape = std::make_shared<sf::RectangleShape>();
	auto bounds = textLabel->text.getLocalBounds();
	sf::Vector2f textPosition = textLabel->text.getPosition();
	sf::Vector2f pos = sf::Vector2f(textPosition.x + bounds.left, textPosition.y + bounds.top);
	shape->setPosition(pos);
	shape->setSize(sf::Vector2f(bounds.width, bounds.height));
}

void Button::setBackgroundColor(const sf::Color& color)
{
	if (shape != nullptr)
		shape->setFillColor(color);
	else std::cout << "Error: Shape size isn't set" << std::endl;
}

void Button::mouseButton1Click(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& click)
{
	auto mousePos = sf::Mouse::getPosition(*window);
	auto worldPos = (*window).mapPixelToCoords(mousePos);
	if (textLabel != nullptr) {
		if (shape == nullptr) {
			auto bounds = textLabel->text.getLocalBounds();
			auto textPosition = textLabel->text.getPosition();
			auto position = sf::Vector2f(textPosition.x + bounds.left, textPosition.y + bounds.top);
			auto size = sf::Vector2f(bounds.width, bounds.height);
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
					if (worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y) {
						click();
					}
		}
		else {
			auto position = shape->getPosition();
			auto size = shape->getSize();
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Left)
					if (worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y) {
						click();
					}
		}
	}
	else {
		if (sprite == nullptr) {
			std::cout << "Error: Texture not load" << std::endl;
			return;
		}
		auto bounds = sprite->getLocalBounds();
		auto position = sprite->getPosition();
		if (event.type == sf::Event::MouseButtonPressed)
			if (event.mouseButton.button == sf::Mouse::Left)
				if (worldPos.x >= position.x && worldPos.x <= position.x + bounds.width && worldPos.y >= position.y && worldPos.y <= position.y + bounds.height) {
					click();
				}
	}
}

void Button::mouseButton2Click(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& click)
{
	auto mousePos = sf::Mouse::getPosition(*window);
	auto worldPos = (*window).mapPixelToCoords(mousePos);
	if (textLabel != nullptr) {
		if (shape == nullptr) {
			auto bounds = textLabel->text.getLocalBounds();
			auto textPosition = textLabel->text.getPosition();
			auto position = sf::Vector2f(textPosition.x + bounds.left, textPosition.y + bounds.top);
			auto size = sf::Vector2f(bounds.width, bounds.height);
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Right)
					if (worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y) {
						click();
					}
		}
		else {
			auto position = shape->getPosition();
			auto size = shape->getSize();
			if (event.type == sf::Event::MouseButtonPressed)
				if (event.mouseButton.button == sf::Mouse::Right)
					if (worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y) {
						click();
					}
		}
	}
	else {
		if (sprite == nullptr) {
			std::cout << "Error: Texture not load" << std::endl;
			return;
		}
		auto bounds = sprite->getLocalBounds();
		auto position = sprite->getPosition();
		if (event.type == sf::Event::MouseButtonPressed)
			if (event.mouseButton.button == sf::Mouse::Right)
				if (worldPos.x >= position.x && worldPos.x <= position.x + bounds.width && worldPos.y >= position.y && worldPos.y <= position.y + bounds.height) {
					click();
				}
	}
}

void Button::mouseButtonHover(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& hover)
{
	if (!isHover) {
		auto mousePos = sf::Mouse::getPosition(*window);
		auto worldPos = (*window).mapPixelToCoords(mousePos);
		if (textLabel != nullptr) {
			if (shape == nullptr) {
				auto bounds = textLabel->text.getLocalBounds();
				auto textPosition = textLabel->text.getPosition();
				auto position = sf::Vector2f(textPosition.x + bounds.left, textPosition.y + bounds.top);
				auto size = sf::Vector2f(bounds.width, bounds.height);
				if (worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y) {
					isHover = true;
					hover();
				}
			}
			else {
				auto position = shape->getPosition();
				auto size = shape->getSize();
				if (worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y) {
					isHover = true;
					hover();
				}
			}
		}
		else {
			if (sprite == nullptr) {
				std::cout << "Error: Texture not load" << std::endl;
				return;
			}
			auto bounds = sprite->getLocalBounds();
			auto position = sprite->getPosition();
			if (worldPos.x >= position.x && worldPos.x <= position.x + bounds.width && worldPos.y >= position.y && worldPos.y <= position.y + bounds.height) {
				isHover = true;
				hover();
			}
		}
	}
}

void Button::mouseButtonUnHover(const sf::Event& event, std::shared_ptr<sf::RenderWindow> window, const callbackButton& hover)
{
	if (isHover) {
		auto mousePos = sf::Mouse::getPosition(*window);
		auto worldPos = (*window).mapPixelToCoords(mousePos);
		if (textLabel != nullptr) {
			if (shape == nullptr) {
				auto bounds = textLabel->text.getLocalBounds();
				auto textPosition = textLabel->text.getPosition();
				auto position = sf::Vector2f(textPosition.x + bounds.left, textPosition.y + bounds.top);
				auto size = sf::Vector2f(bounds.width, bounds.height);
				bool condition = worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y;
				if (!condition) {
					isHover = false;
					hover();
				}
			}
			else {
				auto position = shape->getPosition();
				auto size = shape->getSize();
				bool condition = worldPos.x >= position.x && worldPos.x <= position.x + size.x && worldPos.y >= position.y && worldPos.y <= position.y + size.y;
				if (!condition) {
					isHover = false;
					hover();
				}
			}
		}
		else {
			if (sprite == nullptr) {
				std::cout << "Error: Texture not load" << std::endl;
				return;
			}
			auto bounds = sprite->getLocalBounds();
			auto position = sprite->getPosition();
			bool condition = worldPos.x >= position.x && worldPos.x <= position.x + bounds.width && worldPos.y >= position.y && worldPos.y <= position.y + bounds.height;
			if (!condition) {
				isHover = false;
				hover();
			}
		}
	}
}

void Button::addShapeSize(const sf::Vector2f& size)
{
	if (shape != nullptr) {
		shape->setSize(shape->getSize() + size);
		auto textPosition = textLabel->text.getPosition();
		auto bounds = textLabel->text.getLocalBounds();
		auto position = sf::Vector2f(textPosition.x + bounds.left, textPosition.y + bounds.top);
		shape->setPosition(position.x - size.x / 2, position.y - size.y / 2);
		shape->setSize(shape->getSize() + size);
		textLabel->text.setPosition(textPosition.x + size.x / 2, textPosition.y + size.y / 2);
		addedShapeSize = std::make_unique<sf::Vector2f>(sf::Vector2f(size.x, size.y));
	}
	else std::cout << "Error: Shape size isn't set" << std::endl;
}

void Button::setPosition(const sf::Vector2f& position) {
	if (textLabel != nullptr) {
		textLabel->text.setPosition(position);
	}
	else {
		if (sprite == nullptr) {
			std::cout << "Error: Texture not load" << std::endl;
			return;
		}
		sprite->setPosition(position);
		return;
	}

	if (shape != nullptr) {
		auto textBounds = textLabel->text.getLocalBounds();
		auto textPosition = textLabel->text.getPosition();

		auto shapePosition = sf::Vector2f(
			position.x + textBounds.left,
			position.y + textBounds.top
		);

		shape->setPosition(shapePosition);
	}
}

void  Button::setTextColor(const sf::Color& color) {
	if (textLabel != nullptr) {
		textLabel->text.setFillColor(color);
	}
	else std::cout << "Error: Text label isn't set" << std::endl;
}

void Button::setTextOutlineColor(const sf::Color& color)
{
	if (textLabel != nullptr) {
		textLabel->text.setOutlineColor(color);
	}
	else std::cout << "Error: Text label isn't set" << std::endl;
}

void  Button::setTextFontSize(uint32_t size) {
	if (textLabel != nullptr) {
		textLabel->text.setCharacterSize(size);
		if (shape != nullptr) {
			setPosition(textLabel->text.getPosition());
			setShapeSize();
			if (addedShapeSize != nullptr)
				addShapeSize(*addedShapeSize);
		}
	}
	else std::cout << "Error: Text label isn't set" << std::endl;
}

void Button::setTextOutlineThickness(float thickness) {
	if (textLabel != nullptr) {
		textLabel->text.setOutlineThickness(thickness);
	}
	else std::cout << "Error: Text label isn't set" << std::endl;
}

void Button::setText(const std::string& text) {
	if (textLabel != nullptr) {
		textLabel->text.setString(text);
	}
	else std::cout << "Error: Text label isn't set" << std::endl;
}

sf::FloatRect Button::getLocalBoundsText() {
	if (textLabel != nullptr) {
		return textLabel->text.getLocalBounds();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return sf::FloatRect();
}

sf::FloatRect Button::getGlobalBoundsText() {
	if (textLabel != nullptr) {
		return textLabel->text.getGlobalBounds();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return sf::FloatRect();
}

void Button::setStyleText(sf::Uint32 style) {
	if (textLabel != nullptr) {
		textLabel->text.setStyle(style);
	}
	std::cout << "Error: Text label isn't set" << std::endl;
}

float Button::getTextOutlineThickness()
{
	if (textLabel != nullptr) {
		return  textLabel->text.getOutlineThickness();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return 0;
}

sf::Uint32 Button::getStyleText() {
	if (textLabel != nullptr) {
		return  textLabel->text.getStyle();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return 0;
}

void  Button::setShapeOutlineColor(const sf::Color& color) {
	if (shape != nullptr) {
		shape->setOutlineColor(color);
	}
	else
		std::cout << "Error: Shape size isn't set" << std::endl;
}

sf::Color Button::getShapeOutlineColor() {
	if (shape != nullptr) {
		return shape->getOutlineColor();
	}
	std::cout << "Error: Shape size isn't set" << std::endl;
	return sf::Color();
}

void Button::setShapeOutlineThickness(float thickness) {
	if (shape != nullptr) {
		shape->setOutlineThickness(thickness);
	}
	else
		std::cout << "Error: Shape size isn't set" << std::endl;
}

float Button::getShapeOutlineThickness() {
	if (shape != nullptr) {
		return shape->getOutlineThickness();
	}
	std::cout << "Error: Shape size isn't set" << std::endl;
	return 0;
}

std::string Button::getText() {
	if (textLabel != nullptr) {
		return textLabel->text.getString();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return std::string();
}

sf::Color  Button::getTextColor() {
	if (textLabel != nullptr) {
		return textLabel->text.getFillColor();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return sf::Color();
}

sf::Color Button::getTextOutlineColor() {
	if (textLabel != nullptr) {
		return textLabel->text.getOutlineColor();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return sf::Color();
}

uint32_t Button::getTextFontSize() {
	if (textLabel != nullptr) {
		return textLabel->text.getCharacterSize();
	}
	std::cout << "Error: Text label isn't set" << std::endl;
	return 0;
}

sf::Vector2f Button::getPosition() {
	if (shape != nullptr) {
		return shape->getPosition();
	}

	if (textLabel != nullptr) {
		return textLabel->text.getPosition();
	}

	if (sprite == nullptr) {
		std::cout << "Error: Texture not load" << std::endl;
		return sf::Vector2f(0, 0);
	}
	return sprite->getPosition();
}

sf::Vector2f Button::getShapeSize() {
	if (shape != nullptr) {
		return shape->getSize();
	}
	std::cout << "Error: Shape size isn't set" << std::endl;
	return sf::Vector2f(0, 0);
}

sf::Color Button::getBackgroundColor() {
	if (shape != nullptr) {
		return shape->getFillColor();
	}
	std::cout << "Error: Shape size isn't set" << std::endl;
	return sf::Color();
}

void Button::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	if (textLabel != nullptr) {
		if (shape != nullptr)
		{
			target.draw(*shape, states);
			target.draw(*textLabel, states);
		}
		else target.draw(*textLabel, states);

	}
	else if (sprite != nullptr) target.draw(*sprite, states);
}
