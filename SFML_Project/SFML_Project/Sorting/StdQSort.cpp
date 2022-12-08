#include "StdQSort.h"
#include <algorithm>
double StdQSort::GetRecomendedDelay()
{
  return 0.25;
}

std::string StdQSort::GetName()
{
  return "std::qsort";
}

int cmp(const void* x, const void* y)
{
  const Item arg1 = *static_cast<const Item*>(x);
  const Item arg2 = *static_cast<const Item*>(y);
  if (arg1 < arg2) return -1;
  if (arg1 > arg2) return 1;
  return 0;
}

double StdQSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  std::qsort(list.data(), list.size(), sizeof(Item), cmp);
  
  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
