#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
	void sortColors(vector<int> &nums)
	{
		int sum[] = {0, 0, 0};
		for (int i = 0; i < nums.size(); i++)
		{
			sum[nums[i]]++;
		}
		int itr = 0;
		int currVal = 0;
		while (itr < nums.size())
		{
			if (sum[currVal] == 0)
			{
				currVal++;
			}
			else
			{
				nums[itr] = currVal;
				itr++;
				sum[currVal]--;
			}
		}
	}
};

int main()
{

	return 0;
}
