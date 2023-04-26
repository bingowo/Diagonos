#include <stdio.h>
#include <stdlib.h>
#include<string.h>

/*
思路:
1.16进制转10进制 
*/
int main()
{
    char s[100000],t[100000];
    scanf("%s",s);
    int k=0;
    int i;
    for(i=2;i<strlen(s);i++)//16进制转二进制 
    {
        int d;
        if(s[i]>='A'){
        	d=s[i]-'A'+10;
		}else{
			d=s[i]-'0';
		} 
        unsigned int flag=0x8;//这里是16进制 
        while(flag != 0)
        {
            if(d & flag){
				t[k++]='1';
			}//&位运算 全1取1 有0取0 
            else{
            	t[k++]='0';
			}
            flag=flag>>1;
        }
    }//数组s存放16进制(去掉0x) 数组t存放转换后的二进制 
    long long int qr=0,qi=0;
    long long int a,b;
    for(i=0;i<k;i++){
        int r=t[i]-'0';
        a=-qr-qi+r;
        b=qr-qi;
        qr=a;
        qi=b;
    }
    if(qi==0){
    	printf("%lld",a);
	}else{
        if(qr!=0)
        {
            printf("%lld",qr);
            if(qi>0)printf("+");
        }

        if(qi==1){
        	printf("i\n");	
		}
        else if(qi==-1){
        	printf("-i\n");	
		}
        else{
        	printf("%lldi\n",qi);	
		} 
    }
}
