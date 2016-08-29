#ifndef GPIOControl_h
#define GPIOControl_h

using namespace std;
//namespace GPIO;

class GPIOControl
{
    private:
        int Number;
        std::string Direction;
        bool OutValue;
    public:
        GPIOControl();
        GPIOControl(int GPIONumber, std::string GPIODirection);
        ~GPIOControl();

        void SetOutValue(bool GPIOutValue);
        bool GetOutValue();

        void SetGPIONumber(int GPIONumber);
        int GetGPIONumber();

        void SetGPIODirection(std::string GPIODirection);
        std::string GetGPIOdirection();

        void UnexportGPIOPin();
};


#endif
