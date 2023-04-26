#include<stdio.h>
#include<string.h>
#define N 10005

int main()
{
    char s[N];
    char c;int p=0;
    while((c=getchar())!=EOF)s[p++]=c;
    s[p]=0;
    //printf("%s",s);

    int n=0;int flag=1;
    char ret[N];
    for(int i=0;i<N;++i)ret[i]=0;
    for(int k=0;k<p;){
        if(s[k]=='/'&&s[k+1]=='*'&&flag){
            while((s[k]!='*'||s[k+1]!='/')&&k<p)k++;
            k+=2;
            //printf("%d\n",k);
        }
        else if(s[k]=='/'&&s[k+1]=='/'&&flag){
            while(s[k]!='\n'&&k<p)k++;
        }
        else if(s[k]=='\\'&&s[k+1]=='"')k+=2;
        else{
            ret[n++]=s[k];
            if(s[k]=='"'&&flag==1)flag=0;
            else if(s[k]=='"'&&flag==0)flag=1;
            k++;
        }
        //printf("%d\n",flag);
    }

    printf("%s",ret);

    return 0;
}

