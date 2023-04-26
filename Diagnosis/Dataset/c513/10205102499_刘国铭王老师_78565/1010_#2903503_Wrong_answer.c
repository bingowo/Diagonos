#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int bi[11]={0};

int trans(int*bi,int n)
{
    int i=0;
    while(n)
    {
    bi[i]=n%2;
    n/=2;
    i++;
    }
}

char* mysubstr(char* srcstr,int offset,int length){
	assert(length>0);
	assert(srcstr!=NULL);

	int total_length=strlen(srcstr);

	//长度不够实行截短，并且多分配字符串结束符空间
	int real_length=((total_length-offset)>=length?length:(total_length-offset))+1;

	char *tmp;
	if( NULL==(tmp=(char *)malloc(real_length*sizeof(char))) ){
		exit(0);
	}

	strncpy(tmp,srcstr+offset,real_length-1);
	tmp[real_length-1]='\0';

	return tmp;
}

int main()
{
    char s[501];
    scanf("%s",&s);
    int num=strlen(s);
    int bin[11]={0};
    trans(bin,num);
    printf("0001");
    for(int i=9;i>=0;i--)
        printf("%d",bin[i]);
    int times=num/3;
    int over=num%3;
    int j=0;
    int flag=j;
    if(times!=0)
    {
    for(int i=0;i<times;i++)
    {
        char *str=mysubstr(s,flag,3);
        flag+=3;
        int strn=atoi(str);
        int bistr[11]={0};
        trans(bistr,strn);
        for(int i=9;i>=0;i--)
            printf("%d",bistr[i]);
    }
    }
else
{
    if(over==1)
    {
        char str1[1];
        str1[0]=s[num-1];
        int str1n=atoi(str1);
        int bistr1[5]={0};
        trans(bistr1,str1n);
        for(int i=3;i>=0;i--)
            printf("%d",bistr1[i]);
    }
    else if(over == 2)
    {
        char str2[2];
        str2[0]=s[num-2];
        str2[1]=s[num-1];
        int str2n=atoi(str2);
        int bistr2[8]={0};
        trans(bistr2,str2n);
        for(int i=6;i>=0;i--)
            printf("%d",bistr2[i]);
    }
}
    return 0;
}
