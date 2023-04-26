#include<stdio.h>
#include<string.h>
#include<malloc.h>

void Merge(char *a[],const char b[], int start, int mid, int end){
    char *result[100], ch1, ch2;
    int i = start, k = 0, j = mid + 1;
    while(i <= mid && j <= end){
        if(*(a[i]) >= 'a' && *(a[i]) <= 'z'){
            ch1 = *(a[i]) - 32;
        }
        else ch1 = *(a[i]);
        if(*(a[j]) >= 'a' && *(a[j]) <= 'z'){
            ch2 = *(a[j]) - 32;
        }
        else ch2 = *(a[j]);

        if(strchr(b , ch1) > strchr(b , ch2)){
            result[k++] = a[j++];
        }
        else {
            result[k++] = a[i++];
        }
    }
    while(i <= mid)
        result[k++] = a[i++];
    while(j <= end)
        result[k++] = a[j++];
    
    for(int n = 0;n < k - 1 ;n++){
        a[start++] = result[n];
    }
 }

 void MergeSort(char* a[],int start, int end, const char b[]){
     if(start >= end)return;
     int mid = (start+end)/2;
     MergeSort(a, start, mid, b);
     MergeSort(a, mid+1, end, b);
    Merge(a, b, start, mid, end);
 }

int main(){
    char sort[27], word[20], *p, *words[100], *result[100];
    int i = 0;
    scanf("%s",sort);
    do{
        scanf("%s",word);
        p = (char*)malloc(sizeof(char)*strlen(word));
        strcpy(p,word);
        words[i++] = p;
    }while(getchar()!='\n');
    MergeSort(words, 0, i-1, sort);
    for(int n = 0;n < i ;n++){
        printf("%s ", words[n]);
    }

