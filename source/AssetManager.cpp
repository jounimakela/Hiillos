#include "AssetManager.h"

ImageAsset& AssetManager::fetch(std::string filename)
{
        AssetMap::iterator it;

        it = assets_.find(filename);
        LOG(DEBUG) << "Asset manager size: " << assets_.size();

        if (it != assets_.end()) {
                ImageAsset &asset = it->second;
                asset.increaseReferences();

                LOG(DEBUG) << "Using existing asset " << filename
                           << ". References: " << asset.referenceCount();
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

DrawableGroup& AssetManager::fetch(std::vector<std::string> filelist)
{
        DrawableGroup group;

        for (auto &file : filelist) {
                sf::Sprite sprite;
                sprite.setTexture(fetch(file).data());
                group.drawables.push_back(&sprite);
        }

        return group;
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
