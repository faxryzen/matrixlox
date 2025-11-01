#include <iostream>

void destroy(int ** mtx, size_t created)
{
  for (size_t i = 0; i < created; i++)
  {
    delete[] mtx[i];
  }
  delete[] mtx;
}

int ** create(size_t rows, size_t cols)
{
  int ** mtx = new int * [rows];
  size_t created = 0;
  try 
  {
    for (; created < rows; ++created)
    {
      mtx[created] = new int[cols];
    }
  }
  catch (const std::bad_alloc & e)
  {
    destroy(mtx, created);
    throw;
  }
  return mtx;
}

void construct(int ** mtx, int init, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      mtx[i][j] = init;
    }
  }
}

void input(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      std::cin >> mtx[i][j];
    }
  }
}
void output(int ** mtx, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    std::cout << mtx[i][0];
    for (size_t j = 1; j < cols; ++j)
    {
      std::cout << ' ' << mtx[i][j];
    }
    std::cout << '\n';
  }
}


int main()
{
  size_t r = 0, c = 0;
  std::cin >> r >> c;
  if (!std::cin)
  {
    std::cerr << "ERROR: input failed!\n";

    return 1;
  }

  int ** matrix = create(r, c); //можно обернуть в try/catch

  std::cout << "Matrix created!\n";

  construct(matrix, 0, r, c); //инициализация

  std::cout << "Enter matrix elements:\n";

  input(matrix, r, c);
  if (!std::cin)
  {
    destroy(matrix, r);
    std::cerr << "ERROR: input failed!\n";
    return 1;
  }
  std::cout << "Output:\n";
  output(matrix, r, c);

  destroy(matrix, r);
}
