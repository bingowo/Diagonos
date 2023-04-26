#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    char s[125];
    int a[150];
    int len;
    int f;
} list;
int cmp(const void *a,const void *b)
{
    list*x=(list*)a;
    list*y=(list*)b;
    if(x->f!=y->f)
    {
        return y->f-x->f;   //大的在上面
    }
    else
    {
        if(x->len!=y->len&&y->f==1)
        {
            return y->len-x->len;
        }
        else if(x->len!=y->len&&y->f==-1)
        {
            return x->len-y->len;
        }
        else
        {
            if(y->f==1)
            {
                return y->a[y->len-1]-x->a[x->len-1];
            }
            else
            {
                return x->a[x->len-1]-y->a[y->len-1];
            }
        }
    }
}
void slo(int a[],int b[],int fa,int fb)
{
    int t,carry=0;
    if(fa==1&&fb==-1)
    {
        for(int i=0; i<125; i++)
        {
            t=a[i]+b[i]+carry;
            a[i]=t%10;
            carry=t/10;
        }
    }
    else if(fa==1&&fb==1)
    {
        for(int i=0; i<125; i++)
        {
            t=a[i]-b[i];
            if(t<0)
            {
                a[i]=t+10;
                a[i+1]--;
            }
            else
                a[i]=t;
        }
    }
    else if(fa==-1&&fb==-1)
    {
         for(int i=0; i<125; i++)
        {
            t=b[i]-a[i];
            if(t<0)
            {
                a[i]=t+10;
                b[i+1]--;
            }
            else
                a[i]=t;
        }
    }
    int f=0;
    for(int i=124;i>=0;i--)
    {
        if(a[i]==0&&f==0)
            continue;
        else
            f=1;
        printf("%d",a[i]);
    }
}
int main()
{
    int n;
    char s[125];
    scanf("%d",&n);
    list *t=(list*)malloc(sizeof(list)*n);
    for(int i=0; i<n; i++)
    {
        scanf("%s",s);
        strcpy(t[i].s,s);
        if(s[0]=='-')
        {
            t[i].f=-1;
            t[i].len=strlen(s)+t[i].f;
            for(int j=strlen(s)-1; j>=1; j--)
            {
                t[i].a[strlen(s)-1-j]=s[j]-'0';
            }
        }
        else
        {
            t[i].f=1;
            t[i].len=strlen(s);
            for(int j=strlen(s)-1; j>=0; j--)
            {
                t[i].a[strlen(s)-1-j]=s[j]-'0';
            }
        }
    }
    qsort(t,n,sizeof(list),cmp);//大的在最上面  大-小
    slo(t[0].a,t[n-1].a,t[0].f,t[n-1].f);
    free(t);
    return 0;

}
