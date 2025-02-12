#include <bits/stdc++.h>

using namespace std;
// This code only contains search() and main. To make it a complete running
// above code or see https://ide.geeksforgeeks.org/oY7OkD

// A suffix array based search function to search a given pattern
// 'pat' in given text 'txt' using suffix array suffArr[]

struct suffix
{
    int index;
    char *suff;
};
 
// A comparison function used by sort() to compare two suffixes
int cmp(struct suffix a, struct suffix b)
{
    return strcmp(a.suff, b.suff) < 0? 1 : 0;
}
 
// This is the main function that takes a string 'txt' of size n as an
// argument, builds and return the suffix array for the given string
int *buildSuffixArray(char *txt, int n)
{
    // A structure to store suffixes and their indexes
    struct suffix suffixes[n];
 
    // Store suffixes and their indexes in an array of structures.
    // The structure is needed to sort the suffixes alphabetically
    // and maintain their old indexes while sorting
    for (int i = 0; i < n; i++)
    {
        suffixes[i].index = i;
        suffixes[i].suff = (txt+i);
    }
 
    // Sort the suffixes using the comparison function
    // defined above.
    sort(suffixes, suffixes+n, cmp);
 
    // Store indexes of all sorted suffixes in the suffix array
    int *suffixArr = new int[n];
    for (int i = 0; i < n; i++)
        suffixArr[i] = suffixes[i].index;
 
    // Return the suffix array
    return  suffixArr;
}

void search(char *pat, char *txt, int *suffArr, int n)
{
	int m = strlen(pat); // get length of pattern, needed for strncmp()

	// Do simple binary search for the pat in txt using the
	// built suffix array
	int l = 0, r = n-1; // Initialize left and right indexes
	while (l <= r)
	{
		// See if 'pat' is prefix of middle suffix in suffix array
		int mid = l + (r - l)/2;
		int res = strncmp(pat, txt+suffArr[mid], m);

        cout << l << "+" << r << "=" << mid << "\n";

		// If match found at the middle, print it and return
		if (res == 0)
		{
			cout << "Pattern found at index " << suffArr[mid];
			return;
		}

		// Move to left half if pattern is alphabetically less than
		// the mid suffix
		if (res < 0) r = mid - 1;

		// Otherwise move to right half
		else l = mid + 1;
	}

	// We reach here if return statement in loop is not executed
	cout << "Pattern not found";
}

void printArr(int arr[], int n, char* txt)
{
    for(int i = 0; i < n; i++){
        cout << arr[i] << " " << txt+arr[i] << endl;
    }
}

// Driver program to test above function
int main()
{
	char txt[] = "aaaaaa"; // text
	char pat[] = "aaaaa"; // pattern to be searched in text

	// Build suffix array
	int n = strlen(txt);
	int *suffArr = buildSuffixArray(txt, n);
    printArr(suffArr, n, txt);

	// search pat in txt using the built suffix array
	search(pat, txt, suffArr, n);

	return 0;
}
