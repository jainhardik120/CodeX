import string
import random
import requests

def generate_random_username(i):
    x = i//100;
    y = i%100;
    first_names = [
    "Emma", "Liam", "Olivia", "Noah", "Ava", "Isabella", "Sophia", "Mia", "Elijah", "Oliver",
    "Aiden", "Charlotte", "Amelia", "Harper", "Evelyn", "Abigail", "Emily", "Elizabeth", "Sofia", "Scarlett",
    "Grace", "Victoria", "Madison", "Luna", "Chloe", "Penelope", "Layla", "Riley", "Ellie", "Zoey",
    "Lily", "Stella", "Aurora", "Hannah", "Natalie", "Emilia", "Avery", "Scarlett", "Grace", "Victoria",
    "Madison", "Luna", "Chloe", "Penelope", "Layla", "Riley", "Ellie", "Zoey", "Lily", "Stella",
    "Aurora", "Hannah", "Natalie", "Emilia", "Avery", "Evelyn", "Ella", "Brooklyn", "Scarlett", "Lily",
    "Hannah", "Chloe", "Sofia", "Zoey", "Emily", "Grace", "Elizabeth", "Penelope", "Natalie", "Avery",
    "Addison", "Ellie", "Victoria", "Harper", "Skylar", "Samantha", "Ava", "Zoe", "Abigail", "Camila",
    "Elizabeth", "Lillian", "Ella", "Addison", "Layla", "Alexis", "Grace", "Hannah", "Zoey", "Aria",
    "Aubrey", "Riley", "Nora", "Scarlett", "Lily", "Eleanor", "Hazel", "Violet", "Brooklyn", "Bella"
]

    last_names = [
    "Smith", "Johnson", "Williams", "Jones", "Brown", "Davis", "Miller", "Wilson", "Taylor", "Anderson",
    "Thomas", "Jackson", "White", "Harris", "Martin", "Thompson", "Garcia", "Martinez", "Robinson", "Clark",
    "Rodriguez", "Lewis", "Lee", "Walker", "Hall", "Allen", "Young", "Hernandez", "King", "Wright",
    "Lopez", "Hill", "Scott", "Green", "Adams", "Baker", "Gonzalez", "Nelson", "Carter", "Mitchell",
    "Perez", "Roberts", "Turner", "Phillips", "Campbell", "Parker", "Evans", "Edwards", "Collins", "Stewart",
    "Sanchez", "Morris", "Rogers", "Reed", "Cook", "Morgan", "Bell", "Murphy", "Bailey", "Rivera",
    "Cooper", "Richardson", "Cox", "Howard", "Ward", "Torres", "Peterson", "Gray", "Ramirez", "James",
    "Watson", "Brooks", "Kelly", "Sanders", "Price", "Bennett", "Wood", "Barnes", "Ross", "Henderson",
    "Coleman", "Jenkins", "Perry", "Powell", "Long", "Patterson", "Hughes", "Flores", "Washington", "Butler",
    "Simmons", "Foster", "Gonzales", "Bryant", "Alexander", "Russell", "Griffin", "Diaz", "Hayes", "Myers"
]

    first_name = first_names[x];
    last_name = last_names[y];
    return f"{first_name.lower()}{last_name.lower()}"

def generate_random_email(username):
    domains = ['gmail.com', 'yahoo.com', 'outlook.com', 'hotmail.com', 'example.com']
    domain = random.choice(domains)
    return f"{username}@{domain}"

def generate_random_password():
    chars = string.ascii_letters + string.digits + string.punctuation
    return ''.join(random.choice(chars) for _ in range(12))

def signup_user(username, email, password):
    url = "http://localhost:5000/api/user/signup"
    data = {
        "email": email,
        "password": password,
        "username": username
    }

    response = requests.post(url, json=data)
    return response        

with open("user_accounts2.txt", "w") as file:
    for i in range(10000):
        username = generate_random_username(i)
        email = generate_random_email(username)
        password = generate_random_password()
        response = signup_user(username, email, password)
