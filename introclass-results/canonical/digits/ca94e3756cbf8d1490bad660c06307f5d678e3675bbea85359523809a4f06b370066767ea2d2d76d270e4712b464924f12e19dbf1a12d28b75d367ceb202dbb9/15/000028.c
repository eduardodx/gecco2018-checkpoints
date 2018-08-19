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
struct _IO_FILE;
struct _IO_FILE;
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
struct _IO_jump_t;
struct _IO_FILE;
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
typedef int wchar_t;
enum __anonenum_idtype_t_6 {
    P_ALL = 0,
    P_PID = 1,
    P_PGID = 2
} ;
typedef enum __anonenum_idtype_t_6 idtype_t;
struct __anonstruct___wait_terminated_7 {
   unsigned int __w_termsig : 7 ;
   unsigned int __w_coredump : 1 ;
   unsigned int __w_retcode : 8 ;
   unsigned int  : 16 ;
};
struct __anonstruct___wait_stopped_8 {
   unsigned int __w_stopval : 8 ;
   unsigned int __w_stopsig : 8 ;
   unsigned int  : 16 ;
};
union wait {
   int w_status ;
   struct __anonstruct___wait_terminated_7 __wait_terminated ;
   struct __anonstruct___wait_stopped_8 __wait_stopped ;
};
union __anonunion___WAIT_STATUS_9 {
   union wait *__uptr ;
   int *__iptr ;
};
typedef union __anonunion___WAIT_STATUS_9  __attribute__((__transparent_union__)) __WAIT_STATUS;
struct __anonstruct_div_t_10 {
   int quot ;
   int rem ;
};
typedef struct __anonstruct_div_t_10 div_t;
struct __anonstruct_ldiv_t_11 {
   long quot ;
   long rem ;
};
typedef struct __anonstruct_ldiv_t_11 ldiv_t;
struct __anonstruct_lldiv_t_12 {
   long long quot ;
   long long rem ;
};
typedef struct __anonstruct_lldiv_t_12 lldiv_t;
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
struct __anonstruct___sigset_t_13 {
   unsigned long __val[1024UL / (8UL * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___sigset_t_13 __sigset_t;
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
struct __anonstruct_fd_set_14 {
   __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef struct __anonstruct_fd_set_14 fd_set;
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
union __anonunion_pthread_mutex_t_15 {
   struct __pthread_mutex_s __data ;
   char __size[40] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_15 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_16 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_mutexattr_t_16 pthread_mutexattr_t;
struct __anonstruct___data_18 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_17 {
   struct __anonstruct___data_18 __data ;
   char __size[48] ;
   long long __align ;
};
typedef union __anonunion_pthread_cond_t_17 pthread_cond_t;
union __anonunion_pthread_condattr_t_19 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_condattr_t_19 pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
struct __anonstruct___data_21 {
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
union __anonunion_pthread_rwlock_t_20 {
   struct __anonstruct___data_21 __data ;
   char __size[56] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlock_t_20 pthread_rwlock_t;
union __anonunion_pthread_rwlockattr_t_22 {
   char __size[8] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlockattr_t_22 pthread_rwlockattr_t;
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_23 {
   char __size[32] ;
   long __align ;
};
typedef union __anonunion_pthread_barrier_t_23 pthread_barrier_t;
union __anonunion_pthread_barrierattr_t_24 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_barrierattr_t_24 pthread_barrierattr_t;
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
__inline static unsigned int __bswap_32(unsigned int __bsx ) 
{ 
  int tmp ;

  {
  tmp = __builtin_bswap32((int )__bsx);
  return ((unsigned int )tmp);
}
}
__inline static __uint64_t __bswap_64(__uint64_t __bsx ) 
{ 
  long tmp ;

  {
  tmp = __builtin_bswap64((long )__bsx);
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
  int x ;
  int y ;
  int temp ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
  printf((char const   */* __restrict  */)"\nEnter an integer > ");
  scanf((char const   */* __restrict  */)"%d", & y);
  while (1) {
    x = y % 10;
    tmp___2 = abs(y);
    if (tmp___2 > 10) {
      tmp = abs(x);
      printf((char const   */* __restrict  */)"\n%d", tmp);
    } else {
      tmp___0 = abs(y);
      y = temp;
    }
    x = y / 10;
    temp = x;
    x = y;
    if (tmp___0 >= 0) {
      tmp___1 = abs(y);
      if (tmp___1 < 10) {
        printf((char const   */* __restrict  */)"\n%d", x);
        printf((char const   */* __restrict  */)"\nThat\'s all, have a nice day!\n");
        return (0);
      } else {

      }
    } else {

    }
  }
  return (0);
}
}
