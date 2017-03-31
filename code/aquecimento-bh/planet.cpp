#include <bits/stdc++.h>
using namespace std;

#define mp make_pair
#define EPS 1e-12

#define N 10010

long long R, k;
long long x[N], y[N], r[N], v[N];

inline double dist(int i){
	return sqrt(x[i]*x[i] + y[i]*y[i]);
}

bool in[N<<1];

double cob(double t){
	vector <pair <double, int> > evt;
	int c = 0;

	for(int i=0; i<k; i++)
	if((dist(i)-R)/r[i] < t){
		double a1, a2;

		if(v[i]*(t - (dist(i)-R)/r[i]) >= M_PI*R){
			return 1;
		}
		a1 = atan2(y[i], x[i]) - v[i]*(t - (dist(i)-R)/r[i])/R;
		a2 = atan2(y[i], x[i]) + v[i]*(t - (dist(i)-R)/r[i])/R;

		if(a1<0 && a2>=0){
			in[i] = 1;
			c++;
		}else in[i] = 0;

		while(a1 < 0) a1 += 2*M_PI;
		while(a1 >= 2*M_PI) a1 -= 2*M_PI;
		while(a2 < 0) a2 += 2*M_PI;
		while(a2 >= 2*M_PI) a2 -= 2*M_PI;

		evt.push_back(mp(a1, i));
		evt.push_back(mp(a2, i));
	}

	sort(evt.begin(), evt.end());
	double r = 0, pi = 0;
	for(int i=0; i<evt.size(); i++){
		if(in[evt[i].second]){
			c--;
			if(!c) r += (evt[i].first - pi);
		}else{
			if(!c) pi = evt[i].first;
			c++;
		}
		in[evt[i].second] = 1-in[evt[i].second];
	}
	if(c) r += (2*M_PI - pi);

	return r/(2*M_PI);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lld %lld", &R, &k);
		double a = 0, b = 0;
		for(int i=0; i<k; i++){
			scanf("%lld %lld %lld %lld", x+i, y+i, r+i, v+i);
			b = max(b, (dist(i)-R)/r[i] + M_PI*R/v[i]);
		}

		for(int i=0; i<65; i++){
			double m = (a+b)/2;
			if(fabs(cob(m)-1) > EPS) a = m;
			else b = m;
		}

		printf("%.4lf\n", (a+b)/2);
	}

	return 0;
}
