#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct
{
    int cnt;
    int v[109];
}big;

void DIV2(big *n)
{
    int carry=0;
    if(n->v[n->cnt-1]<2){
        carry=1;
        n->cnt--;
    }
    for(int i=n->cnt-1;i>=0;i--){
        int t=10*carry+n->v[i];
        n->v[i]=t/2;
        carry=t%2;
    }
}

void ADD1(big *n)
{
    int carry=0,i=1;
    n->v[0]++;
    carry=n->v[0]/10;
    n->v[0]%=10;
    while(carry&&i<n->cnt){
        n->v[i]+=carry;
        carry=n->v[i]/10;
        n->v[i]%=10;
        i++;
    }
    if(carry){
        n->v[i]=carry;
        n->cnt++;
    }
}

int main()
{
    char s[109];
    scanf("%s",s);
    big n={0,{0}};
    int len=strlen(s);
    int sign=1;
    for(int i=len-1;i>=1;i--){
        n.v[n.cnt++]=s[i]-'0';
    }
    if(s[0]=='-')sign=-1;
    else n.v[n.cnt++]=s[0]-'0';
    int bin[409]={0};
    int cnt=0;
    while(n.cnt>0){
        int temp=n.v[0]%2;
        bin[cnt++]=temp;
        DIV2(&n);
        if(sign==-1&&temp){
            if(n.cnt==0){
                n.cnt++;
                n.v[0]=1;
            }
            else ADD1(&n);
        }
        sign=-sign;
    }
    for(int i=cnt-1;i>=0;i--){
        printf("%d",bin[i]);
    }
    printf("\n");
    return 0;
}