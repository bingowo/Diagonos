#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
struct data{
	char m[501];
	char m0[501];
};

typedef struct data Data; 


int cmp(const void *a,const void *b){
    struct data p1,p2;
    p1 = *((struct data*)a);
    p2 = *((struct data*)b);
    return strcmp(p1.m0,p2.m0);
}


int main(){
	int T;
	scanf("%d",&T);
	getchar();
	int i; 
	for(i = 0; i < T; i++){
		char *s;
		s = (char *)malloc(1000);
		int numOfAll = 0;
		gets(s);
		char *p = s;
		Data s0[501];
		while (*p != '\0'){//句子没有结束之前 
			char * p2;
			if (isspace(*p) != 0 || ispunct(*p) != 0){
				p++;
			} else{
				p2 = p;
				while (isspace(*p2) == 0 && ispunct(*p2) == 0 && *p2 != '\0'){
					p2++;
				}
			}
			int len = p2 - p;
			strncpy(s0[numOfAll].m,s0,len);
			s0[numOfAll].m[len] = '\0';
			strncpy(s0[numOfAll].m0,s0,len);
			s0[numOfAll].m0[len] = '\0';
			numOfAll++;
		}//到这里将单词按照空格和标点符号拆开来然后存在结构体数组的字符串里面 
		int numOfWord = 0;
		int k;
		for (k = 0; k < numOfAll; k++){
			int flag = 0;
			int j;
			for (j = 0; j < numOfWord; j++){
				if (strcmp(s0[k].m,s0[j].m0) == 0){
					flag = 1; 
				}
			}
			if (flag == 0){
				strcpy(s0[numOfWord].m0,s0[k].m);
                numOfWord++;	
			}
		} 
		qsort(s0,numOfWord,sizeof(s0[0]),cmp); 
		int x;
		printf("case #%d:\n",i);
        for(x = 0;x < numOfWord;x++){
            printf("%s ",s0[x].m0);
        }
        printf("\n");
	} 
	return 0;
}


///////////////////////////////////////////////////////////////////////////////////
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

struct data{
   char m[501];
   char m0[501];
};

int cmp(const void *a,const void *b){
   struct data p1,p2;
   p1 = *((struct data*)a);
   p2 = *((struct data*)b);
   return strcmp(p1.m0,p2.m0);
}

int main()
{
   int T;
   scanf("%d",&T);
   int cnt = 0;//这里的cnt是拿来数T的... 
   getchar();
   int t; 
   for(t = 0; t < T; t++){
       char *s;
       s = (char *)malloc(1000);
       int i = 0;//统计单词数目 
       gets(s);
       char *p = s;
       struct data s0[501];
       while(*p != '\0'){//在句子结束之前 
           if(isspace(*p) || ispunct(*p)) p++; //是标点或者空格的话 p++ 
           else{
               char *p2 = p+1; //起点就是第一个非零的字符 
               while(*p2 != '\0' && *p2 != ' '&& *p2 != ',' && *p2 != '.' && *p2 != '!' && *p2 != '?'){
                   p2++;//一方面要求 p2没有结束 另一方面要求不能是标点符号 
               }//找到这个单词的右边界 
               int len = p2 - p; //获得这个单词的长度 p是左边界  p2是右边界 
               strncpy(s0[i].m,p,len);  //把单词用strncopy放在字符串里面 
               strncpy(s0[i].m0,p,len); 
               s0[i].m[len] = s0[i].m0[len] = '\0'; //这里需要注意的一点是strncopy需要自己补充\0 
               i++;//单词总数目 
               p = p2;//刷新左边界(这个时候p指向的是一个标点符号或者空格) 
           }
       }//这里的是将句子分开弄成一堆单词,并且将单词存放在char型数组中,不同单词位于不同的结构体数组下面 
       int num = 0;
       int k;
       for(k = 0;k < i ;k++){//i是单词总数目 
           int flag = 0;
           int j;
           for(j = 0;j < num;j++){
               if(strcmp(s0[k].m,s0[j].m0) == 0){//如果说长循环里面的等于短循环里面的 
                   flag = 1;
               }//如果俩单词一样 flag就等于1 ,就不进行复制 
           }
           if(flag == 0){//如果前面不等于后面就把后面的那个单词复制过去 
               strcpy(s0[num].m0,s0[k].m);//把后面的内容复制到前面 
               num++;
           }
       }//这里应该是去除重复的单词 
       qsort(s0,num,sizeof(s0[0]),cmp);//具体拿来比较的是s0.m0 
       printf("case #%d:\n",t);
       int x;
       for(x = 0;x < num;x++){
           printf("%s ",s0[x].m0);
       }
       printf("\n");
       cnt++;
       free(s);//有malloc就要free 
   }
}


 