#include<stdio.h>
#include<stdlib.h>
#include<string.h>  
int main()
{   int t;
    scanf("%d\n",&t);
    for(int v=0;v<t;v++){
    printf("case #%d:\n",v);
    int a,n;
    scanf("%d %d",&a,&n);
    if(n==0) 
	{
	printf("1\n");
	continue;}
    else{
    int l=1;//l指向最高位的后一位
    int ans[1010]={0},i;
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
        //进位l往后移动
        if(ans[l]!=0) l++;
    }
    //输出 
    for(int j=l-1;j>=0;j--)
    {
        printf("%d",ans[j]);
    }
    printf("\n");}
     
}
return 0;
}