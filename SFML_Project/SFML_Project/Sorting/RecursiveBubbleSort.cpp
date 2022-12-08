#include "RecursiveBubbleSort.h"

double RecursiveBubbleSort::GetRecomendedDelay()
{
  return 0.01;
}

std::string RecursiveBubbleSort::GetName()
{
  return "Recursive Bubble Sort";
}

void _bubbleSort(List& list, int n)
{
  if (n == 1)
    return;

  int count = 0;

  for (int i = 0; i < n - 1; i++)
  {
    if (list[i] > list[i + 1])
    {
      std::swap(list[i], list[i + 1]);
      count++;
    }
  }
  if (count == 0)
    return;
  _bubbleSort(list, n - 1);
}

double RecursiveBubbleSort::Run(List& list)
{

  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  int n = list.size();

  _bubbleSort(list, n);


  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
