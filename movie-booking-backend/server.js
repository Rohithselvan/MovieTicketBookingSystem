const express = require('express');
const cors = require('cors');

const app = express();
const PORT = 3001;
const HOST = '0.0.0.0'; // Listen on all interfaces

// Enable CORS for all routes
app.use(cors());
app.use(express.json());

console.log('\n🚀 Starting server...\n');

// Movies data - Indian Blockbuster Movies (Tamil & Hindi)
const movies = [
  { movieId: 'M001', title: 'Vikram', genre: 'Action Thriller', durationMinutes: 173, language: 'Tamil', description: 'An intense action thriller featuring a special task force battling criminal organizations.', cast: ['Kamal Haasan', 'Vijay Sethupathi', 'Fahadh Faasil', 'Suriya'] },
  { movieId: 'M002', title: 'KGF - Chapter 2', genre: 'Action Drama', durationMinutes: 168, language: 'Kannada', description: 'A ruthless gold mine rule continues as the protagonist fights to maintain his empire.', cast: ['Yash', 'Srinidhi Shetty', 'Raveena Tandon', 'Sanjay Dutt'] },
  { movieId: 'M003', title: 'Dhurandhar', genre: 'Spy Thriller', durationMinutes: 214, language: 'Hindi', description: 'A gritty spy thriller where an Indian agent infiltrates Karachi underworld to dismantle terrorist networks inspired by true events and geopolitical conflicts.', cast: ['Ranveer Singh', 'Sanjay Dutt', 'Akshaye Khanna', 'R. Madhavan', 'Arjun Rampal'] },
  { movieId: 'M004', title: 'Leo', genre: 'Action Thriller', durationMinutes: 161, language: 'Tamil', description: 'A powerful action-packed revenge thriller with high-octane sequences and emotional depth.', cast: ['Thalapathy Vijay', 'Trisha', 'Arjun', 'Gautham Menon'] },
  { movieId: 'M005', title: 'Enthiran', genre: 'Sci-Fi Action', durationMinutes: 154, language: 'Tamil', description: 'A groundbreaking sci-fi film about a humanoid robot that defies its creator\'s will.', cast: ['Rajinikanth', 'Aishwarya Rai', 'Santhanam', 'Kalabhavan Mani'] }
];

// Shows data
const shows = [
  { showId: 'S001', movieId: 'M001', theater: 'Pathé Cinema Chennai', date: '2025-12-13', startTime: '18:00', ticketPrice: 280, totalSeats: 100, availableSeats: 85, bookedSeats: [1, 2, 3, 5, 7, 10, 15, 20, 25, 30, 35, 40, 45, 50, 55] },
  { showId: 'S002', movieId: 'M001', theater: 'Pathé Cinema Chennai', date: '2025-12-13', startTime: '21:30', ticketPrice: 320, totalSeats: 100, availableSeats: 92, bookedSeats: [1, 2, 3] },
  { showId: 'S003', movieId: 'M002', theater: 'PVR Cinemas Bangalore', date: '2025-12-13', startTime: '19:30', ticketPrice: 290, totalSeats: 100, availableSeats: 78, bookedSeats: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 20, 25] },
  { showId: 'S004', movieId: 'M002', theater: 'PVR Cinemas Bangalore', date: '2025-12-14', startTime: '18:30', ticketPrice: 270, totalSeats: 100, availableSeats: 88, bookedSeats: [1, 2, 3, 4, 5] },
  { showId: 'S005', movieId: 'M003', theater: 'PVR Cinemas Delhi', date: '2025-12-13', startTime: '17:00', ticketPrice: 350, totalSeats: 100, availableSeats: 80, bookedSeats: [5, 10, 15, 20, 25, 30] },
  { showId: 'S006', movieId: 'M003', theater: 'PVR Cinemas Delhi', date: '2025-12-14', startTime: '20:00', ticketPrice: 380, totalSeats: 100, availableSeats: 95, bookedSeats: [1, 2] },
  { showId: 'S007', movieId: 'M004', theater: 'Sathyam Cinemas', date: '2025-12-13', startTime: '16:30', ticketPrice: 275, totalSeats: 100, availableSeats: 90, bookedSeats: [8, 16, 24, 32] },
  { showId: 'S008', movieId: 'M004', theater: 'Sathyam Cinemas', date: '2025-12-14', startTime: '19:00', ticketPrice: 310, totalSeats: 100, availableSeats: 87, bookedSeats: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13] },
  { showId: 'S009', movieId: 'M005', theater: 'INOX Cinemas Chennai', date: '2025-12-13', startTime: '17:30', ticketPrice: 285, totalSeats: 100, availableSeats: 82, bookedSeats: [3, 6, 9, 12, 15, 18, 21, 24, 27, 30, 33, 36, 39, 42, 45, 48, 51, 54] },
  { showId: 'S010', movieId: 'M005', theater: 'INOX Cinemas Chennai', date: '2025-12-14', startTime: '20:30', ticketPrice: 330, totalSeats: 100, availableSeats: 93, bookedSeats: [1, 2, 3, 4, 5, 6, 7] }
];

// Bookings array
const bookings = [];
let bookingCounter = 1;

// Helper functions
function isSeatAvailable(show, seatNumber) {
  return !show.bookedSeats.includes(seatNumber) && seatNumber >= 1 && seatNumber <= show.totalSeats;
}

function bookSeats(show, seats) {
  const unavailable = seats.filter(seat => !isSeatAvailable(show, seat));
  if (unavailable.length > 0) {
    return { success: false, unavailable };
  }
  seats.forEach(seat => {
    show.bookedSeats.push(seat);
  });
  show.availableSeats = show.totalSeats - show.bookedSeats.length;
  return { success: true };
}

function releaseSeats(show, seats) {
  seats.forEach(seat => {
    show.bookedSeats = show.bookedSeats.filter(s => s !== seat);
  });
  show.availableSeats = show.totalSeats - show.bookedSeats.length;
}

// ============ API ENDPOINTS ============

// Health check
app.get('/api/health', (req, res) => {
  console.log('✅ Health check');
  res.json({ status: 'OK', port: PORT });
});

// Get all movies
app.get('/api/movies', (req, res) => {
  console.log('📽️  GET /api/movies - Sending', movies.length, 'movies');
  res.json(movies);
});

// Get shows by movieId
app.get('/api/shows/:movieId', (req, res) => {
  const movieId = req.params.movieId;
  console.log('🎬 GET /api/shows/' + movieId);
  const movieShows = shows.filter(s => s.movieId === movieId);
  if (movieShows.length === 0) {
    return res.status(404).json({ message: 'No shows found' });
  }
  console.log('   Found', movieShows.length, 'shows');
  res.json(movieShows);
});

// Create booking
app.post('/api/bookings', (req, res) => {
  const { showId, customerName, customerPhone, seats } = req.body;
  
  console.log('🎫 POST /api/bookings - Customer:', customerName);
  
  if (!showId || !customerName || !customerPhone || !seats || seats.length === 0) {
    console.log('   ❌ Missing fields');
    return res.status(400).json({ message: 'Missing required fields' });
  }

  const show = shows.find(s => s.showId === showId);
  if (!show) {
    console.log('   ❌ Show not found');
    return res.status(404).json({ message: 'Show not found' });
  }

  const unavailable = seats.filter(seat => !isSeatAvailable(show, seat));
  if (unavailable.length > 0) {
    console.log('   ❌ Seats unavailable:', unavailable);
    return res.status(400).json({ message: 'Some seats are booked', unavailableSeats: unavailable });
  }

  const bookResult = bookSeats(show, seats);
  if (!bookResult.success) {
    console.log('   ❌ Booking failed');
    return res.status(400).json({ message: 'Booking failed' });
  }

  const booking = {
    bookingId: 'B' + bookingCounter++,
    showId,
    show,
    customerName,
    customerPhone,
    seats: seats.sort((a, b) => a - b),
    totalAmount: (seats.length * show.ticketPrice).toFixed(2),
    timestamp: new Date().toISOString(),
    status: 'CONFIRMED'
  };

  bookings.push(booking);
  console.log('   ✅ Booking created:', booking.bookingId);
  res.status(201).json(booking);
});

// Get booking
app.get('/api/bookings/:bookingId', (req, res) => {
  const booking = bookings.find(b => b.bookingId === req.params.bookingId);
  if (!booking) {
    return res.status(404).json({ message: 'Booking not found' });
  }
  res.json(booking);
});

// Get all bookings
app.get('/api/bookings', (req, res) => {
  console.log('📋 GET /api/bookings - Total:', bookings.length);
  res.json(bookings);
});

// Cancel booking
app.delete('/api/bookings/:bookingId', (req, res) => {
  const idx = bookings.findIndex(b => b.bookingId === req.params.bookingId);
  if (idx === -1) {
    return res.status(404).json({ message: 'Booking not found' });
  }

  const booking = bookings[idx];
  const show = shows.find(s => s.showId === booking.showId);
  if (show) {
    releaseSeats(show, booking.seats);
  }

  booking.status = 'CANCELLED';
  console.log('❌ Booking cancelled:', booking.bookingId);
  res.json({ message: 'Cancelled', booking });
});

// Catch-all
app.use((req, res) => {
  console.log('⚠️  404:', req.method, req.path);
  res.status(404).json({ message: 'Endpoint not found' });
});

// Error handler
app.use((err, req, res, next) => {
  console.error('❌ Error:', err.message);
  res.status(500).json({ message: 'Server error', error: err.message });
});

// ============ START SERVER ============

const server = app.listen(PORT, HOST, () => {
  console.log('╔════════════════════════════════════════════════════════════╗');
  console.log('║   🎬 MOVIE TICKET BOOKING SYSTEM - REST API SERVER 🎬      ║');
  console.log('║                                                            ║');
  console.log('║   🇮🇳 Indian Movies Booking System (Tamil & Hindi) 🇮🇳  ║');
  console.log('╠════════════════════════════════════════════════════════════╣');
  console.log(`║ ✅ Server is running on: http://localhost:${PORT}         ║`);
  console.log('║                                                            ║');
  console.log('║ Available Endpoints:                                       ║');
  console.log('║  GET    /api/movies          - Get all movies              ║');
  console.log('║  GET    /api/shows/:movieId  - Get shows for movie         ║');
  console.log('║  POST   /api/bookings        - Create booking              ║');
  console.log('║  GET    /api/bookings/:id    - Get booking details         ║');
  console.log('║  DELETE /api/bookings/:id    - Cancel booking              ║');
  console.log('║  GET    /api/health          - Health check                ║');
  console.log('║                                                            ║');
  console.log('║ Featured Movies:                                           ║');
  console.log('║ 1. Vikram (Tamil)      2. KGF-2 (Kannada)                  ║');
  console.log('║ 3. Dhurandhar (Hindi)  4. Leo (Tamil)                      ║');
  console.log('║ 5. Enthiran (Tamil)                                        ║');
  console.log('║                                                            ║');
  console.log('║ Frontend: http://localhost:3000                            ║');
  console.log('╚════════════════════════════════════════════════════════════╝');
  console.log('\n');
});

// Handle graceful shutdown
process.on('SIGTERM', () => {
  console.log('\n🛑 Server shutting down...');
  server.close(() => {
    console.log('✅ Server stopped');
    process.exit(0);
  });
});