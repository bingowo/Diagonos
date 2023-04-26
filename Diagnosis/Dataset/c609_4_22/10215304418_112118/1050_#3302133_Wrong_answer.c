#include <stdio.h>
#include <stdlib.h>

int a[1234],b[1234];
int c[1234];

int main()
{
    char sta[1234],stb[1234];
    int n;
    scanf("%s %s %d",sta,stb,&n);
    int lena=strlen(sta),lenb=strlen(stb);
    int dota=-1,dotb=-1;
    for (int i=0;i<lena;i++){
        if (sta[i]=='.') dota=i;
    }
    if (dota==-1) dota=lena;
    for (int i=0;i<lenb;i++){
        if (stb[i]=='.') dotb=i;
    }
    if (dotb==-1) dotb=lenb;
    int dot;
    if (dota>dotb) dot=dota;
    else dot=dotb;
    for (int i=dota-1;i>=0;i--){
        a[dot+i-dota+1]=sta[i]-'0';
    }
    for (int i=dota+1;i<lena;i++){
        a[dot+i-dota]=sta[i]-'0';
    }
    for (int i=dotb-1;i>=0;i--){
        b[dot+i-dotb+1]=stb[i]-'0';
    }
    for (int i=dotb+1;i<lenb;i++){
        b[dot+i-dotb]=stb[i]-'0';
    }
    int left=0;
    for (int i=lena+lenb;i>=0;i--){
        c[i]=(left+a[i]+b[i])%10;
        left=(a[i]+b[i]+left)/10;
    }
    int i=dot+n+1;
    if (c[i]>=5) c[i-1]++;
    i--;
    while (c[i]==10){
        c[i]=0;
        c[i-1]++;
        i--;
    }
    i=0;
    while (c[i]==0) i++;
    if (dot==0) printf("0.");
    for (;i<=dot+n;i++){
        printf("%d",c[i]);
        if (i==dot) printf(".");
    }
    printf("\n");
    return 0;
}
