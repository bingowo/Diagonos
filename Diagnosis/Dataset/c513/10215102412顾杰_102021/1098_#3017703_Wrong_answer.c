#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<math.h>
#include<malloc.h>
#include<ctype.h>
//#include "myh.h"

int main()
{
    int n;
    scanf("%d\n",&n);
    for(int i=0;i<n;i++)
    {
        char s[200];
        scanf("%s",s);
        int ans[4]={0},p=0,f=1,temp,pos;
        while(f)
        {
            int num=0,t[4]={0};
            for(int j=0;j<4;j++)
        {
            switch (s[p+j])
            {
                case '!':pos=p+j;num++;temp=-1;break;
                case 'R':temp=0;break;
                case 'B':temp=1;break;
                case 'Y':temp=2;break;
                case 'G':temp=3;break;
                default :f=0;
            }
            if(temp>=0)t[temp]=1;
        }
        if(num==1){int j;for(j=0;j<4&&t[j];j++);p=0;if(j==0)s[pos]='R';if(j==1)s[pos]='B';if(j==2)s[pos]='Y';if(j==3)s[pos]='G';ans[j]++;}
        else p++;
        }
        printf("case #%d:\n",i);
        for(int j=0;j<4;j++)printf("%d ",ans[j]);

    }
}
