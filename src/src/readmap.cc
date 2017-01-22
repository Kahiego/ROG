#include <iostream>

#include "map.hh"
#include "readmap.hh"

Map readmap(std::istream& tiles, std::istream& theme)
{
    std::vector<sf::Texture> textures;
    std::string line;

    while (std::getline(theme, line))
    {
        if (line == "")
        {
            continue;
        }

        sf::Texture texture;

        if (!texture.loadFromFile(line))
        {
            throw std::runtime_error { "Cannot read the theme file" };
        }

        textures.emplace_back(texture);
    }

    std::size_t x, y;

    if (!(tiles >> x >> y))
    {
        throw std::runtime_error { "Cannot read the tilemap" };
    }

    Map map(x, y);

    for (std::size_t i {}; i < x; ++i)
    {
        for (std::size_t j {}; j < y; ++j)
        {
            std::cout << i << " " << j << std::endl;
            unsigned int idx;

            if (!(tiles >> idx))
            {
                throw std::runtime_error { "Cannot read the tilemap" };
            }

            map(i, j) = Tile(false, false, textures[idx]);
        }
    }

    return map;
}
