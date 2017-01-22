#ifndef INCLUDED_READMAP_HH
#define INCLUDED_READMAP_HH

#include <fstream>
#include "map.hh"

Map readmap(std::istream& tiles, std::istream& theme);

#endif
