#ifndef TILE_HH_
# define TILE_HH_

#include <SFML/Graphics.hpp>

struct Tile
{
    Tile(int ty = 0, bool o = false, const sf::Texture& t = {}): type {ty},
                                                occupied {o},
                                                texture {t} {}
    int type;
    bool occupied;
    sf::Texture texture;
};

#endif /* ! TILE_HH_ */
