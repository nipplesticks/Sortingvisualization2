#include "CycleSort.h"

double CycleSort::GetRecomendedDelay()
{
  return 0.005;
}

std::string CycleSort::GetName()
{
  return "Cycle Sort";
}

double CycleSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  int n = list.size();
  for (int cycleStart = 0; cycleStart <= n - 2; cycleStart++)
  {
    Item item = list[cycleStart];
    int pos = cycleStart;
    for (int i = cycleStart + 1; i < n; i++)
      if (list[i] < item)
        pos++;

    if (pos == cycleStart) continue;

    while (item == list[pos])
      pos++;

    if (pos != cycleStart)
      std::swap(item, list[pos]);

    while (pos != cycleStart)
    {
      pos = cycleStart;

      for (int i = cycleStart + 1; i < n; i++)
        if (list[i] < item)
          pos++;
      while (item == list[pos])
        pos++;

      if (item != list[pos])
      {
        std::swap(item, list[pos]);
      }
    }

  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
