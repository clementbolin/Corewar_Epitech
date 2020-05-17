/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** corewar
*/

#ifndef COREWAR_H_
#define COREWAR_H_

#include "op.h"
#include "my.h"
#include "define.h"
#include "struct.h"
#include "bonus.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <curses.h>
#include <ncurses.h>

int bonus_flag(char **av);
char *my_itoa(int nb, char *str);
char *dec_to_hex(int decimalnum);

// ################## BINRAY FILE #############

int open_file_champ(char const *path);
void recup_header_champ(champ_t *champ, char *path);
void recup_instruction_champ(champ_t *champ, char *path);
champ_t *init_champion(char **av);
void init_arena(cor_t *cor, char **av);
int nb_champ(char **av);
void init_color_map(void);
void init_map_color(cor_t *vm);
void init_register_champ(champ_t *champ, int id);

// ###################### DISPLYAY ################

void display_pc_player(cor_t *vm);
int change_value_cycle(cor_t *vm);

// #################### PC #######################
char *my_itc(int nbr);
void recup_inst_pc(cor_t *vm);
int check_special_val(char *mnemonique);
int increase_pc(char *str, char *mnemonique);
void manage_instruction(cor_t *vm, champ_t *champ, char *cdg_bin, char *mnemo);
int recup_value_one_arg(char *arena, int pc, int size);
char *return_cdg_bin(int cdg_byte);
int special_value(int i, cor_t *vm, champ_t *champ);

// #################### LINK ####################

nodev_t *create_node_inst(int value, type_e type);
void add_node_inst(int value, type_e type, linkv_t *link);
void display_link_instruction(linkv_t *link);
linkv_t *init_list_inst(void);
void delete_node_inst(int size, linkv_t *link);
void destroy_link_inst(linkv_t *link);

// ################### INSTRUNCTION ################

int fill_value_link(info_t info, linkv_t *link, char *mnemo, cor_t *vm);
int recup_value_reg(champ_t *champ, int id);
void write_color_in_map(champ_t *champ, cor_t *vm, int id);
char *binary_to_hex(char *str);

// ################### INST FUNCTION ##################

void ld(cor_t *vm, champ_t *champ, linkv_t *link);
void lld(cor_t *vm UNUSED, champ_t *champ, linkv_t *link);
void st(cor_t *vm, champ_t *champ, linkv_t *link);
void add(cor_t *vm, champ_t *champ, linkv_t *link);
void sub(cor_t *vm, champ_t *champ, linkv_t *link);
void live(cor_t *vm UNUSED, champ_t *champ);
void sti(cor_t *vm, champ_t *champ, linkv_t *link);
void or(UNUSED cor_t *vm, UNUSED champ_t *champ, linkv_t *link);
void xor(cor_t *vm UNUSED, champ_t *champ, linkv_t *link);
void ldi(UNUSED cor_t *vm, UNUSED champ_t *champ, UNUSED linkv_t *link);

#endif /* !COREWAR_H_ */
