#include <stdio.h>
int main()
{
    int num=0,R=0,temp=0,i=0;
    scanf("%d %d",&num,&R);
    int L[100]={0};
    if(num==0) printf("0");
    while(num!=0)
    {
        temp=num%R;
        num=num/R;
    	if(temp<0)
		{
			temp=temp-R;
			num++;
		}
        L[i]=temp;
        i++;
    }
    for(int k=i-1;k>=0;k--)
    {
        if(L[k]>9) printf("%c",L[k]-10+'A');
        else printf("%d",L[k]);
    }
    return 0;
}