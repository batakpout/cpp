#include<iostream>
using namespace std;

//convert '4' to d
char integerCharToAlphabet(char c) {
   int chv =  c - '0'; // i.e char --> int; if c = '4' means it is 52 and '0' is 48, so 52-48 = 4
 // char temp = 'a' + c; --> 97 + 52 = 149  which is non-printable or invalid in ASCII, and may appear as empty or garbage in cout.
   char code = (char)'a' + chv - 1; // 'a' is 97 + 4 - 1 = 100 --> d
   return code;
}

int stringToInteger(string str) {
    return stoi(str);
}

int integerToAlphabet(int digit) {
    return (char)'a' + digit - 1;
}

//find its time and space complexity?
void printEncoding(string input, string asf) {
    if(input.size() == 0) {
        cout << asf << endl;
        return;
    } else if(input.size() == 1) {
        char c = input[0];
        if(c == '0') return;
        else {
            char current = integerCharToAlphabet(c);
            cout << asf + current << endl;
        }
    } else {
        char c = input[0];
        if(c == '0') return;
        else {
            char current = integerCharToAlphabet(c);
            printEncoding(input.substr(1), asf + current);
        }
        string firstTwoChars = input.substr(0,2);
        int firstTwoInt = stringToInteger(firstTwoChars);
        if(firstTwoInt <= 26) {
            char current = integerToAlphabet(firstTwoInt);
            printEncoding(input.substr(2), asf + current);
        }
    }

}




int main() {
        cout << "enter digit string: ";
        string s; cin >> s;
        printEncoding(s, "");

    return 0;
}