const EventEmitter = require('events');

class MyEmitter extends EventEmitter {}

const myEmitter = new MyEmitter();

// Bind two listeners to the 'greet' event
myEmitter.on('greet', () => {
  console.log('Hello from listener 1!');
});

myEmitter.on('greet', () => {
  console.log('Hello from listener 2!');
});

// Emit the 'greet' event
myEmitter.emit('greet');
