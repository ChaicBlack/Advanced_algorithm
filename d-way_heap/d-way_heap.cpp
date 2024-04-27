#include <string>
#include <utility>
#include <vector>
class DHeap {
  // D叉堆
  const static unsigned D = 2;
  // pairs.first->element, pairs->second->priority
  std::vector<std::pair<std::string, int>> pairs;

public:
  DHeap() = default;

  // index通常是假定比parent优先级大的children
  void bubbleup(std::vector<std::pair<std::string, int>> pairs, int index) {
    auto current = pairs[index];
    while (index > 0) {
      int parentIndex = (parentIndex - 1) / D; // 或者是任何获得其parent的实现方式
      if (pairs[parentIndex].second < current.second){
        pairs[index] = pairs[parentIndex];
        index = parentIndex;
      }
      else
        break;
    }
    pairs[index] = current;
  }

};
