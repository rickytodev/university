# Modelos UML

## Persona

```
┌───────────────────────────────────────────────────────────────────────────┐
│                                  Persona                                  │
├───────────────────────────────────────────────────────────────────────────┤
│ + nombre   : string                                                       │
│ + apellido : string                                                       │
│ - edad     : int                                                          │
│ - altura   : float                                                        │
├───────────────────────────────────────────────────────────────────────────┤
│ + Persona(nombre : string, apellido : string, edad : int, altura : float) │
│ + hablar() : void                                                         │
│ + verDatos() : void                                                       │
│ + obtenerEdad() : int                                                     │
│ + obtenerAltura() : float                                                 │
│ + cambiarEdad(edad : int) : void                                          │
│ + cambiarAltura(altura : float) : void                                    │
└───────────────────────────────────────────────────────────────────────────┘
```

## Carro

```
┌─────────────────────────────────────────────────────────────────────────────────────┐
│                                        Carro                                        │
├─────────────────────────────────────────────────────────────────────────────────────┤
│ + marca  : string                                                                   │
│ + modelo : string                                                                   │
│ + tipo   : string                                                                   │
│ - color  : string                                                                   │
│ - anio   : int                                                                      │
├─────────────────────────────────────────────────────────────────────────────────────┤
│ + Carro(marca : string, modelo : string, tipo : string, color : string, anio : int) │
│ + encender() : void                                                                 │
│ + apagar() : void                                                                   │
│ + acelerar() : void                                                                 │
│ + verDatos() : void                                                                 │
│ + obtenerColor() : string                                                           │
│ + obtenerAnio() : int                                                               │
│ + cambiarColor(color : string) : void                                               │
│ + cambiarAnio(anio : int) : void                                                    │
└─────────────────────────────────────────────────────────────────────────────────────┘
```

## Libro

```
┌─────────────────────────────────────────────────────────────────────┐
│                                Libro                                │
├─────────────────────────────────────────────────────────────────────┤
│ + titulo   : string                                                 │
│ + autor    : string                                                 │
│ - anio     : int                                                    │
│ - paginas  : int                                                    │
│ - prestado : bool                                                   │
├─────────────────────────────────────────────────────────────────────┤
│ + Libro(titulo : string, autor : string, anio : int, paginas : int) │
│ + prestar() : void                                                  │
│ + devolver() : void                                                 │
│ + verDatos() : void                                                 │
│ + obtenerAnio() : int                                               │
│ + obtenerPaginas() : int                                            │
│ + estaPrestado() : bool                                             │
│ + cambiarAnio(anio : int) : void                                    │
│ + cambiarPaginas(paginas : int) : void                              │
└─────────────────────────────────────────────────────────────────────┘
```

## Notacion

```
+ publico          → public:
- privado          → private:
nombre : Tipo      → Tipo nombre;
metodo() : Retorno → Retorno metodo();
```
