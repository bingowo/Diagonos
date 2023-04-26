#include<stdio.h>
#include<string.h>

int sum(char a[]);
int main()
{
    char a[51];
    int max;
    scanf("%s",&a);
    max = sum(a);
    printf("%d",max);
    return 0;
}
int sum(char a[]){
    char b[51];
    int i = strlen(a),sum[50]={1},count=1,n=0,j,max;
    for(j = 0;j<i-1;j++){
        if (b[j] != b[j+1]){
            count = count +1;
            sum[n++] = count;
        }
        else{
            sum[n++] = count;
            count = 1;
        }
    }
    max = sum[0];
    for(j = 0;j<n;j++){
        if(sum[j]>max) max = sum[j];
    }
    return max;
}

