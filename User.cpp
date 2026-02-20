#include "User.h"

size_t User::nextId = 0;

User::User(const std::string& name) : name(name), id(nextId) {
    nextId++;
}