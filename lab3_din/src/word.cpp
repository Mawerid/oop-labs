#include "../include/word.hpp"
#include <stdexcept>
#include <iostream>
#include <string.h>

namespace word
{
    words::words()
    {
        for (unsigned i = 0; i < MAX_WORD_COUNT; i++)
            strncpy(mass[i], "", MAX_WORD_LEN);
    }

    words::words(const char *word)
    {
        if (strlen(word) > MAX_WORD_LEN)
            throw std::invalid_argument("too big word");
        strncpy(mass[0], word, MAX_WORD_LEN);
        count = 1;

        for (unsigned i = 1; i < MAX_WORD_COUNT; i++)
            strncpy(mass[i], "", MAX_WORD_LEN);
    }

    words::words(const unsigned &count_s, const char **mass_s)
    {
        for (unsigned i = 0; i < count_s; i++)
        {
            if (i > MAX_WORD_COUNT)
                throw std::overflow_error("not enough storage in massive of words");
            if (strlen(mass_s[i]) > MAX_WORD_LEN)
                throw std::invalid_argument("too big word found in massive");
            for (unsigned j = 0; j < i; j++)
                if (!strcmp(mass[j], mass_s[i]))
                    throw std::invalid_argument("no same word can be in massive of words");

            strncpy(mass[i], mass_s[i], MAX_WORD_LEN);
        }
        count = count_s;

        for (unsigned i = count; i < MAX_WORD_COUNT; i++)
            strncpy(mass[i], "", MAX_WORD_LEN);
    }

    words::words(const words &mass_cp)
    {
        count = mass_cp.get_count();
        char *str;
        for (unsigned int i = 0; i < count; i++)
        {
            str = mass_cp.get_word(i);
            strncpy(mass[i], str, MAX_WORD_LEN);
            delete[] str;
        }
    }

    unsigned words::get_count() const
    {
        return count;
    }

    int words::add(const char *word)
    {
        if (count == MAX_WORD_COUNT)
            throw std::overflow_error("not enough storage in massive of words");
        if (strlen(word) > MAX_WORD_LEN)
            throw std::invalid_argument("too big word found");

        for (unsigned i = 0; i < count; i++)
            if (!strcmp(mass[i], word))
                throw std::invalid_argument("no same word can be in massive of words");

        strncpy(mass[count], word, MAX_WORD_LEN);
        count++;
        return 0;
    }

    void words::clear()
    {
        for (unsigned i = 0; i < count; i++)
            strncpy(mass[i], "", MAX_WORD_LEN);
        count = 0;
    }

    int words::del(const unsigned &num)
    {
        if (count == 0)
            throw std::invalid_argument("massive is empty");
        if (num >= count)
            throw std::invalid_argument("no word with this number");

        for (unsigned i = num; i < (count - 1); i++)
        {
            strncpy(mass[i], mass[i + 1], MAX_WORD_LEN);
        }

        if (num == count - 1)
            strncpy(mass[num], "", MAX_WORD_LEN);
        count--;
        return 0;
    }

    unsigned words::search(const char *word) const
    {
        for (unsigned i = 0; i < count; i++)
            if (!strcmp(mass[i], word))
                return i;

        return count;
    }

    char *words::get_word(const unsigned &num) const
    {
        if (num >= count)
            throw std::invalid_argument("invalid position of searching word");

        char *str;
        str = new char[MAX_WORD_LEN];
        strncpy(str, mass[num], MAX_WORD_LEN);
        return str;
    }

    words *words::first_symbol(const char &symbol) const
    {
        words *newmass;
        newmass = new words;

        for (unsigned i = 0; i < count; i++)
            if (mass[i][0] == tolower(symbol) || mass[i][0] == toupper(symbol))
                newmass->add(mass[i]);

        if (newmass->get_count() == 0)
        {
            delete newmass;
            throw std::invalid_argument("there is no words starting with this symbol");
        }

        return newmass;
    }

    void words::swap(char *word1, char *word2)
    {
        char tmp[MAX_WORD_LEN];
        strncpy(tmp, word1, MAX_WORD_LEN);
        strncpy(word1, word2, MAX_WORD_LEN);
        strncpy(word2, tmp, MAX_WORD_LEN);
    }

    void words::sort()
    {
        if (count < 2)
            return;

        char tmp_1[MAX_WORD_LEN];
        char tmp_2[MAX_WORD_LEN];

        for (int i = 0; i < (count - 1); i++)
            for (int j = 0; j < (count - i - 1); j++)
            {
                if (strlen(mass[j]) > strlen(mass[j + 1]))
                {
                    strncpy(tmp_1, mass[j], strlen(mass[j + 1]));
                    strncpy(tmp_2, mass[j + 1], strlen(mass[j + 1]));
                    for (int i = 0; i < strlen(mass[j + 1]); i++)
                    {
                        tmp_1[i] = tolower(tmp_1[i]);
                        tmp_2[i] = tolower(tmp_2[i]);
                    }
                }
                else
                {
                    strncpy(tmp_1, mass[j], strlen(mass[j]));
                    strncpy(tmp_2, mass[j + 1], strlen(mass[j]));
                    for (int i = 0; i < strlen(mass[j]); i++)
                    {
                        tmp_1[i] = tolower(tmp_1[i]);
                        tmp_2[i] = tolower(tmp_2[i]);
                    }
                }

                if (strcmp((tmp_1), (tmp_2)) > 0)
                    swap(mass[j], mass[j + 1]);
            }
    }

    std::ostream &words::print(std::ostream &cout) const
    {
        if (count == 0)
        {
            cout << "Word Massive sizeof " << MAX_WORD_COUNT << " is empty" << std::endl;
            return cout;
        }

        cout << "Word Massive sizeof " << MAX_WORD_COUNT << " filled with " << count << " elements" << std::endl;
        cout << "[ ";

        for (int i = 0; i < count; i++)
        {
            cout << "'" << mass[i] << "'";
            if ((i + 1) < count)
                cout << ", ";
            if (i % 10 == 0 && i != 0)
                cout << std::endl;
        }
        cout << " ]" << std::endl;

        return cout;
    }

    std::istream &words::input(std::istream &cin)
    {
        if (count == MAX_WORD_COUNT)
            throw std::overflow_error("not enough storage in massive of words");

        char str[MAX_WORD_LEN];
        cin.width(MAX_WORD_LEN);
        cin >> str;

        if (!cin.good())
            throw std::ios_base::failure("invalid input");

        cin.clear();

        add(str);

        return cin;
    }

    words &words::operator--()
    {
        this->del(count - 1);
        return *this;
    }

    const words words::operator--(int)
    {
        words tmp(*this);
        this->del(count - 1);
        return tmp;
    }

    char *words::operator[](size_t index)
    {
        if (index >= count)
            throw std::invalid_argument("invalid index");
        return mass[index];
    }

    const char *words::operator[](size_t index) const
    {
        if (index >= count)
            throw std::invalid_argument("invalid index");
        return mass[index];
    }

    std::ostream &operator<<(std::ostream &cout, const words &mass)
    {
        mass.print(cout);
        return cout;
    }

    std::istream &operator>>(std::istream &cin, words &mass)
    {
        mass.input(cin);
        return cin;
    }

    bool words::operator!() const
    {
        if (count)
            return false;
        return true;
    }

    words &words::operator+=(const words &mass_cp)
    {
        unsigned int count_tmp = mass_cp.get_count();
        for (unsigned int i = 0; i < count_tmp; i++)
            this->add(mass_cp.get_word(i));
        return *this;
    }

    const words words::operator+(const words &mass_add) const
    {
        words sum(*this);
        unsigned int count_mass = mass_add.get_count();
        unsigned int count_max = words::MAX_WORD_COUNT;
        char *str;
        for (unsigned int i = 0; i < count_mass; i++)
        {
            if (sum.get_count() >= count_max)
                break;

            str = mass_add.get_word(i);
            sum.add(str);
            delete[] str;
        }
        return sum;
    }

    std::strong_ordering words::operator<=>(const words &mass_check) const
    {
        return (count <=> mass_check.get_count());
    }
}