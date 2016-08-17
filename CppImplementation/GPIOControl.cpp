#include <fstream>
#include <iostream>
#include "GPIOControl.h"

//using namespace Cube;
using namespace std;

    int Number;
    string Direction;
    string IOStatus;

    GPIOControl::GPIOControl(){
        Number = 0;
    }

    GPIOControl::GPIOControl(int GPIONumber, string GPIOdirection)
    {
        if (GPIOdirection != "out") {
            GPIOdirection = "in";
        }

        //Set pin for this class instance
        SetGPIONumber(GPIONumber);
        Direction = GPIOdirection;



        cout << "Setting pin " << " direction: " << Direction << endl;
        ofstream directionFile;
        directionFile.open("/sys/class/gpio/gpio" << Number << "/direction");
        directionFile << Direction;
        directionFile.close();
        cout << "Direction of pin " << Number << " set to " << Direction << endl;
    }

    GPIOControl::~GPIOControl()
    {
        cout << "Unexporting pin: " << Number << endl;
        ofstream unexportFile;
        unexportFile.open("/sys/class/gpio/unexport");
        unexportFile << Number;
        unexportFile.close();
        cout << "Pin " << Number << " Unexported!" << endl;


    }

    void GPIOControl::SetOutStatus(string OneOrZero){
        //TODO: Doesn't do anything, needs to edit files
        if (OneOrZero != "1"){
            IOStatus = "0"
        } else {
            IOStatus = "1"
        }
    }

    string GPIOControl::GetOutStatus(){
        return IOStatus;
    }

    int GPIOControl::GetGPIONumber(){
        return Number;
    }

    void GPIOControl::SetGPIONumber(int GPIONumber){
        // TODO: doesn't actually change anything, needs to update files
        Number = GPIONumber;

        cout << "Exporting pin: " << Number << endl;
        ofstream exportFile;
        exportFile.open("/sys/class/gpio/export");
        exportFile << Number;
        exportFile.close();
        cout << "Pin " << Number << " Exported!" << endl;
    }
