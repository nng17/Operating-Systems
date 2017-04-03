// Nathan Ng
// COEN 177L
// Wednesday 2:15
// Lab 3


#include <iostream>
#include <cctype>
#include <string>
#include <cstdlib>

using namespace std;

typedef struct node {
    int data;
    int flag;
} Node;

void tick();
int dequeue();
void enqueue(int);
bool findElement(int);

int first;
int count;
int size;
Node *buffer;


void tick() {
    ::first = (::first+1) % ::size;
}


bool findElement(int x) {
    // empty array
    if (::count == 0)
        return false;
    for (int i = 0; i < ::count; i++) {
        if (::buffer[(::first+i) % ::size].data == x)
            return true;
    }
    
    return false;
}

//add to buffer
void enqueue(int x) {
    
    ::buffer[(::first+::count) % ::size].data = x;
    ::buffer[(::first+::count) % ::size].flag = 0;
    ::count++;
}

// remove from buffer
int dequeue() {
    int d;
    
    if (::buffer[::first].flag == 1) {
        d = ::buffer[::first].data;
        tick();
        ::count--;
    }
    else {
        ::buffer[::first].flag = 1;
        tick();
        return dequeue();
    }
    
    return d;
}


int main (int argc, char *argv[]) {
    
    int num;
    int i = 0;
    int faults = 0;
    bool found;
    string input;
    string::iterator it;
    
    //intialize array
    ::size = atoi(argv[1]);
    first = ::count = 0;
    ::buffer = new Node[::size];

    
    while (getline(cin, input)) {
        
        tick(); //tick is used to move the clock hand
        
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
        found = findElement(num);
        
        // if not found
        if (!found) {
            if (::count == ::size)
                dequeue();
            
            // insert page into buffer
            enqueue(num);
            cout << num << "\n";
            faults++;
        }
        
        
    }

    cout << "reached the end of test\n";
    cout << "number of lines read: " << i << "\n";
    cout << "number of faults caused: " << faults << "\n";
    return 0;
}
