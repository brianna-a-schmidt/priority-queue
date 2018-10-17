#include "../src/Node.cpp"
#include "../src/LinkedSortedList.cpp"
#include "../src/SL_PriorityQueue.cpp"
#include <iostream>
#include <string>

int main()
{
std::string ioString;
std::shared_ptr<SL_PriorityQueue<char> > stringQueue (new SL_PriorityQueue<char>());
std::cout << "Input a string you want alphabetized:" << std::endl;
std::cin >> ioString;
for(int i = 0; i < ioString.length(); i++)
{
  stringQueue->enqueue(ioString.at(i));
}
for(int i = 0; i < ioString.length(); i++)
{
  ioString.at(i) = stringQueue->peekFront();
  stringQueue->dequeue();
}
std::cout << "The sorted string is: " << ioString << std::endl;
return 0;
}
