var TimeLimitedCache = function() {
    this.map = new Map(); // key -> { value, expire }
};

TimeLimitedCache.prototype.set = function(key, value, duration) {
    const now = Date.now();

    const existed =
        this.map.has(key) && this.map.get(key).expire > now;

    this.map.set(key, {
        value: value,
        expire: now + duration
    });

    return existed;
};

TimeLimitedCache.prototype.get = function(key) {
    const now = Date.now();

    if (!this.map.has(key)) return -1;

    const entry = this.map.get(key);
    if (entry.expire <= now) {
        this.map.delete(key);
        return -1;
    }

    return entry.value;
};

TimeLimitedCache.prototype.count = function() {
    const now = Date.now();
    let cnt = 0;

    for (const [key, entry] of this.map.entries()) {
        if (entry.expire <= now) {
            this.map.delete(key);
        } else {
            cnt++;
        }
    }

    return cnt;   // <-- MUST return explicitly
};

/**
 * const timeLimitedCache = new TimeLimitedCache()
 * timeLimitedCache.set(1, 42, 1000); // false
 * timeLimitedCache.get(1) // 42
 * timeLimitedCache.count() // 1
 */