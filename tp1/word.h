#ifndef WORD_H_INCLUDED
#define WORD_H_INCLUDED

union word {
    unsigned int data;
    struct {
        unsigned int b0:8, b1:8, b2:8, b3:8;
    };
};

#endif // WORD_H_INCLUDED
