#ifndef __SINGLY_LIST__
#define __SINGLY_LIST__
#include <list.h>
class singly_list : public list {
	struct linked_list {
		int data;
		struct linked_list * next;
	} *head;
public:
	virtual int add_head (int data);
        virtual int add_tail (int data);
        virtual int insert_at (int data, int position);
        virtual int remove_head();
        virtual int remove_tail();
        virtual int remove_at (int position);
        virtual int delete_list();
	virtual void display();
        virtual int reverse_list();
        virtual void reverse_list_recursive();
	virtual int reverse_in_slot (int slot);
        virtual int swap_nodes();
	virtual bool find_and_remove_loop();
        virtual void removeLoop(void *loop_node);
        virtual void make_loop(int node_num);
	singly_list();
	~singly_list();
};
#endif /* __SINGLY_LIST__ */
