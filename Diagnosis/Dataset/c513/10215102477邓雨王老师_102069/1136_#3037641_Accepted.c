#include<stdio.h>
#include<string.h>
int main()
{
        int n;
        scanf("%d",&n);
        int mp[n];
        int arry[n],so[n];
        for(int i=0;i<n;i++){
                scanf("%d",&arry[i]);
        }
        int one[20001],zero[20001];
        int index0=0,index1=0,sum0=0,sum1=0;
        for(int i=0;i<n;i++){
                if(arry[i]==0){zero[index0++]=i;sum0++;}
                if(arry[i]==1){one[index1++]=i;sum1++;}
        }
        for(int i=0;i<index0;i++){
                mp[i]=zero[i];
        }
        for(int i=index0;i<n;i++){
                mp[i]=one[i-index0];
        }
        int output[n];
        memset(output,0,n);
        for(int i=0,j=0;i<n;i++){
                output[i]=arry[mp[j]];
                j=mp[j];
        }
        int cnt1=0,cnt0=0;
        for(int i=0;i<n;i++){
                if(output[i]==0) cnt0++;
                else cnt1++;
        }
        if(cnt1==sum1&&cnt0==sum0){
                for(int i=0;i<n;i++) printf("%d ",output[i]);
        }
        else printf("-1");
}