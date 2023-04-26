#include<stdio.h>
#include<string.h>
#include<math.h>
int code(char s[])
{
    int count;
    count=strlen(s);
    int num=count;
    int i,j,k=0;//i,j用来比较每个元素，k为元素分配数值
    int message[60]={1};
    if(count==1) return 1;
    for(i=1;i<=count;i++){
        if(s[i]=='\0') break;
        message[i]=k;
        k++;
        for(j=0;j<i;j++){
            if(s[i]==s[j]){
                num--;
                k--;
                message[i]=message[j];
                break;
            }
        }
    }
    int sum=0,ret,eop=count;
    for(int i=0;i<count;i++){
        ret=pow(num,(--eop));
        sum=sum+message[i]*ret;
    }
    return sum;
}
int main()
{
    char s[61];
    int T;
    int N[10];
    scanf("%d",&T);
    for(int i=0;i<T;i++){
        scanf("%s",&s);
        N[i]=code(s);
    }
    for(int j=0;j<T;j++){
        printf("case #%d:\n",j);
        //code(s);
        printf("%d\n",N[j]);
    }
    return 0;
}

