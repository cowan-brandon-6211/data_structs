#include <iostream>

using std::cout;
using std::endl;

//global CONSTANT var
const int STORAGE_SIZE = 10;

//define prototypes of functions that we will use
void push(int new_value, int *storage_arr, int *top_index);
int pop(int *storage_arr, int *top_index);
int peek(int *storage_arr, int *top_index);
//helper functions, possible private in a class definition later...
bool is_empty(int top_index);
bool is_full(int top_index);


int main() {
    //array to store internal stack values
    int storage[STORAGE_SIZE] = {0};

    //track where the top is
    int index_of_top = -1; //safe default

    //test before operation, push 12
    cout << "storage[0]: " << storage[0] << endl;
    cout << "index_of_top: " << index_of_top << endl;
    cout << "is empty:  " << is_empty(index_of_top) << endl;
    cout << "is full:  " << is_full(index_of_top) << endl << "*****************" << endl;

    push(12, storage, &index_of_top);

    //check if opp succeeded
    cout << "storage[0]: " <<storage[0] << endl;
    cout << "index_of_top:  " << index_of_top << endl;
    cout << "is empty:  " << is_empty(index_of_top) << endl;
    cout << "is full:  " << is_full(index_of_top) << endl << "*****************" << endl;

    //test adding a bunch of values
    for(int i = 0; i < STORAGE_SIZE + 5; i++) {
        push(i, storage, &index_of_top);
    }

    //verify if test worked
    cout << "storage[0]: " <<storage[0] << endl;
    cout << "index_of_top:  " << index_of_top << endl;
    cout << "is empty:  " << is_empty(index_of_top) << endl;
    cout << "is full:  " << is_full(index_of_top) << endl << "*****************" << endl;

    cout << "storage[15]: " <<storage[15] << endl; //random junk
    cout << "storage[" <<STORAGE_SIZE -1 << "]:  " <<storage[STORAGE_SIZE -1] << endl << "*****************" << endl; //end of storage?

    //pop tests...
    int single_pop = pop(storage, &index_of_top);
    cout << "single_pop: " <<storage[0] << endl;
    cout << "index_of_top:  " << index_of_top << endl;
    cout << "is empty:  " << is_empty(index_of_top) << endl;
    cout << "is full:  " << is_full(index_of_top) << endl << "*****************" << endl;

    //multi pop
    //test popping a bunch of values...
    for(int i = 0; i < STORAGE_SIZE + 5; i++) {
        cout << "popping (" << i << "):  " << pop(storage, &index_of_top) << endl;
    }

    cout << "is empty:  " << is_empty(index_of_top) << endl;
    cout << "is full:  " << is_full(index_of_top) << endl << "*****************" << endl;

    //empty peek
    cout << "peak:  " << peek(storage, &index_of_top) << endl;

    //non-empty peek
    push(42, storage, &index_of_top);
    cout << "peak at non-empty stack:  " << peek(storage, &index_of_top) << endl;

    return 0;
}

//way of pushing into stack(push on full?)
//push onto next available position and update top appropriately...
void push(int new_value, int *storage_arr, int *top_index) {
    //check for full...
    if(!is_full(*top_index)) {
        //push and update top
        (*top_index)++;
        storage_arr[*top_index] = new_value;
    }
    //otherwise do nothing
}
//need a way to pop off stack(pop off empty?)
int pop(int *storage_arr, int *top_index) {
    int result = -1; //dummy value, could be valid though...

    //check for full...
    if(!is_empty(*top_index)) {
        //pop and update top
        result = storage_arr[*top_index];
        storage_arr[*top_index] = 0;
        (*top_index)--;
    }
    //otherwise do nothing
    return result; //returns -1 on empty stack...
}

//optionally have a way to peek at the top of the stack(peak at empty?)
int peek(int *storage_arr, int *top_index) {
    int result = -1; //dummy value, could be valid though...

    //check for full...
    if(!is_empty(*top_index)) {
        //peek and just return result
        result = storage_arr[*top_index];
    }
    //otherwise do nothing
    return result; //returns -1 on empty stack...


}
//optional helper function is empy? (check if top index is -1)

bool is_empty(int top_index) {
    return top_index == -1;
}

//optional helper function is full? (check if top index is STORAGE_SIZE -1) (careful of off by one errors!)

bool is_full(int top_index) {
    return top_index >= (STORAGE_SIZE - 1);
}