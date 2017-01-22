#ifndef INCLUDED_TOWER_HH
#define INCLUDED_TOWER_HH

#include <SFML/Graphics.hpp>
#include "enemy.hh"
#include "entity.hh"

#include <utility>

class Tower: public sf::Drawable
{
    sf::Sprite _sprite;
    std::size_t _focus;
    sf::Clock clock;

public:

    Tower(const sf::Sprite& sprite)
        : _sprite { sprite }, _focus { 0 } {}

    Tower(const Tower&)            = delete;
    Tower& operator=(const Tower&) = delete;

    Tower(Tower&& other): _sprite(other._sprite), _focus(other._focus) {}

    sf::Vector2f getPosition() const { return _sprite.getPosition(); }
    void setPosition(const sf::Vector2f& px) { _sprite.setPosition(px); }

    sf::IntRect getSize() const { return _sprite.getTextureRect(); }

    void focus(std::size_t id)
    {
        _focus = id;
    }

    bool canShoot()
    {
        return clock.getElapsedTime() > sf::seconds(2);
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
