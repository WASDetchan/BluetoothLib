// Библиотека для приёма и передачи сигнала по Bluetooth (HC-05, HC-06)

#ifndef bluetooth_h
#define bluetooth_h

class Bluetooth{
private:
    byte _rx_pin, _tx_pin;
    int _symbol_count = 0, _strLen = 32;
    char inputChar = 0, _outStr[32] = {};
    Vector<char[32]> _outline = {};
    bool _isAvailable = false;
    SoftwareSerial BTSerial = SoftwareSerial(0, 0);
    enum ParsingObject {
        STRING,
        INT,
        NOTHING,
    };
    ParsingObject parsing = NOTHING;

public:
    Bluetooth(byte rx_pin, byte tx_pin);

    void BluetoothParseString(char terminator);

    bool BluetoothParseLine(char separator, char terminator);

    void getStr(char* outStr);

    bool IsStringAvailable() const;

    bool WaitForConnection (const char startWord[], char terminator);
};

#endif