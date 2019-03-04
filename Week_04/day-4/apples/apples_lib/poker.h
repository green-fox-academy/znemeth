//
// Created by NEMETH on 2019.03.04..
//

#ifndef APPLES_POKER_H
#define APPLES_POKER_H

typedef struct
{
    char *card[3];

} card_t;

int get_cardValue(char *card)
{
    if (card[0] == 'T') {
        return 10;
    } else if (card[0] == 'J') {
        return 11;
    } else if (card[0] == 'Q') {
        return 12;
    } else if (card[0] == 'K') {
        return 13;
    } else if (card[0] == 'A') {
        return 14;
    }
    return atoi(&card[0]);
}

char get_cardColor(char *card)
{
    return card[1];
}

#endif //APPLES_POKER_H