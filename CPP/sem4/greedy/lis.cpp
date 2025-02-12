// // Dynamic Programming C++ implementation
// // of LIS problem
// #include <bits/stdc++.h>
// using namespace std;

// // lis() returns the length of the longest
// // increasing subsequence in arr[] of size n
// int lis(int arr[], int n)
// {
// 	int lis[n];

// 	lis[0] = 1;

// 	// Compute optimized LIS values in
// 	// bottom up manner
// 	for (int i = 1; i < n; i++) {
// 		lis[i] = 1;
// 		for (int j = 0; j < i; j++)
// 			if (arr[i] > arr[j] && lis[i] < lis[j] + 1)
// 				lis[i] = lis[j] + 1;
// 	}


//     for (int i = 0; i < n; i++)
//     {
//         cout << lis[i] << " ";
//     }
//     cout << "\n";
// 	// Return maximum value in lis[]
// 	return *max_element(lis, lis + n);
// }

// // Driver program to test above function
// int main()
// {
// 	int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60 };
// 	int n = sizeof(arr) / sizeof(arr[0]);

// 	// Function call
// 	printf("Length of lis is %d\n", lis(arr, n));
// 	return 0;
// }


// Bianry Search Approach of Finding LIS by reducing
// the problem to longest common Subsequence
#include <bits/stdc++.h>
using namespace std;


int lengthOfLIS(vector<int>& nums)
{
	// binary search approach
	int n = nums.size();
	vector<int> ans;
	// Initialize the answer vector with the
	// first element of nums
	ans.push_back(nums[0]);

	for (int i = 1; i < n; i++) {
		if (nums[i] > ans.back()) {
			// If the current number is greater than the
			// last element of the answer vector, it means
			// we have found a longer increasing
			// subsequence. Hence, we append the current
			// number to the answer vector.
			ans.push_back(nums[i]);
		}
		else {
			// If the current number is not greater than the
			// last element of the answer vector, we perform
			// a binary search to find the smallest element
			// in the answer vector that is greater than or
			// equal to the current number.

			// The lower_bound function returns an iterator
			// pointing to the first element that is not
			// less than the current number.
			int low = lower_bound(ans.begin(), ans.end(),
								nums[i])
					- ans.begin();

			// We update the element at the found position
			// with the current number. By doing this, we
			// are maintaining a sorted order in the answer
			// vector.
			ans[low] = nums[i];
		}
        for (int i = 0; i < ans.size(); i++)
        {
            cout << ans[i] << " ";
        }
        cout << "\n";
        
	}

	// The length of the answer vector represents the length
	// of the longest increasing subsequence.
	return ans.size();
}

// Driver program to test above function
int main()
{
	vector<int> nums = { 0,4,12,2,10,6,9,13,3,11,7,15 };
	// Function call
	printf("Length of LIS is %d\n", lengthOfLIS(nums));
	return 0;
}

/* This code is contributed by Ravi Singh */
