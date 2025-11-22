#include <stdio.h>
#include "inventory.h"

int main() {
    Item items[MAX_ITEMS];
    int count = 0;
    int choice;

    // Load existing items from file
    load_items(items, &count);

    while (1) {
        printf("\n--- Inventory Management System ---\n");
        printf("1. Add Item\n");
        printf("2. Update Item\n");
        printf("3. Delete Item\n");
        printf("4. Search Item\n");
        printf("5. List Items\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_item(items, &count);
                break;

            case 2:
                update_item(items, count);
                break;

            case 3:
                delete_item(items, &count);
                break;

            case 4:
                search_item(items, count);
                break;

            case 5:
                list_items(items, count);
                break;

            case 6:
                save_items(items, count);
                printf("Exiting... Data saved.\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
