#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
int main()
{int t;
scanf("%d\n",&t);
for(int v=0;v<t;v++){
    printf("case #%d:\n",v);
    int a,n,i;
    scanf("%d %d",&a,&n);
    if (n==0) 
	{
	printf("1\n");
	continue;}
    else{
    int l=1;//l指向最高位的后一位
    int ans[1010];
	memset(ans,0,1010);
    ans[0]=a;
    for(i=1;i<n;i++)
    {
        for(int j=0;j<l;j++)
            ans[j]*=a;
        for(int j=0;j<l;j++)
        {
            ans[j+1]+=ans[j]/10;
            ans[j] = ans[j]%10;
        }
        //如果a[l]不等于零  说明进位了，l往后移动
        if(ans[l]!=0)
            l++;
    }
    for(int j=l-1;j>=0;j--)
    {
        printf("%d",ans[j]);
    }
    printf("\n");}
    return 0;
}
}