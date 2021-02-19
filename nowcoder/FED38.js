function functionFunction(str) {
    return function(...arr){
        return str+', '+ arr.join();
    }
}