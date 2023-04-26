#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int* sToBinaryArray(char* sclip, int arrlen)//arrlen结果数组的长度
{
    int* arr = malloc(arrlen*sizeof(int));memset(arr,0,arrlen);
    int n = 0,temp = 1;
    int slen = strlen(sclip);
    for (int i = slen-1;i>=0;i--)
    {
        n += temp*(sclip[i]-'0');
        temp*=10;
    }
    int r = 0,j = arrlen-1;
    while(n!=0)
    {
        r = n%2;
        n = n/2;
        arr[j--] = r;
    }
    return arr;
}

int main()
{
    char s[500];
    scanf("%s",s);
    //
    printf("0001");
    int digits = strlen(s);//数字位数
    int* tempArr = (int*)malloc(10*sizeof(int));memset(tempArr,0,10*sizeof(int));//输出数字位数的编码
    int tempN = digits, tempr = 0, tempj = 9;
    while(tempN!=0)
    {
        tempr = tempN%2;
        tempN = tempN/2;
        tempArr[tempj] = tempr;
        tempj--;
    }
    for(int i = 0;i<10;i++)
    {
        printf("%d",tempArr[i]);
    }
    free(tempArr);
    //
    printf("\n");
    int j = 0;
    while(j<digits)
    {
        char sclip[3];
        for(int i = 0;i<3;i++){sclip[i] = s[j+i];}
        int arrlen = 0,scliplen = strlen(sclip);
        if(scliplen == 1){arrlen = 4;}
        else if(scliplen == 2){arrlen = 7;}
        else if(scliplen == 3){arrlen = 10;}
        int* p = sToBinaryArray(sclip, arrlen);
        for(int i = 0;i<arrlen;i++){printf("%d",p[i]);}
        free(p);
        j+=3;

    }


    return 0;
}


