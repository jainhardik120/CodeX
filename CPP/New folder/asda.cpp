#include <iostream>
using namespace std;

int main()
{
	// your code goes here
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		char arr[n];
		cin >> arr;
		int count1 = 0;
		int i = 0;
		while (arr[i] != '0' && i < n)
		{
			count1++;
			i++;
		}
		if (i == n)
		{
			cout << n << "\n";
		}
		else
		{
			int maxLength = 0;
			int count2 = 0;
			while (i < n)
			{
				if (arr[i] == '0')
				{
					if (maxLength < count2)
					{
						maxLength = count2;
						count2 = 0;
					}
				}
				else
				{
					count2++;
				}
				i++;
			}
			if (maxLength < count2)
			{
				maxLength = count2;
			}
			cout << count1 + maxLength << "\n";
		}
	}
	return 0;
}
