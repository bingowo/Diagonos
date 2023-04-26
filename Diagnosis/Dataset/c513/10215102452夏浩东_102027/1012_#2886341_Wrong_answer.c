#include <stdio.h>
int max(int m)
{
	if(m>1) return m;
	else return 1;
}
int main()
{
    char s[100];
    scanf("%s",s);
    long long int a=0,b=0,num=0,i=0;
    int flag=1,flag1=0;
    while(s[i]!='\0')
    {
    	if(s[i]=='-') flag=-1;
    	else if(s[i]=='+') flag=1;
    	else if(s[i]<='9'&&s[i]>='0') num=num*10+s[i]-'0';
    	if(s[i+1]=='i'){
    		b=max(num)*flag;
			flag1=1;	
		}
    	else if(s[i+1]=='+' || s[i+1]=='-')
		{
			a=num*flag;
			num=0;
		}
    	i++;
	}
	if(flag1==0)
	{
		a=num*flag;
		b=0;
	}
    long long int m=a,n=b,M=0,N=0,r=0;
    int k=0;
    int L[1000]={0};
    if(m==0 && n==0)printf("0");
    while(m!=0 || n!=0)
    {
    	if((m%2==0 && n%2!=0)||(m%2!=0 && n%2==0)) r=1;
    	else r=0;
    	M=(-m+n+r)/2;
    	N=(-m-n+r)/2;
    	m=M;
    	n=N;
    	L[k]=r;
    	k++;
	}
    for(int i=k-1;i>=0;i--) printf("%d",L[i]);
	return 0; 
}