#include <cstdio>
#include <vector>

using namespace std;

//Zmienne, których będę używał
#define ROZMIAR 20 //ograniczenie na n to 1 000 000, a 2^20 = 1 048 576
#define MAXN 1000000
int drzewo[1 << (ROZMIAR+1)]; //tworzymy drzewo przedzialowe
long long wynik;
int n;
int position;
vector<int> tab[255];
char nazwisko1[MAXN];
char nazwisko2[MAXN];


//Funkcja wstawiająca użycie znaku do drzewa
void wstaw(int pozycja) {
  int v = (1 << ROZMIAR) + pozycja;
  drzewo[v] = 1;
  while (v != 1) {
    v /= 2;
    drzewo[v] = drzewo[2 * v] + drzewo[2 * v + 1];
  }
}

//Funkcja zwracająca ile znaków użyto w przedziale <a,b>
int zapytanie(int a, int b){
  int va = (1 << ROZMIAR) + a;
  int vb = (1 << ROZMIAR) + b;

  int zliczenia = drzewo[va];
  if (va != vb)
    zliczenia += drzewo[vb];

  while (va / 2 != vb / 2) {
    if (va % 2 == 0) zliczenia += drzewo[va + 1];
    if (vb % 2 == 1) zliczenia += drzewo[vb - 1];
    va /= 2; vb /= 2;
  }
  return zliczenia;
}
//implementacja funkcji wstaw oraz zapytanie za wykładami z algorytmiki
//zobacz: http://was.zaa.mimuw.edu.pl/?q=node/9


//Program właściwy
int main() {
  scanf("%d", &n); //wczytuję n
  scanf("%s", nazwisko1); //wczytuję pierwsze nazwisko
  for (int i = n - 1; i >= 0; --i)
    tab[int(nazwisko1[i])].push_back(i); //idąc od końca pierwszego nazwiska tworzę wektor zawierający pozycje poszczególnych liter

  scanf("%s", nazwisko2); //wczytuję drugie nazwisko
  for (int i = 0; i < n; ++i){
    //zwracam pierwsze wystąpienie identycznej litery w pierwszym nazwisku
    position = tab[int(nazwisko2[i])].back();
    //usuwam to położenie z wektora
    tab[int(nazwisko2[i])].pop_back();
    //wynik powiększam o pozycję - muszę przesunąć znak na początek ciągu oraz
    //pomniejszam o ilość wykorzystanych wcześniej znaków
    //(o tyle już znak został przesunięty przy poprzednich permutacjach)
    wynik += position - zapytanie(0, position);
    //wstawiam użycie znaku do drzewa przedziałowego
    wstaw(position);
  }

  printf("%lld\n", wynik);  //zwracam wynik

  return 0;
}
