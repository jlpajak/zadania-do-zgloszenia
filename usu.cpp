#include<cstdio>

using namespace std;

const int MAXN = 1000000;

int stos[MAXN+1];
int suma[MAXN+1]; 
int s;
int wynik[MAXN+1];
int w;
int n, k;

int main(int argc, char *argv[]) {
    scanf("%d %d", &n, &k);
    for(int i=1; i<=n; ++i)
    {
        char z;
        scanf("%c", &z);
        int val;
        if(z == 'b') val = 1;
        else val = -k;
        ++s;
        stos[s] = i;
        suma[s] = suma[s-1] + val;
        if(s >= k+1 && suma[s] - suma[s-k-1] == 0) {
            for(int j=0; j<k+1; ++j)
                wynik[w++] = stos[s--];
        }
    }
    for(int i=0; i<n/(k+1); ++i)
    {
        for(int j=0; j<k+1; ++j)
            printf("%d ", &wynik[--w]);
        printf("\n");
    }
    return 0;
}

