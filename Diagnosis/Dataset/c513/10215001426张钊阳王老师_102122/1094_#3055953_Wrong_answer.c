#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct  dist{
        int flag;
        int s[150];
        char ss[150];
        int len;
};
int main()
{
    int cmp(const void *a1,const void *b1);
    int n;
    scanf("%d",&n);
    struct dist* t=(struct dist*)malloc(sizeof(struct dist)*n);
    for(int i=0;i<n;i++)
    {
        char temp[150];
        scanf("%s",temp);
        strcpy(t[i].ss,temp);
        int l=strlen(temp);
        if(temp[0]=='-') t[i].flag=-1;
        else t[i].flag=1;
        if(temp[0]=='-') {
            for(int j=1;j<l;j++) t[i].s[j-1]=temp[j]-'0';
            t[i].len=strlen(temp)-1;
        }
        else {
            for(int j=0;j<l;j++) t[i].s[j]=temp[j]-'0';
            t[i].len=strlen(temp);
        }
    }
    qsort(t,n,sizeof(t[0]),cmp);
    //for(int j=0;j<n;j++) printf("%s\n",t[j].ss); //从小到大
    //printf("%d %d\n",t[0].flag,t[n-1].flag);
    minus(t[n-1].s,t[0].s,t[n-1].len,t[0].len,t[n-1].flag,t[0].flag);
    return 0;
}

int cmp(const void *a1,const void *b1)
{
    struct dist a=*(struct dist*)a1;
    struct dist b=*(struct dist*)b1;
    int la=strlen(a.ss),lb=strlen(b.ss);
    int aa=a.flag,bb=b.flag;
    if(aa==bb&&aa==1)
    {
        if(la!=lb) return la-lb;
        else return strcmp(a.ss,b.ss);
    }
    else if(aa!=bb)
    {
        return aa-bb;
    }
    else if(aa==bb&&aa==-1)
    {
        if(la!=lb) return lb-la;
        else return strcmp(b.ss,a.ss);
    }
}

void minus(int* a,int *b,int la,int lb,int fa,int fb)//大整数减法 a-b或者大整数加法
{
    if(fa==fb)
    {
        for(int j=0;j<=lb-1;j++)
        {
            if(a[la-1-j]>=b[lb-1-j])
            {
                a[la-1-j]-=b[lb-1-j];
            }
            if(a[la-1-j]<b[lb-1-j])
            {
                a[la-1-j]+=10;
                a[la-1-j]-=b[lb-1-j];
                a[la-1-j-1]--;
            }
        }
    }
    if(fa!=fb)
    {
        if(la>=lb)
        {
            for(int t=0;t<=lb-1;t++)
            {
                a[la-1-t]+=b[lb-1-t];
                //printf("%d\n",a[la-1-t]);
                if(a[la-1-t]>=10)
                {
                    a[la-1-t]-=10;
                    a[la-1-t-1]++;
                }
            }
             if(a[0]>=10)
        {
            a[0]-=10;
            printf("1");
            for(int j=0;j<la;j++) printf("%d",a[j]);
        }
        else if(a[0]<10)
        {
            for(int j=0;j<la;j++) printf("%d",a[j]);
        }
        }
        else if(la<lb)
        {
            for(int t=0;t<=la-1;t++)
            {
                b[lb-1-t]+=a[la-1-t];
                if(b[lb-1-t]>=10)
                {
                    b[lb-1-t]-=10;
                    b[lb-1-t-1]++;
                }
            }
            if(b[0]>=10)
            {
                b[0]-=10;
                printf("1");
                for(int j=0;j<lb;j++) printf("%d",b[j]);
            }
            else if(b[0]<10)
            {
                for(int j=0;j<lb;j++) printf("%d",b[j]);
            }
        }//之后需要检查是否第一位也大于10
    }
}
