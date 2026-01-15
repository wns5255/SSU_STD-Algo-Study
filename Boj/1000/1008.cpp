#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (0 < a && a < 10 && 0 < b && b < 10)
		printf("%.9f",(double)a/b);
	return 0;
}