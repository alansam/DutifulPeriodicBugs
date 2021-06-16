
#include <stdio.h>

//  available to all functions in this compilation unit
static int file_scope = 10;

void fn(void);

int main() {
  //  available only to main
  static int main_scope = 12;
  for (size_t i_ = 0; i_ < 5; ++i_) {
    printf("file_scope: %3d, main_scope : %3d\n",
           file_scope++, main_scope++);
    fn();
  }

  return 0;
}

void fn(void) {
  //  available only to this function
  static int fn_scope = 0;
  //  ERROR main_scope not in scope
  // printf("file_scope: %3d, main_scope : %3d\n",
  //         file_scope++, main_scope++);
  printf("file_scope: %3d, fn_scope   : %3d\n",
         file_scope++, fn_scope++);
  fn_scope *= 3;

  {
    static int inner_scope = 0;
    printf("file_scope: %3d, inner_scope: %3d\n",
          file_scope++, inner_scope++);
    inner_scope += 5;
  }
  //  ERROR inner_scope not inn scope
  // printf("file_scope: %3d, inner_scope: %3d\n",
  //       file_scope++, inner_scope++);

  return;
}
