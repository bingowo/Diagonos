#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	long long int t,i=0,j=0,x,flag,c,k,c1,r,z;
	long long int result;
	char ch[60];
	long long int a[123];
	long long int num[60];
	scanf("%lld",&t);
	for(i=0;i<t;i++){
		scanf("%s",ch);
		r=0;flag=0;c=0;j=0;
		for(z=0;z<123;z++)a[z]=-1;
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
		c1=c-1;c--;
		if(r==1)r++;result=0;
		for(k=0;k<=c1,c>=0;k++,c--){
			result=result+num[k]*pow(r,c);
			}
			printf("case #");
			printf("%lld:\n",i);
			printf("%lld\n",result);
	}
	return 0;
}