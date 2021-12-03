class MyQueue {
private:
    stack<int> istack1;
    stack<int> istack2;
public:
    MyQueue() {

    }
    
    void push(int x) {
        // copy all elements from istack2 to istack1
        while (!istack2.empty()) {
            auto ele = istack2.top();
            istack2.pop();
            istack1.push(ele);
        }
        istack1.push(x); // push new element to istack1

        // copy all elements from istack1 to istack2
        while (!istack1.empty()) {
            auto ele = istack1.top();
            istack1.pop();
            istack2.push(ele);
        }
    }
    
    int pop() {
        auto ele = istack2.top();
        istack2.pop();

        return ele;

    }
    
    int peek() {
        return istack2.top();
    }
    
    bool empty() {
        return istack2.empty();
    }
};
