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
    if(!isEmpty()){
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
  int Back(){
    if(!isEmpty()){
      return rear->value;
    }
    else return -1;
  }
  bool isEmpty(){
    return size==0 ? true : false ;
  }
  void Card(){
    Node* tmp = front->next;
    front->next = front->next->next;
    rear->next = tmp;
    rear = tmp;
  }
};
int main(){
  int n;
  Queue a;
  cin >> n;
  for(int i=1; i<=n; i++)
    a.Push(i);
  while(a.Size()!=1){
    a.Pop();
    a.Card();
  }
  cout << a.Back();
}
