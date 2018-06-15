#include<iostream>

#define MAXN 1000001

using namespace std;

int n, m, d;
int l[MAXN], c[MAXN];
int lancuch[MAXN], ile_w_kolorze[MAXN], ile_ma_byc[MAXN];
int ile_niezgodnosci, wynik;

void akt_kolor(int k, int dodaj) {
	if(ile_w_kolorze[k] == ile_ma_byc[k]) ile_niezgodnosci++;
	ile_w_kolorze[k] += dodaj;
	if(ile_w_kolorze[k] == ile_ma_byc[k]) ile_niezgodnosci--;
}

int main() {
	scanf("%d %d", &n, &m);
	for(int i = 0; i < m; i++) {
		scanf("%d", &l[i]);
		d += l[i];
		if(d > n) {
			printf("%d\n", 0);
			return 0;
		}
	}
	for(int i = 0; i < m; i++) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	for(int i = 0; i < m; i++)
		ile_ma_byc[c[i]] = l[i];
	for(int i = 0; i < n; i++) {
		scanf("%d", &lancuch[i]);
		lancuch[i]--;
	}

	ile_niezgodnosci = m;
	for(int i = 0; i < d; i++)
		akt_kolor(lancuch[i], 1);
	if(ile_niezgodnosci == 0) wynik++;
	for(int i = 0; i + d < n; i++) {
		akt_kolor(lancuch[i], -1);
		akt_kolor(lancuch[i + d], 1);
		if(ile_niezgodnosci == 0) wynik++;
	}

	printf("%d\n", wynik);

	return 0;
}
