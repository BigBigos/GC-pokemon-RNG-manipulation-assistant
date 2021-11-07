#pragma once

#include <vector>

#include "../../Common/CommonTypes.h"

struct AutoRerollSeedData final
{
  bool isActive() const { return m_seedCount != 0; }
  std::vector<u32> getSeeds() const;

  u32 m_startingSeed = 0;
  u32 m_seedCount = 0;
};
