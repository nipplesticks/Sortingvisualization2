#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <thread>
#include <time.h>

int main()
{
  srand(time(0));

  Engine::WINDOW_SIZE.x = 1920;
  Engine::WINDOW_SIZE.y = 1080;
  Engine::WINDOW_SIZE.x = 2048;
  Engine::WINDOW_SIZE.y = 1080;
  sf::RenderWindow wnd(sf::VideoMode(Engine::WINDOW_SIZE.x, Engine::WINDOW_SIZE.y), "Sorting Visualization 2"/*, sf::Style::Fullscreen*/);
  Engine engine;
  
  std::thread t(&Engine::Run, &engine);

  bool upWasPressed = false;
  bool downWasPressed = false;
  while (wnd.isOpen())
  {
    sf::Event e;
    while (wnd.pollEvent(e))
    {
      switch (e.type)
      {
      case sf::Event::Closed:
        wnd.close();
        break;
      default:
        break;
      }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
      wnd.close();
    bool upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    if (upKey || downKey)
    {
      double d = 0.005;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        d = 0.01;

      Engine::ENGINE_MUTEX.lock();
      if (upKey && !upWasPressed)
      {
        Item::DELAY_TIME_MS += d;
      }
      else if (downKey && !downWasPressed)
      {
        Item::DELAY_TIME_MS -= d;
      }
      Item::DELAY_TIME_MS = std::max(0.0, Item::DELAY_TIME_MS);
      engine.SetDelayString("Sleep per comparison: " + std::to_string(Item::DELAY_TIME_MS) + " ms");
      Engine::ENGINE_MUTEX.unlock();
    }

    wnd.clear();
    engine.Draw(&wnd);
    wnd.display();
    upWasPressed = upKey;
    downWasPressed = downKey;
  }
  engine.Terminate();
  t.join();

  return 0;
}