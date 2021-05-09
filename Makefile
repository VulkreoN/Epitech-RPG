##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## My own Makefile <3
##

cc	=	gcc

#	VARIABLES	#

DEFAULT		=	"\033[00m"
GREEN		=	"\033[1;32m"
CYAN		=	"\033[1;36m"
YELLOW		=	"\033[1;184m"
MAGENTA		=	"\033[1;95m"
ERROR		=	"\033[1;31m"

#	SOURCES	#

SRC =	main.c 							\
		fight/fight.c					\
		fight/init_fight_attack.c		\
		fight/introduce_fight.c			\
		fight/initialise.c				\
		fight/init_menu.c				\
		fight/init_text_fight.c			\
		fight/init_both_perso.c			\
		fight/init_bar.c				\
		fight/move_menu.c				\
		fight/combat.c					\
		fight/hit_system.c				\
		fight/make_attack_text.c		\
		fight/draw.c					\
		fight/destroy_menus.c 			\
		fight/destroy_objects.c			\
		fight/check_event.c				\
		fight/init_attack_hugo.c		\
		fight/init_attack_opponent.c	\
		fight/fight_with_opponent.c		\
		fight/fight_music.c 			\
		init_struct.c 					\
		tools.c 						\
		move_player.c 					\
		pnj.c							\
		start/start.c 					\
		start/initialise_start.c 		\
		start/destroy_start.c 			\
		start/start_cinematic.c 		\
		start/intro_config.c 			\
		start/intro_movement.c 			\
		settings/settings.c 			\
		settings/initialise_settings.c 	\
		settings/destroy_settings.c 	\
		music.c 						\
		tools2.c						\
		game_config.c 					\
		game.c 							\
		pause/destroy_pause.c 			\
		pause/initialise_pause.c 		\
		pause/pause.c					\
		pause/pause_buttons.c			\
		pause/pause_headers.c			\
		pause/pause_inventory.c 		\
		calcul_move.c					\
		effect/foot_effect.c			\
		effect/wind_effect.c			\
		npc/npc.c 						\
		npc/covid_npc.c					\
		npc/pops_npc.c 					\
		npc/guard_npc.c 				\
		npc/wise_npc.c 					\
		npc/wise_text.c 				\
		npc/lily_npc.c 					\
		npc/rondoudou_npc.c 			\
		npc/true_rondoudou_npc.c 		\
		npc/jerome_npc.c 				\
		map/map.c						\
		map/print_map.c					\
		map/map_travel.c				\
		map/map_collision.c				\
		save/create_save.c	\
		save/load_save.c	\
		save/detect_save.c 		\
		end/end.c				\
		end/member_end.c 		\
		outside.c			\
		house.c 			\
		init_map.c			\
		settings/how_to_play.c	\
		input.c					\
		first_scene.c			\
		game_tmp.c				\
		init_furniture.c		\
		find_furniture.c


TESTS_SRC	=

$(eval SRC = $(addprefix source/, $(SRC)))

#	OBJECTS	#

OBJ	=	$(SRC:.c=.o)

TESTS_OBJ	=	$(TESTS_SRC:.c=.o)

#	NAME	#

NAME	=	my_rpg

TESTS_NAME	=	unit_tests

#	FLAGS	#

CSFMLFLAGS	=	-l csfml-graphics -l csfml-system -l csfml-window -l csfml-audio -lm

CFLAGS	=	-Llib/ -ltaya -W -Wpedantic -Wall -Wextra -fno-builtin -I./include/

TESTS_FLAGS	=	--coverage -lcriterion


#	RULES	#

all:	$(NAME)

$(NAME):	$(OBJ)
	@printf "\033[1;95m Making lib\n"
	@make --silent -C ./lib/taya
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;36m Compiling .C\n"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

valgrind: $(OBJ)
	@printf "\033[1;95m Making lib\n"
	@make --silent -C ./lib/taya/
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;36m Compiling .C\n"
	@gcc -o $(NAME) $(OBJ) $(CFLAGS) $(CSFMLFLAGS) -g3
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

tests_run: $(OBJ)	$(TESTS_OBJ)
	@printf "\033[1;95m Making lib\n"
	@make --silent -C ./lib/taya/
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;36m Compiling .C\n"
	@gcc -o $(TESTS_NAME) $(OBJ) $(TESTS_OBJ) $(TESTS_FLAGS)
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;31m Launching tests\n"
	./$(TESTS_NAME)
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

clean:
	@printf "\033[1;31m Cleanning .o\n"
	@rm -f $(OBJ) $(TESTS_OBJ)
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;31m cleanning lib\n"
	@make clean --silent -C ./lib/taya
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

fclean: clean
	@printf "\033[1;31m Cleanning binaries\n"
	@rm -f $(NAME) $(TESTS_NAME)
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;31m cleanning lib binaries\n"
	@make fclean --silent -C ./lib/taya
	@printf "\033[1;32m DONE\n"
	@printf "\033[1;31m cleanning vgcore\n"
	@rm -f vgcore.*
	@printf "\033[1;32m DONE\n"
	@printf "\033[00m"

re:	fclean	all
	@printf "\033[1;32m REBULDING DONE\n"
	@printf "\033[00m"

#	END		-Made by VulkreoN	#