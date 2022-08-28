# Dynamic / Generic clist

### Getting Started

#### Creating list

    c_list *list = list_create(sizeof(int));
    
#### Adding item to list

    list_add(list,5);
    
#### Removing item from list

    list_remove_at(list, 5);
    
#### Get list item

    c_list *list = create_list(sizeof(int));
    
    for(int i = 0; i < 10; i++);
      list_add(list, i);
      
    for(int i = 0; i < 10; i++);
      printf("%d\n", *(int*)list_item_at(list, i));
    
#### List find

    list_find(list, 2);
    
#### Working with different types

    c_list *list = list_create(sizeof(char));
    list_add(list, 'A');
    
    
    typedef struct s_list
    {
     int x;
     int y;
    } t_list;
    
    c_list *list = list_create(sizeof(t_list));
    
    t_list data;
    data.x = 20;
    list_addptr(list,&data);
    
    printf("%d\n", ((t_data*)list->item_at(list,0)).x);
    
    
    

    
    


    
