#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char com[300];

void print(char *s,int len,int l,int r)
{
    if(l==r)return;
    for(;l!=r;l++)
    {
        com[len]=s[l];
        com[len+1]='\0';
        printf("%s\n",com);
        print(s,len+1,l+1,r);
    }
}

int cmp(const void* a,const void* b)
{
    char x=*(char*) a;
    char y=*(char*) b;
    if(x<97&&y<97)
    {
        return x-y;
    }
    if(x>=97&&y>=97)
    {
        return x-y;
    }
    else
    {
        if(x>y)
        {
            if(x-y<32) return -1;
            if(x-y==32) return 1;
            else return 1;
        }
        else
        {
            if(y-x<32) return 1;
            if(y-x==32) return -1;
            else return -1;
        }
    }
}

int main()
{
    int t;
    scanf("%d\n",&t);
    for(int i=0;i<t;i++)
    {
        char s[18];
        for(int k=0;k<18;k++)
        {
            s[k]='\0';
        }
        int alpha[300]={0};
        char c;
        int j=0;
        while((c=getchar())!='\n')
        {
            if(alpha[c]==0)
            {
                s[j]=c;
                alpha[c]=1;
                j++;
            }
        }
        qsort(s,j,sizeof(s[0]),cmp);
        printf("case #%d:\n",i);
        print(s,0,0,strlen(s));
    }
}
