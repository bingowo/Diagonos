#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int main()
{
	int t;
	scanf("%d", &t);
	while (t--) {
		int n, i, j;
		scanf("%d",&n) ;
		int d[1005], index = 0;
		int xx = n;
		while (xx) {
			d[index++] = xx % 3;
			xx /= 3;
		}
		int flag = 0;
		for (i = 0; i < index; ++i) {
			if (d[i] + flag == 1) {
				d[i] = d[i] + flag;
				flag = 0;
			} else if (d[i] + flag == 2) {
				d[i] = -1;
				flag = 1;
			} else if (d[i] + flag == 3) {
				d[i] = 0;
				flag = 1;
			}
		}
		if (flag) d[index++] = flag;
		double l[1005], r[1005];
		int x = 0, y = 0;
		for (i = 0; i < index; ++i) {
			if (d[i] == -1)
				l[x++] = pow(3.0, i);
			if (d[i] == 1)
				r[y++] = pow(3.0, i);
		}
		sort(l, l + x);
		sort(r, r + y);
		if (x == 0) printf("empty ");
		else {
			for (i = 0; i < x - 1; ++i)
				printf("%.0lf,", l[i]);
			printf("%.0lf ", l[i]);
		}
		for (i = 0; i < y - 1; ++i)
				printf("%.0lf,", r[i]);
		printf("%.0lf\n", r[i]);
	}
    return 0;
    
}