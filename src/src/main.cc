#include <fstream>
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

#include "readmap.hh"
#include "map.hh"
#include "tile.hh"
#include "world.hh"

int main()
{
    sf::RenderWindow window (sf::VideoMode(800, 600), "llama");
    std::ifstream mapf("Bush.map"), assf("Bush.ass");

    Map map = readmap(mapf, assf);

    World world(map);
    sf::Texture u;

    if (!u.loadFromFile("Tower.png"))
    {
        return 0;
    }

    while (window.isOpen())
    {
        sf::Event ev;

        while (window.pollEvent(ev))
        {
            switch (ev.type)
            {
            case sf::Event::Closed:

                window.close();
                break;

            case sf::Event::MouseButtonPressed:

                {
                    int x = ev.mouseButton.x, y = ev.mouseButton.y;
                    sf::Vector2f v(window.mapPixelToCoords(sf::Vector2i(x, y)));
                    sf::Sprite sp(u);
                    sp.setPosition(v);
                    world.addTower(Tower(sp));
                }

                break;
            }

            world.enqueue(ev);
        }

        window.clear();
        world.update();
        window.draw(world);
        window.display();
    }
}
