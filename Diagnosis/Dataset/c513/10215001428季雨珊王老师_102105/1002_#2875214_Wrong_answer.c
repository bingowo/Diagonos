#include<stdio.h>
#include<math.h>
#include<malloc.h>
#include<strings.h>
int main(){
    int T;
    scanf("%d",&T);
    for(int t=0;t<T;t++){
        char a[61];
        scanf("%s",a);
        int length=strlen(a);
        char *b;
        b=(char *)malloc(sizeof(char)*length);
        b[0]=1;
        int count=1;
        for(int i=1;i<length;i++){
            int flag;
            for(int j=0;j<i;j++){
                if(a[i]!=a[j]) flag=1;
                else{
                    flag=0;
                    b[i]=b[j];
                    break;
                    }
            }
            if(flag==1){
                if(count==1) b[i]=0;
                else b[i]=count;
                count++;
            }
        }//count 进制
        if(count==1) count=2;
        long long int result=pow(count,length-1);
        for(int i=1;i<length;i++){
            result+=b[i]*pow(count,length-1-i);
        }
        printf("case #%d:\n%lld\n",t,result);
    }
    return 0;
}
