#include <stdio.h>

struct Item
{
    char name[50];
    int quantity;
    float price;
};


int main()
{
    int n;
    scanf("%d", &n);
    struct Item items[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %f", items[i].name, &items[i].quantity, &items[i].price);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Item: %s\nQuantity: %d\nPrice: %.2f\n\n", items[i].name, items[i].quantity, items[i].price);
    } 
    
}