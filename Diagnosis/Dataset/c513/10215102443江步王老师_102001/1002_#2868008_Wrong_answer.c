#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>

int trans(char *str);
int main()
{
    int T;
    scanf("%d",&T);
    int *res = (int *)malloc(sizeof(int)*T);//res数组储存结果 
    char str[60];
    int i;
    for (i=0;i<T;i++){//输入字符串并通过trans函数保存结果至res数组中 
        scanf("%s",str);
        res[i]=trans(str);
    }
    for(i=0;i<T;i++){
        printf("case #%d:\n",i);
        printf("%d\n",res[i]);
    }
    return 0;
}

int trans(char *str)
{
    int i;
	int len;//传入字符串的长度 
    int a[128];//a数组用于储存下标字符对应的数 
    char *p=str;
    char temp;
    int num=2;
    int res=0;
    len=strlen(str);
    for(i=0;i<128;i++){
        a[i]=-1;
    }
    a[*p]=1;//给首字符赋值为1 
    temp=*p;
    //printf("第1个字符是%c\n",*p);
    while(*p==temp)
    	p++;
    a[*p]=0;//给首字符后一个不同的字符赋值0 
    temp=*p;
    //printf("第2个字符是%c\n",*p);
    while(*p==temp)
    	p++;
    while(*p!='\0'){//从2开始依次给其他不同的字符赋值 
		if(a[*p]==-1){
			a[*p]=num;
			//printf("第3个字符是%c,他的值是%d\n",*p,num);
			num++;
		}
        p++;
    }
    for(i=0;i<len;i++){
    	res=res*num+a[*(str+i)];
    	//printf("i=%d\nres=%d\n",i,res);
	}   
	return res;
}