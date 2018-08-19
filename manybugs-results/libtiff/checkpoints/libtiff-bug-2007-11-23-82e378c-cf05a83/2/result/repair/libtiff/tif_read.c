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
struct __anonstruct___sigset_t_2 {
   unsigned long __val[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef __sigset_t sigset_t;
typedef __suseconds_t suseconds_t;
typedef long __fd_mask;
struct __anonstruct_fd_set_3 {
   __fd_mask __fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef unsigned long pthread_t;
union __anonunion_pthread_attr_t_4 {
   char __size[36] ;
   long __align ;
};
union __anonunion____missing_field_name_6 {
   int __spins ;
   __pthread_slist_t __list ;
};
union __anonunion_pthread_mutex_t_5 {
   struct __pthread_mutex_s __data ;
   char __size[24] ;
   long __align ;
};
union __anonunion_pthread_mutexattr_t_7 {
   char __size[4] ;
   long __align ;
};
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
union __anonunion_pthread_condattr_t_10 {
   char __size[4] ;
   long __align ;
};
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
union __anonunion_pthread_rwlockattr_t_13 {
   char __size[8] ;
   long __align ;
};
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_14 {
   char __size[20] ;
   long __align ;
};
union __anonunion_pthread_barrierattr_t_15 {
   char __size[4] ;
   int __align ;
};
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
struct __anonstruct__G_fpos_t_29 {
   __off_t __pos ;
   __mbstate_t __state ;
};
struct __anonstruct__G_fpos64_t_30 {
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
extern  __attribute__((__nothrow__)) void _IO_flockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) void _IO_funlockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) int _IO_ftrylockfile(_IO_FILE * ) ;
extern int sys_nerr ;
extern char const   * const  sys_errlist[] ;
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
int TIFFReadBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
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
extern int TIFFWriteDirectory(TIFF * ) ;
extern int TIFFCheckpointDirectory(TIFF * ) ;
extern int TIFFRewriteDirectory(TIFF * ) ;
extern void TIFFPrintDirectory(TIFF * , FILE * , long  ) ;
int TIFFReadScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) ;
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
tmsize_t TIFFReadTile(TIFF *tif , void *buf , uint32 x , uint32 y , uint32 z ,
                      uint16 s ) ;
extern tmsize_t TIFFWriteTile(TIFF *tif , void *buf , uint32 x , uint32 y ,
                              uint32 z , uint16 s ) ;
extern uint32 TIFFComputeStrip(TIFF * , uint32  , uint16  ) ;
extern uint32 TIFFNumberOfStrips(TIFF * ) ;
tmsize_t TIFFReadEncodedStrip(TIFF *tif , uint32 strip , void *buf ,
                              tmsize_t size ) ;
tmsize_t TIFFReadRawStrip(TIFF *tif , uint32 strip , void *buf , tmsize_t size ) ;
tmsize_t TIFFReadEncodedTile(TIFF *tif , uint32 tile , void *buf ,
                             tmsize_t size ) ;
tmsize_t TIFFReadRawTile(TIFF *tif , uint32 tile , void *buf , tmsize_t size ) ;
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
void _TIFFNoPostDecode(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
extern int _TIFFNoPreCode(TIFF *tif , uint16 s ) ;
extern int _TIFFNoSeek(TIFF *tif , uint32 off ) ;
void _TIFFSwab16BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
void _TIFFSwab24BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
void _TIFFSwab32BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
void _TIFFSwab64BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) ;
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
int TIFFFillStrip(TIFF *tif , uint32 strip ) ;
int TIFFFillTile(TIFF *tif , uint32 tile ) ;
static int TIFFStartStrip(TIFF *tif , uint32 strip ) ;
static int TIFFStartTile(TIFF *tif , uint32 tile ) ;
static int TIFFCheckRead(TIFF *tif , int tiles ) ;
static int TIFFSeek(TIFF *tif , uint32 row , uint16 sample ) 
{ 
  register TIFFDirectory *td ;
  uint32 strip ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  td = & tif->tif_dir;



  if (row >= td->td_imagelength) {

    TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                 "%lu: Row out of range, max %lu", (unsigned long )row,
                 (unsigned long )td->td_imagelength);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8081", "0", checkpoints_buf);
    return (0);
  } else {

  }


  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8083", "2", checkpoints_buf);
  if ((int )td->td_planarconfig == 2) {
    if ((int )sample >= (int )td->td_samplesperpixel) {

      TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                   "%lu: Sample out of range, max %lu", (unsigned long )sample,
                   (unsigned long )td->td_samplesperpixel);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8086", "0", checkpoints_buf);
      return (0);
    } else {

    }
    strip = (uint32 )sample * td->td_stripsperimage + row / td->td_rowsperstrip;

  } else {
    strip = row / td->td_rowsperstrip;

  }
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8083", "2", checkpoints_buf);


  if (strip != tif->tif_curstrip) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8091", "tmp", checkpoints_buf);

    tmp = TIFFFillStrip(tif, strip);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8091", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8092", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8094", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8092", "tmp", checkpoints_buf);
  } else {


    if (row < tif->tif_row) {
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8096", "tmp___0", checkpoints_buf);

      tmp___0 = TIFFStartStrip(tif, strip);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8096", "tmp___0", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8097", "tmp___0", checkpoints_buf);
      if (tmp___0) {

      } else {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8099", "0", checkpoints_buf);
        return (0);
      }
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8097", "tmp___0", checkpoints_buf);
    } else {

    }


  }




  if (row != tif->tif_row) {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8102", "tmp___1", checkpoints_buf);

    tmp___1 = (*(tif->tif_seek))(tif, row - tif->tif_row);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8102", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8103", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8105", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8103", "tmp___1", checkpoints_buf);
    tif->tif_row = row;

  } else {

  }


  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8108", "1", checkpoints_buf);
  return (1);
}
}
int TIFFReadScanline(TIFF *tif , void *buf , uint32 row , uint16 sample ) 
{ 
  int e ;
  int tmp ;
  int tmp___0 ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8109", "tmp", checkpoints_buf);

  tmp = TIFFCheckRead(tif, 0);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8109", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8110", "tmp", checkpoints_buf);
  if (tmp) {

  } else {
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8112", "-1", checkpoints_buf);
    return (-1);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8110", "tmp", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8113", "e", checkpoints_buf);

  e = TIFFSeek(tif, row, sample);
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8113", "e", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8114", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8114", "0", checkpoints_buf);
  if (e != 0) {
    sprintf(checkpoints_buf, "%d", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8115", "e", checkpoints_buf);

    e = (*(tif->tif_decoderow))(tif, (uint8 *)buf, tif->tif_scanlinesize, sample);
    sprintf(checkpoints_buf, "%d", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8115", "e", checkpoints_buf);

    tif->tif_row = row + 1U;

    sprintf(checkpoints_buf, "%d", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8117", "e", checkpoints_buf);
    if (e) {

      (*(tif->tif_postdecode))(tif, (uint8 *)buf, tif->tif_scanlinesize);

    } else {

    }
    sprintf(checkpoints_buf, "%d", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8117", "e", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8114", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8114", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8121", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8121", "0", checkpoints_buf);
  if (e > 0) {
    tmp___0 = 1;
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8122", "tmp___0", checkpoints_buf);
  } else {
    tmp___0 = -1;
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8123", "tmp___0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8121", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8121", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8124", "tmp___0", checkpoints_buf);
  return (tmp___0);
}
}
tmsize_t TIFFReadEncodedStrip(TIFF *tif , uint32 strip , void *buf ,
                              tmsize_t size ) ;
static char const   module[21]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'E',      (char const   )'n',      (char const   )'c',      (char const   )'o', 
        (char const   )'d',      (char const   )'e',      (char const   )'d',      (char const   )'S', 
        (char const   )'t',      (char const   )'r',      (char const   )'i',      (char const   )'p', 
        (char const   )'\000'};
tmsize_t TIFFReadEncodedStrip(TIFF *tif , uint32 strip , void *buf ,
                              tmsize_t size ) 
{ 
  TIFFDirectory *td ;
  uint32 rowsperstrip ;
  uint32 stripsperplane ;
  uint32 stripinplane ;
  uint16 plane ;
  uint32 rows ;
  tmsize_t stripsize ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  td = & tif->tif_dir;

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8126", "tmp", checkpoints_buf);

  tmp = TIFFCheckRead(tif, 0);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8126", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8127", "tmp", checkpoints_buf);
  if (tmp) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8127", "tmp", checkpoints_buf);


  if (strip >= td->td_nstrips) {

    TIFFErrorExt(tif->tif_clientdata, module,
                 "%lu: Strip out of range, max %lu", (unsigned long )strip,
                 (unsigned long )td->td_nstrips);

    return ((tmsize_t )-1);
  } else {

  }


  rowsperstrip = td->td_rowsperstrip;



  if (rowsperstrip > td->td_imagelength) {
    rowsperstrip = td->td_imagelength;

  } else {

  }


  stripsperplane = ((td->td_imagelength + rowsperstrip) - 1U) / rowsperstrip;

  stripinplane = strip % stripsperplane;

  plane = (uint16 )(strip / stripsperplane);

  rows = td->td_imagelength - stripinplane * rowsperstrip;



  if (rows > rowsperstrip) {
    rows = rowsperstrip;

  } else {

  }




  stripsize = TIFFVStripSize(tif, rows);



  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8146", "0", checkpoints_buf);
  if (stripsize == 0L) {
    return ((tmsize_t )-1);
  } else {

  }

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8146", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8149", "-1", checkpoints_buf);
  if (size != -1L) {


    if (size < stripsize) {
      stripsize = size;

    } else {

    }


  } else {

  }

  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8149", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8154", "tmp___0", checkpoints_buf);

  tmp___0 = TIFFFillStrip(tif, strip);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8154", "tmp___0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8155", "tmp___0", checkpoints_buf);
  if (tmp___0) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8155", "tmp___0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8158", "tmp___1", checkpoints_buf);

  tmp___1 = (*(tif->tif_decodestrip))(tif, (uint8 *)buf, stripsize, plane);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8158", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8159", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8159", "0", checkpoints_buf);
  if (tmp___1 <= 0) {
    return ((tmsize_t )-1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8159", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8159", "0", checkpoints_buf);

  (*(tif->tif_postdecode))(tif, (uint8 *)buf, stripsize);


  return (stripsize);
}
}
static tmsize_t TIFFReadRawStrip1(TIFF *tif , uint32 strip , void *buf ,
                                  tmsize_t size , char const   *module___0 ) 
{ 
  TIFFDirectory *td ;
  tmsize_t cc ;
  uint64 tmp ;
  tmsize_t ma ;
  tmsize_t mb ;
  tmsize_t n ;

  {
  td = & tif->tif_dir;


  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8165", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8165", "0", checkpoints_buf);
  if ((tif->tif_flags & 131072U) == 0U) {

  } else {

    __assert_fail("(tif->tif_flags&0x20000)==0", "tif_read.c", 176U,
                  "TIFFReadRawStrip1");

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8165", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8165", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8168", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8168", "0", checkpoints_buf);
  if (! ((tif->tif_flags & 2048U) != 0U)) {


    tmp = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                 *(td->td_stripoffset + strip), 0);




    if (tmp == *(td->td_stripoffset + strip)) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Seek error at scanline %lu, strip %lu",
                   (unsigned long )tif->tif_row, (unsigned long )strip);

      return ((tmsize_t )-1);
    }




    cc = (*(tif->tif_readproc))(tif->tif_clientdata, buf, size);




    if (cc != size) {

      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Read error at scanline %lu; got %llu bytes, expected %llu",
                   (unsigned long )tif->tif_row, (unsigned long long )cc,
                   (unsigned long long )size);

      return ((tmsize_t )-1);
    } else {

    }


  } else {
    ma = (tmsize_t )*(td->td_stripoffset + strip);

    mb = ma + size;


    if ((uint64 )ma != *(td->td_stripoffset + strip)) {
      n = (tmsize_t )0;

    } else {


      if (ma > tif->tif_size) {
        n = (tmsize_t )0;

      } else {


        if (mb < ma) {
          n = tif->tif_size - ma;

        } else {


          if (mb < size) {
            n = tif->tif_size - ma;

          } else {


            if (mb > tif->tif_size) {
              n = tif->tif_size - ma;

            } else {
              n = size;

            }


          }


        }


      }


    }



    if (n != size) {

      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Read error at scanline %lu, strip %lu; got %llu bytes, expected %llu",
                   (unsigned long )tif->tif_row, (unsigned long )strip,
                   (unsigned long long )n, (unsigned long long )size);

      return ((tmsize_t )-1);
    } else {

    }



    _TIFFmemcpy(buf, (void const   *)(tif->tif_base + ma), size);

  }

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8168", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8168", "0", checkpoints_buf);

  return (size);
}
}
tmsize_t TIFFReadRawStrip(TIFF *tif , uint32 strip , void *buf , tmsize_t size ) ;
static char const   module___0[17]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'R',      (char const   )'a',      (char const   )'w',      (char const   )'S', 
        (char const   )'t',      (char const   )'r',      (char const   )'i',      (char const   )'p', 
        (char const   )'\000'};
tmsize_t TIFFReadRawStrip(TIFF *tif , uint32 strip , void *buf , tmsize_t size ) 
{ 
  TIFFDirectory *td ;
  uint64 bytecount ;
  tmsize_t bytecountm ;
  int tmp ;
  tmsize_t tmp___0 ;

  {
  td = & tif->tif_dir;

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8199", "tmp", checkpoints_buf);

  tmp = TIFFCheckRead(tif, 0);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8199", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8200", "tmp", checkpoints_buf);
  if (tmp) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8200", "tmp", checkpoints_buf);


  if (strip >= td->td_nstrips) {

    TIFFErrorExt(tif->tif_clientdata, module___0,
                 "%lu: Strip out of range, max %lu", (unsigned long )strip,
                 (unsigned long )td->td_nstrips);

    return ((tmsize_t )-1);
  } else {

  }



  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8207", "131072", checkpoints_buf);
  if (tif->tif_flags & 131072U) {

    TIFFErrorExt(tif->tif_clientdata, module___0,
                 "Compression scheme does not support access to raw uncompressed data");

    return ((tmsize_t )-1);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8207", "131072", checkpoints_buf);
  bytecount = *(td->td_stripbytecount + strip);


  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8212", "0", checkpoints_buf);
  if (bytecount <= 0ULL) {

    TIFFErrorExt(tif->tif_clientdata, module___0,
                 "%llu: Invalid strip byte count, strip %lu", bytecount,
                 (unsigned long )strip);


  } else {

  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8212", "0", checkpoints_buf);
  bytecountm = (tmsize_t )bytecount;


  if ((uint64 )bytecountm != bytecount) {

    TIFFErrorExt(tif->tif_clientdata, module___0, "Integer overflow");

    return ((tmsize_t )-1);
  } else {

  }


  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8221", "-1", checkpoints_buf);
  if (size != -1L) {


    if (size < bytecountm) {
      bytecountm = size;

    } else {

    }


  } else {

  }

  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8221", "-1", checkpoints_buf);


  tmp___0 = TIFFReadRawStrip1(tif, strip, buf, bytecountm, module___0);



  return (tmp___0);
}
}
int TIFFFillStrip(TIFF *tif , uint32 strip ) ;
static char const   module___1[14]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'F',      (char const   )'i',      (char const   )'l',      (char const   )'l', 
        (char const   )'S',      (char const   )'t',      (char const   )'r',      (char const   )'i', 
        (char const   )'p',      (char const   )'\000'};
int TIFFFillStrip(TIFF *tif , uint32 strip ) 
{ 
  TIFFDirectory *td ;
  uint64 bytecount ;
  tmsize_t bytecountm ;
  int tmp ;
  tmsize_t tmp___0 ;
  int tmp___1 ;

  {
  td = & tif->tif_dir;


  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8229", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8229", "0", checkpoints_buf);
  if ((tif->tif_flags & 131072U) == 0U) {
    bytecount = *(td->td_stripbytecount + strip);


    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8231", "0", checkpoints_buf);
    if (bytecount <= 0ULL) {

      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Invalid strip byte count %llu, strip %lu", bytecount,
                   (unsigned long )strip);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8233", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8231", "0", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 2048);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8235", "2048", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8235", "0", checkpoints_buf);
    if ((tif->tif_flags & 2048U) != 0U) {

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8236", "0", checkpoints_buf);
      if ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U) {
        goto _L___0;
      } else {

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8238", "256", checkpoints_buf);
        if (tif->tif_flags & 256U) {

          sprintf(checkpoints_buf, "%u", 512);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8239", "512", checkpoints_buf);
          _L___0: /* CIL Label */ 
          if (tif->tif_flags & 512U) {

            if (tif->tif_rawdata) {

              _TIFFfree((void *)tif->tif_rawdata);

            } else {

            }

          } else {

          }

          sprintf(checkpoints_buf, "%u", 512);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8239", "512", checkpoints_buf);
          tif->tif_flags &= 4294966783U;


          if (bytecount > (uint64 )tif->tif_size) {

            TIFFErrorExt(tif->tif_clientdata, module___1,
                         "Read error on strip %lu; got %llu bytes, expected %llu",
                         (unsigned long )strip,
                         (unsigned long long )tif->tif_size - *(td->td_stripoffset + strip),
                         bytecount);

            tif->tif_curstrip = (uint32 )-1;

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "8248", "0", checkpoints_buf);
            return (0);
          } else {


            if (*(td->td_stripoffset + strip) > (uint64 )tif->tif_size - bytecount) {

              TIFFErrorExt(tif->tif_clientdata, module___1,
                           "Read error on strip %lu; got %llu bytes, expected %llu",
                           (unsigned long )strip,
                           (unsigned long long )tif->tif_size - *(td->td_stripoffset + strip),
                           bytecount);

              tif->tif_curstrip = (uint32 )-1;

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "8252", "0", checkpoints_buf);
              return (0);
            } else {

            }


          }

          tif->tif_rawdatasize = (tmsize_t )bytecount;

          tif->tif_rawdata = tif->tif_base + (tmsize_t )*(td->td_stripoffset + strip);

        } else {
          goto _L;
        }

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8238", "256", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8236", "0", checkpoints_buf);
    } else {
      _L: /* CIL Label */ 
      bytecountm = (tmsize_t )bytecount;


      if ((uint64 )bytecountm != bytecount) {

        TIFFErrorExt(tif->tif_clientdata, module___1, "Integer overflow");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8260", "0", checkpoints_buf);
        return (0);
      } else {

      }



      if (bytecountm > tif->tif_rawdatasize) {
        tif->tif_curstrip = (uint32 )-1;


        sprintf(checkpoints_buf, "%u", 512);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8264", "512", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8264", "0", checkpoints_buf);
        if ((tif->tif_flags & 512U) == 0U) {

          TIFFErrorExt(tif->tif_clientdata, module___1,
                       "Data buffer too small to hold strip %lu",
                       (unsigned long )strip);

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8266", "0", checkpoints_buf);
          return (0);
        } else {

        }

        sprintf(checkpoints_buf, "%u", 512);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8264", "512", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8264", "0", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8268", "tmp", checkpoints_buf);

        tmp = TIFFReadBufferSetup(tif, (void *)0, bytecountm);
        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8268", "tmp", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8269", "tmp", checkpoints_buf);
        if (tmp) {

        } else {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8271", "0", checkpoints_buf);
          return (0);
        }
        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8269", "tmp", checkpoints_buf);
      } else {

      }




      tmp___0 = TIFFReadRawStrip1(tif, strip, (void *)tif->tif_rawdata,
                                  bytecountm, module___1);




      if (tmp___0 != bytecountm) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8275", "0", checkpoints_buf);
        return (0);
      } else {

      }



      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8277", "0", checkpoints_buf);
      if (! ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U)) {

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8278", "256", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8278", "0", checkpoints_buf);
        if ((tif->tif_flags & 256U) == 0U) {

          TIFFReverseBits(tif->tif_rawdata, bytecountm);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8278", "256", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8278", "0", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8277", "0", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 2048);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8235", "2048", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8235", "0", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8229", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8229", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8283", "tmp___1", checkpoints_buf);

  tmp___1 = TIFFStartStrip(tif, strip);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8283", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8284", "tmp___1", checkpoints_buf);
  return (tmp___1);
}
}
tmsize_t TIFFReadTile(TIFF *tif , void *buf , uint32 x , uint32 y , uint32 z ,
                      uint16 s ) 
{ 
  int tmp ;
  int tmp___0 ;
  uint32 tmp___1 ;
  tmsize_t tmp___2 ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8285", "tmp", checkpoints_buf);

  tmp = TIFFCheckRead(tif, 1);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8285", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8286", "tmp", checkpoints_buf);
  if (tmp) {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8287", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFCheckTile(tif, x, y, z, s);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8287", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8288", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8288", "tmp___0", checkpoints_buf);
  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8286", "tmp", checkpoints_buf);


  tmp___1 = TIFFComputeTile(tif, x, y, z, s);




  tmp___2 = TIFFReadEncodedTile(tif, tmp___1, buf, (tmsize_t )-1);



  return (tmp___2);
}
}
tmsize_t TIFFReadEncodedTile(TIFF *tif , uint32 tile , void *buf ,
                             tmsize_t size ) ;
static char const   module___2[20]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'E',      (char const   )'n',      (char const   )'c',      (char const   )'o', 
        (char const   )'d',      (char const   )'e',      (char const   )'d',      (char const   )'T', 
        (char const   )'i',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
tmsize_t TIFFReadEncodedTile(TIFF *tif , uint32 tile , void *buf ,
                             tmsize_t size ) 
{ 
  TIFFDirectory *td ;
  tmsize_t tilesize ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  td = & tif->tif_dir;

  tilesize = tif->tif_tilesize;

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8297", "tmp", checkpoints_buf);

  tmp = TIFFCheckRead(tif, 1);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8297", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8298", "tmp", checkpoints_buf);
  if (tmp) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8298", "tmp", checkpoints_buf);


  if (tile >= td->td_nstrips) {

    TIFFErrorExt(tif->tif_clientdata, module___2,
                 "%lu: Tile out of range, max %lu", (unsigned long )tile,
                 (unsigned long )td->td_nstrips);

    return ((tmsize_t )-1);
  } else {

  }



  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8305", "-1", checkpoints_buf);
  if (size == -1L) {
    size = tilesize;

  } else {


    if (size > tilesize) {
      size = tilesize;

    } else {

    }


  }

  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8305", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8310", "tmp___0", checkpoints_buf);

  tmp___0 = TIFFFillTile(tif, tile);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8310", "tmp___0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8311", "tmp___0", checkpoints_buf);
  if (tmp___0) {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8312", "tmp___1", checkpoints_buf);

    tmp___1 = (*(tif->tif_decodetile))(tif, (uint8 *)buf, size,
                                       (uint16 )(tile / td->td_stripsperimage));
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8312", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8313", "tmp___1", checkpoints_buf);
    if (tmp___1) {

      (*(tif->tif_postdecode))(tif, (uint8 *)buf, size);


      return (size);
    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8313", "tmp___1", checkpoints_buf);
  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8311", "tmp___0", checkpoints_buf);
}
}
static tmsize_t TIFFReadRawTile1(TIFF *tif , uint32 tile , void *buf ,
                                 tmsize_t size , char const   *module___3 ) 
{ 
  TIFFDirectory *td ;
  tmsize_t cc ;
  uint64 tmp ;
  tmsize_t ma ;
  tmsize_t mb ;
  tmsize_t n ;

  {
  td = & tif->tif_dir;


  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8319", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8319", "0", checkpoints_buf);
  if ((tif->tif_flags & 131072U) == 0U) {

  } else {

    __assert_fail("(tif->tif_flags&0x20000)==0", "tif_read.c", 460U,
                  "TIFFReadRawTile1");

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8319", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8319", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8322", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8322", "0", checkpoints_buf);
  if (! ((tif->tif_flags & 2048U) != 0U)) {


    tmp = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                 *(td->td_stripoffset + tile), 0);




    if (tmp == *(td->td_stripoffset + tile)) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___3,
                   "Seek error at row %lu, col %lu, tile %lu",
                   (unsigned long )tif->tif_row, (unsigned long )tif->tif_col,
                   (unsigned long )tile);

      return ((tmsize_t )-1);
    }




    cc = (*(tif->tif_readproc))(tif->tif_clientdata, buf, size);




    if (cc != size) {

      TIFFErrorExt(tif->tif_clientdata, module___3,
                   "Read error at row %lu, col %lu; got %llu bytes, expected %llu",
                   (unsigned long )tif->tif_row, (unsigned long )tif->tif_col,
                   (unsigned long long )cc, (unsigned long long )size);

      return ((tmsize_t )-1);
    } else {

    }


  } else {
    ma = (tmsize_t )*(td->td_stripoffset + tile);

    mb = ma + size;


    if ((uint64 )ma != *(td->td_stripoffset + tile)) {
      n = (tmsize_t )0;

    } else {


      if (ma > tif->tif_size) {
        n = (tmsize_t )0;

      } else {


        if (mb < ma) {
          n = tif->tif_size - ma;

        } else {


          if (mb < size) {
            n = tif->tif_size - ma;

          } else {


            if (mb > tif->tif_size) {
              n = tif->tif_size - ma;

            } else {
              n = size;

            }


          }


        }


      }


    }



    if (n != size) {

      TIFFErrorExt(tif->tif_clientdata, module___3,
                   "Read error at row %lu, col %lu, tile %lu; got %llu bytes, expected %llu",
                   (unsigned long )tif->tif_row, (unsigned long )tif->tif_col,
                   (unsigned long )tile, (unsigned long long )n,
                   (unsigned long long )size);

      return ((tmsize_t )-1);
    } else {

    }



    _TIFFmemcpy(buf, (void const   *)(tif->tif_base + ma), size);

  }

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8322", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8322", "0", checkpoints_buf);

  return (size);
}
}
tmsize_t TIFFReadRawTile(TIFF *tif , uint32 tile , void *buf , tmsize_t size ) ;
static char const   module___3[16]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'R',      (char const   )'a',      (char const   )'w',      (char const   )'T', 
        (char const   )'i',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
tmsize_t TIFFReadRawTile(TIFF *tif , uint32 tile , void *buf , tmsize_t size ) 
{ 
  TIFFDirectory *td ;
  uint64 bytecount64 ;
  tmsize_t bytecountm ;
  int tmp ;
  tmsize_t tmp___0 ;

  {
  td = & tif->tif_dir;

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8353", "tmp", checkpoints_buf);

  tmp = TIFFCheckRead(tif, 1);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8353", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8354", "tmp", checkpoints_buf);
  if (tmp) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8354", "tmp", checkpoints_buf);


  if (tile >= td->td_nstrips) {

    TIFFErrorExt(tif->tif_clientdata, module___3,
                 "%lu: Tile out of range, max %lu", (unsigned long )tile,
                 (unsigned long )td->td_nstrips);

    return ((tmsize_t )-1);
  } else {

  }



  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8361", "131072", checkpoints_buf);
  if (tif->tif_flags & 131072U) {

    TIFFErrorExt(tif->tif_clientdata, module___3,
                 "Compression scheme does not support access to raw uncompressed data");

    return ((tmsize_t )-1);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8361", "131072", checkpoints_buf);
  bytecount64 = *(td->td_stripbytecount + tile);


  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8366", "-1", checkpoints_buf);
  if (size != -1L) {

    if ((uint64 )size < bytecount64) {
      bytecount64 = (uint64 )size;

    } else {

    }

  } else {

  }

  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8366", "-1", checkpoints_buf);
  bytecountm = (tmsize_t )bytecount64;


  if ((uint64 )bytecountm != bytecount64) {

    TIFFErrorExt(tif->tif_clientdata, module___3, "Integer overflow");

    return ((tmsize_t )-1);
  } else {

  }



  tmp___0 = TIFFReadRawTile1(tif, tile, buf, bytecountm, module___3);



  return (tmp___0);
}
}
int TIFFFillTile(TIFF *tif , uint32 tile ) ;
static char const   module___4[13]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'F',      (char const   )'i',      (char const   )'l',      (char const   )'l', 
        (char const   )'T',      (char const   )'i',      (char const   )'l',      (char const   )'e', 
        (char const   )'\000'};
int TIFFFillTile(TIFF *tif , uint32 tile ) 
{ 
  TIFFDirectory *td ;
  uint64 bytecount ;
  tmsize_t bytecountm ;
  int tmp ;
  tmsize_t tmp___0 ;
  int tmp___1 ;

  {
  td = & tif->tif_dir;


  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8379", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8379", "0", checkpoints_buf);
  if ((tif->tif_flags & 131072U) == 0U) {
    bytecount = *(td->td_stripbytecount + tile);


    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8381", "0", checkpoints_buf);
    if (bytecount <= 0ULL) {

      TIFFErrorExt(tif->tif_clientdata, module___4,
                   "%llu: Invalid tile byte count, tile %lu", bytecount,
                   (unsigned long )tile);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8383", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8381", "0", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 2048);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8385", "2048", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8385", "0", checkpoints_buf);
    if ((tif->tif_flags & 2048U) != 0U) {

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8386", "0", checkpoints_buf);
      if ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U) {
        goto _L___0;
      } else {

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8388", "256", checkpoints_buf);
        if (tif->tif_flags & 256U) {

          sprintf(checkpoints_buf, "%u", 512);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8389", "512", checkpoints_buf);
          _L___0: /* CIL Label */ 
          if (tif->tif_flags & 512U) {

            if (tif->tif_rawdata) {

              _TIFFfree((void *)tif->tif_rawdata);

            } else {

            }

          } else {

          }

          sprintf(checkpoints_buf, "%u", 512);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8389", "512", checkpoints_buf);
          tif->tif_flags &= 4294966783U;


          if (bytecount > (uint64 )tif->tif_size) {
            tif->tif_curtile = (uint32 )-1;

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "8397", "0", checkpoints_buf);
            return (0);
          } else {


            if (*(td->td_stripoffset + tile) > (uint64 )tif->tif_size - bytecount) {
              tif->tif_curtile = (uint32 )-1;

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "8400", "0", checkpoints_buf);
              return (0);
            } else {

            }


          }

          tif->tif_rawdatasize = (tmsize_t )bytecount;

          tif->tif_rawdata = tif->tif_base + (tmsize_t )*(td->td_stripoffset + tile);

        } else {
          goto _L;
        }

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8388", "256", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8386", "0", checkpoints_buf);
    } else {
      _L: /* CIL Label */ 
      bytecountm = (tmsize_t )bytecount;


      if ((uint64 )bytecountm != bytecount) {

        TIFFErrorExt(tif->tif_clientdata, module___4, "Integer overflow");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8408", "0", checkpoints_buf);
        return (0);
      } else {

      }



      if (bytecountm > tif->tif_rawdatasize) {
        tif->tif_curtile = (uint32 )-1;


        sprintf(checkpoints_buf, "%u", 512);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8412", "512", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8412", "0", checkpoints_buf);
        if ((tif->tif_flags & 512U) == 0U) {

          TIFFErrorExt(tif->tif_clientdata, module___4,
                       "Data buffer too small to hold tile %lu",
                       (unsigned long )tile);

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8414", "0", checkpoints_buf);
          return (0);
        } else {

        }

        sprintf(checkpoints_buf, "%u", 512);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8412", "512", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8412", "0", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8416", "tmp", checkpoints_buf);

        tmp = TIFFReadBufferSetup(tif, (void *)0, bytecountm);
        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8416", "tmp", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8417", "tmp", checkpoints_buf);
        if (tmp) {

        } else {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "8419", "0", checkpoints_buf);
          return (0);
        }
        sprintf(checkpoints_buf, "%d", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8417", "tmp", checkpoints_buf);
      } else {

      }




      tmp___0 = TIFFReadRawTile1(tif, tile, (void *)tif->tif_rawdata,
                                 bytecountm, module___4);




      if (tmp___0 != bytecountm) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8423", "0", checkpoints_buf);
        return (0);
      } else {

      }



      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8425", "0", checkpoints_buf);
      if (! ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U)) {

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8426", "256", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8426", "0", checkpoints_buf);
        if ((tif->tif_flags & 256U) == 0U) {

          TIFFReverseBits(tif->tif_rawdata, bytecountm);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8426", "256", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8426", "0", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8425", "0", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 2048);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8385", "2048", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8385", "0", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8379", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8379", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8431", "tmp___1", checkpoints_buf);

  tmp___1 = TIFFStartTile(tif, tile);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8431", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8432", "tmp___1", checkpoints_buf);
  return (tmp___1);
}
}
int TIFFReadBufferSetup(TIFF *tif , void *bp , tmsize_t size ) ;
static char const   module___5[20]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'B',      (char const   )'u',      (char const   )'f',      (char const   )'f', 
        (char const   )'e',      (char const   )'r',      (char const   )'S',      (char const   )'e', 
        (char const   )'t',      (char const   )'u',      (char const   )'p',      (char const   )'\000'};
int TIFFReadBufferSetup(TIFF *tif , void *bp , tmsize_t size ) 
{ 
  void *tmp ;

  {

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8433", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8433", "0", checkpoints_buf);
  if ((tif->tif_flags & 131072U) == 0U) {

  } else {

    __assert_fail("(tif->tif_flags&0x20000)==0", "tif_read.c", 674U,
                  "TIFFReadBufferSetup");

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8433", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8433", "0", checkpoints_buf);

  if (tif->tif_rawdata) {

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8437", "512", checkpoints_buf);
    if (tif->tif_flags & 512U) {

      _TIFFfree((void *)tif->tif_rawdata);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8437", "512", checkpoints_buf);
    tif->tif_rawdata = (uint8 *)((void *)0);

  } else {

  }


  if (bp) {
    tif->tif_rawdatasize = size;

    tif->tif_rawdata = (uint8 *)bp;

    tif->tif_flags &= 4294966783U;

  } else {
    tif->tif_rawdatasize = (tmsize_t )((((uint64 )size + 1023ULL) / 1024ULL) * 1024ULL);


    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8447", "0", checkpoints_buf);
    if (tif->tif_rawdatasize == 0L) {
      tif->tif_rawdatasize = (tmsize_t )-1;

    } else {

    }

    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8447", "0", checkpoints_buf);


    tmp = _TIFFmalloc(tif->tif_rawdatasize);


    tif->tif_rawdata = (uint8 *)tmp;

    tif->tif_flags |= 512U;

  }

  if ((unsigned int )tif->tif_rawdata == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___5,
                 "No space for data buffer at scanline %lu",
                 (unsigned long )tif->tif_row);

    tif->tif_rawdatasize = (tmsize_t )0;

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8456", "0", checkpoints_buf);
    return (0);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8458", "1", checkpoints_buf);
  return (1);
}
}
static int TIFFStartStrip(TIFF *tif , uint32 strip ) 
{ 
  TIFFDirectory *td ;
  int tmp ;
  int tmp___0 ;

  {
  td = & tif->tif_dir;


  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8460", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8460", "0", checkpoints_buf);
  if ((tif->tif_flags & 32U) == 0U) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8461", "tmp", checkpoints_buf);

    tmp = (*(tif->tif_setupdecode))(tif);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8461", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8462", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8464", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8462", "tmp", checkpoints_buf);
    tif->tif_flags |= 32U;

  } else {

  }

  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8460", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8460", "0", checkpoints_buf);
  tif->tif_curstrip = strip;

  tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;


  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8469", "131072", checkpoints_buf);
  if (tif->tif_flags & 131072U) {
    tif->tif_rawcp = (uint8 *)((void *)0);

    tif->tif_rawcc = (tmsize_t )0;

  } else {
    tif->tif_rawcp = tif->tif_rawdata;

    tif->tif_rawcc = (tmsize_t )*(td->td_stripbytecount + strip);

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8469", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8474", "tmp___0", checkpoints_buf);

  tmp___0 = (*(tif->tif_predecode))(tif,
                                    (uint16 )(strip / td->td_stripsperimage));
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8474", "tmp___0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8475", "tmp___0", checkpoints_buf);
  return (tmp___0);
}
}
static int TIFFStartTile(TIFF *tif , uint32 tile ) 
{ 
  TIFFDirectory *td ;
  int tmp ;
  int tmp___0 ;

  {
  td = & tif->tif_dir;


  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8477", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8477", "0", checkpoints_buf);
  if ((tif->tif_flags & 32U) == 0U) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8478", "tmp", checkpoints_buf);

    tmp = (*(tif->tif_setupdecode))(tif);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8478", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8479", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8481", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8479", "tmp", checkpoints_buf);
    tif->tif_flags |= 32U;

  } else {

  }

  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8477", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8477", "0", checkpoints_buf);
  tif->tif_curtile = tile;

  tif->tif_row = (tile % ((td->td_imagewidth + (td->td_tilewidth - 1U)) / td->td_tilewidth)) * td->td_tilelength;

  tif->tif_col = (tile % ((td->td_imagelength + (td->td_tilelength - 1U)) / td->td_tilelength)) * td->td_tilewidth;


  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8487", "131072", checkpoints_buf);
  if (tif->tif_flags & 131072U) {
    tif->tif_rawcp = (uint8 *)((void *)0);

    tif->tif_rawcc = (tmsize_t )0;

  } else {
    tif->tif_rawcp = tif->tif_rawdata;

    tif->tif_rawcc = (tmsize_t )*(td->td_stripbytecount + tile);

  }

  sprintf(checkpoints_buf, "%u", 131072);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8487", "131072", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8492", "tmp___0", checkpoints_buf);

  tmp___0 = (*(tif->tif_predecode))(tif, (uint16 )(tile / td->td_stripsperimage));
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8492", "tmp___0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8493", "tmp___0", checkpoints_buf);
  return (tmp___0);
}
}
static int TIFFCheckRead(TIFF *tif , int tiles ) 
{ 
  char const   *tmp ;

  {

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8494", "1", checkpoints_buf);
  if (tif->tif_mode == 1) {

    TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                 "File not open for reading");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8496", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8494", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tiles);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8498", "tiles", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8498", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8498", "0", checkpoints_buf);
  if (tiles ^ ((tif->tif_flags & 1024U) != 0U)) {
    sprintf(checkpoints_buf, "%d", tiles);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8499", "tiles", checkpoints_buf);
    if (tiles) {
      tmp = "Can not read tiles from a stripped image";

    } else {
      tmp = "Can not read scanlines from a tiled image";

    }
    sprintf(checkpoints_buf, "%d", tiles);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8499", "tiles", checkpoints_buf);

    TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name, tmp);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8503", "0", checkpoints_buf);
    return (0);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tiles);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8498", "tiles", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8498", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8498", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8505", "1", checkpoints_buf);
  return (1);
}
}
void _TIFFNoPostDecode(TIFF *tif , uint8 *buf , tmsize_t cc ) 
{ 


  {
  return;
}
}
void _TIFFSwab16BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) 
{ 


  {

  sprintf(checkpoints_buf, "%ld", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8507", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8507", "0", checkpoints_buf);
  if ((cc & 1L) == 0L) {

  } else {

    __assert_fail("(cc & 1) == 0", "tif_read.c", 792U, "_TIFFSwab16BitData");

  }

  sprintf(checkpoints_buf, "%ld", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8507", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8507", "0", checkpoints_buf);

  TIFFSwabArrayOfShort((uint16 *)buf, cc / 2L);

  return;
}
}
void _TIFFSwab24BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) 
{ 


  {

  sprintf(checkpoints_buf, "%ld", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8512", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8512", "0", checkpoints_buf);
  if (cc % 3L == 0L) {

  } else {

    __assert_fail("(cc % 3) == 0", "tif_read.c", 800U, "_TIFFSwab24BitData");

  }

  sprintf(checkpoints_buf, "%ld", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8512", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8512", "0", checkpoints_buf);

  TIFFSwabArrayOfTriples(buf, cc / 3L);

  return;
}
}
void _TIFFSwab32BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) 
{ 


  {

  sprintf(checkpoints_buf, "%ld", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8517", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8517", "0", checkpoints_buf);
  if ((cc & 3L) == 0L) {

  } else {

    __assert_fail("(cc & 3) == 0", "tif_read.c", 808U, "_TIFFSwab32BitData");

  }

  sprintf(checkpoints_buf, "%ld", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8517", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8517", "0", checkpoints_buf);

  TIFFSwabArrayOfLong((uint32 *)buf, cc / 4L);

  return;
}
}
void _TIFFSwab64BitData(TIFF *tif , uint8 *buf , tmsize_t cc ) 
{ 


  {

  sprintf(checkpoints_buf, "%ld", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8522", "7", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8522", "0", checkpoints_buf);
  if ((cc & 7L) == 0L) {

  } else {

    __assert_fail("(cc & 7) == 0", "tif_read.c", 816U, "_TIFFSwab64BitData");

  }

  sprintf(checkpoints_buf, "%ld", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8522", "7", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8522", "0", checkpoints_buf);

  TIFFSwabArrayOfDouble((double *)buf, cc / 8L);

  return;
}
}
