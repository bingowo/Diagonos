#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define C 1000
void motify(char* str,char ch)
{
    int len=strlen(str),i,j;
    char s[1010];for(i=0;i<len;++i)s[i]=str[i];
    s[i]='\0';
    for(i=0;;++i)
    {
        if(i==len)break;
        if((s[i]=='+'&&s[i+1]==ch)||(s[i]=='-'&&s[i+1]==ch))
        {
            for(j=len;j>i+1;--j)s[j]=s[j-1];
            s[len+1]='\0';s[i+1]='1';len++;
        }
        if(s[i]=='-')
        {
            for(j=len;j>i;--j)s[j]=s[j-1];
            s[len+1]='\0';s[i]='+';len++;
            i++;
        }
    }
    if(s[0]!='+')
    {
        for(j=len;j>0;--j)s[j]=s[j-1];
        s[len+1]='\0';s[0]='+';len++;
    }
    if(s[1]==ch)
    {
        for(j=len;j>1;--j)s[j]=s[j-1];
        s[len+1]='\0';s[1]='1';
    }
    for(i=0;s[i];++i)if(s[i]=='=')break;
    if(s[i+1]!='+')
    {
        for(j=len;j>i+1;--j)s[j]=s[j-1];
        s[len+1]='\0';s[i+1]='+';len++;
    }
    strcpy(str,s);
}
int main()
{
    char s[1010],tmp[100],ch;scanf("%s",s);
    for(int i=0;s[i];++i)if(s[i]!='+'&&s[i]!='-'&&!isdigit(s[i])&&s[i]!='='){ch=s[i];break;}
    motify(s,ch);
    int x[C]={0},n[C]={0},cnt1=0,cnt2=0,i,q,start=0,end;
    for(end=2;s[end]!='+'&&s[end]!='=';end++);
    while(s[end]!='=')
    {
        if(isdigit(s[end-1]))
        {
            q=0;for(i=start+1;i<end;++i,q++)tmp[q]=s[i];
            tmp[q]='\0';n[cnt2++]=-1*atoi(tmp);
        }
        else
        {
            q=0;for(i=start+1;i<end-1;++i,++q)tmp[q]=s[i];
            tmp[q]='\0';x[cnt1++]=atoi(tmp);
        }
        start=end;
        for(++end;s[end]!='+'&&s[end]!='=';end++);
    }
    if(s[end]=='=')
    {
        if(isdigit(s[end-1]))
        {
            q=0;for(i=start+1;i<end;++i,++q)tmp[q]=s[i];
            tmp[q]='\0';n[cnt2++]=-1*atoi(tmp);
        }
        else
        {
            q=0;for(i=start+1;i<end-1;++i,++q)tmp[q]=s[i];
            tmp[q]='\0';x[cnt1++]=atoi(tmp);
        }
    }
    start=end+1;end+=2;for(end;s[end]!='+'&&s[end];++end);
    while(s[end])
    {
        if(isdigit(s[end-1]))
        {
            q=0;for(i=start+1;i<end;++i,q++)tmp[q]=s[i];
            tmp[q]='\0';n[cnt2++]=atoi(tmp);
        }
        else
        {
            q=0;for(i=start+1;i<end-1;++i,++q)tmp[q]=s[i];
            tmp[q]='\0';x[cnt1++]=-1*atoi(tmp);
        }
        start=end;
        for(++end;s[end]!='+'&&s[end];++end);
    }
    if(!(s[end]))
    {
        if(isdigit(s[end-1]))
        {
            q=0;for(i=start+1;i<end;++i,q++)tmp[q]=s[i];
            tmp[q]='\0';n[cnt2++]=atoi(tmp);
        }
        else
        {
            q=0;for(i=start+1;i<end-1;++i,++q)tmp[q]=s[i];
            tmp[q]='\0';x[cnt1++]=-1*atoi(tmp);
        }
    }
    int a=0,b=0;double a1,b1,c;
    for(i=0;i<cnt1;++i)a+=x[i];
    for(i=0;i<cnt2;++i)b+=n[i];
    a1=a;b1=b;
    c=b1/a1;
    printf("%c=%.3f",ch,c);
    return 0;
}