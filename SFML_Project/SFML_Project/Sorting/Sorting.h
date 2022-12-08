#pragma once
#include "Shuffle.h"
#include "BubbleSort.h"
#include "InsertionSort.h"
#include "SelectionSort.h"
#include "RandomSort.h"
#include "GnomeSort.h"
#include "RadixSort.h"
#include "QuickSort.h"
#include "StdSort.h"
#include "HeapSort.h"
#include "MergeSort.h"
#include "PancakeSort.h"
#include "CycleSort.h"
#include "ShellSort.h"
#include "StoogeSort.h"
#include "CombSort.h"
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
    RadixSort,
    QuickSort,
    HeapSort,
    MergeSort,
    PancakeSort,
    CycleSort,
    ShellSort,
    StoogeSort,
    CombSort,
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
    case Alg::RadixSort:
      algs.push_back(new RadixSort);
      break;
    case Alg::QuickSort:
      algs.push_back(new QuickSort);
      break;
    case Alg::HeapSort:
      algs.push_back(new HeapSort);
      break;
    case Alg::MergeSort:
      algs.push_back(new MergeSort);
      break;
    case Alg::PancakeSort:
      algs.push_back(new PancakeSort);
      break;
    case Alg::CycleSort:
      algs.push_back(new CycleSort);
      break;
    case Alg::ShellSort:
      algs.push_back(new ShellSort);
      break;
    case Alg::StoogeSort:
      algs.push_back(new StoogeSort);
      break;
    case Alg::CombSort:
      algs.push_back(new CombSort);
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