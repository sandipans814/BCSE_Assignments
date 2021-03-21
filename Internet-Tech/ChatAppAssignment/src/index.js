import express from "express";
const app = express(); // getting an Express app
const server = require("http").Server(app); // creating the server, will be used in socket.io
import path from "path"; // used in handling image upload
const { v4: uuid4 } = require("uuid"); // get a random uuid4, v4 is imported as uuid4
import fs from "fs";

app.set("views", path.join(__dirname, "/views")); // views shall be served from views/ dir
app.set("view engine", "ejs"); // ejs is the view engine
app.use(express.static("public")); // static will be served from public/
app.use(express.json());
app.use(
    express.urlencoded({
        extended: true,
    })
);

app.use(
    require("express-fileupload")({ // middleware handling file upload
        createParentPath: true,
    })
);

var db = {};
var socketDb = {};
var msgDb = {};

import sockets from "./sockets";
sockets.init(server, db, socketDb);

app.get("/", (req, res) => {
    res.redirect("login");
});

app.get("/login", (req, res) => {
    res.render("login");
});

app.post("/room", (req, res) => {
    res.render("room", {
        username: req.body.username,
        name: req.body.firstName + " " + req.body.lastName,
    });
});

app.post("/images", (req, res) => {
    const targetFile = req.files["files[]"]; // get the image from posted files[]
    const extName = path.extname(targetFile.name); // get the extension
    const baseName = uuid4(); // generate a random uuid4, will be used as new name
    let uploadDir = path.join(__dirname, "temp", `${baseName}${extName}`); // uploadDir will be temp/{basename}.{extname}

    targetFile.mv(uploadDir, (err) => { // moving the uploaded image to upload dir
        if (err) return res.status(500).send(err); // returning an error if failed
    });
    return res.send(`${baseName}${extName}`); // returning the image with new name
});

app.get("/image/:imagename", (req, res) => {
    res.sendFile(path.join(__dirname, "temp", req.params.imagename)); // serving the image at image/{imagename} (includes the extension)
});

server.listen(5000, () => {
    console.log("Get ready for some fun!!!");
});
