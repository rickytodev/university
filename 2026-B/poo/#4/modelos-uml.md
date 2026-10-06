# Modelos UML

## Estudiante

```
┌─────────────────────────────────────────────────────────────────────────────────┐
│                                    Estudiante                                   │
├─────────────────────────────────────────────────────────────────────────────────┤
│  - nombre   : string   (estatica)                                               │
│  - edad     : int      (estatica)                                               │
│  - carrera  : string*  (dinamica)                                               │
│  - promedio : float*   (dinamica)                                               │
├─────────────────────────────────────────────────────────────────────────────────┤
│  + Estudiante(nombre : string, edad : int, carrera : string, promedio : float)  │
│  + ~Estudiante()                                                                │
│  + getNombre()                   : string                                       │
│  + getEdad()                     : int                                          │
│  + getCarrera()                  : string                                       │
│  + getPromedio()                 : float                                        │
│  + setNombre(nombre : string)    : void                                         │
│  + setEdad(edad : int)           : void                                         │
│  + setCarrera(carrera : string)  : void                                         │
│  + setPromedio(promedio : float) : void                                         │
│  + verDatos()                    : void                                         │
└─────────────────────────────────────────────────────────────────────────────────┘
```

## Materia

```
┌──────────────────────────────────────────────────────────────────────────────┐
│                                   Materia                                    │
├──────────────────────────────────────────────────────────────────────────────┤
│  - nombre   : string   (estatica)                                            │
│  - creditos : int      (estatica)                                            │
│  - profesor : string*  (dinamica)                                            │
│  - horas    : int*     (dinamica)                                            │
├──────────────────────────────────────────────────────────────────────────────┤
│  + Materia(nombre : string, creditos : int, profesor : string, horas : int)  │
│  + ~Materia()                                                                │
│  + getNombre()                   : string                                    │
│  + getCreditos()                 : int                                       │
│  + getProfesor()                 : string                                    │
│  + getHoras()                    : int                                       │
│  + setNombre(nombre : string)    : void                                      │
│  + setCreditos(creditos : int)   : void                                      │
│  + setProfesor(profesor : string): void                                      │
│  + setHoras(horas : int)         : void                                      │
│  + verDatos()                    : void                                      │
└──────────────────────────────────────────────────────────────────────────────┘
```

## Notacion

```
+ publico          → public:
- privado          → private:
nombre : Tipo      → Tipo nombre;
nombre : Tipo*     → Tipo *nombre;   (memoria dinamica, new / delete)
metodo() : Retorno → Retorno metodo();
~Clase()           → destructor
```

## Memoria

```
Estatica                          Dinamica
────────                          ────────
string nombre;                    string *carrera = new string(...);
int edad;                         float *promedio = new float(...);

Se libera sola al terminar        Se libera con delete en el destructor
```
