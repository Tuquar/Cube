#include <iostream>
#include "GPIOControl.h"

using namespace std;

int PinArray [12] = {15, 16, 18, 29, 31, 32, 33, 35, 36, 37, 38, 40};
GPIOControl GPIOPinArray [12];

int main()
{
    cout << "Hello World! :)" << endl;

    for (int count = 0; count < (sizeof PinArray / sizeof PinArray[0]); count++){
        GPIOPinArray[count].SetGPIONumber(PinArray[count]);
        GPIOPinArray[count].SetGPIODirection("out");

        cout << GPIOPinArray[count].GetGPIONumber() << " C-" << count << endl << endl;
        usleep(1000000);
    }

    return 0;
};
