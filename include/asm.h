/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** asm
*/

#ifndef ASM_H_
#define ASM_H_

#include "op.h"
#include "my.h"
#include "struct.h"
#include "define.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

// ############## INIT ##################
int create_file(char const *path);
int init_champ(char *path, asm_t *champ UNUSED);
int main_init(char *av, asm_t *champ, link_t *link);

// ############## TOOL ##################

int tab_len(char **tab);
char *cpy_name_file(char *str);
void name_file_cor(char *name);
void consolog(int etat);
char *binary_to_hex(char *str);
int	convert_littleend_to_bigend_int(int nb);
int little_to_big_short(int var);

// ######################### ERROR MANAGE ###########

int check_valid_command_header(asm_t *file, link_t *link);
void error_code(int error, int line, char *name);
void check_label(asm_t *file);
int check_arg_type(char *str);

// ######################## BINARY #################

void write_header(asm_t *file, link_t *link);
char *value_str_header(char *str, int size);
void write_binary(asm_t *file, link_t *link);
void write_prog_size(asm_t *file, link_t *link);
void write_reg_arg(node_t *node, asm_t *file, int i, int offset);
void write_dir_arg(node_t *node, asm_t *file, int i, int offset);
void write_ind_arg(node_t *node, asm_t *file, int i, int offset);
int check_arg_type_one(char *arg);
int check_arg_type_two(char *str);

// ####################### LINK INST ###############

link_t *init_link(void);
void delete_node(int size, link_t *link);
void destroy_link(link_t *link);
node_t *create_node(char *str, int line, int b);
void add_node(link_t *link, int line, char *str, int b);
void display_link_inst(link_t *link);
void create_link_inst(asm_t *file, link_t *link UNUSED);

// ####################### PARSER #################

char **return_tab_arg(char *str);
char *return_type_command(char *str);
char *clean_string(char *str);
char **clean_array(char **arr);
int my_strcmp_mod_two(char *str, char *str2, char c);
int my_strcmp_dot(char *str, char *str2);
int is_label(char *str);
char *get_label(char *str);
char *get_args(char *str);
char *get_type(char *str);
void put_header_node(char *str, link_t *link, char *type, char *label);
node_t *put_header_node_two(char *str, char *type, char *label);
char *only_get_name(char *str);
char *get_args(char *str);
int check_pre_label(link_t *link);
int check_arg_type_two(char *str);
int check_arg_type_one(char *arg);
int recup_value_ind(char *arg);
int recup_value_str(char *arg);
int check_arg_type(char *str);
int	convert_littleend_to_bigend_int(int nb);
int get_string_size_three(link_t *link UNUSED, char *str);
int get_string_size(node_t *temp, link_t *link UNUSED);
int check_node(node_t *temp, node_t *node);
void write_code_type(node_t *node, asm_t *file);
char *check_type_arg(char **arg);
int get_string_size_three(link_t *link UNUSED, char *str);
int get_string_size(node_t *temp, link_t *link UNUSED);
int check_node(node_t *temp, node_t *node);
void write_code_type(node_t *node, asm_t *file);
char *check_type_arg(char **arg);

#endif /* !ASM_H_ */