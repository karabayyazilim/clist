#include "clist.h"


#define CLIST_SIZE 2
#define CLIST_RESIZE 5


c_list* list_create(unsigned int type_size)
{
	c_list* list;

	list = malloc(sizeof(c_list));
	if (list == NULL)
		return NULL;
	list->arr = malloc(CLIST_SIZE * type_size);
	if (list->arr == NULL)
	{
		free(list);
		return NULL;
	}
	list->length = 0;
	list->size = CLIST_SIZE;
	list->type_size = type_size;
	return list;
}

void list_add(c_list* list, int item)
{
	void* tmp;
	size_t i;

	if (list == NULL)
		return;
	if (list->length >= list->size)
	{
		tmp = malloc((list->size + CLIST_RESIZE) * list->type_size);
		if (tmp == NULL)
			return;
		i = 0;
		while (i < (list->length * list->type_size))
		{
			ft_cmemcpy((char *)tmp + i, (char *)list->arr + i, list->type_size);
			i += list->type_size;
		}
		ft_cmemcpy((char*)tmp + (list->length * list->type_size), &item, list->type_size);
		free(list->arr);
		list->arr = tmp;
		list->size += CLIST_RESIZE;
	}
	else
	{
		ft_cmemcpy((char *)list->arr + (list->length * list->type_size), &item, list->type_size);
	}
	list->length++;
}

void list_addf(c_list* list, float item)
{
	void* tmp;
	size_t i;

	if (list == NULL)
		return;
	if (list->length >= list->size)
	{
		tmp = malloc((list->size + CLIST_RESIZE) * list->type_size);
		if (tmp == NULL)
			return;
		i = 0;
		while (i < (list->length * list->type_size))
		{
			ft_cmemcpy((char*)tmp + i, (char*)list->arr + i, list->type_size);
			i += list->type_size;
		}
		ft_cmemcpy((char*)tmp + (list->length * list->type_size), &item, list->type_size);
		free(list->arr);
		list->arr = tmp;
		list->size += CLIST_RESIZE;
	}
	else
	{
		ft_cmemcpy((char*)list->arr + (list->length * list->type_size), &item, list->type_size);
	}
	list->length++;
}

void list_addptr(c_list* list, void *item)
{
	void* tmp;
	size_t i;

	if (list == NULL)
		return;
	if (list->length >= list->size)
	{
		tmp = malloc((list->size + CLIST_RESIZE) * list->type_size);
		if (tmp == NULL)
			return;
		i = 0;
		while (i < (list->length * list->type_size))
		{
			ft_cmemcpy((char*)tmp + i, (char*)list->arr + i, list->type_size);
			i += list->type_size;
		}
		ft_cmemcpy((char*)tmp + (list->length * list->type_size), item, list->type_size);
		free(list->arr);
		list->arr = tmp;
		list->size += CLIST_RESIZE;
	}
	else
		ft_cmemcpy((char*)list->arr + (list->length * list->type_size), item, list->type_size);
	list->length++;
}



int list_find(c_list* list, int item)
{
	int i;

	if (list == NULL)
		return -1;
	i = 0;
	while (i < (list->length * list->type_size))
	{
		if (ft_cmemcmp((char*)list->arr + i, &item, list->type_size) == 1)
			return i / list->type_size;
		i += list->type_size;
	}
	return -1;
}

int list_findf(c_list* list, float item)
{
	int i;

	if (list == NULL)
		return -1;
	i = 0;
	while (i < (list->length * list->type_size))
	{
		if (ft_cmemcmp((char*)list->arr + i, &item, list->type_size) == 1)
			return i / list->type_size;
		i += list->type_size;
	}
	return -1;
}

void* list_item_at(c_list* list, size_t index)
{
	if (list == NULL || index > list->length)
		return NULL;
	return (char*)list->arr + (index * list->type_size);
}

void list_remove_at(c_list* list, size_t index)
{
	void* tmp;
	size_t i;

	if (list == NULL || index > list->length)
		return;
	tmp = malloc(list->size * list->type_size);
	if (tmp == NULL)
		return;
	i = 0;
	while (i < (index * list->type_size))
	{
		ft_cmemcpy((char*)tmp + i, (char*)list->arr + i, list->type_size);
		i += list->type_size;
	}

	index++;
	while (index < list->length)
	{
		ft_cmemcpy((char*)tmp + i, (char*)list->arr + (index * list->type_size), list->type_size);
		i += list->type_size;
		index++;
	}
	list->length--;
	free(list->arr);
	list->arr = tmp;
}

void list_print(c_list* list)
{
	size_t i;

	if (list == NULL)
		return;
	if (list->type_size != sizeof(char))
		return;
	i = 0;
	while (i < list->length)
	{
		printf("%c", *((char*)list->arr + i));
		i++;
	}

}

