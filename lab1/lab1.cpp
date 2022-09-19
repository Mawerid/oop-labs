#include <iostream>
#include "lab1.h"

namespace lab1
{
    //  start message about this app
    void start_msg()
    {
        std::cout << "Here is Lab1 " << LAB_VERSION << "in variant " << VARIANT << std::endl;
        std::cout << "This program works with highly sparse matrix of real numbers" << std::endl;
        std::cout << "After all input, it counts special vector using average and maximum of each line" << std::endl;
        std::cout << "------------------------------------------------" << std::endl
                  << std::endl;
    }

    //  func for input matrix
    column *input(int &rm, int &rn)
    {
        const char *msg = "";
        column *mass = nullptr;
        int m = 0;
        int n = 0;
        double value = 0.0;
        int coor_x = 0, coor_y = 0;

        do
        {
            std::cout << msg << std::endl;
            std::cout << "Enter number of columns: --> ";
            msg = "You are wrong; repeat please!";
            if (getNum(m) < 0)
                return nullptr;
        } while (m < 1);

        msg = "";

        do
        {
            std::cout << msg << std::endl;
            std::cout << "Enter number of lines:   --> ";
            msg = "You are wrong; repeat please!";
            if (getNum(n) < 0)
                return nullptr;
        } while (n < 1);

        std::cout << std::endl
                  << "------------------------------------------------" << std::endl;

        msg = "You are wrong. Repeat, please!";

        while (coor_x != -1 || coor_y != -1)
        {
            std::cout << "Enter X and Y coordinates of cell (enter '-1 -1' to stop input):  ";
            if (getNum(coor_x) < 0 || getNum(coor_y) < 0 || (coor_x < 0 && coor_x != -1) || (coor_y < 0 && coor_y != -1) || coor_x >= n || coor_y >= m)
            {
                std::cout << msg << std::endl;
                continue;
            }

            if (coor_x == -1 || coor_y == -1)
                break;

            std::cout << "Enter the value (real number):    ";
            if (getNum(value) < 0)
            {
                std::cout << msg << std::endl;
                continue;
            }

            if (insert(mass, coor_x, coor_y, value))
            {
                std::cout << "Sorry, something went wrong (Most possible error is unable to allocate the memory)." << std::endl;
                erase(mass);
                return nullptr;
            }
        }

        rm = m;
        rn = n;
        return mass;
    }

    //  func for printing all results and matrix
    void output(const char &msg, const column &mass, const line &vec_B, const int m)
    {
        std::cout << msg << std::endl;
        std::cout << "------------------------------------------------" << std::endl;
        for (column ptr_col = mass; ptr_col.next; ptr_col = *ptr_col.next)
        {
            for (line ptr_line = *ptr_col.elements; ptr_line.next; ptr_line = *ptr_line.next)
                std::cout << ptr_line.value << " (" << ptr_line.coordinate << ", " << ptr_col.coordinate << ")   ";
            std::cout << std::endl;
        }
        std::cout << std::endl;

        std::cout << "Here is result vector: " << std::endl;
        std::cout << "------------------------------------------------" << std::endl;

        int count = 0;
        for (line ptr_line = vec_B; ptr_line.next; ptr_line = *ptr_line.next)
        {
            std::cout << ptr_line.value << " (" << ptr_line.coordinate << ")   ";
            count++;
            if (count % 20 == 0)
                std::cout << std::endl;
        }
        std::cout << std::endl
                  << std::endl;
    }

    //  func for calculation each vec_B[i] for each line
    double calc_vec(const line &elements, double (*func)(const line &))
    {
        double res = 0.0, average = 0.0;
        int amount = 0;
        for (line ptr = elements; ptr.next; ptr = *ptr.next)
        {
            average += ptr.value;
            amount++;
        }
        res = average / amount / func(elements);

        return res;
    }

    //  func for search in list data structure
    column *search(column *lst, const int coordinate)
    {
        column *ptr;
        ptr = lst;

        for (; ptr->next; ptr = ptr->next)
            if (ptr->coordinate == coordinate)
                return ptr;
        return nullptr;
    }

    //  func for search in list data structure
    line *search(line *lst, const int coordinate)
    {
        line *ptr;
        ptr = lst;

        for (; ptr->next; ptr = ptr->next)
            if (ptr->coordinate == coordinate)
                return ptr;
        return nullptr;
    }

    //  func for insertion in matrix one element by coordinates
    int insert(column *&mass, const int coordinate_x, const int coordinate_y, const int value)
    {

        column *new_cel;

        try
        {
            new_cel = new column;
        }
        catch (std::bad_alloc &ba)
        {
            std::cout << "------ too many columns in matrix: " << ba.what() << std::endl;
            return 1;
        }

        new_cel->coordinate = coordinate_y;
        new_cel->next = nullptr;

        try
        {
            new_cel->elements = new line;
        }
        catch (std::bad_alloc &ba)
        {
            std::cout << "------ too many rows in matrix: " << ba.what() << std::endl;
            return 1;
        }

        new_cel->elements->coordinate = coordinate_x;
        new_cel->elements->value = value;
        new_cel->elements->next = nullptr;

        column *ptr_col;
        line *ptr_line;

        if (!mass)
        {
            mass = new_cel;
            return 0;
        }

        ptr_col = search(mass, coordinate_y);
        if (!ptr_col)
        {
            column *par_col;
            par_col = nullptr;
            for (ptr_col = mass; ptr_col != nullptr && ptr_col->coordinate < coordinate_y; ptr_col = ptr_col->next)
                par_col = ptr_col;

            if (par_col)
            {
                new_cel->next = par_col->next;
                par_col->next = new_cel;
            }
            else
            {
                new_cel->next = mass->next;
                mass->next = new_cel;
            }
            return 0;
        }

        ptr_line = search(ptr_col->elements, coordinate_x);
        if (!ptr_line)
        {
            line *par_line;
            par_line = nullptr;
            for (ptr_line = ptr_col->elements; ptr_line != nullptr && ptr_line->coordinate < coordinate_x; ptr_line = ptr_line->next)
                par_line = ptr_line;

            if (par_line)
            {
                new_cel->elements->next = par_line->next;
                par_line->next = new_cel->elements;
            }
            else
            {
                new_cel->elements->next = mass->elements->next;
                mass->elements->next = new_cel->elements;
            }

            new_cel->next = nullptr;
            new_cel->coordinate = 0;
            new_cel->elements = nullptr;
            delete new_cel;
            return 0;
        }

        ptr_line->value = value;
        return 0;
    }

    //  func for calculation all vec_B by matrix
    int calc_vec(const column &mass, line *&vec_B, const int m)
    {
        if (vec_B)
            erase(vec_B);

        column ptr = mass;
        line *ptr_vec_B;
        line *par_vec_B;

        ptr_vec_B = nullptr;
        par_vec_B = nullptr;

        try
        {
            ptr_vec_B = new line;
        }
        catch (std::bad_alloc &ba)
        {
            std::cout << ba.what() << std::endl;
            return 1;
        }

        ptr_vec_B->coordinate = ptr.coordinate;
        ptr_vec_B->next = nullptr;

        if ((ptr.elements)->coordinate != 0)
            ptr_vec_B->value = calc_vec(*(ptr.elements), search_first);
        else
            ptr_vec_B->value = calc_vec(*(ptr.elements), max_line);

        vec_B = ptr_vec_B;
        par_vec_B = ptr_vec_B;
        ptr_vec_B = nullptr;
        ptr = *ptr.next;

        for (; ptr.next; ptr = *ptr.next)
        {
            try
            {
                ptr_vec_B = new line;
            }
            catch (std::bad_alloc &ba)
            {
                std::cout << ba.what() << std::endl;
                return 1;
            }

            ptr_vec_B->coordinate = ptr.coordinate;

            if ((ptr.elements)->coordinate != 0)
                ptr_vec_B->value = calc_vec(*(ptr.elements), search_first);
            else
                ptr_vec_B->value = calc_vec(*(ptr.elements), max_line);

            par_vec_B->next = ptr_vec_B;
            par_vec_B = ptr_vec_B;
            ptr_vec_B = nullptr;
        }

        par_vec_B = nullptr;
        ptr_vec_B = nullptr;
        return 0;
    }

    //  func for clear data from matrix
    void erase(column *mass)
    {
        if (!mass)
            return;

        column *ptr;
        while (mass != nullptr)
        {
            ptr = mass;
            mass = mass->next;
            ptr->coordinate = 0;
            ptr->elements = nullptr;
            ptr->next = nullptr;
            delete ptr;
        }
    }

    //  func for clear data from list
    void erase(line *lst)
    {
        if (!lst)
            return;

        line *ptr;
        while (lst != nullptr)
        {
            ptr = lst;
            lst = lst->next;
            ptr->coordinate = 0;
            ptr->value = 0;
            ptr->next = nullptr;
            delete ptr;
        }
    }

}