#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int t,i=0,j=0,x,flag,c,k,c1,r;
	long long int result;
	char ch[60];
	int a[62]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};
	int num[60];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s",ch);
		r=0;flag=0;c=0;result=0;j=0;
		while(ch[j]!='\0'){
			x=ch[j];
			if(a[x]==-1){
				if(j==0){
					a[x]=1;flag=1;
				}
				else if(flag==1){
					a[x]=0;flag=0;
				}
				else a[x]=r;
				r++;
			}
			num[c]=a[x];c++;j++;
		}
		c1=c;
		if(r==1)r++;
		for(k=0;k<=c1;k++,c--){
				result+=num[k]*pow(r,c);
			}
			printf("case #");
			printf("%d:\n",i);
			printf("%lld\n",result/2);
	}
	return 0;
}