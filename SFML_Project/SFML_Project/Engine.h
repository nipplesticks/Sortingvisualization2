#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "Sorting/Item.h"

class Engine
{
public:
  static sf::Vector2u WINDOW_SIZE;
  Engine();

  void Run();
  void Draw(sf::RenderTarget* renderTarget_p);
  void Terminate();

private:
  struct Line
  {
    static sf::Color GetColor(float v);

    Line(int index)
    {
      points.resize(2);
      points[0].position.x = index;
      points[0].position.y = WINDOW_SIZE.y;
      points[1].position.x = index;
      points[1].position.y = WINDOW_SIZE.y;
      points.setPrimitiveType(sf::Lines);
    }

    void SetValue(float v)
    {
      points[1].position.y = points[0].position.y - v;
      points[0].color = points[1].color = GetColor(v);
    }

    void Draw(sf::RenderTarget* renderTarget_p) const
    {
      renderTarget_p->draw(points);
    }
    sf::VertexArray points;
  };

  bool myIsTerminated = false;
  std::vector<Item> myValues;
  sf::Text myAlgorithmName;
  sf::Text myDelay;
  sf::Text myComparison;
  sf::Text myTimeTaken;
};