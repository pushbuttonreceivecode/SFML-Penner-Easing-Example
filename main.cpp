#include <iostream>
#include <SFML/Graphics.hpp>
#include <interpolate.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800,600,32), "Interpolation", sf::Style::Default);
    window.setFramerateLimit(60);

    //set up graphics
    sf::RectangleShape rect;
    rect.setFillColor(sf::Color(255,0,0,255));
    rect.setSize(sf::Vector2f(50.f,50.f));

    std::size_t type = 0;
    sf::Time duration = sf::Time::Zero;

    sf::Clock tickClock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f);

    sf::Event e;
    bool running = true;
    while(running)
    {
        while(window.pollEvent(e))
        {
            if(e.type == sf::Event::Closed)
            {
                window.close();
                return 0;
            }

            if(e.type == sf::Event::KeyPressed)
            {
                switch(e.key.code)
                {
                case sf::Keyboard::Escape:
                {
                    window.close();
                    return 0;
                }
                break;

                case sf::Keyboard::Space:
                {
                    type = 1;
                }
                break;

                case sf::Keyboard::A:
                {
                    type = 2;
                }
                break;

                case sf::Keyboard::S:
                {
                    type = 3;
                }
                break;

                case sf::Keyboard::D:
                {
                    type = 4;
                }
                break;

                case sf::Keyboard::F:
                {
                    type = 5;
                }
                break;

                case sf::Keyboard::G:
                {
                    type = 6;
                }
                break;

                case sf::Keyboard::H:
                {
                    type = 7;
                }
                break;

                case sf::Keyboard::J:
                {
                    type = 8;
                }
                break;

                case sf::Keyboard::K:
                {
                    type = 9;
                }
                break;

                case sf::Keyboard::L:
                {
                    type = 10;
                }
                break;

                case sf::Keyboard::Q:
                {
                    type = 11;
                }
                break;

                case sf::Keyboard::W:
                {
                    type = 12;
                }
                break;

                case sf::Keyboard::E:
                {
                    type = 13;
                }
                break;

                case sf::Keyboard::R:
                {
                    type = 14;
                }
                break;

                case sf::Keyboard::T:
                {
                    type = 15;
                }
                break;

                case sf::Keyboard::Y:
                {
                    type = 16;
                }
                break;

                case sf::Keyboard::U:
                {
                    type = 17;
                }
                break;

                case sf::Keyboard::I:
                {
                    type = 18;
                }
                break;

                case sf::Keyboard::O:
                {
                    type = 19;
                }
                break;

                case sf::Keyboard::P:
                {
                    type = 20;
                }
                break;

                case sf::Keyboard::Z:
                {
                    type = 21;
                }
                break;

                case sf::Keyboard::X:
                {
                    type = 22;
                }
                break;

                case sf::Keyboard::C:
                {
                    type = 23;
                }
                break;

                case sf::Keyboard::V:
                {
                    type = 24;
                }
                break;

                case sf::Keyboard::B:
                {
                    type = 25;
                }
                break;

                case sf::Keyboard::N:
                {
                    type = 26;
                }
                break;

                case sf::Keyboard::M:
                {
                    type = 27;
                }
                break;

                case sf::Keyboard::Num1:
                {
                    type = 28;
                }
                break;

                case sf::Keyboard::Num2:
                {
                    type = 29;
                }
                break;

                case sf::Keyboard::Num3:
                {
                    type = 30;
                }
                break;

                case sf::Keyboard::Num4:
                {
                    type = 31;
                }
                break;

                case sf::Keyboard::Return:
                {
                    type = 0;
                    duration = sf::Time::Zero;
                    rect.setPosition(0.f,0.f);
                }
                break;

                default:
                    break;
                }
            }
        }
        timeSinceLastUpdate += tickClock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;

            if(type > 0)
            {
                duration += TimePerFrame;
                switch(type)
                {
                case 0:
                    break;

                case 1:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::linear(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 2:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::expoEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 3:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::expoEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 4:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::expoEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 5:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::cubicEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 6:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::cubicEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 7:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::cubicEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 8:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quarticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 9:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quarticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 10:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quarticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 11:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quinticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 12:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quinticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 13:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quinticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 14:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quadraticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 15:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quadraticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 16:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::quadraticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 17:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::sineEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 18:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::sineEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 19:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::sineEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 20:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::circularEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 21:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::circularEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 22:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::circularEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 23:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::backEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 24:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::backEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 25:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::backEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 26:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::elasticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 27:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::elasticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 28:
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(20.f * interpolate::elasticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 29://still wonky...
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(30.f * interpolate::bounceEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 30://still wonky...
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(30.f * interpolate::bounceEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                case 31://still wonky...
                {
                    if(duration.asSeconds() < 1.f)
                    rect.move(30.f * interpolate::bounceEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
                break;

                default:
                    break;
                }
                std::cout<<duration.asSeconds()<<std::endl;
                std::cout<<rect.getPosition().x<<std::endl;
            }
        }
        window.clear();
        window.draw(rect);
        window.display();
    }
    return 0;
}
