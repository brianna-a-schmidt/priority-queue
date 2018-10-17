#include "../src/Node.cpp"
#include "../src/LinkedSortedList.cpp"
#include "../src/SL_PriorityQueue.cpp"
#include <iostream>

int main()
{
std::shared_ptr<SL_PriorityQueue<int> > testing (new SL_PriorityQueue<int>());
testing->enqueue(7);
testing->enqueue(4);
std::cout << testing->peekFront() << std::endl;
std::cout << testing->dequeue() << std::endl;
std::cout << testing->isEmpty() << std::endl;
return 0;
}
