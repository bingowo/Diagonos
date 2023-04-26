#include <stdio.h>
#include <stdlib.h>
#include <string.h> 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int cmp(const void *p1,const void *p2){
	return strcmp(*((char**)p1),*((char**)p2));
}
int main(int argc, char *argv[]) {
	    int n,i,en=0;
	    scanf("%d",&n);
	    char** arr=(char**)malloc(100*sizeof(char*));
	    char** earr=(char**)malloc(100*sizeof(char*));
	    char str[]="http:";
	    for(i=0;i<n;i++){
	    	arr[i]=(char*)malloc(300);
	    	scanf("%s",arr[i]);
		}
		for(i=0;i<n;i++){
			if(strncmp(arr[i],str,5)==0){
				earr[en]=(char*)malloc(300);
				strcpy(earr[en],arr[i]);
				en++;
			}
			free(arr[i]);
		}
		qsort(earr,en,sizeof(earr[0]),cmp);
		for(i=0;i<en;i++){
			printf("%s\n",earr[i]);
			free(earr[i]);
		}
		free(arr);
		free(earr);
		return 0;
}