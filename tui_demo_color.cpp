#include <ncurses.h>
#include <vector>
#include <string>

void print_menu(WINDOW *menu_win, int highlight, const std::vector<std::string> &choices);

int main() {
    initscr();            // Start curses mode
    clear();
    noecho();
    cbreak();             // Disable line buffering
    start_color();        // Start color functionality

    // Define color pairs
    init_pair(1, COLOR_RED, COLOR_BLACK);
    init_pair(2, COLOR_GREEN, COLOR_BLACK);
    init_pair(3, COLOR_BLUE, COLOR_BLACK);
    init_pair(4, COLOR_YELLOW, COLOR_BLACK);
    init_pair(5, COLOR_WHITE, COLOR_BLACK);

    int startx = 0, starty = 0;

    std::vector<std::string> choices = {"Option 1", "Option 2", "Option 3", "Exit"};
    int n_choices = choices.size();
    int highlight = 1;
    int choice = 0;
    int c;

    WINDOW *menu_win = newwin(7, 12, starty, startx);
    keypad(menu_win, TRUE);
    mvprintw(0, 0, "Use arrow keys to navigate, press Enter to select");
    refresh();

    while (true) {
        print_menu(menu_win, highlight, choices);
        c = wgetch(menu_win);
        switch (c) {
            case KEY_UP:
                if (highlight == 1)
                    highlight = n_choices;
                else
                    --highlight;
                break;
            case KEY_DOWN:
                if (highlight == n_choices)
                    highlight = 1;
                else
                    ++highlight;
                break;
            case 10: // Enter key
                choice = highlight;
                if (choices[choice - 1] == "Exit") {
                    endwin();
                    return 0;
                }
                attron(COLOR_PAIR(choice));  // Set color based on choice
                mvprintw(23, 0, "You chose option %d with choice string %s", choice, choices[choice - 1].c_str());
                attroff(COLOR_PAIR(choice)); // Turn off color
                clrtoeol();
                refresh();
                break;
            default:
                mvprintw(24, 0, "Character pressed is = %3d", c);
                clrtoeol();
                refresh();
                break;
        }
    }
}

void print_menu(WINDOW *menu_win, int highlight, const std::vector<std::string> &choices) {
    int x, y, i;
    x = 2;
    y = 2;
    box(menu_win, 480, 480);
    for (i = 0; i < choices.size(); ++i) {
        if (highlight == i + 1) {
            wattron(menu_win, A_REVERSE | COLOR_PAIR(4)); // Highlight color
            mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
            wattroff(menu_win, A_REVERSE | COLOR_PAIR(4));
        } else {
            wattron(menu_win, COLOR_PAIR(2));  // Regular color
            mvwprintw(menu_win, y, x, "%s", choices[i].c_str());
            wattroff(menu_win, COLOR_PAIR(2));
        }
        ++y;
    }
    wrefresh(menu_win);
}

