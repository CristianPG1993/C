# 🔓 Simulador de Fuerza Bruta Numérica

## Descripción

Esta herramienta simula un ataque de fuerza bruta sobre una contraseña numérica de 4 cifras (0000 a 9999). Está pensada con fines educativos en el contexto de ciberseguridad, para demostrar cuán vulnerable puede ser una clave corta ante ataques de prueba exhaustiva.

## Funcionamiento

- El usuario introduce una clave de 4 cifras.
- El programa genera e imprime cada intento desde 0000 hasta 9999.
- Se comparan los intentos con la clave objetivo.
- Al encontrar la clave, se muestra:
  - El número de la clave
  - La cantidad total de intentos

## Ejemplo

```bash
Introduce la clave (0000 - 9999): 0423

Intento 0000. Intento de fuerza bruta denegado.
...
Intento 0423. ✅ Clave conseguida por fuerza bruta con éxito.

🔓 Clave encontrada: 0423
📊 Intentos realizados: 424
