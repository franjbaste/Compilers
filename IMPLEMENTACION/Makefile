# ==========================================
# Makefile para el Traductor de C a Lisp
# ==========================================

# Nombre del archivo ejecutable final
TARGET = trad2

# Nombre de tu archivo de Yacc/Bison
YACC_FILE = trad2.y

# Regla principal: se ejecuta cuando escribes solo 'make'
all: $(TARGET)

# Cómo construir el ejecutable
$(TARGET): y.tab.c
	gcc y.tab.c -o $(TARGET)

# Cómo construir el código C a partir de la gramática
y.tab.c: $(YACC_FILE)
	bison -y $(YACC_FILE)

# Regla para limpiar los archivos generados
clean:
	rm -f y.tab.c y.tab.h $(TARGET)

# Evita conflictos si hay un archivo que se llame "clean" o "all"
.PHONY: all clean