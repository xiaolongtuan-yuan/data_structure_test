#include<stdio.h>  
#include<stdlib.h>  
  
  
int main()  
{  
    int **a;  //�ö���ָ�붯̬�����ά����  
    int i,j;  
    int m,n;  
    printf("����������\n");  
    scanf("%d",&m);  
    printf("����������\n");  
    scanf("%d",&n);  
    a=(int**)malloc(sizeof(int*)*m);  
    for(i=0;i<m;i++)  
    a[i]=(int*)malloc(sizeof(int)*n);  
    for(i=0;i<m;i++)  
    for(j=0;j<n;j++)  
    printf("%p\n",&a[i][j]);     //���ÿ��Ԫ�ص�ַ��ÿ�е�������֮��ĵ�ַʱ�����ģ�������֮��ĵ�ַ������  
    for(i=0;i<m;i++)  
    free(a[i]);  
    free(a);  
    return 0;  
}  
