#include <Arduino.h>
#include <SoftwareSerial.h>
#include <Vector.h>
#include "BluetoothLib.h"

Bluetooth::Bluetooth(byte rx_pin, byte tx_pin) {
    _rx_pin = rx_pin;
    _tx_pin = tx_pin;
    BTSerial = SoftwareSerial(rx_pin, tx_pin);
}

void Bluetooth::BluetoothParseString(const char terminator) {
    parsing = STRING;
    if (BTSerial.available()){
        inputChar = (char)BTSerial.read();
        if (inputChar == terminator || _symbol_count == 32) {
            parsing = NOTHING;
            _isAvailable = true;
            _symbol_count = 0;
        }
        else{
            _outStr[_symbol_count] = inputChar;
            _symbol_count++;
        }
    }
}

void Bluetooth::getStr(char* outStr){
    strcpy(outStr, _outStr);
    _isAvailable = false;
}

bool Bluetooth::IsStringAvailable() const{
    return _isAvailable;
}

bool Bluetooth::BluetoothParseLine(const char separator, const char terminator){
    BluetoothParseString(terminator);
    char str[]
    if (IsStringAvailable()){

    }
}

bool Bluetooth::WaitForConnection(const char* startWord, const char terminator) {
    unsigned int len = strchr(startWord, '\0') - startWord;
    char str[len];
    BluetoothParseString(terminator);
    if (IsStringAvailable()){
        getStr(str);
        for (int i = 0; i < sizeof(startWord); i++){
            if (startWord[i] != str[i]){
                return false;
            }
        }
        return true;
    }
}
