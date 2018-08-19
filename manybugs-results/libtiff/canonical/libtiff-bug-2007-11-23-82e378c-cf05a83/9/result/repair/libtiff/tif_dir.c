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
int TIFFGetField(TIFF *tif , uint32 tag  , ...) ;
int TIFFVGetField(TIFF *tif , uint32 tag , va_list ap ) ;
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
uint16 TIFFNumberOfDirectories(TIFF *tif ) ;
uint64 TIFFCurrentDirOffset(TIFF *tif ) ;
extern uint32 TIFFCurrentStrip(TIFF * ) ;
extern uint32 TIFFCurrentTile(TIFF *tif ) ;
extern int TIFFReadBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
extern int TIFFWriteBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
extern int TIFFSetupStrips(TIFF * ) ;
extern int TIFFWriteCheck(TIFF * , int  , char const   * ) ;
void TIFFFreeDirectory(TIFF *tif ) ;
int TIFFCreateDirectory(TIFF *tif ) ;
int TIFFLastDirectory(TIFF *tif ) ;
int TIFFSetDirectory(TIFF *tif , uint16 dirn ) ;
int TIFFSetSubDirectory(TIFF *tif , uint64 diroff ) ;
int TIFFUnlinkDirectory(TIFF *tif , uint16 dirn ) ;
int TIFFSetField(TIFF *tif , uint32 tag  , ...) ;
int TIFFVSetField(TIFF *tif , uint32 tag , va_list ap ) ;
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
TIFFExtendProc TIFFSetTagExtender(void (*extender)(TIFF * ) ) ;
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
int TIFFDefaultDirectory(TIFF *tif ) ;
extern void _TIFFSetDefaultCompressionState(TIFF *tif ) ;
extern int TIFFSetCompressionScheme(TIFF *tif , int scheme ) ;
extern int TIFFSetDefaultCompressionState(TIFF *tif ) ;
extern uint32 _TIFFDefaultStripSize(TIFF *tif , uint32 s ) ;
extern void _TIFFDefaultTileSize(TIFF *tif , uint32 *tw , uint32 *th ) ;
extern int _TIFFDataSize(TIFFDataType type ) ;
void _TIFFsetByteArray(void **vpp , void *vp , uint32 n ) ;
void _TIFFsetString(char **cpp , char *cp ) ;
void _TIFFsetShortArray(uint16 **wpp , uint16 *wp , uint32 n ) ;
void _TIFFsetLongArray(uint32 **lpp , uint32 *lp , uint32 n ) ;
void _TIFFsetFloatArray(float **fpp , float *fp , uint32 n ) ;
void _TIFFsetDoubleArray(double **dpp , double *dp , uint32 n ) ;
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
static void setByteArray(void **vpp , void *vp , size_t nmemb ,
                         size_t elem_size ) 
{ 
  tmsize_t bytes ;
  void *tmp ;

  {
  if (*vpp) {
    _TIFFfree(*vpp);
    *vpp = (void *)0;
  } else {

  }
  if (vp) {
    bytes = (tmsize_t )(nmemb * elem_size);
    if (elem_size) {
      if ((unsigned long )bytes / (unsigned long )elem_size == (unsigned long )nmemb) {
        tmp = _TIFFmalloc(bytes);
        *vpp = tmp;
      } else {

      }
    } else {

    }
    if (*vpp) {
      _TIFFmemcpy(*vpp, (void const   *)vp, bytes);
    } else {

    }
  } else {

  }
  return;
}
}
void _TIFFsetByteArray(void **vpp , void *vp , uint32 n ) 
{ 


  {
  setByteArray(vpp, vp, n, (size_t )1);
  return;
}
}
void _TIFFsetString(char **cpp , char *cp ) 
{ 
  size_t tmp ;

  {
  tmp = strlen((char const   *)cp);
  setByteArray((void **)cpp, (void *)cp, tmp + 1U, (size_t )1);
  return;
}
}
void _TIFFsetNString(char **cpp , char *cp , uint32 n ) 
{ 


  {
  setByteArray((void **)cpp, (void *)cp, n, (size_t )1);
  return;
}
}
void _TIFFsetShortArray(uint16 **wpp , uint16 *wp , uint32 n ) 
{ 


  {
  setByteArray((void **)wpp, (void *)wp, n, sizeof(uint16 ));
  return;
}
}
void _TIFFsetLongArray(uint32 **lpp , uint32 *lp , uint32 n ) 
{ 


  {
  setByteArray((void **)lpp, (void *)lp, n, sizeof(uint32 ));
  return;
}
}
void _TIFFsetLong8Array(uint64 **lpp , uint64 *lp , uint32 n ) 
{ 


  {
  setByteArray((void **)lpp, (void *)lp, n, sizeof(uint64 ));
  return;
}
}
void _TIFFsetFloatArray(float **fpp , float *fp , uint32 n ) 
{ 


  {
  setByteArray((void **)fpp, (void *)fp, n, sizeof(float ));
  return;
}
}
void _TIFFsetDoubleArray(double **dpp , double *dp , uint32 n ) 
{ 


  {
  setByteArray((void **)dpp, (void *)dp, n, sizeof(double ));
  return;
}
}
static int setExtraSamples(TIFFDirectory *td , va_list ap , uint32 *v ) 
{ 
  uint16 *va ;
  uint32 i ;
  uint16_vap tmp ;
  uint16_vap tmp___0 ;
  uint16 *tmp___1 ;

  {
  tmp___0 = __builtin_va_arg(ap, uint16_vap );
  *v = (uint32 )((uint16 )tmp___0);
  if ((int )((uint16 )*v) > (int )td->td_samplesperpixel) {
    return (0);
  } else {

  }
  tmp___1 = __builtin_va_arg(ap, uint16 *);
  va = tmp___1;
  if (*v > 0U) {
    if ((unsigned int )va == (unsigned int )((void *)0)) {
      return (0);
    } else {

    }
  } else {

  }
  i = (uint32 )0;
  while (i < *v) {
    if ((int )*(va + i) > 2) {
      if ((int )*(va + i) == 999) {
        *(va + i) = (uint16 )2;
      } else {
        return (0);
      }
    } else {

    }
    i ++;
  }
  td->td_extrasamples = (uint16 )*v;
  _TIFFsetShortArray(& td->td_sampleinfo, va, (uint32 )td->td_extrasamples);
  return (1);
}
}
static uint32 checkInkNamesString(TIFF *tif , uint32 slen , char const   *s ) 
{ 
  TIFFDirectory *td ;
  uint16 i ;
  char const   *ep ;
  char const   *cp ;

  {
  td = & tif->tif_dir;
  i = td->td_samplesperpixel;
  if (slen > 0U) {
    ep = s + slen;
    cp = s;
    while ((int )i > 0) {
      while ((int const   )*cp != 0) {
        if ((unsigned int )cp >= (unsigned int )ep) {
          goto bad;
        } else {

        }
        cp ++;
      }
      cp ++;
      i = (uint16 )((int )i - 1);
    }
    return ((uint32 )(cp - s));
  } else {

  }
  bad: 
  TIFFErrorExt(tif->tif_clientdata, "TIFFSetField",
               "%s: Invalid InkNames value; expecting %d names, found %d",
               tif->tif_name, (int )td->td_samplesperpixel,
               (int )td->td_samplesperpixel - (int )i);
  return ((uint32 )0);
}
}
static int _TIFFVSetField(TIFF *tif , uint32 tag , va_list ap ) ;
static char const   module[15]  = 
  {      (char const   )'_',      (char const   )'T',      (char const   )'I',      (char const   )'F', 
        (char const   )'F',      (char const   )'V',      (char const   )'S',      (char const   )'e', 
        (char const   )'t',      (char const   )'F',      (char const   )'i',      (char const   )'e', 
        (char const   )'l',      (char const   )'d',      (char const   )'\000'};
static int _TIFFVSetField(TIFF *tif , uint32 tag , va_list ap ) 
{ 
  TIFFDirectory *td ;
  int status ;
  uint32 v32 ;
  uint32 i ;
  uint32 v ;
  char *s ;
  uint32 tmp ;
  uint32 tmp___0 ;
  uint32 tmp___1 ;
  uint32 tmp___2 ;
  uint32 tmp___3 ;
  uint32 tmp___4 ;
  uint16_vap tmp___5 ;
  uint16_vap tmp___6 ;
  uint16_vap tmp___7 ;
  uint16_vap tmp___8 ;
  uint16_vap tmp___9 ;
  uint16_vap tmp___10 ;
  uint16_vap tmp___11 ;
  uint16_vap tmp___12 ;
  uint16_vap tmp___13 ;
  uint16_vap tmp___14 ;
  uint16_vap tmp___15 ;
  uint16_vap tmp___16 ;
  uint16_vap tmp___17 ;
  uint16_vap tmp___18 ;
  uint32 tmp___19 ;
  uint32 tmp___20 ;
  uint16_vap tmp___21 ;
  uint16_vap tmp___22 ;
  uint16_vap tmp___23 ;
  uint16_vap tmp___24 ;
  double tmp___25 ;
  double tmp___26 ;
  double tmp___27 ;
  double tmp___28 ;
  double tmp___29 ;
  double tmp___30 ;
  double tmp___31 ;
  double tmp___32 ;
  uint16_vap tmp___33 ;
  uint16_vap tmp___34 ;
  double tmp___35 ;
  double tmp___36 ;
  double tmp___37 ;
  double tmp___38 ;
  uint16_vap tmp___39 ;
  uint16_vap tmp___40 ;
  uint16_vap tmp___41 ;
  uint16_vap tmp___42 ;
  uint16_vap tmp___43 ;
  uint16_vap tmp___44 ;
  uint16_vap tmp___45 ;
  uint16_vap tmp___46 ;
  uint16_vap tmp___47 ;
  uint16_vap tmp___48 ;
  uint16 *tmp___49 ;
  uint16 *tmp___50 ;
  uint16 *tmp___51 ;
  uint16 *tmp___52 ;
  uint16 *tmp___53 ;
  uint16 *tmp___54 ;
  int tmp___55 ;
  uint16_vap tmp___56 ;
  uint16_vap tmp___57 ;
  uint16 sv ;
  uint32 tmp___58 ;
  uint32 tmp___59 ;
  uint32 tmp___60 ;
  uint32 tmp___61 ;
  uint32 tmp___62 ;
  uint32 tmp___63 ;
  uint16_vap tmp___64 ;
  uint16_vap tmp___65 ;
  uint16_vap tmp___66 ;
  uint16_vap tmp___67 ;
  uint32 tmp___68 ;
  uint32 tmp___69 ;
  uint16_vap tmp___70 ;
  uint16_vap tmp___71 ;
  uint64 *tmp___72 ;
  uint64 *tmp___73 ;
  uint16_vap tmp___74 ;
  uint16_vap tmp___75 ;
  uint16_vap tmp___76 ;
  uint16_vap tmp___77 ;
  uint16_vap tmp___78 ;
  uint16_vap tmp___79 ;
  uint16 *tmp___80 ;
  uint16 *tmp___81 ;
  uint16_vap tmp___82 ;
  uint16_vap tmp___83 ;
  char *tmp___84 ;
  TIFFTagValue *tv ;
  int tv_size ;
  int iCustom ;
  TIFFField const   *fip ;
  TIFFField const   *tmp___85 ;
  char const   *tmp___86 ;
  char const   *tmp___87 ;
  TIFFTagValue *new_customValues ;
  void *tmp___88 ;
  uint32 ma ;
  char *mb ;
  uint32 tmp___89 ;
  uint32 tmp___90 ;
  char *tmp___91 ;
  char *tmp___92 ;
  char *tmp___93 ;
  char *tmp___94 ;
  size_t tmp___95 ;
  uint32 tmp___96 ;
  uint32 tmp___97 ;
  int tmp___98 ;
  int tmp___99 ;
  void *tmp___100 ;
  void *tmp___101 ;
  int i___0 ;
  char *val ;
  uint8 v___0 ;
  int tmp___102 ;
  int tmp___103 ;
  int8 v___1 ;
  int tmp___104 ;
  int tmp___105 ;
  uint16 v___2 ;
  int tmp___106 ;
  int tmp___107 ;
  int16 v___3 ;
  int tmp___108 ;
  int tmp___109 ;
  uint32 v___4 ;
  uint32 tmp___110 ;
  uint32 tmp___111 ;
  int32 v___5 ;
  int32 tmp___112 ;
  int32 tmp___113 ;
  uint64 v___6 ;
  uint64 tmp___114 ;
  uint64 tmp___115 ;
  int64 v___7 ;
  int64 tmp___116 ;
  int64 tmp___117 ;
  float v___8 ;
  double tmp___118 ;
  double tmp___119 ;
  double v___9 ;
  double tmp___120 ;
  double tmp___121 ;
  TIFFField const   *tmp___122 ;
  TIFFField const   *tmp___123 ;
  TIFFField const   *tmp___124 ;
  TIFFField const   *tmp___125 ;

  {
  td = & tif->tif_dir;
  status = 1;
  switch (tag) {
  case 254U: 
  tmp___0 = __builtin_va_arg(ap, uint32 );
  td->td_subfiletype = tmp___0;
  break;
  case 256U: 
  tmp___2 = __builtin_va_arg(ap, uint32 );
  td->td_imagewidth = tmp___2;
  break;
  case 257U: 
  tmp___4 = __builtin_va_arg(ap, uint32 );
  td->td_imagelength = tmp___4;
  break;
  case 258U: 
  tmp___6 = __builtin_va_arg(ap, uint16_vap );
  td->td_bitspersample = (uint16 )tmp___6;
  if (tif->tif_flags & 128U) {
    if ((int )td->td_bitspersample == 16) {
      tif->tif_postdecode = & _TIFFSwab16BitData;
    } else
    if ((int )td->td_bitspersample == 24) {
      tif->tif_postdecode = & _TIFFSwab24BitData;
    } else
    if ((int )td->td_bitspersample == 32) {
      tif->tif_postdecode = & _TIFFSwab32BitData;
    } else
    if ((int )td->td_bitspersample == 64) {
      tif->tif_postdecode = & _TIFFSwab64BitData;
    } else
    if ((int )td->td_bitspersample == 128) {
      tif->tif_postdecode = & _TIFFSwab64BitData;
    } else {

    }
  } else {

  }
  break;
  case 259U: 
  tmp___8 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___8);
  if (tif->tif_dir.td_fieldsset[0] & (1UL << 7)) {
    if ((uint32 )td->td_compression == v) {
      break;
    } else {

    }
    (*(tif->tif_cleanup))(tif);
    tif->tif_flags &= 4294967263U;
  } else {

  }
  status = TIFFSetCompressionScheme(tif, (int )v);
  if (status != 0) {
    td->td_compression = (uint16 )v;
  } else {
    status = 0;
  }
  break;
  case 262U: 
  tmp___10 = __builtin_va_arg(ap, uint16_vap );
  td->td_photometric = (uint16 )tmp___10;
  break;
  case 263U: 
  tmp___12 = __builtin_va_arg(ap, uint16_vap );
  td->td_threshholding = (uint16 )tmp___12;
  break;
  case 266U: 
  tmp___14 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___14);
  if (v != 2U) {
    if (v != 1U) {
      goto badvalue;
    } else {

    }
  } else {

  }
  td->td_fillorder = (uint16 )v;
  break;
  case 274U: 
  tmp___16 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___16);
  if (v < 1U) {
    goto badvalue;
  } else
  if (8U < v) {
    goto badvalue;
  } else {
    td->td_orientation = (uint16 )v;
  }
  break;
  case 277U: 
  tmp___18 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___18);
  if (v == 0U) {
    goto badvalue;
  } else {

  }
  td->td_samplesperpixel = (uint16 )v;
  break;
  case 278U: 
  tmp___20 = __builtin_va_arg(ap, uint32 );
  v32 = tmp___20;
  if (v32 == 0U) {
    goto badvalue32;
  } else {

  }
  td->td_rowsperstrip = v32;
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 2))) {
    td->td_tilelength = v32;
    td->td_tilewidth = td->td_imagewidth;
  } else {

  }
  break;
  case 280U: 
  tmp___22 = __builtin_va_arg(ap, uint16_vap );
  td->td_minsamplevalue = (uint16 )tmp___22;
  break;
  case 281U: 
  tmp___24 = __builtin_va_arg(ap, uint16_vap );
  td->td_maxsamplevalue = (uint16 )tmp___24;
  break;
  case 340U: 
  tmp___26 = __builtin_va_arg(ap, double );
  td->td_sminsamplevalue = tmp___26;
  break;
  case 341U: 
  tmp___28 = __builtin_va_arg(ap, double );
  td->td_smaxsamplevalue = tmp___28;
  break;
  case 282U: 
  tmp___30 = __builtin_va_arg(ap, double );
  td->td_xresolution = (float )tmp___30;
  break;
  case 283U: 
  tmp___32 = __builtin_va_arg(ap, double );
  td->td_yresolution = (float )tmp___32;
  break;
  case 284U: 
  tmp___34 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___34);
  if (v != 1U) {
    if (v != 2U) {
      goto badvalue;
    } else {

    }
  } else {

  }
  td->td_planarconfig = (uint16 )v;
  break;
  case 286U: 
  tmp___36 = __builtin_va_arg(ap, double );
  td->td_xposition = (float )tmp___36;
  break;
  case 287U: 
  tmp___38 = __builtin_va_arg(ap, double );
  td->td_yposition = (float )tmp___38;
  break;
  case 296U: 
  tmp___40 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___40);
  if (v < 1U) {
    goto badvalue;
  } else
  if (3U < v) {
    goto badvalue;
  } else {

  }
  td->td_resolutionunit = (uint16 )v;
  break;
  case 297U: 
  tmp___42 = __builtin_va_arg(ap, uint16_vap );
  td->td_pagenumber[0] = (uint16 )tmp___42;
  tmp___44 = __builtin_va_arg(ap, uint16_vap );
  td->td_pagenumber[1] = (uint16 )tmp___44;
  break;
  case 321U: 
  tmp___46 = __builtin_va_arg(ap, uint16_vap );
  td->td_halftonehints[0] = (uint16 )tmp___46;
  tmp___48 = __builtin_va_arg(ap, uint16_vap );
  td->td_halftonehints[1] = (uint16 )tmp___48;
  break;
  case 320U: 
  v32 = (uint32 )(1L << (int )td->td_bitspersample);
  tmp___50 = __builtin_va_arg(ap, uint16 *);
  _TIFFsetShortArray(& td->td_colormap[0], tmp___50, v32);
  tmp___52 = __builtin_va_arg(ap, uint16 *);
  _TIFFsetShortArray(& td->td_colormap[1], tmp___52, v32);
  tmp___54 = __builtin_va_arg(ap, uint16 *);
  _TIFFsetShortArray(& td->td_colormap[2], tmp___54, v32);
  break;
  case 338U: 
  tmp___55 = setExtraSamples(td, ap, & v);
  if (tmp___55) {

  } else {
    goto badvalue;
  }
  break;
  case 32995U: 
  tmp___57 = __builtin_va_arg(ap, uint16_vap );
  td->td_extrasamples = (uint16 )((int )((uint16 )tmp___57) != 0);
  if (td->td_extrasamples) {
    sv = (uint16 )1;
    _TIFFsetShortArray(& td->td_sampleinfo, & sv, (uint32 )1);
  } else {

  }
  break;
  case 322U: 
  tmp___59 = __builtin_va_arg(ap, uint32 );
  v32 = tmp___59;
  if (v32 % 16U) {
    if (tif->tif_mode != 0) {
      goto badvalue32;
    } else {

    }
    TIFFWarningExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                   "Nonstandard tile width %d, convert file", v32);
  } else {

  }
  td->td_tilewidth = v32;
  tif->tif_flags |= 1024U;
  break;
  case 323U: 
  tmp___61 = __builtin_va_arg(ap, uint32 );
  v32 = tmp___61;
  if (v32 % 16U) {
    if (tif->tif_mode != 0) {
      goto badvalue32;
    } else {

    }
    TIFFWarningExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                   "Nonstandard tile length %d, convert file", v32);
  } else {

  }
  td->td_tilelength = v32;
  tif->tif_flags |= 1024U;
  break;
  case 32998U: 
  tmp___63 = __builtin_va_arg(ap, uint32 );
  v32 = tmp___63;
  if (v32 == 0U) {
    goto badvalue32;
  } else {

  }
  td->td_tiledepth = v32;
  break;
  case 32996U: 
  tmp___65 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___65);
  switch (v) {
  case 0U: 
  v = (uint32 )4;
  break;
  case 1U: 
  v = (uint32 )2;
  break;
  case 2U: 
  v = (uint32 )1;
  break;
  case 3U: 
  v = (uint32 )3;
  break;
  default: 
  goto badvalue;
  }
  td->td_sampleformat = (uint16 )v;
  break;
  case 339U: 
  tmp___67 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___67);
  if (v < 1U) {
    goto badvalue;
  } else
  if (6U < v) {
    goto badvalue;
  } else {

  }
  td->td_sampleformat = (uint16 )v;
  if ((int )td->td_sampleformat == 5) {
    if ((int )td->td_bitspersample == 32) {
      if ((unsigned int )tif->tif_postdecode == (unsigned int )(& _TIFFSwab32BitData)) {
        tif->tif_postdecode = & _TIFFSwab16BitData;
      } else {
        goto _L___1;
      }
    } else {
      goto _L___1;
    }
  } else
  _L___1: /* CIL Label */ 
  _L___0: /* CIL Label */ 
  if ((int )td->td_sampleformat == 5) {
    goto _L;
  } else
  if ((int )td->td_sampleformat == 6) {
    _L: /* CIL Label */ 
    if ((int )td->td_bitspersample == 64) {
      if ((unsigned int )tif->tif_postdecode == (unsigned int )(& _TIFFSwab64BitData)) {
        tif->tif_postdecode = & _TIFFSwab32BitData;
      } else {

      }
    } else {

    }
  } else {

  }
  break;
  case 32997U: 
  tmp___69 = __builtin_va_arg(ap, uint32 );
  td->td_imagedepth = tmp___69;
  break;
  case 330U: 
  if ((tif->tif_flags & 8192U) == 0U) {
    tmp___71 = __builtin_va_arg(ap, uint16_vap );
    td->td_nsubifd = (uint16 )tmp___71;
    tmp___73 = __builtin_va_arg(ap, uint64 *);
    _TIFFsetLong8Array(& td->td_subifd, tmp___73,
                       (uint32 )((long )td->td_nsubifd));
  } else {
    TIFFErrorExt(tif->tif_clientdata, module, "%s: Sorry, cannot nest SubIFDs",
                 tif->tif_name);
    status = 0;
  }
  break;
  case 531U: 
  tmp___75 = __builtin_va_arg(ap, uint16_vap );
  td->td_ycbcrpositioning = (uint16 )tmp___75;
  break;
  case 530U: 
  tmp___77 = __builtin_va_arg(ap, uint16_vap );
  td->td_ycbcrsubsampling[0] = (uint16 )tmp___77;
  tmp___79 = __builtin_va_arg(ap, uint16_vap );
  td->td_ycbcrsubsampling[1] = (uint16 )tmp___79;
  break;
  case 301U: 
  if ((int )td->td_samplesperpixel - (int )td->td_extrasamples > 1) {
    v = (uint32 )3;
  } else {
    v = (uint32 )1;
  }
  i = (uint32 )0;
  while (i < v) {
    tmp___81 = __builtin_va_arg(ap, uint16 *);
    _TIFFsetShortArray(& td->td_transferfunction[i], tmp___81,
                       (uint32 )(1L << (int )td->td_bitspersample));
    i ++;
  }
  break;
  case 333U: 
  tmp___83 = __builtin_va_arg(ap, uint16_vap );
  v = (uint32 )((uint16 )tmp___83);
  tmp___84 = __builtin_va_arg(ap, char *);
  s = tmp___84;
  v = checkInkNamesString(tif, v, (char const   *)s);
  status = v > 0U;
  if (v > 0U) {
    _TIFFsetNString(& td->td_inknames, s, v);
    td->td_inknameslen = (int )v;
  } else {

  }
  break;
  default: 
  tmp___85 = TIFFFindField(tif, tag, (TIFFDataType )0);
  fip = tmp___85;
  if ((unsigned int )fip == (unsigned int )((void *)0)) {
    goto _L___2;
  } else
  if ((int const   )fip->field_bit != 65) {
    _L___2: /* CIL Label */ 
    if (fip) {
      tmp___86 = (char const   */* const  */)fip->field_name;
    } else {
      tmp___86 = (char const   */* const  */)"Unknown";
    }
    if (tag > 65535U) {
      tmp___87 = "pseudo-";
    } else {
      tmp___87 = "";
    }
    TIFFErrorExt(tif->tif_clientdata, module,
                 "%s: Invalid %stag \"%s\" (not supported by codec)",
                 tif->tif_name, tmp___87, tmp___86);
    status = 0;
    break;
  } else {

  }
  tv = (TIFFTagValue *)((void *)0);
  iCustom = 0;
  while (iCustom < td->td_customValueCount) {
    if (((td->td_customValues + iCustom)->info)->field_tag == (uint32 const   )tag) {
      tv = td->td_customValues + iCustom;
      if ((unsigned int )tv->value != (unsigned int )((void *)0)) {
        _TIFFfree(tv->value);
        tv->value = (void *)0;
      } else {

      }
      break;
    } else {

    }
    iCustom ++;
  }
  if ((unsigned int )tv == (unsigned int )((void *)0)) {
    (td->td_customValueCount) ++;
    tmp___88 = _TIFFrealloc((void *)td->td_customValues,
                            (tmsize_t )(sizeof(TIFFTagValue ) * (unsigned int )td->td_customValueCount));
    new_customValues = (TIFFTagValue *)tmp___88;
    if (! new_customValues) {
      TIFFErrorExt(tif->tif_clientdata, module,
                   "%s: Failed to allocate space for list of custom values",
                   tif->tif_name);
      status = 0;
      goto end;
    } else {

    }
    td->td_customValues = new_customValues;
    tv = td->td_customValues + (td->td_customValueCount - 1);
    tv->info = fip;
    tv->value = (void *)0;
    tv->count = 0;
  } else {

  }
  tv_size = _TIFFDataSize((TIFFDataType )fip->field_type);
  if (tv_size == 0) {
    status = 0;
    TIFFErrorExt(tif->tif_clientdata, module,
                 "%s: Bad field type %d for \"%s\"", tif->tif_name,
                 (unsigned int const   )fip->field_type, fip->field_name);
    goto end;
  } else {

  }
  if ((unsigned int const   )fip->field_type == 2U) {
    if (fip->field_passcount) {
      if ((int const   )fip->field_writecount == -3) {

      } else {
        __assert_fail("fip->field_writecount==-3", "tif_dir.c", 474U,
                      "_TIFFVSetField");
      }
      tmp___90 = __builtin_va_arg(ap, uint32 );
      ma = tmp___90;
      tmp___92 = __builtin_va_arg(ap, char *);
      mb = tmp___92;
    } else {
      tmp___94 = __builtin_va_arg(ap, char *);
      mb = tmp___94;
      tmp___95 = strlen((char const   *)mb);
      ma = tmp___95 + 1U;
    }
    tv->count = (int )ma;
    setByteArray(& tv->value, (void *)mb, ma, (size_t )1);
  } else {
    if (fip->field_passcount) {
      if ((int const   )fip->field_writecount == -3) {
        tmp___97 = __builtin_va_arg(ap, uint32 );
        tv->count = (int )tmp___97;
      } else {
        tmp___99 = __builtin_va_arg(ap, int );
        tv->count = tmp___99;
      }
    } else
    if ((int const   )fip->field_writecount == -1) {
      tv->count = 1;
    } else
    if ((int const   )fip->field_writecount == -3) {
      tv->count = 1;
    } else
    if ((int const   )fip->field_writecount == -2) {
      tv->count = (int )td->td_samplesperpixel;
    } else {
      tv->count = (int )fip->field_writecount;
    }
    tv->value = _TIFFCheckMalloc(tif, (tmsize_t )tv_size, (tmsize_t )tv->count,
                                 "Tag Value");
    if (! tv->value) {
      status = 0;
      goto end;
    } else {

    }
    if (fip->field_passcount) {
      goto _L___7;
    } else
    if ((int const   )fip->field_writecount == -1) {
      goto _L___7;
    } else
    if ((int const   )fip->field_writecount == -3) {
      goto _L___7;
    } else
    if ((int const   )fip->field_writecount == -2) {
      goto _L___7;
    } else
    if (tv->count > 1) {
      _L___7: /* CIL Label */ 
      if (fip->field_tag != 297U) {
        if (fip->field_tag != 321U) {
          if (fip->field_tag != 530U) {
            if (fip->field_tag != 336U) {
              tmp___101 = __builtin_va_arg(ap, void *);
              _TIFFmemcpy(tv->value, (void const   *)tmp___101,
                          (tmsize_t )(tv->count * tv_size));
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
      _L___6: /* CIL Label */ 
      _L___5: /* CIL Label */ 
      _L___4: /* CIL Label */ 
      _L___3: /* CIL Label */ 
      val = (char *)tv->value;
      i___0 = 0;
      while (i___0 < tv->count) {
        switch ((unsigned int const   )fip->field_type) {
        case 7U: 
        case 1U: 
        tmp___103 = __builtin_va_arg(ap, int );
        v___0 = (uint8 )tmp___103;
        _TIFFmemcpy((void *)val, (void const   *)(& v___0), (tmsize_t )tv_size);
        break;
        case 6U: 
        tmp___105 = __builtin_va_arg(ap, int );
        v___1 = (int8 )tmp___105;
        _TIFFmemcpy((void *)val, (void const   *)(& v___1), (tmsize_t )tv_size);
        break;
        case 3U: 
        tmp___107 = __builtin_va_arg(ap, int );
        v___2 = (uint16 )tmp___107;
        _TIFFmemcpy((void *)val, (void const   *)(& v___2), (tmsize_t )tv_size);
        break;
        case 8U: 
        tmp___109 = __builtin_va_arg(ap, int );
        v___3 = (int16 )tmp___109;
        _TIFFmemcpy((void *)val, (void const   *)(& v___3), (tmsize_t )tv_size);
        break;
        case 13U: 
        case 4U: 
        tmp___111 = __builtin_va_arg(ap, uint32 );
        v___4 = tmp___111;
        _TIFFmemcpy((void *)val, (void const   *)(& v___4), (tmsize_t )tv_size);
        break;
        case 9U: 
        tmp___113 = __builtin_va_arg(ap, int32 );
        v___5 = tmp___113;
        _TIFFmemcpy((void *)val, (void const   *)(& v___5), (tmsize_t )tv_size);
        break;
        case 18U: 
        case 16U: 
        tmp___115 = __builtin_va_arg(ap, uint64 );
        v___6 = tmp___115;
        _TIFFmemcpy((void *)val, (void const   *)(& v___6), (tmsize_t )tv_size);
        break;
        case 17U: 
        tmp___117 = __builtin_va_arg(ap, int64 );
        v___7 = tmp___117;
        _TIFFmemcpy((void *)val, (void const   *)(& v___7), (tmsize_t )tv_size);
        break;
        case 11U: 
        case 10U: 
        case 5U: 
        tmp___119 = __builtin_va_arg(ap, double );
        v___8 = (float )tmp___119;
        _TIFFmemcpy((void *)val, (void const   *)(& v___8), (tmsize_t )tv_size);
        break;
        case 12U: 
        tmp___121 = __builtin_va_arg(ap, double );
        v___9 = tmp___121;
        _TIFFmemcpy((void *)val, (void const   *)(& v___9), (tmsize_t )tv_size);
        break;
        default: 
        _TIFFmemset((void *)val, 0, (tmsize_t )tv_size);
        status = 0;
        break;
        }
        i___0 ++;
        val += tv_size;
      }
    }
  }
  }
  if (status) {
    tmp___122 = TIFFFieldWithTag(tif, tag);
    tmp___123 = TIFFFieldWithTag(tif, tag);
    tif->tif_dir.td_fieldsset[(int const   )tmp___122->field_bit / 32] |= 1UL << ((int const   )tmp___123->field_bit & 31);
    tif->tif_flags |= 8U;
  } else {

  }
  end: 
  __builtin_va_end(ap);
  return (status);
  badvalue: 
  tmp___124 = TIFFFieldWithTag(tif, tag);
  TIFFErrorExt(tif->tif_clientdata, module, "%s: Bad value %d for \"%s\" tag",
               tif->tif_name, v, tmp___124->field_name);
  __builtin_va_end(ap);
  return (0);
  badvalue32: 
  tmp___125 = TIFFFieldWithTag(tif, tag);
  TIFFErrorExt(tif->tif_clientdata, module, "%s: Bad value %ld for \"%s\" tag",
               tif->tif_name, v32, tmp___125->field_name);
  __builtin_va_end(ap);
  return (0);
}
}
static int OkToChangeTag(TIFF *tif , uint32 tag ) 
{ 
  TIFFField const   *fip ;
  TIFFField const   *tmp ;
  char const   *tmp___0 ;

  {
  tmp = TIFFFindField(tif, tag, (TIFFDataType )0);
  fip = tmp;
  if (! fip) {
    if (tag > 65535U) {
      tmp___0 = "pseudo-";
    } else {
      tmp___0 = "";
    }
    TIFFErrorExt(tif->tif_clientdata, "TIFFSetField", "%s: Unknown %stag %u",
                 tif->tif_name, tmp___0, tag);
    return (0);
  } else {

  }
  if (tag != 257U) {
    if (tif->tif_flags & 64U) {
      if (! fip->field_oktochange) {
        TIFFErrorExt(tif->tif_clientdata, "TIFFSetField",
                     "%s: Cannot modify tag \"%s\" while writing",
                     tif->tif_name, fip->field_name);
        return (0);
      } else {

      }
    } else {

    }
  } else {

  }
  return (1);
}
}
int TIFFSetField(TIFF *tif , uint32 tag  , ...) 
{ 
  va_list ap ;
  int status ;

  {
  __builtin_va_start(ap, tag);
  status = TIFFVSetField(tif, tag, ap);
  __builtin_va_end(ap);
  return (status);
}
}
int TIFFVSetField(TIFF *tif , uint32 tag , va_list ap ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;

  {
  tmp___2 = OkToChangeTag(tif, tag);
  if (tmp___2) {
    tmp___0 = (*(tif->tif_tagmethods.vsetfield))(tif, tag, ap);
    tmp___1 = tmp___0;
  } else {
    tmp___1 = 0;
  }
  return (tmp___1);
}
}
static int _TIFFVGetField(TIFF *tif , uint32 tag , va_list ap ) 
{ 
  TIFFDirectory *td ;
  int ret_val ;
  uint32 *tmp ;
  uint32 *tmp___0 ;
  uint32 *tmp___1 ;
  uint32 *tmp___2 ;
  uint32 *tmp___3 ;
  uint32 *tmp___4 ;
  uint16 *tmp___5 ;
  uint16 *tmp___6 ;
  uint16 *tmp___7 ;
  uint16 *tmp___8 ;
  uint16 *tmp___9 ;
  uint16 *tmp___10 ;
  uint16 *tmp___11 ;
  uint16 *tmp___12 ;
  uint16 *tmp___13 ;
  uint16 *tmp___14 ;
  uint16 *tmp___15 ;
  uint16 *tmp___16 ;
  uint16 *tmp___17 ;
  uint16 *tmp___18 ;
  uint32 *tmp___19 ;
  uint32 *tmp___20 ;
  uint16 *tmp___21 ;
  uint16 *tmp___22 ;
  uint16 *tmp___23 ;
  uint16 *tmp___24 ;
  double *tmp___25 ;
  double *tmp___26 ;
  double *tmp___27 ;
  double *tmp___28 ;
  float *tmp___29 ;
  float *tmp___30 ;
  float *tmp___31 ;
  float *tmp___32 ;
  uint16 *tmp___33 ;
  uint16 *tmp___34 ;
  float *tmp___35 ;
  float *tmp___36 ;
  float *tmp___37 ;
  float *tmp___38 ;
  uint16 *tmp___39 ;
  uint16 *tmp___40 ;
  uint16 *tmp___41 ;
  uint16 *tmp___42 ;
  uint16 *tmp___43 ;
  uint16 *tmp___44 ;
  uint16 *tmp___45 ;
  uint16 *tmp___46 ;
  uint16 *tmp___47 ;
  uint16 *tmp___48 ;
  uint16 **tmp___49 ;
  uint16 **tmp___50 ;
  uint16 **tmp___51 ;
  uint16 **tmp___52 ;
  uint16 **tmp___53 ;
  uint16 **tmp___54 ;
  uint64 **tmp___55 ;
  uint64 **tmp___56 ;
  uint64 **tmp___57 ;
  uint64 **tmp___58 ;
  uint16 *tmp___59 ;
  uint16 *tmp___60 ;
  int tmp___61 ;
  uint16 *tmp___62 ;
  uint16 *tmp___63 ;
  uint16 **tmp___64 ;
  uint16 **tmp___65 ;
  uint32 *tmp___66 ;
  uint32 *tmp___67 ;
  uint32 *tmp___68 ;
  uint32 *tmp___69 ;
  uint32 *tmp___70 ;
  uint32 *tmp___71 ;
  uint16 *tmp___72 ;
  uint16 *tmp___73 ;
  uint16 *tmp___74 ;
  uint16 *tmp___75 ;
  uint16 *tmp___76 ;
  uint16 *tmp___77 ;
  uint16 *tmp___78 ;
  uint16 *tmp___79 ;
  uint16 *tmp___80 ;
  uint16 *tmp___81 ;
  uint32 *tmp___82 ;
  uint32 *tmp___83 ;
  uint16 *tmp___84 ;
  uint16 *tmp___85 ;
  uint64 **tmp___86 ;
  uint64 **tmp___87 ;
  uint16 *tmp___88 ;
  uint16 *tmp___89 ;
  uint16 *tmp___90 ;
  uint16 *tmp___91 ;
  uint16 *tmp___92 ;
  uint16 *tmp___93 ;
  uint16 **tmp___94 ;
  uint16 **tmp___95 ;
  uint16 **tmp___96 ;
  uint16 **tmp___97 ;
  uint16 **tmp___98 ;
  uint16 **tmp___99 ;
  char **tmp___100 ;
  char **tmp___101 ;
  TIFFField const   *fip ;
  TIFFField const   *tmp___102 ;
  int i ;
  char const   *tmp___103 ;
  char const   *tmp___104 ;
  TIFFTagValue *tv ;
  uint32 *tmp___105 ;
  uint32 *tmp___106 ;
  uint16 *tmp___107 ;
  uint16 *tmp___108 ;
  void **tmp___109 ;
  void **tmp___110 ;
  void **tmp___111 ;
  void **tmp___112 ;
  int j ;
  char *val ;
  int tmp___113 ;
  uint8 *tmp___114 ;
  uint8 *tmp___115 ;
  int8 *tmp___116 ;
  int8 *tmp___117 ;
  uint16 *tmp___118 ;
  uint16 *tmp___119 ;
  int16 *tmp___120 ;
  int16 *tmp___121 ;
  uint32 *tmp___122 ;
  uint32 *tmp___123 ;
  int32 *tmp___124 ;
  int32 *tmp___125 ;
  uint64 *tmp___126 ;
  uint64 *tmp___127 ;
  int64 *tmp___128 ;
  int64 *tmp___129 ;
  float *tmp___130 ;
  float *tmp___131 ;
  double *tmp___132 ;
  double *tmp___133 ;

  {
  td = & tif->tif_dir;
  ret_val = 1;
  switch (tag) {
  case 254U: 
  tmp___0 = __builtin_va_arg(ap, uint32 *);
  *tmp___0 = td->td_subfiletype;
  break;
  case 256U: 
  tmp___2 = __builtin_va_arg(ap, uint32 *);
  *tmp___2 = td->td_imagewidth;
  break;
  case 257U: 
  tmp___4 = __builtin_va_arg(ap, uint32 *);
  *tmp___4 = td->td_imagelength;
  break;
  case 258U: 
  tmp___6 = __builtin_va_arg(ap, uint16 *);
  *tmp___6 = td->td_bitspersample;
  break;
  case 259U: 
  tmp___8 = __builtin_va_arg(ap, uint16 *);
  *tmp___8 = td->td_compression;
  break;
  case 262U: 
  tmp___10 = __builtin_va_arg(ap, uint16 *);
  *tmp___10 = td->td_photometric;
  break;
  case 263U: 
  tmp___12 = __builtin_va_arg(ap, uint16 *);
  *tmp___12 = td->td_threshholding;
  break;
  case 266U: 
  tmp___14 = __builtin_va_arg(ap, uint16 *);
  *tmp___14 = td->td_fillorder;
  break;
  case 274U: 
  tmp___16 = __builtin_va_arg(ap, uint16 *);
  *tmp___16 = td->td_orientation;
  break;
  case 277U: 
  tmp___18 = __builtin_va_arg(ap, uint16 *);
  *tmp___18 = td->td_samplesperpixel;
  break;
  case 278U: 
  tmp___20 = __builtin_va_arg(ap, uint32 *);
  *tmp___20 = td->td_rowsperstrip;
  break;
  case 280U: 
  tmp___22 = __builtin_va_arg(ap, uint16 *);
  *tmp___22 = td->td_minsamplevalue;
  break;
  case 281U: 
  tmp___24 = __builtin_va_arg(ap, uint16 *);
  *tmp___24 = td->td_maxsamplevalue;
  break;
  case 340U: 
  tmp___26 = __builtin_va_arg(ap, double *);
  *tmp___26 = td->td_sminsamplevalue;
  break;
  case 341U: 
  tmp___28 = __builtin_va_arg(ap, double *);
  *tmp___28 = td->td_smaxsamplevalue;
  break;
  case 282U: 
  tmp___30 = __builtin_va_arg(ap, float *);
  *tmp___30 = td->td_xresolution;
  break;
  case 283U: 
  tmp___32 = __builtin_va_arg(ap, float *);
  *tmp___32 = td->td_yresolution;
  break;
  case 284U: 
  tmp___34 = __builtin_va_arg(ap, uint16 *);
  *tmp___34 = td->td_planarconfig;
  break;
  case 286U: 
  tmp___36 = __builtin_va_arg(ap, float *);
  *tmp___36 = td->td_xposition;
  break;
  case 287U: 
  tmp___38 = __builtin_va_arg(ap, float *);
  *tmp___38 = td->td_yposition;
  break;
  case 296U: 
  tmp___40 = __builtin_va_arg(ap, uint16 *);
  *tmp___40 = td->td_resolutionunit;
  break;
  case 297U: 
  tmp___42 = __builtin_va_arg(ap, uint16 *);
  *tmp___42 = td->td_pagenumber[0];
  tmp___44 = __builtin_va_arg(ap, uint16 *);
  *tmp___44 = td->td_pagenumber[1];
  break;
  case 321U: 
  tmp___46 = __builtin_va_arg(ap, uint16 *);
  *tmp___46 = td->td_halftonehints[0];
  tmp___48 = __builtin_va_arg(ap, uint16 *);
  *tmp___48 = td->td_halftonehints[1];
  break;
  case 320U: 
  tmp___50 = __builtin_va_arg(ap, uint16 **);
  *tmp___50 = td->td_colormap[0];
  tmp___52 = __builtin_va_arg(ap, uint16 **);
  *tmp___52 = td->td_colormap[1];
  tmp___54 = __builtin_va_arg(ap, uint16 **);
  *tmp___54 = td->td_colormap[2];
  break;
  case 324U: 
  case 273U: 
  tmp___56 = __builtin_va_arg(ap, uint64 **);
  *tmp___56 = td->td_stripoffset;
  break;
  case 325U: 
  case 279U: 
  tmp___58 = __builtin_va_arg(ap, uint64 **);
  *tmp___58 = td->td_stripbytecount;
  break;
  case 32995U: 
  tmp___60 = __builtin_va_arg(ap, uint16 *);
  if ((int )td->td_extrasamples == 1) {
    if ((int )*(td->td_sampleinfo + 0) == 1) {
      tmp___61 = 1;
    } else {
      tmp___61 = 0;
    }
  } else {
    tmp___61 = 0;
  }
  *tmp___60 = (uint16 )tmp___61;
  break;
  case 338U: 
  tmp___63 = __builtin_va_arg(ap, uint16 *);
  *tmp___63 = td->td_extrasamples;
  tmp___65 = __builtin_va_arg(ap, uint16 **);
  *tmp___65 = td->td_sampleinfo;
  break;
  case 322U: 
  tmp___67 = __builtin_va_arg(ap, uint32 *);
  *tmp___67 = td->td_tilewidth;
  break;
  case 323U: 
  tmp___69 = __builtin_va_arg(ap, uint32 *);
  *tmp___69 = td->td_tilelength;
  break;
  case 32998U: 
  tmp___71 = __builtin_va_arg(ap, uint32 *);
  *tmp___71 = td->td_tiledepth;
  break;
  case 32996U: 
  switch ((int )td->td_sampleformat) {
  case 1: 
  tmp___73 = __builtin_va_arg(ap, uint16 *);
  *tmp___73 = (uint16 )2;
  break;
  case 2: 
  tmp___75 = __builtin_va_arg(ap, uint16 *);
  *tmp___75 = (uint16 )1;
  break;
  case 3: 
  tmp___77 = __builtin_va_arg(ap, uint16 *);
  *tmp___77 = (uint16 )3;
  break;
  case 4: 
  tmp___79 = __builtin_va_arg(ap, uint16 *);
  *tmp___79 = (uint16 )0;
  break;
  }
  break;
  case 339U: 
  tmp___81 = __builtin_va_arg(ap, uint16 *);
  *tmp___81 = td->td_sampleformat;
  break;
  case 32997U: 
  tmp___83 = __builtin_va_arg(ap, uint32 *);
  *tmp___83 = td->td_imagedepth;
  break;
  case 330U: 
  tmp___85 = __builtin_va_arg(ap, uint16 *);
  *tmp___85 = td->td_nsubifd;
  tmp___87 = __builtin_va_arg(ap, uint64 **);
  *tmp___87 = td->td_subifd;
  break;
  case 531U: 
  tmp___89 = __builtin_va_arg(ap, uint16 *);
  *tmp___89 = td->td_ycbcrpositioning;
  break;
  case 530U: 
  tmp___91 = __builtin_va_arg(ap, uint16 *);
  *tmp___91 = td->td_ycbcrsubsampling[0];
  tmp___93 = __builtin_va_arg(ap, uint16 *);
  *tmp___93 = td->td_ycbcrsubsampling[1];
  break;
  case 301U: 
  tmp___95 = __builtin_va_arg(ap, uint16 **);
  *tmp___95 = td->td_transferfunction[0];
  if ((int )td->td_samplesperpixel - (int )td->td_extrasamples > 1) {
    tmp___97 = __builtin_va_arg(ap, uint16 **);
    *tmp___97 = td->td_transferfunction[1];
    tmp___99 = __builtin_va_arg(ap, uint16 **);
    *tmp___99 = td->td_transferfunction[2];
  } else {

  }
  break;
  case 333U: 
  tmp___101 = __builtin_va_arg(ap, char **);
  *tmp___101 = td->td_inknames;
  break;
  default: 
  tmp___102 = TIFFFindField(tif, tag, (TIFFDataType )0);
  fip = tmp___102;
  if ((unsigned int )fip == (unsigned int )((void *)0)) {
    goto _L;
  } else
  if ((int const   )fip->field_bit != 65) {
    _L: /* CIL Label */ 
    if (fip) {
      tmp___103 = (char const   */* const  */)fip->field_name;
    } else {
      tmp___103 = (char const   */* const  */)"Unknown";
    }
    if (tag > 65535U) {
      tmp___104 = "pseudo-";
    } else {
      tmp___104 = "";
    }
    TIFFErrorExt(tif->tif_clientdata, "_TIFFVGetField",
                 "%s: Invalid %stag \"%s\" (not supported by codec)",
                 tif->tif_name, tmp___104, tmp___103);
    ret_val = 0;
    break;
  } else {

  }
  ret_val = 0;
  i = 0;
  while (i < td->td_customValueCount) {
    tv = td->td_customValues + i;
    if ((tv->info)->field_tag != (uint32 const   )tag) {
      goto __Cont;
    } else {

    }
    if (fip->field_passcount) {
      if ((int const   )fip->field_readcount == -3) {
        tmp___106 = __builtin_va_arg(ap, uint32 *);
        *tmp___106 = (uint32 )tv->count;
      } else {
        tmp___108 = __builtin_va_arg(ap, uint16 *);
        *tmp___108 = (uint16 )tv->count;
      }
      tmp___110 = __builtin_va_arg(ap, void **);
      *tmp___110 = tv->value;
      ret_val = 1;
    } else
    if ((unsigned int const   )fip->field_type == 2U) {
      goto _L___4;
    } else
    if ((int const   )fip->field_readcount == -1) {
      goto _L___4;
    } else
    if ((int const   )fip->field_readcount == -3) {
      goto _L___4;
    } else
    if ((int const   )fip->field_readcount == -2) {
      goto _L___4;
    } else
    if (tv->count > 1) {
      _L___4: /* CIL Label */ 
      if (fip->field_tag != 297U) {
        if (fip->field_tag != 321U) {
          if (fip->field_tag != 530U) {
            if (fip->field_tag != 336U) {
              tmp___112 = __builtin_va_arg(ap, void **);
              *tmp___112 = tv->value;
              ret_val = 1;
            } else {
              goto _L___3;
            }
          } else {
            goto _L___3;
          }
        } else {
          goto _L___3;
        }
      } else {
        goto _L___3;
      }
    } else {
      _L___3: /* CIL Label */ 
      _L___2: /* CIL Label */ 
      _L___1: /* CIL Label */ 
      _L___0: /* CIL Label */ 
      val = (char *)tv->value;
      j = 0;
      while (j < tv->count) {
        switch ((unsigned int const   )fip->field_type) {
        case 7U: 
        case 1U: 
        tmp___115 = __builtin_va_arg(ap, uint8 *);
        *tmp___115 = *((uint8 *)val);
        ret_val = 1;
        break;
        case 6U: 
        tmp___117 = __builtin_va_arg(ap, int8 *);
        *tmp___117 = *((int8 *)val);
        ret_val = 1;
        break;
        case 3U: 
        tmp___119 = __builtin_va_arg(ap, uint16 *);
        *tmp___119 = *((uint16 *)val);
        ret_val = 1;
        break;
        case 8U: 
        tmp___121 = __builtin_va_arg(ap, int16 *);
        *tmp___121 = *((int16 *)val);
        ret_val = 1;
        break;
        case 13U: 
        case 4U: 
        tmp___123 = __builtin_va_arg(ap, uint32 *);
        *tmp___123 = *((uint32 *)val);
        ret_val = 1;
        break;
        case 9U: 
        tmp___125 = __builtin_va_arg(ap, int32 *);
        *tmp___125 = *((int32 *)val);
        ret_val = 1;
        break;
        case 18U: 
        case 16U: 
        tmp___127 = __builtin_va_arg(ap, uint64 *);
        *tmp___127 = *((uint64 *)val);
        ret_val = 1;
        break;
        case 17U: 
        tmp___129 = __builtin_va_arg(ap, int64 *);
        *tmp___129 = *((int64 *)val);
        ret_val = 1;
        break;
        case 11U: 
        case 10U: 
        case 5U: 
        tmp___131 = __builtin_va_arg(ap, float *);
        *tmp___131 = *((float *)val);
        ret_val = 1;
        break;
        case 12U: 
        tmp___133 = __builtin_va_arg(ap, double *);
        *tmp___133 = *((double *)val);
        ret_val = 1;
        break;
        default: 
        ret_val = 0;
        break;
        }
        j ++;
        tmp___113 = _TIFFDataSize((TIFFDataType )(tv->info)->field_type);
        val += tmp___113;
      }
    }
    break;
    __Cont: /* CIL Label */ 
    i ++;
  }
  }
  return (ret_val);
}
}
int TIFFGetField(TIFF *tif , uint32 tag  , ...) 
{ 
  int status ;
  va_list ap ;

  {
  __builtin_va_start(ap, tag);
  status = TIFFVGetField(tif, tag, ap);
  __builtin_va_end(ap);
  return (status);
}
}
int TIFFVGetField(TIFF *tif , uint32 tag , va_list ap ) 
{ 
  TIFFField const   *fip ;
  TIFFField const   *tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  tmp = TIFFFindField(tif, tag, (TIFFDataType )0);
  fip = tmp;
  if (fip) {
    if (tag > 65535U) {
      tmp___0 = (*(tif->tif_tagmethods.vgetfield))(tif, tag, ap);
      tmp___1 = tmp___0;
    } else
    if (tif->tif_dir.td_fieldsset[(int const   )fip->field_bit / 32] & (1UL << ((int const   )fip->field_bit & 31))) {
      tmp___0 = (*(tif->tif_tagmethods.vgetfield))(tif, tag, ap);
      tmp___1 = tmp___0;
    } else {
      tmp___1 = 0;
    }
  } else {
    tmp___1 = 0;
  }
  return (tmp___1);
}
}
void TIFFFreeDirectory(TIFF *tif ) 
{ 
  TIFFDirectory *td ;
  int i ;

  {
  td = & tif->tif_dir;
  _TIFFmemset((void *)(td->td_fieldsset), 0, (tmsize_t )4);
  if (td->td_colormap[0]) {
    _TIFFfree((void *)td->td_colormap[0]);
    td->td_colormap[0] = (uint16 *)0;
  } else {

  }
  if (td->td_colormap[1]) {
    _TIFFfree((void *)td->td_colormap[1]);
    td->td_colormap[1] = (uint16 *)0;
  } else {

  }
  if (td->td_colormap[2]) {
    _TIFFfree((void *)td->td_colormap[2]);
    td->td_colormap[2] = (uint16 *)0;
  } else {

  }
  if (td->td_sampleinfo) {
    _TIFFfree((void *)td->td_sampleinfo);
    td->td_sampleinfo = (uint16 *)0;
  } else {

  }
  if (td->td_subifd) {
    _TIFFfree((void *)td->td_subifd);
    td->td_subifd = (uint64 *)0;
  } else {

  }
  if (td->td_inknames) {
    _TIFFfree((void *)td->td_inknames);
    td->td_inknames = (char *)0;
  } else {

  }
  if (td->td_transferfunction[0]) {
    _TIFFfree((void *)td->td_transferfunction[0]);
    td->td_transferfunction[0] = (uint16 *)0;
  } else {

  }
  if (td->td_transferfunction[1]) {
    _TIFFfree((void *)td->td_transferfunction[1]);
    td->td_transferfunction[1] = (uint16 *)0;
  } else {

  }
  if (td->td_transferfunction[2]) {
    _TIFFfree((void *)td->td_transferfunction[2]);
    td->td_transferfunction[2] = (uint16 *)0;
  } else {

  }
  if (td->td_stripoffset) {
    _TIFFfree((void *)td->td_stripoffset);
    td->td_stripoffset = (uint64 *)0;
  } else {

  }
  if (td->td_stripbytecount) {
    _TIFFfree((void *)td->td_stripbytecount);
    td->td_stripbytecount = (uint64 *)0;
  } else {

  }
  tif->tif_dir.td_fieldsset[1] &= ~ (1UL << 7);
  tif->tif_dir.td_fieldsset[1] &= ~ (1UL << 8);
  i = 0;
  while (i < td->td_customValueCount) {
    if ((td->td_customValues + i)->value) {
      _TIFFfree((td->td_customValues + i)->value);
    } else {

    }
    i ++;
  }
  td->td_customValueCount = 0;
  if (td->td_customValues) {
    _TIFFfree((void *)td->td_customValues);
    td->td_customValues = (TIFFTagValue *)0;
  } else {

  }
  return;
}
}
static void (*_TIFFextender)(TIFF * )  =    (void (*)(TIFF * ))((void *)0);
TIFFExtendProc TIFFSetTagExtender(void (*extender)(TIFF * ) ) 
{ 
  void (*prev)(TIFF * ) ;

  {
  prev = _TIFFextender;
  _TIFFextender = extender;
  return (prev);
}
}
int TIFFCreateDirectory(TIFF *tif ) 
{ 


  {
  TIFFDefaultDirectory(tif);
  tif->tif_diroff = (uint64 )0;
  tif->tif_nextdiroff = (uint64 )0;
  tif->tif_curoff = (uint64 )0;
  tif->tif_row = (uint32 )-1;
  tif->tif_curstrip = (uint32 )-1;
  return (0);
}
}
int TIFFDefaultDirectory(TIFF *tif ) 
{ 
  register TIFFDirectory *td ;
  TIFFFieldArray const   *tiffFieldArray ;

  {
  td = & tif->tif_dir;
  tiffFieldArray = _TIFFGetFields();
  _TIFFSetupFields(tif, tiffFieldArray);
  _TIFFmemset((void *)td, 0, (tmsize_t )sizeof(*td));
  td->td_fillorder = (uint16 )1;
  td->td_bitspersample = (uint16 )1;
  td->td_threshholding = (uint16 )1;
  td->td_orientation = (uint16 )1;
  td->td_samplesperpixel = (uint16 )1;
  td->td_rowsperstrip = (uint32 )-1;
  td->td_tilewidth = (uint32 )0;
  td->td_tilelength = (uint32 )0;
  td->td_tiledepth = (uint32 )1;
  td->td_stripbytecountsorted = 1;
  td->td_resolutionunit = (uint16 )2;
  td->td_sampleformat = (uint16 )1;
  td->td_imagedepth = (uint32 )1;
  td->td_ycbcrsubsampling[0] = (uint16 )2;
  td->td_ycbcrsubsampling[1] = (uint16 )2;
  td->td_ycbcrpositioning = (uint16 )1;
  tif->tif_postdecode = & _TIFFNoPostDecode;
  tif->tif_foundfield = (TIFFField const   *)((void *)0);
  tif->tif_tagmethods.vsetfield = & _TIFFVSetField;
  tif->tif_tagmethods.vgetfield = & _TIFFVGetField;
  tif->tif_tagmethods.printdir = (void (*)(TIFF * , FILE * , long  ))((void *)0);
  if (_TIFFextender) {
    (*_TIFFextender)(tif);
  } else {

  }
  TIFFSetField(tif, (uint32 )259, 1);
  tif->tif_flags &= 4294967287U;
  tif->tif_flags &= 4294966271U;
  return (1);
}
}
static int TIFFAdvanceDirectory(TIFF *tif , uint64 *nextdir , uint64 *off ) ;
static char const   module___0[21]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'A',      (char const   )'d',      (char const   )'v',      (char const   )'a', 
        (char const   )'n',      (char const   )'c',      (char const   )'e',      (char const   )'D', 
        (char const   )'i',      (char const   )'r',      (char const   )'e',      (char const   )'c', 
        (char const   )'t',      (char const   )'o',      (char const   )'r',      (char const   )'y', 
        (char const   )'\000'};
static int TIFFAdvanceDirectory(TIFF *tif , uint64 *nextdir , uint64 *off ) 
{ 
  uint64 poff ;
  tmsize_t poffa ;
  tmsize_t poffb ;
  tmsize_t poffc ;
  tmsize_t poffd ;
  uint16 dircount ;
  uint32 nextdir32 ;
  tmsize_t poffa___0 ;
  tmsize_t poffb___0 ;
  tmsize_t poffc___0 ;
  tmsize_t poffd___0 ;
  uint64 dircount64 ;
  uint16 dircount16 ;
  uint16 dircount___0 ;
  uint32 nextdir32___0 ;
  uint64 tmp ;
  tmsize_t tmp___0 ;
  tmsize_t tmp___1 ;
  uint64 dircount64___0 ;
  uint16 dircount16___0 ;
  uint64 tmp___2 ;
  tmsize_t tmp___3 ;
  tmsize_t tmp___4 ;

  {
  if ((tif->tif_flags & 2048U) != 0U) {
    poff = *nextdir;
    if (! (tif->tif_flags & 524288U)) {
      poffa = (tmsize_t )poff;
      poffb = (tmsize_t )((unsigned long )poffa + (unsigned long )sizeof(uint16 ));
      if ((uint64 )poffa != poff) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else
      if (poffb < poffa) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else
      if (poffb < (tmsize_t )sizeof(uint16 )) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else
      if (poffb > tif->tif_size) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else {

      }
      _TIFFmemcpy((void *)(& dircount), (void const   *)(tif->tif_base + poffa),
                  (tmsize_t )sizeof(uint16 ));
      if (tif->tif_flags & 128U) {
        TIFFSwabShort(& dircount);
      } else {

      }
      poffc = poffb + (tmsize_t )((int )dircount * 12);
      poffd = (tmsize_t )((unsigned long )poffc + (unsigned long )sizeof(uint32 ));
      if (poffc < poffb) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffc < (tmsize_t )((int )dircount * 12)) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffd < poffc) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffd < (tmsize_t )sizeof(uint32 )) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffd > tif->tif_size) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else {

      }
      if ((unsigned int )off != (unsigned int )((void *)0)) {
        *off = (uint64 )poffc;
      } else {

      }
      _TIFFmemcpy((void *)(& nextdir32),
                  (void const   *)(tif->tif_base + poffc),
                  (tmsize_t )sizeof(uint32 ));
      if (tif->tif_flags & 128U) {
        TIFFSwabLong(& nextdir32);
      } else {

      }
      *nextdir = (uint64 )nextdir32;
    } else {
      poffa___0 = (tmsize_t )poff;
      poffb___0 = (tmsize_t )((unsigned long )poffa___0 + (unsigned long )sizeof(uint64 ));
      if ((uint64 )poffa___0 != poff) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else
      if (poffb___0 < poffa___0) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else
      if (poffb___0 < (tmsize_t )sizeof(uint64 )) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else
      if (poffb___0 > tif->tif_size) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else {

      }
      _TIFFmemcpy((void *)(& dircount64),
                  (void const   *)(tif->tif_base + poffa___0),
                  (tmsize_t )sizeof(uint64 ));
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& dircount64);
      } else {

      }
      if (dircount64 > 65535ULL) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Sanity check on directory count failed");
        return (0);
      } else {

      }
      dircount16 = (uint16 )dircount64;
      poffc___0 = poffb___0 + (tmsize_t )((int )dircount16 * 20);
      poffd___0 = (tmsize_t )((unsigned long )poffc___0 + (unsigned long )sizeof(uint64 ));
      if (poffc___0 < poffb___0) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffc___0 < (tmsize_t )((int )dircount16 * 20)) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffd___0 < poffc___0) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffd___0 < (tmsize_t )sizeof(uint64 )) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else
      if (poffd___0 > tif->tif_size) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");
        return (0);
      } else {

      }
      if ((unsigned int )off != (unsigned int )((void *)0)) {
        *off = (uint64 )poffc___0;
      } else {

      }
      _TIFFmemcpy((void *)nextdir, (void const   *)(tif->tif_base + poffc___0),
                  (tmsize_t )sizeof(uint64 ));
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(nextdir);
      } else {

      }
    }
    return (1);
  } else {
    if (! (tif->tif_flags & 524288U)) {
      tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, *nextdir, 0);
      if (tmp == *nextdir) {
        tmp___0 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& dircount___0),
                                         (tmsize_t )sizeof(uint16 ));
        if ((unsigned long )tmp___0 == (unsigned long )sizeof(uint16 )) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module___0,
                       "%s: Error fetching directory count", tif->tif_name);
          return (0);
        }
      } else {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "%s: Error fetching directory count", tif->tif_name);
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabShort(& dircount___0);
      } else {

      }
      if ((unsigned int )off != (unsigned int )((void *)0)) {
        *off = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                      (uint64 )((int )dircount___0 * 12), 1);
      } else {
        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (uint64 )((int )dircount___0 * 12), 1);
      }
      tmp___1 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                       (void *)(& nextdir32___0),
                                       (tmsize_t )sizeof(uint32 ));
      if ((unsigned long )tmp___1 == (unsigned long )sizeof(uint32 )) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "%s: Error fetching directory link", tif->tif_name);
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong(& nextdir32___0);
      } else {

      }
      *nextdir = (uint64 )nextdir32___0;
    } else {
      tmp___2 = (*(tif->tif_seekproc))(tif->tif_clientdata, *nextdir, 0);
      if (tmp___2 == *nextdir) {
        tmp___3 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& dircount64___0),
                                         (tmsize_t )sizeof(uint64 ));
        if ((unsigned long )tmp___3 == (unsigned long )sizeof(uint64 )) {

        } else {
          TIFFErrorExt(tif->tif_clientdata, module___0,
                       "%s: Error fetching directory count", tif->tif_name);
          return (0);
        }
      } else {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "%s: Error fetching directory count", tif->tif_name);
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(& dircount64___0);
      } else {

      }
      if (dircount64___0 > 65535ULL) {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");
        return (0);
      } else {

      }
      dircount16___0 = (uint16 )dircount64___0;
      if ((unsigned int )off != (unsigned int )((void *)0)) {
        *off = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                      (uint64 )((int )dircount16___0 * 20), 1);
      } else {
        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (uint64 )((int )dircount16___0 * 20), 1);
      }
      tmp___4 = (*(tif->tif_readproc))(tif->tif_clientdata, (void *)nextdir,
                                       (tmsize_t )sizeof(uint64 ));
      if ((unsigned long )tmp___4 == (unsigned long )sizeof(uint64 )) {

      } else {
        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "%s: Error fetching directory link", tif->tif_name);
        return (0);
      }
      if (tif->tif_flags & 128U) {
        TIFFSwabLong8(nextdir);
      } else {

      }
    }
    return (1);
  }
}
}
uint16 TIFFNumberOfDirectories(TIFF *tif ) 
{ 
  uint64 nextdir ;
  uint16 n ;
  int tmp ;

  {
  if (! (tif->tif_flags & 524288U)) {
    nextdir = (uint64 )tif->tif_header.classic.tiff_diroff;
  } else {
    nextdir = tif->tif_header.big.tiff_diroff;
  }
  n = (uint16 )0;
  while (1) {
    if (nextdir != 0ULL) {
      tmp = TIFFAdvanceDirectory(tif, & nextdir, (uint64 *)((void *)0));
      if (tmp) {

      } else {
        break;
      }
    } else {
      break;
    }
    n = (uint16 )((int )n + 1);
  }
  return (n);
}
}
int TIFFSetDirectory(TIFF *tif , uint16 dirn ) 
{ 
  uint64 nextdir ;
  uint16 n ;
  int tmp ;
  int tmp___0 ;

  {
  if (! (tif->tif_flags & 524288U)) {
    nextdir = (uint64 )tif->tif_header.classic.tiff_diroff;
  } else {
    nextdir = tif->tif_header.big.tiff_diroff;
  }
  n = dirn;
  while (1) {
    if ((int )n > 0) {
      if (nextdir != 0ULL) {

      } else {
        break;
      }
    } else {
      break;
    }
    tmp = TIFFAdvanceDirectory(tif, & nextdir, (uint64 *)((void *)0));
    if (tmp) {

    } else {
      return (0);
    }
    n = (uint16 )((int )n - 1);
  }
  tif->tif_nextdiroff = nextdir;
  tif->tif_curdir = (uint16 )(((int )dirn - (int )n) - 1);
  tif->tif_dirnumber = (uint16 )0;
  tmp___0 = TIFFReadDirectory(tif);
  return (tmp___0);
}
}
int TIFFSetSubDirectory(TIFF *tif , uint64 diroff ) 
{ 
  int tmp ;

  {
  tif->tif_nextdiroff = diroff;
  tif->tif_dirnumber = (uint16 )0;
  tmp = TIFFReadDirectory(tif);
  return (tmp);
}
}
uint64 TIFFCurrentDirOffset(TIFF *tif ) 
{ 


  {
  return (tif->tif_diroff);
}
}
int TIFFLastDirectory(TIFF *tif ) 
{ 


  {
  return (tif->tif_nextdiroff == 0ULL);
}
}
int TIFFUnlinkDirectory(TIFF *tif , uint16 dirn ) ;
static char const   module___1[20]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'U',      (char const   )'n',      (char const   )'l',      (char const   )'i', 
        (char const   )'n',      (char const   )'k',      (char const   )'D',      (char const   )'i', 
        (char const   )'r',      (char const   )'e',      (char const   )'c',      (char const   )'t', 
        (char const   )'o',      (char const   )'r',      (char const   )'y',      (char const   )'\000'};
int TIFFUnlinkDirectory(TIFF *tif , uint16 dirn ) 
{ 
  uint64 nextdir ;
  uint64 off ;
  uint16 n ;
  int tmp ;
  int tmp___0 ;
  uint32 nextdir32 ;
  tmsize_t tmp___1 ;
  tmsize_t tmp___2 ;

  {
  if (tif->tif_mode == 0) {
    TIFFErrorExt(tif->tif_clientdata, module___1,
                 "Can not unlink directory in read-only file");
    return (0);
  } else {

  }
  if (! (tif->tif_flags & 524288U)) {
    nextdir = (uint64 )tif->tif_header.classic.tiff_diroff;
    off = (uint64 )4;
  } else {
    nextdir = tif->tif_header.big.tiff_diroff;
    off = (uint64 )8;
  }
  n = (uint16 )((int )dirn - 1);
  while ((int )n > 0) {
    if (nextdir == 0ULL) {
      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Directory %d does not exist", (int )dirn);
      return (0);
    } else {

    }
    tmp = TIFFAdvanceDirectory(tif, & nextdir, & off);
    if (tmp) {

    } else {
      return (0);
    }
    n = (uint16 )((int )n - 1);
  }
  tmp___0 = TIFFAdvanceDirectory(tif, & nextdir, (uint64 *)((void *)0));
  if (tmp___0) {

  } else {
    return (0);
  }
  (*(tif->tif_seekproc))(tif->tif_clientdata, off, 0);
  if (! (tif->tif_flags & 524288U)) {
    nextdir32 = (uint32 )nextdir;
    if ((uint64 )nextdir32 == nextdir) {

    } else {
      __assert_fail("(uint64)nextdir32==nextdir", "tif_dir.c", 1429U,
                    "TIFFUnlinkDirectory");
    }
    if (tif->tif_flags & 128U) {
      TIFFSwabLong(& nextdir32);
    } else {

    }
    tmp___1 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                      (void *)(& nextdir32),
                                      (tmsize_t )sizeof(uint32 ));
    if ((unsigned long )tmp___1 == (unsigned long )sizeof(uint32 )) {

    } else {
      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Error writing directory link");
      return (0);
    }
  } else {
    if (tif->tif_flags & 128U) {
      TIFFSwabLong8(& nextdir);
    } else {

    }
    tmp___2 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& nextdir),
                                      (tmsize_t )sizeof(uint64 ));
    if ((unsigned long )tmp___2 == (unsigned long )sizeof(uint64 )) {

    } else {
      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Error writing directory link");
      return (0);
    }
  }
  (*(tif->tif_cleanup))(tif);
  if (tif->tif_flags & 512U) {
    if (tif->tif_rawdata) {
      _TIFFfree((void *)tif->tif_rawdata);
      tif->tif_rawdata = (uint8 *)((void *)0);
      tif->tif_rawcc = (tmsize_t )0;
    } else {

    }
  } else {

  }
  tif->tif_flags &= 4294963119U;
  TIFFFreeDirectory(tif);
  TIFFDefaultDirectory(tif);
  tif->tif_diroff = (uint64 )0;
  tif->tif_nextdiroff = (uint64 )0;
  tif->tif_curoff = (uint64 )0;
  tif->tif_row = (uint32 )-1;
  tif->tif_curstrip = (uint32 )-1;
  return (1);
}
}
