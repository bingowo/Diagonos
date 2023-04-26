#include<stdio.h>

#include<stdlib.h>

#include<string.h>

char * largeDiffer(char *a,char *b){

/*  使用说明

传入的a和b只能为整数

结果为a-b;返回的为字符指针，注意数组不要越界 ，要加头文件string.h

*/

int a_num[1000]={0},b_num[1000]={0};

char result[1000];//返回的结果

int a_len,b_len,i,j,cmp=-1,len,differ;

a_len=strlen(a);//计算a,b的长度

b_len=strlen(b);

for(i=0;i<a_len;i++){

a_num[a_len-i-1]=a[i]-'0';//给a倒叙赋值

}

for(i=0;i<b_len;i++){

b_num[b_len-i-1]=b[i]-'0';//给a倒叙赋值

}

if(a_len>b_len) cmp=1;//a大于b返回1    否则，返回-1

else if(a_len<b_len) cmp=-1;

else cmp=strcmp(a,b);

 

len=a_len>b_len?a_len:b_len;//返回较大值

if(cmp==1){//a为     大数的时候

for(i=0;i<len;i++){

if(a_num[i]<b_num[i]){

a_num[i]+=10;

if(a_num[i]<0){

a_num[i]=9;

a_num[i+1]=a_num[i+1]-1;

}

a_num[i+1]=a_num[i+1]-1;

differ=a_num[i]-b_num[i];

a_num[i]=differ;

}else{

differ=a_num[i]-b_num[i];

a_num[i]=differ;

}

}

} else if(cmp==-1){//第一个输入的为小数的时候

for(i=0;i<len;i++){

if(b_num[i]<a_num[i]){

b_num[i]+=10;

if(b_num[i]<0){

b_num[i]=9;

b_num[i+1]=b_num[i+1]-1;

}

b_num[i+1]=b_num[i+1]-1;

differ=b_num[i]-a_num[i];

a_num[i]=differ;//

}else{

differ=b_num[i]-a_num[i];

a_num[i]=differ;//

}

}

}

//输出格式

i=len-1;

while(a_num[i]==0) i--;//直到第一个不为0的数

if(cmp==-1) {

result[0]='-';

for(j=1;i>=0;i--,j++)

result[j]=a_num[i]+'0';

result[j]='\0';

} else{

for(j=0;i>=0;i--,j++)

result[j]=a_num[i]+'0';

result[j]='\0';

}

return result;

}

int main(){

char a[1001],b[1001];

gets(a);

gets(b);

char result[1001];

strcpy(result,largeDiffer(a,b));

printf("%s",result);

}