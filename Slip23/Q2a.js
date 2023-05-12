const fs = require('fs');
const replace = require('replace-in-file');

const filePath = 'E:/MSC/SEM 4/SLIPS/Slip23/abc.txt';
const searchWord = 'hello';
const replaceWord = 'world';

// Read the file
fs.readFile(filePath, 'utf8', function(err, data) {
  if (err) throw err;

  // Replace the word and bold it
  const boldReplace = `<strong>${replaceWord}</strong>`;
  const result = data.replace(new RegExp(searchWord, 'g'), boldReplace);

  // Write the updated text back to the file
  fs.writeFile(filePath, result, 'utf8', function(err) {
    if (err) throw err;
    console.log(`The word "${searchWord}" has been replaced with "${replaceWord}" and bolded in the file.`);
  });

  // Also replace the word in file paths
  const options = {
    files: [filePath],
    from: new RegExp(searchWord, 'g'),
    to: boldReplace,
  };
  replace(options)
    .then(results => {
      console.log(`Found and replaced ${results.length} instances of "${searchWord}" in the file paths.`);
    })
    .catch(err => {
      console.error(`Error occurred while replacing instances of "${searchWord}" in the file paths:`, err);
    });
});
