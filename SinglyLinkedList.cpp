#include <iostream>
using namespace std;

template<class T> class Node {
    public:
        T data;
        Node<T> *next;
};

template<class T> class SinglyLinkedList {
    Node<T> *head,*head1; 
    public:
        SinglyLinkedList() {
            head=nullptr,head1=nullptr;
        }

        ~SinglyLinkedList() {
            Node<T> *ptr = head;
            while(head){
                head = head->next;
                delete ptr;
                ptr = head;
            }
            Node<T> *ptr1 = head1;
            while(head1){
                head1 = head1->next;
                delete ptr1;
                ptr1 = head1;
            }
        }
    void create(int n);
    void create1(int n);
    void insert(int a, T x);
    void remove(int a);
    Node<T> *search(T);
    bool empty(Node<T> *ptr);
    int length();
    void concate();
    void display();
};

template<class T> int SinglyLinkedList<T>::length(){
    Node<T> *ptr = head;
    int len = 0;
    while (ptr != nullptr) {
        len++;
        ptr = ptr->next;
    }
    return len;
}

template<class T> bool SinglyLinkedList<T>::empty(Node<T> *ptr){
    if (ptr == nullptr) {
        return true;
    } else {
        return false;
    }
}

template<class T> void SinglyLinkedList<T>::insert(int pos,T x){
    Node<T> *temp = new Node<T> , *ptr = head;
    if (pos < 0 || pos > length()) {
        cout << "Error !! Invalid position !!" << endl;
    } else {
        if(pos==0){
            temp->data=x;
            temp->next = ptr;
            head=temp;
            cout << endl;
            cout << x << " has been added at beginning !! ";
        }else{
            for (int i = 1; i < pos - 1; i++) {
                ptr = ptr->next;
            }
            temp->data = x;
            temp->next = ptr->next;
            ptr->next = temp;
            cout << endl;
            cout << x << " has been added at position " << pos << " !!";}
    }
}

template<class T> void SinglyLinkedList<T>::remove(int pos){
    Node<T> *temp, *ptr = head;
    T x;
    if (pos < 0 || pos > length()) {
        cout << "Error !! Invalid position !!" << endl;
    } else {
        if(pos==0){
            x = ptr->data;
            head = head->next;
            delete ptr;
        cout << x << " has been deleted !!";
        }else{
            for (int i = 1; i < pos - 1; i++) {
                ptr = ptr->next;
            }
            x = (ptr->next)->data;
            temp = (ptr->next)->next;
            ptr->next = temp;
            cout << x << " has been deleted !! ";}
    }
}

template<class T> Node<T> *SinglyLinkedList<T>::search(T x) {
    Node<T> *ptr = head;
    new Node<T>;
    while (ptr != nullptr) {
        if (x == ptr->data) {
            return ptr;
        }
        ptr = ptr->next;
    }
    return nullptr;
}

template<class T> void SinglyLinkedList<T>::display() {
    Node<T> *ptr = head;
    if (empty(ptr)) {
        cout << " Empty !!";
    } else {
        while (ptr != nullptr) {
            cout << ptr->data << " ";
            ptr = ptr->next;
        }
    }
}

template<class T> void SinglyLinkedList<T>::create(int n) {
    Node<T> *newNode, *ptr;
    T x;
    head = new Node<T>;
    if (empty(head)) {
        cout << "\nUnable to allocate memory.";
    }else{
        cout << "\nEnter the data of node 1 : ";
        cin >> x;
        head->data = x;
        head->next = nullptr;
        ptr=head;
        for (int i = 2; i <= n; i++) {
            newNode = new Node<T>;
            if (empty(newNode)) {
                cout << "\nUnable to allocate memory.";
                break;
            } else {
                cout << "Enter the data of node " << i << " : ";
                cin >> x;
                newNode->data = x;
                newNode->next = nullptr;
                ptr->next = newNode;
                ptr = ptr->next;
            }
        }
        cout << "\nSingly Linked List created successfully !!";
    }
}

template<class T> void SinglyLinkedList<T>::create1(int n) {
    Node<T> *newNode, *ptr;
    T x;
    head1 = new Node<T>;
    if (empty(head1)) {
        cout << "\nUnable to allocate memory.";
    }else{
        cout << "\nEnter the data of node 1 : ";
        cin >> x;
        head1->data = x;
        head1->next = nullptr;
        ptr=head1;
        for (int i = 2; i <= n; i++) {
            newNode = new Node<T>;
            if (empty(newNode)) {
                cout << "\nUnable to allocate memory.";
                break;
            } else {
                cout << "Enter the data of node " << i << " : ";
                cin >> x;
                newNode->data = x;
                newNode->next = nullptr;
                ptr->next = newNode;
                ptr = ptr->next;
            }
        }
        cout << "\nSingly Linked List created successfully !!";
    }
}

template<class T> void SinglyLinkedList<T>::concate() {
    Node<T> *ptr = head;
    while (ptr->next != nullptr) {
        ptr = ptr->next;
    }
    ptr->next = head1;
}

int main() {
    Node<int> *node;
    int element, pos, choice, size;
    char ch, character;
    SinglyLinkedList<int> e;
    cout << "Enter no. of elements you wants to add in link 1 = ";
    cin >> size;
    e.create(size);
    do {
        cout << "\n-------Choose what action you want to perform------" << endl;
        cout << "\n1.Insert an element at the beginning." << endl;
        cout << "2.Insert an element at 'i'th position." << endl;
        cout << "3.Remove an element from the beginning." << endl;
        cout << "4.Remove an element from 'i'th position." << endl;
        cout << "5.Search for an element in the linked list." << endl;
        cout << "6.Concatenation of Two lists." << endl;
        cout << "7.Display."<<endl;
        cout << "8.Exit the program." << endl;
        cout << "\nChoice: ";
        cin >> choice;
        switch (choice) {
            case 1:{
                cout << "Enter element to be added: ";
                cin >> element;
                e.insert(0,element);
                cout << "\nList is : ";
                e.display();
                break;}
            
            case 2:{
                cout << "Enter position at which new node is to be added: ";
                cin >> pos;
                cout << "Enter element to be added: ";
                cin >> element;
                e.insert(pos, element);
                cout << "\nList is : ";
                e.display();
                break;}
            
            case 3:{
                e.remove(0);
                break;}

            case 4:{
                cout << "\nEnter position from which node is to be deleted: ";
                cin >> pos;
                e.remove(pos);
                break;}

            case 5:{
                cout << "\nEnter element to be Searched: ";
                cin >> element;
                node = e.search(element);
                if (node == nullptr) {
                    cout << "\nElement not found !!";
                } else {
                    cout << "\nElement found at address : " << node;
                }
                break;}

            case 6:{
                cout << "Enter no. of elements you wants to add in list 2: ";
                cin >> size;
                SinglyLinkedList<int> f;
                e.create1(size);
                e.concate();
                cout << "Concatenated list is : ";
                e.display();
                break;}

            case 7:{
                cout<<"Size of list is "<<e.length()<<" and List is";
                e.display();
                break;}
            
            case 8:{
                exit(0);}
            
            default:{
                cout << "\nWrong Choice!";
                break;}
        }
        cout << "\nDo You Want to Continue? Y/N... ";
        cin >> ch;
    } while (ch == 'Y' || ch == 'y');

    return 0;
}

/*End of this bitch*/