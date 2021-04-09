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
    for(unsigned char i = 0; i < 52; i++) {
        const unsigned char SUIT = ceil(i / 13);
        cards[i].color = (SUIT == CLUBS || SUIT == SPADES) ? BLACK : RED;
        cards[i].value = i - (13 * SUIT);
        cards[i].suit  = SUIT;
    }
    return cards;
}

#endif // CARD_H_INCLUDED
