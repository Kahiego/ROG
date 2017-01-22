#ifndef INCLUDED_ENEMY_HH
#define INCLUDED_ENEMY_HH

#include <SFML/Graphics.hpp>
#include "map.hh"

/*
class Life: public sf::Drawable
{
    

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        
    }
};
*/

class Enemy: public sf::Drawable
{
    sf::Sprite _sprite;
    unsigned int frame {0};

public:

    Enemy(const sf::Sprite& sprite): _sprite(sprite)
    {
    }

    Enemy() = default;

    Enemy(const Enemy& other): _sprite (other._sprite), frame (other.frame) {}
    Enemy& operator=(const Enemy&) = default;

    Enemy(Enemy&&)                 = default;

    sf::Vector2f getPosition() const { return _sprite.getPosition(); }
    void setPosition(const sf::Vector2f& px) { _sprite.setPosition(px); }

    void move(const Map& map, float percent)
    {
        sf::Vector2f px[] =
        {
            sf::Vector2f(1, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            
            sf::Vector2f(0, -1),
            sf::Vector2f(1, 0),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(0, -1),
            sf::Vector2f(1, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(-1, 0),
            sf::Vector2f(-1, 0),
            sf::Vector2f(-1, 0),
            sf::Vector2f(-1, 0),
            sf::Vector2f(-1, 0),
            sf::Vector2f(0, 1),
            
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),

            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),

            sf::Vector2f(-1, 0),
            sf::Vector2f(-1, 0),
            sf::Vector2f(-1, 0),
            sf::Vector2f(-1, 0),
            sf::Vector2f(0, 1),
            sf::Vector2f(0, 1),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0),
            sf::Vector2f(1, 0)
        };

        _sprite.move(px[frame++] * 64.f);

        
    }

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_sprite, states);
    }
};

#endif
