#include<stdio.h>
int main()
{
	char a[36];
	char ans[1000],hei[1000];
	int x,y;
	for (x=0;x<=9;x++)a[x]='0'+x;
	for(x=10;x<=35;x++)a[x]='A'+x-10;
	int t,n,r,i,j,jud;
	scanf("%d",&t);
	for(j=0;j<=t-1;j++){
	    for(i=0;i<=1000;i++)ans[i]='0';
	    for(i=0;i<=1000;i++)hei[i]='0';
		scanf("%d%d",&n,&r);
		if(n>=0){
			for(i=0;n!=0;i++){
			ans[i]=a[n%r];
			n=n/r;		
			}
			ans[i+1]=a[n];
			for(y=0;i>=-1;y++,i--)hei[y]=ans[i+1];
			printf("%s\n",ans);	
		}
		else{
			n=-n;
			for(i=0;n!=0;i++){
			ans[i]=a[n%r];
			n=n/r;		
			}
			ans[i+1]=a[n];
			for(y=0;i>=-1;y++,i--)hei[y]=ans[i+1];
			printf("-%s\n",hei);		
		}
	}
	return 0;	
}