#include <stdio.h>
#include <string.h>
void change(unsigned int a,int S[],int i)
{
    int j=i;
    if (a>=100) {a-=100;i=i+9;}
    else if (a>=10) {a-=10;i+=6;}
    else i+=3;
    while (a)
        {
            S[i--]=a%2;
            a=a/2;
        }
    for (;j<i;j++) S[j]=0;
}
int main()
{
    char s[1000];
    scanf("%s",s);
    int S[5000];
    int len=strlen(s),i=4,q=0;
    S[0]=0;S[1]=0;S[2]=0;S[3]=1;
    int j=i;unsigned int num=len;
    i+=9;
    while (num)
        {
            S[i--]=num%2;
            num=num/2;
        }
    for (;j<i;j++) S[j]=0;
    i=14;
    while (q+2<len)
    {
        num=(s[q]-'0'+1)*100+(s[q+1]-'0')*10+s[q+2]-'0';
        change (num,S,i);
        i+=10;
        q+=3;
    }
    if (len-q==2) {num=(s[q]-'0'+1)*10+s[q+1]-'0';change (num,S,i);i+=7;}
    else if (len-q==1) {num=s[q]-'0';change (num,S,i);i+=4;}
    for (int k=0;k<i;k++) printf("%d",S[k]);
    return 0;

}
