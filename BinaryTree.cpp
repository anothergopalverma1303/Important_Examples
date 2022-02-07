
struct Node
{
	int data;
	Node* left;
	Node* right;
	Node(int n)
	{
		data = n;
		left = NULL;
		right = NULL;
	}
};
void preorder(Node* root)
{
	if(root==NULL)
		return;
	cout<<root->data<<" ";
	preorder(root->left);
	preorder(root->right);
	
}
void inorder(Node* root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}
void postorder(Node* root)
{
	if(root==NULL)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}
/*
void printLevelOrder(Node* root)
{
	if(root==NULL)
		return;
	else
	{
		queue<Node*> q;
		q.push(root);
		q.push(NULL);

		while(!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if(node!=NULL)
			{
				cout<<node->data<<" ";
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
			else if((node==NULL)&&(!q.empty()))
			{
				q.push(NULL);
			}
		}
	}
}
*/

void printLevelOrder(Node* root)
{
	if(root==NULL)
		return;
	else
	{
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if(node!=NULL)
			{
				cout<<node->data<<" ";
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
			else if(!q.empty())
			{
				q.push(NULL);
			}
		}
	}
}
/*
void printSumOfKthLevel(Node* root, int n)
{
	int flag = 0;
	int sum = 0;
	if(root==NULL)
		return;
	else
	{
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if(node!=NULL)
			{
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
			if((node!=NULL)&&(flag == 2))
			{
				sum+=node->data;
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
			if(!q.empty())
			{
				q.push(NULL);
			}
			flag++;
		}
	}
}


void KthLevelSum(Node* root, int k)
{
	int level = 0;
	int sum = 0;
	if(root==NULL)
		return;
	else
	{
		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		while(!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if(node!=NULL)
			{
				cout<<node->data<<" ";
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
				level++;
			}
			if((node!=NULL)&&(level==3))
			{
				sum+=node->data;
			}
			else if(!q.empty())
			{
				q.push(NULL);
				level++;
			}
		}
	}
	cout<<sum;
}
*/

int sumAtK(Node* root, int k)
{
	if(root==NULL)
		return -1;

		queue<Node*> q;
		q.push(root);
		q.push(NULL);
		int level = 0;
		int sum = 0;
		while(!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if(node!=NULL)
			{
				if(level==k)
				{
					sum+=node->data;
				}
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
			else if((node==NULL)&&(!q.empty()))
			{
				q.push(NULL);
				level++;
			}
	}
	return sum;
}
int number_of_nodes(Node* root)
{
	int sum = 0;
	if(root==NULL)
		return -1;
	
		queue<Node*> q;
		q.push(root);
		q.push(NULL);

		while(!q.empty())
		{
			Node* node = q.front();
			q.pop();
			if(node!=NULL)
			{
				sum++;
				if(node->left)
					q.push(node->left);
				if(node->right)
					q.push(node->right);
			}
			else if((node==NULL)&&(!q.empty()))
			{
				q.push(NULL);
			}
		}
		return sum;
}

/*int sum_of_all_nodes(Node* root)
{
	if(root==NULL)
		return -1;
	int sum = 0;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		Node* node = q.front();
		q.pop();
		if(node!=NULL)
		{
			sum+=node->data;
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
		else if((node==NULL)&&(!q.empty()))
			q.push(NULL);

	}
	return 	sum;
}
*/

int num_of_nodes_using_recursion(Node* root)
{
	if(root==NULL)
		return 0;
	return num_of_nodes_using_recursion(root->left) + num_of_nodes_using_recursion(root->right) + 1;	
}
int sum_of_all_nodes(Node* root)
{
	if(root==NULL)
		return 0;
	return sum_of_all_nodes(root->left) + sum_of_all_nodes(root->right) + root->data;
}

int return_hight(Node* root)
{
	if(root==NULL)
		return -1;
	int hight = 0;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(!q.empty())
	{
		Node* node = q.front();
		q.pop();
		if(node!=NULL)
		{
			if(node->left)
				q.push(node->left);
			if(node->right)
				q.push(node->right);
		}
		else if((node==NULL)&&(!q.empty()))
		{
			hight++;
			q.push(NULL);
		}
	}
	return hight+1;
}

int hight_2(Node* root)
{
	if(root==NULL)
		return 0;
	int lhight = hight_2(root->left);
	int rhight = hight_2(root->right);
	return max(lhight, rhight) + 1;
}

int calculateHight(Node* root)
{
	if(root==NULL)
		return 0;
	int lhight = calculateHight(root->left);
	int rhight = calculateHight(root->right);
	return max(lhight, rhight) +1;
}
int calculateDiameter(Node* root)
{
	if(root==NULL)
		return 0;
	int lhight = calculateHight(root->left);
	int rhight = calculateHight(root->right);
	int currentDiameter = lhight+rhight+1;
	int lDiameter = calculateDiameter(root->left);
	int rDiameter = calculateDiameter(root->right);
	return max(currentDiameter, max(lDiameter, rDiameter)); 
}

void sumReplacement(Node* root)
{
	if(root==NULL)
		return;
	sumReplacement(root->left);
	sumReplacement(root->right);
	
	if(root->left!=NULL)
		root->data += root->left->data;
	if(root->right!=NULL)
		root->data += root->right->data;
}

bool isBalanced(Node* root)
{
	if(root==NULL)
	{
		return true;
	}
	if(isBalanced(root->left)==false)
		return false;
	if(isBalanced(root->right)==false)
		return false;
	int lh = calculateHight(root->left);
	int rh = calculateHight(root->right);
	if(abs(lh-rh) <= 1)
		return true;
	else
		return false;

}

void rightView(Node* root)
{
	if(root==NULL)
		return;
	queue<Node*> q;
	q.push(root);
	while(!q.empty())
	{
		int n = q.size();
		for(int i = 0  ; i < n ; i++)
		{
			Node* curr = q.front();
			q.pop();

			if(i==n-1)
				cout<<curr->data<<" ";

		if(curr->left != NULL)
			q.push(curr->left);

		if(curr->right != NULL)
			q.push(curr->right);
		}


	}
}

int main()
{
	Node* root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	preorder(root);
	cout<<endl;
	inorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	printLevelOrder(root);
	cout<<endl;
	cout<<sumAtK(root, 2);
	cout<<endl;
	cout<<number_of_nodes(root);
	cout<<endl;
	cout<<sum_of_all_nodes(root);
	cout<<endl;
	cout<<num_of_nodes_using_recursion(root);
	cout<<endl;
	cout<<sum_of_all_nodes(root);
	cout<<endl;
	cout<<return_hight(root);
	cout<<endl;
	cout<<hight_2(root);
	cout<<endl;
	cout<<calculateDiameter(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	if(isBalanced(root))
		cout<<"Balanced";
	else
		cout<<"Unbalanced";

	Node* root2 = new Node(1);
	root2->left = new Node(2);
	root2->left->left = new Node(3);	
	root2->left->left->left = new Node(4);
	cout<<endl;
	if(isBalanced(root2))
		cout<<"Balanced";
	else
		cout<<"Unbalanced";
	cout<<endl;
	rightView(root);
	return 0;
}
