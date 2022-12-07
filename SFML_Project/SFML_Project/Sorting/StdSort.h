#pragma once

#include "iSort.h"

class StdSort : public iSort
{
public:
  // Inherited via iSort
  virtual double Run(std::vector<Item>& list) override;


  // Inherited via iSort
  virtual std::string GetName() override;

};