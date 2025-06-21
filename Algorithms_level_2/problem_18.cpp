#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string ReadText(string massage)
{
    string text;
    cout << massage;
    cin >> text;
    return text;
}

string Encryption(string text)
{
    for (int i = 0; i < text.length(); i++)
    {
        text[i] = char(text[i] + 2);
        
    }
    return text;
}

string Decryption(string text)
{
    string Encrypted = "";
    for (int i = 0; i < text.length(); i++)
    {
        char letter = text[i] - 2;
        Encrypted += letter;
    }
    return Encrypted;
}

int main()
{
    string text = ReadText("Please enter text to Encryption: ");

    cout << "Text After Encryption : " << Encryption(text) << endl;
    cout << "Text After Decryption : " << Decryption(Encryption(text)) << endl;
    return 0;
};
