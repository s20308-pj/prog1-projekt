#include "gra.hpp"

extern bool KoniecGry;
extern int tab_plansza[17][17];
extern postac gracz;
extern int inp;

int main() {
  initscr();
  noecho();
  setup();
  int menu = menu_input();
  while (!KoniecGry) {
    draw(tab_plansza);
    stat();
    inp = input();
    czyszczenie();
    refresh();
    if (menu != 0) {
      switch (menu) {
      case 1:
        setup();
        menu = 0;
        break;
      case 2:
        zapisz();
        menu = 0;
        break;
      case 3:
        wczytaj();
        menu = 0;
        break;
      case 4:
        KoniecGry = true;
        break;
      }
    }
    interakcja(gracz, inp, tab_plansza);
    if (inp == 8)
      KoniecGry = true;
    if (inp == 7)
      menu = menu_input();
    if (gracz.hp <= 0) {
      KoniecGry = true;
      koniec();
    }
  }

  endwin();
  return 0;
}
