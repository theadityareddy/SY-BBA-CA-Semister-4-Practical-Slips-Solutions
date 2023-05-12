const EventEmitter = require('events');

function createEmitter() {
  const emitter = new EventEmitter();

  emitter.on('greeting', (name) => {
    console.log(`Hello, ${name}!`);
  });

  return emitter;
}

const myEmitter = createEmitter();

myEmitter.emit('greeting', 'John');
