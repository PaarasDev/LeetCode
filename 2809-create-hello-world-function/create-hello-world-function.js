/**
 * @return {Function}
 */
var createHelloWorld = function() {
    let hello="Hello World";
    return function() {
        return hello;
    }
};

/**
 * const f = createHelloWorld();
 * f(); // "Hello World"
 */