# Compilador
CXX = g++

# Flags de compilación
CXXFLAGS_BASE = -I ./include -Wall
CXXFLAGS_WARNINGS = -Wextra -Wpedantic -Wshadow -Wconversion -Wsign-conversion -Wfloat-equal
CXXFLAGS_OPTIMIZATIONS = -O2 -march=native -mtune=native
CXXFLAGS_DEBUGGING = -g #-ggdb

CXXFLAGS_RELEASE = $(CXXFLAGS_BASE) $(CXXFLAGS_OPTIMIZATIONS)
CXXFLAGS_DEBUG = $(CXXFLAGS_BASE) $(CXXFLAGS_DEBUGGING)

CXXFLAGS = $(CXXFLAGS_DEBUG)   # Cambia a $(CXXFLAGS_RELEASE) para producción

# Directorios y ejecutables
OBJ_DIR = build
TARGETS = experimento_1.out experimento_2.out

# Archivos fuente principales
SRC1 = ./src/experimento_1.cpp
SRC2 = ./src/experimento_2.cpp

# Fuentes comunes (sin los experimentos)
COMMON_SOURCES = $(filter-out $(SRC1) $(SRC2), $(wildcard ./src/*.cpp))
COMMON_OBJECTS = $(patsubst ./src/%.cpp, $(OBJ_DIR)/%.o, $(COMMON_SOURCES))

# Objetos individuales
OBJ1 = $(OBJ_DIR)/experimento_1.o $(COMMON_OBJECTS)
OBJ2 = $(OBJ_DIR)/experimento_2.o $(COMMON_OBJECTS)

.PHONY: all clean run1 run2

# Compilar todo
all: $(TARGETS)

# Reglas para cada ejecutable
experimento_1.out: $(OBJ1)
	@echo "Compilando experimento_1..."
	@$(CXX) $(OBJ1) -o $@ $(CXXFLAGS)

experimento_2.out: $(OBJ2)
	@echo "Compilando experimento_2..."
	@$(CXX) $(OBJ2) -o $@ $(CXXFLAGS)

# Compilar archivos objeto
$(OBJ_DIR)/%.o: ./src/%.cpp | $(OBJ_DIR)
	@echo "Compilando $<..."
	@$(CXX) -c $< -o $@ $(CXXFLAGS)

# Crear directorio build si no existe
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Ejecutar cada experimento
run1: experimento_1.out
	@./experimento_1.out

run2: experimento_2.out
	@./experimento_2.out

# Limpiar
clean:
	@rm -rf $(OBJ_DIR) $(TARGETS)
