#include<stdio.h>
#include<stdlib.h>
int main(){
	int m;
	int i,j;
	int **b;
	int *a; 
	scanf("%d",&m);
	a=(int*)malloc(sizeof(int)*m);//用于存每个数组的长度	
	b=(int**)malloc(sizeof(int*)*m);//二维数组存不同的数组 
	for(i=0;i<m;i++){
		scanf("%d",&a[i]);
		b[i]=(int*)malloc(sizeof(int)*a[i]);
		for(j=0;j<a[i];j++){
			scanf("%d",&b[i][j]);
		} 
	}
/*	for(i=0;i<m;i++){
		for(j=0;j<a[i];j++){
			printf("%d ",b[i][j]);
		}
		printf("\n"); 
}*/
	int x=0;
	for(i=0;i<m;i++){
		x=0;
		for(j=0;j<a[i];j++){
			if(b[i][j]==j){
				printf("%d ",j);
				x++;
			}
			
		}
		if(x==0)
			printf("-1");
		printf("\n"); 
}	
	free(a);
	for(i=0;i<m;i++)
	free(b[i]);
	free(b);
	return 0;

}
