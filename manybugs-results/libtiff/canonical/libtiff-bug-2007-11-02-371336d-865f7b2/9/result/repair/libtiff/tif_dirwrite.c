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
struct __anonstruct___fsid_t_1 {
   int __val[2] ;
};
typedef struct __anonstruct___fsid_t_1 __fsid_t;
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
typedef __dev_t dev_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __nlink_t nlink_t;
typedef __uid_t uid_t;
typedef __off64_t off_t;
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
typedef unsigned int size_t;
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
struct __anonstruct___sigset_t_2 {
   unsigned long __val[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___sigset_t_2 __sigset_t;
typedef __sigset_t sigset_t;
struct timespec {
   __time_t tv_sec ;
   long tv_nsec ;
};
struct timeval {
   __time_t tv_sec ;
   __suseconds_t tv_usec ;
};
typedef __suseconds_t suseconds_t;
typedef long __fd_mask;
struct __anonstruct_fd_set_3 {
   __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef struct __anonstruct_fd_set_3 fd_set;
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef __blkcnt64_t blkcnt_t;
typedef __fsblkcnt64_t fsblkcnt_t;
typedef __fsfilcnt64_t fsfilcnt_t;
typedef unsigned long pthread_t;
union __anonunion_pthread_attr_t_4 {
   char __size[36] ;
   long __align ;
};
typedef union __anonunion_pthread_attr_t_4 pthread_attr_t;
struct __pthread_internal_slist {
   struct __pthread_internal_slist *__next ;
};
typedef struct __pthread_internal_slist __pthread_slist_t;
union __anonunion____missing_field_name_6 {
   int __spins ;
   __pthread_slist_t __list ;
};
struct __pthread_mutex_s {
   int __lock ;
   unsigned int __count ;
   int __owner ;
   int __kind ;
   unsigned int __nusers ;
   union __anonunion____missing_field_name_6 __annonCompField1 ;
};
union __anonunion_pthread_mutex_t_5 {
   struct __pthread_mutex_s __data ;
   char __size[24] ;
   long __align ;
};
typedef union __anonunion_pthread_mutex_t_5 pthread_mutex_t;
union __anonunion_pthread_mutexattr_t_7 {
   char __size[4] ;
   long __align ;
};
typedef union __anonunion_pthread_mutexattr_t_7 pthread_mutexattr_t;
struct __anonstruct___data_9 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_8 {
   struct __anonstruct___data_9 __data ;
   char __size[48] ;
   long long __align ;
};
typedef union __anonunion_pthread_cond_t_8 pthread_cond_t;
union __anonunion_pthread_condattr_t_10 {
   char __size[4] ;
   long __align ;
};
typedef union __anonunion_pthread_condattr_t_10 pthread_condattr_t;
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
struct __anonstruct___data_12 {
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
union __anonunion_pthread_rwlock_t_11 {
   struct __anonstruct___data_12 __data ;
   char __size[32] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlock_t_11 pthread_rwlock_t;
union __anonunion_pthread_rwlockattr_t_13 {
   char __size[8] ;
   long __align ;
};
typedef union __anonunion_pthread_rwlockattr_t_13 pthread_rwlockattr_t;
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_14 {
   char __size[20] ;
   long __align ;
};
typedef union __anonunion_pthread_barrier_t_14 pthread_barrier_t;
union __anonunion_pthread_barrierattr_t_15 {
   char __size[4] ;
   int __align ;
};
typedef union __anonunion_pthread_barrierattr_t_15 pthread_barrierattr_t;
struct flock {
   short l_type ;
   short l_whence ;
   __off64_t l_start ;
   __off64_t l_len ;
   __pid_t l_pid ;
};
struct stat {
   __dev_t st_dev ;
   unsigned short __pad1 ;
   __ino_t __st_ino ;
   __mode_t st_mode ;
   __nlink_t st_nlink ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   __dev_t st_rdev ;
   unsigned short __pad2 ;
   __off64_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt64_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   __ino64_t st_ino ;
};
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
typedef int (*__compar_fn_t)(void const   * , void const   * );
enum __anonenum_ACTION_16 {
    FIND = 0,
    ENTER = 1
} ;
typedef enum __anonenum_ACTION_16 ACTION;
struct entry {
   char *key ;
   void *data ;
};
typedef struct entry ENTRY;
struct _ENTRY;
struct _ENTRY;
enum __anonenum_VISIT_17 {
    preorder = 0,
    postorder = 1,
    endorder = 2,
    leaf = 3
} ;
typedef enum __anonenum_VISIT_17 VISIT;
typedef void (*__action_fn_t)(void const   *__nodep , VISIT __value ,
                              int __level );
typedef signed char int8;
typedef unsigned char uint8;
typedef short int16;
typedef unsigned short uint16;
typedef int int32;
typedef unsigned int uint32;
typedef long long int64;
typedef unsigned long long uint64;
typedef int uint16_vap;
struct __anonstruct_TIFFHeaderCommon_18 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
};
typedef struct __anonstruct_TIFFHeaderCommon_18 TIFFHeaderCommon;
struct __anonstruct_TIFFHeaderClassic_19 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint32 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderClassic_19 TIFFHeaderClassic;
struct __anonstruct_TIFFHeaderBig_20 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint16 tiff_offsetsize ;
   uint16 tiff_unused ;
   uint64 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderBig_20 TIFFHeaderBig;
enum __anonenum_TIFFDataType_21 {
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
typedef enum __anonenum_TIFFDataType_21 TIFFDataType;
struct tiff;
typedef struct tiff TIFF;
typedef long tmsize_t;
typedef uint32 ttag_t;
typedef uint16 tdir_t;
typedef uint16 tsample_t;
typedef uint32 tstrile_t;
typedef tstrile_t tstrip_t;
typedef tstrile_t ttile_t;
typedef tmsize_t tsize_t;
typedef void *tdata_t;
typedef uint64 toff_t;
typedef void *thandle_t;
typedef unsigned char TIFFRGBValue;
struct __anonstruct_TIFFDisplay_22 {
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
typedef struct __anonstruct_TIFFDisplay_22 TIFFDisplay;
struct __anonstruct_TIFFYCbCrToRGB_23 {
   TIFFRGBValue *clamptab ;
   int *Cr_r_tab ;
   int *Cb_b_tab ;
   int32 *Cr_g_tab ;
   int32 *Cb_g_tab ;
   int32 *Y_tab ;
};
typedef struct __anonstruct_TIFFYCbCrToRGB_23 TIFFYCbCrToRGB;
struct __anonstruct_TIFFCIELabToRGB_24 {
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
typedef struct __anonstruct_TIFFCIELabToRGB_24 TIFFCIELabToRGB;
struct _TIFFRGBAImage;
typedef struct _TIFFRGBAImage TIFFRGBAImage;
typedef void (*tileContigRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                  uint32  , uint32  , uint32  , int32  ,
                                  int32  , unsigned char * );
typedef void (*tileSeparateRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                    uint32  , uint32  , uint32  , int32  ,
                                    int32  , unsigned char * , unsigned char * ,
                                    unsigned char * , unsigned char * );
union __anonunion_put_25 {
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
   union __anonunion_put_25 put ;
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
struct __anonstruct_TIFFCodec_26 {
   char *name ;
   uint16 scheme ;
   int (*init)(TIFF * , int  ) ;
};
typedef struct __anonstruct_TIFFCodec_26 TIFFCodec;
struct _IO_FILE;
struct _IO_FILE;
typedef struct _IO_FILE FILE;
typedef struct _IO_FILE __FILE;
union __anonunion___value_28 {
   unsigned int __wch ;
   char __wchb[4] ;
};
struct __anonstruct___mbstate_t_27 {
   int __count ;
   union __anonunion___value_28 __value ;
};
typedef struct __anonstruct___mbstate_t_27 __mbstate_t;
struct __anonstruct__G_fpos_t_29 {
   __off_t __pos ;
   __mbstate_t __state ;
};
typedef struct __anonstruct__G_fpos_t_29 _G_fpos_t;
struct __anonstruct__G_fpos64_t_30 {
   __off64_t __pos ;
   __mbstate_t __state ;
};
typedef struct __anonstruct__G_fpos64_t_30 _G_fpos64_t;
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
typedef __gnuc_va_list va_list;
typedef _G_fpos64_t fpos_t;
typedef void (*TIFFErrorHandler)(char const   * , char const   * , va_list  );
typedef void (*TIFFErrorHandlerExt)(thandle_t  , char const   * ,
                                    char const   * , va_list  );
typedef tmsize_t (*TIFFReadWriteProc)(thandle_t  , void * , tmsize_t  );
typedef uint64 (*TIFFSeekProc)(thandle_t  , uint64  , int  );
typedef int (*TIFFCloseProc)(thandle_t  );
typedef uint64 (*TIFFSizeProc)(thandle_t  );
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
struct __anonstruct_TIFFTagMethods_31 {
   int (*vsetfield)(TIFF * , uint32  , va_list  ) ;
   int (*vgetfield)(TIFF * , uint32  , va_list  ) ;
   void (*printdir)(TIFF * , FILE * , long  ) ;
};
typedef struct __anonstruct_TIFFTagMethods_31 TIFFTagMethods;
struct __anonstruct_TIFFFieldInfo_32 {
   ttag_t field_tag ;
   short field_readcount ;
   short field_writecount ;
   TIFFDataType field_type ;
   unsigned short field_bit ;
   unsigned char field_oktochange ;
   unsigned char field_passcount ;
   char *field_name ;
};
typedef struct __anonstruct_TIFFFieldInfo_32 TIFFFieldInfo;
struct __anonstruct_TIFFTagValue_33 {
   TIFFField const   *info ;
   int count ;
   void *value ;
};
typedef struct __anonstruct_TIFFTagValue_33 TIFFTagValue;
struct __anonstruct_TIFFDirectory_34 {
   unsigned long td_fieldsset[4] ;
   uint32 td_imagewidth ;
   uint32 td_imagelength ;
   uint32 td_imagedepth ;
   uint32 td_tilewidth ;
   uint32 td_tilelength ;
   uint32 td_tiledepth ;
   uint32 td_subfiletype ;
   uint16 td_bitspersample ;
   uint16 td_sampleformat ;
   uint16 td_compression ;
   uint16 td_photometric ;
   uint16 td_threshholding ;
   uint16 td_fillorder ;
   uint16 td_orientation ;
   uint16 td_samplesperpixel ;
   uint32 td_rowsperstrip ;
   uint16 td_minsamplevalue ;
   uint16 td_maxsamplevalue ;
   double td_sminsamplevalue ;
   double td_smaxsamplevalue ;
   float td_xresolution ;
   float td_yresolution ;
   uint16 td_resolutionunit ;
   uint16 td_planarconfig ;
   float td_xposition ;
   float td_yposition ;
   uint16 td_pagenumber[2] ;
   uint16 *td_colormap[3] ;
   uint16 td_halftonehints[2] ;
   uint16 td_extrasamples ;
   uint16 *td_sampleinfo ;
   uint32 td_stripsperimage ;
   uint32 td_nstrips ;
   uint64 *td_stripoffset ;
   uint64 *td_stripbytecount ;
   int td_stripbytecountsorted ;
   uint16 td_nsubifd ;
   uint64 *td_subifd ;
   uint16 td_ycbcrsubsampling[2] ;
   uint16 td_ycbcrpositioning ;
   uint16 *td_transferfunction[3] ;
   int td_inknameslen ;
   char *td_inknames ;
   int td_customValueCount ;
   TIFFTagValue *td_customValues ;
};
typedef struct __anonstruct_TIFFDirectory_34 TIFFDirectory;
enum __anonenum_TIFFSetGetFieldType_35 {
    TIFF_SETGET_UNDEFINED = 0,
    TIFF_SETGET_ASCII = 1,
    TIFF_SETGET_UINT8 = 2,
    TIFF_SETGET_SINT8 = 3,
    TIFF_SETGET_UINT16 = 4,
    TIFF_SETGET_SINT16 = 5,
    TIFF_SETGET_UINT32 = 6,
    TIFF_SETGET_SINT32 = 7,
    TIFF_SETGET_UINT64 = 8,
    TIFF_SETGET_SINT64 = 9,
    TIFF_SETGET_FLOAT = 10,
    TIFF_SETGET_DOUBLE = 11,
    TIFF_SETGET_IFD8 = 12,
    TIFF_SETGET_INT = 13,
    TIFF_SETGET_UINT16_PAIR = 14,
    TIFF_SETGET_C0_ASCII = 15,
    TIFF_SETGET_C0_UINT8 = 16,
    TIFF_SETGET_C0_SINT8 = 17,
    TIFF_SETGET_C0_UINT16 = 18,
    TIFF_SETGET_C0_SINT16 = 19,
    TIFF_SETGET_C0_UINT32 = 20,
    TIFF_SETGET_C0_SINT32 = 21,
    TIFF_SETGET_C0_UINT64 = 22,
    TIFF_SETGET_C0_SINT64 = 23,
    TIFF_SETGET_C0_FLOAT = 24,
    TIFF_SETGET_C0_DOUBLE = 25,
    TIFF_SETGET_C0_IFD8 = 26,
    TIFF_SETGET_C16_ASCII = 27,
    TIFF_SETGET_C16_UINT8 = 28,
    TIFF_SETGET_C16_SINT8 = 29,
    TIFF_SETGET_C16_UINT16 = 30,
    TIFF_SETGET_C16_SINT16 = 31,
    TIFF_SETGET_C16_UINT32 = 32,
    TIFF_SETGET_C16_SINT32 = 33,
    TIFF_SETGET_C16_UINT64 = 34,
    TIFF_SETGET_C16_SINT64 = 35,
    TIFF_SETGET_C16_FLOAT = 36,
    TIFF_SETGET_C16_DOUBLE = 37,
    TIFF_SETGET_C16_IFD8 = 38,
    TIFF_SETGET_C32_ASCII = 39,
    TIFF_SETGET_C32_UINT8 = 40,
    TIFF_SETGET_C32_SINT8 = 41,
    TIFF_SETGET_C32_UINT16 = 42,
    TIFF_SETGET_C32_SINT16 = 43,
    TIFF_SETGET_C32_UINT32 = 44,
    TIFF_SETGET_C32_SINT32 = 45,
    TIFF_SETGET_C32_UINT64 = 46,
    TIFF_SETGET_C32_SINT64 = 47,
    TIFF_SETGET_C32_FLOAT = 48,
    TIFF_SETGET_C32_DOUBLE = 49,
    TIFF_SETGET_C32_IFD8 = 50,
    TIFF_SETGET_OTHER = 51
} ;
typedef enum __anonenum_TIFFSetGetFieldType_35 TIFFSetGetFieldType;
enum __anonenum_TIFFFieldArrayType_36 {
    tfiatImage = 0,
    tfiatExif = 1,
    tfiatOther = 2
} ;
typedef enum __anonenum_TIFFFieldArrayType_36 TIFFFieldArrayType;
struct _TIFFFieldArray {
   TIFFFieldArrayType type ;
   uint32 allocated_size ;
   uint32 count ;
   TIFFField *fields ;
};
struct _TIFFField {
   uint32 field_tag ;
   short field_readcount ;
   short field_writecount ;
   TIFFDataType field_type ;
   uint32 reserved ;
   TIFFSetGetFieldType set_field_type ;
   TIFFSetGetFieldType get_field_type ;
   unsigned short field_bit ;
   unsigned char field_oktochange ;
   unsigned char field_passcount ;
   char *field_name ;
   TIFFFieldArray *field_subfields ;
};
struct __anonstruct_TIFFDirEntry_37 {
   uint16 tdir_tag ;
   uint16 tdir_type ;
   uint64 tdir_count ;
   uint64 tdir_offset ;
};
typedef struct __anonstruct_TIFFDirEntry_37 TIFFDirEntry;
struct client_info {
   struct client_info *next ;
   void *data ;
   char *name ;
};
typedef struct client_info TIFFClientInfoLink;
typedef unsigned char tidataval_t;
typedef tidataval_t *tidata_t;
typedef void (*TIFFVoidMethod)(TIFF * );
typedef int (*TIFFBoolMethod)(TIFF * );
typedef int (*TIFFPreMethod)(TIFF * , uint16  );
typedef int (*TIFFCodeMethod)(TIFF *tif , uint8 *buf , tmsize_t size ,
                              uint16 sample );
typedef int (*TIFFSeekMethod)(TIFF * , uint32  );
typedef void (*TIFFPostMethod)(TIFF *tif , uint8 *buf , tmsize_t size );
typedef uint32 (*TIFFStripMethod)(TIFF * , uint32  );
typedef void (*TIFFTileMethod)(TIFF * , uint32 * , uint32 * );
union __anonunion_tif_header_38 {
   TIFFHeaderCommon common ;
   TIFFHeaderClassic classic ;
   TIFFHeaderBig big ;
};
struct tiff {
   char *tif_name ;
   int tif_fd ;
   int tif_mode ;
   uint32 tif_flags ;
   uint64 tif_diroff ;
   uint64 tif_nextdiroff ;
   uint64 *tif_dirlist ;
   uint16 tif_dirlistsize ;
   uint16 tif_dirnumber ;
   TIFFDirectory tif_dir ;
   TIFFDirectory tif_customdir ;
   union __anonunion_tif_header_38 tif_header ;
   uint16 tif_header_size ;
   uint32 tif_row ;
   uint16 tif_curdir ;
   uint32 tif_curstrip ;
   uint64 tif_curoff ;
   uint64 tif_dataoff ;
   uint16 tif_nsubifd ;
   uint64 tif_subifdoff ;
   uint32 tif_col ;
   uint32 tif_curtile ;
   tmsize_t tif_tilesize ;
   int tif_decodestatus ;
   int (*tif_fixuptags)(TIFF * ) ;
   int (*tif_setupdecode)(TIFF * ) ;
   int (*tif_predecode)(TIFF * , uint16  ) ;
   int (*tif_setupencode)(TIFF * ) ;
   int tif_encodestatus ;
   int (*tif_preencode)(TIFF * , uint16  ) ;
   int (*tif_postencode)(TIFF * ) ;
   int (*tif_decoderow)(TIFF *tif , uint8 *buf , tmsize_t size , uint16 sample ) ;
   int (*tif_encoderow)(TIFF *tif , uint8 *buf , tmsize_t size , uint16 sample ) ;
   int (*tif_decodestrip)(TIFF *tif , uint8 *buf , tmsize_t size ,
                          uint16 sample ) ;
   int (*tif_encodestrip)(TIFF *tif , uint8 *buf , tmsize_t size ,
                          uint16 sample ) ;
   int (*tif_decodetile)(TIFF *tif , uint8 *buf , tmsize_t size , uint16 sample ) ;
   int (*tif_encodetile)(TIFF *tif , uint8 *buf , tmsize_t size , uint16 sample ) ;
   void (*tif_close)(TIFF * ) ;
   int (*tif_seek)(TIFF * , uint32  ) ;
   void (*tif_cleanup)(TIFF * ) ;
   uint32 (*tif_defstripsize)(TIFF * , uint32  ) ;
   void (*tif_deftilesize)(TIFF * , uint32 * , uint32 * ) ;
   uint8 *tif_data ;
   tmsize_t tif_scanlinesize ;
   tmsize_t tif_scanlineskew ;
   uint8 *tif_rawdata ;
   tmsize_t tif_rawdatasize ;
   uint8 *tif_rawcp ;
   tmsize_t tif_rawcc ;
   uint8 *tif_base ;
   tmsize_t tif_size ;
   int (*tif_mapproc)(thandle_t  , void **base , toff_t *size ) ;
   void (*tif_unmapproc)(thandle_t  , void *base , toff_t size ) ;
   thandle_t tif_clientdata ;
   tmsize_t (*tif_readproc)(thandle_t  , void * , tmsize_t  ) ;
   tmsize_t (*tif_writeproc)(thandle_t  , void * , tmsize_t  ) ;
   uint64 (*tif_seekproc)(thandle_t  , uint64  , int  ) ;
   int (*tif_closeproc)(thandle_t  ) ;
   uint64 (*tif_sizeproc)(thandle_t  ) ;
   void (*tif_postdecode)(TIFF *tif , uint8 *buf , tmsize_t size ) ;
   TIFFField **tif_fields ;
   uint32 tif_nfields ;
   TIFFField const   *tif_foundfield ;
   TIFFTagMethods tif_tagmethods ;
   TIFFClientInfoLink *tif_clientinfo ;
   TIFFFieldArray *tif_fieldscompat ;
   uint32 tif_nfieldscompat ;
};
extern int select(int __nfds , fd_set * __restrict  __readfds ,
                  fd_set * __restrict  __writefds ,
                  fd_set * __restrict  __exceptfds ,
                  struct timeval * __restrict  __timeout ) ;
extern int pselect(int __nfds , fd_set * __restrict  __readfds ,
                   fd_set * __restrict  __writefds ,
                   fd_set * __restrict  __exceptfds ,
                   struct timespec  const  * __restrict  __timeout ,
                   __sigset_t const   * __restrict  __sigmask ) ;
__inline extern  __attribute__((__nothrow__)) unsigned int gnu_dev_major(unsigned long long __dev ) ;
__inline extern  __attribute__((__nothrow__)) unsigned int gnu_dev_minor(unsigned long long __dev ) ;
__inline extern  __attribute__((__nothrow__)) unsigned long long gnu_dev_makedev(unsigned int __major ,
                                                                                 unsigned int __minor ) ;
__inline extern  __attribute__((__nothrow__)) unsigned int gnu_dev_major(unsigned long long __dev ) ;
__inline extern unsigned int gnu_dev_major(unsigned long long __dev ) 
{ 


  {
  return ((unsigned int )(((__dev >> 8) & 4095ULL) | (unsigned long long )((unsigned int )(__dev >> 32) & 4294963200U)));
}
}
__inline extern  __attribute__((__nothrow__)) unsigned int gnu_dev_minor(unsigned long long __dev ) ;
__inline extern unsigned int gnu_dev_minor(unsigned long long __dev ) 
{ 


  {
  return ((unsigned int )((__dev & 255ULL) | (unsigned long long )((unsigned int )(__dev >> 12) & 4294967040U)));
}
}
__inline extern  __attribute__((__nothrow__)) unsigned long long gnu_dev_makedev(unsigned int __major ,
                                                                                 unsigned int __minor ) ;
__inline extern unsigned long long gnu_dev_makedev(unsigned int __major ,
                                                   unsigned int __minor ) 
{ 


  {
  return (((unsigned long long )((__minor & 255U) | ((__major & 4095U) << 8)) | ((unsigned long long )(__minor & 4294967040U) << 12)) | ((unsigned long long )(__major & 4294963200U) << 32));
}
}
extern int fcntl(int __fd , int __cmd  , ...) ;
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file ,
                                                   int __oflag  , ...)  __asm__("open64")  ;
extern int ( __attribute__((__nonnull__(2))) openat)(int __fd ,
                                                     char const   *__file ,
                                                     int __oflag  , ...)  __asm__("openat64")  ;
extern int ( __attribute__((__nonnull__(1))) creat)(char const   *__file ,
                                                    __mode_t __mode )  __asm__("creat64")  ;
extern int lockf(int __fd , int __cmd , __off64_t __len )  __asm__("lockf64")  ;
extern  __attribute__((__nothrow__)) int posix_fadvise(int __fd ,
                                                       __off64_t __offset ,
                                                       __off64_t __len ,
                                                       int __advise )  __asm__("posix_fadvise64")  ;
extern int posix_fallocate(int __fd , __off64_t __offset , __off64_t __len )  __asm__("posix_fallocate64")  ;
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
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1))) strlen)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) size_t ( __attribute__((__nonnull__(1))) strnlen)(char const   *__string ,
                                                                                       size_t __maxlen )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *strerror(int __errnum ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) strerror_r)(int __errnum ,
                                                                                       char *__buf ,
                                                                                       size_t __buflen )  __asm__("__xpg_strerror_r")  ;
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
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strcasecmp)(char const   *__s1 ,
                                                                                         char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strncasecmp)(char const   *__s1 ,
                                                                                          char const   *__s2 ,
                                                                                          size_t __n )  __attribute__((__pure__)) ;
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
extern void *__rawmemchr(void const   *__s , int __c ) ;
__inline extern size_t __strcspn_c1(char const   *__s , int __reject ) ;
__inline extern size_t __strcspn_c1(char const   *__s , int __reject ) 
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
  return (__result);
}
}
__inline extern size_t __strcspn_c2(char const   *__s , int __reject1 ,
                                    int __reject2 ) ;
__inline extern size_t __strcspn_c2(char const   *__s , int __reject1 ,
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
  return (__result);
}
}
__inline extern size_t __strcspn_c3(char const   *__s , int __reject1 ,
                                    int __reject2 , int __reject3 ) ;
__inline extern size_t __strcspn_c3(char const   *__s , int __reject1 ,
                                    int __reject2 , int __reject3 ) 
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
  return (__result);
}
}
__inline extern size_t __strspn_c1(char const   *__s , int __accept ) ;
__inline extern size_t __strspn_c1(char const   *__s , int __accept ) 
{ 
  register size_t __result ;

  {
  __result = (size_t )0;
  while ((int const   )*(__s + __result) == (int const   )__accept) {
    __result ++;
  }
  return (__result);
}
}
__inline extern size_t __strspn_c2(char const   *__s , int __accept1 ,
                                   int __accept2 ) ;
__inline extern size_t __strspn_c2(char const   *__s , int __accept1 ,
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
  return (__result);
}
}
__inline extern size_t __strspn_c3(char const   *__s , int __accept1 ,
                                   int __accept2 , int __accept3 ) ;
__inline extern size_t __strspn_c3(char const   *__s , int __accept1 ,
                                   int __accept2 , int __accept3 ) 
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
  return (__result);
}
}
__inline extern char *__strpbrk_c2(char const   *__s , int __accept1 ,
                                   int __accept2 ) ;
__inline extern char *__strpbrk_c2(char const   *__s , int __accept1 ,
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
  return (tmp);
}
}
__inline extern char *__strpbrk_c3(char const   *__s , int __accept1 ,
                                   int __accept2 , int __accept3 ) ;
__inline extern char *__strpbrk_c3(char const   *__s , int __accept1 ,
                                   int __accept2 , int __accept3 ) 
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
  return (tmp);
}
}
__inline extern char *__strtok_r_1c(char *__s , char __sep , char **__nextp ) ;
__inline extern char *__strtok_r_1c(char *__s , char __sep , char **__nextp ) 
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
  return (__result);
}
}
extern char *__strsep_g(char **__stringp , char const   *__delim ) ;
__inline extern char *__strsep_1c(char **__s , char __reject ) ;
__inline extern char *__strsep_1c(char **__s , char __reject ) 
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
  return (__retval);
}
}
__inline extern char *__strsep_2c(char **__s , char __reject1 , char __reject2 ) ;
__inline extern char *__strsep_2c(char **__s , char __reject1 , char __reject2 ) 
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
  return (__retval);
}
}
__inline extern char *__strsep_3c(char **__s , char __reject1 , char __reject2 ,
                                  char __reject3 ) ;
__inline extern char *__strsep_3c(char **__s , char __reject1 , char __reject2 ,
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
  return (__retval);
}
}
extern  __attribute__((__nothrow__)) void *malloc(size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) void *calloc(size_t __nmemb ,
                                                  size_t __size )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) char *__strdup(char const   *__string )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__)) char *__strndup(char const   *__string ,
                                                     size_t __n )  __attribute__((__malloc__)) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void __assert_fail(char const   *__assertion ,
                                  char const   *__file , unsigned int __line ,
                                  char const   *__function ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void __assert_perror_fail(int __errnum , char const   *__file ,
                                         unsigned int __line ,
                                         char const   *__function ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void __assert(char const   *__assertion , char const   *__file ,
                             int __line ) ;
extern  __attribute__((__nothrow__)) void insque(void *__elem , void *__prev ) ;
extern  __attribute__((__nothrow__)) void remque(void *__elem ) ;
extern  __attribute__((__nothrow__)) ENTRY *hsearch(ENTRY __item ,
                                                    ACTION __action ) ;
extern  __attribute__((__nothrow__)) int hcreate(size_t __nel ) ;
extern  __attribute__((__nothrow__)) void hdestroy(void) ;
extern void *tsearch(void const   *__key , void **__rootp ,
                     int (*__compar)(void const   * , void const   * ) ) ;
extern void *tfind(void const   *__key , void * const  *__rootp ,
                   int (*__compar)(void const   * , void const   * ) ) ;
extern void *tdelete(void const   * __restrict  __key ,
                     void ** __restrict  __rootp ,
                     int (*__compar)(void const   * , void const   * ) ) ;
extern void twalk(void const   *__root ,
                  void (*__action)(void const   *__nodep , VISIT __value ,
                                   int __level ) ) ;
extern void *lfind(void const   *__key , void const   *__base ,
                   size_t *__nmemb , size_t __size ,
                   int (*__compar)(void const   * , void const   * ) ) ;
extern void *lsearch(void const   *__key , void *__base , size_t *__nmemb ,
                     size_t __size , int (*__compar)(void const   * ,
                                                     void const   * ) ) ;
extern struct _IO_FILE_plus _IO_2_1_stdin_ ;
extern struct _IO_FILE_plus _IO_2_1_stdout_ ;
extern struct _IO_FILE_plus _IO_2_1_stderr_ ;
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
extern  __attribute__((__nothrow__)) char *tmpnam(char *__s ) ;
extern  __attribute__((__nothrow__)) char *tmpnam_r(char *__s ) ;
extern  __attribute__((__nothrow__)) char *tempnam(char const   *__dir ,
                                                   char const   *__pfx )  __attribute__((__malloc__)) ;
extern int fclose(FILE *__stream ) ;
extern int fflush(FILE *__stream ) ;
extern int fflush_unlocked(FILE *__stream ) ;
extern FILE *fopen(char const   * __restrict  __filename ,
                   char const   * __restrict  __modes )  __asm__("fopen64")  ;
extern FILE *freopen(char const   * __restrict  __filename ,
                     char const   * __restrict  __modes ,
                     FILE * __restrict  __stream )  __asm__("freopen64")  ;
extern  __attribute__((__nothrow__)) FILE *fdopen(int __fd ,
                                                  char const   *__modes ) ;
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
__inline extern int vprintf(char const   * __restrict  __fmt ,
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
extern int ( /* format attribute */  vdprintf)(int __fd ,
                                               char const   * __restrict  __fmt ,
                                               __gnuc_va_list __arg ) ;
extern int ( /* format attribute */  dprintf)(int __fd ,
                                              char const   * __restrict  __fmt 
                                              , ...) ;
extern int fscanf(FILE * __restrict  __stream ,
                  char const   * __restrict  __format  , ...)  __asm__("__isoc99_fscanf")  ;
extern int scanf(char const   * __restrict  __format  , ...)  __asm__("__isoc99_scanf")  ;
extern  __attribute__((__nothrow__)) int sscanf(char const   * __restrict  __s ,
                                                char const   * __restrict  __format 
                                                , ...)  __asm__("__isoc99_sscanf")  ;
extern int ( /* format attribute */  vfscanf)(FILE * __restrict  __s ,
                                              char const   * __restrict  __format ,
                                              __gnuc_va_list __arg )  __asm__("__isoc99_vfscanf")  ;
extern int ( /* format attribute */  vscanf)(char const   * __restrict  __format ,
                                             __gnuc_va_list __arg )  __asm__("__isoc99_vscanf")  ;
extern  __attribute__((__nothrow__)) int ( /* format attribute */  vsscanf)(char const   * __restrict  __s ,
                                                                            char const   * __restrict  __format ,
                                                                            __gnuc_va_list __arg )  __asm__("__isoc99_vsscanf")  ;
extern int fgetc(FILE *__stream ) ;
extern int getc(FILE *__stream ) ;
__inline extern int getchar(void) ;
__inline extern int getc_unlocked(FILE *__fp ) ;
__inline extern int getchar_unlocked(void) ;
__inline extern int fgetc_unlocked(FILE *__fp ) ;
extern int fputc(int __c , FILE *__stream ) ;
extern int putc(int __c , FILE *__stream ) ;
__inline extern int putchar(int __c ) ;
__inline extern int fputc_unlocked(int __c , FILE *__stream ) ;
__inline extern int putc_unlocked(int __c , FILE *__stream ) ;
__inline extern int putchar_unlocked(int __c ) ;
extern int getw(FILE *__stream ) ;
extern int putw(int __w , FILE *__stream ) ;
extern char *fgets(char * __restrict  __s , int __n ,
                   FILE * __restrict  __stream ) ;
extern char *gets(char *__s ) ;
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
extern int fseeko(FILE *__stream , __off64_t __off , int __whence )  __asm__("fseeko64")  ;
extern __off64_t ftello(FILE *__stream )  __asm__("ftello64")  ;
extern int fgetpos(FILE * __restrict  __stream , fpos_t * __restrict  __pos )  __asm__("fgetpos64")  ;
extern int fsetpos(FILE *__stream , fpos_t const   *__pos )  __asm__("fsetpos64")  ;
extern  __attribute__((__nothrow__)) void clearerr(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int feof(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ferror(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) void clearerr_unlocked(FILE *__stream ) ;
__inline extern  __attribute__((__nothrow__)) int feof_unlocked(FILE *__stream ) ;
__inline extern  __attribute__((__nothrow__)) int ferror_unlocked(FILE *__stream ) ;
extern void perror(char const   *__s ) ;
extern int sys_nerr ;
extern char const   * const  sys_errlist[] ;
extern  __attribute__((__nothrow__)) int fileno(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int fileno_unlocked(FILE *__stream ) ;
extern FILE *popen(char const   *__command , char const   *__modes ) ;
extern int pclose(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) char *ctermid(char *__s ) ;
extern  __attribute__((__nothrow__)) void flockfile(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) int ftrylockfile(FILE *__stream ) ;
extern  __attribute__((__nothrow__)) void funlockfile(FILE *__stream ) ;
__inline extern int vprintf(char const   * __restrict  __fmt ,
                            __gnuc_va_list __arg ) 
{ 
  int tmp ;

  {
  tmp = vfprintf((FILE */* __restrict  */)stdout, __fmt, __arg);
  return (tmp);
}
}
__inline extern int getchar(void) 
{ 
  int tmp ;

  {
  tmp = _IO_getc(stdin);
  return (tmp);
}
}
__inline extern int fgetc_unlocked(FILE *__fp ) 
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
  return (tmp___2);
}
}
__inline extern int getc_unlocked(FILE *__fp ) 
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
  return (tmp___2);
}
}
__inline extern int getchar_unlocked(void) 
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
  return (tmp___2);
}
}
__inline extern int putchar(int __c ) 
{ 
  int tmp ;

  {
  tmp = _IO_putc(__c, stdout);
  return (tmp);
}
}
__inline extern int fputc_unlocked(int __c , FILE *__stream ) 
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
  return (tmp___3);
}
}
__inline extern int putc_unlocked(int __c , FILE *__stream ) 
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
  return (tmp___3);
}
}
__inline extern int putchar_unlocked(int __c ) 
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
  return (tmp___3);
}
}
__inline extern  __attribute__((__nothrow__)) int feof_unlocked(FILE *__stream ) ;
__inline extern int feof_unlocked(FILE *__stream ) 
{ 


  {
  return ((__stream->_flags & 16) != 0);
}
}
__inline extern  __attribute__((__nothrow__)) int ferror_unlocked(FILE *__stream ) ;
__inline extern int ferror_unlocked(FILE *__stream ) 
{ 


  {
  return ((__stream->_flags & 32) != 0);
}
}
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
extern int TIFFReadCustomDirectory(TIFF *tif , uint64 diroff ,
                                   TIFFFieldArray const   *infoarray ) ;
extern int TIFFReadEXIFDirectory(TIFF *tif , uint64 diroff ) ;
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
int TIFFWriteDirectory(TIFF *tif ) ;
int TIFFCheckpointDirectory(TIFF *tif ) ;
int TIFFRewriteDirectory(TIFF *tif ) ;
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
                            uint64 (*)(thandle_t  , uint64  , int  ) ,
                            int (*)(thandle_t  ) , uint64 (*)(thandle_t  ) ,
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
extern void TIFFSetWriteOffset(TIFF *tif , uint64 off ) ;
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
extern TIFFFieldArray const   *_TIFFGetFields(void) ;
extern TIFFFieldArray const   *_TIFFGetExifFields(void) ;
extern void _TIFFSetupFields(TIFF *tif , TIFFFieldArray const   *infoarray ) ;
extern void _TIFFPrintFieldInfo(TIFF * , FILE * ) ;
extern int _TIFFMergeFields(TIFF * , TIFFField const   * , uint32  ) ;
extern TIFFField const   *_TIFFFindOrRegisterField(TIFF * , uint32  ,
                                                   TIFFDataType  ) ;
extern TIFFField *_TIFFCreateAnonField(TIFF * , uint32  , TIFFDataType  ) ;
extern int _TIFFgetMode(char const   *mode , char const   *module ) ;
extern int _TIFFNoRowEncode(TIFF *tif , uint8 *pp , tmsize_t cc , uint16 s ) ;
extern int _TIFFNoStripEncode(TIFF *tif , uint8 *pp , tmsize_t cc , uint16 s ) ;
extern int _TIFFNoTileEncode(TIFF * , uint8 *pp , tmsize_t cc , uint16 s ) ;
extern int _TIFFNoRowDecode(TIFF *tif , uint8 *pp , tmsize_t cc , uint16 s ) ;
extern int _TIFFNoStripDecode(TIFF *tif , uint8 *pp , tmsize_t cc , uint16 s ) ;
extern int _TIFFNoTileDecode(TIFF * , uint8 *pp , tmsize_t cc , uint16 s ) ;
extern void _TIFFNoPostDecode(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
extern int _TIFFNoPreCode(TIFF *tif , uint16 s ) ;
extern int _TIFFNoSeek(TIFF *tif , uint32 off ) ;
extern void _TIFFSwab16BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
extern void _TIFFSwab24BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
extern void _TIFFSwab32BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
extern void _TIFFSwab64BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
extern int TIFFFlushData1(TIFF *tif ) ;
extern int TIFFDefaultDirectory(TIFF *tif ) ;
extern void _TIFFSetDefaultCompressionState(TIFF *tif ) ;
extern int TIFFSetCompressionScheme(TIFF *tif , int scheme ) ;
extern int TIFFSetDefaultCompressionState(TIFF *tif ) ;
extern uint32 _TIFFDefaultStripSize(TIFF *tif , uint32 s ) ;
extern void _TIFFDefaultTileSize(TIFF *tif , uint32 *tw , uint32 *th ) ;
extern int _TIFFDataSize(TIFFDataType type ) ;
extern void _TIFFsetByteArray(void ** , void * , uint32  ) ;
extern void _TIFFsetString(char ** , char * ) ;
extern void _TIFFsetShortArray(uint16 ** , uint16 * , uint32  ) ;
extern void _TIFFsetLongArray(uint32 ** , uint32 * , uint32  ) ;
extern void _TIFFsetFloatArray(float ** , float * , uint32  ) ;
extern void _TIFFsetDoubleArray(double ** , double * , uint32  ) ;
extern void _TIFFprintAscii(FILE * , char const   * ) ;
extern void _TIFFprintAsciiTag(FILE * , char const   * , char const   * ) ;
extern void (*_TIFFwarningHandler)(char const   * , char const   * , va_list  ) ;
extern void (*_TIFFerrorHandler)(char const   * , char const   * , va_list  ) ;
extern void (*_TIFFwarningHandlerExt)(thandle_t  , char const   * ,
                                      char const   * , va_list  ) ;
extern void (*_TIFFerrorHandlerExt)(thandle_t  , char const   * ,
                                    char const   * , va_list  ) ;
extern void *_TIFFCheckMalloc(TIFF *tif , tmsize_t nmemb , tmsize_t elem_size ,
                              char const   *what ) ;
extern void *_TIFFCheckRealloc(TIFF *tif , void *buffer , tmsize_t nmemb ,
                               tmsize_t elem_size , char const   *what ) ;
extern double _TIFFUInt64ToDouble(uint64  ) ;
extern float _TIFFUInt64ToFloat(uint64  ) ;
extern int TIFFInitDumpMode(TIFF * , int  ) ;
extern int TIFFInitPackBits(TIFF * , int  ) ;
extern int TIFFInitCCITTRLE(TIFF * , int  ) ;
extern int TIFFInitCCITTRLEW(TIFF * , int  ) ;
extern int TIFFInitCCITTFax3(TIFF * , int  ) ;
extern int TIFFInitCCITTFax4(TIFF * , int  ) ;
extern int TIFFInitThunderScan(TIFF * , int  ) ;
extern int TIFFInitNeXT(TIFF * , int  ) ;
extern int TIFFInitLZW(TIFF * , int  ) ;
extern int TIFFInitZIP(TIFF * , int  ) ;
extern int TIFFInitPixarLog(TIFF * , int  ) ;
extern int TIFFInitSGILog(TIFF * , int  ) ;
extern TIFFCodec _TIFFBuiltinCODECS[] ;
static int TIFFWriteDirectorySec(TIFF *tif , int isimage , int imagedone ,
                                 uint64 *pdiroff ) ;
static int TIFFWriteDirectoryTagSampleformatPerSample(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag , double value ) ;
static int TIFFWriteDirectoryTagAscii(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint32 count , char *value ) ;
static int TIFFWriteDirectoryTagUndefinedArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint8 *value ) ;
static int TIFFWriteDirectoryTagByte(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint8 value ) ;
static int TIFFWriteDirectoryTagByteArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint8 *value ) ;
static int TIFFWriteDirectoryTagBytePerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint8 value ) ;
static int TIFFWriteDirectoryTagSbyte(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      int8 value ) ;
static int TIFFWriteDirectoryTagSbyteArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int8 *value ) ;
static int TIFFWriteDirectoryTagSbytePerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int8 value ) ;
static int TIFFWriteDirectoryTagShort(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint16 value ) ;
static int TIFFWriteDirectoryTagShortArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint16 *value ) ;
static int TIFFWriteDirectoryTagShortPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint16 value ) ;
static int TIFFWriteDirectoryTagSshort(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir , uint16 tag ,
                                       int16 value ) ;
static int TIFFWriteDirectoryTagSshortArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int16 *value ) ;
static int TIFFWriteDirectoryTagSshortPerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                int16 value ) ;
static int TIFFWriteDirectoryTagLong(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint32 value ) ;
static int TIFFWriteDirectoryTagLongArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint32 *value ) ;
static int TIFFWriteDirectoryTagLongPerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 value ) ;
static int TIFFWriteDirectoryTagSlong(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      int32 value ) ;
static int TIFFWriteDirectoryTagSlongArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int32 *value ) ;
static int TIFFWriteDirectoryTagSlongPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int32 value ) ;
static int TIFFWriteDirectoryTagLong8(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint64 value ) ;
static int TIFFWriteDirectoryTagLong8Array(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint64 *value ) ;
static int TIFFWriteDirectoryTagSlong8(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir , uint16 tag ,
                                       int64 value ) ;
static int TIFFWriteDirectoryTagSlong8Array(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int64 *value ) ;
static int TIFFWriteDirectoryTagRational(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         double value ) ;
static int TIFFWriteDirectoryTagRationalArray(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 count , float *value ) ;
static int TIFFWriteDirectoryTagSrationalArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , float *value ) ;
static int TIFFWriteDirectoryTagFloat(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      float value ) ;
static int TIFFWriteDirectoryTagFloatArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , float *value ) ;
static int TIFFWriteDirectoryTagFloatPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               float value ) ;
static int TIFFWriteDirectoryTagDouble(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir , uint16 tag ,
                                       double value ) ;
static int TIFFWriteDirectoryTagDoubleArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , double *value ) ;
static int TIFFWriteDirectoryTagDoublePerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) ;
static int TIFFWriteDirectoryTagIfdArray(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         uint32 count , uint32 *value ) ;
static int TIFFWriteDirectoryTagIfd8Array(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint64 *value ) ;
static int TIFFWriteDirectoryTagShortLong(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 value ) ;
static int TIFFWriteDirectoryTagLongLong8Array(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint64 *value ) ;
static int TIFFWriteDirectoryTagShortLongLong8Array(TIFF *tif , uint32 *ndir ,
                                                    TIFFDirEntry *dir ,
                                                    uint16 tag , uint32 count ,
                                                    uint64 *value ) ;
static int TIFFWriteDirectoryTagColormap(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir ) ;
static int TIFFWriteDirectoryTagTransferfunction(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ) ;
static int TIFFWriteDirectoryTagSubifd(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir ) ;
static int TIFFWriteDirectoryTagCheckedAscii(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint32 count , char *value ) ;
static int TIFFWriteDirectoryTagCheckedUndefinedArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      uint8 *value ) ;
static int TIFFWriteDirectoryTagCheckedByte(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint8 value ) ;
static int TIFFWriteDirectoryTagCheckedByteArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint8 *value ) ;
static int TIFFWriteDirectoryTagCheckedSbyte(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             int8 value ) ;
static int TIFFWriteDirectoryTagCheckedSbyteArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int8 *value ) ;
static int TIFFWriteDirectoryTagCheckedShort(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint16 value ) ;
static int TIFFWriteDirectoryTagCheckedShortArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint16 *value ) ;
static int TIFFWriteDirectoryTagCheckedSshort(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              int16 value ) ;
static int TIFFWriteDirectoryTagCheckedSshortArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int16 *value ) ;
static int TIFFWriteDirectoryTagCheckedLong(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 value ) ;
static int TIFFWriteDirectoryTagCheckedLongArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint32 *value ) ;
static int TIFFWriteDirectoryTagCheckedSlong(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             int32 value ) ;
static int TIFFWriteDirectoryTagCheckedSlongArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int32 *value ) ;
static int TIFFWriteDirectoryTagCheckedLong8(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint64 value ) ;
static int TIFFWriteDirectoryTagCheckedLong8Array(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint64 *value ) ;
static int TIFFWriteDirectoryTagCheckedSlong8(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              int64 value ) ;
static int TIFFWriteDirectoryTagCheckedSlong8Array(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int64 *value ) ;
static int TIFFWriteDirectoryTagCheckedRational(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) ;
static int TIFFWriteDirectoryTagCheckedRationalArray(TIFF *tif , uint32 *ndir ,
                                                     TIFFDirEntry *dir ,
                                                     uint16 tag , uint32 count ,
                                                     float *value ) ;
static int TIFFWriteDirectoryTagCheckedSrationalArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      float *value ) ;
static int TIFFWriteDirectoryTagCheckedFloat(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             float value ) ;
static int TIFFWriteDirectoryTagCheckedFloatArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  float *value ) ;
static int TIFFWriteDirectoryTagCheckedDouble(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              double value ) ;
static int TIFFWriteDirectoryTagCheckedDoubleArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   double *value ) ;
static int TIFFWriteDirectoryTagCheckedIfdArray(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                uint32 count , uint32 *value ) ;
static int TIFFWriteDirectoryTagCheckedIfd8Array(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint64 *value ) ;
static int TIFFWriteDirectoryTagData(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint16 datatype , uint32 count ,
                                     uint32 datalength , void *data ) ;
static int TIFFLinkDirectory(TIFF *tif ) ;
int TIFFWriteDirectory(TIFF *tif ) 
{ 
  int tmp ;

  {
  tmp = TIFFWriteDirectorySec(tif, 1, 1, (uint64 *)((void *)0));
  return (tmp);
}
}
int TIFFCheckpointDirectory(TIFF *tif ) 
{ 
  int rc ;
  uint64 tmp ;

  {
  if ((unsigned int )tif->tif_dir.td_stripoffset == (unsigned int )((void *)0)) {
    TIFFSetupStrips(tif);
  } else {

  }
  rc = TIFFWriteDirectorySec(tif, 1, 0, (uint64 *)((void *)0));
  tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )0, 2);
  TIFFSetWriteOffset(tif, tmp);
  return (rc);
}
}
int TIFFWriteCustomDirectory(TIFF *tif , uint64 *pdiroff ) 
{ 
  int tmp ;

  {
  tmp = TIFFWriteDirectorySec(tif, 0, 0, pdiroff);
  return (tmp);
}
}
int TIFFRewriteDirectory(TIFF *tif ) ;
static char const   module[21]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'w',      (char const   )'r', 
        (char const   )'i',      (char const   )'t',      (char const   )'e',      (char const   )'D', 
        (char const   )'i',      (char const   )'r',      (char const   )'e',      (char const   )'c', 
        (char const   )'t',      (char const   )'o',      (char const   )'r',      (char const   )'y', 
        (char const   )'\000'};
int TIFFRewriteDirectory(TIFF *tif ) 
{ 
  int tmp ;
  tmsize_t tmp___0 ;
  uint32 nextdir ;
  uint16 dircount ;
  uint32 nextnextdir ;
  uint64 tmp___1 ;
  tmsize_t tmp___2 ;
  tmsize_t tmp___3 ;
  uint32 m ;
  tmsize_t tmp___4 ;
  tmsize_t tmp___5 ;
  uint64 nextdir___0 ;
  uint64 dircount64 ;
  uint16 dircount___0 ;
  uint64 nextnextdir___0 ;
  uint64 tmp___6 ;
  tmsize_t tmp___7 ;
  tmsize_t tmp___8 ;
  uint64 m___0 ;
  tmsize_t tmp___9 ;
  int tmp___10 ;

  {
  if (tif->tif_diroff == 0ULL) {
    tmp = TIFFWriteDirectory(tif);
    return (tmp);
  } else {

  }
  if (! (tif->tif_flags & 524288U)) {
    if ((uint64 )tif->tif_header.classic.tiff_diroff == tif->tif_diroff) {
      tif->tif_header.classic.tiff_diroff = (uint32 )0;
      tif->tif_diroff = (uint64 )0;
      (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )4, 0);
      tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                        (void *)(& tif->tif_header.classic.tiff_diroff),
                                        (tmsize_t )4);
      if (tmp___0 == 4L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "Error updating TIFF header");
        return (0);
      }
    } else {
      nextdir = tif->tif_header.classic.tiff_diroff;
      while (1) {
        tmp___1 = (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )nextdir,
                                         0);
        if (tmp___1 == (uint64 )nextdir) {
          tmp___2 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                           (void *)(& dircount), (tmsize_t )2);
          if (tmp___2 == 2L) {

          } else {
            TIFFErrorExt(tif->tif_clientdata, module,
                         "Error fetching directory count");
            return (0);
          }
        } else {
          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error fetching directory count");
          return (0);
        }
        if (tif->tif_flags & 128U) {
          TIFFSwabShort(& dircount);
        } else {

        }
        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (uint64 )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                               0);
        tmp___3 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& nextnextdir), (tmsize_t )4);
        if (tmp___3 == 4L) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error fetching directory link");
          return (0);
        }
        if (tif->tif_flags & 128U) {
          TIFFSwabLong(& nextnextdir);
        } else {

        }
        if ((uint64 )nextnextdir == tif->tif_diroff) {
          m = (uint32 )0;
          (*(tif->tif_seekproc))(tif->tif_clientdata,
                                 (uint64 )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                                 0);
          tmp___4 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m),
                                            (tmsize_t )4);
          if (tmp___4 == 4L) {

          } else {
            TIFFErrorExt(tif->tif_clientdata, module,
                         "Error writing directory link");
            return (0);
          }
          tif->tif_diroff = (uint64 )0;
          break;
        } else {

        }
        nextdir = nextnextdir;
      }
    }
  } else
  if (tif->tif_header.big.tiff_diroff == tif->tif_diroff) {
    tif->tif_header.big.tiff_diroff = (uint64 )0;
    tif->tif_diroff = (uint64 )0;
    (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )8, 0);
    tmp___5 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                      (void *)(& tif->tif_header.big.tiff_diroff),
                                      (tmsize_t )8);
    if (tmp___5 == 8L) {

    } else {
      TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                   "Error updating TIFF header");
      return (0);
    }
  } else {
    nextdir___0 = tif->tif_header.big.tiff_diroff;
    while (1) {
      tmp___6 = (*(tif->tif_seekproc))(tif->tif_clientdata, nextdir___0, 0);
      if (tmp___6 == nextdir___0) {
        tmp___7 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& dircount64), (tmsize_t )8);
        if (tmp___7 == 8L) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error fetching directory count");
          return (0);
        }
      } else {
        TIFFErrorExt(tif->tif_clientdata, module,
                     "Error fetching directory count");
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& dircount64);
      } else {

      }
      if (dircount64 > 65535ULL) {
        TIFFErrorExt(tif->tif_clientdata, module,
                     "Sanity check on tag count failed, likely corrupt TIFF");
        return (0);
      } else {

      }
      dircount___0 = (uint16 )dircount64;
      (*(tif->tif_seekproc))(tif->tif_clientdata,
                             (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                             0);
      tmp___8 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                       (void *)(& nextnextdir___0), (tmsize_t )8);
      if (tmp___8 == 8L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module,
                     "Error fetching directory link");
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& nextnextdir___0);
      } else {

      }
      if (nextnextdir___0 == tif->tif_diroff) {
        m___0 = (uint64 )0;
        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                               0);
        tmp___9 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                          (void *)(& m___0), (tmsize_t )8);
        if (tmp___9 == 8L) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error writing directory link");
          return (0);
        }
        tif->tif_diroff = (uint64 )0;
        break;
      } else {

      }
      nextdir___0 = nextnextdir___0;
    }
  }
  tmp___10 = TIFFWriteDirectory(tif);
  return (tmp___10);
}
}
static int TIFFWriteDirectorySec(TIFF *tif , int isimage , int imagedone ,
                                 uint64 *pdiroff ) ;
static char const   module___0[22]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'S',      (char const   )'e', 
        (char const   )'c',      (char const   )'\000'};
static int TIFFWriteDirectorySec(TIFF *tif , int isimage , int imagedone ,
                                 uint64 *pdiroff ) 
{ 
  uint32 ndir ;
  TIFFDirEntry *dir ;
  uint32 dirsize ;
  void *dirmem ;
  uint32 m ;
  tmsize_t orig_rawcc ;
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
  int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  uint16 na ;
  uint16 *nb ;
  int tmp___28 ;
  int tmp___29 ;
  int tmp___30 ;
  int tmp___31 ;
  int tmp___32 ;
  int tmp___33 ;
  int tmp___34 ;
  int tmp___35 ;
  int tmp___36 ;
  int tmp___37 ;
  int tmp___38 ;
  int tmp___39 ;
  uint32 n ;
  TIFFField const   *o ;
  uint32 pa ;
  char *pb ;
  size_t tmp___40 ;
  int tmp___41 ;
  uint16 p ;
  int tmp___42 ;
  uint32 p___0 ;
  int tmp___43 ;
  uint32 pa___0 ;
  void *pb___0 ;
  int tmp___44 ;
  int tmp___45 ;
  int tmp___46 ;
  int tmp___47 ;
  int tmp___48 ;
  int tmp___49 ;
  int tmp___50 ;
  int tmp___51 ;
  int tmp___52 ;
  int tmp___53 ;
  int tmp___54 ;
  int tmp___55 ;
  int tmp___56 ;
  int tmp___57 ;
  int tmp___58 ;
  int tmp___59 ;
  int tmp___60 ;
  void *tmp___61 ;
  int tmp___62 ;
  uint64 tmp___63 ;
  uint32 na___0 ;
  TIFFDirEntry *nb___0 ;
  uint8 *n___0 ;
  TIFFDirEntry *o___0 ;
  uint8 *n___1 ;
  TIFFDirEntry *o___1 ;
  uint64 tmp___64 ;
  tmsize_t tmp___65 ;

  {
  if (tif->tif_mode == 0) {
    return (1);
  } else {

  }
  if (imagedone) {
    orig_rawcc = tif->tif_rawcc;
    if (tif->tif_flags & 4096U) {
      tif->tif_flags &= 4294963199U;
      tmp = (*(tif->tif_postencode))(tif);
      if (tmp) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error post-encoding before directory write");
        return (0);
      }
    } else {

    }
    (*(tif->tif_close))(tif);
    if (tif->tif_rawcc > 0L) {
      if (tif->tif_rawcc != orig_rawcc) {
        if ((tif->tif_flags & 64U) != 0U) {
          tmp___0 = TIFFFlushData1(tif);
          if (tmp___0) {

          } else {
            TIFFErrorExt(tif->tif_clientdata, module___0,
                         "Error flushing data before directory write");
            return (0);
          }
        } else {

        }
      } else {

      }
    } else {

    }
    if (tif->tif_flags & 512U) {
      if (tif->tif_rawdata) {
        _TIFFfree((void *)tif->tif_rawdata);
        tif->tif_rawdata = (uint8 *)((void *)0);
        tif->tif_rawcc = (tmsize_t )0;
        tif->tif_rawdatasize = (tmsize_t )0;
      } else {

      }
    } else {

    }
    tif->tif_flags &= 4294967215U;
  } else {

  }
  dir = (TIFFDirEntry *)((void *)0);
  dirmem = (void *)0;
  dirsize = (uint32 )0;
  while (1) {
    ndir = (uint32 )0;
    if (isimage) {
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 1)) {
        tmp___1 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )256,
                                                 tif->tif_dir.td_imagewidth);
        if (tmp___1) {

        } else {
          goto bad;
        }
        tmp___2 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )257,
                                                 tif->tif_dir.td_imagelength);
        if (tmp___2) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 2)) {
        tmp___3 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )322,
                                                 tif->tif_dir.td_tilewidth);
        if (tmp___3) {

        } else {
          goto bad;
        }
        tmp___4 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )323,
                                                 tif->tif_dir.td_tilelength);
        if (tmp___4) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 3)) {
        tmp___5 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )282,
                                                (double )tif->tif_dir.td_xresolution);
        if (tmp___5) {

        } else {
          goto bad;
        }
        tmp___6 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )283,
                                                (double )tif->tif_dir.td_yresolution);
        if (tmp___6) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 4)) {
        tmp___7 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )286,
                                                (double )tif->tif_dir.td_xposition);
        if (tmp___7) {

        } else {
          goto bad;
        }
        tmp___8 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )287,
                                                (double )tif->tif_dir.td_yposition);
        if (tmp___8) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 5)) {
        tmp___9 = TIFFWriteDirectoryTagLong(tif, & ndir, dir, (uint16 )254,
                                            tif->tif_dir.td_subfiletype);
        if (tmp___9) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 6)) {
        tmp___10 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )258,
                                                       tif->tif_dir.td_bitspersample);
        if (tmp___10) {
          {


          }
        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 7)) {
        tmp___11 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )259,
                                              tif->tif_dir.td_compression);
        if (tmp___11) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 8)) {
        tmp___12 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )262,
                                              tif->tif_dir.td_photometric);
        if (tmp___12) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 9)) {
        tmp___13 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )263,
                                              tif->tif_dir.td_threshholding);
        if (tmp___13) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 10)) {
        tmp___14 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )266,
                                              tif->tif_dir.td_fillorder);
        if (tmp___14) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 15)) {
        tmp___15 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )274,
                                              tif->tif_dir.td_orientation);
        if (tmp___15) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 16)) {
        tmp___16 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )277,
                                              tif->tif_dir.td_samplesperpixel);
        if (tmp___16) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 17)) {
        tmp___17 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir,
                                                  (uint16 )278,
                                                  tif->tif_dir.td_rowsperstrip);
        if (tmp___17) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 18)) {
        tmp___18 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )280,
                                                       tif->tif_dir.td_minsamplevalue);
        if (tmp___18) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 19)) {
        tmp___19 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )281,
                                                       tif->tif_dir.td_maxsamplevalue);
        if (tmp___19) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 20)) {
        tmp___20 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )284,
                                              tif->tif_dir.td_planarconfig);
        if (tmp___20) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 22)) {
        tmp___21 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )296,
                                              tif->tif_dir.td_resolutionunit);
        if (tmp___21) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 23)) {
        tmp___22 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                   (uint16 )297, (uint32 )2,
                                                   & tif->tif_dir.td_pagenumber[0]);
        if (tmp___22) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 24)) {
        if (! ((tif->tif_flags & 1024U) != 0U)) {
          tmp___23 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )279,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripbytecount);
          if (tmp___23) {

          } else {
            goto bad;
          }
        } else {
          tmp___24 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )325,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripbytecount);
          if (tmp___24) {

          } else {
            goto bad;
          }
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 25)) {
        if (! ((tif->tif_flags & 1024U) != 0U)) {
          tmp___25 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )273,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripoffset);
          if (tmp___25) {

          } else {
            goto bad;
          }
        } else {
          tmp___26 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )324,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripoffset);
          if (tmp___26) {

          } else {
            goto bad;
          }
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 26)) {
        tmp___27 = TIFFWriteDirectoryTagColormap(tif, & ndir, dir);
        if (tmp___27) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 31)) {
        if (tif->tif_dir.td_extrasamples) {
          TIFFGetFieldDefaulted(tif, (uint32 )338, & na, & nb);
          tmp___28 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                     (uint16 )338, (uint32 )na,
                                                     nb);
          if (tmp___28) {

          } else {
            goto bad;
          }
        } else {

        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & 1UL) {
        tmp___29 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )339,
                                                       tif->tif_dir.td_sampleformat);
        if (tmp___29) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 1)) {
        tmp___30 = TIFFWriteDirectoryTagSampleformatPerSample(tif, & ndir, dir,
                                                              (uint16 )340,
                                                              tif->tif_dir.td_sminsamplevalue);
        if (tmp___30) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 2)) {
        tmp___31 = TIFFWriteDirectoryTagSampleformatPerSample(tif, & ndir, dir,
                                                              (uint16 )341,
                                                              tif->tif_dir.td_smaxsamplevalue);
        if (tmp___31) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 3)) {
        tmp___32 = TIFFWriteDirectoryTagLong(tif, & ndir, dir, (uint16 )32997,
                                             tif->tif_dir.td_imagedepth);
        if (tmp___32) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 4)) {
        tmp___33 = TIFFWriteDirectoryTagLong(tif, & ndir, dir, (uint16 )32998,
                                             tif->tif_dir.td_tiledepth);
        if (tmp___33) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 5)) {
        tmp___34 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                   (uint16 )321, (uint32 )2,
                                                   & tif->tif_dir.td_halftonehints[0]);
        if (tmp___34) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 7)) {
        tmp___35 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                   (uint16 )530, (uint32 )2,
                                                   & tif->tif_dir.td_ycbcrsubsampling[0]);
        if (tmp___35) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 8)) {
        tmp___36 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )531,
                                              tif->tif_dir.td_ycbcrpositioning);
        if (tmp___36) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 12)) {
        tmp___37 = TIFFWriteDirectoryTagTransferfunction(tif, & ndir, dir);
        if (tmp___37) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 14)) {
        tmp___38 = TIFFWriteDirectoryTagAscii(tif, & ndir, dir, (uint16 )333,
                                              (uint32 )tif->tif_dir.td_inknameslen,
                                              tif->tif_dir.td_inknames);
        if (tmp___38) {

        } else {
          goto bad;
        }
      } else {

      }
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 17)) {
        tmp___39 = TIFFWriteDirectoryTagSubifd(tif, & ndir, dir);
        if (tmp___39) {

        } else {
          goto bad;
        }
      } else {

      }
      n = (uint32 )0;
      while (n < tif->tif_nfields) {
        o = (TIFFField const   *)*(tif->tif_fields + n);
        if ((int const   )o->field_bit >= 66) {
          if (tif->tif_dir.td_fieldsset[(int const   )o->field_bit / 32] & (1UL << ((int const   )o->field_bit & 31))) {
            switch ((unsigned int const   )o->get_field_type) {
            case 1U: 
            if ((unsigned int const   )o->field_type == 2U) {

            } else {
              __assert_fail("o->field_type==TIFF_ASCII", "tif_dirwrite.c", 579U,
                            "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_readcount == -1) {

            } else {
              __assert_fail("o->field_readcount==-1", "tif_dirwrite.c", 580U,
                            "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_passcount == 0) {

            } else {
              __assert_fail("o->field_passcount==0", "tif_dirwrite.c", 581U,
                            "TIFFWriteDirectorySec");
            }
            TIFFGetField(tif, (uint32 )o->field_tag, & pb);
            tmp___40 = strlen((char const   *)pb);
            pa = tmp___40;
            tmp___41 = TIFFWriteDirectoryTagAscii(tif, & ndir, dir,
                                                  (uint16 )o->field_tag, pa, pb);
            if (tmp___41) {

            } else {
              goto bad;
            }
            break;
            case 4U: 
            if ((unsigned int const   )o->field_type == 3U) {

            } else {
              __assert_fail("o->field_type==TIFF_SHORT", "tif_dirwrite.c", 591U,
                            "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_readcount == 1) {

            } else {
              __assert_fail("o->field_readcount==1", "tif_dirwrite.c", 592U,
                            "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_passcount == 0) {

            } else {
              __assert_fail("o->field_passcount==0", "tif_dirwrite.c", 593U,
                            "TIFFWriteDirectorySec");
            }
            TIFFGetField(tif, (uint32 )o->field_tag, & p);
            tmp___42 = TIFFWriteDirectoryTagShort(tif, & ndir, dir,
                                                  (uint16 )o->field_tag, p);
            if (tmp___42) {

            } else {
              goto bad;
            }
            break;
            case 6U: 
            if ((unsigned int const   )o->field_type == 4U) {

            } else {
              __assert_fail("o->field_type==TIFF_LONG", "tif_dirwrite.c", 602U,
                            "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_readcount == 1) {

            } else {
              __assert_fail("o->field_readcount==1", "tif_dirwrite.c", 603U,
                            "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_passcount == 0) {

            } else {
              __assert_fail("o->field_passcount==0", "tif_dirwrite.c", 604U,
                            "TIFFWriteDirectorySec");
            }
            TIFFGetField(tif, (uint32 )o->field_tag, & p___0);
            tmp___43 = TIFFWriteDirectoryTagLong(tif, & ndir, dir,
                                                 (uint16 )o->field_tag, p___0);
            if (tmp___43) {

            } else {
              goto bad;
            }
            break;
            case 40U: 
            if ((unsigned int const   )o->field_type == 7U) {

            } else {
              __assert_fail("o->field_type==TIFF_UNDEFINED", "tif_dirwrite.c",
                            614U, "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_readcount == -3) {

            } else {
              __assert_fail("o->field_readcount==-3", "tif_dirwrite.c", 615U,
                            "TIFFWriteDirectorySec");
            }
            if ((int const   )o->field_passcount == 1) {

            } else {
              __assert_fail("o->field_passcount==1", "tif_dirwrite.c", 616U,
                            "TIFFWriteDirectorySec");
            }
            TIFFGetField(tif, (uint32 )o->field_tag, & pa___0, & pb___0);
            tmp___44 = TIFFWriteDirectoryTagUndefinedArray(tif, & ndir, dir,
                                                           (uint16 )o->field_tag,
                                                           pa___0,
                                                           (uint8 *)pb___0);
            if (tmp___44) {

            } else {
              goto bad;
            }
            break;
            default: 
            __assert_fail("0", "tif_dirwrite.c", 623U, "TIFFWriteDirectorySec");
            break;
            }
          } else {

          }
        } else {

        }
        n ++;
      }
    } else {

    }
    m = (uint32 )0;
    while (m < (uint32 )tif->tif_dir.td_customValueCount) {
      switch ((unsigned int const   )((tif->tif_dir.td_customValues + m)->info)->field_type) {
      case 2U: 
      tmp___45 = TIFFWriteDirectoryTagAscii(tif, & ndir, dir,
                                            (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                            (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                            (char *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___45) {

      } else {
        goto bad;
      }
      break;
      case 7U: 
      tmp___46 = TIFFWriteDirectoryTagUndefinedArray(tif, & ndir, dir,
                                                     (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                     (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                     (uint8 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___46) {

      } else {
        goto bad;
      }
      break;
      case 1U: 
      tmp___47 = TIFFWriteDirectoryTagByteArray(tif, & ndir, dir,
                                                (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                (uint8 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___47) {

      } else {
        goto bad;
      }
      break;
      case 6U: 
      tmp___48 = TIFFWriteDirectoryTagSbyteArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (int8 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___48) {

      } else {
        goto bad;
      }
      break;
      case 3U: 
      tmp___49 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (uint16 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___49) {

      } else {
        goto bad;
      }
      break;
      case 8U: 
      tmp___50 = TIFFWriteDirectoryTagSshortArray(tif, & ndir, dir,
                                                  (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                  (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                  (int16 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___50) {

      } else {
        goto bad;
      }
      break;
      case 4U: 
      tmp___51 = TIFFWriteDirectoryTagLongArray(tif, & ndir, dir,
                                                (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                (uint32 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___51) {

      } else {
        goto bad;
      }
      break;
      case 9U: 
      tmp___52 = TIFFWriteDirectoryTagSlongArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (int32 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___52) {

      } else {
        goto bad;
      }
      break;
      case 16U: 
      tmp___53 = TIFFWriteDirectoryTagLong8Array(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (uint64 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___53) {

      } else {
        goto bad;
      }
      break;
      case 17U: 
      tmp___54 = TIFFWriteDirectoryTagSlong8Array(tif, & ndir, dir,
                                                  (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                  (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                  (int64 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___54) {

      } else {
        goto bad;
      }
      break;
      case 5U: 
      tmp___55 = TIFFWriteDirectoryTagRationalArray(tif, & ndir, dir,
                                                    (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                    (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                    (float *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___55) {

      } else {
        goto bad;
      }
      break;
      case 10U: 
      tmp___56 = TIFFWriteDirectoryTagSrationalArray(tif, & ndir, dir,
                                                     (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                     (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                     (float *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___56) {

      } else {
        goto bad;
      }
      break;
      case 11U: 
      tmp___57 = TIFFWriteDirectoryTagFloatArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (float *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___57) {

      } else {
        goto bad;
      }
      break;
      case 12U: 
      tmp___58 = TIFFWriteDirectoryTagDoubleArray(tif, & ndir, dir,
                                                  (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                  (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                  (double *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___58) {

      } else {
        goto bad;
      }
      break;
      case 13U: 
      tmp___59 = TIFFWriteDirectoryTagIfdArray(tif, & ndir, dir,
                                               (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                               (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                               (uint32 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___59) {

      } else {
        goto bad;
      }
      break;
      case 18U: 
      tmp___60 = TIFFWriteDirectoryTagIfd8Array(tif, & ndir, dir,
                                                (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                (uint64 *)(tif->tif_dir.td_customValues + m)->value);
      if (tmp___60) {

      } else {
        goto bad;
      }
      break;
      default: 
      __assert_fail("0", "tif_dirwrite.c", 699U, "TIFFWriteDirectorySec");
      break;
      }
      m ++;
    }
    if ((unsigned int )dir != (unsigned int )((void *)0)) {
      break;
    } else {

    }
    tmp___61 = _TIFFmalloc((tmsize_t )(ndir * sizeof(TIFFDirEntry )));
    dir = (TIFFDirEntry *)tmp___61;
    if ((unsigned int )dir == (unsigned int )((void *)0)) {
      TIFFErrorExt(tif->tif_clientdata, module___0, "Out of memory");
      goto bad;
    } else {

    }
    if (isimage) {
      if (tif->tif_diroff == 0ULL) {
        tmp___62 = TIFFLinkDirectory(tif);
        if (tmp___62) {

        } else {
          goto bad;
        }
      } else {

      }
    } else {
      tmp___63 = (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )0, 2);
      tif->tif_diroff = (tmp___63 + 1ULL) & 0xfffffffffffffffeULL;
    }
    if ((unsigned int )pdiroff != (unsigned int )((void *)0)) {
      *pdiroff = tif->tif_diroff;
    } else {

    }
    if (! (tif->tif_flags & 524288U)) {
      dirsize = (2U + ndir * 12U) + 4U;
    } else {
      dirsize = (8U + ndir * 20U) + 8U;
    }
    tif->tif_dataoff = tif->tif_diroff + (uint64 )dirsize;
    if (! (tif->tif_flags & 524288U)) {
      tif->tif_dataoff = (uint64 )((uint32 )tif->tif_dataoff);
    } else {

    }
    if (tif->tif_dataoff < tif->tif_diroff) {
      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Maximum TIFF file size exceeded");
      goto bad;
    } else
    if (tif->tif_dataoff < (uint64 )dirsize) {
      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Maximum TIFF file size exceeded");
      goto bad;
    } else {

    }
    if (tif->tif_dataoff & 1ULL) {
      (tif->tif_dataoff) ++;
    } else {

    }
    if (isimage) {
      tif->tif_curdir = (uint16 )((int )tif->tif_curdir + 1);
    } else {

    }
  }
  if (isimage) {
    if (tif->tif_dir.td_fieldsset[1] & (1UL << 17)) {
      if (tif->tif_subifdoff == 0ULL) {
        na___0 = (uint32 )0;
        nb___0 = dir;
        while (1) {
          if (na___0 < ndir) {

          } else {
            __assert_fail("na<ndir", "tif_dirwrite.c", 745U,
                          "TIFFWriteDirectorySec");
          }
          if ((int )nb___0->tdir_tag == 330) {
            break;
          } else {

          }
          na___0 ++;
          nb___0 ++;
        }
        if (! (tif->tif_flags & 524288U)) {
          tif->tif_subifdoff = ((tif->tif_diroff + 2ULL) + (uint64 )(na___0 * 12U)) + 8ULL;
        } else {
          tif->tif_subifdoff = ((tif->tif_diroff + 8ULL) + (uint64 )(na___0 * 20U)) + 12ULL;
        }
      } else {

      }
    } else {

    }
  } else {

  }
  dirmem = _TIFFmalloc((tmsize_t )dirsize);
  if ((unsigned int )dirmem == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___0, "Out of memory");
    goto bad;
  } else {

  }
  if (! (tif->tif_flags & 524288U)) {
    n___0 = (uint8 *)dirmem;
    *((uint16 *)n___0) = (uint16 )ndir;
    if (tif->tif_flags & 128U) {
      TIFFSwabShort((uint16 *)n___0);
    } else {

    }
    n___0 += 2;
    o___0 = dir;
    m = (uint32 )0;
    while (m < ndir) {
      *((uint16 *)n___0) = o___0->tdir_tag;
      if (tif->tif_flags & 128U) {
        TIFFSwabShort((uint16 *)n___0);
      } else {

      }
      n___0 += 2;
      *((uint16 *)n___0) = o___0->tdir_type;
      if (tif->tif_flags & 128U) {
        TIFFSwabShort((uint16 *)n___0);
      } else {

      }
      n___0 += 2;
      *((uint32 *)n___0) = (uint32 )o___0->tdir_count;
      if (tif->tif_flags & 128U) {
        TIFFSwabLong((uint32 *)n___0);
      } else {

      }
      n___0 += 4;
      _TIFFmemcpy((void *)n___0, (void const   *)(& o___0->tdir_offset),
                  (tmsize_t )4);
      n___0 += 4;
      o___0 ++;
      m ++;
    }
    *((uint32 *)n___0) = (uint32 )tif->tif_nextdiroff;
  } else {
    n___1 = (uint8 *)dirmem;
    *((uint64 *)n___1) = (uint64 )ndir;
    if (tif->tif_flags & 128U) {
      TIFFSwabLong8((uint64 *)n___1);
    } else {

    }
    n___1 += 8;
    o___1 = dir;
    m = (uint32 )0;
    while (m < ndir) {
      *((uint16 *)n___1) = o___1->tdir_tag;
      if (tif->tif_flags & 128U) {
        TIFFSwabShort((uint16 *)n___1);
      } else {

      }
      n___1 += 2;
      *((uint16 *)n___1) = o___1->tdir_type;
      if (tif->tif_flags & 128U) {
        TIFFSwabShort((uint16 *)n___1);
      } else {

      }
      n___1 += 2;
      *((uint64 *)n___1) = o___1->tdir_count;
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8((uint64 *)n___1);
      } else {

      }
      n___1 += 8;
      _TIFFmemcpy((void *)n___1, (void const   *)(& o___1->tdir_offset),
                  (tmsize_t )8);
      n___1 += 8;
      o___1 ++;
      m ++;
    }
    *((uint64 *)n___1) = tif->tif_nextdiroff;
  }
  _TIFFfree((void *)dir);
  dir = (TIFFDirEntry *)((void *)0);
  tmp___64 = (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_diroff, 0);
  if (tmp___64 == tif->tif_diroff) {

  } else {
    TIFFErrorExt(tif->tif_clientdata, module___0, "IO error writing directory");
    goto bad;
  }
  tmp___65 = (*(tif->tif_writeproc))(tif->tif_clientdata, dirmem,
                                     (tmsize_t )dirsize);
  if (tmp___65 == (tmsize_t )dirsize) {

  } else {
    TIFFErrorExt(tif->tif_clientdata, module___0, "IO error writing directory");
    goto bad;
  }
  _TIFFfree(dirmem);

  return (1);
  bad: 
  if ((unsigned int )dir != (unsigned int )((void *)0)) {
    _TIFFfree((void *)dir);
  } else {

  }
  if ((unsigned int )dirmem != (unsigned int )((void *)0)) {
    _TIFFfree(dirmem);
  } else {

  }
  return (0);
}
}
static int TIFFWriteDirectoryTagSampleformatPerSample(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag , double value ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;

  {
  switch ((int )tif->tif_dir.td_sampleformat) {
  case 3: 
  if ((int )tif->tif_dir.td_bitspersample <= 32) {
    tmp = TIFFWriteDirectoryTagFloatPerSample(tif, ndir, dir, tag, (float )value);
    return (tmp);
  } else {
    tmp___0 = TIFFWriteDirectoryTagDoublePerSample(tif, ndir, dir, tag, value);
    return (tmp___0);
  }
  case 2: 
  if ((int )tif->tif_dir.td_bitspersample <= 8) {
    tmp___1 = TIFFWriteDirectoryTagSbytePerSample(tif, ndir, dir, tag,
                                                  (int8 )value);
    return (tmp___1);
  } else
  if ((int )tif->tif_dir.td_bitspersample <= 16) {
    tmp___2 = TIFFWriteDirectoryTagSshortPerSample(tif, ndir, dir, tag,
                                                   (int16 )value);
    return (tmp___2);
  } else {
    tmp___3 = TIFFWriteDirectoryTagSlongPerSample(tif, ndir, dir, tag,
                                                  (int32 )value);
    return (tmp___3);
  }
  case 1: 
  if ((int )tif->tif_dir.td_bitspersample <= 8) {
    tmp___4 = TIFFWriteDirectoryTagBytePerSample(tif, ndir, dir, tag,
                                                 (uint8 )value);
    return (tmp___4);
  } else
  if ((int )tif->tif_dir.td_bitspersample <= 16) {
    tmp___5 = TIFFWriteDirectoryTagShortPerSample(tif, ndir, dir, tag,
                                                  (uint16 )value);
    return (tmp___5);
  } else {
    tmp___6 = TIFFWriteDirectoryTagLongPerSample(tif, ndir, dir, tag,
                                                 (uint32 )value);
    return (tmp___6);
  }
  default: 
  return (1);
  }
}
}
static int TIFFWriteDirectoryTagAscii(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint32 count , char *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedAscii(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagUndefinedArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint8 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedUndefinedArray(tif, ndir, dir, tag, count,
                                                   value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagByte(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint8 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedByte(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagByteArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint8 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedByteArray(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagBytePerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint8 value ) ;
static char const   module___1[35]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'B',      (char const   )'y',      (char const   )'t', 
        (char const   )'e',      (char const   )'P',      (char const   )'e',      (char const   )'r', 
        (char const   )'S',      (char const   )'a',      (char const   )'m',      (char const   )'p', 
        (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagBytePerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint8 value ) 
{ 
  uint8 *m ;
  uint8 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(uint8 )));
  m = (uint8 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___1, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedByteArray(tif, ndir, dir, tag,
                                            (uint32 )tif->tif_dir.td_samplesperpixel,
                                            m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagSbyte(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      int8 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSbyte(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSbyteArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int8 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSbyteArray(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSbytePerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int8 value ) ;
static char const   module___2[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'b',      (char const   )'y', 
        (char const   )'t',      (char const   )'e',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagSbytePerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int8 value ) 
{ 
  int8 *m ;
  int8 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(int8 )));
  m = (int8 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___2, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedSbyteArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagShort(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint16 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedShort(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagShortArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint16 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagShortPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint16 value ) ;
static char const   module___3[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'h',      (char const   )'o', 
        (char const   )'r',      (char const   )'t',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagShortPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint16 value ) 
{ 
  uint16 *m ;
  uint16 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(uint16 )));
  m = (uint16 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___3, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagSshort(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir , uint16 tag ,
                                       int16 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSshort(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSshortArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int16 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSshortArray(tif, ndir, dir, tag, count,
                                                value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSshortPerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                int16 value ) ;
static char const   module___4[37]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'s',      (char const   )'h', 
        (char const   )'o',      (char const   )'r',      (char const   )'t',      (char const   )'P', 
        (char const   )'e',      (char const   )'r',      (char const   )'S',      (char const   )'a', 
        (char const   )'m',      (char const   )'p',      (char const   )'l',      (char const   )'e', 
        (char const   )'\000'};
static int TIFFWriteDirectoryTagSshortPerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                int16 value ) 
{ 
  int16 *m ;
  int16 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(int16 )));
  m = (int16 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___4, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedSshortArray(tif, ndir, dir, tag,
                                              (uint32 )tif->tif_dir.td_samplesperpixel,
                                              m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagLong(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint32 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedLong(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagLongArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint32 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedLongArray(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagLongPerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 value ) ;
static char const   module___5[35]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'L',      (char const   )'o',      (char const   )'n', 
        (char const   )'g',      (char const   )'P',      (char const   )'e',      (char const   )'r', 
        (char const   )'S',      (char const   )'a',      (char const   )'m',      (char const   )'p', 
        (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagLongPerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 value ) 
{ 
  uint32 *m ;
  uint32 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(uint32 )));
  m = (uint32 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___5, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedLongArray(tif, ndir, dir, tag,
                                            (uint32 )tif->tif_dir.td_samplesperpixel,
                                            m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagSlong(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      int32 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSlong(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSlongArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int32 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSlongArray(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSlongPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int32 value ) ;
static char const   module___6[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'l',      (char const   )'o', 
        (char const   )'n',      (char const   )'g',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagSlongPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int32 value ) 
{ 
  int32 *m ;
  int32 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(int32 )));
  m = (int32 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___6, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedSlongArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagLong8(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint64 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedLong8(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagLong8Array(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint64 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedLong8Array(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSlong8(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir , uint16 tag ,
                                       int64 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSlong8(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSlong8Array(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int64 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSlong8Array(tif, ndir, dir, tag, count,
                                                value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagRational(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         double value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedRational(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagRationalArray(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 count , float *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedRationalArray(tif, ndir, dir, tag, count,
                                                  value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSrationalArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , float *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedSrationalArray(tif, ndir, dir, tag, count,
                                                   value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagFloat(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      float value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedFloat(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagFloatArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , float *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedFloatArray(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagFloatPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               float value ) ;
static char const   module___7[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'F',      (char const   )'l',      (char const   )'o', 
        (char const   )'a',      (char const   )'t',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagFloatPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               float value ) 
{ 
  float *m ;
  float *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(float )));
  m = (float *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___7, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedFloatArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagDouble(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir , uint16 tag ,
                                       double value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedDouble(tif, ndir, dir, tag, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagDoubleArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , double *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedDoubleArray(tif, ndir, dir, tag, count,
                                                value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagDoublePerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) ;
static char const   module___8[37]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'D',      (char const   )'o',      (char const   )'u', 
        (char const   )'b',      (char const   )'l',      (char const   )'e',      (char const   )'P', 
        (char const   )'e',      (char const   )'r',      (char const   )'S',      (char const   )'a', 
        (char const   )'m',      (char const   )'p',      (char const   )'l',      (char const   )'e', 
        (char const   )'\000'};
static int TIFFWriteDirectoryTagDoublePerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) 
{ 
  double *m ;
  double *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(double )));
  m = (double *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___8, "Out of memory");
    return (0);
  } else {

  }
  na = m;
  nb = (uint16 )0;
  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;
    na ++;
    nb = (uint16 )((int )nb + 1);
  }
  o = TIFFWriteDirectoryTagCheckedDoubleArray(tif, ndir, dir, tag,
                                              (uint32 )tif->tif_dir.td_samplesperpixel,
                                              m);
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagIfdArray(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         uint32 count , uint32 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedIfdArray(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagIfd8Array(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint64 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  tmp = TIFFWriteDirectoryTagCheckedIfd8Array(tif, ndir, dir, tag, count, value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagShortLong(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 value ) 
{ 
  int tmp ;
  int tmp___0 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  if (value <= 65535U) {
    tmp = TIFFWriteDirectoryTagCheckedShort(tif, ndir, dir, tag, (uint16 )value);
    return (tmp);
  } else {
    tmp___0 = TIFFWriteDirectoryTagCheckedLong(tif, ndir, dir, tag, value);
    return (tmp___0);
  }
}
}
static int TIFFWriteDirectoryTagLongLong8Array(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint64 *value ) ;
static char const   module___9[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'L',      (char const   )'o',      (char const   )'n', 
        (char const   )'g',      (char const   )'L',      (char const   )'o',      (char const   )'n', 
        (char const   )'g',      (char const   )'8',      (char const   )'A',      (char const   )'r', 
        (char const   )'r',      (char const   )'a',      (char const   )'y',      (char const   )'\000'};
static int TIFFWriteDirectoryTagLongLong8Array(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint64 *value ) 
{ 
  uint64 *ma ;
  uint32 mb ;
  uint32 *p ;
  uint32 *q ;
  int o ;
  int tmp ;
  void *tmp___0 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  if (tif->tif_flags & 524288U) {
    tmp = TIFFWriteDirectoryTagCheckedLong8Array(tif, ndir, dir, tag, count,
                                                 value);
    return (tmp);
  } else {

  }
  tmp___0 = _TIFFmalloc((tmsize_t )(count * sizeof(uint32 )));
  p = (uint32 *)tmp___0;
  if ((unsigned int )p == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___9, "Out of memory");
    return (0);
  } else {

  }
  q = p;
  ma = value;
  mb = (uint32 )0;
  while (mb < count) {
    if (*ma > 4294967295ULL) {
      TIFFErrorExt(tif->tif_clientdata, module___9,
                   "Attempt to write value larger than 0xFFFFFFFF in Classic TIFF file.");
      _TIFFfree((void *)p);
      return (0);
    } else {

    }
    *q = (uint32 )*ma;
    ma ++;
    mb ++;
    q ++;
  }
  o = TIFFWriteDirectoryTagCheckedLongArray(tif, ndir, dir, tag, count, p);
  _TIFFfree((void *)p);
  return (o);
}
}
static int TIFFWriteDirectoryTagShortLongLong8Array(TIFF *tif , uint32 *ndir ,
                                                    TIFFDirEntry *dir ,
                                                    uint16 tag , uint32 count ,
                                                    uint64 *value ) ;
static char const   module___10[41]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'h',      (char const   )'o', 
        (char const   )'r',      (char const   )'t',      (char const   )'L',      (char const   )'o', 
        (char const   )'n',      (char const   )'g',      (char const   )'L',      (char const   )'o', 
        (char const   )'n',      (char const   )'g',      (char const   )'8',      (char const   )'A', 
        (char const   )'r',      (char const   )'r',      (char const   )'a',      (char const   )'y', 
        (char const   )'\000'};
static int TIFFWriteDirectoryTagShortLongLong8Array(TIFF *tif , uint32 *ndir ,
                                                    TIFFDirEntry *dir ,
                                                    uint16 tag , uint32 count ,
                                                    uint64 *value ) 
{ 
  uint64 *ma ;
  uint32 mb ;
  uint8 n ;
  int o ;
  uint16 *p ;
  uint16 *q ;
  void *tmp ;
  uint32 *p___0 ;
  uint32 *q___0 ;
  void *tmp___0 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  n = (uint8 )0;
  ma = value;
  mb = (uint32 )0;
  while (mb < count) {
    if ((int )n == 0) {
      if (*ma > 65535ULL) {
        n = (uint8 )1;
      } else {

      }
    } else {

    }
    if ((int )n == 1) {
      if (*ma > 4294967295ULL) {
        n = (uint8 )2;
        break;
      } else {

      }
    } else {

    }
    ma ++;
    mb ++;
  }
  if ((int )n == 0) {
    tmp = _TIFFmalloc((tmsize_t )(count * sizeof(uint16 )));
    p = (uint16 *)tmp;
    if ((unsigned int )p == (unsigned int )((void *)0)) {
      TIFFErrorExt(tif->tif_clientdata, module___10, "Out of memory");
      return (0);
    } else {

    }
    ma = value;
    mb = (uint32 )0;
    q = p;
    while (mb < count) {
      *q = (uint16 )*ma;
      ma ++;
      mb ++;
      q ++;
    }
    o = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, tag, count, p);
    _TIFFfree((void *)p);
  } else
  if ((int )n == 1) {
    tmp___0 = _TIFFmalloc((tmsize_t )(count * sizeof(uint32 )));
    p___0 = (uint32 *)tmp___0;
    if ((unsigned int )p___0 == (unsigned int )((void *)0)) {
      TIFFErrorExt(tif->tif_clientdata, module___10, "Out of memory");
      return (0);
    } else {

    }
    ma = value;
    mb = (uint32 )0;
    q___0 = p___0;
    while (mb < count) {
      *q___0 = (uint32 )*ma;
      ma ++;
      mb ++;
      q___0 ++;
    }
    o = TIFFWriteDirectoryTagCheckedLongArray(tif, ndir, dir, tag, count, p___0);
    _TIFFfree((void *)p___0);
  } else {
    if ((int )n == 2) {

    } else {
      __assert_fail("n==2", "tif_dirwrite.c", 1511U,
                    "TIFFWriteDirectoryTagShortLongLong8Array");
    }
    o = TIFFWriteDirectoryTagCheckedLong8Array(tif, ndir, dir, tag, count, value);
  }
  return (o);
}
}
static int TIFFWriteDirectoryTagColormap(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir ) ;
static char const   module___11[30]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'C',      (char const   )'o',      (char const   )'l', 
        (char const   )'o',      (char const   )'r',      (char const   )'m',      (char const   )'a', 
        (char const   )'p',      (char const   )'\000'};
static int TIFFWriteDirectoryTagColormap(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir ) 
{ 
  uint32 m ;
  uint16 *n ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  m = (uint32 )(1 << (int )tif->tif_dir.td_bitspersample);
  tmp = _TIFFmalloc((tmsize_t )((3U * m) * sizeof(uint16 )));
  n = (uint16 *)tmp;
  if ((unsigned int )n == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___11, "Out of memory");
    return (0);
  } else {

  }
  _TIFFmemcpy((void *)(n + 0), (void const   *)tif->tif_dir.td_colormap[0],
              (tmsize_t )(m * sizeof(uint16 )));
  _TIFFmemcpy((void *)(n + m), (void const   *)tif->tif_dir.td_colormap[1],
              (tmsize_t )(m * sizeof(uint16 )));
  _TIFFmemcpy((void *)(n + 2U * m), (void const   *)tif->tif_dir.td_colormap[2],
              (tmsize_t )(m * sizeof(uint16 )));
  o = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, (uint16 )320,
                                             3U * m, n);
  _TIFFfree((void *)n);
  return (o);
}
}
static int TIFFWriteDirectoryTagTransferfunction(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ) ;
static char const   module___12[38]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'T',      (char const   )'r',      (char const   )'a', 
        (char const   )'n',      (char const   )'s',      (char const   )'f',      (char const   )'e', 
        (char const   )'r',      (char const   )'f',      (char const   )'u',      (char const   )'n', 
        (char const   )'c',      (char const   )'t',      (char const   )'i',      (char const   )'o', 
        (char const   )'n',      (char const   )'\000'};
static int TIFFWriteDirectoryTagTransferfunction(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ) 
{ 
  uint32 m ;
  uint16 n ;
  uint16 *o ;
  int p ;
  int tmp ;
  int tmp___0 ;
  void *tmp___1 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  m = (uint32 )(1 << (int )tif->tif_dir.td_bitspersample);
  n = (uint16 )((int )tif->tif_dir.td_samplesperpixel - (int )tif->tif_dir.td_extrasamples);
  if ((int )n > 3) {
    n = (uint16 )3;
  } else {

  }
  if ((int )n == 3) {
    tmp = _TIFFmemcmp((void const   *)tif->tif_dir.td_transferfunction[0],
                      (void const   *)tif->tif_dir.td_transferfunction[2],
                      (tmsize_t )(m * sizeof(uint16 )));
    if (tmp) {

    } else {
      n = (uint16 )2;
    }
  } else {

  }
  if ((int )n == 2) {
    tmp___0 = _TIFFmemcmp((void const   *)tif->tif_dir.td_transferfunction[0],
                          (void const   *)tif->tif_dir.td_transferfunction[1],
                          (tmsize_t )(m * sizeof(uint16 )));
    if (tmp___0) {

    } else {
      n = (uint16 )1;
    }
  } else {

  }
  if ((int )n == 0) {
    n = (uint16 )1;
  } else {

  }
  tmp___1 = _TIFFmalloc((tmsize_t )(((uint32 )n * m) * sizeof(uint16 )));
  o = (uint16 *)tmp___1;
  if ((unsigned int )o == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___12, "Out of memory");
    return (0);
  } else {

  }
  _TIFFmemcpy((void *)(o + 0),
              (void const   *)tif->tif_dir.td_transferfunction[0],
              (tmsize_t )(m * sizeof(uint16 )));
  if ((int )n > 1) {
    _TIFFmemcpy((void *)(o + m),
                (void const   *)tif->tif_dir.td_transferfunction[1],
                (tmsize_t )(m * sizeof(uint16 )));
  } else {

  }
  if ((int )n > 2) {
    _TIFFmemcpy((void *)(o + 2U * m),
                (void const   *)tif->tif_dir.td_transferfunction[2],
                (tmsize_t )(m * sizeof(uint16 )));
  } else {

  }
  p = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, (uint16 )301,
                                             (uint32 )n * m, o);
  _TIFFfree((void *)o);
  return (p);
}
}
static int TIFFWriteDirectoryTagSubifd(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir ) ;
static char const   module___13[28]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'u',      (char const   )'b', 
        (char const   )'i',      (char const   )'f',      (char const   )'d',      (char const   )'\000'};
static int TIFFWriteDirectoryTagSubifd(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir ) 
{ 
  uint64 m ;
  int n ;
  uint32 *o ;
  uint64 *pa ;
  uint32 *pb ;
  uint16 p ;
  void *tmp ;
  uint32 *tmp___0 ;
  uint64 *tmp___1 ;

  {
  if ((int )tif->tif_dir.td_nsubifd == 0) {
    return (1);
  } else {

  }
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;
    return (1);
  } else {

  }
  m = tif->tif_dataoff;
  if (! (tif->tif_flags & 524288U)) {
    tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_nsubifd * sizeof(uint32 )));
    o = (uint32 *)tmp;
    if ((unsigned int )o == (unsigned int )((void *)0)) {
      TIFFErrorExt(tif->tif_clientdata, module___13, "Out of memory");
      return (0);
    } else {

    }
    pa = tif->tif_dir.td_subifd;
    pb = o;
    p = (uint16 )0;
    while ((int )p < (int )tif->tif_dir.td_nsubifd) {
      if (*pa <= 4294967295ULL) {

      } else {
        __assert_fail("*pa<=0xFFFFFFFFUL", "tif_dirwrite.c", 1625U,
                      "TIFFWriteDirectoryTagSubifd");
      }
      tmp___0 = pb;
      pb ++;
      tmp___1 = pa;
      pa ++;
      *tmp___0 = (uint32 )*tmp___1;
      p = (uint16 )((int )p + 1);
    }
    n = TIFFWriteDirectoryTagCheckedIfdArray(tif, ndir, dir, (uint16 )330,
                                             (uint32 )tif->tif_dir.td_nsubifd, o);
    _TIFFfree((void *)o);
  } else {
    n = TIFFWriteDirectoryTagCheckedIfd8Array(tif, ndir, dir, (uint16 )330,
                                              (uint32 )tif->tif_dir.td_nsubifd,
                                              tif->tif_dir.td_subifd);
  }
  if (! n) {
    return (0);
  } else {

  }
  tif->tif_flags |= 8192U;
  tif->tif_nsubifd = tif->tif_dir.td_nsubifd;
  if ((int )tif->tif_dir.td_nsubifd == 1) {
    tif->tif_subifdoff = (uint64 )0;
  } else {
    tif->tif_subifdoff = m;
  }
  return (1);
}
}
static int TIFFWriteDirectoryTagCheckedAscii(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint32 count , char *value ) 
{ 
  int tmp ;

  {
  if (sizeof(char ) == 1U) {

  } else {
    __assert_fail("sizeof(char)==1", "tif_dirwrite.c", 1655U,
                  "TIFFWriteDirectoryTagCheckedAscii");
  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )2, count, count,
                                  (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedUndefinedArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      uint8 *value ) 
{ 
  int tmp ;

  {
  if (sizeof(uint8 ) == 1U) {

  } else {
    __assert_fail("sizeof(uint8)==1", "tif_dirwrite.c", 1662U,
                  "TIFFWriteDirectoryTagCheckedUndefinedArray");
  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )7, count, count,
                                  (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedByte(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint8 value ) 
{ 
  int tmp ;

  {
  if (sizeof(uint8 ) == 1U) {

  } else {
    __assert_fail("sizeof(uint8)==1", "tif_dirwrite.c", 1669U,
                  "TIFFWriteDirectoryTagCheckedByte");
  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )1, (uint32 )1,
                                  (uint32 )1, (void *)(& value));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedByteArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint8 *value ) 
{ 
  int tmp ;

  {
  if (sizeof(uint8 ) == 1U) {

  } else {
    __assert_fail("sizeof(uint8)==1", "tif_dirwrite.c", 1676U,
                  "TIFFWriteDirectoryTagCheckedByteArray");
  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )1, count, count,
                                  (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSbyte(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             int8 value ) 
{ 
  int tmp ;

  {
  if (sizeof(int8 ) == 1U) {

  } else {
    __assert_fail("sizeof(int8)==1", "tif_dirwrite.c", 1683U,
                  "TIFFWriteDirectoryTagCheckedSbyte");
  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )6, (uint32 )1,
                                  (uint32 )1, (void *)(& value));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSbyteArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int8 *value ) 
{ 
  int tmp ;

  {
  if (sizeof(int8 ) == 1U) {

  } else {
    __assert_fail("sizeof(int8)==1", "tif_dirwrite.c", 1690U,
                  "TIFFWriteDirectoryTagCheckedSbyteArray");
  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )6, count, count,
                                  (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedShort(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint16 value ) 
{ 
  uint16 m ;
  int tmp ;

  {
  if (sizeof(uint16 ) == 2U) {

  } else {
    __assert_fail("sizeof(uint16)==2", "tif_dirwrite.c", 1698U,
                  "TIFFWriteDirectoryTagCheckedShort");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabShort(& m);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )3, (uint32 )1,
                                  (uint32 )2, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedShortArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint16 *value ) 
{ 
  int tmp ;

  {
  if (count < 2147483648U) {

  } else {
    __assert_fail("count<0x80000000", "tif_dirwrite.c", 1708U,
                  "TIFFWriteDirectoryTagCheckedShortArray");
  }
  if (sizeof(uint16 ) == 2U) {

  } else {
    __assert_fail("sizeof(uint16)==2", "tif_dirwrite.c", 1709U,
                  "TIFFWriteDirectoryTagCheckedShortArray");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfShort(value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )3, count,
                                  count * 2U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSshort(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              int16 value ) 
{ 
  int16 m ;
  int tmp ;

  {
  if (sizeof(int16 ) == 2U) {

  } else {
    __assert_fail("sizeof(int16)==2", "tif_dirwrite.c", 1719U,
                  "TIFFWriteDirectoryTagCheckedSshort");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabShort((uint16 *)(& m));
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )8, (uint32 )1,
                                  (uint32 )2, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSshortArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int16 *value ) 
{ 
  int tmp ;

  {
  if (count < 2147483648U) {

  } else {
    __assert_fail("count<0x80000000", "tif_dirwrite.c", 1729U,
                  "TIFFWriteDirectoryTagCheckedSshortArray");
  }
  if (sizeof(int16 ) == 2U) {

  } else {
    __assert_fail("sizeof(int16)==2", "tif_dirwrite.c", 1730U,
                  "TIFFWriteDirectoryTagCheckedSshortArray");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfShort((uint16 *)value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )8, count,
                                  count * 2U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedLong(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 value ) 
{ 
  uint32 m ;
  int tmp ;

  {
  if (sizeof(uint32 ) == 4U) {

  } else {
    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1740U,
                  "TIFFWriteDirectoryTagCheckedLong");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabLong(& m);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )4, (uint32 )1,
                                  (uint32 )4, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedLongArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint32 *value ) 
{ 
  int tmp ;

  {
  if (count < 1073741824U) {

  } else {
    __assert_fail("count<0x40000000", "tif_dirwrite.c", 1750U,
                  "TIFFWriteDirectoryTagCheckedLongArray");
  }
  if (sizeof(uint32 ) == 4U) {

  } else {
    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1751U,
                  "TIFFWriteDirectoryTagCheckedLongArray");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong(value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )4, count,
                                  count * 4U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSlong(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             int32 value ) 
{ 
  int32 m ;
  int tmp ;

  {
  if (sizeof(int32 ) == 4U) {

  } else {
    __assert_fail("sizeof(int32)==4", "tif_dirwrite.c", 1761U,
                  "TIFFWriteDirectoryTagCheckedSlong");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabLong((uint32 *)(& m));
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )9, (uint32 )1,
                                  (uint32 )4, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSlongArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int32 *value ) 
{ 
  int tmp ;

  {
  if (count < 1073741824U) {

  } else {
    __assert_fail("count<0x40000000", "tif_dirwrite.c", 1771U,
                  "TIFFWriteDirectoryTagCheckedSlongArray");
  }
  if (sizeof(int32 ) == 4U) {

  } else {
    __assert_fail("sizeof(int32)==4", "tif_dirwrite.c", 1772U,
                  "TIFFWriteDirectoryTagCheckedSlongArray");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong((uint32 *)value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )9, count,
                                  count * 4U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedLong8(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint64 value ) 
{ 
  uint64 m ;
  int tmp ;

  {
  if (sizeof(uint64 ) == 8U) {

  } else {
    __assert_fail("sizeof(uint64)==8", "tif_dirwrite.c", 1782U,
                  "TIFFWriteDirectoryTagCheckedLong8");
  }
  if (tif->tif_flags & 524288U) {

  } else {
    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 1783U,
                  "TIFFWriteDirectoryTagCheckedLong8");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabLong8(& m);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )16, (uint32 )1,
                                  (uint32 )8, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedLong8Array(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint64 *value ) 
{ 
  int tmp ;

  {
  if (count < 536870912U) {

  } else {
    __assert_fail("count<0x20000000", "tif_dirwrite.c", 1793U,
                  "TIFFWriteDirectoryTagCheckedLong8Array");
  }
  if (sizeof(uint64 ) == 8U) {

  } else {
    __assert_fail("sizeof(uint64)==8", "tif_dirwrite.c", 1794U,
                  "TIFFWriteDirectoryTagCheckedLong8Array");
  }
  if (tif->tif_flags & 524288U) {

  } else {
    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 1795U,
                  "TIFFWriteDirectoryTagCheckedLong8Array");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong8(value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )16, count,
                                  count * 8U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSlong8(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              int64 value ) 
{ 
  int64 m ;
  int tmp ;

  {
  if (sizeof(int64 ) == 8U) {

  } else {
    __assert_fail("sizeof(int64)==8", "tif_dirwrite.c", 1805U,
                  "TIFFWriteDirectoryTagCheckedSlong8");
  }
  if (tif->tif_flags & 524288U) {

  } else {
    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 1806U,
                  "TIFFWriteDirectoryTagCheckedSlong8");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabLong8((uint64 *)(& m));
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )17, (uint32 )1,
                                  (uint32 )8, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSlong8Array(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int64 *value ) 
{ 
  int tmp ;

  {
  if (count < 536870912U) {

  } else {
    __assert_fail("count<0x20000000", "tif_dirwrite.c", 1816U,
                  "TIFFWriteDirectoryTagCheckedSlong8Array");
  }
  if (sizeof(int64 ) == 8U) {

  } else {
    __assert_fail("sizeof(int64)==8", "tif_dirwrite.c", 1817U,
                  "TIFFWriteDirectoryTagCheckedSlong8Array");
  }
  if (tif->tif_flags & 524288U) {

  } else {
    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 1818U,
                  "TIFFWriteDirectoryTagCheckedSlong8Array");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong8((uint64 *)value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )17, count,
                                  count * 8U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedRational(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) 
{ 
  uint32 m[2] ;
  int tmp ;

  {
  if (value >= 0.0) {

  } else {
    __assert_fail("value>=0.0", "tif_dirwrite.c", 1828U,
                  "TIFFWriteDirectoryTagCheckedRational");
  }
  if (sizeof(uint32 ) == 4U) {

  } else {
    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1829U,
                  "TIFFWriteDirectoryTagCheckedRational");
  }
  if (value <= 0.0) {
    m[0] = (uint32 )0;
    m[1] = (uint32 )1;
  } else
  if (value == (double )((uint32 )value)) {
    m[0] = (uint32 )value;
    m[1] = (uint32 )1;
  } else
  if (value < 1.0) {
    m[0] = (uint32 )(value * (double )4294967295U);
    m[1] = 4294967295U;
  } else {
    m[0] = 4294967295U;
    m[1] = (uint32 )((double )4294967295U / value);
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabLong(& m[0]);
    TIFFSwabLong(& m[1]);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )5, (uint32 )1,
                                  (uint32 )8, (void *)(& m[0]));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedRationalArray(TIFF *tif , uint32 *ndir ,
                                                     TIFFDirEntry *dir ,
                                                     uint16 tag , uint32 count ,
                                                     float *value ) ;
static char const   module___14[42]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'C',      (char const   )'h',      (char const   )'e', 
        (char const   )'c',      (char const   )'k',      (char const   )'e',      (char const   )'d', 
        (char const   )'R',      (char const   )'a',      (char const   )'t',      (char const   )'i', 
        (char const   )'o',      (char const   )'n',      (char const   )'a',      (char const   )'l', 
        (char const   )'A',      (char const   )'r',      (char const   )'r',      (char const   )'a', 
        (char const   )'y',      (char const   )'\000'};
static int TIFFWriteDirectoryTagCheckedRationalArray(TIFF *tif , uint32 *ndir ,
                                                     TIFFDirEntry *dir ,
                                                     uint16 tag , uint32 count ,
                                                     float *value ) 
{ 
  uint32 *m ;
  float *na ;
  uint32 *nb ;
  uint32 nc ;
  int o ;
  void *tmp ;

  {
  if (sizeof(uint32 ) == 4U) {

  } else {
    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1867U,
                  "TIFFWriteDirectoryTagCheckedRationalArray");
  }
  tmp = _TIFFmalloc((tmsize_t )((count * 2U) * sizeof(uint32 )));
  m = (uint32 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___14, "Out of memory");
    return (0);
  } else {

  }
  na = value;
  nb = m;
  nc = (uint32 )0;
  while (nc < count) {
    if ((double )*na <= 0.0) {
      *(nb + 0) = (uint32 )0;
      *(nb + 1) = (uint32 )1;
    } else
    if (*na == (float )((uint32 )*na)) {
      *(nb + 0) = (uint32 )*na;
      *(nb + 1) = (uint32 )1;
    } else
    if ((double )*na < 1.0) {
      *(nb + 0) = (uint32 )(*na * (float )4294967295U);
      *(nb + 1) = 4294967295U;
    } else {
      *(nb + 0) = 4294967295U;
      *(nb + 1) = (uint32 )((float )4294967295U / *na);
    }
    na ++;
    nb += 2;
    nc ++;
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong(m, (tmsize_t )(count * 2U));
  } else {

  }
  o = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )5, count,
                                count * 8U, (void *)(m + 0));
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagCheckedSrationalArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      float *value ) ;
static char const   module___15[43]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'C',      (char const   )'h',      (char const   )'e', 
        (char const   )'c',      (char const   )'k',      (char const   )'e',      (char const   )'d', 
        (char const   )'S',      (char const   )'r',      (char const   )'a',      (char const   )'t', 
        (char const   )'i',      (char const   )'o',      (char const   )'n',      (char const   )'a', 
        (char const   )'l',      (char const   )'A',      (char const   )'r',      (char const   )'r', 
        (char const   )'a',      (char const   )'y',      (char const   )'\000'};
static int TIFFWriteDirectoryTagCheckedSrationalArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      float *value ) 
{ 
  int32 *m ;
  float *na ;
  int32 *nb ;
  uint32 nc ;
  int o ;
  void *tmp ;

  {
  if (sizeof(int32 ) == 4U) {

  } else {
    __assert_fail("sizeof(int32)==4", "tif_dirwrite.c", 1913U,
                  "TIFFWriteDirectoryTagCheckedSrationalArray");
  }
  tmp = _TIFFmalloc((tmsize_t )((count * 2U) * sizeof(int32 )));
  m = (int32 *)tmp;
  if ((unsigned int )m == (unsigned int )((void *)0)) {
    TIFFErrorExt(tif->tif_clientdata, module___15, "Out of memory");
    return (0);
  } else {

  }
  na = value;
  nb = m;
  nc = (uint32 )0;
  while (nc < count) {
    if ((double )*na < 0.0) {
      if (*na == (float )((int32 )*na)) {
        *(nb + 0) = (int32 )*na;
        *(nb + 1) = 1;
      } else
      if ((double )*na > - 1.0) {
        *(nb + 0) = - ((int32 )(- *na * (float )2147483647));
        *(nb + 1) = 2147483647;
      } else {
        *(nb + 0) = -2147483647;
        *(nb + 1) = (int32 )((float )2147483647 / - *na);
      }
    } else
    if (*na == (float )((int32 )*na)) {
      *(nb + 0) = (int32 )*na;
      *(nb + 1) = 1;
    } else
    if ((double )*na < 1.0) {
      *(nb + 0) = (int32 )(*na * (float )2147483647);
      *(nb + 1) = 2147483647;
    } else {
      *(nb + 0) = 2147483647;
      *(nb + 1) = (int32 )((float )2147483647 / *na);
    }
    na ++;
    nb += 2;
    nc ++;
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong((uint32 *)m, (tmsize_t )(count * 2U));
  } else {

  }
  o = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )10, count,
                                count * 8U, (void *)(m + 0));
  _TIFFfree((void *)m);
  return (o);
}
}
static int TIFFWriteDirectoryTagCheckedFloat(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             float value ) 
{ 
  float m ;
  int tmp ;

  {
  if (sizeof(float ) == 4U) {

  } else {
    __assert_fail("sizeof(float)==4", "tif_dirwrite.c", 1970U,
                  "TIFFWriteDirectoryTagCheckedFloat");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabFloat(& m);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )11, (uint32 )1,
                                  (uint32 )4, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedFloatArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  float *value ) 
{ 
  int tmp ;

  {
  if (count < 1073741824U) {

  } else {
    __assert_fail("count<0x40000000", "tif_dirwrite.c", 1981U,
                  "TIFFWriteDirectoryTagCheckedFloatArray");
  }
  if (sizeof(float ) == 4U) {

  } else {
    __assert_fail("sizeof(float)==4", "tif_dirwrite.c", 1982U,
                  "TIFFWriteDirectoryTagCheckedFloatArray");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfFloat(value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )11, count,
                                  count * 4U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedDouble(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              double value ) 
{ 
  double m ;
  int tmp ;

  {
  if (sizeof(double ) == 8U) {

  } else {
    __assert_fail("sizeof(double)==8", "tif_dirwrite.c", 1993U,
                  "TIFFWriteDirectoryTagCheckedDouble");
  }
  m = value;
  if (tif->tif_flags & 128U) {
    TIFFSwabDouble(& m);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )12, (uint32 )1,
                                  (uint32 )8, (void *)(& m));
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedDoubleArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   double *value ) 
{ 
  int tmp ;

  {
  if (count < 536870912U) {

  } else {
    __assert_fail("count<0x20000000", "tif_dirwrite.c", 2004U,
                  "TIFFWriteDirectoryTagCheckedDoubleArray");
  }
  if (sizeof(double ) == 8U) {

  } else {
    __assert_fail("sizeof(double)==8", "tif_dirwrite.c", 2005U,
                  "TIFFWriteDirectoryTagCheckedDoubleArray");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfDouble(value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )12, count,
                                  count * 8U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedIfdArray(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                uint32 count , uint32 *value ) 
{ 
  int tmp ;

  {
  if (count < 1073741824U) {

  } else {
    __assert_fail("count<0x40000000", "tif_dirwrite.c", 2015U,
                  "TIFFWriteDirectoryTagCheckedIfdArray");
  }
  if (sizeof(uint32 ) == 4U) {

  } else {
    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 2016U,
                  "TIFFWriteDirectoryTagCheckedIfdArray");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong(value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )13, count,
                                  count * 4U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedIfd8Array(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint64 *value ) 
{ 
  int tmp ;

  {
  if (count < 536870912U) {

  } else {
    __assert_fail("count<0x20000000", "tif_dirwrite.c", 2025U,
                  "TIFFWriteDirectoryTagCheckedIfd8Array");
  }
  if (sizeof(uint64 ) == 8U) {

  } else {
    __assert_fail("sizeof(uint64)==8", "tif_dirwrite.c", 2026U,
                  "TIFFWriteDirectoryTagCheckedIfd8Array");
  }
  if (tif->tif_flags & 524288U) {

  } else {
    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 2027U,
                  "TIFFWriteDirectoryTagCheckedIfd8Array");
  }
  if (tif->tif_flags & 128U) {
    TIFFSwabArrayOfLong8(value, (tmsize_t )count);
  } else {

  }
  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )18, count,
                                  count * 8U, (void *)value);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagData(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint16 datatype , uint32 count ,
                                     uint32 datalength , void *data ) ;
static char const   module___16[26]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'D',      (char const   )'a',      (char const   )'t', 
        (char const   )'a',      (char const   )'\000'};
static int TIFFWriteDirectoryTagData(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint16 datatype , uint32 count ,
                                     uint32 datalength , void *data ) 
{ 
  uint32 m ;
  uint32 n ;
  uint64 na ;
  uint64 nb ;
  uint64 tmp ;
  tmsize_t tmp___0 ;
  uint32 o ;
  unsigned int tmp___1 ;

  {
  m = (uint32 )0;
  while (m < *ndir) {
    if ((int )(dir + m)->tdir_tag != (int )tag) {

    } else {
      __assert_fail("dir[m].tdir_tag!=tag", "tif_dirwrite.c", 2041U,
                    "TIFFWriteDirectoryTagData");
    }
    if ((int )(dir + m)->tdir_tag > (int )tag) {
      break;
    } else {

    }
    m ++;
  }
  if (m < *ndir) {
    n = *ndir;
    while (n > m) {
      *(dir + n) = *(dir + (n - 1U));
      n --;
    }
  } else {

  }
  (dir + m)->tdir_tag = tag;
  (dir + m)->tdir_type = datatype;
  (dir + m)->tdir_count = (uint64 )count;
  (dir + m)->tdir_offset = (uint64 )0;
  if (tif->tif_flags & 524288U) {
    tmp___1 = 8U;
  } else {
    tmp___1 = 4U;
  }
  if (datalength <= tmp___1) {
    _TIFFmemcpy((void *)(& (dir + m)->tdir_offset), (void const   *)data,
                (tmsize_t )datalength);
  } else {
    na = tif->tif_dataoff;
    nb = na + (uint64 )datalength;
    if (! (tif->tif_flags & 524288U)) {
      nb = (uint64 )((uint32 )nb);
    } else {

    }
    if (nb < na) {
      TIFFErrorExt(tif->tif_clientdata, module___16,
                   "Maximum TIFF file size exceeded");
      return (0);
    } else
    if (nb < (uint64 )datalength) {
      TIFFErrorExt(tif->tif_clientdata, module___16,
                   "Maximum TIFF file size exceeded");
      return (0);
    } else {

    }
    tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, na, 0);
    if (tmp == na) {

    } else {
      TIFFErrorExt(tif->tif_clientdata, module___16, "IO error writing tag data");
      return (0);
    }
    if ((unsigned long )datalength < 2147483648UL) {

    } else {
      __assert_fail("datalength<0x80000000UL", "tif_dirwrite.c", 2075U,
                    "TIFFWriteDirectoryTagData");
    }
    tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata, data,
                                      (tmsize_t )datalength);
    if (tmp___0 == (tmsize_t )datalength) {

    } else {
      TIFFErrorExt(tif->tif_clientdata, module___16, "IO error writing tag data");
      return (0);
    }
    tif->tif_dataoff = nb;
    if (tif->tif_dataoff & 1ULL) {
      (tif->tif_dataoff) ++;
    } else {

    }
    if (! (tif->tif_flags & 524288U)) {
      o = (uint32 )na;
      if (tif->tif_flags & 128U) {
        TIFFSwabLong(& o);
      } else {

      }
      _TIFFmemcpy((void *)(& (dir + m)->tdir_offset), (void const   *)(& o),
                  (tmsize_t )4);
    } else {
      (dir + m)->tdir_offset = na;
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& (dir + m)->tdir_offset);
      } else {

      }
    }
  }
  (*ndir) ++;
  return (1);
}
}
static int TIFFLinkDirectory(TIFF *tif ) ;
static char const   module___17[18]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'L',      (char const   )'i',      (char const   )'n',      (char const   )'k', 
        (char const   )'D',      (char const   )'i',      (char const   )'r',      (char const   )'e', 
        (char const   )'c',      (char const   )'t',      (char const   )'o',      (char const   )'r', 
        (char const   )'y',      (char const   )'\000'};
static int TIFFLinkDirectory(TIFF *tif ) 
{ 
  uint64 tmp ;
  uint32 m ;
  tmsize_t tmp___0 ;
  uint64 m___0 ;
  tmsize_t tmp___1 ;
  uint32 m___1 ;
  uint32 nextdir ;
  tmsize_t tmp___2 ;
  uint16 dircount ;
  uint32 nextnextdir ;
  uint64 tmp___3 ;
  tmsize_t tmp___4 ;
  tmsize_t tmp___5 ;
  tmsize_t tmp___6 ;
  uint64 m___2 ;
  uint64 nextdir___0 ;
  tmsize_t tmp___7 ;
  uint64 dircount64 ;
  uint16 dircount___0 ;
  uint64 nextnextdir___0 ;
  uint64 tmp___8 ;
  tmsize_t tmp___9 ;
  tmsize_t tmp___10 ;
  tmsize_t tmp___11 ;

  {
  tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )0, 2);
  tif->tif_diroff = (tmp + 1ULL) & 0xfffffffffffffffeULL;
  if (tif->tif_flags & 8192U) {
    if (! (tif->tif_flags & 524288U)) {
      m = (uint32 )tif->tif_diroff;
      if (tif->tif_flags & 128U) {
        TIFFSwabLong(& m);
      } else {

      }
      (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_subifdoff, 0);
      tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m),
                                        (tmsize_t )4);
      if (tmp___0 == 4L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error writing SubIFD directory link");
        return (0);
      }
      tif->tif_nsubifd = (uint16 )((int )tif->tif_nsubifd - 1);
      if (tif->tif_nsubifd) {
        tif->tif_subifdoff += 4ULL;
      } else {
        tif->tif_flags &= 4294959103U;
      }
      return (1);
    } else {
      m___0 = tif->tif_diroff;
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& m___0);
      } else {

      }
      (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_subifdoff, 0);
      tmp___1 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m___0),
                                        (tmsize_t )8);
      if (tmp___1 == 8L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error writing SubIFD directory link");
        return (0);
      }
      tif->tif_nsubifd = (uint16 )((int )tif->tif_nsubifd - 1);
      if (tif->tif_nsubifd) {
        tif->tif_subifdoff += 8ULL;
      } else {
        tif->tif_flags &= 4294959103U;
      }
      return (1);
    }
  } else {

  }
  if (! (tif->tif_flags & 524288U)) {
    {
    m___1 = (uint32 )tif->tif_diroff;

    }
    if (tif->tif_flags & 128U) {
      TIFFSwabLong(& m___1);
    } else {

    }
    if (tif->tif_header.classic.tiff_diroff == 0U) {
      tif->tif_header.classic.tiff_diroff = (uint32 )tif->tif_diroff;
      (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )4, 0);
      tmp___2 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m___1),
                                        (tmsize_t )4);
      if (tmp___2 == 4L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "Error writing TIFF header");
        return (0);
      }
      return (1);
    } else {

    }
    nextdir = tif->tif_header.classic.tiff_diroff;
    while (1) {
      tmp___3 = (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )nextdir, 0);
      if (tmp___3 == (uint64 )nextdir) {
        tmp___4 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& dircount), (tmsize_t )2);
        if (tmp___4 == 2L) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error fetching directory count");
          return (0);
        }
      } else {
        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory count");
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabShort(& dircount);
      } else {

      }
      (*(tif->tif_seekproc))(tif->tif_clientdata,
                             (uint64 )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                             0);
      tmp___5 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                       (void *)(& nextnextdir), (tmsize_t )4);
      if (tmp___5 == 4L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory link");
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong(& nextnextdir);
      } else {

      }
      if (nextnextdir == 0U) {
        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (uint64 )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                               0);
        tmp___6 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                          (void *)(& m___1), (tmsize_t )4);
        if (tmp___6 == 4L) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error writing directory link");
          return (0);
        }
        break;
      } else {

      }
      nextdir = nextnextdir;
    }
  } else {
    m___2 = tif->tif_diroff;
    if (tif->tif_flags & 128U) {
      TIFFSwabLong8(& m___2);
    } else {

    }
    if (tif->tif_header.big.tiff_diroff == 0ULL) {
      tif->tif_header.big.tiff_diroff = tif->tif_diroff;
      (*(tif->tif_seekproc))(tif->tif_clientdata, (uint64 )8, 0);
      tmp___7 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m___2),
                                        (tmsize_t )8);
      if (tmp___7 == 8L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "Error writing TIFF header");
        return (0);
      }
      return (1);
    } else {

    }
    nextdir___0 = tif->tif_header.big.tiff_diroff;
    while (1) {
      tmp___8 = (*(tif->tif_seekproc))(tif->tif_clientdata, nextdir___0, 0);
      if (tmp___8 == nextdir___0) {
        tmp___9 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& dircount64), (tmsize_t )8);
        if (tmp___9 == 8L) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error fetching directory count");
          return (0);
        }
      } else {
        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory count");
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& dircount64);
      } else {

      }
      if (dircount64 > 65535ULL) {
        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Sanity check on tag count failed, likely corrupt TIFF");
        return (0);
      } else {

      }
      dircount___0 = (uint16 )dircount64;
      (*(tif->tif_seekproc))(tif->tif_clientdata,
                             (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                             0);
      tmp___10 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                        (void *)(& nextnextdir___0),
                                        (tmsize_t )8);
      if (tmp___10 == 8L) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory link");
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& nextnextdir___0);
      } else {

      }
      if (nextnextdir___0 == 0ULL) {
        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                               0);
        tmp___11 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                           (void *)(& m___2), (tmsize_t )8);
        if (tmp___11 == 8L) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error writing directory link");
          return (0);
        }
        break;
      } else {

      }
      nextdir___0 = nextnextdir___0;
    }
  }
  return (1);
}
}
