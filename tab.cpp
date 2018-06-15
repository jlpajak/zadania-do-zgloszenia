#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

#define MAX_N 1000

int ile, n, m;
int t1[MAX_N][MAX_N], t2[MAX_N][MAX_N];

int tp[MAX_N][MAX_N];

void sprowadz(int t[MAX_N][MAX_N])
{
	vector<pair<int, int> > pom;
	for (int i = 0; i < n; i++)
		pom.push_back(make_pair(*min_element(t[i], t[i] + m), i));
	sort(pom.begin(), pom.end());
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tp[i][j] = t[pom[i].second][j];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			t[i][j] = tp[i][j];

	pom.clear();
	for (int j = 0; j < m; j++)
		pom.push_back(make_pair(t[0][j], j));
	sort(pom.begin(), pom.end());
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			tp[i][j] = t[i][pom[j].second];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			t[i][j] = tp[i][j];
}

int main()
{
	scanf("%d", &ile);
	while (ile--)
	{
		scanf("%d %d", &n, &m);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &t1[i][j]);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				scanf("%d", &t1[i][j]);
		sprowadz(t1);
		sprowadz(t2);
		bool ok = true;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (t1[i][j] != t2[i][j])
					ok = false;
		printf("%s\n", ok? 'TAK' : 'NIE');
	}
	return 0;
}
