#include <cmath>
#include <SFML/Window.hpp>
#include "world.hh"

World::World(const Map& map): _enemy {}, _tower {}, _map(map)
{

}

void World::viewUpdate(sf::Keyboard::Key key)
{
    float off_x { key == sf::Keyboard::Key::Left  ? -64.f
                : key == sf::Keyboard::Key::Right ? 64.f
                : 0.f },
          off_y { key == sf::Keyboard::Key::Up   ? -64.f
                : key == sf::Keyboard::Key::Down ? 64.f
                : 0.f };

    user_view.setCenter(user_view.getCenter() + sf::Vector2f(off_x, off_y));
}

World::World(): _map(),
                user_view()
{

}

bool World::addEnemy(Enemy&& enemy)
{
    _enemy.emplace_back(std::move(enemy));
    return true;
}

bool World::addTower(Tower&& tower)
{
    sf::Vector2f px { tower.getPosition() };
    sf::IntRect sx { tower.getSize() };

    std::size_t x = px.x / 64 , y = px.y / 64;

    if (!_map.constructible(x, y))
    {
        return false;
    }

    _map(x, y).occupied = true;

    tower.setPosition(sf::Vector2f(x * 64, y * 64 - sx.height + 64));
    _tower.emplace_back(std::move(tower));
    return true;
}

void World::enqueue(const sf::Event& ev)
{
    _events.push_front(ev);
}

void World::enemyUpdate(const sf::Time& t)
{
    for (auto& x: _enemy)
    {
        x.move(_map, t.asSeconds());
    }
}

void World::update()
{
    while (!_events.empty())
    {
        sf::Event x { _events.back() };

        if (x.type == sf::Event::KeyPressed)
        {
            viewUpdate(x.key.code);
        }

        _events.pop_back();
    }

    if (_enemy.size() == 0)
    {
        return;
    }

    for (auto& x: _tower)
    {
        using std::begin;
        using std::end;

        auto cmp = [&x](const Enemy& a, const Enemy& b)
        {
            double hypot_a = std::hypot(x.getPosition().x - a.getPosition().x,
                                        x.getPosition().y - a.getPosition().y),
                   hypot_b = std::hypot(x.getPosition().x - b.getPosition().x,
                                        x.getPosition().y - b.getPosition().y);


            return hypot_a < hypot_b;
        };

        x.focus(&*std::min_element(begin(_enemy), end(_enemy), cmp));
    }

    if (frameClock.getElapsedTime() < sf::seconds(1))
    {
        return;
    }

    enemyUpdate(frameClock.restart());
}
