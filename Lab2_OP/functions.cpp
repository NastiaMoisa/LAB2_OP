#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
#include "functions.h"
Breaks break_time, temp;

int get_hours_from_time(const char* time_str) {
    string temp_str(time_str, 2);
    int hours = stoi(temp_str);
    return hours;
}

int get_mins_from_time(const char* time_str) {
    string temp_str(&time_str[strlen(time_str) - 2], 2);
    int mins = stoi(temp_str);
    return mins;
}

bool check(Breaks breaks_info[], Breaks new_time, int size, string filename){
    ifstream file(filename, ios::binary);
    if(!file) {
        cout << "Error opening a file..." << endl;
        exit(1);
    }

    if (size > 0 &&
        strcmp(breaks_info[0].start_time, new_time.start_time) == 0 &&
        strcmp(breaks_info[0].finish_time, new_time.finish_time) == 0) {
        //cout << "The first element of the array is equal to the new break" << endl;
    } else {
        for (int i = 0; i < size; i++) {

            int prev_start_hours = get_hours_from_time(breaks_info[i].start_time);
            int prev_start_mins = get_mins_from_time(breaks_info[i].start_time);
            int prev_finish_hours = get_hours_from_time(breaks_info[i].finish_time);
            int prev_finish_mins = get_mins_from_time(breaks_info[i].finish_time);

            int new_start_hours = get_hours_from_time(new_time.start_time);
            int new_start_mins = get_mins_from_time(new_time.start_time);
            int new_finish_hours = get_hours_from_time(new_time.finish_time);
            int new_finish_mins = get_mins_from_time(new_time.finish_time);

            if (size > 0 && strcmp(breaks_info[i].start_time, new_time.start_time) == 0 &&
                strcmp(breaks_info[i].finish_time, new_time.finish_time) == 0){
                break;
            } else {
                if ((new_start_hours * 60 + new_start_mins <= prev_finish_hours * 60 + prev_finish_mins) &&
                    (new_finish_hours * 60 + new_finish_mins >= prev_start_hours * 60 + prev_start_mins)) {
                    cout << "The new break overlaps with a previously entered break" << endl;
                    return true;
                }
            }
        }
    }

    file.close();
    return false;
}


void createFile(string filename){
    int c, n, size  = 10;
    fstream file(filename, ios::app | ios:: binary);

    if(!file) {
        cout << "Error opening a file..." << endl;
        exit(1);
    }

    auto *breaks_info = new Breaks[size];
    do{
        n = enterNum("number of breaks (max_num = 10)");

        for (int i = 0; i < n; i++) {
            temp = getData(break_time);

            breaks_info[i] = temp;

            if(check(breaks_info, temp, size, filename)){
                cout << "There is an overlap with the previously recorded breaks. Please try again." << endl;
                i--;
            } else {
                break_time = temp;
                file.write((char *) &break_time, sizeof(Breaks));
                cout << "Break time is written in the file" << endl;
                displayData(break_time);
            }
        }
        cout << "\nDo you want to add info?\n1 - yes\n2 - no" << endl;
        cin >> c;
        cin.ignore();
    }while( c == 1 );

   delete[] breaks_info;
   file.close();
}


Breaks getData(Breaks item) {
        cout << "Enter start_time:";
        cin.getline(item.start_time, 6);
        cout << "Enter finish_time:";
        cin.getline(item.finish_time, 6);
   return item;
}

void displayData(Breaks item) {
    cout << "\nDisplaying Information:" << endl;
    cout << "start_time: " << item.start_time << endl;
    cout <<"finish_time: " << item.finish_time << endl << endl;
}


void readFile(string filename){
    int  i = 0;
    ifstream file(filename, ios::in | ios::binary);
    if(!file) {
        cout << "Error reading a file...\n";
        exit(1);
    }

    cout << "\nFile's contents. List of Breaks:" << endl;
    while(file.read((char *) &break_time, sizeof(Breaks))){
        i++;
        cout << i << ") "<< break_time.start_time << " - " << break_time.finish_time << endl;
    }
    file.close();
}

int enterNum(string text){
    int n;
    cout << "\nEnter " << text << ":";
    cin >> n;
    cin.ignore();
    return n;
}


bool checkUp(int num_of_clients, int work_time, int minsPerClient = 15){
    bool flag;

    int clients_time = num_of_clients * minsPerClient;
//    cout << "CheckUp:\n";
//    cout << "\tclients_time = " << clients_time << endl;
//    cout << "\twork_time = " << work_time << endl;

    if (work_time >= clients_time){
          return flag = true;
    } else return flag = false;
}


void fullCheckUp(string filename){
    int i = 0;
    ifstream file(filename, ios::in | ios::binary);

    if(!file) {
        cout << "Error reading a file...\n";
        exit(1);
    }

    int num_of_clients = enterNum("number of clients");

    cout << "\nCash-desk will be able to serve all clients between breaks\n1 - True, 0 - False | (Time starts at 00:00):" << endl;

    const int midnight = 0;
    int work_time = 0;
    int prev_finish_time_sum = midnight;        // added variable for previous finish time

    while(file.read((char *) &break_time, sizeof(Breaks))){
        i++;
        bool flag;
        int break_duration = 0;

        int start_time_hours = get_hours_from_time(break_time.start_time);
        int finish_time_hours = get_hours_from_time(break_time.finish_time);
//        cout << "\tstart_time_hours = " << start_time_hours << endl;
//        cout << "\tfinish_time_hours = " << finish_time_hours << endl;

        int start_time_mins = get_mins_from_time(break_time.start_time);
        int finish_time_mins = get_mins_from_time(break_time.finish_time);
//        cout << "\tstart_time_mins = " << start_time_mins << endl;
//        cout << "\tfinish_time_mins = " << finish_time_mins << endl;

        int start_time_sum = start_time_hours * 60 + start_time_mins;
        int finish_time_sum = finish_time_hours * 60 + finish_time_mins;
//        cout << "\tstart_time_sum = " << start_time_sum << endl;
//        cout << "\tfinish_time_sum = " << finish_time_sum << endl;

        break_duration += finish_time_sum - start_time_sum;
//        cout << "\tbreak_duration = " << break_duration << endl;

        work_time = start_time_sum - prev_finish_time_sum;
//        cout << "\twork_time = " << work_time << endl;

        flag = checkUp(num_of_clients, work_time);

        cout << i << ") "<< break_time.start_time << " - " << break_time.finish_time << " --> " << flag << endl;

        prev_finish_time_sum = finish_time_sum;         // updating previous finish time
    }

    file.close();
}



