#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    int nums[4];
    char cmd[5],x1[5],x2[5];
    int i;
    while(~scanf("%s",cmd))
    {
        if(cmd[0]=='I')
        {
            scanf("%s",x1);
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            nums[x1[0]-'A']=atoi(x2);
            continue;
        }
        if(cmd[0]=='O')
        {
            scanf("%s",x1);
            printf("%d",nums[x1[0]-'A']);
            continue;
        }
        if(cmd[0]=='A')
        {
            scanf("%s",x1);
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']+=atoi(x2);
            else nums[x1[0]-'A']+=nums[x2[0]-'A'];
            continue;
        }
        if(cmd[0]=='M'&&cmd[1]=='U')
        {
             scanf("%s",x1);
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']*=atoi(x2);
            else nums[x1[0]-'A']*=nums[x2[0]-'A'];
            continue;
        }
        if(cmd[0]=='S')
        {
             scanf("%s",x1);
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']-=atoi(x2);
            else nums[x1[0]-'A']-=nums[x2[0]-'A'];
            continue;
        }
         if(cmd[0]=='M'&&cmd[1]=='O')
        {
             scanf("%s",x1);
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            nums[x1[0]-'A']*=nums[x2[0]-'A'];
            continue;
        }
         if(cmd[0]=='D')
        {
             scanf("%s",x1);
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']/=atoi(x2);
            else nums[x1[0]-'A']/=nums[x2[0]-'A'];
            continue;
        }
    }
}