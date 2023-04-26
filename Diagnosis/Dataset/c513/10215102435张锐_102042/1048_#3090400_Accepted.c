#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
int main()
{
    char s1[150],s2[150];
    while(scanf("%s",&s1)!=EOF)
    {
        scanf("%s",s2);
        int x1[105]={0};int x2[105]={0};
        int len1=strlen(s1),len2=strlen(s2);
        int c=0;
        while(c<len1)
        {
            {
                int bo=1;int t=1;//系数
                if(s1[c]=='+') c++;
                else if(s1[c]=='-') bo=-1,c++;
                if(isdigit(s1[c]))
                {
                    t=s1[c]-'0';
                    while(c<len1-1&&isdigit(s1[++c])) t=t*10+s1[c]-'0';
                    if(c==len1-1) c++;
                }
                t=bo*t;
                if(c==len1)  x1[0]=t;
                else if(s1[c]=='x')
                {
                    if(s1[c+1]=='^')
                    {
                        int temp=s1[c+2]-'0';c=c+2;
                        while(isdigit(s1[++c])) temp=temp*10+s1[c]-'0';
                        x1[temp]=t;
                    }
                    else x1[1]=t,c++;
                }
            }
        }
        c=0;
        while(c<len2)
        {
            {
                int bo=1;int t=1;//系数
                if(s2[c]=='+') c++;
                else if(s2[c]=='-') bo=-1,c++;
                if(isdigit(s2[c]))
                {
                    t=s2[c]-'0';
                    while(c<len2-1&&isdigit(s2[++c])) t=t*10+s2[c]-'0';
                    if(c==len2-1) c++;
                }
                t=bo*t;
                if(c==len2)  x2[0]=t;
                else if(s2[c]=='x')
                {
                    if(s2[c+1]=='^')
                    {
                        int temp=s2[c+2]-'0';c=c+2;
                        while(isdigit(s2[++c])) temp=temp*10+s2[c]-'0';
                        x2[temp]=t;
                    }
                    else x2[1]=t,c++;
                }
            }
        }
        //for(int i=0;i<100;i++) printf("%d ",x1[i]);
        //printf("\n");
        //for(int i=0;i<100;i++) printf("%d ",x2[i]);
        //printf("\n");
        int ans[150]={0};
        for(int i=0;i<105;i++)
        {
            for(int j=0;j<105;j++)
            {
                ans[i+j]+=(x1[i]*x2[j]);
                //if(x1[i]*x2[j]!=0) printf("i=%d,j=%d,%d\n",i,j,x1[i]*x2[j]);
            }
        }
        int p=149;
        for(;;p--)
        {
            if(ans[p]!=0) break;
        }
        for(int k=p;k>=0;k--)
        {
            if(k==p) printf("%d",ans[p]);
            else if(ans[k]!=0) printf(" %d",ans[k]);
        }
        printf("\n");
    }

    return 0;
}
