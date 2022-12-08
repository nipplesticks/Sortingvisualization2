#include "Shuffle.h"

double Shuffle::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  size_t num = list.size();
  size_t it = num * 512;

  for (size_t i = 0; i < it; i++)
  {
    size_t idx1 = rand() % num;
    size_t idx2 = rand() % num;
    std::swap(list[idx1], list[idx2]);
    Sleep(Item::DELAY_TIME_MS);
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

std::string Shuffle::GetName()
{
  return "Just a Shuffle";
}

double Shuffle::GetRecomendedDelay()
{
    return 0.0;
}
