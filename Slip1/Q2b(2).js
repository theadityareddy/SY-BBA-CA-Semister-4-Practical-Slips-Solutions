

var mysql = require('mysql');

var con = mysql.createConnection({

  host: "localhost",

  user: "root",

  password: "root",

  database: "studentdb"

});

con.connect(function(err) {

  if (err) throw err;

  console.log("Connected!");



  var sql = "CREATE TABLE student(rollno int,name VARCHAR(255), percentage double)";

  con.query(sql, function (err, result) {

    if (err) throw err;

    console.log("Table created");

  });


});