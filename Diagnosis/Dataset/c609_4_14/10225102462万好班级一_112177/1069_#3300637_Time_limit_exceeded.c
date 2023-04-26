#include <stdio.h>

int find(const int arr[],int len,int targ);
int method(int i,int arr[],int kpl);

int max,tar;

int main(){
    while(1){
        scanf("%d %d",&max,&tar);
        if(max == -1&&tar == -1)break;
        int arr[max];
        printf("%d\n",method(0,arr,1)/2 + method(0,arr,0)/2);
    }
}

int method(int i,int arr[],int kpl){
    if(i == max) return find(arr,max,tar);
    arr[i] = kpl;
    return method(i+1,arr,0) + method(i+1,arr,1);
}

int find(const int arr[],int len,int targ){//arr[len]
    int maxi = 0,cnt = 0;
    for (int i = 0; i < len; ++i) {
        if(arr[i] == 1)cnt++;
        else if(arr[i] == 0){if(cnt > maxi)maxi = cnt;cnt = 0;}
    }maxi = (maxi > cnt)? maxi:cnt;
    if(maxi >= targ)return 1;
    else return 0;
}