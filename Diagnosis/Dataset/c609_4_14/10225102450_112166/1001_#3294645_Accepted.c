#include<stdio.h>

void reverse(char *a,int n)
{
	for(int i=0;i<n/2;i++)
	{
		char temp;
		temp=a[i];
		a[i]=a[n-i-1];
		a[n-i-1]=temp;
	}
}

int main()
{
	int T;
	scanf("%d",&T);
    char number[32];  //最多32位 用来存储转换进制后的每个位置的数值
	for(int i=0;i<T;i++)
	{
		int N,R,j=0,flag=1;   //j是用来存number的下标,flag用来判断正负
		scanf("%d %d",&N,&R);
        
        if(N<0)
        {
            flag=-1;
            N=-N;
        }
		do{
			if(N%R<10){
				number[j++]=N%R+'0';   
			}
			else{
				number[j++]=N%R+'A'-10;   //大于10时用字母来表示
			}
		}while(N/=R);  
            
        number[j]='\0';
		reverse(number,j);  //数组元素反转
        
        if(flag==-1)
        {
            printf("-");
        }
		for(int k=0;k<j;k++)
		{
			printf("%c",number[k]);
		}
		printf("\n");	
        
	}
	return 0;
 } 
