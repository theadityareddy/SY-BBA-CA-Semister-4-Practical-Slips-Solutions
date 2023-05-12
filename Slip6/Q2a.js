//run this code on local host as (on any web browser)->   localhost:3000/index.html
const http = require('http');
const fs = require('fs');

const server = http.createServer((req, res) => {
  // Get the file path from the request URL
  const filePath = '.' + req.url;

  // Try to read the file
  fs.readFile(filePath, (err, data) => {
    if (err) {
      // If there's an error, send a 404 response
      res.writeHead(404, {'Content-Type': 'text/html'});
      res.end('<h1>404 Not Found</h1>');
    } else {
      // If the file is found, send its content as the response
      res.writeHead(200, {'Content-Type': 'text/html'});
      res.end(data);
    }
  });
});

// Listen for incoming requests on port 3000
server.listen(3000, () => {
  console.log('Server is listening on port 3000');
});
