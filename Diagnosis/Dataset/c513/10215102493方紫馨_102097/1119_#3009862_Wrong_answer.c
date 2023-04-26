#include<stdio.h>
int main()
{
	int d,n;
	long long s[1000];
	int v[1000];
	scanf("%d%d",&d,&n);
	for(int i=0;i<n;i++){
		scanf("%d%d",&s[i],&v[i]);
	}
	double t = (d-s[0])*1.0/v[0],t1=0,t2,v0,v1 = v[0];
	t2 = t;
	int cnt = 1;
	while(cnt<n){
		if(v[cnt]>v[cnt-1]){
			t1 = (s[cnt-1]-s[cnt])/(v[cnt]-v[cnt-1]);
			t -= t1;
			for(int i=0;i<n;i++){
				s[i] += t1*v[i];
			}
		}else{
			v1 = v[cnt];
		}
		
		cnt++;
	}
	v0 = (s[n-1]+v1*t)/t2;
	printf("%.6f",v0);
	return 0;
}