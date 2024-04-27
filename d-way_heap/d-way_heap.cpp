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
  void bubbleUp(std::vector<std::pair<std::string, int>> pairs, int index) {
    auto current = pairs[index];
    while (index > 0) {
      int parentIdx =
          (parentIdx - 1) / D; // 或者是任何获得其parent的实现方式
      if (pairs[parentIdx].second < current.second) {
        pairs[index] = pairs[parentIdx];
        index = parentIdx;
      } else
        break;
    }
    pairs[index] = current;
  }

  void pushDown(std::vector<std::pair<std::string, int>> pairs, int index = 0){
    auto current = pairs[index];
    auto currentIdx = index;
    while(currentIdx < (pairs.size() - 2) / D + 1){ // (|pairs|-2)/D+1是第一个叶子的序号
      auto [child, childIdx] = highestPriorityChild(currentIdx);
      if(child.second > current.second){
        pairs[currentIdx] = child;
        currentIdx = childIdx;
      } else
        break;
    }
    pairs[currentIdx] = current;
  }
};
