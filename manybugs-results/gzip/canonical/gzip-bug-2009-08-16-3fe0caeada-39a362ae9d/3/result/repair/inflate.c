typedef unsigned int size_t;
typedef long wchar_t;
struct __anonstruct___wait_terminated_1 {
   unsigned int __w_termsig : 7 ;
   unsigned int __w_coredump : 1 ;
   unsigned int __w_retcode : 8 ;
   unsigned int  : 16 ;
};
struct __anonstruct___wait_stopped_2 {
   unsigned int __w_stopval : 8 ;
   unsigned int __w_stopsig : 8 ;
   unsigned int  : 16 ;
};
union wait {
   int w_status ;
   struct __anonstruct___wait_terminated_1 __wait_terminated ;
   struct __anonstruct___wait_stopped_2 __wait_stopped ;
};
union __anonunion___WAIT_STATUS_3 {
   union wait *__uptr ;
   int *__iptr ;
};
typedef union __anonunion___WAIT_STATUS_3  __attribute__((__transparent_union__)) __WAIT_STATUS;
struct __anonstruct_div_t_4 {
   int quot ;
   int rem ;
};
typedef struct __anonstruct_div_t_4 div_t;
struct __anonstruct_ldiv_t_5 {
   long quot ;
   long rem ;
};
typedef struct __anonstruct_ldiv_t_5 ldiv_t;
struct __anonstruct_lldiv_t_6 {
   long long quot ;
   long long rem ;
};
typedef struct __anonstruct_lldiv_t_6 lldiv_t;
struct __locale_data;
struct __locale_struct {
   struct __locale_data *__locales[13] ;
   unsigned short const   *__ctype_b ;
   int const   *__ctype_tolower ;
   int const   *__ctype_toupper ;
   char const   *__names[13] ;
};
typedef struct __locale_struct *__locale_t;
typedef __locale_t locale_t;
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
typedef long long __int64_t;
typedef unsigned long long __uint64_t;
typedef long long __quad_t;
typedef unsigned long long __u_quad_t;
typedef __u_quad_t __dev_t;
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef __u_quad_t __ino64_t;
typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long __off_t;
typedef __quad_t __off64_t;
typedef int __pid_t;
struct __anonstruct___fsid_t_7 {
   int __val[2] ;
};
typedef struct __anonstruct___fsid_t_7 __fsid_t;
typedef long __clock_t;
typedef unsigned long __rlim_t;
typedef __u_quad_t __rlim64_t;
typedef unsigned int __id_t;
typedef long __time_t;
typedef unsigned int __useconds_t;
typedef long __suseconds_t;
typedef int __daddr_t;
typedef long __swblk_t;
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef __quad_t __blkcnt64_t;
typedef unsigned long __fsblkcnt_t;
typedef __u_quad_t __fsblkcnt64_t;
typedef unsigned long __fsfilcnt_t;
typedef __u_quad_t __fsfilcnt64_t;
typedef int __ssize_t;
typedef __off64_t __loff_t;
typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;
typedef int __intptr_t;
typedef unsigned int __socklen_t;
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __quad_t quad_t;
typedef __u_quad_t u_quad_t;
typedef __fsid_t fsid_t;
typedef __loff_t loff_t;
typedef __ino64_t ino_t;
typedef __ino64_t ino64_t;
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off64_t off_t;
typedef __off64_t off64_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
typedef __ssize_t ssize_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
typedef __clock_t clock_t;
typedef __time_t time_t;
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
typedef __useconds_t useconds_t;
typedef __suseconds_t suseconds_t;
typedef unsigned long ulong;
typedef unsigned short ushort;
typedef unsigned int uint;
typedef signed char int8_t;
typedef short int16_t;
typedef int int32_t;
typedef long long int64_t;
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;
typedef int register_t;
typedef int __sig_atomic_t;
struct __anonstruct___sigset_t_8 {
   unsigned long __val[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___sigset_t_8 __sigset_t;
typedef __sigset_t sigset_t;
struct timespec {
   __time_t tv_sec ;
   long tv_nsec ;
};
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
typedef long __fd_mask;
struct __anonstruct_fd_set_9 {
   __fd_mask fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef struct __anonstruct_fd_set_9 fd_set;
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef __blkcnt64_t blkcnt_t;
typedef __fsblkcnt64_t fsblkcnt_t;
typedef __fsfilcnt64_t fsfilcnt_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef unsigned long pthread_t;
union __anonunion_pthread_attr_t_10 {
   char __size[36] ;
   long __align ;
};
typedef union __anonunion_pthread_attr_t_10 pthread_attr_t;
struct __pthread_internal_slist {
   struct __pthread_internal_slist *__next ;
};
typedef struct __pthread_internal_slist __pthread_slist_t;
union __anonunion____missing_field_name_12 {
   int __spins ;
   __pthread_slist_t __list ;
};
struct __pthread_mutex_s {
   int __lock ;
   unsigned int __count ;
   int __owner ;
   int __kind ;
   unsigned int __nusers ;
   union __anonunion____missing_field_name_12 __annonCompField1 ;
};
union __anonunion_pthread_mutex_t_11 {
   struct __pthread_mutex_s __data ;
   char __size[24] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_11 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_13 {
   char __size[4] ;
   long __align ;
};
typedef union __anonunion_pthread_mutexattr_t_13 pthread_mutexattr_t;
struct __anonstruct___data_15 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_14 {
   struct __anonstruct___data_15 __data ;
   char __size[48] ;
   long long __align ;
};
typedef union __anonunion_pthread_cond_t_14 pthread_cond_t;
union __anonunion_pthread_condattr_t_16 {
   char __size[4] ;
   long __align ;
};
typedef union __anonunion_pthread_condattr_t_16 pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
struct __anonstruct___data_18 {
   int __lock ;
   unsigned int __nr_readers ;
   unsigned int __readers_wakeup ;
   unsigned int __writer_wakeup ;
   unsigned int __nr_readers_queued ;
   unsigned int __nr_writers_queued ;
   unsigned char __flags ;
   unsigned char __shared ;
   unsigned char __pad1 ;
   unsigned char __pad2 ;
   int __writer ;
};
union __anonunion_pthread_rwlock_t_17 {
   struct __anonstruct___data_18 __data ;
   char __size[32] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlock_t_17 pthread_rwlock_t;
union __anonunion_pthread_rwlockattr_t_19 {
   char __size[8] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlockattr_t_19 pthread_rwlockattr_t;
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_20 {
   char __size[20] ;
   long __align ;
};
typedef union __anonunion_pthread_barrier_t_20 pthread_barrier_t;
union __anonunion_pthread_barrierattr_t_21 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_barrierattr_t_21 pthread_barrierattr_t;
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
typedef int (*comparison_fn_t)(void const   * , void const   * );
typedef int (*__compar_d_fn_t)(void const   * , void const   * , void * );
typedef void *voidp;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef struct _IO_FILE __FILE;
union __anonunion___value_23 {
   unsigned int __wch ;
   char __wchb[4] ;
};
struct __anonstruct___mbstate_t_22 {
   int __count ;
   union __anonunion___value_23 __value ;
};
typedef struct __anonstruct___mbstate_t_22 __mbstate_t;
struct __anonstruct__G_fpos_t_24 {
   __off_t __pos ;
   __mbstate_t __state ;
};
typedef struct __anonstruct__G_fpos_t_24 _G_fpos_t;
struct __anonstruct__G_fpos64_t_25 {
   __off64_t __pos ;
   __mbstate_t __state ;
};
typedef struct __anonstruct__G_fpos64_t_25 _G_fpos64_t;
typedef short _G_int16_t;
typedef int _G_int32_t;
typedef unsigned short _G_uint16_t;
typedef unsigned int _G_uint32_t;
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
   char _unused2[(15U * sizeof(int ) - 4U * sizeof(void *)) - sizeof(size_t )] ;
};
typedef struct _IO_FILE _IO_FILE;
struct _IO_FILE_plus;
struct _IO_FILE_plus;
typedef __ssize_t __io_read_fn(void *__cookie , char *__buf , size_t __nbytes );
typedef __ssize_t __io_write_fn(void *__cookie , char const   *__buf ,
                                size_t __n );
typedef int __io_seek_fn(void *__cookie , __off64_t *__pos , int __w );
typedef int __io_close_fn(void *__cookie );
typedef __io_read_fn cookie_read_function_t;
typedef __io_write_fn cookie_write_function_t;
typedef __io_seek_fn cookie_seek_function_t;
typedef __io_close_fn cookie_close_function_t;
struct __anonstruct__IO_cookie_io_functions_t_26 {
   __io_read_fn *read ;
   __io_write_fn *write ;
   __io_seek_fn *seek ;
   __io_close_fn *close ;
};
typedef struct __anonstruct__IO_cookie_io_functions_t_26 _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;
struct _IO_cookie_file;
struct _IO_cookie_file;
typedef __gnuc_va_list va_list;
typedef _G_fpos64_t fpos_t;
typedef _G_fpos64_t fpos64_t;
struct obstack;
struct obstack;
typedef int ptrdiff_t;
struct tm {
   int tm_sec ;
   int tm_min ;
   int tm_hour ;
   int tm_mday ;
   int tm_mon ;
   int tm_year ;
   int tm_wday ;
   int tm_yday ;
   int tm_isdst ;
   long tm_gmtoff ;
   char const   *tm_zone ;
};
struct itimerspec {
   struct timespec it_interval ;
   struct timespec it_value ;
};
struct sigevent;
struct sigevent;
struct __time_t_must_be_integral {
   unsigned int __floating_time_t_unsupported : 1 ;
};
typedef unsigned char uch;
typedef unsigned short ush;
typedef unsigned long ulg;
typedef int file_t;
union __anonunion_v_27 {
   ush n ;
   struct huft *t ;
};
struct huft {
   uch e ;
   uch b ;
   union __anonunion_v_27 v ;
};
extern  __attribute__((__nothrow__)) size_t __ctype_get_mb_cur_max(void) ;
__inline extern  __attribute__((__nothrow__)) double __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atof)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atoi)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern  __attribute__((__nothrow__)) long __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atol)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern  __attribute__((__nothrow__)) long long __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atoll)(char const   *__nptr )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1))) strtod)(char const   * __restrict  __nptr ,
                                                                                      char ** __restrict  __endptr ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__nonnull__(1))) strtof)(char const   * __restrict  __nptr ,
                                                                                     char ** __restrict  __endptr ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__nonnull__(1))) strtold)(char const   * __restrict  __nptr ,
                                                                                            char ** __restrict  __endptr ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) strtol)(char const   * __restrict  __nptr ,
                                                                                    char ** __restrict  __endptr ,
                                                                                    int __base ) ;
extern  __attribute__((__nothrow__)) unsigned long ( __attribute__((__nonnull__(1))) strtoul)(char const   * __restrict  __nptr ,
                                                                                              char ** __restrict  __endptr ,
                                                                                              int __base ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__nonnull__(1))) strtoq)(char const   * __restrict  __nptr ,
                                                                                         char ** __restrict  __endptr ,
                                                                                         int __base ) ;
extern  __attribute__((__nothrow__)) unsigned long long ( __attribute__((__nonnull__(1))) strtouq)(char const   * __restrict  __nptr ,
                                                                                                   char ** __restrict  __endptr ,
                                                                                                   int __base ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__nonnull__(1))) strtoll)(char const   * __restrict  __nptr ,
                                                                                          char ** __restrict  __endptr ,
                                                                                          int __base ) ;
extern  __attribute__((__nothrow__)) unsigned long long ( __attribute__((__nonnull__(1))) strtoull)(char const   * __restrict  __nptr ,
                                                                                                    char ** __restrict  __endptr ,
                                                                                                    int __base ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1,4))) strtol_l)(char const   * __restrict  __nptr ,
                                                                                        char ** __restrict  __endptr ,
                                                                                        int __base ,
                                                                                        __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) unsigned long ( __attribute__((__nonnull__(1,4))) strtoul_l)(char const   * __restrict  __nptr ,
                                                                                                  char ** __restrict  __endptr ,
                                                                                                  int __base ,
                                                                                                  __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) long long ( __attribute__((__nonnull__(1,4))) strtoll_l)(char const   * __restrict  __nptr ,
                                                                                              char ** __restrict  __endptr ,
                                                                                              int __base ,
                                                                                              __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) unsigned long long ( __attribute__((__nonnull__(1,4))) strtoull_l)(char const   * __restrict  __nptr ,
                                                                                                        char ** __restrict  __endptr ,
                                                                                                        int __base ,
                                                                                                        __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1,3))) strtod_l)(char const   * __restrict  __nptr ,
                                                                                          char ** __restrict  __endptr ,
                                                                                          __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) float ( __attribute__((__nonnull__(1,3))) strtof_l)(char const   * __restrict  __nptr ,
                                                                                         char ** __restrict  __endptr ,
                                                                                         __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) long double ( __attribute__((__nonnull__(1,3))) strtold_l)(char const   * __restrict  __nptr ,
                                                                                                char ** __restrict  __endptr ,
                                                                                                __locale_t __loc ) ;
__inline extern  __attribute__((__nothrow__)) double __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atof)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern double __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atof)(char const   *__nptr ) 
{ 
  double tmp ;

  {
  tmp = strtod((char const   */* __restrict  */)__nptr,
               (char **/* __restrict  */)((char **)((void *)0)));
  return ((double __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atoi)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atoi)(char const   *__nptr ) 
{ 
  long tmp ;

  {
  tmp = strtol((char const   */* __restrict  */)__nptr,
               (char **/* __restrict  */)((char **)((void *)0)), 10);
  return ((int __attribute__((__gnu_inline__))  )((int )tmp));
}
}
__inline extern  __attribute__((__nothrow__)) long __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atol)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern long __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atol)(char const   *__nptr ) 
{ 
  long tmp ;

  {
  tmp = strtol((char const   */* __restrict  */)__nptr,
               (char **/* __restrict  */)((char **)((void *)0)), 10);
  return ((long __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) long long __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atoll)(char const   *__nptr )  __attribute__((__pure__)) ;
__inline extern long long __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) atoll)(char const   *__nptr ) 
{ 
  long long tmp ;

  {
  tmp = strtoll((char const   */* __restrict  */)__nptr,
                (char **/* __restrict  */)((char **)((void *)0)), 10);
  return ((long long __attribute__((__gnu_inline__))  )tmp);
}
}
extern  __attribute__((__nothrow__)) char *l64a(long __n ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) a64l)(char const   *__s )  __attribute__((__pure__)) ;
extern int select(int __nfds , fd_set * __restrict  __readfds ,
                  fd_set * __restrict  __writefds ,
                  fd_set * __restrict  __exceptfds ,
                  struct timeval * __restrict  __timeout ) ;
extern int pselect(int __nfds , fd_set * __restrict  __readfds ,
                   fd_set * __restrict  __writefds ,
                   fd_set * __restrict  __exceptfds ,
                   struct timespec  const  * __restrict  __timeout ,
                   __sigset_t const   * __restrict  __sigmask ) ;
__inline extern  __attribute__((__nothrow__)) unsigned int __attribute__((__gnu_inline__))  gnu_dev_major(unsigned long long __dev ) ;
__inline extern  __attribute__((__nothrow__)) unsigned int __attribute__((__gnu_inline__))  gnu_dev_minor(unsigned long long __dev ) ;
__inline extern  __attribute__((__nothrow__)) unsigned long long __attribute__((__gnu_inline__))  gnu_dev_makedev(unsigned int __major ,
                                                                                                                  unsigned int __minor ) ;
__inline extern  __attribute__((__nothrow__)) unsigned int __attribute__((__gnu_inline__))  gnu_dev_major(unsigned long long __dev ) ;
__inline extern unsigned int __attribute__((__gnu_inline__))  gnu_dev_major(unsigned long long __dev ) 
{ 


  {
  return ((unsigned int __attribute__((__gnu_inline__))  )(((__dev >> 8) & 4095ULL) | (unsigned long long )((unsigned int )(__dev >> 32) & 4294963200U)));
}
}
__inline extern  __attribute__((__nothrow__)) unsigned int __attribute__((__gnu_inline__))  gnu_dev_minor(unsigned long long __dev ) ;
__inline extern unsigned int __attribute__((__gnu_inline__))  gnu_dev_minor(unsigned long long __dev ) 
{ 


  {
  return ((unsigned int __attribute__((__gnu_inline__))  )((__dev & 255ULL) | (unsigned long long )((unsigned int )(__dev >> 12) & 4294967040U)));
}
}
__inline extern  __attribute__((__nothrow__)) unsigned long long __attribute__((__gnu_inline__))  gnu_dev_makedev(unsigned int __major ,
                                                                                                                  unsigned int __minor ) ;
__inline extern unsigned long long __attribute__((__gnu_inline__))  gnu_dev_makedev(unsigned int __major ,
                                                                                    unsigned int __minor ) 
{ 


  {
  return ((unsigned long long __attribute__((__gnu_inline__))  )(((unsigned long long )((__minor & 255U) | ((__major & 4095U) << 8)) | ((unsigned long long )(__minor & 4294967040U) << 12)) | ((unsigned long long )(__major & 4294963200U) << 32)));
}
}
extern  __attribute__((__nothrow__)) long random(void) ;
extern  __attribute__((__nothrow__)) void srandom(unsigned int __seed ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2))) initstate)(unsigned int __seed ,
                                                                                        char *__statebuf ,
                                                                                        size_t __statelen ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) setstate)(char *__statebuf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) random_r)(struct random_data * __restrict  __buf ,
                                                                                       int32_t * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) srandom_r)(unsigned int __seed ,
                                                                                      struct random_data *__buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,4))) initstate_r)(unsigned int __seed ,
                                                                                          char * __restrict  __statebuf ,
                                                                                          size_t __statelen ,
                                                                                          struct random_data * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) setstate_r)(char * __restrict  __statebuf ,
                                                                                         struct random_data * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int rand(void) ;
extern  __attribute__((__nothrow__)) void srand(unsigned int __seed ) ;
extern  __attribute__((__nothrow__)) int rand_r(unsigned int *__seed ) ;
extern  __attribute__((__nothrow__)) double drand48(void) ;
extern  __attribute__((__nothrow__)) double ( __attribute__((__nonnull__(1))) erand48)(unsigned short *__xsubi ) ;
extern  __attribute__((__nothrow__)) long lrand48(void) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) nrand48)(unsigned short *__xsubi ) ;
extern  __attribute__((__nothrow__)) long mrand48(void) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) jrand48)(unsigned short *__xsubi ) ;
extern  __attribute__((__nothrow__)) void srand48(long __seedval ) ;
extern  __attribute__((__nothrow__)) unsigned short *( __attribute__((__nonnull__(1))) seed48)(unsigned short *__seed16v ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1))) lcong48)(unsigned short *__param ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) drand48_r)(struct drand48_data * __restrict  __buffer ,
                                                                                        double * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) erand48_r)(unsigned short *__xsubi ,
                                                                                        struct drand48_data * __restrict  __buffer ,
                                                                                        double * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) lrand48_r)(struct drand48_data * __restrict  __buffer ,
                                                                                        long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) nrand48_r)(unsigned short *__xsubi ,
                                                                                        struct drand48_data * __restrict  __buffer ,
                                                                                        long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) mrand48_r)(struct drand48_data * __restrict  __buffer ,
                                                                                        long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) jrand48_r)(unsigned short *__xsubi ,
                                                                                        struct drand48_data * __restrict  __buffer ,
                                                                                        long * __restrict  __result ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) srand48_r)(long __seedval ,
                                                                                      struct drand48_data *__buffer ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) seed48_r)(unsigned short *__seed16v ,
                                                                                       struct drand48_data *__buffer ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) lcong48_r)(unsigned short *__param ,
                                                                                        struct drand48_data *__buffer ) ;
extern  __attribute__((__nothrow__)) void *malloc(size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *calloc(size_t __nmemb ,
                                                  size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__warn_unused_result__)) realloc)(void *__ptr ,
                                                                                              size_t __size ) ;
extern  __attribute__((__nothrow__)) void free(void *__ptr ) ;
extern  __attribute__((__nothrow__)) void cfree(void *__ptr ) ;
extern  __attribute__((__nothrow__)) void *alloca(size_t __size ) ;
extern  __attribute__((__nothrow__)) void *valloc(size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) posix_memalign)(void **__memptr ,
                                                                                           size_t __alignment ,
                                                                                           size_t __size ) ;
extern  __attribute__((__nothrow__, __noreturn__)) void abort(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) atexit)(void (*__func)(void) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) at_quick_exit)(void (*__func)(void) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) on_exit)(void (*__func)(int __status ,
                                                                                                   void *__arg ) ,
                                                                                    void *__arg ) ;
extern  __attribute__((__nothrow__, __noreturn__)) void exit(int __status ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void quick_exit(int __status ) ;
extern  __attribute__((__nothrow__, __noreturn__)) void _Exit(int __status ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) getenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) __secure_getenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) putenv)(char *__string ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) setenv)(char const   *__name ,
                                                                                   char const   *__value ,
                                                                                   int __replace ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) unsetenv)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int clearenv(void) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) mktemp)(char *__template ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemp)(char *__template )  __asm__("mkstemp64")  ;
extern int ( __attribute__((__nonnull__(1))) mkstemp64)(char *__template ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemps)(char *__template ,
                                                       int __suffixlen )  __asm__("mkstemps64")  ;
extern int ( __attribute__((__nonnull__(1))) mkstemps64)(char *__template ,
                                                         int __suffixlen ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) mkdtemp)(char *__template ) ;
extern int ( __attribute__((__nonnull__(1))) mkostemp)(char *__template ,
                                                       int __flags )  __asm__("mkostemp64")  ;
extern int ( __attribute__((__nonnull__(1))) mkostemp64)(char *__template ,
                                                         int __flags ) ;
extern int ( __attribute__((__nonnull__(1))) mkostemps)(char *__template ,
                                                        int __suffixlen ,
                                                        int __flags )  __asm__("mkostemps64")  ;
extern int ( __attribute__((__nonnull__(1))) mkostemps64)(char *__template ,
                                                          int __suffixlen ,
                                                          int __flags ) ;
extern int system(char const   *__command ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) canonicalize_file_name)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) char *realpath(char const   * __restrict  __name ,
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
extern void ( __attribute__((__nonnull__(1,4))) qsort_r)(void *__base ,
                                                         size_t __nmemb ,
                                                         size_t __size ,
                                                         int (*__compar)(void const   * ,
                                                                         void const   * ,
                                                                         void * ) ,
                                                         void *__arg ) ;
extern  __attribute__((__nothrow__)) int abs(int __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long labs(long __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long long llabs(long long __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) div_t div(int __numer , int __denom )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) ldiv_t ldiv(long __numer , long __denom )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) lldiv_t lldiv(long long __numer ,
                                                   long long __denom )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4))) ecvt)(double __value ,
                                                                                     int __ndigit ,
                                                                                     int * __restrict  __decpt ,
                                                                                     int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4))) fcvt)(double __value ,
                                                                                     int __ndigit ,
                                                                                     int * __restrict  __decpt ,
                                                                                     int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3))) gcvt)(double __value ,
                                                                                   int __ndigit ,
                                                                                   char *__buf ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4))) qecvt)(long double __value ,
                                                                                      int __ndigit ,
                                                                                      int * __restrict  __decpt ,
                                                                                      int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3,4))) qfcvt)(long double __value ,
                                                                                      int __ndigit ,
                                                                                      int * __restrict  __decpt ,
                                                                                      int * __restrict  __sign ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(3))) qgcvt)(long double __value ,
                                                                                    int __ndigit ,
                                                                                    char *__buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5))) ecvt_r)(double __value ,
                                                                                       int __ndigit ,
                                                                                       int * __restrict  __decpt ,
                                                                                       int * __restrict  __sign ,
                                                                                       char * __restrict  __buf ,
                                                                                       size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5))) fcvt_r)(double __value ,
                                                                                       int __ndigit ,
                                                                                       int * __restrict  __decpt ,
                                                                                       int * __restrict  __sign ,
                                                                                       char * __restrict  __buf ,
                                                                                       size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5))) qecvt_r)(long double __value ,
                                                                                        int __ndigit ,
                                                                                        int * __restrict  __decpt ,
                                                                                        int * __restrict  __sign ,
                                                                                        char * __restrict  __buf ,
                                                                                        size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4,5))) qfcvt_r)(long double __value ,
                                                                                        int __ndigit ,
                                                                                        int * __restrict  __decpt ,
                                                                                        int * __restrict  __sign ,
                                                                                        char * __restrict  __buf ,
                                                                                        size_t __len ) ;
extern  __attribute__((__nothrow__)) int mblen(char const   *__s , size_t __n ) ;
extern  __attribute__((__nothrow__)) int mbtowc(wchar_t * __restrict  __pwc ,
                                                char const   * __restrict  __s ,
                                                size_t __n ) ;
extern  __attribute__((__nothrow__)) int wctomb(char *__s , wchar_t __wchar ) ;
extern  __attribute__((__nothrow__)) size_t mbstowcs(wchar_t * __restrict  __pwcs ,
                                                     char const   * __restrict  __s ,
                                                     size_t __n ) ;
extern  __attribute__((__nothrow__)) size_t wcstombs(char * __restrict  __s ,
                                                     wchar_t const   * __restrict  __pwcs ,
                                                     size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) rpmatch)(char const   *__response ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,3))) getsubopt)(char ** __restrict  __optionp ,
                                                                                          char * const  * __restrict  __tokens ,
                                                                                          char ** __restrict  __valuep ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1))) setkey)(char const   *__key ) ;
extern int posix_openpt(int __oflag ) ;
extern  __attribute__((__nothrow__)) int grantpt(int __fd ) ;
extern  __attribute__((__nothrow__)) int unlockpt(int __fd ) ;
extern  __attribute__((__nothrow__)) char *ptsname(int __fd ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) ptsname_r)(int __fd ,
                                                                                      char *__buf ,
                                                                                      size_t __buflen ) ;
extern int getpt(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) getloadavg)(double *__loadavg ,
                                                                                       int __nelem ) ;
extern struct _IO_FILE_plus _IO_2_1_stdin_ ;
extern struct _IO_FILE_plus _IO_2_1_stdout_ ;
extern struct _IO_FILE_plus _IO_2_1_stderr_ ;
extern void _IO_cookie_init(struct _IO_cookie_file *__cfile , int __read_write ,
                            void *__cookie , _IO_cookie_io_functions_t __fns ) ;
extern int __underflow(_IO_FILE * ) ;
extern int __uflow(_IO_FILE * ) ;
extern int __overflow(_IO_FILE * , int  ) ;
extern int _IO_getc(_IO_FILE *__fp ) ;
extern int _IO_putc(int __c , _IO_FILE *__fp ) ;
extern  __attribute__((__nothrow__)) int _IO_feof(_IO_FILE *__fp ) ;
extern  __attribute__((__nothrow__)) int _IO_ferror(_IO_FILE *__fp ) ;
extern int _IO_peekc_locked(_IO_FILE *__fp ) ;
extern  __attribute__((__nothrow__)) void _IO_flockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) void _IO_funlockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) int _IO_ftrylockfile(_IO_FILE * ) ;
extern int _IO_vfscanf(_IO_FILE * __restrict   , char const   * __restrict   ,
                       __gnuc_va_list  , int * __restrict   ) ;
extern int _IO_vfprintf(_IO_FILE * __restrict   , char const   * __restrict   ,
                        __gnuc_va_list  ) ;
extern __ssize_t _IO_padn(_IO_FILE * , int  , __ssize_t  ) ;
extern size_t _IO_sgetn(_IO_FILE * , void * , size_t  ) ;
extern __off64_t _IO_seekoff(_IO_FILE * , __off64_t  , int  , int  ) ;
extern __off64_t _IO_seekpos(_IO_FILE * , __off64_t  , int  ) ;
extern  __attribute__((__nothrow__)) void _IO_free_backup_area(_IO_FILE * ) ;
extern struct _IO_FILE *stdin ;
extern struct _IO_FILE *stdout ;
extern struct _IO_FILE *stderr ;
extern  __attribute__((__nothrow__)) int remove(char const   *__filename ) ;
extern  __attribute__((__nothrow__)) int rename(char const   *__old ,
                                                char const   *__new ) ;
extern  __attribute__((__nothrow__)) int renameat(int __oldfd ,
                                                  char const   *__old ,
                                                  int __newfd ,
                                                  char const   *__new ) ;
extern FILE *tmpfile(void)  __asm__("tmpfile64")  ;
extern FILE *tmpfile64(void) ;
extern  __attribute__((__nothrow__)) char *tmpnam(char *__s ) ;
extern  __attribute__((__nothrow__)) char *tmpnam_r(char *__s ) ;
extern  __attribute__((__nothrow__)) char *tempnam(char const   *__dir ,
                                                   char const   *__pfx )  __attribute__((__malloc__)) ;
extern int fclose(FILE *__stream ) ;
extern int fflush(FILE *__stream ) ;
extern int fflush_unlocked(FILE *__stream ) ;
extern int fcloseall(void) ;
extern FILE *fopen(char const   * __restrict  __filename ,
                   char const   * __restrict  __modes )  __asm__("fopen64")  ;
extern FILE *freopen(char const   * __restrict  __filename ,
                     char const   * __restrict  __modes ,
                     FILE * __restrict  __stream )  __asm__("freopen64")  ;
extern FILE *fopen64(char const   * __restrict  __filename ,
                     char const   * __restrict  __modes ) ;
extern FILE *freopen64(char const   * __restrict  __filename ,
                       char const   * __restrict  __modes ,
                       FILE * __restrict  __stream ) ;
extern  __attribute__((__nothrow__)) FILE *fdopen(int __fd ,
                                                  char const   *__modes ) ;
extern  __attribute__((__nothrow__)) FILE *fopencookie(void * __restrict  __magic_cookie ,
                                                       char const   * __restrict  __modes ,
                                                       _IO_cookie_io_functions_t __io_funcs ) ;
extern  __attribute__((__nothrow__)) FILE *fmemopen(void *__s , size_t __len ,
                                                    char const   *__modes ) ;
extern  __attribute__((__nothrow__)) FILE *open_memstream(char **__bufloc ,
                                                          size_t *__sizeloc ) ;
extern  __attribute__((__nothrow__)) void setbuf(FILE * __restrict  __stream ,
                                                 char * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) int setvbuf(FILE * __restrict  __stream ,
                                                 char * __restrict  __buf ,
                                                 int __modes , size_t __n ) ;
extern  __attribute__((__nothrow__)) void setbuffer(FILE * __restrict  __stream ,
                                                    char * __restrict  __buf ,
                                                    size_t __size ) ;
extern  __attribute__((__nothrow__)) void setlinebuf(FILE *__stream ) ;
extern int fprintf(FILE * __restrict  __stream ,
                   char const   * __restrict  __format  , ...) ;
extern int printf(char const   * __restrict  __format  , ...) ;
extern  __attribute__((__nothrow__)) int sprintf(char * __restrict  __s ,
                                                 char const   * __restrict  __format 
                                                 , ...) ;
extern int vfprintf(FILE * __restrict  __s ,
                    char const   * __restrict  __format , __gnuc_va_list __arg ) ;
__inline extern int __attribute__((__gnu_inline__))  vprintf(char const   * __restrict  __fmt ,
                                                             __gnuc_va_list __arg ) ;
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
extern  __attribute__((__nothrow__)) int ( /* format attribute */  vasprintf)(char ** __restrict  __ptr ,
                                                                              char const   * __restrict  __f ,
                                                                              __gnuc_va_list __arg ) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  __asprintf)(char ** __restrict  __ptr ,
                                                                               char const   * __restrict  __fmt 
                                                                               , ...) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  asprintf)(char ** __restrict  __ptr ,
                                                                             char const   * __restrict  __fmt 
                                                                             , ...) ;
extern int ( /* format attribute */  vdprintf)(int __fd ,
                                               char const   * __restrict  __fmt ,
                                               __gnuc_va_list __arg ) ;
extern int ( /* format attribute */  dprintf)(int __fd ,
                                              char const   * __restrict  __fmt 
                                              , ...) ;
extern int fscanf(FILE * __restrict  __stream ,
                  char const   * __restrict  __format  , ...) ;
extern int scanf(char const   * __restrict  __format  , ...) ;
extern  __attribute__((__nothrow__)) int sscanf(char const   * __restrict  __s ,
                                                char const   * __restrict  __format 
                                                , ...) ;
extern int ( /* format attribute */  vfscanf)(FILE * __restrict  __s ,
                                              char const   * __restrict  __format ,
                                              __gnuc_va_list __arg ) ;
extern int ( /* format attribute */  vscanf)(char const   * __restrict  __format ,
                                             __gnuc_va_list __arg ) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  vsscanf)(char const   * __restrict  __s ,
                                                                            char const   * __restrict  __format ,
                                                                            __gnuc_va_list __arg ) ;
extern int fgetc(FILE *__stream ) ;
extern int getc(FILE *__stream ) ;
__inline extern int __attribute__((__gnu_inline__))  getchar(void) ;
__inline extern int __attribute__((__gnu_inline__))  getc_unlocked(FILE *__fp ) ;
__inline extern int __attribute__((__gnu_inline__))  getchar_unlocked(void) ;
__inline extern int __attribute__((__gnu_inline__))  fgetc_unlocked(FILE *__fp ) ;
extern int fputc(int __c , FILE *__stream ) ;
extern int putc(int __c , FILE *__stream ) ;
__inline extern int __attribute__((__gnu_inline__))  putchar(int __c ) ;
__inline extern int __attribute__((__gnu_inline__))  fputc_unlocked(int __c ,
                                                                    FILE *__stream ) ;
__inline extern int __attribute__((__gnu_inline__))  putc_unlocked(int __c ,
                                                                   FILE *__stream ) ;
__inline extern int __attribute__((__gnu_inline__))  putchar_unlocked(int __c ) ;
extern int getw(FILE *__stream ) ;
extern int putw(int __w , FILE *__stream ) ;
extern char *fgets(char * __restrict  __s , int __n ,
                   FILE * __restrict  __stream ) ;
extern char *gets(char *__s )  __attribute__((__warning__("gets is a security hole - use fgets instead"))) ;
extern char *fgets_unlocked(char * __restrict  __s , int __n ,
                            FILE * __restrict  __stream ) ;
extern __ssize_t __getdelim(char ** __restrict  __lineptr ,
                            size_t * __restrict  __n , int __delimiter ,
                            FILE * __restrict  __stream ) ;
extern __ssize_t getdelim(char ** __restrict  __lineptr ,
                          size_t * __restrict  __n , int __delimiter ,
                          FILE * __restrict  __stream ) ;
__inline extern __ssize_t __attribute__((__gnu_inline__))  getline(char ** __restrict  __lineptr ,
                                                                   size_t * __restrict  __n ,
                                                                   FILE * __restrict  __stream ) ;
extern int fputs(char const   * __restrict  __s , FILE * __restrict  __stream ) ;
extern int puts(char const   *__s ) ;
extern int ungetc(int __c , FILE *__stream ) ;
extern size_t fread(void * __restrict  __ptr , size_t __size , size_t __n ,
                    FILE * __restrict  __stream ) ;
extern size_t fwrite(void const   * __restrict  __ptr , size_t __size ,
                     size_t __n , FILE * __restrict  __s ) ;
extern int fputs_unlocked(char const   * __restrict  __s ,
                          FILE * __restrict  __stream ) ;
extern size_t fread_unlocked(void * __restrict  __ptr , size_t __size ,
                             size_t __n , FILE * __restrict  __stream ) ;
extern size_t fwrite_unlocked(void const   * __restrict  __ptr , size_t __size ,
                              size_t __n , FILE * __restrict  __stream ) ;
extern int fseek(FILE *__stream , long __off , int __whence ) ;
extern long ftell(FILE *__stream )  __attribute__((__warning__("ftell cannot handle files larger than 4 GB on 32-bit platforms - use ftello function for handling of large files"))) ;
extern void rewind(FILE *__stream ) ;
extern int fseeko(FILE *__stream , __off64_t __off , int __whence )  __asm__("fseeko64")  ;
extern __off64_t ftello(FILE *__stream )  __asm__("ftello64")  ;
extern int fgetpos(FILE * __restrict  __stream , fpos_t * __restrict  __pos )  __asm__("fgetpos64")  ;
extern int fsetpos(FILE *__stream , fpos_t const   *__pos )  __asm__("fsetpos64")  ;
extern int fseeko64(FILE *__stream , __off64_t __off , int __whence ) ;
extern __off64_t ftello64(FILE *__stream ) ;
extern int fgetpos64(FILE * __restrict  __stream , fpos64_t * __restrict  __pos ) ;
extern int fsetpos64(FILE *__stream , fpos64_t const   *__pos ) ;
extern  __attribute__((__nothrow__)) void clearerr(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int feof(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ferror(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) void clearerr_unlocked(FILE *__stream ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  feof_unlocked(FILE *__stream ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ferror_unlocked(FILE *__stream ) ;
extern void perror(char const   *__s ) ;
extern int sys_nerr ;
extern char const   * const  sys_errlist[] ;
extern int _sys_nerr ;
extern char const   * const  _sys_errlist[] ;
extern  __attribute__((__nothrow__)) int fileno(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int fileno_unlocked(FILE *__stream ) ;
extern FILE *popen(char const   *__command , char const   *__modes ) ;
extern int pclose(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) char *ctermid(char *__s ) ;
extern char *cuserid(char *__s ) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  obstack_printf)(struct obstack * __restrict  __obstack ,
                                                                                   char const   * __restrict  __format 
                                                                                   , ...) ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  obstack_vprintf)(struct obstack * __restrict  __obstack ,
                                                                                    char const   * __restrict  __format ,
                                                                                    __gnuc_va_list __args ) ;
extern  __attribute__((__nothrow__)) void flockfile(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ftrylockfile(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) void funlockfile(FILE *__stream ) ;
__inline extern int __attribute__((__gnu_inline__))  vprintf(char const   * __restrict  __fmt ,
                                                             __gnuc_va_list __arg ) 
{ 
  int tmp ;

  {
  tmp = vfprintf((FILE */* __restrict  */)stdout, __fmt, __arg);
  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern int __attribute__((__gnu_inline__))  getchar(void) 
{ 
  int tmp ;

  {
  tmp = _IO_getc(stdin);
  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern int __attribute__((__gnu_inline__))  fgetc_unlocked(FILE *__fp ) 
{ 
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  long tmp___3 ;

  {
  tmp___3 = __builtin_expect((long )((unsigned int )__fp->_IO_read_ptr >= (unsigned int )__fp->_IO_read_end),
                             0L);
  if (tmp___3) {
    tmp___0 = __uflow(__fp);
    tmp___2 = tmp___0;
  } else {
    tmp___1 = __fp->_IO_read_ptr;
    (__fp->_IO_read_ptr) ++;
    tmp___2 = (int )*((unsigned char *)tmp___1);
  }
  return ((int __attribute__((__gnu_inline__))  )tmp___2);
}
}
__inline extern int __attribute__((__gnu_inline__))  getc_unlocked(FILE *__fp ) 
{ 
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  long tmp___3 ;

  {
  tmp___3 = __builtin_expect((long )((unsigned int )__fp->_IO_read_ptr >= (unsigned int )__fp->_IO_read_end),
                             0L);
  if (tmp___3) {
    tmp___0 = __uflow(__fp);
    tmp___2 = tmp___0;
  } else {
    tmp___1 = __fp->_IO_read_ptr;
    (__fp->_IO_read_ptr) ++;
    tmp___2 = (int )*((unsigned char *)tmp___1);
  }
  return ((int __attribute__((__gnu_inline__))  )tmp___2);
}
}
__inline extern int __attribute__((__gnu_inline__))  getchar_unlocked(void) 
{ 
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  int tmp___2 ;
  long tmp___3 ;

  {
  tmp___3 = __builtin_expect((long )((unsigned int )stdin->_IO_read_ptr >= (unsigned int )stdin->_IO_read_end),
                             0L);
  if (tmp___3) {
    tmp___0 = __uflow(stdin);
    tmp___2 = tmp___0;
  } else {
    tmp___1 = stdin->_IO_read_ptr;
    (stdin->_IO_read_ptr) ++;
    tmp___2 = (int )*((unsigned char *)tmp___1);
  }
  return ((int __attribute__((__gnu_inline__))  )tmp___2);
}
}
__inline extern int __attribute__((__gnu_inline__))  putchar(int __c ) 
{ 
  int tmp ;

  {
  tmp = _IO_putc(__c, stdout);
  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern int __attribute__((__gnu_inline__))  fputc_unlocked(int __c ,
                                                                    FILE *__stream ) 
{ 
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  char tmp___2 ;
  int tmp___3 ;
  long tmp___4 ;

  {
  tmp___4 = __builtin_expect((long )((unsigned int )__stream->_IO_write_ptr >= (unsigned int )__stream->_IO_write_end),
                             0L);
  if (tmp___4) {
    tmp___0 = __overflow(__stream, (int )((unsigned char )__c));
    tmp___3 = tmp___0;
  } else {
    tmp___1 = __stream->_IO_write_ptr;
    (__stream->_IO_write_ptr) ++;
    tmp___2 = (char )__c;
    *tmp___1 = tmp___2;
    tmp___3 = (int )((unsigned char )tmp___2);
  }
  return ((int __attribute__((__gnu_inline__))  )tmp___3);
}
}
__inline extern int __attribute__((__gnu_inline__))  putc_unlocked(int __c ,
                                                                   FILE *__stream ) 
{ 
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  char tmp___2 ;
  int tmp___3 ;
  long tmp___4 ;

  {
  tmp___4 = __builtin_expect((long )((unsigned int )__stream->_IO_write_ptr >= (unsigned int )__stream->_IO_write_end),
                             0L);
  if (tmp___4) {
    tmp___0 = __overflow(__stream, (int )((unsigned char )__c));
    tmp___3 = tmp___0;
  } else {
    tmp___1 = __stream->_IO_write_ptr;
    (__stream->_IO_write_ptr) ++;
    tmp___2 = (char )__c;
    *tmp___1 = tmp___2;
    tmp___3 = (int )((unsigned char )tmp___2);
  }
  return ((int __attribute__((__gnu_inline__))  )tmp___3);
}
}
__inline extern int __attribute__((__gnu_inline__))  putchar_unlocked(int __c ) 
{ 
  long tmp ;
  int tmp___0 ;
  char *tmp___1 ;
  char tmp___2 ;
  int tmp___3 ;
  long tmp___4 ;

  {
  tmp___4 = __builtin_expect((long )((unsigned int )stdout->_IO_write_ptr >= (unsigned int )stdout->_IO_write_end),
                             0L);
  if (tmp___4) {
    tmp___0 = __overflow(stdout, (int )((unsigned char )__c));
    tmp___3 = tmp___0;
  } else {
    tmp___1 = stdout->_IO_write_ptr;
    (stdout->_IO_write_ptr) ++;
    tmp___2 = (char )__c;
    *tmp___1 = tmp___2;
    tmp___3 = (int )((unsigned char )tmp___2);
  }
  return ((int __attribute__((__gnu_inline__))  )tmp___3);
}
}
__inline extern __ssize_t __attribute__((__gnu_inline__))  getline(char ** __restrict  __lineptr ,
                                                                   size_t * __restrict  __n ,
                                                                   FILE * __restrict  __stream ) 
{ 
  __ssize_t tmp ;

  {
  tmp = __getdelim(__lineptr, __n, '\n', __stream);
  return ((__ssize_t __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  feof_unlocked(FILE *__stream ) ;
__inline extern int __attribute__((__gnu_inline__))  feof_unlocked(FILE *__stream ) 
{ 


  {
  return ((int __attribute__((__gnu_inline__))  )((__stream->_flags & 16) != 0));
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ferror_unlocked(FILE *__stream ) ;
__inline extern int __attribute__((__gnu_inline__))  ferror_unlocked(FILE *__stream ) 
{ 


  {
  return ((int __attribute__((__gnu_inline__))  )((__stream->_flags & 32) != 0));
}
}
extern int rpl_fflush(FILE *gl_stream ) ;
extern int _gl_cxxalias_dummy ;
extern int ( __attribute__((__nonnull__(1))) fpurge)(FILE *gl_stream ) ;
extern int ( __attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp ,
                                                         off_t offset ,
                                                         int whence ) ;
__inline static int ( __attribute__((__nonnull__(1))) rpl_fseek)(FILE *fp ,
                                                                 long offset ,
                                                                 int whence )  __attribute__((__warning__("fseek cannot handle files larger than 4 GB on 32-bit platforms - use fseeko function for handling of large files"))) ;
__inline static int ( __attribute__((__nonnull__(1))) rpl_fseek)(FILE *fp ,
                                                                 long offset ,
                                                                 int whence ) 
{ 
  int tmp ;

  {
  tmp = rpl_fseeko(fp, (off_t )offset, whence);
  return (tmp);
}
}
extern  __attribute__((__nothrow__)) clock_t clock(void) ;
extern  __attribute__((__nothrow__)) time_t time(time_t *__timer ) ;
extern  __attribute__((__nothrow__)) double difftime(time_t __time1 ,
                                                     time_t __time0 )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) time_t mktime(struct tm *__tp ) ;
extern  __attribute__((__nothrow__)) size_t strftime(char * __restrict  __s ,
                                                     size_t __maxsize ,
                                                     char const   * __restrict  __format ,
                                                     struct tm  const  * __restrict  __tp ) ;
extern  __attribute__((__nothrow__)) char *strptime(char const   * __restrict  __s ,
                                                    char const   * __restrict  __fmt ,
                                                    struct tm *__tp ) ;
extern  __attribute__((__nothrow__)) size_t strftime_l(char * __restrict  __s ,
                                                       size_t __maxsize ,
                                                       char const   * __restrict  __format ,
                                                       struct tm  const  * __restrict  __tp ,
                                                       __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) char *strptime_l(char const   * __restrict  __s ,
                                                      char const   * __restrict  __fmt ,
                                                      struct tm *__tp ,
                                                      __locale_t __loc ) ;
extern  __attribute__((__nothrow__)) struct tm *gmtime(time_t const   *__timer ) ;
extern  __attribute__((__nothrow__)) struct tm *localtime(time_t const   *__timer ) ;
extern  __attribute__((__nothrow__)) struct tm *gmtime_r(time_t const   * __restrict  __timer ,
                                                         struct tm * __restrict  __tp ) ;
extern  __attribute__((__nothrow__)) struct tm *localtime_r(time_t const   * __restrict  __timer ,
                                                            struct tm * __restrict  __tp ) ;
extern  __attribute__((__nothrow__)) char *asctime(struct tm  const  *__tp ) ;
extern  __attribute__((__nothrow__)) char *ctime(time_t const   *__timer ) ;
extern  __attribute__((__nothrow__)) char *asctime_r(struct tm  const  * __restrict  __tp ,
                                                     char * __restrict  __buf ) ;
extern  __attribute__((__nothrow__)) char *ctime_r(time_t const   * __restrict  __timer ,
                                                   char * __restrict  __buf ) ;
extern char *__tzname[2] ;
extern int __daylight ;
extern long __timezone ;
extern char *tzname[2] ;
extern  __attribute__((__nothrow__)) void tzset(void) ;
extern int daylight ;
extern long timezone ;
extern  __attribute__((__nothrow__)) int stime(time_t const   *__when ) ;
extern  __attribute__((__nothrow__)) time_t timegm(struct tm *__tp ) ;
extern  __attribute__((__nothrow__)) time_t timelocal(struct tm *__tp ) ;
extern  __attribute__((__nothrow__)) int dysize(int __year )  __attribute__((__const__)) ;
extern int nanosleep(struct timespec  const  *__requested_time ,
                     struct timespec *__remaining ) ;
extern  __attribute__((__nothrow__)) int clock_getres(clockid_t __clock_id ,
                                                      struct timespec *__res ) ;
extern  __attribute__((__nothrow__)) int clock_gettime(clockid_t __clock_id ,
                                                       struct timespec *__tp ) ;
extern  __attribute__((__nothrow__)) int clock_settime(clockid_t __clock_id ,
                                                       struct timespec  const  *__tp ) ;
extern int clock_nanosleep(clockid_t __clock_id , int __flags ,
                           struct timespec  const  *__req ,
                           struct timespec *__rem ) ;
extern  __attribute__((__nothrow__)) int clock_getcpuclockid(pid_t __pid ,
                                                             clockid_t *__clock_id ) ;
extern  __attribute__((__nothrow__)) int timer_create(clockid_t __clock_id ,
                                                      struct sigevent * __restrict  __evp ,
                                                      timer_t * __restrict  __timerid ) ;
extern  __attribute__((__nothrow__)) int timer_delete(timer_t __timerid ) ;
extern  __attribute__((__nothrow__)) int timer_settime(timer_t __timerid ,
                                                       int __flags ,
                                                       struct itimerspec  const  * __restrict  __value ,
                                                       struct itimerspec * __restrict  __ovalue ) ;
extern  __attribute__((__nothrow__)) int timer_gettime(timer_t __timerid ,
                                                       struct itimerspec *__value ) ;
extern  __attribute__((__nothrow__)) int timer_getoverrun(timer_t __timerid ) ;
extern int getdate_err ;
extern struct tm *getdate(char const   *__string ) ;
extern int getdate_r(char const   * __restrict  __string ,
                     struct tm * __restrict  __resbufp ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2))) memcpy)(void * __restrict  __dest ,
                                                                                       void const   * __restrict  __src ,
                                                                                       size_t __n ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2))) memmove)(void *__dest ,
                                                                                        void const   *__src ,
                                                                                        size_t __n ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2))) memccpy)(void * __restrict  __dest ,
                                                                                        void const   * __restrict  __src ,
                                                                                        int __c ,
                                                                                        size_t __n ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1))) memset)(void *__s ,
                                                                                     int __c ,
                                                                                     size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) memcmp)(void const   *__s1 ,
                                                                                     void const   *__s2 ,
                                                                                     size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1))) memchr)(void const   *__s ,
                                                                                     int __c ,
                                                                                     size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1))) rawmemchr)(void const   *__s ,
                                                                                        int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1))) memrchr)(void const   *__s ,
                                                                                      int __c ,
                                                                                      size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strcpy)(char * __restrict  __dest ,
                                                                                       char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strncpy)(char * __restrict  __dest ,
                                                                                        char const   * __restrict  __src ,
                                                                                        size_t __n ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strcat)(char * __restrict  __dest ,
                                                                                       char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strncat)(char * __restrict  __dest ,
                                                                                        char const   * __restrict  __src ,
                                                                                        size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strcmp)(char const   *__s1 ,
                                                                                     char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strncmp)(char const   *__s1 ,
                                                                                      char const   *__s2 ,
                                                                                      size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strcoll)(char const   *__s1 ,
                                                                                      char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(2))) strxfrm)(char * __restrict  __dest ,
                                                                                       char const   * __restrict  __src ,
                                                                                       size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,3))) strcoll_l)(char const   *__s1 ,
                                                                                          char const   *__s2 ,
                                                                                          __locale_t __l )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(2,4))) strxfrm_l)(char *__dest ,
                                                                                           char const   *__src ,
                                                                                           size_t __n ,
                                                                                           __locale_t __l ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) strdup)(char const   *__s )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) strndup)(char const   *__string ,
                                                                                      size_t __n )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) strchr)(char const   *__s ,
                                                                                     int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) strrchr)(char const   *__s ,
                                                                                      int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) strchrnul)(char const   *__s ,
                                                                                        int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1,2))) strcspn)(char const   *__s ,
                                                                                         char const   *__reject )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1,2))) strspn)(char const   *__s ,
                                                                                        char const   *__accept )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strpbrk)(char const   *__s ,
                                                                                        char const   *__accept )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strstr)(char const   *__haystack ,
                                                                                       char const   *__needle )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2))) strtok)(char * __restrict  __s ,
                                                                                     char const   * __restrict  __delim ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2,3))) __strtok_r)(char * __restrict  __s ,
                                                                                           char const   * __restrict  __delim ,
                                                                                           char ** __restrict  __save_ptr ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2,3))) strtok_r)(char * __restrict  __s ,
                                                                                         char const   * __restrict  __delim ,
                                                                                         char ** __restrict  __save_ptr ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strcasestr)(char const   *__haystack ,
                                                                                           char const   *__needle )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,3))) memmem)(void const   *__haystack ,
                                                                                       size_t __haystacklen ,
                                                                                       void const   *__needle ,
                                                                                       size_t __needlelen )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2))) __mempcpy)(void * __restrict  __dest ,
                                                                                          void const   * __restrict  __src ,
                                                                                          size_t __n ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2))) mempcpy)(void * __restrict  __dest ,
                                                                                        void const   * __restrict  __src ,
                                                                                        size_t __n ) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1))) strlen)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1))) strnlen)(char const   *__string ,
                                                                                       size_t __maxlen )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *strerror(int __errnum ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2))) strerror_r)(int __errnum ,
                                                                                         char *__buf ,
                                                                                         size_t __buflen ) ;
extern  __attribute__((__nothrow__)) char *strerror_l(int __errnum ,
                                                      __locale_t __l ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1))) __bzero)(void *__s ,
                                                                                     size_t __n ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1,2))) bcopy)(void const   *__src ,
                                                                                     void *__dest ,
                                                                                     size_t __n ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1))) bzero)(void *__s ,
                                                                                   size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) bcmp)(void const   *__s1 ,
                                                                                   void const   *__s2 ,
                                                                                   size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) index)(char const   *__s ,
                                                                                    int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) rindex)(char const   *__s ,
                                                                                     int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ffs(int __i )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ffsl(long __l )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ffsll(long long __ll )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strcasecmp)(char const   *__s1 ,
                                                                                         char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strncasecmp)(char const   *__s1 ,
                                                                                          char const   *__s2 ,
                                                                                          size_t __n )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,3))) strcasecmp_l)(char const   *__s1 ,
                                                                                             char const   *__s2 ,
                                                                                             __locale_t __loc )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,4))) strncasecmp_l)(char const   *__s1 ,
                                                                                              char const   *__s2 ,
                                                                                              size_t __n ,
                                                                                              __locale_t __loc )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) strsep)(char ** __restrict  __stringp ,
                                                                                       char const   * __restrict  __delim ) ;
extern  __attribute__((__nothrow__)) char *strsignal(int __sig ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) __stpcpy)(char * __restrict  __dest ,
                                                                                         char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) stpcpy)(char * __restrict  __dest ,
                                                                                       char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) __stpncpy)(char * __restrict  __dest ,
                                                                                          char const   * __restrict  __src ,
                                                                                          size_t __n ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) stpncpy)(char * __restrict  __dest ,
                                                                                        char const   * __restrict  __src ,
                                                                                        size_t __n ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strverscmp)(char const   *__s1 ,
                                                                                         char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) strfry)(char *__string ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1))) memfrob)(void *__s ,
                                                                                      size_t __n ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) basename)(char const   *__filename ) ;
extern void *__rawmemchr(void const   *__s , int __c ) ;
__inline extern size_t __attribute__((__gnu_inline__))  __strcspn_c1(char const   *__s ,
                                                                     int __reject ) ;
__inline extern size_t __attribute__((__gnu_inline__))  __strcspn_c1(char const   *__s ,
                                                                     int __reject ) 
{ 
  register size_t __result ;

  {
  __result = (size_t )0;
  while (1) {
    if ((int const   )*(__s + __result) != 0) {
      if ((int const   )*(__s + __result) != (int const   )__reject) {

      } else {
        break;
      }
    } else {
      break;
    }
    __result ++;
  }
  return ((size_t __attribute__((__gnu_inline__))  )__result);
}
}
__inline extern size_t __attribute__((__gnu_inline__))  __strcspn_c2(char const   *__s ,
                                                                     int __reject1 ,
                                                                     int __reject2 ) ;
__inline extern size_t __attribute__((__gnu_inline__))  __strcspn_c2(char const   *__s ,
                                                                     int __reject1 ,
                                                                     int __reject2 ) 
{ 
  register size_t __result ;

  {
  __result = (size_t )0;
  while (1) {
    if ((int const   )*(__s + __result) != 0) {
      if ((int const   )*(__s + __result) != (int const   )__reject1) {
        if ((int const   )*(__s + __result) != (int const   )__reject2) {

        } else {
          break;
        }
      } else {
        break;
      }
    } else {
      break;
    }
    __result ++;
  }
  return ((size_t __attribute__((__gnu_inline__))  )__result);
}
}
__inline extern size_t __attribute__((__gnu_inline__))  __strcspn_c3(char const   *__s ,
                                                                     int __reject1 ,
                                                                     int __reject2 ,
                                                                     int __reject3 ) ;
__inline extern size_t __attribute__((__gnu_inline__))  __strcspn_c3(char const   *__s ,
                                                                     int __reject1 ,
                                                                     int __reject2 ,
                                                                     int __reject3 ) 
{ 
  register size_t __result ;

  {
  __result = (size_t )0;
  while (1) {
    if ((int const   )*(__s + __result) != 0) {
      if ((int const   )*(__s + __result) != (int const   )__reject1) {
        if ((int const   )*(__s + __result) != (int const   )__reject2) {
          if ((int const   )*(__s + __result) != (int const   )__reject3) {

          } else {
            break;
          }
        } else {
          break;
        }
      } else {
        break;
      }
    } else {
      break;
    }
    __result ++;
  }
  return ((size_t __attribute__((__gnu_inline__))  )__result);
}
}
__inline extern size_t __attribute__((__gnu_inline__))  __strspn_c1(char const   *__s ,
                                                                    int __accept ) ;
__inline extern size_t __attribute__((__gnu_inline__))  __strspn_c1(char const   *__s ,
                                                                    int __accept ) 
{ 
  register size_t __result ;

  {
  __result = (size_t )0;
  while ((int const   )*(__s + __result) == (int const   )__accept) {
    __result ++;
  }
  return ((size_t __attribute__((__gnu_inline__))  )__result);
}
}
__inline extern size_t __attribute__((__gnu_inline__))  __strspn_c2(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ) ;
__inline extern size_t __attribute__((__gnu_inline__))  __strspn_c2(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ) 
{ 
  register size_t __result ;

  {
  __result = (size_t )0;
  while (1) {
    if ((int const   )*(__s + __result) == (int const   )__accept1) {

    } else
    if ((int const   )*(__s + __result) == (int const   )__accept2) {

    } else {
      break;
    }
    __result ++;
  }
  return ((size_t __attribute__((__gnu_inline__))  )__result);
}
}
__inline extern size_t __attribute__((__gnu_inline__))  __strspn_c3(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ,
                                                                    int __accept3 ) ;
__inline extern size_t __attribute__((__gnu_inline__))  __strspn_c3(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ,
                                                                    int __accept3 ) 
{ 
  register size_t __result ;

  {
  __result = (size_t )0;
  while (1) {
    if ((int const   )*(__s + __result) == (int const   )__accept1) {

    } else
    if ((int const   )*(__s + __result) == (int const   )__accept2) {

    } else
    if ((int const   )*(__s + __result) == (int const   )__accept3) {

    } else {
      break;
    }
    __result ++;
  }
  return ((size_t __attribute__((__gnu_inline__))  )__result);
}
}
__inline extern char __attribute__((__gnu_inline__))  *__strpbrk_c2(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ) ;
__inline extern char __attribute__((__gnu_inline__))  *__strpbrk_c2(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ) 
{ 
  char *tmp ;

  {
  while (1) {
    if ((int const   )*__s != 0) {
      if ((int const   )*__s != (int const   )__accept1) {
        if ((int const   )*__s != (int const   )__accept2) {

        } else {
          break;
        }
      } else {
        break;
      }
    } else {
      break;
    }
    __s ++;
  }
  if ((int const   )*__s == 0) {
    tmp = (char *)((void *)0);
  } else {
    tmp = (char *)((size_t )__s);
  }
  return ((char __attribute__((__gnu_inline__))  *)tmp);
}
}
__inline extern char __attribute__((__gnu_inline__))  *__strpbrk_c3(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ,
                                                                    int __accept3 ) ;
__inline extern char __attribute__((__gnu_inline__))  *__strpbrk_c3(char const   *__s ,
                                                                    int __accept1 ,
                                                                    int __accept2 ,
                                                                    int __accept3 ) 
{ 
  char *tmp ;

  {
  while (1) {
    if ((int const   )*__s != 0) {
      if ((int const   )*__s != (int const   )__accept1) {
        if ((int const   )*__s != (int const   )__accept2) {
          if ((int const   )*__s != (int const   )__accept3) {

          } else {
            break;
          }
        } else {
          break;
        }
      } else {
        break;
      }
    } else {
      break;
    }
    __s ++;
  }
  if ((int const   )*__s == 0) {
    tmp = (char *)((void *)0);
  } else {
    tmp = (char *)((size_t )__s);
  }
  return ((char __attribute__((__gnu_inline__))  *)tmp);
}
}
__inline extern char __attribute__((__gnu_inline__))  *__strtok_r_1c(char *__s ,
                                                                     char __sep ,
                                                                     char **__nextp ) ;
__inline extern char __attribute__((__gnu_inline__))  *__strtok_r_1c(char *__s ,
                                                                     char __sep ,
                                                                     char **__nextp ) 
{ 
  char *__result ;
  char *tmp ;
  char *tmp___0 ;

  {
  if ((unsigned int )__s == (unsigned int )((void *)0)) {
    __s = *__nextp;
  } else {

  }
  while ((int )*__s == (int )__sep) {
    __s ++;
  }
  __result = (char *)((void *)0);
  if ((int )*__s != 0) {
    tmp = __s;
    __s ++;
    __result = tmp;
    while ((int )*__s != 0) {
      tmp___0 = __s;
      __s ++;
      if ((int )*tmp___0 == (int )__sep) {
        *(__s + -1) = (char )'\000';
        break;
      } else {

      }
    }
  } else {

  }
  *__nextp = __s;
  return ((char __attribute__((__gnu_inline__))  *)__result);
}
}
extern char *__strsep_g(char **__stringp , char const   *__delim ) ;
__inline extern char __attribute__((__gnu_inline__))  *__strsep_1c(char **__s ,
                                                                   char __reject ) ;
__inline extern char __attribute__((__gnu_inline__))  *__strsep_1c(char **__s ,
                                                                   char __reject ) 
{ 
  register char *__retval ;
  char *tmp ;
  char *tmp___0 ;
  void *tmp___1 ;
  char *tmp___2 ;

  {
  __retval = *__s;
  if ((unsigned int )__retval != (unsigned int )((void *)0)) {
    tmp___2 = __builtin_strchr(__retval, (int )__reject);
    tmp___0 = tmp___2;
    *__s = tmp___0;
    if ((unsigned int )tmp___0 != (unsigned int )((void *)0)) {
      tmp = *__s;
      (*__s) ++;
      *tmp = (char )'\000';
    } else {

    }
  } else {

  }
  return ((char __attribute__((__gnu_inline__))  *)__retval);
}
}
__inline extern char __attribute__((__gnu_inline__))  *__strsep_2c(char **__s ,
                                                                   char __reject1 ,
                                                                   char __reject2 ) ;
__inline extern char __attribute__((__gnu_inline__))  *__strsep_2c(char **__s ,
                                                                   char __reject1 ,
                                                                   char __reject2 ) 
{ 
  register char *__retval ;
  register char *__cp ;
  char *tmp ;

  {
  __retval = *__s;
  if ((unsigned int )__retval != (unsigned int )((void *)0)) {
    __cp = __retval;
    while (1) {
      if ((int )*__cp == 0) {
        __cp = (char *)((void *)0);
        break;
      } else {

      }
      if ((int )*__cp == (int )__reject1) {
        tmp = __cp;
        __cp ++;
        *tmp = (char )'\000';
        break;
      } else
      if ((int )*__cp == (int )__reject2) {
        tmp = __cp;
        __cp ++;
        *tmp = (char )'\000';
        break;
      } else {

      }
      __cp ++;
    }
    *__s = __cp;
  } else {

  }
  return ((char __attribute__((__gnu_inline__))  *)__retval);
}
}
__inline extern char __attribute__((__gnu_inline__))  *__strsep_3c(char **__s ,
                                                                   char __reject1 ,
                                                                   char __reject2 ,
                                                                   char __reject3 ) ;
__inline extern char __attribute__((__gnu_inline__))  *__strsep_3c(char **__s ,
                                                                   char __reject1 ,
                                                                   char __reject2 ,
                                                                   char __reject3 ) 
{ 
  register char *__retval ;
  register char *__cp ;
  char *tmp ;

  {
  __retval = *__s;
  if ((unsigned int )__retval != (unsigned int )((void *)0)) {
    __cp = __retval;
    while (1) {
      if ((int )*__cp == 0) {
        __cp = (char *)((void *)0);
        break;
      } else {

      }
      if ((int )*__cp == (int )__reject1) {
        tmp = __cp;
        __cp ++;
        *tmp = (char )'\000';
        break;
      } else
      if ((int )*__cp == (int )__reject2) {
        tmp = __cp;
        __cp ++;
        *tmp = (char )'\000';
        break;
      } else
      if ((int )*__cp == (int )__reject3) {
        tmp = __cp;
        __cp ++;
        *tmp = (char )'\000';
        break;
      } else {

      }
      __cp ++;
    }
    *__s = __cp;
  } else {

  }
  return ((char __attribute__((__gnu_inline__))  *)__retval);
}
}
extern  __attribute__((__nothrow__)) char *__strdup(char const   *__string )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) char *__strndup(char const   *__string ,
                                                     size_t __n )  __attribute__((__malloc__)) ;
extern int method ;
extern uch inbuf[] ;
extern uch outbuf[] ;
extern ush d_buf[] ;
extern uch window[] ;
extern ush prev[] ;
extern unsigned int insize ;
extern unsigned int inptr ;
extern unsigned int outcnt ;
extern off_t bytes_in ;
extern off_t bytes_out ;
extern off_t header_bytes ;
extern int ifd ;
extern int ofd ;
extern char ifname[] ;
extern char ofname[] ;
extern char *program_name ;
extern struct timespec time_stamp ;
extern off_t ifile_size ;
extern int decrypt ;
extern int exit_code ;
extern int verbose ;
extern int quiet ;
extern int level ;
extern int test ;
extern int to_stdout ;
extern int save_orig_name ;
extern int zip(int in , int out ) ;
extern int file_read(char *buf , unsigned int size ) ;
extern int unzip(int in , int out ) ;
extern int check_zipfile(int in ) ;
extern int unpack(int in , int out ) ;
extern int unlzh(int in , int out ) ;
extern  __attribute__((__noreturn__)) void abort_gzip(void) ;
extern void lm_init(int pack_level , ush *flags ) ;
extern off_t deflate(void) ;
extern void ct_init(ush *attr , int *method ) ;
extern int ct_tally(int dist , int lc ) ;
extern off_t flush_block(char *buf , ulg stored_len , int eof ) ;
extern void bi_init(file_t zipfile ) ;
extern void send_bits(int value , int length ) ;
extern unsigned int bi_reverse(unsigned int value , int length ) ;
extern void bi_windup(void) ;
extern void copy_block(char *buf , unsigned int len , int header ) ;
extern int (*read_buf)(char *buf , unsigned int size ) ;
extern int copy(int in , int out ) ;
extern ulg updcrc(uch *s , unsigned int n ) ;
extern void clear_bufs(void) ;
extern int fill_inbuf(int eof_ok ) ;
extern void flush_outbuf(void) ;
extern void flush_window(void) ;
extern void write_buf(int fd , voidp buf , unsigned int cnt ) ;
extern int read_buffer(int fd , voidp buf , unsigned int cnt ) ;
extern char *strlwr(char *s ) ;
extern char *gzip_base_name(char *fname ) ;
extern int xunlink(char *fname ) ;
extern void make_simple_name(char *name ) ;
extern char *add_envopt(int *argcp , char ***argvp , char *env ) ;
extern void gzip_error(char *m ) ;
extern  __attribute__((__noreturn__)) void xalloc_die(void) ;
extern void warning(char *m ) ;
extern void read_error(void) ;
extern void write_error(void) ;
extern void display_ratio(off_t num , off_t den , FILE *file ) ;
extern void fprint_off(FILE * , off_t  , int  ) ;
int inflate(void) ;
extern int yesno(void) ;
int huft_build(unsigned int *b , unsigned int n , unsigned int s , ush *d ,
               ush *e , struct huft **t , int *m ) ;
int huft_free(struct huft *t ) ;
int inflate_codes(struct huft *tl , struct huft *td , int bl , int bd ) ;
int inflate_stored(void) ;
int inflate_fixed(void) ;
int inflate_dynamic(void) ;
int inflate_block(int *e ) ;
static unsigned int border[19]  = 
  {      16U,      17U,      18U,      0U, 
        8U,      7U,      9U,      6U, 
        10U,      5U,      11U,      4U, 
        12U,      3U,      13U,      2U, 
        14U,      1U,      15U};
static ush cplens[31]  = 
  {      (ush )3,      (ush )4,      (ush )5,      (ush )6, 
        (ush )7,      (ush )8,      (ush )9,      (ush )10, 
        (ush )11,      (ush )13,      (ush )15,      (ush )17, 
        (ush )19,      (ush )23,      (ush )27,      (ush )31, 
        (ush )35,      (ush )43,      (ush )51,      (ush )59, 
        (ush )67,      (ush )83,      (ush )99,      (ush )115, 
        (ush )131,      (ush )163,      (ush )195,      (ush )227, 
        (ush )258,      (ush )0,      (ush )0};
static ush cplext[31]  = 
  {      (ush )0,      (ush )0,      (ush )0,      (ush )0, 
        (ush )0,      (ush )0,      (ush )0,      (ush )0, 
        (ush )1,      (ush )1,      (ush )1,      (ush )1, 
        (ush )2,      (ush )2,      (ush )2,      (ush )2, 
        (ush )3,      (ush )3,      (ush )3,      (ush )3, 
        (ush )4,      (ush )4,      (ush )4,      (ush )4, 
        (ush )5,      (ush )5,      (ush )5,      (ush )5, 
        (ush )0,      (ush )99,      (ush )99};
static ush cpdist[30]  = 
  {      (ush )1,      (ush )2,      (ush )3,      (ush )4, 
        (ush )5,      (ush )7,      (ush )9,      (ush )13, 
        (ush )17,      (ush )25,      (ush )33,      (ush )49, 
        (ush )65,      (ush )97,      (ush )129,      (ush )193, 
        (ush )257,      (ush )385,      (ush )513,      (ush )769, 
        (ush )1025,      (ush )1537,      (ush )2049,      (ush )3073, 
        (ush )4097,      (ush )6145,      (ush )8193,      (ush )12289, 
        (ush )16385,      (ush )24577};
static ush cpdext[30]  = 
  {      (ush )0,      (ush )0,      (ush )0,      (ush )0, 
        (ush )1,      (ush )1,      (ush )2,      (ush )2, 
        (ush )3,      (ush )3,      (ush )4,      (ush )4, 
        (ush )5,      (ush )5,      (ush )6,      (ush )6, 
        (ush )7,      (ush )7,      (ush )8,      (ush )8, 
        (ush )9,      (ush )9,      (ush )10,      (ush )10, 
        (ush )11,      (ush )11,      (ush )12,      (ush )12, 
        (ush )13,      (ush )13};
ulg bb  ;
unsigned int bk  ;
ush mask_bits[17]  = 
  {      (ush )0,      (ush )1,      (ush )3,      (ush )7, 
        (ush )15,      (ush )31,      (ush )63,      (ush )127, 
        (ush )255,      (ush )511,      (ush )1023,      (ush )2047, 
        (ush )4095,      (ush )8191,      (ush )16383,      (ush )32767, 
        (ush )65535};
int lbits  =    9;
int dbits  =    6;
unsigned int hufts  ;
int huft_build(unsigned int *b , unsigned int n , unsigned int s , ush *d ,
               ush *e , struct huft **t , int *m ) 
{ 
  unsigned int a ;
  unsigned int c[17] ;
  unsigned int f ;
  int g ;
  int h ;
  register unsigned int i ;
  register unsigned int j ;
  register int k ;
  int l ;
  register unsigned int *p ;
  register struct huft *q ;
  struct huft r ;
  struct huft *u[16] ;
  unsigned int v[288] ;
  register int w ;
  unsigned int x[17] ;
  unsigned int *xp ;
  int y ;
  unsigned int z ;
  void *tmp ;
  unsigned int *tmp___0 ;
  unsigned int *tmp___1 ;
  unsigned int tmp___2 ;
  unsigned int *tmp___3 ;
  void *tmp___4 ;
  int tmp___5 ;
  unsigned int *tmp___6 ;
  unsigned int tmp___7 ;
  int tmp___8 ;

  {
  memset((voidp )(c), 0, sizeof(c));
  p = b;
  i = n;
  while (1) {
    (c[*p]) ++;
    p ++;
    i --;
    if (i) {

    } else {
      break;
    }
  }
  if (c[0] == n) {
    tmp = malloc(2U * sizeof(*q));
    q = (struct huft *)tmp;
    if (! q) {
      return (3);
    } else {

    }
    hufts += 2U;
    (q + 0)->v.t = (struct huft *)((void *)0);
    (q + 1)->e = (uch )99;
    (q + 1)->b = (uch )1;
    *t = q + 1;
    *m = 1;
    return (0);
  } else {

  }
  l = *m;
  j = 1U;
  while (j <= 16U) {
    if (c[j]) {
      break;
    } else {

    }
    j ++;
  }
  k = (int )j;
  if ((unsigned int )l < j) {
    l = (int )j;
  } else {

  }
  i = 16U;
  while (i) {
    if (c[i]) {
      break;
    } else {

    }
    i --;
  }
  g = (int )i;
  if ((unsigned int )l > i) {
    l = (int )i;
  } else {

  }
  *m = l;
  y = 1 << j;
  while (j < i) {
    y = (int )((unsigned int )y - c[j]);
    if (y < 0) {
      return (2);
    } else {

    }
    j ++;
    y <<= 1;
  }
  y = (int )((unsigned int )y - c[i]);
  if (y < 0) {
    return (2);
  } else {

  }
  c[i] += (unsigned int )y;
  j = 0U;
  x[1] = j;
  p = c + 1;
  xp = x + 2;
  while (1) {
    i --;
    if (i) {

    } else {
      break;
    }
    tmp___0 = xp;
    xp ++;
    tmp___1 = p;
    p ++;
    j += *tmp___1;
    *tmp___0 = j;
  }
  p = b;
  i = 0U;
  while (1) {
    tmp___3 = p;
    p ++;
    j = *tmp___3;
    if (j != 0U) {
      tmp___2 = x[j];
      (x[j]) ++;
      v[tmp___2] = i;
    } else {

    }
    i ++;
    if (i < n) {

    } else {
      break;
    }
  }
  n = x[g];
  i = 0U;
  x[0] = i;
  p = v;
  h = -1;
  w = - l;
  u[0] = (struct huft *)((void *)0);
  q = (struct huft *)((void *)0);
  z = 0U;
  while (k <= g) {
    a = c[k];
    while (1) {
      tmp___7 = a;
      a --;
      if (tmp___7) {

      } else {
        break;
      }
      while (k > w + l) {
        h ++;
        w += l;
        z = (unsigned int )(g - w);
        if (z > (unsigned int )l) {
          z = (unsigned int )l;
        } else {
          z = z;
        }
        j = (unsigned int )(k - w);
        f = (unsigned int )(1 << j);
        if (f > a + 1U) {
          f -= a + 1U;
          xp = c + k;
          if (j < z) {
            while (1) {
              j ++;
              if (j < z) {

              } else {
                break;
              }
              f <<= 1;
              xp ++;
              if (f <= *xp) {
                break;
              } else {

              }
              f -= *xp;
            }
          } else {

          }
        } else {

        }
        z = (unsigned int )(1 << j);
        tmp___4 = malloc((z + 1U) * sizeof(struct huft ));
        q = (struct huft *)tmp___4;
        if ((unsigned int )q == (unsigned int )((struct huft *)((void *)0))) {
          if (h) {
            huft_free(u[0]);
          } else {

          }
          return (3);
        } else {

        }
        hufts += z + 1U;
        *t = q + 1;
        t = & q->v.t;
        *t = (struct huft *)((void *)0);
        q ++;
        u[h] = q;
        if (h) {
          x[h] = i;
          r.b = (uch )l;
          r.e = (uch )(16U + j);
          r.v.t = q;
          j = i >> (w - l);
          *(u[h - 1] + j) = r;
        } else {

        }
      }
      r.b = (uch )(k - w);
      if ((unsigned int )p >= (unsigned int )(v + n)) {
        {
        r.e = (uch )99;
        i ++;
        }
      } else
      if (*p < s) {
        if (*p < 256U) {
          tmp___5 = 16;
        } else {
          tmp___5 = 15;
        }
        r.e = (uch )tmp___5;
        r.v.n = (ush )*p;
        p ++;
      } else {
        r.e = (uch )*(e + (*p - s));
        tmp___6 = p;
        p ++;
        r.v.n = *(d + (*tmp___6 - s));
      }
      f = (unsigned int )(1 << (k - w));
      j = i >> w;
      while (j < z) {
        *(q + j) = r;
        j += f;
      }
      j = (unsigned int )(1 << (k - 1));
      while (i & j) {
        i ^= j;
        j >>= 1;
      }
      i ^= j;
      while ((i & (unsigned int )((1 << w) - 1)) != x[h]) {
        h --;
        w -= l;
      }
    }
    k ++;
  }
  if (y != 0) {
    if (g != 1) {
      tmp___8 = 1;
    } else {
      tmp___8 = 0;
    }
  } else {
    tmp___8 = 0;
  }
  return (tmp___8);
}
}
int huft_free(struct huft *t ) 
{ 
  register struct huft *p ;
  register struct huft *q ;

  {
  p = t;
  while ((unsigned int )p != (unsigned int )((struct huft *)((void *)0))) {
    p --;
    q = p->v.t;
    free((void *)((char *)p));
    p = q;
  }
  return (0);
}
}
int inflate_codes(struct huft *tl , struct huft *td , int bl , int bd ) 
{ 
  register unsigned int e ;
  unsigned int n ;
  unsigned int d ;
  unsigned int w ;
  struct huft *t ;
  unsigned int ml ;
  unsigned int md ;
  register ulg b ;
  register unsigned int k ;
  unsigned int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  unsigned int tmp___5 ;
  unsigned int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  unsigned int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  unsigned int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  unsigned int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  unsigned int tmp___18 ;
  unsigned int tmp___19 ;
  unsigned int tmp___20 ;
  unsigned int tmp___21 ;

  {
  b = bb;
  k = bk;
  w = outcnt;
  ml = (unsigned int )mask_bits[bl];
  md = (unsigned int )mask_bits[bd];
  while (1) {
    while (k < (unsigned int )bl) {
      if (inptr < insize) {
        tmp = inptr;
        inptr ++;
        tmp___1 = (int )inbuf[tmp];
      } else {
        outcnt = w;
        tmp___0 = fill_inbuf(0);
        tmp___1 = tmp___0;
      }
      b |= (ulg )((uch )tmp___1) << k;
      k += 8U;
    }
    t = tl + ((unsigned int )b & ml);
    e = (unsigned int )t->e;
    if (e > 16U) {
      while (1) {
        if (e == 99U) {
          return (1);
        } else {

        }
        b >>= (int )t->b;
        k -= (unsigned int )t->b;
        e -= 16U;
        while (k < e) {
          if (inptr < insize) {
            tmp___2 = inptr;
            inptr ++;
            tmp___4 = (int )inbuf[tmp___2];
          } else {
            outcnt = w;
            tmp___3 = fill_inbuf(0);
            tmp___4 = tmp___3;
          }
          b |= (ulg )((uch )tmp___4) << k;
          k += 8U;
        }
        t = t->v.t + ((unsigned int )b & (unsigned int )mask_bits[e]);
        e = (unsigned int )t->e;
        if (e > 16U) {

        } else {
          break;
        }
      }
    } else {

    }
    b >>= (int )t->b;
    k -= (unsigned int )t->b;
    if (e == 16U) {
      tmp___5 = w;
      w ++;
      window[tmp___5] = (uch )t->v.n;
      if (w == 32768U) {
        outcnt = w;
        flush_window();
        w = 0U;
      } else {

      }
    } else {
      if (e == 15U) {
        break;
      } else {

      }
      while (k < e) {
        if (inptr < insize) {
          tmp___6 = inptr;
          inptr ++;
          tmp___8 = (int )inbuf[tmp___6];
        } else {
          outcnt = w;
          tmp___7 = fill_inbuf(0);
          tmp___8 = tmp___7;
        }
        b |= (ulg )((uch )tmp___8) << k;
        k += 8U;
      }
      n = (unsigned int )t->v.n + ((unsigned int )b & (unsigned int )mask_bits[e]);
      b >>= e;
      k -= e;
      while (k < (unsigned int )bd) {
        if (inptr < insize) {
          tmp___9 = inptr;
          inptr ++;
          tmp___11 = (int )inbuf[tmp___9];
        } else {
          outcnt = w;
          tmp___10 = fill_inbuf(0);
          tmp___11 = tmp___10;
        }
        b |= (ulg )((uch )tmp___11) << k;
        k += 8U;
      }
      t = td + ((unsigned int )b & md);
      e = (unsigned int )t->e;
      if (e > 16U) {
        while (1) {
          if (e == 99U) {
            return (1);
          } else {

          }
          b >>= (int )t->b;
          k -= (unsigned int )t->b;
          e -= 16U;
          while (k < e) {
            if (inptr < insize) {
              tmp___12 = inptr;
              inptr ++;
              tmp___14 = (int )inbuf[tmp___12];
            } else {
              outcnt = w;
              tmp___13 = fill_inbuf(0);
              tmp___14 = tmp___13;
            }
            b |= (ulg )((uch )tmp___14) << k;
            k += 8U;
          }
          t = t->v.t + ((unsigned int )b & (unsigned int )mask_bits[e]);
          e = (unsigned int )t->e;
          if (e > 16U) {

          } else {
            break;
          }
        }
      } else {

      }
      b >>= (int )t->b;
      k -= (unsigned int )t->b;
      while (k < e) {
        if (inptr < insize) {
          tmp___15 = inptr;
          inptr ++;
          tmp___17 = (int )inbuf[tmp___15];
        } else {
          outcnt = w;
          tmp___16 = fill_inbuf(0);
          tmp___17 = tmp___16;
        }
        b |= (ulg )((uch )tmp___17) << k;
        k += 8U;
      }
      d = (w - (unsigned int )t->v.n) - ((unsigned int )b & (unsigned int )mask_bits[e]);
      b >>= e;
      k -= e;
      while (1) {
        d &= 32767U;
        if (d > w) {
          tmp___19 = d;
        } else {
          tmp___19 = w;
        }
        e = 32768U - tmp___19;
        if (e > n) {
          e = n;
        } else {
          e = e;
        }
        n -= e;
        if (w - d >= e) {
          memcpy((void */* __restrict  */)(window + w),
                 (void const   */* __restrict  */)(window + d), e);
          w += e;
          d += e;
        } else {
          while (1) {
            tmp___20 = w;
            w ++;
            tmp___21 = d;
            d ++;
            window[tmp___20] = window[tmp___21];
            e --;
            if (e) {

            } else {
              break;
            }
          }
        }
        if (w == 32768U) {
          outcnt = w;
          flush_window();
          w = 0U;
        } else {

        }
        if (n) {

        } else {
          break;
        }
      }
    }
  }
  outcnt = w;
  bb = b;
  bk = k;
  return (0);
}
}
int inflate_stored(void) 
{ 
  unsigned int n ;
  unsigned int w ;
  register ulg b ;
  register unsigned int k ;
  unsigned int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  unsigned int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  unsigned int tmp___8 ;
  unsigned int tmp___9 ;

  {
  b = bb;
  k = bk;
  w = outcnt;
  n = k & 7U;
  b >>= n;
  k -= n;
  while (k < 16U) {
    if (inptr < insize) {
      tmp = inptr;
      inptr ++;
      tmp___1 = (int )inbuf[tmp];
    } else {
      outcnt = w;
      tmp___0 = fill_inbuf(0);
      tmp___1 = tmp___0;
    }
    b |= (ulg )((uch )tmp___1) << k;
    k += 8U;
  }
  n = (unsigned int )b & 65535U;
  b >>= 16;
  k -= 16U;
  while (k < 16U) {
    if (inptr < insize) {
      tmp___2 = inptr;
      inptr ++;
      tmp___4 = (int )inbuf[tmp___2];
    } else {
      outcnt = w;
      tmp___3 = fill_inbuf(0);
      tmp___4 = tmp___3;
    }
    b |= (ulg )((uch )tmp___4) << k;
    k += 8U;
  }
  if (n != (unsigned int )(~ b & 65535UL)) {
    return (1);
  } else {

  }
  b >>= 16;
  k -= 16U;
  while (1) {
    tmp___9 = n;
    n --;
    if (tmp___9) {

    } else {
      break;
    }
    while (k < 8U) {
      if (inptr < insize) {
        tmp___5 = inptr;
        inptr ++;
        tmp___7 = (int )inbuf[tmp___5];
      } else {
        outcnt = w;
        tmp___6 = fill_inbuf(0);
        tmp___7 = tmp___6;
      }
      b |= (ulg )((uch )tmp___7) << k;
      k += 8U;
    }
    tmp___8 = w;
    w ++;
    window[tmp___8] = (uch )b;
    if (w == 32768U) {
      outcnt = w;
      flush_window();
      w = 0U;
    } else {

    }
    b >>= 8;
    k -= 8U;
  }
  outcnt = w;
  bb = b;
  bk = k;
  return (0);
}
}
int inflate_fixed(void) 
{ 
  int i ;
  struct huft *tl ;
  struct huft *td ;
  int bl ;
  int bd ;
  unsigned int l[288] ;
  int tmp ;

  {
  i = 0;
  while (i < 144) {
    l[i] = 8U;
    i ++;
  }
  while (i < 256) {
    l[i] = 9U;
    i ++;
  }
  while (i < 280) {
    l[i] = 7U;
    i ++;
  }
  while (i < 288) {
    l[i] = 8U;
    i ++;
  }
  bl = 7;
  i = huft_build(l, 288U, 257U, cplens, cplext, & tl, & bl);
  if (i != 0) {
    return (i);
  } else {

  }
  i = 0;
  while (i < 30) {
    l[i] = 5U;
    i ++;
  }
  bd = 5;
  i = huft_build(l, 30U, 0U, cpdist, cpdext, & td, & bd);
  if (i > 1) {
    huft_free(tl);
    return (i);
  } else {

  }
  tmp = inflate_codes(tl, td, bl, bd);
  if (tmp) {
    return (1);
  } else {

  }
  huft_free(tl);
  huft_free(td);
  return (0);
}
}
int inflate_dynamic(void) 
{ 
  int i ;
  unsigned int j ;
  unsigned int l ;
  unsigned int m ;
  unsigned int n ;
  unsigned int w ;
  struct huft *tl ;
  struct huft *td ;
  int bl ;
  int bd ;
  unsigned int nb ;
  unsigned int nl ;
  unsigned int nd ;
  unsigned int ll[316] ;
  register ulg b ;
  register unsigned int k ;
  unsigned int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  unsigned int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  unsigned int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  unsigned int tmp___11 ;
  int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  unsigned int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  unsigned int tmp___19 ;
  unsigned int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  int tmp___23 ;
  unsigned int tmp___24 ;
  unsigned int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  int tmp___28 ;
  unsigned int tmp___29 ;
  int tmp___30 ;

  {
  b = bb;
  k = bk;
  w = outcnt;
  while (k < 5U) {
    if (inptr < insize) {
      tmp = inptr;
      inptr ++;
      tmp___1 = (int )inbuf[tmp];
    } else {
      outcnt = w;
      tmp___0 = fill_inbuf(0);
      tmp___1 = tmp___0;
    }
    b |= (ulg )((uch )tmp___1) << k;
    k += 8U;
  }
  nl = 257U + ((unsigned int )b & 31U);
  b >>= 5;
  k -= 5U;
  while (k < 5U) {
    if (inptr < insize) {
      tmp___2 = inptr;
      inptr ++;
      tmp___4 = (int )inbuf[tmp___2];
    } else {
      outcnt = w;
      tmp___3 = fill_inbuf(0);
      tmp___4 = tmp___3;
    }
    b |= (ulg )((uch )tmp___4) << k;
    k += 8U;
  }
  nd = 1U + ((unsigned int )b & 31U);
  b >>= 5;
  k -= 5U;
  while (k < 4U) {
    if (inptr < insize) {
      tmp___5 = inptr;
      inptr ++;
      tmp___7 = (int )inbuf[tmp___5];
    } else {
      outcnt = w;
      tmp___6 = fill_inbuf(0);
      tmp___7 = tmp___6;
    }
    b |= (ulg )((uch )tmp___7) << k;
    k += 8U;
  }
  nb = 4U + ((unsigned int )b & 15U);
  b >>= 4;
  k -= 4U;
  if (nl > 286U) {
    return (1);
  } else
  if (nd > 30U) {
    return (1);
  } else {

  }
  j = 0U;
  while (j < nb) {
    while (k < 3U) {
      if (inptr < insize) {
        tmp___8 = inptr;
        inptr ++;
        tmp___10 = (int )inbuf[tmp___8];
      } else {
        outcnt = w;
        tmp___9 = fill_inbuf(0);
        tmp___10 = tmp___9;
      }
      b |= (ulg )((uch )tmp___10) << k;
      k += 8U;
    }
    ll[border[j]] = (unsigned int )b & 7U;
    b >>= 3;
    k -= 3U;
    j ++;
  }
  while (j < 19U) {
    ll[border[j]] = 0U;
    j ++;
  }
  bl = 7;
  i = huft_build(ll, 19U, 19U, (ush *)((void *)0), (ush *)((void *)0), & tl,
                 & bl);
  if (i != 0) {
    if (i == 1) {
      huft_free(tl);
    } else {

    }
    return (i);
  } else {

  }
  if ((unsigned int )tl == (unsigned int )((void *)0)) {
    return (2);
  } else {

  }
  n = nl + nd;
  m = (unsigned int )mask_bits[bl];
  l = 0U;
  i = (int )l;
  while ((unsigned int )i < n) {
    while (k < (unsigned int )bl) {
      if (inptr < insize) {
        tmp___11 = inptr;
        inptr ++;
        tmp___13 = (int )inbuf[tmp___11];
      } else {
        outcnt = w;
        tmp___12 = fill_inbuf(0);
        tmp___13 = tmp___12;
      }
      b |= (ulg )((uch )tmp___13) << k;
      k += 8U;
    }
    td = tl + ((unsigned int )b & m);
    j = (unsigned int )td->b;
    b >>= j;
    k -= j;
    j = (unsigned int )td->v.n;
    if (j < 16U) {
      tmp___14 = i;
      i ++;
      l = j;
      ll[tmp___14] = l;
    } else
    if (j == 16U) {
      while (k < 2U) {
        if (inptr < insize) {
          tmp___15 = inptr;
          inptr ++;
          tmp___17 = (int )inbuf[tmp___15];
        } else {
          outcnt = w;
          tmp___16 = fill_inbuf(0);
          tmp___17 = tmp___16;
        }
        b |= (ulg )((uch )tmp___17) << k;
        k += 8U;
      }
      j = 3U + ((unsigned int )b & 3U);
      b >>= 2;
      k -= 2U;
      if ((unsigned int )i + j > n) {
        return (1);
      } else {

      }
      while (1) {
        tmp___19 = j;
        j --;
        if (tmp___19) {

        } else {
          break;
        }
        tmp___18 = i;
        i ++;
        ll[tmp___18] = l;
      }
    } else
    if (j == 17U) {
      while (k < 3U) {
        if (inptr < insize) {
          tmp___20 = inptr;
          inptr ++;
          tmp___22 = (int )inbuf[tmp___20];
        } else {
          outcnt = w;
          tmp___21 = fill_inbuf(0);
          tmp___22 = tmp___21;
        }
        b |= (ulg )((uch )tmp___22) << k;
        k += 8U;
      }
      j = 3U + ((unsigned int )b & 7U);
      b >>= 3;
      k -= 3U;
      if ((unsigned int )i + j > n) {
        return (1);
      } else {

      }
      while (1) {
        tmp___24 = j;
        j --;
        if (tmp___24) {

        } else {
          break;
        }
        tmp___23 = i;
        i ++;
        ll[tmp___23] = 0U;
      }
      l = 0U;
    } else {
      while (k < 7U) {
        if (inptr < insize) {
          tmp___25 = inptr;
          inptr ++;
          tmp___27 = (int )inbuf[tmp___25];
        } else {
          outcnt = w;
          tmp___26 = fill_inbuf(0);
          tmp___27 = tmp___26;
        }
        b |= (ulg )((uch )tmp___27) << k;
        k += 8U;
      }
      j = 11U + ((unsigned int )b & 127U);
      b >>= 7;
      k -= 7U;
      if ((unsigned int )i + j > n) {
        return (1);
      } else {

      }
      while (1) {
        tmp___29 = j;
        j --;
        if (tmp___29) {

        } else {
          break;
        }
        tmp___28 = i;
        i ++;
        ll[tmp___28] = 0U;
      }
      l = 0U;
    }
  }
  huft_free(tl);
  bb = b;
  bk = k;
  bl = lbits;
  i = huft_build(ll, nl, 257U, cplens, cplext, & tl, & bl);
  if (i != 0) {
    if (i == 1) {
      huft_free(tl);
    } else {

    }
    return (i);
  } else {

  }
  bd = dbits;
  i = huft_build(ll + nl, nd, 0U, cpdist, cpdext, & td, & bd);
  if (i != 0) {
    if (i == 1) {
      huft_free(td);
    } else {

    }
    huft_free(tl);
    return (i);
  } else {

  }
  tmp___30 = inflate_codes(tl, td, bl, bd);
  if (tmp___30) {
    return (1);
  } else {

  }
  huft_free(tl);
  huft_free(td);
  return (0);
}
}
int inflate_block(int *e ) 
{ 
  unsigned int t ;
  unsigned int w ;
  register ulg b ;
  register unsigned int k ;
  unsigned int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;

  {
  b = bb;
  k = bk;
  w = outcnt;
  while (k < 1U) {
    if (inptr < insize) {
      tmp = inptr;
      inptr ++;
      tmp___1 = (int )inbuf[tmp];
    } else {
      outcnt = w;
      tmp___0 = fill_inbuf(0);
      tmp___1 = tmp___0;
    }
    b |= (ulg )((uch )tmp___1) << k;
    k += 8U;
  }
  *e = (int )b & 1;
  b >>= 1;
  k --;
  while (k < 2U) {
    if (inptr < insize) {
      tmp___2 = inptr;
      inptr ++;
      tmp___4 = (int )inbuf[tmp___2];
    } else {
      outcnt = w;
      tmp___3 = fill_inbuf(0);
      tmp___4 = tmp___3;
    }
    b |= (ulg )((uch )tmp___4) << k;
    k += 8U;
  }
  t = (unsigned int )b & 3U;
  b >>= 2;
  k -= 2U;
  bb = b;
  bk = k;
  if (t == 2U) {
    tmp___5 = inflate_dynamic();
    return (tmp___5);
  } else {

  }
  if (t == 0U) {
    tmp___6 = inflate_stored();
    return (tmp___6);
  } else {

  }
  if (t == 1U) {
    tmp___7 = inflate_fixed();
    return (tmp___7);
  } else {

  }
  return (2);
}
}
int inflate(void) 
{ 
  int e ;
  int r ;
  unsigned int h ;

  {
  outcnt = 0U;
  bk = 0U;
  bb = (ulg )0;
  h = 0U;
  while (1) {
    hufts = 0U;
    r = inflate_block(& e);
    if (r != 0) {
      return (r);
    } else {

    }
    if (hufts > h) {
      h = hufts;
    } else {

    }
    if (! e) {

    } else {
      break;
    }
  }
  while (bk >= 8U) {
    bk -= 8U;
    inptr --;
  }
  outcnt = outcnt;
  flush_window();
  return (0);
}
}
