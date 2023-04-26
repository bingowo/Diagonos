#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void removal(char *a,char *temp);
int compar(const void *p1,const void *p2);
int main()
{
    int n,i,flag=1,mid;
    long long ans;
    char **a,*core,*temp;
    scanf("%d",&n);
    a=(char**)malloc(n*sizeof(char*));
    core=(char*)malloc(101*sizeof(char));
    temp=(char*)malloc(101*sizeof(char));
    for(i=0;i<n;i++)
    {
        a[i]=(char*)malloc(101*sizeof(char));
        scanf("%s",a[i]);
    }
    for(i=0;i<n;i++)                //寻找核心，判断可否达到
    {
        removal(a[i],temp);
        if(i==0)
            //core=temp;
            strcpy(core,temp);
        else
        {
            if(strcmp(core,temp)!=0)
            {
                flag=0;
                printf("-1");
                break;
            }
        }
    }
    if(flag==1)
    {
        ans=0;
        qsort(a,n,sizeof(char**),compar);
        mid=n%2==0? n/2:(n+1)/2;
        mid-=1;        //下标的不同
        for(i=0;i<n;i++)
        {
            ans+=abs(strlen(a[i])-strlen(a[mid]));
        }
        printf("%lld",ans);
    }


    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
    free(core);
    free(temp);
    return 0;
}
void removal(char *a,char *temp)
{
    int i,j;
    temp[0]=a[0];j=1;
    for(i=1;i<strlen(a);i++)
    {
        if(a[i]!=a[i-1])
            temp[j++]=a[i];
    }
    temp[j]=0;
}
int compar(const void *p1,const void *p2)
{
    char *a=*(char**)p1,*b=*(char**)p2;
    int flag=0;
    if(strlen(a)<strlen(b))
        flag=-1;
    else
        flag=1;
    return flag;
}
