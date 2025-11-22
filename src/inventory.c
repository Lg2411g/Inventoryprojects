#include <stdio.h>
#include <string.h>
#include "inventory.h"

// Load items from file
int load_items(Item items[], int *count) {
    FILE *fp = fopen(DATA_FILE, "rb");
    if (!fp) {
        *count = 0;   // No file exists yet → empty inventory
        return 0;
    }

    fread(count, sizeof(int), 1, fp);
    fread(items, sizeof(Item), *count, fp);
    fclose(fp);

    return 1;
}

// Save items to file
int save_items(Item items[], int count) {
    FILE *fp = fopen(DATA_FILE, "wb");
    if (!fp) {
        printf("Error saving data!\n");
        return 0;
    }

    fwrite(&count, sizeof(int), 1, fp);
    fwrite(items, sizeof(Item), count, fp);
    fclose(fp);

    return 1;
}

// Add new item
void add_item(Item items[], int *count) {
    Item new_item;

    printf("Enter Item ID: ");
    scanf("%d", &new_item.id);

    printf("Enter Item Name: ");
    scanf(" %[^\n]s", new_item.name);

    printf("Enter Quantity: ");
    scanf("%d", &new_item.quantity);

    printf("Enter Price: ");
    scanf("%f", &new_item.price);

    items[*count] = new_item;
    (*count)++;

    save_items(items, *count);

    printf("Item added successfully!\n");
}

// Update item by ID
void update_item(Item items[], int count) {
    int id, found = 0;

    printf("Enter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("Enter new Quantity: ");
            scanf("%d", &items[i].quantity);

            printf("Enter new Price: ");
            scanf("%f", &items[i].price);

            save_items(items, count);
            printf("Item updated successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Item not found.\n");
}

// Delete item
void delete_item(Item items[], int *count) {
    int id, found = 0;

    printf("Enter Item ID to delete: ");
    scanf("%d", &id);

    for (int i = 0; i < *count; i++) {
        if (items[i].id == id) {

            for (int j = i; j < *count - 1; j++)
                items[j] = items[j + 1];

            (*count)--;

            save_items(items, *count);
            printf("Item deleted successfully!\n");

            found = 1;
            break;
        }
    }

    if (!found)
        printf("Item not found.\n");
}

// Search for item
void search_item(Item items[], int count) {
    int id;

    printf("Enter Item ID to search: ");
    scanf("%d", &id);

    for (int i = 0; i < count; i++) {
        if (items[i].id == id) {
            printf("\nItem Found:\n");
            printf("ID: %d\n", items[i].id);
            printf("Name: %s\n", items[i].name);
            printf("Quantity: %d\n", items[i].quantity);
            printf("Price: %.2f\n\n", items[i].price);
            return;
        }
    }

    printf("Item not found.\n");
}

// List all items
void list_items(Item items[], int count) {
    if (count == 0) {
        printf("No items in inventory.\n");
        return;
    }

    printf("\n--- Inventory List ---\n");

    for (int i = 0; i < count; i++) {
        printf("%d) ID: %d | Name: %s | Qty: %d | Price: %.2f\n",
               i + 1,
               items[i].id,
               items[i].name,
               items[i].quantity,
               items[i].price);
    }
}
