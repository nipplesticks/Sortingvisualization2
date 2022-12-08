#include "GnomeSort.h"

std::string GnomeSort::GetName()
{
  return "Gnome Sort";
}

double GnomeSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  size_t idx = 0;
  size_t n = list.size();

  while (idx < n)
  {
    if (idx == 0)
      idx++;
    if (list[idx] >= list[idx - 1])
      idx++;
    else
    {
      std::swap(list[idx], list[idx - 1]);
      idx--;
    }
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}

double GnomeSort::GetRecomendedDelay()
{
    return 0.01;
}
