#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct{char s[3];int n;} Register;
int main()
{
    char s[100],tmp[15];
    Register arr[26];int cnt,i,j,k,p,q;//i用于遍历s，j用于定位第1个寄存器，k，p分别是第2,3个
    strcpy(arr[0].s,"AX");arr[0].n=0;
    for(i=1;i<26;++i)
    {
        arr[i].s[0]=arr[i-1].s[0]+1;
        arr[i].s[1]='X';arr[i].s[2]='\0';arr[i].n=0;
    }
    while(gets(s))
    {
        if(s[0]=='I'&&s[1]=='N')
        {
            for(i=3,q=0;s[i]!=',';++i,++q)tmp[q]=s[i];  tmp[q]='\0';
            for(j=0;j<26;++j)if(!strcmp(arr[j].s,tmp))break;
            for(++i,q=0;s[i];++i,++q)tmp[q]=s[i];   tmp[q]='\0';
            arr[j].n=atoi(tmp);
        }
        else if(s[0]=='O'&&s[1]=='U'&&s[2]=='T')
        {
            for(i=4,q=0;s[i];++i,++q)tmp[q]=s[i];  tmp[q]='\0';
            for(j=0;j<26;++j)if(!strcmp(arr[j].s,tmp))break;
            printf("%d\n",arr[j].n);
        }
        else if(s[0]=='M'&&s[1]=='O'&&s[2]=='V')
        {
            for(i=4,q=0;s[i]!=',';++i,++q)tmp[q]=s[i];  tmp[q]='\0';
            for(j=0;j<26;++j)if(!strcmp(arr[j].s,tmp))break;
            for(++i,q=0;s[i];++i,++q)tmp[q]=s[i];  tmp[q]='\0';
            for(k=0;k<26;++k)if(!strcmp(arr[k].s,tmp))break;
            arr[j].n=arr[k].n;
        }
        else if(s[0]=='X'&&s[1]=='C'&&s[2]=='H'&&s[3]=='G')
        {
            for(i=5,q=0;s[i]!=',';++i,++q)tmp[q]=s[i];  tmp[q]='\0';
            for(j=0;j<26;++j)if(!strcmp(arr[j].s,tmp))break;
            for(++i,q=0;s[i];++i,++q)tmp[q]=s[i];  tmp[q]='\0';
            for(k=0;k<26;++k)if(!strcmp(arr[k].s,tmp))break;
            int inttmp=arr[j].n;arr[j].n=arr[k].n;arr[k].n=inttmp;
        }
        else
        {
            cnt=0;for(i=0;s[i];++i)if(s[i]==',')cnt++;
            if(s[0]=='O')
            {
                int len=strlen(s);
                for(i=len;i>0;--i)s[i]=s[i-1];
                s[i]='O';s[len+1]='\0';
            }
            if(cnt==1)
            {
                for(i=4,q=0;s[i]!=',';++i,++q)tmp[q]=s[i];  tmp[q]='\0';
                for(j=0;j<26;++j)if(!strcmp(arr[j].s,tmp))break;
                for(++i,q=0;s[i];++i,++q)tmp[q]=s[i];  tmp[q]='\0';
                for(k=0;k<26;++k)if(!strcmp(arr[k].s,tmp))break;
                if(s[0]=='A'&&s[1]=='D'&&s[2]=='D')arr[j].n+=arr[k].n;
                if(s[0]=='S'&&s[1]=='U'&&s[2]=='B')arr[j].n-=arr[k].n;
                if(s[0]=='M'&&s[1]=='U'&&s[2]=='L')arr[j].n*=arr[k].n;
                if(s[0]=='D'&&s[1]=='I'&&s[2]=='V')arr[j].n/=arr[k].n;
                if(s[0]=='M'&&s[1]=='O'&&s[2]=='D')arr[j].n%=arr[k].n;
                if(s[0]=='A'&&s[1]=='N'&&s[2]=='D')arr[j].n&=arr[k].n;
                if(s[0]=='O'&&s[1]=='O'&&s[2]=='R')arr[j].n|=arr[k].n;
                if(s[0]=='X'&&s[1]=='O'&&s[2]=='R')arr[j].n^=arr[k].n;
            }
            else
            {
                for(i=4,q=0;s[i]!=',';++i,++q)tmp[q]=s[i];  tmp[q]='\0';
                for(j=0;j<26;++j)if(!strcmp(arr[j].s,tmp))break;
                for(++i,q=0;s[i]!=',';++i,++q)tmp[q]=s[i];  tmp[q]='\0';
                for(k=0;k<26;++k)if(!strcmp(arr[k].s,tmp))break;
                for(++i,q=0;s[i];++i,++q)tmp[q]=s[i];  tmp[q]='\0';
                for(p=0;p<26;++p)if(!strcmp(arr[p].s,tmp))break;
                if(s[0]=='A'&&s[1]=='D'&&s[2]=='D')arr[j].n=arr[k].n+arr[p].n;
                if(s[0]=='S'&&s[1]=='U'&&s[2]=='B')arr[j].n=arr[k].n-arr[p].n;
                if(s[0]=='M'&&s[1]=='U'&&s[2]=='L')arr[j].n=arr[k].n*arr[p].n;
                if(s[0]=='D'&&s[1]=='I'&&s[2]=='V')arr[j].n=arr[k].n/arr[p].n;
                if(s[0]=='M'&&s[1]=='O'&&s[2]=='D')arr[j].n=arr[k].n%arr[p].n;
                if(s[0]=='A'&&s[1]=='N'&&s[2]=='D')arr[j].n=arr[k].n&arr[p].n;
                if(s[0]=='O'&&s[1]=='O'&&s[2]=='R')arr[j].n=arr[k].n|arr[p].n;
                if(s[0]=='X'&&s[1]=='O'&&s[2]=='R')arr[j].n=arr[k].n^arr[p].n;
            }
        }
    }
    return 0;
}