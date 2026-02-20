#pragma once

#include <string>
#include "User.h"
#include "Comment.h"
#include <vector>
#include <iostream>

class Topic {
public:
    const std::string title;
    const std::string body;
    const User& op;
    bool resolved;

    std::vector<Comment> comments;

    Topic(const std::string title, const std::string body, const User& op);

    void addComment(Comment& comment);

    void setResolved(bool resolve);

    void printComments();
};