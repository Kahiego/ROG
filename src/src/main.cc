#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>

#include "map.hh"
#include "tile.hh"
#include "world.hh"

int main()
{
    sf::RenderWindow window (sf::VideoMode(800, 600), "llama");

    sf::Texture t;

    if (!t.loadFromFile("a.png"))
    {
        return 0;
    }

    Tile tile (false, false, t);

    Map map(128, 128);

    for (std::size_t i { 0 }; i < 128; ++i)
    {
        for (std::size_t j { 0 }; j < 128; ++j)
        {
            map(i, j) = tile;
        }
    }

    World world(map);

    sf::Texture u;

    if (!u.loadFromFile("b.png"))
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
