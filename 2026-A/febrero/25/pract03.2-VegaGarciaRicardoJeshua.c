/*
    Estudiante: Ricardo Jeshua Vega Garcia
    Matricula: 225976304
    Actividad: 3.2
    Fecha de entrega: 25 - Febrero - 2026
    Materia: Programación Estructurada
    Sección: D07
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ------------------- GLOBAL -------------------

#define MAX_EMPLOYEDS 100

struct __employeds
{
    char full_name[250];
    char phone_number[250];
    char address[250];
    char email[250];
    char position[250];
    float base_salary;
    char schedule[250];
    float commission;
};

int count = 0;

// ------------------- HERRAMIENTAS -------------------

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void line_breack(int n)
{
    for (int i = 0; i < n; i++)
        printf("\n");
}

void repeat(char c, int n, int l)
{
    for (int i = 0; i < n; i++)
        printf("%c", c);

    if (l <= 0)
        l = 1;

    line_breack(l);
}

int exist_employeds()
{
    if (count == 0)
    {
        printf("No hay empleados capturados\n");
        system("pause");
        return 0;
    }
    return 1;
}

void table_data_employed(struct __employeds employedm, int index)
{
    printf("Empleado #%d\n\n", index + 1);
    printf("    Nombre completo: %s\n", employedm.full_name);
    printf("    Numero de telefono: %s\n", employedm.phone_number);
    printf("    Direccion: %s\n", employedm.address);
    printf("    Correo electronico: %s\n", employedm.email);
    printf("    Puesto: %s\n", employedm.position);
    printf("    Sueldo base: $%.2f\n", employedm.base_salary);
    printf("    Horario: %s\n", employedm.schedule);
    printf("    Comision: $%.2f\n", employedm.commission);
    line_breack(1);
    repeat('-', 50, 2);
}

// ------------------- MENU -------------------

int render_menu(char *options[], int min, int max)
{
    while (1)
    {
        system("cls");

        int option;

        repeat('-', 50, 2);

        int count_options = 0;

        for (int i = 0; options[i] != NULL; i++)
        {
            printf("%d. %s\n", i + 1, options[i]);
            count_options++;
        }

        printf("%d. Salir\n", count_options + 1);

        line_breack(1);
        repeat('-', 50, 2);

        printf("$ ");

        if (scanf("%d", &option) != 1)
        {
            clear_input_buffer();
            printf("Opcion no valida\n");
            system("pause");
            continue;
        }

        clear_input_buffer();

        if (option < min || option > max)
        {
            printf("Opcion no valida\n");
            system("pause");
            continue;
        }

        return option;
    }
}

// ------------------- CAPTURAR EMPLEADOS -------------------

void employed_capturate(struct __employeds employeds[])
{
    if (count >= MAX_EMPLOYEDS)
    {
        printf("No se pueden capturar mas empleados\n");
        system("pause");
        return;
    }

    system("cls");

    printf("Nombre completo: ");
    fgets(employeds[count].full_name, 250, stdin);
    employeds[count].full_name[strcspn(employeds[count].full_name, "\n")] = '\0';

    printf("Numero de telefono: ");
    fgets(employeds[count].phone_number, 250, stdin);
    employeds[count].phone_number[strcspn(employeds[count].phone_number, "\n")] = '\0';

    printf("Direccion: ");
    fgets(employeds[count].address, 250, stdin);
    employeds[count].address[strcspn(employeds[count].address, "\n")] = '\0';

    printf("Correo electronico: ");
    fgets(employeds[count].email, 250, stdin);
    employeds[count].email[strcspn(employeds[count].email, "\n")] = '\0';

    printf("Puesto: ");
    fgets(employeds[count].position, 250, stdin);
    employeds[count].position[strcspn(employeds[count].position, "\n")] = '\0';

    while (1)
    {
        printf("Sueldo base: $");
        if (scanf("%f", &employeds[count].base_salary) == 1)
        {
            clear_input_buffer();
            break;
        }
        clear_input_buffer();
        printf("Sueldo base no valido\n");
    }

    printf("Horario: ");
    fgets(employeds[count].schedule, 250, stdin);
    employeds[count].schedule[strcspn(employeds[count].schedule, "\n")] = '\0';

    while (1)
    {
        printf("Comision: $");
        if (scanf("%f", &employeds[count].commission) == 1)
        {
            clear_input_buffer();
            break;
        }
        clear_input_buffer();
        printf("Comision no valida\n");
    }

    count++;
    printf("Empleado capturado correctamente\n");
    system("pause");
}

// ------------------- VISUALIZAR EMPLEADOS -------------------

void employed_view(struct __employeds employeds[])
{
    if (!exist_employeds())
        return;
    repeat('-', 50, 2);
    for (int i = 0; i < count; i++)
    {
        table_data_employed(employeds[i], i);
        system("pause");
    }
}

// ------------------- CONSULTAR EMPLEADO -------------------

void employed_consult(struct __employeds employeds[])
{
    if (!exist_employeds())
        return;

    char full_name[250];

    printf("Nombre completo: ");
    fgets(full_name, 250, stdin);
    full_name[strcspn(full_name, "\n")] = '\0';

    for (int i = 0; i < count; i++)
    {
        if (_stricmp(employeds[i].full_name, full_name) == 0)
        {
            repeat('-', 50, 2);
            table_data_employed(employeds[i], i);
            system("pause");
            return;
        }
    }

    printf("Empleado no encontrado\n");
    system("pause");
}

// ------------------- ELIMINAR EMPLEADO -------------------

void employed_delete(struct __employeds employeds[])
{
    if (!exist_employeds())
        return;

    char full_name[250];

    printf("Nombre completo: ");
    fgets(full_name, 250, stdin);
    full_name[strcspn(full_name, "\n")] = '\0';

    for (int i = 0; i < count; i++)
        if (_stricmp(employeds[i].full_name, full_name) == 0)
        {
            for (int j = i; j < count - 1; j++)
                employeds[j] = employeds[j + 1];

            count--;
            printf("Empleado eliminado\n");
            system("pause");
            return;
        }

    printf("Empleado no encontrado\n");
    system("pause");
}

// ------------------- MODIFICACION -------------------

struct __employeds modify_data_employed(struct __employeds employed)
{
    while (1)
    {
        char *options[] = {
            "Modificar nombre completo",
            "Modificar numero de telefono",
            "Modificar direccion",
            "Modificar correo electronico",
            "Modificar puesto",
            "Modificar sueldo base",
            "Modificar horario",
            "Modificar comision",
            NULL};

        int option = render_menu(options, 1, 9);

        system("cls");

        switch (option)
        {
        case 1:
            printf("Nuevo nombre completo: ");
            fgets(employed.full_name, 250, stdin);
            employed.full_name[strcspn(employed.full_name, "\n")] = '\0';
            break;
        case 2:
            printf("Nuevo numero de telefono: ");
            fgets(employed.phone_number, 250, stdin);
            employed.phone_number[strcspn(employed.phone_number, "\n")] = '\0';
            break;
        case 3:
            printf("Nueva direccion: ");
            fgets(employed.address, 250, stdin);
            employed.address[strcspn(employed.address, "\n")] = '\0';
            break;
        case 4:
            printf("Nuevo correo electronico: ");
            fgets(employed.email, 250, stdin);
            employed.email[strcspn(employed.email, "\n")] = '\0';
            break;
        case 5:
            printf("Nuevo puesto: ");
            fgets(employed.position, 250, stdin);
            employed.position[strcspn(employed.position, "\n")] = '\0';
            break;
        case 6:
            while (1)
            {
                printf("Nuevo sueldo base: $");
                if (scanf("%f", &employed.base_salary) == 1)
                {
                    clear_input_buffer();
                    break;
                }
                clear_input_buffer();
                printf("Sueldo base no valido\n");
            }
            break;
        case 7:
            printf("Nuevo horario: ");
            fgets(employed.schedule, 250, stdin);
            employed.schedule[strcspn(employed.schedule, "\n")] = '\0';
            break;
        case 8:
            while (1)
            {
                printf("Nueva comision: $");
                if (scanf("%f", &employed.commission) == 1)
                {
                    clear_input_buffer();
                    break;
                }
                clear_input_buffer();
                printf("Comision no valida\n");
            }
            break;
        case 9:
            return employed;
        }

        printf("Dato modificado correctamente\n");
        system("pause");
    }
}

void employed_modify(struct __employeds employeds[])
{
    if (!exist_employeds())
        return;

    char full_name[250];

    printf("Nombre completo: ");
    fgets(full_name, 250, stdin);
    full_name[strcspn(full_name, "\n")] = '\0';

    for (int i = 0; i < count; i++)
    {
        if (_stricmp(employeds[i].full_name, full_name) == 0)
        {
            employeds[i] = modify_data_employed(employeds[i]);
            return;
        }
    }

    printf("Empleado no encontrado\n");
    system("pause");
}

// ------------------- MAIN -------------------

int main()
{
    struct __employeds employeds[MAX_EMPLOYEDS];

    while (1)
    {
        char *options[] = {
            "Capturar empleado",
            "Mostrar empleados",
            "Consultar empleado",
            "Eliminar empleado",
            "Modificar empleado",
            NULL};

        int option = render_menu(options, 1, 6);

        system("cls");

        switch (option)
        {
        case 1:
            employed_capturate(employeds);
            break;
        case 2:
            employed_view(employeds);
            break;
        case 3:
            employed_consult(employeds);
            break;
        case 4:
            employed_delete(employeds);
            break;
        case 5:
            employed_modify(employeds);
            break;
        default:
            return 0;
        }
    }

    return 0;
}