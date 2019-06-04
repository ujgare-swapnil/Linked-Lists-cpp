#include <list.h>
#include <iostream>
#include <singly_list.h>

using namespace std;
singly_list::singly_list() {
                head = NULL;
        }

singly_list::~singly_list() {
                cout<<"------~singly_list"<<endl;
                delete_list();
        }
int singly_list::add_head(int data) {
	struct linked_list *obj = NULL;

		struct linked_list *tmp = NULL;

		obj = new struct linked_list;
                if (obj == NULL) {
                        return -1;
                }

                obj->next = NULL;
                obj->data = data;
		
		tmp = head;
		head = obj;
		head->next = tmp;
		return 0;
}

int singly_list::add_tail (int data) {
	struct linked_list *obj = NULL;
        if (head == NULL) {
                obj = new struct linked_list;
                if (obj == NULL) {
                        return -1;
                }

                obj->next = NULL;
                obj->data = data;
                head = obj;
                return 0;
        }

        else {
                struct linked_list *tmp = NULL;
                tmp = head;
                while (tmp->next != NULL) {
                        tmp = tmp->next;
                }

                obj = new struct linked_list;
                if (obj == NULL) {
                        return -1;
                }

                obj->next = NULL;
                obj->data = data;
                tmp->next = obj;

                return 0;
        }

}

int singly_list::insert_at (int data, int position) {
	struct linked_list *obj = NULL;
	struct linked_list *tmp = NULL;
	if(position < 1) {
		cout<<"invalid position\n";
		return 1;
	}

        if (position == 1 || head == NULL) {

		if(head == NULL && position != 1) {
			cout<<"invalid position"<<endl;
			return 1;
		}

                obj = new struct linked_list;
                if (obj == NULL) {
                        return -1;
                }
                obj->next = NULL;
                obj->data = data;
		
		tmp = head;
                head = obj;
		head->next = tmp;
                return 0;
        }
	
	tmp = head;
	while (position > 2 && tmp != NULL) {
		tmp = tmp->next;
		position--;
	}

	if (tmp == NULL) {
		cout<<"INVALID POSTION"<<endl;
		return 1;
	}

	obj = new struct linked_list;
       	if (obj == NULL) {
        	return -1;
        }

	obj->next = NULL;
       	obj->data = data;

	obj->next = tmp->next;
	tmp->next = obj;

	return 0;
}

int singly_list::remove_head() {
	if (head == NULL) {
		cout<<"LIST IS EMPTY"<<endl;
		return 0;
	}

	struct linked_list *tmp = NULL;
	tmp = head;
	head = head->next;

	delete tmp;
	return 0;
}

int singly_list::remove_tail() {
	if (head == NULL) {
		cout<<"LIST IS EMPTY"<<endl;
		return 0;
	}
	
	if (head->next == NULL) {
		delete head;
		head = NULL;
		return 0;
	}

	struct linked_list *tmp = NULL;
	tmp = head;

	while(tmp->next->next != NULL) {
		tmp = tmp->next;
	}

	delete tmp->next;
	tmp->next = NULL;

	return 0;
}

int singly_list::remove_at(int position) {
	if (head == NULL || position < 1) {
		cout<<"list empty or position invalid"<<endl;
		return 0;
	}
	struct linked_list *tmp = NULL;

	if (position == 1) {
		tmp = head;
		head = head->next;
		delete tmp;
		return 0;
	}

	if(head->next == NULL) {
		cout<<"INVALID POSITION"<<endl;
		return 1;
	}

	tmp = head;
	while (position > 2 && tmp != NULL) {
		tmp = tmp->next;
		position--;
	}

	if (tmp == NULL || tmp->next == NULL) {
		cout<<"INVALID POSITION"<<endl;
		return 1;
	}	
	
	struct linked_list *hold = NULL; 
	hold = tmp->next;
	tmp->next = tmp->next->next;
	delete hold;

	return 0;
}

void singly_list::display() {
	struct linked_list * tmp = head;
	while(tmp != NULL) {
		cout<<tmp->data<<endl;
		tmp = tmp->next;
	}
}

int singly_list::delete_list() {
	struct linked_list * tmp = head;
        while(tmp != NULL) {
                tmp = tmp->next;
		delete head;
		head = tmp;
        }

	return 0;
}

int singly_list::reverse_list() {

	struct linked_list * first = head;
	struct linked_list * next = NULL;
	struct linked_list * prev = NULL;

	while (first != NULL) {
		next = first->next;
		first->next = prev;
		prev = first;
		head = first;
		first = next;
	}
	
	return 0;
}

void singly_list::reverse_list_recursive() {
	if (head == NULL || head->next == NULL) {
		return;
	}

	struct linked_list *tmp = head;
	head = head->next;
	reverse_list_recursive();
	tmp->next->next = tmp;
	tmp->next = NULL;
}

int singly_list::reverse_in_slot(int slot_size) {

	struct linked_list *t1 = NULL, *t2 = NULL, *cur = NULL, *pre = NULL, *next = NULL, *h1 = NULL;
	int count = slot_size;
	bool flag = 0;

	t1 = t2 = head;

	if (slot_size < 2) {
		cout<<"INVALID SLOT"<<endl;
		return 0;
	}	
	while (t1 != NULL) {
		while (count > 0 && t2 != NULL) {
			t2 = t2->next;
			count--;
		}
		
		cur = t1;
		pre = cur->next;

		while (pre != t2 && pre != NULL) {
			next = pre->next;
			pre->next = cur;
			cur = pre;
			pre = next;
		}
		
		t1->next = t2;
		if (flag == false) {
			head = cur;
			flag = true;
		}
		else {
			h1->next = cur;
		}

		h1 = t1;
		t1 = t2;
		count = slot_size;
	}

	return 0;
}

int singly_list::swap_nodes() {
	linked_list *t1 = NULL, *t2 = NULL, *t3 = NULL, *h1 = NULL;
	bool flag = false;

	t1 = head;
	if (t1 == NULL || t1->next == NULL) {
		cout<<"LIST IS NULL OR LIST CONTANS ONLY ONE NODE"<<endl;
		return 0;
	}

	while (t1 != NULL && t1->next != NULL) {
		t2 = t1->next;
		t3 = t2->next;
		
		t2->next = t1;
		t1->next = t3;
		
		if (flag == false) {
			head = t2;
			flag = true;
		}
		else {
			h1->next = t2;
		}
		h1 = t1;
		t1 = t3;
	}
	return 0;
}

void singly_list::removeLoop(void *node)
{ 
	struct linked_list *ptr1; 
	struct linked_list *ptr2; 
	struct linked_list *loop_node = (struct linked_list *)node;
  
	ptr1 = head; 
   	while (1) 
   	{ 
     		ptr2 = loop_node; 
     		while (ptr2->next != loop_node && ptr2->next != ptr1) 
         	ptr2 = ptr2->next; 
  
     		if (ptr2->next == ptr1) 
       			break; 
  
     		ptr1 = ptr1->next; 
   	}
  
   	ptr2->next = NULL; 
} 

bool singly_list::find_and_remove_loop() {
	linked_list *t1 = NULL, *t2 = NULL;
	bool flag = false;
	
	t1 = t2 = head;
	while (t2 != NULL && t2->next != NULL) {
		t1 = t1->next;
		t2 = t2->next->next;
		if (t1 == t2) {
			flag = true;
			removeLoop(t1);
			break;
		}
	}
	return flag;
}

void singly_list::make_loop(int node_num) {
        struct linked_list * tmp = head;
	struct linked_list * loop_head = head;
	if (head == NULL)
		return;

	while (node_num > 1 && loop_head != NULL) {
		loop_head = loop_head->next;
		node_num--;
	}
        while(tmp->next != NULL) {
                tmp = tmp->next;
        }

	tmp->next = loop_head;
}
