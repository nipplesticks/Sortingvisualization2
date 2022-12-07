#include "Engine.h"
#include "Timer.h"
#include "Sorting/Sorting.h";

double Item::DELAY_TIME_MS = 0;
size_t Item::NUMBER_OF_COMPARISONS = 0;
double Item::TIME_IN_SLEEP_MODE = 0;

sf::Vector2u Engine::WINDOW_SIZE = sf::Vector2u(1280, 720);

sf::Color ColorLerp(const sf::Color& _a, const sf::Color& _b, double f)
{
  sf::Color ret;

  double r = (double)_a.r + f * ((double)_b.r - (double)_a.r);
  double g = (double)_a.g + f * ((double)_b.g - (double)_a.g);
  double b = (double)_a.b + f * ((double)_b.b - (double)_a.b);

  ret.r = (unsigned int)(r + 0.5);
  ret.g = (unsigned int)(g + 0.5);
  ret.b = (unsigned int)(b + 0.5);

  return ret;
}

Engine::Engine()
{
  myValues.reserve(Engine::WINDOW_SIZE.x);

  for (int i = 0; i < Engine::WINDOW_SIZE.x; i++)
  {
    float t = (float)i / Engine::WINDOW_SIZE.x;
    myValues.push_back(t * Engine::WINDOW_SIZE.y);
  }
}

void Engine::Run()
{
  std::vector<iSort*> sortAlg = GetSortingAlgorithms();

  Alg::SortAlgs selectedAlgorithm = Alg::BubbleSort;

  sf::Font font;
  font.loadFromFile("arial.ttf");

  myAlgorithmName.setFont(font);
  myAlgorithmName.setFillColor(sf::Color::White);
  myAlgorithmName.setString(sortAlg[selectedAlgorithm]->GetName());

  myDelay.setFont(font);
  myDelay.setFillColor(sf::Color::White);
  myDelay.setString("Sleep per comparison: " + std::to_string(Item::DELAY_TIME_MS) + " ms");
  myDelay.setPosition(0, 32);

  myComparison.setFont(font);
  myComparison.setFillColor(sf::Color::White);
  myComparison.setString("Comparisons last run: 0");
  myComparison.setPosition(0, 64);

  myTimeTaken.setFont(font);
  myTimeTaken.setFillColor(sf::Color::White);
  myTimeTaken.setString("Time last run: 0 ms");
  myTimeTaken.setPosition(0, 96);

  bool leftWasPressed = false;
  bool rightWasPressed = false;
  bool upWasPressed = false;
  bool downWasPressed = false;
  bool spaceWasPressed = false;

  while (!myIsTerminated)
  {
    bool leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
    bool upKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Up);
    bool downKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Down);
    bool spaceKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Space);

    if (leftKey || rightKey)
    {
      int selAlg = selectedAlgorithm;
      if (leftKey && !leftWasPressed)
      {
        selAlg--;
        if (selAlg < 0)
          selAlg = Alg::NUM_SORT_ALGS - 1;
      }
      else if (rightKey && !rightWasPressed)
      {
        selAlg++;
        selAlg %= Alg::NUM_SORT_ALGS;
      }
      selectedAlgorithm = (Alg::SortAlgs)selAlg;
      myAlgorithmName.setString(sortAlg[selectedAlgorithm]->GetName());
    }
    else if (upKey || downKey)
    {
      double d = 0.005;
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
        d = 0.01;

      if (upKey && !upWasPressed)
      {
        Item::DELAY_TIME_MS += d;
      }
      else if (downKey && !downWasPressed)
      {
        Item::DELAY_TIME_MS -= d;
      }
      Item::DELAY_TIME_MS = std::max(0.0, Item::DELAY_TIME_MS);
      myDelay.setString("Sleep per comparison: " + std::to_string(Item::DELAY_TIME_MS) + " ms");
    }
    else if (spaceKey && !spaceWasPressed)
    {
      Item::NUMBER_OF_COMPARISONS = 0;
      double old = Item::DELAY_TIME_MS;
      Item::DELAY_TIME_MS = 0.1;
      sortAlg[Alg::Shuffle]->Run(myValues);
      Item::DELAY_TIME_MS = old;
      double timeMs = sortAlg[selectedAlgorithm]->Run(myValues);
      myComparison.setString("Comparisons last run: " + std::to_string(Item::NUMBER_OF_COMPARISONS));
      myTimeTaken.setString("Time last run: " + std::to_string(timeMs) + " ms");
    }

    spaceWasPressed = spaceKey;
    leftWasPressed = leftKey;
    rightWasPressed = rightKey;
    upWasPressed = upKey;
    downWasPressed = downKey;
  }
}

void Engine::Draw(sf::RenderTarget* renderTarget_p)
{
  std::vector<Item> copy = myValues;

  for (int i = 0; i < copy.size(); i++)
  {
    Line l(i);
    l.SetValue(copy[i].data);
    l.Draw(renderTarget_p);
  }
  renderTarget_p->draw(myAlgorithmName);
  renderTarget_p->draw(myDelay);
  renderTarget_p->draw(myComparison);
  renderTarget_p->draw(myTimeTaken);
}

void Engine::Terminate()
{
  myIsTerminated = true;
}

sf::Color Engine::Line::GetColor(float v)
{
  constexpr size_t numColors = 7;
  static const sf::Color roygbiv[numColors] = {
    sf::Color(255, 0, 0),
    sf::Color(255, 165, 0),
    sf::Color(255, 255, 0),
    sf::Color(0, 255, 0),
    sf::Color(0, 165, 255),
    sf::Color(75, 0, 130),
    sf::Color(148, 0, 211)
  };

  double t = (v / Engine::WINDOW_SIZE.y) * (numColors - 1);
  size_t lowIdx = static_cast<size_t>(t);
  size_t highIdx = std::min(lowIdx + 1, numColors - 1);

  double f = t - lowIdx;

  return ColorLerp(roygbiv[lowIdx], roygbiv[highIdx], f);
}
