#include <iostream>
#include <string>
using namespace std;

const int max_spec=20;
const int max_queue=5;

string names[max_spec+1][max_queue];
int status[max_spec+1][max_queue];
int queue_length[max_spec+1];

bool is_text(string input) {
    if (input.empty()) return false;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (!((c >= 'A' && c <= 'Z') ||
            (c >= 'a' && c <= 'z') ||
            c == ' ')) {
            return false;
        }
    }

    return true;
}



bool is_number(string input) {
    if (input.empty()) return false;

    for (int i = 0; i < input.length(); i++) {
        char c = input[i];

        if (c < '0' || c > '9') {
            return false;
        }
    }

    return true;
}


bool valid(int choice) {
    return (choice >= 1 && choice <= 4);
}

int menu() {
    int choice;

    while (true) {
        cout << "Enter Your Choice\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";
        cout << ">> ";

        cin >> choice;

        
        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number between 1 and 4.\n\n";
            continue;
        }

        if (!valid(choice)) {
            cout << "Invalid choice. Please try again.\n\n";
            continue;
        }

        break; 
    }

    return choice;
}

void shift_rhight(int spec,string names_sp[],int status_sp[]){
    int len =queue_length[spec];
    for(int i = len-1;i >= 0;--i){
        names_sp[i+1]=names_sp[i];
        status_sp[i+1]=status_sp[i];
    }
    queue_length[spec]++;
}
void shift_left(int spec,string names_sp[],int status_sp[]){
    int len =queue_length[spec];
    for(int i = 1;i< len;++i){
        names_sp[i-1]=names_sp[i];
        status_sp[i-1]=status_sp[i];
    }
    queue_length[spec]--;
}
bool add_patient(){
    int spec;
    int st;
    string name;
    
    while (true) {

        string spcialization;
        cout << "Enter spcialization:\n\n";
        cin >> spcialization;
        if (is_number(spcialization)) {
            spec = stoi(spcialization);
            break;
        }
        else {
            cout << "invaild spcialization, please try again.\n\n";
        }
    }
    while (true) {

        string Name;
        cout << "Enter Name:\n\n";
        cin >> Name;
        if (is_text(Name)) {
            name = Name;
            break;
        }
        else {
            cout << "invaild Name, please try again.\n\n";
        }
    }
    while (true) {

        string statis;
        cout << "statis(0 for regular // 1 for urgent):\n";
        cin >> statis;
        if (is_number(statis)) {
            st = stoi(statis);
            if (st == 0 || st == 1) {
                break; // true
            }
            else {
                cout << "only allowed 0 or 1.\n";
            }
        }
        else {
            cout << "invaild statis, please try again.\n";
        }
    }
     
    int position=queue_length[spec];
    if(position>=max_queue){
        cout<<"sorry we can't add more patient for this specialization \n";
return false;
    }
    if(st==0){                          //regular put in the end
        names[spec][position]=name;
        status[spec][position]=st;
        queue_length[spec]++;
    }
    else{                              //urgent put in the up
        shift_rhight(spec,names[spec],status[spec]);
        names[spec][0]=name;
        status[spec][0]=st;
    }
return true;
}

void print_patient(int spec,string names_sp[],int status_sp[]){
        int len = queue_length[spec];
    if (len==0){
        return;
    }
    cout<<"there are "<<len<<" patient in specialization "<<spec<<" \n";

    for(int i=0;i<len;++i){
        cout<<names_sp[i]<<" ";
        if(status_sp[i]==1){
            cout<<"urgent\n";
        }
        else{
            cout<<"regular\n";
        }
        cout<<"\n";
    }
}
void print_patients(){

    cout<<"**********************************\n";
    for(int spec=0;spec<max_spec;++spec){
         print_patient(spec, names[spec], status[spec]);
    }

}
void get_next_patient(){
int spec;
while (true) {

    string spcialization;
    cout << "Enter spcialization";
    cin >> spcialization;
    if (is_number(spcialization)) {
        spec = stoi(spcialization);
        break;
    }
    else {
        cout << "invaild spcialization, please try again.";
    }
}
int len =queue_length[spec];
if (len==0){
    return;
}
   cout<<names[spec][0]<<" please go with the DR \n";

    shift_left(spec,names[spec],status[spec]);
}
void sys_hospital(){
while(true){
int choise = menu();

if(choise==1){
    add_patient();
}
else if(choise==2){
    print_patients();
}
else if(choise==3){
    get_next_patient();
}
else{
break;
}
}
}

int main() {
    sys_hospital();
  return 0;
}
