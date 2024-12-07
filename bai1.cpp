#include <iostream>
#include <string.h>

using namespace std;

struct Node{ 
    string name;
    int so_luong;
    int gia_tien;
    Node*next;
};

struct queue {
    Node *F = NULL;
    Node *R = NULL;
bool isEmpty() {
    return F == NULL;
}
bool isFull() {
    Node *temp = new Node;
    if(temp == NULL) {
        return true;
    }
    delete temp;
    return false;
}

void enqueue(string name, int price, int quantity) {
    if(isFull()) {
        cout<<"Hang doi tran"<< endl;
        return;
    }

    Node* newNode = new Node{name,price,quantity,NULL};
    if(R == NULL) {
        F=R = newNode;
    } else{
        R->next = newNode;
        R = newNode;
    }
}

void dequeue() {
    if(isEmpty()) {
        cout<<"Hang doi trong"<< endl;
        return;
    }

    Node *p = F;
    F = F-> next;
    if(F == NULL) {
        R = NULL;
    }
    cout<<p->name<<" da thanh toan xong"<< endl;
    delete p;
}
float TongsoTien() {
    float sum = 0;
    Node *p = F;
    while(p != NULL){
        sum += p-> gia_tien;
        p=p->next;
    }
    return sum;
}
int SosanphamA() {
    int count=0;
    Node *p = F;
    while(p != NULL) {
        count+= p->so_luong;
        p = p->next;
    }
    return count;
}
void clear() {
    while(!isEmpty()) {
        dequeue();
    }
  } 
};

int main() {
    queue queue;
    int n;
    if(queue.isEmpty()) {
        cout<<"Hang doi trong"<< endl;
    }
    cout<<"nhap so khach cua cua hang: ";
    cin>>n;
    for(int i=0;i<=n;i++) {
        string name;
        int price, quantity;
        cout<<"Nhap ten khach hang thu " <<i<< ": ";
        cin>>name;
        cout<<"So tien cua khach hang thu " <<i<< ": ";
        cin>>price;
        cout<<"Nhap so san pham A cua khach hang thu " <<i<< ": ";
        cin>>quantity;
        queue.enqueue(name, price, quantity);
    }
    if(!queue.isEmpty()) {
        cout<<"Hang doi da full" <<endl;
    }

    cout<<"So san pham A la: "<<queue.SosanphamA()<< endl;
    cout<<"Tong so tien thu duoc la: "<<queue.TongsoTien()<<endl;
    queue.clear();
    return 0;
}