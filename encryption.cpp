#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

string encrypt(string str);
vector <long> getlock(string name);
struct employeeData
{
    public:
    string FirstName;
    vector <long> key;
    vector <long> lock;
};

int main()
{
    unsigned seed = time(0);
    ifstream InputFile;
    ofstream FinalFile;
    string sentence;
    srand(seed);

    InputFile.open("test.txt");
    FinalFile.open("encryptedFile.txt", ios::app);

    while(getline(InputFile, sentence))
    {
        FinalFile << encrypt(sentence)<<'\n';
    }
    FinalFile.close();
    InputFile.close();
    return 0;
}
int makePrime(int val)
{
    for(int i = 2; i<=9; i++)
    {
        if(val%i == 0)
        {
            val++;
            i = 1;
        }
    }
    return val;
}
void removeFactor(long target, vector <long> &values)
{
    for(int i = 0; i<values.size(); i++)
    {
        if(values[i]%target == 0)
            values.erase(values.begin()+i);
    }
}
long findVal(vector <long> values, long phiN, long N)
{
    if(phiN%values[0] == 0 && N%values[0] == 0)
    {
        removeFactor(values[0], values);
        return findVal(values, phiN, N);
    }
    else
        return values[0];
}

employeeData createKeyandLock()
{
    employeeData person;
    long p = rand()%20000;
    long q = rand()%20000;
     p = makePrime(p);
     q = makePrime(q);
    long N = p*q;
    long phiN = (p-1)*(q-1);
    vector <long> possibleValues;
    for(int i = 2; i<phiN; i++)
        possibleValues.push_back(i);
    long lockval = findVal(possibleValues, phiN, N);
    int cycle = 2;
    long keyval = cycle*phiN - 1;
    person.key.push_back(keyval);
    person.key.push_back(N);
    person.lock.push_back(lockval);
    person.lock.push_back(N);
    ofstream output;
    output.open("EmployeeEncyptionsKeys.bin", ios::binary);
    if(output.is_open())
    {
        output.write(reinterpret_cast<char *> (&person), sizeof(employeeData));
        output.close();
    }
    return person;
}
string encrypt(string str)
{
    employeeData peter = createKeyandLock();
    long keyval = peter.key[0];
    long N = peter.key[1];
    string newstr = "";
    for(int i = 0; i< str.size(); i++)
    {
        long ch = static_cast<long>(pow(static_cast<long>(str[i]), peter.key[0])) % peter.key[1];
        newstr += to_string(ch);
    }
    return newstr;
}
