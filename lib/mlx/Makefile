


MODULE_SRC= mlx_image.swift mlx_window.swift mlx_init.swift
MODULE_OBJ=$(MODULE_SRC:.swift=.swiftmodule)

SRC= interface.swift $(MODULE_SRC)
OBJ=$(SRC:.swift=.o)

C_SRC= mlx_xpm.c mlx_png.c mlx_string_put.c
C_OBJ=$(C_SRC:.c=.o)
CFLAGS=-O3 -Wno-deprecated-non-prototype
SWIFTCFLAGS = -suppress-warnings

NAME=libmlx.dylib

INC=-I.
#OPTI=-Ounchecked

all: $(NAME)

$(NAME): $(MODULE_OBJ) $(OBJ) $(C_OBJ)
	swiftc $(OPTI) $(INC) -o $(NAME) -emit-library $(OBJ) $(C_OBJ) -lz



%.o: %.swift
	swiftc $(SWIFTCFLAGS) $(OPTI) $(INC) -parse-as-library -c $< -o $@ > /dev/null 2>&1

%.swiftmodule: %.swift
	swiftc $(SWIFTCFLAGS) $(OPTI) $(INC) -parse-as-library -c $< -emit-module -module-name $(patsubst %.swift,%,$<) -module-link-name $(patsubst %.swift,%,$<) > /dev/null 2>&1

clean:
	rm -f $(NAME) $(OBJ) $(MODULE_OBJ) $(C_OBJ) *.swiftdoc *~

