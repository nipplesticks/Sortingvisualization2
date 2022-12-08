#pragma once

#include "iSort.h"

class Shuffle : public iSort
{
public:
  // Inherited via iSort
  virtual double Run(List& list) override;

  // Inherited via iSort
  virtual std::string GetName() override;

  // Inherited via iSort
  virtual double GetRecomendedDelay() override;
};