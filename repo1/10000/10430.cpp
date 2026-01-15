#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (2 <= a && a <= 10000 && 2 <= b && b <= 10000 && 2 <= c && c <= 10000) {
		cout << (a+b) % c << endl << ((a%c)+(b%c))%c << endl << (a*b)%c << endl << ((a%c)*(b%c)) % c << endl;
	}
	return 0;
}