#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PRODUCTS 100

typedef struct {
    int id;
    char name[50];
    int quantity;
    float price;
} Product;

void addProduct(Product products[], int *productCount);
void displayProducts(Product products[], int productCount);
void searchProduct(Product products[], int productCount);

int main() {
    Product products[MAX_PRODUCTS];
    int productCount = 0;
    int choice;

    do {
        printf("\n1. Add Product\n2. Display Products\n3. Search Product\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addProduct(products, &productCount);
                break;
            case 2:
                displayProducts(products, productCount);
                break;
            case 3:
                searchProduct(products, productCount);
                break;
            case 4:
                printf("Exiting program. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}

void addProduct(Product products[], int *productCount) {
    if (*productCount < MAX_PRODUCTS) {
        printf("Enter product details:\n");
        products[*productCount].id = *productCount + 1;

        printf("Name: ");
        scanf("%s", products[*productCount].name);

        printf("Quantity: ");
        scanf("%d", &products[*productCount].quantity);

        printf("Price: ");
        scanf("%f", &products[*productCount].price);

        (*productCount)++;
        printf("Product added successfully!\n");
    } else {
        printf("Maximum number of products reached!\n");
    }
}

void displayProducts(Product products[], int productCount) {
    if (productCount > 0) {
        printf("Product List:\n");
        printf("ID\tName\tQuantity\tPrice\n");

        for (int i = 0; i < productCount; i++) {
            printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
        }
    } else {
        printf("No products available.\n");
    }
}

void searchProduct(Product products[], int productCount) {
    if (productCount > 0) {
        int searchId;
        printf("Enter product ID to search: ");
        scanf("%d", &searchId);

        int found = 0;
        for (int i = 0; i < productCount; i++) {
            if (products[i].id == searchId) {
                printf("Product found:\n");
                printf("ID\tName\tQuantity\tPrice\n");
                printf("%d\t%s\t%d\t\t%.2f\n", products[i].id, products[i].name, products[i].quantity, products[i].price);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("Product with ID %d not found.\n", searchId);
        }
    } else {
        printf("No products available.\n");
    }
}
