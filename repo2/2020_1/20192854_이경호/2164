#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int* arr = new int[N];
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
	while (N > 1)
	{
		if (N % 2 == 0)
		{
			int* newarr = new int[N / 2];
			for (int i = 1; i < N; i += 2)
				newarr[(i-1)/2] = arr[i];
			delete[] arr;
			arr = newarr;
			N /= 2;
		}
		else
		{
			int* newarr = new int[(int)(N / 2) + 1];
			newarr[0] = arr[N-1];
			for (int i = 1; i < N; i += 2)
				newarr[(i-1)/2+1] = arr[i];
			delete[] arr;
			arr = newarr;
			N = (int)(N / 2) + 1;
		}
	}
	cout << arr[0] << endl;
	return 0;
}
