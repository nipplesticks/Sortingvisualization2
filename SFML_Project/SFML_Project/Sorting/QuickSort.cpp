#include "QuickSort.h"

std::string QuickSort::GetName()
{
  return "Quick Sort";
}

int _partition(List& list, int low, int high)
{
  Item pivot = list[high];
  int i = low - 1;
  for (int j = low; j < high; j++)
  {
    if (pivot > list[j])
    {
      i++;
      std::swap(list[i], list[j]);
    }
  }

  std::swap(list[i + 1], list[high]);
  return (i + 1);
}

void _quickSort(List& list, int low, int high)
{
  if (low < high)
  {
    int p = _partition(list, low, high);
    _quickSort(list, low, p - 1);
    _quickSort(list, p + 1, high);
  }
}

double QuickSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  _quickSort(list, 0, (int)list.size() - 1);

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double QuickSort::GetRecomendedDelay()
{
    return 0.5;
}
