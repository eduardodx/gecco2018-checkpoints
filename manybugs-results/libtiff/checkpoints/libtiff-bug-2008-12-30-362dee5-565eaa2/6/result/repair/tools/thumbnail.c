#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
char checkpoints_buf[256];
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
typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long __ino_t;
typedef unsigned int __mode_t;
typedef long __off_t;
typedef int __pid_t;
struct __anonstruct___fsid_t_1 {
   int __val[2] ;
};
typedef long __clock_t;
typedef unsigned long __rlim_t;
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
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef char *__caddr_t;
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
struct __anonstruct__G_fpos_t_4 {
   __off_t __pos ;
   __mbstate_t __state ;
};
struct __anonstruct__G_fpos64_t_5 {
   __off64_t __pos ;
   __mbstate_t __state ;
};
typedef short _G_int16_t;
typedef int _G_int32_t;
typedef unsigned short _G_uint16_t;
typedef unsigned int _G_uint32_t;
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t;
struct _IO_jump_t;
typedef void _IO_lock_t;
struct _IO_FILE_plus;
struct _IO_FILE_plus;
typedef int __io_close_fn(void *__cookie );
typedef __gnuc_va_list va_list;
typedef long wchar_t;
struct __anonstruct___wait_terminated_6 {
   unsigned int __w_termsig : 7 ;
   unsigned int __w_coredump : 1 ;
   unsigned int __w_retcode : 8 ;
   unsigned int  : 16 ;
};
struct __anonstruct___wait_stopped_7 {
   unsigned int __w_stopval : 8 ;
   unsigned int __w_stopsig : 8 ;
   unsigned int  : 16 ;
};
union __anonunion___WAIT_STATUS_8 {
   union wait *__uptr ;
   int *__iptr ;
};
struct __anonstruct_div_t_9 {
   int quot ;
   int rem ;
};
struct __anonstruct_ldiv_t_10 {
   long quot ;
   long rem ;
};
struct __anonstruct_lldiv_t_11 {
   long long quot ;
   long long rem ;
};
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
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
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;
typedef int __sig_atomic_t;
struct __anonstruct___sigset_t_12 {
   unsigned long __val[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef __sigset_t sigset_t;
typedef __suseconds_t suseconds_t;
typedef long __fd_mask;
struct __anonstruct_fd_set_13 {
   __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef unsigned long pthread_t;
union __anonunion_pthread_attr_t_14 {
   char __size[36] ;
   long __align ;
};
union __anonunion____missing_field_name_16 {
   int __spins ;
   __pthread_slist_t __list ;
};
union __anonunion_pthread_mutex_t_15 {
   struct __pthread_mutex_s __data ;
   char __size[24] ;
   long __align ;
};
union __anonunion_pthread_mutexattr_t_17 {
   char __size[4] ;
   long __align ;
};
struct __anonstruct___data_19 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_18 {
   struct __anonstruct___data_19 __data ;
   char __size[48] ;
   long long __align ;
};
union __anonunion_pthread_condattr_t_20 {
   char __size[4] ;
   long __align ;
};
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
struct __anonstruct___data_22 {
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
union __anonunion_pthread_rwlock_t_21 {
   struct __anonstruct___data_22 __data ;
   char __size[32] ;
   long __align ;
};
union __anonunion_pthread_rwlockattr_t_23 {
   char __size[8] ;
   long __align ;
};
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_24 {
   char __size[20] ;
   long __align ;
};
union __anonunion_pthread_barrierattr_t_25 {
   char __size[4] ;
   int __align ;
};
typedef int (*__compar_fn_t)(void const   * , void const   * );
struct __locale_data;
typedef long double float_t;
typedef long double double_t;
enum __anonenum_26 {
    FP_NAN = 0,
    FP_INFINITE = 1,
    FP_ZERO = 2,
    FP_SUBNORMAL = 3,
    FP_NORMAL = 4
} ;
enum __anonenum__LIB_VERSION_TYPE_27 {
    _IEEE_ = -1,
    _SVID_ = 0,
    _XOPEN_ = 1,
    _POSIX_ = 2,
    _ISOC_ = 3
} ;
typedef enum __anonenum__LIB_VERSION_TYPE_27 _LIB_VERSION_TYPE;
struct exception {
   int type ;
   char *name ;
   double arg1 ;
   double arg2 ;
   double retval ;
};
union __anonunion___u_28 {
   float __f ;
   int __i ;
};
union __anonunion___u_29 {
   double __d ;
   int __i[2] ;
};
union __anonunion___u_30 {
   long double __l ;
   int __i[3] ;
};
union __anonunion___n_31 {
   long double __xld ;
   unsigned int __xi[3] ;
};
union __anonunion_32 {
   double __d ;
   int __i[2] ;
};
typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
enum __anonenum_33 {
    _PC_LINK_MAX = 0,
    _PC_MAX_CANON = 1,
    _PC_MAX_INPUT = 2,
    _PC_NAME_MAX = 3,
    _PC_PATH_MAX = 4,
    _PC_PIPE_BUF = 5,
    _PC_CHOWN_RESTRICTED = 6,
    _PC_NO_TRUNC = 7,
    _PC_VDISABLE = 8,
    _PC_SYNC_IO = 9,
    _PC_ASYNC_IO = 10,
    _PC_PRIO_IO = 11,
    _PC_SOCK_MAXBUF = 12,
    _PC_FILESIZEBITS = 13,
    _PC_REC_INCR_XFER_SIZE = 14,
    _PC_REC_MAX_XFER_SIZE = 15,
    _PC_REC_MIN_XFER_SIZE = 16,
    _PC_REC_XFER_ALIGN = 17,
    _PC_ALLOC_SIZE_MIN = 18,
    _PC_SYMLINK_MAX = 19,
    _PC_2_SYMLINKS = 20
} ;
enum __anonenum_34 {
    _SC_ARG_MAX = 0,
    _SC_CHILD_MAX = 1,
    _SC_CLK_TCK = 2,
    _SC_NGROUPS_MAX = 3,
    _SC_OPEN_MAX = 4,
    _SC_STREAM_MAX = 5,
    _SC_TZNAME_MAX = 6,
    _SC_JOB_CONTROL = 7,
    _SC_SAVED_IDS = 8,
    _SC_REALTIME_SIGNALS = 9,
    _SC_PRIORITY_SCHEDULING = 10,
    _SC_TIMERS = 11,
    _SC_ASYNCHRONOUS_IO = 12,
    _SC_PRIORITIZED_IO = 13,
    _SC_SYNCHRONIZED_IO = 14,
    _SC_FSYNC = 15,
    _SC_MAPPED_FILES = 16,
    _SC_MEMLOCK = 17,
    _SC_MEMLOCK_RANGE = 18,
    _SC_MEMORY_PROTECTION = 19,
    _SC_MESSAGE_PASSING = 20,
    _SC_SEMAPHORES = 21,
    _SC_SHARED_MEMORY_OBJECTS = 22,
    _SC_AIO_LISTIO_MAX = 23,
    _SC_AIO_MAX = 24,
    _SC_AIO_PRIO_DELTA_MAX = 25,
    _SC_DELAYTIMER_MAX = 26,
    _SC_MQ_OPEN_MAX = 27,
    _SC_MQ_PRIO_MAX = 28,
    _SC_VERSION = 29,
    _SC_PAGESIZE = 30,
    _SC_RTSIG_MAX = 31,
    _SC_SEM_NSEMS_MAX = 32,
    _SC_SEM_VALUE_MAX = 33,
    _SC_SIGQUEUE_MAX = 34,
    _SC_TIMER_MAX = 35,
    _SC_BC_BASE_MAX = 36,
    _SC_BC_DIM_MAX = 37,
    _SC_BC_SCALE_MAX = 38,
    _SC_BC_STRING_MAX = 39,
    _SC_COLL_WEIGHTS_MAX = 40,
    _SC_EQUIV_CLASS_MAX = 41,
    _SC_EXPR_NEST_MAX = 42,
    _SC_LINE_MAX = 43,
    _SC_RE_DUP_MAX = 44,
    _SC_CHARCLASS_NAME_MAX = 45,
    _SC_2_VERSION = 46,
    _SC_2_C_BIND = 47,
    _SC_2_C_DEV = 48,
    _SC_2_FORT_DEV = 49,
    _SC_2_FORT_RUN = 50,
    _SC_2_SW_DEV = 51,
    _SC_2_LOCALEDEF = 52,
    _SC_PII = 53,
    _SC_PII_XTI = 54,
    _SC_PII_SOCKET = 55,
    _SC_PII_INTERNET = 56,
    _SC_PII_OSI = 57,
    _SC_POLL = 58,
    _SC_SELECT = 59,
    _SC_UIO_MAXIOV = 60,
    _SC_IOV_MAX = 60,
    _SC_PII_INTERNET_STREAM = 61,
    _SC_PII_INTERNET_DGRAM = 62,
    _SC_PII_OSI_COTS = 63,
    _SC_PII_OSI_CLTS = 64,
    _SC_PII_OSI_M = 65,
    _SC_T_IOV_MAX = 66,
    _SC_THREADS = 67,
    _SC_THREAD_SAFE_FUNCTIONS = 68,
    _SC_GETGR_R_SIZE_MAX = 69,
    _SC_GETPW_R_SIZE_MAX = 70,
    _SC_LOGIN_NAME_MAX = 71,
    _SC_TTY_NAME_MAX = 72,
    _SC_THREAD_DESTRUCTOR_ITERATIONS = 73,
    _SC_THREAD_KEYS_MAX = 74,
    _SC_THREAD_STACK_MIN = 75,
    _SC_THREAD_THREADS_MAX = 76,
    _SC_THREAD_ATTR_STACKADDR = 77,
    _SC_THREAD_ATTR_STACKSIZE = 78,
    _SC_THREAD_PRIORITY_SCHEDULING = 79,
    _SC_THREAD_PRIO_INHERIT = 80,
    _SC_THREAD_PRIO_PROTECT = 81,
    _SC_THREAD_PROCESS_SHARED = 82,
    _SC_NPROCESSORS_CONF = 83,
    _SC_NPROCESSORS_ONLN = 84,
    _SC_PHYS_PAGES = 85,
    _SC_AVPHYS_PAGES = 86,
    _SC_ATEXIT_MAX = 87,
    _SC_PASS_MAX = 88,
    _SC_XOPEN_VERSION = 89,
    _SC_XOPEN_XCU_VERSION = 90,
    _SC_XOPEN_UNIX = 91,
    _SC_XOPEN_CRYPT = 92,
    _SC_XOPEN_ENH_I18N = 93,
    _SC_XOPEN_SHM = 94,
    _SC_2_CHAR_TERM = 95,
    _SC_2_C_VERSION = 96,
    _SC_2_UPE = 97,
    _SC_XOPEN_XPG2 = 98,
    _SC_XOPEN_XPG3 = 99,
    _SC_XOPEN_XPG4 = 100,
    _SC_CHAR_BIT = 101,
    _SC_CHAR_MAX = 102,
    _SC_CHAR_MIN = 103,
    _SC_INT_MAX = 104,
    _SC_INT_MIN = 105,
    _SC_LONG_BIT = 106,
    _SC_WORD_BIT = 107,
    _SC_MB_LEN_MAX = 108,
    _SC_NZERO = 109,
    _SC_SSIZE_MAX = 110,
    _SC_SCHAR_MAX = 111,
    _SC_SCHAR_MIN = 112,
    _SC_SHRT_MAX = 113,
    _SC_SHRT_MIN = 114,
    _SC_UCHAR_MAX = 115,
    _SC_UINT_MAX = 116,
    _SC_ULONG_MAX = 117,
    _SC_USHRT_MAX = 118,
    _SC_NL_ARGMAX = 119,
    _SC_NL_LANGMAX = 120,
    _SC_NL_MSGMAX = 121,
    _SC_NL_NMAX = 122,
    _SC_NL_SETMAX = 123,
    _SC_NL_TEXTMAX = 124,
    _SC_XBS5_ILP32_OFF32 = 125,
    _SC_XBS5_ILP32_OFFBIG = 126,
    _SC_XBS5_LP64_OFF64 = 127,
    _SC_XBS5_LPBIG_OFFBIG = 128,
    _SC_XOPEN_LEGACY = 129,
    _SC_XOPEN_REALTIME = 130,
    _SC_XOPEN_REALTIME_THREADS = 131,
    _SC_ADVISORY_INFO = 132,
    _SC_BARRIERS = 133,
    _SC_BASE = 134,
    _SC_C_LANG_SUPPORT = 135,
    _SC_C_LANG_SUPPORT_R = 136,
    _SC_CLOCK_SELECTION = 137,
    _SC_CPUTIME = 138,
    _SC_THREAD_CPUTIME = 139,
    _SC_DEVICE_IO = 140,
    _SC_DEVICE_SPECIFIC = 141,
    _SC_DEVICE_SPECIFIC_R = 142,
    _SC_FD_MGMT = 143,
    _SC_FIFO = 144,
    _SC_PIPE = 145,
    _SC_FILE_ATTRIBUTES = 146,
    _SC_FILE_LOCKING = 147,
    _SC_FILE_SYSTEM = 148,
    _SC_MONOTONIC_CLOCK = 149,
    _SC_MULTI_PROCESS = 150,
    _SC_SINGLE_PROCESS = 151,
    _SC_NETWORKING = 152,
    _SC_READER_WRITER_LOCKS = 153,
    _SC_SPIN_LOCKS = 154,
    _SC_REGEXP = 155,
    _SC_REGEX_VERSION = 156,
    _SC_SHELL = 157,
    _SC_SIGNALS = 158,
    _SC_SPAWN = 159,
    _SC_SPORADIC_SERVER = 160,
    _SC_THREAD_SPORADIC_SERVER = 161,
    _SC_SYSTEM_DATABASE = 162,
    _SC_SYSTEM_DATABASE_R = 163,
    _SC_TIMEOUTS = 164,
    _SC_TYPED_MEMORY_OBJECTS = 165,
    _SC_USER_GROUPS = 166,
    _SC_USER_GROUPS_R = 167,
    _SC_2_PBS = 168,
    _SC_2_PBS_ACCOUNTING = 169,
    _SC_2_PBS_LOCATE = 170,
    _SC_2_PBS_MESSAGE = 171,
    _SC_2_PBS_TRACK = 172,
    _SC_SYMLOOP_MAX = 173,
    _SC_STREAMS = 174,
    _SC_2_PBS_CHECKPOINT = 175,
    _SC_V6_ILP32_OFF32 = 176,
    _SC_V6_ILP32_OFFBIG = 177,
    _SC_V6_LP64_OFF64 = 178,
    _SC_V6_LPBIG_OFFBIG = 179,
    _SC_HOST_NAME_MAX = 180,
    _SC_TRACE = 181,
    _SC_TRACE_EVENT_FILTER = 182,
    _SC_TRACE_INHERIT = 183,
    _SC_TRACE_LOG = 184,
    _SC_LEVEL1_ICACHE_SIZE = 185,
    _SC_LEVEL1_ICACHE_ASSOC = 186,
    _SC_LEVEL1_ICACHE_LINESIZE = 187,
    _SC_LEVEL1_DCACHE_SIZE = 188,
    _SC_LEVEL1_DCACHE_ASSOC = 189,
    _SC_LEVEL1_DCACHE_LINESIZE = 190,
    _SC_LEVEL2_CACHE_SIZE = 191,
    _SC_LEVEL2_CACHE_ASSOC = 192,
    _SC_LEVEL2_CACHE_LINESIZE = 193,
    _SC_LEVEL3_CACHE_SIZE = 194,
    _SC_LEVEL3_CACHE_ASSOC = 195,
    _SC_LEVEL3_CACHE_LINESIZE = 196,
    _SC_LEVEL4_CACHE_SIZE = 197,
    _SC_LEVEL4_CACHE_ASSOC = 198,
    _SC_LEVEL4_CACHE_LINESIZE = 199,
    _SC_IPV6 = 235,
    _SC_RAW_SOCKETS = 236,
    _SC_V7_ILP32_OFF32 = 237,
    _SC_V7_ILP32_OFFBIG = 238,
    _SC_V7_LP64_OFF64 = 239,
    _SC_V7_LPBIG_OFFBIG = 240,
    _SC_SS_REPL_MAX = 241,
    _SC_TRACE_EVENT_NAME_MAX = 242,
    _SC_TRACE_NAME_MAX = 243,
    _SC_TRACE_SYS_MAX = 244,
    _SC_TRACE_USER_EVENT_MAX = 245,
    _SC_XOPEN_STREAMS = 246,
    _SC_THREAD_ROBUST_PRIO_INHERIT = 247,
    _SC_THREAD_ROBUST_PRIO_PROTECT = 248
} ;
enum __anonenum_35 {
    _CS_PATH = 0,
    _CS_V6_WIDTH_RESTRICTED_ENVS = 1,
    _CS_GNU_LIBC_VERSION = 2,
    _CS_GNU_LIBPTHREAD_VERSION = 3,
    _CS_V5_WIDTH_RESTRICTED_ENVS = 4,
    _CS_V7_WIDTH_RESTRICTED_ENVS = 5,
    _CS_LFS_CFLAGS = 1000,
    _CS_LFS_LDFLAGS = 1001,
    _CS_LFS_LIBS = 1002,
    _CS_LFS_LINTFLAGS = 1003,
    _CS_LFS64_CFLAGS = 1004,
    _CS_LFS64_LDFLAGS = 1005,
    _CS_LFS64_LIBS = 1006,
    _CS_LFS64_LINTFLAGS = 1007,
    _CS_XBS5_ILP32_OFF32_CFLAGS = 1100,
    _CS_XBS5_ILP32_OFF32_LDFLAGS = 1101,
    _CS_XBS5_ILP32_OFF32_LIBS = 1102,
    _CS_XBS5_ILP32_OFF32_LINTFLAGS = 1103,
    _CS_XBS5_ILP32_OFFBIG_CFLAGS = 1104,
    _CS_XBS5_ILP32_OFFBIG_LDFLAGS = 1105,
    _CS_XBS5_ILP32_OFFBIG_LIBS = 1106,
    _CS_XBS5_ILP32_OFFBIG_LINTFLAGS = 1107,
    _CS_XBS5_LP64_OFF64_CFLAGS = 1108,
    _CS_XBS5_LP64_OFF64_LDFLAGS = 1109,
    _CS_XBS5_LP64_OFF64_LIBS = 1110,
    _CS_XBS5_LP64_OFF64_LINTFLAGS = 1111,
    _CS_XBS5_LPBIG_OFFBIG_CFLAGS = 1112,
    _CS_XBS5_LPBIG_OFFBIG_LDFLAGS = 1113,
    _CS_XBS5_LPBIG_OFFBIG_LIBS = 1114,
    _CS_XBS5_LPBIG_OFFBIG_LINTFLAGS = 1115,
    _CS_POSIX_V6_ILP32_OFF32_CFLAGS = 1116,
    _CS_POSIX_V6_ILP32_OFF32_LDFLAGS = 1117,
    _CS_POSIX_V6_ILP32_OFF32_LIBS = 1118,
    _CS_POSIX_V6_ILP32_OFF32_LINTFLAGS = 1119,
    _CS_POSIX_V6_ILP32_OFFBIG_CFLAGS = 1120,
    _CS_POSIX_V6_ILP32_OFFBIG_LDFLAGS = 1121,
    _CS_POSIX_V6_ILP32_OFFBIG_LIBS = 1122,
    _CS_POSIX_V6_ILP32_OFFBIG_LINTFLAGS = 1123,
    _CS_POSIX_V6_LP64_OFF64_CFLAGS = 1124,
    _CS_POSIX_V6_LP64_OFF64_LDFLAGS = 1125,
    _CS_POSIX_V6_LP64_OFF64_LIBS = 1126,
    _CS_POSIX_V6_LP64_OFF64_LINTFLAGS = 1127,
    _CS_POSIX_V6_LPBIG_OFFBIG_CFLAGS = 1128,
    _CS_POSIX_V6_LPBIG_OFFBIG_LDFLAGS = 1129,
    _CS_POSIX_V6_LPBIG_OFFBIG_LIBS = 1130,
    _CS_POSIX_V6_LPBIG_OFFBIG_LINTFLAGS = 1131,
    _CS_POSIX_V7_ILP32_OFF32_CFLAGS = 1132,
    _CS_POSIX_V7_ILP32_OFF32_LDFLAGS = 1133,
    _CS_POSIX_V7_ILP32_OFF32_LIBS = 1134,
    _CS_POSIX_V7_ILP32_OFF32_LINTFLAGS = 1135,
    _CS_POSIX_V7_ILP32_OFFBIG_CFLAGS = 1136,
    _CS_POSIX_V7_ILP32_OFFBIG_LDFLAGS = 1137,
    _CS_POSIX_V7_ILP32_OFFBIG_LIBS = 1138,
    _CS_POSIX_V7_ILP32_OFFBIG_LINTFLAGS = 1139,
    _CS_POSIX_V7_LP64_OFF64_CFLAGS = 1140,
    _CS_POSIX_V7_LP64_OFF64_LDFLAGS = 1141,
    _CS_POSIX_V7_LP64_OFF64_LIBS = 1142,
    _CS_POSIX_V7_LP64_OFF64_LINTFLAGS = 1143,
    _CS_POSIX_V7_LPBIG_OFFBIG_CFLAGS = 1144,
    _CS_POSIX_V7_LPBIG_OFFBIG_LDFLAGS = 1145,
    _CS_POSIX_V7_LPBIG_OFFBIG_LIBS = 1146,
    _CS_POSIX_V7_LPBIG_OFFBIG_LINTFLAGS = 1147,
    _CS_V6_ENV = 1148,
    _CS_V7_ENV = 1149
} ;
typedef signed char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef int uint16_vap;
struct __anonstruct_TIFFHeaderCommon_36 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
};
typedef struct __anonstruct_TIFFHeaderCommon_36 TIFFHeaderCommon;
struct __anonstruct_TIFFHeaderClassic_37 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint32 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderClassic_37 TIFFHeaderClassic;
struct __anonstruct_TIFFHeaderBig_38 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint16 tiff_offsetsize ;
   uint16 tiff_unused ;
   uint64 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderBig_38 TIFFHeaderBig;
enum __anonenum_TIFFDataType_39 {
    TIFF_NOTYPE = 0,
    TIFF_BYTE = 1,
    TIFF_ASCII = 2,
    TIFF_SHORT = 3,
    TIFF_LONG = 4,
    TIFF_RATIONAL = 5,
    TIFF_SBYTE = 6,
    TIFF_UNDEFINED = 7,
    TIFF_SSHORT = 8,
    TIFF_SLONG = 9,
    TIFF_SRATIONAL = 10,
    TIFF_FLOAT = 11,
    TIFF_DOUBLE = 12,
    TIFF_IFD = 13,
    TIFF_LONG8 = 16,
    TIFF_SLONG8 = 17,
    TIFF_IFD8 = 18
} ;
typedef enum __anonenum_TIFFDataType_39 TIFFDataType;
struct tiff;
typedef struct tiff TIFF;
typedef long tmsize_t;
typedef uint64 toff_t;
typedef uint32 ttag_t;
typedef uint16 tdir_t;
typedef uint16 tsample_t;
typedef uint32 tstrile_t;
typedef tstrile_t tstrip_t;
typedef tstrile_t ttile_t;
typedef tmsize_t tsize_t;
typedef void *tdata_t;
typedef void *thandle_t;
typedef unsigned char TIFFRGBValue;
struct __anonstruct_TIFFDisplay_40 {
   float d_mat[3][3] ;
   float d_YCR ;
   float d_YCG ;
   float d_YCB ;
   uint32 d_Vrwr ;
   uint32 d_Vrwg ;
   uint32 d_Vrwb ;
   float d_Y0R ;
   float d_Y0G ;
   float d_Y0B ;
   float d_gammaR ;
   float d_gammaG ;
   float d_gammaB ;
};
typedef struct __anonstruct_TIFFDisplay_40 TIFFDisplay;
struct __anonstruct_TIFFYCbCrToRGB_41 {
   TIFFRGBValue *clamptab ;
   int *Cr_r_tab ;
   int *Cb_b_tab ;
   int32 *Cr_g_tab ;
   int32 *Cb_g_tab ;
   int32 *Y_tab ;
};
typedef struct __anonstruct_TIFFYCbCrToRGB_41 TIFFYCbCrToRGB;
struct __anonstruct_TIFFCIELabToRGB_42 {
   int range ;
   float rstep ;
   float gstep ;
   float bstep ;
   float X0 ;
   float Y0 ;
   float Z0 ;
   TIFFDisplay display ;
   float Yr2r[1501] ;
   float Yg2g[1501] ;
   float Yb2b[1501] ;
};
typedef struct __anonstruct_TIFFCIELabToRGB_42 TIFFCIELabToRGB;
struct _TIFFRGBAImage;
typedef struct _TIFFRGBAImage TIFFRGBAImage;
typedef void (*tileContigRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                  uint32  , uint32  , uint32  , int32  ,
                                  int32  , unsigned char * );
typedef void (*tileSeparateRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                    uint32  , uint32  , uint32  , int32  ,
                                    int32  , unsigned char * , unsigned char * ,
                                    unsigned char * , unsigned char * );
union __anonunion_put_43 {
   void (*any)(TIFFRGBAImage * ) ;
   void (*contig)(TIFFRGBAImage * , uint32 * , uint32  , uint32  , uint32  ,
                  uint32  , int32  , int32  , unsigned char * ) ;
   void (*separate)(TIFFRGBAImage * , uint32 * , uint32  , uint32  , uint32  ,
                    uint32  , int32  , int32  , unsigned char * ,
                    unsigned char * , unsigned char * , unsigned char * ) ;
};
struct _TIFFRGBAImage {
   TIFF *tif ;
   int stoponerr ;
   int isContig ;
   int alpha ;
   uint32 width ;
   uint32 height ;
   uint16 bitspersample ;
   uint16 samplesperpixel ;
   uint16 orientation ;
   uint16 req_orientation ;
   uint16 photometric ;
   uint16 *redcmap ;
   uint16 *greencmap ;
   uint16 *bluecmap ;
   int (*get)(TIFFRGBAImage * , uint32 * , uint32  , uint32  ) ;
   union __anonunion_put_43 put ;
   TIFFRGBValue *Map ;
   uint32 **BWmap ;
   uint32 **PALmap ;
   TIFFYCbCrToRGB *ycbcr ;
   TIFFCIELabToRGB *cielab ;
   uint8 *UaToAa ;
   uint8 *Bitdepth16To8 ;
   int row_offset ;
   int col_offset ;
};
typedef int (*TIFFInitMethod)(TIFF * , int  );
struct __anonstruct_TIFFCodec_44 {
   char *name ;
   uint16 scheme ;
   int (*init)(TIFF * , int  ) ;
};
typedef struct __anonstruct_TIFFCodec_44 TIFFCodec;
typedef void (*TIFFErrorHandler)(char const   * , char const   * , va_list  );
typedef void (*TIFFErrorHandlerExt)(thandle_t  , char const   * ,
                                    char const   * , va_list  );
typedef tmsize_t (*TIFFReadWriteProc)(thandle_t  , void * , tmsize_t  );
typedef toff_t (*TIFFSeekProc)(thandle_t  , toff_t  , int  );
typedef int (*TIFFCloseProc)(thandle_t  );
typedef toff_t (*TIFFSizeProc)(thandle_t  );
typedef int (*TIFFMapFileProc)(thandle_t  , void **base , toff_t *size );
typedef void (*TIFFUnmapFileProc)(thandle_t  , void *base , toff_t size );
typedef void (*TIFFExtendProc)(TIFF * );
struct _TIFFField;
typedef struct _TIFFField TIFFField;
struct _TIFFFieldArray;
typedef struct _TIFFFieldArray TIFFFieldArray;
typedef int (*TIFFVSetMethod)(TIFF * , uint32  , va_list  );
typedef int (*TIFFVGetMethod)(TIFF * , uint32  , va_list  );
typedef void (*TIFFPrintMethod)(TIFF * , FILE * , long  );
struct __anonstruct_TIFFTagMethods_45 {
   int (*vsetfield)(TIFF * , uint32  , va_list  ) ;
   int (*vgetfield)(TIFF * , uint32  , va_list  ) ;
   void (*printdir)(TIFF * , FILE * , long  ) ;
};
typedef struct __anonstruct_TIFFTagMethods_45 TIFFTagMethods;
struct __anonstruct_TIFFFieldInfo_46 {
   ttag_t field_tag ;
   short field_readcount ;
   short field_writecount ;
   TIFFDataType field_type ;
   unsigned short field_bit ;
   unsigned char field_oktochange ;
   unsigned char field_passcount ;
   char *field_name ;
};
typedef struct __anonstruct_TIFFFieldInfo_46 TIFFFieldInfo;
enum __anonenum_Contrast_47 {
    EXP50 = 0,
    EXP60 = 1,
    EXP70 = 2,
    EXP80 = 3,
    EXP90 = 4,
    EXP = 5,
    LINEAR = 6
} ;
typedef enum __anonenum_Contrast_47 Contrast;
struct cpTag {
   uint16 tag ;
   uint16 count ;
   TIFFDataType type ;
};
extern struct _IO_FILE_plus _IO_2_1_stdin_ ;
extern struct _IO_FILE_plus _IO_2_1_stdout_ ;
extern struct _IO_FILE_plus _IO_2_1_stderr_ ;
extern  __attribute__((__nothrow__)) void _IO_flockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) void _IO_funlockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) int _IO_ftrylockfile(_IO_FILE * ) ;
extern int sys_nerr ;
extern char const   * const  sys_errlist[] ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) a64l)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *alloca(size_t __size ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2,3))) __strtok_r)(char * __restrict  __s ,
                                                                                           char const   * __restrict  __delim ,
                                                                                           char ** __restrict  __save_ptr ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) index)(char const   *__s ,
                                                                                    int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) rindex)(char const   *__s ,
                                                                                     int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strcasecmp)(char const   *__s1 ,
                                                                                         char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) __stpcpy)(char * __restrict  __dest ,
                                                                                         char const   * __restrict  __src ) ;
extern char *__strsep_g(char **__stringp , char const   *__delim ) ;
extern  __attribute__((__nothrow__)) double acos(double __x ) ;
extern  __attribute__((__nothrow__)) double __acos(double __x ) ;
extern  __attribute__((__nothrow__)) double asin(double __x ) ;
extern  __attribute__((__nothrow__)) double __asin(double __x ) ;
extern  __attribute__((__nothrow__)) double atan(double __x ) ;
extern  __attribute__((__nothrow__)) double __atan(double __x ) ;
extern  __attribute__((__nothrow__)) double atan2(double __y , double __x ) ;
extern  __attribute__((__nothrow__)) double __atan2(double __y , double __x ) ;
extern  __attribute__((__nothrow__)) double cos(double __x ) ;
extern  __attribute__((__nothrow__)) double __cos(double __x ) ;
extern  __attribute__((__nothrow__)) double sin(double __x ) ;
extern  __attribute__((__nothrow__)) double __sin(double __x ) ;
extern  __attribute__((__nothrow__)) double tan(double __x ) ;
extern  __attribute__((__nothrow__)) double __tan(double __x ) ;
extern  __attribute__((__nothrow__)) double cosh(double __x ) ;
extern  __attribute__((__nothrow__)) double __cosh(double __x ) ;
extern  __attribute__((__nothrow__)) double sinh(double __x ) ;
extern  __attribute__((__nothrow__)) double __sinh(double __x ) ;
extern  __attribute__((__nothrow__)) double tanh(double __x ) ;
extern  __attribute__((__nothrow__)) double __tanh(double __x ) ;
extern  __attribute__((__nothrow__)) double acosh(double __x ) ;
extern  __attribute__((__nothrow__)) double __acosh(double __x ) ;
extern  __attribute__((__nothrow__)) double asinh(double __x ) ;
extern  __attribute__((__nothrow__)) double __asinh(double __x ) ;
extern  __attribute__((__nothrow__)) double atanh(double __x ) ;
extern  __attribute__((__nothrow__)) double __atanh(double __x ) ;
extern  __attribute__((__nothrow__)) double exp(double __x ) ;
extern  __attribute__((__nothrow__)) double __exp(double __x ) ;
extern  __attribute__((__nothrow__)) double frexp(double __x , int *__exponent ) ;
extern  __attribute__((__nothrow__)) double __frexp(double __x ,
                                                    int *__exponent ) ;
extern  __attribute__((__nothrow__)) double ldexp(double __x , int __exponent ) ;
extern  __attribute__((__nothrow__)) double __ldexp(double __x , int __exponent ) ;
extern  __attribute__((__nothrow__)) double log(double __x ) ;
extern  __attribute__((__nothrow__)) double __log(double __x ) ;
extern  __attribute__((__nothrow__)) double log10(double __x ) ;
extern  __attribute__((__nothrow__)) double __log10(double __x ) ;
extern  __attribute__((__nothrow__)) double modf(double __x , double *__iptr ) ;
extern  __attribute__((__nothrow__)) double __modf(double __x , double *__iptr ) ;
extern  __attribute__((__nothrow__)) double expm1(double __x ) ;
extern  __attribute__((__nothrow__)) double __expm1(double __x ) ;
extern  __attribute__((__nothrow__)) double log1p(double __x ) ;
extern  __attribute__((__nothrow__)) double __log1p(double __x ) ;
extern  __attribute__((__nothrow__)) double logb(double __x ) ;
extern  __attribute__((__nothrow__)) double __logb(double __x ) ;
extern  __attribute__((__nothrow__)) double exp2(double __x ) ;
extern  __attribute__((__nothrow__)) double __exp2(double __x ) ;
extern  __attribute__((__nothrow__)) double log2(double __x ) ;
extern  __attribute__((__nothrow__)) double __log2(double __x ) ;
extern  __attribute__((__nothrow__)) double pow(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __pow(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double sqrt(double __x ) ;
extern  __attribute__((__nothrow__)) double __sqrt(double __x ) ;
extern  __attribute__((__nothrow__)) double hypot(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __hypot(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double cbrt(double __x ) ;
extern  __attribute__((__nothrow__)) double __cbrt(double __x ) ;
__inline extern  __attribute__((__nothrow__)) double ceil(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __ceil(double __x )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) double fabs(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __fabs(double __x )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) double floor(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __floor(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double fmod(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __fmod(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) int __isinf(double __value )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) int __finite(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int isinf(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int finite(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double drem(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __drem(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double significand(double __x ) ;
extern  __attribute__((__nothrow__)) double __significand(double __x ) ;
extern  __attribute__((__nothrow__)) double copysign(double __x , double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __copysign(double __x , double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double nan(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __nan(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int __isnan(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int isnan(double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double j0(double  ) ;
extern  __attribute__((__nothrow__)) double __j0(double  ) ;
extern  __attribute__((__nothrow__)) double j1(double  ) ;
extern  __attribute__((__nothrow__)) double __j1(double  ) ;
extern  __attribute__((__nothrow__)) double jn(int  , double  ) ;
extern  __attribute__((__nothrow__)) double __jn(int  , double  ) ;
extern  __attribute__((__nothrow__)) double y0(double  ) ;
extern  __attribute__((__nothrow__)) double __y0(double  ) ;
extern  __attribute__((__nothrow__)) double y1(double  ) ;
extern  __attribute__((__nothrow__)) double __y1(double  ) ;
extern  __attribute__((__nothrow__)) double yn(int  , double  ) ;
extern  __attribute__((__nothrow__)) double __yn(int  , double  ) ;
extern  __attribute__((__nothrow__)) double erf(double  ) ;
extern  __attribute__((__nothrow__)) double __erf(double  ) ;
extern  __attribute__((__nothrow__)) double erfc(double  ) ;
extern  __attribute__((__nothrow__)) double __erfc(double  ) ;
extern  __attribute__((__nothrow__)) double lgamma(double  ) ;
extern  __attribute__((__nothrow__)) double __lgamma(double  ) ;
extern  __attribute__((__nothrow__)) double tgamma(double  ) ;
extern  __attribute__((__nothrow__)) double __tgamma(double  ) ;
extern  __attribute__((__nothrow__)) double gamma(double  ) ;
extern  __attribute__((__nothrow__)) double __gamma(double  ) ;
extern  __attribute__((__nothrow__)) double lgamma_r(double  , int *__signgamp ) ;
extern  __attribute__((__nothrow__)) double __lgamma_r(double  ,
                                                       int *__signgamp ) ;
extern  __attribute__((__nothrow__)) double rint(double __x ) ;
extern  __attribute__((__nothrow__)) double __rint(double __x ) ;
extern  __attribute__((__nothrow__)) double nextafter(double __x , double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __nextafter(double __x , double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double nexttoward(double __x ,
                                                       long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __nexttoward(double __x ,
                                                         long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double remainder(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __remainder(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double scalbn(double __x , int __n ) ;
extern  __attribute__((__nothrow__)) double __scalbn(double __x , int __n ) ;
extern  __attribute__((__nothrow__)) int ilogb(double __x ) ;
extern  __attribute__((__nothrow__)) int __ilogb(double __x ) ;
extern  __attribute__((__nothrow__)) double scalbln(double __x , long __n ) ;
extern  __attribute__((__nothrow__)) double __scalbln(double __x , long __n ) ;
extern  __attribute__((__nothrow__)) double nearbyint(double __x ) ;
extern  __attribute__((__nothrow__)) double __nearbyint(double __x ) ;
extern  __attribute__((__nothrow__)) double round(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __round(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double trunc(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double __trunc(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double remquo(double __x , double __y ,
                                                   int *__quo ) ;
extern  __attribute__((__nothrow__)) double __remquo(double __x , double __y ,
                                                     int *__quo ) ;
__inline extern  __attribute__((__nothrow__)) long lrint(double __x ) ;
extern  __attribute__((__nothrow__)) long __lrint(double __x ) ;
__inline extern  __attribute__((__nothrow__)) long long llrint(double __x ) ;
extern  __attribute__((__nothrow__)) long long __llrint(double __x ) ;
extern  __attribute__((__nothrow__)) long lround(double __x ) ;
extern  __attribute__((__nothrow__)) long __lround(double __x ) ;
extern  __attribute__((__nothrow__)) long long llround(double __x ) ;
extern  __attribute__((__nothrow__)) long long __llround(double __x ) ;
extern  __attribute__((__nothrow__)) double fdim(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __fdim(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double fmax(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __fmax(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double fmin(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) double __fmin(double __x , double __y ) ;
extern  __attribute__((__nothrow__)) int __fpclassify(double __value )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) int __signbit(double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) double fma(double __x , double __y ,
                                                double __z ) ;
extern  __attribute__((__nothrow__)) double __fma(double __x , double __y ,
                                                  double __z ) ;
extern  __attribute__((__nothrow__)) double scalb(double __x , double __n ) ;
extern  __attribute__((__nothrow__)) double __scalb(double __x , double __n ) ;
extern  __attribute__((__nothrow__)) float acosf(float __x ) ;
extern  __attribute__((__nothrow__)) float __acosf(float __x ) ;
extern  __attribute__((__nothrow__)) float asinf(float __x ) ;
extern  __attribute__((__nothrow__)) float __asinf(float __x ) ;
extern  __attribute__((__nothrow__)) float atanf(float __x ) ;
extern  __attribute__((__nothrow__)) float __atanf(float __x ) ;
extern  __attribute__((__nothrow__)) float atan2f(float __y , float __x ) ;
extern  __attribute__((__nothrow__)) float __atan2f(float __y , float __x ) ;
extern  __attribute__((__nothrow__)) float cosf(float __x ) ;
extern  __attribute__((__nothrow__)) float __cosf(float __x ) ;
extern  __attribute__((__nothrow__)) float sinf(float __x ) ;
extern  __attribute__((__nothrow__)) float __sinf(float __x ) ;
extern  __attribute__((__nothrow__)) float tanf(float __x ) ;
extern  __attribute__((__nothrow__)) float __tanf(float __x ) ;
extern  __attribute__((__nothrow__)) float coshf(float __x ) ;
extern  __attribute__((__nothrow__)) float __coshf(float __x ) ;
extern  __attribute__((__nothrow__)) float sinhf(float __x ) ;
extern  __attribute__((__nothrow__)) float __sinhf(float __x ) ;
extern  __attribute__((__nothrow__)) float tanhf(float __x ) ;
extern  __attribute__((__nothrow__)) float __tanhf(float __x ) ;
extern  __attribute__((__nothrow__)) float acoshf(float __x ) ;
extern  __attribute__((__nothrow__)) float __acoshf(float __x ) ;
extern  __attribute__((__nothrow__)) float asinhf(float __x ) ;
extern  __attribute__((__nothrow__)) float __asinhf(float __x ) ;
extern  __attribute__((__nothrow__)) float atanhf(float __x ) ;
extern  __attribute__((__nothrow__)) float __atanhf(float __x ) ;
extern  __attribute__((__nothrow__)) float expf(float __x ) ;
extern  __attribute__((__nothrow__)) float __expf(float __x ) ;
extern  __attribute__((__nothrow__)) float frexpf(float __x , int *__exponent ) ;
extern  __attribute__((__nothrow__)) float __frexpf(float __x , int *__exponent ) ;
extern  __attribute__((__nothrow__)) float ldexpf(float __x , int __exponent ) ;
extern  __attribute__((__nothrow__)) float __ldexpf(float __x , int __exponent ) ;
extern  __attribute__((__nothrow__)) float logf(float __x ) ;
extern  __attribute__((__nothrow__)) float __logf(float __x ) ;
extern  __attribute__((__nothrow__)) float log10f(float __x ) ;
extern  __attribute__((__nothrow__)) float __log10f(float __x ) ;
extern  __attribute__((__nothrow__)) float modff(float __x , float *__iptr ) ;
extern  __attribute__((__nothrow__)) float __modff(float __x , float *__iptr ) ;
extern  __attribute__((__nothrow__)) float expm1f(float __x ) ;
extern  __attribute__((__nothrow__)) float __expm1f(float __x ) ;
extern  __attribute__((__nothrow__)) float log1pf(float __x ) ;
extern  __attribute__((__nothrow__)) float __log1pf(float __x ) ;
extern  __attribute__((__nothrow__)) float logbf(float __x ) ;
extern  __attribute__((__nothrow__)) float __logbf(float __x ) ;
extern  __attribute__((__nothrow__)) float exp2f(float __x ) ;
extern  __attribute__((__nothrow__)) float __exp2f(float __x ) ;
extern  __attribute__((__nothrow__)) float log2f(float __x ) ;
extern  __attribute__((__nothrow__)) float __log2f(float __x ) ;
extern  __attribute__((__nothrow__)) float powf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __powf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float sqrtf(float __x ) ;
extern  __attribute__((__nothrow__)) float __sqrtf(float __x ) ;
extern  __attribute__((__nothrow__)) float hypotf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __hypotf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float cbrtf(float __x ) ;
extern  __attribute__((__nothrow__)) float __cbrtf(float __x ) ;
__inline extern  __attribute__((__nothrow__)) float ceilf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __ceilf(float __x )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) float fabsf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __fabsf(float __x )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) float floorf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __floorf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float fmodf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __fmodf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) int __isinff(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int __finitef(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int isinff(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int finitef(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float dremf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __dremf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float significandf(float __x ) ;
extern  __attribute__((__nothrow__)) float __significandf(float __x ) ;
extern  __attribute__((__nothrow__)) float copysignf(float __x , float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __copysignf(float __x , float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float nanf(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __nanf(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int __isnanf(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int isnanf(float __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float j0f(float  ) ;
extern  __attribute__((__nothrow__)) float __j0f(float  ) ;
extern  __attribute__((__nothrow__)) float j1f(float  ) ;
extern  __attribute__((__nothrow__)) float __j1f(float  ) ;
extern  __attribute__((__nothrow__)) float jnf(int  , float  ) ;
extern  __attribute__((__nothrow__)) float __jnf(int  , float  ) ;
extern  __attribute__((__nothrow__)) float y0f(float  ) ;
extern  __attribute__((__nothrow__)) float __y0f(float  ) ;
extern  __attribute__((__nothrow__)) float y1f(float  ) ;
extern  __attribute__((__nothrow__)) float __y1f(float  ) ;
extern  __attribute__((__nothrow__)) float ynf(int  , float  ) ;
extern  __attribute__((__nothrow__)) float __ynf(int  , float  ) ;
extern  __attribute__((__nothrow__)) float erff(float  ) ;
extern  __attribute__((__nothrow__)) float __erff(float  ) ;
extern  __attribute__((__nothrow__)) float erfcf(float  ) ;
extern  __attribute__((__nothrow__)) float __erfcf(float  ) ;
extern  __attribute__((__nothrow__)) float lgammaf(float  ) ;
extern  __attribute__((__nothrow__)) float __lgammaf(float  ) ;
extern  __attribute__((__nothrow__)) float tgammaf(float  ) ;
extern  __attribute__((__nothrow__)) float __tgammaf(float  ) ;
extern  __attribute__((__nothrow__)) float gammaf(float  ) ;
extern  __attribute__((__nothrow__)) float __gammaf(float  ) ;
extern  __attribute__((__nothrow__)) float lgammaf_r(float  , int *__signgamp ) ;
extern  __attribute__((__nothrow__)) float __lgammaf_r(float  , int *__signgamp ) ;
extern  __attribute__((__nothrow__)) float rintf(float __x ) ;
extern  __attribute__((__nothrow__)) float __rintf(float __x ) ;
extern  __attribute__((__nothrow__)) float nextafterf(float __x , float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __nextafterf(float __x , float __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float nexttowardf(float __x ,
                                                       long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __nexttowardf(float __x ,
                                                         long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float remainderf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __remainderf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float scalbnf(float __x , int __n ) ;
extern  __attribute__((__nothrow__)) float __scalbnf(float __x , int __n ) ;
extern  __attribute__((__nothrow__)) int ilogbf(float __x ) ;
extern  __attribute__((__nothrow__)) int __ilogbf(float __x ) ;
extern  __attribute__((__nothrow__)) float scalblnf(float __x , long __n ) ;
extern  __attribute__((__nothrow__)) float __scalblnf(float __x , long __n ) ;
extern  __attribute__((__nothrow__)) float nearbyintf(float __x ) ;
extern  __attribute__((__nothrow__)) float __nearbyintf(float __x ) ;
extern  __attribute__((__nothrow__)) float roundf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __roundf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float truncf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float __truncf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float remquof(float __x , float __y ,
                                                   int *__quo ) ;
extern  __attribute__((__nothrow__)) float __remquof(float __x , float __y ,
                                                     int *__quo ) ;
__inline extern  __attribute__((__nothrow__)) long lrintf(float __x ) ;
extern  __attribute__((__nothrow__)) long __lrintf(float __x ) ;
__inline extern  __attribute__((__nothrow__)) long long llrintf(float __x ) ;
extern  __attribute__((__nothrow__)) long long __llrintf(float __x ) ;
extern  __attribute__((__nothrow__)) long lroundf(float __x ) ;
extern  __attribute__((__nothrow__)) long __lroundf(float __x ) ;
extern  __attribute__((__nothrow__)) long long llroundf(float __x ) ;
extern  __attribute__((__nothrow__)) long long __llroundf(float __x ) ;
extern  __attribute__((__nothrow__)) float fdimf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __fdimf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float fmaxf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __fmaxf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float fminf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) float __fminf(float __x , float __y ) ;
extern  __attribute__((__nothrow__)) int __fpclassifyf(float __value )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) int __signbitf(float __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) float fmaf(float __x , float __y ,
                                                float __z ) ;
extern  __attribute__((__nothrow__)) float __fmaf(float __x , float __y ,
                                                  float __z ) ;
extern  __attribute__((__nothrow__)) float scalbf(float __x , float __n ) ;
extern  __attribute__((__nothrow__)) float __scalbf(float __x , float __n ) ;
extern  __attribute__((__nothrow__)) long double acosl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __acosl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double asinl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __asinl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double atanl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __atanl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double atan2l(long double __y ,
                                                        long double __x ) ;
__inline extern  __attribute__((__nothrow__)) long double __atan2l(long double __y ,
                                                                   long double __x ) ;
extern  __attribute__((__nothrow__)) long double cosl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __cosl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double sinl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __sinl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double tanl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __tanl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double coshl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __coshl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double sinhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __sinhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double tanhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __tanhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double acoshl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __acoshl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double asinhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __asinhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double atanhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __atanhl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double expl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __expl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double frexpl(long double __x ,
                                                        int *__exponent ) ;
extern  __attribute__((__nothrow__)) long double __frexpl(long double __x ,
                                                          int *__exponent ) ;
extern  __attribute__((__nothrow__)) long double ldexpl(long double __x ,
                                                        int __exponent ) ;
extern  __attribute__((__nothrow__)) long double __ldexpl(long double __x ,
                                                          int __exponent ) ;
extern  __attribute__((__nothrow__)) long double logl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __logl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double log10l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __log10l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double modfl(long double __x ,
                                                       long double *__iptr ) ;
extern  __attribute__((__nothrow__)) long double __modfl(long double __x ,
                                                         long double *__iptr ) ;
extern  __attribute__((__nothrow__)) long double expm1l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __expm1l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double log1pl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __log1pl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double logbl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __logbl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double exp2l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __exp2l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double log2l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __log2l(long double __x ) ;
extern  __attribute__((__nothrow__)) long double powl(long double __x ,
                                                      long double __y ) ;
extern  __attribute__((__nothrow__)) long double __powl(long double __x ,
                                                        long double __y ) ;
extern  __attribute__((__nothrow__)) long double sqrtl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __sqrtl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double hypotl(long double __x ,
                                                        long double __y ) ;
extern  __attribute__((__nothrow__)) long double __hypotl(long double __x ,
                                                          long double __y ) ;
extern  __attribute__((__nothrow__)) long double cbrtl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __cbrtl(long double __x ) ;
__inline extern  __attribute__((__nothrow__)) long double ceill(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __ceill(long double __x )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) long double fabsl(long double __x )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) long double __fabsl(long double __x )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) long double floorl(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __floorl(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double fmodl(long double __x ,
                                                       long double __y ) ;
extern  __attribute__((__nothrow__)) long double __fmodl(long double __x ,
                                                         long double __y ) ;
extern  __attribute__((__nothrow__)) int __isinfl(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int __finitel(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int isinfl(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int finitel(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double dreml(long double __x ,
                                                       long double __y ) ;
extern  __attribute__((__nothrow__)) long double __dreml(long double __x ,
                                                         long double __y ) ;
extern  __attribute__((__nothrow__)) long double significandl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __significandl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double copysignl(long double __x ,
                                                           long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __copysignl(long double __x ,
                                                             long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double nanl(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __nanl(char const   *__tagb )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int __isnanl(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int isnanl(long double __value )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double j0l(long double  ) ;
extern  __attribute__((__nothrow__)) long double __j0l(long double  ) ;
extern  __attribute__((__nothrow__)) long double j1l(long double  ) ;
extern  __attribute__((__nothrow__)) long double __j1l(long double  ) ;
extern  __attribute__((__nothrow__)) long double jnl(int  , long double  ) ;
extern  __attribute__((__nothrow__)) long double __jnl(int  , long double  ) ;
extern  __attribute__((__nothrow__)) long double y0l(long double  ) ;
extern  __attribute__((__nothrow__)) long double __y0l(long double  ) ;
extern  __attribute__((__nothrow__)) long double y1l(long double  ) ;
extern  __attribute__((__nothrow__)) long double __y1l(long double  ) ;
extern  __attribute__((__nothrow__)) long double ynl(int  , long double  ) ;
extern  __attribute__((__nothrow__)) long double __ynl(int  , long double  ) ;
extern  __attribute__((__nothrow__)) long double erfl(long double  ) ;
extern  __attribute__((__nothrow__)) long double __erfl(long double  ) ;
extern  __attribute__((__nothrow__)) long double erfcl(long double  ) ;
extern  __attribute__((__nothrow__)) long double __erfcl(long double  ) ;
extern  __attribute__((__nothrow__)) long double lgammal(long double  ) ;
extern  __attribute__((__nothrow__)) long double __lgammal(long double  ) ;
extern  __attribute__((__nothrow__)) long double tgammal(long double  ) ;
extern  __attribute__((__nothrow__)) long double __tgammal(long double  ) ;
extern  __attribute__((__nothrow__)) long double gammal(long double  ) ;
extern  __attribute__((__nothrow__)) long double __gammal(long double  ) ;
extern  __attribute__((__nothrow__)) long double lgammal_r(long double  ,
                                                           int *__signgamp ) ;
extern  __attribute__((__nothrow__)) long double __lgammal_r(long double  ,
                                                             int *__signgamp ) ;
extern  __attribute__((__nothrow__)) long double rintl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __rintl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double nextafterl(long double __x ,
                                                            long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __nextafterl(long double __x ,
                                                              long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double nexttowardl(long double __x ,
                                                             long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __nexttowardl(long double __x ,
                                                               long double __y )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double remainderl(long double __x ,
                                                            long double __y ) ;
extern  __attribute__((__nothrow__)) long double __remainderl(long double __x ,
                                                              long double __y ) ;
extern  __attribute__((__nothrow__)) long double scalbnl(long double __x ,
                                                         int __n ) ;
extern  __attribute__((__nothrow__)) long double __scalbnl(long double __x ,
                                                           int __n ) ;
extern  __attribute__((__nothrow__)) int ilogbl(long double __x ) ;
extern  __attribute__((__nothrow__)) int __ilogbl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double scalblnl(long double __x ,
                                                          long __n ) ;
extern  __attribute__((__nothrow__)) long double __scalblnl(long double __x ,
                                                            long __n ) ;
extern  __attribute__((__nothrow__)) long double nearbyintl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double __nearbyintl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double roundl(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __roundl(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double truncl(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double __truncl(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double remquol(long double __x ,
                                                         long double __y ,
                                                         int *__quo ) ;
extern  __attribute__((__nothrow__)) long double __remquol(long double __x ,
                                                           long double __y ,
                                                           int *__quo ) ;
__inline extern  __attribute__((__nothrow__)) long lrintl(long double __x ) ;
extern  __attribute__((__nothrow__)) long __lrintl(long double __x ) ;
__inline extern  __attribute__((__nothrow__)) long long llrintl(long double __x ) ;
extern  __attribute__((__nothrow__)) long long __llrintl(long double __x ) ;
extern  __attribute__((__nothrow__)) long lroundl(long double __x ) ;
extern  __attribute__((__nothrow__)) long __lroundl(long double __x ) ;
extern  __attribute__((__nothrow__)) long long llroundl(long double __x ) ;
extern  __attribute__((__nothrow__)) long long __llroundl(long double __x ) ;
extern  __attribute__((__nothrow__)) long double fdiml(long double __x ,
                                                       long double __y ) ;
extern  __attribute__((__nothrow__)) long double __fdiml(long double __x ,
                                                         long double __y ) ;
extern  __attribute__((__nothrow__)) long double fmaxl(long double __x ,
                                                       long double __y ) ;
extern  __attribute__((__nothrow__)) long double __fmaxl(long double __x ,
                                                         long double __y ) ;
extern  __attribute__((__nothrow__)) long double fminl(long double __x ,
                                                       long double __y ) ;
extern  __attribute__((__nothrow__)) long double __fminl(long double __x ,
                                                         long double __y ) ;
extern  __attribute__((__nothrow__)) int __fpclassifyl(long double __value )  __attribute__((__const__)) ;
__inline extern  __attribute__((__nothrow__)) int __signbitl(long double __x )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) long double fmal(long double __x ,
                                                      long double __y ,
                                                      long double __z ) ;
extern  __attribute__((__nothrow__)) long double __fmal(long double __x ,
                                                        long double __y ,
                                                        long double __z ) ;
extern  __attribute__((__nothrow__)) long double scalbl(long double __x ,
                                                        long double __n ) ;
extern  __attribute__((__nothrow__)) long double __scalbl(long double __x ,
                                                          long double __n ) ;
extern int signgam ;
extern _LIB_VERSION_TYPE _LIB_VERSION ;
extern int matherr(struct exception *__exc ) ;
__inline extern  __attribute__((__nothrow__)) int __signbitf(float __x )  __attribute__((__const__)) ;
__inline extern int __signbitf(float __x ) 
{ 
  union __anonunion___u_28 __u ;

  {
  __u.__f = __x;


  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2382", "0", checkpoints_buf);
  return (__u.__i < 0);
}
}
__inline extern  __attribute__((__nothrow__)) int __signbit(double __x )  __attribute__((__const__)) ;
__inline extern int __signbit(double __x ) 
{ 
  union __anonunion___u_29 __u ;

  {
  __u.__d = __x;


  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2384", "0", checkpoints_buf);
  return (__u.__i[1] < 0);
}
}
__inline extern  __attribute__((__nothrow__)) int __signbitl(long double __x )  __attribute__((__const__)) ;
__inline extern int __signbitl(long double __x ) 
{ 
  union __anonunion___u_30 __u ;

  {
  __u.__l = __x;


  sprintf(checkpoints_buf, "%d", 32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2386", "32768", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2386", "0", checkpoints_buf);
  return ((__u.__i[2] & 32768) != 0);
}
}
__inline extern  __attribute__((__nothrow__)) double __sgn(double __x ) ;
__inline extern  __attribute__((__nothrow__)) double __sgn(double __x ) ;
__inline extern double __sgn(double __x ) 
{ 
  double tmp ;
  double tmp___0 ;

  {
  sprintf(checkpoints_buf, "%lf", __x);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2387", "__x", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2387", "0.000000", checkpoints_buf);
  if (__x == 0.0) {
    tmp___0 = 0.0;
    sprintf(checkpoints_buf, "%lf", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2388", "tmp___0", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%lf", __x);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2389", "__x", checkpoints_buf);
    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2389", "0.000000", checkpoints_buf);
    if (__x > 0.0) {
      tmp = 1.0;
      sprintf(checkpoints_buf, "%lf", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2390", "tmp", checkpoints_buf);
    } else {
      tmp = - 1.0;
      sprintf(checkpoints_buf, "%lf", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2391", "tmp", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%lf", __x);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2389", "__x", checkpoints_buf);
    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2389", "0.000000", checkpoints_buf);
    tmp___0 = tmp;
    sprintf(checkpoints_buf, "%lf", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2392", "tmp___0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%lf", __x);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2387", "__x", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2387", "0.000000", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2393", "tmp___0", checkpoints_buf);
  return (tmp___0);
}
}
__inline extern  __attribute__((__nothrow__)) float __sgnf(float __x ) ;
__inline extern  __attribute__((__nothrow__)) float __sgnf(float __x ) ;
__inline extern float __sgnf(float __x ) 
{ 
  double tmp ;
  double tmp___0 ;

  {
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2394", "0.000000", checkpoints_buf);
  if ((double )__x == 0.0) {
    tmp___0 = 0.0;
    sprintf(checkpoints_buf, "%lf", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2395", "tmp___0", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2396", "0.000000", checkpoints_buf);
    if ((double )__x > 0.0) {
      tmp = 1.0;
      sprintf(checkpoints_buf, "%lf", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2397", "tmp", checkpoints_buf);
    } else {
      tmp = - 1.0;
      sprintf(checkpoints_buf, "%lf", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2398", "tmp", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2396", "0.000000", checkpoints_buf);
    tmp___0 = tmp;
    sprintf(checkpoints_buf, "%lf", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2399", "tmp___0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2394", "0.000000", checkpoints_buf);
  return ((float )tmp___0);
}
}
__inline extern  __attribute__((__nothrow__)) long double __sgnl(long double __x ) ;
__inline extern  __attribute__((__nothrow__)) long double __sgnl(long double __x ) ;
__inline extern long double __sgnl(long double __x ) 
{ 
  double tmp ;
  double tmp___0 ;

  {
  sprintf(checkpoints_buf, "%Le", __x);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2401", "__x", checkpoints_buf);
  if (__x == (long double )0.0) {
    tmp___0 = 0.0;
    sprintf(checkpoints_buf, "%lf", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2402", "tmp___0", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%Le", __x);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2403", "__x", checkpoints_buf);
    if (__x > (long double )0.0) {
      tmp = 1.0;
      sprintf(checkpoints_buf, "%lf", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2404", "tmp", checkpoints_buf);
    } else {
      tmp = - 1.0;
      sprintf(checkpoints_buf, "%lf", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2405", "tmp", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%Le", __x);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2403", "__x", checkpoints_buf);
    tmp___0 = tmp;
    sprintf(checkpoints_buf, "%lf", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2406", "tmp___0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%Le", __x);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2401", "__x", checkpoints_buf);
  return ((long double )tmp___0);
}
}
__inline extern  __attribute__((__nothrow__)) long double __atan2l(long double __y ,
                                                                   long double __x ) ;
__inline extern long double __atan2l(long double __y , long double __x ) 
{ 
  long double tmp ;

  {
  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2408", "tmp", checkpoints_buf);

  tmp = __builtin_atan2l(__y, __x);
  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2408", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2409", "tmp", checkpoints_buf);
  return (tmp);
}
}
__inline extern  __attribute__((__nothrow__)) double fabs(double __x )  __attribute__((__const__)) ;
__inline extern double fabs(double __x ) 
{ 
  double tmp ;

  {
  sprintf(checkpoints_buf, "%lf", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2410", "tmp", checkpoints_buf);

  tmp = __builtin_fabs(__x);
  sprintf(checkpoints_buf, "%lf", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2410", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%lf", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2411", "tmp", checkpoints_buf);
  return (tmp);
}
}
__inline extern  __attribute__((__nothrow__)) float fabsf(float __x )  __attribute__((__const__)) ;
__inline extern float fabsf(float __x ) 
{ 
  float tmp ;

  {
  sprintf(checkpoints_buf, "%f", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2412", "tmp", checkpoints_buf);

  tmp = __builtin_fabsf(__x);
  sprintf(checkpoints_buf, "%f", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2412", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%f", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2413", "tmp", checkpoints_buf);
  return (tmp);
}
}
__inline extern  __attribute__((__nothrow__)) long double fabsl(long double __x )  __attribute__((__const__)) ;
__inline extern long double fabsl(long double __x ) 
{ 
  long double tmp ;

  {
  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2414", "tmp", checkpoints_buf);

  tmp = __builtin_fabsl(__x);
  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2414", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2415", "tmp", checkpoints_buf);
  return (tmp);
}
}
__inline extern  __attribute__((__nothrow__)) long double __fabsl(long double __x )  __attribute__((__const__)) ;
__inline extern long double __fabsl(long double __x ) 
{ 
  long double tmp ;

  {
  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2416", "tmp", checkpoints_buf);

  tmp = __builtin_fabsl(__x);
  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2416", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%Le", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2417", "tmp", checkpoints_buf);
  return (tmp);
}
}
__inline extern  __attribute__((__nothrow__)) long double __sgn1l(long double __x ) ;
__inline extern  __attribute__((__nothrow__)) long double __sgn1l(long double __x ) ;
__inline extern long double __sgn1l(long double __x ) 
{ 
  union __anonunion___n_31 __n ;

  {
  __n.__xld = __x;

  __n.__xi[2] = (__n.__xi[2] & 32768U) | 16383U;

  __n.__xi[1] = 2147483648U;

  __n.__xi[0] = 0U;


  return (__n.__xld);
}
}
__inline extern  __attribute__((__nothrow__)) double floor(double __x )  __attribute__((__const__)) ;
__inline extern double floor(double __x ) 
{ 
  register long double __value ;
  register int __ignore ;
  unsigned short __cw ;
  unsigned short __cwtmp ;

  {
  __asm__  volatile   ("fnstcw %3\n\t"
                       "movzwl %3, %1\n\t"
                       "andl $0xf3ff, %1\n\t"
                       "orl $0x0400, %1\n\t"
                       "movw %w1, %2\n\t"
                       "fldcw %2\n\t"
                       "frndint\n\t"
                       "fldcw %3": "=t" (__value), "=&q" (__ignore),
                       "=m" (__cwtmp), "=m" (__cw): "0" (__x));
  return ((double )__value);
}
}
__inline extern  __attribute__((__nothrow__)) float floorf(float __x )  __attribute__((__const__)) ;
__inline extern float floorf(float __x ) 
{ 
  register long double __value ;
  register int __ignore ;
  unsigned short __cw ;
  unsigned short __cwtmp ;

  {
  __asm__  volatile   ("fnstcw %3\n\t"
                       "movzwl %3, %1\n\t"
                       "andl $0xf3ff, %1\n\t"
                       "orl $0x0400, %1\n\t"
                       "movw %w1, %2\n\t"
                       "fldcw %2\n\t"
                       "frndint\n\t"
                       "fldcw %3": "=t" (__value), "=&q" (__ignore),
                       "=m" (__cwtmp), "=m" (__cw): "0" (__x));
  return ((float )__value);
}
}
__inline extern  __attribute__((__nothrow__)) long double floorl(long double __x )  __attribute__((__const__)) ;
__inline extern long double floorl(long double __x ) 
{ 
  register long double __value ;
  register int __ignore ;
  unsigned short __cw ;
  unsigned short __cwtmp ;

  {
  __asm__  volatile   ("fnstcw %3\n\t"
                       "movzwl %3, %1\n\t"
                       "andl $0xf3ff, %1\n\t"
                       "orl $0x0400, %1\n\t"
                       "movw %w1, %2\n\t"
                       "fldcw %2\n\t"
                       "frndint\n\t"
                       "fldcw %3": "=t" (__value), "=&q" (__ignore),
                       "=m" (__cwtmp), "=m" (__cw): "0" (__x));
  sprintf(checkpoints_buf, "%Le", __value);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2428", "__value", checkpoints_buf);
  return (__value);
}
}
__inline extern  __attribute__((__nothrow__)) double ceil(double __x )  __attribute__((__const__)) ;
__inline extern double ceil(double __x ) 
{ 
  register long double __value ;
  register int __ignore ;
  unsigned short __cw ;
  unsigned short __cwtmp ;

  {
  __asm__  volatile   ("fnstcw %3\n\t"
                       "movzwl %3, %1\n\t"
                       "andl $0xf3ff, %1\n\t"
                       "orl $0x0800, %1\n\t"
                       "movw %w1, %2\n\t"
                       "fldcw %2\n\t"
                       "frndint\n\t"
                       "fldcw %3": "=t" (__value), "=&q" (__ignore),
                       "=m" (__cwtmp), "=m" (__cw): "0" (__x));
  return ((double )__value);
}
}
__inline extern  __attribute__((__nothrow__)) float ceilf(float __x )  __attribute__((__const__)) ;
__inline extern float ceilf(float __x ) 
{ 
  register long double __value ;
  register int __ignore ;
  unsigned short __cw ;
  unsigned short __cwtmp ;

  {
  __asm__  volatile   ("fnstcw %3\n\t"
                       "movzwl %3, %1\n\t"
                       "andl $0xf3ff, %1\n\t"
                       "orl $0x0800, %1\n\t"
                       "movw %w1, %2\n\t"
                       "fldcw %2\n\t"
                       "frndint\n\t"
                       "fldcw %3": "=t" (__value), "=&q" (__ignore),
                       "=m" (__cwtmp), "=m" (__cw): "0" (__x));
  return ((float )__value);
}
}
__inline extern  __attribute__((__nothrow__)) long double ceill(long double __x )  __attribute__((__const__)) ;
__inline extern long double ceill(long double __x ) 
{ 
  register long double __value ;
  register int __ignore ;
  unsigned short __cw ;
  unsigned short __cwtmp ;

  {
  __asm__  volatile   ("fnstcw %3\n\t"
                       "movzwl %3, %1\n\t"
                       "andl $0xf3ff, %1\n\t"
                       "orl $0x0800, %1\n\t"
                       "movw %w1, %2\n\t"
                       "fldcw %2\n\t"
                       "frndint\n\t"
                       "fldcw %3": "=t" (__value), "=&q" (__ignore),
                       "=m" (__cwtmp), "=m" (__cw): "0" (__x));
  sprintf(checkpoints_buf, "%Le", __value);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2434", "__value", checkpoints_buf);
  return (__value);
}
}
__inline extern  __attribute__((__nothrow__)) long lrintf(float __x ) ;
__inline extern long lrintf(float __x ) 
{ 
  long __lrintres ;

  {
  __asm__  volatile   ("fistpl %0": "=m" (__lrintres): "t" (__x): "st");
  sprintf(checkpoints_buf, "%ld", __lrintres);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2436", "__lrintres", checkpoints_buf);
  return (__lrintres);
}
}
__inline extern  __attribute__((__nothrow__)) long lrint(double __x ) ;
__inline extern long lrint(double __x ) 
{ 
  long __lrintres ;

  {
  __asm__  volatile   ("fistpl %0": "=m" (__lrintres): "t" (__x): "st");
  sprintf(checkpoints_buf, "%ld", __lrintres);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2438", "__lrintres", checkpoints_buf);
  return (__lrintres);
}
}
__inline extern  __attribute__((__nothrow__)) long lrintl(long double __x ) ;
__inline extern long lrintl(long double __x ) 
{ 
  long __lrintres ;

  {
  __asm__  volatile   ("fistpl %0": "=m" (__lrintres): "t" (__x): "st");
  sprintf(checkpoints_buf, "%ld", __lrintres);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2440", "__lrintres", checkpoints_buf);
  return (__lrintres);
}
}
__inline extern  __attribute__((__nothrow__)) long long llrintf(float __x ) ;
__inline extern long long llrintf(float __x ) 
{ 
  long long __llrintres ;

  {
  __asm__  volatile   ("fistpll %0": "=m" (__llrintres): "t" (__x): "st");
  sprintf(checkpoints_buf, "%lld", __llrintres);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2442", "__llrintres", checkpoints_buf);
  return (__llrintres);
}
}
__inline extern  __attribute__((__nothrow__)) long long llrint(double __x ) ;
__inline extern long long llrint(double __x ) 
{ 
  long long __llrintres ;

  {
  __asm__  volatile   ("fistpll %0": "=m" (__llrintres): "t" (__x): "st");
  sprintf(checkpoints_buf, "%lld", __llrintres);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2444", "__llrintres", checkpoints_buf);
  return (__llrintres);
}
}
__inline extern  __attribute__((__nothrow__)) long long llrintl(long double __x ) ;
__inline extern long long llrintl(long double __x ) 
{ 
  long long __llrintres ;

  {
  __asm__  volatile   ("fistpll %0": "=m" (__llrintres): "t" (__x): "st");
  sprintf(checkpoints_buf, "%lld", __llrintres);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2446", "__llrintres", checkpoints_buf);
  return (__llrintres);
}
}
__inline extern  __attribute__((__nothrow__)) int __finite(double __x )  __attribute__((__const__)) ;
__inline extern int __finite(double __x ) 
{ 
  union __anonunion_32 __constr_expr_0 ;

  {
  __constr_expr_0.__d = __x;

  return ((int )((((unsigned int )__constr_expr_0.__i[1] | 2148532223U) + 1U) >> 31));
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) access)(char const   *__name ,
                                                                                   int __type ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) faccessat)(int __fd ,
                                                                                      char const   *__file ,
                                                                                      int __type ,
                                                                                      int __flag ) ;
extern  __attribute__((__nothrow__)) __off64_t lseek(int __fd ,
                                                     __off64_t __offset ,
                                                     int __whence )  __asm__("lseek64")  ;
extern int close(int __fd ) ;
extern ssize_t read(int __fd , void *__buf , size_t __nbytes ) ;
extern ssize_t write(int __fd , void const   *__buf , size_t __n ) ;
extern ssize_t pread(int __fd , void *__buf , size_t __nbytes ,
                     __off64_t __offset )  __asm__("pread64")  ;
extern ssize_t pwrite(int __fd , void const   *__buf , size_t __nbytes ,
                      __off64_t __offset )  __asm__("pwrite64")  ;
extern  __attribute__((__nothrow__)) int pipe(int *__pipedes ) ;
extern  __attribute__((__nothrow__)) unsigned int alarm(unsigned int __seconds ) ;
extern unsigned int sleep(unsigned int __seconds ) ;
extern  __attribute__((__nothrow__)) __useconds_t ualarm(__useconds_t __value ,
                                                         __useconds_t __interval ) ;
extern int usleep(__useconds_t __useconds ) ;
extern int pause(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) chown)(char const   *__file ,
                                                                                  __uid_t __owner ,
                                                                                  __gid_t __group ) ;
extern  __attribute__((__nothrow__)) int fchown(int __fd , __uid_t __owner ,
                                                __gid_t __group ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) lchown)(char const   *__file ,
                                                                                   __uid_t __owner ,
                                                                                   __gid_t __group ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) fchownat)(int __fd ,
                                                                                     char const   *__file ,
                                                                                     __uid_t __owner ,
                                                                                     __gid_t __group ,
                                                                                     int __flag ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) chdir)(char const   *__path ) ;
extern  __attribute__((__nothrow__)) int fchdir(int __fd ) ;
extern  __attribute__((__nothrow__)) char *getcwd(char *__buf , size_t __size ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) getwd)(char *__buf )  __attribute__((__deprecated__)) ;
extern  __attribute__((__nothrow__)) int dup(int __fd ) ;
extern  __attribute__((__nothrow__)) int dup2(int __fd , int __fd2 ) ;
extern char **__environ ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execve)(char const   *__path ,
                                                                                     char * const  *__argv ,
                                                                                     char * const  *__envp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) fexecve)(int __fd ,
                                                                                    char * const  *__argv ,
                                                                                    char * const  *__envp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execv)(char const   *__path ,
                                                                                    char * const  *__argv ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execle)(char const   *__path ,
                                                                                     char const   *__arg 
                                                                                     , ...) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execl)(char const   *__path ,
                                                                                    char const   *__arg 
                                                                                    , ...) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execvp)(char const   *__file ,
                                                                                     char * const  *__argv ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execlp)(char const   *__file ,
                                                                                     char const   *__arg 
                                                                                     , ...) ;
extern  __attribute__((__nothrow__)) int nice(int __inc ) ;
extern  __attribute__((__noreturn__)) void _exit(int __status ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) pathconf)(char const   *__path ,
                                                                                      int __name ) ;
extern  __attribute__((__nothrow__)) long fpathconf(int __fd , int __name ) ;
extern  __attribute__((__nothrow__)) long sysconf(int __name ) ;
extern  __attribute__((__nothrow__)) size_t confstr(int __name , char *__buf ,
                                                    size_t __len ) ;
extern  __attribute__((__nothrow__)) __pid_t getpid(void) ;
extern  __attribute__((__nothrow__)) __pid_t getppid(void) ;
extern  __attribute__((__nothrow__)) __pid_t getpgrp(void) ;
extern  __attribute__((__nothrow__)) __pid_t __getpgid(__pid_t __pid ) ;
extern  __attribute__((__nothrow__)) __pid_t getpgid(__pid_t __pid ) ;
extern  __attribute__((__nothrow__)) int setpgid(__pid_t __pid , __pid_t __pgid ) ;
extern  __attribute__((__nothrow__)) int setpgrp(void) ;
extern  __attribute__((__nothrow__)) __pid_t setsid(void) ;
extern  __attribute__((__nothrow__)) __pid_t getsid(__pid_t __pid ) ;
extern  __attribute__((__nothrow__)) __uid_t getuid(void) ;
extern  __attribute__((__nothrow__)) __uid_t geteuid(void) ;
extern  __attribute__((__nothrow__)) __gid_t getgid(void) ;
extern  __attribute__((__nothrow__)) __gid_t getegid(void) ;
extern  __attribute__((__nothrow__)) int getgroups(int __size , __gid_t *__list ) ;
extern  __attribute__((__nothrow__)) int setuid(__uid_t __uid ) ;
extern  __attribute__((__nothrow__)) int setreuid(__uid_t __ruid ,
                                                  __uid_t __euid ) ;
extern  __attribute__((__nothrow__)) int seteuid(__uid_t __uid ) ;
extern  __attribute__((__nothrow__)) int setgid(__gid_t __gid ) ;
extern  __attribute__((__nothrow__)) int setregid(__gid_t __rgid ,
                                                  __gid_t __egid ) ;
extern  __attribute__((__nothrow__)) int setegid(__gid_t __gid ) ;
extern  __attribute__((__nothrow__)) __pid_t fork(void) ;
extern  __attribute__((__nothrow__)) __pid_t vfork(void) ;
extern  __attribute__((__nothrow__)) char *ttyname(int __fd ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) ttyname_r)(int __fd ,
                                                                                      char *__buf ,
                                                                                      size_t __buflen ) ;
extern  __attribute__((__nothrow__)) int isatty(int __fd ) ;
extern  __attribute__((__nothrow__)) int ttyslot(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) link)(char const   *__from ,
                                                                                   char const   *__to ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,4))) linkat)(int __fromfd ,
                                                                                     char const   *__from ,
                                                                                     int __tofd ,
                                                                                     char const   *__to ,
                                                                                     int __flags ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) symlink)(char const   *__from ,
                                                                                      char const   *__to ) ;
extern  __attribute__((__nothrow__)) ssize_t ( __attribute__((__nonnull__(1,2))) readlink)(char const   * __restrict  __path ,
                                                                                           char * __restrict  __buf ,
                                                                                           size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,3))) symlinkat)(char const   *__from ,
                                                                                        int __tofd ,
                                                                                        char const   *__to ) ;
extern  __attribute__((__nothrow__)) ssize_t ( __attribute__((__nonnull__(2,3))) readlinkat)(int __fd ,
                                                                                             char const   * __restrict  __path ,
                                                                                             char * __restrict  __buf ,
                                                                                             size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) unlink)(char const   *__name ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) unlinkat)(int __fd ,
                                                                                     char const   *__name ,
                                                                                     int __flag ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) rmdir)(char const   *__path ) ;
extern  __attribute__((__nothrow__)) __pid_t tcgetpgrp(int __fd ) ;
extern  __attribute__((__nothrow__)) int tcsetpgrp(int __fd , __pid_t __pgrp_id ) ;
extern char *getlogin(void) ;
extern int ( __attribute__((__nonnull__(1))) getlogin_r)(char *__name ,
                                                         size_t __name_len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) setlogin)(char const   *__name ) ;
extern char *optarg ;
extern int optind ;
extern int opterr ;
extern int optopt ;
extern  __attribute__((__nothrow__)) int getopt(int ___argc ,
                                                char * const  *___argv ,
                                                char const   *__shortopts ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) gethostname)(char *__name ,
                                                                                        size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sethostname)(char const   *__name ,
                                                                                        size_t __len ) ;
extern  __attribute__((__nothrow__)) int sethostid(long __id ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) getdomainname)(char *__name ,
                                                                                          size_t __len ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) setdomainname)(char const   *__name ,
                                                                                          size_t __len ) ;
extern  __attribute__((__nothrow__)) int vhangup(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) revoke)(char const   *__file ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) profil)(unsigned short *__sample_buffer ,
                                                                                   size_t __size ,
                                                                                   size_t __offset ,
                                                                                   unsigned int __scale ) ;
extern  __attribute__((__nothrow__)) int acct(char const   *__name ) ;
extern  __attribute__((__nothrow__)) char *getusershell(void) ;
extern  __attribute__((__nothrow__)) void endusershell(void) ;
extern  __attribute__((__nothrow__)) void setusershell(void) ;
extern  __attribute__((__nothrow__)) int daemon(int __nochdir , int __noclose ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) chroot)(char const   *__path ) ;
extern char *( __attribute__((__nonnull__(1))) getpass)(char const   *__prompt ) ;
extern int fsync(int __fd ) ;
extern long gethostid(void) ;
extern  __attribute__((__nothrow__)) void sync(void) ;
extern  __attribute__((__nothrow__)) int getpagesize(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int getdtablesize(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) truncate)(char const   *__file ,
                                                                                     __off64_t __length )  __asm__("truncate64")  ;
extern  __attribute__((__nothrow__)) int ftruncate(int __fd ,
                                                   __off64_t __length )  __asm__("ftruncate64")  ;
extern  __attribute__((__nothrow__)) int brk(void *__addr ) ;
extern  __attribute__((__nothrow__)) void *sbrk(intptr_t __delta ) ;
extern  __attribute__((__nothrow__)) long syscall(long __sysno  , ...) ;
extern int lockf(int __fd , int __cmd , __off64_t __len )  __asm__("lockf64")  ;
extern int fdatasync(int __fildes ) ;
extern char const   *TIFFGetVersion(void) ;
extern TIFFCodec const   *TIFFFindCODEC(uint16  ) ;
extern TIFFCodec *TIFFRegisterCODEC(uint16  , char const   * ,
                                    int (*)(TIFF * , int  ) ) ;
extern void TIFFUnRegisterCODEC(TIFFCodec * ) ;
extern int TIFFIsCODECConfigured(uint16  ) ;
extern TIFFCodec *TIFFGetConfiguredCODECs(void) ;
extern void *_TIFFmalloc(tmsize_t s ) ;
extern void *_TIFFrealloc(void *p , tmsize_t s ) ;
extern void _TIFFmemset(void *p , int v , tmsize_t c ) ;
extern void _TIFFmemcpy(void *d , void const   *s , tmsize_t c ) ;
extern int _TIFFmemcmp(void const   *p1 , void const   *p2 , tmsize_t c ) ;
extern void _TIFFfree(void *p ) ;
extern int TIFFGetTagListCount(TIFF * ) ;
extern uint32 TIFFGetTagListEntry(TIFF * , int tag_index ) ;
extern TIFFField const   *TIFFFindField(TIFF * , uint32  , TIFFDataType  ) ;
extern TIFFField const   *TIFFFieldWithTag(TIFF * , uint32  ) ;
extern TIFFField const   *TIFFFieldWithName(TIFF * , char const   * ) ;
extern TIFFTagMethods *TIFFAccessTagMethods(TIFF * ) ;
extern void *TIFFGetClientInfo(TIFF * , char const   * ) ;
extern void TIFFSetClientInfo(TIFF * , void * , char const   * ) ;
extern void TIFFCleanup(TIFF *tif ) ;
extern void TIFFClose(TIFF *tif ) ;
extern int TIFFFlush(TIFF *tif ) ;
extern int TIFFFlushData(TIFF *tif ) ;
extern int TIFFGetField(TIFF *tif , uint32 tag  , ...) ;
extern int TIFFVGetField(TIFF *tif , uint32 tag , va_list ap ) ;
extern int TIFFGetFieldDefaulted(TIFF *tif , uint32 tag  , ...) ;
extern int TIFFVGetFieldDefaulted(TIFF *tif , uint32 tag , va_list ap ) ;
extern int TIFFReadDirectory(TIFF *tif ) ;
extern int TIFFReadCustomDirectory(TIFF *tif , toff_t diroff ,
                                   TIFFFieldArray const   *infoarray ) ;
extern int TIFFReadEXIFDirectory(TIFF *tif , toff_t diroff ) ;
extern uint64 TIFFScanlineSize64(TIFF *tif ) ;
extern tmsize_t TIFFScanlineSize(TIFF *tif ) ;
extern uint64 TIFFRasterScanlineSize64(TIFF *tif ) ;
extern tmsize_t TIFFRasterScanlineSize(TIFF *tif ) ;
extern uint64 TIFFStripSize64(TIFF *tif ) ;
extern tmsize_t TIFFStripSize(TIFF *tif ) ;
extern uint64 TIFFRawStripSize64(TIFF *tif , uint32 strip ) ;
extern tmsize_t TIFFRawStripSize(TIFF *tif , uint32 strip ) ;
extern uint64 TIFFVStripSize64(TIFF *tif , uint32 nrows ) ;
extern tmsize_t TIFFVStripSize(TIFF *tif , uint32 nrows ) ;
extern uint64 TIFFTileRowSize64(TIFF *tif ) ;
extern tmsize_t TIFFTileRowSize(TIFF *tif ) ;
extern uint64 TIFFTileSize64(TIFF *tif ) ;
extern tmsize_t TIFFTileSize(TIFF *tif ) ;
extern uint64 TIFFVTileSize64(TIFF *tif , uint32 nrows ) ;
extern tmsize_t TIFFVTileSize(TIFF *tif , uint32 nrows ) ;
extern uint32 TIFFDefaultStripSize(TIFF *tif , uint32 request ) ;
extern void TIFFDefaultTileSize(TIFF * , uint32 * , uint32 * ) ;
extern int TIFFFileno(TIFF * ) ;
extern int TIFFSetFileno(TIFF * , int  ) ;
extern thandle_t TIFFClientdata(TIFF * ) ;
extern thandle_t TIFFSetClientdata(TIFF * , thandle_t  ) ;
extern int TIFFGetMode(TIFF * ) ;
extern int TIFFSetMode(TIFF * , int  ) ;
extern int TIFFIsTiled(TIFF * ) ;
extern int TIFFIsByteSwapped(TIFF * ) ;
extern int TIFFIsUpSampled(TIFF * ) ;
extern int TIFFIsMSB2LSB(TIFF * ) ;
extern int TIFFIsBigEndian(TIFF * ) ;
extern TIFFReadWriteProc TIFFGetReadProc(TIFF * ) ;
extern TIFFReadWriteProc TIFFGetWriteProc(TIFF * ) ;
extern TIFFSeekProc TIFFGetSeekProc(TIFF * ) ;
extern TIFFCloseProc TIFFGetCloseProc(TIFF * ) ;
extern TIFFSizeProc TIFFGetSizeProc(TIFF * ) ;
extern TIFFMapFileProc TIFFGetMapFileProc(TIFF * ) ;
extern TIFFUnmapFileProc TIFFGetUnmapFileProc(TIFF * ) ;
extern uint32 TIFFCurrentRow(TIFF * ) ;
extern uint16 TIFFCurrentDirectory(TIFF * ) ;
extern uint16 TIFFNumberOfDirectories(TIFF * ) ;
extern uint64 TIFFCurrentDirOffset(TIFF * ) ;
extern uint32 TIFFCurrentStrip(TIFF * ) ;
extern uint32 TIFFCurrentTile(TIFF *tif ) ;
extern int TIFFReadBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
extern int TIFFWriteBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
extern int TIFFSetupStrips(TIFF * ) ;
extern int TIFFWriteCheck(TIFF * , int  , char const   * ) ;
extern void TIFFFreeDirectory(TIFF * ) ;
extern int TIFFCreateDirectory(TIFF * ) ;
extern int TIFFLastDirectory(TIFF * ) ;
extern int TIFFSetDirectory(TIFF * , uint16  ) ;
extern int TIFFSetSubDirectory(TIFF * , uint64  ) ;
extern int TIFFUnlinkDirectory(TIFF * , uint16  ) ;
extern int TIFFSetField(TIFF * , uint32   , ...) ;
extern int TIFFVSetField(TIFF * , uint32  , va_list  ) ;
extern int TIFFUnsetField(TIFF * , uint32  ) ;
extern int TIFFWriteDirectory(TIFF * ) ;
extern int TIFFCheckpointDirectory(TIFF * ) ;
extern int TIFFRewriteDirectory(TIFF * ) ;
extern void TIFFPrintDirectory(TIFF * , FILE * , long  ) ;
extern int TIFFReadScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) ;
extern int TIFFWriteScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) ;
extern int TIFFReadRGBAImage(TIFF * , uint32  , uint32  , uint32 * , int  ) ;
extern int TIFFReadRGBAImageOriented(TIFF * , uint32  , uint32  , uint32 * ,
                                     int  , int  ) ;
extern int TIFFReadRGBAStrip(TIFF * , uint32  , uint32 * ) ;
extern int TIFFReadRGBATile(TIFF * , uint32  , uint32  , uint32 * ) ;
extern int TIFFRGBAImageOK(TIFF * , char * ) ;
extern int TIFFRGBAImageBegin(TIFFRGBAImage * , TIFF * , int  , char * ) ;
extern int TIFFRGBAImageGet(TIFFRGBAImage * , uint32 * , uint32  , uint32  ) ;
extern void TIFFRGBAImageEnd(TIFFRGBAImage * ) ;
extern TIFF *TIFFOpen(char const   * , char const   * ) ;
extern TIFF *TIFFFdOpen(int  , char const   * , char const   * ) ;
extern TIFF *TIFFClientOpen(char const   * , char const   * , thandle_t  ,
                            tmsize_t (*)(thandle_t  , void * , tmsize_t  ) ,
                            tmsize_t (*)(thandle_t  , void * , tmsize_t  ) ,
                            toff_t (*)(thandle_t  , toff_t  , int  ) ,
                            int (*)(thandle_t  ) , toff_t (*)(thandle_t  ) ,
                            int (*)(thandle_t  , void **base , toff_t *size ) ,
                            void (*)(thandle_t  , void *base , toff_t size ) ) ;
extern char const   *TIFFFileName(TIFF * ) ;
extern char const   *TIFFSetFileName(TIFF * , char const   * ) ;
extern void TIFFError(char const   * , char const   *  , ...) ;
extern void TIFFErrorExt(thandle_t  , char const   * , char const   *  , ...) ;
extern void TIFFWarning(char const   * , char const   *  , ...) ;
extern void TIFFWarningExt(thandle_t  , char const   * , char const   *  , ...) ;
extern TIFFErrorHandler TIFFSetErrorHandler(void (*)(char const   * ,
                                                     char const   * , va_list  ) ) ;
extern TIFFErrorHandlerExt TIFFSetErrorHandlerExt(void (*)(thandle_t  ,
                                                           char const   * ,
                                                           char const   * ,
                                                           va_list  ) ) ;
extern TIFFErrorHandler TIFFSetWarningHandler(void (*)(char const   * ,
                                                       char const   * ,
                                                       va_list  ) ) ;
extern TIFFErrorHandlerExt TIFFSetWarningHandlerExt(void (*)(thandle_t  ,
                                                             char const   * ,
                                                             char const   * ,
                                                             va_list  ) ) ;
extern TIFFExtendProc TIFFSetTagExtender(void (*)(TIFF * ) ) ;
extern uint32 TIFFComputeTile(TIFF *tif , uint32 x , uint32 y , uint32 z ,
                              uint16 s ) ;
extern int TIFFCheckTile(TIFF *tif , uint32 x , uint32 y , uint32 z , uint16 s ) ;
extern uint32 TIFFNumberOfTiles(TIFF * ) ;
extern tmsize_t TIFFReadTile(TIFF *tif , void *buf , uint32 x , uint32 y ,
                             uint32 z , uint16 s ) ;
extern tmsize_t TIFFWriteTile(TIFF *tif , void *buf , uint32 x , uint32 y ,
                              uint32 z , uint16 s ) ;
extern uint32 TIFFComputeStrip(TIFF * , uint32  , uint16  ) ;
extern uint32 TIFFNumberOfStrips(TIFF * ) ;
extern tmsize_t TIFFReadEncodedStrip(TIFF *tif , uint32 strip , void *buf ,
                                     tmsize_t size ) ;
extern tmsize_t TIFFReadRawStrip(TIFF *tif , uint32 strip , void *buf ,
                                 tmsize_t size ) ;
extern tmsize_t TIFFReadEncodedTile(TIFF *tif , uint32 tile , void *buf ,
                                    tmsize_t size ) ;
extern tmsize_t TIFFReadRawTile(TIFF *tif , uint32 tile , void *buf ,
                                tmsize_t size ) ;
extern tmsize_t TIFFWriteEncodedStrip(TIFF *tif , uint32 strip , void *data ,
                                      tmsize_t cc ) ;
extern tmsize_t TIFFWriteRawStrip(TIFF *tif , uint32 strip , void *data ,
                                  tmsize_t cc ) ;
extern tmsize_t TIFFWriteEncodedTile(TIFF *tif , uint32 tile , void *data ,
                                     tmsize_t cc ) ;
extern tmsize_t TIFFWriteRawTile(TIFF *tif , uint32 tile , void *data ,
                                 tmsize_t cc ) ;
extern int TIFFDataWidth(TIFFDataType  ) ;
extern void TIFFSetWriteOffset(TIFF *tif , toff_t off ) ;
extern void TIFFSwabShort(uint16 * ) ;
extern void TIFFSwabLong(uint32 * ) ;
extern void TIFFSwabLong8(uint64 * ) ;
extern void TIFFSwabFloat(float * ) ;
extern void TIFFSwabDouble(double * ) ;
extern void TIFFSwabArrayOfShort(uint16 *wp , tmsize_t n ) ;
extern void TIFFSwabArrayOfTriples(uint8 *tp , tmsize_t n ) ;
extern void TIFFSwabArrayOfLong(uint32 *lp , tmsize_t n ) ;
extern void TIFFSwabArrayOfLong8(uint64 *lp , tmsize_t n ) ;
extern void TIFFSwabArrayOfFloat(float *fp , tmsize_t n ) ;
extern void TIFFSwabArrayOfDouble(double *dp , tmsize_t n ) ;
extern void TIFFReverseBits(uint8 *cp , tmsize_t n ) ;
extern unsigned char const   *TIFFGetBitRevTable(int  ) ;
extern double LogL16toY(int  ) ;
extern double LogL10toY(int  ) ;
extern void XYZtoRGB24(float * , uint8 * ) ;
extern int uv_decode(double * , double * , int  ) ;
extern void LogLuv24toXYZ(uint32  , float * ) ;
extern void LogLuv32toXYZ(uint32  , float * ) ;
extern int LogL16fromY(double  , int  ) ;
extern int LogL10fromY(double  , int  ) ;
extern int uv_encode(double  , double  , int  ) ;
extern uint32 LogLuv24fromXYZ(float * , int  ) ;
extern uint32 LogLuv32fromXYZ(float * , int  ) ;
extern int TIFFCIELabToRGBInit(TIFFCIELabToRGB * , TIFFDisplay * , float * ) ;
extern void TIFFCIELabToXYZ(TIFFCIELabToRGB * , uint32  , int32  , int32  ,
                            float * , float * , float * ) ;
extern void TIFFXYZToRGB(TIFFCIELabToRGB * , float  , float  , float  ,
                         uint32 * , uint32 * , uint32 * ) ;
extern int TIFFYCbCrToRGBInit(TIFFYCbCrToRGB * , float * , float * ) ;
extern void TIFFYCbCrtoRGB(TIFFYCbCrToRGB * , uint32  , int32  , int32  ,
                           uint32 * , uint32 * , uint32 * ) ;
extern int TIFFMergeFieldInfo(TIFF * , TIFFFieldInfo const   * , uint32  ) ;
extern TIFFFieldInfo const   *TIFFFindFieldInfo(TIFF * , uint32  ,
                                                TIFFDataType  ) ;
extern TIFFFieldInfo const   *TIFFFindFieldInfoByName(TIFF * , char const   * ,
                                                      TIFFDataType  ) ;
static uint32 tnw  =    (uint32 )216;
static uint32 tnh  =    (uint32 )274;
static Contrast contrast  =    (Contrast )6;
static uint8 *thumbnail  ;
static int cpIFD(TIFF *in , TIFF *out ) ;
static int generateThumbnail(TIFF *in , TIFF *out ) ;
static void initScale(void) ;
static void usage(void) ;
int main(int argc , char **argv ) 
{ 
  TIFF *in ;
  TIFF *out ;
  int c ;
  unsigned long tmp ;
  unsigned long tmp___0 ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___4 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  size_t __s1_len___0 ;
  size_t __s2_len___0 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  unsigned char const   *__s2___0 ;
  register int __result___1 ;
  int tmp___11 ;
  unsigned char const   *__s1___0 ;
  register int __result___2 ;
  int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  size_t __s1_len___1 ;
  size_t __s2_len___1 ;
  int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  unsigned char const   *__s2___1 ;
  register int __result___3 ;
  int tmp___18 ;
  unsigned char const   *__s1___1 ;
  register int __result___4 ;
  int tmp___19 ;
  int tmp___20 ;
  int tmp___21 ;
  size_t __s1_len___2 ;
  size_t __s2_len___2 ;
  int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  unsigned char const   *__s2___2 ;
  register int __result___5 ;
  int tmp___25 ;
  unsigned char const   *__s1___2 ;
  register int __result___6 ;
  int tmp___26 ;
  int tmp___27 ;
  int tmp___28 ;
  size_t __s1_len___3 ;
  size_t __s2_len___3 ;
  int tmp___29 ;
  int tmp___30 ;
  int tmp___31 ;
  unsigned char const   *__s2___3 ;
  register int __result___7 ;
  int tmp___32 ;
  unsigned char const   *__s1___3 ;
  register int __result___8 ;
  int tmp___33 ;
  int tmp___34 ;
  int tmp___35 ;
  size_t __s1_len___4 ;
  size_t __s2_len___4 ;
  int tmp___36 ;
  int tmp___37 ;
  int tmp___38 ;
  unsigned char const   *__s2___4 ;
  register int __result___9 ;
  int tmp___39 ;
  unsigned char const   *__s1___4 ;
  register int __result___10 ;
  int tmp___40 ;
  int tmp___41 ;
  int tmp___42 ;
  size_t __s1_len___5 ;
  size_t __s2_len___5 ;
  int tmp___43 ;
  int tmp___44 ;
  int tmp___45 ;
  unsigned char const   *__s2___5 ;
  register int __result___11 ;
  int tmp___46 ;
  unsigned char const   *__s1___5 ;
  register int __result___12 ;
  int tmp___47 ;
  int tmp___48 ;
  int tmp___49 ;
  int tmp___50 ;
  size_t __s1_len___6 ;
  size_t __s2_len___6 ;
  int tmp___51 ;
  int tmp___52 ;
  int tmp___53 ;
  unsigned char const   *__s2___6 ;
  register int __result___13 ;
  int tmp___54 ;
  unsigned char const   *__s1___6 ;
  register int __result___14 ;
  int tmp___55 ;
  int tmp___56 ;
  int tmp___57 ;
  int tmp___58 ;
  size_t __s1_len___7 ;
  size_t __s2_len___7 ;
  int tmp___59 ;
  int tmp___60 ;
  int tmp___61 ;
  unsigned char const   *__s2___7 ;
  register int __result___15 ;
  int tmp___62 ;
  unsigned char const   *__s1___7 ;
  register int __result___16 ;
  int tmp___63 ;
  int tmp___64 ;
  int tmp___65 ;
  int tmp___66 ;
  size_t __s1_len___8 ;
  size_t __s2_len___8 ;
  int tmp___67 ;
  int tmp___68 ;
  int tmp___69 ;
  unsigned char const   *__s2___8 ;
  register int __result___17 ;
  int tmp___70 ;
  unsigned char const   *__s1___8 ;
  register int __result___18 ;
  int tmp___71 ;
  int tmp___72 ;
  int tmp___73 ;
  int tmp___74 ;
  size_t __s1_len___9 ;
  size_t __s2_len___9 ;
  int tmp___75 ;
  int tmp___76 ;
  int tmp___77 ;
  unsigned char const   *__s2___9 ;
  register int __result___19 ;
  int tmp___78 ;
  unsigned char const   *__s1___9 ;
  register int __result___20 ;
  int tmp___79 ;
  int tmp___80 ;
  int tmp___81 ;
  int tmp___82 ;
  size_t __s1_len___10 ;
  size_t __s2_len___10 ;
  int tmp___83 ;
  int tmp___84 ;
  int tmp___85 ;
  unsigned char const   *__s2___10 ;
  register int __result___21 ;
  int tmp___86 ;
  unsigned char const   *__s1___10 ;
  register int __result___22 ;
  int tmp___87 ;
  int tmp___88 ;
  int tmp___89 ;
  int tmp___90 ;
  size_t __s1_len___11 ;
  size_t __s2_len___11 ;
  int tmp___91 ;
  int tmp___92 ;
  int tmp___93 ;
  unsigned char const   *__s2___11 ;
  register int __result___23 ;
  int tmp___94 ;
  unsigned char const   *__s1___11 ;
  register int __result___24 ;
  int tmp___95 ;
  int tmp___96 ;
  int tmp___97 ;
  size_t __s1_len___12 ;
  size_t __s2_len___12 ;
  int tmp___98 ;
  int tmp___99 ;
  int tmp___100 ;
  unsigned char const   *__s2___12 ;
  register int __result___25 ;
  int tmp___101 ;
  unsigned char const   *__s1___12 ;
  register int __result___26 ;
  int tmp___102 ;
  int tmp___103 ;
  int tmp___104 ;
  void *tmp___105 ;
  char const   *tmp___106 ;
  int tmp___107 ;
  int tmp___108 ;
  int tmp___109 ;
  int tmp___110 ;

  {
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2449", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2449", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2449", "-1", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2450", "c", checkpoints_buf);

    c = getopt(argc, (char * const  *)argv, "w:h:c:");
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2450", "c", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2451", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2451", "-1", checkpoints_buf);
    if (c != -1) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2451", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2451", "-1", checkpoints_buf);
    switch (c) {
    sprintf(checkpoints_buf, "%ul", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2455", "tmp", checkpoints_buf);

    case 119: 
    tmp = strtoul((char const   */* __restrict  */)optarg,
                  (char **/* __restrict  */)((void *)0), 0);
    sprintf(checkpoints_buf, "%ul", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2455", "tmp", checkpoints_buf);

    tnw = (uint32 )tmp;

    break;
    sprintf(checkpoints_buf, "%ul", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2458", "tmp___0", checkpoints_buf);

    case 104: 
    tmp___0 = strtoul((char const   */* __restrict  */)optarg,
                      (char **/* __restrict  */)((void *)0), 0);
    sprintf(checkpoints_buf, "%ul", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2458", "tmp___0", checkpoints_buf);

    tnh = (uint32 )tmp___0;

    break;
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2461", "0", checkpoints_buf);
    case 99: 
    if (0) {


      __s1_len___12 = strlen((char const   *)optarg);




      __s2_len___12 = strlen("exp50");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2464", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
        goto _L___26;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2466", "4", checkpoints_buf);
        if (__s1_len___12 >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2467", "1", checkpoints_buf);
          _L___26: /* CIL Label */ 
          if (! ((size_t )((void const   *)("exp50" + 1)) - (size_t )((void const   *)"exp50") == 1U)) {
            tmp___104 = 1;
            sprintf(checkpoints_buf, "%d", tmp___104);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2468", "tmp___104", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2469", "4", checkpoints_buf);
            if (__s2_len___12 >= 4U) {
              tmp___104 = 1;
              sprintf(checkpoints_buf, "%d", tmp___104);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2470", "tmp___104", checkpoints_buf);
            } else {
              tmp___104 = 0;
              sprintf(checkpoints_buf, "%d", tmp___104);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2471", "tmp___104", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2469", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2467", "1", checkpoints_buf);
        } else {
          tmp___104 = 0;
          sprintf(checkpoints_buf, "%d", tmp___104);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2472", "tmp___104", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2466", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2464", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___104);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2473", "tmp___104", checkpoints_buf);
      if (tmp___104) {
        sprintf(checkpoints_buf, "%d", tmp___99);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2474", "tmp___99", checkpoints_buf);

        tmp___99 = __builtin_strcmp((char const   *)optarg, "exp50");
        sprintf(checkpoints_buf, "%d", tmp___99);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2474", "tmp___99", checkpoints_buf);

        tmp___103 = tmp___99;
        sprintf(checkpoints_buf, "%d", tmp___103);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2475", "tmp___103", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___102);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2476", "tmp___102", checkpoints_buf);

        tmp___102 = __builtin_strcmp((char const   *)optarg, "exp50");
        sprintf(checkpoints_buf, "%d", tmp___102);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2476", "tmp___102", checkpoints_buf);

        tmp___103 = tmp___102;
        sprintf(checkpoints_buf, "%d", tmp___103);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2477", "tmp___103", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___104);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2473", "tmp___104", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___102);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2478", "tmp___102", checkpoints_buf);

      tmp___102 = __builtin_strcmp((char const   *)optarg, "exp50");
      sprintf(checkpoints_buf, "%d", tmp___102);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2478", "tmp___102", checkpoints_buf);

      tmp___103 = tmp___102;
      sprintf(checkpoints_buf, "%d", tmp___103);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2479", "tmp___103", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2461", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___103);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2480", "tmp___103", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2480", "0", checkpoints_buf);
    if (tmp___103 == 0) {
      contrast = (Contrast )0;

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2482", "0", checkpoints_buf);
      if (0) {


        __s1_len___11 = strlen((char const   *)optarg);




        __s2_len___11 = strlen("exp60");


        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2485", "1", checkpoints_buf);
        if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
          goto _L___24;
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2487", "4", checkpoints_buf);
          if (__s1_len___11 >= 4U) {
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2488", "1", checkpoints_buf);
            _L___24: /* CIL Label */ 
            if (! ((size_t )((void const   *)("exp60" + 1)) - (size_t )((void const   *)"exp60") == 1U)) {
              tmp___97 = 1;
              sprintf(checkpoints_buf, "%d", tmp___97);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2489", "tmp___97", checkpoints_buf);
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2490", "4", checkpoints_buf);
              if (__s2_len___11 >= 4U) {
                tmp___97 = 1;
                sprintf(checkpoints_buf, "%d", tmp___97);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2491", "tmp___97", checkpoints_buf);
              } else {
                tmp___97 = 0;
                sprintf(checkpoints_buf, "%d", tmp___97);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2492", "tmp___97", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2490", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2488", "1", checkpoints_buf);
          } else {
            tmp___97 = 0;
            sprintf(checkpoints_buf, "%d", tmp___97);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2493", "tmp___97", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2487", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2485", "1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___97);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2494", "tmp___97", checkpoints_buf);
        if (tmp___97) {
          sprintf(checkpoints_buf, "%d", tmp___92);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2495", "tmp___92", checkpoints_buf);

          tmp___92 = __builtin_strcmp((char const   *)optarg, "exp60");
          sprintf(checkpoints_buf, "%d", tmp___92);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2495", "tmp___92", checkpoints_buf);

          tmp___96 = tmp___92;
          sprintf(checkpoints_buf, "%d", tmp___96);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2496", "tmp___96", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___95);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2497", "tmp___95", checkpoints_buf);

          tmp___95 = __builtin_strcmp((char const   *)optarg, "exp60");
          sprintf(checkpoints_buf, "%d", tmp___95);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2497", "tmp___95", checkpoints_buf);

          tmp___96 = tmp___95;
          sprintf(checkpoints_buf, "%d", tmp___96);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2498", "tmp___96", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___97);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2494", "tmp___97", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___95);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2499", "tmp___95", checkpoints_buf);

        tmp___95 = __builtin_strcmp((char const   *)optarg, "exp60");
        sprintf(checkpoints_buf, "%d", tmp___95);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2499", "tmp___95", checkpoints_buf);

        tmp___96 = tmp___95;
        sprintf(checkpoints_buf, "%d", tmp___96);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2500", "tmp___96", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2482", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___96);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2501", "tmp___96", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2501", "0", checkpoints_buf);
      if (tmp___96 == 0) {
        tmp___90 = 1;
        sprintf(checkpoints_buf, "%d", tmp___90);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2502", "tmp___90", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2503", "0", checkpoints_buf);
        if (0) {


          __s1_len___10 = strlen((char const   *)optarg);




          __s2_len___10 = strlen("exp70");


          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2506", "1", checkpoints_buf);
          if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
            goto _L___22;
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2508", "4", checkpoints_buf);
            if (__s1_len___10 >= 4U) {
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2509", "1", checkpoints_buf);
              _L___22: /* CIL Label */ 
              if (! ((size_t )((void const   *)("exp70" + 1)) - (size_t )((void const   *)"exp70") == 1U)) {
                tmp___89 = 1;
                sprintf(checkpoints_buf, "%d", tmp___89);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2510", "tmp___89", checkpoints_buf);
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2511", "4", checkpoints_buf);
                if (__s2_len___10 >= 4U) {
                  tmp___89 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___89);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2512", "tmp___89", checkpoints_buf);
                } else {
                  tmp___89 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___89);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2513", "tmp___89", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2511", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2509", "1", checkpoints_buf);
            } else {
              tmp___89 = 0;
              sprintf(checkpoints_buf, "%d", tmp___89);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2514", "tmp___89", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2508", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2506", "1", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___89);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2515", "tmp___89", checkpoints_buf);
          if (tmp___89) {
            sprintf(checkpoints_buf, "%d", tmp___84);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2516", "tmp___84", checkpoints_buf);

            tmp___84 = __builtin_strcmp((char const   *)optarg, "exp70");
            sprintf(checkpoints_buf, "%d", tmp___84);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2516", "tmp___84", checkpoints_buf);

            tmp___88 = tmp___84;
            sprintf(checkpoints_buf, "%d", tmp___88);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2517", "tmp___88", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___87);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2518", "tmp___87", checkpoints_buf);

            tmp___87 = __builtin_strcmp((char const   *)optarg, "exp70");
            sprintf(checkpoints_buf, "%d", tmp___87);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2518", "tmp___87", checkpoints_buf);

            tmp___88 = tmp___87;
            sprintf(checkpoints_buf, "%d", tmp___88);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2519", "tmp___88", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___89);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2515", "tmp___89", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___87);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2520", "tmp___87", checkpoints_buf);

          tmp___87 = __builtin_strcmp((char const   *)optarg, "exp70");
          sprintf(checkpoints_buf, "%d", tmp___87);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2520", "tmp___87", checkpoints_buf);

          tmp___88 = tmp___87;
          sprintf(checkpoints_buf, "%d", tmp___88);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2521", "tmp___88", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2503", "0", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___88);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2522", "tmp___88", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2522", "0", checkpoints_buf);
        if (tmp___88 == 0) {
          tmp___82 = 2;
          sprintf(checkpoints_buf, "%d", tmp___82);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2523", "tmp___82", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2524", "0", checkpoints_buf);
          if (0) {


            __s1_len___9 = strlen((char const   *)optarg);




            __s2_len___9 = strlen("exp80");


            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2527", "1", checkpoints_buf);
            if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
              goto _L___20;
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2529", "4", checkpoints_buf);
              if (__s1_len___9 >= 4U) {
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2530", "1", checkpoints_buf);
                _L___20: /* CIL Label */ 
                if (! ((size_t )((void const   *)("exp80" + 1)) - (size_t )((void const   *)"exp80") == 1U)) {
                  tmp___81 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___81);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2531", "tmp___81", checkpoints_buf);
                } else {

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2532", "4", checkpoints_buf);
                  if (__s2_len___9 >= 4U) {
                    tmp___81 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___81);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2533", "tmp___81", checkpoints_buf);
                  } else {
                    tmp___81 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___81);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2534", "tmp___81", checkpoints_buf);
                  }

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2532", "4", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2530", "1", checkpoints_buf);
              } else {
                tmp___81 = 0;
                sprintf(checkpoints_buf, "%d", tmp___81);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2535", "tmp___81", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2529", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2527", "1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___81);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2536", "tmp___81", checkpoints_buf);
            if (tmp___81) {
              sprintf(checkpoints_buf, "%d", tmp___76);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2537", "tmp___76", checkpoints_buf);

              tmp___76 = __builtin_strcmp((char const   *)optarg, "exp80");
              sprintf(checkpoints_buf, "%d", tmp___76);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2537", "tmp___76", checkpoints_buf);

              tmp___80 = tmp___76;
              sprintf(checkpoints_buf, "%d", tmp___80);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2538", "tmp___80", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___79);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2539", "tmp___79", checkpoints_buf);

              tmp___79 = __builtin_strcmp((char const   *)optarg, "exp80");
              sprintf(checkpoints_buf, "%d", tmp___79);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2539", "tmp___79", checkpoints_buf);

              tmp___80 = tmp___79;
              sprintf(checkpoints_buf, "%d", tmp___80);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2540", "tmp___80", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___81);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2536", "tmp___81", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___79);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2541", "tmp___79", checkpoints_buf);

            tmp___79 = __builtin_strcmp((char const   *)optarg, "exp80");
            sprintf(checkpoints_buf, "%d", tmp___79);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2541", "tmp___79", checkpoints_buf);

            tmp___80 = tmp___79;
            sprintf(checkpoints_buf, "%d", tmp___80);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2542", "tmp___80", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2524", "0", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___80);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2543", "tmp___80", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2543", "0", checkpoints_buf);
          if (tmp___80 == 0) {
            tmp___74 = 3;
            sprintf(checkpoints_buf, "%d", tmp___74);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2544", "tmp___74", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2545", "0", checkpoints_buf);
            if (0) {


              __s1_len___8 = strlen((char const   *)optarg);




              __s2_len___8 = strlen("exp90");


              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2548", "1", checkpoints_buf);
              if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
                goto _L___18;
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2550", "4", checkpoints_buf);
                if (__s1_len___8 >= 4U) {
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2551", "1", checkpoints_buf);
                  _L___18: /* CIL Label */ 
                  if (! ((size_t )((void const   *)("exp90" + 1)) - (size_t )((void const   *)"exp90") == 1U)) {
                    tmp___73 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___73);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2552", "tmp___73", checkpoints_buf);
                  } else {

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2553", "4", checkpoints_buf);
                    if (__s2_len___8 >= 4U) {
                      tmp___73 = 1;
                      sprintf(checkpoints_buf, "%d", tmp___73);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2554", "tmp___73", checkpoints_buf);
                    } else {
                      tmp___73 = 0;
                      sprintf(checkpoints_buf, "%d", tmp___73);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2555", "tmp___73", checkpoints_buf);
                    }

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2553", "4", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2551", "1", checkpoints_buf);
                } else {
                  tmp___73 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___73);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2556", "tmp___73", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2550", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2548", "1", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___73);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2557", "tmp___73", checkpoints_buf);
              if (tmp___73) {
                sprintf(checkpoints_buf, "%d", tmp___68);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2558", "tmp___68", checkpoints_buf);

                tmp___68 = __builtin_strcmp((char const   *)optarg, "exp90");
                sprintf(checkpoints_buf, "%d", tmp___68);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2558", "tmp___68", checkpoints_buf);

                tmp___72 = tmp___68;
                sprintf(checkpoints_buf, "%d", tmp___72);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2559", "tmp___72", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", tmp___71);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2560", "tmp___71", checkpoints_buf);

                tmp___71 = __builtin_strcmp((char const   *)optarg, "exp90");
                sprintf(checkpoints_buf, "%d", tmp___71);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2560", "tmp___71", checkpoints_buf);

                tmp___72 = tmp___71;
                sprintf(checkpoints_buf, "%d", tmp___72);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2561", "tmp___72", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", tmp___73);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2557", "tmp___73", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___71);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2562", "tmp___71", checkpoints_buf);

              tmp___71 = __builtin_strcmp((char const   *)optarg, "exp90");
              sprintf(checkpoints_buf, "%d", tmp___71);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2562", "tmp___71", checkpoints_buf);

              tmp___72 = tmp___71;
              sprintf(checkpoints_buf, "%d", tmp___72);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2563", "tmp___72", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2545", "0", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___72);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2564", "tmp___72", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2564", "0", checkpoints_buf);
            if (tmp___72 == 0) {
              tmp___66 = 4;
              sprintf(checkpoints_buf, "%d", tmp___66);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2565", "tmp___66", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2566", "0", checkpoints_buf);
              if (0) {


                __s1_len___7 = strlen((char const   *)optarg);




                __s2_len___7 = strlen("exp");


                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2569", "1", checkpoints_buf);
                if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
                  goto _L___16;
                } else {

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2571", "4", checkpoints_buf);
                  if (__s1_len___7 >= 4U) {
                    sprintf(checkpoints_buf, "%u", 1);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2572", "1", checkpoints_buf);
                    _L___16: /* CIL Label */ 
                    if (! ((size_t )((void const   *)("exp" + 1)) - (size_t )((void const   *)"exp") == 1U)) {
                      tmp___65 = 1;
                      sprintf(checkpoints_buf, "%d", tmp___65);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2573", "tmp___65", checkpoints_buf);
                    } else {

                      sprintf(checkpoints_buf, "%u", 4);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2574", "4", checkpoints_buf);
                      if (__s2_len___7 >= 4U) {
                        tmp___65 = 1;
                        sprintf(checkpoints_buf, "%d", tmp___65);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                        "2575", "tmp___65", checkpoints_buf);
                      } else {
                        tmp___65 = 0;
                        sprintf(checkpoints_buf, "%d", tmp___65);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                        "2576", "tmp___65", checkpoints_buf);
                      }

                      sprintf(checkpoints_buf, "%u", 4);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2574", "4", checkpoints_buf);
                    }
                    sprintf(checkpoints_buf, "%u", 1);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2572", "1", checkpoints_buf);
                  } else {
                    tmp___65 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___65);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2577", "tmp___65", checkpoints_buf);
                  }

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2571", "4", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2569", "1", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", tmp___65);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2578", "tmp___65", checkpoints_buf);
                if (tmp___65) {
                  sprintf(checkpoints_buf, "%d", tmp___60);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2579", "tmp___60", checkpoints_buf);

                  tmp___60 = __builtin_strcmp((char const   *)optarg, "exp");
                  sprintf(checkpoints_buf, "%d", tmp___60);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2579", "tmp___60", checkpoints_buf);

                  tmp___64 = tmp___60;
                  sprintf(checkpoints_buf, "%d", tmp___64);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2580", "tmp___64", checkpoints_buf);
                } else {
                  sprintf(checkpoints_buf, "%d", tmp___63);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2581", "tmp___63", checkpoints_buf);

                  tmp___63 = __builtin_strcmp((char const   *)optarg, "exp");
                  sprintf(checkpoints_buf, "%d", tmp___63);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2581", "tmp___63", checkpoints_buf);

                  tmp___64 = tmp___63;
                  sprintf(checkpoints_buf, "%d", tmp___64);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2582", "tmp___64", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%d", tmp___65);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2578", "tmp___65", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", tmp___63);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2583", "tmp___63", checkpoints_buf);

                tmp___63 = __builtin_strcmp((char const   *)optarg, "exp");
                sprintf(checkpoints_buf, "%d", tmp___63);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2583", "tmp___63", checkpoints_buf);

                tmp___64 = tmp___63;
                sprintf(checkpoints_buf, "%d", tmp___64);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2584", "tmp___64", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2566", "0", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___64);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2585", "tmp___64", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2585", "0", checkpoints_buf);
              if (tmp___64 == 0) {
                tmp___58 = 5;
                sprintf(checkpoints_buf, "%d", tmp___58);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2586", "tmp___58", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2587", "0", checkpoints_buf);
                if (0) {


                  __s1_len___6 = strlen((char const   *)optarg);




                  __s2_len___6 = strlen("linear");


                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2590", "1", checkpoints_buf);
                  if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
                    goto _L___14;
                  } else {

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2592", "4", checkpoints_buf);
                    if (__s1_len___6 >= 4U) {
                      sprintf(checkpoints_buf, "%u", 1);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2593", "1", checkpoints_buf);
                      _L___14: /* CIL Label */ 
                      if (! ((size_t )((void const   *)("linear" + 1)) - (size_t )((void const   *)"linear") == 1U)) {
                        tmp___57 = 1;
                        sprintf(checkpoints_buf, "%d", tmp___57);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                        "2594", "tmp___57", checkpoints_buf);
                      } else {

                        sprintf(checkpoints_buf, "%u", 4);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                        "2595", "4", checkpoints_buf);
                        if (__s2_len___6 >= 4U) {
                          tmp___57 = 1;
                          sprintf(checkpoints_buf, "%d", tmp___57);
                          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                          "2596", "tmp___57", checkpoints_buf);
                        } else {
                          tmp___57 = 0;
                          sprintf(checkpoints_buf, "%d", tmp___57);
                          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                          "2597", "tmp___57", checkpoints_buf);
                        }

                        sprintf(checkpoints_buf, "%u", 4);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                        "2595", "4", checkpoints_buf);
                      }
                      sprintf(checkpoints_buf, "%u", 1);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2593", "1", checkpoints_buf);
                    } else {
                      tmp___57 = 0;
                      sprintf(checkpoints_buf, "%d", tmp___57);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                      "2598", "tmp___57", checkpoints_buf);
                    }

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2592", "4", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2590", "1", checkpoints_buf);
                  sprintf(checkpoints_buf, "%d", tmp___57);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2599", "tmp___57", checkpoints_buf);
                  if (tmp___57) {
                    sprintf(checkpoints_buf, "%d", tmp___52);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2600", "tmp___52", checkpoints_buf);

                    tmp___52 = __builtin_strcmp((char const   *)optarg, "linear");
                    sprintf(checkpoints_buf, "%d", tmp___52);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2600", "tmp___52", checkpoints_buf);

                    tmp___56 = tmp___52;
                    sprintf(checkpoints_buf, "%d", tmp___56);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2601", "tmp___56", checkpoints_buf);
                  } else {
                    sprintf(checkpoints_buf, "%d", tmp___55);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2602", "tmp___55", checkpoints_buf);

                    tmp___55 = __builtin_strcmp((char const   *)optarg, "linear");
                    sprintf(checkpoints_buf, "%d", tmp___55);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2602", "tmp___55", checkpoints_buf);

                    tmp___56 = tmp___55;
                    sprintf(checkpoints_buf, "%d", tmp___56);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                    "2603", "tmp___56", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%d", tmp___57);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2599", "tmp___57", checkpoints_buf);
                } else {
                  sprintf(checkpoints_buf, "%d", tmp___55);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2604", "tmp___55", checkpoints_buf);

                  tmp___55 = __builtin_strcmp((char const   *)optarg, "linear");
                  sprintf(checkpoints_buf, "%d", tmp___55);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2604", "tmp___55", checkpoints_buf);

                  tmp___56 = tmp___55;
                  sprintf(checkpoints_buf, "%d", tmp___56);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2605", "tmp___56", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2587", "0", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", tmp___56);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2606", "tmp___56", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2606", "0", checkpoints_buf);
                if (tmp___56 == 0) {
                  tmp___50 = 6;
                  sprintf(checkpoints_buf, "%d", tmp___50);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2607", "tmp___50", checkpoints_buf);
                } else {
                  tmp___50 = 5;
                  sprintf(checkpoints_buf, "%d", tmp___50);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                  "2608", "tmp___50", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%d", tmp___56);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2606", "tmp___56", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2606", "0", checkpoints_buf);
                tmp___58 = tmp___50;
                sprintf(checkpoints_buf, "%d", tmp___58);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2609", "tmp___58", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", tmp___64);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2585", "tmp___64", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2585", "0", checkpoints_buf);
              tmp___66 = tmp___58;
              sprintf(checkpoints_buf, "%d", tmp___66);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                              "2610", "tmp___66", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___72);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2564", "tmp___72", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2564", "0", checkpoints_buf);
            tmp___74 = tmp___66;
            sprintf(checkpoints_buf, "%d", tmp___74);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2611", "tmp___74", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___80);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2543", "tmp___80", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2543", "0", checkpoints_buf);
          tmp___82 = tmp___74;
          sprintf(checkpoints_buf, "%d", tmp___82);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2612", "tmp___82", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___88);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2522", "tmp___88", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2522", "0", checkpoints_buf);
        tmp___90 = tmp___82;
        sprintf(checkpoints_buf, "%d", tmp___90);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2613", "tmp___90", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___96);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2501", "tmp___96", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2501", "0", checkpoints_buf);
      contrast = (Contrast )tmp___90;

    }
    sprintf(checkpoints_buf, "%d", tmp___103);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2480", "tmp___103", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2480", "0", checkpoints_buf);
    break;

    default: 
    usage();

    }
  }
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2449", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2449", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2449", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2617", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2617", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2617", "2", checkpoints_buf);
  if (argc - optind != 2) {

    usage();

  } else {

  }
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2617", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2617", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2617", "2", checkpoints_buf);


  out = TIFFOpen((char const   *)*(argv + (optind + 1)), "w");


  if ((unsigned int )out == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2622", "2", checkpoints_buf);
    return (2);
  } else {

  }


  in = TIFFOpen((char const   *)*(argv + optind), "r");


  if ((unsigned int )in == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2626", "2", checkpoints_buf);
    return (2);
  } else {

  }


  tmp___105 = _TIFFmalloc((tmsize_t )(tnw * tnh));


  thumbnail = (uint8 *)tmp___105;


  if (! thumbnail) {


    tmp___106 = TIFFFileName(in);



    TIFFError(tmp___106, "Can\'t allocate space for thumbnail buffer.");

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2633", "1", checkpoints_buf);
    return (1);
  } else {

  }

  if ((unsigned int )in != (unsigned int )((void *)0)) {

    initScale();

    sprintf(checkpoints_buf, "%d", tmp___107);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___107", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___107);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___107", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___108);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___108", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___108);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___108", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___110);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___110", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___110);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___110", checkpoints_buf);
    while (1) {
      sprintf(checkpoints_buf, "%d", tmp___107);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2638", "tmp___107", checkpoints_buf);

      tmp___107 = generateThumbnail(in, out);
      sprintf(checkpoints_buf, "%d", tmp___107);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2638", "tmp___107", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___107);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2639", "tmp___107", checkpoints_buf);
      if (tmp___107) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___107);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2639", "tmp___107", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___108);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2642", "tmp___108", checkpoints_buf);

      tmp___108 = cpIFD(in, out);
      sprintf(checkpoints_buf, "%d", tmp___108);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2642", "tmp___108", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___108);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2643", "tmp___108", checkpoints_buf);
      if (tmp___108) {
        sprintf(checkpoints_buf, "%d", tmp___109);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2644", "tmp___109", checkpoints_buf);

        tmp___109 = TIFFWriteDirectory(out);
        sprintf(checkpoints_buf, "%d", tmp___109);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2644", "tmp___109", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___109);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2645", "tmp___109", checkpoints_buf);
        if (tmp___109) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___109);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2645", "tmp___109", checkpoints_buf);
      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___108);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2643", "tmp___108", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___110);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2649", "tmp___110", checkpoints_buf);

      tmp___110 = TIFFReadDirectory(in);
      sprintf(checkpoints_buf, "%d", tmp___110);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2649", "tmp___110", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___110);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2650", "tmp___110", checkpoints_buf);
      if (tmp___110) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%d", tmp___110);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2650", "tmp___110", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___107);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___107", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___107);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___107", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___108);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___108", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___108);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___108", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___110);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___110", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___110);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2637", "tmp___110", checkpoints_buf);

    TIFFClose(in);

  } else {

  }

  TIFFClose(out);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2656", "0", checkpoints_buf);
  return (0);

  bad: 
  TIFFClose(out);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2658", "1", checkpoints_buf);
  return (1);
}
}
static void cpTag(TIFF *in , TIFF *out , uint16 tag , uint16 count ,
                  TIFFDataType type ) 
{ 
  uint16 shortv ;
  int tmp ;
  uint16 shortv1 ;
  uint16 shortv2 ;
  int tmp___0 ;
  uint16 *tr ;
  uint16 *tg ;
  uint16 *tb ;
  uint16 *ta ;
  int tmp___1 ;
  uint16 shortv1___0 ;
  uint16 *shortav ;
  int tmp___2 ;
  uint32 longv ;
  int tmp___3 ;
  float floatv ;
  int tmp___4 ;
  float *floatav ;
  int tmp___5 ;
  char *stringv ;
  int tmp___6 ;
  double doublev ;
  int tmp___7 ;
  double *doubleav ;
  int tmp___8 ;
  char const   *tmp___9 ;

  {
  switch ((unsigned int )type) {
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2660", "1", checkpoints_buf);
  case 3U: 
  if ((int )count == 1) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2661", "tmp", checkpoints_buf);

    tmp = TIFFGetField(in, (uint32 )tag, & shortv);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2661", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2662", "tmp", checkpoints_buf);
    if (tmp) {

      TIFFSetField(out, (uint32 )tag, (int )shortv);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2662", "tmp", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2665", "2", checkpoints_buf);
    if ((int )count == 2) {
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2666", "tmp___0", checkpoints_buf);

      tmp___0 = TIFFGetField(in, (uint32 )tag, & shortv1, & shortv2);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2666", "tmp___0", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2667", "tmp___0", checkpoints_buf);
      if (tmp___0) {

        TIFFSetField(out, (uint32 )tag, (int )shortv1, (int )shortv2);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2667", "tmp___0", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2670", "4", checkpoints_buf);
      if ((int )count == 4) {
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2671", "tmp___1", checkpoints_buf);

        tmp___1 = TIFFGetField(in, (uint32 )tag, & tr, & tg, & tb, & ta);
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2671", "tmp___1", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2672", "tmp___1", checkpoints_buf);
        if (tmp___1) {

          TIFFSetField(out, (uint32 )tag, tr, tg, tb, ta);

        } else {

        }
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2672", "tmp___1", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2675", "65535", checkpoints_buf);
        if ((int )count == 65535) {
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2676", "tmp___2", checkpoints_buf);

          tmp___2 = TIFFGetField(in, (uint32 )tag, & shortv1___0, & shortav);
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2676", "tmp___2", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2677", "tmp___2", checkpoints_buf);
          if (tmp___2) {

            TIFFSetField(out, (uint32 )tag, (int )shortv1___0, shortav);

          } else {

          }
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2677", "tmp___2", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2675", "65535", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2670", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2665", "2", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2660", "1", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2682", "tmp___3", checkpoints_buf);

  case 4U: 
  tmp___3 = TIFFGetField(in, (uint32 )tag, & longv);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2682", "tmp___3", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2683", "tmp___3", checkpoints_buf);
  if (tmp___3) {

    TIFFSetField(out, (uint32 )tag, longv);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2683", "tmp___3", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2687", "1", checkpoints_buf);
  case 5U: 
  if ((int )count == 1) {
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2688", "tmp___4", checkpoints_buf);

    tmp___4 = TIFFGetField(in, (uint32 )tag, & floatv);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2688", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2689", "tmp___4", checkpoints_buf);
    if (tmp___4) {

      TIFFSetField(out, (uint32 )tag, (double )floatv);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2689", "tmp___4", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2692", "65535", checkpoints_buf);
    if ((int )count == 65535) {
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2693", "tmp___5", checkpoints_buf);

      tmp___5 = TIFFGetField(in, (uint32 )tag, & floatav);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2693", "tmp___5", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2694", "tmp___5", checkpoints_buf);
      if (tmp___5) {

        TIFFSetField(out, (uint32 )tag, floatav);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2694", "tmp___5", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2692", "65535", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2687", "1", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2699", "tmp___6", checkpoints_buf);

  case 2U: 
  tmp___6 = TIFFGetField(in, (uint32 )tag, & stringv);
  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2699", "tmp___6", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2700", "tmp___6", checkpoints_buf);
  if (tmp___6) {

    TIFFSetField(out, (uint32 )tag, stringv);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2700", "tmp___6", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2704", "1", checkpoints_buf);
  case 12U: 
  if ((int )count == 1) {
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2705", "tmp___7", checkpoints_buf);

    tmp___7 = TIFFGetField(in, (uint32 )tag, & doublev);
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2705", "tmp___7", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2706", "tmp___7", checkpoints_buf);
    if (tmp___7) {

      TIFFSetField(out, (uint32 )tag, doublev);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2706", "tmp___7", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2709", "65535", checkpoints_buf);
    if ((int )count == 65535) {
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2710", "tmp___8", checkpoints_buf);

      tmp___8 = TIFFGetField(in, (uint32 )tag, & doubleav);
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2710", "tmp___8", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2711", "tmp___8", checkpoints_buf);
      if (tmp___8) {

        TIFFSetField(out, (uint32 )tag, doubleav);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2711", "tmp___8", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2709", "65535", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2704", "1", checkpoints_buf);
  break;


  default: 
  tmp___9 = TIFFFileName(in);



  TIFFError(tmp___9, "Data type %d is not supported, tag %d skipped.",
            (int )tag, (unsigned int )type);

  }
  return;
}
}
static struct cpTag tags[47]  = 
  {      {(uint16 )256, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )257, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )258, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )259, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )266, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )277, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )278, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )284, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )292, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )254, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )262, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )263, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )269, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )270, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )271, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )272, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )274, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )280, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )281, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )282, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )283, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )285, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )286, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )287, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )293, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )296, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )297, (uint16 )2, (TIFFDataType )3}, 
        {(uint16 )305, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )306, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )315, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )316, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )318, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )319, (uint16 )-1, (TIFFDataType )5}, 
        {(uint16 )321, (uint16 )2, (TIFFDataType )3}, 
        {(uint16 )326, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )327, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )328, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )332, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )333, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )336, (uint16 )2, (TIFFDataType )3}, 
        {(uint16 )337, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )339, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )529, (uint16 )-1, (TIFFDataType )5}, 
        {(uint16 )530, (uint16 )2, (TIFFDataType )3}, 
        {(uint16 )531, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )532, (uint16 )-1, (TIFFDataType )5}, 
        {(uint16 )338, (uint16 )-1, (TIFFDataType )3}};
static void cpTags(TIFF *in , TIFF *out ) 
{ 
  struct cpTag *p ;

  {
  p = tags;



  while ((unsigned int )p < (unsigned int )(& tags[sizeof(tags) / sizeof(tags[0])])) {

    cpTag(in, out, p->tag, p->count, p->type);

    p ++;

  }


  return;
}
}
static int cpStrips(TIFF *in , TIFF *out ) 
{ 
  tsize_t bufsize ;
  tmsize_t tmp ;
  unsigned char *buf ;
  void *tmp___0 ;
  tstrip_t s ;
  tstrip_t ns ;
  uint32 tmp___1 ;
  tsize_t *bytecounts ;
  void *tmp___2 ;
  tmsize_t tmp___3 ;
  tmsize_t tmp___4 ;
  char const   *tmp___5 ;

  {


  tmp = TIFFStripSize(in);


  bufsize = tmp;



  tmp___0 = _TIFFmalloc(bufsize);


  buf = (unsigned char *)tmp___0;


  if (buf) {


    tmp___1 = TIFFNumberOfStrips(in);


    ns = tmp___1;


    TIFFGetField(in, (uint32 )279, & bytecounts);

    s = (tstrip_t )0;








    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2736", "0", checkpoints_buf);

    while (s < ns) {




      if (*(bytecounts + s) > bufsize) {


        tmp___2 = _TIFFrealloc((void *)buf, *(bytecounts + s));


        buf = (unsigned char *)tmp___2;


        if (! buf) {
          goto bad;
        } else {

        }

        bufsize = *(bytecounts + s);

      } else {

      }




      tmp___3 = TIFFReadRawStrip(in, s, (void *)buf, *(bytecounts + s));



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2749", "0", checkpoints_buf);
      if (tmp___3 < 0L) {

        _TIFFfree((void *)buf);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2751", "0", checkpoints_buf);
        return (0);
      } else {


        tmp___4 = TIFFWriteRawStrip(out, s, (void *)buf, *(bytecounts + s));



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2753", "0", checkpoints_buf);
        if (tmp___4 < 0L) {

          _TIFFfree((void *)buf);

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2755", "0", checkpoints_buf);
          return (0);
        } else {

        }

        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2753", "0", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2749", "0", checkpoints_buf);
      s ++;

    }







    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2736", "0", checkpoints_buf);


    _TIFFfree((void *)buf);

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2759", "1", checkpoints_buf);
    return (1);
  } else {

  }



  bad: 
  tmp___5 = TIFFFileName(in);



  TIFFError(tmp___5, "Can\'t allocate space for strip buffer.");

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2763", "0", checkpoints_buf);
  return (0);
}
}
static int cpTiles(TIFF *in , TIFF *out ) 
{ 
  tsize_t bufsize ;
  tmsize_t tmp ;
  unsigned char *buf ;
  void *tmp___0 ;
  ttile_t t ;
  ttile_t nt ;
  uint32 tmp___1 ;
  tsize_t *bytecounts ;
  void *tmp___2 ;
  tmsize_t tmp___3 ;
  tmsize_t tmp___4 ;
  char const   *tmp___5 ;

  {


  tmp = TIFFTileSize(in);


  bufsize = tmp;



  tmp___0 = _TIFFmalloc(bufsize);


  buf = (unsigned char *)tmp___0;


  if (buf) {


    tmp___1 = TIFFNumberOfTiles(in);


    nt = tmp___1;


    TIFFGetField(in, (uint32 )325, & bytecounts);

    t = (ttile_t )0;








    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2773", "0", checkpoints_buf);

    while (t < nt) {




      if (*(bytecounts + t) > bufsize) {


        tmp___2 = _TIFFrealloc((void *)buf, *(bytecounts + t));


        buf = (unsigned char *)tmp___2;


        if (! buf) {
          goto bad;
        } else {

        }

        bufsize = *(bytecounts + t);

      } else {

      }




      tmp___3 = TIFFReadRawTile(in, t, (void *)buf, *(bytecounts + t));



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2786", "0", checkpoints_buf);
      if (tmp___3 < 0L) {

        _TIFFfree((void *)buf);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2788", "0", checkpoints_buf);
        return (0);
      } else {


        tmp___4 = TIFFWriteRawTile(out, t, (void *)buf, *(bytecounts + t));



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2790", "0", checkpoints_buf);
        if (tmp___4 < 0L) {

          _TIFFfree((void *)buf);

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2792", "0", checkpoints_buf);
          return (0);
        } else {

        }

        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2790", "0", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2786", "0", checkpoints_buf);
      t ++;

    }







    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2773", "0", checkpoints_buf);


    _TIFFfree((void *)buf);

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2796", "1", checkpoints_buf);
    return (1);
  } else {

  }



  bad: 
  tmp___5 = TIFFFileName(in);



  TIFFError(tmp___5, "Can\'t allocate space for tile buffer.");

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2800", "0", checkpoints_buf);
  return (0);
}
}
static int cpIFD(TIFF *in , TIFF *out ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {

  cpTags(in, out);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2802", "tmp___1", checkpoints_buf);

  tmp___1 = TIFFIsTiled(in);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2802", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2803", "tmp___1", checkpoints_buf);
  if (tmp___1) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2804", "tmp", checkpoints_buf);

    tmp = cpTiles(in, out);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2804", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2805", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2807", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2805", "tmp", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2808", "tmp___0", checkpoints_buf);

    tmp___0 = cpStrips(in, out);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2808", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2809", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2811", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2809", "tmp___0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2803", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2812", "1", checkpoints_buf);
  return (1);
}
}
static uint16 photometric  ;
static uint16 filterWidth  ;
static uint32 stepSrcWidth  ;
static uint32 stepDstWidth  ;
static uint8 *src0  ;
static uint8 *src1  ;
static uint8 *src2  ;
static uint32 *rowoff  ;
static uint8 cmap[256]  ;
static uint8 bits[256]  ;
static void setupBitsTables(void) 
{ 
  int i ;
  int n ;

  {
  i = 0;
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2813", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "256", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "16", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "64", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "128", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2815", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2815", "256", checkpoints_buf);
    if (i < 256) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2815", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2815", "256", checkpoints_buf);
    n = 0;
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2818", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2819", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2819", "1", checkpoints_buf);
    if (i & 1) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2820", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2819", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2819", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2822", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2822", "2", checkpoints_buf);
    if (i & 2) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2823", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2822", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2822", "2", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2825", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2825", "4", checkpoints_buf);
    if (i & 4) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2826", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2825", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2825", "4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2828", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2828", "8", checkpoints_buf);
    if (i & 8) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2829", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2828", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2828", "8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2831", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2831", "16", checkpoints_buf);
    if (i & 16) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2832", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2831", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2831", "16", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2834", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2834", "32", checkpoints_buf);
    if (i & 32) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2835", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2834", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2834", "32", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2837", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 64);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2837", "64", checkpoints_buf);
    if (i & 64) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2838", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2837", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 64);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2837", "64", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2840", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2840", "128", checkpoints_buf);
    if (i & 128) {
      n ++;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2841", "n", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2840", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2840", "128", checkpoints_buf);
    bits[i] = (uint8 )n;

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2844", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "256", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "16", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "64", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "128", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2814", "i", checkpoints_buf);
  return;
}
}
static int clamp(float v , int low , int high ) 
{ 
  int tmp ;
  int tmp___0 ;

  {
  sprintf(checkpoints_buf, "%f", v);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2846", "v", checkpoints_buf);
  if (v < (float )low) {
    tmp___0 = low;
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2847", "tmp___0", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%f", v);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2848", "v", checkpoints_buf);
    if (v > (float )high) {
      tmp = high;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2849", "tmp", checkpoints_buf);
    } else {
      tmp = (int )v;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2850", "tmp", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%f", v);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2848", "v", checkpoints_buf);
    tmp___0 = tmp;
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2851", "tmp___0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%f", v);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2846", "v", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2852", "tmp___0", checkpoints_buf);
  return (tmp___0);
}
}
static void expFill(float *pct , uint32 p , uint32 n ) 
{ 
  uint32 i ;
  uint32 c ;
  double tmp ;

  {
  c = (p * n) / 100U;

  i = (uint32 )1;



  sprintf(checkpoints_buf, "%lf", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2855", "tmp", checkpoints_buf);



  while (i < c) {


    sprintf(checkpoints_buf, "%lf", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2859", "tmp", checkpoints_buf);

    tmp = exp((double )i / (double )(n - 1U));
    sprintf(checkpoints_buf, "%lf", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2859", "tmp", checkpoints_buf);

    *(pct + i) = (float )((double )1 - tmp / 2.7182818284590452354);

    i ++;

  }


  sprintf(checkpoints_buf, "%lf", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2855", "tmp", checkpoints_buf);







  while (i < n) {


    *(pct + i) = (float )0.;

    i ++;

  }




  return;
}
}
static void setupCmap(void) 
{ 
  float pct[256] ;
  uint32 i ;
  int tmp ;
  int tmp___0 ;

  {
  pct[0] = (float )1;

  switch ((unsigned int )contrast) {

  case 0U: 
  expFill(pct, (uint32 )50, (uint32 )256);

  break;

  case 1U: 
  expFill(pct, (uint32 )60, (uint32 )256);

  break;

  case 2U: 
  expFill(pct, (uint32 )70, (uint32 )256);

  break;

  case 3U: 
  expFill(pct, (uint32 )80, (uint32 )256);

  break;

  case 4U: 
  expFill(pct, (uint32 )90, (uint32 )256);

  break;

  case 5U: 
  expFill(pct, (uint32 )100, (uint32 )256);

  break;
  case 6U: 
  i = (uint32 )1;


  sprintf(checkpoints_buf, "%u", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2884", "256", checkpoints_buf);


  while (1) {

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2885", "256", checkpoints_buf);
    if (i < 256U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2885", "256", checkpoints_buf);
    pct[i] = (float )1 - (float )i / (float )255;

    i ++;

  }

  sprintf(checkpoints_buf, "%u", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2884", "256", checkpoints_buf);


  break;
  }
  switch ((int )photometric) {
  case 0: 
  i = (uint32 )0;


  sprintf(checkpoints_buf, "%u", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2893", "256", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2893", "tmp", checkpoints_buf);



  while (1) {

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2894", "256", checkpoints_buf);
    if (i < 256U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2894", "256", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2897", "tmp", checkpoints_buf);

    tmp = clamp((float )255 * pct[255U - i], 0, 255);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2897", "tmp", checkpoints_buf);

    cmap[i] = (uint8 )tmp;

    i ++;

  }

  sprintf(checkpoints_buf, "%u", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2893", "256", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2893", "tmp", checkpoints_buf);



  break;
  case 1: 
  i = (uint32 )0;


  sprintf(checkpoints_buf, "%u", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2902", "256", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2902", "tmp___0", checkpoints_buf);



  while (1) {

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2903", "256", checkpoints_buf);
    if (i < 256U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2903", "256", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2906", "tmp___0", checkpoints_buf);

    tmp___0 = clamp((float )255 * pct[i], 0, 255);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2906", "tmp___0", checkpoints_buf);

    cmap[i] = (uint8 )tmp___0;

    i ++;

  }

  sprintf(checkpoints_buf, "%u", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2902", "256", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2902", "tmp___0", checkpoints_buf);



  break;
  }
  return;
}
}
static void initScale(void) 
{ 
  void *tmp ;
  void *tmp___0 ;
  void *tmp___1 ;
  void *tmp___2 ;

  {


  tmp = _TIFFmalloc((tmsize_t )(sizeof(uint8 ) * tnw));


  src0 = (uint8 *)tmp;



  tmp___0 = _TIFFmalloc((tmsize_t )(sizeof(uint8 ) * tnw));


  src1 = (uint8 *)tmp___0;



  tmp___1 = _TIFFmalloc((tmsize_t )(sizeof(uint8 ) * tnw));


  src2 = (uint8 *)tmp___1;



  tmp___2 = _TIFFmalloc((tmsize_t )(sizeof(uint32 ) * tnw));


  rowoff = (uint32 *)tmp___2;

  filterWidth = (uint16 )0;

  stepSrcWidth = (uint32 )0;

  stepDstWidth = stepSrcWidth;


  setupBitsTables();

  return;
}
}
static void setupStepTables(uint32 sw ) 
{ 
  int step ;
  int limit ;
  int err ;
  uint32 sx ;
  uint32 x ;
  int fw ;
  uint8 b ;
  uint32 sx0 ;

  {


  if (stepSrcWidth != sw) {
    goto _L;
  } else {


    if (stepDstWidth != tnw) {
      _L: /* CIL Label */ 
      step = (int )sw;
      sprintf(checkpoints_buf, "%d", step);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2927", "step", checkpoints_buf);
      limit = (int )tnw;
      sprintf(checkpoints_buf, "%d", limit);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2928", "limit", checkpoints_buf);
      err = 0;
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2929", "err", checkpoints_buf);
      sx = (uint32 )0;

      x = (uint32 )0;




      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", limit);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "limit", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "err", checkpoints_buf);


      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "8", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "0", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);


      while (x < tnw) {


        sx0 = sx;

        err += step;
        sprintf(checkpoints_buf, "%d", err);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2937", "err", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", err);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2938", "err", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", limit);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2938", "limit", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", err);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2938", "err", checkpoints_buf);

        while (1) {
          sprintf(checkpoints_buf, "%d", err);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2939", "err", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", limit);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2939", "limit", checkpoints_buf);
          if (err >= limit) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%d", err);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2939", "err", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", limit);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2939", "limit", checkpoints_buf);
          err -= limit;
          sprintf(checkpoints_buf, "%d", err);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2942", "err", checkpoints_buf);
          sx ++;

        }
        sprintf(checkpoints_buf, "%d", err);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2938", "err", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", limit);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2938", "limit", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", err);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2938", "err", checkpoints_buf);

        *(rowoff + x) = sx0 >> 3;

        fw = (int )(sx - sx0);
        sprintf(checkpoints_buf, "%d", fw);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2945", "fw", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", fw);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2946", "fw", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2946", "8", checkpoints_buf);
        if (fw < 8) {
          b = (uint8 )(255 << (8 - fw));

        } else {
          b = (uint8 )255;

        }
        sprintf(checkpoints_buf, "%d", fw);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2946", "fw", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2946", "8", checkpoints_buf);
        *(src0 + x) = (uint8 )((int )b >> (sx0 & 7U));

        fw = (int )((unsigned int )fw - (8U - (sx0 & 7U)));
        sprintf(checkpoints_buf, "%d", fw);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2950", "fw", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", fw);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2951", "fw", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2951", "0", checkpoints_buf);
        if (fw < 0) {
          fw = 0;
          sprintf(checkpoints_buf, "%d", fw);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2952", "fw", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", fw);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2951", "fw", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2951", "0", checkpoints_buf);
        *(src1 + x) = (uint8 )(fw >> 3);

        fw -= (fw >> 3) << 3;
        sprintf(checkpoints_buf, "%d", fw);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2955", "fw", checkpoints_buf);
        *(src2 + x) = (uint8 )(255 << (8 - fw));

        x ++;

      }



      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", limit);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "limit", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "err", checkpoints_buf);


      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "8", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "0", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", fw);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2932", "fw", checkpoints_buf);


      stepSrcWidth = sw;

      stepDstWidth = tnw;

    } else {

    }


  }


  return;
}
}
static void setrow(uint8 *row , uint32 nrows , uint8 const   **rows ) 
{ 
  uint32 x ;
  uint32 area ;
  uint32 mask0 ;
  uint32 fw ;
  uint32 mask1 ;
  uint32 off ;
  uint32 acc ;
  uint32 y ;
  uint32 i ;
  uint8 const   *src ;
  uint8 const   *tmp ;
  uint8 const   *tmp___0 ;
  uint8 const   *tmp___1 ;
  uint8 const   *tmp___2 ;
  uint8 const   *tmp___3 ;
  uint8 const   *tmp___4 ;
  uint8 const   *tmp___5 ;
  uint8 const   *tmp___6 ;
  uint8 const   *tmp___7 ;
  uint8 const   *tmp___8 ;
  uint8 *tmp___9 ;

  {
  area = nrows * (uint32 )filterWidth;

  x = (uint32 )0;





















  while (x < tnw) {


    mask0 = (uint32 )*(src0 + x);

    fw = (uint32 )*(src1 + x);

    mask1 = (uint32 )*(src1 + x);

    off = *(rowoff + x);

    acc = (uint32 )0;

    y = (uint32 )0;









    while (y < nrows) {


      src = *(rows + y) + off;

      tmp = src;

      src ++;

      acc += (uint32 )bits[(unsigned int )*tmp & mask0];

      switch (fw) {
      default: 
      i = fw;


      sprintf(checkpoints_buf, "%u", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2984", "8", checkpoints_buf);




      while (1) {

        sprintf(checkpoints_buf, "%u", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2985", "8", checkpoints_buf);
        if (i > 8U) {

        } else {
          break;
        }

        sprintf(checkpoints_buf, "%u", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2985", "8", checkpoints_buf);
        tmp___0 = src;

        src ++;

        acc += (uint32 )bits[*tmp___0];

        i --;

      }

      sprintf(checkpoints_buf, "%u", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2984", "8", checkpoints_buf);




      case 8U: 
      tmp___1 = src;

      src ++;

      acc += (uint32 )bits[*tmp___1];

      case 7U: 
      tmp___2 = src;

      src ++;

      acc += (uint32 )bits[*tmp___2];

      case 6U: 
      tmp___3 = src;

      src ++;

      acc += (uint32 )bits[*tmp___3];

      case 5U: 
      tmp___4 = src;

      src ++;

      acc += (uint32 )bits[*tmp___4];

      case 4U: 
      tmp___5 = src;

      src ++;

      acc += (uint32 )bits[*tmp___5];

      case 3U: 
      tmp___6 = src;

      src ++;

      acc += (uint32 )bits[*tmp___6];

      case 2U: 
      tmp___7 = src;

      src ++;

      acc += (uint32 )bits[*tmp___7];

      case 1U: 
      tmp___8 = src;

      src ++;

      acc += (uint32 )bits[*tmp___8];

      case 0U: 
      break;
      }
      acc += (uint32 )bits[(unsigned int )*src & mask1];

      y ++;

    }








    tmp___9 = row;

    row ++;

    *tmp___9 = cmap[(255U * acc) / area];

    x ++;

  }




















  return;
}
}
static void setImage1(uint8 const   *br , uint32 rw , uint32 rh ) 
{ 
  int step ;
  int limit ;
  int err ;
  int bpr ;
  uint32 tmp ;
  int sy ;
  uint8 *row ;
  uint32 dy ;
  uint8 const   *rows[256] ;
  uint32 nrows ;
  uint32 tmp___0 ;

  {
  step = (int )rh;
  sprintf(checkpoints_buf, "%d", step);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3024", "step", checkpoints_buf);
  limit = (int )tnh;
  sprintf(checkpoints_buf, "%d", limit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3025", "limit", checkpoints_buf);
  err = 0;
  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3026", "err", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3027", "7", checkpoints_buf);
  if (rw & 7U) {
    tmp = (rw >> 3) + 1U;

  } else {
    tmp = rw >> 3;

  }

  sprintf(checkpoints_buf, "%u", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3027", "7", checkpoints_buf);
  bpr = (int )tmp;
  sprintf(checkpoints_buf, "%d", bpr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3030", "bpr", checkpoints_buf);
  sy = 0;
  sprintf(checkpoints_buf, "%d", sy);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3031", "sy", checkpoints_buf);
  row = thumbnail;

  dy = (uint32 )0;






  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", limit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "limit", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", sy);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "sy", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", limit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "limit", checkpoints_buf);



  while (dy < tnh) {


    nrows = (uint32 )1;


    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"bpr=%d, sy=%d, bpr*sy=%d\n", bpr,
            sy, bpr * sy);

    rows[0] = br + bpr * sy;

    err += step;
    sprintf(checkpoints_buf, "%d", err);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3041", "err", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", err);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "err", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", limit);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "limit", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", err);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "err", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", sy);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "sy", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", err);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "err", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", limit);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "limit", checkpoints_buf);
    while (1) {
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3043", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", limit);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3043", "limit", checkpoints_buf);
      if (err >= limit) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3043", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", limit);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3043", "limit", checkpoints_buf);
      err -= limit;
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3046", "err", checkpoints_buf);
      sy ++;
      sprintf(checkpoints_buf, "%d", sy);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3047", "sy", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3048", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", limit);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3048", "limit", checkpoints_buf);
      if (err >= limit) {
        tmp___0 = nrows;

        nrows ++;

        rows[tmp___0] = br + bpr * sy;

      } else {

      }
      sprintf(checkpoints_buf, "%d", err);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3048", "err", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", limit);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3048", "limit", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", err);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "err", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", limit);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "limit", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", err);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "err", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", sy);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "sy", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", err);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "err", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", limit);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3042", "limit", checkpoints_buf);

    setrow(row, nrows, rows);

    row += tnw;

    dy ++;

  }





  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", limit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "limit", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", sy);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "sy", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", err);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "err", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", limit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3034", "limit", checkpoints_buf);



  return;
}
}
static void setImage(uint8 const   *br , uint32 rw , uint32 rh ) 
{ 
  double tmp ;

  {
  sprintf(checkpoints_buf, "%lf", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3057", "tmp", checkpoints_buf);

  tmp = ceil((double )rw / (double )tnw);
  sprintf(checkpoints_buf, "%lf", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3057", "tmp", checkpoints_buf);

  filterWidth = (uint16 )tmp;


  setupStepTables(rw);


  setImage1(br, rw, rh);

  return;
}
}
static int generateThumbnail(TIFF *in , TIFF *out ) 
{ 
  unsigned char *raster ;
  unsigned char *rp ;
  uint32 sw ;
  uint32 sh ;
  uint32 rps ;
  uint16 bps ;
  uint16 spp ;
  tsize_t rowsize ;
  tsize_t rastersize ;
  tstrip_t s ;
  tstrip_t ns ;
  uint32 tmp ;
  uint32 diroff[1] ;
  void *tmp___0 ;
  char const   *tmp___1 ;
  tmsize_t tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;

  {


  tmp = TIFFNumberOfStrips(in);


  ns = tmp;


  TIFFGetField(in, (uint32 )256, & sw);


  TIFFGetField(in, (uint32 )257, & sh);


  TIFFGetFieldDefaulted(in, (uint32 )258, & bps);

  {

  TIFFGetFieldDefaulted(in, (uint32 )277, & spp);

  return (1);
  }

  TIFFGetFieldDefaulted(in, (uint32 )278, & rps);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3069", "1", checkpoints_buf);
  if ((int )spp != 1) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3070", "0", checkpoints_buf);
    return (0);
  } else {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3071", "1", checkpoints_buf);
    if ((int )bps != 1) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3072", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3071", "1", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3069", "1", checkpoints_buf);


  rowsize = TIFFScanlineSize(in);


  rastersize = (tsize_t )((unsigned long )sh * (unsigned long )rowsize);


  fprintf((FILE */* __restrict  */)stderr,
          (char const   */* __restrict  */)"rastersize=%u\n",
          (unsigned int )rastersize);



  tmp___0 = _TIFFmalloc(rastersize);


  raster = (unsigned char *)tmp___0;


  if (! raster) {


    tmp___1 = TIFFFileName(in);



    TIFFError(tmp___1, "Can\'t allocate space for raster buffer.");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3082", "0", checkpoints_buf);
    return (0);
  } else {

  }

  rp = raster;

  s = (tstrip_t )0;






  while (s < ns) {



    TIFFReadEncodedStrip(in, s, (void *)rp, (tmsize_t )-1);

    rp += (unsigned long )rps * (unsigned long )rowsize;

    s ++;

  }






  TIFFGetField(in, (uint32 )262, & photometric);


  setupCmap();


  setImage((uint8 const   *)raster, sw, sh);


  _TIFFfree((void *)raster);


  TIFFSetField(out, (uint32 )254, 1);


  TIFFSetField(out, (uint32 )256, tnw);


  TIFFSetField(out, (uint32 )257, tnh);


  TIFFSetField(out, (uint32 )258, (int )((uint16 )8));


  TIFFSetField(out, (uint32 )277, (int )((uint16 )1));


  TIFFSetField(out, (uint32 )259, 32773);


  TIFFSetField(out, (uint32 )262, 0);


  TIFFSetField(out, (uint32 )284, 1);


  TIFFSetField(out, (uint32 )274, 1);


  cpTag(in, out, (uint16 )305, (uint16 )-1, (TIFFDataType )2);


  cpTag(in, out, (uint16 )270, (uint16 )-1, (TIFFDataType )2);


  cpTag(in, out, (uint16 )306, (uint16 )-1, (TIFFDataType )2);


  cpTag(in, out, (uint16 )316, (uint16 )-1, (TIFFDataType )2);

  diroff[0] = (uint32 )0;


  TIFFSetField(out, (uint32 )330, 1, diroff);



  tmp___2 = TIFFWriteEncodedStrip(out, (uint32 )0, (void *)thumbnail,
                                  (tmsize_t )(tnw * tnh));



  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3113", "-1", checkpoints_buf);
  if (tmp___2 != -1L) {
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3114", "tmp___3", checkpoints_buf);

    tmp___3 = TIFFWriteDirectory(out);
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3114", "tmp___3", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3115", "tmp___3", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3115", "-1", checkpoints_buf);
    if (tmp___3 != -1) {
      tmp___4 = 1;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3116", "tmp___4", checkpoints_buf);
    } else {
      tmp___4 = 0;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "3117", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3115", "tmp___3", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3115", "-1", checkpoints_buf);
  } else {
    tmp___4 = 0;
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3118", "tmp___4", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3113", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3119", "tmp___4", checkpoints_buf);
  return (tmp___4);
}
}
char *stuff[13]  = 
  {      (char *)"usage: thumbnail [options] input.tif output.tif",      (char *)"where options are:",      (char *)" -h #\t\tspecify thumbnail image height (default is 274)",      (char *)" -w #\t\tspecify thumbnail image width (default is 216)", 
        (char *)"",      (char *)" -c linear\tuse linear contrast curve",      (char *)" -c exp50\tuse 50% exponential contrast curve",      (char *)" -c exp60\tuse 60% exponential contrast curve", 
        (char *)" -c exp70\tuse 70% exponential contrast curve",      (char *)" -c exp80\tuse 80% exponential contrast curve",      (char *)" -c exp90\tuse 90% exponential contrast curve",      (char *)" -c exp\t\tuse pure exponential contrast curve", 
        (char *)((void *)0)};
static void usage(void) 
{ 
  char buf[8192] ;
  int i ;
  char const   *tmp ;

  {

  setbuf((FILE */* __restrict  */)stderr, (char */* __restrict  */)(buf));



  tmp = TIFFGetVersion();



  fprintf((FILE */* __restrict  */)stderr,
          (char const   */* __restrict  */)"%s\n\n", tmp);

  i = 0;
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3123", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3124", "i", checkpoints_buf);
  while ((unsigned int )stuff[i] != (unsigned int )((void *)0)) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s\n", stuff[i]);

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "3129", "i", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "3124", "i", checkpoints_buf);

  exit(-1);

}
}
