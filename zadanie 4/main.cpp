// Lukasz Bobinski numer indeksu 159651

#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
//#include <iomanip>

using namespace std;

double pole_trapez(double, double, double); //oblicza pole trapezu z zad.1
double wartosc_funkcji(double); // wartosc funkcji w punkcie x zad.2
string coinToss();
bool trojkat(double, double, double); // sprawdzi, czy jest mozliwe utworzenie trojkata zad4
double poleTrojkata(double, double, double); //obliczy pole trojkata zad4

int main()
{
    char poz_menu, wybor;
    do {
        cout << "Wybierz prosze jedna z opcji programu:" << endl;
        cout << "1 - Wykonuje zadanie nr.1(pole powierzchni trapezu)" << endl;
        cout << "2 - Wykonuje zadanie nr.2(wartosc funkcji w punkcie)" << endl;
        cout << "3 - Wykonuje zadanie nr.3(coin toss)" << endl;
        cout << "4 - Wykonuje zadanie nr.4(trojkat)" << endl;
        cout << "q - Konczy dzialanie programu\n" << endl;
        cin >> poz_menu;

        switch (poz_menu){
            case '1' : {
                double a, b, h, pole_pow;
                wybor = 't';
                do {
                cout << endl;
                cout << "Zadanie 1. Oblicze pole trapezu.\n";
                cout << "Podaj prosze wymiary podstaw a i b oraz wysokosc h trapezu(w cm):\n";
                cout << "a: ";
                cin >> a;
                while (a <= 0) {
                    cout << "Wprowadz prosze liczbe wieksza od zera: ";
                    cin >> a;
                }
                cout << "b: ";
                cin >> b;
                while (b <= 0) {
                    cout << "Wprowadz prosze liczbe wieksza od zera: ";
                    cin >> b;
                }
                cout << "h: ";
                cin >> h;
                while (h <= 0) {
                    cout <<"Wprowadz prosze liczbe wieksza od zera: ";
                    cin >>h;
                }
                pole_pow = pole_trapez (a,  b, h);
                cout << "Pole powierzchni trapezu o podanych wymiarach wynosi: "<<pole_pow<<"cm2"<<endl;
                cout << "Czy chcesz powtorzyc obliczenia? (t/n):";
                cin >> wybor;
                } while (wybor != 'n');
                cout << "Koncze zadanie i wracam do menu glownego."<<endl<<endl;

            } break;

            case '2' : {
                double x, y;
                wybor = 't';
                do {
                cout << endl;
                cout << "Zadanie 2. Oblicze wartosc funkcji y(x) w podanym punkcie x.\n";
                cout << "Podaj dla jakiego x mam obliczyc wartosc funkcji: ";
                cin >> x;
                y = wartosc_funkcji(x);
                cout << "Wartosc funkcji w punkcie "<< x <<" wynosi :" << y <<endl;
                cout << "Czy chcesz powtorzyc obliczenia? (t/n):";
                cin >> wybor;
                } while (wybor !='n');
                cout << "Koncze zadanie i wracam do menu glownego." <<endl<<endl;
            } break;

            case '3' : {
                int n, licznik_r, licznik_o;
                //srand(time(0));
                srand(static_cast<unsigned int>(time(0)));  // poprawa dla macos
                wybor = 't';
                do {
                cout << endl;
                cout << "Zadanie 3.\n";
                cout << "Ile rzutow moneta mam wykonac? :";
                cin >> n;
                while ( n<=0 ){
                    cout << "Liczba rzutow musi byc wieksza od zera:";
                    cin >> n;
                }
                licznik_o = 0;
                licznik_r = 0;
                for (int i=1; i<=n; i++){
                    string moneta;
                    moneta = coinToss();
                    if (moneta == "Reszka") licznik_r++;
                        else licznik_o++;
                }
                cout << "Orzel wypadl :" << licznik_o << " razy.\n";
                cout << "Reszka wypadla : " << licznik_r << " razy.\n";
                cout << "Czy chcesz powtorzyc obliczenia? (t/n):";
                cin >> wybor;
                } while (wybor != 'n');
                cout << "Powrot do menu glownego.\n"<<endl;

            } break;

            case '4' : {
                double a, b, c;
                wybor = 't';
                do {
                cout << endl;
                cout << "Zadanie 4. Trojkat.\n";
                cout << "Podaj dlugosci odcinkow w cm, a sprawdze czy mozna z nich utworzyc trojkat: \n";
                cout << "a :";
                cin >> a;
                while ( a <= 0 ){
                    cout << "Dlugosc odcinka a musi byc wieksza od zera: ";
                    cin >> a;
                }
                cout << "b :";
                cin >> b;
                while ( b <= 0 ){
                    cout << "Dlugosc odcinka b musi byc wieksza od zera: ";
                    cin >> b;
                }
                cout << "c :";
                cin >> c;
                while ( c <= 0 ){
                    cout << "Dlugosc odcinka c musi byc wieksza od zera: ";
                    cin >> c;
                }
                if (trojkat(a, b, c) == true){
                    cout << "Z podanych odcinkow mozna zbudowac trojkat.\n";
                    //cout << setprecision (2) << fixed;
                    cout << "Pole jego powierzchni wynosi : " << poleTrojkata(a, b, c) << " cm2.\n";
                    }
                        else{
                            cout << "Z podanych odcinkow nie mozna zbudowac trojkata.\n";
                            }
                cout << "Czy chcesz powtorzyc obliczenia? (t/n):";
                cin >> wybor;
                } while (wybor !='n');
                cout << "Powrot do menu glownego.\n"<<endl;
            } break;

            default : {
                cout<<"Niewlasciwa opcja, sprobuj jeszcze raz.\n";
            } break;

            case 'q' : {
                cout<<"Koncze dzialanie, do widzenia!\n";
            } break;

        }

    } while (poz_menu != 'q');

    return 0;
    }

double pole_trapez(double a, double b, double h){
    double pole_pow;
    pole_pow = ((a + b)*h)/(2.0);
    return pole_pow;
}

double wartosc_funkcji(double x){
    double y;
    if (x < 0){
        y = ((x * x)/2.0)+(x/3.0);
    }
        else if (x > 6){
            y = (x + 3);
    }
            else y = (sin(x)+1);
    return y;
}
string coinToss(){
    string wynik;
    int losowanie;
    losowanie = (rand()%2 + 1);
    if (losowanie == 1) wynik = "Reszka";
        else wynik = "Orzel";
    cout << wynik << endl;
    return wynik;
}
bool trojkat(double a, double b, double c){
    bool status;
    if ((a+b)>c && (b+c)>a && (a+c)>b)
        status = true;
            else status = false;
    return status;
}
double poleTrojkata(double a, double b, double c){
    double pole, P;
    P = (a + b + c)/2.0;
    pole = sqrt(P * (P-a) * (P-b) * (P-c));
    return pole;
}

