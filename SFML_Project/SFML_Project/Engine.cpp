#include "Engine.h"
#include "Timer.h"
#include "Sorting/Sorting.h";

double Item::DELAY_TIME_MS = 0;
size_t Item::NUMBER_OF_COMPARISONS = 0;
size_t Item::NUMBER_OF_ASSIGNMENTS = 0;
double Item::TIME_IN_SLEEP_MODE = 0;
std::mutex Engine::ENGINE_MUTEX;

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
    myValues.push_back((t * Engine::WINDOW_SIZE.y) + 0.5f);
  }
}

void Engine::SetDelayString(const std::string& str)
{
  myDelay.setString(str);
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
  Item::DELAY_TIME_MS = sortAlg[selectedAlgorithm]->GetRecomendedDelay();

  myDelay.setFont(font);
  myDelay.setFillColor(sf::Color::White);
  myDelay.setString("Sleep per comparison: " + std::to_string(Item::DELAY_TIME_MS) + " ms");
  myDelay.setPosition(0, 32);

  myComparison.setFont(font);
  myComparison.setFillColor(sf::Color::White);
  myComparison.setString("Comparisons last run: 0");
  myComparison.setPosition(0, 64);

  myAsignments.setFont(font);
  myAsignments.setFillColor(sf::Color::White);
  myAsignments.setString("Asignments last run: 0");
  myAsignments.setPosition(0, 96);

  myTimeTaken.setFont(font);
  myTimeTaken.setFillColor(sf::Color::White);
  myTimeTaken.setString("Time last run: 0 ms");
  myTimeTaken.setPosition(0, 128);

  bool leftWasPressed = false;
  bool rightWasPressed = false;
  bool spaceWasPressed = false;

  while (!myIsTerminated)
  {
    bool leftKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Left);
    bool rightKey = sf::Keyboard::isKeyPressed(sf::Keyboard::Right);
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
      ENGINE_MUTEX.lock();
      Item::DELAY_TIME_MS = sortAlg[selectedAlgorithm]->GetRecomendedDelay();
      SetDelayString("Sleep per comparison: " + std::to_string(Item::DELAY_TIME_MS) + " ms");
      ENGINE_MUTEX.unlock();
    }
    else if (spaceKey && !spaceWasPressed)
    {
      ENGINE_MUTEX.lock();
      Item::NUMBER_OF_COMPARISONS = 0;
      Item::NUMBER_OF_ASSIGNMENTS = 0;
      double old = Item::DELAY_TIME_MS;
      Item::DELAY_TIME_MS = 0.0;
      sortAlg[Alg::Shuffle]->Run(myValues);
      Item::DELAY_TIME_MS = old;
      ENGINE_MUTEX.unlock();
      double timeMs = sortAlg[selectedAlgorithm]->Run(myValues);
      myComparison.setString("Comparisons last run: " + std::to_string(Item::NUMBER_OF_COMPARISONS));
      myAsignments.setString("Asignments last run: " + std::to_string(Item::NUMBER_OF_ASSIGNMENTS));
      myTimeTaken.setString("Time last run: " + std::to_string(timeMs) + " ms");
    }

    spaceWasPressed = spaceKey;
    leftWasPressed = leftKey;
    rightWasPressed = rightKey;
  }
}

void Engine::Draw(sf::RenderTarget* renderTarget_p)
{
  List copy = myValues;

  for (int i = 0; i < copy.size(); i++)
  {
    Line l(i);
    l.SetValue(copy[i].data);
    l.Draw(renderTarget_p);
  }
  renderTarget_p->draw(myAlgorithmName);
  renderTarget_p->draw(myDelay);
  renderTarget_p->draw(myComparison);
  renderTarget_p->draw(myAsignments);
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
