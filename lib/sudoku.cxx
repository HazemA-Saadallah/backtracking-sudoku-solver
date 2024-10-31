#include "sudoku.h"

  void helper_functions::show_grid(grid_array grid) {
    for (usi i{0}; i < 9; ++i) {
      for (usi j{0}; j < 8; ++j) {
        if (!((j+1) % 3)) {
          if (grid[i][j] == 0) std::cout <<"   ||";
          else std::cout <<' ' <<grid[i][j] <<" ||";
        } else {
          if (grid[i][j] == 0) std::cout <<"   |";
          else std::cout <<' ' <<grid[i][j] <<" |";
        }
      }
      if (grid[i].back() == 0) std::cout <<"   \n";
      else std::cout <<" " <<grid[i].back() <<" \n";
      if (i != 8) {
        if (!((i+1) % 3)) for (usi k{0}; k < 37; ++k) std::cout <<'=';
        else for (usi k{0}; k < 37; ++k) std::cout <<'-';
      }
      std::cout <<'\n';
    }
    std::cout <<'\n';
  }

  sudoku::sudoku(grid_array grid) { this->grid = grid, this->solved_grid = grid; }

  void sudoku::show_grid() { helper_functions::show_grid(this->grid); }

  void sudoku::show_solved_grid() { helper_functions::show_grid(this->solved_grid); }

  bool sudoku::is_valid_move(usi x, usi y, usi n) {
    for (usi i{0}; i < 9; ++i) if (this->grid[y][i] == n || this->grid[i][x] == n) return false;
    usi x0=(x/3)*3, y0=(y/3)*3;
    for (usi i{0}; i < 3; ++i) for (usi j{0}; j < 3; ++j) if (this->grid[y0+i][x0+j] == n) return false;
    return true;
  }

  void sudoku::solve() {
    for (usi y{0}; y < 9; ++y) {
      for (usi x{0}; x < 9; ++x) {
        if (this->grid[y][x] == 0) {
          for (usi n{1}; n < 10; ++n) {
            if (this->is_valid_move(x, y, n)) {
              this->grid[y][x] = n;
              solve();
              this->grid[y][x] = 0;
            }
          }
          return;
        }
      }
    }
    this->solved_grid = this->grid;
  }
