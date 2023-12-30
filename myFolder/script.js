function showMessage(message) {
    document.getElementById('message').innerText = message;
}

function signup() {
    let admin = document.getElementById("admin").value;
    let username = document.getElementById("username").value;
    let password = document.getElementById("password").value;

    if (!admin || !username || !password) {
        showMessage("All fields are required for signup");
        return;
    }

    if(localStorage.getItem(username) === null){
        localStorage.setItem(username, JSON.stringify({password, admin}));
        showMessage("Signup successful!");
    } else {
        showMessage("Username already exists!");
    }
}
function login() {
    let username = document.getElementById("username").value;
    let password = document.getElementById("password").value;

    let userDetails = JSON.parse(localStorage.getItem(username));
    if(userDetails && userDetails.password === password){
        // Set logged-in flag
        localStorage.setItem("isLoggedIn", "true");

        // Redirect to dashboard
        window.location.href = "dashboard.html";
    } else {
        // Show error message: Invalid username or password
        showMessage("Invalid username or password");
    }
}