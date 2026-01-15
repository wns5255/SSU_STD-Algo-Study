#include <iostream>
#include <algorithm>
using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int* arr = new int[n];
	arr[0] = 0;
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 4; i <= n; i++)
	{
		int min = std::min(arr[i - 2] + 1, arr[i - 3] + 2);
		if (i % 3 == 0)
			min = std::min(min, arr[i / 3 - 1] + 1);
		if (i % 2 == 0)
			min = std::min(min, arr[i / 2 - 1] + 1);
		arr[i - 1] = min;
	}
	cout << arr[n - 1];
	return 0;
}