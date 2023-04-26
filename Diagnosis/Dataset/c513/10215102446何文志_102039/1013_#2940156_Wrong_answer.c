#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cToThree(char c){
    if(c == '0'){return 0;}
    if(c == '1'){return 1;}
    if(c == '2'){return -1;}
    return 0;
}
int threeToi1(char *s){
    int slen = strlen(s);
    int res = 0;
    for(int i = 0;i<slen;i++){
        res = res*3+cToThree(s[i]);
    }
    return res;
}
void threeToi2(char *s, int *n2){
    int slen = strlen(s);
    char t[slen];memset(t,0,slen*sizeof(char));
    strcpy(t,s);
    int tlen = strlen(t);
    for(int i = 0,j = tlen-1;i<j;i++,j--){
        char tmp = s[i];
        t[i] = t[j];
        t[j] = tmp;
    }
    int n21 = 0,n22 = 1;
    //printf("t = %s\n",t);
    for(int k = 0;k<tlen;k++){
        n22*=3;
        n21 = n21*3+cToThree(t[k]);
    }
    n2[0] = n21;n2[1] = n22;
    //n2[1] = -111;
}
int GCD(int a, int b)
{
    int r = 0;
    while(b!=0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}
void myPrint(int n1,int*n2){
    if(n1 == 0){
        printf("%d %d",n2[0],n2[1]);
        return;
    }
    if(n2[0] == 0){
        printf("%d",n1);
        return;
    }
    printf("%d %d %d",n1,n2[0],n2[1]);
    return;
}
int main()
{
    char s[50];memset(s,0,50*sizeof(char));
    scanf("%s",s);
    char s1[50];memset(s1,0,50*sizeof(char));
    char s2[50];memset(s2,0,50*sizeof(char));
    sscanf(s,"%[^.].%[^.]",s1,s2);
    int n1 = threeToi1(s1);
    int *n2 = (int*)malloc(2*sizeof(int));memset(n2,0,2*sizeof(int));
    threeToi2(s2,n2);

    if((n1<0)&&(n2[0]>0)){
        n1+=1;
        n2[0] = n2[1] - n2[0];
    }
    else if((n1>0)&&(n2[0]<0)){
        n1-=1;
        n2[0] = n2[1] + n2[0];
    }
    else if((n1<0)&&(n2[0]<0)){
        n2[0] = -1*n2[0];
    }
    //printf("n1 = %d, n21 = %d, n22 = %d\n",n1,n2[0],n2[1]);
    int gcd = GCD(n2[0],n2[1]);
    gcd = gcd>0 ? gcd : -1*gcd;
    n2[0]/=gcd;n2[1]/=gcd;
    //printf("s1 = %s\ns2 = %s\n",s1,s2);
    //printf("n1 = %d, n21 = %d, n22 = %d\n",n1,n2[0],n2[1]);


    myPrint(n1,n2);
    return 0;
}
