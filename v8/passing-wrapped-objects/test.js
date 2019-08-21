// test.js
const addon = require('./build/Release/addon');

const obj1 = addon.createObject(20);
const obj2 = addon.createObject(33);
const response = addon.add(obj1, obj2);

console.log(response);
// Prints: 53
