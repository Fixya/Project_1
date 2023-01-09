#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;
const long size = 300;
const int doubl = 5;

const float figureWidth = 60.f;
const float figureHeight = figureWidth;
const float figureOffset = 25;
const float figureY = WINDOW_HEIGHT - (figureOffset + figureHeight);
const sf::Vector2f figureSize(figureWidth, figureHeight);
const sf::Vector2f TextSize(250, 175);
const sf::Color ggColor{ sf::Color::Yellow };
const sf::Color enemyColor{ sf::Color::Red };
const float figureSpeed = 0.5;
const sf::Vector2f ggPosition{ WINDOW_WIDTH / 2 - figureWidth / 2 , figureY };
const sf::Vector2f enemyPosition{ WINDOW_WIDTH / 2 - figureWidth / 2, figureOffset };
const sf::Vector2f enemyPosition1{ WINDOW_WIDTH / 2 - figureWidth - 50, figureOffset + figureHeight + 25 };
const sf::Vector2f enemyPosition2{ WINDOW_WIDTH / 2 + 50, figureOffset + figureHeight + 25 };
const sf::Vector2f enemyPosition3{ WINDOW_WIDTH / 2 - figureWidth - figureWidth / 2 - 100, figureOffset };
const sf::Vector2f enemyPosition4{ WINDOW_WIDTH / 2 + figureWidth / 2 + 100, figureOffset };
const sf::Vector2f textRectPosition{ WINDOW_WIDTH / 2 - 125, WINDOW_HEIGHT / 2 - 83 };

const float ballRadius = 10.f;

const sf::Color ggBallColor{ sf::Color::Yellow };
const sf::Color enemyBallColor{ sf::Color::Red };

const sf::Vector2f textPosition{ 10.f, 10.f };
const sf::Vector2f textPosition1{ 70.f, 10.f };
const sf::Vector2f textPosition2{ 10.f, WINDOW_HEIGHT - 40 };
const sf::Vector2f textPosition3{ 50.f, WINDOW_HEIGHT - 40 };
const sf::Vector2f textPosition4{ WINDOW_WIDTH - 15, WINDOW_HEIGHT / 2 };