#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    char s[101];
    scanf("%s",s);
    int x[101];
    int y[101];
    memset(x,0,sizeof(x));
    memset(y,0,sizeof(y));
    for(int i=0; i<strlen(s); i++)
    {
        switch (s[i])
        {
        case 'U':
            x[i+1]=x[i];
            y[i+1]=y[i]+1;
            break;
        case 'R':
            x[i+1]=x[i]+1;
            y[i+1]=y[i];
            break;
        case 'D':
            x[i+1]=x[i];
            y[i+1]=y[i]-1;
            break;
        case 'L':
            x[i+1]=x[i]-1;
            y[i+1]=y[i];
            break;
        }
    }
    int t;
    scanf("%d",&t);
    for (int i=0; i<t; i++)
    {
        int x1,y1;
        scanf("%d%d",&x1,&y1);
        int find=0;
        for (int j=0; j<=strlen(s)&&find==0; j++)
        {
            int x2=x1-x[j];
            int y2=y1-y[j];
            int len=strlen(s);
            if (x[len]!=0&&y[len]!=0)
            {   if ((x2%x[len]==0 && ((x2>0&&x[len]>0) || (x2<0&&x[len]<0))) && (y2%y[len]==0 && ((y2>0&&y[len]>0) || (y2<0&&y[len]<0))) && x2/x[len]==y2/y[len])
                    {find=1;}
                if (x2==0&&y2==0) find=1;

            }
            else if (x[len]==0&&y[len]==0){
                if (x2==0&&y2==0) {find=1;}
            }
            else if (x[len]==0){
                if (x2==0 && (y2%y[len]==0 && (y2>0&&y[len]>0) || (y2<0&&y[len]<0)))
                    {find=1;}
                if (x2==0&&y2==0) find=1;
            }
            else if (y[len]==0 ){
                if (y2==0 && (x2%x[len]==0 && (x2>0&&x[len]>0) || (x2<0&&x[len]<0)))
                    find=1;
                if (x2==0&&y2==0) find=1;
            }
        }
        
        if (find==1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
