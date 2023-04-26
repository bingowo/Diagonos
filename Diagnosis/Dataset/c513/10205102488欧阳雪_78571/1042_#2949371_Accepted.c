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
	scanf("%d\n",&T);
	int b[128]={0};
	char c1='A',c2='a';
	for(int i1=65;i1<=90;i1++)
	{
		b[i1]=c1;
		c1++;
	}
	for(int i2=97;i2<=122;i2++)
	{
		b[i2]=c2;
		c2++;
	}
	
	for(int i=0;i<T;i++)
	{
		char s[50]={0};
		char c;
		int a[128]={0};
		int j=1;
		while((c=getchar())!='\n')
		{
			s[j++]=c;
			a[c]++;
		}
		//printf("s:%s\n",s);
		char df[50]={0};//存不同的字符 
		int k=0;
		for(j=0;j<128;j++)
		{
			if(a[j]>0){
				df[k++]=b[j];
			}
		}
		
		printf("case #%d:\n",i);
        //printf("df:%s\n",df);
        int len=strlen(df);
        print(df,0,0,len);
    }
}