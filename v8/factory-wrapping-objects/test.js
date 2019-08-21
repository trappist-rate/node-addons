// test.js
const addon = require('./build/Release/addon');

const obj = createObject(20);

console.log(obj.plusOne()); // Prints: 21
console.log(obj.plusOne()); // Prints: 22
console.log(obj.plusOne()); // Prints: 23

const obj = createObject(33);

console.log(obj.plusOne()); // Prints: 34
console.log(obj.plusOne()); // Prints: 35
console.log(obj.plusOne()); // Prints: 36

