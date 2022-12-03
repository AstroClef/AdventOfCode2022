COMPILER = gcc

INC_DIR = ../../lib/
BUILD_DIR = ../build/
OBJ_DIR = ../obj/

FLAGS = -I$(INC_DIR)

EntryClass = dayone
_BASEOBJ = $(EntryClass).o
_PREREQS = astroclef-lib.c astroclef-aocdemo-helpers.c
_OBJECTS = astroclef-lib.o astroclef-aocdemo-helpers.o

BASEOBJ = $(addprefix $(OBJ_DIR), $(_BASEOBJ))
PREREQS = $(addprefix $(INC_DIR),$(_PREREQS))
OBJECTS = $(addprefix $(OBJ_DIR),$(_OBJECTS))

$(EntryClass): $(BASEOBJ) $(OBJECTS)
	$(COMPILER) $^ -o $(BUILD_DIR)$@

$(BASEOBJ): $(EntryClass).c
	$(COMPILER) -c $^ -o $@

$(OBJ_DIR)%.o: $(INC_DIR)%.c
	$(COMPILER) -c $< -o $@ $(FLAGS)

.PHONY: clean
clean:
	del ..\\obj\\*.o ..\\build\\*.exe