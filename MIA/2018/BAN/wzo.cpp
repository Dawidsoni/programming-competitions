#include <iostream>
#include <stack>
using namespace std;

typedef long long int LType;
const int MAX_SIZE = 1100000;

LType nTest;
LType nEvent, checkoutCash;
LType event;
stack<int> envStack;
stack<int> minStack;

void handlePayout(LType amount) {
    if(envStack.empty()) {
        checkoutCash -= amount;
    }else if(amount < minStack.top()) {
        checkoutCash -= amount;
    }else {
        while(envStack.size() > 0 && amount > 0) {
            amount -= envStack.top();
            if(minStack.top() == envStack.top()) {
                minStack.pop();
            }
            envStack.pop();
        }
        checkoutCash -= amount;
    }
}

void handlePayin(LType amount) {
    if(minStack.empty() || minStack.top() >= amount) {
        minStack.push(amount);
    }
    envStack.push(amount);
}

void handleEvent(LType event) {
    if(event < 0) {
        handlePayout(-event);
    }else {
        handlePayin(event);
    }
}

void printResult() {
    LType envCash = 0;
    while(envStack.empty() == false) {
        envCash += envStack.top();
        envStack.pop();
    }
    while(minStack.empty() == false) {
        minStack.pop();
    }
    cout << checkoutCash << " " << envCash << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> nTest;
    for(LType i = 0; i < nTest; i++) {
        cin >> nEvent >> checkoutCash;
        for(LType j = 0; j < nEvent; j++) {
            cin >> event;
            handleEvent(event);
        }
        printResult();
    }
    return 0;
}
