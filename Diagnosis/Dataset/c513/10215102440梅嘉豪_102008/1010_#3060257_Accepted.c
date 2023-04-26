#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct QRcode2
{
    /* data */
    int n;
    int num[10];
    int len;
}QR;
QR QR_creat(int n,int len);
QR sq[1000];
int main()
{
    char s[1000],t[4];
    scanf("%s",s);
    int len=strlen(s),i=0,j=0;
    while(i<len)
    {
        if((i+3)<=len)
        {
            t[0]=s[i++];
            t[1]=s[i++];
            t[2]=s[i++];
            t[3]=0;
            sq[j++]=QR_creat(atoi(t),3);
        }
        else if(len%3==2)
        {
            t[0]='0';
            t[1]=s[i++];
            t[2]=s[i++];
            t[3]=0;
            sq[j++]=QR_creat(atoi(t),2);
        }
        else if(len%3==1)
        {
            t[0]='0';
            t[1]='0';
            t[2]=s[i++];
            t[3]=0;
            sq[j++]=QR_creat(atoi(t),1);
        }
        // printf("%s\n",t);
    }
    sq[i]=QR_creat(len,3);
    printf("0001");
    for(int k=0;k<10;k++) printf("%d",sq[i].num[k]);
    for(int k=0;k<i;k++)
    {
        if(sq[k].len==3)
        {
            for(int h=0;h<10;h++)    printf("%d",sq[k].num[h]);
        }
        else if(sq[k].len==2)
        {
            for(int h=3;h<10;h++)    printf("%d",sq[k].num[h]);
        }
        else if(sq[k].len==1)
        {
            for(int h=6;h<10;h++)    printf("%d",sq[k].num[h]);
        }
    }

}
QR QR_creat(int n,int len)
{
    QR t;
    t.n=n;
    t.len=len;
    for(int i=0;i<10;i++)   t.num[i]=0;
    int j=9;
    while(n!=0)
    {
        t.num[j--]=n%2;
        n=n/2;
    }
    return t;


}
