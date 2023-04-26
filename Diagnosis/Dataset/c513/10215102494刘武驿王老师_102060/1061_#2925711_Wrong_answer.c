#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct code
{
    char s[100];
    long long unsigned res;
};
int cmp(void *a,void *b)
{
    if(((struct code*)a)->res<((struct code*)b)->res) return -1;
    if(((struct code*)a)->res>((struct code*)b)->res) return 1;
    else return strcmp(((struct code*)a)->s,((struct code*)b)->s);
}
int main()
{
    int n;
    scanf("%d",&n);
    struct code re[10000];
    char tmp=getchar();
    for(int i=0;i<n;i++)
    {
        scanf("%s",re[i].s);
        int len=re[i].s;
        int nums[1000];
        re[i].res=0;
        memset(nums,-1,1000);
        nums[re[i].s[0]]=1;
        int count=2,j;
        for(j=1;j<len;j++) if(nums[re[i].s[j]]==-1)
        {
            nums[re[i].s[j]]=0;
            break;
        }
        for(int x=j;x<len;x++) if(nums[re[i].s[x]]==-1) nums[re[i].s[x]]=count++;
        for(j=0;j<len;j++) re[i].res+=pow(count,len-1-j)*nums[re[i].s[j]];
    }
    qsort(re,n,sizeof(re[0]),cmp);
    for(int i=0;i<n;i++) printf("%s\n",re[i].s);
}