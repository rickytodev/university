# Modelos UML - Herencia simple

Tres clases en una cadena lineal: `Persona` → `Empleado` → `Gerente`.
Cada clase hereda de una sola clase padre.

```
┌──────────────────────────────────────────────────────┐
│                        Persona                       │
├──────────────────────────────────────────────────────┤
│ # nombre : string                                    │
│ # edad   : int                                       │
│ - curp   : string                                    │
├──────────────────────────────────────────────────────┤
│ + Persona()                                          │
│ + Persona(nombre : string, edad : int, curp : string)│
│ + ~Persona()                         «virtual»       │
│ + presentarse()      : void          «virtual»       │
│ + verDatos()         : void          «virtual»       │
│ + caminar()          : void                          │
│ + getNombre() / setNombre(...)                       │
│ + getEdad()   / setEdad(...)                         │
│ + getCurp()   / setCurp(...)                         │
└──────────────────────────────────────────────────────┘
                           ▲
                           │  public
                           │
┌──────────────────────────────────────────────────────┐
│                       Empleado                       │
├──────────────────────────────────────────────────────┤
│ # puesto  : string                                   │
│ # salario : float                                    │
├──────────────────────────────────────────────────────┤
│ + Empleado()                                         │
│ + Empleado(nombre, edad, curp, puesto, salario)      │
│ + ~Empleado()                                        │
│ + presentarse()       : void        (sobreescrito)   │
│ + verDatos()          : void        (sobreescrito)   │
│ + trabajar()          : void                         │
│ + calcularPagoAnual() : float       «virtual»        │
│ + getPuesto()  / setPuesto(...)                      │
│ + getSalario() / setSalario(...)                     │
└──────────────────────────────────────────────────────┘
                           ▲
                           │  public
                           │
┌──────────────────────────────────────────────────────┐
│                        Gerente                       │
├──────────────────────────────────────────────────────┤
│ - departamento : string                              │
│ - bono         : float                               │
├──────────────────────────────────────────────────────┤
│ + Gerente()                                          │
│ + Gerente(nombre, edad, curp, salario,               │
│           departamento, bono)                        │
│ + ~Gerente()                                         │
│ + presentarse()       : void        (sobreescrito)   │
│ + verDatos()          : void        (sobreescrito)   │
│ + calcularPagoAnual() : float       (sobreescrito)   │
│ + dirigirReunion()    : void                         │
│ + getDepartamento() / setDepartamento(...)           │
│ + getBono()         / setBono(...)                   │
└──────────────────────────────────────────────────────┘
```

## Conceptos que se muestran

| Concepto | Donde |
|---|---|
| Herencia simple (`class B : public A`) | `Empleado : public Persona`, `Gerente : public Empleado` |
| Miembros `protected` | `nombre`, `edad`, `puesto`, `salario`: se usan directo en las hijas |
| Miembros `private` no accesibles en la hija | `curp` solo se lee con `getCurp()` |
| Lista de inicializacion (llamar al constructor del padre) | `Empleado(...) : Persona(...)` |
| Orden de constructores | base → derivada |
| Orden de destructores | derivada → base |
| Metodos heredados sin cambios | `gerente.caminar()`, `gerente.trabajar()` |
| Sobreescritura de metodos | `presentarse()`, `verDatos()`, `calcularPagoAnual()` |
| Reutilizar el metodo del padre (`::`) | `Empleado::verDatos()` llama a `Persona::verDatos()` |
| Polimorfismo con `virtual` | arreglo de `Persona*` |
| Destructor virtual | `delete` de un `Gerente` desde un `Persona*` |

## Notacion

```
+ publico      → public:
# protegido    → protected:
- privado      → private:
───▲           → herencia (la flecha apunta a la clase padre)
```
