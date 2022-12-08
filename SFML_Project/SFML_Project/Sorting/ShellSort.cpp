#include "ShellSort.h"

double ShellSort::GetRecomendedDelay()
{
  return 0.05;
}

std::string ShellSort::GetName()
{
  return "Shell Sort";
}

double ShellSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  int n = list.size();
  for (int gap = n / 2; gap > 0; gap /= 2)
  {
    for (int i = gap; i < n; i++)
    {
      Item t = list[i];
      int j = 0;
      for (j = i; j >= gap && list[j - gap] > t; j -= gap)
      {
        list[j] = list[j - gap];
      }
      list[j] = t;
    }
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
