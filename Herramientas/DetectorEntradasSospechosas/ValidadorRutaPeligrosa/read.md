# 🛡️ Validador de Rutas Peligrosas en C++

## Descripción

Esta herramienta analiza rutas o cadenas de texto que representan comandos del sistema para detectar patrones potencialmente peligrosos que podrían indicar un intento de evasión, ataque traversal o acceso a zonas restringidas.

## Reglas de detección

La función `cadenaPotencialmentePeligrosa(string input)` evalúa:

1. ❌ Si la ruta comienza por `/` o `C:\`
2. ❌ Si contiene `../` o `..\` (path traversal)
3. ❌ Si menciona carpetas críticas como `etc`, `bin`, `system32`
4. ❌ Si incluye comillas escapadas como `\"` o `\'`
5. ❌ Si comienza con doble barra (`//` o `\\`)

## Ejemplo

```bash
Introduce una cadena de texto: ../../etc/passwd
❌ La entrada es potencialmente peligrosa porque contiene '../' o '..\'.
❌ La entrada contiene algún directorio crítico.
⚠️ La entrada de texto contiene elementos potencialmente maliciosos. Detalles:
 - Contiene patrones de traversal (../ o ..\).
 - Hace referencia a directorios críticos como etc, bin o system32.
