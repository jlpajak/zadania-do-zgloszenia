#include <cstdio>

const int N=1000;
int n; 
int wys[N][N]; 
int vis[N][N]; 
int grzbiet, dolina; 
int stos[N*N];
int rozmiar_stosu; 

void wczytaj(){
  scanf("%d",&n);
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      scanf("%d",&wys[i][j]);
}

#define koduj(i,j) ((i)*N+j)

void dfs(int i,int j){
  vis[i][j]=1;
  rozmiar_stosu=1;
  stos[0]=koduj(i,j);
  while (rozmiar_stosu){
    int x=stos[--rozmiar_stosu];
    j=x%N;
    i=x/N;
    for (int ni=i-1; ni<=i+1; ++ni)
      for (int nj=j-1; nj<=j+1; ++nj)
        if (ni>=0 && ni<n && nj>=0 && nj<n){
          if (wys[ni][nj]==wys[i][j] && !vis[ni][nj]){
            vis[ni][nj]=1;
            stos[rozmiar_stosu++]=koduj(ni,nj);
          } else if (wys[ni][nj]<wys[i][j]) dolina=0;
          else if (wys[ni][nj]>wys[i][j]) grzbiet=0;
        }
  }
}

void licz(){
  int grzbiety=0, doliny=0;
  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      vis[i][j]=0;

  for (int i=0; i<n; ++i)
    for (int j=0; j<n; ++j)
      if (!vis[i][j]){
        grzbiet=dolina=1;
        dfs(i,j);
        grzbiety+=grzbiet;
        doliny+=dolina;
      }
  printf("%d %d\n",grzbiety, doliny);
}

int main(){
  wczytaj();
  licz();
}