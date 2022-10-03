#include "../include/word.hpp"
#include <stdexcept>
#include <iostream>
#include <string.h>

namespace word
{
    words::words()
    {
        for (unsigned i = 0; i < MAX_WORD_COUNT; i++)
            strcpy(mass[i], "");
    }

    words::words(char *word)
    {
        if (strlen(word) > MAX_WORD_LEN)
            throw std::invalid_argument("too big word");
        strncpy(mass[0], word, MAX_WORD_LEN);
        count++;

        for (unsigned i = 1; i < MAX_WORD_COUNT; i++)
            strcpy(mass[i], "");
    }

    words::words(unsigned count_s, const char **mass_s)
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
            strcpy(mass[i], "");
    }

    unsigned words::get_count()
    {
        return count;
    }

    int words::add(char *word)
    {
        if (count == MAX_WORD_COUNT)
            throw std::overflow_error("not enough storage in massive of words");
        if (strlen(word) > MAX_WORD_LEN)
            throw std::invalid_argument("too big word found");

        strncpy(mass[count], word, MAX_WORD_LEN);
        count++;
        return 0;
    }

    unsigned words::search(char *word)
    {
        for (unsigned i = 0; i < count; i++)
            if (!strcmp(mass[i], word))
                return i;

        return count;
    }

    char *words::ret_word(unsigned num)
    {
        if (num < count)
            throw std::invalid_argument("invalid position of searching word");

        char *str = mass[num];
        return str;
    }

    words *words::first_symbol(char symbol)
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

        char tmp;
        int stack[count];
        int top = -1;
        int l, h, p;
        stack[++top] = 0;
        stack[++top] = count;

        while (top >= 0)
        {
            h = stack[top--];
            l = stack[top--];

            tmp = mass[h][0];
            p = (l - 1);

            for (int j = l; j <= h - 1; j++)
            {
                if (mass[j][0] <= tmp)
                {
                    p++;
                    swap(mass[p], mass[j]);
                }
            }
            p++;
            swap(mass[p], mass[h]);

            if (p - 1 > l)
            {
                stack[++top] = l;
                stack[++top] = p - 1;
            }

            if (p + 1 < h)
            {
                stack[++top] = p + 1;
                stack[++top] = h;
            }
        }
    }

    std::ostream &words::print(std::ostream &cout)
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
            cout << "'" << mass[i];
            if ((i + 1) < count)
                cout << "', ";
            if (i % 10 == 0)
                cout << std::endl;
        }
        cout << " ]" << std::endl;

        return cout;
    }

    std::istream &words::input(std::istream &cin)
    {
        char *str;

        cin >> str;

        if (!cin.good())
        {
            throw std::ios_base::failure("invalid input");
        }

        try
        {
            add(str);
        }
        catch (std::exception &ex)
        {
            throw ex;
        }

        return cin;
    }
}
