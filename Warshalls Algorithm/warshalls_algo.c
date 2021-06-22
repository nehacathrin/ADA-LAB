/*1)To find path matrix using Warshalls algorithm*/
#include<stdio.h>
#include<conio.h>
#include<process.h>
int a[10][10],p[10][10],n;
void warshalls();
void main()
{
	printf("Enter no of vertices\n");
	scanf("%d",&n);
	printf("Enter adjacency matrix :\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			scanf("%d",&a[i][j]);
	}
	warshalls();
	printf("Path matrix :\n");
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			printf("%d ",p[i][j]);
		printf("\n");
	}
}
void warshalls()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			p[i][j]=a[i][j];
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if((p[i][j]!=1)&&(p[i][k]==1)&&(p[k][j]==1))
					p[i][j]=1;
			}
		}
	}
}