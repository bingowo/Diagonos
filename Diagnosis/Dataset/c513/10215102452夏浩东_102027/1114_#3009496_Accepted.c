#include <stdio.h>
#include <math.h>
void Input(int*L)
{
    char s[20];
    scanf("%s",s);
    int num=0,flag=1;
    for(int i=0;s[i]!='\0';i++)
    {
        if(s[i]<='9' && s[i]>='0') num=num*10+s[i]-'0';
        else if(s[i]=='-') flag=-1;
        else if(s[i]=='x' && s[i+1]=='^') {L[2]= num==0?flag:flag*num; num=0;flag=1;i+=2;}
        else if(s[i]=='x' && s[i+1]!='^') {L[1]= num==0?flag:flag*num; num=0;flag=1;}
    }
    L[0]=num*flag;
}
int gcd(int x, int y)
{	
	if(x<0) x=-x;
	else if(y<0) y=-y;
    if(x<y){
        int temp = 0;
        temp = x;
        x = y;
        y=temp;
    }
    if(y) return gcd(y, x%y);		
    else return x;
}
int main()
{
    int L[]={0,0,0};
    Input(L);
    int a=L[2],b=L[1],c=L[0];
    if(b*b-4*a*c<0 || sqrt(b*b-4*a*c)-(int)sqrt(b*b-4*a*c)>0.01){
        printf("No Answer!");
    } else {
        int m1=2*a,m2=2*a,n1=(int)(b-sqrt(b*b-4*a*c)),n2=(int)(b+sqrt(b*b-4*a*c));
        int r1=m1/gcd(m1,n1),r2=m2/gcd(m2,n2),q1=n1/gcd(m1,n1),q2=n2/gcd(m2,n2);
        if(r1<r2) printf("%d %d %d %d",r1,q1,r2,q2);
        else if(r1>r2) printf("%d %d %d %d",r2,q2,r1,q1);
        else if(q1<=q2) printf("%d %d %d %d",r1,q1,r2,q2);
        else printf("%d %d %d %d",r2,q2,r1,q1);
    }
    return 0;
}