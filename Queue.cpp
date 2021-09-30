#include<iostream>
using namespace std;

// customer has 3 val: 1 name, 1 item, 1 number of item want to buy
class Customer{
    public:
    string name;
    string item;
    int num;
    Customer(){

    }
    Customer(string name, string wantToBuy, int num){
        this->name= name;
        this->item= wantToBuy;
        this->num= num;
    }

    void printCustomer(){
        cout<<"Name: "<<name<<" Item: "<<item <<" number: "<<num;
    }
};
class Node{
    public:
    Customer data;
    Node* next;

    Node(){

    }
    Node(Customer customer, Node* next){
        this->data= customer;
        this->next = next;
    }
};

class LinkListed{
    public:
    Node* head;

    LinkListed(){
        head = NULL;
    }

    void enqueue(Customer newCustomer){
        Node* newNode = new Node(newCustomer, NULL);
        if(head == NULL){
            head = newNode;
        } else {
            Node *tmp = head;
            while(tmp->next != NULL){
                tmp= tmp->next;
            }
            tmp->next= newNode;
        }
    }
    void dequeue(){
        if (head == NULL) {
            cout<<"Out of queue!!!\n";
        } else {
            cout<<"Customer "<<head->data.name<<" finished \n";
            head= head->next;
        }
        
    }
    void print(){
        Node* print = head;
        while(print != NULL){
            cout<<print->data.name<<" ";
            print= print->next;
        }
    }
};
// ietmName , constNumber = number of item in the shop, number = number want to buy, setName = name of the item
void printPill(string itemName,int &constNumber, int number, LinkListed &shop, string setName){
    if(itemName == setName) {
            if (constNumber >= number) {
               constNumber -= number;
               cout<<"\n success buying book ";
            }
            else {
                cout<<"cant do this offer ";
            }
            shop.dequeue();
        }
}


int main(){
    
    LinkListed shop;

    string name, item;
    int num;
    int count =0; 
    int item1 = 10; // book
    int item2 = 5;  // apple
    int item3 = 6;  // key
    
    while(true){
        cin>>name; if (name=="done") break;
        cin>>item>>num;
        count++;
        Customer customer(name, item, num);
        shop.enqueue(customer);
        
    }
       
    while (shop.head!=NULL) // stop when queue is empty    
    {
        string item = shop.head->data.item;
        int number = shop.head->data.num;
        printPill(item, item1, number, shop, "book");
        printPill(item, item2, number, shop, "apple");
        printPill(item, item3, number, shop, "key");
        count--;
        
    }
    return 0;
}