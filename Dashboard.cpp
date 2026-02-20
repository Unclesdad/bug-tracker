#include "Dashboard.h"

Dashboard::Dashboard(const User& user) : user(user) {}

void Dashboard::printTopics() {
    if (topics.size() == 0) {
        std::cout << "-- No topics yet!! make one by typing \"c\" --" << std::endl;
    }
    for (size_t i = 0; i < topics.size(); i++) {
        std::cout << i << " " << topics[i].title << "   | " << topics[i].op.name << "  Comments: " << topics[i].comments.size() << std::endl;
    }
}

bool isAllDigits(std::string str) {
    if (str.empty()) return false;
    return std::all_of(str.begin(), str.end(), [](unsigned char c) {
        return std::isdigit(c);
    });
}

// returns true -> call again, returns false -> stop program
bool Dashboard::query() {
    std::cout << "\n\n";
    printTopics();
    std::cout << "#: access post  c - create post  x - exit" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    if (input == "c") {
        makeTopic();
        accessTopic(topics.size() - 1);
    }
    else if (isAllDigits(input)) {
        size_t index((size_t) std::stoi(input));
        if (index < topics.size()) {
            accessTopic(index);
        }
        else {
            std::cout << "Index out of bounds" << std::endl;
        }
    }
    else if (input == "x") {
        return false;
    }
    else {
        std::cout << "Input not understood. Please try again." << std::endl;
    }
    return true;
}

void Dashboard::makeTopic() {
    std::cout << "\n\n";

    std::cout << "Enter title:" << std::endl;
    std::string title;
    std::getline(std::cin, title);

    std::cout << std::endl;
    std::cout << "Enter body:" << std::endl;
    std::string body;
    std::getline(std::cin, body);

    topics.push_back(Topic(title, body, user));
}

void Dashboard::accessTopic(int index) {
    std::cout << "\n\n";
    Topic& topic(topics[index]);
    std::cout << "Title: " << topic.title << std::endl << "User: " << topic.op.name << std::endl << "-- BODY --" << std::endl << topic.body << "\n\n" << "-- COMMENTS --" << std::endl;
    topic.printComments();
    std::cout << "c - add comment  b - back" << std::endl;

    std::string input;
    std::getline(std::cin, input);

    if (input == "c") {
        std::cout << "\n\n";
        std::cout << "Enter comment text:" << std::endl;
        std::string commentText;
        std::getline(std::cin, commentText);
        
        Comment comment(commentText, user);

        topic.addComment(comment);
    }
    else if (input == "b") {}
    else {
        std::cout << "Input not understood. Please try again." << std::endl;
    }
}