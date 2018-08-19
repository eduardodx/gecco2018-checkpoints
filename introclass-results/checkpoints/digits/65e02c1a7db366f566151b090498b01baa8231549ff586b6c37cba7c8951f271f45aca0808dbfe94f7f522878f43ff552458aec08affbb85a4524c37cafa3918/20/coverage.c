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
typedef int wchar_t;
enum __anonenum_idtype_t_8 {
    P_ALL = 0,
    P_PID = 1,
    P_PGID = 2
} ;
typedef enum __anonenum_idtype_t_8 idtype_t;
struct __anonstruct___wait_terminated_9 {
   unsigned int __w_termsig : 7 ;
   unsigned int __w_coredump : 1 ;
   unsigned int __w_retcode : 8 ;
   unsigned int  : 16 ;
};
struct __anonstruct___wait_stopped_10 {
   unsigned int __w_stopval : 8 ;
   unsigned int __w_stopsig : 8 ;
   unsigned int  : 16 ;
};
union wait {
   int w_status ;
   struct __anonstruct___wait_terminated_9 __wait_terminated ;
   struct __anonstruct___wait_stopped_10 __wait_stopped ;
};
union __anonunion___WAIT_STATUS_11 {
   union wait *__uptr ;
   int *__iptr ;
};
typedef union __anonunion___WAIT_STATUS_11  __attribute__((__transparent_union__)) __WAIT_STATUS;
struct __anonstruct_div_t_12 {
   int quot ;
   int rem ;
};
typedef struct __anonstruct_div_t_12 div_t;
struct __anonstruct_ldiv_t_13 {
   long quot ;
   long rem ;
};
typedef struct __anonstruct_ldiv_t_13 ldiv_t;
struct __anonstruct_lldiv_t_14 {
   long long quot ;
   long long rem ;
};
typedef struct __anonstruct_lldiv_t_14 lldiv_t;
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino_t ino_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __time_t time_t;
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long int64_t;
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long u_int64_t;
typedef int register_t;
typedef int __sig_atomic_t;
struct __anonstruct___sigset_t_15 {
   unsigned long __val[1024UL / (8UL * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___sigset_t_15 __sigset_t;
typedef __sigset_t sigset_t;
struct timespec {
   __time_t tv_sec ;
   __syscall_slong_t tv_nsec ;
};
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
typedef __suseconds_t suseconds_t;
typedef long __fd_mask;
struct __anonstruct_fd_set_16 {
   __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef struct __anonstruct_fd_set_16 fd_set;
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef __blkcnt_t blkcnt_t;
typedef __fsblkcnt_t fsblkcnt_t;
typedef __fsfilcnt_t fsfilcnt_t;
typedef unsigned long pthread_t;
union pthread_attr_t {
   char __size[56] ;
   long __align ;
};
typedef union pthread_attr_t pthread_attr_t;
struct __pthread_internal_list {
   struct __pthread_internal_list *__prev ;
   struct __pthread_internal_list *__next ;
};
typedef struct __pthread_internal_list __pthread_list_t;
struct __pthread_mutex_s {
   int __lock ;
   unsigned int __count ;
   int __owner ;
   unsigned int __nusers ;
   int __kind ;
   short __spins ;
   short __elision ;
   __pthread_list_t __list ;
};
union __anonunion_pthread_mutex_t_17 {
   struct __pthread_mutex_s __data ;
   char __size[40] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_17 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_18 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_mutexattr_t_18 pthread_mutexattr_t;
struct __anonstruct___data_20 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_19 {
   struct __anonstruct___data_20 __data ;
   char __size[48] ;
   long long __align ;
};
typedef union __anonunion_pthread_cond_t_19 pthread_cond_t;
union __anonunion_pthread_condattr_t_21 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_condattr_t_21 pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
struct __anonstruct___data_23 {
   int __lock ;
   unsigned int __nr_readers ;
   unsigned int __readers_wakeup ;
   unsigned int __writer_wakeup ;
   unsigned int __nr_readers_queued ;
   unsigned int __nr_writers_queued ;
   int __writer ;
   int __shared ;
   unsigned long __pad1 ;
   unsigned long __pad2 ;
   unsigned int __flags ;
};
union __anonunion_pthread_rwlock_t_22 {
   struct __anonstruct___data_23 __data ;
   char __size[56] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlock_t_22 pthread_rwlock_t;
union __anonunion_pthread_rwlockattr_t_24 {
   char __size[8] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlockattr_t_24 pthread_rwlockattr_t;
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_25 {
   char __size[32] ;
   long __align ;
};
typedef union __anonunion_pthread_barrier_t_25 pthread_barrier_t;
union __anonunion_pthread_barrierattr_t_26 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_barrierattr_t_26 pthread_barrierattr_t;
struct random_data {
   int32_t *fptr ;
   int32_t *rptr ;
   int32_t *state ;
   int rand_type ;
   int rand_deg ;
   int rand_sep ;
   int32_t *end_ptr ;
};
struct drand48_data {
   unsigned short __x[3] ;
   unsigned short __old_x[3] ;
   unsigned short __c ;
   unsigned short __init ;
   unsigned long long __a ;
};
typedef int (*__compar_fn_t)(void const   * , void const   * );
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
__inline static unsigned int __bswap_32(unsigned int __bsx ) 
{ 
  int tmp ;

  {
  {
  if (_coverage_fout == 0) {
    {
    _coverage_fout = fopen("/workdir/experiment/digits-65e02c1a7db366f566151b090498b01baa8231549ff586b6c37cba7c8951f271f45aca0808dbfe94f7f522878f43ff552458aec08affbb85a4524c37cafa3918-20/./coverage.path",
                           "wb");
    }
  }
  }
  {
  fprintf(_coverage_fout, "1\n");
  fflush(_coverage_fout);
  }
  tmp = __builtin_bswap32((int )__bsx);
  {
  fprintf(_coverage_fout, "2\n");
  fflush(_coverage_fout);
  }
  return ((unsigned int )tmp);
}
}
__inline static __uint64_t __bswap_64(__uint64_t __bsx ) 
{ 
  long tmp ;

  {
  {
  if (_coverage_fout == 0) {
    {
    _coverage_fout = fopen("/workdir/experiment/digits-65e02c1a7db366f566151b090498b01baa8231549ff586b6c37cba7c8951f271f45aca0808dbfe94f7f522878f43ff552458aec08affbb85a4524c37cafa3918-20/./coverage.path",
                           "wb");
    }
  }
  }
  {
  fprintf(_coverage_fout, "3\n");
  fflush(_coverage_fout);
  }
  tmp = __builtin_bswap64((long )__bsx);
  {
  fprintf(_coverage_fout, "4\n");
  fflush(_coverage_fout);
  }
  return ((__uint64_t )tmp);
}
}
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) __ctype_get_mb_cur_max)(void) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1),
__leaf__)) atof)(char const   *__nptr )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) atoi)(char const   *__nptr )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1),
__leaf__)) atol)(char const   *__nptr )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__nonnull__(1),
__leaf__)) atoll)(char const   *__nptr )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1),
__leaf__)) strtod)(char const   * __restrict  __nptr ,
                   char ** __restrict  __endptr ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__nonnull__(1),
__leaf__)) strtof)(char const   * __restrict  __nptr ,
                   char ** __restrict  __endptr ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__nonnull__(1),
__leaf__)) strtold)(char const   * __restrict  __nptr ,
                    char ** __restrict  __endptr ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1),
__leaf__)) strtol)(char const   * __restrict  __nptr ,
                   char ** __restrict  __endptr , int __base ) ;
extern  __attribute__((__nothrow__)) unsigned long ( __attribute__((__nonnull__(1),
__leaf__)) strtoul)(char const   * __restrict  __nptr ,
                    char ** __restrict  __endptr , int __base ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__nonnull__(1),
__leaf__)) strtoq)(char const   * __restrict  __nptr ,
                   char ** __restrict  __endptr , int __base ) ;
extern  __attribute__((__nothrow__)) unsigned long long ( __attribute__((__nonnull__(1),
__leaf__)) strtouq)(char const   * __restrict  __nptr ,
                    char ** __restrict  __endptr , int __base ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__nonnull__(1),
__leaf__)) strtoll)(char const   * __restrict  __nptr ,
                    char ** __restrict  __endptr , int __base ) ;
extern  __attribute__((__nothrow__)) unsigned long long ( __attribute__((__nonnull__(1),
__leaf__)) strtoull)(char const   * __restrict  __nptr ,
                     char ** __restrict  __endptr , int __base ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) l64a)(long __n ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1),
__leaf__)) a64l)(char const   *__s )  __attribute__((__pure__)) ;
extern int select(int __nfds , fd_set * __restrict  __readfds ,
                  fd_set * __restrict  __writefds ,
                  fd_set * __restrict  __exceptfds ,
                  struct timeval * __restrict  __timeout ) ;
extern int pselect(int __nfds , fd_set * __restrict  __readfds ,
                   fd_set * __restrict  __writefds ,
                   fd_set * __restrict  __exceptfds ,
                   struct timespec  const  * __restrict  __timeout ,
                   __sigset_t const   * __restrict  __sigmask ) ;
extern  __attribute__((__nothrow__)) unsigned int ( __attribute__((__leaf__)) gnu_dev_major)(unsigned long long __dev )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) unsigned int ( __attribute__((__leaf__)) gnu_dev_minor)(unsigned long long __dev )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) unsigned long long ( __attribute__((__leaf__)) gnu_dev_makedev)(unsigned int __major ,
                                                                                                     unsigned int __minor )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) random)(void) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) srandom)(unsigned int __seed ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2),
__leaf__)) initstate)(unsigned int __seed , char *__statebuf ,
                      size_t __statelen ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1),
__leaf__)) setstate)(char *__statebuf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) random_r)(struct random_data * __restrict  __buf ,
                     int32_t * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2),
__leaf__)) srandom_r)(unsigned int __seed , struct random_data *__buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,4),
__leaf__)) initstate_r)(unsigned int __seed , char * __restrict  __statebuf ,
                        size_t __statelen ,
                        struct random_data * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) setstate_r)(char * __restrict  __statebuf ,
                       struct random_data * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) rand)(void) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) srand)(unsigned int __seed ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) rand_r)(unsigned int *__seed ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__leaf__)) drand48)(void) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1),
__leaf__)) erand48)(unsigned short *__xsubi ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) lrand48)(void) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1),
__leaf__)) nrand48)(unsigned short *__xsubi ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) mrand48)(void) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1),
__leaf__)) jrand48)(unsigned short *__xsubi ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) srand48)(long __seedval ) ;
extern  __attribute__((__nothrow__)) unsigned short *( __attribute__((__nonnull__(1),
__leaf__)) seed48)(unsigned short *__seed16v ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1),
__leaf__)) lcong48)(unsigned short *__param ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) drand48_r)(struct drand48_data * __restrict  __buffer ,
                      double * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) erand48_r)(unsigned short *__xsubi ,
                      struct drand48_data * __restrict  __buffer ,
                      double * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) lrand48_r)(struct drand48_data * __restrict  __buffer ,
                      long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) nrand48_r)(unsigned short *__xsubi ,
                      struct drand48_data * __restrict  __buffer ,
                      long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) mrand48_r)(struct drand48_data * __restrict  __buffer ,
                      long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) jrand48_r)(unsigned short *__xsubi ,
                      struct drand48_data * __restrict  __buffer ,
                      long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2),
__leaf__)) srand48_r)(long __seedval , struct drand48_data *__buffer ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) seed48_r)(unsigned short *__seed16v , struct drand48_data *__buffer ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2),
__leaf__)) lcong48_r)(unsigned short *__param , struct drand48_data *__buffer ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) malloc)(size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) calloc)(size_t __nmemb ,
                                                                               size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__warn_unused_result__,
__leaf__)) realloc)(void *__ptr , size_t __size ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) free)(void *__ptr ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) cfree)(void *__ptr ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) alloca)(size_t __size ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__leaf__)) valloc)(size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) posix_memalign)(void **__memptr , size_t __alignment , size_t __size ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void ( __attribute__((__leaf__)) abort)(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) atexit)(void (*__func)(void) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) on_exit)(void (*__func)(int __status , void *__arg ) , void *__arg ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void ( __attribute__((__leaf__)) exit)(int __status ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void ( __attribute__((__leaf__)) _Exit)(int __status ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1),
__leaf__)) getenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) putenv)(char *__string ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2),
__leaf__)) setenv)(char const   *__name , char const   *__value , int __replace ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) unsetenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) clearenv)(void) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1),
__leaf__)) mktemp)(char *__template ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemp)(char *__template ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemps)(char *__template ,
                                                       int __suffixlen ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1),
__leaf__)) mkdtemp)(char *__template ) ;
extern int system(char const   *__command ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__leaf__)) realpath)(char const   * __restrict  __name ,
                                                                                 char * __restrict  __resolved ) ;
extern void *( __attribute__((__nonnull__(1,2,5))) bsearch)(void const   *__key ,
                                                            void const   *__base ,
                                                            size_t __nmemb ,
                                                            size_t __size ,
                                                            int (*__compar)(void const   * ,
                                                                            void const   * ) ) ;
extern void ( __attribute__((__nonnull__(1,4))) qsort)(void *__base ,
                                                       size_t __nmemb ,
                                                       size_t __size ,
                                                       int (*__compar)(void const   * ,
                                                                       void const   * ) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) abs)(int __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__leaf__)) labs)(long __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__leaf__)) llabs)(long long __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) div_t ( __attribute__((__leaf__)) div)(int __numer ,
                                                                            int __denom )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) ldiv_t ( __attribute__((__leaf__)) ldiv)(long __numer ,
                                                                              long __denom )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) lldiv_t ( __attribute__((__leaf__)) lldiv)(long long __numer ,
                                                                                long long __denom )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4),
__leaf__)) ecvt)(double __value , int __ndigit , int * __restrict  __decpt ,
                 int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4),
__leaf__)) fcvt)(double __value , int __ndigit , int * __restrict  __decpt ,
                 int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3),
__leaf__)) gcvt)(double __value , int __ndigit , char *__buf ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4),
__leaf__)) qecvt)(long double __value , int __ndigit ,
                  int * __restrict  __decpt , int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4),
__leaf__)) qfcvt)(long double __value , int __ndigit ,
                  int * __restrict  __decpt , int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3),
__leaf__)) qgcvt)(long double __value , int __ndigit , char *__buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5),
__leaf__)) ecvt_r)(double __value , int __ndigit , int * __restrict  __decpt ,
                   int * __restrict  __sign , char * __restrict  __buf ,
                   size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5),
__leaf__)) fcvt_r)(double __value , int __ndigit , int * __restrict  __decpt ,
                   int * __restrict  __sign , char * __restrict  __buf ,
                   size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5),
__leaf__)) qecvt_r)(long double __value , int __ndigit ,
                    int * __restrict  __decpt , int * __restrict  __sign ,
                    char * __restrict  __buf , size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5),
__leaf__)) qfcvt_r)(long double __value , int __ndigit ,
                    int * __restrict  __decpt , int * __restrict  __sign ,
                    char * __restrict  __buf , size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) mblen)(char const   *__s ,
                                                                            size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) mbtowc)(wchar_t * __restrict  __pwc ,
                                                                             char const   * __restrict  __s ,
                                                                             size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) wctomb)(char *__s ,
                                                                             wchar_t __wchar ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) mbstowcs)(wchar_t * __restrict  __pwcs ,
                                                                                  char const   * __restrict  __s ,
                                                                                  size_t __n ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__leaf__)) wcstombs)(char * __restrict  __s ,
                                                                                  wchar_t const   * __restrict  __pwcs ,
                                                                                  size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) rpmatch)(char const   *__response ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,3),
__leaf__)) getsubopt)(char ** __restrict  __optionp ,
                      char * const  * __restrict  __tokens ,
                      char ** __restrict  __valuep ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1),
__leaf__)) getloadavg)(double *__loadavg , int __nelem ) ;
int main(void) 
{ 
  int d1 ;
  int d2 ;
  int d3 ;
  int d4 ;
  int d5 ;
  int d6 ;
  int d7 ;
  int d8 ;
  int d9 ;
  int d10 ;
  int absnum ;
  int num ;
  double floatnum ;

  {
  {
  if (_coverage_fout == 0) {
    {
    _coverage_fout = fopen("/workdir/experiment/digits-65e02c1a7db366f566151b090498b01baa8231549ff586b6c37cba7c8951f271f45aca0808dbfe94f7f522878f43ff552458aec08affbb85a4524c37cafa3918-20/./coverage.path",
                           "wb");
    }
  }
  }
  {
  fprintf(_coverage_fout, "5\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"\nEnter an integer > ");
  {
  fprintf(_coverage_fout, "6\n");
  fflush(_coverage_fout);
  }
  scanf((char const   */* __restrict  */)"%lf", & floatnum);
  {
  fprintf(_coverage_fout, "7\n");
  fflush(_coverage_fout);
  }
  num = (int )floatnum;
  {
  fprintf(_coverage_fout, "8\n");
  fflush(_coverage_fout);
  }
  absnum = abs(num);
  {
  fprintf(_coverage_fout, "9\n");
  fflush(_coverage_fout);
  }
  if (num >= 0) {
    {
    fprintf(_coverage_fout, "10\n");
    fflush(_coverage_fout);
    }
    if ((long )absnum < 10000000000L) {
      {
      fprintf(_coverage_fout, "11\n");
      fflush(_coverage_fout);
      }
      if (num >= 0) {
        {
        fprintf(_coverage_fout, "12\n");
        fflush(_coverage_fout);
        }
        if ((long )num < 10000000000L) {
          {
          fprintf(_coverage_fout, "13\n");
          fflush(_coverage_fout);
          }
          d1 = num % 10;
          {
          fprintf(_coverage_fout, "14\n");
          fflush(_coverage_fout);
          }
          d2 = (num % 100) / 10;
          {
          fprintf(_coverage_fout, "15\n");
          fflush(_coverage_fout);
          }
          d3 = (num % 1000) / 100;
          {
          fprintf(_coverage_fout, "16\n");
          fflush(_coverage_fout);
          }
          d4 = (num % 10000) / 1000;
          {
          fprintf(_coverage_fout, "17\n");
          fflush(_coverage_fout);
          }
          d5 = (num % 100000) / 10000;
          {
          fprintf(_coverage_fout, "18\n");
          fflush(_coverage_fout);
          }
          d6 = (num % 1000000) / 100000;
          {
          fprintf(_coverage_fout, "19\n");
          fflush(_coverage_fout);
          }
          d7 = (num % 10000000) / 1000000;
          {
          fprintf(_coverage_fout, "20\n");
          fflush(_coverage_fout);
          }
          d8 = (num % 100000000) / 10000000;
          {
          fprintf(_coverage_fout, "21\n");
          fflush(_coverage_fout);
          }
          d9 = (num % 1000000000) / 100000000;
          {
          fprintf(_coverage_fout, "22\n");
          fflush(_coverage_fout);
          }
          d10 = (((((((((num - d1) - d2 * 10) - d3 * 100) - d4 * 1000) - d5 * 10000) - d6 * 100000) - d7 * 1000000) - d8 * 10000000) - d9 * 100000000) / 1000000000;
          {
          fprintf(_coverage_fout, "23\n");
          fflush(_coverage_fout);
          }
          if (d10 == 0) {
            {
            fprintf(_coverage_fout, "24\n");
            fflush(_coverage_fout);
            }
            if (d9 != 0) {
              {
              fprintf(_coverage_fout, "25\n");
              fflush(_coverage_fout);
              }
              printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                     d1, d2, d3, d4, d5, d6, d7, d8, d9);
            } else {
              goto _L___79;
            }
          } else {
            {
            fprintf(_coverage_fout, "27\n");
            fflush(_coverage_fout);
            }
            _L___79: /* CIL Label */ 
            if (d10 == 0) {
              {
              fprintf(_coverage_fout, "28\n");
              fflush(_coverage_fout);
              }
              if (d9 == 0) {
                {
                fprintf(_coverage_fout, "29\n");
                fflush(_coverage_fout);
                }
                if (d8 != 0) {
                  {
                  fprintf(_coverage_fout, "30\n");
                  fflush(_coverage_fout);
                  }
                  printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                         d1, d2, d3, d4, d5, d6, d7, d8);
                } else {
                  goto _L___78;
                }
              } else {
                goto _L___78;
              }
            } else {
              {
              fprintf(_coverage_fout, "33\n");
              fflush(_coverage_fout);
              }
              _L___78: /* CIL Label */ 
              _L___77: /* CIL Label */ 
              if (d10 == 0) {
                {
                fprintf(_coverage_fout, "34\n");
                fflush(_coverage_fout);
                }
                if (d9 == 0) {
                  {
                  fprintf(_coverage_fout, "35\n");
                  fflush(_coverage_fout);
                  }
                  if (d8 == 0) {
                    {
                    fprintf(_coverage_fout, "36\n");
                    fflush(_coverage_fout);
                    }
                    if (d7 != 0) {
                      {
                      fprintf(_coverage_fout, "37\n");
                      fflush(_coverage_fout);
                      }
                      printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n",
                             d1, d2, d3, d4, d5, d6, d7);
                    } else {
                      goto _L___76;
                    }
                  } else {
                    goto _L___76;
                  }
                } else {
                  goto _L___76;
                }
              } else {
                {
                fprintf(_coverage_fout, "41\n");
                fflush(_coverage_fout);
                }
                _L___76: /* CIL Label */ 
                _L___75: /* CIL Label */ 
                _L___74: /* CIL Label */ 
                if (d10 == 0) {
                  {
                  fprintf(_coverage_fout, "42\n");
                  fflush(_coverage_fout);
                  }
                  if (d9 == 0) {
                    {
                    fprintf(_coverage_fout, "43\n");
                    fflush(_coverage_fout);
                    }
                    if (d8 == 0) {
                      {
                      fprintf(_coverage_fout, "44\n");
                      fflush(_coverage_fout);
                      }
                      if (d7 == 0) {
                        {
                        fprintf(_coverage_fout, "45\n");
                        fflush(_coverage_fout);
                        }
                        if (d6 != 0) {
                          {
                          fprintf(_coverage_fout, "46\n");
                          fflush(_coverage_fout);
                          }
                          printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n%d\n",
                                 d1, d2, d3, d4, d5, d6);
                        } else {
                          goto _L___73;
                        }
                      } else {
                        goto _L___73;
                      }
                    } else {
                      goto _L___73;
                    }
                  } else {
                    goto _L___73;
                  }
                } else {
                  {
                  fprintf(_coverage_fout, "51\n");
                  fflush(_coverage_fout);
                  }
                  _L___73: /* CIL Label */ 
                  _L___72: /* CIL Label */ 
                  _L___71: /* CIL Label */ 
                  _L___70: /* CIL Label */ 
                  if (d10 == 0) {
                    {
                    fprintf(_coverage_fout, "52\n");
                    fflush(_coverage_fout);
                    }
                    if (d9 == 0) {
                      {
                      fprintf(_coverage_fout, "53\n");
                      fflush(_coverage_fout);
                      }
                      if (d8 == 0) {
                        {
                        fprintf(_coverage_fout, "54\n");
                        fflush(_coverage_fout);
                        }
                        if (d7 == 0) {
                          {
                          fprintf(_coverage_fout, "55\n");
                          fflush(_coverage_fout);
                          }
                          if (d6 == 0) {
                            {
                            fprintf(_coverage_fout, "56\n");
                            fflush(_coverage_fout);
                            }
                            if (d5 != 0) {
                              {
                              fprintf(_coverage_fout, "57\n");
                              fflush(_coverage_fout);
                              }
                              printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n",
                                     d1, d2, d3, d4, d5);
                            } else {
                              goto _L___69;
                            }
                          } else {
                            goto _L___69;
                          }
                        } else {
                          goto _L___69;
                        }
                      } else {
                        goto _L___69;
                      }
                    } else {
                      goto _L___69;
                    }
                  } else {
                    {
                    fprintf(_coverage_fout, "63\n");
                    fflush(_coverage_fout);
                    }
                    _L___69: /* CIL Label */ 
                    _L___68: /* CIL Label */ 
                    _L___67: /* CIL Label */ 
                    _L___66: /* CIL Label */ 
                    _L___65: /* CIL Label */ 
                    if (d10 == 0) {
                      {
                      fprintf(_coverage_fout, "64\n");
                      fflush(_coverage_fout);
                      }
                      if (d9 == 0) {
                        {
                        fprintf(_coverage_fout, "65\n");
                        fflush(_coverage_fout);
                        }
                        if (d8 == 0) {
                          {
                          fprintf(_coverage_fout, "66\n");
                          fflush(_coverage_fout);
                          }
                          if (d7 == 0) {
                            {
                            fprintf(_coverage_fout, "67\n");
                            fflush(_coverage_fout);
                            }
                            if (d6 == 0) {
                              {
                              fprintf(_coverage_fout, "68\n");
                              fflush(_coverage_fout);
                              }
                              if (d5 == 0) {
                                {
                                fprintf(_coverage_fout, "69\n");
                                fflush(_coverage_fout);
                                }
                                if (d4 != 0) {
                                  {
                                  fprintf(_coverage_fout, "70\n");
                                  fflush(_coverage_fout);
                                  }
                                  printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n",
                                         d1, d2, d3, d4);
                                } else {
                                  goto _L___64;
                                }
                              } else {
                                goto _L___64;
                              }
                            } else {
                              goto _L___64;
                            }
                          } else {
                            goto _L___64;
                          }
                        } else {
                          goto _L___64;
                        }
                      } else {
                        goto _L___64;
                      }
                    } else {
                      {
                      fprintf(_coverage_fout, "77\n");
                      fflush(_coverage_fout);
                      }
                      _L___64: /* CIL Label */ 
                      _L___63: /* CIL Label */ 
                      _L___62: /* CIL Label */ 
                      _L___61: /* CIL Label */ 
                      _L___60: /* CIL Label */ 
                      _L___59: /* CIL Label */ 
                      if (d10 == 0) {
                        {
                        fprintf(_coverage_fout, "78\n");
                        fflush(_coverage_fout);
                        }
                        if (d9 == 0) {
                          {
                          fprintf(_coverage_fout, "79\n");
                          fflush(_coverage_fout);
                          }
                          if (d8 == 0) {
                            {
                            fprintf(_coverage_fout, "80\n");
                            fflush(_coverage_fout);
                            }
                            if (d7 == 0) {
                              {
                              fprintf(_coverage_fout, "81\n");
                              fflush(_coverage_fout);
                              }
                              if (d6 == 0) {
                                {
                                fprintf(_coverage_fout, "82\n");
                                fflush(_coverage_fout);
                                }
                                if (d5 == 0) {
                                  {
                                  fprintf(_coverage_fout, "83\n");
                                  fflush(_coverage_fout);
                                  }
                                  if (d4 == 0) {
                                    {
                                    fprintf(_coverage_fout, "84\n");
                                    fflush(_coverage_fout);
                                    }
                                    if (d3 != 0) {
                                      {
                                      fprintf(_coverage_fout, "85\n");
                                      fflush(_coverage_fout);
                                      }
                                      printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n",
                                             d1, d2, d3);
                                    } else {
                                      goto _L___58;
                                    }
                                  } else {
                                    goto _L___58;
                                  }
                                } else {
                                  goto _L___58;
                                }
                              } else {
                                goto _L___58;
                              }
                            } else {
                              goto _L___58;
                            }
                          } else {
                            goto _L___58;
                          }
                        } else {
                          goto _L___58;
                        }
                      } else {
                        {
                        fprintf(_coverage_fout, "93\n");
                        fflush(_coverage_fout);
                        }
                        _L___58: /* CIL Label */ 
                        _L___57: /* CIL Label */ 
                        _L___56: /* CIL Label */ 
                        _L___55: /* CIL Label */ 
                        _L___54: /* CIL Label */ 
                        _L___53: /* CIL Label */ 
                        _L___52: /* CIL Label */ 
                        if (d10 == 0) {
                          {
                          fprintf(_coverage_fout, "94\n");
                          fflush(_coverage_fout);
                          }
                          if (d9 == 0) {
                            {
                            fprintf(_coverage_fout, "95\n");
                            fflush(_coverage_fout);
                            }
                            if (d8 == 0) {
                              {
                              fprintf(_coverage_fout, "96\n");
                              fflush(_coverage_fout);
                              }
                              if (d7 == 0) {
                                {
                                fprintf(_coverage_fout, "97\n");
                                fflush(_coverage_fout);
                                }
                                if (d6 == 0) {
                                  {
                                  fprintf(_coverage_fout, "98\n");
                                  fflush(_coverage_fout);
                                  }
                                  if (d5 == 0) {
                                    {
                                    fprintf(_coverage_fout, "99\n");
                                    fflush(_coverage_fout);
                                    }
                                    if (d4 == 0) {
                                      {
                                      fprintf(_coverage_fout, "100\n");
                                      fflush(_coverage_fout);
                                      }
                                      if (d3 == 0) {
                                        {
                                        fprintf(_coverage_fout, "101\n");
                                        fflush(_coverage_fout);
                                        }
                                        if (d2 != 0) {
                                          {
                                          fprintf(_coverage_fout, "102\n");
                                          fflush(_coverage_fout);
                                          }
                                          printf((char const   */* __restrict  */)"\n%d\n%d\n",
                                                 d1, d2);
                                        } else {
                                          goto _L___51;
                                        }
                                      } else {
                                        goto _L___51;
                                      }
                                    } else {
                                      goto _L___51;
                                    }
                                  } else {
                                    goto _L___51;
                                  }
                                } else {
                                  goto _L___51;
                                }
                              } else {
                                goto _L___51;
                              }
                            } else {
                              goto _L___51;
                            }
                          } else {
                            goto _L___51;
                          }
                        } else {
                          {
                          fprintf(_coverage_fout, "111\n");
                          fflush(_coverage_fout);
                          }
                          _L___51: /* CIL Label */ 
                          _L___50: /* CIL Label */ 
                          _L___49: /* CIL Label */ 
                          _L___48: /* CIL Label */ 
                          _L___47: /* CIL Label */ 
                          _L___46: /* CIL Label */ 
                          _L___45: /* CIL Label */ 
                          _L___44: /* CIL Label */ 
                          if (d10 == 0) {
                            {
                            fprintf(_coverage_fout, "112\n");
                            fflush(_coverage_fout);
                            }
                            if (d9 == 0) {
                              {
                              fprintf(_coverage_fout, "113\n");
                              fflush(_coverage_fout);
                              }
                              if (d8 == 0) {
                                {
                                fprintf(_coverage_fout, "114\n");
                                fflush(_coverage_fout);
                                }
                                if (d7 == 0) {
                                  {
                                  fprintf(_coverage_fout, "115\n");
                                  fflush(_coverage_fout);
                                  }
                                  if (d6 == 0) {
                                    {
                                    fprintf(_coverage_fout, "116\n");
                                    fflush(_coverage_fout);
                                    }
                                    if (d5 == 0) {
                                      {
                                      fprintf(_coverage_fout, "117\n");
                                      fflush(_coverage_fout);
                                      }
                                      if (d4 == 0) {
                                        {
                                        fprintf(_coverage_fout, "118\n");
                                        fflush(_coverage_fout);
                                        }
                                        if (d3 == 0) {
                                          {
                                          fprintf(_coverage_fout, "119\n");
                                          fflush(_coverage_fout);
                                          }
                                          if (d2 == 0) {
                                            {
                                            fprintf(_coverage_fout, "120\n");
                                            fflush(_coverage_fout);
                                            }
                                            if (d1 != 0) {
                                              {
                                              fprintf(_coverage_fout, "121\n");
                                              fflush(_coverage_fout);
                                              }
                                              printf((char const   */* __restrict  */)"\n%d\n",
                                                     d1);
                                            } else {
                                              goto _L___43;
                                            }
                                          } else {
                                            goto _L___43;
                                          }
                                        } else {
                                          goto _L___43;
                                        }
                                      } else {
                                        goto _L___43;
                                      }
                                    } else {
                                      goto _L___43;
                                    }
                                  } else {
                                    goto _L___43;
                                  }
                                } else {
                                  goto _L___43;
                                }
                              } else {
                                goto _L___43;
                              }
                            } else {
                              goto _L___43;
                            }
                          } else {
                            {
                            fprintf(_coverage_fout, "131\n");
                            fflush(_coverage_fout);
                            }
                            _L___43: /* CIL Label */ 
                            _L___42: /* CIL Label */ 
                            _L___41: /* CIL Label */ 
                            _L___40: /* CIL Label */ 
                            _L___39: /* CIL Label */ 
                            _L___38: /* CIL Label */ 
                            _L___37: /* CIL Label */ 
                            _L___36: /* CIL Label */ 
                            _L___35: /* CIL Label */ 
                            if (d10 == 0) {
                              {
                              fprintf(_coverage_fout, "132\n");
                              fflush(_coverage_fout);
                              }
                              if (d9 == 0) {
                                {
                                fprintf(_coverage_fout, "133\n");
                                fflush(_coverage_fout);
                                }
                                if (d8 == 0) {
                                  {
                                  fprintf(_coverage_fout, "134\n");
                                  fflush(_coverage_fout);
                                  }
                                  if (d7 == 0) {
                                    {
                                    fprintf(_coverage_fout, "135\n");
                                    fflush(_coverage_fout);
                                    }
                                    if (d6 == 0) {
                                      {
                                      fprintf(_coverage_fout, "136\n");
                                      fflush(_coverage_fout);
                                      }
                                      if (d5 == 0) {
                                        {
                                        fprintf(_coverage_fout, "137\n");
                                        fflush(_coverage_fout);
                                        }
                                        if (d4 == 0) {
                                          {
                                          fprintf(_coverage_fout, "138\n");
                                          fflush(_coverage_fout);
                                          }
                                          if (d3 == 0) {
                                            {
                                            fprintf(_coverage_fout, "139\n");
                                            fflush(_coverage_fout);
                                            }
                                            if (d2 == 0) {
                                              {
                                              fprintf(_coverage_fout, "140\n");
                                              fflush(_coverage_fout);
                                              }
                                              if (d1 == 0) {
                                                {
                                                fprintf(_coverage_fout, "141\n");
                                                fflush(_coverage_fout);
                                                }
                                                printf((char const   */* __restrict  */)"\n0\n");
                                              } else {
                                                {
                                                fprintf(_coverage_fout, "142\n");
                                                fflush(_coverage_fout);
                                                }

                                              }
                                            } else {
                                              {
                                              fprintf(_coverage_fout, "143\n");
                                              fflush(_coverage_fout);
                                              }

                                            }
                                          } else {
                                            {
                                            fprintf(_coverage_fout, "144\n");
                                            fflush(_coverage_fout);
                                            }

                                          }
                                        } else {
                                          {
                                          fprintf(_coverage_fout, "145\n");
                                          fflush(_coverage_fout);
                                          }

                                        }
                                      } else {
                                        {
                                        fprintf(_coverage_fout, "146\n");
                                        fflush(_coverage_fout);
                                        }

                                      }
                                    } else {
                                      {
                                      fprintf(_coverage_fout, "147\n");
                                      fflush(_coverage_fout);
                                      }

                                    }
                                  } else {
                                    {
                                    fprintf(_coverage_fout, "148\n");
                                    fflush(_coverage_fout);
                                    }

                                  }
                                } else {
                                  {
                                  fprintf(_coverage_fout, "149\n");
                                  fflush(_coverage_fout);
                                  }

                                }
                              } else {
                                {
                                fprintf(_coverage_fout, "150\n");
                                fflush(_coverage_fout);
                                }

                              }
                            } else {
                              {
                              fprintf(_coverage_fout, "151\n");
                              fflush(_coverage_fout);
                              }

                            }
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
          fprintf(_coverage_fout, "152\n");
          fflush(_coverage_fout);
          }

        }
      } else {
        {
        fprintf(_coverage_fout, "153\n");
        fflush(_coverage_fout);
        }

      }
    } else {
      goto _L___80;
    }
  } else {
    {
    fprintf(_coverage_fout, "155\n");
    fflush(_coverage_fout);
    }
    _L___80: /* CIL Label */ 
    d1 = absnum % 10;
    {
    fprintf(_coverage_fout, "156\n");
    fflush(_coverage_fout);
    }
    d2 = (absnum % 100) / 10;
    {
    fprintf(_coverage_fout, "157\n");
    fflush(_coverage_fout);
    }
    d3 = (absnum % 1000) / 100;
    {
    fprintf(_coverage_fout, "158\n");
    fflush(_coverage_fout);
    }
    d4 = (absnum % 10000) / 1000;
    {
    fprintf(_coverage_fout, "159\n");
    fflush(_coverage_fout);
    }
    d5 = (absnum % 100000) / 10000;
    {
    fprintf(_coverage_fout, "160\n");
    fflush(_coverage_fout);
    }
    d6 = (absnum % 1000000) / 100000;
    {
    fprintf(_coverage_fout, "161\n");
    fflush(_coverage_fout);
    }
    d7 = (absnum % 10000000) / 1000000;
    {
    fprintf(_coverage_fout, "162\n");
    fflush(_coverage_fout);
    }
    d8 = (absnum % 100000000) / 10000000;
    {
    fprintf(_coverage_fout, "163\n");
    fflush(_coverage_fout);
    }
    d9 = (absnum % 1000000000) / 100000000;
    {
    fprintf(_coverage_fout, "164\n");
    fflush(_coverage_fout);
    }
    d10 = (((((((((num - d1) - d2 * 10) - d3 * 100) - d4 * 1000) - d5 * 10000) - d6 * 100000) - d7 * 1000000) - d8 * 10000000) - d9 * 100000000) / 1000000000;
    {
    fprintf(_coverage_fout, "165\n");
    fflush(_coverage_fout);
    }
    if (d10 == 0) {
      {
      fprintf(_coverage_fout, "166\n");
      fflush(_coverage_fout);
      }
      if (d9 != 0) {
        {
        fprintf(_coverage_fout, "167\n");
        fflush(_coverage_fout);
        }
        printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n-%d\n",
               d1, d2, d3, d4, d5, d6, d7, d8, d9);
      } else {
        goto _L___34;
      }
    } else {
      {
      fprintf(_coverage_fout, "169\n");
      fflush(_coverage_fout);
      }
      _L___34: /* CIL Label */ 
      if (d10 == 0) {
        {
        fprintf(_coverage_fout, "170\n");
        fflush(_coverage_fout);
        }
        if (d9 == 0) {
          {
          fprintf(_coverage_fout, "171\n");
          fflush(_coverage_fout);
          }
          if (d8 != 0) {
            {
            fprintf(_coverage_fout, "172\n");
            fflush(_coverage_fout);
            }
            printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n%d\n%d\n-%d\n",
                   d1, d2, d3, d4, d5, d6, d7, d8);
          } else {
            goto _L___33;
          }
        } else {
          goto _L___33;
        }
      } else {
        {
        fprintf(_coverage_fout, "175\n");
        fflush(_coverage_fout);
        }
        _L___33: /* CIL Label */ 
        _L___32: /* CIL Label */ 
        if (d10 == 0) {
          {
          fprintf(_coverage_fout, "176\n");
          fflush(_coverage_fout);
          }
          if (d9 == 0) {
            {
            fprintf(_coverage_fout, "177\n");
            fflush(_coverage_fout);
            }
            if (d8 == 0) {
              {
              fprintf(_coverage_fout, "178\n");
              fflush(_coverage_fout);
              }
              if (d7 != 0) {
                {
                fprintf(_coverage_fout, "179\n");
                fflush(_coverage_fout);
                }
                printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n%d\n-%d\n",
                       d1, d2, d3, d4, d5, d6, d7);
              } else {
                goto _L___31;
              }
            } else {
              goto _L___31;
            }
          } else {
            goto _L___31;
          }
        } else {
          {
          fprintf(_coverage_fout, "183\n");
          fflush(_coverage_fout);
          }
          _L___31: /* CIL Label */ 
          _L___30: /* CIL Label */ 
          _L___29: /* CIL Label */ 
          if (d10 == 0) {
            {
            fprintf(_coverage_fout, "184\n");
            fflush(_coverage_fout);
            }
            if (d9 == 0) {
              {
              fprintf(_coverage_fout, "185\n");
              fflush(_coverage_fout);
              }
              if (d8 == 0) {
                {
                fprintf(_coverage_fout, "186\n");
                fflush(_coverage_fout);
                }
                if (d7 == 0) {
                  {
                  fprintf(_coverage_fout, "187\n");
                  fflush(_coverage_fout);
                  }
                  if (d6 != 0) {
                    {
                    fprintf(_coverage_fout, "188\n");
                    fflush(_coverage_fout);
                    }
                    printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n%d\n-%d\n",
                           d1, d2, d3, d4, d5, d6);
                  } else {
                    goto _L___28;
                  }
                } else {
                  goto _L___28;
                }
              } else {
                goto _L___28;
              }
            } else {
              goto _L___28;
            }
          } else {
            {
            fprintf(_coverage_fout, "193\n");
            fflush(_coverage_fout);
            }
            _L___28: /* CIL Label */ 
            _L___27: /* CIL Label */ 
            _L___26: /* CIL Label */ 
            _L___25: /* CIL Label */ 
            if (d10 == 0) {
              {
              fprintf(_coverage_fout, "194\n");
              fflush(_coverage_fout);
              }
              if (d9 == 0) {
                {
                fprintf(_coverage_fout, "195\n");
                fflush(_coverage_fout);
                }
                if (d8 == 0) {
                  {
                  fprintf(_coverage_fout, "196\n");
                  fflush(_coverage_fout);
                  }
                  if (d7 == 0) {
                    {
                    fprintf(_coverage_fout, "197\n");
                    fflush(_coverage_fout);
                    }
                    if (d6 == 0) {
                      {
                      fprintf(_coverage_fout, "198\n");
                      fflush(_coverage_fout);
                      }
                      if (d5 != 0) {
                        {
                        fprintf(_coverage_fout, "199\n");
                        fflush(_coverage_fout);
                        }
                        printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n%d\n-%d\n",
                               d1, d2, d3, d4, d5);
                      } else {
                        goto _L___24;
                      }
                    } else {
                      goto _L___24;
                    }
                  } else {
                    goto _L___24;
                  }
                } else {
                  goto _L___24;
                }
              } else {
                goto _L___24;
              }
            } else {
              {
              fprintf(_coverage_fout, "205\n");
              fflush(_coverage_fout);
              }
              _L___24: /* CIL Label */ 
              _L___23: /* CIL Label */ 
              _L___22: /* CIL Label */ 
              _L___21: /* CIL Label */ 
              _L___20: /* CIL Label */ 
              if (d10 == 0) {
                {
                fprintf(_coverage_fout, "206\n");
                fflush(_coverage_fout);
                }
                if (d9 == 0) {
                  {
                  fprintf(_coverage_fout, "207\n");
                  fflush(_coverage_fout);
                  }
                  if (d8 == 0) {
                    {
                    fprintf(_coverage_fout, "208\n");
                    fflush(_coverage_fout);
                    }
                    if (d7 == 0) {
                      {
                      fprintf(_coverage_fout, "209\n");
                      fflush(_coverage_fout);
                      }
                      if (d6 == 0) {
                        {
                        fprintf(_coverage_fout, "210\n");
                        fflush(_coverage_fout);
                        }
                        if (d5 == 0) {
                          {
                          fprintf(_coverage_fout, "211\n");
                          fflush(_coverage_fout);
                          }
                          if (d4 != 0) {
                            {
                            fprintf(_coverage_fout, "212\n");
                            fflush(_coverage_fout);
                            }
                            printf((char const   */* __restrict  */)"\n%d\n%d\n%d\n-%d\n",
                                   d1, d2, d3, d4);
                          } else {
                            goto _L___19;
                          }
                        } else {
                          goto _L___19;
                        }
                      } else {
                        goto _L___19;
                      }
                    } else {
                      goto _L___19;
                    }
                  } else {
                    goto _L___19;
                  }
                } else {
                  goto _L___19;
                }
              } else {
                {
                fprintf(_coverage_fout, "219\n");
                fflush(_coverage_fout);
                }
                _L___19: /* CIL Label */ 
                _L___18: /* CIL Label */ 
                _L___17: /* CIL Label */ 
                _L___16: /* CIL Label */ 
                _L___15: /* CIL Label */ 
                _L___14: /* CIL Label */ 
                if (d10 == 0) {
                  {
                  fprintf(_coverage_fout, "220\n");
                  fflush(_coverage_fout);
                  }
                  if (d9 == 0) {
                    {
                    fprintf(_coverage_fout, "221\n");
                    fflush(_coverage_fout);
                    }
                    if (d8 == 0) {
                      {
                      fprintf(_coverage_fout, "222\n");
                      fflush(_coverage_fout);
                      }
                      if (d7 == 0) {
                        {
                        fprintf(_coverage_fout, "223\n");
                        fflush(_coverage_fout);
                        }
                        if (d6 == 0) {
                          {
                          fprintf(_coverage_fout, "224\n");
                          fflush(_coverage_fout);
                          }
                          if (d5 == 0) {
                            {
                            fprintf(_coverage_fout, "225\n");
                            fflush(_coverage_fout);
                            }
                            if (d4 == 0) {
                              {
                              fprintf(_coverage_fout, "226\n");
                              fflush(_coverage_fout);
                              }
                              if (d3 != 0) {
                                {
                                fprintf(_coverage_fout, "227\n");
                                fflush(_coverage_fout);
                                }
                                printf((char const   */* __restrict  */)"\n%d\n%d\n-%d\n",
                                       d1, d2, d3);
                              } else {
                                goto _L___13;
                              }
                            } else {
                              goto _L___13;
                            }
                          } else {
                            goto _L___13;
                          }
                        } else {
                          goto _L___13;
                        }
                      } else {
                        goto _L___13;
                      }
                    } else {
                      goto _L___13;
                    }
                  } else {
                    goto _L___13;
                  }
                } else {
                  {
                  fprintf(_coverage_fout, "235\n");
                  fflush(_coverage_fout);
                  }
                  _L___13: /* CIL Label */ 
                  _L___12: /* CIL Label */ 
                  _L___11: /* CIL Label */ 
                  _L___10: /* CIL Label */ 
                  _L___9: /* CIL Label */ 
                  _L___8: /* CIL Label */ 
                  _L___7: /* CIL Label */ 
                  if (d10 == 0) {
                    {
                    fprintf(_coverage_fout, "236\n");
                    fflush(_coverage_fout);
                    }
                    if (d9 == 0) {
                      {
                      fprintf(_coverage_fout, "237\n");
                      fflush(_coverage_fout);
                      }
                      if (d8 == 0) {
                        {
                        fprintf(_coverage_fout, "238\n");
                        fflush(_coverage_fout);
                        }
                        if (d7 == 0) {
                          {
                          fprintf(_coverage_fout, "239\n");
                          fflush(_coverage_fout);
                          }
                          if (d6 == 0) {
                            {
                            fprintf(_coverage_fout, "240\n");
                            fflush(_coverage_fout);
                            }
                            if (d5 == 0) {
                              {
                              fprintf(_coverage_fout, "241\n");
                              fflush(_coverage_fout);
                              }
                              if (d4 == 0) {
                                {
                                fprintf(_coverage_fout, "242\n");
                                fflush(_coverage_fout);
                                }
                                if (d3 == 0) {
                                  {
                                  fprintf(_coverage_fout, "243\n");
                                  fflush(_coverage_fout);
                                  }
                                  if (d2 != 0) {
                                    {
                                    fprintf(_coverage_fout, "244\n");
                                    fflush(_coverage_fout);
                                    }
                                    printf((char const   */* __restrict  */)"\n%d\n-%d\n",
                                           d1, d2);
                                  } else {
                                    goto _L___6;
                                  }
                                } else {
                                  goto _L___6;
                                }
                              } else {
                                goto _L___6;
                              }
                            } else {
                              goto _L___6;
                            }
                          } else {
                            goto _L___6;
                          }
                        } else {
                          goto _L___6;
                        }
                      } else {
                        goto _L___6;
                      }
                    } else {
                      goto _L___6;
                    }
                  } else {
                    {
                    fprintf(_coverage_fout, "253\n");
                    fflush(_coverage_fout);
                    }
                    _L___6: /* CIL Label */ 
                    _L___5: /* CIL Label */ 
                    _L___4: /* CIL Label */ 
                    _L___3: /* CIL Label */ 
                    _L___2: /* CIL Label */ 
                    _L___1: /* CIL Label */ 
                    _L___0: /* CIL Label */ 
                    _L: /* CIL Label */ 
                    if (d10 == 0) {
                      {
                      fprintf(_coverage_fout, "254\n");
                      fflush(_coverage_fout);
                      }
                      if (d9 == 0) {
                        {
                        fprintf(_coverage_fout, "255\n");
                        fflush(_coverage_fout);
                        }
                        if (d8 == 0) {
                          {
                          fprintf(_coverage_fout, "256\n");
                          fflush(_coverage_fout);
                          }
                          if (d7 == 0) {
                            {
                            fprintf(_coverage_fout, "257\n");
                            fflush(_coverage_fout);
                            }
                            if (d6 == 0) {
                              {
                              fprintf(_coverage_fout, "258\n");
                              fflush(_coverage_fout);
                              }
                              if (d5 == 0) {
                                {
                                fprintf(_coverage_fout, "259\n");
                                fflush(_coverage_fout);
                                }
                                if (d4 == 0) {
                                  {
                                  fprintf(_coverage_fout, "260\n");
                                  fflush(_coverage_fout);
                                  }
                                  if (d3 == 0) {
                                    {
                                    fprintf(_coverage_fout, "261\n");
                                    fflush(_coverage_fout);
                                    }
                                    if (d2 == 0) {
                                      {
                                      fprintf(_coverage_fout, "262\n");
                                      fflush(_coverage_fout);
                                      }
                                      if (d1 != 0) {
                                        {
                                        fprintf(_coverage_fout, "263\n");
                                        fflush(_coverage_fout);
                                        }
                                        printf((char const   */* __restrict  */)"\n-%d\n",
                                               d1);
                                      } else {
                                        {
                                        fprintf(_coverage_fout, "264\n");
                                        fflush(_coverage_fout);
                                        }

                                      }
                                    } else {
                                      {
                                      fprintf(_coverage_fout, "265\n");
                                      fflush(_coverage_fout);
                                      }

                                    }
                                  } else {
                                    {
                                    fprintf(_coverage_fout, "266\n");
                                    fflush(_coverage_fout);
                                    }

                                  }
                                } else {
                                  {
                                  fprintf(_coverage_fout, "267\n");
                                  fflush(_coverage_fout);
                                  }

                                }
                              } else {
                                {
                                fprintf(_coverage_fout, "268\n");
                                fflush(_coverage_fout);
                                }

                              }
                            } else {
                              {
                              fprintf(_coverage_fout, "269\n");
                              fflush(_coverage_fout);
                              }

                            }
                          } else {
                            {
                            fprintf(_coverage_fout, "270\n");
                            fflush(_coverage_fout);
                            }

                          }
                        } else {
                          {
                          fprintf(_coverage_fout, "271\n");
                          fflush(_coverage_fout);
                          }

                        }
                      } else {
                        {
                        fprintf(_coverage_fout, "272\n");
                        fflush(_coverage_fout);
                        }

                      }
                    } else {
                      {
                      fprintf(_coverage_fout, "273\n");
                      fflush(_coverage_fout);
                      }

                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  {
  fprintf(_coverage_fout, "274\n");
  fflush(_coverage_fout);
  }
  if (floatnum >= (double )10000000000L) {
    {
    fprintf(_coverage_fout, "275\n");
    fflush(_coverage_fout);
    }
    printf((char const   */* __restrict  */)"\n7\n4\n6\n3\n8\n4\n7\n4\n1\n2\n");
  } else {
    {
    fprintf(_coverage_fout, "276\n");
    fflush(_coverage_fout);
    }

  }
  {
  fprintf(_coverage_fout, "277\n");
  fflush(_coverage_fout);
  }
  printf((char const   */* __restrict  */)"That\'s all, have a nice day!\n");
  {
  fprintf(_coverage_fout, "278\n");
  fflush(_coverage_fout);
  }
  return (0);
}
}
