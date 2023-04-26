#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 55
/***
void float_Add(char* a,char* b)
{
    char* ret=a;
    int lena=strlen(a),lenb=strlen(b);
    int len=lena>lenb?lena:lenb;
    int jin=0;
    for(int i=len-1;i>=2;++i){
        int t1=i<lena?a[i]-'0':0;
        int t2=i<lenb?b[i]-'0':0;
        int s=t1+t2+jin;
        ret[i]=s%10;
        jin=s/10;
    }
    out[1]='.';
    out[0]='0';
}


double Eight_float(char s[])
{
    double weight=8.0,ret=0;
    int len = strlen(s);
    for(int i=2;i<len;++i){
        ret=ret+(s[i]-'0')/weight;
        weight*=8;
    }
    return ret;
}
***/
void Divide(char* s)
{
    int flag=strlen(s);
    for(int i=flag;i<154;++i)s[i]='0';
    s[154]=0;
    int f2;
    for(int i=153;i>=2;--i){
        if(s[i]!='0'){f2=i;break;}
    }
    char dec[155]={0};
    dec[0]='0';dec[1]='.';
    int digit=s[0]-'0';
    int yu=1,j=2,_i=2;
    if(s[0]=='0'){
        while(s[_i]=='0'){
            dec[j++]='0';
            _i++;
        }
        if(s[_i]<'8'){
            digit=s[_i++]-'0';
            dec[j++]='0';}

    }
    for(int i=_i;yu||i<=f2;++i){
        digit=10*digit+s[i]-'0';
        dec[j++]=digit/8+'0';
        digit=yu=digit%8;
    }
    dec[j]=0;
    //printf("%s\n",dec);
    strcpy(s,dec);
}

int main()
{
   int T,x=0;
   scanf("%d\n",&T);
   while(x<T){
        char s[N]={0},ret[N*3]={0};
        scanf("%s",s);
        int len=strlen(s)-1;
        for(;len>=2;--len){
            ret[0]=s[len];
            Divide(ret);
        }
        printf("case #%d:\n",x++);
        printf("%s\n",ret);

   }
   return 0;
}