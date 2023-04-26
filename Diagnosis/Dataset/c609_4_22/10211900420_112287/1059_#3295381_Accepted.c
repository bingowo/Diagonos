#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int sign,flag;
    char in[200],fl[200];
}num;
int cmp(const void* a,const void* b)
{
    num c,d;
    c=*(num*) a;
    d=*(num*) b;
    if(c.sign!=d.sign) return c.sign-d.sign;
    if(c.sign==1 && strlen(c.in)!=strlen(d.in)) return strlen(c.in)-strlen(d.in);
    if(c.sign==-1 && strlen(c.in)!=strlen(d.in)) return strlen(d.in)-strlen(c.in);
    if(c.sign==1 && strcmp(c.in,d.in)) return strcmp(c.in,d.in);
    if(c.sign==-1 && strcmp(c.in,d.in)) return strcmp(d.in,c.in);
    if(c.sign==1 && strcmp(c.fl,d.fl)) return strcmp(c.fl,d.fl);
    if(c.sign==-1 && strcmp(c.fl,d.fl)) return strcmp(d.fl,c.fl);
    return 0;
}
int main()
{
    int i,j,k,n;
    scanf("%d",&n);
    char x[200];
    num y[200];
    for(i=0;i<n;i++)
    {
        scanf("%s",x);
        if(x[0]=='-')
        {
            y[i].sign=-1;
            for(j=1;j<strlen(x);j++)
            {
                if(x[j]!='.')
                {
                    y[i].in[j-1]=x[j];
                }
                else
                {
                    y[i].in[j-1]='\0';
                    break;
                }
            }
            for(k=j+1;k<strlen(x);k++)
            {
                y[i].fl[k-j-1]=x[k];
            }
            y[i].fl[k-j-1]='\0';
            y[i].flag=1;
        }
        else if(x[0]=='+')
        {
            y[i].sign=1;
            for(j=1;j<strlen(x);j++)
            {
                if(x[j]!='.')
                {
                    y[i].in[j-1]=x[j];
                }
                else
                {
                    y[i].in[j-1]='\0';
                    break;
                }
            }
            for(k=j+1;k<strlen(x);k++)
            {
                y[i].fl[k-j-1]=x[k];
            }
            y[i].fl[k-j-1]='\0';
            y[i].flag=2;
        }
        else
        {
            y[i].sign=1;
            for(j=0;j<strlen(x);j++)
            {
                if(x[j]!='.')
                {
                    y[i].in[j]=x[j];
                }
                else
                {
                    y[i].in[j]='\0';
                    break;
                }
            }
            for(k=j+1;k<strlen(x);k++)
            {
                y[i].fl[k-j-1]=x[k];
            }
            y[i].fl[k-j-1]='\0';
            y[i].flag=3;
        }
    }
    qsort(y,n,sizeof(y[0]),cmp);
    for(i=0;i<n;i++)
    {
        if(y[i].flag==1)
        {
            printf("-%s",y[i].in);
            if(strlen(y[i].fl)!=0)
                printf(".%s",y[i].fl);
        }
        else if(y[i].flag==2)
        {
            printf("+%s",y[i].in);
            if(strlen(y[i].fl)!=0)
                printf(".%s",y[i].fl);
        }
        else
        {
            printf("%s",y[i].in);
            if(strlen(y[i].fl)!=0)
                printf(".%s",y[i].fl);
        }
        printf("\n");
    }
    return 0;
}