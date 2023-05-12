const mysql = require("mysql");

const express = require("express");

const bodyParser = require("body-parser");

const encoder = bodyParser.urlencoded();

const app = express();

const con = mysql.createConnection({

    host: "localhost",

    user: "root",

    password: "root",

    database: "studentdb"

});

con.connect(function(error){

    if (error) throw error

    else console.log("connected")

});

app.get("/",function(req,res){

    res.sendFile(__dirname + "/index.html");

})

app.post("/",encoder, function(req,res){

    var username = req.body.username;

    var password = req.body.password;

    con.query("select * from loginuser where user_name = ? and user_pass = ?",[username,password],function(error,results,fields){

        if (results.length > 0) {

            res.redirect("/loggedine");

        } else {

            res.redirect("/");

        }

        res.end();

    })

})

app.get("/loggedine",function(req,res){

    res.sendFile(__dirname + "/loggedine.html")

})

app.listen(8080);

