#pragma once

#include "Topic.h"
#include <iostream>
#include <string>
#include <vector>
#include "User.h"

class Dashboard {
public:
    const User& user;
    std::vector<Topic> topics;

    Dashboard(const User& user);

    void printTopics();

    bool query();

    void makeTopic();

    void accessTopic(int index);
};