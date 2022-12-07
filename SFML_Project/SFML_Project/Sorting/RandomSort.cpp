#include "RandomSort.h"
#include "BubbleSort.h"

std::string RandomSort::GetName()
{
  return "Random Sort... with bubble sort to finnish the job after 100k missed comparisons";
}

double RandomSort::Run(std::vector<Item>& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();

  size_t size = list.size();
  size_t missCounter = 0;
  while (true)
  {
    bool isSorted = true;
    for (size_t i = 1; i < size; i++)
    {
      if (list[i] < list[i - 1])
      {
        isSorted = false;
        break;
      }
    }

    if (isSorted)
      break;

    if (missCounter < 100000)
    {
      size_t idx1 = rand() % size;
      size_t idx2 = rand() % size;

      if (idx2 < idx1)
        std::swap(idx1, idx2);

      missCounter++;
      if (list[idx2] < list[idx1])
      {
        std::swap(list[idx2], list[idx1]);
        missCounter = 0;
      }
    }
    else
    {
      BubbleSort bs;
      bs.Run(list);
    }
  }

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
