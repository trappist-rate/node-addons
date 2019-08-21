// test.js
const addon = require('./build/Release/addon');

const obj = new addon.MyObject(20);

console.log(obj.plusOne()); // Prints: 21
console.log(obj.plusOne()); // Prints: 22
console.log(obj.plusOne()); // Prints: 23
