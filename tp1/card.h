#ifndef CARD_H_INCLUDED
#define CARD_H_INCLUDED

enum color {
    RED, BLACK
};
enum suit {
    CLUBS, DIAMONDS, HEARTS, SPADES
};
enum value {
    ACE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING
};


struct Card {
    unsigned char color:2, suit:3, value:4;
};


Card * initCards() {
    Card * cards = new Card[52];
    for(char i = 0; i < 52; i++) {
        if(i <= 12) {
            cards[i].color = BLACK;
            cards[i].value = i;
        } else if(i > 12 && i <= 25) {
            cards[i].color = RED;
            cards[i].value = i - 13;
        } else if(i > 25 && i <= 38) {
            cards[i].color = RED;
            cards[i].value = i - (13 * 2);
        } else if(i > 38 && i <= 51) {
            cards[i].color = BLACK;
            cards[i].value = i - (13 * 3);
        }
        cards[i].suit  = ceil(i / 13);
    }
    return cards;
}




#endif // CARD_H_INCLUDED
