/*
** EPITECH PROJECT, 2020
** CPE_corewar_2019
** File description:
** define
*/

#ifndef DEFINE_H_
#define DEFINE_H_

#define UNUSED __attribute__((unused))

#define INSTRUCTION_ER 80
#define COMMENT_ER 81
#define SWAP_INT_TO_WRITE(x) ((x >> 24)&0xff) | ((x << 8)&0xff0000) | \
((x >> 8)&0xff00) | ((x << 24)&0xff000000)

#define PLAYER1 1
#define PLAYER2 2
#define PLAYER3 3
#define PLAYER4 4

#define PC1 5
#define PC2 6
#define PC3 7
#define PC4 8

#endif /* !DEFINE_H_ */
