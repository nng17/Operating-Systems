// Nathan Ng
// COEN 177 Lab
// Wednesday 2:15
// Lab 3

#include <iostream>
#include <cstdlib>
#include <string>
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
    
    // uses Deque.cpp to create a buffer
    Deque buffer;
   
    while (getline(cin, input)) {
        
        // beginning of input line
        it = input.begin();
        if (!isdigit(*it)) {
            continue;
        }
        
        // find whitespace
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
            // check if buffer is full
            if (buffer.size() == size) {
                buffer.removeLast();
            }
            
            // insert page into buffer
            buffer.addFirst(num, 0);
            cout << num << "\n";
            faults++;
        }
        
        // if page in buffer
        else {
            // move to first
            data = buffer.removeElement(buffer_element);
            buffer.addFirst(data, 0);
        }
    }
    
    cout << "reached the end of test.\n";
    cout << "number of lines read: " << i << "\n";
    cout << "number of faults caused: " << faults << "\n";
    
    return 0;
}
