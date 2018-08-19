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
  int number ;
  int i ;
  int store ;
  int state ;

  {
  {
  if (_coverage_fout == 0) {
    {
    _coverage_fout = fopen("/workdir/experiment/digits-c5d8f924b86adfeafa7f520559aeb8bd0c3c178efe2500c4054c5ce51bcdbfc2da2e3d9fd5c73f559a7cb6c3b3555b04646111404744496cbcf31caa90e5beb4-17/./coverage.path",
                           "wb");
    }
  }
  }
  {
  fprintf(_coverage_fout, "1\n");
  fflush(_coverage_fout);
  }
  number = 0;
  {
  fprintf(_coverage_fout, "2\n");
  fflush(_coverage_fout);
  }
  i = 0;
  {
  fprintf(_coverage_fout, "3\n");
  fflush(_coverage_fout);
  }
  store = 0;
  {
  fprintf(_coverage_fout, "4\n");
  fflush(_coverage_fout);
  }
  state = 1;
  {
  fprintf(_coverage_fout, "5\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"\nEnter an integer > ");
  {
  fprintf(_coverage_fout, "6\n");
  fflush(_coverage_fout);
  }
  scanf((char const   */* __restrict  */)"%d", & number);
  {
  fprintf(_coverage_fout, "7\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"\n");
  {
  fprintf(_coverage_fout, "8\n");
  fflush(_coverage_fout);
  }
  while (1) {
    {
    fprintf(_coverage_fout, "9\n");
    fflush(_coverage_fout);
    }
    if (i < 9) {
      {
      fprintf(_coverage_fout, "10\n");
      fflush(_coverage_fout);
      }

    } else {
      break;
    }
    {
    fprintf(_coverage_fout, "12\n");
    fflush(_coverage_fout);
    }
    if (number < 0) {
      {
      fprintf(_coverage_fout, "13\n");
      fflush(_coverage_fout);
      }
      number *= -1;
      {
      fprintf(_coverage_fout, "14\n");
      fflush(_coverage_fout);
      }
      state = -1;
    } else {
      {
      fprintf(_coverage_fout, "15\n");
      fflush(_coverage_fout);
      }

    }
    {
    fprintf(_coverage_fout, "16\n");
    fflush(_coverage_fout);
    }
    store = number % 10;
    {
    fprintf(_coverage_fout, "17\n");
    fflush(_coverage_fout);
    }
    if (number <= 9) {
      {
      fprintf(_coverage_fout, "18\n");
      fflush(_coverage_fout);
      }
      store = number * state;
    } else {
      {
      fprintf(_coverage_fout, "19\n");
      fflush(_coverage_fout);
      }

    }
    {
    fprintf(_coverage_fout, "20\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"%d\n", store);
    {
    fprintf(_coverage_fout, "21\n");
    fflush(_coverage_fout);
    }
    number /= 10;
    {
    fprintf(_coverage_fout, "22\n");
    fflush(_coverage_fout);
    }
    i ++;
    {
    fprintf(_coverage_fout, "23\n");
    fflush(_coverage_fout);
    }
    if (number == 0) {
      {
      fprintf(_coverage_fout, "24\n");
      fflush(_coverage_fout);
      }
      printf((char const   */* __restrict  */)"That\'s all, have a nice day!\n");
      break;
    } else {
      {
      fprintf(_coverage_fout, "26\n");
      fflush(_coverage_fout);
      }

    }
  }
  {
  fprintf(_coverage_fout, "27\n");
  fflush(_coverage_fout);
  }
  return (0);
}
}
