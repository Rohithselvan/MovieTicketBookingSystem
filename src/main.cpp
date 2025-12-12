#include "BookingSystem.hpp"
#include <iostream>
#include <vector>

using namespace std;

int main()
{
    BookingSystem system;

    cout << "\n"
         << endl;
    cout << "===============================================================" << endl;
    cout << "|   MOVIE TICKET BOOKING SYSTEM - C++ DEMO                    |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|   Indian Blockbuster Movies (Tamil, Kannada, Hindi)         |" << endl;
    cout << "===============================================================" << endl;
    cout << "\n"
         << endl;

    // ==================== CREATE 5 INDIAN MOVIES ====================
    cout << "Loading 5 Indian Blockbuster Movies...\n"
         << endl;

    // Movie 1: Vikram (Tamil)
    Movie *vikram = new Movie("M001", "Vikram",
                              "An intense action thriller featuring a special task force battling criminal organizations.",
                              MovieGenre::ACTION, 173, "Tamil");
    vikram->addCastMember("Kamal Haasan");
    vikram->addCastMember("Vijay Sethupathi");
    vikram->addCastMember("Fahadh Faasil");
    vikram->addCastMember("Suriya");

    // Movie 2: KGF - Chapter 2 (Kannada)
    Movie *kgf2 = new Movie("M002", "KGF - Chapter 2",
                            "A ruthless gold mine rule continues as the protagonist fights to maintain his empire.",
                            MovieGenre::ACTION, 168, "Kannada");
    kgf2->addCastMember("Yash");
    kgf2->addCastMember("Srinidhi Shetty");
    kgf2->addCastMember("Raveena Tandon");
    kgf2->addCastMember("Sanjay Dutt");

    // Movie 3: Dhurandhar (Hindi)
    Movie *dhurandhar = new Movie("M003", "Dhurandhar",
                                  "A gritty spy thriller where an Indian agent infiltrates Karachi underworld to dismantle terrorist networks.",
                                  MovieGenre::THRILLER, 214, "Hindi");
    dhurandhar->addCastMember("Ranveer Singh");
    dhurandhar->addCastMember("Sanjay Dutt");
    dhurandhar->addCastMember("Akshaye Khanna");
    dhurandhar->addCastMember("R. Madhavan");
    dhurandhar->addCastMember("Arjun Rampal");

    // Movie 4: Leo (Tamil)
    Movie *leo = new Movie("M004", "Leo",
                           "A powerful action-packed revenge thriller with high-octane sequences and emotional depth.",
                           MovieGenre::ACTION, 161, "Tamil");
    leo->addCastMember("Thalapathy Vijay");
    leo->addCastMember("Trisha");
    leo->addCastMember("Arjun");
    leo->addCastMember("Gautham Menon");

    // Movie 5: Enthiran (Tamil)
    Movie *enthiran = new Movie("M005", "Enthiran",
                                "A groundbreaking sci-fi film about a humanoid robot that defies its creator's will.",
                                MovieGenre::SCIFI, 154, "Tamil");
    enthiran->addCastMember("Rajinikanth");
    enthiran->addCastMember("Aishwarya Rai");
    enthiran->addCastMember("Santhanam");
    enthiran->addCastMember("Kalabhavan Mani");

    // Add movies to system
    system.addMovie(vikram);
    system.addMovie(kgf2);
    system.addMovie(dhurandhar);
    system.addMovie(leo);
    system.addMovie(enthiran);

    cout << "[OK] 5 Indian movies loaded successfully!\n"
         << endl;

    // ==================== CREATE THEATERS ====================
    cout << "Setting up Indian Cinema Chains...\n"
         << endl;

    Theater *patheCinemaChennai = new Theater("T001", "Pathe Cinema Chennai", "Chennai", 100);
    Theater *pvrCinemasBangalore = new Theater("T002", "PVR Cinemas Bangalore", "Bangalore", 100);
    Theater *pvrCinemaDelhi = new Theater("T003", "PVR Cinemas Delhi", "Delhi", 100);
    Theater *sathyamCinemas = new Theater("T004", "Sathyam Cinemas", "Chennai", 100);
    Theater *inoxCinemas = new Theater("T005", "INOX Cinemas Chennai", "Chennai", 100);

    system.addTheater(patheCinemaChennai);
    system.addTheater(pvrCinemasBangalore);
    system.addTheater(pvrCinemaDelhi);
    system.addTheater(sathyamCinemas);
    system.addTheater(inoxCinemas);

    cout << "[OK] 5 theaters configured!\n"
         << endl;

    // ==================== CREATE SHOWS ====================
    cout << "Scheduling Shows...\n"
         << endl;

    // Shows for Vikram (M001)
    Show *vikram_show1 = new Show("S001", vikram, "2025-12-13", "18:00", 280, 100);
    Show *vikram_show2 = new Show("S002", vikram, "2025-12-13", "21:30", 320, 100);
    patheCinemaChennai->addShow(vikram_show1);
    patheCinemaChennai->addShow(vikram_show2);
    cout << "  [+] Vikram: 2 shows at Pathe Cinema Chennai" << endl;

    // Shows for KGF - Chapter 2 (M002)
    Show *kgf2_show1 = new Show("S003", kgf2, "2025-12-13", "19:30", 290, 100);
    Show *kgf2_show2 = new Show("S004", kgf2, "2025-12-14", "18:30", 270, 100);
    pvrCinemasBangalore->addShow(kgf2_show1);
    pvrCinemasBangalore->addShow(kgf2_show2);
    cout << "  [+] KGF - Chapter 2: 2 shows at PVR Cinemas Bangalore" << endl;

    // Shows for Dhurandhar (M003) - Hindi Spy Thriller
    Show *dhurandhar_show1 = new Show("S005", dhurandhar, "2025-12-13", "17:00", 350, 100);
    Show *dhurandhar_show2 = new Show("S006", dhurandhar, "2025-12-14", "20:00", 380, 100);
    pvrCinemaDelhi->addShow(dhurandhar_show1);
    pvrCinemaDelhi->addShow(dhurandhar_show2);
    cout << "  [+] Dhurandhar: 2 shows at PVR Cinemas Delhi (Hindi)" << endl;

    // Shows for Leo (M004)
    Show *leo_show1 = new Show("S007", leo, "2025-12-13", "16:30", 275, 100);
    Show *leo_show2 = new Show("S008", leo, "2025-12-14", "19:00", 310, 100);
    sathyamCinemas->addShow(leo_show1);
    sathyamCinemas->addShow(leo_show2);
    cout << "  [+] Leo: 2 shows at Sathyam Cinemas" << endl;

    // Shows for Enthiran (M005)
    Show *enthiran_show1 = new Show("S009", enthiran, "2025-12-13", "17:30", 285, 100);
    Show *enthiran_show2 = new Show("S010", enthiran, "2025-12-14", "20:30", 330, 100);
    inoxCinemas->addShow(enthiran_show1);
    inoxCinemas->addShow(enthiran_show2);
    cout << "  [+] Enthiran: 2 shows at INOX Cinemas Chennai" << endl;

    cout << "\n[OK] All 10 shows scheduled!\n"
         << endl;

    // ==================== DISPLAY MOVIES ====================
    cout << "===============================================================" << endl;
    cout << "|              AVAILABLE MOVIES IN SYSTEM                     |" << endl;
    cout << "===============================================================\n"
         << endl;
    system.displayMovies();

    // ==================== DISPLAY SHOWS ====================
    cout << "===============================================================" << endl;
    cout << "|         SHOWS FOR VIKRAM (Tamil Action Thriller)            |" << endl;
    cout << "===============================================================\n"
         << endl;
    system.displayShows("M001");

    cout << "===============================================================" << endl;
    cout << "|         SHOWS FOR DHURANDHAR (Hindi Spy Thriller)           |" << endl;
    cout << "===============================================================\n"
         << endl;
    system.displayShows("M003");

    // ==================== CREATE BOOKINGS ====================
    cout << "===============================================================" << endl;
    cout << "|                  BOOKING DEMONSTRATION                      |" << endl;
    cout << "===============================================================\n"
         << endl;

    // Booking 1: Vikram
    cout << "[BOOKING-1] Customer 'Rajesh Kumar' for Vikram\n"
         << endl;
    vector<int> vikram_seats = {5, 6, 7};
    Booking *booking1 = system.createBooking("S001", "Rajesh Kumar", "+91-9876543210", vikram_seats);

    if (booking1)
    {
        cout << "[OK] Booking 1 created successfully!\n"
             << endl;
        system.displayBooking(booking1->getBookingId());
        cout << endl;

        // Try to book same seats again
        cout << "[ATTEMPT] Attempting to book SAME seats again...\n"
             << endl;
        Booking *failedBooking = system.createBooking("S001", "Priya Singh", "+91-9876543211", vikram_seats);

        if (!failedBooking)
        {
            cout << "[FAILED] Booking failed as expected: Seats [5, 6, 7] already taken!\n"
                 << endl;
        }

        // Book different seats
        cout << "[BOOKING-2] Customer 'Priya Singh' for different seats\n"
             << endl;
        vector<int> vikram_seats2 = {10, 11, 12};
        Booking *booking2 = system.createBooking("S001", "Priya Singh", "+91-9876543211", vikram_seats2);

        if (booking2)
        {
            cout << "[OK] Booking 2 created successfully!\n"
                 << endl;
            system.displayBooking(booking2->getBookingId());
            cout << endl;

            // Booking 3: Dhurandhar (Hindi)
            cout << "[BOOKING-3] Customer 'Arun Verma' for Dhurandhar (Hindi Spy Thriller)\n"
                 << endl;
            vector<int> dhurandhar_seats = {15, 16, 17, 18};
            Booking *booking3 = system.createBooking("S005", "Arun Verma", "+91-8765432109", dhurandhar_seats);

            if (booking3)
            {
                cout << "[OK] Booking 3 created successfully for Dhurandhar!\n"
                     << endl;
                system.displayBooking(booking3->getBookingId());
                cout << endl;

                // Cancel first booking
                cout << "===============================================================" << endl;
                cout << "|                 CANCELLATION DEMONSTRATION                  |" << endl;
                cout << "===============================================================\n"
                     << endl;

                cout << "[CANCEL] Cancelling Booking 1...\n"
                     << endl;
                if (system.cancelBooking(booking1->getBookingId()))
                {
                    cout << "[OK] Booking 1 cancelled successfully!\n"
                         << endl;
                    system.displayBooking(booking1->getBookingId());
                    cout << endl;
                }

                // Display all bookings
                cout << "===============================================================" << endl;
                cout << "|                 ALL BOOKINGS IN SYSTEM                      |" << endl;
                cout << "===============================================================\n"
                     << endl;
                system.displayMovies();
            }
        }
    }

    cout << "===============================================================" << endl;
    cout << "|         DEMO COMPLETED SUCCESSFULLY!                        |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|  Indian Movies Booking System (C++ OOP)                     |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|  Features:                                                  |" << endl;
    cout << "|  [+] 5 Indian Blockbuster Movies                            |" << endl;
    cout << "|  [+] 5 Cinema Chains                                        |" << endl;
    cout << "|  [+] 10 Shows Scheduled                                     |" << endl;
    cout << "|  [+] Real-time Seat Management                              |" << endl;
    cout << "|  [+] Double-booking Prevention                              |" << endl;
    cout << "|  [+] Booking Cancellation Support                           |" << endl;
    cout << "|                                                             |" << endl;
    cout << "|  Movies Included:                                           |" << endl;
    cout << "|  1. Vikram (Tamil)          - Kamal Haasan                 |" << endl;
    cout << "|  2. KGF - Chapter 2 (Kannada) - Yash                       |" << endl;
    cout << "|  3. Dhurandhar (Hindi)      - Ranveer Singh                |" << endl;
    cout << "|  4. Leo (Tamil)             - Thalapathy Vijay             |" << endl;
    cout << "|  5. Enthiran (Tamil)        - Rajinikanth                  |" << endl;
    cout << "|                                                             |" << endl;
    cout << "===============================================================\n"
         << endl;

    // Clean up memory
    delete vikram;
    delete kgf2;
    delete dhurandhar;
    delete leo;
    delete enthiran;
    delete patheCinemaChennai;
    delete pvrCinemasBangalore;
    delete pvrCinemaDelhi;
    delete sathyamCinemas;
    delete inoxCinemas;
    delete vikram_show1;
    delete vikram_show2;
    delete kgf2_show1;
    delete kgf2_show2;
    delete dhurandhar_show1;
    delete dhurandhar_show2;
    delete leo_show1;
    delete leo_show2;
    delete enthiran_show1;
    delete enthiran_show2;

    return 0;
}