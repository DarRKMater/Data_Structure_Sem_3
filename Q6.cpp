#include <iostream>
#include <exception>
using namespace std;

class StackEmpty : public exception // StackEmpty exception class
{
public:
    const char *exep() const throw() {
        return "Exception Caught :- Stack is empty . ";
    }
};

class StackFull : public exception // StackFull exception class
{
public:
    const char *exep() const throw() {
        return "Exception Caught :- Stack is full";
    }
};

template<class t>
class ArrayStack {
private:
    int T = -1;
    int n;
    t arr[10];
public:
    void input();

    // Get the size of the stack/ Array
    bool empty();

    // Check if stack is empty
    void display(); // Display the elements of the stack
    void pop(); // Pop the top element of the stack
    void push(); // Push an element on stack
    void top(); // Displays the top element of the stack
    int size();
    // Number of current items in the stack
};

template<class t>
void ArrayStack<t>::input() {
    cout << "Enter the size of the stack . " << endl;
    cin >> n;
}

template<class t>
bool ArrayStack<t>::empty() {
    if (T < 0) {
        return true;
    } else
        return false;
}

template<class t>
void ArrayStack<t>::pop() {
    if (empty()) {
        StackEmpty s;
        throw s;
    cout<<"Array is empty. "<<endl;
    } else {
        --T;
        cout << "POPPED " << endl;
    }
}

template<class t>
void ArrayStack<t>::push() {
    if (T == n - 1) {
        StackFull s;
        throw s;
    } else {
        cout << "Enter the element . " << endl;
        T = T + 1;
        cin >> arr[T];
    }
}

template<class t>
void ArrayStack<t>::top() {
    if (empty()) {
        StackEmpty s;
        throw s;
    } else {
        cout << arr[T] << " \n";
    }
}

template<class t>
void ArrayStack<t>::display() {
    if (empty()) {
        StackEmpty s;
        throw s;
    } else {
        cout << "Elements in the stack :- " << endl;
        for (int i = 0; i <= T; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

template<class t>
int ArrayStack<t>::size() {
    if (empty()) {
        StackEmpty s;
        throw s;
    } else
        return T + 1;
}

int main() {
        ArrayStack<int> A;
        A.input();
        char r='y';
        do {
            cout << "1: Push an element ." << endl;
            cout << "2: Pop . " << endl;
            cout << "3: Display. "<< endl;
            cout << "4: top element . "<< endl;
            cout << "5: Number of elements." << endl;
            int choice;
            cin >> choice;
            switch (choice) {
                case 1:
                    try {
                        A.push();
                    }
                    catch (StackFull e) {
                        cout << e.exep() << endl;
                    }
                    break;
                case 2:
                    try {
                        A.pop();
                    }
                    catch (StackEmpty e) {
                        cout << e.exep() << endl;
                    }
                    break;
                case 3:
                    try {
                        A.display();
                    }
                    catch (StackEmpty e) {
                        cout << e.exep();
                    }
                    break;
                case 4:
                    try {
                        A.top();
                    }
                    catch (StackEmpty e) {
                        cout << e.exep() << endl;
                    }
                    break;
                case 5:
                    try {
                        cout << "Number of current elements :- " << A.size() << " \n";
                    }
                    catch (StackEmpty s) {
                        cout << s.exep();
                    }
                    break;
                default:
                    cout << "Invalid Choice . " << endl;
                    break;
            }
            cout << "\nWant to repeat ? Y or N ? " <<
                 endl;
            cin >> r;
        } while (r == 'y' || r == 'Y');
}