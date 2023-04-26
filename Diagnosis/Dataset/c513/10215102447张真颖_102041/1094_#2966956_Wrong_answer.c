#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* pa,const void* pb)
{
    char *a=*(char(*)[121])pa,*b=*(char(*)[121])pb;
    int signa=0,signb=0;
    if(a[0]=='-') signa=1;
    if(b[0]=='-') signb=1;
    if((strlen(a)-signa)>(strlen(b)-signb)) return -1;
    else if((strlen(a)-signa)<(strlen(b)-signb)) return 1;
    else
    {
        for(int ia=signa,ib=signb;ia<strlen(a)-signa;ia++,ib++)
        {
            if(a[ia]>b[ib]) return -1;
            else if(a[ia]<b[ib]) return 1;
        }
        return 0;
    }
}

void distance(char* a,char* b,int r[])
{
    int signa=0,signb=0;
    if(a[0]=='-') signa=1;
    if(b[0]=='-') signb=1;
    if(signa-signb==1||signb-signa==1)
    {
        int cnt=121,carry=0,ia,ib;
        for(ia=strlen(a)-1,ib=strlen(b)-1;ia>=signa&&ib>=signb;ia--,ib--,cnt--)
        {
            int tmp=a[ia]-'0'+b[ib]-'0'+carry;
            r[cnt]=tmp%10;
            carry=tmp/10;
        }
        while(ia>=signa)
        {
            int tmp=a[ia]-'0'+carry;
            r[cnt]=tmp%10;
            carry=tmp/10;
            ia--;
            cnt--;
        }
        if(carry)
            r[cnt]=carry,cnt--;
    }
    else
    {
        int cnt=121,carry=0,ia,ib;
        for(ia=strlen(a)-1,ib=strlen(b)-1;ia>=signa&&ib>=signb;ia--,ib--,cnt--)
        {
            int tmp=a[ia]-b[ib]-carry;
            if(tmp<0) tmp+=10,carry=1;
            else carry=0;
            r[cnt]=tmp;
        }
        while(ia>=signa)
        {
            int tmp=a[ia]-'0'-carry;
            if(tmp<0) tmp+=10,carry=1;
            else carry=0;
            r[cnt]=tmp;
            cnt--;
            ia--;
        }
    }
}

int main()
{
    int n=0;
    scanf("%d",&n);
    char s[50][121]={0};
    for(int i=0;i<n;i++)
        scanf("%s",s[i]);
    qsort(s,n,sizeof(s[0]),cmp);
    int r[122]={0};
    distance(s[0],s[n-1],r);
    int i=0;
    while(r[i]==0) i++;
    for(;i<122;i++)
        printf("%d",r[i]);
    return 0;
}