#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
#include "Declerations.h"
using namespace std;

//--------------------------------------------------------

myString::myString() {
    Data = new char[1]; 
    Data[0] = '\0';    
    length = 0;
    //cout << "default.. Nothing to see here..." << endl;
}
myString::myString(const char* pleaseWork)
{
    if (pleaseWork == nullptr) {
        Data = new char[1];
        Data[0] = '\0';
        length = 0;
    }
    else
    {
        length = 0;
        while (pleaseWork[length] != '\0') {
            length++;
        }
        Data = new char[length + 1];
        for (int i = 0; i < length; i++) {
            Data[i] = pleaseWork[i];
        }
        Data[length] = '\0';
    }
    //cout << "String Created" << endl;
}
myString::myString(const myString& copy)
{
    length = copy.length;
    Data = new char[length + 1];
    for (int i = 0; i < length; i++) {
        Data[i] = copy.Data[i];
    }
    Data[length] = '\0'; 
        //cout << "Copy called" << endl;
}
myString::~myString()
{
    //oops almost forgot
    delete[]Data;
    Data = nullptr;
    //cout << "Data gone?" << endl;
};

//--------------------------------------------------------

size_t myString::Length() const
{
    return length;
}
char& myString::CharacterAt(size_t index)
{
    char willitwork = '\0'; //bruh almost made this static
    if (index >= length) {
        cout << "ERROR! ERROR! ERROR!" << endl;
        return willitwork;
    }
    return Data[index];
}
const char& myString::CharacterAt(size_t index) const
{
    char willitwork = '\0'; 
    if (index >= length) {
        cout << "ERROR! ERROR! ERROR!" << endl;
        return willitwork;
    }
    return Data[index];
}
bool myString::EqualTo(const myString& equaltest) const
{
    if (length != equaltest.length){
        return false;
    }
    for (int i = 0; i < length; i++) {
        if (Data[i] != equaltest.Data[i]) {
            return false;
        }
    }
        return true;
}
myString& myString::Append(const myString& newer) 
{
    int updatedLength = length + newer.length;
    char* newData = new char[updatedLength + 1];

    for (int i = 0; i < length; i++) {
        newData[i] = Data[i];
    }
    for (int i = 0; i < newer.length; i++) {
        newData[length + i] = newer.Data[i]; //idk bro, flagged but works.
    }
    newData[updatedLength] = '\0';
    delete[]Data;
    Data = newData;
    length = updatedLength;
    return *this; 
}
myString& myString::Prepend(const myString& newer)
{
    int updatedLength = length + newer.length;
    char* newData = new char[updatedLength + 1];

    for (int i = 0; i < newer.length; i++) {
        newData[length + i] = newer.Data[i];
    }

    for (int i = 0; i < length; i++) {
        newData[i] = Data[i];
    }
    newData[updatedLength] = '\0';
    delete[]Data;
    Data = newData;
    length = updatedLength;
    return *this;
}
const char* myString::CStr() const
{
    return Data;
}
myString& myString::ToLower()
{
    for (int i = 0; i < length; i++) {
        if (Data[i] >= 'A' && Data[i] <= 'Z') {
            Data[i] = Data[i] + 32;
        }
  }
    return *this;
}
myString& myString::ToUpper()
{
    for (int i = 0; i < length; i++) {
        if (Data[i] >= 'a' && Data[i] <= 'z') {
            Data[i] = Data[i] - 32;
        }
    }
     return *this;
}
size_t myString::Find(const myString& finder)
    {
        if (finder.length == 0 || finder.length > length) {
            return -1;
        }
        for (int i = 0; i <= length - finder.length; i++) {
            int u = 0;
            while (u < finder.length && Data[i + u] == finder.Data[u]) { u++; }
            if (u == finder.length) {
                return i;
            }
            return -1;
        }
    }
size_t myString::Find(size_t startIndex, const myString& finder)
{
    if (finder.length == 0 || finder.length > length) {
        return(size_t)-1; //poggers
    }
    for (size_t i = startIndex; i <= length - finder.length; i++) {
        size_t u = 0;
        while (u < finder.length && Data[i + u] == finder.Data[u]) { u++; } 
        if (u == finder.length) { //scope bruh, remember
            return i;
        }
    }
}
myString& myString::Replace(const myString& findStr, const myString& replaceStr)
{
    size_t position = Find(findStr);
    if (position == (size_t)-1) {
        return*this;
    }
    int newLength = length - findStr.length + replaceStr.length;
    char* newData = new char[newLength + 1];
    for (int i = 0; i < position; i++) {
        newData[i] = Data[i];
    }
    for (int i = 0; i < replaceStr.length; i++) {
        newData[position + 1] = replaceStr.Data[i];
    }
    for (int i = position + findStr.length; i < length; i++) {
        newData[i - findStr.length + replaceStr.length] = Data[i];
    }
    newData[newLength] = '\0';

   
    delete[]Data;
    Data = newData;
    length = newLength;
    return*this;
}
myString& myString::ReadFromConsole()
{
    char input[20];
    cin >> input;
    length = 0;
    while (input[length] != '\0') {length++;}
    delete[] Data;
    Data = new char[length + 1];
    for (int i = 0; i < length; i++) {
        Data[i] = input[i];
        }
    Data[length] = '\0';
    return *this;
}
myString& myString::WriteToConsole()
{
    cout << Data << endl;
    return *this;
}

//--------------------------------------------------------

bool myString::operator==(const myString& other)
{
    return EqualTo(other);
}
bool myString::operator!=(const myString& other)
{
    return !EqualTo(other);
}
myString& myString::operator=(const myString& other)
{
    if (Data == other.Data) {
        return *this;
   }
    delete[] Data;
    length = other.length;
    Data = new char[length + 1];
    for (int i = 0; i < length; i++) {
        Data[i] = other.Data[i];
    }
    Data[length] = '\0';
    return *this;
}
inline bool myString::operator<(const myString& other) const
{
    int lengthLess;
    if (length < other.length) {
        lengthLess = length;
    } 
    else {
        lengthLess = other.length;
    }

    for (int i = 0; i < lengthLess; i++) {
        Data[i] < other.Data[i]; {
            return true;
        }
        if (Data[i] > other.Data[i]) { return false; }
    }

    if (length < other.length) {
        return true;
    }
    else {
        return false;
    }
}
myString myString::operator+(const myString& other) const
{
    int newLength = length + other.length;
    char* newData = new char[newLength + 1];
    for (int i = 0; i < length; i++) {
        newData[i] = Data[i];
    }
    for (int i = 0; i < other.length;i++) {
        newData[length + i] = other.Data[i];
    }
    newData[length] = '\0';
    myString result(newData);
    delete[] newData;
        return result;
}
myString& myString::operator+=(const myString& other)
{
    int newLength = length + other.length;
    char* newData = new char[newLength + 1];
    
    for (int i = 0; i < length; i++) {
        newData[i] = Data[i];
    }
    for (int i = 0; i < other.length; i++) {
        newData[length + i] = other.Data[i];
    }
    newData[newLength] = '\0';
    delete[] Data;
    Data = newData;
    length = newLength;
    return *this;
}

//--------------------------------------------------------


