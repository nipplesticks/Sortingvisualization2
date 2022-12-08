#pragma once
#include "iSort.h"
class StdStableSort : public iSort
{
public:
  // Inherited via iSort
  virtual double GetRecomendedDelay() override;
  virtual std::string GetName() override;
  virtual double Run(List& list) override;
};

