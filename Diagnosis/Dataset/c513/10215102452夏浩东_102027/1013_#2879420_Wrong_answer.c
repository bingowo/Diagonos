#include <stdio.h>
#include <math.h>
int gcd(int x, int y)
{ 
	if(y==0) return x;
	else return gcd(y, x%y);
}
int main()
{
    char s[31];
    scanf("%s",s);
    int isInt=1,i=0,m=0,A=0,B=0,C=0;
    for(i=0;s[i]!='\0';i++)
    {
        if(s[i]=='.')
        {
            isInt=0;
            m=i;
        }
    }
    if(isInt==1)
    {
        for(int k=0;k<i;k++)
        {
            if(s[k]=='1') A+=pow(3,i-k-1);
            else if(s[k]=='2') A-=pow(3,i-k-1);
        }
        printf("%d",A);
    }
    else
    {
        int k=0;
        for(k=0;s[k]!='.';k++)
        {
            if(s[k]=='1') A+=pow(3,m-k-1);
            else if(s[k]=='2') A-=pow(3,m-k-1);
        }
        for(int t=k+1;s[t]!='\0';t++)
        {
            if(s[t]=='1') B+=pow(3,i-1-t);
            else if(s[t]=='2') B-=pow(3,i-1-t);
        }
        C=pow(3,i-k-1);
        C=C/gcd(C,B);
        B=B/gcd(C,B);
        if(C<0)
		{
			C=-C;
			B=-B;
		}
        if(A>0 && B<0)
		{
			B=C+B;
			A=A-1;	
		}
		if(A<0 && B>0)
		{
			B=C-B;
			A=A+1;
		}
		if(A<0 && B<0)
		{
			B=-B;
		}
		if(A==0) 
		{
			printf("%d %d",B,C);
		}
        else printf("%d %d %d",A,B,C);
    }
}