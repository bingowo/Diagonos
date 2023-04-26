#include<stdio.h>
#include<string.h>
#define C 200
int deal(int* ans,const char* str)
{
    int R=0,B=0,Y=0,G=0;
    if(strchr(str,'R'))R=1;
    if(strchr(str,'B'))B=1;
    if(strchr(str,'Y'))Y=1;
    if(strchr(str,'G'))G=1;
    if(R&&B&&Y)return 4;
    if(R&&B&&G)return 3;
    if(R&&Y&&G)return 2;
    if(B&&Y&&G)return 1;
    return 0;
}
int main()
{
    int T,i,len;scanf("%d",&T);char s[C];
    for(int cas=0;cas<T;++cas)
    {
        scanf("%s",s);len=strlen(s);
        int ans[4]={0,0,0,0},flag;
        while(strchr(s,'!'))
        {
            for(i=0;s[i];++i)
            {
                if(s[i]=='!')
                {
                    flag=0;
                    if(!flag&&i>2)              {char str[5];str[0]=s[i-3];str[1]=s[i-2];str[2]=s[i-1];str[3]=s[i];  str[4]='\0';flag=deal(ans,str);}
                    if(!flag&&i>1&&i<len-1){char str[5];str[0]=s[i-2];str[1]=s[i-1];str[2]=s[i];  str[3]=s[i+1];str[4]='\0';flag=deal(ans,str);}
                    if(!flag&&i>0&&i<len-2){char str[5];str[0]=s[i-1];str[1]=s[i];  str[2]=s[i+1];str[3]=s[i+2];str[4]='\0';flag=deal(ans,str);}
                    if(!flag&&i<len-3)     {char str[5];str[0]=s[i];  str[1]=s[i+1];str[2]=s[i+2];str[3]=s[i+3];str[4]='\0';flag=deal(ans,str);}
                    switch (flag)
                    {
                        case 0:{break;}
                        case 1:{s[i]='R';ans[0]++;break;}
                        case 2:{s[i]='B';ans[1]++;break;}
                        case 3:{s[i]='Y';ans[2]++;break;}
                        case 4:{s[i]='G';ans[3]++;break;}
                    }
                }
            }
        }
        printf("case #%d:\n%d %d %d %d\n",cas,ans[0],ans[1],ans[2],ans[3]);
    }
    return 0;
}