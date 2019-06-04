#ifndef __MY_LIST__
#define __MY_LIST__

#include <iostream>
class list {
public:

	virtual int add_head (int data) = 0;
	virtual int add_tail (int data) = 0;
	virtual int insert_at (int data, int position) = 0;
	virtual	int remove_head() = 0;
	virtual	int remove_tail() = 0;
	virtual	int remove_at (int position) = 0;
	virtual int delete_list() = 0;
	virtual	void display () = 0;
	virtual int reverse_list() = 0;
	virtual void reverse_list_recursive() = 0;

	/* Reverse the list in k size slot. 
	example if user gives size k = 3, the list will be reversed in 3 - 3 segments, means 3 nodes reversed and 
	after that next 3 nodes and so on*/

	virtual int reverse_in_slot(int slot_size) = 0;
	/*funtion swap_nodes swaping pair of nodes in list 
	example. if list is like 1->3->5->2 then output of the function will be 3->1->2->5
		and for odd number of nodes 1->3->2 output will be 3->1->2
	*/
	virtual int swap_nodes() = 0;
	virtual bool find_and_remove_loop() = 0;
	virtual void removeLoop(void *loop_node) = 0;
	virtual void make_loop(int node_num) = 0;
	static list * get_list(const char * type);
	static void destroy_list(list *ptr);
	list();
	virtual ~list();
};

#endif /* __MY_LIST__ */
