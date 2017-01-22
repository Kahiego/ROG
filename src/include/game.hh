#include "world.hh"

class Game
{
private:
  int level;
  sf::Clock clock;
  sf::Time elapsedLastLevel;

public:
  Game();
  ~Game() = default;
  float getElapsedSeconds();
  int getLevel();
  void restartTime();
  bool play(sf::RenderWindow& window, std::istream& mapf, std::istream& assf);
};
