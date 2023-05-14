const assert = require('assert');

describe("Set of Tests", () => {
    describe("One test", () => {
        const s = "Hello Mocha";
        const parts = s.split(" ");
        it("should have two elements", () => {
            assert.equal(parts.length, 2)
        });
        it("should have three elements", () => {
            assert.equal(parts.length, 3)
        });

    })
})