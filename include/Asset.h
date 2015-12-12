#ifndef __ASSET_H_DEFINED__
#define __ASSET_H_DEFINED__

#include "vendor/easylogging++.h"
#include "SFML/Graphics.hpp"

class Asset
{
public:
        Asset() :
                references_(0)
        {};

        virtual bool load(std::string filename) = 0;

        void increaseReferences();
        void decreaseReferences();
        int referenceCount();

        std::string identifier;

private:
        int references_;
};

/* @todo reference counting */
class ImageAsset : public Asset
{
public:
        ImageAsset() {}
        ~ImageAsset() {}

        bool load(std::string filename)
        {
                if (data_.loadFromFile(filename)) {
                        LOG(DEBUG) << "Asset loaded from file: " << filename;
                        identifier = filename;
                        return  true;
                }

                LOG(ERROR) << "Failed to load " << filename << "from a file!";
                return false;
        }

        sf::Texture& data() { return data_; }

private:
        sf::Texture data_;
};

#endif
