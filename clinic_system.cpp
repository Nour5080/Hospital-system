#include <iostream>
#include <string>
#include <limits>
using namespace std;

const int max_spec = 20;
const int max_queue = 5;

string names[max_spec + 1][max_queue];
int status[max_spec + 1][max_queue];
int queue_length[max_spec + 1] = {};

bool is_text(string input) {
    if (input.empty()) return false;
    for (char c : input)
        if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || c == ' '))
            return false;
    return true;
}

bool is_number(string input) {
    if (input.empty()) return false;
    for (char c : input)
        if (c < '0' || c > '9')
            return false;
    return true;
}

int read_number(const string& msg) {
    string input;
    while (true) {
        cout << msg;
        getline(cin, input);
        if (is_number(input)) return stoi(input);
        cout << "Invalid input. Please enter a number.\n";
    }
}

string read_text(const string& msg) {
    string input;
    while (true) {
        cout << msg;
        getline(cin, input);
        if (is_text(input)) return input;
        cout << "Invalid input. Please use letters only.\n";
    }
}

void shift_right(int spec) {
    int len = queue_length[spec];
    for (int i = len - 1; i >= 0; --i) {
        names[spec][i + 1] = names[spec][i];
        status[spec][i + 1] = status[spec][i];
    }
    queue_length[spec]++;
}

void shift_left(int spec) {
    int len = queue_length[spec];
    for (int i = 1; i < len; ++i) {
        names[spec][i - 1] = names[spec][i];
        status[spec][i - 1] = status[spec][i];
    }
    queue_length[spec]--;
}

bool add_patient() {
    int spec = read_number("Enter specialization (0 - 20): ");
    if (spec < 0 || spec > max_spec) {
        cout << "Invalid specialization number.\n";
        return false;
    }

    string name = read_text("Enter patient name: ");

    int st;
    while (true) {
        st = read_number("Status (0 = regular, 1 = urgent): ");
        if (st == 0 || st == 1) break;
        cout << "Only 0 or 1 allowed.\n";
    }

    int pos = queue_length[spec];
    if (pos >= max_queue) {
        cout << "Sorry, can't add more patients for this specialization.\n";
        return false;
    }

    if (st == 0) {
        names[spec][pos] = name;
        status[spec][pos] = st;
        queue_length[spec]++;
    } else {
        shift_right(spec);
        names[spec][0] = name;
        status[spec][0] = st;
    }
    return true;
}

void print_patient(int spec) {
    int len = queue_length[spec];
    if (len == 0) return;
    cout << "There are " << len << " patients in specialization " << spec << ":\n";
    for (int i = 0; i < len; ++i) {
        cout << names[spec][i] << " - " << (status[spec][i] == 1 ? "urgent" : "regular") << "\n";
    }
}

void print_patients() {
    cout << "\n************ All Patients ************\n";
    for (int spec = 0; spec < max_spec; ++spec) {
        print_patient(spec);
    }
    cout << "**************************************\n";
}

void get_next_patient() {
    int spec = read_number("Enter specialization to process: ");
    if (queue_length[spec] == 0) {
        cout << "No patients in this specialization.\n";
        return;
    }
    cout << names[spec][0] << ", please go with the doctor.\n";
    shift_left(spec);
}

int menu() {
    string input;
    while (true) {
        cout << "\nHospital Menu:\n"
             << "1) Add new patient\n"
             << "2) Print all patients\n"
             << "3) Get next patient\n"
             << "4) Exit\n"
             << "Enter your choice: ";
        getline(cin, input);
        if (is_number(input)) {
            int choice = stoi(input);
            if (choice >= 1 && choice <= 4) return choice;
        }
        cout << "Invalid choice. Try again.\n";
    }
}

void hospital_system() {
    while (true) {
        int choice = menu();
        if (choice == 1) add_patient();
        else if (choice == 2) print_patients();
        else if (choice == 3) get_next_patient();
        else break;
    }
}

int main() {
    hospital_system();
    return 0;
}
