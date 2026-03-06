/*
    Estudiante: Ricardo Jeshua Vega Garcia
    Matricula: 225976304
    Actividad: 3.4
    Fecha de entrega: 06 - Marzo - 2026
    Materia: Programación Estructurada
    Sección: D07
*/

/*
    Realice un programa que le permita crear el kardex de n estudiantes, los datos que debe capturar son:

    Nombre del alumno
    código
    Clave de la materia
    nombre de la materia
    calificación
    situación (Ordinario / Extraordinario / otro
    Ciclo escolar en que la curso.
    Promedio

    NOTA: el programa debe permitir capturar mas de una materia.
    Al eliminar una materia se elimina solo la de un alumno en particular.

    El menu de opciones para esta estructura son:

    1.- Capturar (captura datos de alumno y lista de materias, pregunte cuantas materias serán capturadas )
    2.- Eliminar una materia de un alumno
    3.- Consultar el listado de las materias por ciclo escolar (todos)
    4.- Buscar por nombre de la materia, deberá mostrar los datos de la materia (por alumno)
    5.- mostrar todas las materias (de un alumno)
    6.- Eliminar todo
    7.- Salir

    se incluye como ejemplo el ejercicio realizado en clase.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 25
#define MAX_STUDENTS 100

// ------ valores globales

typedef struct
{
    char key_matter[10];
    char matter[MAX_CHAR];
    char school_cycle[5];
    int qualification;
} __matter;

typedef struct
{
    char fullname[MAX_CHAR];
    char code[10];
    char situation[MAX_CHAR];
    float average;
    __matter matters[60]; // <- cada estudiante puede tener hasta 60 materias
} __student;

int total_students = 0;

// ------ funciones

void clear_screen()
{
    system("cls || clear");
}

void repeat(char c, int n)
{
    for (int i = 0; i < n; i++)
        printf("%c", c);
}

int validate_code_student(__student students[], char code[10])
{
    for (int i = 0; i < total_students; i++) // FIX: solo hasta total_students, no MAX_STUDENTS
        if (strcmp(students[i].code, code) == 0)
            return 1;
    return 0;
}

int validate_code_matter(__matter matter[], char code_matter[10])
{
    for (int i = 0; i < 60; i++)
    {
        if (strlen(matter[i].key_matter) == 0) // FIX: para cuando no hay mas materias
            break;
        if (strcmp(matter[i].key_matter, code_matter) == 0)
            return 1;
    }
    return 0;
}

void clear_input_buffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void break_line(int n)
{
    for (int i = 0; i < n; i++)
        printf("\n");
}

void stop(char *message)
{
    if (strlen(message) > 0)
        printf("%s", message);
    break_line(2);
    system("pause");
}

// ------ tabla -> materias

void table_head_matters()
{
    repeat('-', 81);
    printf("\n| %-12s | %-24s | %-12s | %-20s |\n", "Codigo", "Materia", "Ciclo", "Calificacion");
    repeat('-', 81);
}

void table_row_matters(__matter matter)
{
    printf("\n| %-12s | %-24s | %-12s | %-20d |\n", matter.key_matter, matter.matter, matter.school_cycle, matter.qualification);
    repeat('-', 81);
}

void table_matters(__matter matter[], int clear, int stop_after)
{
    if (clear)
        clear_screen();

    // FIX: verificar si hay materias antes de mostrar la tabla
    int has_matters = 0;
    for (int i = 0; i < 60; i++)
        if (strlen(matter[i].key_matter) > 0)
        {
            has_matters = 1;
            break;
        }

    if (!has_matters)
    {
        stop("No hay materias registradas");
        return;
    }

    table_head_matters();

    for (int i = 0; i < 60; i++)
        if (strlen(matter[i].key_matter) > 0)
            table_row_matters(matter[i]);

    printf("\n");

    if (stop_after)
        stop("");
}

// ------ tabla -> estudiantes

void table_head_student()
{
    repeat('-', 94);
    printf("\n| %-12s | %-24s | %-20s | %-10s | %-12s |\n", "Codigo", "Nombre completo", "Situacion", "Promedio", "Materias");
    repeat('-', 94);
}

void table_row_student(__student student)
{
    int total_matters = 0;

    for (int i = 0; i < 60; i++)
    {
        __matter matter = student.matters[i];
        if (strlen(matter.key_matter) == 0)
            break;
        total_matters++;
    }

    printf("\n| %-12s | %-24s | %-20s | %-10.2f | %-12d |\n", student.code, student.fullname, student.situation, student.average, total_matters);
    repeat('-', 94);
}

void table_students(__student students[], int clear, int stop_after)
{
    if (clear)
        clear_screen();

    if (total_students == 0) // FIX: usar total_students en lugar de revisar solo el primer elemento
    {
        stop("No hay estudiantes registrados");
        return;
    }

    table_head_student();

    for (int i = 0; i < MAX_STUDENTS; i++)
        if (strlen(students[i].code) > 0)
            table_row_student(students[i]);

    printf("\n");

    if (stop_after)
        stop("");
}

// ------ menu

int menu(char *options[], int max, int exit_option)
{
    while (1)
    {
        clear_screen();

        int option = 0;

        for (int i = 0; i < max; i++)
            printf("%d.- %s\n", i + 1, options[i]);

        if (exit_option)
            printf("%d.- Salir\n", max + 1);

        break_line(2);
        printf("Selecciona una opcion: ");

        if (scanf("%d", &option) != 1)
        {
            clear_input_buffer();
            stop("Opcion no valida, intente de nuevo");
            continue;
        }

        clear_input_buffer(); // FIX: limpiar buffer despues de leer la opcion valida tambien

        if (option < 1 || option > max + exit_option)
        {
            stop("Opcion no valida, intente de nuevo");
            continue;
        }

        return option;
    }
}

// ------ captura de datos del estudiante

float capture_matters(__student *current, int total_matters)
{
    int total_qualification = 0;

    for (int i = 0; i < total_matters; i++)
    {
        __matter *matter = &current->matters[i];

        // clave de la materia
        while (1)
        {
            clear_screen();
            printf("Materia %d de %d\n", i + 1, total_matters);
            repeat('-', 30);
            printf("\n");
            char temp[10];
            printf("Ingresa la clave de la materia: ");
            scanf(" %9[^\n]", temp);
            clear_input_buffer();

            if (strlen(temp) == 0)
            {
                stop("La clave de la materia no puede estar vacia");
                continue;
            }
            if (validate_code_matter(current->matters, temp))
            {
                stop("Ya existe una materia con esa clave");
                continue;
            }
            strcpy(matter->key_matter, temp);
            break;
        }

        // ciclo escolar -> por materia
        while (1)
        {
            clear_screen();
            printf("Materia %d de %d\n", i + 1, total_matters);
            repeat('-', 30);
            printf("\n");
            char temp[5];
            printf("Ciclo escolar de la materia (ejemplo: 2025): ");
            scanf(" %4[^\n]", temp);
            clear_input_buffer();

            if (strlen(temp) == 4)
            {
                strcpy(matter->school_cycle, temp);
                break;
            }

            stop("El ciclo escolar no es valido, debe tener 4 digitos");
            continue;
        }

        // nombre de la materia
        while (1)
        {
            clear_screen();
            printf("Materia %d de %d\n", i + 1, total_matters);
            repeat('-', 30);
            printf("\n");
            char temp[MAX_CHAR];
            printf("Ingresa el nombre de la materia: ");
            scanf(" %24[^\n]", temp);
            clear_input_buffer();

            if (strlen(temp) == 0)
            {
                stop("El nombre de la materia no puede estar vacio");
                continue;
            }
            strcpy(matter->matter, temp);
            break;
        }

        // calificación de la materia
        while (1)
        {
            clear_screen();
            printf("Materia %d de %d\n", i + 1, total_matters);
            repeat('-', 30);
            printf("\n");
            printf("Ingresa la calificacion de la materia (0 a 100): ");
            if (scanf("%d", &matter->qualification) != 1)
            {
                clear_input_buffer();
                stop("La calificacion debe ser un numero entero");
                continue;
            }
            clear_input_buffer();

            if (matter->qualification < 0 || matter->qualification > 100)
            {
                stop("La calificacion debe estar entre 0 y 100");
                continue;
            }
            total_qualification += matter->qualification;
            break;
        }
    }

    const float average = (float)total_qualification / (float)total_matters;
    return average;
}

void capture_student(__student student[])
{
    // validamos que no se capture mas de lo permitido
    if (total_students == MAX_STUDENTS)
    {
        stop("No se pueden capturar mas estudiantes");
        return;
    }

    __student *current = &student[total_students];

    // código
    while (1)
    {
        clear_screen();
        char temp[10];
        printf("Codigo del alumno (9 caracteres): ");
        scanf(" %9[^\n]", temp);
        clear_input_buffer();

        // FIX: primero validar duplicado, luego longitud
        if (validate_code_student(student, temp))
        {
            stop("Ya existe un alumno con ese codigo");
            continue;
        }

        if (strlen(temp) != 9)
        {
            stop("El codigo del alumno debe tener exactamente 9 caracteres");
            continue;
        }

        strcpy(current->code, temp);
        break;
    }

    // nombre completo
    while (1)
    {
        clear_screen();
        char temp[MAX_CHAR];
        printf("Nombre completo del alumno: ");
        scanf(" %24[^\n]", temp);
        clear_input_buffer();

        if (strlen(temp) == 0)
        {
            stop("El nombre del alumno no puede estar vacio");
            continue;
        }
        strcpy(current->fullname, temp);
        break;
    }

    // situación del estudiante
    {
        char *options[] = {
            "Ordinario",
            "Extraordinario",
            "Otro",
        };

        switch (menu(options, 3, 0))
        {
        case 1:
            strcpy(current->situation, "Ordinario");
            break;
        case 2:
            strcpy(current->situation, "Extraordinario");
            break;
        case 3:
            strcpy(current->situation, "Otro");
            break;
        }
    }

    int total_matters = 0;

    while (1)
    {
        clear_screen();

        printf("Ingresa la cantidad de materias a capturar (1 - 60): ");
        if (scanf("%d", &total_matters) != 1)
        {
            clear_input_buffer();
            stop("La cantidad de materias debe ser un numero entero");
            continue;
        }
        clear_input_buffer();

        if (total_matters < 1 || total_matters > 60)
        {
            stop("La cantidad de materias debe estar entre 1 y 60");
            continue;
        }
        break;
    }

    const float average = capture_matters(current, total_matters);
    current->average = average;

    // pasamos a la siguiente fila -> arreglo estudiantes
    total_students++;

    stop("Alumno capturado correctamente"); // FIX: confirmar al usuario que se guardo
}

// busqueda y eliminación de materia de un alumno
void delete_matter(__student *student)
{
    while (1)
    {
        clear_screen();

        // FIX: mostrar las materias del alumno antes de pedir la clave
        table_matters(student->matters, 0, 0);
        printf("\n");

        char temp[10];
        printf("Ingresa la clave de la materia a eliminar (0 para cancelar): ");
        scanf(" %9[^\n]", temp);
        clear_input_buffer();

        // FIX: opcion para cancelar
        if (strcmp(temp, "0") == 0)
            return;

        int found = 0;

        for (int i = 0; i < 60; i++)
        {
            if (strlen(student->matters[i].key_matter) == 0)
                break;

            if (strcmp(student->matters[i].key_matter, temp) == 0)
            {
                // shift correcto hasta 59
                for (int j = i; j < 59; j++)
                {
                    if (strlen(student->matters[j + 1].key_matter) == 0)
                    {
                        memset(&student->matters[j], 0, sizeof(__matter));
                        break;
                    }
                    student->matters[j] = student->matters[j + 1];
                }

                // FIX: limpiar ultimo elemento si se llego al final del arreglo
                if (strlen(student->matters[58].key_matter) != 0 &&
                    strlen(student->matters[59].key_matter) != 0)
                    memset(&student->matters[59], 0, sizeof(__matter));

                found = 1;
                break;
            }
        }

        if (found)
        {
            // recalcula el promedio correctamente tras eliminar la materia
            int total = 0, sum = 0;
            for (int i = 0; i < 60; i++)
            {
                if (strlen(student->matters[i].key_matter) == 0)
                    break;
                sum += student->matters[i].qualification;
                total++;
            }
            student->average = total > 0 ? (float)sum / (float)total : 0;

            stop("Materia eliminada correctamente");
            return;
        }

        stop("No se encontro una materia con esa clave");
    }
}

// busqueda de materia por nombre de un alumno
void search_matter(__matter *matter)
{
    while (1)
    {
        clear_screen();

        // mostrar las materias disponibles antes de buscar
        table_matters(matter, 0, 0);
        printf("\n");

        char temp[MAX_CHAR];
        printf("Ingresa el nombre de la materia a buscar (0 para cancelar): ");
        scanf(" %24[^\n]", temp);
        clear_input_buffer();

        // opcion para cancelar
        if (strcmp(temp, "0") == 0)
            return;

        int found = 0;

        for (int i = 0; i < 60; i++)
        {
            if (strlen(matter[i].key_matter) == 0)
                break;

            // busqueda por nombre (insensible a mayusculas)
            if (strcasecmp(matter[i].matter, temp) == 0)
            {
                // muestra los datos de la materia encontrada
                clear_screen();
                printf("Materia encontrada:\n");
                table_head_matters();
                table_row_matters(matter[i]);
                printf("\n");
                stop("");
                found = 1;
                return;
            }
        }

        if (!found)
            stop("No se encontro una materia con ese nombre");
    }
}

// consulta de materias por ciclo escolar -> todos los alumnos
void matters_by_cycle(__student students[])
{
    if (total_students == 0)
    {
        stop("No hay estudiantes registrados");
        return;
    }

    while (1)
    {
        clear_screen();

        char cycle[5];
        printf("Ingresa el ciclo escolar a consultar (ejemplo: 2025, 0 para cancelar): ");
        scanf(" %4[^\n]", cycle);
        clear_input_buffer();

        // opcion para cancelar
        if (strcmp(cycle, "0") == 0)
            return;

        if (strlen(cycle) != 4)
        {
            stop("El ciclo escolar no es valido, debe tener 4 digitos");
            continue;
        }

        // recorre todos los alumnos buscando materias del ciclo
        int found = 0;

        clear_screen();
        printf("Materias del ciclo escolar: %s\n", cycle);
        repeat('-', 106);
        printf("\n| %-24s | %-10s | %-24s | %-12s | %-20s |\n", "Alumno", "Codigo", "Materia", "Ciclo", "Calificacion");
        repeat('-', 106);

        for (int i = 0; i < total_students; i++)
        {
            for (int j = 0; j < 60; j++)
            {
                if (strlen(students[i].matters[j].key_matter) == 0)
                    break;

                if (strcmp(students[i].matters[j].school_cycle, cycle) == 0)
                {
                    printf("\n| %-24s | %-10s | %-24s | %-12s | %-20d |\n",
                           students[i].fullname,
                           students[i].code,
                           students[i].matters[j].matter,
                           students[i].matters[j].school_cycle,
                           students[i].matters[j].qualification);
                    repeat('-', 106);
                    found = 1;
                }
            }
        }

        printf("\n");

        if (!found)
            stop("No se encontraron materias para ese ciclo escolar");
        else
            stop("");

        return;
    }
}

// alumnos

void students(__student students[])
{
    if (total_students == 0) // FIX: usar total_students
    {
        stop("No hay estudiantes registrados");
        return;
    }

    char *options_students[] = {
        "Buscar materia",
        "Mostrar todas las materias",
        "Eliminar materia",
    }; // <- todo esto por medio del codigo del alumno

    while (1)
    {
        // FIX: mostrar tabla y pedir codigo antes del menu, no despues
        table_students(students, 1, 0);
        printf("\n");

        char code_student[10];
        printf("Ingresa el codigo del alumno (0 para volver): ");
        scanf(" %9[^\n]", code_student);
        clear_input_buffer();

        // FIX: opcion para volver al menu principal
        if (strcmp(code_student, "0") == 0)
            return;

        if (strlen(code_student) != 9)
        {
            stop("El codigo del alumno no es valido, debe tener 9 caracteres");
            continue;
        }

        if (validate_code_student(students, code_student) == 0)
        {
            stop("No se encontro un alumno con ese codigo");
            continue;
        }

        int index = 0;
        for (int i = 0; i < MAX_STUDENTS; i++)
            if (strcmp(students[i].code, code_student) == 0)
            {
                index = i;
                break; // FIX: salir del loop cuando se encuentra
            }

        const int option = menu(options_students, 3, 1);

        switch (option)
        {
        case 1:
            // buscar materia
            search_matter(students[index].matters);
            break;
        case 2:
            // mostrar todas las materias
            table_matters(students[index].matters, 1, 1);
            break;
        case 3:
            // eliminar materia
            delete_matter(&students[index]);
            break;
        default:
            return;
        }
    }
}

// ------ main

int main()
{
    __student student[MAX_STUDENTS] = {0};

    char *options_menu[] = {
        "Nuevo alumno",
        "Alumnos",
        "Materias por ciclo escolar",
        "Mostrar alumnos",
        "Eliminar todo",
    }; // <- menu general

    while (1)
    {
        clear_screen();

        switch (menu(options_menu, 5, 1))
        {
        case 1:
            // nuevo alumno
            capture_student(student);
            break;
        case 2:
            // alumnos
            students(student);
            break;
        case 3:
            // materias por ciclo escolar -> todos los alumnos
            matters_by_cycle(student);
            break;
        case 4:
            // mostrar alumnos
            table_students(student, 1, 1);
            break;
        case 5:
            // eliminar todo
            clear_screen();
            memset(student, 0, sizeof(student));
            total_students = 0;
            stop("Todos los alumnos han sido eliminados");
            break;

        default:
            return 0;
        }
    }

    return 0;
}
