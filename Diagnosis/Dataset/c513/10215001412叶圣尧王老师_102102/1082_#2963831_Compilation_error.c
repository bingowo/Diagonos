#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

void input(char *s,char *da,char *fa)
{
    int k=-1;
    for(int i=0;i<strlen(s);i++)if(s[i]=='.'){k=i;break;}
    if(k==-1){strcpy(da,s);fa[1]='\0';}
    else if(k==strlen(s)-1){s[k]='\0';strcpy(da,s);fa[1]='\0';}
    else if(k==0){strcpy(fa,s+1);da[1]='\0';}
    else
    {
        s[k]='\0';
        strcpy(da,s);
        strcpy(fa,s+k+1);
    }
}

int main()
{
    char da[501]={'0'},db[501]={'0'},fa[501]={'0'},fb[501]={'0'};char s[501];
    char out_d[501]={'\0'},out_f[501]={'\0'};
    scanf("%s",s);input(s,da,fa);
    scanf("%s",s);input(s,db,fb);
    int d=0,k,i;scanf("%d",&k);
    if(strlen(da)<strlen(db)){strcpy(s,da);strcpy(da,db);strcpy(db,s);}
    int len_da=strlen(da),len_db=strlen(db);
    if(strlen(fa)<strlen(fb)){strcpy(s,fa);strcpy(fa,fb);strcpy(fb,s);}
    int len_fa=strlen(fa),len_fb=strlen(fb);
    if(k>=len_fb&&k<len_fa)
    {
        i=k-1;out_f[k]='\0';
        if(fa[k]>'4')d=1;
    }
    else i=len_fa-1;
    for(;i>len_fb-1;i--)
    {
        out_f[i]=(fa[i]-'0'+d)%10+'0';
        d=(fa[i]-'0'+d)/10;
    }
    for(;i>=0;i--)
    {   out_f[i]=(fa[i]-'0'+fb[i]-'0'+d)%10+'0';
        d=(fa[i]-'0'+fb[i]-'0'+d)/10;
    }
    if(k>len_fb)
    {
        out_f[k]='\0';
        for(i=k-1;i>=len_fa;i--)out_f[i]='0';
    }
    else if(k<len_fa)
    {
        for(i=k-1;i>=0;i--)
        {
            out_f[i]=(out_f[i]-'0'+d)%10+'0';
            d=(out_f[i]-'0'+d)/10;
        }
    }
    for(i=len_da-1;i>len_db;i--)
    {
        out_d[i]=(da[i]-'0'+db[i]-'0'+d)%10+'0';
        d=(da[i]-'0'+db[i]-'0'+d)/10;
    }
    for(;i>=0;i--)
    {
        out_d[i]=(da[i]-'0'+d)%10;
        d=(da[i]-'0'+d)/10;
    }
    if(d==1)printf("1")
    printf("%s.%s",out_d,out_f);
   
}