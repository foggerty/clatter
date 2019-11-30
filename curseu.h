#include <ncurses.h>
#include <term.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#ifndef CURSEU_HEADER
#define CURSEU_HEADER

// Displays that capabilities that ncurses (thinks it) provides, based
// off the TERMINFO database.
void dump_capabilities(void);

/*******************************************************************************
  List of constants for querying various capabilities - not a complete
  list, just things that I though might be useful :-)
*******************************************************************************/

// BOOLEANS - tigetflag()
#define CAN_CHANGE           "ccc"    // Terminal can re-define existing colour
#define HAS_META_KEY         "km"     // Has a meta key (shift, sets parity bit)
#define HAS_STATUS_LINE      "hs"     // Has extra "status line"
#define MEMORY_ABOVE         "da"     // Display may be retained above the screen
#define MEMORY_BELOW         "db"     // Display may be retained below the screen

// INTEGERS - tigetnum()
#define BUFFER_CAPACITY      "bufsz"  // Number of bytes buffered before printing
#define BUTTONS              "btns"   // Number of buttons on the mouse
#define MAX_COLORS           "colors" // Maximum number of colours on the screen
#define OUTPUT_RES_CHAR      "orc"    // Horizontal resolution in units per character
#define OUTPUT_RES_LINE      "orl"    // Vertical resolution in units per line
#define OUTPUT_RES_HORZ_INCH "orhi"   // Horizontal resolution in units per inch
#define OUTPUT_RES_VERT_INCH "orvi"   // Vertical resolution in units per inch
#define VIRTUAL_TERMINAL     "vt"     // Virtual terminal number

// STRINGS - tigetstr()
// nothing to see here......


#endif
