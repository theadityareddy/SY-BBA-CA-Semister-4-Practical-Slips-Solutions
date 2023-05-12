const fs = require('fs');
const path = require('path');

const dirPath = './my-directory';
const fileNames = ['file1.txt', 'file2.txt', 'file3.txt'];

// Create directory if it doesn't exist
if (!fs.existsSync(dirPath)) {
  fs.mkdirSync(dirPath);
}

// Create files in directory
fileNames.forEach((fileName) => {
  const filePath = path.join(dirPath, fileName);
  fs.writeFileSync(filePath, `This is ${fileName}`);
});

console.log('Directory and files created successfully!');
