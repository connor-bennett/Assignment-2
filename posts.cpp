#include "posts.h"

Post::Post(std::string postId, std::string userId, std::string visibility) 
    : postId(postId), userId(userId), visibility(visibility) {}

std::string Post::getPostId() const {
    return postId;
}

std::string Post::getUserId() const {
    return userId;
}

std::string Post::getVisibility() const {
    return visibility;
}

void PostsManager::addPost(const Post& post) {
    posts.push_back(post);
}

std::vector<Post> PostsManager::getPostsForUser(const std::string& userId) const {
    std::vector<Post> accessiblePosts;
    for (const Post& post : posts) {
        if (post.getUserId() != userId && post.getVisibility() == "public") {
            accessiblePosts.push_back(post);
        }
    }
    return accessiblePosts;
}

std::vector<std::string> PostsManager::searchUsersByLocation(const std::string& location, const std::vector<std::string>& users) const {
    std::vector<std::string> matchingUsers;
    for (const std::string& user : users) {
        // Assuming the state is stored as the last character of the username
        if (user.back() == location[0]) {
            matchingUsers.push_back(user);
        }
    }
    return matchingUsers;
}
