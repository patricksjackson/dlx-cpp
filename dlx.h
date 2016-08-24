#pragma once

#include <vector>
#include <stack>

/**
 * Common node for every entry (and column head) in the matrix
 * It contains extra info for most nodes but makes the code simpler
 */
struct dlx_node {
    dlx_node* up;
    dlx_node* down;
    dlx_node* left;
    dlx_node* right;
    int row;
    int column;
    std::size_t count;
    dlx_node* head;

    dlx_node()
        : up(this), down(this),
        left(this), right(this),
        row(-1), column(-1), count(0), head(this)
    {}
    ~dlx_node() {};
};


class DLX {
    public:

        DLX(std::vector<std::vector<std::size_t>> definition,
            std::size_t req_columns);

        ~DLX();

        // Specify any rows that must be included
        void require_row(std::size_t row);

        // Return vector of row indices satisfying the cover
        std::vector<std::size_t> find_solution();

        // Return the number of solutions
        std::size_t count_solutions();

    private:
        // Functions
        bool is_solved() const;
        bool search(bool all);

        void insert_node(std::size_t row, std::size_t col);

        void cover_column(dlx_node* col_head);
        void uncover_column(dlx_node* col_head);

        dlx_node* smallest_column() const;

        // Data
        std::vector<std::vector<std::size_t>> definition_;
        std::size_t required_;
        dlx_node* matrix;
        std::stack<std::size_t> solutions;
        std::size_t solution_count;

        std::vector<std::vector<dlx_node>> nodes_;
};

