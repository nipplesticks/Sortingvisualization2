#pragma once
#include "iSort.h"

class InsertionSort : public iSort
{
  public:

    // Inherited via iSort
    virtual std::string GetName() override;
    virtual double Run(std::vector<Item>& list) override;
};