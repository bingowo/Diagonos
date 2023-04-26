#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double s[26];                //用于存储浮点数

int cmp(const void*a,const void*b)
{
    char A=*(char*)a;
    char B=*(char*)b;
    double  m,n;         //表示浮点数
    if(A>=97){
        m=s[A-97];
    }else{
        m=s[A-65];
    }
    if(B>=97){
        n=s[B-97];
    }else{
        n=s[B-65];
    }
    if(fabs(m-n)>0.0000000001){
       // return n-m;              //n-m可能为0.几，不好直接return
       if((m>n)&&fabs(m-n)>0.00000001){                       //浮点数精度问题直接比较大小不好
         return -1;
       }else{
         return 1;
       }
    }else{
        if(A>=97&&B<97){
            return -1;
        }else if(A<97&&B>=97){
            return 1;
        }else{
            int x=A-B;
            return x;
        }
    }
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){

        for(int j=0;j<26;j++){
            scanf("%lf",&s[j]);
        }
        char t[150];
        scanf("%s",t);
        int x=strlen(t);
        qsort(t,x,sizeof(char),cmp);
        printf("case #%d:\n%s\n",i,t);
    }
    return 0;
}
