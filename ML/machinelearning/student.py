#%%
import pandas as pd
import numpy as np
import sklearn
from sklearn import linear_model


df = pd.read_csv('student.csv', sep=';')

print(df.head())

data =df[["G1", "G2", "G3", "studytime", "failures", "absences"]]

predict = "G3"

print(data.head())

X = np.array(data.drop([predict], axis=1))
y = np.array(data[[predict]])



#%%
x_train, x_test, y_train, y_test = sklearn.model_selection.train_test_split(X, y, test_size=0.1)
linear = linear_model.LinearRegression()
linear.fit(x_train, y_train)
acc = linear.score(x_test, y_test)
print(acc)
print("Coefficient : \n", linear.coef_)
print("Intercept : \n", linear.intercept_)

#%%

predictions = linear.predict(x_test)
for x in range(len(predictions)):
    print(predictions[x], x_test[x], y_test[x])
# %%
import pickle
with open("studentgrades.pickle", "wb") as f:
    pickle.dump(linear, f)
# %%
