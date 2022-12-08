#include "StdStableSort.h"
#include <algorithm>

double StdStableSort::GetRecomendedDelay()
{
    return 0.25;
}

std::string StdStableSort::GetName()
{
    return "std::stable_sort";
}

double StdStableSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();
  
  std::stable_sort(list.begin(), list.end());

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
