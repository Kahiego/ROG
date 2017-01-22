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

    sf::Clock frameClock;
    unsigned int clockCnt;

    std::size_t _credits { 5 };

public:

    World();
    World(const Map&);

    World(const World&)            = delete;
    World& operator=(const World&) = delete;

    bool addEnemy(Enemy&& enemy);
    bool addTower(Tower&& tower);

    void enqueue(const sf::Event& ev);
    bool update();

    std::size_t enemiesCount();

    void enemyUpdate(const sf::Time& t);
    void viewUpdate(sf::Keyboard::Key);

    void removeEnemy(std::size_t id);

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
