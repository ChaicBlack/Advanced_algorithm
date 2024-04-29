#include <stdexcept>
#include <string>
#include <utility>
#include <vector>

class DHeap {
  // D叉堆
  static const unsigned D = 2;                    // 使D为静态常量
  std::vector<std::pair<std::string, int>> pairs; // 存储元素和它们的优先级

  // 返回最高优先级子节点的索引
  int highestPriorityChild(const int index) {
    int firstChildIdx = D * index + 1;
    if (firstChildIdx >= pairs.size())
      return -1; // 没有子节点时返回 -1

    int res = firstChildIdx;
    int priority = pairs[firstChildIdx].second;
    for (int i = firstChildIdx + 1; i < D * index + D && i < pairs.size();
         i++) {
      if (pairs[i].second > priority) {
        priority = pairs[i].second;
        res = i;
      }
    }
    return res;
  }

public:
  DHeap() = default;

  // 从给定索引处向上调整堆
  void bubbleUp(int index) {
    auto current = pairs[index];
    while (index > 0) {
      int parentIdx = (index - 1) / D;
      if (pairs[parentIdx].second < current.second) {
        pairs[index] = pairs[parentIdx];
        index = parentIdx;
      } else {
        break;
      }
    }
    pairs[index] = current;
  }

  // 从给定索引处向下调整堆
  void pushDown(int index = 0) {
    auto current = pairs[index];
    int currentIdx = index;
    while (currentIdx < (pairs.size() - 2) / D + 1) {
      int childIdx = highestPriorityChild(currentIdx);
      if (childIdx == -1)
        break;
      if (pairs[childIdx].second > current.second) {
        pairs[currentIdx] = pairs[childIdx];
        currentIdx = childIdx;
      } else {
        break;
      }
    }
    pairs[currentIdx] = current;
  }

  void insert(std::string element, int priority) {
    auto p = std::make_pair(element, priority);
    this->pairs.emplace_back(p);
    bubbleUp(pairs.size() - 1);
  }

  std::string top() {
    if (this->pairs.empty())
      throw std::runtime_error("Heap is empty");
    std::string old = this->pairs.front().first;
    this->pairs[0] = this->pairs.back();
    this->pairs.pop_back();
    if (!this->pairs.empty())
      this->pushDown();
    return old;
  }
};
