//code not working
const express = require('express');
const bodyParser = require('body-parser');
const app = express();
const PORT = 3000;

app.use(bodyParser.json());

// employee registration form
app.get('/register', (req, res) => {
  res.send(`
    <form method="POST" action="/register">
      <label>Name</label>
      <input type="text" name="name" required>
      <br><br>
      <label>Date of Birth (YYYY-MM-DD)</label>
      <input type="text" name="dob" required>
      <br><br>
      <label>Joining Date (YYYY-MM-DD)</label>
      <input type="text" name="joiningDate" required>
      <br><br>
      <label>Salary</label>
      <input type="number" name="salary" required>
      <br><br>
      <button type="submit">Submit</button>
    </form>
  `);
});

// employee registration form submission
app.post('/register', (req, res) => {
  const { name, dob, joiningDate, salary } = req.body;

  // validate date of birth
  const dobDate = new Date(dob);
  if (isNaN(dobDate.getTime())) {
    res.status(400).send('Invalid Date of Birth');
    return;
  }

  // validate joining date
  const joiningDateDate = new Date(joiningDate);
  if (isNaN(joiningDateDate.getTime())) {
    res.status(400).send('Invalid Joining Date');
    return;
  }

  // validate salary
  if (isNaN(salary) || salary <= 0) {
    res.status(400).send('Invalid Salary');
    return;
  }

  // employee registration successful
  res.send(`Employee registration successful! Name: ${name}, DOB: ${dob}, Joining Date: ${joiningDate}, Salary: ${salary}`);
});

app.listen(PORT, () => console.log(`Server running on port ${PORT}`));
