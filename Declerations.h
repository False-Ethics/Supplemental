#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <cstddef>
using namespace std;

class myString
{
private:
	char* Data;
	int length;

public:
    myString();
    myString(const char* pleaseWork);
    myString(const myString& copy);
    ~myString();                           
public:
    size_t Length() const;
    char& CharacterAt(size_t index);
    const char& CharacterAt(size_t index) const;
    bool EqualTo(const myString& other) const;
    myString& Append(const myString& str);
    myString& Prepend(const myString& str);
    const char* CStr() const;
    myString& ToLower();
    myString& ToUpper();
    size_t Find(const myString& str);
    size_t Find(size_t startIndex, const myString& str);
    myString& Replace(const myString& findStr, const myString& replaceStr);
    myString& ReadFromConsole();
    myString& WriteToConsole();
public:
    bool operator==(const myString& other);
    bool operator!=(const myString& other);
    myString& operator=(const myString& str);
    char& operator[](size_t index);
    const char& operator[](size_t index) const;
    bool operator<(const myString& other) const;
    myString operator+(const myString& other) const;
    myString& operator+=(const myString& other);
};


