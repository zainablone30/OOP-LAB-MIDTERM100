#include <iostream>
#include <vector>
#include <string>

class FitnessClass {
private:
    std::string className;
    int maxSlots;
    int availableSlots;

public:
    FitnessClass(const std::string& name, int maxSlots)
        : className(name), maxSlots(maxSlots), availableSlots(maxSlots) {}

    std::string getClassName() const {
        return className;
    }

    int getAvailableSlots() const {
        return availableSlots;
    }

    bool bookSlot() {
        if (availableSlots > 0) {
            availableSlots--;
            return true;
        }
        return false;
    }

    void cancelBooking() {
        availableSlots++;
    }
};

class Booking {
private:
    std::string memberName;
    FitnessClass* fitnessClass;

public:
    Booking(const std::string& name, FitnessClass* fitnessClass)
        : memberName(name), fitnessClass(fitnessClass) {}

    std::string getMemberName() const {
        return memberName;
    }

    FitnessClass* getFitnessClass() const {
        return fitnessClass;
    }
};

void displayBookedSlots(const std::vector<Booking>& bookings) {
    if (bookings.empty()) {
        std::cout << "No bookings made yet." << std::endl;
        return;
    }

    std::cout << "Booked Slots:" << std::endl;
    for (size_t i = 0; i < bookings.size(); ++i) {
        std::cout << i + 1 << ". " << bookings[i].getFitnessClass()->getClassName() << " - " << bookings[i].getMemberName() << std::endl;
    }
}

void cancelReservation(std::vector<Booking>& bookings) {
    displayBookedSlots(bookings);

    if (bookings.empty()) {
        return;
    }

    int choice;
    std::cout << "Enter the number of the reservation you want to cancel (0 to cancel): ";
    std::cin >> choice;

    if (choice == 0) {
        return;
    }

    if (choice > 0 && choice <= static_cast<int>(bookings.size())) {
        bookings.erase(bookings.begin() + choice - 1);
        std::cout << "Reservation canceled successfully." << std::endl;
    } else {
        std::cout << "Invalid choice!" << std::endl;
    }
}

int main() {
    // Create fitness classes
    FitnessClass yoga("Yoga", 10);
    FitnessClass zumba("Zumba", 15);
    FitnessClass pilates("Pilates", 8);

    // Create a vector to store bookings
    std::vector<Booking> bookings;

    while (true) {
        // Display available fitness classes
        std::cout << "\nAvailable Fitness Classes:" << std::endl;
        std::cout << "1. " << yoga.getClassName() << " (" << yoga.getAvailableSlots() << " slots available)" << std::endl;
        std::cout << "2. " << zumba.getClassName() << " (" << zumba.getAvailableSlots() << " slots available)" << std::endl;
        std::cout << "3. " << pilates.getClassName() << " (" << pilates.getAvailableSlots() << " slots available)" << std::endl;
        std::cout << "4. View Booked Slots" << std::endl;
        std::cout << "5. Cancel Reservation" << std::endl;
        std::cout << "6. Exit" << std::endl;

        // Get member's choice
        int choice;
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                if (yoga.bookSlot()) {
                    std::string memberName;
                    std::cout << "Enter your name: ";
                    std::cin >> memberName;

                    Booking newBooking(memberName, &yoga);
                    bookings.push_back(newBooking);

                    std::cout << "Booking confirmed! You have successfully booked a slot for " << yoga.getClassName() << "." << std::endl;
                } else {
                    std::cout << "Sorry, no slots available for " << yoga.getClassName() << "." << std::endl;
                }
                break;
            case 2:
                if (zumba.bookSlot()) {
                    std::string memberName;
                    std::cout << "Enter your name: ";
                    std::cin >> memberName;

                    Booking newBooking(memberName, &zumba);
                    bookings.push_back(newBooking);

                    std::cout << "Booking confirmed! You have successfully booked a slot for " << zumba.getClassName() << "." << std::endl;
                } else {
                    std::cout << "Sorry, no slots available for " << zumba.getClassName() << "." << std::endl;
                }
                break;
            case 3:
                if (pilates.bookSlot()) {
                    std::string memberName;
                    std::cout << "Enter your name: ";
                    std::cin >> memberName;

                    Booking newBooking(memberName, &pilates);
                    bookings.push_back(newBooking);

                    std::cout << "Booking confirmed! You have successfully booked a slot for " << pilates.getClassName() << "." << std::endl;
                } else {
                    std::cout << "Sorry, no slots available for " << pilates.getClassName() << "." << std::endl;
                }
                break;
            case 4:
                displayBookedSlots(bookings);
                break;
            case 5:
                cancelReservation(bookings);
                break;
            case 6:
                std::cout << "Exiting..." << std::endl;
                return 0;
            default:
                std::cout << "Invalid choice! Please try again." << std::endl;
                break;
        }
    }

    return 0;
}
