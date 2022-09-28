#include <iostream>
using namespace std;

template<class T> class Node {
public:
    T data;
    Node *next;
    Node *prev;
};

template<class T> class DoublyLinkedList{
    
    public:
        DoublyLinkedList<T>(){
            head1 = new Node<T>;
            tail1 = new Node<T>;
            head1->next = tail1;
            tail1->prev = head1;
            head2 = new Node<T>;
            tail2 = new Node<T>;
            head2->next = tail2;
            tail2->prev = head2;
        };

        bool empty();
        int length();
        void display();
        void create(int n);
        void create1(int n);
        void add(int pos,T x);
        void vipe(int pos);
        void search(T x);
        void concate();
    private:
        Node<T> *head1;
        Node<T> *tail1;
        Node<T> *head2;
        Node<T> *tail2;
};

template<class T> bool DoublyLinkedList<T>::empty(){
    if (head1->next == tail1) {
        return true;
    } else
        return false;
}

template<class T> int DoublyLinkedList<T>::length(){
    Node<T> *ptr = head1;
    int len = 0;
    while (ptr != nullptr) {
        len++;
        ptr = ptr->next;
    }
    return len;
}

template<class T> void DoublyLinkedList<T>::display(){
    Node<T> *ptr = new Node<T>;
    if (empty()==true){
        cout << " Empty !!";
    } else {
        cout<<"The List is :- [ ";
        
        ptr = head1->next;
        while (ptr != tail1) {
            if(ptr->next==tail1)
                cout << ptr->data << " ";
            else
                cout << ptr->data << ", ";
            ptr = ptr->next;
        }
        cout<<"]";
    }
}

template<class T> void DoublyLinkedList<T>::add(int pos,T x){
    Node<T> *temp =new Node<T>;
    Node<T> *ptr =new Node<T>;
    if(pos==0){
        ptr->next=head1->next;
        head1->next->prev = ptr;
        ptr->prev=head1;
        ptr->data=x;
        head1->next=ptr;
    }else if(pos==length()){
        ptr->next = tail1;
        ptr->prev = tail1->prev;
        tail1->prev->next = ptr;
        tail1->prev = ptr;
        ptr->data = x; 
    }else{
        ptr = head1->next;
        int count=0;
        for(int i=1;i<=pos-1;i++)
            ptr = ptr->next;
        ptr->prev->next = temp;
        temp->next = ptr;
        temp->data = x;
        temp->prev = ptr->prev;
        ptr->prev = temp;
        cout << endl;
        cout << x << " has been added at position " << pos << " !!";
    }
}

template<class T> void DoublyLinkedList<T>::vipe(int pos){
    Node<T> *ptr = new Node<T>;
    Node<T> *temp = new Node<T>;
    if (empty() == true) {
        cout << "List is empty ." << endl;
    }else if(head1->next=nullptr){
        cout<<"can't delete";
    }else{
        if(pos==0){
            ptr=head1->next;
            head1->next = ptr->next;
            ptr->next->prev=head1;
            cout << "Element " << ptr->data << " deleted . " << endl;
            delete ptr;
        }else if(pos==length()){
            temp= tail1->prev;
            temp->prev->next = tail1;
            tail1->prev = temp->prev;
            cout << "Element " << temp->data << " deleted . " << endl;
            delete temp; 
        }else{
            temp=head1;
            for(int i=1;i<pos-1;i++){
                temp=temp->next;
            }
            ptr->prev->next = ptr->next;
            ptr->next->prev = ptr->prev;
            cout << "Element " << ptr->data << " deleted . " << endl;
            delete ptr;
        }
    }
}

template<class T> void DoublyLinkedList<T>::create(int size){
    Node<T> *n, *ptr;
    T x;
    head1 = new Node<T>;
    if (head1==nullptr) {
        cout << "\nUnable to allocate memory.";
    }else{
        cout << "\nEnter the data of node 1 : ";
        cin >> x;
        n = new Node<T>;
        n->data = x;
        n->next = tail1;
        n->prev = tail1->prev;
        tail1->prev = n;
        head1->next = n;
        for (int i = 2; i <= size; i++) {
            n = new Node<T>;
            if (n==nullptr) {
                cout << "\nUnable to allocate memory.";
                break;
            } else {
                cout << "Enter the data of node " << i << " : ";
                cin >> x;
                n->next = tail1;
                n->prev = tail1->prev;
                tail1->prev->next = n;
                tail1->prev = n;
                n->data = x;
            }
        }
        cout << "\nDoubly Linked List created successfully !!"<<endl;
    }
}

template<class T> void DoublyLinkedList<T>::search(T x){
    bool flag = false;
    int counter = 1;
    Node<T> *ptr = new Node<T>;

    ptr = head1->next;
    while (ptr != tail1){
        if (ptr->data == x) {
            cout << "Element is found at the position " << counter << endl;
            cout << "It's pointer is " << ptr->prev << endl;
            flag = true;
            break;
        }
        counter++;
        ptr = ptr->next;
    }
    if (flag == false) {
        cout << "Element is not found in the list :" << endl;
    }
}

template<class T> void DoublyLinkedList<T>::create1(int size){
    Node<T> *n, *ptr;
    T x;
    head2 = new Node<T>;
    if (head2==nullptr) {
        cout << "\nUnable to allocate memory.";
    }else{
        cout << "\nEnter the data of node 1 : ";
        cin >> x;
        n = new Node<T>;
        n->data = x;
        n->next = tail2;
        n->prev = tail2->prev;
        tail2->prev = n;
        head2->next = n;
        for (int i = 2; i <= size; i++) {
            n = new Node<T>;
            if (n==nullptr) {
                cout << "\nUnable to allocate memory.";
                break;
            } else {
                cout << "Enter the data of node " << i << " : ";
                cin >> x;
                n->next = tail2;
                n->prev = tail2->prev;
                tail2->prev->next = n;
                tail2->prev = n;
                n->data = x;
            }
        }
        cout << "\nDoubly Linked List created successfully !!"<<endl;
    }
}

template<class T> void DoublyLinkedList<T>::concate(){
    head2->prev=tail1;
    tail2->next=head1;
    Node<T> *ptr = new Node<T>;
    cout<<"The List is :- [ ";
    ptr = head1->next;
    while (ptr != tail2) {
        cout << ptr->data << ", ";
        ptr = ptr->next;
    }
    cout<<"]";
}

int main() {
    Node<int> *node;
    int elem, pos, choice, size, c;
    char ch;
    DoublyLinkedList<int> e;
    cout << "Enter no. of elements you wants to add in list 1 :- ";
    cin >> size;
    e.create(size);
    cout << "************************";
    cout << "\n\n1. add at the first ." << endl;
    cout << "2. add at the ith position . " << endl;
    cout << "3. add at the last ." << endl;
    cout << "4. To delete from first ." << endl;
    cout << "5. To delete at ith position ." << endl;
    cout << "6. To delete from last." << endl;
    cout << "7. To searchElement an element in the list :" << endl;
    cout << "8. To concatenate both list and print the elements." << endl;
    cout << "9. Display Doubly Linked List"<<endl;
    cout << "************************" << endl << endl;
    
    do {
        cout << "Enter Choice :- ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout<<"Enter new node to add in Begining :- ";
                cin>>elem;
                e.add(0,elem);
                e.display();
                break;
            case 2:
                cout << "Enter position at which new node is to be added :- ";
                cin >> pos;
                cout << "Enter element to be added: ";
                cin >> elem;
                e.add(pos,elem);
                e.display();
                break;
            case 3:
                cout << "Enter new node is to be added in Ending :- ";
                cin >> elem;
                c=e.length();
                e.add(c,elem);
                e.display();
                break;
            case 4:
                e.vipe(0);
                e.display();
                break;
            case 5:
                cout << "Enter position at which node is to be deleted :- ";
                cin >> pos;
                e.vipe(pos);
                e.display();
                break;
            case 6:
                e.vipe(e.length());
                e.display();
                break;
            case 7:
                cout << "Enter the element to search.";
                cin >> elem;
                e.search(elem);
                break;
            case 8:
                cout << "Enter no. of elements you wants to add in list 2 :- ";
                cin >> size;
                e.create1(size);
                e.concate();
                e.display();
                break;
            case 9:
                e.display();
                break;
            default:
                cout << "INVALID CHOICE ." << endl;
                break;
        }
        cout << "\nDo you want to repeat in the First List  ? Y or N " << endl;
        cin >> ch;
    } while (ch == 'y' || ch == 'Y');
}

/* bitch viped out */