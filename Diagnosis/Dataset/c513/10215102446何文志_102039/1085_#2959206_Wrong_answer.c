#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 10000

int myMax(int a, int b){
    return a>b? a:b;
}
void reverse(char* s){
    int len = strlen(s);
    for(int i = 0,j = len-1;i<j;i++,j--){
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
    }
    return;
}

void toReverse(char* src, char* des){
    int srcLen = strlen(src),desCnt = 0;
    for(int i = srcLen-1;i>=0;i--){
        des[desCnt++] = src[i];
    }
    return;
}

int BigNumCmp(char*a, char*b){
    int alen = strlen(a),blen = strlen(b);
    if(alen!=blen){
        return alen-blen;
    }
    else{
        return strcmp(a,b);
    }
}

void BigNumMinus1(char* a,char* b,char* res){
    //printf("%d",BigNumCmp(a,b));
    if(BigNumCmp(a,b)<0){
        BigNumCmp(b,a);
        char stmp[MAXLEN+1];memset(stmp,0,(MAXLEN+1)*sizeof(char));
        stmp[0] = '-';
        strcat(stmp,res);
        strcpy(res,stmp);
        return;
    }
    int alen = strlen(a),blen = strlen(b),resCnt = 0;
    int max = myMax(alen,blen);
    char revA[max+1],revB[max+1];
    memset(revA,0,(max+1)*sizeof(char));
    memset(revB,0,(max+1)*sizeof(char));
    toReverse(a,revA);toReverse(b,revB);
    //printf("a = %s, revA = %s, b = %s, revB = %s\n",a,revA,b,revB);
    int up = 0;
    for(int i = 0;i<max;i++){
        int aNum = revA[i]==0? 0:revA[i]-'0',bNum = revB[i]==0? 0:revB[i]-'0';
        int tmp = aNum-bNum;
        int curNum = tmp>=0? tmp:tmp+10;
        res[resCnt++] = up+curNum+'0';
        up = tmp<0? -1:0;
        //printf("%d: a = %d, b = %d,up = %d, curNum = %d, tmp = %d\n",i,aNum,bNum,up,curNum,tmp);
    }
    reverse(res);
}

void BigNumMinus(char* a,char* b,char* res){
    int alen = strlen(a),blen = strlen(b),resCnt = 0;
    int max = myMax(alen,blen);
    char revA[max+1],revB[max+1];
    memset(revA,0,(max+1)*sizeof(char));
    memset(revB,0,(max+1)*sizeof(char));
    toReverse(a,revA);toReverse(b,revB);
    printf("a = %s, revA = %s, b = %s, revB = %s\n",a,revA,b,revB);
    int up = 0;
    for(int i = 0;i<max;i++){
        int aNum = revA[i]==0? 0:revA[i]-'0',bNum = revB[i]==0? 0:revB[i]-'0';
        int tmp = aNum-bNum;
        int curNum = tmp>=0? tmp:tmp+10;
        res[resCnt++] = up+curNum+'0';
        up = tmp<0? -1:0;
        printf("%d: a = %d, b = %d,up = %d, curNum = %d, tmp = %d\n",i,aNum,bNum,up,curNum,tmp);
    }
    res[resCnt-1] = res[resCnt-1] + up;
    if(up<0){
        for(int i = 0;i<resCnt;i++){
            res[i] = '9'-res[i] + '0';
        }
        res[0]-=1;
        res[resCnt-1]-=1;
        res[resCnt] = '-';
    }
    reverse(res);
}

int main()
{

    char a[MAXLEN+1];memset(a,0,(MAXLEN+1)*sizeof(char));
    char b[MAXLEN+1];memset(b,0,(MAXLEN+1)*sizeof(char));
    char res[MAXLEN+1];memset(b,0,(MAXLEN+1)*sizeof(char));
    while(scanf("%s%s",a,b)!=EOF){
        BigNumMinus1(a,b,res);
        printf("%s\n",res);
    }




    return 0;
}
