#include<stdio.h>
int main()
{
    //10=1010 10%2=0(5) 5%2=1(2) 2%2=0(1) 1%2=1(0)
	int t,n,r;
	int z,j;
	char table[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
	char res[100];
	scanf("%d",&t);
	for(z=0;z<t;z++)
	{
	    scanf("%d %d",&n,&r);
	    int flag=0;
	    if(n<0) 
	    {
	        flag=1;
	        n=0-n;
	    }
	    int i=0;
	    while(n/r!=0)
	    {
	        res[i++]=table[n%r];
	        n=n/r;
	    }
	    res[i]=table[n%r];
	    if(flag==1)  printf("-");
	    for(j=i-1;j>=0;j--)  printf("%c",res[j]);
	    printf("\n");
	}
	return 0;
}