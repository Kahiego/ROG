#include <iostream>
#include <sstream>

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

    std::string llama;

    std::getline(tiles, llama);

    std::string tiles_line, props_line;

    std::getline(tiles, tiles_line);
    std::getline(tiles, props_line);

    std::istringstream tiles_iss (tiles_line), props_iss(props_line);

    Map map(x, y);

    for (std::size_t i {}; i < x; ++i)
    {
        for (std::size_t j {}; j < y; ++j)
        {
            std::cout << i << " " << j << std::endl;
            unsigned int idx;
            int props;

            if (!(tiles_iss >> idx))
            {
                throw std::runtime_error { "Cannot read the tilemap2" };
            }

            if (!(props_iss >> props))
            {
                throw std::runtime_error { "Cannot read the tilemap3" };
            }

            map(i, j) = Tile(props, false, textures[idx]);
        }
    }

    return map;
}
