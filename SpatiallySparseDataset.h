#pragma once
#include "Picture.h"
#include "Rng.h"
#include <vector>
#include <string>
#include "types.h"
#include "SpatiallySparseDataset.h"


class SpatiallySparseDataset {
  RNG rng;
public:
  std::string name;
  std::vector<Picture*> pictures;
  int nFeatures;
  int nClasses;
  batchType type;
  void summary();
  void shuffle();
  SpatiallySparseDataset extractValidationSet(float p=0.1);
  void subsetOfClasses(std::vector<int> activeClasses);
  SpatiallySparseDataset subset(int n);
  SpatiallySparseDataset balencedSubset(int n);
  void repeatSamples(int reps); // Make dataset seem n times bigger (i.e. for small datasets to avoid having v. small training epochs)
};
