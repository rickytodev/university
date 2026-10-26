# Modelos UML - Herencia multiple (diamante)

Cuatro clases en formacion de diamante. `Smartphone` hereda de `Telefono` y de
`Camara`, y ambas heredan de `Dispositivo`.

```
                 ┌───────────────────────────────────────┐
                 │              Dispositivo              │
                 ├───────────────────────────────────────┤
                 │ # marca     : string                  │
                 │ # modelo    : string                  │
                 │ # encendido : bool                    │
                 ├───────────────────────────────────────┤
                 │ + Dispositivo()                       │
                 │ + Dispositivo(marca, modelo)          │
                 │ + ~Dispositivo()          «virtual»   │
                 │ + encender()      : void              │
                 │ + apagar()        : void              │
                 │ + verDatos()      : void  «virtual»   │
                 │ + getMarca()  / setMarca(...)         │
                 │ + getModelo() / setModelo(...)        │
                 │ + estaEncendido() : bool              │
                 └───────────────────────────────────────┘
                        ▲                         ▲
       virtual public   │                         │   virtual public
                        │                         │
┌────────────────────────────────────┐ ┌────────────────────────────────────┐
│              Telefono              │ │               Camara               │
├────────────────────────────────────┤ ├────────────────────────────────────┤
│ # numero : string                  │ │ # megapixeles  : int               │
│                                    │ │ # fotosTomadas : int               │
├────────────────────────────────────┤ ├────────────────────────────────────┤
│ + Telefono()                       │ │ + Camara()                         │
│ + Telefono(marca, modelo, numero)  │ │ + Camara(marca, modelo, mp)        │
│ + ~Telefono()                      │ │ + ~Camara()                        │
│ + llamar(destino : string) : void  │ │ + tomarFoto() : void               │
│ + verDatos() : void (sobreescrito) │ │ + verDatos()  : void (sobreescrito)│
│ + getNumero() / setNumero(...)     │ │ + getMegapixeles() / set...(...)   │
│                                    │ │ + getFotosTomadas() : int          │
└────────────────────────────────────┘ └────────────────────────────────────┘
                        ▲                         ▲
               public   │                         │   public
                        │                         │
                 ┌───────────────────────────────────────┐
                 │               Smartphone              │
                 ├───────────────────────────────────────┤
                 │ - sistemaOperativo : string           │
                 │ - appsInstaladas   : int              │
                 ├───────────────────────────────────────┤
                 │ + Smartphone()                        │
                 │ + Smartphone(marca, modelo, numero,   │
                 │              megapixeles, so)         │
                 │ + ~Smartphone()                       │
                 │ + verDatos()  : void  (sobreescrito)  │
                 │ + instalarApp(app : string) : void    │
                 │ + getSistemaOperativo() / set...(...) │
                 └───────────────────────────────────────┘
```

## El problema del diamante

Sin `virtual`, `Telefono` y `Camara` tendrian cada una su propia copia de
`Dispositivo`, y un `Smartphone` tendria **dos** marcas, dos modelos y dos
estados de encendido:

```
Sin virtual:                      Con virtual:

Dispositivo   Dispositivo              Dispositivo
     │             │                    /       \
 Telefono       Camara             Telefono    Camara
      \           /                     \       /
       Smartphone                       Smartphone
```

Con dos copias, `smartphone.getMarca()` o `Dispositivo *d = &smartphone;` son
ambiguos y no compilan. Con `virtual public Dispositivo` solo hay una copia
compartida y esas llamadas funcionan.

## Conceptos que se muestran

| Concepto | Donde |
|---|---|
| Herencia multiple (`class D : public B, public C`) | `Smartphone : public Telefono, public Camara` |
| Herencia virtual | `Telefono : virtual public Dispositivo`, igual en `Camara` |
| La clase mas derivada construye la base virtual | `Smartphone(...) : Dispositivo(...), Telefono(...), Camara(...)` |
| Orden de constructores | Dispositivo (una vez) → Telefono → Camara → Smartphone |
| Orden de destructores | inverso: Smartphone → Camara → Telefono → Dispositivo |
| Ambiguedad de metodos | `Smartphone` debe redefinir `verDatos()` porque sus dos padres lo redefinen |
| Operador de ambito para elegir padre | `smartphone.Telefono::verDatos()`, `smartphone.Camara::verDatos()` |
| Una sola copia de la base | cambiar la marca por `Telefono` se ve tambien por `Camara` |
| Polimorfismo | punteros `Telefono*`, `Camara*` y `Dispositivo*` al mismo smartphone |
| Destructor virtual | `delete` de un `Smartphone` desde un `Dispositivo*` |

## Notacion

```
+ publico      → public:
# protegido    → protected:
- privado      → private:
───▲           → herencia (la flecha apunta a la clase padre)
«virtual»      → metodo virtual
```
