#pragma once

/* ВАЖНО:
 * Чтобы LPCTSTR был wide при UNICODE-сборке, UNICODE должен быть определён
 * ДО windows.h. Поэтому мы не ставим здесь #define UNICODE — это делаем флагом компилятора.
 */

#include <windows.h>
#include <commctrl.h>

/* Некоторые версии commctrl.h (mingw-w64) скрывают NMTVITEMCHANGE при _WIN32_WINNT < 0x0600.
 * wxWidgets 2.8.12 всё равно использует его в src/msw/treectrl.cpp.
 * Для сборки под XP достаточно объявить структуру, если её нет.
 */
#ifndef NMTVITEMCHANGE
typedef struct tagNMTVITEMCHANGE {
    NMHDR     hdr;
    UINT      uChanged;
    HTREEITEM hItem;
    LPARAM    lParam;
    UINT      uStateNew;
    UINT      uStateOld;
} NMTVITEMCHANGE, *LPNMTVITEMCHANGE;
#endif
