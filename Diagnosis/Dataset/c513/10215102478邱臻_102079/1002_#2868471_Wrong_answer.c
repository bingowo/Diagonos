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
		flag=0;result=0;
		c=0;r=0;
		for(j=0;ch[j]!='\0';j++){
			x=ch[j];
			if(a[x]==-1){
				if(j==0){a[x]=1;flag=1;r++;}
				else if(flag==1){a[x]=0;flag=0;r++;}
				else {a[x]=r;r++;}
			}
			num[c]=a[x];
			c++;
		}
		c1=c;
		if(r==1)r+=1;
		for(k=0;k<=c1;k++,c--){
			result+=num[k]*pow(r,c);
		}
		printf("case #");
		printf("%lld:\n",i);
		printf("%lld\n",result);
	} 
	return 0;
}