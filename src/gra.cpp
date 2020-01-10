#include "gra.hpp"

bool KoniecGry;
const int width = 17;
const int height = 17;
int plansza_x;
int plansza_y;
int plansza_mx;
int plansza_my;
int start_y;
int start_x;
int inp;
int tab_plansza[17][17];
postac gracz;

int kosc(int x) { return rand() % x + 1; }


void intro()
{
	WINDOW *wintro=newwin(29, 71, 4, 2);
	box(wintro, 0, 0);
	mvwprintw(wintro, 3, 2, "                                                              000  ");
	mvwprintw(wintro, 4, 2, "                                                             00000 ");
	mvwprintw(wintro, 5, 2, "^           ^                  ^     ^          ^             000  ");
	mvwprintw(wintro, 6, 2, "^^  ^^     ^^^         ^     ^ ^^   ^^^        ^^^       ^      ^  ");
	mvwprintw(wintro, 7, 2, "^^ ^^^^   ^^^^^       ^^^   ^^^^^^ ^^^^^      ^^^^^     ^^^    ^^^ ");
	mvwprintw(wintro, 8, 2, "^ ^^^^^^ ^^^^^^^   ^ ^^^^^ ^^^^^^^^ ^^^^^   ^^^^^^^^   ^^^^^^ ^^^^^");
	mvwprintw(wintro, 9, 2, " ^^^^^^ # # # # ^^ ^^^^ # # # # ^^^^^ # # # # ^^^^^^^ # # # # ^ ^^^^");
	mvwprintw(wintro, 10, 2, "^^^^^^^ ##### ^^ ^^^^^^ ##### ^^^^^^^ ##### ^^^^^ ^^^ ##### ^^^ ^^^");
	mvwprintw(wintro, 11, 2, "^^^^^^^ ## ## ^ ^^^^^^^ ## ## ^^^^^^^ ## ## ^^^ ^^^^^ ## ## ^^^^ ^^");
	mvwprintw(wintro, 12, 2, "# # # # ##### # # # # # ##### # # # # ##### # # # # # ##### # # # #");
	mvwprintw(wintro, 13, 2, "#################################+#################################");
	mvwprintw(wintro, 14, 2, "###############################+++++###############################");
	mvwprintw(wintro, 15, 2, "###############################+++++###############################");
	mvwprintw(wintro, 16, 2, "###############################+++++###############################");
	mvwprintw(wintro, 20, 2, "       ***                ***           ***     ***             ***");
	mvwprintw(wintro, 21, 2, "     *******            *******       ******* *******          ****");
	mvwprintw(wintro, 22, 2, "     *******  ***       *******       ******* *******  ***     ****");
	mvwprintw(wintro, 23, 2, "      *****  *****       *****         *****   *****  *****     *#*");
	mvwprintw(wintro, 24, 2, "        #     ***          #             #       #     ***       # ");
	mvwprintw(wintro, 25, 2, "........#......#...........#.............#.......#......#........#.");
	refresh();
	wrefresh(wintro);
	WINDOW *wgracz = newwin(3,5, 21, 4);
	mvwprintw(wgracz,0,1,"_o_");
	mvwprintw(wgracz,1,1,",^,");
	mvwprintw(wgracz,2,1,"   ");
	move(0,0);
	for (int i=4; i<36; i++) {
		mvwin(wgracz, 21,i);
		wrefresh(wgracz);
		usleep(150000);
	}
	usleep(350000);
	for (int i=0;i<3;i++){
		mvwprintw(wintro, 16-i, 33, "     ");
		wrefresh(wintro);
		usleep(250000);
	}
	usleep(800000);
	for (int i=21; i>17; i--) {
		mvwin(wgracz, i,35);
		wrefresh(wgracz);
		usleep(180000);
	}
	wclear(wgracz);
	delwin(wgracz);
	wrefresh(wintro);
	for (int i=0;i<3;i++){
		mvwprintw(wintro, 14+i, 33, "+++++");
		wrefresh(wintro);
		usleep(250000);
	}
	usleep(800000);
	wclear(wintro);
	wrefresh(wintro);
mvwprintw(wintro, 1, 32, "WITAJ");//5
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 3, 19, "Przed Toba podroz po labiryncie.");//32 
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 5, 16, "Do poruszania postaci uzywaj strzalek,");//39
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 6, 11, "klawiszem x wychodzisz z gry, a m wywoluje menu.");//48
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 8, 16, "Twoja postac opisuje kilka statystyki:");//38
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 10, 20, "ZYCIE - okresla twoja witalnosc,");//32
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 11, 17, "jezeli spadnie do zera, konczysz gre;");//37
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 12, 20, "SILA - to twoja sile fizyczna,");//30
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 13, 10, "potrzebna do walki z wojownikiem oraz straznikiem;");//50
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 14, 21, "MOC - to twoja moc mentalna,");//28
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 15, 13, "potrzebna do walki z magiem oraz straznikiem;");//45
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 17, 9, "W czasie gry spotkasz nastepujace typy przeciwnikow:");//52
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 18, 6, "wojownik - atakuje sila, gdy go zabijesz znajdziesz ZLOTO;");//58
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 19, 7, "mag - atakuje moca, po jego smierci masz szanse na ZYCIE;");//57
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 20, 6, "straznik - walczy z polaczonymi statystykami sily i mocy,");//58
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 21, 14, "po jego zabiciu dostaniesz KLUCZ do bramy;");//42
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 23, 3, "Dodatkowo mozesz znalesc kufry ze zlotem, kluczem lub eliksirami.");//65
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 25, 13, "Do przejscia przez brame potrzebujesz klucza.");//45
wrefresh(wintro);
usleep(600000);
mvwprintw(wintro, 27, 30, "POWODZENIA!");//11
wrefresh(wintro);
usleep(600000);
	getch();
	wclear(wintro);
	delwin(wintro);
}


void setup() {
  clear();
  KoniecGry = false;
  plansza_x = width;
  plansza_y = height;
  plansza_mx = width;
  plansza_my = height;
  inp = 1;
  gracz.zerowanie();
  wczytaj_mape();
  refresh();
}

int menu_input() {
  WINDOW *winmenu = newwin(7, 12, 16, 30);
  box(winmenu, 0, 0);
  refresh();
  wrefresh(winmenu);
  keypad(winmenu, true);
  std::string wybory[5] = {"WZNOW", "NOWA_GRA", "ZAPISZ", "WCZYTAJ", "WYJDZ"};
  int wybor;
  int menu = 0;

  while (1) {
    for (int i = 0; i < 5; i++) {
      if (i == menu)
        wattron(winmenu, A_REVERSE);
      mvwprintw(winmenu, i + 1, 2, wybory[i].c_str());
      wattroff(winmenu, A_REVERSE);
    }
    wybor = wgetch(winmenu);
    switch (wybor) {
    case KEY_UP:
      menu--;
      if (menu == -1)
        menu = 4;
      break;
    case KEY_DOWN:
      menu++;
      if (menu == 5)
        menu = 0;
      break;
    default:
      break;
    }
    okno nmanu;
    WINDOW *wnmanu = newwin(nmanu.kolumny, nmanu.wiersze, nmanu.x, nmanu.y);
    box(wnmanu, 0, 0);

    switch (menu) {
    case 0:
      mvwprintw(wnmanu, 2, 3, "Wznow gre");
      break;
    case 1:
      mvwprintw(wnmanu, 2, 3, "Rozpocznij nowa gre");
      break;
    case 2:
      mvwprintw(wnmanu, 2, 3, "Zapisz gre");
      break;
    case 3:
      mvwprintw(wnmanu, 2, 3, "Wczytaj");
      break;
    case 4:
      mvwprintw(wnmanu, 2, 3, "Wyjdz z gry");
      break;
    default:
      break;
    }
    if (wybor == 10)
      break;
    wrefresh(wnmanu);
  }
  wclear(winmenu);
  delwin(winmenu);
  return menu;
}
void czyszczenie() {
  okno okno;
  WINDOW *wokno = newwin(okno.kolumny, okno.wiersze, okno.x, okno.y);
  wclear(wokno);
  wrefresh(wokno);
  delwin(wokno);
}
void draw(int tab_plansza[17][17]) {
  start_y = 2;
  start_x = 4;
  stat();
  WINDOW *plansza =
      newwin(plansza_x * 2 + 2, plansza_y * 4 + 2, start_y, start_x);
  for (int i = 0; i < height; i++) {
    for (int j = 0; j < width; j++) {
      if (tab_plansza[i][j] == 1) { // sciana
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "XXX");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, "XXX");
      }

      if (tab_plansza[i][j] == 2) { // las
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "#|#");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, "|#|");
      }

      if (tab_plansza[i][j] == 3) { // gory
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "^ ^");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, "^^^");
      }

      if (tab_plansza[i][j] == 4) { // przejscie do nastepnej planszy
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "T^T");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, "|_|");
      }
      if (tab_plansza[i][j] == 5) { // skrzynia
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "___");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, "|_|");
      }
      if (tab_plansza[i][j] == 6) { // mag
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "_m_");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, ",O,");
      }

      if (tab_plansza[i][j] == 7) { // wojownik
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "_w_");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, ",X,");
      }

      if (tab_plansza[i][j] == 8) { // straznik
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "_o_");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, ",S,");
      }

      if (tab_plansza[i][j] == 9) { // drzwi
        mvwprintw(plansza, i * 2 + 1, j * 4 + 2, "/X\\");
        mvwprintw(plansza, i * 2 + 2, j * 4 + 2, "|X|");
      }
    }
  }
  refresh();
  box(plansza, 0, 0);
  mvwprintw(plansza, 0, plansza_y / 2 - 3, "poziom %d", gracz.poziom);
  WINDOW *Gracz = newwin(2, 4, gracz.x * 2 + 1, gracz.y * 4 + 1);
  mvwprintw(Gracz, 0, 1, "_o_");
  mvwprintw(Gracz, 1, 1, ",^,");
  wrefresh(plansza);
  wrefresh(Gracz);
}

void stat() {
  mvprintw(38, 5, "\t\t\t\t\t\t\t\t\t\t");
  mvprintw(38, 5, "ZYCIE %d  \t SILA %d \tMOC %d  \tZLOTO %d \tKLUCZ %d",
           gracz.hp, gracz.sila, gracz.moc, gracz.zloto, gracz.klucz);
  refresh();
}

int input() {
  int input, inp;
  input = getch();
  keypad(stdscr, true);
  switch (input) {
  case 'x':
    inp = 8; // exit
    break;
  case 'm':
    inp = 7; // menu
    break;
  case KEY_UP:
    inp = 0;
    break;
  case KEY_DOWN:
    inp = 6;
    break;
  case KEY_LEFT:
    inp = 3;
    break;
  case KEY_RIGHT:
    inp = 9;
    break;
  default:
    inp = 1;
    break;
  }
  return inp;
}

void interakcja(postac &gracz, int inp, int tab_plansza[17][17]) {
  switch (inp) {
  case 0:
    gracz.x--;
    if (gracz.x < 2 || czy_mozna(gracz) == 1)
      gracz.x++;
    break;
  case 6:
    gracz.x++;
    if (gracz.x > plansza_mx - 1 || czy_mozna(gracz) == 1)
      gracz.x--;
    break;
  case 3:
    gracz.y--;
    if (gracz.y < 2 || czy_mozna(gracz) == 1)
      gracz.y++;
    break;
  case 9:
    gracz.y++;
    if (gracz.y > plansza_my - 1 || czy_mozna(gracz) == 1)
      gracz.y--;
    break;
  default:
    break;
  }
  switch (tab_plansza[gracz.x - 1][gracz.y - 1]) {
  case 2:
    las(gracz);
    break;
  case 3:
    gory(gracz);
    break;
  case 4:
    gracz.mapa++;
    gracz.poziom++;
    sklep();
    wczytaj_mape();
    gracz.x = 2;
    gracz.y = 2;
    break;
  case 5:
    kufer(gracz);
    break;
  default:
    break;
  }
}

int czy_mozna(postac &gracz) {
  int powrot = 0;
  switch (tab_plansza[gracz.x - 1][gracz.y - 1]) {
  case 1:
    powrot = 1;
    break;
  case 6:
    powrot = mwalka(gracz);
    break;
  case 7:
    powrot = wwalka(gracz);
    ;
    break;
  case 8:
    powrot = swalka(gracz);
    ;
    break;
  case 9:
    powrot = drzwi(gracz);
    break;
  default:
    break;
  }
  return powrot;
}

int mwalka(postac &gracz) {
  int zwrot;
  okno mwalka(10, 36, 10, 21);
  WINDOW *wmwalka = newwin(mwalka.kolumny, mwalka.wiersze, mwalka.x, mwalka.y);
  box(wmwalka, 0, 0);
  mag m1;
  int lvl = 3 * (1 + gracz.poziom) - 2;
  m1.poziom(kosc(1 + gracz.poziom)+lvl);
  while (!gracz.smierc && !m1.smierc) {
    wclear(wmwalka);
    box(wmwalka, 0, 0);
    if (gracz.hp < 1)
      gracz.smierc = true;
    else if (m1.hp < 1)
      m1.smierc = true;
    int wynik = walka(m1.moc, gracz.moc);
    if (wynik > 0) {
      mvwprintw(wmwalka, 2, 2, "przeciwnik cie pokonal");
      mvwprintw(wmwalka, 3, 2, "twoje ZYCIE obniza sie o %d", wynik / 2);
      gracz.hp -= wynik / 2;
    } else if (wynik == 0) {
      mvwprintw(wmwalka, 2, 2, "remis...");
    } else {
      wynik = -wynik;
      mvwprintw(wmwalka, 2, 2, "pokonales przeciwnika");
      mvwprintw(wmwalka, 3, 2, "jego ZYCIE obniza sie o %d", wynik / 2);
      m1.hp -= wynik / 2;
    }
    mvwprintw(wmwalka, 6, 5, "gracz\tmag");
    mvwprintw(wmwalka, 7, 5, "atak:%d\tatak %d", gracz.moc, m1.moc);
    mvwprintw(wmwalka, 8, 5, "zycie:%d\tzycie: %d", gracz.hp, m1.hp);
    wrefresh(wmwalka);
    stat();
  }
  wclear(wmwalka);
  box(wmwalka, 0, 0);
  if (m1.smierc == true) {
    int loot = kosc(5) + 2;
    gracz.hp += loot;
    mvwprintw(wmwalka, 2, 2, "pokonales przeciwnika, znalazles");
    mvwprintw(wmwalka, 3, 2, "ELIKSIR ktory przywraca %d ZYCIA", loot);
    tab_plansza[gracz.x - 1][gracz.y - 1] = 0;
    gracz.expm += m1.moc;
    if (gracz.expm > 20) {
      gracz.moc++;
      gracz.expm -= 20;
      mvwprintw(wmwalka, 4, 2, "zdobywasz punkt MOCY    ");
    }
    zwrot = 0;
  } else {
    zwrot = 1;
    mvwprintw(wmwalka, 2, 2, "przegrywasz walke");
  }
  wrefresh(wmwalka);
  usleep(300000);
  getch();
  delwin(wmwalka);
  return zwrot;
}

int wwalka(postac &gracz) {
  int zwrot;
  okno wwalka(10, 36, 10, 21);
  WINDOW *wwwalka = newwin(wwalka.kolumny, wwalka.wiersze, wwalka.x, wwalka.y);
  box(wwwalka, 0, 0);
  woj w1;
  int lvl = 3 * (1 + gracz.poziom) - 2;
  w1.poziom(kosc(1 + gracz.poziom)+lvl);
  while (!gracz.smierc && !w1.smierc) {
    wclear(wwwalka);
    box(wwwalka, 0, 0);
    if (gracz.hp < 1)
      gracz.smierc = true;
    else if (w1.hp < 1)
      w1.smierc = true;
    int wynik = walka(w1.sila, gracz.sila);
    if (wynik > 0) {
      mvwprintw(wwwalka, 2, 2, "przeciwnik cie pokonal");
      mvwprintw(wwwalka, 3, 2, "twoje ZYCIE obniza sie o %d", wynik / 2);
      gracz.hp -= wynik / 2;
    } else if (wynik == 0) {
      mvwprintw(wwwalka, 2, 2, "remis...");
    } else {
      wynik = -wynik;
      mvwprintw(wwwalka, 2, 2, "pokonales przeciwnika");
      mvwprintw(wwwalka, 3, 2, "jego ZYCIE obniza sie o %d", wynik / 2);
      w1.hp -= wynik / 2;
    }
    mvwprintw(wwwalka, 6, 5, "gracz\twojownik");
    mvwprintw(wwwalka, 7, 5, "atak:%d\tatak %d", gracz.sila, w1.sila);
    mvwprintw(wwwalka, 8, 5, "zycie:%d\tzycie: %d", gracz.hp, w1.hp);
    wrefresh(wwwalka);
    stat();
  }
  wclear(wwwalka);
  box(wwwalka, 0, 0);
  if (w1.smierc == true) {
    int loot = kosc(10) + 10;
    gracz.zloto += loot;
    mvwprintw(wwwalka, 2, 2, "pokonales przeciwnika,");
    mvwprintw(wwwalka, 3, 2, "znalazles  %d ZLOTA", loot);
    tab_plansza[gracz.x - 1][gracz.y - 1] = 0;
    gracz.exps += w1.sila;
    if (gracz.exps > 20) {
      gracz.sila++;
      gracz.exps -= 20;
      mvwprintw(wwwalka, 2, 2, "zdobywasz punkt SILY   ");
    }
    zwrot = 0;
  } else {
    zwrot = 1;
    mvwprintw(wwwalka, 2, 2, "przegrywasz walke");
  }
  wrefresh(wwwalka);
  usleep(200000);
  getch();
  delwin(wwwalka);
  return zwrot;
}

int swalka(postac &gracz) {
  int zwrot;
  okno swalka(10, 40, 10, 21);
  WINDOW *wswalka = newwin(swalka.kolumny, swalka.wiersze, swalka.x, swalka.y);
  box(wswalka, 0, 0);
  str s1;
  int lvl = 6 * (1 + gracz.poziom) - 5;
  s1.poziom(kosc(3 + gracz.poziom)+lvl);
  switch (kosc(2) + 1) {
  case 1:
    mvwprintw(wswalka, 2, 2, "atakuje cie straszny mag");
    break;
  case 2:
    mvwprintw(wswalka, 2, 2, "atakuje cie wielki wojownik");
    break;
  }
  while (!gracz.smierc && !s1.smierc) {
    wclear(wswalka);
    box(wswalka, 0, 0);
    if (gracz.hp < 1)
      gracz.smierc = true;
    else if (s1.hp < 1)
      s1.smierc = true;
    int wynik = walka(s1.atak, gracz.sila + gracz.moc);
    if (wynik > 0) {
      mvwprintw(wswalka, 2, 2, "przeciwnik cie pokonal");
      mvwprintw(wswalka, 3, 2, "twoje ZYCIE obniza sie o %d", wynik / 2);
      gracz.hp -= wynik / 2;
    } else if (wynik == 0) {
      mvwprintw(wswalka, 2, 2, "remis...");
    } else {
      wynik = -wynik;
      mvwprintw(wswalka, 2, 2, "pokonales przeciwnika");
      mvwprintw(wswalka, 3, 2, "jego ZYCIE obniza sie o %d", wynik / 2);
      s1.hp -= wynik / 2;
    }
    mvwprintw(wswalka, 6, 5, "gracz\tstraznik");
    mvwprintw(wswalka, 7, 5, "atak:%d\tatak %d", gracz.sila + gracz.moc,
              s1.atak);
    mvwprintw(wswalka, 8, 5, "zycie:%d\tzycie: %d", gracz.hp, s1.hp);
    wrefresh(wswalka);
    stat();
  }
  wclear(wswalka);
  box(wswalka, 0, 0);
  if (s1.smierc == true) {
    int loot = kosc(2);
    gracz.klucz += loot;
    mvwprintw(wswalka, 2, 2, "pokonales przeciwnika,");
    mvwprintw(wswalka, 3, 2, "znalazles %d kluczy", loot);
    tab_plansza[gracz.x - 1][gracz.y - 1] = 0;
    gracz.expm += s1.atak / 2;
    gracz.exps += s1.atak / 2;
    if (gracz.exps > 20) {
      gracz.sila++;
      gracz.exps -= 20;
      mvwprintw(wswalka, 4, 2, "zdobywasz punkt SILY   ");
    }
    if (gracz.expm > 20) {
      gracz.moc++;
      gracz.expm -= 20;
      mvwprintw(wswalka, 4, 2, "zdobywasz punkt MOCY   ");
    }
    zwrot = 0;
  } else {
    zwrot = 1;
    mvwprintw(wswalka, 2, 2, "przegrywasz walke");
  }
  wrefresh(wswalka);
  usleep(300000);
  getch();
  delwin(wswalka);
  return zwrot;
}

int walka(int przeciwnik, int gracz) {
  int kosc_przeciwnik = kosc(6);
  int kosc_gracz = kosc(7);
  okno walka;
  WINDOW *wwalka = newwin(walka.kolumny, walka.wiersze, walka.x, walka.y);
  wclear(wwalka);
  box(wwalka, 0, 0);
  if (kosc_przeciwnik == 6) {
    kosc_przeciwnik += 5;
    przeciwnik += kosc_przeciwnik;
    mvwprintw(wwalka, 2, 4, "przeciwnik zadal cios krytyczny!!!  wynik: %d",
              przeciwnik);
  } else {
    przeciwnik += kosc_przeciwnik;
    mvwprintw(wwalka, 2, 4, "przeciwnik zadal:  wynik: %d", przeciwnik);
  }
  if (kosc_gracz == 6) {
    kosc_gracz += 5;
    gracz += kosc_gracz;
    mvwprintw(wwalka, 3, 4, "zadales przeciwnikowi cios krytyczny!!! wynik: %d",
              gracz);
  } else {
    gracz += kosc_gracz;
    mvwprintw(wwalka, 3, 4, "zadales przeciwnikowi : %d", gracz);
  }
  wrefresh(wwalka);
  usleep(300000);
  delwin(wwalka);
  return przeciwnik - gracz;
}

int drzwi(postac &gracz) {
  int zwrot;
  if (gracz.klucz > 0) {
    gracz.klucz--;
    tab_plansza[gracz.x - 1][gracz.y - 1] = 0;
    zwrot = 0;
  } else
    zwrot = 1;
  return zwrot;
}

void las(postac &gracz) {
  okno las;
  WINDOW *wlas = newwin(las.kolumny, las.wiersze, las.x, las.y);
  box(wlas, 0, 0);
  int wynik = kosc(10);
  if (wynik < 3) {
    mvwprintw(wlas, 2, 4, "wedrujac przez las, znalazles jagody");
    mvwprintw(wlas, 3, 7, "twoje ZYCIE wzroslo o 1");
    gracz.hp++;
  } else if (wynik == 3) {
    mvwprintw(wlas, 2, 4, "wedrujac przez las, zaatakowal Cie krolik");
    mvwprintw(wlas, 3, 7, "tracisz jeden punkt ZYCIA");
    gracz.hp--;
  } else {
    mvwprintw(wlas, 2, 4, "spacerujesz przez las");
  }
  wrefresh(wlas);
  delwin(wlas);
}

void gory(postac &gracz) {
  okno gory;
  WINDOW *wgory = newwin(gory.kolumny, gory.wiersze, gory.x, gory.y);
  box(wgory, 0, 0);
  int wynik = kosc(10);
  if (wynik < 3) {
    mvwprintw(wgory, 2, 4, "wedrujac po gorach, spostrzegles cos blyszczacego");
    mvwprintw(wgory, 3, 7, "znalazles troche ZLOTA");
    gracz.zloto += kosc(3);
  } else if (wynik == 3) {
    mvwprintw(wgory, 2, 4,
              "wedrujac po gorach, potknales sie i skreciles kostke");
    mvwprintw(wgory, 3, 7, "tracisz jeden punkt ZYCIA");
    gracz.hp--;
  } else {
    mvwprintw(wgory, 2, 4, "wedrujesz po gorach");
  }
  wrefresh(wgory);
  delwin(wgory);
}

void kufer(postac &gracz) {
  okno kufer;
  WINDOW *wkufer = newwin(kufer.kolumny, kufer.wiersze, kufer.x, kufer.y);
  box(wkufer, 0, 0);
  int wynik = kosc(10);
  int los = kosc(10);
  mvwprintw(wkufer, 2, 4, "odkryles stary kufer %d", los);
  switch (los) {
  case 1:
    mvwprintw(wkufer, 3, 4, "znalazles eliksir SILY  ");
    gracz.sila++;
    break;
  case 2:
    mvwprintw(wkufer, 3, 4, "znalazles eliksir MOCY  ");
    gracz.moc++;
    break;
  case 3:
    mvwprintw(wkufer, 3, 4, "znalazles klucz");
    gracz.klucz++;
    break;
  }

  if (los >= 4 and los <= 5) {
    mvwprintw(wkufer, 3, 4, "znalazles eliksir ZYCIA  ");
    gracz.hp += wynik + 5;
  }
  if (los > 5) {
    mvwprintw(wkufer, 3, 4, "w srodku znalazles %d ZLOTA,", wynik * 2 + 5);
    gracz.zloto += wynik * 2 + 5;
  }
  tab_plansza[gracz.x - 1][gracz.y - 1] = 0;
  wrefresh(wkufer);
  delwin(wkufer);
}
void sklep() {
  int menu = 0;
  int zakup;
  okno sklep(19, 38, 12, 20);
  WINDOW *wsklep = newwin(sklep.kolumny, sklep.wiersze, sklep.x, sklep.y);
  box(wsklep, 0, 0);
  mvwprintw(wsklep, 1, 1, "************************************");
  mvwprintw(wsklep, 2, 1, "****************    ****************");
  mvwprintw(wsklep, 3, 1, "******   *****        **************");
  mvwprintw(wsklep, 4, 1, "******   *                **********");
  mvwprintw(wsklep, 5, 1, "******   +++++++++++++++++   *******");
  mvwprintw(wsklep, 6, 1, "****     +++++ SKLEP +++++      ****");
  mvwprintw(wsklep, 7, 1, "***      +++++++++++++++++       ***");
  mvwprintw(wsklep, 8, 1, "****                            ****");
  mvwprintw(wsklep, 9, 1, "****    ******        *******   ****");
  mvwprintw(wsklep, 10, 1, "****    ******        *******   ****");
  mvwprintw(wsklep, 11, 1, "****    ******        *******   ****");
  mvwprintw(wsklep, 12, 1, "****    ******        *******   ****");
  mvwprintw(wsklep, 13, 1, "****                  *******   ****");
  mvwprintw(wsklep, 14, 1, "****                  *******   ****");
  mvwprintw(wsklep, 15, 1, "****                  *******   ****");
  mvwprintw(wsklep, 16, 1, "****..................*******...****");
  mvwprintw(wsklep, 17, 1, "....................................");
  wrefresh(wsklep);
  getch();
  do {
    zakup = sklep_menu(menu);
    switch (zakup) {
    case 0:
      if (gracz.zloto >= 50) {
        gracz.zloto -= 50;
        gracz.hp += 10;
        mvwprintw(wsklep, 6, 10, "+ KUPILES ZYCIE +");
      } else
        mvwprintw(wsklep, 6, 10, "+  BRAK  ZLOTA  +");
      break;
    case 1:
      if (gracz.zloto >= 100) {
        gracz.zloto -= 100;
        gracz.sila += 1;
        mvwprintw(wsklep, 6, 10, "+ KUPILES  SILE +");
      } else
        mvwprintw(wsklep, 6, 10, "+  BRAK  ZLOTA  +");
      break;
    case 2:
      if (gracz.zloto >= 100) {
        gracz.zloto -= 100;
        gracz.moc += 1;
        mvwprintw(wsklep, 6, 10, "+  KUPILES MOC  +");
      } else
        mvwprintw(wsklep, 6, 10, "+  BRAK  ZLOTA  +");
      break;
    }
    wrefresh(wsklep);
    stat();
  } while (zakup != 3);
  delwin(wsklep);
}

int sklep_menu(int menu) {
  WINDOW *winmenu = newwin(7, 12, 20, 33);
  box(winmenu, 0, 0);
  refresh();
  wrefresh(winmenu);
  keypad(winmenu, true);
  std::string wybory[5] = {"KUP ZYCIE", "KUP SILE", "KUP MOC", "WYJDZ"};
  int wybor;

  while (1) {
    for (int i = 0; i < 4; i++) {
      if (i == menu)
        wattron(winmenu, A_REVERSE);
      mvwprintw(winmenu, i + 1, 2, wybory[i].c_str());
      wattroff(winmenu, A_REVERSE);
    }
    wybor = wgetch(winmenu);
    switch (wybor) {
    case KEY_UP:
      menu--;
      if (menu == -1)
        menu = 3;
      break;
    case KEY_DOWN:
      menu++;
      if (menu == 4)
        menu = 0;
      break;
    default:
      break;
    }
    if (wybor == 10)
      break;
    okno nmanu;
    WINDOW *wnmanu = newwin(nmanu.kolumny, nmanu.wiersze, nmanu.x, nmanu.y);
    box(wnmanu, 0, 0);
    switch (menu) {
    case 0:
      mvwprintw(wnmanu, 2, 3, "Kup elixir ZYCIA");
      mvwprintw(wnmanu, 3, 3, "Dodaje 10 punktow");
      mvwprintw(wnmanu, 4, 3, "koszt 50 ZLOTA");
      break;
    case 1:
      mvwprintw(wnmanu, 2, 3, "Kup elixir SILY");
      mvwprintw(wnmanu, 3, 3, "Dodaje 1 punkt");
      mvwprintw(wnmanu, 4, 3, "koszt 100 ZLOTA");
      break;
    case 2:
      mvwprintw(wnmanu, 2, 3, "Kup elixir MOCY");
      mvwprintw(wnmanu, 3, 3, "Dodaje 1 punkt");
      mvwprintw(wnmanu, 4, 3, "koszt 100 ZLOTA");
      break;
    case 3:
      mvwprintw(wnmanu, 2, 3, "Odejdz od sklepu");
      break;
    }
    wrefresh(wnmanu);
  }
  wclear(winmenu);
  delwin(winmenu);
  return menu;
}

void wczytaj_mape() {
  if (gracz.mapa > 10)
    gracz.mapa=0;
  int pozycja_pliku = 578 * gracz.mapa;
  std::fstream plik;
  plik.open("source/plansze.bin", std::ios::binary | std::ios::in);
  if (plik.is_open()) {
    plik.seekg(pozycja_pliku, std::ios::beg);
    for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 17; j++) {
        plik >> tab_plansza[i][j];
      }
    }
    plik.close();
  } else
    std::cout << "Blad wczytywania!!!" << std::endl;
}

void koniec() {
  okno koniec(24, 35, 8, 22);
  WINDOW *koniec_gry =
      newwin(koniec.kolumny, koniec.wiersze, koniec.x, koniec.y);
  box(koniec_gry, 0, 0);
  mvwprintw(koniec_gry, 3, 1, "     XXXXXXXXXXXXXXXXXXXXXXX     ");
  mvwprintw(koniec_gry, 4, 1, "     XXXXXXXX       XXXXXXXX     ");
  mvwprintw(koniec_gry, 5, 1, "     XXXXX             XXXXX     ");
  mvwprintw(koniec_gry, 6, 1, "     XXXX               XXXX     ");
  mvwprintw(koniec_gry, 7, 1, "     XXX                 XXX     ");
  mvwprintw(koniec_gry, 8, 1, "     XXX   XXXX   XXXX   XXX     ");
  mvwprintw(koniec_gry, 9, 1, "     XXX   XXXX   XXXX   XXX     ");
  mvwprintw(koniec_gry, 10, 1, "     XXXX    XX   XX    XXXX     ");
  mvwprintw(koniec_gry, 11, 1, "     XXXX       X       XXXX     ");
  mvwprintw(koniec_gry, 12, 1, "     XXXXXX    XXX     XXXXX     ");
  mvwprintw(koniec_gry, 13, 1, "     XXXXXXX   X X   XXXXXXX     ");
  mvwprintw(koniec_gry, 14, 1, "     XXXXXXX         XXXXXXX     ");
  mvwprintw(koniec_gry, 15, 1, "     XXXXXXXxX X X XxXXXXXXX     ");
  mvwprintw(koniec_gry, 16, 1, "     XXXXXXXXXXXXXXXXXXXXXXX     ");
  mvwprintw(koniec_gry, 17, 1, "     XXXX...............XXXX     ");
  mvwprintw(koniec_gry, 18, 1, "     XXXX..KONIEC..GRY..XXXX     ");
  mvwprintw(koniec_gry, 19, 1, "     XXXX...............XXXX     ");
  mvwprintw(koniec_gry, 20, 1, "     XXXXXXXXXXXXXXXXXXXXXXX     ");
  wrefresh(koniec_gry);
  usleep(300000);
  getch();
  delwin(koniec_gry);
}

void zapisz() {
  okno zapis;
  WINDOW *wzapis = newwin(zapis.kolumny, zapis.wiersze, zapis.x, zapis.y);
  box(wzapis, 0, 0);
  std::fstream zapis_plik;
  zapis_plik.open("source/zapis.sav", std::ios::binary | std::ios::out);
  if (zapis_plik.is_open()) {
    zapis_plik.seekg(0, std::ios::beg);
    for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 17; j++)
        zapis_plik << tab_plansza[i][j] << " ";
    }
    zapis_plik << gracz.x << " " << gracz.y << " " << gracz.hp << " "
               << gracz.sila << " " << gracz.moc << " " << gracz.exps << " "
               << gracz.expm << " " << gracz.zloto << " " << gracz.klucz << " "
               << gracz.poziom << " ";
    mvwprintw(wzapis, 2, 3, "Gra zapisana");
    zapis_plik.close();
  } else
    mvwprintw(wzapis, 2, 3, "Blad zapisu");
  wrefresh(wzapis);
  delwin(wzapis);
}

void wczytaj() {
  okno wczytywanie;
  WINDOW *wwczytywanie = newwin(wczytywanie.kolumny, wczytywanie.wiersze,
                                wczytywanie.x, wczytywanie.y);
  box(wwczytywanie, 0, 0);
  std::fstream wczytywanie_plik;
  wczytywanie_plik.open("source/zapis.sav", std::ios::binary | std::ios::in);
  if (wczytywanie_plik.is_open()) {
    wczytywanie_plik.seekg(0, std::ios::beg);
    for (int i = 0; i < 17; i++) {
      for (int j = 0; j < 17; j++)
        wczytywanie_plik >> tab_plansza[i][j];
    }
    wczytywanie_plik >> gracz.x >> gracz.y >> gracz.hp >> gracz.sila >>
        gracz.moc >> gracz.exps >> gracz.expm >> gracz.zloto >> gracz.klucz >>
        gracz.poziom;
    mvwprintw(wwczytywanie, 2, 3, "Gra zapisana");
    wczytywanie_plik.close();
  } else
    mvwprintw(wwczytywanie, 2, 3, "Blad zapisu");
  wrefresh(wwczytywanie);
  delwin(wwczytywanie);
}
