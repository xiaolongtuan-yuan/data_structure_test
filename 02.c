#include<stdio.h>
#include<time.h>

int main(){
	clock_t start_t, end_t;
	int i,j,k;
    double total_t;
    long int n;
    scanf("%d",&n);
    start_t = clock();
	int sum = 0;
for( i=1; i<n; i++ )
for( j=1; j<i*i; j++ )
if( j%1 == 0 )
for( k=0; k<j; k++ )
sum++;
    end_t = clock();
    printf("Ê±¼ä: %f\n",(double)(end_t - start_t)/CLOCKS_PER_SEC);
	
	return 0;
} 
