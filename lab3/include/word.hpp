#include <iostream>
#ifndef WORD_HPP
#define WORD_HPP

#define LAB_VERSION "1.0.0"
#define VARIANT 5

namespace word
{
    class words
    {
    private:
        static const unsigned MAX_WORD_LEN = 25;
        static const unsigned MAX_WORD_COUNT = 10;
        unsigned count = 0;
        char mass[MAX_WORD_COUNT][MAX_WORD_LEN];

    public:
        explicit words();
        explicit words(const char *word);
        explicit words(const unsigned &count_s, const char **mass_s);

        unsigned get_count();
        char *get_word(const unsigned &num);

        int add(const char *word);
        void clear();
        int del(const unsigned &num);
        unsigned search(const char *word);
        words *first_symbol(const char &symbol);
        void sort();
        void swap(char *word1, char *word2);
        std::ostream &print(std::ostream &cout);
        std::istream &input(std::istream &cin);
    };
}

#endif
