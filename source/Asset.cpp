#include "Asset.h"

void Asset::increaseReferences()
{
        reference_timer_.restart();
        references_++;
};

void Asset::decreaseReferences()
{
        references_--;
};

int Asset::referenceCount()
{
        return references_;
};

sf::Time Asset::lastReferenced()
{
        return reference_timer_.getElapsedTime();
};

void Asset::resetReferences()
{
        references_ = 0;
};
