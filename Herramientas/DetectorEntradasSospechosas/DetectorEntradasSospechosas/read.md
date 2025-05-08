# 🛡️ Detector de Entradas Sospechosas en C++

## Descripción

Esta herramienta desarrollada en C++ tiene como objetivo analizar cadenas de texto introducidas por el usuario y detectar patrones que podrían representar entradas maliciosas o sospechosas. Es parte de un laboratorio práctico de defensa activa en el contexto de ciberseguridad.

## Características

La función `esEntradaPeligrosa(string input)` evalúa la entrada según los siguientes criterios:

1. ❌ Contiene la palabra "DROP" (ignorando mayúsculas y minúsculas).
2. ❌ Contiene el símbolo `;` (frecuente en inyecciones SQL y comandos shell).
3. ❌ Supera los 40 caracteres de longitud.
4. ❌ Comienza con un espacio en blanco.
5. ❌ Contiene más de 3 símbolos especiales del conjunto: `* ? ! ^ " $`

Cada una de estas reglas se evalúa por separado, y se proporciona un resumen final indicando si la entrada ha sido marcada como peligrosa, junto con los motivos específicos.

## Ejemplo de uso

```bash
$ ./DetectorEntradaSospechosa

Introduce un texto: DROP table users;

⚠️ La entrada ha sido marcada como PELIGROSA por los siguientes motivos:
  - Contiene la palabra 'DROP'.
  - Contiene el símbolo ';'.
