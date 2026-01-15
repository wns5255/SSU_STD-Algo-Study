#include <iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	if (1 <= a && a <= 10000 && 1 <= b && b <= 10000)
		cout << a + b << endl << a - b << endl << a*b << endl << a / b << endl << a%b << endl;
	return 0;
}