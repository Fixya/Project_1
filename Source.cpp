#include "settings.h"
#include "functions.h"
#include <ctime>
using namespace sf;

int main()
{
    // Объект, который, собственно, является главным окном приложения
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");

    //гг и противники
    RectangleShape gg, enemy;
    charDescr(gg, ggColor, ggPosition);
    charDescr(enemy, enemyColor, enemyPosition);
    //скорости
    float ggSpeed = 0.f;
    float enemySpeed = 0.f;


    //пули
    CircleShape ggBall, enemyBall;
    initBall(ggBall, ggBallColor);
    initBall(enemyBall, ggBallColor);
    //появление
    ggBall.setPosition(gg.getPosition().x + figureHeight / 2, gg.getPosition().y);
    enemyBall.setPosition(enemy.getPosition().x + figureHeight / 2, enemy.getPosition().y + figureWidth);
    //скорость
    float ggBall_speedy = -0.5;
    float enemyBall_speedy = 0.5;


    //
    int lvl = 0;
    Font font;
    font.loadFromFile("ds-digib.ttf");

    Text textLvl, textLvl1;
    PText(textLvl, font, textPosition);
    PText(textLvl1, font, textPosition1);
    textLvl.setString("Lvl");
    textLvl1.setString(std::to_string(lvl));

    // Главный цикл приложения. Выполняется, пока открыто окно
    while (window.isOpen())
    {
        // Обрабатываем очередь событий в цикле
        Event event;
        while (window.pollEvent(event))
        {
            // Пользователь нажал на «крестик» и хочет закрыть окно?
            if (event.type == Event::Closed)
                // тогда закрываем его
                window.close();
        }
       
        //2 Обновление объектов
        //дваижение пуль
        ggBall.move(0, ggBall_speedy);
        enemyBall.move(0, enemyBall_speedy);

        //движение гг
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
        //чтобы не выходил за границу
        if (gg.getPosition().x <= 0)
        {
            gg.setPosition(0, figureY);
        }
        if (gg.getPosition().x + figureWidth >= WINDOW_WIDTH)
        {
            gg.setPosition(WINDOW_WIDTH - figureWidth, figureY);
        }

        // Отрисовка окна 
        //очистка
        window.clear();
        //отрисовка
        window.draw(gg);
        window.draw(enemy);
        window.draw(ggBall);
        window.draw(enemyBall);
        window.draw(textLvl);
        window.draw(textLvl1);
        //хз что это, но оно важное
        window.display();
    }
    return 0;
}