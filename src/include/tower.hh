#ifndef INCLUDED_TOWER_HH
#define INCLUDED_TOWER_HH

#include <SFML/Graphics.hpp>
#include <cmath>
#include "enemy.hh"
#include "entity.hh"

#include <utility>

class Tower: public sf::Drawable
{
    sf::Sprite _sprite;
    std::size_t _focus;
    sf::Clock clock;
    double _radius;
    double _interval;

public:

    Tower(const sf::Sprite& sprite)
        : _sprite { sprite }, _focus { 0 }, _radius { 128. }, _interval { 2. } {}

    Tower(const Tower&)            = delete;
    Tower& operator=(const Tower&) = delete;

    Tower(Tower&& other): _sprite(other._sprite), _focus(other._focus), _radius {other._radius}, _interval { other._interval } {}

    sf::Vector2f getPosition() const { return _sprite.getPosition(); }
    void setPosition(const sf::Vector2f& px) { _sprite.setPosition(px); }

    sf::IntRect getSize() const { return _sprite.getTextureRect(); }

    void setRadius(double radius) { _radius = radius; }
    double getRadius() const { return _radius; }

    void setInterval(double i) { _interval = i; }

    void focus(std::size_t id)
    {
        _focus = id;
    }

    bool canShoot(const sf::Vector2f& coords)
    {
        double hypot_a = std::hypot(getPosition().x - coords.x,
                                    getPosition().y - coords.y);

        if (hypot_a > _radius)
        {
            return false;
        }

        return clock.getElapsedTime() > sf::seconds(_interval);
    }

    void resetShoot()
    {
        clock.restart();
    }

    std::size_t focused()
    {
        return _focus;
    }

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_sprite, states);
    }
};

#endif
