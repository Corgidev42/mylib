# 🏳️‍🌈 Définition des couleurs
RESET   = \033[0m
RED     = \033[31m
GREEN   = \033[32m
YELLOW  = \033[33m
BLUE    = \033[34m
MAGENTA = \033[35m
CYAN    = \033[36m
BOLD    = \033[1m

# 🏆 Nom du projet
PROJECT_NAME = lib/libft.a

# 🏳️‍🌈 Variables de configuration
IS_LIBFT ?= false
IS_MLX ?= false

# 🛠 Compilateur et flags
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iinclude
LDFLAGS =

# 🖥️ Détection de l'OS
UNAME_S := $(shell uname -s)
ifeq ($(UNAME_S), Linux)
	MLX_DIR   = minilibx-linux
	MLX       = $(MLX_DIR)/libmlx_Linux.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -lXext -lX11 -lm -lz
	CFLAGS   += -I/usr/include
else ifeq ($(UNAME_S), Darwin)
	MLX_DIR   = minilibx-mac-2
	MLX       = $(MLX_DIR)/libmlx.a
	MLX_FLAGS = -L$(MLX_DIR) -lmlx -framework OpenGL -framework AppKit -I /opt/X11/include/X11
	CFLAGS   += -I/opt/homebrew/include
	LDFLAGS  += -L/opt/homebrew/lib
endif

ifeq ($(IS_MLX), true)
	CFLAGS += -I$(MLX_DIR)
endif

# 📂 Répertoires
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include

# 📌 Fichiers sources et objets
SRC_FILES = $(wildcard $(SRC_DIR)/**/*.c) $(wildcard $(SRC_DIR)/*.c)
OBJ_FILES = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRC_FILES))

# 📚 Headers
INCLUDES = -I$(INCLUDE_DIR)

# 🎯 Cible principale
all: $(OBJ_DIR) $(PROJECT_NAME)

$(PROJECT_NAME): $(OBJ_FILES)
	@mkdir -p $(dir $@)
	@echo "${MAGENTA}🚀 Création de la bibliothèque...${RESET}"
	@ar rcs $@ $^
	@echo "${GREEN}✅ Libft compilée avec succès !${RESET}"

# 🛠️ Compilation des objets
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) -c $(CFLAGS) $(INCLUDES) $< -o $@
	@echo "${CYAN}🔨 Compilé : $< -> $@${RESET}"

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# 🧹 Nettoyage
clean:
	@rm -rf $(OBJ_DIR)
	@echo "${RED}🧼 Objets supprimés.${RESET}"

fclean: clean
	@rm -f $(PROJECT_NAME)
	@echo "${RED}🗑️  Nettoyage complet effectué.${RESET}"

re: fclean all

# 🆘 Aide
help:
	@echo "${BOLD}${CYAN}--- 📘 Liste des commandes disponibles ---${RESET}"
	@echo "${BOLD}make${RESET}        : Compile le projet ($(PROJECT_NAME))"
	@echo "${BOLD}make clean${RESET}  : Supprime les fichiers objets"
	@echo "${BOLD}make fclean${RESET} : Supprime les objets + la bibliothèque"
	@echo "${BOLD}make re${RESET}     : Nettoie puis recompile tout"
	@echo "${BOLD}make help${RESET}   : Affiche ce message d’aide"

.PHONY: all clean fclean re help
