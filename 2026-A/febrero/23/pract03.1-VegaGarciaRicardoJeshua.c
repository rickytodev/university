/*
    Estudiante: Ricardo Jeshua Vega Garcia
    Matricula: 225976304
    Actividad: 3.1
    Fecha de entrega: 23 - Febrero - 2026
    Materia: Programación Estructurada
    Sección: D07
*/

/*
    Información de la actividad:
    Escriba un programa que en una estructura guarde los datos de 5 amigos suyos y los muestre por pantalla, la misma estructura contendrá: Nombre, Apellidos, Edad, Sexo, correo electrónico y teléfono.
    Puede utilizar funciones o bien puede realizar todo en el menu principal, recuerde utilizar lo necesario de los temas de estructuras de control y funciones.
*/

#include <stdlib.h>
#include <stdio.h>
#define MAX_FRIENDS 10

struct Object
{
    char first_name[250];
    char last_name[250];
    int age;
    int sex;
    char email[250];
    char thelphone[250];
};

void lBreack(int count)
{
    for (int i = 0; i < count; i++)
        printf("\n");
}

void repeat(char character, int instances, int line_break)
{
    for (int i = 0; i < instances; i++)
        printf("%c", character);
    if (line_break > 0)
        lBreack(line_break);
}

void read_input(char value[], int size)
{
    char format[20];
    sprintf(format, " %%%d[^\n]", size - 1);
    scanf(format, value);
}

int read_int(const char *prompt, int min, int max)
{
    int value;
    while (1)
    {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= min && value <= max)
            return value;
        printf("Error: Entrada no valida. Intenta de nuevo.\n");
        scanf("%*[^\n]");
        scanf("%*c");
    }
}

void input_friend(struct Object *friend, int index)
{
    system("cls");
    char prompt[100];

    printf("Ingresa el nombre del amigo %d: ", index);
    read_input(friend->first_name, sizeof(friend->first_name));

    printf("Ingresa el apellido del amigo %d: ", index);
    read_input(friend->last_name, sizeof(friend->last_name));

    sprintf(prompt, "Ingresa la edad del amigo %d: ", index);
    friend->age = read_int(prompt, 1, 120);

    sprintf(prompt, "Ingresa el sexo del amigo %d (0 para hombre, 1 para mujer): ", index);
    friend->sex = read_int(prompt, 0, 1);

    printf("Ingresa el correo electronico del amigo %d: ", index);
    read_input(friend->email, sizeof(friend->email));

    printf("Ingresa el telefono del amigo %d: ", index);
    read_input(friend->thelphone, sizeof(friend->thelphone));
}

void view_information(struct Object friends[], int sFriends)
{
    system("cls");
    lBreack(1);
    repeat('#', 100, 1);
    printf("\n");
    for (int i = 0; i < sFriends; i++)
    {
        printf("Amigo #%d\n", i + 1);
        lBreack(1);
        printf("    Nombre: %s\n", friends[i].first_name);
        printf("    Apellido: %s\n", friends[i].last_name);
        printf("    Edad: %d\n", friends[i].age);
        printf("    Sexo: %s\n", friends[i].sex == 0 ? "Hombre" : "Mujer");
        printf("    Correo electronico: %s\n", friends[i].email);
        printf("    Telefono: %s\n\n", friends[i].thelphone);
        repeat('#', 100, 2);
    }
}

int main()
{
    int sFriends;
    struct Object friends[MAX_FRIENDS];

    printf("Cuantos amigos desea ingresar (maximo %d): ", MAX_FRIENDS);
    sFriends = read_int("", 1, MAX_FRIENDS);

    for (int i = 0; i < sFriends; i++)
        input_friend(&friends[i], i + 1);

    view_information(friends, sFriends);
    return 0;
}