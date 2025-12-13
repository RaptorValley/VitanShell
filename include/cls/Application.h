#pragma once

#ifndef ___APPLICATION_H_jS5yD2tF5aX6oS5eJ3cI
#define ___APPLICATION_H_jS5yD2tF5aX6oS5eJ3cI

#include <string>
#include <memory>
#include <vector>

class Application {
    bool state = true;
    std::string name;
    unsigned layer;

  public:
    Application(std::string n, unsigned l) :
        name(n), layer(l) {
    }
};

class AppManager {
  public:
    std::vector<std::unique_ptr<Application>> apps;

    Application* create(const std::string& name) {
        unsigned layer = apps.size();
        apps.push_back(std::make_unique<Application>(name, layer));
        return apps.back().get();
    }
};

#endif //___APPLICATION_H_jS5yD2tF5aX6oS5eJ3cI