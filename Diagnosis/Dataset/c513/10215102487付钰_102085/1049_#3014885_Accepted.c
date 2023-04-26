#include<stdio.h>
#include<string.h>
#include<math.h>
#define INF 501

char word[INF][50];
int s=0;

void select(char a[]) {
	s=0;

    int i,j,len,start;

    len=strlen(a);
    start=0;
//读入
    for(i=0; i<len; i++) {
        if(a[i]<='z'&&a[i]>='a') {//读单词
			continue;
		}
		else if(start<i)//每个单词结束的时候要判断start的位置，防止读入空格
		{//每个单词结束 把这个单词放入words[]
			for(j=start; j<i; j++) {
                word[s][j-start]=a[j];
            }
            s++;
            start=i+1;
		}
		else//标点符号
			start=i+1;
    }

	if(start<len)//只有一个单词的时候需要把这个单词弄到words[]里面去
	{
		for(j=start; j<i; j++) {
			word[s][j-start]=a[j];
        }
        s++;
        start=i+1;
	}
    char tmp[INF];
//排序
    for(i=0; i<s; i++) {
        for(j=i+1; j<s; j++) {
            if(strcmp(word[i],word[j])>0) {
                strcpy(tmp,word[i]);
                strcpy(word[i],word[j]);
                strcpy(word[j],tmp);
            }
        }
    }
    strcpy(tmp,word[0]);
    printf("%s",word[0]);
//去重
	for(i=1; i<s; i++) {
        if(strcmp(tmp,word[i])==0) {
            continue;
        } else {
			strcpy(tmp,word[i]);
            printf(" %s",word[i]);
        }
    }
    printf("\n");
}

int main() {
    int i,j,t;
    char sentence[INF];

    scanf("%d",&t);getchar();
    for(i=0; i<t; i++) {

		for(int h=0;h<501;h++)//清空
			for(j=0;j<50;j++)
				word[h][j]='\0';

			gets(sentence);
			printf("case #%d:\n",i);
			select(sentence);
    }
    return 0;
}
