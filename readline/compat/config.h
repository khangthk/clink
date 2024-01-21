// Copyright (c) 2012 Martin Ridgers
// License: http://opensource.org/licenses/MIT

#pragma once

#include <conio.h>
#include <io.h>
#include <limits.h>
#include <process.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <wchar.h>
#include <uchar.h>

#if !defined(__cplusplus) && !defined(_MSC_VER)
#define static_assert _Static_assert
#endif

#if defined(BUILD_READLINE) && !defined(__cplusplus)
#include "../../clink/core/include/core/bldopts.h"
#include "../../clink/core/include/core/debugheap.h"
#include <assert.h>
#endif

#include "hooks.h"

int     compare_string(const char* s1, const char* s2, int casefold);

// here be dragons (for purposes of utf-8 and capturing stdio)
//
//
int     hooked_fwrite(const void*, int, int, FILE*);
void    hooked_fprintf(FILE*, const char*, ...);
int     hooked_putc(int, FILE*);
void    hooked_fflush(FILE*);
int     hooked_fileno(FILE*);
int     hooked_stat(const char*, struct hooked_stat*);
int     hooked_lstat(const char*, struct hooked_stat*);
int     hooked_fstat(int, struct hooked_stat*);

#if defined(__MINGW32__)
#   undef fwrite
#   undef fprintf
#   undef putc
#   undef fflush
#   undef fileno
// #   undef mbrtowc
// #   undef mbrlen
#   undef stat
#   undef fstat
#   define __MSDOS__

    // We compile Readline the same way MSVC does for consistency.
#   if defined(BUILD_READLINE)
#       undef __MINGW32__
#   endif

#   define RL_LIBRARY_VERSION "8.1"
#endif

#if defined(BUILD_READLINE)
#   define fwrite           hooked_fwrite
#   define fprintf          hooked_fprintf
#   define putc             hooked_putc
#   define fflush           hooked_fflush
#   define fileno           hooked_fileno
#   define stat             hooked_stat
#   define lstat            hooked_lstat
#   define fstat            hooked_fstat
#endif // BUILD_READLINE

#undef MB_CUR_MAX
#define MB_CUR_MAX  4       // 4-bytes is enough for the Unicode standard.

// msvc vs posix|readline|gnu
//
#if defined(_MSC_VER)
#   define strncasecmp      strnicmp
#   define strcasecmp       _stricmp
#   define strchr           strchr
#   define getpid           _getpid
#   define snprintf         _snprintf

typedef ptrdiff_t           ssize_t;
typedef unsigned short      mode_t;

#   define __STDC__         0
#   define __MSDOS__
/*
#   define __MINGW32__
#   define __WIN32__
*/

#   pragma warning(disable : 4018)  // signed/unsigned mismatch
#   pragma warning(disable : 4090)  // different 'const' qualifiers
#   pragma warning(disable : 4101)  // unreferenced local variable
#   pragma warning(disable : 4244)  // conversion from 'X' to 'Y', possible loss of data
#   pragma warning(disable : 4267)  // conversion from 'X' to 'Y', possible loss of data
#endif // _MSC_VER

#define HAVE_ISASCII 1
#define HAVE_STRCASECMP 1
#define HAVE_WCWIDTH 1
#define HAVE_DIRENT_H 1
#define WCHAR_T_BROKEN 1            // Visual Studio uses 2 byte wchar_t; Readline expects 4 byte wchar_t.

typedef int wcwidth_t (char32_t);
extern wcwidth_t *wcwidth;

#if 0
typedef int wcswidth_t (const char32_t*, size_t);
extern wcswidth_t *wcswidth;
#endif

#define EXTERNAL_COLOR_SUPPORT      // Host provides external color support; avoid compiling unused functions.
#define HAVE_WAIT_FOR_INPUT         // Host provides a wait_for_input(timeout) function.

// What follows was generated by autotools...
//------------------------------------------------------------------------------

/* config.h.  Generated from config.h.in by configure.  */
/* config.h.in.  Maintained by hand. */

/* Template definitions for autoconf */
#define __EXTENSIONS__ 1
#define _ALL_SOURCE 1
#define _GNU_SOURCE 1
/* #undef _POSIX_SOURCE */
/* #undef _POSIX_1_SOURCE */
#define _POSIX_PTHREAD_SEMANTICS 1
#define _TANDEM_SOURCE 1
/* #undef _MINIX */

/* Define NO_MULTIBYTE_SUPPORT to not compile in support for multibyte
   characters, even if the OS supports them. */
/* #undef NO_MULTIBYTE_SUPPORT */

/* #undef _FILE_OFFSET_BITS */

/* Define as the return type of signal handlers (int or void).  */
#define RETSIGTYPE void

#define VOID_SIGHANDLER 1

/* Characteristics of the compiler. */
/* #undef sig_atomic_t */

/* #undef size_t */

#define ssize_t int

/* #undef const */

/* #undef volatile */

#define PROTOTYPES 1
#define __PROTOTYPES 1

/* #undef __CHAR_UNSIGNED__ */

/* Define if the `S_IS*' macros in <sys/stat.h> do not work properly.  */
/* #undef STAT_MACROS_BROKEN */

/* Define if you have the chown function. */
/* #undef HAVE_CHOWN */

/* Define if you have the fcntl function. */
/* #undef HAVE_FCNTL */

/* Define if you have the fnmatch function. */
#define HAVE_FNMATCH 1

/* Define if you have the getpwent function. */
/* #undef HAVE_GETPWENT */

/* Define if you have the getpwnam function. */
/* #undef HAVE_GETPWNAM */

/* Define if you have the getpwuid function. */
/* #undef HAVE_GETPWUID */

/* Define if you have the isascii function. */
/* #undef HAVE_ISASCII */

/* Define if you have the iswctype function.  */
#define HAVE_ISWCTYPE 1

/* Define if you have the iswlower function.  */
#define HAVE_ISWLOWER 1

/* Define if you have the iswupper function.  */
#define HAVE_ISWUPPER 1

/* Define if you have the isxdigit function. */
#define HAVE_ISXDIGIT 1

/* Define if you have the gettimeofday function.*/
/* #undef HAVE_GETTIMEOFDAY */

/* Define if you have the kill function. */
/* #undef HAVE_KILL */

/* Define if you have the lstat function. */
#define HAVE_LSTAT 1

/* Define if you have the mbrlen function. */
#define HAVE_MBRLEN 1

/* Define if you have the mbrtowc function. */
#define HAVE_MBRTOWC 1

/* Define if you have the mbsrtowcs function. */
#define HAVE_MBSRTOWCS 1

/* Define if you have the memmove function. */
#define HAVE_MEMMOVE 1

/* Define if you have the pselect function.  */
/* #undef HAVE_PSELECT */

/* Define if you have the putenv function.  */
#define HAVE_PUTENV 1

/* Define if you have the readlink function.  */
/* #undef HAVE_READLINK */

/* Define if you have the select function.  */
/* #undef HAVE_SELECT */

/* Define if you have the setenv function.  */
/* #undef HAVE_SETENV */

/* Define if you have the setlocale function. */
#define HAVE_SETLOCALE 1

/* Define if you have the strcasecmp function.  */
/* #undef HAVE_STRCASECMP */

/* Define if you have the strcoll function.  */
#define HAVE_STRCOLL 1

#define STRCOLL_BROKEN 1

/* Define if you have the strpbrk function.  */
#define HAVE_STRPBRK 1

/* Define if you have the tcgetattr function.  */
/* #undef HAVE_TCGETATTR */

/* Define if you have the towlower function.  */
#define HAVE_TOWLOWER 1

/* Define if you have the towupper function.  */
#define HAVE_TOWUPPER 1

/* Define if you have the vsnprintf function.  */
#define HAVE_VSNPRINTF 1

/* Define if you have the wcrtomb function.  */
#define HAVE_WCRTOMB 1

/* Define if you have the wcscoll function.  */
#define HAVE_WCSCOLL 1

/* Define if you have the wctype function.  */
#define HAVE_WCTYPE 1

/* Define if you have the wcwidth function.  */
/* #undef HAVE_WCWIDTH */

/* and whether it works */
/* #undef WCWIDTH_BROKEN */

#define STDC_HEADERS 1

/* Define if you have the <dirent.h> header file.  */
/* #undef HAVE_DIRENT_H */

/* Define if you have the <fcntl.h> header file.  */
#define HAVE_FCNTL_H 1

/* Define if you have the <langinfo.h> header file.  */
/* #undef HAVE_LANGINFO_H */

/* Define if you have the <libaudit.h> header file.  */
/* #undef HAVE_LIBAUDIT_H */

/* Define if you have the <limits.h> header file.  */
#define HAVE_LIMITS_H 1

/* Define if you have the <locale.h> header file.  */
#define HAVE_LOCALE_H 1

/* Define if you have the <memory.h> header file.  */
#define HAVE_MEMORY_H 1

/* Define if you have the <ndir.h> header file.  */
/* #undef HAVE_NDIR_H */

/* Define if you have the <ncurses/termcap.h> header file.  */
/* #undef HAVE_NCURSES_TERMCAP_H */

/* Define if you have the <pwd.h> header file.  */
/* #undef HAVE_PWD_H */

/* Define if you have the <stdarg.h> header file.  */
#define HAVE_STDARG_H 1

/* Define if you have the <stdbool.h> header file.  */
#define HAVE_STDBOOL_H 1

/* Define if you have the <stdlib.h> header file.  */
#define HAVE_STDLIB_H 1

/* Define if you have the <string.h> header file.  */
#define HAVE_STRING_H 1

/* Define if you have the <strings.h> header file.  */
/* #undef HAVE_STRINGS_H */

/* Define if you have the <sys/dir.h> header file.  */
/* #undef HAVE_SYS_DIR_H */

/* Define if you have the <sys/file.h> header file.  */
/* #undef HAVE_SYS_FILE_H */

/* Define if you have the <sys/ioctl.h> header file.  */
/* #undef HAVE_SYS_IOCTL_H */

/* Define if you have the <sys/ndir.h> header file.  */
/* #undef HAVE_SYS_NDIR_H */

/* Define if you have the <sys/pte.h> header file.  */
/* #undef HAVE_SYS_PTE_H */

/* Define if you have the <sys/ptem.h> header file.  */
/* #undef HAVE_SYS_PTEM_H */

/* Define if you have the <sys/select.h> header file.  */
/* #undef HAVE_SYS_SELECT_H */

/* Define if you have the <sys/stream.h> header file.  */
/* #undef HAVE_SYS_STREAM_H */

/* Define if you have the <termcap.h> header file.  */
/* #undef HAVE_TERMCAP_H */

/* Define if you have the <termio.h> header file.  */
/* #undef HAVE_TERMIO_H */

/* Define if you have the <termios.h> header file.  */
/* #undef HAVE_TERMIOS_H */

/* Define if you have the <unistd.h> header file.  */
/* #undef HAVE_UNISTD_H */

/* Define if you have the <varargs.h> header file.  */
#define HAVE_VARARGS_H 1

/* Define if you have the <wchar.h> header file.  */
#define HAVE_WCHAR_H 1

/* Define if you have the <wctype.h> header file.  */
#define HAVE_WCTYPE_H 1

#define HAVE_MBSTATE_T 1

/* Define if you have wchar_t in <wctype.h>. */
#define HAVE_WCHAR_T 1

/* Define if you have wctype_t in <wctype.h>. */
#define HAVE_WCTYPE_T 1

/* Define if you have wint_t in <wctype.h>. */  
#define HAVE_WINT_T 1

/* Define if you have <langinfo.h> and nl_langinfo(CODESET). */
/* #undef HAVE_LANGINFO_CODESET */

/* Define if you have <linux/audit.h> and it defines AUDIT_USER_TTY */
#define HAVE_DECL_AUDIT_USER_TTY 0

/* Definitions pulled in from aclocal.m4. */
#define VOID_SIGHANDLER 1

/* #undef GWINSZ_IN_SYS_IOCTL */

/* #undef STRUCT_WINSIZE_IN_SYS_IOCTL */

/* #undef STRUCT_WINSIZE_IN_TERMIOS */

/* #undef TIOCSTAT_IN_SYS_IOCTL */

/* #undef FIONREAD_IN_SYS_IOCTL */

/* #undef SPEED_T_IN_SYS_TYPES */

/* #undef HAVE_GETPW_DECLS */

/* #undef HAVE_STRUCT_DIRENT_D_INO */

/* #undef HAVE_STRUCT_DIRENT_D_FILENO */

/* #undef HAVE_STRUCT_DIRENT_D_NAMLEN */

/* #undef HAVE_BSD_SIGNALS */

/* #undef HAVE_POSIX_SIGNALS */

/* #undef HAVE_USG_SIGHOLD */

#define MUST_REINSTALL_SIGHANDLERS 1

/* #undef HAVE_POSIX_SIGSETJMP */

#define CTYPE_NON_ASCII 1

/* modify settings or make new ones based on what autoconf tells us. */

/* Ultrix botches type-ahead when switching from canonical to
   non-canonical mode, at least through version 4.3 */
#if !defined (HAVE_TERMIOS_H) || !defined (HAVE_TCGETATTR) || defined (ultrix)
#  define TERMIOS_MISSING
#endif

/* VARARGS defines moved to rlstdc.h */
