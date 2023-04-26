#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct {int dec[105]; int bin[335]; int cnt;}Big;
void decTurnToBin(Big *n)
{
    int i=0, j, lend=0, all, check, c=0;
    for(j=0; j<335; j++) n->bin[j]=0;
    while(n->cnt)
    {
        lend=0; 
        n->bin[i++]+=(n->dec[0])%2;
        if(n->dec[n->cnt-1]<2){n->cnt--;lend=1;check=1;}
        for(j=n->cnt-1; j>=0; j--)
        {
            if(n->cnt>1) all=lend*10+n->dec[j];
            else if(check==1) all=lend*10+n->dec[j];
            else all=n->dec[j];
            n->dec[j]=all/2;
            lend=all%2;
            check=0;
        }
    }
    n->cnt=i;
}
void binTurnToDec(Big *n)
{
    int i, j, k;
    for(i=0; i<n->cnt; i++)
        {if(n->bin[i]) break;}
    for(j=0; j<105; j++) n->dec[j]=0;
    for(; i<n->cnt; i++)
    {
        int add=0;
        for(k=0; k<104; k++)
        {
            n->dec[k]*=2;
            n->dec[k]+=add;
            add=n->dec[k]/10;
            n->dec[k]%=10;
        }
        n->dec[0]+=n->bin[i];
        for(k=0; k<104; k++) 
            if(n->dec[k]>9)
            {
                n->dec[k+1]+=n->dec[k]/10;
                n->dec[k]%=10;
            }
    }
}
int main()
{
    int T, I;
    scanf("%d",&T);
    getchar();
    for(I=0; I<T; I++)
    {
        Big n;
        char num[105];
        gets(num);
        int l=strlen(num), i;
        for(i=0; i<105; i++) n.dec[i]=0;
        for(i=0; i<335; i++) n.bin[i]=0;
        for(i=0; i<l; i++)
            n.dec[i]=num[l-i-1]-'0';
        n.cnt=i;
        if(l==1 && num[0]=='0') n.cnt=0;
        if(n.cnt)decTurnToBin(&n);
        if(n.cnt)binTurnToDec(&n);
        printf("case #%d:\n",I);
        for(i=104; i+1; i--) if(n.dec[i]) break;
        for(; i+1; i--) printf("%d",n.dec[i]);
        if(n.cnt==0) printf("0");
        printf("\n");
    }
}