#include <string>
#include "Topic.h"

Topic::Topic(const std::string title, const std::string body, const User& op) : title(title), body(body), op(op), resolved(false), comments(std::vector<Comment>()) {}

void Topic::addComment(const Comment& comment) {
    comments.push_back(comment);
}

void Topic::setResolved(bool resolve) {
    resolved = resolve;
}

void Topic::printComments() {
    for (size_t i = 0; i < comments.size(); i++) {
        std::cout << comments[i].commenter.name << ": " << comments[i].text << std::endl;
    }
}