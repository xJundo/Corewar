/*
** EPITECH PROJECT, 2023
** bite
** File description:
** bite
*/

#ifndef _OP_H_
    #define _OP_H_

    #include "my.h"
    #include "mylist.h"
    #include "ncurses.h"

    #define MEM_SIZE (6 * 1024)
    #define IDX_MOD 512 /* modulo of the index < */
    #define MAX_ARGS_NUMBER 4 /* this may not be changed 2^*IND_SIZE */

    #define COMMENT_CHAR '#'
    #define LABEL_CHAR ':'
    #define DIRECT_CHAR '%'
    #define SEPARATOR_CHAR ','
    #define LABEL_CHARS "abcdefghijklmnopqrstuvwxyz_0123456789"

    #define NAME_CMD_STRING ".name"
    #define COMMENT_CMD_STRING ".comment"

/*
** regs
*/
    #define REG_NUMBER 16 /* r1 <--> rx */

/*
**
*/
typedef char args_type_t;

    #define T_REG 1 /* register */
    #define T_DIR 4 /* direct  (ld  #1,r1  put 1 into r1) */
    #define T_IND 2
    /* indirect always relative
     * (ld 1,r1 put what's in the address (1+pc) into r1 (4 bytes )) */
    #define T_LAB 8 /* LABEL */

/*
** size (in bytes)
*/
    #define IND_SIZE 2
    #define DIR_SIZE 4
    #define REG_SIZE DIR_SIZE



/*
** header
*/
    #define PROG_NAME_LENGTH 128
    #define COMMENT_LENGTH 2048
    #define COREWAR_EXEC_MAGIC 0xea83f3

typedef struct header_s {
    int magic;
    char prog_name[PROG_NAME_LENGTH + 1];
    int prog_size;
    char comment[COMMENT_LENGTH + 1];
} header_t;

/*
** live
*/
    #define CYCLE_TO_DIE 1536 /* number of cycle before beig declared dead */
    #define CYCLE_DELTA 5
    #define NBR_LIVE 40

typedef struct champion_s {
    struct champion_s *parent;
    header_t *header;
    char *prog;
    int prog_number;
    int address;

    int pc;
    int reg[REG_NUMBER];
    int carry;

    int cooldown;
    int live;
    int color;
    int line;
} champion_t;

typedef struct {
    char *dump;
    char *prog_number;
    char *load_address;
} args_t;

enum exit_status {
    SUCCESS,
    FAILURE,
    CONTINUE,
};

typedef struct map_s {
    int line;
    int col;
    int color;
    int cursor;
} map_t;

typedef struct {
    int dump_nb;
    nodes_t *progs_ids;
    nodes_t *addresses;

    int total_cycle;
    unsigned char arena[MEM_SIZE];
    int reg[REG_NUMBER];
    nodes_t *champions;
    map_t map[MEM_SIZE];
    char input;
    int x;
    int y;

    int total_live;
    int nbr_live;
    int speed;
} vm_t;

typedef struct op_s {
    char *mnemonique;
    char nbr_args;
    args_type_t type[MAX_ARGS_NUMBER];
    char code;
    int nbr_cycles;
    char *comment;
    int (*instructions)(champion_t *champion);
} op_t;


/*
** op_tab
*/
extern op_t op_tab[];

vm_t *get_vm(void);

/**
 * @brief Parse the arguments
 *
 * @param int ac
 *  The number of arguments
 *  @param char **av
 *  The arguments
 * @return int
 */
int parse_args(int, char **);
/**
 * @brief Parse the flag
 *
 * @param char **av
 *  The arguments
 * @param int ac
 *  The number of arguments
 * @param int *i
 *  The index of the argument
 * @param args_t *args
 *  The current informations about dump, prog_number and load_address
 * @return int
 */
int parse_flag(char **av, int ac, int *i, args_t *args);

/**
 * @brief Parse the file
 *
 * @param char *file
 *  The file to parse
 * @param args_t *args
 *  The current informations about dump, prog_number and load_address
 * @return int
 */
int parse_file(char *, args_t *);

/**
 * @brief Check if the string is composed by another string
 *
 * @param char *str
 *  The string to check
 * @param char *str2
 *  The string to check with
 * @return int
 */
int my_str_is_composed_by(char *str, char *str2);

/**
 * @brief Get the first id
 * @description The first available id for a champion (starting at 1)
 * @return int
 *
 */
int get_first_id(void);

/**
 * @brief Place the champions
 * @description Place the champions in the arena
 * @return int
 *
 */
int place_champions(void);


//FLAGS
/**
 * @brief Parse the dump flag, set the dump value
 *
 * @param char **av
 *  The arguments
 * @param int ac
 *  The number of arguments
 * @param int *i
 *  The index of the argument
 * @param args_t *args
 *  The current informations about dump, prog_number and load_address
 * @return int
 */
int flag_dump(char **av, int ac, int *i, args_t *args);

/**
 * @brief Parse the n flag, set the prog_number value
 *
 * @param char **av
 *  The arguments
 * @param int ac
 *  The number of arguments
 * @param int *i
 *  The index of the argument
 * @param args_t *args
 *  The current informations about dump, prog_number and load_address
 * @return int
 */
int flag_n_id(char **av, int ac, int *i, args_t *args);

/**
 * @brief Parse the a flag, set the load_address value
 *
 * @param char **av
 *  The arguments
 * @param int ac
 *  The number of arguments
 * @param int *i
 *  The index of the argument
 * @param args_t *args
 *  The current informations about dump, prog_number and load_address
 * @return int
 */
int flag_add(char **av, int ac, int *i, args_t *args);

//MAIN LOOP

/**
 * @brief The main loop
 * @description The main loop of the program, depending on the cycle_to_die,
 * the champions will play their instructions
 * @return int
 *
 */
int main_loop(void);
void do_instruction(champion_t *champion, int nb_cycle);

//COMMANDS

/**
 * @brief Check if the register is valid
 * @description Check if the register is valid (between 1 and 16)
 * @param int reg
 * The register to check
 * @return int
 */
int reg_is_valid(int reg);

/**
 * @brief Get the byte to read
 * @description Get the nb_byte to read depending on the type of parameter
 * @param int type_param
 * The type of parameter
 * @param int exception
 * Instruction can be exception and need to read 2 bytes instead of 4
 * @return int
 */
int get_byte_to_read(int type_param, int exception);

/**
 * @brief Get the value
 * @description Get the value of the parameter swaped in endian
 * @param int byte
 * The nb_byte to read
 * @param int start
 * The byte to start
 * @return int
 */
int get_value(int byte, int start);

/**
 * @brief Set the value
 * @description Set the value in the arena
 * @param int value
 * The value to set
 * @param int nb_byte
 * The nb_byte to set
 * @param int start
 * The byte to start
 * @return int
 */
int set_value(int value, int nb_byte, int start);


/**
 * @brief Live instruction
 * @description The instruction live
 * @param champion_t *champion
 * The champion
 * @return int
 */
int live(champion_t *champion);

/**
 * @brief Load instruction
 * @description
 * takes 2 parameters. It loads the value of the first parameter into
 * the secondparameter, which must be a register (not the PC).This operation
 * modifies the carry.ld 34, r3loads theREG_SIZEbytes starting at the
 * addressPC + 34 % IDX_MODintor3.0x03
 * @param champion_t *champion
 * The champion
 * @return int
 */
int my_ld(champion_t *champion);

/**
 * @brief Store instruction
 * @description
 * takes 2 parameters and a registry. It stores the value of the first
 * parameter in the registry. The first parameter can be either a register
 * or a direct value.0x03
 * @param champion_t *champion
 * The champion
 * @return int
 */
int my_st(champion_t *champion);
int add(champion_t *champion);
int sub(champion_t *champion);
int my_and(champion_t *champion);
int my_or(champion_t *champion);
int my_xor(champion_t *champion);
int zjmp(champion_t *champion);
int ldi(champion_t *champion);
int sti(champion_t *champion);
int my_fork(champion_t *champion);
int lld(champion_t *champion);
int lldi(champion_t *champion);
int lfork(champion_t *champion);
int aff(champion_t *champion);

int corewar(int ac, char **av);

//BONUS
void init_color_arena(void);
void print_color_arena(void);
int print_color_cursor(int index, int color, int cursor);
int print_color_cursor_to_value(int start, int end, int color, int cursor);
void sort_list_champions(void);
int recalcule_screen_size(void);

    #define BTR(x, y) get_byte_to_read(x, y)

#endif /* OP_H_ */
