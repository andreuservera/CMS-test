
# Build & run
```
mkdir build
cd build
cmake ..
make
```
This creates 2 executables, one for the application and one for the tests.


### Hint
To clone the *googletest* git submodule you can use the **--recurse-submodules** option, for instance:
```
git clone --recurse-submodules -j8 https://github.com/andreuservera/CMS-test
```
***

# Enunciado: Code sample

La muestra de código es libre, aunque debe cumplir unos requisitos. Al final hay algunas propuestas para aplicarlos. No tiene por qué ser ninguna de ellas, al final se trata de aplicar C++ moderno y hablar sobre la organización, arquitectura, diseño del código y de las estructuras y funcionalidades usadas.

## Requisitos
* Usar características de C++11, 14, 17 (std::tuple, std::optional, std::filesystem, lambdas, contenedores, funciones de <algorithm> (operaciones sobre contenedores), etc.).
* OOP: herencia, composición, etc.
* Principios SOLID.
* Configurar el proyecto para construirse con CMake.
* Añadir al README.md instrucciones (build & run), y lo que se considere oportuno.

## Bonus
* Conan config con CMake.
* C++ templates.
* Unit-testing (gtest/gmock ó Catch2).
* Git.

## Propuestas

Pequeña aplicación (en consola) que gestione:
* Un par de entidades de un negocio (clientes, proveedores, facturas, etc.), con un CRUD para cada entidad.
* Entidades de un hospital (altas, bajas, etc.).
* Una biblioteca digital de videojuegos (géneros, tiempo jugado, logros, etc.).

*****************************************************************************************************************

## Apuntes
### SOLID principles
- Single Responsibility Principle
    + A class should have one and only one reason to change

- Open/Closed Principle 
    + Open for extensions (new shapes) but closed for modification (area method)

- Liskov substitution principle (LSP)
    + Subtypes must be substitutable for their base types

- Interface Segregation Principles (ISP)
    + Keep interfaces as small as possible.

- Dependency Inversion Principle (DIP)
    + Depend upon abstractions (interfaces) rather than concrete classes


*****************************************************************************************************************
# Mejoras
## The rule of three/five/zero
### Rule of three
If a class requires any of:
    - user-defined destructor,
    - user-defined copy constructor,
    -  user-defined copy assignment operator,

 it almost certainly requires all three.

### Rule of five


# Todo:
**default** & **delete** keywords in constructors

