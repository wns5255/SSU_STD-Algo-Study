#include<iostream>
using namespace std;
class Node{
friend class Queue;
private:
  int value;
  Node* next;
public:
  Node(const int v, Node * ptr):value(v),next(ptr){}
};
class Queue{
private:
  Node* front;
  Node* rear;
  int size;
public:
  Queue(){
    front = rear = new Node(0,NULL);
    size=0;
  }
  void Push(const int v){
    Node* newNode = new Node(v,front);
    rear->next = newNode;
    rear = newNode;
    size++;
  }
  int Pop(){
    if(!isEmpty()){ //size가 1일때랑 2이상일때 구분해야함
      if(size>=2){
        Node* removal =front->next;
        int tmp = removal->value;
        front->next = front->next->next;
        delete removal;
        size--;
        return tmp;
        }
      else{
        Node* removal =front->next;
        int tmp = removal->value;
        rear = front;
        front->next = NULL;
        delete removal;
        size--;
        return tmp;
      }
    }
    else{
      return -1;
    }
  }
  int Size(){
    return size;
  }
  int Front(){
    if(!isEmpty()){
      return front->next->value; 
    }
    else
      return -1;
  }
  int Back(){
    if(!isEmpty()){
      return rear->value;
    }
    else return -1;
  }
  bool isEmpty(){
    return size==0 ? true : false ;
  }
};
int main(){
  Queue a;
  int n;
  char command[6];
  cin >> n;
  for(int i=0; i<n; i++){
    scanf("%s",command);
    switch(command[0]){
    case 'p':
      if(command[1]=='u'){ //push
        int x;
        cin >> x;
        a.Push(x);
        break;
      }
      else{ //pop
        cout << a.Pop() << endl;
        break;
      }
    case 's': // size
      cout << a.Size() << endl;
      break;
    case 'e': //empty
      cout << a.isEmpty() << endl;
      break;
    case 'f': //front
      cout << a.Front() << endl;
      break;
    case 'b': //back
      cout << a.Back() << endl;
      break;
    }
  }
}
