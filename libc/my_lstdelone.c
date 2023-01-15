#include "libc.h"

void	my_lstdelone(t_list *lst, void (*del)(void *))
{
	del(lst->content);
	free(lst);
}
