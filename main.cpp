#include <iostream>
#include <vector>
#include <string>

#include "posts.h"
#include "user.h"

int main() {

    std::string action;
    // Create USERS HERE
    User user("goldenlover1", "John Doe", "CA");

    // Add some friends
    user.addFriend("petpal4ever");
    user.addFriend("whiskerwatcher");

    // Print user details
    user.printDetails();

    // Example usage
    PostsManager manager;

    // Add some posts
    manager.addPost(Post("p1924", "petpal4ever", "public"));
    manager.addPost(Post("p9367", "goldenlover1", "friend"));


// -------------------------Main Interface for terminal--------------------------
    std:: cout << "=========================================================" << std::endl;
    std::cout << "Welcome to Assignment 2 Code for Review!" << std::endl;
    std::cout << "Functions:" << std::endl;
    std::cout << "1.) Print Details" << std::endl;
    std::cout << "2.) User Posts" << std::endl;
    std::cout << "3.) Search by Location" << std::endl;
    std::cout << "4.) Add Friend" << std::endl;
    std::cout << "5.) Exit" << std::endl;
    std:: cout << "=========================================================" << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

    std::cin >> action;
    std::cout << action << std::endl;

    std::cout << std::endl;
    std::cout << std::endl;

// TODO: loop for actions and execution

// -------------------------Main Interface for terminal--------------------------

    // Retrieve posts for a user
    std::vector<Post> userPosts = manager.getPostsForUser("petpal4ever");
    std::cout << "Posts accessible to user petpal4ever: ";
    // if None print none else print posts
    if(userPosts.size() <= 0){
        std::cout << "None" << std::endl;
    }else{
        for (const Post& post : userPosts) {
            std::cout << "Post ID: " << post.getPostId() << ", Visibility: " << post.getVisibility() << std::endl;
        }
    }

    // Search users by location
    std::vector<std::string> users = {"petpal4ever", "goldenlover1", "whiskerwatcher"};
    std::vector<std::string> matchingUsers = manager.searchUsersByLocation("CA", users);

    // log users in State or None if None
    std::cout << "Users located in CA: ";
    if(matchingUsers.size() <= 0){
        std::cout << "None" << std::endl;
    }else{
        for (const std::string& user : matchingUsers) {
            std::cout << user << std::endl;
        }
    }

    return 0;
}