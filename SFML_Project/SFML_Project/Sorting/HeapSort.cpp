#include "HeapSort.h"

std::string HeapSort::GetName()
{
  return "Heap sort";
}

void _heapify(List& list, int size, int i)
{
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < size && list[left] > list[largest])
    largest = left;
  if (right < size && list[right] > list[largest])
    largest = right;
  if (largest != i)
  {
    std::swap(list[i], list[largest]);
    _heapify(list, size, largest);
  }
}

void _heapSort(List& list, int size)
{
  for (int i = size / 2 - 1; i >= 0; i--)
  {
    _heapify(list, size, i);
  }
  for (int i = size - 1; i >= 0; i--)
  {
    std::swap(list[0], list[i]);
    _heapify(list, i, 0);
  }
}

double HeapSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  _heapSort(list, list.size());

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double HeapSort::GetRecomendedDelay()
{
    return 0.5;
}
