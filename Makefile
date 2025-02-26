TARGET = bin/raytracer
SRC = $(wildcard src/*.c)
OBJ = $(patsubst src/%.c, obj/%.o, $(SRC))
TAGS = -lm

run: clean default
	./$(TARGET) > image.ppm

default: $(TARGET)

clean:
	rm -f obj/*.o
	rm -f bin/*
	rm -f *.ppm

$(TARGET): $(OBJ)
	gcc -o $@ $? $(TAGS)

obj/%.o : src/%.c
	gcc -c $< -o $@ -Iinclude
