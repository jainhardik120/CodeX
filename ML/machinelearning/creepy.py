
#%%
import pandas as pd

stories = pd.read_excel('creepypastas.xlsx')
# %%
import requests as req
# %%
import json
# %%

import random

categories = ['horror', 'comedy', 'romance', 'fantasy', 'sciencefiction', 'mystery', 'thriller', 'adventure', 'historical', 'drama', 'action', 'science', 'biography', 'inspirational', 'poetry']

tokens = ['Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI2NDkyZTNiODE5YTVkZjExMWFhNGM4YTQiLCJlbWFpbCI6InRlY2h5Z3V5MTIwQGdtYWlsLmNvbSJ9.EtClmJwblqhR11otIc3mp_4BCwNQxezAaeNoSA6gt7I', 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6ImphaW5oYXJkaWsxMjBAZ21haWwuY29tIiwidXNlcklkIjoiNjQ5MDM0N2Y2NjVmMWRkNmI5ZmI0MTM1IiwiaWF0IjoxNjg3Njg0MDY1fQ.O0ImEOugKfPd_oo2b6z5TE8B9toXUN8ybVqz6VDPRio', 'Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJlbWFpbCI6ImphaW5oYXJkaWsyMEBnbWFpbC5jb20iLCJ1c2VySWQiOiI2NDkyZDhiOGI2ZWYyZmZlYzU2NzFhM2UiLCJpYXQiOjE2ODc2ODQxMjF9.2X7dusoNIvhxka8jfXhMwOVsAVCoc6J3XY1n4-JJzFs']

def createPost(content):
    url = "https://tale-vista-server.onrender.com/api/posts"

    # JSON data for the request body
    data = {
        "content": content,
        "category": random.choice(categories)
    }

    # Authorization headers
    headers = {
        "Authorization": random.choice(tokens),
        "Content-Type": "application/json"
    }

    # Send POST request
    response = req.post(url, json=data, headers=headers)

    # Check response status code
    print(response.status_code)

#%%
# body  = stories['body']
# # %%
# for index, row in stories.head(50).iterrows():
#     body = row['body']  # Assuming 'body' is the column name containing the post body
#     createPost(body)

# %%
# object_ids = [
#     '6497f91f91c62f45bc4405a0',
#     '6497fa6991c62f45bc4405a3',
#     '6497fa6a91c62f45bc4405a6',
#     '6497fa6a91c62f45bc4405a9',
#     '6497fa6a91c62f45bc4405ac',
#     '6497fa6b91c62f45bc4405af',
#     '6497fa6b91c62f45bc4405b2',
#     '6497fa6b91c62f45bc4405b5',
#     '6497fa6c91c62f45bc4405b8',
#     '6497fa6c91c62f45bc4405bb',
#     '6497fa6d91c62f45bc4405be',
#     '6497fa6d91c62f45bc4405c1',
#     '6497fa6d91c62f45bc4405c4',
#     '6497fa6e91c62f45bc4405c7',
#     '6497fa6e91c62f45bc4405ca',
#     '6497fa6f91c62f45bc4405cd',
#     '6497fa6f91c62f45bc4405d0',
#     '6497fa7091c62f45bc4405d3',
#     '6497fa7091c62f45bc4405d6',
#     '6497fa7091c62f45bc4405d9',
#     '6497fa7191c62f45bc4405dc',
#     '6497fa7191c62f45bc4405df',
#     '6497fa7291c62f45bc4405e2',
#     '6497fa7291c62f45bc4405e5',
#     '6497fa7291c62f45bc4405e8',
#     '6497fa7391c62f45bc4405eb',
#     '6497fa7391c62f45bc4405ee',
#     '6497fa7491c62f45bc4405f1',
#     '6497fa7491c62f45bc4405f4',
#     '6497fa7491c62f45bc4405f7',
#     '6497fa7591c62f45bc4405fa',
#     '6497fa7591c62f45bc4405fd',
#     '6497fa7691c62f45bc440600',
#     '6497fa7691c62f45bc440603',
#     '6497fa7691c62f45bc440606',
#     '6497fa7791c62f45bc440609',
#     '6497fa7791c62f45bc44060c',
#     '6497fa7891c62f45bc44060f',
#     '6497fa7891c62f45bc440612',
#     '6497fa7991c62f45bc440615',
#     '6497fa7991c62f45bc440618',
#     '6497fa7991c62f45bc44061b',
#     '6497fa7a91c62f45bc44061e',
#     '6497fa7a91c62f45bc440621',
#     '6497fa7a91c62f45bc440624',
#     '6497fa7b91c62f45bc440627',
#     '6497fa7b91c62f45bc44062a',
#     '6497fa7b91c62f45bc44062d',
#     '6497fa7c91c62f45bc440630',
#     '6497fa7c91c62f45bc440633',
#     '6497fa7d91c62f45bc440636',
#     '6497fb0291c62f45bc44065f',
#     '6497fb0391c62f45bc440662',
#     '6497fb0391c62f45bc440665',
#     '6497fb0491c62f45bc440668',
#     '6497fb0591c62f45bc44066b',
#     '6497fb0591c62f45bc44066e',
#     '6497fb0691c62f45bc440671',
#     '6497fb0691c62f45bc440674',
#     '6497fb0691c62f45bc440677',
#     '6497fb0791c62f45bc44067a',
#     '6497fb0791c62f45bc44067d',
#     '6497fb0891c62f45bc440680',
#     '6497fb0891c62f45bc440683',
#     '6497fb0991c62f45bc440686',
#     '6497fb0991c62f45bc440689',
#     '6497fb0a91c62f45bc44068c',
#     '6497fb0a91c62f45bc44068f',
#     '6497fb0a91c62f45bc440692',
#     '6497fb0b91c62f45bc440695',
#     '6497fb0b91c62f45bc440698',
#     '6497fb0c91c62f45bc44069b',
#     '6497fb0c91c62f45bc44069e',
#     '6497fb0c91c62f45bc4406a1',
#     '6497fb0d91c62f45bc4406a4',
#     '6497fb0d91c62f45bc4406a7',
#     '6497fb0e91c62f45bc4406aa',
#     '6497fb0e91c62f45bc4406ad',
#     '6497fb0f91c62f45bc4406b0',
#     '6497fb0f91c62f45bc4406b3',
#     '6497fb0f91c62f45bc4406b6',
#     '6497fb1091c62f45bc4406b9',
#     '6497fb1091c62f45bc4406bc',
#     '6497fb1191c62f45bc4406bf',
#     '6497fb1191c62f45bc4406c2',
#     '6497fb1291c62f45bc4406c5',
#     '6497fb1291c62f45bc4406c8',
#     '6497fb1291c62f45bc4406cb',
#     '6497fb1391c62f45bc4406ce',
#     '6497fb1391c62f45bc4406d1',
#     '6497fb1491c62f45bc4406d4',
#     '6497fb1491c62f45bc4406d7',
#     '6497fb1591c62f45bc4406da',
#     '6497fb1591c62f45bc4406dd',
#     '6497fb1591c62f45bc4406e0',
#     '6497fb1691c62f45bc4406e3',
#     '6497fb1691c62f45bc4406e6',
#     '6497fb1791c62f45bc4406e9',
#     '6497fb1791c62f45bc4406ec',
#     '6497fb1791c62f45bc4406ef',
#     '6497fb1891c62f45bc4406f2'
# ]

# %%
# def deletePosts(objectId) : 
#     url = "https://tale-vista-server.onrender.com/api/posts/post/" + objectId

#     # Authorization headers
#     headers = {
#         "Authorization": "Bearer eyJhbGciOiJIUzI1NiIsInR5cCI6IkpXVCJ9.eyJ1c2VySWQiOiI2NDkyZTNiODE5YTVkZjExMWFhNGM4YTQiLCJlbWFpbCI6InRlY2h5Z3V5MTIwQGdtYWlsLmNvbSJ9.EtClmJwblqhR11otIc3mp_4BCwNQxezAaeNoSA6gt7I",
#         "Content-Type": "application/json"
#     }

#     # Send POST request
#     response = req.delete(url, headers=headers)

#     # Check response status code
#     print(response.status_code)

# for i in object_ids:
#     deletePosts(i)

#%%

# batch = stories.iloc[600:900]
# for index, row in batch.iterrows():
#     body = row['body']  # Assuming 'body' is the column name containing the post body
#     createPost(body)

#%%
