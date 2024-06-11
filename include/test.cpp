#include "OList.h"
#include <iostream>

template <typename T>
void print(OList<T> l) {
  for(int i = 0; i < l.length(); i++)
    std::cout<<" "<<l.get(i);
}

int main (int argc, char *argv[]) {
	OList<int> l;
  l.add(0);
  l.add(1);
  l.add(2);
  print(l);

  return 0;
}
