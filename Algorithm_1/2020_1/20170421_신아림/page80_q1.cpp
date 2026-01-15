#include <iostream>

using namespace std;

void increase(int &a)
{
   a++;
}
void change(int &a)
{
   a*=-1;
}

int main()
{
   int num;
   cout<<"num : ";
   cin>>num;
   increase(num);
   cout<<"1증가 후 : "<<num<<endl;
   change(num);
   cout<<"부호 바뀐 후 : "<<num<<endl;

   return 0;
}