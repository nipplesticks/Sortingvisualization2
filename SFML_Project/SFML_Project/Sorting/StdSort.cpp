#include "StdSort.h"
#include <algorithm>

double StdSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();
  
  std::sort(list.begin(), list.end());

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

std::string StdSort::GetName()
{
  return "std::sort";
}

double StdSort::GetRecomendedDelay()
{
    return 0.5;
}
