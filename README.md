# Tarea: Buffer Overflow — Inyección de shellcode

**Autor:** agente616 (Julian Lizano)

**Video de la demostración:** https://youtu.be/AXoZVqnVmaw

---

## Shellcode usado

- **Archivo:** `Linux/x86-64/execve(-bin-sh);.c`
- **Repositorio:** https://github.com/7feilee/shellcode
- **Autor del shellcode:** zbt
- **Tamaño:** 30 bytes
- **Función:** `execve("/bin/sh", NULL, NULL)`

## Resultado esperado

Obtener una **shell `/bin/sh` interactiva** dentro del proceso vulnerable.

---

## Paso a paso

### 1. Compilar `vulnerable.c`

```bash
gcc -o vulnerable vulnerable.c -fno-stack-protector -z execstack -no-pie
