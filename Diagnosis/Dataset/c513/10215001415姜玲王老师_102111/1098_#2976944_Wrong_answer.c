#include <stdio.h>
#include <stdlib.h>
#include<string.h>
int main()
{
    int n,j;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("case #%d:\n",i);
        char a[101];
        int R=0,B=0,Y=0,G=0,r=-1,b=-1,y=-1,g=-1,j;
        scanf("%s",a);
        int t=strlen(a);
        for(j=0;j<t;j++)
        {
           if(!strstr(a,"R")) break;
            if(a[j]=='R') {r=j%4;break;}
        }
        for(j=0;j<t;j++)
        {
           if(!strstr(a,"B")) break;
            if(a[j]=='B') {b=j%4;break;}
        }
        for(j=0;j<t;j++)
        {
           if(!strstr(a,"Y")) break;
            if(a[j]=='Y') {y=j%4;break;}
        }
        for(j=0;j<t;j++)
        {
           if(!strstr(a,"G")) break;
            if(a[j]=='G') {g=j%4;break;}
        }
        if(r==-1){r=6-b-y-g;}
        if(b==-1){b=6-r-y-g;}
        if(y==-1){y=6-r-b-g;}
        if(g==-1){g=6-r-y-b;}
        for(j=0;j<t;j++)
        {{if(a[j]=='!')
        {if(a[j]%4==r)R++;
        if(a[j]%4==b)B++;
        if(a[j]%4==y)G++;
        if(a[j]%4==r)R++;}
        }

        }
        printf("%d %d %d %d\n",R,B,Y,G);
    }
}
