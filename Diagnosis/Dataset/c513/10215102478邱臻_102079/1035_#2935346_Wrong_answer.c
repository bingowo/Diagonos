#include <stdio.h>
#include <stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int cmp(const void*a,const void*b){
	long long int* p1,*p2;
	p1=*(long long int(*)[3])a;p2=*(long long int(*)[3])b;
	return *p1<*p2?1:-1;
}
int main() {
	long long int n,max=0,result=0,m,i,j,k,z,r,h; 
	long long int s[1000][3]={},s1[1000][3]={}; 
	scanf("%lld%lld",&n,&m);
	for(i=0;i<n;i++){
		scanf("%lld%lld",&r,&h);
		s[i][1]=r;s[i][2]=h;
		s[i][0]=2*h*r;   //计算侧面积 
	}  //总的圆柱体集合 
	max=0;
	for(i=0;i<n;i++){
		k=0;
		for(j=0;j<n;j++){
			if(j!=i && s[j][1]<=s[i][1]){
				s1[k][0]=s[i][0];
				s1[k][1]=s[i][0];
				s1[k][2]=s[i][0];
				k++;
			}   //新数组 
		}
		qsort(s1,k,sizeof(s1[0]),cmp);
		result=0;
		if(k!=0 && k>=m-1){
			for(z=0;z<m-1;z++)result+=s1[z][0];  //侧表面积之和 
		}
		result=result+s[i][0]+s[i][1]*s[i][1];
		max=max>result?max:result;  //最大值 
	}
	printf("%lld",max);
	
	return 0;
}