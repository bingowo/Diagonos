#include<stdio.h>
#include<string.h>
int cal(char s[100]){       //用来计算字符串中不同字符的个数
    int count=0;
    int i=0;
        for(i=0;i<strlen(s);i++){
            int j=0;
            for ( j=0;j<i;j++){
                if (s[j]==s[i]){
                    break;
                }
            }
            if (j==i){
                count++;
            }
        }

    return count;
}
int main(){
    int n;
    scanf("%d",&n);
    int i;
    for(i=0;i<n;i++){
        char s[100];
        scanf("%s",&s);
        int m=0,r=cal(s);
        int a[128];
        for (i=0;i<128;i++) a[i]=-1;
        int digit=0,N=1,i; char *p=s; 
  a[*p]=1;
  while (*++p)
     if (a[*p]==-1)   
     { a[*p]=digit; digit=digit?digit+1:2; N++;}
  if (N<2) N=2; 
  int j,sum=0;
  for(j=0;j<strlen(s);j++){    //strlen是用来处理字符串的 ，但a是数组，因此需要改变a的形式 
      sum=sum*r+a[j];
  }
  printf("case #%d:\n",i);
  printf("%d\n",sum);
    }
    
}