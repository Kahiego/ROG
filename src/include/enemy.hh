#ifndef INCLUDED_ENEMY_HH
#define INCLUDED_ENEMY_HH

#include <SFML/Graphics.hpp>

class Enemy: public sf::Drawable
{
    sf::Sprite _sprite;

public:

    Enemy(const sf::Sprite& sprite): _sprite(sprite)
    {
        
    }

    Enemy() = default;

    Enemy(const Enemy&)            = delete;
    Enemy& operator=(const Enemy&) = delete;

    Enemy(Enemy&&)                 = default;

    sf::Vector2f getPosition() const { return _sprite.getPosition(); }

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        target.draw(_sprite, states);
    }
};

#endif
