extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1),
__leaf__)) memset)(void *__s , int __c , unsigned long __n ) ;
struct _IO_FILE;
struct _IO_FILE *_coverage_fout  ;
typedef unsigned long size_t;
typedef unsigned char __u_char;
typedef unsigned short __u_short;
typedef unsigned int __u_int;
typedef unsigned long __u_long;
typedef signed char __int8_t;
typedef unsigned char __uint8_t;
typedef short __int16_t;
typedef unsigned short __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;
typedef long __int64_t;
typedef unsigned long __uint64_t;
typedef long __quad_t;
typedef unsigned long __u_quad_t;
typedef unsigned long __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned long __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned long __nlink_t;
typedef long __off_t;
typedef long __off64_t;
typedef int __pid_t;
struct __anonstruct___fsid_t_1 {
   int __val[2] ;
};
typedef struct __anonstruct___fsid_t_1 __fsid_t;
typedef long __clock_t;
typedef unsigned long __rlim_t;
typedef unsigned long __rlim64_t;
typedef unsigned int __id_t;
typedef long __time_t;
typedef unsigned int __useconds_t;
typedef long __suseconds_t;
typedef int __daddr_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef long __blkcnt64_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsblkcnt64_t;
typedef unsigned long __fsfilcnt_t;
typedef unsigned long __fsfilcnt64_t;
typedef long __fsword_t;
typedef long __ssize_t;
typedef long __syscall_slong_t;
typedef unsigned long __syscall_ulong_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef long __intptr_t;
typedef unsigned int __socklen_t;
typedef struct _IO_FILE FILE;
typedef struct _IO_FILE __FILE;
union __anonunion___value_3 {
   unsigned int __wch ;
   char __wchb[4] ;
};
struct __anonstruct___mbstate_t_2 {
   int __count ;
   union __anonunion___value_3 __value ;
};
typedef struct __anonstruct___mbstate_t_2 __mbstate_t;
struct __anonstruct__G_fpos_t_4 {
   __off_t __pos ;
   __mbstate_t __state ;
};
typedef struct __anonstruct__G_fpos_t_4 _G_fpos_t;
struct __anonstruct__G_fpos64_t_5 {
   __off64_t __pos ;
   __mbstate_t __state ;
};
typedef struct __anonstruct__G_fpos64_t_5 _G_fpos64_t;
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t;
typedef void _IO_lock_t;
struct _IO_marker {
   struct _IO_marker *_next ;
   struct _IO_FILE *_sbuf ;
   int _pos ;
};
enum __codecvt_result {
    __codecvt_ok = 0,
    __codecvt_partial = 1,
    __codecvt_error = 2,
    __codecvt_noconv = 3
} ;
struct _IO_FILE {
   int _flags ;
   char *_IO_read_ptr ;
   char *_IO_read_end ;
   char *_IO_read_base ;
   char *_IO_write_base ;
   char *_IO_write_ptr ;
   char *_IO_write_end ;
   char *_IO_buf_base ;
   char *_IO_buf_end ;
   char *_IO_save_base ;
   char *_IO_backup_base ;
   char *_IO_save_end ;
   struct _IO_marker *_markers ;
   struct _IO_FILE *_chain ;
   int _fileno ;
   int _flags2 ;
   __off_t _old_offset ;
   unsigned short _cur_column ;
   signed char _vtable_offset ;
   char _shortbuf[1] ;
   _IO_lock_t *_lock ;
   __off64_t _offset ;
   void *__pad1 ;
   void *__pad2 ;
   void *__pad3 ;
   void *__pad4 ;
   size_t __pad5 ;
   int _mode ;
   char _unused2[(15UL * sizeof(int ) - 4UL * sizeof(void *)) - sizeof(size_t )] ;
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
typedef __ssize_t __io_read_fn(void *__cookie , char *__buf , size_t __nbytes );
typedef __ssize_t __io_write_fn(void *__cookie , char const   *__buf ,
                                size_t __n );
typedef int __io_seek_fn(void *__cookie , __off64_t *__pos , int __w );
typedef int __io_close_fn(void *__cookie );
typedef __gnuc_va_list va_list;
typedef __off_t off_t;
typedef __ssize_t ssize_t;
typedef _G_fpos_t fpos_t;
typedef float float_t;
typedef double double_t;
enum __anonenum_6 {
    FP_NAN = 0,
    FP_INFINITE = 1,
    FP_ZERO = 2,
    FP_SUBNORMAL = 3,
    FP_NORMAL = 4
} ;
enum __anonenum__LIB_VERSION_TYPE_7 {
    _IEEE_ = -1,
    _SVID_ = 0,
    _XOPEN_ = 1,
    _POSIX_ = 2,
    _ISOC_ = 3
} ;
typedef enum __anonenum__LIB_VERSION_TYPE_7 _LIB_VERSION_TYPE;
struct exception {
   int type ;
   char *name ;
   double arg1 ;
   double arg2 ;
   double retval ;
};
extern struct _IO_FILE_plus _IO_2_1_stdin_ ;
extern struct _IO_FILE_plus _IO_2_1_stdout_ ;
extern struct _IO_FILE_plus _IO_2_1_stderr_ ;
extern int __underflow(_IO_FILE * ) ;
extern int __uflow(_IO_FILE * ) ;
extern int __overflow(_IO_FILE * , int  ) ;
extern int _IO_getc(_IO_FILE *__fp ) ;
extern int _IO_putc(int __c , _IO_FILE *__fp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) _IO_feof)(_IO_FILE *__fp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) _IO_ferror)(_IO_FILE *__fp ) ;
extern int _IO_peekc_locked(_IO_FILE *__fp ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) _IO_flockfile)(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) _IO_funlockfile)(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) _IO_ftrylockfile)(_IO_FILE * ) ;
extern int _IO_vfscanf(_IO_FILE * __restrict   , char const   * __restrict   ,
                       __gnuc_va_list  , int * __restrict   ) ;
extern int _IO_vfprintf(_IO_FILE * __restrict   , char const   * __restrict   ,
                        __gnuc_va_list  ) ;
extern __ssize_t _IO_padn(_IO_FILE * , int  , __ssize_t  ) ;
extern size_t _IO_sgetn(_IO_FILE * , void * , size_t  ) ;
extern __off64_t _IO_seekoff(_IO_FILE * , __off64_t  , int  , int  ) ;
extern __off64_t _IO_seekpos(_IO_FILE * , __off64_t  , int  ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) _IO_free_backup_area)(_IO_FILE * ) ;
extern struct _IO_FILE *stdin ;
extern struct _IO_FILE *stdout ;
extern struct _IO_FILE *stderr ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) remove)(char const   *__filename ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) rename)(char const   *__old ,
                                                                             char const   *__new ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) renameat)(int __oldfd ,
                                                                               char const   *__old ,
                                                                               int __newfd ,
                                                                               char const   *__new ) ;
extern FILE *tmpfile(void) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) tmpnam)(char *__s ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) tmpnam_r)(char *__s ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) tempnam)(char const   *__dir ,
                                                                                char const   *__pfx )  __attribute__((__malloc__)) ;
extern int fclose(FILE *__stream ) ;
extern int fflush(FILE *__stream ) ;
extern int fflush_unlocked(FILE *__stream ) ;
extern FILE *fopen(char const   * __restrict  __filename ,
                   char const   * __restrict  __modes ) ;
extern FILE *freopen(char const   * __restrict  __filename ,
                     char const   * __restrict  __modes ,
                     FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) FILE *( __attribute__((__leaf__)) fdopen)(int __fd ,
                                                                               char const   *__modes ) ;
extern  __attribute__((__nothrow__)) FILE *( __attribute__((__leaf__)) fmemopen)(void *__s ,
                                                                                 size_t __len ,
                                                                                 char const   *__modes ) ;
extern  __attribute__((__nothrow__)) FILE *( __attribute__((__leaf__)) open_memstream)(char **__bufloc ,
                                                                                       size_t *__sizeloc ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) setbuf)(FILE * __restrict  __stream ,
                                                                              char * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) setvbuf)(FILE * __restrict  __stream ,
                                                                              char * __restrict  __buf ,
                                                                              int __modes ,
                                                                              size_t __n ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) setbuffer)(FILE * __restrict  __stream ,
                                                                                 char * __restrict  __buf ,
                                                                                 size_t __size ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) setlinebuf)(FILE *__stream ) ;
extern int fprintf(FILE * __restrict  __stream ,
                   char const   * __restrict  __format  , ...) ;
extern int printf(char const   * __restrict  __format  , ...) ;
extern  __attribute__((__nothrow__)) int sprintf(char * __restrict  __s ,
                                                 char const   * __restrict  __format 
                                                 , ...) ;
extern int vfprintf(FILE * __restrict  __s ,
                    char const   * __restrict  __format , __gnuc_va_list __arg ) ;
extern int vprintf(char const   * __restrict  __format , __gnuc_va_list __arg ) ;
extern  __attribute__((__nothrow__)) int vsprintf(char * __restrict  __s ,
                                                  char const   * __restrict  __format ,
                                                  __gnuc_va_list __arg ) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  snprintf)(char * __restrict  __s ,
                                                                             size_t __maxlen ,
                                                                             char const   * __restrict  __format 
                                                                             , ...) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  vsnprintf)(char * __restrict  __s ,
                                                                              size_t __maxlen ,
                                                                              char const   * __restrict  __format ,
                                                                              __gnuc_va_list __arg ) ;
extern int ( /* format attribute */  vdprintf)(int __fd ,
                                               char const   * __restrict  __fmt ,
                                               __gnuc_va_list __arg ) ;
extern int ( /* format attribute */  dprintf)(int __fd ,
                                              char const   * __restrict  __fmt 
                                              , ...) ;
extern int fscanf(FILE * __restrict  __stream ,
                  char const   * __restrict  __format  , ...)  __asm__("__isoc99_fscanf")  ;
extern int scanf(char const   * __restrict  __format  , ...)  __asm__("__isoc99_scanf")  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) sscanf)(char const   * __restrict  __s ,
                                                                             char const   * __restrict  __format 
                                                                             , ...)  __asm__("__isoc99_sscanf")  ;
extern int ( /* format attribute */  vfscanf)(FILE * __restrict  __s ,
                                              char const   * __restrict  __format ,
                                              __gnuc_va_list __arg )  __asm__("__isoc99_vfscanf")  ;
extern int ( /* format attribute */  vscanf)(char const   * __restrict  __format ,
                                             __gnuc_va_list __arg )  __asm__("__isoc99_vscanf")  ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */ __attribute__((__leaf__)) vsscanf)(char const   * __restrict  __s ,
                                                                                                     char const   * __restrict  __format ,
                                                                                                     __gnuc_va_list __arg )  __asm__("__isoc99_vsscanf")  ;
extern int fgetc(FILE *__stream ) ;
extern int getc(FILE *__stream ) ;
extern int getchar(void) ;
extern int getc_unlocked(FILE *__stream ) ;
extern int getchar_unlocked(void) ;
extern int fgetc_unlocked(FILE *__stream ) ;
extern int fputc(int __c , FILE *__stream ) ;
extern int putc(int __c , FILE *__stream ) ;
extern int putchar(int __c ) ;
extern int fputc_unlocked(int __c , FILE *__stream ) ;
extern int putc_unlocked(int __c , FILE *__stream ) ;
extern int putchar_unlocked(int __c ) ;
extern int getw(FILE *__stream ) ;
extern int putw(int __w , FILE *__stream ) ;
extern char *fgets(char * __restrict  __s , int __n ,
                   FILE * __restrict  __stream ) ;
extern char *gets(char *__s )  __attribute__((__deprecated__)) ;
extern __ssize_t __getdelim(char ** __restrict  __lineptr ,
                            size_t * __restrict  __n , int __delimiter ,
                            FILE * __restrict  __stream ) ;
extern __ssize_t getdelim(char ** __restrict  __lineptr ,
                          size_t * __restrict  __n , int __delimiter ,
                          FILE * __restrict  __stream ) ;
extern __ssize_t getline(char ** __restrict  __lineptr ,
                         size_t * __restrict  __n , FILE * __restrict  __stream ) ;
extern int fputs(char const   * __restrict  __s , FILE * __restrict  __stream ) ;
extern int puts(char const   *__s ) ;
extern int ungetc(int __c , FILE *__stream ) ;
extern size_t fread(void * __restrict  __ptr , size_t __size , size_t __n ,
                    FILE * __restrict  __stream ) ;
extern size_t fwrite(void const   * __restrict  __ptr , size_t __size ,
                     size_t __n , FILE * __restrict  __s ) ;
extern size_t fread_unlocked(void * __restrict  __ptr , size_t __size ,
                             size_t __n , FILE * __restrict  __stream ) ;
extern size_t fwrite_unlocked(void const   * __restrict  __ptr , size_t __size ,
                              size_t __n , FILE * __restrict  __stream ) ;
extern int fseek(FILE *__stream , long __off , int __whence ) ;
extern long ftell(FILE *__stream ) ;
extern void rewind(FILE *__stream ) ;
extern int fseeko(FILE *__stream , __off_t __off , int __whence ) ;
extern __off_t ftello(FILE *__stream ) ;
extern int fgetpos(FILE * __restrict  __stream , fpos_t * __restrict  __pos ) ;
extern int fsetpos(FILE *__stream , fpos_t const   *__pos ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) clearerr)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) feof)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ferror)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) clearerr_unlocked)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) feof_unlocked)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ferror_unlocked)(FILE *__stream ) ;
extern void perror(char const   *__s ) ;
extern int sys_nerr ;
extern char const   * const  sys_errlist[] ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fileno)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) fileno_unlocked)(FILE *__stream ) ;
extern FILE *popen(char const   *__command , char const   *__modes ) ;
extern int pclose(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) ctermid)(char *__s ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) flockfile)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ftrylockfile)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) funlockfile)(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) acos)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __acos)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) asin)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __asin)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) atan)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __atan)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) atan2)(double __y ,
                                                                               double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __atan2)(double __y ,
                                                                                 double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) cos)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __cos)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) sin)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __sin)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) tan)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __tan)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) cosh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __cosh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) sinh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __sinh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) tanh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __tanh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) acosh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __acosh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) asinh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __asinh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) atanh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __atanh)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) exp)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __exp)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) frexp)(double __x ,
                                                                               int *__exponent ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __frexp)(double __x ,
                                                                                 int *__exponent ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) ldexp)(double __x ,
                                                                               int __exponent ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __ldexp)(double __x ,
                                                                                 int __exponent ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) log)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __log)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) log10)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __log10)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) modf)(double __x ,
                                                                              double *__iptr ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(2),
__leaf__)) __modf)(double __x , double *__iptr ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) expm1)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __expm1)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) log1p)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __log1p)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) logb)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __logb)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) exp2)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __exp2)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) log2)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __log2)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) pow)(double __x ,
                                                                             double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __pow)(double __x ,
                                                                               double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) sqrt)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __sqrt)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) hypot)(double __x ,
                                                                               double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __hypot)(double __x ,
                                                                                 double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) cbrt)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __cbrt)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) ceil)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __ceil)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) fabs)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __fabs)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) floor)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __floor)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) fmod)(double __x ,
                                                                              double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __fmod)(double __x ,
                                                                                double __y ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __isinf)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __finite)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) isinf)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) finite)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) drem)(double __x ,
                                                                              double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __drem)(double __x ,
                                                                                double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) significand)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __significand)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) copysign)(double __x ,
                                                                                  double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __copysign)(double __x ,
                                                                                    double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) nan)(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __nan)(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __isnan)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) isnan)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) j0)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __j0)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) j1)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __j1)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) jn)(int  ,
                                                                            double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __jn)(int  ,
                                                                              double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) y0)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __y0)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) y1)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __y1)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) yn)(int  ,
                                                                            double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __yn)(int  ,
                                                                              double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) erf)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __erf)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) erfc)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __erfc)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) lgamma)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __lgamma)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) tgamma)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __tgamma)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) gamma)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __gamma)(double  ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) lgamma_r)(double  ,
                                                                                  int *__signgamp ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __lgamma_r)(double  ,
                                                                                    int *__signgamp ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) rint)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __rint)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) nextafter)(double __x ,
                                                                                   double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __nextafter)(double __x ,
                                                                                     double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) nexttoward)(double __x ,
                                                                                    long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __nexttoward)(double __x ,
                                                                                      long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) remainder)(double __x ,
                                                                                   double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __remainder)(double __x ,
                                                                                     double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) scalbn)(double __x ,
                                                                                int __n ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __scalbn)(double __x ,
                                                                                  int __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ilogb)(double __x ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __ilogb)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) scalbln)(double __x ,
                                                                                 long __n ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __scalbln)(double __x ,
                                                                                   long __n ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) nearbyint)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __nearbyint)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) round)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __round)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) trunc)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __trunc)(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) remquo)(double __x ,
                                                                                double __y ,
                                                                                int *__quo ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __remquo)(double __x ,
                                                                                  double __y ,
                                                                                  int *__quo ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) lrint)(double __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) __lrint)(double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) llrint)(double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) __llrint)(double __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) lround)(double __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) __lround)(double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) llround)(double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) __llround)(double __x ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) fdim)(double __x ,
                                                                              double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __fdim)(double __x ,
                                                                                double __y ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) fmax)(double __x ,
                                                                              double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __fmax)(double __x ,
                                                                                double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) fmin)(double __x ,
                                                                              double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __fmin)(double __x ,
                                                                                double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __fpclassify)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __signbit)(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) fma)(double __x ,
                                                                             double __y ,
                                                                             double __z ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __fma)(double __x ,
                                                                               double __y ,
                                                                               double __z ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) scalb)(double __x ,
                                                                               double __n ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) __scalb)(double __x ,
                                                                                 double __n ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) acosf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __acosf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) asinf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __asinf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) atanf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __atanf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) atan2f)(float __y ,
                                                                               float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __atan2f)(float __y ,
                                                                                 float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) cosf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __cosf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) sinf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __sinf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) tanf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __tanf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) coshf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __coshf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) sinhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __sinhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) tanhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __tanhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) acoshf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __acoshf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) asinhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __asinhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) atanhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __atanhf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) expf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __expf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) frexpf)(float __x ,
                                                                               int *__exponent ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __frexpf)(float __x ,
                                                                                 int *__exponent ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) ldexpf)(float __x ,
                                                                               int __exponent ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __ldexpf)(float __x ,
                                                                                 int __exponent ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) logf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __logf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) log10f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __log10f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) modff)(float __x ,
                                                                              float *__iptr ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__nonnull__(2),
__leaf__)) __modff)(float __x , float *__iptr ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) expm1f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __expm1f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) log1pf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __log1pf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) logbf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __logbf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) exp2f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __exp2f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) log2f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __log2f)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) powf)(float __x ,
                                                                             float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __powf)(float __x ,
                                                                               float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) sqrtf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __sqrtf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) hypotf)(float __x ,
                                                                               float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __hypotf)(float __x ,
                                                                                 float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) cbrtf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __cbrtf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) ceilf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __ceilf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) fabsf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __fabsf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) floorf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __floorf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) fmodf)(float __x ,
                                                                              float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __fmodf)(float __x ,
                                                                                float __y ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __isinff)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __finitef)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) isinff)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) finitef)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) dremf)(float __x ,
                                                                              float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __dremf)(float __x ,
                                                                                float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) significandf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __significandf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) copysignf)(float __x ,
                                                                                  float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __copysignf)(float __x ,
                                                                                    float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) nanf)(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __nanf)(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __isnanf)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) isnanf)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) j0f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __j0f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) j1f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __j1f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) jnf)(int  ,
                                                                            float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __jnf)(int  ,
                                                                              float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) y0f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __y0f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) y1f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __y1f)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) ynf)(int  ,
                                                                            float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __ynf)(int  ,
                                                                              float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) erff)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __erff)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) erfcf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __erfcf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) lgammaf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __lgammaf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) tgammaf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __tgammaf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) gammaf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __gammaf)(float  ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) lgammaf_r)(float  ,
                                                                                  int *__signgamp ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __lgammaf_r)(float  ,
                                                                                    int *__signgamp ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) rintf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __rintf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) nextafterf)(float __x ,
                                                                                   float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __nextafterf)(float __x ,
                                                                                     float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) nexttowardf)(float __x ,
                                                                                    long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __nexttowardf)(float __x ,
                                                                                      long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) remainderf)(float __x ,
                                                                                   float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __remainderf)(float __x ,
                                                                                     float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) scalbnf)(float __x ,
                                                                                int __n ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __scalbnf)(float __x ,
                                                                                  int __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ilogbf)(float __x ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __ilogbf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) scalblnf)(float __x ,
                                                                                 long __n ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __scalblnf)(float __x ,
                                                                                   long __n ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) nearbyintf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __nearbyintf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) roundf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __roundf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) truncf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __truncf)(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) remquof)(float __x ,
                                                                                float __y ,
                                                                                int *__quo ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __remquof)(float __x ,
                                                                                  float __y ,
                                                                                  int *__quo ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) lrintf)(float __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) __lrintf)(float __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) llrintf)(float __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) __llrintf)(float __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) lroundf)(float __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) __lroundf)(float __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) llroundf)(float __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) __llroundf)(float __x ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) fdimf)(float __x ,
                                                                              float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __fdimf)(float __x ,
                                                                                float __y ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) fmaxf)(float __x ,
                                                                              float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __fmaxf)(float __x ,
                                                                                float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) fminf)(float __x ,
                                                                              float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __fminf)(float __x ,
                                                                                float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __fpclassifyf)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __signbitf)(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) fmaf)(float __x ,
                                                                             float __y ,
                                                                             float __z ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __fmaf)(float __x ,
                                                                               float __y ,
                                                                               float __z ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) scalbf)(float __x ,
                                                                               float __n ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__leaf__)) __scalbf)(float __x ,
                                                                                 float __n ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) acosl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __acosl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) asinl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __asinl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) atanl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __atanl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) atan2l)(long double __y ,
                                                                                     long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __atan2l)(long double __y ,
                                                                                       long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) cosl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __cosl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) sinl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __sinl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) tanl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __tanl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) coshl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __coshl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) sinhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __sinhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) tanhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __tanhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) acoshl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __acoshl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) asinhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __asinhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) atanhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __atanhl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) expl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __expl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) frexpl)(long double __x ,
                                                                                     int *__exponent ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __frexpl)(long double __x ,
                                                                                       int *__exponent ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) ldexpl)(long double __x ,
                                                                                     int __exponent ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __ldexpl)(long double __x ,
                                                                                       int __exponent ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) logl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __logl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) log10l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __log10l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) modfl)(long double __x ,
                                                                                    long double *__iptr ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__nonnull__(2),
__leaf__)) __modfl)(long double __x , long double *__iptr ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) expm1l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __expm1l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) log1pl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __log1pl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) logbl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __logbl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) exp2l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __exp2l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) log2l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __log2l)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) powl)(long double __x ,
                                                                                   long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __powl)(long double __x ,
                                                                                     long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) sqrtl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __sqrtl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) hypotl)(long double __x ,
                                                                                     long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __hypotl)(long double __x ,
                                                                                       long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) cbrtl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __cbrtl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) ceill)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __ceill)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) fabsl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __fabsl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) floorl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __floorl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) fmodl)(long double __x ,
                                                                                    long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __fmodl)(long double __x ,
                                                                                      long double __y ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __isinfl)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __finitel)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) isinfl)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) finitel)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) dreml)(long double __x ,
                                                                                    long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __dreml)(long double __x ,
                                                                                      long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) significandl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __significandl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) copysignl)(long double __x ,
                                                                                        long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __copysignl)(long double __x ,
                                                                                          long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) nanl)(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __nanl)(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __isnanl)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) isnanl)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) j0l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __j0l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) j1l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __j1l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) jnl)(int  ,
                                                                                  long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __jnl)(int  ,
                                                                                    long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) y0l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __y0l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) y1l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __y1l)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) ynl)(int  ,
                                                                                  long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __ynl)(int  ,
                                                                                    long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) erfl)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __erfl)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) erfcl)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __erfcl)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) lgammal)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __lgammal)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) tgammal)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __tgammal)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) gammal)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __gammal)(long double  ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) lgammal_r)(long double  ,
                                                                                        int *__signgamp ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __lgammal_r)(long double  ,
                                                                                          int *__signgamp ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) rintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __rintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) nextafterl)(long double __x ,
                                                                                         long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __nextafterl)(long double __x ,
                                                                                           long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) nexttowardl)(long double __x ,
                                                                                          long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __nexttowardl)(long double __x ,
                                                                                            long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) remainderl)(long double __x ,
                                                                                         long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __remainderl)(long double __x ,
                                                                                           long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) scalbnl)(long double __x ,
                                                                                      int __n ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __scalbnl)(long double __x ,
                                                                                        int __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) ilogbl)(long double __x ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __ilogbl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) scalblnl)(long double __x ,
                                                                                       long __n ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __scalblnl)(long double __x ,
                                                                                         long __n ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) nearbyintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __nearbyintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) roundl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __roundl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) truncl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __truncl)(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) remquol)(long double __x ,
                                                                                      long double __y ,
                                                                                      int *__quo ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __remquol)(long double __x ,
                                                                                        long double __y ,
                                                                                        int *__quo ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) lrintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) __lrintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) llrintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) __llrintl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) lroundl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) __lroundl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) llroundl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) __llroundl)(long double __x ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) fdiml)(long double __x ,
                                                                                    long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __fdiml)(long double __x ,
                                                                                      long double __y ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) fmaxl)(long double __x ,
                                                                                    long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __fmaxl)(long double __x ,
                                                                                      long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) fminl)(long double __x ,
                                                                                    long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __fminl)(long double __x ,
                                                                                      long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __fpclassifyl)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) __signbitl)(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) fmal)(long double __x ,
                                                                                   long double __y ,
                                                                                   long double __z ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __fmal)(long double __x ,
                                                                                     long double __y ,
                                                                                     long double __z ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) scalbl)(long double __x ,
                                                                                     long double __n ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__leaf__)) __scalbl)(long double __x ,
                                                                                       long double __n ) ;
extern int signgam ;
extern _LIB_VERSION_TYPE _LIB_VERSION ;
extern int matherr(struct exception *__exc ) ;
extern int ( /* missing proto */  abs)() ;
int main(void) 
{ 
  int n ;
  int rem1 ;
  int rem2 ;
  int rem3 ;
  int rem4 ;
  int rem5 ;
  int rem6 ;
  int rem7 ;
  int rem8 ;
  int rem9 ;
  int rem10 ;
  float p ;
  int x ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;

  {
  {
  if (_coverage_fout == 0) {
    {
    _coverage_fout = fopen("/workdir/experiment/digits-7b78b2d5ab654253c4acb32046237950862d20275165bdb24a7584184a22d3cebeadb299f4e16fdf452f4dc6f958000d118d5ba60dea5645d143183573109d58-20/./coverage.path",
                           "wb");
    }
  }
  }
  {
  fprintf(_coverage_fout, "1\n");
  fflush(_coverage_fout);
  }
  rem1 = 0;
  {
  fprintf(_coverage_fout, "2\n");
  fflush(_coverage_fout);
  }
  rem2 = 0;
  {
  fprintf(_coverage_fout, "3\n");
  fflush(_coverage_fout);
  }
  rem3 = 0;
  {
  fprintf(_coverage_fout, "4\n");
  fflush(_coverage_fout);
  }
  rem4 = 0;
  {
  fprintf(_coverage_fout, "5\n");
  fflush(_coverage_fout);
  }
  rem5 = 0;
  {
  fprintf(_coverage_fout, "6\n");
  fflush(_coverage_fout);
  }
  rem6 = 0;
  {
  fprintf(_coverage_fout, "7\n");
  fflush(_coverage_fout);
  }
  rem7 = 0;
  {
  fprintf(_coverage_fout, "8\n");
  fflush(_coverage_fout);
  }
  rem8 = 0;
  {
  fprintf(_coverage_fout, "9\n");
  fflush(_coverage_fout);
  }
  rem9 = 0;
  {
  fprintf(_coverage_fout, "10\n");
  fflush(_coverage_fout);
  }
  rem10 = 0;
  {
  fprintf(_coverage_fout, "11\n");
  fflush(_coverage_fout);
  }
  x = 0;
  {
  fprintf(_coverage_fout, "12\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"\nEnter an integer > ");
  {
  fprintf(_coverage_fout, "13\n");
  fflush(_coverage_fout);
  }
  scanf((char const   */* __restrict  */)"%f", & p);
  {
  fprintf(_coverage_fout, "14\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"\n");
  {
  fprintf(_coverage_fout, "15\n");
  fflush(_coverage_fout);
  }
  while (1) {
    {
    fprintf(_coverage_fout, "16\n");
    fflush(_coverage_fout);
    }
    if (x == 0) {
      {
      fprintf(_coverage_fout, "17\n");
      fflush(_coverage_fout);
      }

    } else {
      break;
    }
    {
    fprintf(_coverage_fout, "19\n");
    fflush(_coverage_fout);
    }
    if (p > (float )0) {
      {
      fprintf(_coverage_fout, "20\n");
      fflush(_coverage_fout);
      }
      if (p < (float )1) {
        {
        fprintf(_coverage_fout, "21\n");
        fflush(_coverage_fout);
        }
        printf((char const   */* __restrict  */)"5\n2\n0\n4\n1\n5\n4\n3\n1\n");
        {
        fprintf(_coverage_fout, "22\n");
        fflush(_coverage_fout);
        }
        x = 1;
      } else {
        {
        fprintf(_coverage_fout, "23\n");
        fflush(_coverage_fout);
        }
        n = (int )p;
      }
    } else {
      {
      fprintf(_coverage_fout, "24\n");
      fflush(_coverage_fout);
      }
      n = (int )p;
    }
    {
    fprintf(_coverage_fout, "25\n");
    fflush(_coverage_fout);
    }
    tmp = abs(n);
    {
    fprintf(_coverage_fout, "26\n");
    fflush(_coverage_fout);
    }
    if ((long )tmp > 9999999999L) {
      {
      fprintf(_coverage_fout, "27\n");
      fflush(_coverage_fout);
      }
      printf((char const   */* __restrict  */)"7\n4\n6\n3\n8\n4\n7\n4\n1\n2\n");
      {
      fprintf(_coverage_fout, "28\n");
      fflush(_coverage_fout);
      }
      x = 1;
    } else {
      {
      fprintf(_coverage_fout, "29\n");
      fflush(_coverage_fout);
      }

    }
    {
    fprintf(_coverage_fout, "30\n");
    fflush(_coverage_fout);
    }
    while (1) {
      {
      fprintf(_coverage_fout, "31\n");
      fflush(_coverage_fout);
      }
      if (x == 0) {
        {
        fprintf(_coverage_fout, "32\n");
        fflush(_coverage_fout);
        }

      } else {
        break;
      }
      {
      fprintf(_coverage_fout, "34\n");
      fflush(_coverage_fout);
      }
      tmp___0 = abs(n);
      {
      fprintf(_coverage_fout, "35\n");
      fflush(_coverage_fout);
      }
      if (tmp___0 >= 1000000000) {
        {
        fprintf(_coverage_fout, "36\n");
        fflush(_coverage_fout);
        }
        rem10 = (int )((long )n % 10000000000L);
        {
        fprintf(_coverage_fout, "37\n");
        fflush(_coverage_fout);
        }
        rem10 /= 1000000000;
      } else {
        {
        fprintf(_coverage_fout, "38\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "39\n");
      fflush(_coverage_fout);
      }
      tmp___1 = abs(n);
      {
      fprintf(_coverage_fout, "40\n");
      fflush(_coverage_fout);
      }
      if (tmp___1 >= 100000000) {
        {
        fprintf(_coverage_fout, "41\n");
        fflush(_coverage_fout);
        }
        rem9 = n % 1000000000;
        {
        fprintf(_coverage_fout, "42\n");
        fflush(_coverage_fout);
        }
        rem9 /= 100000000;
        {
        fprintf(_coverage_fout, "43\n");
        fflush(_coverage_fout);
        }
        if (rem10 < 0) {
          {
          fprintf(_coverage_fout, "44\n");
          fflush(_coverage_fout);
          }
          rem9 = - rem9;
        } else {
          {
          fprintf(_coverage_fout, "45\n");
          fflush(_coverage_fout);
          }

        }
      } else {
        {
        fprintf(_coverage_fout, "46\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "47\n");
      fflush(_coverage_fout);
      }
      tmp___2 = abs(n);
      {
      fprintf(_coverage_fout, "48\n");
      fflush(_coverage_fout);
      }
      if (tmp___2 >= 10000000) {
        {
        fprintf(_coverage_fout, "49\n");
        fflush(_coverage_fout);
        }
        rem8 = n % 100000000;
        {
        fprintf(_coverage_fout, "50\n");
        fflush(_coverage_fout);
        }
        rem8 /= 10000000;
        {
        fprintf(_coverage_fout, "51\n");
        fflush(_coverage_fout);
        }
        if (rem9 < 0) {
          {
          fprintf(_coverage_fout, "52\n");
          fflush(_coverage_fout);
          }
          rem8 = - rem8;
        } else {
          {
          fprintf(_coverage_fout, "53\n");
          fflush(_coverage_fout);
          }
          if (rem10 < 0) {
            {
            fprintf(_coverage_fout, "54\n");
            fflush(_coverage_fout);
            }
            rem8 = - rem8;
          } else {
            {
            fprintf(_coverage_fout, "55\n");
            fflush(_coverage_fout);
            }

          }
        }
      } else {
        {
        fprintf(_coverage_fout, "56\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "57\n");
      fflush(_coverage_fout);
      }
      tmp___3 = abs(n);
      {
      fprintf(_coverage_fout, "58\n");
      fflush(_coverage_fout);
      }
      if (tmp___3 >= 1000000) {
        {
        fprintf(_coverage_fout, "59\n");
        fflush(_coverage_fout);
        }
        rem7 = n % 10000000;
        {
        fprintf(_coverage_fout, "60\n");
        fflush(_coverage_fout);
        }
        rem7 /= 1000000;
        {
        fprintf(_coverage_fout, "61\n");
        fflush(_coverage_fout);
        }
        if (rem8 < 0) {
          {
          fprintf(_coverage_fout, "62\n");
          fflush(_coverage_fout);
          }
          rem7 = - rem7;
        } else {
          {
          fprintf(_coverage_fout, "63\n");
          fflush(_coverage_fout);
          }
          if (rem9 < 0) {
            {
            fprintf(_coverage_fout, "64\n");
            fflush(_coverage_fout);
            }
            rem7 = - rem7;
          } else {
            {
            fprintf(_coverage_fout, "65\n");
            fflush(_coverage_fout);
            }
            if (rem10 < 0) {
              {
              fprintf(_coverage_fout, "66\n");
              fflush(_coverage_fout);
              }
              rem7 = - rem7;
            } else {
              {
              fprintf(_coverage_fout, "67\n");
              fflush(_coverage_fout);
              }

            }
          }
        }
      } else {
        {
        fprintf(_coverage_fout, "68\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "69\n");
      fflush(_coverage_fout);
      }
      tmp___4 = abs(n);
      {
      fprintf(_coverage_fout, "70\n");
      fflush(_coverage_fout);
      }
      if (tmp___4 >= 100000) {
        {
        fprintf(_coverage_fout, "71\n");
        fflush(_coverage_fout);
        }
        rem6 = n % 1000000;
        {
        fprintf(_coverage_fout, "72\n");
        fflush(_coverage_fout);
        }
        rem6 /= 100000;
        {
        fprintf(_coverage_fout, "73\n");
        fflush(_coverage_fout);
        }
        if (rem7 < 0) {
          {
          fprintf(_coverage_fout, "74\n");
          fflush(_coverage_fout);
          }
          rem6 = - rem6;
        } else {
          {
          fprintf(_coverage_fout, "75\n");
          fflush(_coverage_fout);
          }
          if (rem8 < 0) {
            {
            fprintf(_coverage_fout, "76\n");
            fflush(_coverage_fout);
            }
            rem6 = - rem6;
          } else {
            {
            fprintf(_coverage_fout, "77\n");
            fflush(_coverage_fout);
            }
            if (rem9 < 0) {
              {
              fprintf(_coverage_fout, "78\n");
              fflush(_coverage_fout);
              }
              rem6 = - rem6;
            } else {
              {
              fprintf(_coverage_fout, "79\n");
              fflush(_coverage_fout);
              }
              if (rem10 < 0) {
                {
                fprintf(_coverage_fout, "80\n");
                fflush(_coverage_fout);
                }
                rem6 = - rem6;
              } else {
                {
                fprintf(_coverage_fout, "81\n");
                fflush(_coverage_fout);
                }

              }
            }
          }
        }
      } else {
        {
        fprintf(_coverage_fout, "82\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "83\n");
      fflush(_coverage_fout);
      }
      tmp___5 = abs(n);
      {
      fprintf(_coverage_fout, "84\n");
      fflush(_coverage_fout);
      }
      if (tmp___5 >= 10000) {
        {
        fprintf(_coverage_fout, "85\n");
        fflush(_coverage_fout);
        }
        rem5 = n % 100000;
        {
        fprintf(_coverage_fout, "86\n");
        fflush(_coverage_fout);
        }
        rem5 /= 10000;
        {
        fprintf(_coverage_fout, "87\n");
        fflush(_coverage_fout);
        }
        if (rem6 < 0) {
          {
          fprintf(_coverage_fout, "88\n");
          fflush(_coverage_fout);
          }
          rem5 = - rem5;
        } else {
          {
          fprintf(_coverage_fout, "89\n");
          fflush(_coverage_fout);
          }
          if (rem7 < 0) {
            {
            fprintf(_coverage_fout, "90\n");
            fflush(_coverage_fout);
            }
            rem5 = - rem5;
          } else {
            {
            fprintf(_coverage_fout, "91\n");
            fflush(_coverage_fout);
            }
            if (rem8 < 0) {
              {
              fprintf(_coverage_fout, "92\n");
              fflush(_coverage_fout);
              }
              rem5 = - rem5;
            } else {
              {
              fprintf(_coverage_fout, "93\n");
              fflush(_coverage_fout);
              }
              if (rem9 < 0) {
                {
                fprintf(_coverage_fout, "94\n");
                fflush(_coverage_fout);
                }
                rem5 = - rem5;
              } else {
                {
                fprintf(_coverage_fout, "95\n");
                fflush(_coverage_fout);
                }
                if (rem10 < 0) {
                  {
                  fprintf(_coverage_fout, "96\n");
                  fflush(_coverage_fout);
                  }
                  rem5 = - rem5;
                } else {
                  {
                  fprintf(_coverage_fout, "97\n");
                  fflush(_coverage_fout);
                  }

                }
              }
            }
          }
        }
      } else {
        {
        fprintf(_coverage_fout, "98\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "99\n");
      fflush(_coverage_fout);
      }
      tmp___6 = abs(n);
      {
      fprintf(_coverage_fout, "100\n");
      fflush(_coverage_fout);
      }
      if (tmp___6 >= 1000) {
        {
        fprintf(_coverage_fout, "101\n");
        fflush(_coverage_fout);
        }
        rem4 = n % 10000;
        {
        fprintf(_coverage_fout, "102\n");
        fflush(_coverage_fout);
        }
        rem4 /= 1000;
        {
        fprintf(_coverage_fout, "103\n");
        fflush(_coverage_fout);
        }
        if (rem5 < 0) {
          {
          fprintf(_coverage_fout, "104\n");
          fflush(_coverage_fout);
          }
          rem4 = - rem4;
        } else {
          {
          fprintf(_coverage_fout, "105\n");
          fflush(_coverage_fout);
          }
          if (rem6 < 0) {
            {
            fprintf(_coverage_fout, "106\n");
            fflush(_coverage_fout);
            }
            rem4 = - rem4;
          } else {
            {
            fprintf(_coverage_fout, "107\n");
            fflush(_coverage_fout);
            }
            if (rem7 < 0) {
              {
              fprintf(_coverage_fout, "108\n");
              fflush(_coverage_fout);
              }
              rem4 = - rem4;
            } else {
              {
              fprintf(_coverage_fout, "109\n");
              fflush(_coverage_fout);
              }
              if (rem8 < 0) {
                {
                fprintf(_coverage_fout, "110\n");
                fflush(_coverage_fout);
                }
                rem4 = - rem4;
              } else {
                {
                fprintf(_coverage_fout, "111\n");
                fflush(_coverage_fout);
                }
                if (rem9 < 0) {
                  {
                  fprintf(_coverage_fout, "112\n");
                  fflush(_coverage_fout);
                  }
                  rem4 = - rem4;
                } else {
                  {
                  fprintf(_coverage_fout, "113\n");
                  fflush(_coverage_fout);
                  }
                  if (rem10 < 0) {
                    {
                    fprintf(_coverage_fout, "114\n");
                    fflush(_coverage_fout);
                    }
                    rem4 = - rem4;
                  } else {
                    {
                    fprintf(_coverage_fout, "115\n");
                    fflush(_coverage_fout);
                    }

                  }
                }
              }
            }
          }
        }
      } else {
        {
        fprintf(_coverage_fout, "116\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "117\n");
      fflush(_coverage_fout);
      }
      tmp___7 = abs(n);
      {
      fprintf(_coverage_fout, "118\n");
      fflush(_coverage_fout);
      }
      if (tmp___7 >= 100) {
        {
        fprintf(_coverage_fout, "119\n");
        fflush(_coverage_fout);
        }
        rem3 = n % 1000;
        {
        fprintf(_coverage_fout, "120\n");
        fflush(_coverage_fout);
        }
        rem3 /= 100;
        {
        fprintf(_coverage_fout, "121\n");
        fflush(_coverage_fout);
        }
        if (rem4 < 0) {
          {
          fprintf(_coverage_fout, "122\n");
          fflush(_coverage_fout);
          }
          rem3 = - rem3;
        } else {
          {
          fprintf(_coverage_fout, "123\n");
          fflush(_coverage_fout);
          }
          if (rem6 < 0) {
            {
            fprintf(_coverage_fout, "124\n");
            fflush(_coverage_fout);
            }
            rem3 = - rem3;
          } else {
            {
            fprintf(_coverage_fout, "125\n");
            fflush(_coverage_fout);
            }
            if (rem7 < 0) {
              {
              fprintf(_coverage_fout, "126\n");
              fflush(_coverage_fout);
              }
              rem3 = - rem3;
            } else {
              {
              fprintf(_coverage_fout, "127\n");
              fflush(_coverage_fout);
              }
              if (rem8 < 0) {
                {
                fprintf(_coverage_fout, "128\n");
                fflush(_coverage_fout);
                }
                rem3 = - rem3;
              } else {
                {
                fprintf(_coverage_fout, "129\n");
                fflush(_coverage_fout);
                }
                if (rem9 < 0) {
                  {
                  fprintf(_coverage_fout, "130\n");
                  fflush(_coverage_fout);
                  }
                  rem3 = - rem3;
                } else {
                  {
                  fprintf(_coverage_fout, "131\n");
                  fflush(_coverage_fout);
                  }
                  if (rem10 < 0) {
                    {
                    fprintf(_coverage_fout, "132\n");
                    fflush(_coverage_fout);
                    }
                    rem3 = - rem3;
                  } else {
                    {
                    fprintf(_coverage_fout, "133\n");
                    fflush(_coverage_fout);
                    }

                  }
                }
              }
            }
          }
        }
      } else {
        {
        fprintf(_coverage_fout, "134\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "135\n");
      fflush(_coverage_fout);
      }
      tmp___8 = abs(n);
      {
      fprintf(_coverage_fout, "136\n");
      fflush(_coverage_fout);
      }
      if (tmp___8 >= 10) {
        {
        fprintf(_coverage_fout, "137\n");
        fflush(_coverage_fout);
        }
        rem2 = n % 100;
        {
        fprintf(_coverage_fout, "138\n");
        fflush(_coverage_fout);
        }
        rem2 /= 10;
        {
        fprintf(_coverage_fout, "139\n");
        fflush(_coverage_fout);
        }
        if (rem3 < 0) {
          {
          fprintf(_coverage_fout, "140\n");
          fflush(_coverage_fout);
          }
          rem2 = - rem2;
        } else {
          {
          fprintf(_coverage_fout, "141\n");
          fflush(_coverage_fout);
          }
          if (rem4 < 0) {
            {
            fprintf(_coverage_fout, "142\n");
            fflush(_coverage_fout);
            }
            rem2 = - rem2;
          } else {
            {
            fprintf(_coverage_fout, "143\n");
            fflush(_coverage_fout);
            }
            if (rem6 < 0) {
              {
              fprintf(_coverage_fout, "144\n");
              fflush(_coverage_fout);
              }
              rem2 = - rem2;
            } else {
              {
              fprintf(_coverage_fout, "145\n");
              fflush(_coverage_fout);
              }
              if (rem7 < 0) {
                {
                fprintf(_coverage_fout, "146\n");
                fflush(_coverage_fout);
                }
                rem2 = - rem2;
              } else {
                {
                fprintf(_coverage_fout, "147\n");
                fflush(_coverage_fout);
                }
                if (rem8 < 0) {
                  {
                  fprintf(_coverage_fout, "148\n");
                  fflush(_coverage_fout);
                  }
                  rem2 = - rem2;
                } else {
                  {
                  fprintf(_coverage_fout, "149\n");
                  fflush(_coverage_fout);
                  }
                  if (rem9 < 0) {
                    {
                    fprintf(_coverage_fout, "150\n");
                    fflush(_coverage_fout);
                    }
                    rem2 = - rem2;
                  } else {
                    {
                    fprintf(_coverage_fout, "151\n");
                    fflush(_coverage_fout);
                    }
                    if (rem10 < 0) {
                      {
                      fprintf(_coverage_fout, "152\n");
                      fflush(_coverage_fout);
                      }
                      rem2 = - rem2;
                    } else {
                      {
                      fprintf(_coverage_fout, "153\n");
                      fflush(_coverage_fout);
                      }

                    }
                  }
                }
              }
            }
          }
        }
      } else {
        {
        fprintf(_coverage_fout, "154\n");
        fflush(_coverage_fout);
        }

      }
      {
      fprintf(_coverage_fout, "155\n");
      fflush(_coverage_fout);
      }
      tmp___19 = abs(n);
      {
      fprintf(_coverage_fout, "156\n");
      fflush(_coverage_fout);
      }
      if (tmp___19 > 0) {
        {
        fprintf(_coverage_fout, "157\n");
        fflush(_coverage_fout);
        }
        rem1 = n % 10;
        {
        fprintf(_coverage_fout, "158\n");
        fflush(_coverage_fout);
        }
        if (n < -10) {
          {
          fprintf(_coverage_fout, "159\n");
          fflush(_coverage_fout);
          }
          rem1 = - rem1;
        } else {
          {
          fprintf(_coverage_fout, "160\n");
          fflush(_coverage_fout);
          }

        }
        {
        fprintf(_coverage_fout, "161\n");
        fflush(_coverage_fout);
        }
        tmp___17 = abs(n);
        {
        fprintf(_coverage_fout, "162\n");
        fflush(_coverage_fout);
        }
        if (tmp___17 >= 1000000000) {
          {
          fprintf(_coverage_fout, "163\n");
          fflush(_coverage_fout);
          }
          printf((char const   */* __restrict  */)"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                 rem1, rem2, rem3, rem4, rem5, rem6, rem7, rem8, rem9, rem10);
        } else {
          {
          fprintf(_coverage_fout, "164\n");
          fflush(_coverage_fout);
          }
          tmp___16 = abs(n);
          {
          fprintf(_coverage_fout, "165\n");
          fflush(_coverage_fout);
          }
          if (tmp___16 >= 100000000) {
            {
            fprintf(_coverage_fout, "166\n");
            fflush(_coverage_fout);
            }
            printf((char const   */* __restrict  */)"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                   rem1, rem2, rem3, rem4, rem5, rem6, rem7, rem8, rem9);
          } else {
            {
            fprintf(_coverage_fout, "167\n");
            fflush(_coverage_fout);
            }
            tmp___15 = abs(n);
            {
            fprintf(_coverage_fout, "168\n");
            fflush(_coverage_fout);
            }
            if (tmp___15 >= 10000000) {
              {
              fprintf(_coverage_fout, "169\n");
              fflush(_coverage_fout);
              }
              printf((char const   */* __restrict  */)"%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                     rem1, rem2, rem3, rem4, rem5, rem6, rem7, rem8);
            } else {
              {
              fprintf(_coverage_fout, "170\n");
              fflush(_coverage_fout);
              }
              tmp___14 = abs(n);
              {
              fprintf(_coverage_fout, "171\n");
              fflush(_coverage_fout);
              }
              if (tmp___14 >= 1000000) {
                {
                fprintf(_coverage_fout, "172\n");
                fflush(_coverage_fout);
                }
                printf((char const   */* __restrict  */)"%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                       rem1, rem2, rem3, rem4, rem5, rem6, rem7);
              } else {
                {
                fprintf(_coverage_fout, "173\n");
                fflush(_coverage_fout);
                }
                tmp___13 = abs(n);
                {
                fprintf(_coverage_fout, "174\n");
                fflush(_coverage_fout);
                }
                if (tmp___13 >= 100000) {
                  {
                  fprintf(_coverage_fout, "175\n");
                  fflush(_coverage_fout);
                  }
                  printf((char const   */* __restrict  */)"%d\n%d\n%d\n%d\n%d\n%d\n",
                         rem1, rem2, rem3, rem4, rem5, rem6);
                } else {
                  {
                  fprintf(_coverage_fout, "176\n");
                  fflush(_coverage_fout);
                  }
                  tmp___12 = abs(n);
                  {
                  fprintf(_coverage_fout, "177\n");
                  fflush(_coverage_fout);
                  }
                  if (tmp___12 >= 10000) {
                    {
                    fprintf(_coverage_fout, "178\n");
                    fflush(_coverage_fout);
                    }
                    printf((char const   */* __restrict  */)"%d\n%d\n%d\n%d\n%d\n",
                           rem1, rem2, rem3, rem4, rem5);
                  } else {
                    {
                    fprintf(_coverage_fout, "179\n");
                    fflush(_coverage_fout);
                    }
                    tmp___11 = abs(n);
                    {
                    fprintf(_coverage_fout, "180\n");
                    fflush(_coverage_fout);
                    }
                    if (tmp___11 >= 1000) {
                      {
                      fprintf(_coverage_fout, "181\n");
                      fflush(_coverage_fout);
                      }
                      printf((char const   */* __restrict  */)"%d\n%d\n%d\n%d\n",
                             rem1, rem2, rem3, rem4);
                    } else {
                      {
                      fprintf(_coverage_fout, "182\n");
                      fflush(_coverage_fout);
                      }
                      tmp___10 = abs(n);
                      {
                      fprintf(_coverage_fout, "183\n");
                      fflush(_coverage_fout);
                      }
                      if (tmp___10 >= 100) {
                        {
                        fprintf(_coverage_fout, "184\n");
                        fflush(_coverage_fout);
                        }
                        printf((char const   */* __restrict  */)"%d\n%d\n%d\n",
                               rem1, rem2, rem3);
                      } else {
                        {
                        fprintf(_coverage_fout, "185\n");
                        fflush(_coverage_fout);
                        }
                        tmp___9 = abs(n);
                        {
                        fprintf(_coverage_fout, "186\n");
                        fflush(_coverage_fout);
                        }
                        if (tmp___9 >= 10) {
                          {
                          fprintf(_coverage_fout, "187\n");
                          fflush(_coverage_fout);
                          }
                          printf((char const   */* __restrict  */)"%d\n%d\n",
                                 rem1, rem2);
                        } else {
                          {
                          fprintf(_coverage_fout, "188\n");
                          fflush(_coverage_fout);
                          }
                          printf((char const   */* __restrict  */)"%d\n", rem1);
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      } else {
        {
        fprintf(_coverage_fout, "189\n");
        fflush(_coverage_fout);
        }
        tmp___18 = abs(n);
        {
        fprintf(_coverage_fout, "190\n");
        fflush(_coverage_fout);
        }
        if (tmp___18 == 0) {
          {
          fprintf(_coverage_fout, "191\n");
          fflush(_coverage_fout);
          }
          printf((char const   */* __restrict  */)"0\n");
        } else {
          {
          fprintf(_coverage_fout, "192\n");
          fflush(_coverage_fout);
          }

        }
      }
      {
      fprintf(_coverage_fout, "193\n");
      fflush(_coverage_fout);
      }
      x = 1;
    }
  }
  {
  fprintf(_coverage_fout, "194\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"That\'s all, have a nice day!\n");
  {
  fprintf(_coverage_fout, "195\n");
  fflush(_coverage_fout);
  }
  return (0);
}
}