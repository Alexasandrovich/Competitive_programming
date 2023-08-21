#include <vector>
#include <algorithm>
#include <optional>
#include <iostream>
#include <string>

using namespace std;
class Heap
{
public:
  void siftUp(size_t index)
  {
    while(heap[index] < heap[(index - 1) / 2])
    {
      swap(heap[index], heap[(index - 1) / 2]);
      index = (index - 1) / 2;
    }
  }

  bool hasValue()
  {
    return !heap.empty();
  }

  void siftDown(size_t index)
  {
    while(2 * index + 1 < heap.size())
    {
      int left = 2 * index + 1;
      int right = 2 * index + 2;
      int j = left;
      if(left < heap.size() - 1 && heap[right] < heap[left])
      {
        j = right;
      }
      if(heap[index] <= heap[j])
      {
        break;
      }
      swap(heap[index], heap[j]);
      index = j;
    }
  }

  void add(int value){
    heap.emplace_back(value);
    siftUp(heap.size() - 1);
  }

  optional<int> getMin()
  {
    optional<int> res;
    if(!heap.empty())
    {
      res = heap[0];
      swap(heap[0], heap[heap.size() - 1]);
      heap.pop_back();
      siftDown(0);
    }
    return res;
  }

  void clear()
  {
    heap.clear();
  }
private:
  std::vector<int> heap;
};

int main()
{
  Heap h;
  string command;
  while(cin >> command)
  {
    if(command == "ADD")
    {
      int val;
      cin >> val;
      h.add(val);
    }else if(command == "CLEAR")
    {
      h.clear();  
    }else if(command == "EXTRACT")
    {
      auto val = h.getMin();
      if(val.has_value())
      {
        cout << val.value() << endl;
      }else cout << "CANNOT" << endl;
    }
  }

  return 0;
}
