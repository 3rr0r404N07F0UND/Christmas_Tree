#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <wchar.h>

wchar_t get_deco(void) {
  wchar_t deco_list[] = {L'●', L'o', L'x', L'X', L'+', L'◆'};
  return deco_list[rand() % 6];
}

int get_color(void) {
  int color_list[] = {91, 93, 94, 95, 96, 97};
  return color_list[rand() % 6];
}

void draw_tree(int height) {
  _wsetlocale(LC_ALL, L"Korean");
  for (register int i = 0; i < height; i++) {
    for (register int j = 0; j < height * 2; j++) {
      if (height - i > j || height + i < j) {
        printf(" ");
      } else {
        if (i == 0) {
          printf("\x1b[93m%lc\x1b[0m", L'★');
        } else if (rand() % 4 == 0) {
          wchar_t *buffer = (wchar_t *)calloc(13, sizeof(wchar_t));

          swprintf(buffer, 13, L"\x1b[%dm%lc\x1b[0m", get_color(), get_deco());
          wprintf(L"%ls", buffer);

          free(buffer);
        } else {
          printf("\x1b[92m*\x1b[0m");
        }
      }
    }
    printf("\n");
  }
}