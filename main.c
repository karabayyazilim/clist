#include "clist.h"

typedef struct s_data
{
	int x;
	int y;
} t_data;


int main()
{

	c_list* list = list_create(sizeof(char));
    
	char str[] = "adsadasd";

	for (int i = 0; i < 9; i++)
		list_add(list, str[i]);

	list_print(list);





}