# ** READ ME **
This is a read me for Assignment 3.

Makefile was generated with CMake, as seen in CMakeLists.txt. The project structure is as follows:

---
##### Project structure
```
bin //contains executables
    ->alphabetize   //driver to test priority queue, alphabetizes string
build //contains Makefile and CMAKE stuff
    ->Makefile
    ->CMake generated files
include //for header files
    ->LinkedSortedList.h //specification for sorted list
    ->Node.h  //specification for node
    ->PrecondViolatedExcep.h //specification for exceptions
    ->PriorityQueueInterface.h  //specification for priority queue functions
    ->SL_PriorityQueue.h  //specification for the actual priority queue
    ->SortedListInteface.h  //specification for the sorted list functions
src //for .cpp files
    ->LinkedSortedList.cpp  //implementation of the sorted list
    ->Node.cpp //implementation of nodes
    ->PrecondViolatedExcep  //implementation of the exception
    ->SL_PriorityQueue.cpp  //implementation of the priority queue
test  //for the exercises
    ->main.cpp //driver for testing the priority queue
CMakeLists.txt  //for generating Makefile
README.md //this document
```
---
##### Running the program
To run an executable, `cd bin`, then `./alphabetize` to run the test of the priority queue.

---
##### Inputs for test program

The program is case sensitive. For instance, the name William will be sorted such that W is at the start, as capital letters are sorted first.

Only one string can be entered at a time. The presence of space will cause the program to stop reading input and will only sort the items before

---
