#include <stdio.h>
#include <string.h>
#include <stdlib.h>
int cmp(const void *p1,const void *p2){
    int a=*(int *)p1;
    int b=*(int *)p2;
    return a-b;
}
int main() {
    int T;
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        char s[21];
        int num[21];
        scanf("%s",s);
        int len= strlen(s),sign2=0;
        for(int p=0;p<len;p++){
            num[p]=s[p]-'0';
            if(num[p]>0&&sign2<2){
                sign2++;
            }
        }
        if(sign2==2){
            int sign=0;
            int j=len-2;
            for(;j>=0;j--){
                if(num[j]<num[len-1]){
                    sign=j;
                    break;
                }
            }
            int retLen=len;
            if(j==-1){
                num[len]=0;
                int temp=num[0];
                num[0]=num[len-1];
                num[len-1]=temp;
                qsort(&num[1],len,sizeof(int),cmp);
                retLen=len+1;
            }else{
                int temp=num[sign];
                num[sign]=num[len-1];
                num[len-1]=temp;
                qsort(&num[sign+1],len-sign-1,sizeof(int),cmp);
            }
            printf("case #%d:\n",i);
            for(int q=0;q<retLen;q++){
                printf("%d",num[q]);
            }
            printf("\n");
        }else{
            printf("case #%d:\n",i);
            printf("%s0\n",s);
        }
        
        
    }
    return 0;
}
