#include "SelectionSort.h"

std::string SelectionSort::GetName()
{
    return "Selection sort";
}

double SelectionSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  size_t size = list.size();

  for (size_t i = 0; i < size; i++)
  {
    size_t minIdx = i;
    for (size_t j = i + 1; j < size; j++)
    {
      if (list[j] < list[minIdx])
      {
        minIdx = j;
      }
    }
    std::swap(list[i], list[minIdx]);
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double SelectionSort::GetRecomendedDelay()
{
    return 0.01;
}
