#include<iostream>
#include<fstream>
#include<sstream>
#include<cstring>
using namespace std;

void writetofile(){
    ofstream file;
    if (!file)
    {
        cerr<<"error"<<endl;
    }
    
    file.open("sensor_log.txt",ios::out);
    file << "sensor1:"<< "25.5c"<<endl;
    cout << "Position after Sensor1 write: " << file.tellp() << endl;

    file<<endl;
    file << "sensor2:"<< "98.1RH"<<endl;
    cout << "Position after Sensor2 write: " << file.tellp() << endl;

    file.close();
}

int main ()
{
    writetofile();
    return 0;
}