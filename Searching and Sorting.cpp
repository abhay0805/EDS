#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Student {
public:
    int roll;
    string name;
    float Sgpa;
    string dept;
};

//=========== DISPLAY FUNCTIONS ===========
void Display(Student S[15]) {
    cout << "Name\t\tRollno\tSgpa\tDepartment" << endl;
    for (int i = 0; i < 15; i++) {
        cout << S[i].name << "\t\t" << S[i].roll << "\t" << S[i].Sgpa << "\t" << S[i].dept << endl;
    }
}

void DisplayDataset(Student S[15]) {
    cout << "\n=========== ORIGINAL DATASET ===========\n";
    cout << "Name\t\tRollno\tSgpa\tDepartment" << endl;
    for (int i = 0; i < 15; i++) {
        cout << S[i].name << "\t\t" << S[i].roll << "\t" << S[i].Sgpa << "\t" << S[i].dept << endl;
    }
    cout << "========================================\n";
}

//=========== SORTING FUNCTIONS ===========
void BubleSort(Student S[15]) {
    for (int i = 0; i < 15 - 1; i++) {
        for (int j = 0; j < 15 - i - 1; j++) {
            if (S[j].roll > S[j + 1].roll) {
                swap(S[j], S[j + 1]);
            }
        }
    }
}

void InsertionSort(Student S[15]) {
    for (int i = 1; i < 15; i++) {
        Student curr = S[i];
        int prev = i - 1;
        while (prev >= 0 && S[prev].name > curr.name) {
            S[prev + 1] = S[prev];
            prev--;
        }
        S[prev + 1] = curr;
    }
}

// Quick Sort (by SGPA)
int Partition(Student S[15], int low, int high) {
    float pivot = S[high].Sgpa;
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (S[j].Sgpa < pivot) {
            i++;
            swap(S[i], S[j]);
        }
    }
    swap(S[i + 1], S[high]);
    return (i + 1);
}

void QuickSort(Student S[15], int low, int high) {
    if (low < high) {
        int pi = Partition(S, low, high);
        QuickSort(S, low, pi - 1);
        QuickSort(S, pi + 1, high);
    }
}

//=========== SEARCHING FUNCTIONS ===========
void LinearSearch(Student S[15], float target) {
    cout << "\nStudents with SGPA " << target << " are:\n";
    bool found = false;
    for (int i = 0; i < 15; i++) {
        if (S[i].Sgpa == target) {
            cout << S[i].name << "\t\t" << S[i].roll << "\t" << S[i].Sgpa << "\t" << S[i].dept << endl;
            found = true;
        }
    }
    if (!found) cout << "No student found with SGPA " << target << endl;
}

void BinarySearch(Student S[15], string target) {
    int low = 0, high = 14;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (S[mid].name == target) {
            cout << "\nStudent Found:\n";
            cout << S[mid].name << "\t" << S[mid].roll << "\t" << S[mid].Sgpa << "\t" << S[mid].dept << endl;
            return;
        } else if (S[mid].name < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "\nStudent with name '" << target << "' not found.\n";
}

int FibbSearch(Student S[15], string target) {
    int offset = -1;
    int Fm1 = 1, Fm2 = 0, Fm = Fm1 + Fm2;
    while (Fm < 15) {
        Fm2 = Fm1;
        Fm1 = Fm;
        Fm = Fm2 + Fm1;
    }

    while (Fm > 1) {
        int i = min(offset + Fm2, 15 - 1);
        if (S[i].name < target) {
            Fm = Fm1;
            Fm1 = Fm2;
            Fm2 = Fm - Fm1;
            offset = i;
        } else if (S[i].name > target) {
            Fm = Fm2;
            Fm1 = Fm1 - Fm2;
            Fm2 = Fm - Fm1;
        } else {
            return i;
        }
    }
    if (Fm1 && offset + 1 < 15 && S[offset + 1].name == target)
        return offset + 1;

    return -1;
}

//=========== MAIN ===========
int main() {
    Student S[15] = {
        {101, "Aarav", 8.9, "Computer"},
        {102, "Diya", 9.1, "IT"},
        {103, "Kabir", 7.8, "Mechanical"},
        {104, "Isha", 9.5, "Computer"},
        {105, "Rohan", 8.7, "Civil"},
        {106, "Mira", 8.2, "IT"},
        {107, "Vihaan", 9.4, "Computer"},
        {108, "Sara", 7.5, "ENTC"},
        {109, "Aditya", 8.6, "Mechanical"},
        {110, "Tanya", 9.0, "IT"},
        {111, "Arnav", 8.3, "Civil"},
        {112, "Kriti", 9.6, "Computer"},
        {113, "Reyansh", 7.9, "ENTC"},
        {114, "Anaya", 8.4, "IT"},
        {115, "Yash", 9.2, "Computer"}
    };

    int mainChoice;

    do {
        cout << "\n==================== MAIN MENU ====================\n";
        cout << "1. Display Original Dataset\n";
        cout << "2. Sorting Menu\n";
        cout << "3. Searching Menu\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> mainChoice;

        switch (mainChoice) {
        case 1:
            DisplayDataset(S);
            break;

        case 2: {
            int sortChoice;
            cout << "\n====== SORTING MENU ======\n";
            cout << "1. Bubble Sort (By Roll No)\n";
            cout << "2. Insertion Sort (By Name)\n";
            cout << "3. Quick Sort (By SGPA)\n";
            cout << "Enter your choice: ";
            cin >> sortChoice;

            switch (sortChoice) {
            case 1:
                BubleSort(S);
                cout << "\nSorted by Roll No (Bubble Sort):\n";
                Display(S);
                break;

            case 2:
                InsertionSort(S);
                cout << "\nSorted by Name (Insertion Sort):\n";
                Display(S);
                break;

            case 3:
                QuickSort(S, 0, 14);
                cout << "\nSorted by SGPA (Quick Sort):\n";
                Display(S);
                break;

            default:
                cout << "Invalid Sorting Option!\n";
            }
            break;
        }

        case 3: {
            int searchChoice;
            cout << "\n====== SEARCHING MENU ======\n";
            cout << "1. Linear Search by SGPA\n";
            cout << "2. Binary Search by Name\n";
            cout << "3. Fibonacci Search (Check Dept)\n";
            cout << "Enter your choice: ";
            cin >> searchChoice;

            switch (searchChoice) {
            case 1: {
                float sgpaKey;
                cout << "\nEnter SGPA to search: ";
                cin >> sgpaKey;
                LinearSearch(S, sgpaKey);
                break;
            }

            case 2: {
                string target;
                cout << "\nEnter name to search: ";
                cin >> target;
                InsertionSort(S); // ensure sorted for binary search
                BinarySearch(S, target);
                break;
            }

            case 3: {
                string target;
                cout << "\nEnter name to check department: ";
                cin >> target;
                InsertionSort(S);
                int index = FibbSearch(S, target);
                if (index != -1) {
                    cout << "\nStudent found:\n";
                    cout << S[index].name << "\t" << S[index].roll << "\t" << S[index].Sgpa << "\t" << S[index].dept << endl;
                    if (S[index].dept == "Computer")
                        cout << S[index].name << " belongs to the Computer Department.\n";
                    else
                        cout << S[index].name << " does NOT belong to the Computer Department.\n";
                } else {
                    cout << "\nStudent not found!\n";
                }
                break;
            }

            default:
                cout << "Invalid Searching Option!\n";
            }
            break;
        }

        case 4:
            cout << "\nExiting Program...\n";
            break;

        default:
            cout << "\nInvalid Main Menu Option!\n";
        }

    } while (mainChoice != 4);

    return 0;
}

