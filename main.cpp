#include <iostream>
#include <SFML/Graphics.hpp>
#include <THOR/Shapes.hpp>
#include <THOR/Graphics.hpp>
#include <button.hpp>
#include <interpolate.hpp>

int main(void)
{
    sf::RenderWindow window(sf::VideoMode(800,600,32), "Robert Penner's Easing Equations with SFML", sf::Style::Default);
    window.setFramerateLimit(60);

    sf::Event e;
    bool running = true;

    sf::Font myfont;
    if(!myfont.loadFromFile("fonts/contb.ttf"))
    {
        std::cerr<<"Could not load your font contb.ttf."<<std::endl;
    }

    //set up a canvas to showcase the easing
    sf::RectangleShape line(sf::Vector2f(800, 1));
    line.setPosition(0.f, 75.f);

    //smooth curve ease in
    gui::button smoothin("Ease In\nDemo", myfont, sf::Vector2f(50.f,54.f), gui::style::clean);
    smoothin.setSize(14);
    smoothin.makeActive(true);
    smoothin.setLabelOffset(sf::Vector2f(0.f,5.f));//use this because the line breaks interfere with the alignment of the label
    smoothin.setBorderThickness(1.f);
    smoothin.setBorderRadius(0.f);
    smoothin.setBorderColor(sf::Color(255,255,255,255));

    //smooth curve ease out
    gui::button smoothout("Ease Out\nDemo", myfont, sf::Vector2f(smoothin.getPosition().x + smoothin.getDimensions().x + 20.f,53.f), gui::style::clean);
    smoothout.setSize(14);
    smoothout.setLabelOffset(sf::Vector2f(0.f,5.f));
    smoothout.makeActive(true);
    smoothout.setBorderThickness(1.f);
    smoothout.setBorderRadius(0.f);
    smoothout.setBorderColor(sf::Color(255,255,255,255));

    //smooth curve ease in out
    gui::button smoothInOut("Ease In-Out\nDemo", myfont, sf::Vector2f(smoothout.getPosition().x + smoothout.getDimensions().x + 20.f,53.f), gui::style::clean);
    smoothInOut.setSize(14);
    smoothInOut.setLabelOffset(sf::Vector2f(0.f,5.f));
    smoothInOut.makeActive(true);
    smoothInOut.setBorderThickness(1.f);
    smoothInOut.setBorderRadius(0.f);
    smoothInOut.setBorderColor(sf::Color(255,255,255,255));

    //set up shapes to ease
    sf::ConvexShape star = thor::Shapes::star(5,2.f, 10.f, sf::Color(255,255,255,255), 1.f, sf::Color(255,0,0,255));
    sf::ConvexShape box = thor::Shapes::roundedRect(sf::Vector2f(20.f,20.f), 5.f, sf::Color(255,255,255,255), 1.f, sf::Color(255,255,255,255));
    sf::ConvexShape poly = thor::Shapes::polygon(5, 10.f, sf::Color(255,255,0,255), 1.f, sf::Color(255,0,255,255));
    sf::CircleShape circ;
    circ.setRadius(10.f);
    circ.setFillColor(sf::Color(0,255,0,255));

    sf::ConvexShape star2 = star;
    sf::ConvexShape box2 = box;
    sf::CircleShape circ2 = circ;
    sf::ConvexShape star3 = star;
    sf::ConvexShape box3 = box;
    sf::ConvexShape poly3 = poly;

    //initialize shape positions
    star.setPosition(140.f, 100.f);
    box.setPosition(140.f, 125.f);
    poly.setPosition(140.f, 170.f);
    circ.setPosition(140.f, 200.f);
    star2.setPosition(140.f, 240.f);
    box2.setPosition(140.f, 270.f);
    circ2.setPosition(140.f, 310.f);
    star3.setPosition(140.f, 350.f);
    box3.setPosition(140.f, 380.f);
    poly3.setPosition(140.f, 430.f);

    //set up labels
    sf::Text label("Linear\n\nExponential\n\nCubic\n\nQuartic\n\nQuintic\n\nQuadratic\n\nSinusoidal\n\nCircular\n\nBack\n\nElastic", myfont);
    label.setPosition(10.f, 90.f);
    label.setCharacterSize(18);

    std::size_t easetype = 0;
    sf::Clock tickClock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    sf::Time duration = sf::Time::Zero;
    sf::Time TimePerFrame = sf::seconds(1.f/60.f);

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

                case sf::Keyboard::Return:
                {
                    duration = sf::Time::Zero;
                }
                break;

                default:
                    break;
                }
            }
            if(e.type == sf::Event::MouseButtonPressed && e.mouseButton.button == sf::Mouse::Left)
            {
                duration = sf::Time::Zero;
                star.setPosition(140.f, 100.f);
                box.setPosition(140.f, 125.f);
                poly.setPosition(140.f, 170.f);
                circ.setPosition(140.f, 200.f);
                star2.setPosition(140.f, 240.f);
                box2.setPosition(140.f, 270.f);
                circ2.setPosition(140.f, 310.f);
                star3.setPosition(140.f, 350.f);
                box3.setPosition(140.f, 380.f);
                poly3.setPosition(140.f, 430.f);
            }
        }

        //perform updates
        smoothin.update(e,window);
        smoothout.update(e,window);
        smoothInOut.update(e,window);

        if(smoothin.getState() == gui::state::active)
        {
            easetype = 0;
        }
        else if(smoothout.getState() == gui::state::active)
        {
            easetype = 1;
        }
        else if(smoothInOut.getState() == gui::state::active)
        {
            easetype = 2;
        }

        timeSinceLastUpdate += tickClock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            duration += TimePerFrame;
            switch(easetype)
            {
            case 0:
            {
                if(duration.asSeconds() < 1.f)
                {
                    star.move(10.f*interpolate::linear(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box.move(10.f*interpolate::expoEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    poly.move(10.f*interpolate::cubicEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    circ.move(10.f*interpolate::quarticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    star2.move(10.f*interpolate::quinticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box2.move(10.f*interpolate::quadraticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    circ2.move(10.f*interpolate::sineEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    star3.move(10.f*interpolate::circularEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box3.move(10.f*interpolate::backEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    poly3.move(10.f*interpolate::elasticEaseIn(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
            }
            break;
            case 1:
            {
                if(duration.asSeconds() < 1.f)
                {
                    star.move(10.f*interpolate::linear(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box.move(10.f*interpolate::expoEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    poly.move(10.f*interpolate::cubicEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    circ.move(10.f*interpolate::quarticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    star2.move(10.f*interpolate::quinticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box2.move(10.f*interpolate::quadraticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    circ2.move(10.f*interpolate::sineEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    star3.move(10.f*interpolate::circularEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box3.move(10.f*interpolate::backEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    poly3.move(10.f*interpolate::elasticEaseOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
            }
            break;
            case 2:
            {
                if(duration.asSeconds() < 1.f)
                {
                    star.move(10.f*interpolate::linear(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box.move(10.f*interpolate::expoEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    poly.move(10.f*interpolate::cubicEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    circ.move(10.f*interpolate::quarticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    star2.move(10.f*interpolate::quinticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box2.move(10.f*interpolate::quadraticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    circ2.move(10.f*interpolate::sineEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    star3.move(10.f*interpolate::circularEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    box3.move(10.f*interpolate::backEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                    poly3.move(10.f*interpolate::elasticEaseInOut(duration.asSeconds(), 0.f, 1.f, 1.f), 0.f);
                }
            }
            break;

            default:
                break;
            }
        }

        window.clear();
        window.draw(line);
        window.draw(smoothin);
        window.draw(smoothout);
        window.draw(smoothInOut);
        window.draw(label);
        window.draw(star);
        window.draw(box);
        window.draw(poly);
        window.draw(circ);
        window.draw(star2);
        window.draw(box2);
        window.draw(circ2);
        window.draw(star3);
        window.draw(box3);
        window.draw(poly3);
        window.display();
    }
    return 0;
}
