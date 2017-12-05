struct node{
	int info;
	node *left;
	node *right;
public:
	node();
	node(int, node*, node*);
};

class tree{
	node *head;
	node*delete_Node(node*, int);
	node* search_node1(int val, node * curr);
	void insert_node1(int, node **);
	void print_tree1(node *);
	int count_node(node *);
	node *mirror(node *here);
	node* remove_half_node(node *);
	void kthLargestUtil(node *root, int k, int &c);
public:

	tree();
	node *get_head()const{
		return head;
	}
	node * search_node(int);
	void insert_node(int);
	void print_tree();
	void delete_node(int);
	int count_node();
	void mirror1(node*);
	void mirror_trees(tree*);
	void remove_half_node();
	void kthLargest(int k);
};
int mirror_trees1(node*head1, node*head2);
//void mirror_trees(node*, node*);

void check_complete(tree*ptr);