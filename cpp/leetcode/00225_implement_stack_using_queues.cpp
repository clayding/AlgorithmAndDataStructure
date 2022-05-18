// 自己做的  感觉很差
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }

    void push(int x) {
        q1.push(x);
    }

    int pop() {
        int x = 0;
        while(!q1.empty()) {
            x = q1.front();
            q1.pop();

            if (q1.empty())
                break;
            q2.push(x);
        }

        while(!q2.empty()) {
            int y = q2.front();
            q2.pop();
            q1.push(y);
        }

        return x;
    }
    
    int top() {
        int x = 0;
        while(!q1.empty()) {
            x = q1.front();
            q1.pop();
            q2.push(x);
            if (q1.empty()) {
                break;
            }
        }

        while(!q2.empty()) {
            int y = q2.front();
            q2.pop();
            q1.push(y);
        }

        return x;

    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */

// 根据官方的解法优化的
class MyStack {
    queue<int> q1;
    queue<int> q2;
public:
    MyStack() {

    }
    
    void push(int x) {
        q2.push(x);

        while(!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }

        swap(q1, q2);
    }
    
    int pop() {
        int x = q1.front();
        q1.pop();

        return x;
    }
    
    int top() {
        return q1.front();
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */


// 用一个queue
