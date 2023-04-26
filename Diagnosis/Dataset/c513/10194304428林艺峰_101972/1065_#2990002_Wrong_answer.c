#include<stdio.h>
#define Maxn 30
struct people{
	int inn, outn, inx, outx, total, totalx;
}p[Maxn];
int main(){
	int a, n, m, x, i, ans = 0;
	scanf("%d%d%d%d", &a, &n, &m, &x);
	p[1].inn = a;
	p[1].total = a;
	p[2].inx = 1;
	p[2].outx = 1;
	p[2].total = a;
	for(i = 3; i <= n; ++i){
		p[i].inn = p[i-1].inn + p[i-2].inn;
		p[i].inx = p[i-1].inx + p[i-2].inx;
		p[i].outn = p[i-1].inn;
		p[i].outx = p[i-1].inx;
		p[i].total = p[i-1].total + p[i].inn - p[i].outn;
		p[i].totalx = p[i-1].totalx + p[i].inx - p[i].outx;
	}
	ans = (m - p[n].outn) / p[n].outx;
	printf("%d", p[x].total + p[x].totalx * ans);
	return 0;
}