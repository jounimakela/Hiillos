#include "AssetManager.h"

ImageAsset& AssetManager::fetch(std::string filename)
{
        AssetMap::iterator it;

        it = assets_.find(filename);

        if (it != assets_.end()) {
                ImageAsset &asset = it->second;
                asset.increaseReferences();

//                LOG(DEBUG) << "Using existing asset " << filename
//                           << ". References: " << asset.referenceCount();
                return asset;
        }

        ImageAsset asset;

        if (asset.load(filename)) {
                LOG(DEBUG) << "Asset loaded from file " << filename;
        } else {
                LOG(ERROR) << "Asset not found.";
        }


        assets_[filename] = asset;
        return assets_[filename];
}

void AssetManager::cleanup()
{
        for(AssetMap::iterator it = assets_.begin();
                        it != assets_.end();
                        ++it)
        {
                /*
                LOG(DEBUG) << "Asset " << it->first << " has now " << it->second.referenceCount();
                LOG(DEBUG) << "Last referenced " << it->second.lastReferenced().asSeconds() << " seconds ago";
                */

                if (it->second.referenceCount() == 0
                 && it->second.lastReferenced().asSeconds() > 3)
                {
                        forget(it->first);
                }
        }
}

void AssetManager::resetReferences()
{
        for(AssetMap::iterator it = assets_.begin();
                        it != assets_.end();
                        ++it)
        {
                it->second.resetReferences();
//                LOG(DEBUG) << "Asset " << it->first << " has now " << it->second.referenceCount();
        }
}

bool AssetManager::forget(std::string filename)
{
        AssetMap::iterator it;
        it = assets_.find(filename);

        if (it != assets_.end()) {
                LOG(DEBUG) << "Forgetting asset " << filename;
                assets_.erase(it);
                return true;
        }

        LOG(ERROR) << "Asset not found.";
        return false;
}
