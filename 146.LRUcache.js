/**
 * @param {number} capacity
 */
var LRUCache = function(capacity) {
    this.cache = new Map();
    this.capacity = capacity;
};

/** 
 * @param {number} key
 * @return {number}
 */
LRUCache.prototype.get = function(key) {
    var cache = this.cache;
    if(cache.has(key)){
        var temp = cache.get(key);
         cache.delete(key);
        cache.set(key,temp);
        return temp;
    }else
        return -1;
};

/** 
 * @param {number} key 
 * @param {number} value
 * @return {void}
 */
LRUCache.prototype.put = function(key, value) {
    var cache = this.cache;
    if(cache.has(key)){
         cache.delete(key);
        
    }else if(cache.size >= this.capacity){
            cache.delete(cache.keys().next().value);
        }
        
    
    cache.set(key,value);  
};
