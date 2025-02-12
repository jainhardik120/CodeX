import random

# Generate random user likes
users = []
posts = []
user_likes = {}

# Generate 100 users
for i in range(1, 101):
    user = f'User{i}'
    users.append(user)

    # Generate random number of liked posts for each user
    num_likes = random.randint(1, 20)
    likes = random.sample(range(1, 101), num_likes)
    user_likes[user] = [f'Post{j}' for j in likes]

    # Collect all unique posts
    posts.extend(user_likes[user])

posts = list(set(posts))  # Remove duplicates

print(f"Total Users: {len(users)}")
print(f"Total Posts: {len(posts)}")
print("User Likes:")
# for user, likes in user_likes.items():
#     print(f"{user}: {likes}")

print(user_likes)