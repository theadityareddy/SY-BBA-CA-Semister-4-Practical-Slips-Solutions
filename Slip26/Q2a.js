const EventEmitter = require('events');

// Create a custom class that extends EventEmitter
class MyEmitter extends EventEmitter {}

// Create an instance of the custom class
const myEmitter = new MyEmitter();

// Bind a custom event with a callback function
myEmitter.on('customEvent', (arg) => {
  console.log(`Custom event occurred with argument: ${arg}`);
});

// Raise the custom event and pass an argument
myEmitter.emit('customEvent', 'Hello, world!');
