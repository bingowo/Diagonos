#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[105];
    scanf("%s",s);
    int x,y,n,len=strlen(s),a[105][3]= {0};
    a[0][0]=0;
    a[0][1]=0;
    for(int i=1; i<=len; i++)
    {
        switch(s[i-1])
        {
        case 'U':
            a[i][1]=a[i-1][1]+1;
            a[i][0]=a[i-1][0];
            break;
        case 'D':
            a[i][1]=a[i-1][1]-1;
            a[i][0]=a[i-1][0];
            break;
        case 'L':
            a[i][0]=a[i-1][0]-1;
            a[i][1]=a[i-1][1];
            break;
        case 'R':
            a[i][0]=a[i-1][0]+1;
            a[i][1]=a[i-1][1];
            break;
        }
    }
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        int t,x1,y1,f=-1;
        scanf("%d %d",&x,&y);
        for(int j=0; j<=len; j++)
        {
            if(a[j][0]==x&&a[j][1]==y)
            {
                f=1;
                break;
            }
            else
            {
                x1=x-a[j][0],y1=y-a[j][1];
                if((a[len][0]==0)&&(a[len][1]==0))
                    continue;
                else if(a[len][0]==0)
                {
                    if(x1==0)
                    {
                        if((a[len][1]*y1)>0)
                            if(y1%a[len][1]==0)
                            {
                                f=1;
                                break;
                            }
                    }
                }
                else if(a[len][1]==0)
                {
                    if(y1==0)
                    {
                        if((a[len][0]*x1)>0)
                            if(x1%a[len][0]==0)
                            {
                                f=1;
                                break;
                            }
                    }

                }
                else
                {
                    if(a[len][0]>0&&a[len][1]>0)
                    {
                        if(x1>0&&y1>0)
                        {   if(x1%a[len][0]==0)
                        {

                            t=x1/a[len][0];
                            if(a[len][1]*t==y1)
                            {
                                f=1;
                                break;
                            }
                        }
                        }
                    }
                    else if(a[len][0]<0&&a[len][1]<0)
                    {
                        if(x1<0&&y1<0)
                        {    if(x1%a[len][0]==0){
                            t=x1/a[len][0];
                            if(a[len][1]*t==y1)
                            {
                                f=1;
                                break;
                            }
                        }
                        }
                    }
                    else if(a[len][0]>0&&a[len][1]<0)
                    {

                        if(x1>0&&y1<0)
                        {   if(x1%a[len][0]==0){
                            t=x1/a[len][0];
                            if(a[len][1]*t==y1)
                            {
                                f=1;
                                break;
                            }
                        }
                        }
                    }
                    else if(a[len][0]<0&&a[len][1]>0)
                    {
                        if(x1%a[len][0]==0){
                        if(x1<0&&y1>0)
                        {
                            t=x1/a[len][0];
                            if(a[len][1]*t==y1)
                            {
                                f=1;
                                break;
                            }
                        }
                        }
                    }
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
