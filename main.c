#include "clist.h"


int main()
{

	c_list* list = list_create(sizeof(int));

	for (int i = 0; i < 10; i++)
		list_add(list, i + 1000000);

	for (int i = 0; i < 10; i++)
		printf("%d\n", *(int*)list_item_at(list, i));

}