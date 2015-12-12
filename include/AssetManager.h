#ifndef __ASSET_MANAGER_H_DEFINED__
#define __ASSET_MANAGER_H_DEFINED__

#include <iostream>
#include <string>
#include <map>

#include "vendor/easylogging++.h"
#include "Asset.h"
#include "DrawableGroup.h"

class AssetManager
{
public:
        AssetManager() {}
        ~AssetManager() {}

        /* @todo Fetches asset from memory or loads it from a file
         * Asset has to know how to load itself (from a file)
         * constant reference, so asset cannot be altered
         */
//        template <class AssetType>
        ImageAsset& fetch(std::string filename);
        DrawableGroup& fetch(std::vector<std::string> filelist);


protected:
        /* @todo unloads asset, run destructor, remove from assets_ */
        /* @todo: Only forget if reference count = 0! */
        bool forget(std::string filename);

private:
        /* AssetMap type */
        typedef std::map<std::string, ImageAsset> AssetMap;

        AssetMap assets_;
};

#endif
