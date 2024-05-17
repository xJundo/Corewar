/*
** EPITECH PROJECT, 2023
** Libmy
** File description:
** Store libmy functions prototypes
*/


#ifndef CSFML_H
    #define CSFML_H

    #define TEXTURE NULL

    #include <SFML/Graphics.h>
    #include <SFML/System.h>
    #include <SFML/Audio.h>
    #include <stdbool.h>
    #include <malloc.h>
    #include <stdlib.h>
    #include <time.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <math.h>
    #include <stdarg.h>
    #include "mylist.h"
    #include "my.h"

typedef enum {
    INTRO,
    MENU,
    MAIN,
    PAUSE,
    SETTINGS,
    EXIT,
}scene_e_t;

typedef enum {
    PLAYER,
    ENEMY,
    NPC,
    OBJECT,
    DECOR,
} entity_type_e_t;

typedef struct {
    sfSprite *sprite;
    sfVector2f origin;
    sfVector2f position;
    sfVector2f scale;
    sfIntRect rect;
    sfIntRect initial_rect;
    sfClock *clock;
    void *hitbox;

    entity_type_e_t type;
    void *entity_struct;
    char *id;
    int *offset_rect;
} entity_t;

typedef struct {
    sfVideoMode video_mode;
    sfRenderWindow *window;
    sfView *view;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2i mouse_pos;
    sfVector2i old_mouse_pos;
    sfClock *clock;
    sfEvent event;

    int size;
    float delay;
    int framerate;
} window_info_t;

typedef struct variables {
    int standby;
    int show_hitbox;
} user_variables_t;


typedef struct {
    window_info_t *window_i;
    user_variables_t *user_variables;
    sfTexture *main_texture;

    int old_state;
    int cur_state;

    nodes_t *entities_list;
    entity_t *player;
} game_info_t;

////////////////// INIT
game_info_t *get_game(void);
entity_t *get_player_entity(void);
window_info_t *get_window(void);
user_variables_t *get_user(void);
entity_t *get_entity(char *id);
void *init_game(void);


/**
 * @brief Create a text object
 * @param nb Number of arguments
 * @param  ... Arguments : <br>
 * 1st <b>char *</b> : String <br>
 * 2nd <b>sfFont *</b> : Font <br>
 * 3rd <b>int</b> : CharacterSize <br>
 * 4th <b>sfColor</b> : Color <br>
 * 5th <b>sfVector2f</b> : Position <br>
 * 6th <b>sfVector2f</b> : Scale <br>
 * @return <b>sfText*</b>
*/
sfText *create_text(int nb, ...);


/**
 * @brief Create a sprite object
 *
 * @param nb
 * @param ...
 *  1st : <b>sfTexture *</b> : texture <br>
 * 2nd : <b>sfIntRect</b> : texture rect <br>
 * 3rd : <b>sfVector2f</b> : position <br>
 * 4th : <b>sfVector2f</b> : origin <br>
 * 5th : <b>sfVector2f</b> : scale <br>
 * @return sfSprite*
 */
sfSprite *create_sprite(int nb, ...);


/**
 * @brief Create a rectangle object
 *
 * @param nb
 * @param ... Arguments : <br>
 * 1st <b>sfVector2f</b> : Size <br>
 * 2nd <b>sfVector2f</b> : Position <br>
 * 3rd <b>sfVector2f</b> : Origin <br>
 * 4th <b>sfVector2f</b> : Scale <br>
 * 5th <b>sfColor</b> : FillColor <br>
 * 6th <b>sfColor</b> : OutlineColor <br>
 * 7th <b>float</b> : OutlineThickness <br>
 * @return sfRectangleShape*
 */
sfRectangleShape *create_rectangle(int nb, ...);


/**
 * @brief Create an entity object
 *
 * @param nb
 * @param ... <br>
 * 1st : <b>entity_type_e</b> : entity_type <br>
 * 2nd : <b>char *</b> : id <br>
 * 3rd : <b>sfSprite *</b> : sprite <br>
 * 4th : <b>void *</b> : entity_struct / action for entity <br>
 * 5th : <b>void *</b> : hitbox <br>
 * @return <b>entity_t*<b>
 */
entity_t *create_entity(int nb, ...);

////////////////////////////////////////////////////////////


#endif //CSFML_H
