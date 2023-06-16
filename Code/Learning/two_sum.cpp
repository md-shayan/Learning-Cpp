#include <cstdio>

void TwoSum(int arr[], int target, int size)
{

	for (int left=0; left<size; left++)
	{
		for(int right=left+1; right<size; right++)
		{
			if (arr[left]+arr[right] == target)
			{
				printf("[%d, %d]", left, right);
				break;
			}
		}
	}
}

int main()
{
	int arr[5] = {1, 4, 6, 8, 2};
	int target = 6;
	TwoSum(arr, target, 5);
}