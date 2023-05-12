const EventEmitter = require('events');

// create a new event emitter
const eventEmitter = new EventEmitter();

// define the data_receive_handler function
const data_receive_handler = (data) => {
  console.log(`Received data: ${data}`);
};

// bind the custom event 'receive_data' with the 'data_receive_handler' function
eventEmitter.on('receive_data', data_receive_handler);

// emit the 'receive_data' event with some sample data
eventEmitter.emit('receive_data', 'Hello World!');
