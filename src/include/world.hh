#ifndef INCLUDED_WORLD_HH
#define INCLUDED_WORLD_HH

#include <deque>
#include <memory>
#include <vector>

#include "enemy.hh"
#include "tower.hh"
#include "map.hh"

class World: public sf::Drawable
{
    Map _map;

    std::vector<Enemy> _enemy;
    std::vector<Tower> _tower;

    sf::View user_view;
    std::deque<sf::Event> _events;

public:

    World();
    World(const Map&);

    World(const World&)            = delete;
    World& operator=(const World&) = delete;

    bool addEnemy(Enemy&& enemy);
    bool addTower(Tower&& tower);

    void enqueue(const sf::Event& ev);
    void update();

    void viewUpdate(sf::Keyboard::Key);

private:

    virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.setView(user_view);
        target.draw(_map, states);

        for (const auto& x: _enemy)
        {
            target.draw(x, states);
        }

        for (const auto& x: _tower)
        {
            target.draw(x, states);
        }
    }
};

#endif
