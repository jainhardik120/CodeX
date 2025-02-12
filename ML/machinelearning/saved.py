#%%
import pickle

linear = pickle.load(open("studentgrades.pickle", "rb"))
# %%
import pandas as pd
import numpy as np
df = pd.read_csv("student.csv", sep=";")

data =df[["G1", "G2", "G3", "studytime", "failures", "absences"]]

predict = "G3"

print(data.head())

X = np.array(data.drop([predict], axis=1))
y = np.array(data[[predict]])
# %%
predictions = linear.predict(X)
for i in range(len(predictions)):
    print(X[i], y[i], predictions[i])
# %%
import matplotlib.pyplot as plt

plt.plot(X[:,0], y, '+', label='Actual values')
plt.plot(X[:,0], predictions, '.', label='Actual values')
# plt.plot(X[:, 0], predictions, label='Predicted values')
plt.xlabel('Test input')
plt.ylabel('Test Output or Predicted output')
plt.legend()
plt.show()
# %%
plt.plot(X[:,1], y, '+', label='Actual values')
plt.plot(X[:,1], predictions, '.', label='Actual values')
# plt.plot(X[:, 0], predictions, label='Predicted values')
plt.xlabel('Test input')
plt.ylabel('Test Output or Predicted output')
plt.legend()
plt.show()