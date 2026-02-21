#pragma once

#include <string>
class User {
public: 
    const std::string name;
    const size_t id;

    User(const std::string& name);

private:
    static size_t nextId;
};