#ifndef MAP_HH_
# define MAP_HH_

#include "matrix.hh"
#include "tile.hh"

class Map: public sf::Drawable
{
    Matrix<Tile> _xs;

public:

    Map(): _xs(0, 0) {}
    Map(const Map&) = default;
    Map(std::size_t w, std::size_t h): _xs(w, h) {}

    const Tile& operator()(std::size_t i, std::size_t j) const
    {
        return _xs(i, j);
    }

    Tile& operator()(std::size_t i, std::size_t j)
    {
        return _xs(i, j);
    }

    bool constructible(std::size_t i, std::size_t j)
    {
        if (i >= _xs.width() || j >= _xs.height())
        {
            return false;
        }

        if (_xs(i, j).type != 1)
        {
            return false;
        }

        if (_xs(i, j).occupied)
        {
            return false;
        }

        return true;
    }

private:

    void draw(sf::RenderTarget& target, sf::RenderStates states) const
    {
        for (std::size_t i (0); i < _xs.width(); ++i)
        {
            for (std::size_t j (0); j < _xs.height(); ++j)
            {
                const Tile& t { _xs(i, j) };
                sf::Sprite sp(t.texture);
                sp.setPosition(i * 64, j * 64);
                target.draw(sp, states);
            }
        }
    }
};

#endif /* ! MAP_HH_ */
