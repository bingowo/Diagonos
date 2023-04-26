#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define C 100
typedef struct{char s[10];int n;} Variable;
int main()
{
    char s[100];
    Variable arr[C];int cnt=0,i,j,k;
    while(gets(s))
    {
        //printf("%s\n",s);
		if(s[0]=='I'&&s[1]=='N')
        {
            char tmp[10];int q=0,flag=0;
            for(i=3;s[i]!=',';++i,q++)tmp[q]=s[i];
            tmp[q]='\0';
            for(j=0;j<cnt;++j)
            {
            	if(!strcmp(arr[j].s,tmp))
            	{
            		flag=1;
            		break;
				}
			}
			if(flag)
			{
				q=0;
				for(++i;s[i];++i,q++)tmp[q]=s[i];
            	tmp[q]='\0';
            	arr[j].n=atoi(tmp);
        	}
			else
			{
				strcpy(arr[cnt].s,tmp);q=0;
            	for(++i;s[i];++i,q++)tmp[q]=s[i];
            	tmp[q]='\0'; //printf("%s\n",tmp);
            	arr[cnt].n=atoi(tmp);
            	cnt++;	
			}
		}
        else if(s[0]=='O')
        {
            char tmp[10];int q=0;
            for(i=4;s[i];++i,++q)tmp[q]=s[i];
            tmp[q]='\0';
            for(j=0;j<cnt;++j)if(!strcmp(arr[j].s,tmp))printf("%d\n",arr[j].n);
        }
        else
        {
            char tmp[10];int q=0;
            for(i=4;s[i]!=',';++i,++q)tmp[q]=s[i]; 
            tmp[q]='\0';
            for(j=0;j<cnt;++j)if(!strcmp(arr[j].s,tmp))break;
            q=0;for(++i;s[i];++i,++q)tmp[q]=s[i];
            tmp[q]='\0';
            for(k=0;k<cnt;++k)if(!strcmp(arr[k].s,tmp))break;
            if(s[0]=='M'&&s[1]=='O'&&s[2]=='V')arr[j].n=arr[k].n;
            if(s[0]=='A'&&s[1]=='D'&&s[2]=='D')arr[j].n+=arr[k].n;
            if(s[0]=='S'&&s[1]=='U'&&s[2]=='B')arr[j].n-=arr[k].n;
            if(s[0]=='M'&&s[1]=='U'&&s[2]=='L')arr[j].n*=arr[k].n;
            if(s[0]=='D'&&s[1]=='I'&&s[2]=='V')arr[j].n/=arr[k].n;
        }
    }
    return 0;
}