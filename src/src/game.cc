#include "game.hh"
#include "readmap.hh"

Game::Game(): level(0)
{
}

float Game::getElapsedSeconds()
{
  return (this->clock.getElapsedTime().asSeconds());
}

int Game::getLevel()
{
  return (this->level);
}

void Game::restartTime()
{
  clock.restart();
}

bool Game::play(sf::RenderWindow& window, std::istream& mapf, std::istream& assf)
{
  Map map = readmap(mapf, assf);
  
  World world(map);
  sf::Texture u;
  
  if (!u.loadFromFile("Tower.png"))
    {
      return false;
    }
  
  sf::Texture enemyTexture;
  
  if (!enemyTexture.loadFromFile("flame.png"))
    {
      return false;
    }
  
  sf::Sprite enemySprite(enemyTexture);
  enemySprite.setPosition(64, 64);

    sf::Font arial;

    if (!arial.loadFromFile("./arial.ttf"))
    {
        return false;
    }

  std::string levelString(std::string("Level") + std::to_string(level));
  sf::Text levelHint(levelString, arial);

  for (unsigned int i = 0; i < 5 * (level + 2); ++i)
    {
      world.addEnemy(Enemy(enemySprite));
    }
  
  while (window.isOpen())
    {
      sf::Event ev;
      
      while (window.pollEvent(ev))
        {
	  switch (ev.type)
            {
            case sf::Event::Closed:
	      window.close();
	      return false;;
            case sf::Event::MouseButtonPressed:
	      
	      {
		int x = ev.mouseButton.x, y = ev.mouseButton.y;
		sf::Vector2f v(window.mapPixelToCoords(sf::Vector2i(x, y)));
		sf::Sprite sp(u);
		sp.setPosition(v);
        Tower t(sp);
        t.setInterval(2. / (level + 1));
		world.addTower(std::move(t));
	      }
	      
	      break;
            }
	  
	  world.enqueue(ev);
        }
      
      window.clear();
      if (!world.update())
        {
            break;
        }
      window.draw(world);

    levelHint.setString(levelString + " " + std::to_string(world.enemiesCount()));

      window.draw(levelHint);
      window.display();
    }  
  level++;
  return true;
}
