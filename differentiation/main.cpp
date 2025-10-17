#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

#define MAX 100

using namespace std;

int counter, foundIndex;
double searchedValue, step, table[MAX][MAX];
struct DataStruct{
    float x;
    float y;
};

vector <DataStruct> dataStruct;
DataStruct element;

bool loadData(){
    string text;
    
    fstream file; // "pointer" to file
    stringstream buffer;
    file.open("test.txt", ios::in);
    
    while(!file.eof()){
        file >> text; buffer << text; buffer >> element.x;
        buffer.str("");
        buffer.clear();
        
        file >> text; buffer << text; buffer >> element.y;
        buffer.str("");
        buffer.clear();
        counter++;
        
        dataStruct.push_back(element);
    }
    searchedValue = dataStruct[counter-1].x;
    step = dataStruct[1].x - dataStruct[0].x;
    for (int i = 0; i < counter - 1; i++){
        table[i][0] = dataStruct[i].y;
    }
    return true;
}

void backwardDifferencesTable() {
    double sum = 0;
    cout << setprecision(3);
    double a = 1;
    for (int i = 1; i < counter - 1; i++) {
            for (int j = 0; j < counter - i; j++)
                table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    for (int i = 1; i < counter - 1; i++) {
            for (int j = counter - 2; j >= i; j--)
                table[j][i] = table[j][i - 1] - table[j - 1][i - 1];
        }
    cout << "X" << setw(10) << "Y" << setw(10) << "∇1" << setw(10) << "∇2" << setw(10) << "∇3" << setw(10) << "∇4" << setw(14) << "ETC." << endl;
    cout << "------------------------------------------------------------" << endl;
        for (int i = 0; i < counter - 1; i++) {
            cout << setw(4) << dataStruct[i].x << "\t";
            for (int j = 0; j <= i; j++)
                cout << setw(4) << table[i][j]<< "\t";
            cout << endl;
        }
    for (int i = 0; i < counter - 1; i++){
        if (dataStruct[i].x == searchedValue){
            foundIndex = i;
        }
    }
    for (int i = 0; i < foundIndex; i++){
        sum = sum + (a/(i+1) * table[foundIndex][i+1]);
    }
    cout << endl;
    cout << "Result: " << sum * (1/step);
}

void forwardDifferencesTable() {
    double sum = 0;
    int size = counter - 1;
    cout << setprecision(3);
    double a = 1;
    for (int i = 1; i < counter - 1; i++) {
            for (int j = 0; j < counter - i; j++)
                table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    cout << "X" << setw(10) << "Y" << setw(10) << "Δ1" << setw(10) << "Δ2" << setw(8) << "Δ3" << setw(10) << "Δ4" << setw(14) << "ETC." << endl;
    cout << "------------------------------------------------------------" << endl;
    for (int i = 0; i < counter - 1; i++) {
        cout << setw(4) << dataStruct[i].x << "\t";
        for (int j = 0; j < size - i; j++)
            cout << setw(4) << table[i][j]<< "\t";
        cout << endl;
    }
    
    for (int i = 0; i < counter - 1; i++){
        if (dataStruct[i].x == searchedValue){
            foundIndex = i;
        }
    }
    for (int i = 0; i < 3; i++){
        if (i == 1){
            sum = sum - (a/(i+1) * table[foundIndex][i+1]);
        } else {
        sum = sum + (a/(i+1) * table[foundIndex][i+1]);
        }
    }
    cout << endl;
    cout << "Result: " << sum * (1/step);
}

int main(int argc, const char * argv[]) {
    if (loadData()== false){
        cout << "Error loading dataStruct, check file path." <<endl;
        exit(0);
    } else {
        int choice;
    
        for(;;){
            cout << "MAIN MENU" << endl;
            cout << "--------------------------------------"<<endl;
            cout << "1 - Forward differences method"<< endl;
            cout << "2 - Backward differences method"<< endl;
            cout << "3 - Exit program"<< endl;
            cout << endl;
            cout << "Choose calculation method: ";
            cin >> choice;
            
            switch(choice){
                case 1:
                    cout << endl;
                    cout << "FORWARD DIFFERENCES METHOD" << endl;
                    forwardDifferencesTable();
                    break;
                case 2:
                    cout << endl;
                    cout << "BACKWARD DIFFERENCES METHOD" << endl;
                    backwardDifferencesTable();
                    break;
                case 3:
                    cout << "End of program";
                    exit(0);
                    break;
                default: cout << "No such option." << endl;
            }
            getchar(); getchar();
            system("clear");
        }
    }
    return 0;
}
