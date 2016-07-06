#include<iostream>
using namespace std;

string dodaj(string licz1, string licz2) {
    string wynik = "";
    int ileDodac = 0;
    for(int i = licz1.size() - 1, j = licz2.size() - 1, licz = 0; i >= 0 || j >= 0; i--, j--, licz++) {
        int cyfr1 = i < 0 ? 0 : (licz1[i] - '0');
        int cyfr2 = j < 0 ? 0 : (licz2[j] - '0');
        int wyn = cyfr1 + cyfr2 + ileDodac;
        if(wyn >= 10) {
            wyn -= 10;
            ileDodac = 1;
        }else {
            ileDodac = 0;
        }
        wynik += (wyn + '0');
    }
    if(ileDodac) wynik += "1";
    string odwrWynik = "";
    for(int i = wynik.size() - 1; i >= 0; i--) {
        odwrWynik += wynik[i];
    }
    return odwrWynik == "" ? "0" : odwrWynik;
}


string odejmij(string licz1, string licz2) {
    string wynik = "";
    int ileOdjac = 0;
    for(int i = licz1.size() - 1, j = licz2.size() - 1, licz = 0; i >= 0 || j >= 0; i--, j--, licz++) {
        int cyfr1 = i < 0 ? 0 : (licz1[i] - '0');
        int cyfr2 = j < 0 ? 0 : (licz2[j] - '0');
        int wyn = cyfr1 - cyfr2 - ileOdjac;
        if(wyn < 0) {
            wyn = 10 + wyn;
            ileOdjac = 1;
        }else {
            ileOdjac = 0;
        }
        wynik += (wyn + '0');
    }
    string odwrWynik = "";
    bool czyZero = true;
    for(int i = wynik.size() - 1; i >= 0; i--) {
        if(wynik[i] != '0') czyZero = false;
        if(czyZero == false) odwrWynik += wynik[i];
    }
    return odwrWynik == "" ? "0" : odwrWynik;
}

bool czyWiekszy(string licz1, string licz2) {
    if(licz1.size() != licz2.size()) return licz1.size() > licz2.size();
    for(int i = 0; i < licz1.size(); i++) {
        if(licz1[i] != licz2[i]) {
            return licz1[i] > licz2[i];
        }
    }
    return false;
}

string ile, licz1, licz2;

bool czyRowny(string licz1, string licz2) {
    return (czyWiekszy(licz1, licz2) == false && czyWiekszy(licz2, licz1) == false);
}

string x2(string licz) {
    int ileDodac = 0;
    string wynik = "";
    for(int i = licz.size() - 1; i >= 0; i--) {
        int cyfr = ((licz[i] - '0') * 2) + ileDodac;
        if(cyfr >= 10) {
            cyfr -= 10;
            ileDodac = 1;
        }else {
            ileDodac = 0;
        }
        wynik += (cyfr + '0');
    }
    if(ileDodac) wynik += "1";
    string odwrWynik = "";
    for(int i = wynik.size() - 1; i >= 0; i--) {
        odwrWynik += wynik[i];
    }
    return odwrWynik == "" ? "0" : odwrWynik;
}

string reszta(string licz1, string licz2) {
    string tab[50000];
    int i = 1;
    tab[0] = licz2;
    for(;;i++) {
        string wyn = x2(tab[i - 1]);
        if(czyWiekszy(wyn, licz1)) break;
        tab[i] = wyn;
    }
    string wynik = licz1;
    for(;i >= 0; i--) {
        if(czyWiekszy(wynik, tab[i])) {
            wynik = odejmij(wynik, tab[i]);
        }
    }
    return (wynik == licz2) ? "0" : wynik;
}

string nwd(string licz1, string licz2) {
   while(licz1 != "0" && licz2 != "0") {
        if(czyWiekszy(licz1, licz2)) {
            licz1 = reszta(licz1, licz2);
        }else {
            licz2 = reszta(licz2, licz1);
        }
   }
   return (licz1 == "0") ? licz2 : licz1;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin >> ile >> licz1 >> licz2;
    string wynNwd = nwd(licz1, licz2);
    if(czyWiekszy(odejmij(dodaj(licz1, licz2), wynNwd), ile)) {
        cout << (odejmij(dodaj(licz1, licz2), ile));
    }else {
        cout << wynNwd;
    }
    return 0;
}
