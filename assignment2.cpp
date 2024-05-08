#include <bits/stdc++.h>
using namespace std;
#define N 3

struct Node
{
	Node* parent;
	int mat[N][N];
	int x, y;
	int cost;
	int level;
};

int printMatrix(int mat[N][N])
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
        if(mat[i][j] == 0)
            cout << "_ ";
        else
			printf("%d ", mat[i][j]);
		printf("\n");
	}
}

Node* newNode(int mat[N][N], int x, int y, int newX,int newY, int level, Node* parent)
{
	Node* node = new Node;
	node->parent = parent;
	memcpy(node->mat, mat, sizeof node->mat);
	swap(node->mat[x][y], node->mat[newX][newY]);
	node->cost = INT_MAX;
	node->level = level;
	node->x = newX;
	node->y = newY;
	return node;
}

int row[] = { 1, 0, -1, 0 };
int col[] = { 0, -1, 0, 1 };

int calculateCost(int initial[N][N], int final[N][N])
{
	int count = 0;
	for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            if (initial[i][j]!=0&& initial[i][j] != final[i][j])
                count++;
	return count;
}

int isSafe(int x, int y)
{
	return (x >= 0 && x < N && y >= 0 && y < N);
}

void printPath(Node* root)
{
	if (root == NULL)
		return;
	printPath(root->parent);
	cout << " g-> " << root->level << " h->" << root->cost << " f->" << root->cost+root->level << endl;
	printMatrix(root->mat);

	printf("\n");
}


class comp {
public:
    bool operator()(Node* lhs,Node* rhs) 
    {
		return (lhs->cost + lhs->level)  > (rhs->cost + rhs->level);
    }
};

int getInvCount(int arr[])
{
    int inv_count = 0;
    for (int i = 0; i < 9 - 1; i++)
        for (int j = i+1; j < 9; j++)
             if (arr[j] && arr[i] &&  arr[i] > arr[j])
                  inv_count++;
    return inv_count;
}
 
bool isSolvable(int puzzle[3][3])
{
	// passing as single array 
    int invCount = getInvCount((int *)puzzle);
    return (invCount%2 == 0);
}
 
void solve(int initial[N][N],int x, int y,int final[N][N])
{
	priority_queue<Node*,vector<Node*>, comp> pq;

	Node* root = newNode(initial, x, y, x, y, 0, NULL);
	root->cost = calculateCost(initial, final);

	pq.push(root);
    // cout << "son";
	while (!pq.empty())
	{
        // cout << "s";
        Node* min = pq.top();
		pq.pop();

		if (min->cost == 0)
		{
			printPath(min);
            cout << "step to solve : " << min->level << endl;
			return;
		}

		for (int i = 0; i < 4; i++)
		{
			if (isSafe(min->x + row[i], min->y + col[i]))
			{
				Node* child = newNode(min->mat, min->x,
                min->y, min->x + row[i],
                min->y + col[i],
                min->level + 1, min);

				child->cost = calculateCost(child->mat, final);
				pq.push(child);
			}
		}
	}
}

int main()
{
	int initial[N][N] =
	{
		{1, 2, 3},
		{5, 6, 0},
		{7, 8, 4}
	};

    for(int i=0;i<3;i++)
        for(int j=0;j<3;j++)
            cin >> initial[i][j];
    
	// int x = 1, y = 2;
	int x , y; cin >> x; cin >> y;

	int final[N][N] =
	{
		{1, 2, 3},
		{4, 5, 6},
		{7, 8, 0}
	};


   cout << endl;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
        if(final[i][j] == 0)
            cout << "_ ";
        else
			cout << final[i][j] << " ";
	cout << endl;}

	cout << endl;

	if(!isSolvable(initial))
	{
		cout << "Not Solvable !!" << endl;
		return 0;
	}
	solve(initial, x, y, final);
	return 0;
}
