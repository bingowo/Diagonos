#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int h;
    int m;
    int s;
}time;

int splitstring(char s[],char sign,char *word[],int nmax)
{
    int co=0,i,len=strlen(s);
    word[co++]=s;
    for(i=0;i<len;i++)
    {
        if(s[i]==sign)
        {
            s[i]=0;
            word[co++]=&s[i+1];
        }
        if(co>=nmax) break;
    }
    return co;
}

int jiaoyanhe(char s[])
{
    int i,len=strlen(s),re=0;
    for(i=1;i<len;i++)
    {
        if(s[i]==',') continue;
        if(s[i]=='*') break;
        re^=s[i];
    }
    return re;
}

int quzhi(char s[])
{
    int i,len=strlen(s),re=0,st;
    for(i=0;i<len;i++)
    {
        if(s[i]=='*') {st=i+1;break;}
    }
    for(i=st;i<len;i++)
    {
        re*=16;
        re+=s[i]-'0';
    }
    return re;
}

time shijian(char s[])
{
    int i;
    time re;
    re.h=0;
    re.m=0;
    re.s=0;
    //printf("timeword=%s\n",s);
    for(i=0;i<2;i++)
    {
        re.h*=10;
        re.h+=s[i]-'0';
    }
    for(i=2;i<4;i++)
    {
        re.m*=10;
        re.m+=s[i]-'0';
    }
    for(i=4;i<6;i++)
    {
        re.s*=10;
        re.s+=s[i]-'0';
    }
    //printf("test %d:%d:%d\n",re.h,re.m,re.s);
    return re;

}

int main()
{
    time a;
    while(1)
    {
        char s[200];
        memset(s,0,sizeof(char)*200);
        gets(s);
        if(!strcmp(s,"END")) break;
        int yihuo=jiaoyanhe(s);
        int zhi=quzhi(s);
        if(yihuo==zhi);
        else continue;
        char *word[50];
        int co,i;
        co=splitstring(s,',',word,50);
        /*for(i=0;i<co;i++)
        {
            printf("%s\n",word[i]);
        }*/
        if(!strcmp(word[2],"V")) continue;
        if(strcmp(word[0],"$GPRMC")) continue;

        a=shijian(word[1]);
        a.h+=8;
        a.h%=24;
    }
    printf("%02d:%02d:%02d",a.h,a.m,a.s);
    return 0;
}
