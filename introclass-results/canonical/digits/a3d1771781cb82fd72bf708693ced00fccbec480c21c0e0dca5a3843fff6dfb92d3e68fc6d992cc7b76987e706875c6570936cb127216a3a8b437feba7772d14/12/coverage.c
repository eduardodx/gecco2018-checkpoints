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
int main(void) 
{ 
  int n ;
  int d10 ;
  int d9 ;
  int d8 ;
  int d7 ;
  int d6 ;
  int d5 ;
  int d4 ;
  int d3 ;
  int d2 ;
  int d1 ;

  {
  {
  if (_coverage_fout == 0) {
    {
    _coverage_fout = fopen("/workdir/experiment/digits-a3d1771781cb82fd72bf708693ced00fccbec480c21c0e0dca5a3843fff6dfb92d3e68fc6d992cc7b76987e706875c6570936cb127216a3a8b437feba7772d14-12/./coverage.path",
                           "wb");
    }
  }
  }
  {
  fprintf(_coverage_fout, "1\n");
  fflush(_coverage_fout);
  }
  d10 = 0;
  {
  fprintf(_coverage_fout, "2\n");
  fflush(_coverage_fout);
  }
  d9 = 0;
  {
  fprintf(_coverage_fout, "3\n");
  fflush(_coverage_fout);
  }
  d8 = 0;
  {
  fprintf(_coverage_fout, "4\n");
  fflush(_coverage_fout);
  }
  d7 = 0;
  {
  fprintf(_coverage_fout, "5\n");
  fflush(_coverage_fout);
  }
  d6 = 0;
  {
  fprintf(_coverage_fout, "6\n");
  fflush(_coverage_fout);
  }
  d5 = 0;
  {
  fprintf(_coverage_fout, "7\n");
  fflush(_coverage_fout);
  }
  d4 = 0;
  {
  fprintf(_coverage_fout, "8\n");
  fflush(_coverage_fout);
  }
  d3 = 0;
  {
  fprintf(_coverage_fout, "9\n");
  fflush(_coverage_fout);
  }
  d2 = 0;
  {
  fprintf(_coverage_fout, "10\n");
  fflush(_coverage_fout);
  }
  d1 = 0;
  {
  fprintf(_coverage_fout, "11\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"\nEnter an integer > ");
  {
  fprintf(_coverage_fout, "12\n");
  fflush(_coverage_fout);
  }
  scanf((char const   */* __restrict  */)"%d", & n);
  {
  fprintf(_coverage_fout, "13\n");
  fflush(_coverage_fout);
  }
  d1 = n % 10;
  {
  fprintf(_coverage_fout, "14\n");
  fflush(_coverage_fout);
  }
  d2 = (n % 100 - n % 10) / 10;
  {
  fprintf(_coverage_fout, "15\n");
  fflush(_coverage_fout);
  }
  d3 = (n % 1000 - n % 100) / 100;
  {
  fprintf(_coverage_fout, "16\n");
  fflush(_coverage_fout);
  }
  d4 = (n % 10000 - n % 1000) / 1000;
  {
  fprintf(_coverage_fout, "17\n");
  fflush(_coverage_fout);
  }
  d5 = (n % 100000 - n % 10000) / 10000;
  {
  fprintf(_coverage_fout, "18\n");
  fflush(_coverage_fout);
  }
  d6 = (n % 1000000 - n % 100000) / 100000;
  {
  fprintf(_coverage_fout, "19\n");
  fflush(_coverage_fout);
  }
  d7 = (n % 10000000 - n % 1000000) / 1000000;
  {
  fprintf(_coverage_fout, "20\n");
  fflush(_coverage_fout);
  }
  d8 = (n % 100000000 - n % 10000000) / 10000000;
  {
  fprintf(_coverage_fout, "21\n");
  fflush(_coverage_fout);
  }
  d9 = (n % 1000000000 - n % 100000000) / 100000000;
  {
  fprintf(_coverage_fout, "22\n");
  fflush(_coverage_fout);
  }
  d10 = (int )(((long )n % 10000000000L - (long )(n % 1000000000)) / 1000000000L);
  {
  fprintf(_coverage_fout, "23\n");
  fflush(_coverage_fout);
  }
  if (d1 != 0) {
    {
    fprintf(_coverage_fout, "24\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d1);
  } else {
    {
    fprintf(_coverage_fout, "25\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "26\n");
  fflush(_coverage_fout);
  }
  if (d2 != 0) {
    {
    fprintf(_coverage_fout, "27\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d2);
  } else {
    {
    fprintf(_coverage_fout, "28\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "29\n");
  fflush(_coverage_fout);
  }
  if (d3 != 0) {
    {
    fprintf(_coverage_fout, "30\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d3);
  } else {
    {
    fprintf(_coverage_fout, "31\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "32\n");
  fflush(_coverage_fout);
  }
  if (d4 != 0) {
    {
    fprintf(_coverage_fout, "33\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d4);
  } else {
    {
    fprintf(_coverage_fout, "34\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "35\n");
  fflush(_coverage_fout);
  }
  if (d5 != 0) {
    {
    fprintf(_coverage_fout, "36\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d5);
  } else {
    {
    fprintf(_coverage_fout, "37\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "38\n");
  fflush(_coverage_fout);
  }
  if (d6 != 0) {
    {
    fprintf(_coverage_fout, "39\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d6);
  } else {
    {
    fprintf(_coverage_fout, "40\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "41\n");
  fflush(_coverage_fout);
  }
  if (d7 != 0) {
    {
    fprintf(_coverage_fout, "42\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d7);
  } else {
    {
    fprintf(_coverage_fout, "43\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "44\n");
  fflush(_coverage_fout);
  }
  if (d8 != 0) {
    {
    fprintf(_coverage_fout, "45\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d8);
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
  if (d9 != 0) {
    {
    fprintf(_coverage_fout, "48\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d9);
  } else {
    {
    fprintf(_coverage_fout, "49\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "50\n");
  fflush(_coverage_fout);
  }
  if (d10 != 0) {
    {
    fprintf(_coverage_fout, "51\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n%d", d10);
  } else {
    {
    fprintf(_coverage_fout, "52\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "53\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"\nThat\'s all, have a nice day!\n");
  {
  fprintf(_coverage_fout, "54\n");
  fflush(_coverage_fout);
  }
  return (0);
}
}
