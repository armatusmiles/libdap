/*
 * Doubly-Linked Lists — linked lists that can be iterated over in both directions
 */

#ifndef __DAP_LIST_H__
#define __DAP_LIST_H__

typedef void (*DapDestroyNotify)(void* data);
typedef void (*DapFunc)(void* data, void* user_data);
typedef void* (*DapCopyFunc)(const void * src, void* data);
typedef int (*DapCompareFunc)(const void * a, const void * b);
typedef int (*DapCompareDataFunc)(const void * a, const void * b, void* user_data);

typedef struct _dap_list dap_list_t;

struct _dap_list
{
    void* data;
    dap_list_t *next;
    dap_list_t *prev;
};

/* Doubly linked lists
 */
dap_list_t* dap_list_alloc(void);
void dap_list_free(dap_list_t *list);
void dap_list_free1(dap_list_t *list);
void dap_list_free_full(dap_list_t *list, DapDestroyNotify free_func);
dap_list_t* dap_list_append(dap_list_t *list, void* data);
dap_list_t* dap_list_prepend(dap_list_t *list, void* data);
dap_list_t* dap_list_insert(dap_list_t *list, void* data, int position);
dap_list_t* dap_list_insert_sorted(dap_list_t *list, void* data, DapCompareFunc func);
dap_list_t* dap_list_insert_sorted_with_data(dap_list_t *list, void* data, DapCompareDataFunc func, void* user_data);
dap_list_t* dap_list_insert_before(dap_list_t *list, dap_list_t *sibling, void* data);
dap_list_t* dap_list_concat(dap_list_t *list1, dap_list_t *list2);
dap_list_t* dap_list_remove(dap_list_t *list, const void * data);
dap_list_t* dap_list_remove_all(dap_list_t *list, const void * data);
dap_list_t* dap_list_remove_link(dap_list_t *list, dap_list_t *llink);
dap_list_t* dap_list_delete_link(dap_list_t *list, dap_list_t *link_);
dap_list_t* dap_list_reverse(dap_list_t *list);
dap_list_t* dap_list_copy(dap_list_t *list);

dap_list_t* dap_list_copy_deep(dap_list_t *list, DapCopyFunc func, void* user_data);

dap_list_t* dap_list_nth(dap_list_t *list, unsigned int n);
dap_list_t* dap_list_nth_prev(dap_list_t *list, unsigned int n);
dap_list_t* dap_list_find(dap_list_t *list, const void * data);
dap_list_t* dap_list_find_custom(dap_list_t *list, const void * data, DapCompareFunc func);
int dap_list_position(dap_list_t *list, dap_list_t *llink);
int dap_list_index(dap_list_t *list, const void * data);
dap_list_t* dap_list_last(dap_list_t *list);
dap_list_t* dap_list_first(dap_list_t *list);
unsigned int dap_list_length(dap_list_t *list);
void dap_list_foreach(dap_list_t *list, DapFunc func, void* user_data);
dap_list_t* dap_list_sort(dap_list_t *list, DapCompareFunc compare_func);
dap_list_t* dap_list_sort_with_data(dap_list_t *list, DapCompareDataFunc compare_func, void* user_data);
void* dap_list_nth_data(dap_list_t *list, unsigned int n);

#define dap_list_previous(list)	        ((list) ? (((dap_list_t *)(list))->prev) : NULL)
#define dap_list_next(list)	        ((list) ? (((dap_list_t *)(list))->next) : NULL)

#endif /* __DAP_LIST_H__ */