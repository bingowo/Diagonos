#include<stdio.h>
#include<malloc.h>

int trans(char *str);
int main()
{
    int T;
    scanf("%d",&T);
    int *res = (int *)malloc(sizeof(int)*T);
    char str[60];
    int i;
    for (i=0;i<T;i++){
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
	int len;
    int a[128];
    char *p=str;
    char temp;
    int num=2;
    int res=0;
    for(i=0;i<128;i++){
        a[i]=-1;
    }
    a[*p]=1;
    temp=*p;
    while(*++p!=temp);
    a[*p]=0;
    temp=*p;
    while(*++p!=temp);
    while(*p!='\0'){
		if(a[*p]==-1){
			a[*p]=num;
			num++;
		}
        p++;
    }
    num--; 
    for(i=0;i<len;i++){
    	res=res*num+a[*(str+i)];
	}   
	return res;
}