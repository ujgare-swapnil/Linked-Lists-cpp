#include "list.h"
#include <string.h>
#include <singly_list.h>
#include <iostream>
using namespace std;
list::list () {
	cout<<"in CONSTRUCTOR list\n";
}

list::~list() {
	cout<<"DISTRUr\n";
}

list * list::get_list (const char* type) {
	list *ptr = NULL;
        if ((strcmp(type,"singly_list")) == 0) {
		cout<<"enter"<<endl;
                ptr = new singly_list;
        }

        return ptr;
}

void list::destroy_list (list *ptr) {
	delete ptr;
}
