#include <stdio.h>
#include <string.h>
void change(int a,int S[],int i)
{
    int j=i;
    if (a>=100) i=i+9;
    else if (a>=10) i+=6;
    else i+=3;
    while (a)
        {
            S[i--]=a%2;
            a=a/2;
        }
    for (j;j<i;j++) S[j]=0;
}
int main()
{
    char s[100];
    scanf("%s",s);
    int S[10000];
    int len=strlen(s),i=4,q=0;
    S[0]=0;S[1]=0;S[2]=0;S[3]=1;
    int j=i,num=len;
    i+=9;
    while (num)
        {
            S[i--]=num%2;
            num=num/2;
        }
    for (j;j<i;j++) S[j]=0;
    i=14;
    while (i<len+14)
    {
        if (len+14-i>=3) {num=(s[q]-'0')*100+(s[q+1]-'0')*10+s[q+2]-'0';change (num,S,i);i+=3;q+=3;}
        else if (len+14-i==2) {num=(s[q]-'0')*10+s[q+1]-'0';change (num,S,i);i+=2;q+=2;}
        else if (len+14-i==1) {num=s[q]-'0';change (num,S,i);i+=1;q+=1;}
    }
    i=i+7;
    
    for (int k=0;k<i;k++) printf("%d",S[k]);
    return 0;

}
