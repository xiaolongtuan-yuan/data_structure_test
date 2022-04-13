#include<stdio.h>
#include<time.h>

int main(){
	clock_t start_t, end_t;
    double total_t;
    long int n;
    scanf("%d",&n);
    start_t = clock();
	int sum = 0;
    for(int i=0; i<n; i++)
      sum++;
    end_t = clock();
    printf("Ê±¼ä: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	return 0;
} 
