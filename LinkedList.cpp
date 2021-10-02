#include<iostream>
using namespace std;

/* LinkedList là 1 kiểu cấu trúc dữ liệu
 Trong đó là các Node được định nghĩa và có liên kết với nhau bằng next
 có thể có 1 liên kết là next và có thể có cả prev cho liên kết Node sau tới Node trước đó 
 trong file này chỉ sử dụng next
*/
class LinkedList
{
    public:
    struct Node
    {
        int data;
        Node* next;

        Node(){}
        Node(int value, Node* next){
            this->data = value;
            this->next = next;
        }
        Node(int value){
            this->data = value;
            this->next = NULL;
        }
    };
    
    Node* head; // Nên làm như này thì lúc sử dụng sẽ dễ hơn cho cả Stack and Queue
    /*
        Stack là LIFO: last in first out
        Queue là FIFO: first in first out
        Những cái này đều có trong thư viện của C++
    */
    void enQueue(int data) {
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
        } else { 
            Node* ptr = head;
            while(ptr->next != NULL) {
                ptr= ptr->next;
            }
            ptr->next = newNode;
        }
    }
    void deQueue() {
        cout<<"DEQUEUE: " <<head->data<<endl;
        head = head->next;
    }
    void display(){
        Node* ptr = head;
        while(ptr != NULL) {
            cout<<ptr->data<<" ";
            ptr= ptr->next;   
        }
        cout<<endl;
    }

    void push_stack(int n){
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }

    // Dùng khi mà Node mới được thêm vào ở cuối
    void pop_stack(){
        Node* ptr = head;
        Node* prev = head;
        while (ptr->next!=NULL)
        {   
            prev = ptr;
            ptr = ptr->next;
            
        }
        cout<<"POP "<< ptr->data<<endl;
        prev->next = NULL;
    }
    // Dùng khi mà Node mới được thêm vào đầu 
    void pop_head(){
        cout<<"POP head " <<head->data<<endl;
        head= head->next;
    }
};

int main(){
    LinkedList ls;
    ls.push_stack(1);
    ls.push_stack(2);
    ls.push_stack(3);
    ls.push_stack(4);
    ls.push_stack(5);
    ls.push_stack(6);
    ls.display();
    ls.pop_head();
    ls.pop_head();
    ls.display();
}