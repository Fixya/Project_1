#include "settings.h"
#include "functions.h"
#include <ctime>
using namespace sf;

int main()
{
    // ������, �������, ����������, �������� ������� ����� ����������
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "SFML Works!");

    //�� � ����������
    RectangleShape gg, enemy;
    charDescr(gg, ggColor, ggPosition);
    charDescr(enemy, enemyColor, enemyPosition);
    //��������
    float ggSpeed = 0.f;
    float enemySpeed = 0.f;


    //����
    CircleShape ggBall, enemyBall;
    initBall(ggBall, ggBallColor);
    initBall(enemyBall, ggBallColor);
    //���������
    ggBall.setPosition(gg.getPosition().x + figureHeight / 2, gg.getPosition().y);
    enemyBall.setPosition(enemy.getPosition().x + figureHeight / 2, enemy.getPosition().y + figureWidth);
    //��������
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

    // ������� ���� ����������. �����������, ���� ������� ����
    while (window.isOpen())
    {
        // ������������ ������� ������� � �����
        Event event;
        while (window.pollEvent(event))
        {
            // ������������ ����� �� �������� � ����� ������� ����?
            if (event.type == Event::Closed)
                // ����� ��������� ���
                window.close();
        }
       
        //2 ���������� ��������
        //��������� ����
        ggBall.move(0, ggBall_speedy);
        enemyBall.move(0, enemyBall_speedy);

        //�������� ��
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
        //����� �� ������� �� �������
        if (gg.getPosition().x <= 0)
        {
            gg.setPosition(0, figureY);
        }
        if (gg.getPosition().x + figureWidth >= WINDOW_WIDTH)
        {
            gg.setPosition(WINDOW_WIDTH - figureWidth, figureY);
        }

        // ��������� ���� 
        //�������
        window.clear();
        //���������
        window.draw(gg);
        window.draw(enemy);
        window.draw(ggBall);
        window.draw(enemyBall);
        window.draw(textLvl);
        window.draw(textLvl1);
        //�� ��� ���, �� ��� ������
        window.display();
    }
    return 0;
}