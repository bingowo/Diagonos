#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
int er(int i)
{  int j,n=1;
 	for(j=1;j<=i;j++) n*=2;
 	return n;
}
int main()
{  int k,T,co=0;
	char z;
	char base[66]={'\0'};
	for(z='A';z<='Z';z++) base[co++]=z; 
	for(z='a';z<='z';z++) base[co++]=z;
	for(z='0';z<='9';z++) base[co++]=z;
	base[62]='+';base[63]='/';
	scanf("%d\n",&T);
	for(k=0;k<T;k++)
	{  	char s[102]={'\0'};
		int y[1000]={0};
		int cn=0;
		gets(s);
		int i;
		for(i=0;i<strlen(s);i++)
		{int x[8]={0};
		 int j=0,r,c=s[i];
		   while(c!=0)
		    {  r=c%2;
		       x[j++]=r;
		       c=c/2;
		    }
	     for(j=7;j>=0;j--) y[cn++]=x[j];
		}
		int deng=3-strlen(s)%3;//不取时deng==3 
	    printf("case #%d:\n",k);
		    char wo[200]={'\0'};
	        int n=cn/6,dn=1,cnt=0;
	        n+=(deng==3)?0:1;
	        for(dn=1;dn<=n;dn++)
	        {  int flag=0;
	        for(i=6*dn-6;i<dn*6;i++) 
		      flag+=y[i]*er(6*dn-1-i);
	         wo[cnt++]=base[flag];
	       }
	       if(deng!=3)for(i=1;i<=deng;i++) wo[cnt++]='=';
		for(i=0;i<cnt;i++) putchar(wo[i]);
		putchar('\n');
	}
	return 0;
}