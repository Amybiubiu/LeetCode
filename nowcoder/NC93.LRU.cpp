#include <unordered_map>;
struct DLinkedNode{
    int key;
    int value;
    DLinkedNode* next;
    DLinkedNode* prev;
    DLinkedNode(int _key, int _value):key(_key), value(_value), next(nullptr), prev(nullptr){};
    DLinkedNode():key(0), value(0), next(nullptr), prev(nullptr){};
};
class Solution {
public:
    /**
     * lru design
     * @param operators int整型vector<vector<>> the ops
     * @param k int整型 the k
     * @return int整型vector
     */
    unordered_map<int, DLinkedNode*> cache;
    vector<int> res;
    DLinkedNode* head;
    DLinkedNode* tail;
    int size;
    int capacity;
    void set(int key, int value){
        if(cache.count(key)){
            // key 存在!! 修改value 而不是新建！！！
            DLinkedNode* node =  cache[key];
            node->value = value;
            removeToHead(node);
        }else{
            // key 值不存在
            // ！！先加进去再看需不需要减
            DLinkedNode* node = new DLinkedNode(key, value);
            cache[key] = node;
            size++;
            addToHead(node);
            if(size > capacity){
                DLinkedNode* node = moveTail();
                cache.erase(node->key);
                delete node;
                size--;
            }
        }
    }
    void get(int key){
        if(cache.count(key)){
            res.push_back(cache[key]->value);
            removeToHead(cache[key]);
        }else
            res.push_back(-1);
    }
    vector<int> LRU(vector<vector<int> >& operators, int k) {
        // write code here
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->next = head;
        capacity = k;
        size = 0;
        cache = unordered_map<int, DLinkedNode*>(k);
        for(auto operate : operators){
            if(operate[0] == 1){
                set(operate[1], operate[2]);
            }else{
                get(operate[1]);
            }
        }
        return res;
    }
    void removeToHead(DLinkedNode* node){
        // move
        node->prev->next = node->next;
        node->next->prev = node->prev;
        // remove
        addToHead(node);
    }
    void addToHead(DLinkedNode* node){
        node->next = head->next;
        head->next->prev = node;
        node->prev = head;
        head->next = node;
    }
    DLinkedNode* moveTail(){
        DLinkedNode* node = tail->prev;
        node->prev->next = tail;
        tail->prev = node->prev;
        return node;
    }
};
