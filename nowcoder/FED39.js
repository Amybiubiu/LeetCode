function makeClosures(arr, fn) {
    return arr.map((value)=> fn.bind(null, value));
}