#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sta[70];//0-9 0-9 10-35 a-z 36- A-Z
long long int nums(char *a)
{
    int i,count=0;
    long long int res=0;
    for(i=0;i<strlen(a);i++)
    {
        if(a[i]>='0'&&a[i]<='9')
        {
            int num=a[i]-'0'+0;
            if(sta[num]==-1)
            {
                if(count==0)sta[num]=1;
                else if(count==1)sta[num]=0;
                else sta[num]=count;
                count++;
            }
        }
        if(a[i]>='a'&&a[i]<='z')
        {
            int num=a[i]-'a'+10;
            if(sta[num]==-1)
            {
                if(count==0)sta[num]=1;
                else if(count==1)sta[num]=0;
                else sta[num]=count;
                count++;
            }
        }
        if(a[i]>='A'&&a[i]<='Z')
        {
            int num=a[i]-'A'+36;
            if(sta[num]==-1)
            {
                if(count==0)sta[num]=1;
                else if(count==1)sta[num]=0;
                else sta[num]=count;
                count++;
            }
        }//载入数据
    }
    count+=1;
    for(i=0;i<strlen(a);i++)
    {
        int j=0;
        if(a[i]>='0'&&a[i]<='9')j=a[i]-'0'+0;
        if(a[i]>='a'&&a[i]<='z')j=a[i]-'a'+10;
        if(a[i]>='A'&&a[i]<='Z')j=a[i]-'A'+36;
        res=res*count+sta[j];
    }
    for(i=0;i<70;i++)
    {
        sta[i]=-1;
    }
    return res;
}
int cmp(const void *a,const void *b)
{
    char *a1=(char *)a;
    char *b1=(char *)b;
    if(nums(a1)!=nums(b1))
    {
        if(nums(a1)>nums(b1))return 1;
        else if(nums(a1)<nums(b1))return -1;
    }
    else
    return strcmp(a1,b1);
}
int main()
{
    int i;
    for(i=0;i<70;i++)
    {
        sta[i]=-1;
    }
    int N;
    scanf("%d",&N);
    char a[N][16];
    for(i=0;i<N;i++)
    {
        scanf("%s",&a[i]);
    }
    qsort(a,N,sizeof(a[0]),cmp);
    for(i=0;i<N;i++)
    {
        printf("%s\n",a[i]);
    }
    return 0;
}