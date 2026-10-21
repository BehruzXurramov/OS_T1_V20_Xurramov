# Operatsion Tizimlar - 1-Topshiriq (Variant 20)

Ushbu repozitoriy C dasturlash tilining kompilyatsiya bosqichlari, pointerlar va dinamik xotira bilan ishlashga bag'ishlangan.

## Fayllar strukturasi:
- `hello.c`, `hello.i`, `hello.s`, `hello.o`, `hello` - Kompilyatsiyaning 4 ta bosqichi fayllari.
- `main.c` - 1-topshiriq (B qism: massiv takrorlanishlari va pointerlar).
- `task2.c` - 2-topshiriq (Dinamik stek yordamida qavslar balansini tekshirish).
- `valgrind.txt` - Valgrind yordamida xotira sizib chiqmasligini (memory leak) tekshirish natijasi.

## Kompilyatsiya va ishga tushirish:

### 1-topshiriq:
gcc -Wall -Wextra main.c -o main
./main

### 2-topshiriq:
gcc -Wall -Wextra task2.c -o task2_app
./task2_app

### Valgrind testi:
valgrind --leak-check=full ./task2_app
