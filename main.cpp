#include "Topic.h"
#include <iostream>
#include <string>
#include "User.h"
#include "Dashboard.h"

int main() {
    std::string name;

    std::cout << "Enter username" << std::endl;
    std::getline(std::cin, name);

    User user = User(name);

    std::cout << "User " << name << " id " << user.id << std::endl;

    Dashboard* dashboard = new Dashboard(user);

    bool loop = true;

    while (loop) {
        loop = dashboard->query();
    }
    
    delete dashboard;

    return 0;
}