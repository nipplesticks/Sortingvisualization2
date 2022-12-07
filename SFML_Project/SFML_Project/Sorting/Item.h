#pragma once
#include "../Timer.h"


struct Item
{
  static double DELAY_TIME_MS;
  static size_t NUMBER_OF_COMPARISONS;
  static double TIME_IN_SLEEP_MODE;

public:
  static void SleepFor(double ms)
  {
    Timer t;
    t.Start();
    while (true)
    {
      if (t.GetElapsedTime(Timer::MILLISECONDS) >= DELAY_TIME_MS)
        break;
    }
    TIME_IN_SLEEP_MODE += t.Stop(Timer::MILLISECONDS);
  }

  Item()
  {
    data = 0;
  }
  Item(const Item& other)
  {
    data = other.data;
  }
  Item(float other)
  {
    data = other;
  }
  bool operator<(const Item& other)
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data < other.data;
  }
  bool operator<(float other)
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data < other;
  }
  Item& operator=(const Item& other)
  {
    data = other.data;
    return *this;
  }
  float& operator=(float other)
  {
    data = other;
    return data;
  }
  float data;
};