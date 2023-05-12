const readline = require('readline');
const fs = require('fs');

// Create a readline interface to read user input
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

// Ask the user for the two file names
rl.question('Enter the first file name: ', (file1) => {
  rl.question('Enter the second file name: ', (file2) => {

    // Read the contents of the two files
    const content1 = fs.readFileSync(file1, 'utf8');
    const content2 = fs.readFileSync(file2, 'utf8');

    // Combine the contents in upper case
    const combinedContent = `${content1.toUpperCase()}${content2.toUpperCase()}`;

    // Write the result to a third file
    fs.writeFileSync('combined.txt', combinedContent);

    // Notify the user
    console.log(`The combined content has been written to combined.txt`);

    // Close the readline interface
    rl.close();
  });
});
