#include<stdio.h>
int F(int x,int y)
{
    int arr1[32],arr2[32],i=0,count=0;
    for(i=0;i<32;i++) { arr1[i]=(x>>i)&1; }
	for(i=0;i<32;i++) { arr2[i]=(y>>i)&1; }
	for(i=0;i<32;i++) { if(arr1[i]!=arr2[i]) count++; }
    return count;
}
int main()
{
    int t,x,y;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&x,&y);
        printf("%d\n",F(x,y));
    }
    return 0;
}

