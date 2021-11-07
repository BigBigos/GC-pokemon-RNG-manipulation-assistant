#include "AutoRerollSeedData.h"

#include "../SPokemonRNG.h"
#include "../Settings/SConfig.h"

std::vector<u32> AutoRerollSeedData::getSeeds() const
{
  const auto& config = SConfig::getInstance();

  const u32 minAdvances = static_cast<u32>(m_seedCount * config.getMinAdvancesFactor());
  const u32 maxAdvances = static_cast<u32>(m_seedCount * config.getMaxAdvancesFactor());

  return SPokemonRNG::getCurrentSystem()->getSeedsWithinBounds(
      m_startingSeed, minAdvances, maxAdvances);
}
