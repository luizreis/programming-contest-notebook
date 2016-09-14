#include <cstdio>
#include <vector>
using namespace std;
vector <int> rel[1001];
int n,m,q;
char novo[1001];

void dfs(int p){
	novo[p]=0;
	for(int i=0;i<rel[p].size();i++){
		if(novo[rel[p][i]])
			dfs(rel[p][i]);
	}
	return;
}

int main(){
	int a,b;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=n;i++){
			rel[i].clear();
			novo[i]=-1;
		}
		for(int i=0;i<m;i++){
			scanf("%d %d",&a,&b);
			rel[a].push_back(b);
			rel[b].push_back(a);
		}

		q=0;
		for(int i=1;i<=n;i++)
			if(novo[i]){
				dfs(i);
				q++;
			}

		printf("%d\n",q);
	}
	return 0;
}
