#include <stdio.h>
#include <stdlib.h>

int * baseconvertion(int n);
void func(int n1, int n2);

int main()
{
    int T;
    scanf("%d",&T);
    for(int t = 0; t < T; t++){
        int num1;
        int num2;
        scanf("%d %d",&num1,&num2);
        func(num1,num2);
    }
    return 0;
}

void func(int n1, int n2){
    int *s1;
    int *s2;
    int arr1[100];
    int arr2[100];
    int ans = 0;
    int pl = 0;
    s1 = baseconvertion(n1);
    for(int i = 0; i < 100; i++){
        arr1[i] = *(s1 + i);
    }
    s2 = baseconvertion(n2);
    for(int i = 0; i < 100; i++){
        arr2[i] = *(s2 + i);
    }
    for(int i = 0; i < 100; i++){
        if(arr1[i] != arr2[i]){
            ans++;
        }
    }
    printf("%d\n",ans);
}

int * baseconvertion(int n){
    static int s[100];
    for(int i = 0; i < 100; i++){
        s[i] = -1;
    }
    // a/b = c......d
    int a = n;
    int d;
    int pl = 0;
    while(a >0){
        d = a % 2;
        a = (a - d) / 2;
        s[pl] = d;
        pl++;
    }
    return s;
}
