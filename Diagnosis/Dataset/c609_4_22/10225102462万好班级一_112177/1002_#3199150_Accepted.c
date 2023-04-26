#include <stdio.h>

int main() {
    int loop;
    scanf("%d",&loop);
    for (int q = 0; q < loop; ++q) {



    int max;
    int c_input;
    int arr[1000];
    int i = 0;
    int s[100];
    int m = 0;

    scanf("%d",&c_input);

    while(c_input){
        arr[i++] = c_input%2;
        c_input = c_input/2;
    }
    int count = 0;
    for (int j = 0;j < i -1; ++j) {
        if(arr[j] != arr[j + 1])
        {
            count++;s[m++] = count + 1;
        }else if(arr[j] == arr[j + 1])
        {
            s[m++] = count + 1;
            count = 0;
        }
    }
    max = s[0];
    for (int j = 1; j < m; ++j) {


        if(s[j] > max)
            max = s[j];
    }printf("case #%d:\n%d\n",q,max);}
}
