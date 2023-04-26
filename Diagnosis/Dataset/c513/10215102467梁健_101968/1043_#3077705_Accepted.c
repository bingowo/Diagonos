#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<ctype.h>

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
            else res++;
            for(int i=1;i<strlen(c)-1;i++){
                if(c[i]!=c[i+1]&&c[i]!=c[i-1])jud[cnt++]=c[i];
                else res++;
            }
            if(c[strlen(c)-2]!=c[strlen(c)-1])jud[cnt++]=c[strlen(c)-1];
            else res++;
            jud[cnt]=0;
            if(cnt==strlen(c)||strlen(c)==1||cnt==0)break;
            else strcpy(c,jud);
                //printf("c=%s jud=%s res=%d\n",c,jud,res);
        }
    }
    return res;
}
void solve(char *s)
{
    int res=0,len=strlen(s);
    for(int i=1;i<len;i++){
        for(char p='A';p<='C';p++){
            char jud[120];
            for(int t=0;t<i;t++){
                jud[t]=s[t];
            }
            for(int t=i;t<strlen(s);t++){
                jud[t+1]=s[t];
            }
            jud[strlen(s)+1]=0;
            for(char p='A';p<='C';p++){
                jud[i]=p;
                int cnt=judge(jud);
                if(cnt>res)res=cnt;
            }
        }
        if(res==len+1)break;
    }
    printf("%d\n",res);
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
