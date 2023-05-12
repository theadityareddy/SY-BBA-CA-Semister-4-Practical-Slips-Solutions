const readline = require('readline');

const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});

rl.question('Enter your name: ', (name) => {
  rl.question('Enter your date of birth (YYYY-MM-DD): ', (dob) => {
    // Validate date of birth (YYYY-MM-DD format)
    const dobRegex = /^\d{4}-\d{2}-\d{2}$/;
    if (!dobRegex.test(dob)) {
      console.log('Invalid date of birth!');
      rl.close();
      return;
    }

    rl.question('Enter your mobile number: ', (mobile) => {
      // Validate mobile number (10 digits)
      const mobileRegex = /^\d{10}$/;
      if (!mobileRegex.test(mobile)) {
        console.log('Invalid mobile number!');
        rl.close();
        return;
      }

      rl.question('Enter your email address: ', (email) => {
        // Validate email address
        const emailRegex = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;
        if (!emailRegex.test(email)) {
          console.log('Invalid email address!');
          rl.close();
          return;
        }

        // All inputs are valid, log the registration details
        console.log(`Registration successful!\nName: ${name}\nDate of birth: ${dob}\nMobile number: ${mobile}\nEmail address: ${email}`);
        rl.close();
      });
    });
  });
});
