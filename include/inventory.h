#ifndef INVENTORY_H
#define INVENTORY_H

#define NAME_LEN 50
#define MAX_ITEMS 1000
#define DATA_FILE "data.bin"

typedef struct {
    int id;
    char name[NAME_LEN];
    int quantity;
    float price;
} Item;

int load_items(Item items[], int *count);
int save_items(Item items[], int count);
void add_item(Item items[], int *count);
void update_item(Item items[], int count);
void delete_item(Item items[], int *count);
void search_item(Item items[], int count);
void list_items(Item items[], int count);

#endif
