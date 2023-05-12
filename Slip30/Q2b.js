const mysql = require('mysql');

// Create a connection to the MySQL server
const connection = mysql.createConnection({
  host: 'localhost',
  user: 'root',
  password: 'root', // Replace with your own MySQL password
});

// Connect to the MySQL server
connection.connect((err) => {
  if (err) {
    console.error('Error connecting to the MySQL server:', err);
    return;
  }

  console.log('Connected to the MySQL server.');

  // Create the database
  connection.query('CREATE DATABASE IF NOT EXISTS hospital', (err, results) => {
    if (err) {
      console.error('Error creating the database:', err);
      return;
    }

    console.log('Database created successfully.');

    // Select the database
    connection.query('USE hospital', (err, results) => {
      if (err) {
        console.error('Error selecting the database:', err);
        return;
      }

      console.log('Database selected successfully.');

      // Create the Hospital table
      connection.query(
        `CREATE TABLE IF NOT EXISTS Hospital (
          hReg INT NOT NULL PRIMARY KEY,
          hName VARCHAR(255) NOT NULL,
          address VARCHAR(255) NOT NULL,
          contact VARCHAR(255) NOT NULL
        )`,
        (err, results) => {
          if (err) {
            console.error('Error creating the Hospital table:', err);
            return;
          }

          console.log('Hospital table created successfully.');
          connection.end(); // Close the connection
        }
      );
    });
  });
});
