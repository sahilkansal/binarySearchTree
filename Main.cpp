#include<iostream>
#include"Header.h"

using namespace std;

int main(){
	tree tr;
	tree *ptr = &tr;
	tr.insert_node(5);
	tr.insert_node(7);
	tr.insert_node(1);
	tr.insert_node(9);
	tr.insert_node(8);
	tr.insert_node(10);
	tr.insert_node(2);
	tr.insert_node(3);
	tr.insert_node(4);
	tr.insert_node(13);
	tr.insert_node(11);
	/*tr.insert_node(12);*/
	tr.print_tree();

	tree tr1;
	tr1.mirror1(tr.get_head());
	tr1.print_tree();
	tr1.mirror_trees(ptr);

	tr.remove_half_node();
	tr.print_tree();

	tr.kthLargest(3);
	cin.get();
}