// This example shows how iterators work when paired with a container from the STL. 
// Brandon Vandergriff
// 8/13/24

// REMINDER: TO USE THE LIST CONTAINER YOU MUST #include<list>
#include<list>
#include<iostream>

using namespace std; 

int main() { 

    // create our list, passing in integer as our type template
    list<int> myList;

    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);
    myList.push_back(4);
    
    // our linked list is currently 
    // 1 -> 2 -> 3 -> 4 -> NULL 

    // create our iterator. we have to specify that it is an integer list iterator.
    // if we were creating an iterator for a list of doubles, it would be list<double>::iterator ... 
    list<int>::iterator it; 

    // set our iterator to the beginning of the list. 
    // this will store (essentially) a pointer to the first element, which holds 1. 
    it = myList.begin(); 

    // to output the value, we have to dereference it. 
    // this will output 1
    cout << "First element of the list " << endl; 
    cout << *it << endl; 

    // move our iterator down the list. 
    // each it++ is equivalent to nodePtr = nodePtr->next;
    cout << "Moving our iterator two spaces forward. " << endl; 
    it++;
    it++;

    // output will be 3 
    cout << *it << endl; 

    // this works like a doubly linked list, where we can go forwards and backwards.
    // equivalent to nodePtr = nodePtr->prev;
    cout << "Moving our iterator one space back. " << endl; 
    
    it--;

    // will output 2
    cout << *it << endl; 

    // Finally, list.end() will set the list to the NULL at the end.
    it = myList.end();

    // ***** THIS MAY OR MAY NOT SEGFAULT ***** 
    // IN MY TESTING, IT STILL OUTPUT THE CORRECT NUMBER, BUT IS STILL POINTING ONE STEP AHEAD OF THE END (I.E NULL)
    cout << *it << endl; 

    // Move the iterator from NULL to 4 
    cout << "Moving our iterator from end of list to 4." << endl;
    cout << *it << endl;
    it--; 

    // Move the iterator from 4 to 3 
    cout << "Moving our iterator from 4 to 3 " << endl; 
    it--; 
    cout << *it << endl;

    return 0;
}