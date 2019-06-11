#include <yaml-cpp/node/node.h>
#include <yaml-cpp/yaml.h>
#include <fstream>
#include <assert.h>


#include "Configuration.h"

Configuration::Configuration(const std::string& file){
//    TODO what do do if it does not exist?
//TODO Find way to make it more clean
    assert(ifFileExists(file));
    YAML::Node root = YAML::LoadFile(file);
    if(root["left"])
        left = root["left"].as<float>();
    else
        left = -100.0;
    if(root["right"])
        right = root["right"].as<float>();
    else
        right = 100.0;
    if(root["bottom"])
        bottom = root["bottom"].as<float>();
    else
        bottom = 100.0;
    if(root["top"])
        top = root["top"].as<float>();
    else
        top = 100.0;
    if(root["near"])
        near_ = root["near"].as<float>();
    else
        near_ = -100.0;
    if(root["far"])
        far_ = root["far"].as<float>();
    else
        far_ = 100.0;
    if(root["controls"] && (root["controls"].as<YAML::Node>())["sensitivity"])
        sensitivity = (root["controls"].as<YAML::Node>())["sensitivity"].as<float>();
    else
        sensitivity = 10;

}
bool Configuration::ifFileExists(const std::string& file){
    std::ifstream proxy(file.c_str());
    return proxy.good();
}

