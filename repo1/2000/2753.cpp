#include <iostream>
using namespace std;
int year = 0;

int main(){
    cin >> year;
    if(1<=year&&year<=4000){
        if (year%4 == 0 && year%100 != 0)
            cout << "1";
        else if (year%400 == 0)
            cout << "1";
        else 
            cout << "0";
    }
    return 0;
}

