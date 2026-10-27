#include "hash_tables.h"
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the new table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = calloc(size, sizeof(shash_node_t *));
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}

	return (ht);
}

/**
 * make_node - creates a node with copies of key and value
 * @key: the key
 * @value: the value
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_node(const char *key, const char *value)
{
	shash_node_t *node;

	node = malloc(sizeof(shash_node_t));
	if (node == NULL)
		return (NULL);

	node->key = strdup(key);
	node->value = strdup(value);
	if (node->key == NULL || node->value == NULL)
	{
		free(node->key);
		free(node->value);
		free(node);
		return (NULL);
	}
	node->next = NULL;
	node->sprev = NULL;
	node->snext = NULL;

	return (node);
}

/**
 * sorted_insert - inserts a node in the sorted list (by ASCII key)
 * @ht: the sorted hash table
 * @node: the node to insert
 */
void sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *cur;

	if (ht->shead == NULL)
	{
		ht->shead = node;
		ht->stail = node;
		return;
	}
	cur = ht->shead;
	while (cur != NULL && strcmp(cur->key, node->key) < 0)
		cur = cur->snext;
	if (cur == NULL)
	{
		node->sprev = ht->stail;
		ht->stail->snext = node;
		ht->stail = node;
		return;
	}
	node->snext = cur;
	node->sprev = cur->sprev;
	if (cur->sprev != NULL)
		cur->sprev->snext = node;
	else
		ht->shead = node;
	cur->sprev = node;
}

/**
 * shash_table_set - adds or updates an element in a sorted hash table
 * @ht: the sorted hash table
 * @key: the key (cannot be an empty string)
 * @value: the value (duplicated)
 *
 * Return: 1 if it succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *node;
	char *new_value;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
		return (0);

	index = key_index((const unsigned char *)key, ht->size);
	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
		{
			new_value = strdup(value);
			if (new_value == NULL)
				return (0);
			free(node->value);
			node->value = new_value;
			return (1);
		}
	}

	node = make_node(key, value);
	if (node == NULL)
		return (0);
	node->next = ht->array[index];
	ht->array[index] = node;
	sorted_insert(ht, node);

	return (1);
}

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the sorted hash table
 * @key: the key to look for
 *
 * Return: the value, or NULL if the key is not found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index;

	if (ht == NULL || key == NULL || *key == '\0')
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	for (node = ht->array[index]; node != NULL; node = node->next)
	{
		if (strcmp(node->key, key) == 0)
			return (node->value);
	}

	return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table in order
 * @ht: the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->shead; node != NULL; node = node->snext)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->snext != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order
 * @ht: the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;

	if (ht == NULL)
		return;

	printf("{");
	for (node = ht->stail; node != NULL; node = node->sprev)
	{
		printf("'%s': '%s'", node->key, node->value);
		if (node->sprev != NULL)
			printf(", ");
	}
	printf("}\n");
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;

	if (ht == NULL)
		return;

	node = ht->shead;
	while (node != NULL)
	{
		tmp = node->snext;
		free(node->key);
		free(node->value);
		free(node);
		node = tmp;
	}

	free(ht->array);
	free(ht);
}
