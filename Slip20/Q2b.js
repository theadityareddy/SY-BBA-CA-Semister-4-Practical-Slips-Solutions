//code not working
const http = require('http');
const courseStructure = {
  year: 'SY',
  course: 'BBA(CA)',
  subjects: [
    {
      name: 'Financial Accounting',
      code: 'FC',
      credits: 4,
    },
    {
      name: 'Cost Accounting',
      code: 'CC',
      credits: 4,
    },
    {
      name: 'Quantitative Techniques',
      code: 'QT',
      credits: 4,
    },
    {
      name: 'Computer Programming and Problem Solving',
      code: 'CPPS',
      credits: 4,
    },
    {
      name: 'Database Management Systems',
      code: 'DBMS',
      credits: 4,
    },
    {
      name: 'Web Technology and E-Commerce',
      code: 'WTEC',
      credits: 4,
    },
    {
      name: 'Business Communication',
      code: 'BC',
      credits: 2,
    },
    {
      name: 'Environmental Studies',
      code: 'ES',
      credits: 2,
    },
  ],
};

const server = http.createServer((req, res) => {
  if (req.url === '/courses/bbacasy') {
    res.writeHead(200, { 'Content-Type': 'application/json' });
    res.write(JSON.stringify(courseStructure));
    res.end();
  } else {
    res.writeHead(404, { 'Content-Type': 'text/html' });
    res.write('<h1>404 Page Not Found</h1>');
    res.end();
  }
});

server.listen(3000, () => {
  console.log('Server listening on port 3000');
});
