// Challenge 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Checks if the input has any alphabetical characters
bool hasAlphabeticCharacters(string text)
{
    for (char c : text)
    {
        if (isalpha(static_cast<unsigned char>(c)))
        {
            return true;
        }
    }

    return false;
}

// Converts the string to uppercase
string convertToUppercase(string text)
{
    for (char& c : text)
    {
        c = toupper(static_cast<unsigned char>(c));
    }

    return text;
}

// Converts the string to lowercase
string convertToLowercase(string text)
{
    for (char& c : text)
    {
        c = tolower(static_cast<unsigned char>(c));
    }

    return text;
}

// Convert the string to sentence case
string convertToSentenceCase(string text)
{
    // Converts everything to lowercase
    text = convertToLowercase(text);

    bool capitaliseNext = true;

    for (char& c : text)
    {
        if (isalpha(static_cast<unsigned char>(c)))
        {
            if (capitaliseNext)
            {
                c = toupper(static_cast<unsigned char>(c));
                capitaliseNext = false;
            }
        }

        // Check for punctuation and add capitalisation to the next letter
        if (c == '.' || c == '!' || c == '?')
        {
            capitaliseNext = true;
        }
    }

    return text;
}

// Convert the string to alternating case
string convertToAlternatingCase(string text)
{
    bool uppercaseNext = false;

    for (char& c : text)
    {
        if (isalpha(static_cast<unsigned char>(c)))
        {
            if (uppercaseNext)
            {
                c = toupper(static_cast<unsigned char>(c));
            }
            else
            {
                c = tolower(static_cast<unsigned char>(c));
            }

            uppercaseNext = !uppercaseNext;
        }
    }

    return text;
}

int main()
{
    string inputText;

    // Gets the input from the user
    cout << "Enter some text: ";
    getline(cin, inputText);

    // Checks if the input contains alphabetical characters
    if (!hasAlphabeticCharacters(inputText))
    {
        cout << "\n[!] ERROR: Can't run text casing, "
            << "there are no alphabetical characters in input string.\n";

        return 0;
    }

    // Display all four conversions
    cout << "\nUppercase => "
        << convertToUppercase(inputText) << endl;

    cout << "Lowercase => "
        << convertToLowercase(inputText) << endl;

    cout << "Sentence casing => "
        << convertToSentenceCase(inputText) << endl;

    cout << "Alternate casing => "
        << convertToAlternatingCase(inputText) << endl;

    return 0;
}


