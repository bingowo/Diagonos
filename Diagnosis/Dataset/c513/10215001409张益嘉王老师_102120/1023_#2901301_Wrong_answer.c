#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int splitstring(char zong[],char sign,char* fen[],int maxn)
{
    int len,i,co=0;
    len=strlen(zong);
    fen[co++]=zong;
    for(i=0;i<len;i++)
    {
        if(zong[i]==sign)
        {
            zong[i]=0;
            fen[co++]=&zong[i+1];
            if(co>=maxn) break;
        }

    }
    return co;

}

int strnumcmp(char*a,char*b)
{
    int lena,lenb,signa=0,signb=0,i,nofa=0,nofb=0,sta,stb;
    lena=strlen(a);
    lenb=strlen(b);
    for(i=0;i<lena;i++)
    {
        if((a[i]<='9')||(a[i]>='0')) signa++;
    }
    for(i=0;i<lenb;i++)
    {
        if((b[i]<='9')||(b[i]>='0')) signb++;
    }

    if((signa==0)&&(signb==0)) return strcmp(a,b);
    else if((signa>0)&&(signb==0)) return -1;
    else if((signb>0)&&(signa==0)) return 1;
    else
    {
            for(i=0;i<lena;i++)
            {
                if((a[i]<='9')||(a[i]>='0')) {sta=i;break;}
            }
            for(i=0;i<lenb;i++)
            {
                if((b[i]<='9')||(b[i]>='0')) {stb=i;break;}
            }
            for(i=sta;i<sta+signa;i++)
            {
                nofa*=10;
                nofa+=a[i]-'0';
            }
            for(i=stb;i<stb+signb;i++)
            {
                nofb*=10;
                nofb+=b[i]-'0';
            }
            if(nofa>nofb) return 1;
            else if(nofa<nofb) return -1;
            else return strcmp(a,b);
    }
}

int cmp(const void*a,const void*b)
{
    char* aa=*((char**)a);
    char* bb=*((char**)b);

    return strnumcmp(aa,bb);

}

int main()
{
    char s[4000];
    char* fs[100];
    int co,i;
    gets(s);
    co=splitstring(s,' ',fs,100);
    qsort(fs,co,sizeof(char*),cmp);
    for(i=0;i<co-1;i++)
    {
        printf("%s ",fs[i]);
    }
    printf("%s",fs[i]);

}
