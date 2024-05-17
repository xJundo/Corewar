/*
** EPITECH PROJECT, 2023
** main
** File description:
** main
*/

#include "op.h"

int convert_endian(int number)
{
    int byte0 = (number & 0x000000FF) >> 0;
    int byte1 = (number & 0x0000FF00) >> 8;
    int byte2 = (number & 0x00FF0000) >> 16;
    int byte3 = (number & 0xFF000000) >> 24;

    return ((byte0 << 24) | (byte1 << 16) | (byte2 << 8) | (byte3 << 0));
}

static int reset_args(args_t *args)
{
    if (args->dump)
        args->dump = NULL;
    if (args->prog_number)
        args->prog_number = NULL;
    if (args->load_address)
        args->load_address = NULL;
    return 0;
}

static int fill_champ(champion_t *champion,
    int fd, struct stat *s, args_t *args)
{
    read(fd, champion->header, sizeof(header_t));
    champion->header->prog_size = convert_endian(champion->header->prog_size);
    champion->header->magic = convert_endian(champion->header->magic);
    if (champion->header->magic != COREWAR_EXEC_MAGIC) {
        my_printf(2, "Invalid magic number.\n");
        return FAILURE;
    }
    if ((int)(s->st_size - sizeof(header_t)) != champion->header->prog_size) {
        my_printf(2, "Invalid program size.\n");
        return FAILURE;
    }
    champion->prog = MALLOC(champion->header->prog_size);
    read(fd, champion->prog, champion->header->prog_size);
    push_b_doubly(&get_vm()->champions, champion, UNKNOW);
    return 0;
}

int read_file(int fd, struct stat *s, args_t *args)
{
    static int color = 1;
    champion_t *champion = MALLOC(sizeof(champion_t));

    champion->header = MALLOC(sizeof(header_t));
    champion->prog_number = args->prog_number
    ? my_getnbr(args->prog_number) : get_first_id();
    champion->address =
    args->load_address ? my_getnbr(args->load_address) : -1;
    champion->reg[0] = champion->prog_number;
    champion->carry = -1;
    champion->cooldown = 0;
    champion->parent = NULL;
    champion->color = color;
    champion->live = 0;
    color++;
    if (fill_champ(champion, fd, s, args))
        return FAILURE;
    return 0;
}

int parse_file(char *file, args_t *args)
{
    static int champion_nb = 0;
    int fd = 0;
    struct stat s = {0};

    if (champion_nb >= 4) {
        my_printf(2, "Too many champions.\n");
        return FAILURE;
    }
    fd = open(file, O_RDONLY);
    if (fd == -1 || stat(file, &s) == -1) {
        my_printf(2, "Can't read source file %s\n", file);
        return FAILURE;
    }
    read_file(fd, &s, args);
    champion_nb++;
    reset_args(args);
    return SUCCESS;
}
