#include <gtest/gtest.h>
#include "Topic.h"

TEST(TopicTests, SetTitleText) {
    User author("omkstrange1000");
    Topic topic("Money, money. I really like money.", "One day, I will purchase all the sushi in the world!", author);

    EXPECT_EQ(topic.title, "Money, money. I really like money.");
    EXPECT_EQ(topic.body, "One day, I will purchase all the sushi in the world!");
}

TEST(TopicTests, ResolveToggle) {
    User author("jckawesome200");
    Topic topic("I love chicken fingers", "I just lost the game", author);

    topic.setResolved(true, author);

    EXPECT_TRUE(topic.resolved); 

    EXPECT_EQ(topic.comments[0].text, "Topic marked as resolved");

    EXPECT_EQ(topic.comments[0].commenter, author);

    topic.setResolved(false, author);

    EXPECT_FALSE(topic.resolved);

    EXPECT_EQ(topic.comments[1].text, "Topic marked as unresolved");
}

TEST(TopicTests, AddComment) {
    User author("cmkflirtatious234");
    Topic topic("Wow, I'm learning C++!", "Rather than getting a girlfriend, of course.", author);

    topic.addComment(Comment("Confidence is key", author));

    EXPECT_EQ(topic.comments[0].commenter, author);
    EXPECT_EQ(topic.comments[0].text, "Confidence is key");
}