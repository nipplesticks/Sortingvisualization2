#pragma once
#include "iSort.h"
class GnomeSort :
    public iSort
{
public:


  // Inherited via iSort
  virtual std::string GetName() override;

  virtual double Run(std::vector<Item>& list) override;

};

