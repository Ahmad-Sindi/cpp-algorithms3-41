#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
 * Algorithm Challenge – Level 3 | #41 Reverse Words in a String
 *
 * This program reads a full line of text from the user and reverses the order of its words (not characters).
 *
 * Example:
 * Input : "Hassan Abdullah Makkah"
 * Output: "Makkah Abdullah Hassan"
 *
 * The solution demonstrates:
 * - String manipulation
 * - Splitting strings into words
 * - Using vectors and iterators
 * - Reverse traversal of containers
 * - Clean and modular C++ design
 */

// Reads a full line of text from the user
string ReadString()
{
    string S1;
    cout << "Enter String:\n";
    getline(cin, S1);
    return S1;
}

// Splits a string into words based on a delimiter
vector<string> SplitString(string S1, string Delim)
{
    vector<string> vString;
    short Pos = 0;
    string Word;

    // Loop until no delimiter is found
    while ((Pos = S1.find(Delim)) != string::npos)
    {
        Word = S1.substr(0, Pos);

        // Avoid pushing empty strings
        if (Word != "")
        {
            vString.push_back(Word);
        }

        // Remove processed word from the string
        S1.erase(0, Pos + Delim.length());
    }

    // Add the last remaining word
    if (S1 != "")
    {
        vString.push_back(S1);
    }

    return vString;
}

// Reverses the order of words in a given string
string ReverseWordsInString(string S1)
{
    vector<string> vString;
    string Result = "";

    // Split the string into individual words
    vString = SplitString(S1, " ");

    // Iterator pointing to the end of the vector
    vector<string>::iterator Iter = vString.end();

    // Traverse the vector backwards
    while (Iter != vString.begin())
    {
        --Iter;
        Result += *Iter + " ";
    }

    // Remove the trailing space
    Result = Result.substr(0, Result.length() - 1);

    return Result;
}

int main()
{
    string S1 = ReadString();

    cout << "\nString After Reversing Words:\n";
    cout << ReverseWordsInString(S1);

    return 0;
}
