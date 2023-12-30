if (localStorage.getItem("isLoggedIn") !== "true") {
    window.location.href = "index.html";
}

function addTrain() {
    var trainNumber = document.getElementById("trainNumber").value;
    var trainRoute = document.getElementById("trainRoute").value;
    var entryPrice = document.getElementById("entryPrice").value;

    if (!trainNumber || !trainRoute || !entryPrice) {
        alert("Please fill in all fields");
        return;
    }

    // Optional: Validate that entry price is a valid number
    if (isNaN(entryPrice) || entryPrice < 0) {
        alert("Please enter a valid entry price");
        return;
    }

    var trains = JSON.parse(localStorage.getItem("trains") || "[]");
    trains.push({ trainNumber, trainRoute, entryPrice });
    localStorage.setItem("trains", JSON.stringify(trains));

 document.getElementById("trainNumber").value = '';
   document.getElementById("trainRoute").value = '';
    document.getElementById("entryPrice").value = '';


    alert("Train added successfully");
}



function viewTrains() {
    var trains = JSON.parse(localStorage.getItem("trains") || "[]");
    var trainList = document.getElementById("trainList");
    trainList.innerHTML = '<h3>All Trains:</h3>';

    trains.forEach(function(train) {
        trainList.innerHTML += 'Number: ' + train.trainNumber + ', Route: ' + train.trainRoute + ' , Price: ' + train.entryPrice + '<br>';
    });
}

function searchTrainByNumber() {
    var searchNumber = document.getElementById("searchTrainNumber").value.trim();
    var trains = JSON.parse(localStorage.getItem("trains") || "[]");
    var trainList = document.getElementById("trainList");
    trainList.innerHTML = '<h3>Search Results by Number:</h3>';

    var foundTrains = trains.filter(function(train) {
        return train.trainNumber === searchNumber;
    });

    displaySearchResults(foundTrains, trainList);
}

function searchTrainByRoute() {
    var searchRoute = document.getElementById("searchTrainRoute").value.trim().toLowerCase();
    var trains = JSON.parse(localStorage.getItem("trains") || "[]");
    var trainList = document.getElementById("trainList");
    trainList.innerHTML = '<h3>Search Results by Route:</h3>';

    var foundTrains = trains.filter(function(train) {
        return train.trainRoute.trim().toLowerCase().includes(searchRoute);
    });

    displaySearchResults(foundTrains, trainList);
}

function displaySearchResults(foundTrains, trainList) {
    if (foundTrains.length > 0) {
        foundTrains.forEach(function(train) {
            trainList.innerHTML += 'Number: ' + train.trainNumber + ', Route: ' + train.trainRoute +  ', Price: ' + train.entryPrice +'<br>';
        });
    } else {
        trainList.innerHTML += 'No trains found for the given search criteria';
    }
}




function bookTicket() {
    var bookingId = document.getElementById("bookingId").value;
    var passengerName = document.getElementById("passengerName").value;
    var trainNumber = document.getElementById("bookTrainNumber").value;

    if (!bookingId || !passengerName || !trainNumber) {
        alert("Please fill in all booking fields");
        return;
    }

    // Check if the train number exists
    var trains = JSON.parse(localStorage.getItem("trains") || "[]");
    var trainPrice = '';
    var trainExists = trains.some(function(train) {
        if(train.trainNumber  === trainNumber){
            trainPrice = train.entryPrice;
        }
        return train.trainNumber === trainNumber;
    });




    if (!trainExists) {
        alert("Train number does not exist. Please enter a valid train number.");
        return;
    }

    // Proceed with booking
    var bookings = JSON.parse(localStorage.getItem("bookings") || "[]");
    bookings.push({ bookingId, passengerName, trainNumber, trainPrice });
    localStorage.setItem("bookings", JSON.stringify(bookings));

    alert("Ticket booked successfully");
}
function viewBookings() {
    var bookings = JSON.parse(localStorage.getItem("bookings") || "[]");
    var bookingList = document.getElementById("bookingList");
    bookingList.innerHTML = '<h3>All Bookings:</h3>';

    bookings.forEach(function(booking) {
        bookingList.innerHTML += 'Booking ID: ' + booking.bookingId + ', Passenger: ' + booking.passengerName + ', Train Number: ' + booking.trainNumber +  ', Price: '+ booking.trainPrice +'<br>';
    });
}



function logout() {
    // Clear logged-in flag
    localStorage.removeItem("isLoggedIn");

    // Redirect to login page
    window.location.href = "index.html";
}



function cancelTicket() {
    var cancelBookingId = document.getElementById("cancelBookingId").value;
    
    if (!cancelBookingId) {
        alert("Please enter a Booking ID to cancel");
        return;
    }

    var bookings = JSON.parse(localStorage.getItem("bookings") || "[]");
    var updatedBookings = bookings.filter(function(booking) {
        return booking.bookingId !== cancelBookingId;
    });

    if (bookings.length === updatedBookings.length) {
        alert("No booking found with ID: " + cancelBookingId);
        return;
    }

    localStorage.setItem("bookings", JSON.stringify(updatedBookings));
    alert("Booking cancelled successfully");

    // Optionally, refresh the bookings list if displayed
    viewBookings();
}