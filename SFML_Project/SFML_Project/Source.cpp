#include <SFML/Graphics.hpp>
#include "Engine.h"
#include <thread>
#include <time.h>

int main()
{
  srand(time(0));
  Engine::WINDOW_SIZE.x = 1920;
  Engine::WINDOW_SIZE.y = 1080;
  sf::RenderWindow wnd(sf::VideoMode(Engine::WINDOW_SIZE.x, Engine::WINDOW_SIZE.y), "Sorting Visualization 2");
  Engine engine;

  std::thread t(&Engine::Run, &engine);

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

    wnd.clear();
    engine.Draw(&wnd);
    wnd.display();
  }
  engine.Terminate();
  t.join();

  return 0;
}