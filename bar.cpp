#include <cstdio>
#include <algorithm>

using namespace std;

#define MAXN 1000005;

int n;
int wynik;
int mins;
int sumy[MAXN];
int nastepny[MAXN];
int peak[MAXN];
char owoc[MAXN];

void oblicz_sume() {
    for(int i = 1; i <= n; i++) {
        sumy[i] = sumy[i - 1] + (owoc[i - 1] == 'p' ? 1 : -1);
        minimum = min(minimum, sumy[i]);
    }
}

void oblicz_nastepny_z_rowna_suma() {
    int ostatni[MAXN];
    for(int i = 0; i <= n; i++) ostatni[i] = -1;
    for(int i = n; i >= 0; i--) {
        nastepny[i] = ostatni[sumy[i] - minimum];
        ostatni[sumy[i] - minimum] = i;
    }
}

void rozwiaz() {
    int cpeak = n;
    for(int i = 0; i <= n; i++) peak[i] = i;
    for(int i = n - 1; i >= 0; i--) if(owoc[i] == 'p') {
            if(nastepny[i] != -1 && sumy[peak[nastepny[i]]] >= sumy[cpeak]) {
                cpeak = peak[nastepny[i]];
            }
            peak[i] = cpeak;
            wynik = max(wynik, cpeak - i);
        } else {
            cpeak = i;
        }
}

int main() {
    scanf("%d %s", &n, owoc);
    oblicz_sume();
    oblicz_nastepny_z_rowna_suma();
    rozwiaz();
    printf("%d\n", wynik);
    return 0;
}
