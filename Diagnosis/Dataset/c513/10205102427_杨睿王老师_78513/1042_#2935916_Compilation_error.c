//1042
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
struct data{
    char ans[100];
    int l;
}d[1<<17];
int cmp1(const void* x, const void* y)
{
	return *(char*)x-*(char*)y;
}
int cmp2(const void* x, const void* y)
{
	data xx=*(data*)x;
	data yy=*(data*)y;
	if(strcmp(xx.ans,yy.ans)>0) return 1;
	else return -1;
}

int main()
{
	int i,T;
    scanf("%d",&T);
    getchar();
    for(i=0;i<T;i++){
        printf("case #%d:\n",i);   	
    	char str[20];
		scanf("%s",&str);
		int len=strlen(str);
        //排序去重
        qsort(str,len,sizeof(char),cmp1);

        int len1=1;
        for(int i=0, j=0;j<len;++j)
            if(str[j]!=str[i]) {str[++i]=str[j];len1++;}
        str[len1]='\0';

        //二进制枚举
        int len2=(1<<len1);
        for(int i=1;i<len2;++i){//从1开始，空集不考虑
            int l=0;
            for(int j=0;j<len1;++j)
                if(i & (1 << j)) d[i-1].ans[l++]=str[j];
            d[i-1].ans[l]='\0';
        }

        //每个组合按字典序排好后输出
        qsort(d,len2-1,sizeof(data),cmp2);
        
        for(int i=0;i<len2-1;++i){
        	d[i].l=strlen(d[i].ans);
        	//printf("test-l:%d\n",d[i].l);
	        	for(int r=0;r<d[i].l;r++){
	        		printf("%c",d[i].ans[r]); 
				} 
			printf("\n");        	
		}

    }
    return 0;
}