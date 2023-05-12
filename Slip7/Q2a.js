const http = require('http');
const fs = require('fs');
const url = require('url');
const querystring = require('querystring');

const server = http.createServer(function(req, res) {
  const { pathname, query } = url.parse(req.url);
  
  if (req.method === 'GET' && pathname === '/') {
    res.writeHead(200, {'Content-Type': 'text/html'});
    res.write(`
      <form method="POST" action="/">
        <label for="file1">First file name:</label>
        <input type="text" name="file1" id="file1"><br>
        <label for="file2">Second file name:</label>
        <input type="text" name="file2" id="file2"><br>
        <button type="submit">Submit</button>
      </form>
    `);
    res.end();
  } else if (req.method === 'POST' && pathname === '/') {
    let body = '';
    req.on('data', chunk => {
      body += chunk.toString();
    });
    req.on('end', () => {
      const data = querystring.parse(body);
      const file1 = data.file1;
      const file2 = data.file2;
      
      fs.readFile(file1, 'utf8', (err, content1) => {
        if (err) {
          res.writeHead(400, {'Content-Type': 'text/plain'});
          res.write(`Error reading file ${file1}`);
          res.end();
          return;
        }
        fs.appendFile(file2, content1, err => {
          if (err) {
            res.writeHead(400, {'Content-Type': 'text/plain'});
            res.write(`Error writing to file ${file2}`);
            res.end();
            return;
          }
          res.writeHead(200, {'Content-Type': 'text/plain'});
          res.write(`Successfully appended contents of ${file1} to ${file2}`);
          res.end();
        });
      });
    });
  } else {
    res.writeHead(404, {'Content-Type': 'text/plain'});
    res.write('404 Not Found');
    res.end();
  }
});

server.listen(3000, () => {
  console.log('Server listening on http://localhost:3000');
});
