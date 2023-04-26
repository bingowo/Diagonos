#include <stdio.h>
#include <string.h>
#include <stdlib.h>




void solve()
{
	int n;
	scanf("%d\n",&n);
	char s[2100];
	gets(s);
	char word[2000][40];
	int i=0,ii=0,i0;
	while(i<strlen(s))
	{
		i0=0;
	    while(s[i]!=' '&&s[i]!='\n'&&i<strlen(s)) word[ii][i0]=s[i],i++,i0++;
	    if(i0>0) word[ii][i0]='\0',ii++;
	    i++;
	}//printf("%s\n",word[1]);
	int konge=0,sum=0;
	int k=0,qk=0;
	while(k<ii)
	{
		sum=strlen(word[k]);qk=k;
		while(sum<n&&k!=ii-1)
		{
			k++;
			sum+=1+strlen(word[k]);
		}
	
		if(sum==n)
		{
			for(int j=qk;j<k;j++) printf("%s ",word[j]);
			printf("%s\n",word[k]);
		}
		else if(k==ii-1&&sum<n)
		{
			if(qk==k) printf("%s\n",word[k]);//cout<<word[k]<<'\n';
			else if(qk<k)
			{
				for(int j=qk;j<k;j++) printf("%s ",word[j]);// cout<<word[j]<<' ';
				printf("%s\n",word[k]);
			}
		}
		else
		{	
			k--;
			sum=0;
			for(int j=qk;j<=k;j++) sum+=strlen(word[j]);
			int len=n-sum;
			int mx=0,my=0;
			while((len-mx)%(k-qk)!=0) mx++;
			my=len/(k-qk);
			printf("%s",word[qk]);
			if(k-qk>0)
			{
				for(int j=qk+1;j<=k-mx;j++)
				{
					for(int p=0;p<my;p++) printf(" ");
					printf("%s",word[j]);
				}
				for(int j=k-mx+1;j<=k;j++) 
				{
					for(int p=0;p<my+1;p++) printf(" ");
					printf("%s",word[j]);
				}
			}
			printf("\n");
		}
		k++;
	}
}



int main()
{  
	int i,t; 
	scanf("%d\n",&t);
    for(i=0;i<t;i++)
    { 
		printf("case #%d:\n",i); 
		solve();
	} 
    return 0;
}