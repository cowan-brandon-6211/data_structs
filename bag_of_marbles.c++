#include <iostream>
using namespace std;

int red = 1;
int green = 2;
int blue = 3;
int marbles_bag = 1;

long long int bag[3] = {0,0,0};

int main_input;
long long int num_input;

int main() {
    cout << "Here is your bag of marbles.\n";
    while (marbles_bag = 1){
        cout << "Your bag of marbles contains "<<bag[0]<<" red, "<<bag[1]<< " green, "<<bag[2]<< " blue.\n";
        cout << "Enter a command from the following list.\n";
        cout << "[1] to add Red marbles.\n";
        cout << "[2] to add Green marbles.\n";
        cout << "[3] to add Blue marbles.\n";
        cout << "[4] to remove Red marbles.\n";
        cout << "[5] to remove Green marbles.\n";
        cout << "[6] to remove Blue marbles.\n";
        cout << "[7] put your bag of marbles away.\n";
        cin >> main_input;

        if (main_input >= 1 && main_input <= 7){
            if (main_input == 1) {
                cout << "How many Red marbles would you like to add:  \n";
                cin >> num_input;
                bag[0] = bag[0] + num_input;
            } 
            else if (main_input == 2) {
                cout << "How many Green marbles would you like to add:  \n";
                cin >> num_input;
                bag[1] = bag[1] + num_input;
            } 
            else if (main_input == 3) {
                cout << "How many Blue marbles would you like to add:  \n";
                cin >> num_input;
                bag[2] = bag[2] + num_input;
            } 
            else if (main_input == 4) {
                cout << "How many Red marbles would you like to remove:  \n";
                cin >> num_input;
                bag[3] = bag[3] - num_input;
            } 
            else if (main_input == 5) {
                cout << "How many Red marbles would you like to remove:  \n";
                cin >> num_input;
                bag[4] = bag[4] - num_input;
            } 
            else if (main_input == 6) {
                cout << "How many Red marbles would you like to remove:  \n";
                cin >> num_input;
                bag[5] = bag[5] - num_input;
            } 
            else {
                cout << "Your bag of marbles contains "<<bag[0]<<" red, "<<bag[1]<< " green, "<<bag[2]<< " blue.\n";
                break;
                };
        } else {
            cout << "Please enter an integer between 1 and 7:  \n";
            cin >> main_input;
        };
    }
}

