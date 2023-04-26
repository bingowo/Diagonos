#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    char tb[3]={'A','B','C'};
    int T;scanf("%d",&T);
    for(int t=0;t<T;t++)
    {
        char s[101];
        scanf("%s",s);int max=0;
        for(int j=0;j<strlen(s);j++)
        {
            for(int k=0;k<3;k++)
            {
                char s1[strlen(s)+2];
                strcpy(s1,s);s1[j]=tb[k];strcpy(s1+j+1,s+j);int deth=0,num=0;
                while(deth!=1)
                {
                    deth=1;
                    int i,i1=0,i2=0;
                    for(i=1;i<strlen(s1);i++)
                    {
                        if(s1[i]!=s1[i-1])i1=i;
                        if(s1[i]==s1[i-1])
                         {
                             deth=1;
                             while(s1[i]==s1[i-1]&&i<strlen(s1)){i2=i;i++;deth++;}
                             strcpy(s1+i1,s1+i);
                             i=i1;
                             if(deth!=1)num+=deth;
                         }
                    }
                }
                max=max>num?max:num;
            }
        }
        printf("case #%d:\n%d",t,max);
    }
}
