#include <stdio.h>
#include <string.h>

struct Date {
    short month, day, year;
};
struct Song { 
    char title[64];
    char artist[32];
    char composer[32];
    short duration; // playing time in secs
    struct Date published;
};

const char *dateAsString(struct Date d)
{
    static char strDate[12];
    sprintf(strDate, "%02d/%02d/%04d", d.month, d.day, d.year);
    return strDate;
}

void printSong(const Song *pSong)
{
    int m = pSong->duration / 60, 
        s = pSong->duration % 60;
    printf( " ===================================\n"
        "Title:\t\t\t%s\n"
        "Artist:\t\t\t%s\n"
        "Composer:\t\t\t%s\n"
        "Playing time:\t\t\t%d:%02d\n"
        "date:\t\t\t%s\n",
        pSong->title, pSong->artist, pSong->composer, m, s,
        dateAsString(pSong->published));
}
typedef struct { struct Cell *pFirst, *pLast; } SongList_t;

typedef struct  Cell { struct Song song; // The record data
                        struct Cell *pNext;  // A pointer to the next record
                        } Cell_t;
int main() 
{
    Song song1, song2, song3, *pSong = &song1, *pSong2 = &song2; 
    strcpy(song1.title, "Havana Club");
    strcpy(song1.artist, "Mark KNopfler");
    strcpy(song1.composer, "Ottmar Liebert");
    song1.duration = 241;
    song1.published = {12,5,1998};
    strcpy(song2.title, "Brewskies");
    strcpy(song2.artist, "Hitler");
    strcpy(song2.composer, "Oftar Liedbust");
    song2.duration = 300;
    song2.published = {9,11,2011};
    strcpy(song3.title, "THird song");
    strcpy(song3.artist, "Human jones");
    strcpy(song3.composer, "Gottfired");
    song3.duration = 243;
    song3.published = {12,5,1998};
    Cell_t first_cell, second_cell, third_cell;
    SongList_t songlist;
    first_cell = {song1, &second_cell};
    second_cell = {song2, &third_cell};
    third_cell = {song3, NULL};

    songlist = {&first_cell, &second_cell };
    printSong(&first_cell.pNext->song);
    printSong(&second_cell.pNext->song);

}