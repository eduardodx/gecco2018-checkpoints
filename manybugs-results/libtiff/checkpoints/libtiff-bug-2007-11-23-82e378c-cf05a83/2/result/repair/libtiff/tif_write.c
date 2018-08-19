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
  sprintf(checkpoints_buf, "%d", imagegrew);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8769", "imagegrew", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8770", "64", checkpoints_buf);
  if (tif->tif_flags & 64U) {

  } else {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8772", "tmp", checkpoints_buf);

    tmp = TIFFWriteCheck(tif, 0, module);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8772", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8773", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8775", "-1", checkpoints_buf);
      return (-1);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8773", "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8770", "64", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8776", "16", checkpoints_buf);
  if (tif->tif_flags & 16U) {

    if (tif->tif_rawdata) {

    } else {
      goto _L;
    }

  } else {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8780", "tmp___0", checkpoints_buf);

    _L: /* CIL Label */ 
    tmp___0 = TIFFWriteBufferSetup(tif, (void *)0, (tmsize_t )-1);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8780", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8781", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8783", "-1", checkpoints_buf);
      return (-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8781", "tmp___0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8776", "16", checkpoints_buf);
  td = & tif->tif_dir;



  if (row >= td->td_imagelength) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8786", "2", checkpoints_buf);
    if ((int )td->td_planarconfig == 2) {

      TIFFErrorExt(tif->tif_clientdata, module,
                   "Can not change \"ImageLength\" when using separate planes");

      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8788", "-1", checkpoints_buf);
      return (-1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8786", "2", checkpoints_buf);
    td->td_imagelength = row + 1U;

    imagegrew = 1;
    sprintf(checkpoints_buf, "%d", imagegrew);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8791", "imagegrew", checkpoints_buf);
  } else {

  }


  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8793", "2", checkpoints_buf);
  if ((int )td->td_planarconfig == 2) {
    if ((int )sample >= (int )td->td_samplesperpixel) {

      TIFFErrorExt(tif->tif_clientdata, module,
                   "%lu: Sample out of range, max %lu", (unsigned long )sample,
                   (unsigned long )td->td_samplesperpixel);

      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8796", "-1", checkpoints_buf);
      return (-1);
    } else {

    }
    strip = (uint32 )sample * td->td_stripsperimage + row / td->td_rowsperstrip;

  } else {
    strip = row / td->td_rowsperstrip;

  }
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8793", "2", checkpoints_buf);


  if (strip >= td->td_nstrips) {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8801", "tmp___1", checkpoints_buf);

    tmp___1 = TIFFGrowStrips(tif, (uint32 )1, module);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8801", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8802", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8804", "-1", checkpoints_buf);
      return (-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8802", "tmp___1", checkpoints_buf);
  } else {

  }




  if (strip != tif->tif_curstrip) {
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8807", "tmp___2", checkpoints_buf);

    tmp___2 = TIFFFlushData(tif);
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8807", "tmp___2", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8808", "tmp___2", checkpoints_buf);
    if (tmp___2) {

    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8810", "-1", checkpoints_buf);
      return (-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8808", "tmp___2", checkpoints_buf);
    tif->tif_curstrip = strip;



    if (strip >= td->td_stripsperimage) {
      sprintf(checkpoints_buf, "%d", imagegrew);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8813", "imagegrew", checkpoints_buf);
      if (imagegrew) {
        td->td_stripsperimage = (td->td_imagelength + (td->td_rowsperstrip - 1U)) / td->td_rowsperstrip;

      } else {

      }
      sprintf(checkpoints_buf, "%d", imagegrew);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8813", "imagegrew", checkpoints_buf);
    } else {

    }


    tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;


    sprintf(checkpoints_buf, "%u", 32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8818", "32", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8818", "0", checkpoints_buf);
    if ((tif->tif_flags & 32U) == 0U) {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8819", "tmp___3", checkpoints_buf);

      tmp___3 = (*(tif->tif_setupencode))(tif);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8819", "tmp___3", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8820", "tmp___3", checkpoints_buf);
      if (tmp___3) {

      } else {
        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "8822", "-1", checkpoints_buf);
        return (-1);
      }
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8820", "tmp___3", checkpoints_buf);
      tif->tif_flags |= 32U;

    } else {

    }

    sprintf(checkpoints_buf, "%u", 32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8818", "32", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8818", "0", checkpoints_buf);
    tif->tif_rawcc = (tmsize_t )0;

    tif->tif_rawcp = tif->tif_rawdata;


    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8827", "0", checkpoints_buf);
    if (*(td->td_stripbytecount + strip) > 0ULL) {
      *(td->td_stripbytecount + strip) = (uint64 )0;

      tif->tif_curoff = (uint64 )0;

    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8827", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8831", "tmp___4", checkpoints_buf);

    tmp___4 = (*(tif->tif_preencode))(tif, sample);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8831", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8832", "tmp___4", checkpoints_buf);
    if (tmp___4) {

    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8834", "-1", checkpoints_buf);
      return (-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8832", "tmp___4", checkpoints_buf);
    tif->tif_flags |= 4096U;

  } else {

  }




  if (row != tif->tif_row) {


    if (row < tif->tif_row) {
      tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;

      tif->tif_rawcp = tif->tif_rawdata;

    } else {

    }


    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8842", "tmp___5", checkpoints_buf);

    tmp___5 = (*(tif->tif_seek))(tif, row - tif->tif_row);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8842", "tmp___5", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8843", "tmp___5", checkpoints_buf);
    if (tmp___5) {

    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "8845", "-1", checkpoints_buf);
      return (-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8843", "tmp___5", checkpoints_buf);
    tif->tif_row = row;

  } else {

  }



  (*(tif->tif_postdecode))(tif, (uint8 *)buf, tif->tif_scanlinesize);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8849", "status", checkpoints_buf);

  status = (*(tif->tif_encoderow))(tif, (uint8 *)buf, tif->tif_scanlinesize,
                                   sample);
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8849", "status", checkpoints_buf);

  tif->tif_row = row + 1U;

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8851", "status", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8853", "64", checkpoints_buf);
  if (tif->tif_flags & 64U) {

  } else {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8855", "tmp", checkpoints_buf);

    tmp = TIFFWriteCheck(tif, 0, module___0);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8855", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8856", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8856", "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8853", "64", checkpoints_buf);


  if (strip >= td->td_nstrips) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8860", "2", checkpoints_buf);
    if ((int )td->td_planarconfig == 2) {

      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Can not grow image by strips when using separate planes");

      return ((tmsize_t )-1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8860", "2", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8864", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFGrowStrips(tif, (uint32 )1, module___0);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8864", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8865", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8865", "tmp___0", checkpoints_buf);
    td->td_stripsperimage = (td->td_imagelength + (td->td_rowsperstrip - 1U)) / td->td_rowsperstrip;

  } else {

  }



  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8870", "16", checkpoints_buf);
  if (tif->tif_flags & 16U) {

    if (tif->tif_rawdata) {

    } else {
      goto _L;
    }

  } else {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8874", "tmp___1", checkpoints_buf);

    _L: /* CIL Label */ 
    tmp___1 = TIFFWriteBufferSetup(tif, (void *)0, (tmsize_t )-1);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8874", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8875", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8875", "tmp___1", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8870", "16", checkpoints_buf);
  tif->tif_curstrip = strip;

  tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;


  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8880", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8880", "0", checkpoints_buf);
  if ((tif->tif_flags & 32U) == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8881", "tmp___2", checkpoints_buf);

    tmp___2 = (*(tif->tif_setupencode))(tif);
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8881", "tmp___2", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8882", "tmp___2", checkpoints_buf);
    if (tmp___2) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8882", "tmp___2", checkpoints_buf);
    tif->tif_flags |= 32U;

  } else {

  }

  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8880", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8880", "0", checkpoints_buf);
  tif->tif_rawcc = (tmsize_t )0;

  tif->tif_rawcp = tif->tif_rawdata;


  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8889", "0", checkpoints_buf);
  if (*(td->td_stripbytecount + strip) > 0ULL) {
    tif->tif_curoff = (uint64 )0;

  } else {

  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8889", "0", checkpoints_buf);
  tif->tif_flags &= 4294963199U;

  sample = (uint16 )(strip / td->td_stripsperimage);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8894", "tmp___3", checkpoints_buf);

  tmp___3 = (*(tif->tif_preencode))(tif, sample);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8894", "tmp___3", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8895", "tmp___3", checkpoints_buf);
  if (tmp___3) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8895", "tmp___3", checkpoints_buf);

  (*(tif->tif_postdecode))(tif, (uint8 *)data, cc);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8899", "tmp___4", checkpoints_buf);

  tmp___4 = (*(tif->tif_encodestrip))(tif, (uint8 *)data, cc, sample);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8899", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8900", "tmp___4", checkpoints_buf);
  if (tmp___4) {

  } else {
    return ((tmsize_t )0);
  }
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8900", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8903", "tmp___5", checkpoints_buf);

  tmp___5 = (*(tif->tif_postencode))(tif);
  sprintf(checkpoints_buf, "%d", tmp___5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8903", "tmp___5", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8904", "tmp___5", checkpoints_buf);
  if (tmp___5) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp___5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8904", "tmp___5", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8907", "0", checkpoints_buf);
  if (! ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U)) {

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8908", "256", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8908", "0", checkpoints_buf);
    if ((tif->tif_flags & 256U) == 0U) {

      TIFFReverseBits(tif->tif_rawdata, tif->tif_rawcc);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8908", "256", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8908", "0", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8907", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8912", "0", checkpoints_buf);
  if (tif->tif_rawcc > 0L) {
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8913", "tmp___6", checkpoints_buf);

    tmp___6 = TIFFAppendToStrip(tif, strip, tif->tif_rawdata, tif->tif_rawcc);
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8913", "tmp___6", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8914", "tmp___6", checkpoints_buf);
    if (tmp___6) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8914", "tmp___6", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8912", "0", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8922", "64", checkpoints_buf);
  if (tif->tif_flags & 64U) {

  } else {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8924", "tmp", checkpoints_buf);

    tmp = TIFFWriteCheck(tif, 0, module___1);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8924", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8925", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8925", "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8922", "64", checkpoints_buf);


  if (strip >= td->td_nstrips) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8929", "2", checkpoints_buf);
    if ((int )td->td_planarconfig == 2) {

      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Can not grow image by strips when using separate planes");

      return ((tmsize_t )-1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8929", "2", checkpoints_buf);


    if (strip >= td->td_stripsperimage) {
      td->td_stripsperimage = (td->td_imagelength + (td->td_rowsperstrip - 1U)) / td->td_rowsperstrip;

    } else {

    }


    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8936", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFGrowStrips(tif, (uint32 )1, module___1);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8936", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8937", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8937", "tmp___0", checkpoints_buf);
  } else {

  }


  tif->tif_curstrip = strip;

  tif->tif_row = (strip % td->td_stripsperimage) * td->td_rowsperstrip;

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8943", "tmp___3", checkpoints_buf);

  tmp___3 = TIFFAppendToStrip(tif, strip, (uint8 *)data, cc);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8943", "tmp___3", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8944", "tmp___3", checkpoints_buf);
  if (tmp___3) {
    tmp___2 = cc;

  } else {
    tmp___2 = (tmsize_t )-1;

  }
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8944", "tmp___3", checkpoints_buf);

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
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8948", "tmp", checkpoints_buf);

  tmp = TIFFCheckTile(tif, x, y, z, s);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8948", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8949", "tmp", checkpoints_buf);
  if (tmp) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8949", "tmp", checkpoints_buf);


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

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8955", "64", checkpoints_buf);
  if (tif->tif_flags & 64U) {

  } else {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8957", "tmp", checkpoints_buf);

    tmp = TIFFWriteCheck(tif, 1, module___2);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8957", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8958", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8958", "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8955", "64", checkpoints_buf);
  td = & tif->tif_dir;



  if (tile >= td->td_nstrips) {

    TIFFErrorExt(tif->tif_clientdata, module___2,
                 "Tile %lu out of range, max %lu", (unsigned long )tile,
                 (unsigned long )td->td_nstrips);

    return ((tmsize_t )-1);
  } else {

  }



  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8966", "16", checkpoints_buf);
  if (tif->tif_flags & 16U) {

    if (tif->tif_rawdata) {

    } else {
      goto _L;
    }

  } else {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8970", "tmp___0", checkpoints_buf);

    _L: /* CIL Label */ 
    tmp___0 = TIFFWriteBufferSetup(tif, (void *)0, (tmsize_t )-1);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8970", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8971", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8971", "tmp___0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8966", "16", checkpoints_buf);
  tif->tif_curtile = tile;

  tif->tif_rawcc = (tmsize_t )0;

  tif->tif_rawcp = tif->tif_rawdata;


  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8977", "0", checkpoints_buf);
  if (*(td->td_stripbytecount + tile) > 0ULL) {
    tif->tif_curoff = (uint64 )0;

  } else {

  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8977", "0", checkpoints_buf);
  tif->tif_row = (tile % ((td->td_imagelength + (td->td_tilelength - 1U)) / td->td_tilelength)) * td->td_tilelength;

  tif->tif_col = (tile % ((td->td_imagewidth + (td->td_tilewidth - 1U)) / td->td_tilewidth)) * td->td_tilewidth;


  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8982", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8982", "0", checkpoints_buf);
  if ((tif->tif_flags & 32U) == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8983", "tmp___1", checkpoints_buf);

    tmp___1 = (*(tif->tif_setupencode))(tif);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8983", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8984", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "8984", "tmp___1", checkpoints_buf);
    tif->tif_flags |= 32U;

  } else {

  }

  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8982", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8982", "0", checkpoints_buf);
  tif->tif_flags &= 4294963199U;

  sample = (uint16 )(tile / td->td_stripsperimage);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8991", "tmp___2", checkpoints_buf);

  tmp___2 = (*(tif->tif_preencode))(tif, sample);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8991", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8992", "tmp___2", checkpoints_buf);
  if (tmp___2) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8992", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%ld", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8995", "1", checkpoints_buf);
  if (cc < 1L) {
    cc = tif->tif_tilesize;

  } else {


    if (cc > tif->tif_tilesize) {
      cc = tif->tif_tilesize;

    } else {

    }


  }

  sprintf(checkpoints_buf, "%ld", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "8995", "1", checkpoints_buf);

  (*(tif->tif_postdecode))(tif, (uint8 *)data, cc);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9001", "tmp___3", checkpoints_buf);

  tmp___3 = (*(tif->tif_encodetile))(tif, (uint8 *)data, cc, sample);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9001", "tmp___3", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9002", "tmp___3", checkpoints_buf);
  if (tmp___3) {

  } else {
    return ((tmsize_t )0);
  }
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9002", "tmp___3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9005", "tmp___4", checkpoints_buf);

  tmp___4 = (*(tif->tif_postencode))(tif);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9005", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9006", "tmp___4", checkpoints_buf);
  if (tmp___4) {

  } else {
    return ((tmsize_t )-1);
  }
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9006", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9009", "0", checkpoints_buf);
  if (! ((tif->tif_flags & (unsigned int )td->td_fillorder) != 0U)) {

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9010", "256", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9010", "0", checkpoints_buf);
    if ((tif->tif_flags & 256U) == 0U) {

      TIFFReverseBits(tif->tif_rawdata, tif->tif_rawcc);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9010", "256", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9010", "0", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9009", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9014", "0", checkpoints_buf);
  if (tif->tif_rawcc > 0L) {
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9015", "tmp___5", checkpoints_buf);

    tmp___5 = TIFFAppendToStrip(tif, tile, tif->tif_rawdata, tif->tif_rawcc);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9015", "tmp___5", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9016", "tmp___5", checkpoints_buf);
    if (tmp___5) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9016", "tmp___5", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9014", "0", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9023", "64", checkpoints_buf);
  if (tif->tif_flags & 64U) {

  } else {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9025", "tmp", checkpoints_buf);

    tmp = TIFFWriteCheck(tif, 1, module___3);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9025", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9026", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      return ((tmsize_t )-1);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9026", "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 64);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9023", "64", checkpoints_buf);


  if (tile >= tif->tif_dir.td_nstrips) {

    TIFFErrorExt(tif->tif_clientdata, module___3,
                 "Tile %lu out of range, max %lu", (unsigned long )tile,
                 (unsigned long )tif->tif_dir.td_nstrips);

    return ((tmsize_t )-1);
  } else {

  }


  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9033", "tmp___2", checkpoints_buf);

  tmp___2 = TIFFAppendToStrip(tif, tile, (uint8 *)data, cc);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9033", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9034", "tmp___2", checkpoints_buf);
  if (tmp___2) {
    tmp___1 = cc;

  } else {
    tmp___1 = (tmsize_t )-1;

  }
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9034", "tmp___2", checkpoints_buf);

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


  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9039", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9039", "0", checkpoints_buf);
  if ((tif->tif_flags & 1024U) != 0U) {

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9040", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9040", "2", checkpoints_buf);
    if (tif->tif_dir.td_fieldsset[0] & (1UL << 2)) {

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9041", "0", checkpoints_buf);
      if (tif->tif_dir.td_imagelength == 0U) {
        td->td_stripsperimage = (uint32 )td->td_samplesperpixel;

      } else {


        tmp = TIFFNumberOfTiles(tif);


        td->td_stripsperimage = tmp;

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9041", "0", checkpoints_buf);
    } else {


      tmp = TIFFNumberOfTiles(tif);


      td->td_stripsperimage = tmp;

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9040", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9040", "2", checkpoints_buf);
  } else {

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9047", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9047", "17", checkpoints_buf);
    if (tif->tif_dir.td_fieldsset[0] & (1UL << 17)) {

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9048", "0", checkpoints_buf);
      if (tif->tif_dir.td_imagelength == 0U) {
        td->td_stripsperimage = (uint32 )td->td_samplesperpixel;

      } else {


        tmp___0 = TIFFNumberOfStrips(tif);


        td->td_stripsperimage = tmp___0;

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9048", "0", checkpoints_buf);
    } else {


      tmp___0 = TIFFNumberOfStrips(tif);


      td->td_stripsperimage = tmp___0;

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9047", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9047", "17", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9039", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9039", "0", checkpoints_buf);
  td->td_nstrips = td->td_stripsperimage;

  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9055", "2", checkpoints_buf);
  if ((int )td->td_planarconfig == 2) {
    td->td_stripsperimage /= (uint32 )td->td_samplesperpixel;

  } else {

  }
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9055", "2", checkpoints_buf);


  tmp___1 = _TIFFmalloc((tmsize_t )(td->td_nstrips * sizeof(uint64 )));


  td->td_stripoffset = (uint64 *)tmp___1;



  tmp___2 = _TIFFmalloc((tmsize_t )(td->td_nstrips * sizeof(uint64 )));


  td->td_stripbytecount = (uint64 *)tmp___2;

  if ((unsigned int )td->td_stripoffset == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9063", "0", checkpoints_buf);
    return (0);
  } else
  if ((unsigned int )td->td_stripbytecount == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9065", "0", checkpoints_buf);
    return (0);
  } else {

  }

  _TIFFmemset((void *)td->td_stripoffset, 0,
              (tmsize_t )(td->td_nstrips * sizeof(uint64 )));


  _TIFFmemset((void *)td->td_stripbytecount, 0,
              (tmsize_t )(td->td_nstrips * sizeof(uint64 )));

  tif->tif_dir.td_fieldsset[0] |= 1UL << 25;

  tif->tif_dir.td_fieldsset[0] |= 1UL << 24;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9071", "1", checkpoints_buf);
  return (1);
}
}
int TIFFWriteCheck(TIFF *tif , int tiles , char const   *module___4 ) 
{ 
  char const   *tmp ;
  char const   *tmp___0 ;
  int tmp___1 ;

  {

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9072", "0", checkpoints_buf);
  if (tif->tif_mode == 0) {

    TIFFErrorExt(tif->tif_clientdata, module___4, "File not open for writing");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9074", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9072", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tiles);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9076", "tiles", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9076", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9076", "0", checkpoints_buf);
  if (tiles ^ ((tif->tif_flags & 1024U) != 0U)) {
    sprintf(checkpoints_buf, "%d", tiles);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9077", "tiles", checkpoints_buf);
    if (tiles) {
      tmp = "Can not write tiles to a stripped image";

    } else {
      tmp = "Can not write scanlines to a tiled image";

    }
    sprintf(checkpoints_buf, "%d", tiles);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9077", "tiles", checkpoints_buf);

    TIFFErrorExt(tif->tif_clientdata, module___4, tmp);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9081", "0", checkpoints_buf);
    return (0);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tiles);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9076", "tiles", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9076", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9076", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9083", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9083", "1", checkpoints_buf);
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 1))) {

    TIFFErrorExt(tif->tif_clientdata, module___4,
                 "Must set \"ImageWidth\" before writing data");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9085", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9083", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9083", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9087", "1", checkpoints_buf);
  if ((int )tif->tif_dir.td_samplesperpixel == 1) {
    tif->tif_dir.td_planarconfig = (uint16 )1;

  } else {

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9089", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9089", "20", checkpoints_buf);
    if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 20))) {

      TIFFErrorExt(tif->tif_clientdata, module___4,
                   "Must set \"PlanarConfiguration\" before writing data");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9091", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9089", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9089", "20", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9087", "1", checkpoints_buf);
  if ((unsigned int )tif->tif_dir.td_stripoffset == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9094", "tmp___1", checkpoints_buf);

    tmp___1 = TIFFSetupStrips(tif);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9094", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9095", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {
      tif->tif_dir.td_nstrips = (uint32 )0;


      sprintf(checkpoints_buf, "%u", 1024);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9098", "1024", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9098", "0", checkpoints_buf);
      if ((tif->tif_flags & 1024U) != 0U) {
        tmp___0 = "tile";

      } else {
        tmp___0 = "strip";

      }

      sprintf(checkpoints_buf, "%u", 1024);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9098", "1024", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9098", "0", checkpoints_buf);

      TIFFErrorExt(tif->tif_clientdata, module___4, "No space for %s arrays",
                   tmp___0);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9102", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9095", "tmp___1", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9104", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9104", "0", checkpoints_buf);
  if ((tif->tif_flags & 1024U) != 0U) {


    tif->tif_tilesize = TIFFTileSize(tif);



    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9106", "0", checkpoints_buf);
    if (tif->tif_tilesize == 0L) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9107", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9106", "0", checkpoints_buf);
  } else {
    tif->tif_tilesize = (tmsize_t )-1;

  }

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9104", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9104", "0", checkpoints_buf);


  tif->tif_scanlinesize = TIFFScanlineSize(tif);



  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9111", "0", checkpoints_buf);
  if (tif->tif_scanlinesize == 0L) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9112", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9111", "0", checkpoints_buf);
  tif->tif_flags |= 64U;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9115", "1", checkpoints_buf);
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

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9117", "512", checkpoints_buf);
    if (tif->tif_flags & 512U) {

      _TIFFfree((void *)tif->tif_rawdata);

      tif->tif_flags &= 4294966783U;

    } else {

    }

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9117", "512", checkpoints_buf);
    tif->tif_rawdata = (uint8 *)((void *)0);

  } else {

  }


  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9123", "-1", checkpoints_buf);
  if (size == -1L) {

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9124", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9124", "0", checkpoints_buf);
    if ((tif->tif_flags & 1024U) != 0U) {
      size = tif->tif_tilesize;

    } else {


      tmp = TIFFStripSize(tif);


      size = tmp;

    }

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9124", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9124", "0", checkpoints_buf);

    sprintf(checkpoints_buf, "%ld", 8192);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9128", "8192", checkpoints_buf);
    if (size < 8192L) {
      size = (tmsize_t )8192;

    } else {

    }

    sprintf(checkpoints_buf, "%ld", 8192);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9128", "8192", checkpoints_buf);
    bp = (void *)0;

  } else {

  }

  sprintf(checkpoints_buf, "%ld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9123", "-1", checkpoints_buf);
  if ((unsigned int )bp == (unsigned int )((void *)0)) {


    bp = _TIFFmalloc(size);


    if ((unsigned int )bp == (unsigned int )((void *)0)) {

      TIFFErrorExt(tif->tif_clientdata, module___4, "No space for output buffer");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9137", "0", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9146", "1", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9148", "1", checkpoints_buf);
  if ((int )td->td_planarconfig == 1) {

  } else {

    __assert_fail("td->td_planarconfig == 1", "tif_write.c", 598U,
                  "TIFFGrowStrips");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9148", "1", checkpoints_buf);


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

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9166", "0", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9173", "1", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9175", "0", checkpoints_buf);
  if (*(td->td_stripoffset + strip) == 0ULL) {
    goto _L;
  } else {

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9177", "0", checkpoints_buf);
    if (tif->tif_curoff == 0ULL) {

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9178", "0", checkpoints_buf);
      _L: /* CIL Label */ 
      if (td->td_nstrips > 0U) {

      } else {

        __assert_fail("td->td_nstrips > 0", "tif_write.c", 633U,
                      "TIFFAppendToStrip");

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9178", "0", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9181", "0", checkpoints_buf);
      if (*(td->td_stripbytecount + strip) != 0ULL) {

        sprintf(checkpoints_buf, "%llu", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "9182", "0", checkpoints_buf);
        if (*(td->td_stripoffset + strip) != 0ULL) {

          if (*(td->td_stripbytecount + strip) >= (uint64 )cc) {


            tmp = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                         *(td->td_stripoffset + strip), 0);




            if (tmp == *(td->td_stripoffset + strip)) {

            } else {

              TIFFErrorExt(tif->tif_clientdata, module___5,
                           "Seek error at scanline %lu",
                           (unsigned long )tif->tif_row);

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "9188", "0", checkpoints_buf);
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

        sprintf(checkpoints_buf, "%llu", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "9182", "0", checkpoints_buf);
      } else {


        *(td->td_stripoffset + strip) = (*(tif->tif_seekproc))(tif->tif_clientdata,
                                                               (uint64 )0, 2);


      }

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9181", "0", checkpoints_buf);
      tif->tif_curoff = *(td->td_stripoffset + strip);

      *(td->td_stripbytecount + strip) = (uint64 )0;

    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9177", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9175", "0", checkpoints_buf);
  m = tif->tif_curoff + (uint64 )cc;


  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9196", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    m = (uint64 )((uint32 )m);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9196", "524288", checkpoints_buf);


  if (m < tif->tif_curoff) {

    TIFFErrorExt(tif->tif_clientdata, module___5,
                 "Maximum TIFF file size exceeded");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9201", "0", checkpoints_buf);
    return (0);
  } else {

    if (m < (uint64 )cc) {

      TIFFErrorExt(tif->tif_clientdata, module___5,
                   "Maximum TIFF file size exceeded");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9204", "0", checkpoints_buf);
      return (0);
    } else {

    }

  }




  tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)data, cc);




  if (tmp___0 == cc) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, module___5, "Write error at scanline %lu",
                 (unsigned long )tif->tif_row);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9210", "0", checkpoints_buf);
    return (0);
  }


  tif->tif_curoff = m;

  *(td->td_stripbytecount + strip) += (uint64 )cc;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9213", "1", checkpoints_buf);
  return (1);
}
}
int TIFFFlushData1(TIFF *tif ) 
{ 
  uint32 tmp ;
  int tmp___0 ;

  {

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9214", "0", checkpoints_buf);
  if (tif->tif_rawcc > 0L) {

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9215", "0", checkpoints_buf);
    if (! ((tif->tif_flags & (unsigned int )tif->tif_dir.td_fillorder) != 0U)) {

      sprintf(checkpoints_buf, "%u", 256);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9216", "256", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9216", "0", checkpoints_buf);
      if ((tif->tif_flags & 256U) == 0U) {

        TIFFReverseBits(tif->tif_rawdata, tif->tif_rawcc);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 256);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9216", "256", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9216", "0", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9215", "0", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9220", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9220", "0", checkpoints_buf);
    if ((tif->tif_flags & 1024U) != 0U) {
      tmp = tif->tif_curtile;

    } else {
      tmp = tif->tif_curstrip;

    }

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9220", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9220", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9223", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFAppendToStrip(tif, tmp, tif->tif_rawdata, tif->tif_rawcc);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9223", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9224", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "9226", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "9224", "tmp___0", checkpoints_buf);
    tif->tif_rawcc = (tmsize_t )0;

    tif->tif_rawcp = tif->tif_rawdata;

  } else {

  }

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9214", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "9230", "1", checkpoints_buf);
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
