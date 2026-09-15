#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Ticket {
private:
    int bookingID;
    string name;
    string movie;
    int seats;

public:
    void showMovies() {
        cout << "\n===== Available Movies =====\n";
        cout << "1. Avengers\n";
        cout << "2. Pushpa\n";
        cout << "3. Pathaan\n";
        cout << "4. Animal\n";
    }

    void bookTicket() {
        ofstream file("bookings.txt", ios::app);
        cout << "\nEnter Booking ID: ";
        cin >> bookingID;
        cin.ignore();

        cout << "Enter Your Name: ";
        getline(cin, name);

        cout << "Enter Movie Name: ";
        getline(cin, movie);

        cout << "Enter Number of Seats: ";
        cin >> seats;

        file << bookingID << "|" << name << "|" << movie << "|" << seats << endl;
        file.close();

        cout << "\nTicket Booked Successfully!\n";
    }

    void viewBookings() {
        ifstream file("bookings.txt");
        string line;

        cout << "\n===== All Bookings =====\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    }

    void cancelTicket() {
        ifstream file("bookings.txt");
        ofstream temp("temp.txt");
        string line;
        int id;
        bool found = false;

        cout << "\nEnter Booking ID to Cancel: ";
        cin >> id;

        while (getline(file, line)) {
            if (line.find(to_string(id)) != 0) {
                temp << line << endl;
            } else {
                found = true;
            }
        }

        file.close();
        temp.close();

        remove("bookings.txt");
        rename("temp.txt", "bookings.txt");

        if (found)
            cout << "\nTicket Cancelled Successfully!\n";
        else
            cout << "\nBooking Not Found!\n";
    }
};

int main() {
    Ticket t;
    int choice;

    do {
        cout << "\n===== Movie Ticket Booking System =====\n";
        cout << "1. Show Movies\n";
        cout << "2. Book Ticket\n";
        cout << "3. View Bookings\n";
        cout << "4. Cancel Ticket\n";
        cout << "5. Exit\n";
        cout << "Enter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                t.showMovies();
                break;
            case 2:
                t.bookTicket();
                break;
            case 3:
                t.viewBookings();
                break;
            case 4:
                t.cancelTicket();
                break;
            case 5:
                cout << "\nThank You for Using System!\n";
                break;
            default:
                cout << "\nInvalid Choice!\n";
        }

    } while (choice != 5);

    return 0;
}
