#pragma once

#include "Item.h"
#include <vector>
#include <string>
#include "../Timer.h"

class iSort
{
public:
  virtual double GetRecomendedDelay() = 0;
  virtual std::string GetName() = 0;
  virtual double Run(List& list) = 0;
};