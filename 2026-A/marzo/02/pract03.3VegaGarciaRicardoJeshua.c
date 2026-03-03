/*
    Estudiante: Ricardo Jeshua Vega Garcia
    Matricula: 225976304
    Actividad: 3.3
    Fecha de entrega: 02 - Marzo - 2026
    Materia: Programación Estructurada
    Sección: D07
*/

/*
    # Información de la actividad

    Realiza una programa que permita llevar la gestión de las ventas de productos

    De los productos que se venden en la empresa se almacenan los siguientes datos: clave del producto,  Descripción, cantidad,  precio de lista, precio de venta.

    Las operaciones que se deben realizar son:

        1. Capturar producto
        2. Mostrar producto
        3. Consultar existencias
        4. Eliminar producto
        5. Modificar datos del producto.
        6. Consultar ventas por mes
        7. Consultar ventas por producto

    Deberá realizar también una estructura para almacenar los datos de las ventas.

    Realice el menú de opciones y deberá utilizar typedef, arreglos unidimensionales, estructuras de control, etc.
*/

/*
    Databases concep data

    Tabla: productos

    | clave | producto | descripcion | stock | precio lista | precio venta |
    |-------|----------|-------------|-------|--------------|--------------|
    | 123   | producto | descripcion | 10    | 100.00       | 150.00       |

    Tabla: ventas
    | clave producto | cantidad | precio total | mes |
    |----------------|----------|--------------|-----|
    | 123            | 2        | 300.00       | 1   |

    Relación:

    clave producto -> referencia a la clave del producto vendido
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// -------------------------- VALORES GLOBALES

#define MAX_CHAR 25
#define MAX_PRODUCTS 100
#define MAX_SALES 1000

int count_products = 0; // <- contador de productos
int count_sales = 0;    // <- contador de ventas

// -------------------------- ESTRUCTURAS

typedef struct
{
    char clave[11];             // <- id o clave del producto
    char product[MAX_CHAR];     // <- nombre del producto
    char description[MAX_CHAR]; // <- descripción
    int stock;                  // <- stock
    float list_price;           // <- precio de compra
    float sale_price;           // <- precio de venta
} tProduct;

typedef struct
{
    char product_clave[11]; // <- clave del producto vendido
    char product[MAX_CHAR]; // <- nombre del producto vendido
    int quantity;           // <- cantidad vendida
    float total_price;      // <- precio total de la venta
    int month;              // <- mes de la venta (1-12)
} tSale;

//  -------------------------- HERRAMIENTAS

void clear_screen()
{
    system("cls || clear");
}

void break_line(int n)
{
    for (int i = 0; i < n; i++)
        printf("\n");
}

void repeat(char character, int n, int z)
{
    for (int i = 0; i < n; i++)
        printf("%c", character);

    if (z)
        break_line(z);
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void stop(char *message)
{
    if (message)
        printf("%s", message);
    break_line(2);
    system("pause");
}

int exist_producs(tProduct products[])
{
    for (int i = 0; i < MAX_PRODUCTS; i++)
        if (strlen(products[i].clave) > 0)
            return 1;
    return 0;
}

int exist_producto_for_clave(tProduct products[], char *value)
{
    for (int i = 0; i < MAX_PRODUCTS; i++)
        if (strcmp(products[i].clave, value) == 0)
            return i + 1; // <- regresa el indice del producto -> solo si existe
    return 0;             // <- no existe el producto
}

// -------------------------- TABLA DE PRODUCTOS

void table_products_head()
{
    repeat('-', 120, 1);
    printf("| %-11s | %-25s | %-25s | %-10s | %-15s | %-15s |\n", "Clave", "Producto", "Descripcion", "Cantidad", "Precio Lista", "Precio Venta");
    repeat('-', 120, 1);
}

void table_products_row(tProduct products[], int idx)
{
    printf("| %-11s | %-25s | %-25s | %-10d | $%-14.2f | $%-14.2f |\n",
           products[idx].clave,
           products[idx].product,
           products[idx].description,
           products[idx].stock,
           products[idx].list_price,
           products[idx].sale_price);
}

void table_products(tProduct products[], char clave[11])
{
    clear_screen();

    // validar si existen productos registrados
    if (!exist_producs(products))
    {
        printf("No hay productos registrados");
        ;
        return;
    }

    if (clave != NULL)
    {
        const int idx = exist_producto_for_clave(products, clave);
        if (idx != 0)
        {
            table_products_head();
            table_products_row(products, idx - 1);
            repeat('-', 120, 1);
            break_line(3);
            stop(NULL);
            return;
        }
        else
        {
            stop("No se encontro el producto con la clave especificada");
            return;
        }
    }
    else
    {
        table_products_head();
        for (int i = 0; i < MAX_PRODUCTS; i++)
            if (strlen(products[i].clave) > 0)
                table_products_row(products, i);
    }

    repeat('-', 120, 1);
}

// -------------------------- TABLA DE VENTAS

void table_sales_head()
{
    repeat('-', 86, 1);
    printf("| %-15s | %-25s | %-10s | %-15s | %-5s |\n", "Clave Producto", "Producto", "Cantidad", "Precio Total", "Mes");
    repeat('-', 86, 1);
}

void table_sales_row(tSale sales[], int idx)
{
    printf("| %-15s | %-25s | %-10d | $%-14.2f | %-5d |\n",
           sales[idx].product_clave,
           sales[idx].product,
           sales[idx].quantity,
           sales[idx].total_price,
           sales[idx].month);
}

void table_sales(tProduct products[], tSale sales[], char product_clave[11], int month)
{
    clear_screen();

    if (count_sales == 0 || !exist_producs(products))
    {
        printf("No hay ventas registradas");
        return;
    }

    double total = 0;

    if (month != 0)
    {
        table_sales_head();
        for (int i = 0; i < count_sales; i++)
            if (strlen(sales[i].product_clave) > 0 && sales[i].month == month)
            {
                table_sales_row(sales, i);
                total += sales[i].total_price;
                repeat('-', 86, 1);
            }
    }
    else if (product_clave != NULL)
    {
        if (exist_producto_for_clave(products, product_clave) == 0)
        {
            stop("No se encontro el producto con la clave especificada");
            return;
        }
        table_sales_head();
        for (int i = 0; i < count_sales; i++)
            if (strcmp(sales[i].product_clave, product_clave) == 0)
            {
                table_sales_row(sales, i);
                repeat('-', 86, 1);
                total += sales[i].total_price;
            }
    }
    else
    {
        table_sales_head();
        for (int i = 0; i < count_sales; i++)
            if (strlen(sales[i].product_clave) > 0)
            {
                table_sales_row(sales, i);
                repeat('-', 86, 1);
                total += sales[i].total_price;
            }
    }

    break_line(2);
    printf("Total de ventas: $%.2f\n", total);
}

// -------------------------- MENU

int menu(char title[MAX_CHAR], char *options[], int max)
{
    int option;

    while (1)
    {
        clear_screen();
        repeat('-', 50, 2);

        printf("%s", title);
        break_line(2);

        for (int i = 0; i < max; i++)
            printf("%d. %s\n", i + 1, options[i]);
        printf("%d. Salir\n", max + 1);

        break_line(1);
        repeat('-', 50, 0);

        break_line(2);
        printf("Opcion: ");

        if (scanf("%d", &option) != 1)
        {
            clear_input_buffer();
            option = -1;
        }

        if (option < 1 || option > max + 1)
        {
            clear_input_buffer();
            clear_screen();
            stop("Opcion no valida, intente de nuevo");
            continue;
        }

        if (option == max + 1)
        {
            clear_screen();
            stop("Saliendo");
        }

        return option;
    }
}

// -------------------------- PRODUCTOS

void product_capture(tProduct products[], char *modify, int modify_option, int idx)
{
    if (count_products == MAX_PRODUCTS)
    {
        stop("No se pueden capturar mas productos");
        return;
    }

    clear_input_buffer();

    while (1)
    {
        clear_screen();

        if (modify != NULL && modify_option != 1)
            break;

        char temp[11];

        printf("Clave del producto: ");
        scanf(" %10[^\n]", temp);

        if (strlen(temp) == 0)
        {
            stop("La clave del producto no puede estar vacia");
            continue;
        }

        if (exist_producto_for_clave(products, temp) != 0)
        {
            stop("Ya existe un producto con esa clave, intente de nuevo");
            break_line(2);
            continue;
        }

        if (modify != NULL)
            strcpy(products[idx].clave, temp);
        else
            strcpy(products[count_products].clave, temp);

        break;
    }

    while (1)
    {
        clear_screen();

        if (modify != NULL && modify_option != 2)
            break;

        char temp[26];

        printf("Nombre del producto: ");
        scanf(" %25[^\n]", temp);

        if (strlen(temp) == 0)
        {
            stop("El nombre del producto no puede estar vacio");
            continue;
        }

        if (modify != NULL)
            strcpy(products[idx].product, temp);
        else
            strcpy(products[count_products].product, temp);

        break;
    }

    while (1)
    {
        clear_screen();

        if (modify != NULL && modify_option != 3)
            break;

        char temp[26];

        printf("Descripcion del producto: ");
        scanf(" %25[^\n]", temp);

        if (strlen(temp) == 0)
        {
            stop("La descripcion del producto no puede estar vacia");
            continue;
        }

        if (modify != NULL)
            strcpy(products[idx].description, temp);
        else
            strcpy(products[count_products].description, temp);

        break;
    }

    while (1)
    {
        clear_screen();

        if (modify != NULL && modify_option != 4)
            break;

        int temp;

        printf("Stock del producto: ");
        if (scanf("%d", &temp) != 1)
        {
            clear_input_buffer();
            stop("El stock del producto debe ser un numero entero");
            continue;
        }

        if (temp < 0)
        {
            stop("El stock del producto no puede ser negativo");
            continue;
        }

        if (modify != NULL)
            products[idx].stock = temp;
        else
            products[count_products].stock = temp;

        break;
    }

    while (1)
    {
        clear_screen();

        if (modify != NULL && modify_option != 5)
            break;

        float temp;

        printf("Precio de lista del producto: ");
        if (scanf("%f", &temp) != 1)
        {
            clear_input_buffer();
            stop("El precio de lista del producto debe ser un numero decimal");
            continue;
        }

        if (temp < 0)
        {
            stop("El precio de lista del producto no puede ser negativo");
            continue;
        }

        if (modify != NULL)
            products[idx].list_price = temp;
        else
            products[count_products].list_price = temp;

        break;
    }

    while (1)
    {
        clear_screen();

        if (modify != NULL && modify_option != 6)
            break;

        float temp;

        printf("Precio de venta del producto: ");
        if (scanf("%f", &temp) != 1)
        {
            clear_input_buffer();
            stop("El precio de venta del producto debe ser un numero decimal");
            continue;
        }

        if (temp < 0)
        {
            stop("El precio de venta del producto no puede ser negativo");
            continue;
        }

        if (modify != NULL)
            products[idx].sale_price = temp;
        else
            products[count_products].sale_price = temp;

        break;
    }

    table_products(products, NULL);

    if (idx == 0 && modify_option == 0)
        count_products++;

    stop(NULL);
}

void product_delete(tProduct products[], char clave[])
{
    clear_screen();

    if (!exist_producs(products))
    {
        stop("No hay productos registrados");
        return;
    }

    const int idx = exist_producto_for_clave(products, clave);

    if (idx != 0)
    {
        for (int i = idx - 1; i < count_products - 1; i++)
            products[i] = products[i + 1];
        products[count_products - 1] = (tProduct){0};
        count_products--;
        stop("Producto eliminado exitosamente");
    }
    else
        stop("No se encontro el producto con la clave especificada");
}

void product_modify(tProduct products[], char clave[], int modify_option)
{
    clear_screen();

    if (!exist_producs(products))
    {
        stop("No hay productos registrados");
        return;
    }

    const int idx = exist_producto_for_clave(products, clave);

    if (idx == 0)
    {
        stop("No se encontro el producto con la clave especificada");
        return;
    }
}

// -------------------------- VENTAS

void sales_capture(tProduct products[], tSale sales[])
{
    clear_screen();

    if (count_sales == MAX_SALES)
    {
        stop("No se pueden capturar mas ventas");
        return;
    }

    if (!exist_producs(products))
    {
        stop("No hay productos registrados");
        return;
    }

    clear_input_buffer();

    while (1)
    {
        clear_screen();

        table_products(products, NULL);

        break_line(2);

        char clave[11];
        printf("Ingresa la clave del producto a vender: ");
        scanf(" %10[^\n]", clave);

        const int idx = exist_producto_for_clave(products, clave);

        if (idx == 0)
        {
            clear_input_buffer();
            stop("No se encontro el producto con la clave especificada");
            break_line(2);
            continue;
        }

        strcpy(sales[count_sales].product_clave, clave);
        strcpy(sales[count_sales].product, products[idx - 1].product);
        break;
    }

    while (1)
    {
        clear_screen();

        int month;

        printf("Ingresa el mes de la venta (1-12): ");
        if (scanf("%d", &month) != 1)
        {
            clear_input_buffer();
            stop("El mes de la venta debe ser un numero entero");
            continue;
        }

        if (month < 1 || month > 12)
        {
            stop("El mes de la venta debe estar entre 1 y 12");
            continue;
        }

        sales[count_sales].month = month;
        break;
    }

    int flag = 1;

    while (flag)
    {
        clear_screen();

        int quantity;

        printf("Ingresa la cantidad a vender: ");
        if (scanf("%d", &quantity) != 1)
        {
            clear_input_buffer();
            stop("La cantidad a vender debe ser un numero entero");
            continue;
        }

        if (quantity < 1)
        {
            stop("La cantidad a vender debe ser mayor a 0");
            continue;
        }

        for (int i = 0; i < MAX_PRODUCTS; i++)
            if (strcmp(products[i].clave, sales[count_sales].product_clave) == 0)
            {
                if (quantity > products[i].stock)
                {
                    stop("No hay suficiente stock para realizar la venta");
                    break_line(2);
                    continue;
                }
                else
                {
                    products[i].stock -= quantity;
                    sales[count_sales].quantity = quantity;
                    sales[count_sales].total_price = quantity * products[i].sale_price;
                    flag = 0;
                }
            }
    }

    count_sales++;
    table_sales(products, sales, NULL, 0);
    stop(NULL);
}

// -------------------------- MAIN

int main()
{
    tProduct products[MAX_PRODUCTS] = {0}; // <- arreglo de productos
    tSale sales[MAX_SALES] = {0};          // <- arreglo de ventas
    char clave[11];                        // <- idx para referenciar productos

    char *options[] = {
        "Productos", // <- sub-menu para productos
        "Ventas",    // <- sub-menu para ventas
    };

    char *options_products[] = {
        "Capturar",             // <- captura un nuevo producto
        "Mostrar por producto", // <- clave producto
        "Mostrar todo",         // <- clave producto
        "Existencias",          // <- clave producto
        "Eliminar",             // <- clave producto
        "Modificar"             // <- clave producto
    };

    char *options_products_modify[] = {
        "Clave",        // <- clave producto
        "Producto",     // <- clave producto
        "Descripcion",  // <- clave producto
        "Stock",        // <- clave producto
        "Precio Lista", // <- clave producto
        "Precio Venta"  // <- clave producto
    };

    char *options_sales[] = {
        "Realizar venta",      // <- clave producto, cantidad, mes
        "Ventas totales",      // <- selecciona clave producto y mes
        "Ventas por mes",      // <- selecciona clave producto y mes
        "Ventas por producto", // <- clave producto
    };

    while (1)
    {

        switch (menu("MENU PRINCIPAL", options, 2))
        {
        case 1:
        {
            int flag = 1;
            while (flag)
            {
                switch (menu("PRODUCTOS", options_products, 6))
                {
                case 1:
                    product_capture(products, NULL, 0, 0);
                    break;

                case 2:
                {
                    clear_screen();

                    if (!exist_producs(products))
                    {
                        stop("No hay productos registrados");
                        break;
                    }

                    printf("Ingresa la clave del producto a mostrar: ");
                    scanf("%10s", clave);
                    table_products(products, clave);
                    break;
                }

                case 3:
                    table_products(products, NULL);
                    stop(NULL);
                    break;

                case 4:
                {
                    clear_screen();

                    if (!exist_producs(products))
                    {
                        stop("No hay productos registrados");
                        break;
                    }

                    printf("Ingresa la clave del producto a consultar existencias: ");
                    scanf("%10s", clave);

                    const int idx = exist_producto_for_clave(products, clave);

                    if (idx != 0)
                    {
                        printf("El producto %s tiene %d existencias\n", products[idx - 1].product, products[idx - 1].stock);
                        stop(NULL);
                    }
                    else
                        stop("No se encontro el producto con la clave especificada");

                    break;
                }

                case 5:
                    clear_screen();

                    if (!exist_producs(products))
                    {
                        stop("No hay productos registrados");
                        break;
                    }

                    printf("Ingresa la clave del producto a eliminar: ");
                    scanf("%10s", clave);

                    if (exist_producto_for_clave(products, clave) == 0)
                    {
                        stop("No se encontro el producto con la clave especificada");
                        break;
                    }

                    product_delete(products, clave);
                    break;

                case 6:
                {
                    clear_screen();

                    if (!exist_producs(products))
                    {
                        stop("No hay productos registrados");
                        break;
                    }

                    table_products(products, NULL);

                    printf("Ingresa la clave del producto a modificar: ");
                    scanf("%10s", clave);

                    const int idx = exist_producto_for_clave(products, clave);

                    if (idx == 0)
                    {
                        stop("No se encontro el producto con la clave especificada");
                        break;
                    }

                    while (1)
                    {
                        const int select = menu("MODIFICAR PRODUCTO", options_products_modify, 6);

                        if (select == 7)
                            break;

                        product_capture(products, "modify", select, idx - 1);
                    }

                    break;
                }

                default:
                    flag = 0;
                }
            }
            break;
        }

        case 2:
        {
            int flag = 1;
            while (flag)
            {
                switch (menu("VENTAS", options_sales, 4))
                {
                case 1:
                    sales_capture(products, sales);
                    break;

                case 2:
                {
                    clear_screen();

                    if (!exist_producs(products) || count_sales == 0)
                    {
                        stop("No hay productos registrados o no hay ventas");
                        break;
                    }

                    table_sales(products, sales, NULL, 0);
                    stop(NULL);
                    break;
                }

                case 3:
                {
                    clear_screen();

                    if (!exist_producs(products) || count_sales == 0)
                    {
                        stop("No hay productos registrados o no hay ventas");
                        break;
                    }

                    int month;

                    printf("Ingresa el mes a consultar ventas (1-12): ");
                    if (scanf("%d", &month) != 1)
                    {
                        clear_input_buffer();
                        stop("El mes a consultar debe ser un numero entero");
                        break;
                    }

                    if (month < 1 || month > 12)
                    {
                        stop("El mes a consultar debe estar entre 1 y 12");
                        break;
                    }

                    table_sales(products, sales, NULL, month);
                    stop(NULL);

                    break;
                }

                case 4:
                {
                    clear_screen();

                    if (!exist_producs(products) || count_sales == 0)
                    {
                        stop("No hay productos registrados o no hay ventas");
                        break;
                    }

                    char clave[11];
                    printf("Ingresa la clave del producto a consultar ventas: ");
                    scanf("%10s", clave);

                    table_sales(products, sales, clave, 0);
                    stop(NULL);

                    break;
                }
                default:
                    flag = 0;
                }
            }
            break;
        }

        default:
            return 0;
        }
    }

    return 0;
}