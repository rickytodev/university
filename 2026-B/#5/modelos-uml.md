# Modelos UML

Tres clases: `Alumno`, `Profesor` y `Curso`. Cada una tiene 5 atributos privados,
dos de ellos de tipo clase, sus metodos get y set, y tres sobrecargas del
constructor.

## Alumno

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│                                      Alumno                                      │
├──────────────────────────────────────────────────────────────────────────────────┤
│ - nombre    : string                                                             │
│ - matricula : string                                                             │
│ - promedio  : float                                                              │
│ - curso     : Curso*                                                             │
│ - tutor     : Profesor*                                                          │
├──────────────────────────────────────────────────────────────────────────────────┤
│ + Alumno()                                                                       │
│ + Alumno(nombre : string, matricula : string)                                    │
│ + Alumno(nombre : string, matricula : string, promedio : float,                  │
│          curso : Curso*, tutor : Profesor*)                                      │
│ + estudiar()                       : void                                        │
│ + verDatos()                       : void                                        │
│ + getNombre()                      : string                                      │
│ + setNombre(nombre : string)       : void                                        │
│ + getMatricula()                   : string                                      │
│ + setMatricula(matricula : string) : void                                        │
│ + getPromedio()                    : float                                       │
│ + setPromedio(promedio : float)    : void                                        │
│ + getCurso()                       : Curso*                                      │
│ + setCurso(curso : Curso*)         : void                                        │
│ + getTutor()                       : Profesor*                                   │
│ + setTutor(tutor : Profesor*)      : void                                        │
└──────────────────────────────────────────────────────────────────────────────────┘
```

## Profesor

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│                                     Profesor                                     │
├──────────────────────────────────────────────────────────────────────────────────┤
│ - nombre      : string                                                           │
│ - cedula      : string                                                           │
│ - antiguedad  : int                                                              │
│ - curso       : Curso*                                                           │
│ - mejorAlumno : Alumno*                                                          │
├──────────────────────────────────────────────────────────────────────────────────┤
│ + Profesor()                                                                     │
│ + Profesor(nombre : string, cedula : string)                                     │
│ + Profesor(nombre : string, cedula : string, antiguedad : int,                   │
│            curso : Curso*, mejorAlumno : Alumno*)                                │
│ + impartirClase()                   : void                                       │
│ + verDatos()                        : void                                       │
│ + getNombre()                       : string                                     │
│ + setNombre(nombre : string)        : void                                       │
│ + getCedula()                       : string                                     │
│ + setCedula(cedula : string)        : void                                       │
│ + getAntiguedad()                   : int                                        │
│ + setAntiguedad(antiguedad : int)   : void                                       │
│ + getCurso()                        : Curso*                                     │
│ + setCurso(curso : Curso*)          : void                                       │
│ + getMejorAlumno()                  : Alumno*                                    │
│ + setMejorAlumno(alumno : Alumno*)  : void                                       │
└──────────────────────────────────────────────────────────────────────────────────┘
```

## Curso

```
┌──────────────────────────────────────────────────────────────────────────────────┐
│                                       Curso                                      │
├──────────────────────────────────────────────────────────────────────────────────┤
│ - nombre        : string                                                         │
│ - creditos      : int                                                            │
│ - aula          : string                                                         │
│ - profesor      : Profesor*                                                      │
│ - representante : Alumno*                                                        │
├──────────────────────────────────────────────────────────────────────────────────┤
│ + Curso()                                                                        │
│ + Curso(nombre : string, creditos : int)                                         │
│ + Curso(nombre : string, creditos : int, aula : string,                          │
│         profesor : Profesor*, representante : Alumno*)                           │
│ + iniciarCurso()                       : void                                    │
│ + verDatos()                           : void                                    │
│ + getNombre()                          : string                                  │
│ + setNombre(nombre : string)           : void                                    │
│ + getCreditos()                        : int                                     │
│ + setCreditos(creditos : int)          : void                                    │
│ + getAula()                            : string                                  │
│ + setAula(aula : string)               : void                                    │
│ + getProfesor()                        : Profesor*                               │
│ + setProfesor(profesor : Profesor*)    : void                                    │
│ + getRepresentante()                   : Alumno*                                 │
│ + setRepresentante(alumno : Alumno*)   : void                                    │
└──────────────────────────────────────────────────────────────────────────────────┘
```

## Relaciones

```
Alumno   ────► Curso       (atributo curso)
Alumno   ────► Profesor    (atributo tutor)
Profesor ────► Curso       (atributo curso)
Profesor ────► Alumno      (atributo mejorAlumno)
Curso    ────► Profesor    (atributo profesor)
Curso    ────► Alumno      (atributo representante)
```

Las tres clases se referencian entre si, asi que los atributos de tipo clase se
guardan como punteros (`Curso*`, `Profesor*`, `Alumno*`) y en cada encabezado se
usa una declaracion adelantada (`class Curso;`) en lugar del `#include`.

Si se guardaran como objetos completos (`Curso curso;`) habria una dependencia
circular: para calcular el tamanio de `Alumno` el compilador necesitaria el de
`Curso`, y para el de `Curso` necesitaria el de `Alumno`. Con punteros el tamanio
siempre es el de una direccion de memoria y el ciclo se rompe.

Los punteros solo apuntan a objetos que ya existen, no reservan memoria con `new`,
por eso ninguna clase necesita destructor.

## Notacion

```
+ publico          → public:
- privado          → private:
nombre : Tipo      → Tipo nombre;
nombre : Tipo*     → Tipo *nombre;   (atributo de tipo clase, por puntero)
metodo() : Retorno → Retorno metodo();
────►              → asociacion (atributo de tipo clase)
```
