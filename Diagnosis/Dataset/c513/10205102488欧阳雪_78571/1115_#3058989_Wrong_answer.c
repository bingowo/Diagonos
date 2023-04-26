#include<stdio.h>
#include<string.h>
int swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}
void reverse (char*first, char*last)
{
  /*  while ((first!=last)&&(first!=--last))
    {
        std::iter_swap (first,last);
        ++first;
    }*/
    char temp[30]={0};
    char*f=first;
    int j=0;
    while(first!=last)
    {
    	temp[j++]=*first;
    	first++;
	}
	j--;
	while(j>=0)
	{
		*f=temp[j];
		j--;
		f++;
	}
}

int myNextPermutation(char *start, char *end) { //[start,end)
	char *cur = end - 1, *pre = cur - 1; //pre指向partitionNumber 
	while (cur > start && *pre >= *cur) 
		--cur, --pre; //从右到左进行扫描，发现第一个违背非递减趋势的数字
	if (cur <= start) return 0; //整个排列逆序, 不存在更大的排列 
	//从右到左进行扫描，发现第一个比partitionNumber大的数
	for (cur = end - 1; *cur <= *pre; --cur); //cur指向changeNumber  
	swap(pre, cur);
	reverse(pre + 1, end); //将尾部的逆序变成正序 
	return 1; 
}

/*int main() {
	char data[] = "aabc";
	do {
		puts(data);
	} while (myNextPermutation(data, data + 4));
	return 0;	
}*/
int main()
{
	int T;
	scanf("%d",&T);
	for(int i=0;i<T;i++)
	{
		char data[30]={0};
		scanf("%s",data);
		myNextPermutation(data, data+strlen(data));
		printf("case #%d:\n",i);
	    puts(data);
	}
	return 0;
}

