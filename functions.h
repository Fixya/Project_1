#pragma once
#include "SFML/Graphics.hpp"

void charDescr(sf::RectangleShape& figure, const sf::Color Color, const sf::Vector2f Position)
{
	figure.setSize(figureSize);
	figure.setFillColor(Color);
	figure.setPosition(Position);
}
void charDescr2(sf::RectangleShape& figure, const sf::Color Color)
{
	figure.setSize(figureSize);
	figure.setFillColor(Color);
}
void initBall(sf::CircleShape& ball, const sf::Color ballColor)
{
	ball.setRadius(ballRadius);
	ball.setFillColor(ballColor);
}
void PText(sf::Text& PText, sf::Font& font, const sf::Vector2f textPosition)
{
	PText.setFont(font);
	PText.setCharacterSize(30);
	PText.setPosition(textPosition);
}