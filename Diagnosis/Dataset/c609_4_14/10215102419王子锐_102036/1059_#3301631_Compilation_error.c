#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int n;

typedef struct node
{
    int flag;
    char num[405],ori_num[105];
} Node;

Node A[1005];

int cmp(const void* a,const void* b)
{
    Node x=*(Node *)a,y=*(Node *)b;
    if(x.flag!=y.flag) return x.flag-y.flag;
    else if(x.flag==1) return strcmp(x.num,y.num);
    else return -1*strcmp(x.num,y.num);
}

int main()
{
    scanf("%d",&n);
    for(int i=1; i<=n; i++)
    {
        scanf("%s",s);
        int pos=-1,flag=1,l=strlen(s);
        strcpy(A[i].ori_num,s);
        for(int j=0; j<l; j++)
        {
            if(s[j]=='-') flag=-1;
            if(s[j]=='.') pos=j;
            if(j==l-1 && pos==-1) pos=l;
        }
        for(int j=0; j<400; j++) A[i].num[j]='0';
        for(int j=0; j<l; j++)
            if(s[j]!='-' && s[j]!='+') A[i].num[200-pos+j]=s[j];
        A[i].num[200]='.',A[i].num[400]='\0';
        A[i].flag=flag;
    }
    qsort(A+1,n,sizeof(Node),cmp);
    for(int i=1; i<=n; i++)
        printf("%s\n",A[i].ori_num);

    return 0;
}