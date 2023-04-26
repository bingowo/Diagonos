#include<stdlib.h>
#include<string.h>
int main()
{
    long long int nums[30];
    for(int i=0;i<30;i++) nums[i]=0;
    char cmd[5],x1[50],x2[50],x3[50];
    int i;
    while(~scanf("%s %s",cmd,x1))
    {
        if(cmd[0]=='I'&&cmd[1]=='N')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            nums[x1[0]-'A']=atoi(x2);
            continue;
            }
        }
        if(cmd[0]=='O'&&cmd[1]=='U')
        {
            printf("%lld\n",nums[x1[0]-'A']);
            continue;
        }
        if(cmd[0]=='X'&&cmd[1]=='C')
        {
           for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']+=atoi(x2);
            else
            {
                int t;
                t=nums[x2[0]-'A'];
                nums[x2[0]-'A']=nums[x1[0]-'A'];
                nums[x1[0]-'A']=t;
            }
            continue;
        }
        if(cmd[0]=='A'&&cmd[1]=='D')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']+=atoi(x2);
            else nums[x1[0]-'A']+=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']+nums[x1[6]-'A'];
            }
        }
        if(cmd[0]=='M'&&cmd[1]=='U')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']*=atoi(x2);
            else nums[x1[0]-'A']*=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']*nums[x1[6]-'A'];
            }
        }
        if(cmd[0]=='S'&&cmd[1]=='U')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']-=atoi(x2);
            else nums[x1[0]-'A']-=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']-nums[x1[6]-'A'];
            }
        }
         if(cmd[0]=='M'&&cmd[2]=='V')
        {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            nums[x1[0]-'A']=nums[x2[0]-'A'];
            continue;
        }
         if(cmd[0]=='D'&&cmd[1]=='I')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']/=atoi(x2);
            else nums[x1[0]-'A']/=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']/nums[x1[6]-'A'];
            }
        }
        if(cmd[0]=='M'&&cmd[2]=='D')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']%=atoi(x2);
            else nums[x1[0]-'A']%=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']%nums[x1[6]-'A'];
            }
        }
        if(cmd[0]=='A'&&cmd[1]=='N')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']&=atoi(x2);
            else nums[x1[0]-'A']&=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']&nums[x1[6]-'A'];
            }
        }
        if(cmd[0]=='O'&&cmd[1]=='R')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']|=atoi(x2);
            else nums[x1[0]-'A']|=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']|nums[x1[6]-'A'];
            }
        }
        if(cmd[0]=='X'&&cmd[2]=='R')
        {
            int cou=0;
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') cou++;
            if(cou==1)
            {
            for(i=0;i<strlen(x1);i++) if(x1[i]==',') break;
            i++;
            int p=0;
            for(;i<strlen(x1);i++) x2[p++]=x1[i];
            x2[p]='\0';
            if(x2[0]>='0'&&x2[0]<='9') nums[x1[0]-'A']^=atoi(x2);
            else nums[x1[0]-'A']^=nums[x2[0]-'A'];
            continue;
            }
            else
            {
                nums[x1[0]-'A']=nums[x1[3]-'A']^nums[x1[6]-'A'];
            }
        }
    }
}