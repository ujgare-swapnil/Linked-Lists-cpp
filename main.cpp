#include "list.h"
#include <iostream>
using namespace std;

int main() {

int a =11;
int xyz =21;


	list * ptr = NULL;
	ptr = list::get_list("singly_list");
	ptr->add_head(1);
	ptr->add_head(2);

	ptr->add_head(3);
	ptr->add_tail(4);
	ptr->add_tail(17);
	ptr->add_tail(10);
	cout<<"-------"<<endl;
	ptr->display();
	ptr->make_loop(3);
	ptr->find_and_remove_loop();
	cout<<"8888888"<<endl;
	ptr->display();
	
//	ptr->insert_at(11,1);
//	ptr->insert_at(15,7);

//	ptr->insert_at(20,9);



	list::destroy_list(ptr);	
	return 0;
}
