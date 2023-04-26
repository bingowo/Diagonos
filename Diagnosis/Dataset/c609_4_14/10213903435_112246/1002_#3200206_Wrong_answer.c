#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t,i=0;
    int arr[10],cnt[10];
    scanf("%d",&t);
    while(i<t)scanf("%d",arr+(i++));
    for(i=0;i<t;i++)
    {
        cnt[i]=0;
        int temp_cnt=1,n=*(arr+i);
        int temp_n=n%2;
        n/=2;
        do
        {

           if(n%2!=temp_n&&n!=1){temp_cnt++;temp_n=n%2;}
           else if(n%2!=temp_n&&n==1){temp_cnt++;cnt[i]=temp_cnt;}
           else if(n%2==temp_n&&temp_cnt<cnt[i])continue;
           else if(n%2==temp_n&&temp_cnt>=cnt[i]){cnt[i]=temp_cnt;temp_cnt=1;continue;}
        }while(n/=2);
    }
    int k=0;
    while(k++<t)
    {
        printf("case #%d:\n%d\n",k,cnt[k-1]);
    }
    return 0;
}
