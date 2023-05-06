#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

struct employeeData
{
    public:
    string FirstName;
    vector <long> key;
    vector <long> lock;
};

int main()
{
    employeeData person;
    ifstream inputFile;
    inputFile.open("EmployeesEncryptionKeys.bin", ios::binary);
    if(inputFile.is_open())
    {
        inputFile.read(reinterpret_cast<char*>(&person), sizeof(employeeData));
        inputFile.close();
    }
    else
        cout<<"Error"<<endl;
    
    cout<<person.lock[0]<<endl;
    cout<<person.lock[1]<<endl;

    ifstream encryptedFile;
    encryptedFile.open("encryptedFile.txt", ios::binary);
    char line[30];
    encryptedFile.read(line, sizeof(long));
    cout<<line<<endl; 

    return 0;
}
