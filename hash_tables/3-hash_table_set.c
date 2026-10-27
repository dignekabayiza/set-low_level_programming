#include "hash_tables.h"
#include <string.h>

/**
 * add_node - creates a node and adds it at the start of a list
 * @head: pointer to the head of the list
 * @key: the key
 * @value: the value (already duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int add_node(hash_node_t **head, const char *key, char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
		return (0);

	node->key = strdup(key);
	if (node->key == NULL)
	{
		free(node);
		return (0);
	}

	node->value = value;
	node->next = *head;
	*head = node;

	return (1);
}

/**
 * hash_table_set - adds or updates an element in a hash table
 * @ht: the hash table
 * @key: the key (cannot be an empty string)
 * @value: the value associated with the key (duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	hash_node_t *node;
	char *new_value;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	new_value = strdup(value);
	if (new_value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);

	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			free(node->value);
			node->value = new_value;
			return (1);
		}
	}

	if (add_node(&ht->array[index], key, new_value) == 0)
	{
		free(new_value);
		return (0);
	}

	return (1);
}
