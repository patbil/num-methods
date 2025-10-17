#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>

using namespace std;

int counter;
float step = 0.5;
double resultUnderestimate, resultOverestimate, resultTrapezoid, resultSimpson;
struct DataStruct{
    float x;
    float y;
};
vector <DataStruct> dataStruct;
DataStruct dataPoint;

bool loadData(){
    string text;
    
    fstream file;
    stringstream buffer;
    file.open("test.txt", ios::in);
    
    while(!file.eof()){
        file >> text; buffer << text; buffer >> dataPoint.x;
        buffer.str("");
        buffer.clear();

        file >> text; buffer << text; buffer >> dataPoint.y;
        buffer.str("");
        buffer.clear();
        counter++;
        
        dataStruct.push_back(dataPoint);
    }
    return true;
}

double calculateUnderestimate(){
    resultUnderestimate = 0;
        for(int i = 0; i < counter - 1; i++)
            resultUnderestimate += dataStruct[i].y;
        return (step * resultUnderestimate);
}

double calculateOverestimate(){
    resultOverestimate = 0;
        for(int i = 1; i < counter; i++)
            resultOverestimate += dataStruct[i].y;
        return (step * resultOverestimate);
}

double trapezoidMethod(){
    resultTrapezoid = 0;
        for(int i = 1; i < counter - 1; i++)
            resultTrapezoid += dataStruct[i].y;
        return ((step*(((dataStruct[0].y + dataStruct[counter-1].y) / 2) + resultTrapezoid)));
}

double simpsonMethod(){
    resultSimpson = 0;
    for(int i = 1 ; i < counter - 1; i++){
        if(i % 2 == 0) {
            resultSimpson += (dataStruct[i].y * 2);
        } else {
            resultSimpson += (dataStruct[i].y * 4);
        }
    }
    return (step / 3 * (dataStruct[0].y + dataStruct[counter-1].y + resultSimpson));
}


int main(int argc, const char * argv[]) {
    if (loadData()== false){
        cout << "Error loading dataStruct, check path." <<endl;
        exit(0);
    }
        
        double underestimateResult = calculateUnderestimate();
        double overestimateResult = calculateOverestimate();
        double trapezoidResult = trapezoidMethod();
        double simpsonResult = simpsonMethod();
        int choice;
        
        for(;;){
            cout << "MAIN MENU" << endl;
            cout << "--------------------------------------"<<endl;
            cout << "1 - Rectangle method with underestimate"<< endl;
            cout << "2 - Rectangle method with overestimate"<< endl;
            cout << "3 - Trapezoid method"<< endl;
            cout << "4 - Simpson's method"<< endl;
            cout << "5 - End program"<< endl;
            cout << endl;
            cout << "Choose calculation method: ";
            cin >> choice;
            
            switch(choice){
                case 1:
                    cout << "Result: " << underestimateResult <<endl;
                    break;
                case 2:
                    cout << "Result: " << overestimateResult <<endl;
                    break;
                case 3:
                    cout << "Result: " << trapezoidResult <<endl;
                    break;
                case 4:
                    cout << "Result: " << simpsonResult <<endl;
                    break;
                case 5:
                    cout << "End of program";
                    exit(0);
                    break;
                default: cout << "No such option." << endl;
            }
            getchar();
            system("clear");
        }
    return 0;
}
