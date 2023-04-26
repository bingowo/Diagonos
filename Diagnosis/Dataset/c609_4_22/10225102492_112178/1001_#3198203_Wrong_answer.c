#include<stdio.h>
int main()
{
	char a[36],hei[100000];
	int x,y;
	for (x=0;x<=9;x++)a[x]='0'+x;
	for(x=10;x<=35;x++)a[x]='A'+x-10;
	int t,n,r,i,j,jud;
	char ans[10000];
	scanf("%d",&t);
	for(j=0;j<=t-1;j++){
		scanf("%d%d",&n,&r);
		if(n>=0){
			for(i=0;n!=0;i++){
			ans[i]=a[n%r];
			n=n/r;		
			}
			ans[i+1]=a[n];
			for(y=0;i>=-1;y++,i--)hei[y]=ans[i];
			hei[y+1]='0';
			printf("%s\n",hei);	
		}
		else{
			n=-n;
			for(i=0;n!=0;i++){
			ans[i]=a[n%r];
			n=n/r;		
			}
			ans[i+1]=a[n];
			for(y=0;i>=-1;y++,i--)hei[y]=ans[i];
			hei[y+1]='0';
			printf("-%s\n",hei);		
		}
	}
	return 0;	
}