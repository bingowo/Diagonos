#include<stdio.h>
#include<string.h>
int pow(int a,int b)
{
    int sum,i;
    sum=1;
    for(i=0;i<b;i++)
    {
        sum=sum*a;
    }
    return sum;
}
int a2d(char a)
{
    if(a=='0') return 0;
    if(a=='1') return 1;
    if(a=='2') return 2;
    if(a=='3') return 3;
    if(a=='4') return 4;
    if(a=='5') return 5;
    if(a=='6') return 6;
    if(a=='7') return 7;
    if(a=='8') return 8;
    if(a=='9') return 9;
    if(a=='A' || a=='a') return 10;
    if(a=='B' || a=='b') return 11;
    if(a=='C' || a=='c') return 12;
    if(a=='D' || a=='d') return 13;
    if(a=='E' || a=='e') return 14;
    if(a=='F' || a=='f') return 15;
}
int main()
{
    char a[1000],c[1000],b[16]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    int n,x,len,num,sum,i,A,B;
    sum=0;
    scanf("%d",&A);
    scanf("%s",&a);
    scanf("%d",&B);
    len=strlen(a);
    for(i=0;i<len;i++)
    {
        num=a2d(a[i]);
        sum=sum+num*pow(A,len-1-i);
    }
    n=0;
    while(sum!=0)
    {
        x=sum%B;
        sum=sum/B;
        c[n]=b[x];
        n++;
    }
    for(n=n-1;n>=0;n--)
    {
        printf("%c",c[n]);
    }
    return 0;

}
