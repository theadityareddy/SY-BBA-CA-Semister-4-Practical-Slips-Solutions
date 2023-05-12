const fs = require('fs');

const filename = 'searchf.txt'; // the name of the file to search
const searchWord = 'a'; // the word to search for

// read the contents of the file
fs.readFile(filename, 'utf8', (err, data) => {
  if (err) {
    console.error(err);
    return;
  }
  
  // search for the word in the file
  const matches = data.match(new RegExp(searchWord, 'gi'));
  
  // display the results
  console.log(`Found ${matches.length} matches for "${searchWord}" in ${filename}:`);
  matches.forEach((match, index) => {
    console.log(`${index + 1}. ${match}`);
  });
});
