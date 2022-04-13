#include<stdio.h>
#include<time.h>

int main(){
	int n,m;
	scanf("%d",&n);
	m = n;	
	int i; 
	int a[10][100]={0};
	while(n>0){
		scanf("%d\n",&a[n-1][0]);
		for(i=0;i<a[n-1][0];i++)
		scanf("%d",&a[n-1][i]);
		n--;
	}
	while(m>0)
	{
		int x = 0;
		for(i=0;i<a[m-1][0];i++){
			if(a[m-1][i]==(i-1)){
				printf("%d ",a[m-1][i]);
				x++;			
			}
		}
		if(x == 0)
			printf("-1");
		printf("\n");
		m--;
	}
	
	return 0;
}

