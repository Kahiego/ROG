#ifndef TILE_HH_
# define TILE_HH_

#include <SFML/Graphics.hpp>

struct Tile
{
    Tile(bool c = false, bool o = false, const sf::Texture& t = {}): collision {c},
                                                occupied {o},
                                                texture {t} {}
    bool collision;
    bool occupied;
    sf::Texture texture;
};

#endif /* ! TILE_HH_ */
