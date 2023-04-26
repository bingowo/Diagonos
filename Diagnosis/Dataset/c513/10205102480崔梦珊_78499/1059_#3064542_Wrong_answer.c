#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void f(int s,int kuan)
{
    int fenzi=s;
    int fenmu=kuan;
    int temp=fenzi;
    while(fenmu%fenzi)
    {
        temp=fenmu%fenzi;
        fenmu=fenzi;
        fenzi=temp;
    }
    s=s/temp;
    kuan=kuan/temp;
    printf("+%d/%d",s,kuan);
}

int cmp(const void* a,const void* b)
{
    int x=*(int*)a;
    int y=*(int*)b;
    return x-y;
}


int main()
{
    int n,s;
    scanf("%d %d",&n,&s);
    int height[1000]={0};
    for(int i=0;i<n;i++)
    {
        scanf("%d",&height[i]);
    }
    qsort(height,n,sizeof(height[0]),cmp);
    height[n]=1011;
    int low=height[0];
    int rong=0;
    int levelz=height[0];
    int kuan=0;
    int high=0;
    for(int i=0;i<n;i++)
    {
        if(height[i+1]==height[i])
        {
            continue;
        }
        else
        {
            high=height[i+1]-height[i];
            rong=high*(i+1);
            if(s>=rong)
            {
                levelz=height[i+1];
                s=s-rong;
            }
            else
            {
                kuan=i+1;
                break;
            }
        }
    }
    if(s!=0)
    {
        levelz+=s/kuan;
        s=s%kuan;
    }
    if(s==0) printf("%d",levelz);
    else
    {
        printf("%d",levelz);
        f(s,kuan);
    }

    /*printf("%d %d %d %d",levelz,kuan,high,s);*/
}
