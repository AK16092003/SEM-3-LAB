#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *next;
};

// adjcency list

struct node **adjlst;
int visited[1000];

struct node *insert(struct node *head , int data)
{
	struct node *c = (struct node *)malloc(sizeof(struct node));
	struct node *h = head;
	c->data = data;
	c->next = NULL;
	if(head == NULL) return c;
	
	while(head->next!=NULL) head = head->next;
	head->next = c;
	return h;
}

void dfs(int start_node)
{
	visited[start_node] = 1;
	printf("%d " , start_node);
	
	struct node *cur = adjlst[start_node];
	while(cur!=NULL)
	{
		int new_sc = cur->data;
		if(visited[new_sc] == 0) dfs(new_sc);
		cur = cur->next;
	}
}

void display(struct node * c)
{
	while(c!=NULL)
	{
		printf("%d " , c->data);
		c = c->next;
	}
	printf("\n");
}


int main()
{

	int n , m;
	printf("Enter the number of nodes : ");
	scanf("%d" , &n);
	printf("Enter the number of edges : ");
	scanf("%d" , &m);
	
	// adjacency list
	adjlst = (struct node **)malloc(n*sizeof(struct node *));
	
	for(int i = 0 ; i < n ; i ++)
	{
		//adjlst[i] = (struct node *)malloc(sizeof(struct node));
		adjlst[i] = NULL;
		visited[i] = 0;
	}
	
	
	
	for(int i = 0 ; i < m ; i ++)
	{
		printf("start node | end node  :   ");
		int x , y;
		scanf("%d%d" , &x , &y);
		adjlst[x] = insert(adjlst[x] , y);
		adjlst[y] = insert(adjlst[y] , x);
	}
	for(int i = 0; i < n ; i ++)
	{
		printf("Node %d : " , i);
		display(adjlst[i]);
	}
	
	while(1)
	{
		printf("\nEnter the source node : ");
		int start;
		scanf("%d" , &start);
		
		printf("\nDFS : \n");
		for(int i = 0 ; i < n ; i ++) visited[i] = 0;
		dfs(start);
		
		printf("\nBFS : \n");
		for(int i = 0 ; i < n ; i ++) visited[i] = 0;
		
		struct node *queue = NULL;
		queue = insert(queue , start);
		
		while(queue!=NULL)
		{
			
			int cur_node = queue->data;
			printf("%d " , cur_node);
			visited[cur_node] = 1;
			queue = queue->next;
			
			struct node *next_node = adjlst[cur_node];
			while(next_node!=NULL)
			{
				if(visited[next_node->data] == 0)
				{
					queue = insert(queue , next_node->data);
				}	
				next_node = next_node->next;
			}
			while(queue!=NULL && visited[queue->data]) queue = queue->next;
		}
		
		
	}
}
