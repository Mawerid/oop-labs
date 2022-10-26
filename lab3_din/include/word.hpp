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
    private:
        //  current lengh of massive
        size_t size = 0;
        //  quote of memory in massive
        static const size_t QUOTE = 5;
        //  current filled lengh of massive
        size_t curr_size = 0;
        //  our massive
        char **mass;

    public:
        //  constructors

        /// @brief empty constructor
        explicit words();

        /// @brief constructor with first word
        /// @param word
        explicit words(const char *word);

        /// @brief constructor with massive of words
        /// @param count_s
        /// @param mass_s
        explicit words(const size_t &count_s, const char **mass_s);

        /// @brief copy constructor
        /// @param mass_cp
        words(const words &mass_cp);

        /// @brief move constructor
        /// @param mass_mv
        words(words &&mass_mv);

        /// @brief destructor
        ~words();

        //  getters

        /// @brief get current size of massive
        /// @return current size
        size_t get_size() const;

        /// @brief get word by index (need to be deleted after use)
        /// @param num
        /// @return word (need to be deleted after use)
        char *get_word(const size_t &num) const;

        //  other functions

        /// @brief add a word
        /// @param word
        void add(const char *word);

        /// @brief clear massive of words (but memory for massive stay)
        void clear();

        /// @brief delete element in massive by index
        /// @param num
        void del(const size_t &num);

        /// @brief search element in massive by index
        /// @param word
        /// @return index of word
        size_t search(const char *word) const;

        /// @brief create mass of words, started by same symbol
        /// @param symbol
        /// @return massive of words with words, started by some symbol (need to be deleted after use)
        words *first_symbol(const char &symbol) const;

        /// @brief sort massive of words by alphabet
        void sort();

        /// @brief output
        /// @param cout
        /// @return cout
        std::ostream &print(std::ostream &cout) const;

        /// @brief input
        /// @param cin
        /// @return cin
        std::istream &input(std::istream &cin);

        //  overloaded operators

        /// @brief decrement
        /// @return new instance of class element
        words &operator--();

        /// @brief decrement
        /// @param none
        /// @return previous instance of class element
        const words operator--(int);

        /// @brief by indexes
        /// @param index
        /// @return word by index
        char *operator[](size_t index);

        /// @brief by indexes
        /// @param index
        /// @return word by index
        const char *operator[](size_t index) const;

        /// @brief output
        /// @param cout
        /// @param mass
        /// @return cout
        friend std::ostream &operator<<(std::ostream &cout, const words &mass);

        /// @brief input
        /// @param cin
        /// @param mass
        /// @return cin
        friend std::istream &operator>>(std::istream &cin, words &mass);

        /// @brief overloaded operator !
        /// @return empty massive or not
        bool operator!() const;

        /// @brief operator of adding other massive of words
        /// @param mass_cp
        /// @return new instance of massive of words
        words &operator+=(const words &mass_cp);

        /// @brief overloaded operator of sum
        /// @param mass_add
        /// @return sum of two
        const words operator+(const words &mass_add) const;

        /// @brief copy assignment
        /// @param mass_new
        /// @return new instance of massive of words
        words &operator=(const words &mass_new);

        /// @brief move assignment
        /// @param mass_new
        /// @return new instance of massive of words
        words &operator=(words &&mass_new);

        /// @brief compare operator
        /// @param mass_check
        /// @return compare size of two masses
        std::strong_ordering operator<=>(const words &mass_check) const;
    };
}

#endif