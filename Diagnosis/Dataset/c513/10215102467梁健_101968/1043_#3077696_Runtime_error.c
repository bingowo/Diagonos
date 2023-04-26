#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>
void insert(char *s,char *jud,char p,int i)
{
    int len=strlen(s),cnt=0;
    for(int j=0;j<=i;j++){
        jud[cnt++]=s[j];
    }
    jud[cnt++]=p;
    for(int j=i+1;j<len;j++){
        jud[cnt++]=s[j];
    }
    jud[cnt]=0;
}
int judge(char *s)
{
    int res=0,len=strlen(s);
    char c[120];
    strcpy(c,s);
    while(1)
    {
        char jud[120];
        int cnt=0;
        {
            if(c[0]!=c[1])jud[cnt++]=c[0];
            for(int i=1;i<strlen(c)-1;i++){
                if(c[i]!=c[i+1]&&c[i]!=c[i-1])jud[cnt++]=c[i];
            }
            if(c[strlen(c)-2]!=c[strlen(c)-1])jud[cnt++]=c[strlen(c)-1];
            jud[cnt]=0;
            if(cnt==strlen(c)||strlen(c)==1)break;
            else{
                res+=(strlen(c)-cnt);
                //printf("c=%s jud=%s res=%d\n",c,jud,res);
                strcpy(c,jud);
            }
        }
    }
    return res;
}
void solve(char *s)
{
    int res=0,len=strlen(s);
    for(int i=0;i<len-1;i++){
        for(char p='A';p<='C';p++){
            char jud[120];
            insert(s,jud,p,i);
            int cnt=judge(jud);
            if(cnt>res)res=cnt;
        }
        if(res==len+1)break;
    }
    printf("%d\n",res);
    return 0;
}
int main()
{
    int T;scanf("%d",&T);
    for(int pp=0;pp<T;pp++)
    {
        printf("case #%d:\n",pp);
        char s[120];scanf("%s",s);
        solve(s);
    }
    return 0;
}
