#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    char s[200];
    scanf("%s",s);
    int len=strlen(s);
    int **p1=(int **)malloc((len+1)*sizeof(int*));
    for(int i=0;i<=len;i++)
    {
        p1[i]=(int*)malloc(sizeof(int)*2);
    }
    int pa=0,pb=0;
    p1[0][0]=0;p1[0][1]=0;
    for(int f=0;f<len;f++)
    {
        if(s[f]=='U') pb++;
        if(s[f]=='D') pb--;
        if(s[f]=='L') pa--;
        if(s[f]=='R') pa++;
        p1[f+1][0]=pa,p1[f+1][1]=pb;
    }
    int x=p1[len][0],y=p1[len][1];
    int n;
    scanf("%d",&n);
    int bo=0;
    for(int i=0;i<n;i++)
    {
        bo=0;
        int a,b;
        scanf("%d%d",&a,&b);
        for(int j=0;j<=len;j++)
        {
            if(a==p1[j][0]&&b==p1[j][1]) {bo=1;break;}
        }
        if(bo==0)
        {
            if(x==0&&y!=0)
            {
                for(int j=0;j<=len;j++)
                {
                    int temp=b-p1[j][1];
                    if(temp%y==0&&a==p1[j][0]&&temp/y>=0) bo=1;
                }
            }
            else if(x!=0&&y==0)
            {
                for(int j=0;j<=len;j++)
                {
                    int temp=a-p1[j][0];
                    if(temp%x==0&&b==p1[j][1]&&temp/x>=0) {bo=1;break;}
                }
            }
            else
            {
                for(int j=0;j<=len;j++)
                {
                    int temp1=b-p1[j][1];int temp2=a-p1[j][0];
                    if(temp1%y==0&&temp2%x==0&&temp1/y==temp2/x&&temp1/y>=0){bo=1;break;
                }
            }
        }
        }
        if(bo==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
