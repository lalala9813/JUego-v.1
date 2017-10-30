#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Audio.hpp>


int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Dragon Ball Super");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(true);
   //**********************************************
   sf::Texture fondo;
   fondo.loadFromFile("fondo.png");
   //################################
   sf::Sprite espacio;
   espacio.setTexture(fondo);
   espacio.setColor(sf::Color(255, 255, 255,255));

   //**********************************************
   sf::Texture nave;
   nave.loadFromFile("nave.png");
   //################################
   sf::Sprite naveF;
   naveF.setTexture(nave);
   int x=250, y=550;
   naveF.move(sf::Vector2f(x,y));
   naveF.scale(sf::Vector2f(0.7, 0.4));

    //*********************************************
    sf::Texture esfera;
   esfera.loadFromFile("esfera.png");
   //################################
   sf::Sprite bala;
   bala.setTexture(esfera);
   bala.move(sf::Vector2f(275,540));
    //*********************************************
    //***MUSICA****
    sf::Music music;
    music.openFromFile("lb.wav");
    music.setVolume(50);

    music.play();

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //****MOve*********************************
        float ladoIzq = naveF.getPosition().x;
        float ladoDer = naveF.getPosition().x;
        float anchoArb = naveF.getPosition().y;
        float anchoAbj = naveF.getPosition().y;
        //*******************************************
        float anchoArb2 = bala.getPosition().y;
        float anchoAbj2 = bala.getPosition().y;
        //*******************************************
       if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && ladoIzq<=520)
        {
            naveF.move(10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && ladoDer>=10)
        {
            naveF.move(-10, 0);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && anchoArb>=10)
        {
            naveF.move(0, -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && anchoAbj<=550)
        {
            naveF.move(0, 10);
        }
        //****BALA*********************************
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z)&& anchoArb2>=10)
        {
            bala.move(0, -10);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)&& anchoAbj2<=560)
        {
            bala.move(0, 10);
        }



        window.clear();
        window.draw(espacio);
        window.draw(naveF);
        window.draw(bala);
        window.display();
    }

    return 0;
}
