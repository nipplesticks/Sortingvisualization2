#pragma once

#include "Item.h"
#include <vector>
#include <string>
#include "../Timer.h"

class iSort
{
public:
  virtual std::string GetName() = 0;
  virtual double Run(std::vector<Item>& list) = 0;
};