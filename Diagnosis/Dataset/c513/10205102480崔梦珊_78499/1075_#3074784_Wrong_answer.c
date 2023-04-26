#include<stdio.h>
#include<string.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int q[201][201]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&q[i][j]);
        }
    }
    int ans[201][201]={0};
    ans[0][0]=q[0][0];
    //char s[201][201][401]={0};
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==0&j==0)
            {
                continue;
            }
            else if(i==0)
            {
                /*int len=strlen(s[i][j]);
                for(int k=0;k<len;k++)
                {
                    s[i][j][k]=s[i][j-1][k];
                }
                s[i][j][len]='R';*/
                ans[i][j]=ans[i][j-1]+q[i][j];
                continue;
            }
            else if(j==0)
            {
                /*int len=strlen(s[i][j]);
                for(int k=0;k<len;k++)
                {
                    s[i][j][k]=s[i-1][j][k];
                }
                s[i][j][len]='D';*/
                ans[i][j]=ans[i-1][j]+q[i][j];
                continue;
            }
            else
            {
                int temp1=ans[i-1][j]+q[i][j];
                int temp2=ans[i][j-1]+q[i][j];
                if(temp1<temp2)
                {
                    ans[i][j]=temp1;
                    /*int len=strlen(s[i][j]);
                    for(int k=0;k<len;k++)
                    {
                        s[i][j][k]=s[i-1][j][k];
                    }
                    s[i][j][len]='D';*/
                }
                else
                {
                    ans[i][j]=temp2;
                    /*int len=strlen(s[i][j]);
                    for(int k=0;k<len;k++)
                    {
                        s[i][j][k]=s[i][j-1][k];
                    }
                    s[i][j][len]='R';*/
                }
            }
        }
    }
    printf("%d\n",ans[m-1][n-1]);
    int i=m-1;
    int j=n-1;
    char s[500]={0};
    int flag=m+n-2;
    int f=0;
    while(i!=0||j!=0)
    {
        if(i>0&&j>0)
        {
            if(ans[i-1][j]<ans[i][j-1])
            {
                s[flag]='D';
                flag--;
                i--;
            }
            else
            {
                s[flag]='R';
                flag--;
                j--;
            }
            continue;
        }
        else if(i==0)
        {
            s[flag]='R';
            flag--;
            j--;
            f=6;
            continue;
        }
        else
        {
            s[flag]='D';
            flag--;
            i--;
            f=7;
            continue;
        }

    }
    if(f==6) s[0]='R';
    if(f==7) s[0]='D';

    printf("%s",s);

}
