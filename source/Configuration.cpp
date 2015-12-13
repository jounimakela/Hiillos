#include "Configuration.h"

Configuration::Configuration(std::string file_path) :
        nlohmann::json(loadFromFile(file_path))
{}

Configuration::~Configuration() {}

nlohmann::json Configuration::loadFromFile(std::string file_path)
{
        std::ifstream file(file_path, std::ios::in | std::ios::binary);

        if (!file) {
                LOG(ERROR) << "Couldn't open file " << file_path;
                return nullptr;
        }

        std::string contents;

        file.seekg(0, std::ios::end);
        contents.resize(file.tellg());
        file.seekg(0, std::ios::beg);

        file.read(&contents[0], contents.size());

        file.close();

        return nlohmann::json::parse(contents);
}
