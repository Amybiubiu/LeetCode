class MedianFinder {
private:
    // 大顶堆-小顶堆 是 顺序
    // 小顶堆-大顶堆 是 逆序
    // 都能正确的求出中位数
    priority_queue<int, vector<int>, greater<int> > maxHeap;
    priority_queue<int, vector<int>, less<int> > minHeap;
public:
    /** initialize your data structure here. */
    MedianFinder() {

    }
    
    void addNum(int num) {
        // 往A中插入元素时
        // 为保证绝对的逆序，不能直接push到A
        // 而要先push 到B，再把B的top push 到A
        if(maxHeap.size() == minHeap.size()){
            minHeap.push(num);
            int temp = minHeap.top();
            minHeap.pop();
            maxHeap.push(temp);
        }else{
            maxHeap.push(num);
            int temp = maxHeap.top();
            maxHeap.pop();
            minHeap.push(temp);
        }
    }
    
    double findMedian() {
        if(maxHeap.size() == minHeap.size()){
            return (maxHeap.top() + minHeap.top())/2.0;
        }else
            return maxHeap.top()*1.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */