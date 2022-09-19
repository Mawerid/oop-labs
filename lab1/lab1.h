#ifndef LAB1_H
#define LAB1_H

#define LAB_VERSION "1.0.0"
#define VARIANT 3

namespace lab1
{
    struct line
    {
        double value = 0.0;
        int coordinate;
        line *next;
    };

    struct column
    {
        line *elements;
        int coordinate;
        column *next;
    };

    template <class T>

    int getNum(T &a)
    {
        std::cin >> a;
        if (!std::cin.good())
        {
            std::cin.clear();
            while (std::cin.get() != '\n') 
            {
                continue;
            }
            return -1;
        }
        return 1;
    }

    inline double max_line(const line &elements)
    {
        line ptr = elements;
        double max_el = elements.value;
        for (; ptr.next; ptr = *ptr.next)
            if (max_el < ptr.value)
                max_el = ptr.value;
        if (max_el < ptr.value)
                max_el = ptr.value;
        return max_el;
    }

    inline double search_first(const line &elements) { return elements.value; }

    column *input(int &, int &);
    void output(const char *msg, const column &mass, const line &vec_B);
    double calc_vec(const line *elements, double (*func)(line &));

    column *search(column *lst, const int coordinate);
    line *search(line *lst, const int coordinate);

    int insert(column *&mass, const int coordinate_x, const int coordinate_y, const double value);
    int calc_vec(const column &mass, line *&vec_B, const int m);
    void erase(column *mass);
    void erase(line *lst);
    void start_msg();

}

#endif