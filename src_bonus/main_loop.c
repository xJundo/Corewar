/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

static void reset_live(void)
{
    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next)
        ((champion_t *)tmp->data)->live = 0;
}

static void check_alive(void)
{
    champion_t *champion = NULL;

    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
        champion = tmp->data;
        if (champion->live == 0) {
            previous_to_next(&get_vm()->champions, tmp);
            clear();
        }
    }
}

static void suite_color(void)
{
    start_color();
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_YELLOW, COLOR_BLACK);
    init_pair(4, COLOR_BLUE, COLOR_BLACK);
    init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
}

static void init_screen(void)
{
    int x = 0;
    int y = 0;

    initscr();
    refresh();
    curs_set(0);
    scrollok(stdscr, TRUE);
    keypad(stdscr, TRUE);
    noecho();
    nodelay(stdscr, TRUE);
    while (1) {
        getmaxyx(stdscr, y, x);
        if (x > 40 && y > 20)
            break;
        clear();
        mvprintw(y / 2, x / 2 - 10, "Please resize the terminal");
        printw("  : %d x %d", x, y);
        refresh();
    }
    suite_color();
}

static int analyse_input(void)
{
    int ch = getch();

    if (ch == ERR)
        return 0;
    if (ch == ' ')
        while (getch() != ' ');
    if (ch == KEY_RIGHT)
        get_vm()->speed += 100;
    if (ch == KEY_LEFT)
        if (get_vm()->speed > 1)
            get_vm()->speed -= 100;
    return 0;
}

int reste_one_color(void)
{
    int color = 0;
    int count = 0;

    for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
        if (color == 0)
            color = ((champion_t *)tmp->data)->color;
        if (color != ((champion_t *)tmp->data)->color)
            return 0;
        count++;
    }
    return count == 1 ? 1 : 0;
}

int end(void)
{
    clear();
    if (reste_one_color())
        mvprintw(0, 0, "The player %d(%s) has won.\n",
        ((champion_t *)get_vm()->champions->data)->prog_number,
        ((champion_t *)get_vm()->champions->data)->header->prog_name);
    else
        mvprintw(0, 0, "No winner");
    refresh();
    usleep(2000000);
    endwin();
    curs_set(1);
}

int refresh_live(int *i)
{
    if (get_vm()->total_live >= get_vm()->nbr_live) {
        *i -= CYCLE_DELTA;
        get_vm()->total_live = 0;
        get_vm()->nbr_live -= get_vm()->nbr_live > 10 ? CYCLE_DELTA : 0;
        clear();
    }
}

int loop_prog(int *i)
{
    int nb_cycle = 0;

    while (nb_cycle < *i) {
        refresh();
        refresh_live(i);
        for (nodes_t *tmp = get_vm()->champions; tmp; tmp = tmp->next) {
            mvprintw(0, 0, "CYCLE_TO_DIE : %d / %d", nb_cycle, *i);
            recalcule_screen_size();
            print_color_arena();
            do_instruction(tmp->data, nb_cycle);
            analyse_input();
        }
        (nb_cycle)++;
        get_vm()->total_cycle++;
    }
}

int main_loop(void)
{
    init_screen();
    init_color_arena();
    for (int i = CYCLE_TO_DIE; i > 0; i -= CYCLE_DELTA) {
        if (reste_one_color())
            break;
        sort_list_champions();
        loop_prog(&i);
        check_alive();
        reset_live();
    }
    end();
    return 0;
}
