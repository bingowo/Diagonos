#include<stdio.h>
#include<stdlib.h>
#include<string.h>
unsigned long long int ans[1000000];
int main()
{   int t;
    scanf("%d\n",&t);
    for(int v=0;v<t;v++){
    printf("case #%d:\n",v);
    int a,n,b;
    scanf("%d %d %d",&a,&b,&n);
    /*if(b==0) 
	{
	printf("1\n");
	continue;}
    else{  */
    memset(ans,0,sizeof(ans));
    int l=1;//l指向最高位的后一位
    int i;
    ans[0]=a;
    for(i=1;i<b;i++)
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
    for(int j=n-1;j>=0;j--)
    {
        printf("%lld",ans[j]);
    }
    printf("\n");//}
     
}
return 0;
}