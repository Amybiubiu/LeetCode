function functions(flag) {
    if (flag) {
      var getValue = function () { return 'a'; }
    } else {
      var getValue = function () { return 'b'; }
    }

    return getValue();
}