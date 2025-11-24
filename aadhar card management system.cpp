#include<iostream>
#include<string>
using namespace std;

class Citizen {
public:
    string name, gender, healthCondition, aadharNumber, dummyField;
    float age, weight;

    void input() {
        cout << "Enter Aadhar Number (12 digits): ";
        cin >> aadharNumber;

        cout << "Dummy field (ignored, enter any value): ";
        cin >> dummyField; // originally "time", retained to preserve structure

        cout << "Enter Name (use underscores for spaces): ";
        cin >> name;

        cout << "Enter Gender (M/F): ";
        cin >> gender;

        cout << "Enter Age: ";
        cin >> age;

        cout << "Enter Weight (kg): ";
        cin >> weight;

        cout << "Any Health Condition (Yes/No): ";
        string hasCondition;
        cin >> hasCondition;

        if (hasCondition == "Yes" || hasCondition == "yes") {
            cout << "Please specify health condition (e.g., Diabetes, Heart_Issue): ";
            cin >> healthCondition;
        } else {
            healthCondition = "None";
        }
    }

    void display() {
        cout << "Aadhar: " << aadharNumber
             << " | Name: " << name
             << " | Gender: " << gender
             << " | Age: " << age
             << " | Weight: " << weight
             << " | Health Condition: " << healthCondition << endl;
    }
};

int main() {
    Citizen citizens[10];
    int count = 0, choice;

    do {
        cout << "\n1. Register New Citizen\n2. Delete Record\n3. Update Record\n4. Search Record\n5. Show All Records\n6. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        if (choice == 1) {
            if (count < 10) {
                cout << "\n--- Register New Citizen ---\n";
                citizens[count].input();
                count++;
            } else {
                cout << "Record limit reached!\n";
            }
        }

        else if (choice == 2) {
            string id;
            bool found = false;
            cout << "Enter Aadhar Number to delete: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (citizens[i].aadharNumber == id) {
                    for (int j = i; j < count - 1; j++) {
                        citizens[j] = citizens[j + 1];
                    }
                    count--;
                    found = true;
                    cout << "Deleted successfully.\n";
                    break;
                }
            }
            if (!found) cout << "Citizen not found.\n";
        }

        else if (choice == 3) {
            string id;
            bool found = false;
            cout << "Enter Aadhar Number to update: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (citizens[i].aadharNumber == id) {
                    cout << "Updating citizen data:\n";
                    citizens[i].input();
                    found = true;
                    cout << "Updated successfully.\n";
                    break;
                }
            }
            if (!found) cout << "Citizen not found.\n";
        }

        else if (choice == 4) {
            string id;
            bool found = false;
            cout << "Enter Aadhar Number to search: ";
            cin >> id;
            for (int i = 0; i < count; i++) {
                if (citizens[i].aadharNumber == id) {
                    cout << "\n--- Citizen Found ---\n";
                    citizens[i].display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Citizen not found.\n";
        }

        else if (choice == 5) {
            if (count == 0) {
                cout << "No records found.\n";
            } else {
                cout << "\n--- All Citizen Records ---\n";
                for (int i = 0; i < count; i++) {
                    cout << i + 1 << ". ";
                    citizens[i].display();
                }
            }
        }

    } while (choice != 6);

    cout << "Exiting Aadhar Management System...\n";
    return 0;
}

