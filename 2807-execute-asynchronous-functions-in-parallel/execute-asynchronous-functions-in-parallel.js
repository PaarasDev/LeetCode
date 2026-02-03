/**
 * @param {Array<Function>} functions
 * @return {Promise<any>}
 */
var promiseAll = function(functions) {
    return new Promise((resolve, reject) => {
        const n = functions.length;
        const results = new Array(n);
        let completed = 0;
        let rejected = false;

        for (let i = 0; i < n; i++) {
            functions[i]()
                .then((value) => {
                    if (rejected) return;
                    results[i] = value;
                    completed++;
                    if (completed === n) {
                        resolve(results);
                    }
                })
                .catch((err) => {
                    if (rejected) return;
                    rejected = true;
                    reject(err);
                });
        }
    });
};


/**
 * const promise = promiseAll([() => new Promise(res => res(42))])
 * promise.then(console.log); // [42]
 */