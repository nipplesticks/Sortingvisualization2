#include "StdSortHeap.h"
#include <algorithm>

double StdSortHeap::GetRecomendedDelay()
{
  return 0.5;
}

std::string StdSortHeap::GetName()
{
  return "std::sort_heap";
}

double StdSortHeap::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  std::make_heap(list.begin(), list.end());
  std::sort_heap(list.begin(), list.end());

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
