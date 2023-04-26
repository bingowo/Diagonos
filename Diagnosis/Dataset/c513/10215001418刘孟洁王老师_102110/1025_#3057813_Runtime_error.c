#include<stdio.h>
#include<string.h>
#include<math.h>

int cmp1(const void*a,const void*b)//按字典顺序
{
    char *c=*(char**)a;
    char *d=*(char**)b;
    if(strcmp(c,d)<0) return -1;
    else if(strcmp(c,d)>=0) return 1;
}

int cmp2(char a[21],char b[21])
{
    int i,j,num1=0,num2=0,l1,l2;
    l1=strlen(a);
    l2=strlen(b);
    for(i=1;i<l1;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(a[i]!=a[j]) num1++;
        }
    }
    for(i=1;i<l2;i++)
    {
        for(j=i-1;j>=0;j--)
        {
            if(b[i]!=b[j]) num2++;
        }

    }
    if(num1>num2) return a-b;
    else if(num2<num1) return b-a;
    else return cmp1(a,b);

}


int main()
{
    int T,i,j,n;
    scanf("%d",&T);
    char s[101][21]={0};
    for(i=0;i<T;i++)
    {
        scanf('%d',&n);
        for(j=0;j<n;j++)
        {
            scanf("%c",&s[j]);
        }
    qsort(s[j],n,sizeof(s[0]),cmp2);
    printf("case #%d:\n",i);
    for(j=0;j<n;j++)
        printf("%s\n",s[j]);
    }
    return 0;
}
