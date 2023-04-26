#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
int main()
{
	char s[105];
	int tabx[105],taby[105];
	scanf("%s",s);
	int n=strlen(s);
	long long x=0,y=0,sumx=0,sumy=0;
	for(int i=0;i<n;i++)
	{
		if(s[i]=='U')y+=1;
		else if(s[i]=='D')y-=1;
		else if(s[i]=='L')x-=1;
		else x+=1;
		tabx[i]=x;
		taby[i]=y;
	}
	tabx[n-1]=0;
	taby[n-1]=0;
	//printf("%d %d %d",x,y,n);
	int q;scanf("%d",&q);
	for(int j=0;j<q;j++){	
		int ans=0,ff=0;
		int xx,yy;
		scanf("%d%d",&xx,&yy);
		for(int i=0;i<n;i++){
			int f=0;
			//printf("%d %d\n",xx-tabx[i],yy-taby[i]);
			if(x==0){
				if(xx-tabx[i]==0) f+=2;
			}
			else if((xx-tabx[i])%x==0 && (xx-tabx[i])/x>0) f++;
			if(y==0){
				if(yy-taby[i]==0) f+=2;
			}
			else if((yy-taby[i])%y==0 && (yy-taby[i])/y>0) f++;
			if(x!=0 && y!=0)
			 if((xx-tabx[i])/x==(yy-taby[i])/y) f++;
			if(f>=3 || (xx==0 && yy==0)){
				printf("Yes\n");
				ff=1;
				break;
			}
		}
		if(ff==0) printf("No\n");
	}
}