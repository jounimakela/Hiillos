#ifndef __CONFIGURATION_H_DEFINED__
#define __CONFIGURATION_H_DEFINED__

#include <string>
#include <fstream>

#include "vendor/json.hpp"
#include "vendor/easylogging++.h"

class Configuration : public nlohmann::json
{
public:
        Configuration(std::string file_path);
        ~Configuration();

        nlohmann::json loadFromFile(std::string file_path);
};

#endif
