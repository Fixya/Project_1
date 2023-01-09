#include "settings.h"
#include "functions.h"
#include <ctime>
using namespace sf;

int main()
{
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works");

	//1
	
	RectangleShape gg, enemy[doubl], textRect;
	charDescr(textRect, enemyColor, textRectPosition);
	textRect.setSize(TextSize);
	textRect.setFillColor(Color::Green);

	charDescr(gg, ggColor, ggPosition);
	for (int i = 0; i < doubl; i++)
	{
		charDescr2(enemy[i], enemyColor);
	}
	enemy[0].setPosition(enemyPosition);
	enemy[1].setPosition(enemyPosition1);
	enemy[2].setPosition(enemyPosition2);
	enemy[3].setPosition(enemyPosition3);
	enemy[4].setPosition(enemyPosition4);
	
	float ggSpeed = 0.f;
	float enemySpeed = 0.f;


	CircleShape ggBall[size], enemyBall[size][doubl];

	for (long i = 0; i < size; i++)
	{
		initBall(ggBall[i], ggBallColor);
		ggBall[i].setPosition(gg.getPosition().x + figureHeight / 2 - ballRadius, gg.getPosition().y);
	}

	for (int i = 0; i < doubl; i++)
	{
		for (long j = 0; j < size; j++)
		{
			initBall(enemyBall[j][i], enemyBallColor);
			enemyBall[j][i].setPosition(enemy[i].getPosition().x + figureHeight / 2 - ballRadius, enemy[i].getPosition().y + figureWidth - ballRadius * 2);
		}
	}
	float ggBall_speedy = -0.5;
	float enemyBall_speedy[doubl];
	for (int i = 0; i < doubl; i++)
	{
		enemyBall_speedy[i] = 0.4;
	}

	int lvl = 1, hp = 3;
	Font font;
	font.loadFromFile("ds-digib.ttf");

	Text textLvl, textLvl1, textHp, textHp1, text;
	PText(textLvl, font, textPosition);
	PText(textLvl1, font, textPosition1);
	PText(textHp, font, textPosition2);
	PText(textHp1, font, textPosition3);
	PText(text, font, textPosition4);

	textLvl.setString("Lvl");
	textLvl1.setString(std::to_string(lvl));
	textHp.setString("Hp");
	textHp1.setString(std::to_string(hp));
	text.setString("Press 2 to continue");

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

		//2
		for (long i = 0; i < size - 1; i++)
		{
			ggBall[i].move(0, ggBall_speedy);
			if (ggBall[i].getPosition().y >= WINDOW_HEIGHT / 2)
			{
				ggBall[i + 1].setPosition(gg.getPosition().x + figureHeight / 2 - ballRadius, gg.getPosition().y);
			}
		}
		for (int j = 0; j < doubl; j++)
		{
			for (long i = 0; i < size - 1; i++)
			{
				enemyBall[i][j].move(0, enemyBall_speedy[j]);
				if (enemyBall[i][j].getPosition().y <= WINDOW_HEIGHT / 2)
				{
					enemyBall[i + 1][j].setPosition(enemy[j].getPosition().x + figureHeight / 2 - ballRadius, enemy[j].getPosition().y + figureWidth - ballRadius * 2);
				}
			}
		}


		if (Keyboard::isKeyPressed(Keyboard::S))
		{
			ggSpeed = -figureSpeed;
		}
		if (Keyboard::isKeyPressed(Keyboard::D))
		{
			ggSpeed = figureSpeed;
		}
		gg.move(ggSpeed, 0);
		ggSpeed = 0.f;

		if (gg.getPosition().x <= 0)
		{
			gg.setPosition(0, figureY);
		}
		if (gg.getPosition().x + figureWidth >= WINDOW_WIDTH)
		{
			gg.setPosition(WINDOW_WIDTH - figureWidth, figureY);
		}
		
		for (int j = 0; j < doubl; j++)
		{
			for (long i = 0; i < size; i++)
			{
				if (enemy[j].getPosition().y + figureHeight == ggBall[i].getPosition().y && enemy[j].getPosition().x <= ggBall[i].getPosition().x + ballRadius && ggBall[i].getPosition().x + ballRadius <= enemy[j].getPosition().x + figureWidth)
				{
					for (long l = 0; l < size; l++)
					{
						enemyBall_speedy[j] = 0;
						enemyBall[l][j].setFillColor(Color::Black);
						enemyBall[l][j].setPosition(enemy[j].getPosition().x + figureHeight / 2 - ballRadius, enemy[j].getPosition().y + figureWidth - ballRadius * 2);
						enemy[j].setFillColor(Color::Black);
					}
				}
			}
		}
		

		if (hp != 0)
		{
			for (int j = 0; j < doubl; j++)
			{
				for (long i = 0; i < size; i++)
				{
					if (gg.getPosition().y == enemyBall[i][j].getPosition().y + ballRadius * 2 && gg.getPosition().x <= enemyBall[i][j].getPosition().x && enemyBall[i][j].getPosition().x <= gg.getPosition().x + figureWidth)
					{
						hp--;
						textHp1.setString(std::to_string(hp));
					}
				}
			}
		}
		if (hp == 0)
		{
			ggBall_speedy = 0;
			for (int i = 0; i < doubl; i++)
			{
				enemyBall_speedy[i] = 0;
			}
		}
		window.clear();
		window.draw(gg);
		for (int i = 0; i < doubl; i++)
		{
			window.draw(enemy[i]);
		}
		for (long i = 0; i < size; i++)
		{
			window.draw(ggBall[i]);
		}
		for (int j = 0; j < doubl; j++)
		{
			for (long i = 0; i < size; i++)
			{
				window.draw(enemyBall[i][j]);
			}
		}
		window.draw(textLvl);
		window.draw(textLvl1);
		window.draw(textHp);
		window.draw(textHp1);
		if (Keyboard::isKeyPressed(Keyboard::O))
		{
			window.draw(textRect);
			window.draw(text);
		}
		window.display();
	}
	return 0;
}