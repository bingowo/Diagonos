#include<stdio.h>
#include<string.h>
int main()
{
	int n,m;//初始进制/目标进制
	int j=0;
	char a[100];//数组
	scanf("%d %s %d", &n,a,&m);
	int len=strlen(a);
	int sum=0;
	int w=1;
	for(int i=len-1;i>=0;i--){
            if(a[i]>='a'&&a[i]<='z'){
                sum+=(a[i]-'a'+10)*w;
	}
	        else if(a[i]>='A'&&a[i]<='Z'){
                sum+=(a[i]-'A'+10)*w;
	}
            else{
                sum+=(a[i]-'0')*w;
	}
	        w*=n;
	}
	char num[1000];
	if(sum==0){printf("0");continue;}
	while(sum){
            num[j]=sum%m;
            j++;
            sum/=m;
	}
    for(int i=j-1;i>=0;i--){
        if(num[i]>10){
            printf("%c",'A'+num[i]-10);
            j=0;
        }
        else
            printf("%d",num[i]);
            j=0;


    }
	return 0;

}
