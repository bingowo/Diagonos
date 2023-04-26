#include<stdio.h>
#include<string.h>
int result(int m,int n){//计算最简分数 
	int a = m;
    int b = n;
    while(a % b)
    {
        int temp = a % b;
        a = b;
        b = temp;
    }
    m /= b;
    n /= b;						
   	printf("%d",n);
   	printf("/");
   	printf("%d\n",m);
}
int main()
{
	int n;
	scanf("%d\n",&n);//！！！！！ 
	for(int i=0;i<n;i++)
	{
		char s[1000]={'\0'};//注意初始化！！！ 
		char a;
		int j=0;
		while((a=getchar())!='\n')
		{
			s[j]=a;
			j++;
		}
		int len=strlen(s);
		//printf("%s %d\n",s,len);
		int cnt=0;
		for(int j=0;j<len;j++)//1的个数 
		{
			while(s[j])
			{
				if(s[j]%2==1){
				cnt++;	
				}
				s[j]=s[j]/2;
			}
		}
	//	printf("%d\n",cnt); 
		result(len*8,cnt);
	 } 
}