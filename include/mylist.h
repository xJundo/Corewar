/*
** EPITECH PROJECT, 2023
** my list
** File description:
** struct of linked list
*/

#ifndef MYLIST_H
    #define MYLIST_H
    #include <stdlib.h>

typedef enum type {
    INT,
    CHAR,
    STR,
    UNKNOW,
    SFSPRITE,
    SFTEXT,
    LABEL,
    INSTRUCTION,
} type_t;

typedef struct nodes {
    struct nodes *previous;
    void *data;
    type_t type;
    struct nodes *next;
} nodes_t;

int list_size(nodes_t **head);
int just_remove_in_list(nodes_t **head, void *data,
    int (*cmp)(void *, void *));
int del_matching_node(nodes_t **head, void *data, int (*cmp)(void *, void *));
void push_f(nodes_t **head, void *data, type_t type);
int print_list(nodes_t **head);
int print_typed_value(void *data, type_t type);
int delete_list(nodes_t **head, char const *);

//Doubly
int remove_doubly(nodes_t **head, void *id, int cmp(void *, void *));
void print_list_doubly(nodes_t **head);
void push_f_doubly(nodes_t **head, void *data, type_t type);
void push_b_doubly(nodes_t **head, void *data, type_t type);
int remove_doubly_free(nodes_t **head, void *id, int cmp(void *, void *));
nodes_t *previous_to_next(nodes_t **head, nodes_t *to_delete);
nodes_t *pop_b_doubly(nodes_t **list);
nodes_t *pop_f_doubly(nodes_t **list);

int my_strput(char const *str);
int my_lenstr(char const *str);
void my_charput(char c);
int my_nbr_put(int nb);
int my_cmpstr(char const *str1, char const *str2);
char *my_dupstr(char const *src);
char *print_adress(unsigned int nbr, char const *base);


int my_intcmp_void(void *data, void *ref);
int my_strcmp_void(void *data, void *ref);
int my_pointercmp(void *s1, void *s2);

#endif
