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
  bool isEmpty(){
    return size==0 ? true : false ;
  }
  int Priority(int x){
      int res = 0;
      Node* scan = front->next;
      for(int i=0; i<x; i++)
        scan = scan->next; // M번째 값 가리키는 포인터
      while(size!=0){
        Node* cur = front->next;
        Node* max = front->next;
        for(Node* i = front->next; i!=front; i=i->next){
          if(max->value < i->value)
            max = i;
        }
        if(max->value > cur->value){ // 현재 큐 값보다 큰 값이 존재 >>  cur 맨 뒤로 보내기
            front->next = front->next->next;
            rear->next = cur;
            rear = cur;
            rear->next = front;
        }
        else{ // cur==max
          if(cur==scan) return ++res;
          else{
            Pop();
            res++;
          }
        }
      }
    return res;
  }
  ~Queue(){
    while(size){
      Pop();
    }
  }
};
int main(){
  int n,N,M;
  cin >> n;
  for(int i=0; i<n; i++){
    Queue a;
    cin >> N;
    cin >> M;
    for(int i=0; i<N; i++){
      int tmp;
      cin >> tmp;
      a.Push(tmp);
    }
    cout << a.Priority(M) << endl;
  }
}
/*priority 매서드 문제해결의 아이디어
현재 노드를 기준으로 cur = front->next
더 큰 값을 가지는 노드가 있는지 확인 => max->value cur->value 비교
1.max->value > cur->value : cur맨 뒤로
2.cur==max : cur 제거
  cur 제거 : if(cur==scan) return res++;
  else cur 제거 */
