const http = require('http');

// sample data for CS department courses
const courses = [
  { code: 'CS101', name: 'Introduction to Computer Science', credits: 3 },
  { code: 'CS201', name: 'Data Structures and Algorithms', credits: 4 },
  { code: 'CS301', name: 'Computer Networks', credits: 3 },
  { code: 'CS401', name: 'Artificial Intelligence', credits: 4 },
];

// create the server
const server = http.createServer((req, res) => {
  // handle requests for the home page
  if (req.url === '/' && req.method === 'GET') {
    // set response header
    res.writeHead(200, { 'Content-Type': 'text/html' });

    // send response
    res.write(`
      <html>
        <head>
          <title>CS Department Portal</title>
        </head>
        <body>
          <h1>Welcome to the CS Department Portal</h1>
          <p>Here you can view the list of available courses:</p>
          <ul>
    `);

    // iterate over courses and add them to the response
    courses.forEach((course) => {
      res.write(`<li>${course.code} - ${course.name} (${course.credits} credits)</li>`);
    });

    // complete the response and send it
    res.write(`
          </ul>
        </body>
      </html>
    `);
    res.end();
  }

  // handle requests for the about page
  else if (req.url === '/about' && req.method === 'GET') {
    // set response header
    res.writeHead(200, { 'Content-Type': 'text/html' });

    // send response
    res.write(`
      <html>
        <head>
          <title>About the CS Department</title>
        </head>
        <body>
          <h1>About the CS Department</h1>
          <p>We offer a range of courses covering various topics in computer science.</p>
          <p>Our department has world-class faculty and state-of-the-art facilities.</p>
        </body>
      </html>
    `);
    res.end();
  }

  // handle requests for other pages
  else {
    // set response header
    res.writeHead(404, { 'Content-Type': 'text/html' });

    // send response
    res.write(`
      <html>
        <head>
          <title>Page Not Found</title>
        </head>
        <body>
          <h1>Page Not Found</h1>
          <p>The page you requested could not be found.</p>
        </body>
      </html>
    `);
    res.end();
  }
});

// start the server
server.listen(3000, () => {
  console.log('Server running on port 3000');
});
