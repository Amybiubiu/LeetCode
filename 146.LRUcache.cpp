class LRUCache {
    //我还是学了数据库再写吧 伤脑筋
public:
    LRUCache(int capacity) {
        //开辟capacity大小的内存空间
        hash_map<int,int> code;
        for(int i=0;i<capacity ;i++){
            code[i]=-1;
        }
    }
    
    int get(int key) {
        //按照key值搜索，查询
        if(code.find(key) != -1)
            return code.
    }
    
    void put(int key, int value) {
        //储存密钥
        //储存前查看空间剩余量，不足的话，删除最少使用的
        //关键是如何找到最少使用的？，设置一个new变量，每次操作后（put/get），更新new的对象。
        //看了题解后反应过来，如果是容量大于2的话，new是不够的，题解用了链表，储存使用顺序？
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */