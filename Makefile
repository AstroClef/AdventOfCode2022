COMPILER = gcc

PREREQ_DIR = ../../lib/
BUILD_DIR = ../build/
OBJ_DIR = ../obj/

FLAGS = -I$(PREREQ_DIR)

_OBJECTS = astroclef-lib.o astroclef-aocdemo-helpers.o
_PREREQS = astroclef-lib.c astroclef-aocdemo-helpers.c
PREREQS = $(addprefix $(PREREQ_DIR),$(_PREREQS))
OBJECTS = $(addprefix $(OBJ_DIR),$(_OBJECTS))

_basobj = dayone.o
BASEOBJ = $(addprefix $(OBJ_DIR), $(_BASEOBJ))


dayone: dayone.o $(OBJECTS)
	$(COMPILER) $^ -o $(BUILD_DIR)$@

dayone.o: dayone.c
	$(COMPILER) -c $^ -o $@

$(OBJ_DIR)%.o: $(PREREQ_DIR)%.c
	$(COMPILER) -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	del ..\\obj\\*.o ..\\build\\*.exe