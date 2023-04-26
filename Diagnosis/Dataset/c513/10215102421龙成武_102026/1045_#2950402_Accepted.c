#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void removal(char *a,char *temp);
int compar(const void *p1,const void *p2);
int main()
{
    int n,i,j,k,flag=1,mid,*len,*pos;
    long long ans;
    char **a,*core,*temp;
    scanf("%d",&n);
    a=(char**)malloc(n*sizeof(char*));
    core=(char*)malloc(101*sizeof(char));
    temp=(char*)malloc(101*sizeof(char));
    len=(int*)malloc(n*sizeof(int));
    pos=(int*)malloc(n*sizeof(int));
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
    {                       //len记录当前这个片在各个串里面的长度，pos记录下标到了哪里
        memset(pos,0,n*sizeof(int));
        ans=0;
        for(i=0;i<strlen(core);i++)
        {
            memset(len,0,n*sizeof(int));
            for(j=0;j<n;j++)
            {
                for(k=pos[j];k<strlen(a[j]);k++)
                {
                    if(a[j][k]==core[i])
                        len[j]++;
                    else
                        break;
                }
                pos[j]+=len[j];         //更新下一次的角标
            }
            qsort(len,n,sizeof(int),compar);
            mid=n%2==0? n/2:(n+1)/2;
            mid--;                  //数学上中位数和角标不一样
            for(j=0;j<n;j++)
            {
                ans+=abs(len[j]-len[mid]);
            }
        }

        printf("%lld",ans);
    }


    for(i=0;i<n;i++)
        free(a[i]);
    free(a);
    free(core);
    free(temp);
    free(len);
    free(pos);
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
    int *a=(int*)p1,*b=(int*)p2,flag;
    if(*a<*b)
        flag=-1;
    else
        flag=1;
    return flag;
}
