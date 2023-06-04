let assert = require("assert");

const sensorReading = 65000;

const storedValue = sensorReading + 1;

assert(storedValue == sensorReading);
