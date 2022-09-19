#ifndef LAB1_H
#define LAB1_H

#define LAB_VERSION "1.0.0"
#define VARIANT 3

namespace lab1
{   
    //  structure for line in matrix (common list)
    struct line
    {
        double value = 0.0;
        int coordinate;
        line *next = nullptr;
    };

    //  structure for column in matrix (common list)
    struct column
    {
        line *elements = nullptr;
        int coordinate;
        column *next = nullptr;
    };

    //  func for safe and clean input
    template <class T>
    int getNum(T &a)
    {
        std::cin >> a;
        if (!std::cin.good())
        {
            std::cin.clear();
            while (std::cin.get() != '\n')
                continue;
            return -1;
        }
        return 1;
    }

    //  func for calculation max element in line
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

    //  func for calculation first no-zero element in line
    inline double search_first(const line &elements) { return elements.value; }

    //  start message about this app
    void start_msg();
    //  func for input matrix
    column *input(int &, int &);
    //  func for printing all results and matrix
    void output(const char *msg, const column &mass, const line &vec_B);

    //  func for calculation each vec_B[i] for each line
    double calc_vec(const line *elements, double (*func)(line &));
     //  func for calculation all vec_B by matrix
    int calc_vec(const column &mass, line *&vec_B, const int m);

    //  func for search in list data structure
    column *search(column *lst, const int coordinate);
    //  func for search in list data structure
    line *search(line *lst, const int coordinate);

    //  func for insertion in matrix one element by coordinates
    int insert(column *&mass, const int coordinate_x, const int coordinate_y, const double value);
    //  func for clear data from matrix
    void erase(column *mass);
    //  func for clear data from list
    void erase(line *lst);
    

}

#endif