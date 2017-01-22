#ifndef MATRIX_HH_
# define MATRIX_HH_

#include <cassert>
#include <vector>

template<typename T>
class Matrix
{
    std::size_t _w;
    std::size_t _h;
    std::vector<T> _xs;

public:

    Matrix(std::size_t w, std::size_t h, const T& t = T{})
        : _w(w), _h(h), _xs(w * h, t)
    {

    }

    Matrix &operator=(const Matrix&) = default;

    T const &operator()(std::size_t i, std::size_t j) const 
    {
        assert(i < _w && j < _h);
        return _xs[j * _h + i];
    }

    T &operator()(std::size_t i, std::size_t j)
    {
        assert(i < _w && j < _h);
        return _xs[j * _h + i];
    }

    std::size_t width() const
    {
        return _w;
    }

    std::size_t height() const
    {
        return _h;
    }
};

#endif /* ! MATRIX_HH_ */
