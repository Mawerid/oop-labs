#ifndef LAB1_H
#define LAB1_H

#define LAB_VERSION "1.0.0"
#define VARIANT 3

namespace lab1
{
    struct line
    {
        double value = 0;
        int coordinate;
        line *next = nullptr;
    };

    struct column
    {
        line *elements = nullptr;
        int coordinate;
        column *next = nullptr;
    };

    template <class T>

    int getNum(T &a)
    {
        std::cin >> a;
        if (!std::cin.good())
            return -1;
        return 1;
    }

    inline double max_line(line *elements)
    {
        line *ptr, *max_el;
        ptr = elements;
        max_el = elements;
        for (; ptr->next != nullptr; ptr = ptr->next)
            if (max_el->value < ptr->value)
                max_el = ptr;
        return max_el->value;
    }

    inline double search_first(line *elements) { return elements->value; }

    column *input(int &, int &);
    void output(const char *msg, column *mass, line *vec_B, const int m);
    double calc_vec(line *elements, double (*func)(line *));

    template <class list>
    list *search(list *lst, const int coordinate);

    int insert(column *mass, const int coordinate_x, const int coordinate_y, const int value);
    int calc_vec(column *mass, line *vec_B, const int m);
    void erase(column *mass);
    void erase(line *lst);
    void start_msg();

}

#endif