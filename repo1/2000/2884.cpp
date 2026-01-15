#include <iostream>
using namespace std;

int main(){
    int h = 0, m = 0;
    cin >> h >> m;
    if(0<=h&&h<=23 && 0<=m&&m<=59){
        if(m<45 && h>0){
            m=m+15;
            h= h-1;
        }
        else if(m<45 && h==0){
            m=m+15;
            h= h+23;
        }
        else
            m=m-45;    
        cout << h << " " << m;
    }
    return 0;
}