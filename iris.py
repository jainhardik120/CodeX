import pandas as pd
import sklearn
from sklearn.svm import SVC
import pickle
import joblib
from sklearn.model_selection import train_test_split
colnames = ["s_length", "s_width", "p_length", "p_width", "class"]
dataset = pd.read_csv("https://archive.ics.uci.edu/ml/machine-learning-databases/iris/iris.data", header = None, names= colnames )
dataset = dataset.replace({"class":  {"Iris-setosa":1,"Iris-versicolor":2, "Iris-virginica":3}})
X = dataset.drop(["class"], axis=1)[:,0]
y = dataset["class"]
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.25, random_state = 0)
classifier = SVC(kernel = 'linear', random_state = 0)
#Fit the model on training data
classifier.fit(X_train, y_train)
#Make the prediction
y_pred = classifier.predict(X_test)
## Save as a pickle file
filename= 'final_mod_v1.pkl'
joblib.dump(classifier,open(filename, 'wb'))