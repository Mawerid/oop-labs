#include "../include/word.hpp"
#include <stdexcept>
#include <iostream>
#include <string.h>

namespace word
{
    /// @brief empty constructor
    words::words()
    {
        mass = nullptr;
    }

    /// @brief constructor with first word
    /// @param word
    words::words(const char *word)
    {
        mass = new char *[QUOTE];
        size_t len = strlen(word);

        mass[0] = new char[len + 1];
        mass[0][len] = '\0';

        strncpy(mass[0], word, len);
        curr_size = 1;
        size = QUOTE;
    }

    /// @brief constructor with massive of words
    /// @param count_s
    /// @param mass_s
    words::words(const size_t &count_s, const char **mass_s)
    {
        size = QUOTE * (count_s / QUOTE + 1);
        curr_size = count_s;
        mass = new char *[size];

        size_t len = 0;

        for (size_t i = 0; i < curr_size; i++)
        {
            for (size_t j = 0; j < i; j++)
                if (strlen(mass[j]) == strlen(mass_s[i]) && !strncmp(mass[j], mass_s[i], strlen(mass[j])))
                    throw std::invalid_argument("no same word can be in massive of words");

            len = strlen(mass_s[i]);

            try
            {
                mass[i] = new char[len + 1];
            }
            catch (const std::exception &e)
            {
                for (size_t j = 0; j < i; j++)
                    delete[] mass[j];
                delete[] mass;
                throw e;
            }

            mass[i][len] = '\0';

            strncpy(mass[i], mass_s[i], len);
        }
    }

    /// @brief copy constructor
    /// @param mass_cp
    words::words(const words &mass_cp)
    {
        curr_size = mass_cp.get_size();
        size = QUOTE * (curr_size / QUOTE + 1); // = mass_cp.size
        mass = new char *[size];
        size_t len = 0;

        char *str;
        for (size_t i = 0; i < curr_size; i++)
        {
            str = mass_cp.get_word(i);

            len = strlen(str);

            try
            {
                mass[i] = new char[len + 1];
            }
            catch (const std::exception &e)
            {
                for (size_t j = 0; j < i; j++)
                    delete[] mass[j];
                delete[] mass;
                throw e;
            }

            mass[i][len] = '\0';

            strncpy(mass[i], str, len);
            delete[] str;
        }
    }

    /// @brief move constructor
    /// @param mass_mv
    words::words(words &&mass_mv)
    {
        size = mass_mv.size;
        curr_size = mass_mv.curr_size;
        mass = mass_mv.mass;
        mass_mv.mass = nullptr;
    }

    /// @brief destructor
    words::~words()
    {
        if (mass != nullptr)
        {
            for (size_t i = 0; i < curr_size; i++)
                if (mass[i] != nullptr)
                    delete[] mass[i];
            delete[] mass;
        }
    }

    /// @brief get current size of massive
    /// @return current size
    size_t words::get_size() const
    {
        return curr_size;
    }

    /// @brief get word by index (need to be deleted after use)
    /// @param num
    /// @return word (need to be deleted after use)
    char *words::get_word(const size_t &num) const
    {
        if (num >= curr_size)
            throw std::invalid_argument("invalid position of searching word");

        char *str;
        size_t len = strlen(mass[num]);

        str = new char[len + 1];
        str[len] = '\0';

        strncpy(str, mass[num], len);

        return str;
    }

    /// @brief add a word
    /// @param word
    void words::add(const char *word)
    {
        for (size_t i = 0; i < curr_size; i++)
            if (strlen(mass[i]) == strlen(word) && !strncmp(mass[i], word, strlen(word)))
                throw std::invalid_argument("no same word can be in massive of words");

        size_t len = 0;

        if (curr_size == size)
        {
            char **tmp_mass;
            size += QUOTE;
            tmp_mass = new char *[size];
            for (size_t i = 0; i < curr_size; i++)
            {
                len = strlen(mass[i]);
                tmp_mass[i] = new char[len + 1];
                tmp_mass[i][len] = '\0';
                strncpy(tmp_mass[i], mass[i], len);
                delete[] mass[i];
            }
            delete[] mass;
            mass = tmp_mass;
        }

        len = strlen(word);

        mass[curr_size] = new char[len + 1];
        mass[curr_size][len] = '\0';

        strncpy(mass[curr_size], word, len);
        curr_size++;
    }

    /// @brief clear massive of words (but memory for massive stay)
    void words::clear()
    {
        for (size_t i = 0; i < curr_size; i++)
            delete[] mass[i];

        delete[] mass;
        size = QUOTE;
        mass = new char *[size];
        curr_size = 0;
    }

    /// @brief delete element in massive by index
    /// @param num
    void words::del(const size_t &num)
    {
        if (curr_size == 0)
            throw std::invalid_argument("massive is empty");
        if (num >= curr_size)
            throw std::invalid_argument("no word with this number");

        size_t len = 0;

        curr_size--;
        size = QUOTE * (curr_size / QUOTE + 1);
        char **mass_cp;

        mass_cp = new char *[curr_size];

        for (size_t i = 0; i < num; i++)
        {
            len = strlen(mass[i]);

            try
            {
                mass_cp[i] = new char[len + 1];
            }
            catch (const std::exception &e)
            {
                for (size_t j = 0; j < i; j++)
                    delete[] mass_cp[j];
                delete[] mass_cp;
                throw e;
            }
            mass_cp[i][len] = '\0';

            strncpy(mass_cp[i], mass[i], len);
            delete[] mass[i];
        }

        for (size_t i = num; i < curr_size; i++)
        {
            delete[] mass[i];
            len = strlen(mass[i + 1]);

            try
            {
                mass_cp[i] = new char[len + 1];
            }
            catch (const std::exception &e)
            {
                for (size_t j = 0; j < i; j++)
                    delete[] mass_cp[j];
                delete[] mass_cp;
                throw e;
            }
            mass_cp[i][len] = '\0';

            strncpy(mass_cp[i], mass[i + 1], len);
        }

        delete[] mass;
        mass = mass_cp;
    }

    /// @brief search element in massive by index
    /// @param word
    /// @return index of word
    size_t words::search(const char *word) const
    {
        for (size_t i = 0; i < curr_size; i++)
            if (strlen(mass[i]) == strlen(word) && !strncmp(mass[i], word, strlen(word)))
                return i;

        return curr_size;
    }

    /// @brief create mass of words, started by same symbol
    /// @param symbol
    /// @return massive of words with words, started by some symbol (need to be deleted after use)
    words *words::first_symbol(const char &symbol) const
    {
        words *newmass;
        newmass = new words;

        for (size_t i = 0; i < curr_size; i++)
            if (mass[i][0] == tolower(symbol) || mass[i][0] == toupper(symbol))
                newmass->add(mass[i]);

        if (newmass->get_size() == 0)
        {
            delete newmass;
            throw std::invalid_argument("there is no words starting with this symbol");
        }

        return newmass;
    }

    /// @brief sort massive of words by alphabet
    void words::sort()
    {
        if (curr_size < 2)
            return;

        char *tmp_1;
        char *tmp_2;
        char *tmp;
        tmp_1 = new char[1];
        tmp_2 = new char[1];
        size_t len = 0;

        for (size_t i = 0; i < (curr_size - 1); i++)
        {
            for (size_t j = 0; j < (curr_size - i - 1); j++)
            {
                if (strlen(mass[j]) > strlen(mass[j + 1]))
                    len = strlen(mass[j + 1]);
                else
                    len = strlen(mass[j]);

                delete[] tmp_1;
                delete[] tmp_2;

                tmp_1 = new char[len + 1];
                tmp_1[len] = '\0';

                strncpy(tmp_1, mass[j], len);

                tmp_2 = new char[len + 1];
                tmp_2[len] = '\0';

                strncpy(tmp_2, mass[j + 1], len);

                for (size_t k = 0; k < len; k++)
                {
                    tmp_1[k] = tolower(tmp_1[k]);
                    tmp_2[k] = tolower(tmp_2[k]);
                }

                if (strncmp(tmp_1, tmp_2, len) > 0)
                // swap(mass[j], mass[j + 1]);
                {
                    size_t len = strlen(mass[j]);

                    tmp = new char[len + 1];
                    tmp[len] = '\0';

                    strncpy(tmp, mass[j], len);
                    delete[] mass[j];

                    len = strlen(mass[j + 1]);

                    mass[j] = new char[len + 1];
                    mass[j][len] = '\0';

                    strncpy(mass[j], mass[j + 1], len);
                    delete[] mass[j + 1];

                    len = strlen(tmp);

                    mass[j + 1] = new char[len + 1];
                    mass[j + 1][len] = '\0';

                    strncpy(mass[j + 1], tmp, len);
                    delete[] tmp;
                }
            }
        }
        delete[] tmp_1;
        delete[] tmp_2;
    }

    /// @brief output
    /// @param cout
    /// @return cout
    std::ostream &words::print(std::ostream &cout) const
    {
        if (curr_size == 0)
        {
            cout << "Word Massive sizeof " << size << " is empty" << std::endl;
            return cout;
        }

        cout << "Word Massive sizeof " << size << " filled with " << curr_size << " elements" << std::endl;
        cout << "[ ";

        for (size_t i = 0; i < curr_size; i++)
        {
            cout << "'" << mass[i] << "'";
            if ((i + 1) < curr_size)
                cout << ", ";
            if (i % 4 == 0 && i != 0 && i != curr_size - 1)
                cout << std::endl;
        }
        cout << " ]" << std::endl;

        return cout;
    }

    /// @brief input
    /// @param cin
    /// @return cin
    std::istream &words::input(std::istream &cin)
    {
        char str[81];
        cin >> str;
        if (!cin.good())
            throw std::ios_base::failure("invalid input");
        cin.clear();
        if (strlen(str) < 81)
            str[strlen(str)] = '\0';

        add(str);

        return cin;
    }

    /// @brief decrement
    /// @return new instance of class element
    words &words::operator--()
    {
        this->del(curr_size - 1);
        return *this;
    }

    /// @brief decrement
    /// @param none
    /// @return previous instance of class element
    const words words::operator--(int)
    {
        words tmp(*this);
        this->del(curr_size - 1);
        return tmp;
    }

    /// @brief by indexes
    /// @param index
    /// @return word by index
    char *words::operator[](size_t index)
    {
        if (index >= curr_size)
            throw std::invalid_argument("invalid index");
        return mass[index];
    }

    /// @brief by indexes
    /// @param index
    /// @return word by index
    const char *words::operator[](size_t index) const
    {
        if (index >= curr_size)
            throw std::invalid_argument("invalid index");
        return mass[index];
    }

    /// @brief output
    /// @param cout
    /// @param mass
    /// @return cout
    std::ostream &operator<<(std::ostream &cout, const words &mass)
    {
        mass.print(cout);
        return cout;
    }

    /// @brief input
    /// @param cin
    /// @param mass
    /// @return cin
    std::istream &operator>>(std::istream &cin, words &mass)
    {
        mass.input(cin);
        return cin;
    }

    /// @brief overloaded operator !
    /// @return empty massive or not
    bool words::operator!() const
    {
        if (curr_size)
            return false;
        return true;
    }

    /// @brief operator of adding other massive of words
    /// @param mass_cp
    /// @return new instance of massive of words
    words &words::operator+=(const words &mass_cp)
    {
        size_t count_tmp = mass_cp.get_size();
        for (size_t i = 0; i < count_tmp; i++)
            this->add(mass_cp[i]);

        return *this;
    }

    /// @brief overloaded operator of sum
    /// @param mass_add
    /// @return sum of two
    const words words::operator+(const words &mass_add) const
    {
        words sum(*this);
        size_t size_add = mass_add.get_size();
        for (size_t i = 0; i < size_add; i++)
            sum.add(mass_add[i]);

        return sum;
    }

    /// @brief copy assignment
    /// @param mass_new
    /// @return new instance of massive of words
    words &words::operator=(const words &mass_new)
    {
        size_t len = 0;
        if (this != &mass_new)
        {
            if (mass != nullptr)
            {
                for (size_t i = 0; i < curr_size; i++)
                    if (mass[i] != nullptr)
                        delete[] mass[i];
                delete[] mass;
            }
            mass = nullptr;
            curr_size = mass_new.curr_size;
            size = mass_new.size;

            if (curr_size > 0)
            {
                mass = new char *[size];
                for (size_t i = 0; i < curr_size; i++)
                {
                    len = strlen(mass_new.mass[i]);
                    mass[i] = new char[len + 1];
                    mass[i][len] = '\0';
                    strncpy(mass[i], mass_new.mass[i], len);
                }
            }
        }
        return *this;
    }

    /// @brief move assignment
    /// @param mass_new
    /// @return new instance of massive of words
    words &words::operator=(words &&mass_new)
    {
        size_t tmp;
        tmp = size;
        size = mass_new.size;
        mass_new.size = tmp;
        tmp = curr_size;
        curr_size = mass_new.curr_size;
        mass_new.curr_size = tmp;

        char **tmp_mass;
        tmp_mass = mass;
        mass = mass_new.mass;
        mass_new.mass = tmp_mass;

        return *this;
    }

    /// @brief compare operator
    /// @param mass_check
    /// @return compare size of two masses
    std::strong_ordering words::operator<=>(const words &mass_check) const
    {
        return (curr_size <=> mass_check.get_size());
    }
}