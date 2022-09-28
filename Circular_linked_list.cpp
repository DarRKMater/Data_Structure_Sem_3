#include <iostream>
using namespace std;

template<class T> class Node{
public:
    T data;
    Node *next;
};

template<class T> class CL{
public:
    Node<T> *cursor;
    CL<T>(){
        cursor = NULL;
    }
    bool empty(Node<T> *ptr);
    void add(int t);
    void remove(int t);
    void search();
    void display();
    void list(int n);
    void concate(Node<T>* l,Node<T>* e);
};

template<class T> void CL<T>::list(int t){
    Node<T> *n, *ptr;
    T x;
    cursor = new Node<T>;
    if (empty(cursor)) {
        cout << "\nUnable to allocate memory.";
    }else{
        cout << "\nEnter the data of node 1 : ";
        cin >> x;
        ptr = new Node<T>;
        ptr->data = x;
        ptr->next = ptr;
        cursor = ptr;
        for (int i = 2; i <= t; i++) {
            n = new Node<T>;
            if (empty(n)) {
                cout << "\nUnable to allocate memory.";
                break;
            } else {
                cout << "Enter the data of node " << i << " : ";
                cin >> x;
                n->data = x;
                n->next = cursor->next;
                cursor->next = n;
                cursor = n;
            }
        }
        cout << "\nCircular Linked List created successfully !!\n";
    }
}

template<class T> bool CL<T>::empty(Node<T> *ptr){
    if (ptr == NULL)
    {
        return true;
    }
    else
        return false;
}

template<class T> void CL<T>::display(){
    Node<T> *ptr = cursor;
    if (empty(ptr) == true)
        cout << "List is empty. " << endl;
    else{
        cout << "Elements in the list :- { ";
        Node<T> *n = new Node<T>;
        n = ptr->next;
        cout << n->data << ", ";
        while (n->next != ptr->next)
        {
            n = n->next;
            if(n->next==ptr->next)
                cout << n->data << " ";
            else
                cout << n->data << ", ";
        }
        cout<<"}";
    }
    cout << endl;
}

template<class T> void CL<T>::add(int t){
    Node<T> *ptr=new Node<T>,*temp=new Node<T>;
    T x,y;
    switch (t){
        case 1:
            cout<<"Enter the element to add in the begining :- ";
            cin>>x;
            ptr->data=x;
            ptr->next=cursor->next;
            cursor->next=ptr;
            display();
            break;
        case 2:
            cout<<"Enter the element to add in the end :- ";
            cin>>x;
            ptr->data=x;
            ptr->next=cursor->next;
            cursor->next=ptr;
            cursor=ptr;
            display();
            break;
        case 3:
            display();
            cout<<"after Element :- ";cin>>y;
            ptr=cursor->next;
            while(ptr->data!=y)
                ptr=ptr->next;
            if(ptr==cursor){
                add(2);
            }
            else{
                cout<<"Add Element :- "; cin>>x;
                temp->data=x;
                temp->next=ptr->next;
                ptr->next=temp;
                display();
            }
            break;
    }
}

template<class T> void CL<T>::remove(int t){
    Node<T> *ptr=new Node<T>,*temp=new Node<T>;
    T x,y;
    switch (t){
        case 1:
            ptr=cursor->next;
            cursor->next=ptr->next;
            cout<<ptr->data<<"is deleted from the begining \n";
            delete(ptr);
            display();
            break;
        case 2:
            ptr=cursor->next;
            while(ptr->next!=cursor)  ptr=ptr->next;
            temp=ptr->next;
            ptr->next=temp->next;
            cursor=ptr;
            cout<<temp->data<<" is deleted from the end \n";
            delete(temp);
            display();
            break;
        case 3:
            display();
            cout<<"Element to delete:- "; cin>>x;
            ptr=cursor;
            if(ptr->data==x){
                remove(2);
            }
            else if (ptr->next->data==x){
                remove(1);
            }
            else{
                while (ptr->next != cursor){
                    if (ptr->next->data == x){
                        temp = ptr->next;
                        ptr->next = temp->next;
                        cout<<temp->data<<" is deleted from the end \n";
                        delete(temp);
                        display();
                    }
                    ptr = ptr->next;
                }
            }
            break;
    }
}

template<class T> void CL<T>::search(){
    cout<<"Enter the Element to search :- ";
    T x; cin>>x;
    Node<T> *ptr=new Node<T>;
    int count=0;
    ptr=cursor;
    while(ptr->data!=x){
        if(ptr->next->data==x){
            cout<<"Element is found at place :- "<<count+1<<endl;
            display();
            break;
        }
        ptr=ptr->next;
        count++;
    }
}

template<class T> void CL<T>::concate(Node<T> *l,Node<T> *e){
    Node<T> *first_next = l->next;
    Node<T> *second_next = e->next;

    l->next = second_next;
    e->next = first_next;
}

int main(){
    int size,elem,pos,choice;
    CL<int> l;
    CL<int> e;
    cout << "Enter no. of elements you wants to add in link 1 : ";
    cin >> size;
    l.list(size);
    l.display();
    char r;
    do
    {
        cout << "--------------------------------------------------------" << endl;
        cout << "1: Insert an element X at the front. " << endl;
        cout << "2: Insert an element X at the back of the List. " << endl;
        cout << "3: Insert an element X after an element Y." << endl;
        cout << "4: Display the elements of the list." << endl;
        cout << "5: Remove an element from the front. " << endl;
        cout << "6: Remove an element from the back. " << endl;
        cout << "7 :Remove an element X. " << endl;
        cout << "8 :Search for an element X. " << endl;
        cout << "9 : To concatenate two circularly linked list. " << endl;
        cout << "--------------------------------------------------------" << endl;
        cin >> choice;
        switch (choice){
            case 1:
                l.add(1);
                break;
            case 2:
                l.add(2);
                break;
            case 3:
                l.add(3);
                break;
            case 4:
                l.display();
                break;
            case 5:
                l.remove(1);
                break;
            case 6:
                l.remove(2);
                break;
            case 7:
                l.remove(3);
                break;
            case 8:
                l.search();
                break;
            case 9:
                cout << "Enter no. of elements you wants to add in list 2 : ";
                cin >> size;
                e.list(size);
                e.display();
                e.concate(l.cursor->next,e.cursor->next);
                l.display();
                break;
            default:
                cout << "Invalid Choice . " << endl;
                break;
            }
            cout << "want to repeat ? Y / N ? " << endl;
            cin >> r;

        } while (r == 'y' || r == 'Y');
}
/* Paradox */
/* Paradox */
