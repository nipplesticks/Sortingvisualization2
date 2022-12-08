#include "RadixSort.h"

std::string RadixSort::GetName()
{
  return "Radix Sort";
}

int _getMax(List& list)
{
  int mx = list[0].data;
  for (int i = 1; i < list.size(); i++)
    if (list[i] > mx)
      mx = list[i].data;
  return mx;
}

void _countSort(List& list, int exp)
{
  List copy = list;
  int count[10]{};
  int n = list.size();
  for (int i = 0; i < n; i++)
    count[(list[i].data / exp) % 10]++;
  for (int i = 1; i < 10; i++)
    count[i] += count[i - 1];
  for (int i = n - 1; i >= 0; i--)
  {
    copy[count[(list[i].data / exp) % 10] - 1] = list[i];
    count[(list[i].data / exp) % 10]--;
  }
  for (int i = 0; i < n; i++)
  {
    list[i] = copy[i];
  }
}

double RadixSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();
  int m = _getMax(list);
  for (int exp = 1; m / exp > 0; exp *= 10)
    _countSort(list, exp);
  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double RadixSort::GetRecomendedDelay()
{
    return 0.5;
}
