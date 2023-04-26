#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct file
{
    char s[100];
    char day[11];
    char time[5];
    char size[100];
    char name[100];
};

int cmp1(const void*a,const void*b)
{
    struct file *ap=(struct file*)a;
    struct file *bp=(struct file*)b;
    if(strcmp(ap->name,bp->name)>0)
        return 1;
    else
        return -1;
}

int cmp2(const void*a,const void*b)
{
    struct file*ap=(struct file*)a;
    struct file*bp=(struct file*)b;
    int n1=0,n2=0;int i;
    for(i=0;ap->size[i];i++)
        n1=10*n1+ap->size[i]-'0';
    for(i=0;bp->size[i];i++)
        n2=10*n2+bp->size[i]-'0';
    if(n1>n2)
        return 1;
    else
        return -1;
    if(strcmp(ap->name,bp->name)>0)
        return 1;
    else
        return -1;
}

int cmp3(const void*a,const void*b)
{
    struct file*ap=(struct file*)a;
    struct file*bp=(struct file*)b;
    int n1=0,n2=0;
    int i,j;
    for(i=0;i<4;i++)
        n1=10*n1+ap->day[i]-'0';
    for(j=0;j<4;j++)
        n2=10*n2+bp->day[j]-'0';
    if(n1!=n2)
        return (n1-n2);
    n1=0;n2=0;
    for(i=i+1;i<7;i++)
        n1=10*n1+ap->day[i]-'0';
    for(j=j+1;j<7;j++)
        n2=10*n2+bp->day[j]-'0';
    if(n1!=n2)
        return (n1-n2);
    n1=0;n2=0;
    for(i=i+1;i<10;i++)
        n1=10*n1+ap->day[i]-'0';
    for(j=j+1;j<10;j++)
        n2=10*n2+bp->day[j]-'0';
    if(n1!=n2)
        return (n1-n2);
    n1=0;n2=0;
    for(i=0;i<2;i++)
        n1=10*n1+ap->time[i]-'0';
    for(j=0;j<2;j++)
        n2=10*n2+bp->time[j]-'0';
    if(n1!=n2)
        return (n1-n2);
    n1=0;n2=0;
    for(i=i+1;i<5;i++)
        n1=10*n1+ap->time[i]-'0';
    for(j=j+1;j<5;j++)
        n2=10*n2+bp->time[j]-'0';
    if(n1!=n2)
        return(n1-n2);
    if(strcmp(ap->name,bp->name)>0)
        return 1;
    else
        return -1;
}

int main()
{
    int n;
    while(scanf("%d ",&n)!=EOF)
    {
        struct file a[100];
        int i,j,p;
        for(i=0;i<n;i++)
            gets(a[i].s);
        for(i=0;i<n;i++)
        {
            for(j=0,p=0;a[i].s[j]!=' ';j++,p++)
                a[i].day[p]=a[i].s[j];
            for(j=j+1,p=0;a[i].s[j]!=' ';j++,p++)
                a[i].time[p]=a[i].s[j];
            for(;;j++)
            {
                if(a[i].s[j]==' ');
                else
                    break;
            }
            for(p=0;a[i].s[j]!=' ';j++,p++)
                a[i].size[p]=a[i].s[j];
            a[i].size[p]=0;
            for(j=j+1,p=0;a[i].s[j];j++,p++)
                a[i].name[p]=a[i].s[j];
        }
        char s1[4];char s2[5];
        scanf("%s%s",s1,s2);
        if(s2[1]=='N')
            qsort(a,n,sizeof(struct file),cmp1);
        else
        {
            if(s2[1]=='S')
                qsort(a,n,sizeof(struct file),cmp2);
            else
                qsort(a,n,sizeof(struct file),cmp3);
        }
        for(i=0;i<n;i++)
        {
            printf("%s",a[i].s);
            printf("\n");
        }
        printf("\n");
    }
}