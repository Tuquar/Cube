#include <fstream>
#include <iostream>
#include "GPIOControl.h"

//using namespace Cube;
using namespace std;
//using namespace GPIO;

    // TODO clean up control variables
    int Number;
    string Direction;
    bool OutValue;

    GPIOControl::GPIOControl(){
        SetGPIONumber(0);
    }

    GPIOControl::GPIOControl(int GPIONumber, string GPIODirection)
    {
        SetGPIODirection(GPIODirection);
        SetGPIONumber(GPIONumber);
    }

    GPIOControl::~GPIOControl()
    {
        UnexportGPIOPin();
    }

    void GPIOControl::SetOutValue(bool GPIOutValue){
        //TODO: Doesn't do anything, needs to edit files
        OutValue = GPIOutValue;
        string OutValueStr;

        if (GPIOutValue == true){
            OutValueStr = "1";
        } else {
            OutValueStr = "0";
        }

        //cout << "Changing value of pin: " << Number << endl;
        // TODO: Should we close the file reader or leave it open for the duration of the pins use?
        ofstream valueFile;
        valueFile.open("/sys/class/gpio/gpio" << Number << "/value");
        valueFile << OutValueStr;
        valueFile.close();
        cout << "Pin " << Number << " changed to " << OutValueStr << endl;
    }
    bool GPIOControl::GetOutValue(){
        return OutValue;
    }

    void GPIOControl::SetGPIONumber(int GPIONumber){
        Number = GPIONumber;
        // TODO: Better checks needed here? If the number is changed part way through the program what will happen?
        if (GPIONumber > 0){
            cout << "Exporting pin: " << Number << endl;
            ofstream exportFile;
            exportFile.open("/sys/class/gpio/export");
            exportFile << Number;
            exportFile.close();
            cout << "Pin " << Number << " Exported!" << endl;
        }
    }
    int GPIOControl::GetGPIONumber(){
        return Number;
    }

    void GPIOControl::SetGPIODirection(string GPIODirection){
        if (GPIODirection != "out") {
            GPIODirection = "in";
        }
        Direction = GPIODirection;

        cout << "Setting pin " << " direction: " << GPIODirection << endl;
        ofstream directionFile;
        directionFile.open("/sys/class/gpio/gpio" << Number << "/direction");
        directionFile << GPIODirection;
        directionFile.close();
        cout << "Direction of pin " << Number << " set to " << GPIODirection << endl;
    }
    string GPIOControl::GetGPIOdirection(){
        return Direction;
    }

    void GPIOControl::UnexportGPIOPin(){
        cout << "Unexporting pin: " << Number << endl;
        ofstream unexportFile;
        unexportFile.open("/sys/class/gpio/unexport");
        unexportFile << Number;
        unexportFile.close();
        cout << "Pin " << Number << " Unexported!" << endl;

    }
