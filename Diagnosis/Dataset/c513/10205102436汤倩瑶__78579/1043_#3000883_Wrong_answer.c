#include<stdio.h>
#include<string.h>

void solve(char s[])
{



}
int main()
{
    int T;
    scanf("%d",&T);
    char s[105];
    for(int i=0; i<T; i++)
    {
        scanf("%s",s);
        int l=strlen(s);
        int cnt1=0;
        int a[105]= {0};
        for(int j=0; j<l; j++)
        {
            if(s[j]!=s[j+1])a[cnt1++]=j;
        }
        for(int j=0; j<cnt1; j++)
        {
            printf("%d ",a[j]);
            char s1[105];
            int cnt=0;
            for(int k=0; k<=a[j]; k++)
            {
                s1[cnt++]=s[k];
            }

            for(int k=a[j]; k<l; k++)
            {
                s1[cnt++]=s[k];
            }
            s1[cnt]='\0';
            char ans[105];
            printf("%s\n",s1);
            int ll=strlen(s1);
            strcpy(ans,s1);
            int cnt1=1;
            int a[105]= {0};
            a[0]=-1;
            for(int k=0; k<ll; k++)
            {
                if(s1[k]!=s1[k+1])a[cnt1++]=k;
            }
            for(int k=0; k<cnt1-1; k++)
            {
              //  printf("%d ",a[i]);
              if((a[k]+1)!=a[k+1])
               {
                   for(int p=a[k]+1; p<=a[k+1]; p++)
                {
                    ans[p]='1';
                }
               }
            }
            char ans1[105];
            int cnt2=0;
            

            printf("%s\n",ans);

        }
        printf("case #%d:\n",i);
    }
}
