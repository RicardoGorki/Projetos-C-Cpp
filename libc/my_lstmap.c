#include "libc.h"

t_list	*my_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*newlist;

	newlist = NULL;
	while (lst)
	{
		temp = my_lstnew(f(lst->content));
		if (!temp)
		{
			my_lstclear(&newlist, del);
			return (NULL);
		}
		my_lstadd_back(&newlist, temp);
		lst = lst->next;
	}
	return (newlist);
}
