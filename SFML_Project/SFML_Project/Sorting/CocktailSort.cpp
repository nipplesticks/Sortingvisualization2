#include "CocktailSort.h"

double CocktailSort::GetRecomendedDelay()
{
  return 0.01;
}

std::string CocktailSort::GetName()
{
  return "Cocktail Sort";
}

double CocktailSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  int n = list.size();
  bool swapped = true;
  int start = 0;
  int end = n - 1;

  while (swapped)
  {
    swapped = false;
    for (int i = start; i < end; i++)
    {
      if (list[i] > list[i + 1])
      {
        std::swap(list[i], list[i + 1]);
        swapped = true;
      }
    }

    if (!swapped) break;
    end--;

    for (int i = end - 1; i >= start; i--)
    {
      if (list[i] > list[i + 1])
      {
        std::swap(list[i], list[i + 1]);
        swapped = true;
      }
    }
    start++;
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
