const { v4: uuid4 } = require("uuid"); // uuid4, used in creating a temp room with a random name

const sockets = {};

const usernameMapper = (db) => { // returns a map of {Username: Fullname}
    let newDb = {};
    Object.entries(db).forEach((k) => {
        // console.table(k);
        newDb[k[0]] = k[1].fullName;
    });
    return newDb;
};

sockets.init = (server, db, socketDb) => {
    const io = require("socket.io")(server); // server from index.js used in socket.io server
    io.on("connection", (socket) => { // on connection...
        console.log(`Socket Connected : ${socket.id}`);
        socket.emit("connected", usernameMapper(db));
        socket.join("room"); // room is the place for broadcast
        socket.on("subscribe", (username, fullName) => { // * same socket object is present inside socket.on(...)
            let user = { // user object has socket and the fullName
                socket,
                fullName,
            };
            db[username] = user; // db gets key username, value user
            socketDb[socket.id] = username; // socketDb, stores the socket objects, key is socket, value is username
            socket
                .to("room")
                .broadcast.emit(
                    "user-connected",
                    username,
                    fullName,
                    usernameMapper(db)
                ); // broadcasting that a user has connected, handler in script.js
        });
        socket.on("disconnect", () => { // * same socket object is present inside socket.on(...)
            let username = socketDb[socket.id]; // getting username from socketDb using socket.id key
            console.log(username);
            console.log(`Socket Disconnected : ${socket.id}`);
            let user = db[username]; // getting the user {socket, fullName} from db
            // console.log(user);
            delete db[username];
            delete socketDb[socket.id];
            socket
                .to("room")
                .broadcast.emit("user-disconnected", username, user.fullName); // broadcasting that a user has disconnected
        });
        socket.on("send-msg", (type, username, msg, contacts) => { // sending a message
            if (type === "b") { // type is b for broadcast
                socket
                    .to("room")
                    .broadcast.emit("msg-received", username, msg, type); // broadcasting the message
            } else { // else creating a room
                let tempRoom = uuid4(); // temp room with a random uuid4 name
                console.log(contacts); // contacts as selected from the contact selection dropdown
                contacts.forEach((element) => {
                    db[element].socket.join(tempRoom); // getting the sockets using the usernames and joining them to the temp room
                });
                socket
                    .to(tempRoom)
                    .broadcast.emit("msg-received", username, msg, type); // sending the message in our temp room
                contacts.forEach((element) => {
                    db[element].socket.join("room"); // joining the broadcast room back again, after message is sent.
                });
            }
        });
        socket.on("send-image", (type, username, msg, contacts) => { // sending an image as a message
            console.log(msg);
            if (type === "b") { // same procedure as in send-msg handler
                socket
                    .to("room")
                    .broadcast.emit("receive-image", username, msg, type);
            } else {
                let tempRoom = uuid4();
                console.log(contacts);
                contacts.forEach((element) => {
                    db[element].socket.join(tempRoom);
                });
                socket
                    .to(tempRoom)
                    .broadcast.emit("receive-image", username, msg, type);
                contacts.forEach((element) => {
                    db[element].socket.join("room");
                });
            }
        });
    });
};

// module.exports = sockets;
export default sockets;
