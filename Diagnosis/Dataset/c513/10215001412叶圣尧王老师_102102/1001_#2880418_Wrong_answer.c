#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char *jz="0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F,G,H,I,J,K,L,M,N,O,P,Q,R,S,T,U,V,W,X,Y,Z";
int main()
{
    char c[100];int num=12;
    sprintf(c,"%d",2);
    printf("%s",c);
}

void zhuan(int N,int R)
{
    int c;char str1[100];int i=0,k;
    while(N>0)
    {
        c=N%R;str1[i]=jz[c];
        N=N/R;
        i++;
    }str1[i]='\0';
    for(k=i-1;k>=0;k--)printf("%c",str1[k]);
}
