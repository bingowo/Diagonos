#include<stdio.h>
#include<math.h> 
int main()
{
	int t;
	scanf("%d",&t);
	int a[t],b[t],s[32];
	int i=0;
	int c=45;//输出符号 
	while(scanf("%d%d\n",&a[i],&b[i])==1){i++;
	}//输入数据 
	for(i=0;i<t;i++){
		if(a[i]<0){printf("%c",c);
		}
		int n;
		n=abs(a[i]);
		int j;
		for(j=0;n>=1;j++){
			s[j]=n%b[i];
			n=n/b[i];
		}//进制转换 
		for(int k=j;k>1;k--){ 
			if(s[k]<10){printf("%d",s[k]);
				}
			else printf("%c",s[k]+55);		
		}
		s[0]<10?printf("%d",s[0]):printf("%c",s[0]+55);
		}
	return 0;	
	}