#pragma once
#include "Shuffle.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "RandomSort.h"
#include "GnomeSort.h"
#include "StdSort.h"
#include <vector>

namespace Alg
{
  enum SortAlgs
  {
    Shuffle = 0,
    BubbleSort,
    InsertionSort,
    SelectionSort,
    RandomSort,
    GnomeSort,
    StdSort,
    NUM_SORT_ALGS
  };
}

static inline std::vector<iSort*> GetSortingAlgorithms()
{
  std::vector<iSort*> algs;
  for (int i = 0; i < Alg::NUM_SORT_ALGS; i++)
  {
    Alg::SortAlgs alg = (Alg::SortAlgs)i;
    switch (alg)
    {
    case Alg::Shuffle:
      algs.push_back(new Shuffle);
      break;
    case Alg::BubbleSort:
      algs.push_back(new BubbleSort);
      break;
    case Alg::InsertionSort:
      algs.push_back(new InsertionSort);
      break;
    case Alg::SelectionSort:
      algs.push_back(new SelectionSort);
      break;
    case Alg::RandomSort:
      algs.push_back(new RandomSort);
      break;
    case Alg::GnomeSort:
      algs.push_back(new GnomeSort);
      break;
    case Alg::StdSort:
      algs.push_back(new StdSort);
      break;
    default:
      break;
    }
  }
  return algs;
}