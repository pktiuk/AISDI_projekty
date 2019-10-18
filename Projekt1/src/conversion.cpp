#include <conversion.hpp>

string letters[]={".,","-...","-.-.","-..",".","..-.","--.","....", "..", ".---", "-.-", ".-..","--","-.","---", ".--.","--.-", ".-.", "...", "-", "..-","...-",".--","-..-","-.--","--.."};

void printMorse(string& words)
{
    cout<<"Morse:\n";
    int size=words.length();
    for(int i=0;i<size;i++)
    {
        cout<<"/"<<letters[words[i]-'A'];
    }

}