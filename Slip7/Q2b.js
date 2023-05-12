var mysql = require('mysql');



var con = mysql.createConnection({

  host: "localhost",

  user: "root",

  password: "root",

  database: "sybbaca"

});


con.connect(function(err) {

  if (err) throw err;

  console.log("Connected!");

/* for creating Database and tables


//database creation

//   con.query("CREATE DATABASE customer_DB", function (err, result) {

//     if (err) throw err;

//     console.log("Database created");

//   });

             //table create

// var table = "CREATE TABLE customer (cid int,name VARCHAR(255), city VARCHAR(255))";

//   con.query(table, function (err, result) {

//     if (err) throw err;

//     console.log("Table created");

//   });


    //data insert

var data1 = "INSERT INTO customer (cid, name, city) VALUES (1,’Shamal', 'Pune')";

var data2 = "INSERT INTO customer (cid, name, city) VALUES (2,'Rutuja', 'Mumbai')";

var data3 = "INSERT INTO customer2 (cid, name, city) VALUES (3,'Seema', 'Nagpur')";


con.query(data1, function (err, result) {

  if (err) throw err;

  console.log( "no. 1 record inserted");

});

con.query(data2, function (err, result) {

  if (err) throw err;

  console.log( "no. 2 record inserted");

});

con.query(data3, function (err, result) {

  if (err) throw err;

  console.log( "no. 3 record inserted");

});

*/

con.query("SELECT * FROM  student", function (err, result, fields) {

    if (err) throw err;

    console.log(result);

  });


});
