#include "RecursiveInsertionSort.h"

double RecursiveInsertionSort::GetRecomendedDelay()
{
  return 0.01;
}

std::string RecursiveInsertionSort::GetName()
{
  return "Recursive Insertion Sort";
}

void _insertionSort(List& list, int n)
{
  if (n <= 1)
    return;
  _insertionSort(list, n - 1);

  Item last = list[n - 1];
  int j = n - 2;

  while (j >= 0 && list[j] > last)
  {
    list[j + 1] = list[j];
    j--;
  }
  list[j + 1] = last;
}

double RecursiveInsertionSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  _insertionSort(list, list.size());

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
