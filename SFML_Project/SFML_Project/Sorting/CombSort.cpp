#include "CombSort.h"

double CombSort::GetRecomendedDelay()
{
  return 0.05;
}

std::string CombSort::GetName()
{
  return "Comb Sort";
}

int _getNextGap(int gap)
{
  gap = (gap * 10) / 13;
  if (gap < 1)
    return 1;
  return gap;

}

double CombSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  int n = list.size();
  int gap = n;
  bool swapped = true;
  while (gap != 1 || swapped == true)
  {
    gap = _getNextGap(gap);
    swapped = false;
    for (int i = 0; i < n - gap; i++)
    {
      if (list[i] > list[i + gap])
      {
        std::swap(list[i], list[i + gap]);
        swapped = true;
      }
    }
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
