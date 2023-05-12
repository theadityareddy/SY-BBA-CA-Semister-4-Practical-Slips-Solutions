const fs = require('fs');
const moment = require('moment');

// Sample data for the eTicket
const ticketData = {
  from: 'New York',
  to: 'Los Angeles',
  date: '2023-06-01',
  departureTime: '10:00 AM',
  arrivalTime: '5:00 PM',
  trainName: 'California Zephyr',
  seatNumber: 'A32',
  passengerName: 'John Doe',
  price: 99.99,
};

// Generate the eTicket text
const ticketText = `
  -----------------------------------------
  |            RAILWAY E-TICKET            |
  -----------------------------------------
  | From: ${ticketData.from}                |
  | To: ${ticketData.to}                    |
  | Date: ${moment(ticketData.date).format('MMMM DD, YYYY')}            |
  | Departure Time: ${ticketData.departureTime}         |
  | Arrival Time: ${ticketData.arrivalTime}             |
  | Train Name: ${ticketData.trainName}           |
  | Seat Number: ${ticketData.seatNumber}             |
  | Passenger Name: ${ticketData.passengerName}      |
  | Price: $${ticketData.price.toFixed(2)}             |
  -----------------------------------------
`;

// Save the eTicket to a file
const fileName = `eTicket_${moment().format('YYYY-MM-DD_HH-mm-ss')}.txt`;
fs.writeFile(fileName, ticketText, function(err) {
  if (err) throw err;
  console.log(`The eTicket has been saved to ${fileName}.`);
});
