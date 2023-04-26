#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* getBase(char* s)
{
    int len = strlen(s);
    int i = 0,j = 0,k = 0;
    char* baseList = malloc(61*sizeof(char));
    memset(baseList,0,61*sizeof(char));
    for(i = 0;i<len;i++)
    {
        int flag = 0;
        for(j = i+1;j<len;j++)
        {
            if(s[i]==s[j]){flag = 1;break;}//后面有元素相同
        }
        if(flag == 0){baseList[k++] = s[i];}
    }
    return baseList;
}

void baseSort(char* baseList, char* s)//baseList中每个元素第一次出现的位置为pi-p0
{
    int i = 0,baseLen = strlen(baseList);
    int indexList[baseLen];memset(indexList,0,baseLen*sizeof(int));
    char* p0 = s;
    for(i = 0;i<baseLen;i++)
    {
        char* pi = strchr(s,baseList[i]);
        indexList[i] = pi - p0;
    }
    //根据第一次出现的位置冒泡排序
    for(int i = 0;i<baseLen-1;i++)
    {
        for(int j = i;j<baseLen-1;j++)
        {
            if(indexList[j]>indexList[j+1])
            {
                char temp = baseList[j];
                baseList[j] = baseList[j+1];
                baseList[j+1] = temp;
            }
        }
    }

}

int getValue(char* baseList,char c)
{
    int base = strlen(baseList);
    if(c == baseList[0]){return 1;}
    else if(c==baseList[1]){return 0;}
    for(int i = 2;i<base;i++)
    {
        if(c==baseList[i])
        {
            return i;
        }
    }
}


int main()
{
    int T = 0;
    scanf("%d",&T);
    int i = 0;
    for(i = 0;i<T;i++)
    {
        char s[61];memset(s,0,61*sizeof(char));
        scanf("%s",s);
        char* baseList = getBase(s);
        baseSort(baseList,s);

        long long res = 0;
        int j = 0,base = strlen(baseList);
        while(s[j]!=0)
        {
            int temp = getValue(baseList,s[j]);
            res = res*base+temp;
            j++;
        }


        //printf("%s\n",baseList);
        printf("case #%d:\n%d\n",i,res);
        free(baseList);
    }

    return 0;
}
