#include "PigeonHoleSort.h"

double PigeonHoleSort::GetRecomendedDelay()
{
  return 0.5;
}

std::string PigeonHoleSort::GetName()
{
  return "Pigeon Hole Sort";
}

double PigeonHoleSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  int n = list.size();
  
  Item mi = list[0];
  Item ma = list[0];

  for (int i = 0; i < n; i++)
  {
    if (list[i] < mi)
      mi = list[i];
    if (list[i] > ma)
      ma = list[i];
  }

  int range = ma.data - mi.data + 1;

  std::vector<List> holes(range);
  for (int i = 0; i < n; i++)
    holes[list[i].data - mi.data].push_back(list[i]);

  int idx = 0;

  for (int i = 0; i < range; i++)
  {
    std::vector<Item>::iterator it;
    for (it = holes[i].begin(); it != holes[i].end(); ++it)
    {
      list[idx++] = *it;
    }
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
