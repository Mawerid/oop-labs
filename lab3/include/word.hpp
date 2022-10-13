#ifndef WORD_HPP
#define WORD_HPP

#include <iostream>
#include <memory>

#define LAB_VERSION "1.0.0"
#define VARIANT 5

namespace word
{
    class words
    {
    public:
        //  our constants, that we need
        static const unsigned MAX_WORD_LEN = 25;
        static const unsigned MAX_WORD_COUNT = 10;

    private:
        //  current lengh of massive
        unsigned int count = 0;
        //  our massive
        char mass[MAX_WORD_COUNT][MAX_WORD_LEN];

    public:
        //  constructors
        explicit words();
        explicit words(const char *word);
        explicit words(const unsigned &count_s, const char **mass_s);
        words(const words &mass_cp);

        //  getters
        unsigned get_count() const;
        char *get_word(const unsigned &num) const;

        //  add a word, len must be no greater than MAX_WORD_LEN
        int add(const char *word);
        void clear();
        int del(const unsigned &num);
        unsigned search(const char *word) const;
        words *first_symbol(const char &symbol) const;
        void sort();
        //  swap two words
        void swap(char *word1, char *word2);
        //  input and output
        std::ostream &print(std::ostream &cout) const;
        std::istream &input(std::istream &cin);

        //  overloaded operators
        //  decrement
        words &operator--();
        const words operator--(int);
        //  by indexes
        char *operator[](size_t index);
        const char *operator[](size_t index) const;
        //  пустой не пустой !
        bool operator!() const;

        //  cin and cout
        friend std::ostream &operator<<(std::ostream &cout, const words &mass);
        //  std::ostream &operator<<(std::ostream &cout) const;
        friend std::istream &operator>>(std::istream &cin, words &mass);
        //  add masses to masses
        words &operator+=(const words &mass_cp);

        //  sum of two
        const words operator+(const words &mass_add) const;
        //  compare
        std::strong_ordering operator<=>(const words &mass_check) const;
    };
}

#endif
