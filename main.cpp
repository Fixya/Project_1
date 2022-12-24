#include "settings.h"
#include "functions.h"
#include <ctime>
using namespace sf;

int main()
{
	// Îáúåêò, êîòîðûé, ñîáñòâåííî, ÿâëÿåòñÿ ãëàâíûì îêíîì ïðèëîæåíèÿ
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");

	//ãã è ïðîòèâíèêè
	RectangleShape gg, enemy;
	charDescr(gg, ggColor, ggPosition);
	charDescr(enemy, enemyColor, enemyPosition);
	//ñêîðîñòè
	float ggSpeed = 0.f;
	float enemySpeed = 0.f;


	//ïóëè
	CircleShape ggBall[size], enemyBall[size];
	/*initBall(ggBall[1000], ggBallColor);
	initBall(ggBall2, ggBallColor);
	initBall(ggBall3, ggBallColor);*/
	//initBall(enemyBall, enemyBallColor);
	//ïîÿâëåíèå
	for (int i = 0; i < size; i++)
	{
		initBall(ggBall[i], ggBallColor);
		ggBall[i].setPosition(gg.getPosition().x + figureHeight / 2 - ballRadius, gg.getPosition().y);
	}
	for (int i = 0; i < size; i++)
	{
		initBall(enemyBall[i], enemyBallColor);
		enemyBall[i].setPosition(enemy.getPosition().x + figureHeight / 2 - ballRadius, enemy.getPosition().y + figureWidth- ballRadius*2);
	}
	/*ggBall[1000].setPosition(gg.getPosition().x + figureHeight / 2, gg.getPosition().y);
	ggBall2.setPosition(gg.getPosition().x + figureHeight / 2, gg.getPosition().y);
	ggBall3.setPosition(gg.getPosition().x + figureHeight / 2, gg.getPosition().y);*/
	//enemyBall.setPosition(enemy.getPosition().x + figureHeight / 2, enemy.getPosition().y + figureWidth);
	//ñêîðîñòü
	float ggBall_speedy = -1;
	float enemyBall_speedy = 1;

	


	//
	int lvl = 1;
	Font font;
	font.loadFromFile("ds-digib.ttf");

	Text textLvl, textLvl1;
	PText(textLvl, font, textPosition);
	PText(textLvl1, font, textPosition1);
	textLvl.setString("Lvl");
	textLvl1.setString(std::to_string(lvl));

	// Ãëàâíûé öèêë ïðèëîæåíèÿ. Âûïîëíÿåòñÿ, ïîêà îòêðûòî îêíî
	while (window.isOpen())
	{
		// Îáðàáàòûâàåì î÷åðåäü ñîáûòèé â öèêëå
		Event event;
		while (window.pollEvent(event))
		{
			// Ïîëüçîâàòåëü íàæàë íà «êðåñòèê» è õî÷åò çàêðûòü îêíî?
			if (event.type == Event::Closed)
				// òîãäà çàêðûâàåì åãî
				window.close();
		}

		//2 Îáíîâëåíèå îáúåêòîâ
		//äâàèæåíèå ïóëü
		for (int i = 0; i < size + 1; i++)
		{
			ggBall[i].move(0, ggBall_speedy);
			if (ggBall[i].getPosition().y >= WINDOW_HEIGHT / 2)
			{
				ggBall[i+1].setPosition(gg.getPosition().x + figureHeight / 2 - ballRadius , gg.getPosition().y);
			}
			if ((ggBall[i].getPosition().y <= enemy.getPosition().y && ggBall[i].getPosition().y <= enemy.getPosition().y + figureHeight) && ggBall[i].getPosition().x <= enemy.getPosition().x)
			{
				enemy.setFillColor(Color::Black);
			}

		}
		for (int i = 0; i < size + 1; i++)
		{
			enemyBall[i].move(0, enemyBall_speedy);
			if (enemyBall[i].getPosition().y <= WINDOW_HEIGHT / 2)
			{
				enemyBall[i + 1].setPosition(enemy.getPosition().x + figureHeight / 2 - ballRadius, enemy.getPosition().y + figureWidth - ballRadius*2);
			}
		}


		//äâèæåíèå ãã
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
		//÷òîáû íå âûõîäèë çà ãðàíèöó
		if (gg.getPosition().x <= 0)
		{
			gg.setPosition(0, figureY);
		}
		if (gg.getPosition().x + figureWidth >= WINDOW_WIDTH)
		{
			gg.setPosition(WINDOW_WIDTH - figureWidth, figureY);
		}

		

		// Îòðèñîâêà îêíà 
		//î÷èñòêà
		window.clear();
		//îòðèñîâêà
		window.draw(gg);
		window.draw(enemy);
		for (int i = 0; i < size; i++)
		{
			window.draw(ggBall[i]);
		}
		/*window.draw(ggBall2);
		window.draw(ggBall3);*/
		for (int i = 0; i < size; i++)
		{
			window.draw(enemyBall[i]);
		}
		window.draw(textLvl);
		window.draw(textLvl1);
		//õç ÷òî ýòî, íî îíî âàæíîå
		window.display();
	}
	return 0;
}
