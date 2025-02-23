gcc -o xiaolin_wu xiaolin_wu.c -lfreeglut -lopengl32 -lglu32 -lgdi32


gcc -o xiaolin_wu src/main.c src/xiaolin_wu.c -Iinclude -lfreeglut -lopengl32 -lglu32 -lgdi32 -Wl,-subsystem,console
