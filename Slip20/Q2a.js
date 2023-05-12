const fs = require('fs');

const file = 'example.txt';

const readStream = fs.createReadStream(file);

readStream.on('open', () => {
  console.log(`Reading contents of ${file}...`);
});

readStream.on('data', (data) => {
  console.log(`Read chunk: ${data.toString()}`);
});

readStream.on('end', () => {
  console.log('File reading completed.');
});

readStream.on('error', (err) => {
  console.error(`Error occurred while reading ${file}: ${err}`);
});
