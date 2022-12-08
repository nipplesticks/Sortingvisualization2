#include "BubbleSort.h"

std::string BubbleSort::GetName()
{
  return "Bubble sort";
}

double BubbleSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  size_t size = list.size();

  for (size_t i = 0; i < size; i++)
  {
    for (size_t j = i + 1; j < size; j++)
    {
      if (list[j] < list[i])
        std::swap(list[j], list[i]);
    }
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double BubbleSort::GetRecomendedDelay()
{
    return 0.01;
}
