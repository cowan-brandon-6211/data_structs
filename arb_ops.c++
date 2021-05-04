#include <iostream>

using std::cout;
using std::endl;

int ARR_SIZE = 10;

class ArrBuilder {
    int *new_arr;
    int arr_cap;
    int front;
    int rear;
    int count;

    public:
    ArrBuilder(int size = ARR_SIZE);
    ~ArrBuilder();

    void enqueue(int new_item);
    void remove(int location);
    void add(int location, int new_item);
    void peek(int location);
    int size ();
    bool is_full();
    bool is_empty();
    void show_arr();
};

//initialize our array
ArrBuilder::ArrBuilder(int size) {
    new_arr = new int[size];
    arr_cap = size;
    front = 0;
    rear = -1;
    count = 0;
}

//Free memory allocated to array
ArrBuilder::~ArrBuilder() {
    delete[] new_arr;
}

//Add to the front to load our test array
void ArrBuilder::enqueue(int new_item) {
    if (is_full()) {
        cout << "Failure." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "Enqueuing: " << new_item << endl;
    rear = (rear + 1) % arr_cap;
    new_arr[rear] = new_item;
    count++;
}

//Code for inserting a value at a given position
void ArrBuilder::add(int location, int new_item) {
    cout << "Adding: " << new_item << " to location " << location << "." << endl;
    new_arr[location] = new_item;
    count++;
}


//Code for removing a value at a given postion
void ArrBuilder::remove(int location) {
    if (is_empty()) {
        cout << "Array is empty." << endl;
        return;
    }

    arr_cap = arr_cap;
    cout << "Removing: " << new_arr[location] << " from location " << location << "." << endl;
    for (int j = location; j < arr_cap; j++) {
        new_arr[j] = new_arr[j + 1] % arr_cap;
    }
    count--;
}


//Code for peeking at the value of a given postion
void ArrBuilder::peek(int location) {
    if (is_empty()) {
        cout << "Array is empty." << endl;
    }

    cout << "Item at location " << location << " is: " << new_arr[location] << "." << endl;
}

int ArrBuilder::size() {
    return count;
}

bool ArrBuilder::is_empty() {
    return (size() == 0);
}

bool ArrBuilder::is_full() {
    return (size() == arr_cap);
}

void ArrBuilder::show_arr() {
    if (is_empty()) {
        cout << "Array is empty." << endl;
    } else {
        cout << "Current array: " << endl;
        for (int i = front; i <= rear; i++) {
            cout << new_arr[i] << " ";
        }
        cout << endl;
    }
}

//Main for tests
int main() {
    ArrBuilder new_array(ARR_SIZE);

    //Check if array is initialized
    new_array.show_arr();
    cout << "*********************************************" << endl;

    //Fill the array
    for (int i = 0; i < ARR_SIZE; i++) {
        new_array.enqueue(i);
    }

    //Check if array is filled
    new_array.show_arr();
    cout << "*********************************************" << endl;

    //Add an item to the array at a specific location, then check to see if it worked
    new_array.add(0, 42);
    new_array.show_arr();
    cout << "*********************************************" << endl;

    //Peek at an item
    new_array.peek(4);
    cout << "*********************************************" << endl;

    //Try to remove an item
    new_array.remove(3);
    new_array.show_arr();
    cout << "*********************************************" << endl;

    return 0;
}