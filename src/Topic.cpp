#include <string>
#include "Topic.h"

Topic::Topic(const std::string title, const std::string body, const User& op) : title(title), body(body), op(op), resolved(false), comments(std::vector<Comment>()) {}

void Topic::addComment(const Comment& comment) {
    comments.push_back(comment);
}

void Topic::setResolved(bool resolve, const User& user) {
    resolved = resolve;
    addComment(Comment("Topic marked as " + std::string(resolved ? "resolved" : "unresolved"), user));

}

void Topic::printComments() {
    for (size_t i = 0; i < comments.size(); i++) {
        std::cout << comments[i].commenter.name << ": " << comments[i].text << std::endl;
    }
}