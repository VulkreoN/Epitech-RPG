/*
** EPITECH PROJECT, 2021
** lib_taya
** File description:
** taya
*/

#ifndef TAYA_H_
    #define TAYA_H_
    #include <stddef.h>

/* ARRAY */
    char **my_str_to_word_array(char *str, char c);
    void my_free_word_array(char **array);
    size_t my_arraylen(char **array);

/* INTS */
    int my_getnbr(char const *str);
    int my_isneg(int n);
    int my_intlen(int nb);
    int my_atoi(char *str);

/* PUTS */
    void my_putchar(char c);
    void my_putnbr(int nb);
    void my_putnbr_unsigned(unsigned int nb);
    void my_putoctal(int nb);
    void my_puthexa(int nb, int capital);
    void my_putuhexa(unsigned int nb, int capital);
    int my_putstr(char const *str);
    int my_putstr_error(char const *str);
    int my_fputstr(int FD, char const *str);
    void my_print_array(char **array);
    void my_printf(char *str, ...);
    void my_ldprintf(int fd, char *format, ...);
    int my_dputstr(int fd, char const *str);
    void my_dputnbr(int fd, int nb);
    void my_dputchar(int fd, char c);

/* STRINGS */
    char *my_revstr(char *str);
    char *my_strcat(char *dest, char const *src);
    int my_str_isnum(char const *str);
    int my_strcmp(char const *s1, char const *s2);
    char *my_strcpy(char *dest, char const *src);
    char *my_strncpy(char *dest, char const *src, int n);
    int my_strlen(char const *str);
    char *my_strupcase(char *str);
    char *my_strlowcase(char *str);
    void my_swap(int *a, int *b);
    char *my_strndup(char const *str, int n);
    char *my_strdup(char const *str);

/* CSFML */
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/Sound.h>
    #include <SFML/Audio/SoundBuffer.h>

    typedef struct object {
        sfTexture **pixel;
        int img;
        sfSprite *spr;
        int texture;
        sfVector2f pos;
        sfVector2u size;
    } object_t;

    typedef struct settings_s {
            object_t *play;
            object_t *high;
            object_t *low;
            object_t *back;
            sfTexture *bg;
            sfSprite *bg_spr;
            int leave;
    } settings_t;

    typedef struct tmp_s {
        int atk;
        int def;
        int money;
        int index;
        sfVector2f cell;
        int lily;
    } tmp_t;

    typedef struct opponent_s {
        int covid;
        int rondodu;
        int rondoudou;
        int jerome;
        int maxence;
        int pops;
        int wise;
    } opponent_t;

    typedef struct game_s {
        sfRenderWindow *window;
        int play_pause;
        float volum;
        int mouse;
        sfMusic *music;
        int error;
        object_t *pause;
        int talk;
        opponent_t adv;
        sfBool key;
        int wise;
        int intro;
        int save;
        tmp_t tmp;
    } game_t;

    void mouse_handling(game_t *game, sfEvent event);

    void make_redirection(game_t *game, object_t *object);

    void make_play_pause_redirection(game_t *game, settings_t *param);

    int check_mouse_on_button(object_t *object, sfVector2i mous, game_t *game);

    void change_sprite(object_t *object, int texture);

    void make_sprite(object_t *object, char *path);

    void destroy_sprite(object_t *object);

    void make_file_path(char *path, char *start, char *file);

    void make_object_texture(object_t *object, char *path);

    sfVector2f send_pos(int x, int y);

    void make_text(sfRenderWindow *window, char *str, sfVector2f pos, int siz);

    void set_pos(sfVector2f *pos, float x, float y);

    void gameloop(game_t *game);

    void destroy_game(game_t *game);

    int initialise_game(game_t *game);

    void assign_music(game_t *game, int number);

    char *int_to_str(int nb);

    void make_text_white(sfRenderWindow *w, char *s, sfVector2f p, int si);

    sfIntRect send_rect(int height, int width, int top, int left);

    void handle_end_game(game_t *game);
#endif
