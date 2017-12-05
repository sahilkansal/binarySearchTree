#include"Header.h"
#include<iostream>

using namespace std;


tree::tree(){
	head = NULL;
}

node::node(){
	info = 0;
	left = NULL;
	right = NULL;
}

node::node(int a, node *left, node*right){
	info = a;
	this->left = left;
	this->right = right;
}

node* tree::search_node1(int val, node * curr){
	if (curr == NULL){
		cout << "item not found in tree" << endl;
		return NULL;
	}
	else if ((curr)->info>val){
		search_node1(val, ((curr)->left));
	}
	else if ((curr)->info<val){
		search_node1(val, ((curr)->right));
	}
	else if (val == curr->info){
		cout << "item found in tree" << endl;
		return curr;
	}
}

node * tree::search_node(int val){
	if (head == NULL){
		return 0;
	}
	else{
		if (val < head->info){
			return search_node1(val, head->left);
		}
		else{
			return search_node1(val, head->right);
		}
	}
}

void tree::insert_node1(int val, node **curr){

	node *ptr = new node(val, NULL, NULL);
	if (*curr == NULL){
		*curr = ptr;
		return;
	}
	else if ((*curr)->info>val){
		insert_node1(val, &((*curr)->left));
	}
	else{
		insert_node1(val, &((*curr)->right));
	}

}

void tree::insert_node(int val){
	if (head == NULL){
		node*ptr = new node(val, NULL, NULL);
		head = ptr;
	}
	else{
		if (val < head->info){
			insert_node1(val, &(head->left));
		}
		else{
			insert_node1(val, &(head->right));
		}
	}
}


void tree::print_tree1(node *curr){
	if (curr != NULL){
		print_tree1(curr->left);
		cout << curr->info << ",";
		print_tree1(curr->right);
	}
}


void tree::print_tree(){
	if (head != NULL){
		print_tree1(head);
		cout << endl;
	}
	else{
		cout << "tree is empty" << endl;
	}
}



void tree::delete_node(int val){
	delete_Node(head, val);
}


node * minValueNode(struct node* node)
{
	struct node* current = node;

	while (current->left != NULL)
		current = current->left;

	return current;
}



node * tree::delete_Node(node *root, int val){
	if (root == NULL){
		cout << "No such element exist" << endl;
		return 0;
	}
	if (val > root->info){
		root->right = delete_Node(root->right, val);
	}
	else if (val < root->info){
		root->left = delete_Node(root->left, val);
	}
	else{
		if (root->left == NULL){
			node *ptr = root->right;
			free(root);
			return ptr;
		}
		else if (root->right == NULL){
			node *ptr = root->left;
			free(root);
			return ptr;
		}
		node *ptr = minValueNode(root->right);
		root->info = ptr->info;
		root->right = delete_Node(root->right, ptr->info);
	}
	return root;
}



int tree::count_node(node *ptr){
	int count = 0;
	if (head == NULL){
		return 0;
	}
	else{
		count++;
		if (ptr->left != NULL){
			count += count_node(ptr->left);
		}
		if (ptr->right != NULL){
			count = count + count_node(ptr->right);
		}
		if (ptr->left == NULL&&ptr->right == NULL){
			return count;
		}
		return count;
	}
}

int tree::count_node(){
	return count_node(head);
}


node *tree::mirror(node *here) {

	if (here == NULL)
		return NULL;
	else {
		node *newNode = (node*)malloc(sizeof(struct node));
		newNode->info = here->info;
		newNode->left = mirror(here->right);
		newNode->right = mirror(here->left);
		return newNode;
	}
}

void tree::mirror1(node *here){

	this->head = mirror(here);
}

void tree::mirror_trees(tree *t){
	//this->head->right->left->info = 6;
	if (this->count_node() != t->count_node()){
		cout << "not mirror image" << endl;
	}
	else if (this->head != NULL&&t->get_head() != NULL){
		if (mirror_trees1(this->head, t->get_head()) == 1){ cout << "mirror image" << endl; }
		else{ cout << "not mirror image" << endl; }
	}
	else{
		cout << "both trees are null" << endl;
	}
}

int mirror_trees1(node*head1, node*head2){
	int a = 0;
	if (head1 != NULL&&head2 != NULL){
		if (head1->info == head2->info){
			a = mirror_trees1(head1->left, head2->right);
			if (a == 1)a = mirror_trees1(head1->right, head2->left);
			return a;
		}
		else{
			return a;
			cout << "not mirror image" << endl;
		}
	}
	return 1;
}


node* tree::remove_half_node(node*ptr){
	if (ptr->left == NULL&&ptr->right != NULL){
		return remove_half_node(ptr->right);
	}
	if (ptr->left != NULL&&ptr->right == NULL){
		return remove_half_node(ptr->left);
	}
	if (ptr->left == NULL&&ptr->right == NULL){
		return (ptr);
	}
	if (ptr->left != NULL&&ptr->right != NULL){
		return ptr;
	}
}

void tree::remove_half_node(){
	if (head != NULL){
		if (head->left != NULL && head->right != NULL){
			//head = 0;
			head->left = remove_half_node(head->left);
			head->right = remove_half_node(head->right);
		}
		else if (head->left == NULL || head->right == NULL){
			/*remove_half_node(head->left);
			remove_half_node(head->right);*/
			head = 0;
		}
	}
}

void tree::kthLargestUtil(node *root, int k, int &c)
{
	// Base cases, the second condition is important to
	// avoid unnecessary recursive calls
	if (root == NULL || c >= k)
		return;

	// Follow reverse inorder traversal so that the
	// largest element is visited first
	kthLargestUtil(root->right, k, c);

	// Increment count of visited nodes
	c++;

	// If c becomes k now, then this is the k'th largest 
	if (c == k)
	{
		cout << "K'th largest element is "
			<< root->info << endl;
		return;
	}

	// Recur for left subtree
	kthLargestUtil(root->left, k, c);
}

// Function to find k'th largest element
void tree::kthLargest(int k)
{
	// Initialize count of nodes visited as 0
	int c = 0;

	// Note that c is passed by reference
	kthLargestUtil(head, k, c);
}



void check_complete(node *head){
	if (head->left != NULL&&head->right != NULL)
	{
		check_complete(head->left);
		check_complete(head->right);
	}
	//	else if()
}