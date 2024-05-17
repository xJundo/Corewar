/*
** EPITECH PROJECT, 2023
** op.c
** File description:
** op.c
*/

#include "op.h"

static int suite_value(int byte, int start)
{
    int value = 0;

    if (byte == 2) {
        value = ((int)get_vm()->arena[start]) << 8
        | ((int)get_vm()->arena[(start + 1) % MEM_SIZE]);
        if (value & 0x8000)
            value = value | 0xFFFF0000;
    }
    if (byte == 1) {
        value = (int)get_vm()->arena[start];
        if (value & 0x80)
            value = value | 0xFFFFFF00;
    }
    return value;
}

int get_value(int byte, int start)
{
    int value = 0;

    if (byte == 4) {
        value = (((int)get_vm()->arena[start]) << 24 & 0xFF000000)
        | ((int)(get_vm()->arena[(start + 1) % MEM_SIZE]) << 16 & 0xFF0000)
        | ((int)(get_vm()->arena[(start + 2) % MEM_SIZE]) << 8 & 0xFF00)
        | ((int)(get_vm()->arena[(start + 3) % MEM_SIZE]) & 0xFF);
        if (value & 0x80000000)
            value = value | 0xFFFFFFF;
    } else
        value = suite_value(byte, start);
    return value;
}

int reg_is_valid(int reg)
{
    return reg >= 1 && reg <= REG_NUMBER;
}

int set_value(int value, int nb_byte, int start)
{
    if (nb_byte == 4) {
        get_vm()->arena[start] = value >> 24;
        get_vm()->arena[(start + 1) % MEM_SIZE] = value >> 16;
        get_vm()->arena[(start + 2) % MEM_SIZE] = value >> 8;
        get_vm()->arena[(start + 3) % MEM_SIZE] = value;
    } else if (nb_byte == 2) {
        get_vm()->arena[start] = value >> 8;
        get_vm()->arena[(start + 1) % MEM_SIZE] = value;
    } else {
        get_vm()->arena[start] = value;
    }
}

int get_byte_to_read(int type_param, int exception)
{
        if (type_param == 1)
            return 1;
        if (type_param == 2)
            return exception ? 2 : 4;
        if (type_param == 3)
            return 2;
}

void do_instruction(champion_t *champion, int nb_cycle)
{
    int code = get_vm()->arena[champion->pc % MEM_SIZE];

    if (code < 1 || code > 16) {
        champion->pc += 1;
        champion->pc %= MEM_SIZE;
        return;
    }
    if (champion->cooldown == 0) {
        if (op_tab[code - 1].instructions(champion)) {
            champion->cooldown = 0;
            champion->pc = (champion->pc + 1) % MEM_SIZE;
        } else
            champion->cooldown = op_tab[code - 1].nbr_cycles;
    } else
        champion->cooldown--;
}
