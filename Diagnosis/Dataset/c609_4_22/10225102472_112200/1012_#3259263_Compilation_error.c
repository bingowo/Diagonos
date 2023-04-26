#include <stdio.h>
#include <string.h>
#define MAXSIZE 100 //定义最大位数

//单个字符转化为数字
int getNum(char c) {
  //顺序是先数字后大写字母后小写字母
  if(c>='0'&&c<='9') return c-'0';
  if(c>='A'&&c<='Z') return c-'A'+10; //A是10，B是11
  if(c>='a'&&c<='z') return c-'a'+36; //a是36，b是37
}

//数字转化为字符
char getchar(int i) {
  if(i>=0&&i<=9) return i+'0';
  if(i>=10&&i<=35) return i-'10'+'A'; //A是10，B是11
  return i-36+'a';
}

//把输入的字符串的各个数位还原为数字形式
void change(char* str,int start[MAXSIZE]) {
  int i;
  start[0]=strlen(str); //被除数数组的第0位存的是输入字符串str的长度
  for(i=1; i<=start[0]; i++) {
    start[i]=getNum(str[i-1]);
  }
}

//进制转化函数 start、ans、res分别表示被除数、商和余数，oldBase指原数字进制，newBase指需要转化的进制
void solve(int start[MAXSIZE],int ans[MAXSIZE],int res[MAXSIZE],int oldBase,int newBase) {
  //余数位初始化为0
  memset(res,0,sizeof(res));
  
  int y,i,j;
  
  while(start[0]>=1) {
    y=0;
    i=1;
    ans[0]=start[0]; //商的第一位表示的也是商的位数
    
    while(i<=start[0]) {
      //y表示的是被除数
      y=y*oldBase+start[i]; //更新方法是上一轮得到的余数*进制基数+当前位数上的数
      
      ans[i++]=y/newBase; //商
      
      y%=newBase; //余数
      
    }
    
    res[++res[0]]=y; //这一轮得到的余数
    
    i=1; //找下一轮商的起始处，去掉前面的0
    
    ans [0]表示的是商的位数
    
    while(i<=ans[0]&&ans[i]==0) i++;
    
    memset(start,0,sizeof(start)); //全部初始化为0
    
    //这轮得到的商
    for(j=i; j<=ans[0]; j++) {
      start[++start[0]]=ans[j];
      
    }
    
    memset(ans,0,sizeof(ans));
    
  }
  
}

//从高位到低位逆序输出
void output(int res[MAXSIZE]) {
  
  int i;
  
  for(i=res[0]; i>=1; i--)
  
   printf("%c",getchar(res[i])); //输出字符用%c
   
   printf("\n");
   
}

//测试函数

int main() {

 char str[MAXSIZE];
 
 printf("请输入数字：");
 
 gets(str);
 
 int oldBase,newBase;
 
 printf("请输入原数字进制:");
 
 scanf("%d",&oldBase);
 
 printf("请输入转变后数字进制:");
 
 scanf("%d",&newBase);
 
 int start[MAXSIZE],ans[MAXSIZE],res[MAXSIZE];
 
 change(str,start);
 
 solve(start,ans,res,oldBase,newBase);
 
 output(res);
 
 return 0;
}