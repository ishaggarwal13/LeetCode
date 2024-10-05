class MyCalendar {
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        for (auto it : m_vEvents) {
            int intersectStart = max(it.first, start);
            int intersectEnd = min(it.second, end);
            if (intersectStart < intersectEnd)
                return false;
        }
        m_vEvents.push_back({start, end});
        return true;
    }
private:
    vector<pair<int, int>> m_vEvents;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */