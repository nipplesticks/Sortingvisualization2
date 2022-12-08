#pragma once
#include "iSort.h"
class HeapSort : public iSort
{
public:

  // Inherited via iSort
  virtual std::string GetName() override;
  virtual double Run(List& list) override;

  // Inherited via iSort
  virtual double GetRecomendedDelay() override;
};

