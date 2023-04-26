#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#include<string.h>
int slo1(char s[],int a[])
{
    int i=0,cnt=0;
    a[cnt]=0;
    while(s[i]!='\0')
    {
        if (s[i]==',')
        {
            cnt++;
            a[cnt]=0;
        }
        else
            a[cnt]=a[cnt]*10+s[i]-'0';
        i++;
    }
    return cnt+1;
}
void reverse(int s[],int cnt)
{
    int c,i,j;
    for (i=0,j=cnt; i<j; i++,j--)
    {
        c=s[i];
        s[i]=s[j];
        s[j]=c;
    }
}
void prime(int p[])
{
    int cnt=0;
    p[cnt++]=2;
    p[cnt++]=3;
    for(int i=5; i<200; i+=2)
    {
        int t=0;
        for (int j=2; j<i; j++)
        {
            if (i%j==0)
            {
                t=1;
                break;
            }
        }
        if (t==0)
            p[cnt++]=i;
        if (cnt>26)
            break;
    }

}
int main()
{
    char x1[100],x2[100];
    int p[30];
    prime(p);
    int n,i,len1,len2;

    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {   int r=0;
        scanf("%s",x1);
        scanf("%s",x2);
        int *a1=(int *)malloc(sizeof(int)*30);
        int *a2=(int *)malloc(sizeof(int)*30);
        int *a3=(int *)malloc(sizeof(int)*35);
        len1=slo1(x1,a1);
        len2=slo1(x2,a2);
        reverse(a1,len1-1);
        reverse(a2,len2-1);
        if(len1<len2)
        {
            for(int j=0; j<len2-len1; j++)
                a1[len1+j]=0;
                len1=len2;
        }
        else if(len2<len1)
        {
            for(int j=0; j<len1-len2; j++)
                a2[len2+j]=0;
                len2=len1;
        }
        for(int j=0;j<len1;j++)
        {
            a3[j]=(a1[j]+a2[j]+r)%p[j];
            r=(a1[j]+a2[j]+r)/p[j];
        }
        if (r>0)
            a3[len1]=r;
        printf("case #%d:\n",i);
        if (r>0){
        for(int j=len1;j>=0;j--)
        {
            if (j==0)
                printf("%d\n",a3[j]);
            else
                printf("%d,",a3[j]);
        }
        }
        else
        {
            for(int j=len1-1;j>=0;j--)
        {
            if (j==0)
                printf("%d\n",a3[j]);
            else
                printf("%d,",a3[j]);
        }
        }
        free(a1);
        free(a2);
        free(a3);

    }
    return 0;
}
