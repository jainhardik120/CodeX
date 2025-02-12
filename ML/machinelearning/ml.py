import pandas as pd
import random

# Sample data representing user likes
user_likes = {
    "User1": ["Post48", "Post93", "Post71", "Post22", "Post34", "Post78"],
    "User2": [
        "Post23",
        "Post59",
        "Post100",
        "Post25",
        "Post69",
        "Post39",
        "Post3",
        "Post38",
    ],
    "User3": [
        "Post24",
        "Post50",
        "Post40",
        "Post91",
        "Post75",
        "Post3",
        "Post77",
        "Post72",
        "Post33",
        "Post29",
        "Post81",
        "Post41",
        "Post15",
        "Post71",
        "Post68",
        "Post51",
    ],
    "User4": [
        "Post60",
        "Post28",
        "Post70",
        "Post44",
        "Post71",
        "Post85",
        "Post51",
        "Post100",
        "Post20",
        "Post3",
        "Post37",
        "Post55",
        "Post59",
        "Post34",
        "Post16",
        "Post47",
    ],
    "User5": [
        "Post80",
        "Post88",
        "Post49",
        "Post51",
        "Post35",
        "Post55",
        "Post70",
        "Post7",
    ],
    "User6": [
        "Post67",
        "Post76",
        "Post64",
        "Post83",
        "Post55",
        "Post98",
        "Post23",
        "Post77",
        "Post11",
        "Post24",
        "Post63",
        "Post47",
    ],
    "User7": [
        "Post90",
        "Post18",
        "Post49",
        "Post65",
        "Post78",
        "Post63",
        "Post95",
        "Post39",
        "Post33",
        "Post14",
        "Post23",
        "Post79",
        "Post12",
        "Post10",
        "Post61",
        "Post89",
        "Post96",
        "Post64",
        "Post41",
        "Post37",
    ],
    "User8": [
        "Post55",
        "Post70",
        "Post31",
        "Post92",
        "Post86",
        "Post30",
        "Post66",
        "Post50",
    ],
    "User9": ["Post8", "Post49", "Post50", "Post93", "Post74"],
    "User10": [
        "Post25",
        "Post9",
        "Post56",
        "Post64",
        "Post17",
        "Post19",
        "Post73",
        "Post97",
        "Post28",
        "Post54",
        "Post51",
    ],
    "User11": [
        "Post50",
        "Post1",
        "Post73",
        "Post98",
        "Post87",
        "Post94",
        "Post19",
        "Post90",
        "Post51",
        "Post49",
    ],
    "User12": [
        "Post88",
        "Post95",
        "Post92",
        "Post20",
        "Post73",
        "Post100",
        "Post39",
        "Post14",
        "Post51",
        "Post70",
        "Post18",
        "Post11",
        "Post24",
        "Post83",
        "Post7",
    ],
    "User13": [
        "Post89",
        "Post95",
        "Post99",
        "Post57",
        "Post3",
        "Post93",
        "Post64",
        "Post58",
        "Post29",
        "Post80",
        "Post35",
        "Post2",
        "Post87",
    ],
    "User14": [
        "Post57",
        "Post64",
        "Post73",
        "Post71",
        "Post29",
        "Post19",
        "Post78",
        "Post54",
        "Post70",
        "Post26",
        "Post69",
        "Post42",
        "Post53",
        "Post96",
        "Post59",
        "Post39",
    ],
    "User15": [
        "Post62",
        "Post83",
        "Post65",
        "Post5",
        "Post93",
        "Post45",
        "Post74",
        "Post97",
        "Post66",
    ],
    "User16": ["Post54", "Post87", "Post84", "Post57", "Post33", "Post79"],
    "User17": [
        "Post39",
        "Post29",
        "Post5",
        "Post19",
        "Post40",
        "Post91",
        "Post33",
        "Post87",
        "Post16",
        "Post11",
        "Post90",
        "Post8",
        "Post83",
    ],
    "User18": [
        "Post58",
        "Post62",
        "Post28",
        "Post17",
        "Post12",
        "Post72",
        "Post7",
        "Post61",
        "Post11",
        "Post52",
    ],
    "User19": [
        "Post2",
        "Post10",
        "Post17",
        "Post42",
        "Post44",
        "Post64",
        "Post45",
        "Post72",
        "Post12",
    ],
    "User20": [
        "Post89",
        "Post65",
        "Post42",
        "Post16",
        "Post85",
        "Post79",
        "Post41",
        "Post49",
        "Post96",
        "Post46",
        "Post77",
        "Post78",
        "Post94",
        "Post81",
        "Post51",
        "Post100",
    ],
    "User21": [
        "Post15",
        "Post24",
        "Post72",
        "Post76",
        "Post60",
        "Post7",
        "Post74",
        "Post20",
        "Post77",
    ],
    "User22": ["Post34", "Post87", "Post44"],
    "User23": ["Post26", "Post90", "Post28", "Post61", "Post47"],
    "User24": ["Post16", "Post77", "Post12", "Post47"],
    "User25": [
        "Post12",
        "Post92",
        "Post4",
        "Post53",
        "Post51",
        "Post79",
        "Post14",
        "Post6",
        "Post28",
        "Post77",
        "Post8",
        "Post7",
        "Post45",
    ],
    "User26": ["Post73"],
    "User27": ["Post68", "Post15", "Post57"],
    "User28": [
        "Post54",
        "Post35",
        "Post8",
        "Post16",
        "Post85",
        "Post78",
        "Post46",
        "Post89",
        "Post49",
        "Post74",
    ],
    "User29": [
        "Post74",
        "Post76",
        "Post100",
        "Post84",
        "Post6",
        "Post87",
        "Post58",
        "Post34",
        "Post23",
        "Post37",
    ],
    "User30": [
        "Post80",
        "Post58",
        "Post33",
        "Post37",
        "Post32",
        "Post94",
        "Post34",
        "Post6",
        "Post69",
    ],
    "User31": ["Post50", "Post57", "Post87", "Post83", "Post9", "Post77", "Post99"],
    "User32": [
        "Post46",
        "Post72",
        "Post52",
        "Post17",
        "Post98",
        "Post14",
        "Post20",
        "Post58",
        "Post51",
        "Post28",
        "Post56",
        "Post21",
        "Post39",
        "Post48",
        "Post1",
        "Post16",
        "Post80",
        "Post93",
        "Post41",
        "Post53",
    ],
    "User33": [
        "Post64",
        "Post97",
        "Post3",
        "Post30",
        "Post83",
        "Post78",
        "Post88",
        "Post94",
        "Post28",
        "Post31",
        "Post74",
        "Post55",
        "Post54",
        "Post23",
        "Post75",
        "Post20",
        "Post73",
    ],
    "User34": [
        "Post54",
        "Post52",
        "Post9",
        "Post79",
        "Post5",
        "Post88",
        "Post92",
        "Post62",
        "Post87",
        "Post95",
        "Post10",
        "Post91",
        "Post67",
        "Post34",
        "Post76",
    ],
    "User35": [
        "Post4",
        "Post37",
        "Post58",
        "Post32",
        "Post61",
        "Post99",
        "Post74",
        "Post16",
        "Post62",
        "Post92",
        "Post82",
        "Post91",
        "Post56",
        "Post11",
        "Post38",
        "Post14",
        "Post41",
        "Post89",
        "Post31",
    ],
    "User36": [
        "Post76",
        "Post3",
        "Post66",
        "Post35",
        "Post72",
        "Post59",
        "Post17",
        "Post33",
        "Post64",
        "Post48",
        "Post1",
        "Post78",
        "Post5",
        "Post20",
        "Post84",
        "Post70",
    ],
    "User37": [
        "Post90",
        "Post24",
        "Post45",
        "Post16",
        "Post69",
        "Post58",
        "Post62",
        "Post10",
        "Post38",
    ],
    "User38": ["Post90", "Post8", "Post16", "Post92", "Post5"],
    "User39": [
        "Post6",
        "Post58",
        "Post44",
        "Post7",
        "Post84",
        "Post73",
        "Post75",
        "Post28",
        "Post45",
        "Post2",
    ],
    "User40": [
        "Post11",
        "Post66",
        "Post16",
        "Post10",
        "Post80",
        "Post84",
        "Post78",
        "Post67",
        "Post47",
        "Post35",
        "Post97",
        "Post40",
        "Post73",
        "Post70",
        "Post74",
        "Post42",
        "Post83",
        "Post19",
        "Post22",
        "Post34",
    ],
    "User41": [
        "Post56",
        "Post39",
        "Post4",
        "Post9",
        "Post70",
        "Post40",
        "Post2",
        "Post7",
        "Post65",
        "Post71",
        "Post18",
        "Post84",
        "Post34",
        "Post94",
        "Post80",
        "Post21",
        "Post92",
        "Post77",
        "Post61",
        "Post36",
    ],
    "User42": [
        "Post65",
        "Post23",
        "Post49",
        "Post48",
        "Post36",
        "Post94",
        "Post46",
        "Post77",
        "Post2",
    ],
    "User43": [
        "Post18",
        "Post40",
        "Post64",
        "Post87",
        "Post37",
        "Post93",
        "Post83",
        "Post63",
        "Post92",
        "Post100",
        "Post26",
        "Post34",
        "Post56",
        "Post76",
        "Post77",
        "Post16",
        "Post85",
        "Post39",
        "Post81",
        "Post70",
    ],
    "User44": [
        "Post81",
        "Post12",
        "Post90",
        "Post83",
        "Post70",
        "Post19",
        "Post76",
        "Post38",
        "Post73",
        "Post67",
        "Post45",
        "Post62",
        "Post54",
    ],
    "User45": [
        "Post2",
        "Post55",
        "Post93",
        "Post69",
        "Post4",
        "Post47",
        "Post71",
        "Post61",
        "Post90",
        "Post96",
        "Post79",
        "Post5",
        "Post99",
        "Post30",
    ],
    "User46": ["Post3"],
    "User47": ["Post22", "Post32"],
    "User48": [
        "Post22",
        "Post45",
        "Post10",
        "Post35",
        "Post90",
        "Post37",
        "Post27",
        "Post33",
        "Post50",
        "Post40",
        "Post7",
        "Post56",
        "Post95",
        "Post4",
        "Post21",
        "Post100",
        "Post63",
        "Post31",
        "Post51",
        "Post2",
    ],
    "User49": [
        "Post8",
        "Post63",
        "Post42",
        "Post61",
        "Post87",
        "Post80",
        "Post36",
        "Post1",
        "Post37",
        "Post83",
        "Post100",
        "Post33",
        "Post5",
        "Post86",
        "Post35",
        "Post19",
        "Post62",
        "Post76",
        "Post7",
        "Post84",
    ],
    "User50": [
        "Post67",
        "Post84",
        "Post7",
        "Post18",
        "Post51",
        "Post68",
        "Post16",
        "Post46",
        "Post61",
        "Post87",
        "Post33",
    ],
    "User51": [
        "Post63",
        "Post68",
        "Post91",
        "Post39",
        "Post51",
        "Post89",
        "Post22",
        "Post32",
        "Post78",
        "Post71",
        "Post46",
        "Post49",
        "Post13",
        "Post62",
        "Post80",
        "Post64",
        "Post7",
    ],
    "User52": ["Post66", "Post82"],
    "User53": [
        "Post65",
        "Post47",
        "Post68",
        "Post54",
        "Post99",
        "Post75",
        "Post63",
        "Post94",
        "Post13",
        "Post8",
        "Post43",
        "Post48",
        "Post74",
        "Post83",
        "Post53",
        "Post78",
    ],
    "User54": ["Post29", "Post13", "Post83"],
    "User55": [
        "Post8",
        "Post31",
        "Post65",
        "Post81",
        "Post59",
        "Post20",
        "Post80",
        "Post13",
        "Post17",
        "Post71",
        "Post6",
    ],
    "User56": [
        "Post83",
        "Post33",
        "Post67",
        "Post63",
        "Post89",
        "Post57",
        "Post23",
        "Post15",
        "Post84",
        "Post85",
    ],
    "User57": [
        "Post81",
        "Post95",
        "Post78",
        "Post40",
        "Post69",
        "Post22",
        "Post90",
        "Post26",
        "Post79",
        "Post87",
        "Post46",
        "Post39",
        "Post61",
        "Post96",
        "Post52",
    ],
    "User58": [
        "Post91",
        "Post99",
        "Post24",
        "Post38",
        "Post65",
        "Post84",
        "Post13",
        "Post31",
    ],
    "User59": ["Post90", "Post12", "Post67", "Post32", "Post63"],
    "User60": [
        "Post99",
        "Post43",
        "Post27",
        "Post82",
        "Post32",
        "Post1",
        "Post76",
        "Post67",
        "Post51",
        "Post80",
    ],
    "User61": [
        "Post89",
        "Post8",
        "Post76",
        "Post74",
        "Post100",
        "Post73",
        "Post70",
        "Post46",
        "Post47",
        "Post22",
        "Post67",
        "Post83",
        "Post57",
        "Post79",
        "Post41",
        "Post58",
    ],
    "User62": ["Post89"],
    "User63": [
        "Post56",
        "Post29",
        "Post91",
        "Post51",
        "Post68",
        "Post59",
        "Post52",
        "Post76",
    ],
    "User64": ["Post93", "Post75", "Post70", "Post44", "Post53"],
    "User65": [
        "Post63",
        "Post27",
        "Post19",
        "Post43",
        "Post12",
        "Post13",
        "Post17",
        "Post64",
        "Post62",
        "Post54",
        "Post40",
        "Post2",
        "Post52",
        "Post92",
        "Post28",
        "Post57",
        "Post97",
        "Post50",
        "Post33",
    ],
    "User66": ["Post87", "Post26"],
    "User67": ["Post70", "Post7", "Post20", "Post61", "Post46", "Post89", "Post84"],
    "User68": [
        "Post95",
        "Post55",
        "Post39",
        "Post31",
        "Post75",
        "Post10",
        "Post63",
        "Post50",
        "Post99",
    ],
    "User69": [
        "Post17",
        "Post87",
        "Post23",
        "Post34",
        "Post8",
        "Post98",
        "Post91",
        "Post42",
        "Post21",
        "Post69",
        "Post75",
        "Post100",
        "Post33",
    ],
    "User70": [
        "Post15",
        "Post21",
        "Post96",
        "Post70",
        "Post51",
        "Post55",
        "Post19",
        "Post2",
        "Post62",
        "Post7",
        "Post13",
        "Post90",
        "Post31",
        "Post46",
        "Post91",
    ],
    "User71": [
        "Post18",
        "Post73",
        "Post10",
        "Post67",
        "Post85",
        "Post72",
        "Post65",
        "Post98",
        "Post25",
        "Post88",
    ],
    "User72": ["Post50", "Post65", "Post15", "Post53", "Post77", "Post95", "Post2"],
    "User73": [
        "Post87",
        "Post10",
        "Post100",
        "Post7",
        "Post83",
        "Post88",
        "Post95",
        "Post92",
        "Post51",
        "Post12",
        "Post68",
        "Post3",
        "Post78",
    ],
    "User74": [
        "Post53",
        "Post31",
        "Post4",
        "Post24",
        "Post95",
        "Post63",
        "Post20",
        "Post68",
    ],
    "User75": ["Post65", "Post94", "Post55", "Post3", "Post99", "Post90"],
    "User76": [
        "Post55",
        "Post12",
        "Post71",
        "Post69",
        "Post43",
        "Post72",
        "Post26",
        "Post93",
        "Post54",
        "Post57",
        "Post17",
        "Post32",
        "Post44",
    ],
    "User77": ["Post41", "Post22", "Post72", "Post46"],
    "User78": [
        "Post13",
        "Post12",
        "Post8",
        "Post76",
        "Post5",
        "Post28",
        "Post27",
        "Post39",
        "Post21",
        "Post91",
    ],
    "User79": [
        "Post84",
        "Post99",
        "Post98",
        "Post81",
        "Post90",
        "Post5",
        "Post16",
        "Post9",
        "Post45",
        "Post20",
    ],
    "User80": [
        "Post37",
        "Post22",
        "Post59",
        "Post95",
        "Post69",
        "Post93",
        "Post79",
        "Post9",
        "Post25",
        "Post14",
        "Post33",
        "Post96",
    ],
    "User81": [
        "Post86",
        "Post91",
        "Post89",
        "Post87",
        "Post29",
        "Post83",
        "Post84",
        "Post65",
        "Post7",
        "Post53",
        "Post96",
        "Post41",
        "Post31",
        "Post93",
        "Post44",
        "Post46",
        "Post81",
        "Post28",
    ],
    "User82": ["Post37", "Post75", "Post99", "Post48", "Post92", "Post89", "Post7"],
    "User83": ["Post86"],
    "User84": [
        "Post48",
        "Post55",
        "Post26",
        "Post41",
        "Post9",
        "Post56",
        "Post3",
        "Post90",
        "Post16",
        "Post66",
        "Post7",
        "Post68",
        "Post77",
        "Post4",
        "Post72",
        "Post35",
        "Post87",
        "Post64",
    ],
    "User85": [
        "Post91",
        "Post40",
        "Post18",
        "Post20",
        "Post25",
        "Post44",
        "Post65",
        "Post1",
        "Post75",
        "Post24",
        "Post34",
        "Post68",
        "Post92",
        "Post15",
        "Post74",
    ],
    "User86": [
        "Post42",
        "Post49",
        "Post56",
        "Post8",
        "Post27",
        "Post1",
        "Post71",
        "Post70",
        "Post94",
        "Post95",
        "Post28",
        "Post77",
        "Post97",
    ],
    "User87": ["Post63"],
    "User88": [
        "Post42",
        "Post59",
        "Post25",
        "Post93",
        "Post55",
        "Post46",
        "Post34",
        "Post67",
    ],
    "User89": [
        "Post49",
        "Post88",
        "Post81",
        "Post30",
        "Post93",
        "Post19",
        "Post54",
        "Post70",
        "Post34",
    ],
    "User90": [
        "Post4",
        "Post57",
        "Post71",
        "Post2",
        "Post86",
        "Post85",
        "Post100",
        "Post14",
        "Post17",
        "Post88",
        "Post47",
        "Post53",
        "Post35",
        "Post40",
        "Post42",
    ],
    "User91": [
        "Post98",
        "Post89",
        "Post62",
        "Post52",
        "Post27",
        "Post14",
        "Post21",
        "Post54",
        "Post56",
        "Post81",
        "Post33",
        "Post16",
        "Post17",
        "Post59",
        "Post8",
        "Post71",
        "Post92",
        "Post88",
        "Post87",
    ],
    "User92": [
        "Post100",
        "Post34",
        "Post28",
        "Post63",
        "Post52",
        "Post37",
        "Post59",
        "Post45",
        "Post56",
        "Post73",
        "Post55",
        "Post86",
        "Post78",
        "Post1",
        "Post35",
        "Post14",
        "Post95",
        "Post15",
    ],
    "User93": [
        "Post27",
        "Post47",
        "Post31",
        "Post11",
        "Post96",
        "Post48",
        "Post55",
        "Post45",
        "Post4",
        "Post87",
        "Post81",
        "Post2",
        "Post22",
        "Post18",
        "Post76",
        "Post100",
        "Post38",
        "Post20",
        "Post10",
    ],
    "User94": [
        "Post41",
        "Post89",
        "Post51",
        "Post3",
        "Post66",
        "Post70",
        "Post98",
        "Post29",
        "Post60",
        "Post88",
        "Post45",
        "Post7",
        "Post34",
        "Post97",
        "Post54",
        "Post39",
        "Post56",
    ],
    "User95": [
        "Post33",
        "Post59",
        "Post39",
        "Post44",
        "Post46",
        "Post58",
        "Post80",
        "Post73",
        "Post88",
        "Post71",
        "Post78",
        "Post23",
        "Post48",
        "Post57",
        "Post16",
    ],
    "User96": ["Post61", "Post64", "Post47", "Post60", "Post45", "Post25", "Post14"],
    "User97": ["Post97", "Post76", "Post63", "Post14", "Post3", "Post12"],
    "User98": ["Post5", "Post58"],
    "User99": [
        "Post99",
        "Post77",
        "Post97",
        "Post56",
        "Post76",
        "Post16",
        "Post25",
        "Post94",
        "Post18",
        "Post43",
        "Post60",
        "Post89",
        "Post2",
        "Post41",
        "Post36",
        "Post5",
        "Post15",
        "Post72",
        "Post87",
    ],
    "User100": [
        "Post34",
        "Post83",
        "Post88",
        "Post43",
        "Post82",
        "Post12",
        "Post33",
        "Post22",
        "Post1",
        "Post89",
        "Post58",
        "Post56",
        "Post94",
        "Post27",
        "Post39",
    ],
}

# Function to generate post recommendations for a given user
def recommend_posts(user_likes, current_user):
    # Find users who have liked more than 5 posts matching with the current user
    matching_users = []
    for user, likes in user_likes.items():
        if user != current_user:
            common_likes = set(likes).intersection(set(user_likes[current_user]))
            if len(common_likes) > 3:
                matching_users.append(user)


    other_likes = [likes for user, likes in user_likes.items() if user in matching_users]
    other_likes = [like for likes in other_likes for like in likes]

    # Count the occurrence of each post liked by matching users
    post_counts = pd.Series(other_likes).value_counts()

    # Filter posts that the current user has already liked
    filtered_counts = post_counts.drop(user_likes[current_user], errors='ignore')

    # Filter posts liked by more than 5 users in the matching group
    filtered_counts = filtered_counts[filtered_counts > 5]

    # Sort the posts by count (popularity) in descending order
    sorted_posts = filtered_counts.sort_values(ascending=False)

    # Return the recommended posts
    return sorted_posts.index.tolist()


# Test the recommender system
# current_user = "User1"
# recommended_posts = recommend_posts(user_likes, current_user)
# print(f"Recommended posts for {current_user}: {recommended_posts}")

for i in range(1, 101):
    current_user = f'User{i}'
    recommended_posts = recommend_posts(user_likes, current_user)
    print(f"Recommended posts for {current_user}: {recommended_posts}")
