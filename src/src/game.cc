#include "game.hh"

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
  this->clock.restart;
  return ;
}

void Game::play()
{
  Map map = readmap(mapf, assf);
  
  World world(map);
  sf::Texture u;
  
  if (!u.loadFromFile("Tower.png"))
    {
      return 0;
    }
  
  sf::Texture enemyTexture;
  
  if (!enemyTexture.loadFromFile("flame.png"))
    {
      return 0;
    }
  
  sf::Sprite enemySprite(enemyTexture);
  enemySprite.setPosition(64, 64);
  
  for (unsigned int i = 0; i < 10; ++i)
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
	      break;
            case sf::Event::MouseButtonPressed:
	      
	      {
		int x = ev.mouseButton.x, y = ev.mouseButton.y;
		sf::Vector2f v(window.mapPixelToCoords(sf::Vector2i(x, y)));
		sf::Sprite sp(u);
		sp.setPosition(v);
		world.addTower(Tower(sp));
	      }
	      
	      break;
            }
	  
	  world.enqueue(ev);
        }
      
      window.clear();
      world.update();
      window.draw(world);
      window.display();
    }  
  level++;
}
