#include "SleepSort.h"
#include <windows.h>
#include <process.h>

static List* list_p = nullptr;
static int counter = 0;

double SleepSort::GetRecomendedDelay()
{
    return 0.0;
}

std::string SleepSort::GetName()
{
  return "Sleep Sort";
}

void routine(void* a)
{
  int i = *(int*)a;
  Sleep(i);
  list_p->at(counter++).data = i;
}

double SleepSort::Run(List& list)
{
  Item::TIME_IN_SLEEP_MODE = 0;
  Timer t;
  t.Start();
  list_p = &list;
  counter = 0;

  std::vector<HANDLE> threads(list.size());
  for (int i = 0; i < list.size(); i++)
    threads[i] = (HANDLE)_beginthread(&routine, 0, &list[i]);

  WaitForMultipleObjects(list.size(), threads.data(), TRUE, INFINITE);

  return t.Stop(Timer::MILLISECONDS) - Item::TIME_IN_SLEEP_MODE;
}
