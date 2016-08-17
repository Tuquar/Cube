#ifndef GPIOControl_h
#define GPIOControl_h

class GPIOControl
{
private:
    int Number;
    string Direction;
    string IOStatus;
public:
    GPIOControl();
    GPIOControl(int GPIONumber, string GPIOdirection);
    ~GPIOControl();
    int GetGPIONumber();
    void SetGPIONumber(int GPIONumber);

    string GetIOStatus();
    void SetIOStatus(string OneOrZero);

};


#endif
