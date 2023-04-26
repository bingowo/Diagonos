#include <stdio.h>
#include <string.h>

int max(int a, int b){
    return a > b ? a : b;
}

//find 两字符串的所有头位置 （尾位置=头位置+len）
//取所有的最大距离maxdis

int find(char s[], char s1[], int arr[]){
    char*p = strstr(s, s1);
    int index = 0;
    while (p != NULL){
        arr[index++] = p-s;
        p = strstr(s+arr[index-1]+1, s1);
    }
    return index;
}

int main(){
    int T;
    scanf("%d ", &T);
    for (int t = 0; t < T; t++){
        printf("case #%d:\n", t);
        char s[85] = {0}, s1[85] = {0}, s2[85] = {0};
        gets(s1);
        gets(s2);
        gets(s);
        int arr1[85] = {0}, arr2[85] = {0};
        int index1 = find(s, s1, arr1), index2 = find(s, s2, arr2);
        if(index1*index2==0){
            printf("0\n");
            continue;
        } 
        int maxdis = max(0, max(arr2[index2-1]-arr1[0]-strlen(s1), arr1[index1-1]-arr2[0]-strlen(s2)));
        printf("%d\n", maxdis);
    }
    return 0;
}