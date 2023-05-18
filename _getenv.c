#include "main.h"

/**
 * _getenv - retrieves the value of an environment variable given its name.
 * @name: the name of the environment variable to retrieve.
 *
 * Return: a pointer to the value of the environment variable,
 * otherwise NULL if the environment variable is not found.
 */
char *_getenv(char *name)
{
	/* Calculate the length of the name */
	size_t name_len = _strlen(name);
	/* Get a pointer to the environment variables array */
	char **env = environ;

	/* Loop through each environment variable until the end is reached */
	while (*env != NULL)
	{
		/*Check ifcurrent environment variable matches requested name*/
		if (_strncmp(name, *env, name_len) == 0 && (*env)[name_len] == '=')
			return (&(*env)[name_len + 1]);
		env++;
	}
	return (NULL);
}

/**
 * _add_node_end - adds a new node at the end of a list_t list.
 * @head: the list to add the string to.
 * @str: the string to add to the list.
 *
 * Return: a pointer to the head of the linked list, or NULL if it fails.
 */
list_t *_add_node_end(list_t **head, char *str)
{
	list_t *ptr, *tmp;

	/* Set ptr to point to the head of the linked list */
	ptr = *head;
	/* Allocate memory for the new node */
	tmp = malloc(sizeof(list_t));
	if (tmp == NULL)
		return (NULL);
	/* Set the string of the new node to a duplicate of the input string */
	tmp->str = _strdup(str);
	/* Set the next pointer of the new node to NULL */
	tmp->next = NULL;
	/* If the linked list is empty, set the head to point to the new node*/
	if (ptr == NULL)
		*head = tmp;
	else
	{
		/* Traverse the linked list to find the last node */
		while (ptr->next != NULL)
			ptr = ptr->next;
		/* Set the next pointer of the last node to point to the new node */
		ptr->next = tmp;
	}

	return (*head);
}

/**
 * _list_len - counts the number of elements in a linked list_t list.
 * @h: the list to be counted.
 *
 * Return: the number of nodes in the linked list.
 */
size_t _list_len(const list_t *h)
{
	const list_t *ptr = h;
	size_t count = 0;

	/* Traverse the linked list and count the number of nodes */
	while (ptr != NULL)
	{
		count++;
		ptr = ptr->next;
	}

	return (count);
}

/**
 * _get_node_at_index - gets the nth node of a listint_t linked list.
 * @head: the linked list to be searched in.
 * @index: the index of the node, starting at 0.
 *
 * Return: a pointer to the node at the specified index,
 * otherwise NULL if the node does not exist or failed.
 */
list_t *_get_node_at_index(list_t *head, unsigned int index)
{
	list_t *ptr, *tmp;
	unsigned int i;
	size_t length;

	/* Set ptr to point to the head of the linked list */
	ptr = head;
	/* If the linked list is empty, return NULL */
	if (ptr == NULL)
		return (NULL);
	/* Calculate the length of the linked list */
	length = _list_len(head);
	/*Return NULL if specified index is greater than length of the list*/
	if (index > length)
		return (NULL);
	/* Traverse the linked list to find the node at the specified index */
	for (i = 0; ptr != NULL && i < index; i++)
		ptr = ptr->next;
	/*If the desired node is found at the specified index, add a node*/
	if (i == index && ptr != NULL)
	{
		/* Allocate memory for the new node */
		tmp = malloc(sizeof(list_t));
		if (tmp == NULL)
			return (NULL);
		/* Allocate memory for the string in the new node */
		tmp->str = malloc(sizeof(char) * _strlen(ptr->str));
		if (tmp->str == NULL)
			return (NULL);
		/* Copy its value */
		tmp->str = _strcpy(tmp->str, ptr->str);
		/*Set the next pointer of new node to match the original node*/
		tmp->next = ptr->next;
	}
	else
		/*Return NULL if desired node is not found at specified index*/
		return (NULL);

	return (tmp);
}
