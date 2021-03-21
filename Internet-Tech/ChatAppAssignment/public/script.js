const msgList = document.getElementById("msg-list");
const userList = document.getElementById("user-list");

document
    .getElementById("image-input")
    .addEventListener("change", handleFileSelect, false); // adding change event listener to image input

const socket = io("/"); // socket initialization, main namespace

socket.on("connected", (newDb) => { // "connected" handler
    db = JSON.parse(JSON.stringify(newDb)); // copying the newDb
    db[UserName] = FullName; // adding new key, value
    updateContacts(); // updating the contacts list
    socket.emit("subscribe", UserName, FullName);
});

var db = {};

var urlRegex =/(\b(https?|ftp|file):\/\/[-A-Z0-9+&@#\/%?=~_|!:,.;]*[-A-Z0-9+&@#\/%=~_|])/ig;

db[UserName] = FullName;

var init = true; // at first init is true

const imageAdd = (username, b, url, fullname) => { // creating a message element for image
    console.log(url);
    if (!init) { // runs for new messages. This part stores the image link in Local Storage
        msgDb.push([username, url, db[username], b, "image"]);
        localStorage.setItem(`${UserName}`, JSON.stringify(msgDb));
    }
    let msgCard = document.createElement("div");
    msgCard.classList.add("msg-card");
    let msgHeader = document.createElement("div");
    msgHeader.classList.add("msg-header");
    let msgAvatar = document.createElement("div");
    msgAvatar.classList.add("msg-avatar");
    let svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
    svg.setAttribute("width", 50);
    svg.setAttribute("height", 50);
    svg.setAttribute("data-jdenticon-value", username);
    console.log(svg);
    msgAvatar.append(svg);
    let msgName = document.createElement("div");
    msgName.classList.add("msg-name");
    msgName.innerHTML = `<span style="font-family: 'Lora', serif; font-size: 20px;">${
        fullname ? fullname : db[username]
    }</span>`;
    msgHeader.append(msgAvatar);
    msgHeader.append(msgName);
    msgCard.append(msgHeader);
    let imageDiv = document.createElement("div");
    imageDiv.classList.add("image-div");
    let a = document.createElement("a");
    a.href = "/image/" + url;
    a.target = "_blank";
    let image = document.createElement("img");
    image.src = "/image/" + url;
    a.append(image);
    imageDiv.append(a);
    msgCard.append(imageDiv);
    msgList.append(msgCard);
    $("#msg-list").scrollTop($("#msg-list").prop("scrollHeight"));
    jdenticon.updateSvg(svg, username);
};

const addUsers = () => {
    userList.innerHTML = "";
    let users = [
        ...Object.entries(db)
            .map((elem) => {
                return {
                    name: elem[1],
                    value: elem[0],
                };
            })
            .filter((e) => e.value != UserName),
    ];
    users.forEach((e) => {
        let msgCard = document.createElement("div");
        msgCard.classList.add("msg-card");
        let msgHeader = document.createElement("div");
        msgHeader.classList.add("msg-header");
        let msgAvatar = document.createElement("div");
        msgAvatar.classList.add("msg-avatar");
        let svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
        svg.setAttribute("width", 50);
        svg.setAttribute("height", 50);
        svg.setAttribute("data-jdenticon-value", e.value);
        msgAvatar.append(svg);
        let msgName = document.createElement("div");
        msgName.classList.add("msg-name");
        msgName.innerHTML = `
            <span
                style="
                    font-family: 'Lora', cursive;
                    font-size: 20px;
                    display: flex;
                    flex-direction: column;
                "
            >
                <div>${e.value}</div>
                <div>${e.name}</div>
            </span>`;
        msgHeader.append(msgAvatar);
        msgHeader.append(msgName);
        msgCard.append(msgHeader);
        userList.append(msgCard);
        $("#user-list").scrollTop($("#user-list").prop("scrollHeight"));
        jdenticon.updateSvg(svg, e.value);
    });
};

const initMsg = () => {
    msgDb.forEach((e) => { // displaying previous messages, if any
        if (e[4] === "text") createMsg(e[0], e[1], e[2], e[3]);
        else imageAdd(e[0], e[3], e[1], e[2]);
    });
    init = false;
};

if (localStorage.getItem(`${UserName}`)) { // getting saved data from Local storage, if any
    var msgDb = JSON.parse(localStorage.getItem(`${UserName}`));
} else {
    var msgDb = [];
}

const createMsg = (username, msg, fullname, b) => { // creating a message element for image
    if (!init) { // runs for new messages. This part stores the message text in Local Storage
        msgDb.push([username, msg, db[username], b, "text"]);
        localStorage.setItem(`${UserName}`, JSON.stringify(msgDb));
    }
    let msgCard = document.createElement("div");
    msgCard.classList.add("msg-card");
    let msgHeader = document.createElement("div");
    msgHeader.classList.add("msg-header");
    let msgAvatar = document.createElement("div");
    msgAvatar.classList.add("msg-avatar");
    let svg = document.createElementNS("http://www.w3.org/2000/svg", "svg");
    svg.setAttribute("width", 50);
    svg.setAttribute("height", 50);
    svg.setAttribute("data-jdenticon-value", username);
    console.log(svg);
    msgAvatar.append(svg);
    let msgName = document.createElement("div");
    msgName.classList.add("msg-name");
    msgName.innerHTML = `<span style="font-family: 'Lora', serif; font-size: 20px;">${
        fullname ? fullname : db[username]
    }</span>`;
    msgHeader.append(msgAvatar);
    msgHeader.append(msgName);
    let msgMessage = document.createElement("div");
    msgMessage.classList.add("msg-message");
    if (msg.match(urlRegex)) {
        msgMessage.innerHTML =
        `<span style="font-weight: bolder; color: gray; font-family: 'Asap', sans-serif;"> ${
            b === "b" ? "Broadcast" : b === "m" ? "Multicast" : "Unicast"
        }: </span>` + `<a href=${msg} target="_blank">${msg}</a>`;
    }
    else
        msgMessage.innerHTML =
        `<span style="font-weight: bolder; color: gray; font-family: 'Asap', sans-serif;"> ${
            b === "b" ? "Broadcast" : b === "m" ? "Multicast" : "Unicast"
        }: </span>` + msg;
    msgCard.append(msgHeader);
    msgCard.append(msgMessage);
    msgList.append(msgCard);
    $("#msg-list").scrollTop($("#msg-list").prop("scrollHeight"));
    jdenticon.updateSvg(svg, username);
};

initMsg(); // initMsg() called here
const updateContacts = () => { // updates the contacts dropdown, with online members only
    $(".ui.search.dropdown").dropdown({
        direction: "upward",
        placeholder: "Select Contacts",
        values: [
            ...Object.entries(db)
                .map((elem) => {
                    return {
                        name: elem[1],
                        value: elem[0],
                    };
                })
                .filter((e) => e.value != UserName), // removing self from the list
        ],
    });
    addUsers();
};

socket.on("user-connected", (username, fullname) => {
    db[username] = fullname;
    updateContacts(); // update contacts when user connects
    let span = document.createElement("div");
    span.style.textAlign = "center";
    span.innerHTML = `${username} : ${fullname} Connected`; // display a message 
    msgList.append(span);
    $("#msg-list").scrollTop($("#msg-list").prop("scrollHeight"));
});

socket.on("user-disconnected", (username, fullname) => { // similar for user disconnected
    let span = document.createElement("div");
    span.style.textAlign = "center";
    span.innerHTML = `${username} : ${fullname} Disconnected`;
    msgList.append(span);
    $("#msg-list").scrollTop($("#msg-list").prop("scrollHeight"));
    delete db[username];
    updateContacts();
    // addUsers();
});

const msgInput = document.getElementById("msg-input");
const msgButton = document.getElementById("msg-button");
const imgButton = document.getElementById("image-button");

imgButton.addEventListener("click", (e) => {
    const imgInput = document.getElementById("image-input");
    imgInput.addEventListener("click", () => {
        const fileReader = new FileReader();
        let fname = null;

        console.log(fileReader);

        console.log(imgInput.files.length);

        fileReader.onload = () => {
            fname = imgInput.files[0];
            console.log(fname);
        };
    });
    imgInput.click();
});

msgButton.addEventListener("click", (e) => {
    if (msgInput.value.length > 0) { // if theres a message
        let contacts = [];
        $(".ui.label.transition.visible").each((e, v) => {
            contacts.push($(v).attr("data-value")); // getting contacts selected from dropdown
        });
        let b = contacts.length > 0 ? (contacts.length > 1 ? "m" : "u") : "b";
        if (contacts.length > 0) {
            socket.emit("send-msg", b, UserName, msgInput.value, contacts);
        } else {
            socket.emit("send-msg", b, UserName, msgInput.value, []);
        }
        createMsg(UserName, msgInput.value, null, b); // appending to sender's screen
        msgInput.value = "";
    }
});

msgInput.addEventListener("keyup", (e) => { // for enter key
    if (e.key === "Enter" || e.key === 13) {
        let contacts = [];
        $(".ui.label.transition.visible").each((e, v) => {
            contacts.push($(v).attr("data-value"));
        });
        if (msgInput.value.length > 0) {
            let b =
                contacts.length > 0 ? (contacts.length > 1 ? "m" : "u") : "b";
            if (contacts.length > 0) {
                socket.emit("send-msg", b, UserName, msgInput.value, contacts);
            } else {
                socket.emit("send-msg", b, UserName, msgInput.value, []);
            }
            createMsg(UserName, msgInput.value, null, b); // appending to sender's screen
            msgInput.value = "";
        }
    }
    e.preventDefault();
});

socket.on("msg-received", (username, msg, b) => {
    createMsg(username, msg, null, b); // appending to receiver's screen
});

function handleFileSelect(ele) { // element is image-input
    var file = ele.target.files[0]; // getting the file, our image
    const formData = new FormData(); // creating a new FormData object
    console.log(file);
    formData.append("files[]", file); // appending our image file as files[]

    const xhr = new XMLHttpRequest(); // new XHR for uploading the image

    // log response
    xhr.onload = () => { // The load event is fired when an XHR transaction completes successfully.
        console.log(xhr.response);
        let contacts = [];
        $(".ui.label.transition.visible").each((e, v) => {
            contacts.push($(v).attr("data-value"));
        });
        let b = contacts.length > 0 ? (contacts.length > 1 ? "m" : "u") : "b";
        imageAdd(UserName, b, xhr.response, null); // adding image to sender's window
        console.log(b);
        if (contacts.length > 0) {
            socket.emit("send-image", b, UserName, xhr.response, contacts);
        } else {
            socket.emit("send-image", b, UserName, xhr.response, []);
        }
    };

    xhr.open("POST", "/images"); // posting the XHR to /images link
    xhr.send(formData); // Sends the request
}

socket.on("receive-image", (username, url, b) => {
    console.log(url);
    imageAdd(username, b, url, null);
});
