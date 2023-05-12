//code is working but not running on localhost
const express = require('express');
const mongoose = require('mongoose');

// Create the voter schema
const voterSchema = new mongoose.Schema({
  name: { type: String, required: true },
  age: { type: Number, required: true },
  nationality: { type: String, required: true }
});

// Create the Voter model
const Voter = mongoose.model('Voter', voterSchema);

// Connect to the MongoDB database
mongoose.connect('mongodb://localhost/voters', { useNewUrlParser: true, useUnifiedTopology: true });

// Create the Express app
const app = express();

// Add middleware to parse incoming JSON data
app.use(express.json());

// Define the endpoint for adding a new voter
app.post('/voters', async (req, res) => {
  try {
    // Extract the voter details from the request body
    const { name, age, nationality } = req.body;

    // Validate the voter details
    if (!name.match(/^[A-Z ]+$/)) {
      return res.status(400).json({ message: 'Name should be in uppercase letters only' });
    }

    if (age < 18) {
      return res.status(400).json({ message: 'Age should not be less than 18 years' });
    }

    if (nationality !== 'Indian') {
      return res.status(400).json({ message: 'Nationality should be Indian' });
    }

    // Create a new voter object with the validated details
    const voter = new Voter({ name, age, nationality });

    // Save the voter object to the database
    await voter.save();

    // Return the saved voter object
    res.json(voter);
  } catch (error) {
    console.error(error);
    res.status(500).json({ message: 'Internal server error' });
  }
});

// Start the server
app.listen(3000, () => {
  console.log('Server started on port 3000');
});
