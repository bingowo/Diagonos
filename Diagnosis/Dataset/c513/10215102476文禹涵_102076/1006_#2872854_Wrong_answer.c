#include<stdio.h>
#include<string.h>
#include<math.h>

int main()
{
	int n,len,num[1000],sum,i;
	char s[1000];
	scanf("%d",&n);
	while(n--){
		sum = 0;
	    scanf("%s",s);
		len = strlen(s);
		for(i=0;i<len;i++){
			if(s[i] == '-')
			num[i] = -1;
			if(s[i] == '0')
			num[i] = 0;
			if(s[i] == '1')
			num[i] = 1;
			sum = sum + num[i]*pow(3,len-i-1);
		}
		printf("%d\n",sum);
		
	}
	return 0; 
 } 