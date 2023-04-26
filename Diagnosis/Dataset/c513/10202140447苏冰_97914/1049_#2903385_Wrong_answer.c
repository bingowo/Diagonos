#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char s[255][255];
int cmp(const void* p,const void* q)
{
    char* a=(char*)p;
    char* b=(char*)q;
    return strcmp(a,b);
}
int main()
{
    int T;
    scanf("%d",&T);
    getchar();
    char c;
    int flag=0,num=0,sign=0;;
    for(int cas=0;cas<T;cas++)
    {
        flag=0;num=0;sign=0;
        for(int i=0;;i++)
        {
            for(int j=0; ;j++)
            {
                c=getchar();
                if(c==' ' || c==',' || c=='.' || c=='!' || c=='?')
                {
                    s[i][j]='\0';
                    sign=1;
                    num++;break;
                }
                else if(c=='\n')
                {
                    if(sign==0) num++;
                    flag=1;break;
                }
                else
                    s[i][j]=c;
            }
            if(flag) break;
        }
        qsort(s,num,sizeof(s[0]),cmp);
        printf("case #%d:\n",cas);
        for(int i=0;i<num-1;i++)
        {
            if(strcmp(s[i],s[i+1])==0) continue;
            else if(strlen(s[i])!=0) printf("%s ",s[i]);
        }
        printf("%s\n",s[num-1]);
    }
    return 0;
}
