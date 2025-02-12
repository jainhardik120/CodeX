import pandas as pd
import matplotlib.pyplot as plt

# calories = {"day1": 420, "day2": 380, "day3": 390}

# myvar = pd.Series(calories)

# data = {
#   "calories": [420, 380, 390],
#   "duration": [50, 40, 45]
# }

# myvar = pd.DataFrame(data, index=["x", "y", "z"])

# print(myvar)

# pd.options.display.max_rows=200

df = pd.read_csv("data (1).csv")
print(df.corr())

# df.plot()
df.plot(kind="scatter", x="Duration", y="Calories")
df.plot(kind="scatter", x ="Maxpulse", y="Pulse")
plt.show()

# new_df = df.dropna()
# print(new_df.to_string())

# print("--------------------------------")
# print(df.to_string())
# print("----------------------------")
# df.dropna(inplace=True)
# print(df)

# print(df["Calories"].mean())
# print(df["Calories"].median())
# print(df["Calories"].mode()[0])

# df["Calories"].fillna(df["Calories"].mean(), inplace=True)
# df["Date"] = pd.to_datetime(df["Date"] , format='mixed', dayfirst=True)
# df.dropna(subset=["Date"], inplace=True)
# df.drop_duplicates(inplace=True)
# for x in df.index:
#     if(df.loc[x, "Duration"]>120):
#         df.drop(x, inplace=True)
# print(df.to_string())

# print(df.corr())

# df.loc[1, "Calories"] = 100
# print(df["Calories"][1])

# print(df)

# print(pd.options.display.max_rows)

# df = pd.read_json("data.json")
# print(df)

# data = {
#   "Duration":{
#     "0":60,
#     "1":60,
#     "2":60,
#     "3":45,
#     "4":45,
#     "5":60
#   },
#   "Pulse":{
#     "0":110,
#     "1":117,
#     "2":103,
#     "3":109,
#     "4":117,
#     "5":102
#   },
#   "Maxpulse":{
#     "0":130,
#     "1":145,
#     "2":135,
#     "3":175,
#     "4":148,
#     "5":127
#   },
#   "Calories":{
#     "0":409,
#     "1":479,
#     "2":340,
#     "3":282,
#     "4":406,
#     "5":300
#   }
# }

# df = pd.DataFrame(data, index=["0", "1"])

# print(df) 