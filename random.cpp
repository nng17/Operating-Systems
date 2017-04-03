// Nathan Ng
// COEN 177 Lab
// Wendesday 2:15
// Lab 3

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include "deque.h"

using namespace std;

int main (int argc, char *argv[]) {
    
    int buffer_element;
    int data;
    int num;
    int i = 0;
    int faults = 0;
    int size = atoi(argv[1]);
    string input;
    string::iterator it;
    
    //uses Deque.cpp to create a buffer
    Deque buffer;
    
    srand(time(NULL));
    
    while (getline(cin, input)) {
        it = input.begin();
        if (!isdigit(*it)) {
            continue;
        }
        
        // clear everything after white space
        for (it = input.begin(); it != input.end(); it++) {
            if (isspace(*it)) {
                input.erase(it, input.end());
                break;
            }
        }
        
        // convert to number
        num = stoi(input);
        i++;
        
        // look for page in buffer
        buffer_element = buffer.findElement(num);
        
        // if empty list
        if (buffer_element == -1) {
            // check buffer to see if it is full or not
            if (buffer.size() == size) {
                data = rand()%buffer.size();
                buffer.removeElement(data);
            }
            buffer.addFirst(num, 0);
            cout << num << "\n";
            faults++;
        }


    }

    cout << "reached the eend of test.\n";
    cout << "number of lines read: " << i << "\n";
    cout << "number of faults caused: " << faults << "\n";
    
    return 0;
}