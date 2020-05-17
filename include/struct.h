/*
** EPITECH PROJECT, 2020
** struct
** File description:
** struct
*/

#ifndef STRUCT_H_
#define STRUCT_H_

#include "op.h"

typedef enum type_s {
    IND,
    DIR,
    REG
} type_e;

// ##################### ASM STRUCT ################
typedef struct parse_s {
    char **table;
    int count;
    int j;
} parse_t;

typedef struct asm_s {
    char *name;
    char **file;
    int fd;
    int size;
    char *contents;
} asm_t;

typedef struct node_s {
    char *type;
    int line;
    char **arg;
    char *label;
    struct node_s *next;
    int used;
} node_t;

typedef struct link_s {
    node_t *head;
} link_t;


// ##################### COREWAR STRUCT ###################

typedef struct champ_s {
    header_t header;
    unsigned char *inst;
    int pc;
    char **arg;
    int basic_pc;
    int last_pc;
    int max_pc;
    int reg[16];
    int color;
    int cycle;
    int etat;
    int live;
} champ_t;

typedef struct nodev_s {
    int value;
    type_e type;
    struct nodev_s *next;
} nodev_t;

typedef struct linkv_s {
    nodev_t *head;
} linkv_t;

typedef struct cor_s {
    champ_t *champ;
    char *map;
    int nb_champ;
    int draw;
    char *txt;
    int nbr_live;
    int cycle_delta;
    int cycle_die;
    int carry;
} cor_t;

typedef struct info_s {
    int tmp;
    char *str;
} info_t;

typedef struct array_s {
    char *mnemonique;
    int cycle;
    void (*ft)(cor_t *, champ_t *, linkv_t *);
} array_t;

typedef struct ar_s {
    char *mnemo;
    int cycle;
    void (*ft)(cor_t *, champ_t *champ);
} ar_t;

#endif /* !STRUCT_H_ */
