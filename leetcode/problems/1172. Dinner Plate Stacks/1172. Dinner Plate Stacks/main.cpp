#include <bits/stdc++.h>
using namespace std;
// https://leetcode.cn/problems/dinner-plate-stacks/solution/yu-qi-wei-hu-di-yi-ge-wei-man-zhan-bu-ru-sphs/
class DinnerPlates {
    int capacity;
    vector<stack<int>> stacks; // 所有栈
    priority_queue<int, vector<int>, greater<>> idx; // 未满栈的下标
public:
    DinnerPlates(int capacity) : capacity(capacity) {

    }
    
    void push(int val) {
        if (!idx.empty() && idx.top() >= stacks.size())
            while (!idx.empty()) idx.pop();
        if (idx.empty()) { // 所有栈都是满的
            stack<int> st;
            st.push(val);
            stacks.emplace_back(st);
            if (capacity > 1)
                idx.push(stacks.size() - 1);
        } else { // 还有未满栈
            auto &st = stacks[idx.top()];
            st.push(val);
            if (st.size() == capacity) // 栈满了
                idx.pop();
        }
    }
    
    int pop() {
        return popAtStack(stacks.size() - 1);
    }
    
    int popAtStack(int index) {
        if (index < 0 || index >= stacks.size() || stacks[index].empty())
            return -1;
        auto &st = stacks[index];
        if (st.size() == capacity) // 满栈
            idx.push(index); // 元素出栈后，栈就不满了，把下标入堆
        int val = st.top();
        st.pop();
        while (!stacks.empty() && stacks.back().empty())
            stacks.pop_back(); // 去掉末尾的空栈（懒删除，堆中下标在 push 时处理）
        return val;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */

int main() {
    DinnerPlates *obj = new DinnerPlates(2);
    obj->push(1);
    obj->push(2);
    obj->push(3);
    obj->pop();
    obj->pop();
    obj->push(4);
}
