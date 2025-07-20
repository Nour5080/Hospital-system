#include <iostream>
using namespace std;

const int max_spec=20;
const int max_queue=5;

string names[max_spec+1][max_queue];
int status[max_spec+1][max_queue];
int queue_length[max_spec+1];

int menu () {
    int choise;
    choise = -1;
    while (choise == -1) {
        cout << "Enter Your Choise\n";
        cout << "1) Add new patient\n";
        cout << "2) Print all patients\n";
        cout << "3) Get next patient\n";
        cout << "4) Exit\n";
        cin >> choise;

    if(!(choise>=1&&choise<5)){
        cout<<"invalid choice. TRY again\n";
        choise=-1;                                                                                      //keep loop
    }
}
return choise;

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
    cout<<"Enter spcialization, name, statis(0 for regular // 1 for urgent):\n";
    cin>>spec>>name>>st;
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
cout<<"enter specialization\n";
cin>>spec;
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
