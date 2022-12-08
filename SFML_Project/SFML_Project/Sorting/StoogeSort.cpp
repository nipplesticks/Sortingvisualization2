#include "StoogeSort.h"

double StoogeSort::GetRecomendedDelay()
{
  return 0.0;
}

std::string StoogeSort::GetName()
{
  return "Stooge Sort";
}

void _stoogeSort(List& list, int l, int h)
{
  if (l >= h)
    return;
  if (list[l] > list[h])
    std::swap(list[l], list[h]);
  if ((h - l + 1) > 2)
  {
    int t = (h - l + 1) / 3;
    _stoogeSort(list, l, h - t);
    _stoogeSort(list, l + t, h);
    _stoogeSort(list, l, h - t);
  }
}

double StoogeSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  _stoogeSort(list, 0, list.size() - 1);

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
