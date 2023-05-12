const http = require('http');

const server = http.createServer((req, res) => {
  if (req.url === '/') {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write('<h1>College Information</h1>');
    res.write('<p>Welcome to our college! We offer a variety of courses and programs to help you achieve your goals.</p>');
    res.end();
  } else {
    res.writeHead(404, {'Content-Type': 'text/html'});
    res.write('<h1>404 Page Not Found</h1>');
    res.end();
  }
});

server.listen(3000, () => {
  console.log('Server listening on port 3000');
});
