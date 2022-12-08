#include "PancakeSort.h"

std::string PancakeSort::GetName()
{
  return "Pancake Sort";
}

int _findMaxIndex(List& list, int size)
{
  int maxIndex = 0;
  for (int i = 1; i < size; i++)
    if (list[i] > list[maxIndex])
      maxIndex = i;

  return maxIndex;
}

void _flip(List& list, int i)
{
  int start = 0;
  while (start < i)
  {
    std::swap(list[start], list[i]);
    start++;
    i--;
  }
}

double PancakeSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  int n = list.size();
  for (int currentSize = n; currentSize > 1; --currentSize)
  {
    int maxIndex = _findMaxIndex(list, currentSize);
    if (maxIndex != currentSize - 1)
    {
      _flip(list, maxIndex);
      _flip(list, currentSize - 1);
    }
  }

  

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double PancakeSort::GetRecomendedDelay()
{
    return 0.005;
}
