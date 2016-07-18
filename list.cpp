//constructing list
#include <iostream>
#include <list>
#include <algorithm> //std::find

int main ()
{
  //using the connstructors in order 
  //iterating through the lists
  std::list<int> first;                                // empty list of ints
  std::list<int> second (4,100);                       // (4,50) 4, four ints with value 50
  std::list<int> third (second.begin(),second.end());  // iterating through second
  std::list<int> fourth (third);                       // fourth int is a copy of third

  // the iterator constructors:
  int myints[] = {16,20,40,19};
  int *it;// declaring algorithm
  std::list<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

  std::cout << "The contents of fifth are: ";
  for (std::list<int>::iterator it = fifth.begin(); it != fifth.end(); it++)
    std::cout << *it << ' ';

  std::cout << '\n';
  
  //using algorithm find
  
  it = std::find (myints, myints+6, 20);
  if (it != myints+6)
    std::cout << "Element found in myints: " << *it << '\n';
  else
    std::cout << "Element not found in myints\n";

  return 0;
}