#include<stdio.h>
int main(){
    char fund[38] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H'
    ,'I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z','\0'};
    int T;
    int N[999],R[999];
    char ans[999][999];
    scanf("%d",%T);
    do{
        scanf("%d %d",N,R);
    }while (getchar != '\n');
    for(int i = 0;i < T + 1;i++){
        int k = 0,j = 0;
        while (N[i] >= 0){
            ans[i][j++] = N[i] % R[i];
            N[i] /= R[i];
        }
        printf("%s",ans[i][k++]);
        k = 0,j = 0;
    }
    return 0;
}