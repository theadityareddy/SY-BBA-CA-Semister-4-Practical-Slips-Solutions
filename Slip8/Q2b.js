//code not working
const express = require('express');
const app = express();
const port = 3000;

app.use(express.urlencoded({ extended: true }));
app.use(express.json());

app.post('/register', (req, res) => {
  const { firstName, lastName, age } = req.body;

  // Validate first and last name
  const nameRegex = /^[a-zA-Z]+$/;
  if (!nameRegex.test(firstName) || !nameRegex.test(lastName)) {
    return res.status(400).send('First and last name should not contain any special symbols or digits');
  }

  // Validate age
  const ageNum = parseInt(age);
  if (isNaN(ageNum) || ageNum < 6 || ageNum > 25) {
    return res.status(400).send('Age should be a number between 6 and 25');
  }

  // Store student details in database or do something else with the data
  res.send('Registration successful');
});

app.listen(port, () => {
  console.log(`Server listening on port ${port}`);
});
