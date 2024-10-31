#include <array>
#include <iostream>

#define USI_MAX std::numeric_limits<unsigned short int>::max()
#define grid_array std::array<std::array<unsigned short int, 9>, 9>
typedef unsigned short int usi;

namespace helper_functions {
  void show_grid(grid_array grid);
}

class sudoku {
  grid_array grid, solved_grid;

public:
  sudoku(grid_array grid);

  void show_grid();

  void show_solved_grid();

  bool is_valid_move(usi x, usi y, usi n);

  void solve();
};
