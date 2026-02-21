#include <gtest/gtest.h>
#include "Topic.h"
#include "Dashboard.h"

TEST(DashboardTests, MakeTopic) {
    User user("username");
    Dashboard dashboard(user);

    Topic topic("title", "body", user);

    dashboard.topics.push_back(topic);

    EXPECT_EQ(dashboard.topics[0], topic);
}