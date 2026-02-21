#pragma once

#include "Topic.h"
#include <iostream>
#include <string>
#include <vector>
#include "User.h"

class Dashboard {
public:
    const User& user;
    const User system;
    std::vector<Topic> topics;

    Dashboard(const User& user);

    void printTopics();

    bool query();

    void makeTopic();

    void accessTopic(size_t index);

    void resolveTopic(size_t index, bool resolve);
};