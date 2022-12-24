#pragma once
#include <SFML/Graphics.hpp>

const float WINDOW_WIDTH = 800;
const float WINDOW_HEIGHT = 600;
const std::string WINDOW_TITLE = "SFML Lesson2";
const float FPS = 60.f;

const float figureWidth = 60.f;
const float figureHeight = figureWidth;
const float figureOffset = 25;
const float figureY = WINDOW_HEIGHT - (figureOffset + figureHeight);
const sf::Vector2f figureSize(figureWidth, figureHeight);
const sf::Color ggColor{ 158,20,37 };
const sf::Color enemyColor{ 20,158,49 };
const float figureSpeed = 0.1;
const sf::Vector2f ggPosition{ WINDOW_WIDTH / 2 - figureWidth / 2 , figureY };
const sf::Vector2f enemyPosition{ WINDOW_WIDTH / 2 - figureWidth / 2, figureOffset };

const float ballRadius = 10.f;
const sf::Color ggBallColor{ sf::Color::Yellow };
const sf::Color enemyBallColor{ sf::Color::Red };

const sf::Vector2f textPosition{ 10.f, 10.f };
const sf::Vector2f textPosition1{ 60.f, 10.f };