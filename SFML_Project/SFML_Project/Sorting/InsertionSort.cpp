#include "InsertionSort.h"

std::string InsertionSort::GetName()
{
    return "Insertion sort";
}

double InsertionSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  size_t size = list.size();
  for (size_t i = 1; i < size; i++)
  {
    Item t = list[i];
    int j = i - 1;
    while ((j >= 0) && (t < list[j]))
    {
      list[j + 1] = list[j];
      j = j - 1;
    }
    list[j + 1] = t;
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double InsertionSort::GetRecomendedDelay()
{
    return 0.01;
}
