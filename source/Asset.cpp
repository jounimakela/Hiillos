#include "Asset.h"

void Asset::increaseReferences()
{
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
