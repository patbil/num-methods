
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

int counter;
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

// function calculating coefficients (Gaussian elimination)
void calculate(int degree){
    cout.precision(4);
    vector<double> X(2*degree+1, 0);
    vector<double> Y(degree+1, 0);
    vector<vector<double>> matrix(degree+1, vector<double>(degree+2, 0));
    vector<double> coefficients(degree+1, 0);
    
    for (int i=0;i<2*degree+1;i++){
        X[i]=0;
        for (int j=0; j<counter; j++){
            X[i]=X[i]+pow(dataStruct[j].x,i);
        }
    }
    
    for (int i=0; i<=degree; i++){
        for(int j=0; j<=degree; j++){
            matrix[i][j]=X[i+j];
        }
    }
    
    for(int i=0;i<degree+1;i++){
        Y[i]=0;
        for (int j=0;j<counter;j++){
            Y[i]=Y[i]+pow(dataStruct[j].x,i)*dataStruct[j].y;
        }
    }
    
    for (int i=0; i<=degree; i++) matrix[i][degree+1] = Y[i];
    degree=degree+1;
    
    for (int i=0; i<degree; i++){
        for(int k=i+1;k<degree;k++){
            if (matrix[i][i]<matrix[k][i]){
                for (int j=0;j<=degree;j++){
                    double buf = matrix[i][j];
                    matrix[i][j] = matrix[k][j];
                    matrix[k][j] = buf;
                }
            }
        }
    }
    
    for (int i=0; i<degree - 1; i++){
        for (int k=i+1;k<degree;k++){
            double s = matrix[k][i] / matrix[i][i];
            for (int j=0; j<=degree; j++){
                matrix[k][j] = matrix[k][j]- s * matrix[i][j];
            }
        }
    }
    
    for (int i = degree-1; i>=0; i--){
        coefficients[i]=matrix[i][degree];
        for (int j=0;j<degree;j++)
        if (j != i)
            coefficients[i] = coefficients[i] - matrix[i][j] * coefficients[j];
            coefficients[i] = coefficients[i] / matrix[i][i];
    }
    cout << endl;
    cout << "The sought coefficients are: " << endl;

    for (int i=0; i<degree; i++){
        cout<<"x^"<<i<<" = "<<coefficients[i]<<endl;
    }
    
    cout << endl;
    cout << "The sought approximating function is:\nF(x) = ";
    for (int i=0; i<degree; i++){
        cout<<" + ("<<coefficients[i]<<")"<<"x^"<<i;
    }
    cout << endl;
}

// main function
int main(int argc, char * argv[]){
    int degree = 0;
    cout << "Enter polynomial degree (max:5): ";
    cin >> degree;
    if (degree > 5){
        cout << "Given degree is too large. Try again: ";
        cin >> degree;
    }
    if(loadData() == true){
        cout<<"i:"<<setw(8)<<"X:"<<setw(15)<<"Y: "<<setw(20)<<endl;
        cout<<"------------------------------------\n";
        for (int k = 0; k < counter ; k++){
                cout<<k+1<<"."<<setw(8)<<dataStruct[k].x<<setw(15)<<dataStruct[k].y<<endl;
        }
        calculate(degree);
    } else {
        cout << "Failed to load dataStruct. Check path to txt file."<< endl;
    }
    return 0;
}
