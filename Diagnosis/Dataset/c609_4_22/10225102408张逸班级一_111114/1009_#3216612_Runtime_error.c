#include<stdio.h>
#include<stdlib.h>
int count(char a){
    int num=0;
while(a){
    a=a&(a-1);
    num++;
}
return num;
}
int main(){
    int n;
    char c;
    scanf("%d\n",&n);
    gets(c);
    while(n--){
      int k=0;
      char s[121];
      gets(s);
      int total=8*strlen(s);
      printf("total=%d\n",total);
      int one=0;
      for(int i=0;i<strlen(s);i++){
        one+=count(s[i]);
      }
      printf("one =%d\n",one);
     for(int i=2;i<=one;i++){
        while(one%i==0&&total%i==0){
            one/=i;total/=i;
        }
     }
     printf("%d/%d\n",one,total);

    }
    return 0;
}
