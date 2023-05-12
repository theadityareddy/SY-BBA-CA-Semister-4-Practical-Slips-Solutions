const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter the number of units consumed: ', (answer) => {
  const units = parseInt(answer);
  const baseCharge = 10;
  let totalCharge;

  if (units <= 50) {
    totalCharge = baseCharge + (units * 0.5);
  } else if (units <= 150) {
    totalCharge = baseCharge + (50 * 0.5) + ((units - 50) * 0.75);
  } else if (units <= 250) {
    totalCharge = baseCharge + (50 * 0.5) + (100 * 0.75) + ((units - 150) * 1.2);
  } else {
    totalCharge = baseCharge + (50 * 0.5) + (100 * 0.75) + (100 * 1.2) + ((units - 250) * 1.5);
  }

  console.log(`Your electricity bill for ${units} units is ${totalCharge.toFixed(2)} dollars.`);

  rl.close();
});
