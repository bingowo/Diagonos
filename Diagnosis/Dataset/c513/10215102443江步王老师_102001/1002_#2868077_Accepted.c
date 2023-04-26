#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

long long int trans(char *str);
int main()
{
    int T;
    scanf("%d",&T);
    long long int *res = (long long int *)malloc(sizeof(long long int)*T);//res数组储存结果 
    char str[100];
    int i;
    for (i=0;i<T;i++){//输入字符串并通过trans函数保存结果至res数组中 
        scanf("%s",str);
        res[i]=trans(str);
    }
    for(i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%lld\n",res[i]);
    }
    return 0;
}

long long int trans(char *str)
{
    int i;
	int len;//传入字符串的长度 
    int a[128];//a数组用于储存下标字符对应的数 
    char *p=str;
    char temp;
    int num=2;
    long long int res=0;
    len=strlen(str);
    for(i=0;i<128;i++){
        a[i]=-1;
    }
    //首字符 
	a[*p]=1;//给首字符赋值为1 
    temp=*p;
    //printf("第1个字符是%c\n",*p);
    p++;
	while(*p==temp)
    	p++;
    //第二个字符 
	a[*p]=0;
    temp=*p;
    //printf("第2个字符是%c\n",*p);
    p++;
	while(*p==temp)
    	p++;
    //	
    while(*p!='\0'){//从2开始依次给其他不同的字符赋值 
		if(a[*p]==-1){
			a[*p]=num;
			//printf("第%d个字符是%c\n",num,*p);
			num++;
		}
        p++;
    }
    for(i=0;i<len;i++){
    	res=res*num+a[*(str+i)];
    	//printf("res=%lld",res);
		//printf("第%d字符是%c,他的值是%d\n",(i+1),*(str+i),a[*(str+i)]);
	}   
	return res;
}