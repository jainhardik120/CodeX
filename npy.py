import numpy as np

print(np.__version__)
arr = np.array([[1, 2, 3], [4, 5, 6]], ndmin=2)
print(arr[1, 2])
print(arr[1, -1])  # negative means from end [-3, -2, -1] indexes
print(type(arr))


arr2 = np.array([1, 2, 3, 4, 5, 6, 7])
print(arr2[1:4])  # 2 3 4
print(arr2[0::3])  # 1 4 7
print(arr2[4::2])  # 5 7
print(arr2[-3:-1])  # 5 6
print(arr2[-3:-6])  # No value

arr = np.array([[1, 2, 3, 4, 5], [6, 7, 8, 9, 10]])
print(arr.shape)
print(arr[1, 1:4])
print(arr[0:, 2])


arr = np.array([[[1, 2, 3, 4], [1, 2, 3, 4]], [[1, 2, 3, 4], [1, 2, 3, 4]]], ndmin=5)

print(arr)
print("shape of array :", arr.shape)
newarr = arr.reshape(1, 2, 2, 2, 2)
newarr[0, 1, 1, 1, 1] = 100
print(arr)
print(newarr)
print("shape of array :", newarr.shape)

for x in arr:
    for y in x:
        for z in y:
            for w in z:
                print(w)

for x in np.nditer(arr):
    print(x)

arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])

for x in np.nditer(arr[:, ::2]):
    print(x)

arr = np.array([[1, 2, 3, 4], [5, 6, 7, 8]])

for idx, x in np.ndenumerate(arr):
    print(idx[0], idx[1], x)

arr1 = np.array([[1, 2], [3, 4]])

arr2 = np.array([[5, 6], [7, 8]])

arr = np.concatenate((arr1, arr2), axis=1)


arr = np.array([1, 2, 3, 4, 5, 6])

newarr = np.array_split(arr, 3)

print(newarr)

print(arr)

arr = np.array(
    [[1, 2, 3], [4, 5, 6], [7, 8, 9], [10, 11, 12], [13, 14, 15], [16, 17, 18]]
)

newarr = np.array_split(arr, 3)
newarr2 = arr.reshape(3, -1, 3)
print(newarr2.shape)
print(newarr2)

print(newarr)

# print(arr.dtype)

# arr = np.array(['apple', 'banana', 'cherry'])

# print(arr.dtype)

# arr = np.array([1, 2, 3, 4], dtype='S4')

# print(arr)
# print(arr.dtype)


# arr = np.array(['1', '2', '3'], dtype='i')

# print(arr)

# arr = np.array([1.1, 2.1, 3.1])

# newarr = arr.astype('i')

# print(newarr)
# print(newarr.dtype)

# arr = np.array([1, 2, 3, 4, 5])
# x = arr.view()
# arr[0] = 42

# print(arr)
# print(x)

# print(arr.base)
# print(x.base)


arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])

x = np.where(arr % 2 == 0)

for y in x:
    print(arr[y])


arr = np.array([1, 2, 4, 6])

x = np.searchsorted(arr, [2, 4, 6], side="right")

print(x)

arr = np.array([41, 42, 43, 44])

filter_arr = arr > 42

newarr = np.where(arr > 42)

print(filter_arr)
print(newarr)

X = np.linspace(-np.pi, np.pi, 256, endpoint=True)
C, S = np.cos(X), np.sin(X)
import matplotlib.pyplot as plt

# plt.plot(X, C)
# plt.plot(X, S)
# plt.show()

X = np.array([-np.pi, -np.pi / 2, -np.pi / 4, 0, np.pi / 4, np.pi / 2, np.pi])
A,B,C = np.tan(X), np.cos(X), np.sin(X)

plt.scatter(X,A)
plt.scatter(X,1/A)
plt.scatter(X,1/B)
plt.scatter(X,1/C)

plt.show()

# Create a sample array
arr = np.array([5, 2, 9, 1, 5])

# Sort the array
sorted_arr = np.sort(arr)
print("Sorted array:", sorted_arr)

# Sort the array row-wise
matrix = np.array([[5, 2, 9], [1, 5, 3]])
sorted_matrix = np.sort(matrix, axis=0)
print("Sorted matrix row-wise:")
print(sorted_matrix)

# Sort array with specified sort algorithm (e.g., quicksort)
arr = np.array([5, 2, 9, 1, 5])
sorted_arr_quick = np.sort(arr, kind='quicksort')
print("Sorted array using quicksort:", sorted_arr_quick)

# Define a structured array
dtype = [('PNAME', 'S10'), ('TOTAL_SALE', float), ('RATING', float)]
data = [('ProductA', 100.0, 4.5), ('ProductB', 75.0, 4.2), ('ProductC', 120.0, 4.9)]
structured_arr = np.array(data, dtype=dtype)

# Sort array by names
sorted_by_name = np.sort(structured_arr, order='PNAME')
print("Sorted by name:")
print(sorted_by_name)

# Sort array by total sale and then rating
sorted_by_sale_rating = np.sort(structured_arr, order=['TOTAL_SALE', 'RATING'])
print("Sorted by total sale and rating:")
print(sorted_by_sale_rating)

# Print details of the top-rated product
top_rated_product = sorted_by_sale_rating[-1]
print("Top Rated Product Details:")
print("Product Name:", top_rated_product['PNAME'])
print("Total Sale:", top_rated_product['TOTAL_SALE'])
print("Rating:", top_rated_product['RATING'])
import matplotlib.pyplot as plt

# Test Data
GMAT_score = [87, 91, 79, 88, 99, 79, 59, 99, 79, 33]
GRE_score = [34, 78, 78, 47, 99, 87, 31, 44, 19, 29]
marks_range = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]

# Create a scatter plot
plt.scatter(marks_range, GMAT_score, label="GMAT Score", marker='o', color='blue')
plt.scatter(marks_range, GRE_score, label="GRE Score", marker='x', color='red')

# Set labels and title
plt.xlabel("Marks Range")
plt.ylabel("Score")
plt.title("GMAT vs GRE Scores")

# Add a legend
plt.legend()

# Display the plot
# plt.show()

a = np.zeros((2,2,2),dtype='int64')
print(a)