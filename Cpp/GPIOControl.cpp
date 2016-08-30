#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
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
        SetGPIONumber(GPIONumber);
        SetGPIODirection(GPIODirection);
    }

    GPIOControl::~GPIOControl()
    {
        UnexportGPIOPin();
    }

    void GPIOControl::SetOutValue(bool GPIOutValue){
        //TODO: Return integer to confirm value is set
        std::stringstream ValuePathSS;
        string ValuePath;
        string OutValueStr;

        OutValue = GPIOutValue;

        if (GPIOutValue == true){
            OutValueStr = "1";
        } else {
            OutValueStr = "0";
        }

        ValuePathSS << "/sys/class/gpio/gpio" << Number << "/value";
        ValuePath = ValuePathSS.str();
        //cout << "Changing value of pin: " << Number << eDirectionPathndl;
        // TODO: Should we close the file reader or leave it open for the duration of the pins use?
        // Adding to that, we can also store the path rather than building it each time
        ofstream valueFile;
        valueFile.open(ValuePath.c_str());
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
        // TODO: Check if pin is already exported
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
        std::stringstream DirectionPathSS;
        string DirectionPath;

        if (GPIODirection != "out") {
            GPIODirection = "in";
        }
        Direction = GPIODirection;

        // HACK: This string manipluation could possibly be made quicker
        DirectionPathSS << "/sys/class/gpio/gpio" << Number << "/direction";
        DirectionPath = DirectionPathSS.str();

        cout << "Setting pin " << " direction: " << GPIODirection << endl;
        cout << DirectionPath << endl;
        ofstream directionFile;
        directionFile.open(DirectionPath.c_str());
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
        usleep(1000000);
    }
