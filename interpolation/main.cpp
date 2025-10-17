
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const int MAX = 20; 
const double COMPARE = 0.0000000001; 

int counter;
double matrix[MAX][MAX+1];
double coefficients[MAX];
struct DataStruct{
    float x;
    float y;
};
vector <DataStruct> dataStruct;
DataStruct element;

bool loadData(){
    string text;
    
    fstream file; // file pointer
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
    return true;
}

// Gaussian elimination function
bool eliminateX(){
    double a;
    for(int i = 0; i < counter - 1; i++){
        if (fabs(matrix[i][i] < COMPARE)) return false;
        for(int j = i + 1; j < counter; j++){
            a = -matrix[j][i]/matrix[i][i];
            for(int k = i + 1; k <= counter; k++) matrix[j][k] += a * matrix[i][k];
        }
    }
    return true;
}

// Function calculating polynomial coefficients
bool calculateCoefficients(){
    double sum;
    for (int i = counter-1; i >= 0; i--){
        if(fabs(matrix[i][i]) < COMPARE) return false;
        sum = matrix[i][counter];
        for(int j = counter-1; j > i; j--) sum -= matrix[i][j] * coefficients[j];
            coefficients[i] = sum/matrix[i][i];
    }
    return true;
}

int main( int argc, char * argv[] ){
    cout.precision(5);
    cout.setf(ios::fixed);
    if (loadData()==true){
        for(int i = 0; i < counter; i++)
        for(int j = 0; j < counter+1; j++){
            matrix[i][j] = pow(dataStruct[i].x, j);
            if(j == counter) matrix[i][j] = dataStruct[i].y;
        }
        if(eliminateX() && calculateCoefficients()){
            cout << coefficients[0];
            for(int a = 1; a < counter; a++){
                if(coefficients[a] >= 0) cout << " + ";
                else cout << " ";
                cout << coefficients[a] << "*x^"<< a;
            }
            cout << ";" << endl;
        }
    } else {
        cout << "Failed to load dataStruct"<<endl;
    }
    return 0;
}



