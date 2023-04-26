#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[105];
    scanf("%s",s);
    int x,y,n,len=strlen(s),a[105][3]={0};
    a[0][0]=0;a[0][1]=0;
    for(int i=1;i<=len;i++)
    {
        switch(s[i-1])
        {
            case 'U':a[i][1]=a[i-1][1]+1;a[i][0]=a[i-1][0];break;
            case 'D':a[i][1]=a[i-1][1]-1;a[i][0]=a[i-1][0];break;
            case 'L':a[i][0]=a[i-1][0]-1;a[i][1]=a[i-1][1];break;
            case 'R':a[i][0]=a[i-1][0]+1;a[i][1]=a[i-1][1];break;
        }
    }
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {   int x1,y1,f=-1;
        scanf("%d %d",&x,&y);
        for(int j=0;j<=len;j++)
        {
            if(a[j][0]==x&&a[j][1]==y)
            {
                f=1;break;
            }
            else
            {   x1=a[j][0],y1=a[j][1];
                if((a[len][0]==0)&&a[len][1]==0)
                    break;
                else if(a[len][0]==0)
                {
                    while(y1<y)
                        y1+=a[len][1];
                }
                else if(a[len][1]==0)
                {
                    while(x1<x)
                        x1+=a[len][0];
                }
                else{
                while(x1<x&&y1<y)
                {
                    x1+=a[len][0];
                    y1+=a[len][1];
                }
                }
                if(x1==x&&y1==y)
                {
                    f=1;break;
                }
            }
        }
        if(f==1)
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}
