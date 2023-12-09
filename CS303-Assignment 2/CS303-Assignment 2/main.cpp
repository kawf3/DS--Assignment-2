#include <iostream>
#include <fstream>
#include <array>
#include <string>
#include <cmath>
#include <stdexcept>

#include "Employee.h" 
#include "Single_Linked_List.cpp"

using namespace std;

Single_Linked_List<int> listS;

int main() {
    for (int i = 1; i <= 10; i++) {
        listS.push_back(i);
    }

    int choice, item, index, position;

    //creation of two new employees
    Employee* emp;
    Employee* emp2;

    do {
        //Menu display
        cout << "\n-----MENU-----" << endl;
        cout << "Please only enter integers" << endl;
        cout << "1. Push front" << endl;
        cout << "2. Push back" << endl;
        cout << "3. Pop front" << endl;
        cout << "4. Pop back" << endl;
        cout << "5. Front" << endl;
        cout << "6. Back" << endl;
        cout << "7. Empty" << endl;
        cout << "8. Insert" << endl;
        cout << "9. Remove" << endl;
        cout << "10. Find" << endl;
        cout << "11. Test out classes relating to employees" << endl;
        cout << "12. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter integer to push front: ";
            cin >> item;
            listS.push_front(item);
            break;
        case 2:
            cout << "Enter integer to push back: ";
            cin >> item;
            listS.push_back(item);
            break;
        case 3:
            listS.pop_front();
            break;
        case 4:
            listS.pop_back();
            break;
        case 5:
            cout << "Front integer: " << listS.front() << endl;
            break;
        case 6:
            cout << "Back integer: " << listS.back() << endl;
            break;
        case 7:
            if (listS.empty()) {
                cout << "List is empty" << endl;
            }
            else {
                cout << "List is not empty" << endl;
            }
            break;
        case 8:
            cout << "Enter index to insert at: ";
            cin >> index;
            cout << "Enter integer to insert: ";
            cin >> item;
            listS.insert(index, item);
            break;
        case 9:
            cout << "Enter index to remove: ";
            cin >> index;
            if (listS.remove(index)) {
                cout << "Integer removed successfully" << endl;
            }
            else {
                cout << "Index is beyond the end of the list" << endl;
            }
            break;
        case 10:
            cout << "Enter Integer to find: ";
            cin >> item;
            position = listS.find(item);
            if (position == listS.size()) {
                cout << "Integer not found" << endl;
            }
            else {
                cout << "Integer found at position " << position << endl;
            }
            break;
        case 11:
            //Automatic creation and assigning of employee information
            emp = new Professional(5000, 15);
            cout << "Type: " << emp->getType() << endl;
            cout << "Weekly salary: " << emp->weeklySalary() << endl;
            cout << "Health care contribution: " << emp->healthCare() << endl;
            cout << "Vacation Days: " << emp->vacationDays() << endl;
            cout << endl;

            emp2 = new NonProfessional(20, 40, 120);
            cout << "Type: " << emp2->getType() << endl;
            cout << "Weekly salary: " << emp2->weeklySalary() << endl;
            cout << "Health care contribution: " << emp2->healthCare() << endl;
            cout << "Vacation Days: " << emp2->vacationDays() << endl;

            delete emp;
            delete emp2;
            break;
        case 12:
            cout << "Exiting..." << endl;
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    } while (choice != 12); // Exit loop when choice is 12 (Exit)

}
