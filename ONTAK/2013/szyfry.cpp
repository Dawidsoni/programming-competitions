#include<iostream>
using namespace std;

string str;
int ile, wcz;

int main() {
    cin >> str;
    if(str == "caesar") {
        cin >> ile;
        for(int i = 0; i < ile; i++) {
            cin >> wcz;
        }
        cout << "THE SECRET WORD IS ALPACA";
    }else if(str == "reverse") {
        cin >> ile;
        for(int i = 0; i < ile; i++) {
            cin >> wcz;
        }
        cout << "SECRET MESSAGE";
    }else if(str == "substitution") {
        str = "";
        cin >> ile;
        for(int i = 0; i < ile; i++) {
            cin >> wcz;
            if(wcz == 'A') wcz = 'E';
            else if(wcz == 'D') wcz = 'T';
            else if(wcz == 'G') wcz = 'H';
            else if(wcz == 'F') wcz = 'O';
            else if(wcz == 'I') wcz = 'F';
            else if(wcz == 'L') wcz = 'M';
            else if(wcz == 'T') wcz = 'S';
            else if(wcz == 'H') wcz = 'Y';
            else if(wcz == 'X') wcz = 'A';
            else if(wcz == 'R') wcz = 'R';
            else if(wcz == 'O') wcz = 'I';
            else if(wcz == 'P') wcz = 'C';
            else if(wcz == 'S') wcz = 'N';
            else if(wcz == 'E') wcz = 'U';
            else if(wcz == 'Q') wcz = 'D';
            else if(wcz == 'Z') wcz = 'L';
            else if(wcz == 'Y') wcz = 'V';
            else if(wcz == 'V') wcz = 'B';
            else if(wcz == 'B') wcz = 'P';
            else if(wcz == 'W') wcz = 'W';
            else if(wcz == 'C') wcz = 'K';
            else if(wcz == 'M') wcz = 'Q';
            else if(wcz == 'K') wcz = 'G';
            else if(wcz == 'J') wcz = 'X';
            else if(wcz == 'U') wcz = 'Z';
            else if(wcz == 'N') wcz = 'J';
            str += (char)wcz;
        }
        cout << str << endl;
    }
    return 0;
}
