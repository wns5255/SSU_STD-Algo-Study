#include <iostream>

using namespace std;

int main(){
    int a,b;
    int h,t,o;
    
    cin >> a >> b;
    h = b/100; 
    t = (b - h * 100) / 10;
    o = b%10;
     
    cout << o * a << endl << t * a << endl << h * a << endl;
    cout << a * b;
    return 0;
}