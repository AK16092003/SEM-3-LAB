#include<stdio.h>
#include<stdlib.h>

int parent[1000];

void swap(int *p , int *q)
{
	int t = *p;
	*p = *q;
	*q = t;
}

int find_top(int u)
{
	if(parent[u] == u)
		return u;
	else 
		return find_top(parent[u]);
}

int same_comp(int u , int v)
{

	int a = find_top(u);
	int b = find_top(v);
	if(a == b) return 1;
	else return 0;
		
}

int merge(int u , int v)
{
	int a = find_top(u);
	int b = find_top(v);
	parent[a] = b;
}

int main()
{

	int n , m;
	printf("Enter the number of nodes : ");
	scanf("%d" , &n);
	printf("Enter the number of edges : ");
	scanf("%d" , &m);
	
	int weight[m];
	int node1[m];
	int node2[m];
	
	for(int i = 0 ; i <= n ; i ++)
	{
		parent[i] = i;
	}
	
	for(int i = 0 ; i < m ; i ++)
	{
		printf("start node | end node | weight :   ");
		int x , y , z;
		scanf("%d%d%d" , &x , &y , &z);
		
		weight[i] = z;
		node1[i] = x;
		node2[i] = y;

	}
	
	// sort the edges
	
	for(int i = 0 ; i < m ; i ++)
	{
		for(int j = 0 ; j < m-i-1 ; j ++)
		{
			if(weight[j] >= weight[j+1])
			{
				// swap
				swap(&(weight[j]) ,&(weight[j+1]));
				swap(&(node1[j]) , &(node1[j+1]));
				swap(&(node2[j]) , &(node2[j+1]));
				
			}
		}
	}
	printf("\nSorted weights : \n\n");
	
	for(int i = 0 ; i < m ; i ++)
	{
		printf("%d %d %d\n" , weight[i] , node1[i] , node2[i]);
	}
	
	
	// kruskal algorithm;
	int count = 0;
	int tot_weight = 0;
	for(int i = 0 ; i < m ; i ++)
	{
		if(same_comp(node1[i] , node2[i]))
		{
			printf("forms a cycle\n");
		}
		else
		{
			printf("choosed : %d   (%d) --- (%d) " , weight[i] , node1[i] , node2[i]);
			count++;
			tot_weight += weight[i];
			merge(node1[i] , node2[i]);
		}
		
		if(count == n-1)
		{
			printf("Minimal Spanning Tree constructed\n\n");
			printf("Minimal Value : %d\n\n " , tot_weight);
			break;
		}
	}
		
}
