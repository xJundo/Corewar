/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"
#include "ncurses.h"

static void suite_suite(int col, int line)
{
    int values_per_line;

    mvprintw(0, 30, "NBR_LIVE : %d / %d",
    get_vm()->total_live, get_vm()->nbr_live);
    mvprintw(0, 60, "Press [SPACE] to pause");
    mvprintw(1, 60, "Press [KEY_RIGHT] to speed up");
    mvprintw(2, 60, "Press [KEY_LEFT] to speed down");
    values_per_line = get_vm()->x / 3;
    for (int j = 0; j < MEM_SIZE; j++) {
        if (col >= values_per_line * 3) {
            col = 0;
            line++;
        }
        get_vm()->map[j].col = col;
        get_vm()->map[j].line = line;
        col += 3;
    }
}

int recalcule_screen_size(void)
{
    int x = 0;
    int y = 0;
    int col = 0;
    int line = 8;
    int values_per_line;

    getmaxyx(stdscr, y, x);
    suite_suite(col, line);
    if (x != get_vm()->x || y != get_vm()->y) {
        clear();
        get_vm()->x = x;
        get_vm()->y = y;
    } else
        return 0;
    suite_suite(col, line);
    return 0;
}

int print_color_cursor(int index, int color, int cursor)
{
    index = index % MEM_SIZE;
    attron(COLOR_PAIR(color));
    if (cursor)
        attron(A_REVERSE);
    mvprintw(get_vm()->map[index].line,
    get_vm()->map[index].col, "%02x", get_vm()->arena[index]);
    refresh();
    usleep(200000 / (get_vm()->speed));
    if (cursor)
        attroff(A_REVERSE);
    mvprintw(get_vm()->map[index].line,
    get_vm()->map[index].col, "%02x", get_vm()->arena[index]);
    get_vm()->map[index].color = color;
    get_vm()->map[index].cursor = 0;
    attroff(COLOR_PAIR(color));
    return 0;
}

int print_color_cursor_to_value(int start, int end, int color, int cursor)
{
    attron(COLOR_PAIR(color));
    while (start <= end) {
        print_color_cursor(start, color, cursor);
        start++;
    }
    attroff(COLOR_PAIR(color));
    return 0;
}

static void print_champions_status(void)
{
    champion_t *champion = NULL;
    int line = 3;

    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
        champion = tmp->data;
        if (champion->parent != NULL)
            continue;
        attron(COLOR_PAIR(champion->color));
        mvprintw(line, 0, "Champion %d: %s : %d",
        champion->prog_number, champion->header->prog_name,
        champion->live);
        mvprintw(line, 50, "reg = [%d, %d, %d, %d, %d, %d, %d, %d, %d, %d, %d,"
            " %d, %d, %d, %d, %d]", champion->reg[0], champion->reg[1],
        champion->reg[2], champion->reg[3], champion->reg[4], champion->reg[5],
        champion->reg[6], champion->reg[7], champion->reg[8], champion->reg[9],
        champion->reg[10], champion->reg[11], champion->reg[12],
        champion->reg[13], champion->reg[14], champion->reg[15]);
        attroff(COLOR_PAIR(champion->color));
        line++;
    }
}

void print_color_arena(void)
{
    print_champions_status();
    for (int i = 0; i < MEM_SIZE; i++) {
        attron(COLOR_PAIR(get_vm()->map[i].color));
        if (get_vm()->map[i].cursor == 1)
            attron(A_REVERSE);
        mvprintw(get_vm()->map[i].line,
        get_vm()->map[i].col, "%02x", get_vm()->arena[i]);
        attroff(COLOR_PAIR(get_vm()->map[i].color));
        if (get_vm()->map[i].cursor == 1)
            attroff(A_REVERSE);
    }
}

void init_color_arena(void)
{
    int col = 0;
    int line = 8;
    int values_per_line;

    getmaxyx(stdscr, get_vm()->y, get_vm()->x);
    clear();
    values_per_line = get_vm()->x / 3;
    for (int j = 0; j < MEM_SIZE; j++) {
        if (col >= values_per_line * 3) {
            col = 0;
            line++;
        }
        get_vm()->map[j].col = col;
        get_vm()->map[j].line = line;
        get_vm()->map[j].color = 0;
        get_vm()->map[j].cursor = 0;
        col += 3;
    }
}
