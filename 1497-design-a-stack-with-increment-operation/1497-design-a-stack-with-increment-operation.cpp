class CustomStack {
public:
    queue<int> q;
    int mx;
    
public:
    CustomStack(int maxSize) {
        mx = maxSize;
    }
    
    void push(int x) {
        if (q.size() == mx) return;
        q.push(x);
    }
    
    int pop() {
        if (q.empty()) return -1;  // Return -1 if the stack is empty
        
        int n = q.size() - 1;
        queue<int> tmp_q;
        
        // Move all elements except the last one to a temporary queue
        for (int i = 0; i < n; i++) {
            tmp_q.push(q.front());
            q.pop();
        }
        
        // This is the element to be removed (top of the stack)
        int poppedElement = q.front();
        q.pop();
        
        // Restore the elements back into the original queue
        while (!tmp_q.empty()) {
            q.push(tmp_q.front());
            tmp_q.pop();
        }
        
        return poppedElement;  // Return the popped element
    }
    
    void increment(int k, int val) {
        int n = min(k, (int)q.size());  // Increment only the first k elements
        queue<int> tmp_q;
        
        // Increment the first k elements
        for (int i = 0; i < n; i++) {
            int incrementedValue = q.front() + val;
            tmp_q.push(incrementedValue);
            q.pop();
        }
        
        // Move the rest of the elements as they are
        while (!q.empty()) {
            tmp_q.push(q.front());
            q.pop();
        }
        
        // Restore the elements back into the original queue
        q = tmp_q;
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */