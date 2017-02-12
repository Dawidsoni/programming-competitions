#include <iostream>
using namespace std;

string text1, text2;
string sub1, sub2;
int pref, suf;
int pArr[2100000];

string getExceptStar(string text) {
  return text.erase(text.find("*"), 1);
}

bool checkPrefix() {
  while(text1[pref] == text2[pref] && text1[pref] && text1[pref] != '*' && text2[pref] != '*') {
    pref++;
  }
  return (text1[pref] == '*' || text2[pref] == '*');
}

bool checkSuffix() {
  int size1 = text1.size() - 1;
  int size2 = text2.size() - 1;
  while(text1[size1 - suf] == text2[size2 - suf] && text1[size1 - suf] != '*' && text2[size2 - suf] != '*') {
    suf++;
  }
  return (text1[size1 - suf] == '*' || text2[size2 - suf] == '*');
}

void countSub() {
  sub1 = text1;
  sub2 = text2;
  sub1.erase(0, pref);
  sub2.erase(0, pref);
  sub1.erase(sub1.size() - suf);
  sub2.erase(sub2.size() - suf);
}

int getOverlapInd() {
  string text = sub2 + "#" + sub1;
  int ind = 0;
  for(int i = 1; i < (int)text.size(); i++) {
    while(ind > 0 && text[i] != text[ind]) {
        ind = pArr[ind - 1];
    }
    if(text[i] == text[ind]) {
        ind++;
    }
    pArr[i] = ind;
  }
  return sub1.size() - pArr[text.size() - 1];
}

string countOverlap() {
  if(sub1[0] == '*') {
    swap(sub1, sub2);
  }
  sub1.erase(sub1.size() - 1);
  sub2.erase(0, 1);
  int ovInd = getOverlapInd();
  return sub1.substr(0, ovInd);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin >> text1 >> text2;
  if(text1.size() == 1) {
    cout << getExceptStar(text2) << "\n";
    return 0;
  }else if(text2.size() == 1) {
    cout << getExceptStar(text1) << "\n";
    return 0;
  }else if(checkPrefix() == false || checkSuffix() == false) {
    cout << "impossible\n";
    return 0;
  }
  countSub();
  if(sub1.size() == 1) {
    cout << getExceptStar(text2) << "\n";
    return 0;
  }else if(sub2.size() == 1) {
    cout << getExceptStar(text1) << "\n";
    return 0;
  }
  string overlap = countOverlap();
  if(text1.find("*") < text2.find("*")) {
    int ind = text1.find("*");
    cout << text1.replace(ind, 1, overlap) << "\n";
  }else {
    int ind = text2.find("*");
    cout << text2.replace(ind, 1, overlap) << "\n";
  }
  return 0;
}
