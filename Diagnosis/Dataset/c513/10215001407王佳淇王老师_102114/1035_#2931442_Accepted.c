#include<stdio.h> 
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define ll long long int
typedef struct {
	ll r;
	ll h;
	ll ad;
	ll ac;
	ll s;
}CYL;
int cmp(const void*a,const void*b) {
	ll a1=((CYL*)a)->ac;
	ll b1=((CYL*)b)->ac;
	if(a1!=b1) return b1>a1?1:-1;
	else return 0;
	
}
int main(){
	int n,m;
	scanf("%d %d\n",&n,&m);
	CYL c[1000];
	for(int v=0;v<n;v++){
		scanf("%lld %lld",&c[v].r,&c[v].h);
		c[v].ad=c[v].r*c[v].r;
		c[v].ac=2*c[v].r*c[v].h;
		c[v].s=c[v].r*c[v].r+2*c[v].r*c[v].h;
	}
	qsort(c,n,sizeof(CYL),cmp);
	ll res=0;
	for (int i=0;i<n;i++){  //用每一个圆柱体作底（最下面的一个），计算可能的结果
        long long sum = c[i].s;
        int cou = 1;
        for (int j = 0;j<n && cou<m;j++){  //用m-1个圆柱组成最终的几何体
            if( i==j || c[j].r >c[i].r) continue;  //后面选的圆柱底面积不能大于第i个
            sum += c[j].ac;
            cou++;
        }
        if (cou == m) res = fmax(res,sum);
    }
    printf("%lld ",res);
    return 0;
}