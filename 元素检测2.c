#include<stdio.h>
int main(){
	int x=0,y=0,i,j,a[10],b[10];
	scanf("%d",&x);
	for(i=0;i<x;i++){
		scanf("%d",&a[i]); 
		for(j=0;j<a[i];j++){
			scanf("%d",&b[j]);
		}
	}
	for(i=0;i<x;i++){
		for(j=0;j<a[i];j++){
			if(b[j]==j){
				printf("%d",j);
				y++;
			}
			if(y==0)
				printf("-1");
		}
	}
	
	return 0;
}
