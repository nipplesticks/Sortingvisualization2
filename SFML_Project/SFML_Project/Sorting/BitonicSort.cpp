#include "BitonicSort.h"
#include <algorithm>

double BitonicSort::GetRecomendedDelay()
{
    return 0.5;
}

std::string BitonicSort::GetName()
{
    return "Bitonic Sort (Only works for 2^n elements...)";
}

void _compAndSwap(List& list, int i, int j, int dir)
{
  if (dir == (list[i] > list[j]))
    std::swap(list[i], list[j]);
}

void bitonicMerge(List& list, int low, int cnt, int dir)
{
  if (cnt > 1)
  {
    int k = cnt / 2;
    for (int i = low; i < (low + k); i++)
      _compAndSwap(list, i, i + k, dir);
    bitonicMerge(list, low, k, dir);
    bitonicMerge(list, low + k, k, dir);
  }
}

void _bitonicSort(List& list, int low, int cnt, int dir)
{
  if (cnt > 1)
  {
    int k = cnt / 2;
    _bitonicSort(list, low, k, 1);
    _bitonicSort(list, low + k, k, 0);
    bitonicMerge(list, low, cnt, dir);
  }
}

double BitonicSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  _bitonicSort(list, 0, list.size(), 1);
  
  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
