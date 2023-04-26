#include<stdio.h>
#include<string.h>
char ans[100];
void print(char*df,int k,int l,int r)
{
	if(l==r){
		return;
	}
	for(;l!=r;l++)
	{
		ans[k]=df[l];
		ans[k+1]=0;
		printf("%s\n",ans);
		print(df,k+1,l+1,r);
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	for(int z=0;z<T;z++)
	{
		char s[17]={0};
		scanf("%s",s);
		int i=0,j=0;
		int flg[200]={0};
		for(i=0;i<strlen(s);i++)
		{
			flg[s[i]]++;
		}
		char ds[17]={0};
		for(i=0;i<200;i++)
		{
			if(flg[i]>0)
			{
				if(i>90)
				{
					ds[j]=i%97+'a';
				}
				else{
					ds[j]=i%65+'A';
				}
				j++;
			}
		}
		printf("case #%d:\n",z);
        int len=strlen(ds);
        print(ds,0,0,len);
	}
}