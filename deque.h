// Nathan Ng
// COEN 177 Lab
// Wednesday 2:15
// Lab 3

// Taken from COEN 70 HW files

# ifndef DEQUE_H
# define DEQUE_H

class Deque {
    int count;
    class Node *head;

public:
    Deque();
    ~Deque();
    int size();
    void addFirst(int x, int y);
    void addLast(int x, int y);
    int removeFirst();
    int removeLast();
    int getFirst();
    int getLast();
    // added feb. '16
    int findElement(int x);
    int removeElement(int x);
    int increase(int x);
    int findMin();
    int removeMin();
    int removeVisited();
};

# endif /* DEQUE_H */
