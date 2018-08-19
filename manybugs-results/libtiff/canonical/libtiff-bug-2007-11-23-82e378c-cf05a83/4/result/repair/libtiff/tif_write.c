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
int TIFFWriteBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
int TIFFSetupStrips(TIFF *tif ) ;
int TIFFWriteCheck(TIFF *tif , int tiles , char const   *module___4 ) ;
extern void TIFFFreeDirectory(TIFF * ) ;
extern int TIFFCreateDirectory(TIFF * ) ;
extern int TIFFLastDirectory(TIFF * ) ;
extern int TIFFSetDirectory(TIFF * , uint16  ) ;
extern int TIFFSetSubDirectory(TIFF * , uint64  ) ;
extern int TIFFUnlinkDirectory(TIFF * , uint16  ) ;
extern int TIFFSetField(TIFF * , uint32   , ...) ;
extern int TIFFVSetField(TIFF * , uint32  , va_list  ) ;
extern int TIFFWriteDirectory(TIFF * ) ;
extern int TIFFCheckpointDirectory(TIFF * ) ;
extern int TIFFRewriteDirectory(TIFF * ) ;
extern void TIFFPrintDirectory(TIFF * , FILE * , long  ) ;
extern int TIFFReadScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) ;
int TIFFWriteScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) ;
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
tmsize_t TIFFWriteTile(TIFF *tif , void *buf , uint32 x , uint32 y , uint32 z ,
                       uint16 s ) ;
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
tmsize_t TIFFWriteEncodedStrip(TIFF *tif , uint32 strip , void *data ,
                               tmsize_t cc ) ;
tmsize_t TIFFWriteRawStrip(TIFF *tif , uint32 strip , void *data , tmsize_t cc ) ;
tmsize_t TIFFWriteEncodedTile(TIFF *tif , uint32 tile , void *data ,
                              tmsize_t cc ) ;
tmsize_t TIFFWriteRawTile(TIFF *tif , uint32 tile , void *data , tmsize_t cc ) ;
extern int TIFFDataWidth(TIFFDataType  ) ;
void TIFFSetWriteOffset(TIFF *tif , uint64 off ) ;
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
int TIFFFlushData1(TIFF *tif ) ;
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
static int TIFFGrowStrips(TIFF *tif , uint32 delta , char const   *module___5 ) ;
static int TIFFAppendToStrip(TIFF *tif , uint32 strip , uint8 *data ,
                             tmsize_t cc ) ;
int TIFFWriteScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) ;
static char const   module[18]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'S',      (char const   )'c',      (char const   )'a', 
        (char const   )'n',      (char const   )'l',      (char const   )'i',      (char const   )'n', 
        (char const   )'e',      (char const   )'\000'};
int TIFFWriteScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) 
{ 
  register TIFFDirectory *td ;
  int status ;
  int imagegrew ;
  uint32 strip ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;

  {
  imagegrew = 0;
  if (tif->tif_flags & 64U) {

  } else {
    tmp = TIFFWriteCheck(tif, 0, module);
    if (tmp) {

    } else {
      return (-1);
    }
  }
  if (tif->tif_flags & 16U) {
    if (tif->tif_rawdata) {

    } else {
      goto _L;
    }
  } else {
    _L: /* CIL Label */ 
    tmp___0 = TIFFWriteBufferSetup(tif, (void *)0, (tmsize_t )-1);
    if (tmp___0) {

    } else {
      return (-1);
    }
  }
  td = & tif->tif_dir;
  if (row >= td->td_imagelength) {
    if ((int )td->td_planarconfig == 2) {
      TIFFErrorExt(tif->tif_clientdata, module,
                   "Can not change \"ImageLength\" when using separate planes");
      return (-1);
    } else {

    }
    td->td_imagelength = row + 1U;
    imagegrew = 1;
  } else {

  }
  if ((int )td->td_planarconfig == 2) {
    if ((int )sample >= (int )td->td_samplesperpixel) {
      TIFFErrorExt(tif->tif_clientdata, module,
                   "%lu: Sample out of range, max %lu", (unsigned long )sample,
                   (unsigned long )td->td_samplesperpixel);
      return (-1);
    } else {

    }
    strip = (uint32 )sample * td->td_stripsperimage + row / td->td_rowsperstrip;
  } else {
    strip = row / td->td_rowsperstrip;
  }
  if (strip >= td->td_nstrips) {
    tmp___1 = TIFFGrowStrips(tif, (uint32 )1, module);
    if (tmp___1) {

    } else {
      return (-1);
    }
  } else {

  }
  if (strip != tif->tif_curstrip) {
    tmp___2 = TIFFFlushData(tif);
    if (tmp___2) {

    } else {
      return (-1);
    }
    tif->tif_curstrip = strip;
    if (strip >= td->td_stripsperimage) {
      if (imagegrew) {
        td->td_stripsperimage = (td->td_imagelength + (td->td_rowsperstrip - 1U)) / td->td_rowsperstrip;
      } else {

      }
    } else {

    }
    tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;
    if ((tif->tif_flags & 32U) == 0U) {
      tmp___3 = (*(tif->tif_setupencode))(tif);
      if (tmp___3) {

      } else {
        return (-1);
      }
      tif->tif_flags |= 32U;
    } else {

    }
    tif->tif_rawcc = (tmsize_t )0;
    tif->tif_rawcp = tif->tif_rawdata;
    if (*(td->td_stripbytecount + strip) > 0ULL) {
      *(td->td_stripbytecount + strip) = (uint64 )0;
      tif->tif_curoff = (uint64 )0;
    } else {

    }
    tmp___4 = (*(tif->tif_preencode))(tif, sample);
    if (tmp___4) {

    } else {
      return (-1);
    }
    tif->tif_flags |= 4096U;
  } else {

  }
  if (row != tif->tif_row) {
    if (row < tif->tif_row) {
      tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;
      tif->tif_rawcp = tif->tif_rawdata;
    } else {

    }
    tmp___5 = (*(tif->tif_seek))(tif, row - tif->tif_row);
    if (tmp___5) {

    } else {
      return (-1);
    }
    tif->tif_row = row;
  } else {

  }
  (*(tif->tif_postdecode))(tif, (uint8 *)buf, tif->tif_scanlinesize);
  status = (*(tif->tif_encoderow))(tif, (uint8 *)buf, tif->tif_scanlinesize,
                                   sample);
  tif->tif_row = row + 1U;
  return (status);
}
}
tmsize_t TIFFWriteEncodedStrip(TIFF *tif , uint32 strip , void *data ,
                               tmsize_t cc ) ;
static char const   module___0[22]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'E',      (char const   )'n',      (char const   )'c', 
        (char const   )'o',      (char const   )'d',      (char const   )'e',      (char const   )'d', 
        (char const   )'S',      (char const   )'t',      (char const   )'r',      (char const   )'i', 
        (char const   )'p',      (char const   )'\000'};
tmsize_t TIFFWriteEncodedStrip(TIFF *tif , uint32 strip , void *data ,
                               tmsize_t cc ) 
{ 
  TIFFDirectory *td ;
  uint16 sample ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;

  {
  td = & tif->tif_dir;
  if (tif->tif_flags & 64U) {

  } else {
    tmp = TIFFWriteCheck(tif, 0, module___0);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
  }
  if (strip >= td->td_nstrips) {
    if ((int )td->td_planarconfig == 2) {
      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Can not grow image by strips when using separate planes");
      return ((tmsize_t )-1);
    } else {

    }
    tmp___0 = TIFFGrowStrips(tif, (uint32 )1, module___0);
    if (tmp___0) {

    } else {
      return ((tmsize_t )-1);
    }
    td->td_stripsperimage = (td->td_imagelength + (td->td_rowsperstrip - 1U)) / td->td_rowsperstrip;
  } else {

  }
  if (tif->tif_flags & 16U) {
    if (tif->tif_rawdata) {

    } else {
      goto _L;
    }
  } else {
    _L: /* CIL Label */ 
    tmp___1 = TIFFWriteBufferSetup(tif, (void *)0, (tmsize_t )-1);
    if (tmp___1) {

    } else {
      return ((tmsize_t )-1);
    }
  }
  tif->tif_curstrip = strip;
  tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;
  if ((tif->tif_flags & 32U) == 0U) {
    tmp___2 = (*(tif->tif_setupencode))(tif);
    if (tmp___2) {

    } else {
      return ((tmsize_t )-1);
    }
    tif->tif_flags |= 32U;
  } else {

  }
  tif->tif_rawcc = (tmsize_t )0;
  tif->tif_rawcp = tif->tif_rawdata;
  if (*(td->td_stripbytecount + strip) > 0ULL) {
    tif->tif_curoff = (uint64 )0;
  } else {

  }
  tif->tif_flags &= 4294963199U;
  sample = (uint16 )(strip / td->td_stripsperimage);
  tmp___3 = (*(tif->tif_preencode))(tif, sample);
  if (tmp___3) {

  } else {
    return ((tmsize_t )-1);
  }
  (*(tif->tif_postdecode))(tif, (uint8 *)data, cc);
  tmp___4 = (*(tif->tif_encodestrip))(tif, (uint8 *)data, cc, sample);
  if (tmp___4) {

  } else {
    return ((tmsize_t )0);
  }
  tmp___5 = (*(tif->tif_postencode))(tif);
  if (tmp___5) {

  } else {
    return ((tmsize_t )-1);
  }
  if (! ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U)) {
    if ((tif->tif_flags & 256U) == 0U) {
      TIFFReverseBits(tif->tif_rawdata, tif->tif_rawcc);
    } else {

    }
  } else {

  }
  if (tif->tif_rawcc > 0L) {
    tmp___6 = TIFFAppendToStrip(tif, strip, tif->tif_rawdata, tif->tif_rawcc);
    if (tmp___6) {

    } else {
      return ((tmsize_t )-1);
    }
  } else {

  }
  tif->tif_rawcc = (tmsize_t )0;
  tif->tif_rawcp = tif->tif_rawdata;
  return (cc);
}
}
tmsize_t TIFFWriteRawStrip(TIFF *tif , uint32 strip , void *data , tmsize_t cc ) ;
static char const   module___1[18]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'R',      (char const   )'a',      (char const   )'w', 
        (char const   )'S',      (char const   )'t',      (char const   )'r',      (char const   )'i', 
        (char const   )'p',      (char const   )'\000'};
tmsize_t TIFFWriteRawStrip(TIFF *tif , uint32 strip , void *data , tmsize_t cc ) 
{ 
  TIFFDirectory *td ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  tmsize_t tmp___2 ;
  int tmp___3 ;

  {
  td = & tif->tif_dir;
  if (tif->tif_flags & 64U) {

  } else {
    tmp = TIFFWriteCheck(tif, 0, module___1);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
  }
  if (strip >= td->td_nstrips) {
    if ((int )td->td_planarconfig == 2) {
      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Can not grow image by strips when using separate planes");
      return ((tmsize_t )-1);
    } else {

    }
    if (strip >= td->td_stripsperimage) {
      td->td_stripsperimage = (td->td_imagelength + (td->td_rowsperstrip - 1U)) / td->td_rowsperstrip;
    } else {

    }
    tmp___0 = TIFFGrowStrips(tif, (uint32 )1, module___1);
    if (tmp___0) {

    } else {
      return ((tmsize_t )-1);
    }
  } else {

  }
  tif->tif_curstrip = strip;
  tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;
  tmp___3 = TIFFAppendToStrip(tif, strip, (uint8 *)data, cc);
  if (tmp___3) {
    tmp___2 = cc;
  } else {
    tmp___2 = (tmsize_t )-1;
  }
  return (tmp___2);
}
}
tmsize_t TIFFWriteTile(TIFF *tif , void *buf , uint32 x , uint32 y , uint32 z ,
                       uint16 s ) 
{ 
  int tmp ;
  uint32 tmp___0 ;
  tmsize_t tmp___1 ;

  {
  tmp = TIFFCheckTile(tif, x, y, z, s);
  if (tmp) {

  } else {
    return ((tmsize_t )-1);
  }
  tmp___0 = TIFFComputeTile(tif, x, y, z, s);
  tmp___1 = TIFFWriteEncodedTile(tif, tmp___0, buf, (tmsize_t )-1);
  return (tmp___1);
}
}
tmsize_t TIFFWriteEncodedTile(TIFF *tif , uint32 tile , void *data ,
                              tmsize_t cc ) ;
static char const   module___2[21]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'E',      (char const   )'n',      (char const   )'c', 
        (char const   )'o',      (char const   )'d',      (char const   )'e',      (char const   )'d', 
        (char const   )'T',      (char const   )'i',      (char const   )'l',      (char const   )'e', 
        (char const   )'\000'};
tmsize_t TIFFWriteEncodedTile(TIFF *tif , uint32 tile , void *data ,
                              tmsize_t cc ) 
{ 
  TIFFDirectory *td ;
  uint16 sample ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;

  {
  if (tif->tif_flags & 64U) {

  } else {
    tmp = TIFFWriteCheck(tif, 1, module___2);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
  }
  td = & tif->tif_dir;
  if (tile >= td->td_nstrips) {
    TIFFErrorExt(tif->tif_clientdata, module___2,
                 "Tile %lu out of range, max %lu", (unsigned long )tile,
                 (unsigned long )td->td_nstrips);
    return ((tmsize_t )-1);
  } else {

  }
  if (tif->tif_flags & 16U) {
    if (tif->tif_rawdata) {

    } else {
      goto _L;
    }
  } else {
    _L: /* CIL Label */ 
    tmp___0 = TIFFWriteBufferSetup(tif, (void *)0, (tmsize_t )-1);
    if (tmp___0) {

    } else {
      return ((tmsize_t )-1);
    }
  }
  tif->tif_curtile = tile;
  tif->tif_rawcc = (tmsize_t )0;
  tif->tif_rawcp = tif->tif_rawdata;
  if (*(td->td_stripbytecount + tile) > 0ULL) {
    tif->tif_curoff = (uint64 )0;
  } else {

  }
  tif->tif_row = (tile % ((td->td_imagelength + (td->td_tilelength - 1U)) / td->td_tilelength)) * td->td_tilelength;
  tif->tif_col = (tile % ((td->td_imagewidth + (td->td_tilewidth - 1U)) / td->td_tilewidth)) * td->td_tilewidth;
  if ((tif->tif_flags & 32U) == 0U) {
    tmp___1 = (*(tif->tif_setupencode))(tif);
    if (tmp___1) {

    } else {
      return ((tmsize_t )-1);
    }
    tif->tif_flags |= 32U;
  } else {

  }
  tif->tif_flags &= 4294963199U;
  sample = (uint16 )(tile / td->td_stripsperimage);
  tmp___2 = (*(tif->tif_preencode))(tif, sample);
  if (tmp___2) {

  } else {
    return ((tmsize_t )-1);
  }
  if (cc < 1L) {
    cc = tif->tif_tilesize;
  } else
  if (cc > tif->tif_tilesize) {
    cc = tif->tif_tilesize;
  } else {

  }
  (*(tif->tif_postdecode))(tif, (uint8 *)data, cc);
  tmp___3 = (*(tif->tif_encodetile))(tif, (uint8 *)data, cc, sample);
  if (tmp___3) {

  } else {
    return ((tmsize_t )0);
  }
  tmp___4 = (*(tif->tif_postencode))(tif);
  if (tmp___4) {

  } else {
    return ((tmsize_t )-1);
  }
  if (! ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U)) {
    if ((tif->tif_flags & 256U) == 0U) {
      TIFFReverseBits(tif->tif_rawdata, tif->tif_rawcc);
    } else {

    }
  } else {

  }
  if (tif->tif_rawcc > 0L) {
    tmp___5 = TIFFAppendToStrip(tif, tile, tif->tif_rawdata, tif->tif_rawcc);
    if (tmp___5) {

    } else {
      return ((tmsize_t )-1);
    }
  } else {

  }
  tif->tif_rawcc = (tmsize_t )0;
  tif->tif_rawcp = tif->tif_rawdata;
  return (cc);
}
}
tmsize_t TIFFWriteRawTile(TIFF *tif , uint32 tile , void *data , tmsize_t cc ) ;
static char const   module___3[17]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'R',      (char const   )'a',      (char const   )'w', 
        (char const   )'T',      (char const   )'i',      (char const   )'l',      (char const   )'e', 
        (char const   )'\000'};
tmsize_t TIFFWriteRawTile(TIFF *tif , uint32 tile , void *data , tmsize_t cc ) 
{ 
  int tmp ;
  int tmp___0 ;
  tmsize_t tmp___1 ;
  int tmp___2 ;

  {
  if (tif->tif_flags & 64U) {

  } else {
    tmp = TIFFWriteCheck(tif, 1, module___3);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
  }
  if (tile >= tif->tif_dir.td_nstrips) {
    TIFFErrorExt(tif->tif_clientdata, module___3,
                 "Tile %lu out of range, max %lu", (unsigned long )tile,
                 (unsigned long )tif->tif_dir.td_nstrips);
    return ((tmsize_t )-1);
  } else {

  }
  tmp___2 = TIFFAppendToStrip(tif, tile, (uint8 *)data, cc);
  if (tmp___2) {
    tmp___1 = cc;
  } else {
    tmp___1 = (tmsize_t )-1;
  }
  return (tmp___1);
}
}
int TIFFSetupStrips(TIFF *tif ) 
{ 
  TIFFDirectory *td ;
  uint32 tmp ;
  uint32 tmp___0 ;
  void *tmp___1 ;
  void *tmp___2 ;

  {
  td = & tif->tif_dir;
  if ((tif->tif_flags & 1024U) != 0U) {
    if (tif->tif_dir.td_fieldsset[0] & (1UL << 2)) {
      if (tif->tif_dir.td_imagelength == 0U) {
        td->td_stripsperimage = (uint32 )td->td_samplesperpixel;
      } else {
        tmp = TIFFNumberOfTiles(tif);
        td->td_stripsperimage = tmp;
      }
    } else {
      tmp = TIFFNumberOfTiles(tif);
      td->td_stripsperimage = tmp;
    }
  } else
  if (tif->tif_dir.td_fieldsset[0] & (1UL << 17)) {
    if (tif->tif_dir.td_imagelength == 0U) {
      td->td_stripsperimage = (uint32 )td->td_samplesperpixel;
    } else {
      tmp___0 = TIFFNumberOfStrips(tif);
      td->td_stripsperimage = tmp___0;
    }
  } else {
    tmp___0 = TIFFNumberOfStrips(tif);
    td->td_stripsperimage = tmp___0;
  }
  td->td_nstrips = td->td_stripsperimage;
  if ((int )td->td_planarconfig == 2) {
    td->td_stripsperimage /= (uint32 )td->td_samplesperpixel;
  } else {

  }
  tmp___1 = _TIFFmalloc((tmsize_t )(td->td_nstrips * sizeof(uint64 )));
  td->td_stripoffset = (uint64 *)tmp___1;
  tmp___2 = _TIFFmalloc((tmsize_t )(td->td_nstrips * sizeof(uint64 )));
  td->td_stripbytecount = (uint64 *)tmp___2;
  if ((unsigned int )td->td_stripoffset == (unsigned int )((void *)0)) {
    return (0);
  } else
  if ((unsigned int )td->td_stripbytecount == (unsigned int )((void *)0)) {
    return (0);
  } else {

  }
  _TIFFmemset((void *)td->td_stripoffset, 0,
              (tmsize_t )(td->td_nstrips * sizeof(uint64 )));
  _TIFFmemset((void *)td->td_stripbytecount, 0,
              (tmsize_t )(td->td_nstrips * sizeof(uint64 )));
  tif->tif_dir.td_fieldsset[0] |= 1UL << 25;
  tif->tif_dir.td_fieldsset[0] |= 1UL << 24;
  return (1);
}
}
int TIFFWriteCheck(TIFF *tif , int tiles , char const   *module___4 ) 
{ 
  char const   *tmp ;
  char const   *tmp___0 ;
  int tmp___1 ;

  {
  if (tif->tif_mode == 0) {
    TIFFErrorExt(tif->tif_clientdata, module___4, "File not open for writing");
    return (0);
  } else {

  }
  if (tiles ^ ((tif->tif_flags & 1024U) != 0U)) {
    if (tiles) {
      tmp = "Can not write tiles to a stripped image";
    } else {
      tmp = "Can not write scanlines to a tiled image";
    }
    TIFFErrorExt(tif->tif_clientdata, module___4, tmp);
    return (0);
  } else {

  }
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 1))) {
    TIFFErrorExt(tif->tif_clientdata, module___4,
                 "Must set \"ImageWidth\" before writing data");
    return (0);
  } else {

  }
  if ((int )tif->tif_dir.td_samplesperpixel == 1) {
    tif->tif_dir.td_planarconfig = (uint16 )1;
  } else
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 20))) {
    TIFFErrorExt(tif->tif_clientdata, module___4,
                 "Must set \"PlanarConfiguration\" before writing data");
    return (0);
  } else {

  }
  if ((unsigned int )tif->tif_dir.td_stripoffset == (unsigned int )((void *)0)) {
    tmp___1 = TIFFSetupStrips(tif);
    if (tmp___1) {

    } else {
      tif->tif_dir.td_nstrips = (uint32 )0;
      if ((tif->tif_flags & 1024U) != 0U) {
        tmp___0 = "tile";
      } else {
        tmp___0 = "strip";
      }
      TIFFErrorExt(tif->tif_clientdata, module___4, "No space for %s arrays",
                   tmp___0);
      return (0);
    }
  } else {

  }
  if ((tif->tif_flags & 1024U) != 0U) {
    tif->tif_tilesize = TIFFTileSize(tif);
    if (tif->tif_tilesize == 0L) {
      return (0);
    } else {

    }
  } else {
    tif->tif_tilesize = (tmsize_t )-1;
  }
  tif->tif_scanlinesize = TIFFScanlineSize(tif);
  if (tif->tif_scanlinesize == 0L) {
    return (0);
  } else {

  }
  tif->tif_flags |= 64U;
  return (1);
}
}
int TIFFWriteBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
static char const   module___4[21]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'B',      (char const   )'u',      (char const   )'f', 
        (char const   )'f',      (char const   )'e',      (char const   )'r',      (char const   )'S', 
        (char const   )'e',      (char const   )'t',      (char const   )'u',      (char const   )'p', 
        (char const   )'\000'};
int TIFFWriteBufferSetup(TIFF *tif , void *bp , tmsize_t size ) 
{ 
  tmsize_t tmp ;

  {
  if (tif->tif_rawdata) {
    if (tif->tif_flags & 512U) {
      _TIFFfree((void *)tif->tif_rawdata);
      tif->tif_flags &= 4294966783U;
    } else {

    }
    tif->tif_rawdata = (uint8 *)((void *)0);
  } else {

  }
  if (size == -1L) {
    if ((tif->tif_flags & 1024U) != 0U) {
      size = tif->tif_tilesize;
    } else {
      tmp = TIFFStripSize(tif);
      size = tmp;
    }
    if (size < 8192L) {
      size = (tmsize_t )8192;
    } else {

    }
    bp = (void *)0;
  } else {

  }
  if ((unsigned int )bp == (unsigned int )((void *)0)) {
    bp = _TIFFmalloc(size);
    if ((unsigned int )bp == (unsigned int )((void *)0)) {
      TIFFErrorExt(tif->tif_clientdata, module___4, "No space for output buffer");
      return (0);
    } else {

    }
    tif->tif_flags |= 512U;
  } else {
    tif->tif_flags &= 4294966783U;
  }
  tif->tif_rawdata = (uint8 *)bp;
  tif->tif_rawdatasize = size;
  tif->tif_rawcc = (tmsize_t )0;
  tif->tif_rawcp = tif->tif_rawdata;
  tif->tif_flags |= 16U;
  return (1);
}
}
static int TIFFGrowStrips(TIFF *tif , uint32 delta , char const   *module___5 ) 
{ 
  TIFFDirectory *td ;
  uint64 *new_stripoffset ;
  uint64 *new_stripbytecount ;
  void *tmp ;
  void *tmp___0 ;

  {
  td = & tif->tif_dir;
  if ((int )td->td_planarconfig == 1) {

  } else {
    __assert_fail("td->td_planarconfig == 1", "tif_write.c", 598U,
                  "TIFFGrowStrips");
  }
  tmp = _TIFFrealloc((void *)td->td_stripoffset,
                     (tmsize_t )((td->td_nstrips + delta) * sizeof(uint64 )));
  new_stripoffset = (uint64 *)tmp;
  tmp___0 = _TIFFrealloc((void *)td->td_stripbytecount,
                         (tmsize_t )((td->td_nstrips + delta) * sizeof(uint64 )));
  new_stripbytecount = (uint64 *)tmp___0;
  if ((unsigned int )new_stripoffset == (unsigned int )((void *)0)) {
    goto _L;
  } else
  if ((unsigned int )new_stripbytecount == (unsigned int )((void *)0)) {
    _L: /* CIL Label */ 
    if (new_stripoffset) {
      _TIFFfree((void *)new_stripoffset);
    } else {

    }
    if (new_stripbytecount) {
      _TIFFfree((void *)new_stripbytecount);
    } else {

    }
    td->td_nstrips = (uint32 )0;
    TIFFErrorExt(tif->tif_clientdata, module___5,
                 "No space to expand strip arrays");
    return (0);
  } else {

  }
  td->td_stripoffset = new_stripoffset;
  td->td_stripbytecount = new_stripbytecount;
  _TIFFmemset((void *)(td->td_stripoffset + td->td_nstrips), 0,
              (tmsize_t )(delta * sizeof(uint64 )));
  _TIFFmemset((void *)(td->td_stripbytecount + td->td_nstrips), 0,
              (tmsize_t )(delta * sizeof(uint64 )));
  td->td_nstrips += delta;
  return (1);
}
}
static int TIFFAppendToStrip(TIFF *tif , uint32 strip , uint8 *data ,
                             tmsize_t cc ) ;
static char const   module___5[18]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'A',      (char const   )'p',      (char const   )'p',      (char const   )'e', 
        (char const   )'n',      (char const   )'d',      (char const   )'T',      (char const   )'o', 
        (char const   )'S',      (char const   )'t',      (char const   )'r',      (char const   )'i', 
        (char const   )'p',      (char const   )'\000'};
static int TIFFAppendToStrip(TIFF *tif , uint32 strip , uint8 *data ,
                             tmsize_t cc ) 
{ 
  TIFFDirectory *td ;
  uint64 m ;
  uint64 tmp ;
  tmsize_t tmp___0 ;

  {
  td = & tif->tif_dir;
  if (*(td->td_stripoffset + strip) == 0ULL) {
    goto _L;
  } else
  if (tif->tif_curoff == 0ULL) {
    _L: /* CIL Label */ 
    if (td->td_nstrips > 0U) {

    } else {
      __assert_fail("td->td_nstrips > 0", "tif_write.c", 633U,
                    "TIFFAppendToStrip");
    }
    if (*(td->td_stripbytecount + strip) != 0ULL) {
      if (*(td->td_stripoffset + strip) != 0ULL) {
        if (*(td->td_stripbytecount + strip) >= (uint64 )cc) {
          tmp = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                       *(td->td_stripoffset + strip), 0);
          if (tmp == *(td->td_stripoffset + strip)) {

          } else {
            TIFFErrorExt(tif->tif_clientdata, module___5,
                         "Seek error at scanline %lu",
                         (unsigned long )tif->tif_row);
            return (0);
          }
        } else {
          *(td->td_stripoffset + strip) = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                                                 (uint64 )0, 2);
        }
      } else {
        *(td->td_stripoffset + strip) = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                                               (uint64 )0, 2);
      }
    } else {
      *(td->td_stripoffset + strip) = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                                             (uint64 )0, 2);
    }
    tif->tif_curoff = *(td->td_stripoffset + strip);
    *(td->td_stripbytecount + strip) = (uint64 )0;
  } else {

  }
  m = tif->tif_curoff + (uint64 )cc;
  if (! (tif->tif_flags & 524288U)) {
    m = (uint64 )((uint32 )m);
  } else {

  }
  if (m < tif->tif_curoff) {
    TIFFErrorExt(tif->tif_clientdata, module___5,
                 "Maximum TIFF file size exceeded");
    return (0);
  } else
  if (m < (uint64 )cc) {
    TIFFErrorExt(tif->tif_clientdata, module___5,
                 "Maximum TIFF file size exceeded");
    return (0);
  } else {

  }
  tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)data, cc);
  if (tmp___0 == cc) {

  } else {
    TIFFErrorExt(tif->tif_clientdata, module___5, "Write error at scanline %lu",
                 (unsigned long )tif->tif_row);
    return (0);
  }
  tif->tif_curoff = m;
  *(td->td_stripbytecount + strip) += (uint64 )cc;
  return (1);
}
}
int TIFFFlushData1(TIFF *tif ) 
{ 
  uint32 tmp ;
  int tmp___0 ;

  {
  if (tif->tif_rawcc > 0L) {
    if (! ((tif->tif_flags & (unsigned int )tif->tif_dir.td_fillorder) != 0U)) {
      if ((tif->tif_flags & 256U) == 0U) {
        TIFFReverseBits(tif->tif_rawdata, tif->tif_rawcc);
      } else {

      }
    } else {

    }
    if ((tif->tif_flags & 1024U) != 0U) {
      tmp = tif->tif_curtile;
    } else {
      tmp = tif->tif_curstrip;
    }
    tmp___0 = TIFFAppendToStrip(tif, tmp, tif->tif_rawdata, tif->tif_rawcc);
    if (tmp___0) {

    } else {
      return (0);
    }
    tif->tif_rawcc = (tmsize_t )0;
    tif->tif_rawcp = tif->tif_rawdata;
  } else {

  }
  return (1);
}
}
void TIFFSetWriteOffset(TIFF *tif , uint64 off ) 
{ 


  {
  tif->tif_curoff = off;
  return;
}
}
