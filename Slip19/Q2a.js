const fs = require('fs');

// Display a message when the application starts up
console.log('Starting Node.js application...');

// Check if the file exists
fs.access('example.txt', fs.constants.F_OK, (err) => {
  if (err) {
    // If the file is not found, display an error message
    console.error('Error: example.txt not found.');
    return;
  }

  // If the file exists, display a warning
  console.warn('Warning: example.txt already exists.');
});

// Do other stuff here...
