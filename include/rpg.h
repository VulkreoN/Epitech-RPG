/*
** EPITECH PROJECT, 2021
** rpg
** File description:
** header for rpg
*/

#ifndef RPG_H_
    #define RPG_H_

    #include <SFML/Graphics.h>
    #include <stdlib.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <dirent.h>
    #include <unistd.h>
    #include "taya.h"

    typedef struct {
        sfClock *clock;
        sfTime time;
    } t_clock;

    typedef struct {
        sfVector2f pos;
        sfVector2f cell;
        sfVector2f last_cell;
        int whichSprite;
        int lastUpdate;
        sfIntRect take;
        sfBool isMoving;
        int direction;
        int attack;
        int defense;
        int money;
        sfVector2f *foot_pos;
        int *foot_dir;
        t_clock foot_time;
        sfBool talk;
        int foot_index;
        int lily;
        int guard;
    } player_t;

    typedef struct npc_s {
        sfVector2f pos;
        sfTexture *pixel;
        sfSprite *spr;
        char **text;
        void (*opponent)(game_t *, player_t *);
        sfIntRect rect;
    } npc_t;

    typedef struct pause_s {
        sfTexture *bg;
        sfSprite *bg_spr;
        sfTexture *rod;
        sfSprite *rod_spr;
        object_t *menu;
        object_t *resume;
        object_t *home;
        object_t *param;
        object_t *quit;
        object_t *info;
        object_t *player;
        object_t *skill;
        object_t *atkbtn;
        object_t *defbtn;
        int leave;
        int header;
        int atk;
        int def;
        int money;
    } pause_t;

    typedef struct intro_s {
        sfTexture *wan;
        sfTexture *rdd;
        sfSprite *wan_spr;
        sfSprite *rdd_spr;
        sfVector2f wan_pos;
        sfVector2f rdd_pos;
        sfTexture *bg;
        sfSprite *bg_spr;
        int skip;
        float sec;
        float angle;
        sfClock *time;
        sfTime duration;
    } intro_t;

    typedef struct start_s {
        sfTexture *bg;
        sfSprite *bg_spr;
        object_t *param;
        object_t *start;
        object_t *new;
        object_t *quit;
        sfTexture *play_disabled;
        sfSprite *play_disabled_spr;
        sfTexture *rdd;
        sfSprite *rdd_spr;
        int played;
    } start_t;

        #define WIDTH (16)
    #define HEIGHT (16)
    #define TIMEMOVE (150)
    #define SPEEDPLAYER (5)
    #define SPRITEUPDATEPERIOD (50)

    enum house_furniture {
        CANAPE_TL,
        CANAPE_TM,
        CANAPE_TR,
        CANAPE_BL,
        CANAPE_BM,
        CANAPE_BR,
        CARPET1_TL,
        CARPET1_TM,
        CARPET1_TR,
        CARPET1_ML,
        CARPET1_MM,
        CARPET1_MR,
        CARPET1_BL,
        CARPET1_BM,
        CARPET1_BR,
        TABLE_TL,
        TABLE_TR,
        TABLE_BL,
        TABLE_BR,
        CHAIR,
        DRACO_TL,
        DRACO_TR,
        DRACO_BL,
        DRACO_BR,
        TREE_T,
        TREE_B,
        DESK_T,
        DESK_M,
        DESK_B,
    };

    enum outside {
        HOUSE,
        GRASS,
        FLOWERS,
    };

    typedef struct {
        t_clock clock;
        int i_timeStamp_currentFrame;
        int i_timeStamp_lastFrame;
        int i_deltaTime;
        int i_timeSinceLastScoreUpdate;
    } t_timeManager;

    typedef struct {
        sfVector2f pos;
        sfVector2i cell;
        char *text;
        sfBool isTalking;
        int indexMap;
        int fight;
    } pnj_t;

    typedef struct {
        sfBool isEmpty;
        sfVector2f pos;
        sfTexture *texture;
        char *path;
    } colone_t;

    typedef struct {
        colone_t colone[50];
    } line_t;

    typedef struct {
        line_t line[37];
        sfTexture *sol;
        char *path;
        char *buffer;
        int indexScreen;
        pnj_t pnj_t[1];
        int wind;
        sfVector2f wind_pos;
    } map_t;

    void make_house(map_t *map_t, int a, int b, char *string);

    void fill_cell(int a, int b, map_t *map_t, sfIntRect *area);

    void make_outside(map_t *map_t, int a, int b, char *string);

    void get_string(char *buffer, int *c, char *string);

    void make_furniture(map_t *map_t, int a, int b, char *string);

    enum house_furniture check_enum(char *string);

    void fill_struct(sfBool isEmpty, char *path, colone_t *cell);

    enum outside enum_outside(char *string);

    void built_house(colone_t *cell, int a, int b, map_t *map_t);

    void initi_time(t_timeManager *timeManager, int binairy);

    int gettime(sfTime time, sfClock *clock);

    void print_map(map_t *map_t, game_t *game);

    void move_camera(player_t *player_t, map_t *map_t);

    void move_player(player_t *player_t, game_t *game,
    t_timeManager *timeManager, map_t *map);

    void print_sprite(char *path, player_t *player_t, sfVector2f size,
    sfRenderWindow *window);

    void which_sprite(player_t *player_t);

    void print_pnj(sfRenderWindow *window, pnj_t *pnj_t, int *indexScreen);

    void get_map(map_t *map_t, sfRenderWindow *window);

    void init_map(map_t *map_t);

    void interact(game_t *game, player_t *player_t, map_t *map_t);

    void print_text(sfRenderWindow* window, char *text, sfVector2f pos,
    sfColor color);

    void print_dia(char *path, sfVector2f pos,
    sfRenderWindow *window);

    char *getbuffer(char *arg);

    void print_cell(sfVector2f *pos, sfRenderWindow *window,
    sfTexture *texture);

    void init_screen(map_t *map_t);

    void check_pause_in_game(game_t *game, player_t *player, sfEvent event);

    int handle_pause(game_t *game, player_t *player);

    void destroy_pause_menu(pause_t *pause, player_t *player);

    int initialise_pause(pause_t *pause, game_t *game, player_t *player);

    void calcul_move(player_t *player_t, t_timeManager *timeManger);

    void initialise_game_config(player_t *pl, map_t *ma,
    t_timeManager *ti, game_t *game);

    void make_foot_effect(player_t *player);

    void display_foot_effect(game_t *game, player_t *pl);

    void create_wind_effect(map_t *map, sfRenderWindow *window);

    int handle_npc(game_t *game, player_t *player, map_t *map);

    int initialise_covid(game_t *game, player_t *player);

    void destroy_npc(npc_t *npc);

    sfBool can_talk_to_npc(npc_t *npc, sfVector2f pos);

    void handle_npc_interaction(npc_t *npc, game_t *game,
    player_t *player, sfBool fight);

    void start_fight_with_music(game_t *game, player_t *player,
    void (*opponent)(game_t *, player_t *));

    int handle_starting(game_t *game);

    int initialise_start(start_t *start, game_t *game);

    void destroy_start(start_t *start);

    int initialise_settings(settings_t *param, game_t *game);

    void destroy_settings(settings_t *param);

    void handle_settings(game_t *game);

    void destroy_music(game_t *game);

    int put_game_error(game_t *game);

    void handle_pause_headers_display(game_t *game, pause_t *pause);

    void handle_pause_buttons(game_t *game, pause_t *pause);

    void handle_escape_pause(pause_t *pause, sfEvent event);

    void handle_pause_headers_display(game_t *game, pause_t *pause);

    int initialise_intro(game_t *game, intro_t *intro);

    void handle_starting_cinematic(game_t *game, start_t *start);

    void destroy_intro(intro_t *intro, start_t *start);

    void handle_intro_movement(game_t *game, intro_t *intro, start_t *start);

    void handle_inventory(game_t *game);

    void handle_map(game_t *game, player_t *player, map_t *map);

    void display_map(game_t *game, map_t *map);

    void remove_all_foot(player_t *player, map_t *map);

    void travel_to_jap_garden(player_t *player, map_t *map);

    void travel_from_jap_garden(player_t *player, map_t *map);

    void travel_park_garden(player_t *player, map_t *map);

    void travel_between_601(player_t *player, map_t *map);

    void travel_between_pedago(player_t *player, map_t *map);

    sfBool check_map_collision(player_t *player, game_t *game,
    int index, int direction);

    sfBool check_jap_garden_collision(sfVector2f cell);

    sfBool check_carrefour_collision(sfVector2f cell, player_t *player);

    sfBool check_etipech_collision(sfVector2f cell, player_t *player);

    sfBool check_601_collision(sfVector2f cell, game_t *game);

    sfBool check_pedago_collision(sfVector2f cell, game_t *game);

    int check_collide(sfVector2f cel, sfVector2f pos1, sfVector2f pos2);

    int initialise_pops(game_t *game, player_t *player);

    int initialise_guard(game_t *game, player_t *player);

    int check_guard_collision(sfVector2f cell, player_t *player);

    int initialise_wise(game_t *game, player_t *player);

    void handle_wise_test(npc_t *wise, game_t *game);

    void make_lily_function(game_t *game, player_t *player);

    int initialise_lily(game_t *game, player_t *player);

    int check_lily_collision(sfVector2f cell, player_t *player);

    int initialise_rondodu(game_t *game, player_t *player);

    int initialise_rondoudou(game_t *game, player_t *player);

    void make_rondoudou_function(game_t *game, player_t *player);

    int initialise_rondodu(game_t *game, player_t *player);

    int initialise_jerome(game_t *game, player_t *player);

    void display_how_to_play_menu(sfRenderWindow *window);

    void check_wise_class(game_t *game, npc_t *npc);

    int handle_wise_bad_class(game_t *game, int key, sfBool display);

    void check_input(player_t *player_t, game_t *game, map_t *map);

    void move(player_t *player_t, game_t *game, int check, int index);

    void make_game_first_scene(game_t *game);

    void handle_copyright_end(game_t *game, float y);

    void handle_hakim_end(game_t *game, float y);

    void handle_joris_end(game_t *game, float y);

    void handle_maxence_end(game_t *game, float y);

    void handle_johann_end(game_t *game, float y);

    int create_save(player_t *player, game_t *game, map_t *map);

    int load_save(player_t *player, game_t *game, map_t *map);
#endif
