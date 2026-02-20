#include "Comment.h"

Comment::Comment(const std::string text, const User& commenter) : text(text), commenter(commenter) {}