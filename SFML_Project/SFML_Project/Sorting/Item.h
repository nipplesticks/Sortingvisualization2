#pragma once
#include "../Timer.h"
#include <vector>

struct Item
{
  static double DELAY_TIME_MS;
  static size_t NUMBER_OF_COMPARISONS;
  static size_t NUMBER_OF_ASSIGNMENTS;
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
  Item(int other)
  {
    data = other;
  }
  bool operator<(const Item& other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data < other.data;
  }
  bool operator<(int other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data < other;
  }
  bool operator>(const Item& other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data > other.data;
  }
  bool operator>(int other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data > other;
  }
  bool operator<=(const Item& other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data <= other.data;
  }
  bool operator<=(int other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data <= other;
  }
  bool operator>=(const Item& other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data >= other.data;
  }
  bool operator>=(int other) const
  {
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_COMPARISONS++;
    return data >= other;
  }
  Item& operator=(const Item& other)
  {
    data = other.data;
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_ASSIGNMENTS++;
    return *this;
  }
  int& operator=(int other)
  {
    data = other;
    SleepFor(DELAY_TIME_MS);
    NUMBER_OF_ASSIGNMENTS++;
    return data;
  }
  bool operator==(const Item& other)
  {
    return data == other.data;
  }
  bool operator==(int other)
  {
    return data == other;
  }
  bool operator!=(const Item& other)
  {
    return data != other.data;
  }
  bool operator!=(int other)
  {
    return data != other;
  }
  int data;
};

using List = std::vector<Item>;
