#include <iostream>

using std::cout;
using std::cin;
using std::endl;

const int STORAGE_SIZE = 10;

class queue {
    int *queue_array; //store elements of queue
    int queue_cap; //maximum queue capacity
    int front; //points to front element
    int rear; //points to rear element
    int count; //current size

    public:
    queue(int size = STORAGE_SIZE); //queue constructor
    ~queue(); //queue destructor

    //define functions linked to the class that will be used
    void dequeue();
    void enqueue(int new_item);
    int peek();
    int size();
    bool is_full();
    bool is_empty();
    void show_queue();
};

//initialize the queue
queue::queue(int size) {
    queue_array = new int[size];
    queue_cap = size;
    front = 0;
    rear = -1;
    count = 0;
}

//queue destructor to free memory allocated to the queue
queue::~queue() {
    delete[] queue_array;
}

//dequeue function, removing first element
void queue::dequeue() {
    //check for is_empty
    if (is_empty()) {
        cout << "Underflow failure." << endl;
        exit(EXIT_FAILURE);
    }
    
    cout << "dequeueing: " << queue_array[front] << endl;
    front = (front + 1) % queue_cap;
    count--;
}

//enqueue function, add to rear of queue
void queue::enqueue(int new_item) {
    //check for is_full
    if (is_full()) {
        cout << "Overflow failure." << endl;
        exit(EXIT_FAILURE);
    }

    cout << "enqueuing: " << new_item << endl;
    rear = (rear + 1) % queue_cap;
    queue_array[rear] = new_item;
    count++;
}

//look at and return the front of queue
int queue::peek() {
    if (is_empty()) {
        cout << "Queue is empty" << endl;
    }

    return queue_array[front];
}

//return size of the queue
int queue::size() {
    return count;
}

//check if queue is empty
bool queue::is_empty() {
    return (size() == 0);
}

//check if queue is full
bool queue::is_full() {
    return (size() == queue_cap);
}

//give option to easily show queue
void queue::show_queue() {
    if (is_empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Current Queue: " << endl;
        for (int i = front; i <= rear; i++) {
            cout << queue_array[i] << endl;
        }
    }
}

int main () {
    //initialize a new queue
    queue new_queue(10);

    //show current queue
    new_queue.show_queue();
    cout << "***********************" << endl;

    //adding single element
    new_queue.enqueue(1);

    //test to see if adding single element worked
    new_queue.show_queue();
    cout << "***********************" << endl;

    //add multiple elements
    for (int i = 0; i <= 5; i++) {
        new_queue.enqueue(i);
    }

    //test to see if adding multiple elements worked
    new_queue.show_queue();
    cout << "***********************" << endl;

    //peek at first element of queue
    cout << "Peek: " << new_queue.peek() << endl;
    cout << "***********************" << endl;

    //dequeue single
    new_queue.dequeue();

    //test to see if dequeue worked
    new_queue.show_queue();
    cout << "***********************" << endl;

    //dequeue multiple
    for (int i = 0; i <= 3; i++) {
        new_queue.dequeue();
    }

    //test to see if dequeue multiple worked
    new_queue.show_queue();

    return 0;
}