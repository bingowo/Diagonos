#include<stdio.h>
#include<string.h>
#define N 505

void reverse(char* s)
{
    char temp;
    for(int i=0,j=strlen(s)-1;i<j;++i,--j){
        temp=s[i];s[i]=s[j];s[j]=temp;
    }
}

int compare(char* s,char* t)
{
    int ls=strlen(s),lt=strlen(t);
    if(ls<lt)return 1;
    else if(ls==lt){
        if(strcmp(s,t)<0)return 1;
        else return 0;
    }
    else return 0;
}

int main()
{
    char ss[N];char tt[N];
    while(scanf("%s %s",ss,tt)!=EOF){
        int sign=1;
        char t[N];char s[N];
        for(int i=0;i<N;++i)t[i]=s[i]=0;
        if(compare(ss,tt)){
            strcpy(t,ss);strcpy(s,tt);sign=0;
        }
        else{strcpy(s,ss);strcpy(t,tt);}
        reverse(s);reverse(t);
        int a[N];int b[N];char ret[N];
        for(int i=0;i<N;++i)a[i]=b[i]=ret[i]=0;
        int lens=strlen(s),lent=strlen(t);
        for(int i=0;i<lens;++i)a[i]=s[i]-'0';
        for(int i=0;i<lent;++i)b[i]=t[i]-'0';
        int m=lens>lent?lens:lent;
        int p=0,pr=0;
        for(int i=0;i<m-1;++i){
            if(a[i]>=b[i])ret[p++]=a[i]-b[i]+'0';
            else {
                a[i]+=10;a[i+1]--;
                ret[p++]=a[i]-b[i]+'0';
            }
        }
        if(a[m-1]>=b[m-1])ret[p++]=a[m-1]-b[m-1]+'0';
        else{
            a[m-1]+=10;
            ret[p++]=a[m-1]-b[m-1]+'0';
            ret[p++]='-';
        }
        p--;
        char out[N];for(int i=0;i<N;++i)out[i]=0;
        while(ret[p]=='0')p--;if(p<0)ret[p++]='0';
        if(sign==0)ret[++p]='-';
        for(int k=p;k>-1;--k)out[pr++]=ret[k];
        //if(sign==0)out[pr]='-';
        printf("%s\n",out);
    }
    return 0;
}
