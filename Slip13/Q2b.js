var mysql = require('mysql');

var con = mysql.createConnection({

host: "localhost",

user: "root",

password: "root",

database: "studentdb"

});

con.connect(function(err) {

if (err) throw err;

var sql = "UPDATE student SET percentage = 90 WHERE rollno = 1";

con.query(sql, function (err, result,display) {

if (err) throw err;

console.log(result.affectedRows + " record updated");

});

con.query("SELECT *, name FROM student", function (err, result, fields) {

if (err) throw err;

console.log(result);

});

});