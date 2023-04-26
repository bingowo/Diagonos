#include<stdio.h>
#include<string.h>
#include<malloc.h>



char Bigger(char alph){
    if(alph >= 'a' && alph <= 'z')
        return (alph - 32);
    else return alph;
}
void Merge(char *a[], int start, int mid, int end){
    char *result[100], ch1, ch2;
    int i = start, k = 0, j = mid + 1;
    while(i <= mid && j <= end){
        int ii = 0, flag = 0;
        while(ii < strlen(a[j]) && ii < strlen(a[i])){
            ch1 = Bigger(*(a[i]+ii));
            ch2 = Bigger(*(a[j]+ii));
            if(strchr(sort , ch1) > strchr(sort , ch2)){
                result[k++] = a[j++];
                flag = 1;
                break;
            }
            if(strchr(sort , ch1) < strchr(sort , ch2)){
                result[k++] = a[i++];
                flag = 1;
                break;
            }
            else ii++;
        }
        if(flag == 0){
            if(ii < strlen(a[j]))result[k++] = a[i++];
            else result[k++] = a[j++];
        } 
    }
    while(i <= mid)
        result[k++] = a[i++];
    while(j <= end)
        result[k++] = a[j++];
        
    for(int n = 0;n < k;n++){
        a[start++] = result[n];
    }
 }

 void MergeSort(char* a[],int start, int end){
     if(start >= end)return;
     int mid = (start+end)/2;
     MergeSort(a, start, mid);
     MergeSort(a, mid+1, end);
    Merge(a, start, mid, end);
 }

int main(){
    char sort[27];
    char word[20], *p, *words[100];
    while(scanf("%s",sort)){
    int i = 0;
        do{
            scanf("%s",word);
            p = (char*)malloc(sizeof(char)*strlen(word));
            strcpy(p,word);
            words[i++] = p;
        }while(getchar()!='\n');
        MergeSort(words, 0, i-1);
        for(int n = 0;n < i ;n++){
            printf("%s ", words[n]);
        }
        printf("\n");
        i--;
        for(i;i >= 0;i--)
            free(words[i]);
    }
}
