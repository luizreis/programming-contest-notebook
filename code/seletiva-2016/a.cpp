#include <cstdio>
#include <cmath>

#define abs(a) (((a)<0)?(-a):(a))
#define sign_zero(a) (((abs((a)))>0.000001)?(a):(0.0))
using namespace std;

double to_rad(int ang) {
    return ang*M_PI/180.0;
}

int main () {
	int r, la, lo;
	scanf("%d %d %d", &r, &la, &lo);

	double z = cos(to_rad(la)) * -cos(to_rad(lo)) * r;
	double y = sin(to_rad(la)) * r;
	double x = cos(to_rad(la)) * sin(to_rad(lo)) * r;

	printf("%.2lf %.2lf %.2lf\n", sign_zero(x), sign_zero(y), sign_zero(z));

	return 0;
}
