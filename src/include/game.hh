#include "world.hh"

class Game
{
private:
  int level;
  sf::Clock clock;
  sf::Time elapsedLastLevel;

public:
  Game();
  ~Game();
  float getElapsedSeconds();
  int getLevel();
  void restartTime();
};
