#pragma once

#include <string>
#include "User.h"

class Comment {
public:
    const std::string text;
    const User& commenter;

    Comment(const std::string text, const User& commenter);
};