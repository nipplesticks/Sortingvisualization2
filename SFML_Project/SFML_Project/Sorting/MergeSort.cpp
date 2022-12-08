#include "MergeSort.h"

std::string MergeSort::GetName()
{
  return "Merge Sort";
}

void _merge(List& list, int l, int m, int r)
{
  int i, j, k;
  int n1 = m - l + 1;
  int n2 = r - m;

  List L(n1);
  List R(n2);

  for (i = 0; i < n1; i++)
    L[i] = list[l + i];
  for (j = 0; j < n2; j++)
    R[j] = list[m + 1 + j];

  i = 0; j = 0; k = l;

  while (i < n1 && j < n2)
  {
    if (L[i] <= R[j])
    {
      list[k] = L[i];
      i++;
    }
    else
    {
      list[k] = R[j];
      j++;
    }
    k++;
  }

  while (i < n1)
  {
    list[k] = L[i];
    i++;
    k++;
  }

  while (j < n2)
  {
    list[k] = R[j];
    j++;
    k++;
  }
}

void _mergeSort(List& list, int l, int r)
{
  if (l < r)
  {
    int m = l + (r - l) / 2;
    _mergeSort(list, l, m);
    _mergeSort(list, m + 1, r);
    _merge(list, l, m, r);
  }
}

double MergeSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();
  _mergeSort(list, 0, list.size() - 1);
  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double MergeSort::GetRecomendedDelay()
{
    return 0.5;
}
