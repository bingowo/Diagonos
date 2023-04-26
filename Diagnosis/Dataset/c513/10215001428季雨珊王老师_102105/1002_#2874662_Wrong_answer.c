#include<stdio.h>
#include<math.h>
#include<malloc.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char a[60];
        int length=0;
        while(getchar()!=EOF){
                scanf("%c",&a[length]);
            length++;
        }
        char *b;
        b=(char *)malloc(sizeof(char)*length);
        b[0]=1;b[1]=0;
        int count=2;
        for(int i=2;i<length;i++){
            int flag;
            for(int j=0;j<i;j++){
                if(a[i]!=a[j]) flag=1;
                else{
                    flag=0;
                    b[i]=b[j];
                    break;
                    }
            if(flag==1){
                b[i]=count;
                count++;
            }
            }
        }//count 进制
        int result=pow(count,length-1);
        for(int i=1;i<length;i++){
            result+=b[i]*pow(count,length-1-i);
        }
        printf("case #%d:\n%d",t,result);
    }
    return 0;
}