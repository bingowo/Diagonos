#include <stdio.h>
int main()
{
    char s[100];
    scanf("%s",s);
    long long int a=0,b=0,num=0;
    int flag1=1,flag2=1,flag3=0,i=0;
    if(s[0]=='-') flag1=-1;
    while(s[i]!='\0')
    {
        if(s[i]<='9'&&s[i]>='0') num=num*10+s[i]-'0';
        if(s[i+1]=='\0' && flag3==0) a=(s[i]-'0')*flag1;
        if(i!=0 && s[i]=='+')
        {
            a=num*flag1;
            num=0;
            flag3=1;
        }
        if(i!=0 && s[i]=='-')
        {
            a=num*flag1;
            num=0;
            flag2=-1;
            flag3=1;
        }
        if(s[i]=='i'&&num!=0) b=num*flag2;
        else if(s[i]=='i'&&num==0) b=flag2;
        i++;
    }
    long long int m=a,n=b,M=0,N=0,r=0;
    int k=0;
    int L[1000]={0};
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