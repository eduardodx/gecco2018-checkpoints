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
enum TIFFReadDirEntryErr {
    TIFFReadDirEntryErrOk = 0,
    TIFFReadDirEntryErrCount = 1,
    TIFFReadDirEntryErrType = 2,
    TIFFReadDirEntryErrIo = 3,
    TIFFReadDirEntryErrRange = 4,
    TIFFReadDirEntryErrPsdif = 5,
    TIFFReadDirEntryErrSizesan = 6,
    TIFFReadDirEntryErrAlloc = 7
} ;
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
int TIFFReadDirectory(TIFF *tif ) ;
int TIFFReadCustomDirectory(TIFF *tif , uint64 diroff ,
                            TIFFFieldArray const   *infoarray ) ;
int TIFFReadEXIFDirectory(TIFF *tif , uint64 diroff ) ;
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
static enum TIFFReadDirEntryErr TIFFReadDirEntryByte(TIFF *tif ,
                                                     TIFFDirEntry *direntry ,
                                                     uint8 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryShort(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      uint16 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryLong(TIFF *tif ,
                                                     TIFFDirEntry *direntry ,
                                                     uint32 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryLong8(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      uint64 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryFloat(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      float *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryDouble(TIFF *tif ,
                                                       TIFFDirEntry *direntry ,
                                                       double *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryIfd8(TIFF *tif ,
                                                     TIFFDirEntry *direntry ,
                                                     uint64 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryArray(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      uint32 *count ,
                                                      uint32 desttypesize ,
                                                      void **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryByteArray(TIFF *tif ,
                                                          TIFFDirEntry *direntry ,
                                                          uint8 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntrySbyteArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           int8 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryShortArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           uint16 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntrySshortArray(TIFF *tif ,
                                                            TIFFDirEntry *direntry ,
                                                            int16 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryLongArray(TIFF *tif ,
                                                          TIFFDirEntry *direntry ,
                                                          uint32 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntrySlongArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           int32 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryLong8Array(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           uint64 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntrySlong8Array(TIFF *tif ,
                                                            TIFFDirEntry *direntry ,
                                                            int64 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryFloatArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           float **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryDoubleArray(TIFF *tif ,
                                                            TIFFDirEntry *direntry ,
                                                            double **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryIfd8Array(TIFF *tif ,
                                                          TIFFDirEntry *direntry ,
                                                          uint64 **value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryPersampleShort(TIFF *tif ,
                                                               TIFFDirEntry *direntry ,
                                                               uint16 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryPersampleDouble(TIFF *tif ,
                                                                TIFFDirEntry *direntry ,
                                                                double *value ) ;
static void TIFFReadDirEntryCheckedByte(TIFF *tif , TIFFDirEntry *direntry ,
                                        uint8 *value ) ;
static void TIFFReadDirEntryCheckedSbyte(TIFF *tif , TIFFDirEntry *direntry ,
                                         int8 *value ) ;
static void TIFFReadDirEntryCheckedShort(TIFF *tif , TIFFDirEntry *direntry ,
                                         uint16 *value ) ;
static void TIFFReadDirEntryCheckedSshort(TIFF *tif , TIFFDirEntry *direntry ,
                                          int16 *value ) ;
static void TIFFReadDirEntryCheckedLong(TIFF *tif , TIFFDirEntry *direntry ,
                                        uint32 *value ) ;
static void TIFFReadDirEntryCheckedSlong(TIFF *tif , TIFFDirEntry *direntry ,
                                         int32 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedLong8(TIFF *tif ,
                                                             TIFFDirEntry *direntry ,
                                                             uint64 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedSlong8(TIFF *tif ,
                                                              TIFFDirEntry *direntry ,
                                                              int64 *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedRational(TIFF *tif ,
                                                                TIFFDirEntry *direntry ,
                                                                double *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedSrational(TIFF *tif ,
                                                                 TIFFDirEntry *direntry ,
                                                                 double *value ) ;
static void TIFFReadDirEntryCheckedFloat(TIFF *tif , TIFFDirEntry *direntry ,
                                         float *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedDouble(TIFF *tif ,
                                                              TIFFDirEntry *direntry ,
                                                              double *value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSbyte(int8 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteShort(uint16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSshort(int16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteLong(uint32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSlong(int32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteLong8(uint64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSlong8(int64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteByte(uint8 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteShort(uint16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteSshort(int16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteLong(uint32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteSlong(int32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteLong8(uint64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteSlong8(int64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSbyte(int8 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSshort(int16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortLong(uint32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSlong(int32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortLong8(uint64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSlong8(int64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortShort(uint16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortLong(uint32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortSlong(int32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortLong8(uint64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortSlong8(int64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSbyte(int8 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSshort(int16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSlong(int32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongLong8(uint64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSlong8(int64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlongLong(uint32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlongLong8(uint64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlongSlong8(int64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Sbyte(int8 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Sshort(int16 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Slong(int32 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Slong8(int64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlong8Long8(uint64 value ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryData(TIFF *tif , uint64 offset ,
                                                     tmsize_t size , void *dest ) ;
static void TIFFReadDirEntryOutputErr(TIFF *tif , enum TIFFReadDirEntryErr err ,
                                      char const   *module ,
                                      char const   *tagname , int recover ) ;
static void TIFFReadDirectoryCheckOrder(TIFF *tif , TIFFDirEntry *dir ,
                                        uint16 dircount ) ;
static TIFFDirEntry *TIFFReadDirectoryFindEntry(TIFF *tif , TIFFDirEntry *dir ,
                                                uint16 dircount , uint16 tagid ) ;
static void TIFFReadDirectoryFindFieldInfo(TIFF *tif , uint16 tagid ,
                                           uint32 *fii ) ;
static int EstimateStripByteCounts(TIFF *tif , TIFFDirEntry *dir ,
                                   uint16 dircount ) ;
static void MissingRequired(TIFF *tif , char const   *tagname ) ;
static int TIFFCheckDirOffset(TIFF *tif , uint64 diroff ) ;
static int CheckDirCount(TIFF *tif , TIFFDirEntry *dir , uint32 count ) ;
static uint16 TIFFFetchDirectory(TIFF *tif , uint64 diroff ,
                                 TIFFDirEntry **pdir , uint64 *nextdiroff ) ;
static int TIFFFetchNormalTag(TIFF *tif , TIFFDirEntry *dp , int recover ) ;
static int TIFFFetchStripThing(TIFF *tif , TIFFDirEntry *dir , uint32 nstrips ,
                               uint64 **lpp ) ;
static int TIFFFetchSubjectDistance(TIFF *tif , TIFFDirEntry *dir ) ;
static void ChopUpSingleUncompressedStrip(TIFF *tif ) ;
static enum TIFFReadDirEntryErr TIFFReadDirEntryByte(TIFF *tif ,
                                                     TIFFDirEntry *direntry ,
                                                     uint8 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  int8 m ;
  uint16 m___0 ;
  int16 m___1 ;
  uint32 m___2 ;
  int32 m___3 ;
  uint64 m___4 ;
  int64 m___5 ;

  {

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1674", "1", checkpoints_buf);
  if (direntry->tdir_count != 1ULL) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1674", "1", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  case 1: 
  TIFFReadDirEntryCheckedByte(tif, direntry, value);

  return ((enum TIFFReadDirEntryErr )0);

  case 6: 
  TIFFReadDirEntryCheckedSbyte(tif, direntry, & m);



  err = TIFFReadDirEntryCheckRangeByteSbyte(m);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1682", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1682", "0", checkpoints_buf);
  *value = (uint8 )m;

  return ((enum TIFFReadDirEntryErr )0);

  case 3: 
  TIFFReadDirEntryCheckedShort(tif, direntry, & m___0);



  err = TIFFReadDirEntryCheckRangeByteShort(m___0);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1689", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1689", "0", checkpoints_buf);
  *value = (uint8 )m___0;

  return ((enum TIFFReadDirEntryErr )0);

  case 8: 
  TIFFReadDirEntryCheckedSshort(tif, direntry, & m___1);



  err = TIFFReadDirEntryCheckRangeByteSshort(m___1);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1696", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1696", "0", checkpoints_buf);
  *value = (uint8 )m___1;

  return ((enum TIFFReadDirEntryErr )0);

  case 4: 
  TIFFReadDirEntryCheckedLong(tif, direntry, & m___2);



  err = TIFFReadDirEntryCheckRangeByteLong(m___2);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1703", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1703", "0", checkpoints_buf);
  *value = (uint8 )m___2;

  return ((enum TIFFReadDirEntryErr )0);

  case 9: 
  TIFFReadDirEntryCheckedSlong(tif, direntry, & m___3);



  err = TIFFReadDirEntryCheckRangeByteSlong(m___3);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1710", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1710", "0", checkpoints_buf);
  *value = (uint8 )m___3;

  return ((enum TIFFReadDirEntryErr )0);


  case 16: 
  err = TIFFReadDirEntryCheckedLong8(tif, direntry, & m___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1716", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1716", "0", checkpoints_buf);


  err = TIFFReadDirEntryCheckRangeByteLong8(m___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1720", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1720", "0", checkpoints_buf);
  *value = (uint8 )m___4;

  return ((enum TIFFReadDirEntryErr )0);


  case 17: 
  err = TIFFReadDirEntryCheckedSlong8(tif, direntry, & m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1726", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1726", "0", checkpoints_buf);


  err = TIFFReadDirEntryCheckRangeByteSlong8(m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1730", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1730", "0", checkpoints_buf);
  *value = (uint8 )m___5;

  return ((enum TIFFReadDirEntryErr )0);
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryShort(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      uint16 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint8 m ;
  int8 m___0 ;
  int16 m___1 ;
  uint32 m___2 ;
  int32 m___3 ;
  uint64 m___4 ;
  int64 m___5 ;

  {

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1736", "1", checkpoints_buf);
  if (direntry->tdir_count != 1ULL) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1736", "1", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  case 1: 
  TIFFReadDirEntryCheckedByte(tif, direntry, & m);

  *value = (uint16 )m;

  return ((enum TIFFReadDirEntryErr )0);

  case 6: 
  TIFFReadDirEntryCheckedSbyte(tif, direntry, & m___0);



  err = TIFFReadDirEntryCheckRangeShortSbyte(m___0);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1745", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1745", "0", checkpoints_buf);
  *value = (uint16 )m___0;

  return ((enum TIFFReadDirEntryErr )0);

  case 3: 
  TIFFReadDirEntryCheckedShort(tif, direntry, value);

  return ((enum TIFFReadDirEntryErr )0);

  case 8: 
  TIFFReadDirEntryCheckedSshort(tif, direntry, & m___1);



  err = TIFFReadDirEntryCheckRangeShortSshort(m___1);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1754", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1754", "0", checkpoints_buf);
  *value = (uint16 )m___1;

  return ((enum TIFFReadDirEntryErr )0);

  case 4: 
  TIFFReadDirEntryCheckedLong(tif, direntry, & m___2);



  err = TIFFReadDirEntryCheckRangeShortLong(m___2);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1761", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1761", "0", checkpoints_buf);
  *value = (uint16 )m___2;

  return ((enum TIFFReadDirEntryErr )0);

  case 9: 
  TIFFReadDirEntryCheckedSlong(tif, direntry, & m___3);



  err = TIFFReadDirEntryCheckRangeShortSlong(m___3);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1768", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1768", "0", checkpoints_buf);
  *value = (uint16 )m___3;

  return ((enum TIFFReadDirEntryErr )0);


  case 16: 
  err = TIFFReadDirEntryCheckedLong8(tif, direntry, & m___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1774", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1774", "0", checkpoints_buf);


  err = TIFFReadDirEntryCheckRangeShortLong8(m___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1778", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1778", "0", checkpoints_buf);
  *value = (uint16 )m___4;

  return ((enum TIFFReadDirEntryErr )0);


  case 17: 
  err = TIFFReadDirEntryCheckedSlong8(tif, direntry, & m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1784", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1784", "0", checkpoints_buf);


  err = TIFFReadDirEntryCheckRangeShortSlong8(m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1788", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1788", "0", checkpoints_buf);
  *value = (uint16 )m___5;

  return ((enum TIFFReadDirEntryErr )0);
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryLong(TIFF *tif ,
                                                     TIFFDirEntry *direntry ,
                                                     uint32 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint8 m ;
  int8 m___0 ;
  uint16 m___1 ;
  int16 m___2 ;
  int32 m___3 ;
  uint64 m___4 ;
  int64 m___5 ;

  {

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1794", "1", checkpoints_buf);
  if (direntry->tdir_count != 1ULL) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1794", "1", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  case 1: 
  TIFFReadDirEntryCheckedByte(tif, direntry, & m);

  *value = (uint32 )m;

  return ((enum TIFFReadDirEntryErr )0);

  case 6: 
  TIFFReadDirEntryCheckedSbyte(tif, direntry, & m___0);



  err = TIFFReadDirEntryCheckRangeLongSbyte(m___0);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1803", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1803", "0", checkpoints_buf);
  *value = (uint32 )m___0;

  return ((enum TIFFReadDirEntryErr )0);

  case 3: 
  TIFFReadDirEntryCheckedShort(tif, direntry, & m___1);

  *value = (uint32 )m___1;

  return ((enum TIFFReadDirEntryErr )0);

  case 8: 
  TIFFReadDirEntryCheckedSshort(tif, direntry, & m___2);



  err = TIFFReadDirEntryCheckRangeLongSshort(m___2);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1813", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1813", "0", checkpoints_buf);
  *value = (uint32 )m___2;

  return ((enum TIFFReadDirEntryErr )0);

  case 4: 
  TIFFReadDirEntryCheckedLong(tif, direntry, value);

  return ((enum TIFFReadDirEntryErr )0);

  case 9: 
  TIFFReadDirEntryCheckedSlong(tif, direntry, & m___3);



  err = TIFFReadDirEntryCheckRangeLongSlong(m___3);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1822", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1822", "0", checkpoints_buf);
  *value = (uint32 )m___3;

  return ((enum TIFFReadDirEntryErr )0);


  case 16: 
  err = TIFFReadDirEntryCheckedLong8(tif, direntry, & m___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1828", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1828", "0", checkpoints_buf);


  err = TIFFReadDirEntryCheckRangeLongLong8(m___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1832", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1832", "0", checkpoints_buf);
  *value = (uint32 )m___4;

  return ((enum TIFFReadDirEntryErr )0);


  case 17: 
  err = TIFFReadDirEntryCheckedSlong8(tif, direntry, & m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1838", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1838", "0", checkpoints_buf);


  err = TIFFReadDirEntryCheckRangeLongSlong8(m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1842", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1842", "0", checkpoints_buf);
  *value = (uint32 )m___5;

  return ((enum TIFFReadDirEntryErr )0);
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryLong8(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      uint64 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint8 m ;
  int8 m___0 ;
  uint16 m___1 ;
  int16 m___2 ;
  uint32 m___3 ;
  int32 m___4 ;
  int64 m___5 ;

  {

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1848", "1", checkpoints_buf);
  if (direntry->tdir_count != 1ULL) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1848", "1", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  case 1: 
  TIFFReadDirEntryCheckedByte(tif, direntry, & m);

  *value = (uint64 )m;

  return ((enum TIFFReadDirEntryErr )0);

  case 6: 
  TIFFReadDirEntryCheckedSbyte(tif, direntry, & m___0);



  err = TIFFReadDirEntryCheckRangeLong8Sbyte(m___0);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1857", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1857", "0", checkpoints_buf);
  *value = (uint64 )m___0;

  return ((enum TIFFReadDirEntryErr )0);

  case 3: 
  TIFFReadDirEntryCheckedShort(tif, direntry, & m___1);

  *value = (uint64 )m___1;

  return ((enum TIFFReadDirEntryErr )0);

  case 8: 
  TIFFReadDirEntryCheckedSshort(tif, direntry, & m___2);



  err = TIFFReadDirEntryCheckRangeLong8Sshort(m___2);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1867", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1867", "0", checkpoints_buf);
  *value = (uint64 )m___2;

  return ((enum TIFFReadDirEntryErr )0);

  case 4: 
  TIFFReadDirEntryCheckedLong(tif, direntry, & m___3);

  *value = (uint64 )m___3;

  return ((enum TIFFReadDirEntryErr )0);

  case 9: 
  TIFFReadDirEntryCheckedSlong(tif, direntry, & m___4);



  err = TIFFReadDirEntryCheckRangeLong8Slong(m___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1877", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1877", "0", checkpoints_buf);
  *value = (uint64 )m___4;

  return ((enum TIFFReadDirEntryErr )0);


  case 16: 
  err = TIFFReadDirEntryCheckedLong8(tif, direntry, value);



  return (err);


  case 17: 
  err = TIFFReadDirEntryCheckedSlong8(tif, direntry, & m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1885", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1885", "0", checkpoints_buf);


  err = TIFFReadDirEntryCheckRangeLong8Slong8(m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1889", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1889", "0", checkpoints_buf);
  *value = (uint64 )m___5;

  return ((enum TIFFReadDirEntryErr )0);
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryFloat(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      float *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint8 m ;
  int8 m___0 ;
  uint16 m___1 ;
  int16 m___2 ;
  uint32 m___3 ;
  int32 m___4 ;
  uint64 m___5 ;
  int64 m___6 ;
  double m___7 ;
  double m___8 ;
  double m___9 ;

  {

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1895", "1", checkpoints_buf);
  if (direntry->tdir_count != 1ULL) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1895", "1", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  case 1: 
  TIFFReadDirEntryCheckedByte(tif, direntry, & m);

  *value = (float )m;

  return ((enum TIFFReadDirEntryErr )0);

  case 6: 
  TIFFReadDirEntryCheckedSbyte(tif, direntry, & m___0);

  *value = (float )m___0;

  return ((enum TIFFReadDirEntryErr )0);

  case 3: 
  TIFFReadDirEntryCheckedShort(tif, direntry, & m___1);

  *value = (float )m___1;

  return ((enum TIFFReadDirEntryErr )0);

  case 8: 
  TIFFReadDirEntryCheckedSshort(tif, direntry, & m___2);

  *value = (float )m___2;

  return ((enum TIFFReadDirEntryErr )0);

  case 4: 
  TIFFReadDirEntryCheckedLong(tif, direntry, & m___3);

  *value = (float )m___3;

  return ((enum TIFFReadDirEntryErr )0);

  case 9: 
  TIFFReadDirEntryCheckedSlong(tif, direntry, & m___4);

  *value = (float )m___4;

  return ((enum TIFFReadDirEntryErr )0);


  case 16: 
  err = TIFFReadDirEntryCheckedLong8(tif, direntry, & m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1918", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1918", "0", checkpoints_buf);
  *value = (float )m___5;

  return ((enum TIFFReadDirEntryErr )0);


  case 17: 
  err = TIFFReadDirEntryCheckedSlong8(tif, direntry, & m___6);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1924", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1924", "0", checkpoints_buf);
  *value = (float )m___6;

  return ((enum TIFFReadDirEntryErr )0);


  case 5: 
  err = TIFFReadDirEntryCheckedRational(tif, direntry, & m___7);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1930", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1930", "0", checkpoints_buf);
  *value = (float )m___7;

  return ((enum TIFFReadDirEntryErr )0);


  case 10: 
  err = TIFFReadDirEntryCheckedSrational(tif, direntry, & m___8);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1936", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1936", "0", checkpoints_buf);
  *value = (float )m___8;

  return ((enum TIFFReadDirEntryErr )0);

  case 11: 
  TIFFReadDirEntryCheckedFloat(tif, direntry, value);

  return ((enum TIFFReadDirEntryErr )0);


  case 12: 
  err = TIFFReadDirEntryCheckedDouble(tif, direntry, & m___9);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1944", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1944", "0", checkpoints_buf);
  *value = (float )m___9;

  return ((enum TIFFReadDirEntryErr )0);
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryDouble(TIFF *tif ,
                                                       TIFFDirEntry *direntry ,
                                                       double *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint8 m ;
  int8 m___0 ;
  uint16 m___1 ;
  int16 m___2 ;
  uint32 m___3 ;
  int32 m___4 ;
  uint64 m___5 ;
  int64 m___6 ;
  float m___7 ;

  {

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1950", "1", checkpoints_buf);
  if (direntry->tdir_count != 1ULL) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1950", "1", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  case 1: 
  TIFFReadDirEntryCheckedByte(tif, direntry, & m);

  *value = (double )m;

  return ((enum TIFFReadDirEntryErr )0);

  case 6: 
  TIFFReadDirEntryCheckedSbyte(tif, direntry, & m___0);

  *value = (double )m___0;

  return ((enum TIFFReadDirEntryErr )0);

  case 3: 
  TIFFReadDirEntryCheckedShort(tif, direntry, & m___1);

  *value = (double )m___1;

  return ((enum TIFFReadDirEntryErr )0);

  case 8: 
  TIFFReadDirEntryCheckedSshort(tif, direntry, & m___2);

  *value = (double )m___2;

  return ((enum TIFFReadDirEntryErr )0);

  case 4: 
  TIFFReadDirEntryCheckedLong(tif, direntry, & m___3);

  *value = (double )m___3;

  return ((enum TIFFReadDirEntryErr )0);

  case 9: 
  TIFFReadDirEntryCheckedSlong(tif, direntry, & m___4);

  *value = (double )m___4;

  return ((enum TIFFReadDirEntryErr )0);


  case 16: 
  err = TIFFReadDirEntryCheckedLong8(tif, direntry, & m___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1973", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1973", "0", checkpoints_buf);
  *value = (double )m___5;

  return ((enum TIFFReadDirEntryErr )0);


  case 17: 
  err = TIFFReadDirEntryCheckedSlong8(tif, direntry, & m___6);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1979", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1979", "0", checkpoints_buf);
  *value = (double )m___6;

  return ((enum TIFFReadDirEntryErr )0);


  case 5: 
  err = TIFFReadDirEntryCheckedRational(tif, direntry, value);



  return (err);


  case 10: 
  err = TIFFReadDirEntryCheckedSrational(tif, direntry, value);



  return (err);

  case 11: 
  TIFFReadDirEntryCheckedFloat(tif, direntry, & m___7);

  *value = (double )m___7;

  return ((enum TIFFReadDirEntryErr )0);


  case 12: 
  err = TIFFReadDirEntryCheckedDouble(tif, direntry, value);



  return (err);
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryIfd8(TIFF *tif ,
                                                     TIFFDirEntry *direntry ,
                                                     uint64 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 m ;

  {

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1994", "1", checkpoints_buf);
  if (direntry->tdir_count != 1ULL) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1994", "1", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  case 13: 
  case 4: 
  TIFFReadDirEntryCheckedLong(tif, direntry, & m);

  *value = (uint64 )m;

  return ((enum TIFFReadDirEntryErr )0);


  case 18: 
  case 16: 
  err = TIFFReadDirEntryCheckedLong8(tif, direntry, value);



  return (err);
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryArray(TIFF *tif ,
                                                      TIFFDirEntry *direntry ,
                                                      uint32 *count ,
                                                      uint32 desttypesize ,
                                                      void **value ) 
{ 
  int typesize ;
  uint32 datasize ;
  void *data ;
  enum TIFFReadDirEntryErr err ;
  uint32 offset ;
  enum TIFFReadDirEntryErr err___0 ;
  uint64 offset___0 ;

  {
  sprintf(checkpoints_buf, "%d", typesize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2004", "typesize", checkpoints_buf);

  typesize = TIFFDataWidth((TIFFDataType )direntry->tdir_type);
  sprintf(checkpoints_buf, "%d", typesize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2004", "typesize", checkpoints_buf);


  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2005", "0", checkpoints_buf);
  if (direntry->tdir_count == 0ULL) {
    *value = (void *)0;

    return ((enum TIFFReadDirEntryErr )0);
  } else {
    sprintf(checkpoints_buf, "%d", typesize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2008", "typesize", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2008", "0", checkpoints_buf);
    if (typesize == 0) {
      *value = (void *)0;

      return ((enum TIFFReadDirEntryErr )0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", typesize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2008", "typesize", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2008", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2005", "0", checkpoints_buf);

  if ((uint64 )(4194304 / typesize) < direntry->tdir_count) {
    return ((enum TIFFReadDirEntryErr )6);
  } else {

  }


  if ((uint64 )(4194304U / desttypesize) < direntry->tdir_count) {
    return ((enum TIFFReadDirEntryErr )6);
  } else {

  }

  *count = (uint32 )direntry->tdir_count;

  datasize = *count * (uint32 )typesize;

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2020", "0", checkpoints_buf);
  if ((tmsize_t )datasize > 0L) {

  } else {

    __assert_fail("(tmsize_t)datasize>0", "tif_dirread.c", 732U,
                  "TIFFReadDirEntryArray");

  }
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2020", "0", checkpoints_buf);


  data = _TIFFmalloc((tmsize_t )datasize);


  if ((unsigned int )data == (unsigned int )((void *)0)) {
    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2027", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {

    sprintf(checkpoints_buf, "%u", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2028", "4", checkpoints_buf);
    if (datasize <= 4U) {

      _TIFFmemcpy(data, (void const   *)(& direntry->tdir_offset),
                  (tmsize_t )datasize);

    } else {
      offset = *((uint32 *)(& direntry->tdir_offset));


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2031", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong(& offset);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2031", "128", checkpoints_buf);


      err = TIFFReadDirEntryData(tif, (uint64 )offset, (tmsize_t )datasize, data);


      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2035", "0", checkpoints_buf);
      if ((unsigned int )err != 0U) {

        _TIFFfree(data);


        return (err);
      } else {

      }
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2035", "0", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2028", "4", checkpoints_buf);
  } else {

    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2039", "8", checkpoints_buf);
    if (datasize <= 8U) {

      _TIFFmemcpy(data, (void const   *)(& direntry->tdir_offset),
                  (tmsize_t )datasize);

    } else {
      offset___0 = direntry->tdir_offset;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2042", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& offset___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2042", "128", checkpoints_buf);


      err___0 = TIFFReadDirEntryData(tif, offset___0, (tmsize_t )datasize, data);


      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2046", "0", checkpoints_buf);
      if ((unsigned int )err___0 != 0U) {

        _TIFFfree(data);


        return (err___0);
      } else {

      }
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "2046", "0", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2039", "8", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2027", "524288", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryByteArray(TIFF *tif ,
                                                          TIFFDirEntry *direntry ,
                                                          uint8 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  uint8 *data ;
  int8 *m ;
  uint32 n ;
  void *tmp ;
  uint16 *ma ;
  uint8 *mb ;
  uint32 n___0 ;
  uint8 *tmp___0 ;
  uint16 *tmp___1 ;
  int16 *ma___0 ;
  uint8 *mb___0 ;
  uint32 n___1 ;
  uint8 *tmp___2 ;
  int16 *tmp___3 ;
  uint32 *ma___1 ;
  uint8 *mb___1 ;
  uint32 n___2 ;
  uint8 *tmp___4 ;
  uint32 *tmp___5 ;
  int32 *ma___2 ;
  uint8 *mb___2 ;
  uint32 n___3 ;
  uint8 *tmp___6 ;
  int32 *tmp___7 ;
  uint64 *ma___3 ;
  uint8 *mb___3 ;
  uint32 n___4 ;
  uint8 *tmp___8 ;
  uint64 *tmp___9 ;
  int64 *ma___4 ;
  uint8 *mb___4 ;
  uint32 n___5 ;
  uint8 *tmp___10 ;
  int64 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  case 7: 
  case 2: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )1, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2056", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (uint8 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (uint8 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2056", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 1: 
  case 7: 
  case 2: 
  *value = (uint8 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  case 6: 
  m = (int8 *)origdata;

  n = (uint32 )0;





  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2068", "0", checkpoints_buf);


  while (n < count) {




    err = TIFFReadDirEntryCheckRangeByteSbyte(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2073", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2073", "0", checkpoints_buf);
    m ++;

    n ++;

  }




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2068", "0", checkpoints_buf);


  *value = (uint8 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )count);


  data = (uint8 *)tmp;

  if ((unsigned int )data == (unsigned int )((uint8 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 3: 
  ma = (uint16 *)origdata;

  mb = data;

  n___0 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2091", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2091", "0", checkpoints_buf);






  while (n___0 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2095", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2095", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeByteShort(*ma);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2099", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2099", "0", checkpoints_buf);
    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (uint8 )*tmp___1;

    n___0 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2091", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2091", "0", checkpoints_buf);






  break;
  case 8: 
  ma___0 = (int16 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2112", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2112", "0", checkpoints_buf);






  while (n___1 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2116", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___0);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2116", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeByteSshort(*ma___0);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2120", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2120", "0", checkpoints_buf);
    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (uint8 )*tmp___3;

    n___1 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2112", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2112", "0", checkpoints_buf);






  break;
  case 4: 
  ma___1 = (uint32 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2133", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2133", "0", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2137", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2137", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeByteLong(*ma___1);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2141", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2141", "0", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (uint8 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2133", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2133", "0", checkpoints_buf);






  break;
  case 9: 
  ma___2 = (int32 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2154", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2154", "0", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2158", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2158", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeByteSlong(*ma___2);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2162", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2162", "0", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (uint8 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2154", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2154", "0", checkpoints_buf);






  break;
  case 16: 
  ma___3 = (uint64 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2175", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2175", "0", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2179", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2179", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeByteLong8(*ma___3);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2183", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2183", "0", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (uint8 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2175", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2175", "0", checkpoints_buf);






  break;
  case 17: 
  ma___4 = (int64 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2196", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2196", "0", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2200", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2200", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeByteSlong8(*ma___4);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2204", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2204", "0", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (uint8 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2196", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2196", "0", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2215", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2215", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntrySbyteArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           int8 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  int8 *data ;
  uint8 *m ;
  uint32 n ;
  void *tmp ;
  uint16 *ma ;
  int8 *mb ;
  uint32 n___0 ;
  int8 *tmp___0 ;
  uint16 *tmp___1 ;
  int16 *ma___0 ;
  int8 *mb___0 ;
  uint32 n___1 ;
  int8 *tmp___2 ;
  int16 *tmp___3 ;
  uint32 *ma___1 ;
  int8 *mb___1 ;
  uint32 n___2 ;
  int8 *tmp___4 ;
  uint32 *tmp___5 ;
  int32 *ma___2 ;
  int8 *mb___2 ;
  uint32 n___3 ;
  int8 *tmp___6 ;
  int32 *tmp___7 ;
  uint64 *ma___3 ;
  int8 *mb___3 ;
  uint32 n___4 ;
  int8 *tmp___8 ;
  uint64 *tmp___9 ;
  int64 *ma___4 ;
  int8 *mb___4 ;
  uint32 n___5 ;
  int8 *tmp___10 ;
  int64 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  case 7: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )1, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2225", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (int8 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (int8 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2225", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 1: 
  case 7: 
  m = (uint8 *)origdata;

  n = (uint32 )0;





  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2235", "0", checkpoints_buf);


  while (n < count) {




    err = TIFFReadDirEntryCheckRangeSbyteByte(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2240", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2240", "0", checkpoints_buf);
    m ++;

    n ++;

  }




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2235", "0", checkpoints_buf);


  *value = (int8 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  case 6: 
  *value = (int8 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )count);


  data = (int8 *)tmp;

  if ((unsigned int )data == (unsigned int )((int8 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 3: 
  ma = (uint16 *)origdata;

  mb = data;

  n___0 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2260", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2260", "0", checkpoints_buf);






  while (n___0 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2264", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2264", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSbyteShort(*ma);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2268", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2268", "0", checkpoints_buf);
    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (int8 )*tmp___1;

    n___0 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2260", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2260", "0", checkpoints_buf);






  break;
  case 8: 
  ma___0 = (int16 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2281", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2281", "0", checkpoints_buf);






  while (n___1 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2285", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___0);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2285", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSbyteSshort(*ma___0);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2289", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2289", "0", checkpoints_buf);
    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (int8 )*tmp___3;

    n___1 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2281", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2281", "0", checkpoints_buf);






  break;
  case 4: 
  ma___1 = (uint32 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2302", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2302", "0", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2306", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2306", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSbyteLong(*ma___1);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2310", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2310", "0", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (int8 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2302", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2302", "0", checkpoints_buf);






  break;
  case 9: 
  ma___2 = (int32 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2323", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2323", "0", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2327", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2327", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSbyteSlong(*ma___2);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2331", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2331", "0", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (int8 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2323", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2323", "0", checkpoints_buf);






  break;
  case 16: 
  ma___3 = (uint64 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2344", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2344", "0", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2348", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2348", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSbyteLong8(*ma___3);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2352", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2352", "0", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (int8 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2344", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2344", "0", checkpoints_buf);






  break;
  case 17: 
  ma___4 = (int64 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2365", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2365", "0", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2369", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2369", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSbyteSlong8(*ma___4);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2373", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2373", "0", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (int8 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2365", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2365", "0", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2384", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2384", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryShortArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           uint16 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  uint16 *data ;
  int16 *m ;
  uint32 n ;
  void *tmp ;
  uint8 *ma ;
  uint16 *mb ;
  uint32 n___0 ;
  uint16 *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  uint16 *mb___0 ;
  uint32 n___1 ;
  uint16 *tmp___2 ;
  int8 *tmp___3 ;
  uint32 *ma___1 ;
  uint16 *mb___1 ;
  uint32 n___2 ;
  uint16 *tmp___4 ;
  uint32 *tmp___5 ;
  int32 *ma___2 ;
  uint16 *mb___2 ;
  uint32 n___3 ;
  uint16 *tmp___6 ;
  int32 *tmp___7 ;
  uint64 *ma___3 ;
  uint16 *mb___3 ;
  uint32 n___4 ;
  uint16 *tmp___8 ;
  uint64 *tmp___9 ;
  int64 *ma___4 ;
  uint16 *mb___4 ;
  uint32 n___5 ;
  uint16 *tmp___10 ;
  int64 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )2, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2394", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (uint16 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (uint16 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2394", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 3: 
  *value = (uint16 *)origdata;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2403", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfShort(*value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2403", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
  case 8: 
  m = (int16 *)origdata;

  n = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2409", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2409", "0", checkpoints_buf);


  while (n < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2413", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)m);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2413", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeShortSshort(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2417", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2417", "0", checkpoints_buf);
    m ++;

    n ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2409", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2409", "0", checkpoints_buf);


  *value = (uint16 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * 2U));


  data = (uint16 *)tmp;

  if ((unsigned int )data == (unsigned int )((uint16 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (uint16 )*tmp___1;

    n___0 ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;





  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2449", "0", checkpoints_buf);






  while (n___1 < count) {




    err = TIFFReadDirEntryCheckRangeShortSbyte(*ma___0);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2454", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2454", "0", checkpoints_buf);
    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (uint16 )*tmp___3;

    n___1 ++;

  }




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2449", "0", checkpoints_buf);






  break;
  case 4: 
  ma___1 = (uint32 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2467", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2467", "0", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2471", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2471", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeShortLong(*ma___1);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2475", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2475", "0", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (uint16 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2467", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2467", "0", checkpoints_buf);






  break;
  case 9: 
  ma___2 = (int32 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2488", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2488", "0", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2492", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2492", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeShortSlong(*ma___2);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2496", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2496", "0", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (uint16 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2488", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2488", "0", checkpoints_buf);






  break;
  case 16: 
  ma___3 = (uint64 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2509", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2509", "0", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2513", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2513", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeShortLong8(*ma___3);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2517", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2517", "0", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (uint16 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2509", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2509", "0", checkpoints_buf);






  break;
  case 17: 
  ma___4 = (int64 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2530", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2530", "0", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2534", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2534", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeShortSlong8(*ma___4);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2538", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2538", "0", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (uint16 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2530", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2530", "0", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2549", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2549", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntrySshortArray(TIFF *tif ,
                                                            TIFFDirEntry *direntry ,
                                                            int16 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  int16 *data ;
  uint16 *m ;
  uint32 n ;
  void *tmp ;
  uint8 *ma ;
  int16 *mb ;
  uint32 n___0 ;
  int16 *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  int16 *mb___0 ;
  uint32 n___1 ;
  int16 *tmp___2 ;
  int8 *tmp___3 ;
  uint32 *ma___1 ;
  int16 *mb___1 ;
  uint32 n___2 ;
  int16 *tmp___4 ;
  uint32 *tmp___5 ;
  int32 *ma___2 ;
  int16 *mb___2 ;
  uint32 n___3 ;
  int16 *tmp___6 ;
  int32 *tmp___7 ;
  uint64 *ma___3 ;
  int16 *mb___3 ;
  uint32 n___4 ;
  int16 *tmp___8 ;
  uint64 *tmp___9 ;
  int64 *ma___4 ;
  int16 *mb___4 ;
  uint32 n___5 ;
  int16 *tmp___10 ;
  int64 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )2, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2559", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (int16 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (int16 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2559", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 3: 
  m = (uint16 *)origdata;

  n = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2569", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2569", "0", checkpoints_buf);


  while (n < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2573", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(m);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2573", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSshortShort(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2577", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2577", "0", checkpoints_buf);
    m ++;

    n ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2569", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2569", "0", checkpoints_buf);


  *value = (int16 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  case 8: 
  *value = (int16 *)origdata;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2586", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfShort((uint16 *)*value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2586", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * 2U));


  data = (int16 *)tmp;

  if ((unsigned int )data == (unsigned int )((int16 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (int16 )*tmp___1;

    n___0 ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;









  while (n___1 < count) {


    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (int16 )*tmp___3;

    n___1 ++;

  }








  break;
  case 4: 
  ma___1 = (uint32 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2628", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2628", "0", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2632", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2632", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSshortLong(*ma___1);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2636", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2636", "0", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (int16 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2628", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2628", "0", checkpoints_buf);






  break;
  case 9: 
  ma___2 = (int32 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2649", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2649", "0", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2653", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2653", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSshortSlong(*ma___2);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2657", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2657", "0", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (int16 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2649", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2649", "0", checkpoints_buf);






  break;
  case 16: 
  ma___3 = (uint64 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2670", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2670", "0", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2674", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2674", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSshortLong8(*ma___3);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2678", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2678", "0", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (int16 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2670", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2670", "0", checkpoints_buf);






  break;
  case 17: 
  ma___4 = (int64 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2691", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2691", "0", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2695", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2695", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSshortSlong8(*ma___4);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2699", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2699", "0", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (int16 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2691", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2691", "0", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2710", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2710", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryLongArray(TIFF *tif ,
                                                          TIFFDirEntry *direntry ,
                                                          uint32 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  uint32 *data ;
  int32 *m ;
  uint32 n ;
  void *tmp ;
  uint8 *ma ;
  uint32 *mb ;
  uint32 n___0 ;
  uint32 *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  uint32 *mb___0 ;
  uint32 n___1 ;
  uint32 *tmp___2 ;
  int8 *tmp___3 ;
  uint16 *ma___1 ;
  uint32 *mb___1 ;
  uint32 n___2 ;
  uint32 *tmp___4 ;
  uint16 *tmp___5 ;
  int16 *ma___2 ;
  uint32 *mb___2 ;
  uint32 n___3 ;
  uint32 *tmp___6 ;
  int16 *tmp___7 ;
  uint64 *ma___3 ;
  uint32 *mb___3 ;
  uint32 n___4 ;
  uint32 *tmp___8 ;
  uint64 *tmp___9 ;
  int64 *ma___4 ;
  uint32 *mb___4 ;
  uint32 n___5 ;
  uint32 *tmp___10 ;
  int64 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )4, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2720", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (uint32 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (uint32 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2720", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 4: 
  *value = (uint32 *)origdata;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2729", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong(*value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2729", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
  case 9: 
  m = (int32 *)origdata;

  n = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2735", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2735", "0", checkpoints_buf);


  while (n < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2739", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)m);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2739", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeLongSlong(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2743", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2743", "0", checkpoints_buf);
    m ++;

    n ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2735", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2735", "0", checkpoints_buf);


  *value = (uint32 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * 4U));


  data = (uint32 *)tmp;

  if ((unsigned int )data == (unsigned int )((uint32 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (uint32 )*tmp___1;

    n___0 ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;





  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2775", "0", checkpoints_buf);






  while (n___1 < count) {




    err = TIFFReadDirEntryCheckRangeLongSbyte(*ma___0);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2780", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2780", "0", checkpoints_buf);
    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (uint32 )*tmp___3;

    n___1 ++;

  }




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2775", "0", checkpoints_buf);






  break;
  case 3: 
  ma___1 = (uint16 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2793", "128", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2797", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2797", "128", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (uint32 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2793", "128", checkpoints_buf);






  break;
  case 8: 
  ma___2 = (int16 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2810", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2810", "0", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2814", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2814", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeLongSshort(*ma___2);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2818", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2818", "0", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (uint32 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2810", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2810", "0", checkpoints_buf);






  break;
  case 16: 
  ma___3 = (uint64 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2831", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2831", "0", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2835", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2835", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeLongLong8(*ma___3);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2839", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2839", "0", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (uint32 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2831", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2831", "0", checkpoints_buf);






  break;
  case 17: 
  ma___4 = (int64 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2852", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2852", "0", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2856", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2856", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeLongSlong8(*ma___4);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2860", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2860", "0", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (uint32 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2852", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2852", "0", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2871", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2871", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntrySlongArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           int32 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  int32 *data ;
  uint32 *m ;
  uint32 n ;
  void *tmp ;
  uint8 *ma ;
  int32 *mb ;
  uint32 n___0 ;
  int32 *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  int32 *mb___0 ;
  uint32 n___1 ;
  int32 *tmp___2 ;
  int8 *tmp___3 ;
  uint16 *ma___1 ;
  int32 *mb___1 ;
  uint32 n___2 ;
  int32 *tmp___4 ;
  uint16 *tmp___5 ;
  int16 *ma___2 ;
  int32 *mb___2 ;
  uint32 n___3 ;
  int32 *tmp___6 ;
  int16 *tmp___7 ;
  uint64 *ma___3 ;
  int32 *mb___3 ;
  uint32 n___4 ;
  int32 *tmp___8 ;
  uint64 *tmp___9 ;
  int64 *ma___4 ;
  int32 *mb___4 ;
  uint32 n___5 ;
  int32 *tmp___10 ;
  int64 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )4, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2881", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (int32 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (int32 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2881", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 4: 
  m = (uint32 *)origdata;

  n = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2891", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2891", "0", checkpoints_buf);


  while (n < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2895", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(m);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2895", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSlongLong(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2899", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2899", "0", checkpoints_buf);
    m ++;

    n ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2891", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2891", "0", checkpoints_buf);


  *value = (int32 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  case 9: 
  *value = (int32 *)origdata;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2908", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong((uint32 *)*value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2908", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * 4U));


  data = (int32 *)tmp;

  if ((unsigned int )data == (unsigned int )((int32 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (int32 )*tmp___1;

    n___0 ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;









  while (n___1 < count) {


    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (int32 )*tmp___3;

    n___1 ++;

  }








  break;
  case 3: 
  ma___1 = (uint16 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2950", "128", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2954", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2954", "128", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (int32 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2950", "128", checkpoints_buf);






  break;
  case 8: 
  ma___2 = (int16 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2967", "128", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2971", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2971", "128", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (int32 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2967", "128", checkpoints_buf);






  break;
  case 16: 
  ma___3 = (uint64 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2984", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2984", "0", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2988", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2988", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSlongLong8(*ma___3);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2992", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "2992", "0", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (int32 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2984", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "2984", "0", checkpoints_buf);






  break;
  case 17: 
  ma___4 = (int64 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3005", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3005", "0", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3009", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3009", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSlongSlong8(*ma___4);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3013", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3013", "0", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (int32 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3005", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3005", "0", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3024", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3024", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryLong8Array(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           uint64 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  uint64 *data ;
  int64 *m ;
  uint32 n ;
  void *tmp ;
  uint8 *ma ;
  uint64 *mb ;
  uint32 n___0 ;
  uint64 *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  uint64 *mb___0 ;
  uint32 n___1 ;
  uint64 *tmp___2 ;
  int8 *tmp___3 ;
  uint16 *ma___1 ;
  uint64 *mb___1 ;
  uint32 n___2 ;
  uint64 *tmp___4 ;
  uint16 *tmp___5 ;
  int16 *ma___2 ;
  uint64 *mb___2 ;
  uint32 n___3 ;
  uint64 *tmp___6 ;
  int16 *tmp___7 ;
  uint32 *ma___3 ;
  uint64 *mb___3 ;
  uint32 n___4 ;
  uint64 *tmp___8 ;
  uint32 *tmp___9 ;
  int32 *ma___4 ;
  uint64 *mb___4 ;
  uint32 n___5 ;
  uint64 *tmp___10 ;
  int32 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )8, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3034", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (uint64 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (uint64 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3034", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 16: 
  *value = (uint64 *)origdata;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3043", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8(*value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3043", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
  case 17: 
  m = (int64 *)origdata;

  n = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3049", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3049", "0", checkpoints_buf);


  while (n < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3053", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)m);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3053", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeLong8Slong8(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3057", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3057", "0", checkpoints_buf);
    m ++;

    n ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3049", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3049", "0", checkpoints_buf);


  *value = (uint64 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * 8U));


  data = (uint64 *)tmp;

  if ((unsigned int )data == (unsigned int )((uint64 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (uint64 )*tmp___1;

    n___0 ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;





  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3089", "0", checkpoints_buf);






  while (n___1 < count) {




    err = TIFFReadDirEntryCheckRangeLong8Sbyte(*ma___0);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3094", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3094", "0", checkpoints_buf);
    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (uint64 )*tmp___3;

    n___1 ++;

  }




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3089", "0", checkpoints_buf);






  break;
  case 3: 
  ma___1 = (uint16 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3107", "128", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3111", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3111", "128", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (uint64 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3107", "128", checkpoints_buf);






  break;
  case 8: 
  ma___2 = (int16 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3124", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3124", "0", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3128", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3128", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeLong8Sshort(*ma___2);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3132", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3132", "0", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (uint64 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3124", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3124", "0", checkpoints_buf);






  break;
  case 4: 
  ma___3 = (uint32 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3145", "128", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3149", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3149", "128", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (uint64 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3145", "128", checkpoints_buf);






  break;
  case 9: 
  ma___4 = (int32 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3162", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3162", "0", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3166", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3166", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeLong8Slong(*ma___4);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3170", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3170", "0", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (uint64 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3162", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3162", "0", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3181", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3181", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntrySlong8Array(TIFF *tif ,
                                                            TIFFDirEntry *direntry ,
                                                            int64 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  int64 *data ;
  uint64 *m ;
  uint32 n ;
  void *tmp ;
  uint8 *ma ;
  int64 *mb ;
  uint32 n___0 ;
  int64 *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  int64 *mb___0 ;
  uint32 n___1 ;
  int64 *tmp___2 ;
  int8 *tmp___3 ;
  uint16 *ma___1 ;
  int64 *mb___1 ;
  uint32 n___2 ;
  int64 *tmp___4 ;
  uint16 *tmp___5 ;
  int16 *ma___2 ;
  int64 *mb___2 ;
  uint32 n___3 ;
  int64 *tmp___6 ;
  int16 *tmp___7 ;
  uint32 *ma___3 ;
  int64 *mb___3 ;
  uint32 n___4 ;
  int64 *tmp___8 ;
  uint32 *tmp___9 ;
  int32 *ma___4 ;
  int64 *mb___4 ;
  uint32 n___5 ;
  int64 *tmp___10 ;
  int32 *tmp___11 ;

  {
  switch ((int )direntry->tdir_type) {
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )8, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3191", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (int64 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (int64 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3191", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 16: 
  m = (uint64 *)origdata;

  n = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3201", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3201", "0", checkpoints_buf);


  while (n < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3205", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(m);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3205", "128", checkpoints_buf);


    err = TIFFReadDirEntryCheckRangeSlong8Long8(*m);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3209", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      _TIFFfree(origdata);


      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3209", "0", checkpoints_buf);
    m ++;

    n ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3201", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3201", "0", checkpoints_buf);


  *value = (int64 *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  case 17: 
  *value = (int64 *)origdata;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3218", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8((uint64 *)*value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3218", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * 8U));


  data = (int64 *)tmp;

  if ((unsigned int )data == (unsigned int )((int64 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (int64 )*tmp___1;

    n___0 ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___1 = (uint32 )0;









  while (n___1 < count) {


    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (int64 )*tmp___3;

    n___1 ++;

  }








  break;
  case 3: 
  ma___1 = (uint16 *)origdata;

  mb___1 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3260", "128", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3264", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3264", "128", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (int64 )*tmp___5;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3260", "128", checkpoints_buf);






  break;
  case 8: 
  ma___2 = (int16 *)origdata;

  mb___2 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3277", "128", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3281", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3281", "128", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (int64 )*tmp___7;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3277", "128", checkpoints_buf);






  break;
  case 4: 
  ma___3 = (uint32 *)origdata;

  mb___3 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3294", "128", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3298", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3298", "128", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (int64 )*tmp___9;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3294", "128", checkpoints_buf);






  break;
  case 9: 
  ma___4 = (int32 *)origdata;

  mb___4 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3311", "128", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3315", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3315", "128", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (int64 )*tmp___11;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3311", "128", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3326", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3326", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryFloatArray(TIFF *tif ,
                                                           TIFFDirEntry *direntry ,
                                                           float **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  float *data ;
  void *tmp ;
  uint8 *ma ;
  float *mb ;
  uint32 n ;
  float *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  float *mb___0 ;
  uint32 n___0 ;
  float *tmp___2 ;
  int8 *tmp___3 ;
  uint16 *ma___1 ;
  float *mb___1 ;
  uint32 n___1 ;
  float *tmp___4 ;
  uint16 *tmp___5 ;
  int16 *ma___2 ;
  float *mb___2 ;
  uint32 n___2 ;
  float *tmp___6 ;
  int16 *tmp___7 ;
  uint32 *ma___3 ;
  float *mb___3 ;
  uint32 n___3 ;
  float *tmp___8 ;
  uint32 *tmp___9 ;
  int32 *ma___4 ;
  float *mb___4 ;
  uint32 n___4 ;
  float *tmp___10 ;
  int32 *tmp___11 ;
  uint64 *ma___5 ;
  float *mb___5 ;
  uint32 n___5 ;
  float *tmp___12 ;
  uint64 *tmp___13 ;
  int64 *ma___6 ;
  float *mb___6 ;
  uint32 n___6 ;
  float *tmp___14 ;
  int64 *tmp___15 ;
  uint32 *ma___7 ;
  uint32 maa ;
  uint32 mab ;
  float *mb___7 ;
  uint32 n___7 ;
  uint32 *tmp___16 ;
  uint32 *tmp___17 ;
  float *tmp___18 ;
  float *tmp___19 ;
  uint32 *ma___8 ;
  int32 maa___0 ;
  uint32 mab___0 ;
  float *mb___8 ;
  uint32 n___8 ;
  uint32 *tmp___20 ;
  float *tmp___21 ;
  float *tmp___22 ;
  double *ma___9 ;
  float *mb___9 ;
  uint32 n___9 ;
  float *tmp___23 ;
  double *tmp___24 ;

  {
  switch ((int )direntry->tdir_type) {
  case 12: 
  case 11: 
  case 10: 
  case 5: 
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )4, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3336", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (float *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (float *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3336", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3344", "128", checkpoints_buf);
  case 11: 
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong((uint32 *)origdata, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3344", "128", checkpoints_buf);
  *value = (float *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * sizeof(float )));


  data = (float *)tmp;

  if ((unsigned int )data == (unsigned int )((float *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n = (uint32 )0;









  while (n < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (float )*tmp___1;

    n ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (float )*tmp___3;

    n___0 ++;

  }








  break;
  case 3: 
  ma___1 = (uint16 *)origdata;

  mb___1 = data;

  n___1 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3387", "128", checkpoints_buf);






  while (n___1 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3391", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3391", "128", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (float )*tmp___5;

    n___1 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3387", "128", checkpoints_buf);






  break;
  case 8: 
  ma___2 = (int16 *)origdata;

  mb___2 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3404", "128", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3408", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3408", "128", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (float )*tmp___7;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3404", "128", checkpoints_buf);






  break;
  case 4: 
  ma___3 = (uint32 *)origdata;

  mb___3 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3421", "128", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3425", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3425", "128", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (float )*tmp___9;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3421", "128", checkpoints_buf);






  break;
  case 9: 
  ma___4 = (int32 *)origdata;

  mb___4 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3438", "128", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3442", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3442", "128", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (float )*tmp___11;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3438", "128", checkpoints_buf);






  break;
  case 16: 
  ma___5 = (uint64 *)origdata;

  mb___5 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3455", "128", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3459", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___5);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3459", "128", checkpoints_buf);
    tmp___12 = mb___5;

    mb___5 ++;

    tmp___13 = ma___5;

    ma___5 ++;

    *tmp___12 = (float )*tmp___13;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3455", "128", checkpoints_buf);






  break;
  case 17: 
  ma___6 = (int64 *)origdata;

  mb___6 = data;

  n___6 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3472", "128", checkpoints_buf);






  while (n___6 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3476", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___6);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3476", "128", checkpoints_buf);
    tmp___14 = mb___6;

    mb___6 ++;

    tmp___15 = ma___6;

    ma___6 ++;

    *tmp___14 = (float )*tmp___15;

    n___6 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3472", "128", checkpoints_buf);






  break;
  case 5: 
  ma___7 = (uint32 *)origdata;

  mb___7 = data;

  n___7 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3489", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3489", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3489", "0", checkpoints_buf);

  while (n___7 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3493", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___7);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3493", "128", checkpoints_buf);
    tmp___16 = ma___7;

    ma___7 ++;

    maa = *tmp___16;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3499", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___7);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3499", "128", checkpoints_buf);
    tmp___17 = ma___7;

    ma___7 ++;

    mab = *tmp___17;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3505", "0", checkpoints_buf);
    if (mab == 0U) {
      tmp___18 = mb___7;

      mb___7 ++;

      *tmp___18 = (float )0.0;

    } else {
      tmp___19 = mb___7;

      mb___7 ++;

      *tmp___19 = (float )maa / (float )mab;

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3505", "0", checkpoints_buf);
    n___7 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3489", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3489", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3489", "0", checkpoints_buf);

  break;
  case 10: 
  ma___8 = (uint32 *)origdata;

  mb___8 = data;

  n___8 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3517", "128", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3517", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3517", "0", checkpoints_buf);

  while (n___8 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3521", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___8);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3521", "128", checkpoints_buf);
    maa___0 = *((int32 *)ma___8);

    ma___8 ++;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3526", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___8);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3526", "128", checkpoints_buf);
    tmp___20 = ma___8;

    ma___8 ++;

    mab___0 = *tmp___20;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3532", "0", checkpoints_buf);
    if (mab___0 == 0U) {
      tmp___21 = mb___8;

      mb___8 ++;

      *tmp___21 = (float )0.0;

    } else {
      tmp___22 = mb___8;

      mb___8 ++;

      *tmp___22 = (float )maa___0 / (float )mab___0;

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3532", "0", checkpoints_buf);
    n___8 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3517", "128", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3517", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3517", "0", checkpoints_buf);

  break;

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3541", "128", checkpoints_buf);
  case 12: 
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8((uint64 *)origdata, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3541", "128", checkpoints_buf);
  ma___9 = (double *)origdata;

  mb___9 = data;

  n___9 = (uint32 )0;









  while (n___9 < count) {


    tmp___23 = mb___9;

    mb___9 ++;

    tmp___24 = ma___9;

    ma___9 ++;

    *tmp___23 = (float )*tmp___24;

    n___9 ++;

  }








  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3559", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3559", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryDoubleArray(TIFF *tif ,
                                                            TIFFDirEntry *direntry ,
                                                            double **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  double *data ;
  void *tmp ;
  uint8 *ma ;
  double *mb ;
  uint32 n ;
  double *tmp___0 ;
  uint8 *tmp___1 ;
  int8 *ma___0 ;
  double *mb___0 ;
  uint32 n___0 ;
  double *tmp___2 ;
  int8 *tmp___3 ;
  uint16 *ma___1 ;
  double *mb___1 ;
  uint32 n___1 ;
  double *tmp___4 ;
  uint16 *tmp___5 ;
  int16 *ma___2 ;
  double *mb___2 ;
  uint32 n___2 ;
  double *tmp___6 ;
  int16 *tmp___7 ;
  uint32 *ma___3 ;
  double *mb___3 ;
  uint32 n___3 ;
  double *tmp___8 ;
  uint32 *tmp___9 ;
  int32 *ma___4 ;
  double *mb___4 ;
  uint32 n___4 ;
  double *tmp___10 ;
  int32 *tmp___11 ;
  uint64 *ma___5 ;
  double *mb___5 ;
  uint32 n___5 ;
  double *tmp___12 ;
  uint64 *tmp___13 ;
  int64 *ma___6 ;
  double *mb___6 ;
  uint32 n___6 ;
  double *tmp___14 ;
  int64 *tmp___15 ;
  uint32 *ma___7 ;
  uint32 maa ;
  uint32 mab ;
  double *mb___7 ;
  uint32 n___7 ;
  uint32 *tmp___16 ;
  uint32 *tmp___17 ;
  double *tmp___18 ;
  double *tmp___19 ;
  uint32 *ma___8 ;
  int32 maa___0 ;
  uint32 mab___0 ;
  double *mb___8 ;
  uint32 n___8 ;
  uint32 *tmp___20 ;
  double *tmp___21 ;
  double *tmp___22 ;
  float *ma___9 ;
  double *mb___9 ;
  uint32 n___9 ;
  double *tmp___23 ;
  float *tmp___24 ;

  {
  switch ((int )direntry->tdir_type) {
  case 12: 
  case 11: 
  case 10: 
  case 5: 
  case 17: 
  case 16: 
  case 9: 
  case 4: 
  case 8: 
  case 3: 
  case 6: 
  case 1: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )8, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3569", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (double *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (double *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3569", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3577", "128", checkpoints_buf);
  case 12: 
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8((uint64 *)origdata, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3577", "128", checkpoints_buf);
  *value = (double *)origdata;

  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * sizeof(double )));


  data = (double *)tmp;

  if ((unsigned int )data == (unsigned int )((double *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 1: 
  ma = (uint8 *)origdata;

  mb = data;

  n = (uint32 )0;









  while (n < count) {


    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (double )*tmp___1;

    n ++;

  }








  break;
  case 6: 
  ma___0 = (int8 *)origdata;

  mb___0 = data;

  n___0 = (uint32 )0;









  while (n___0 < count) {


    tmp___2 = mb___0;

    mb___0 ++;

    tmp___3 = ma___0;

    ma___0 ++;

    *tmp___2 = (double )*tmp___3;

    n___0 ++;

  }








  break;
  case 3: 
  ma___1 = (uint16 *)origdata;

  mb___1 = data;

  n___1 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3620", "128", checkpoints_buf);






  while (n___1 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3624", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(ma___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3624", "128", checkpoints_buf);
    tmp___4 = mb___1;

    mb___1 ++;

    tmp___5 = ma___1;

    ma___1 ++;

    *tmp___4 = (double )*tmp___5;

    n___1 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3620", "128", checkpoints_buf);






  break;
  case 8: 
  ma___2 = (int16 *)origdata;

  mb___2 = data;

  n___2 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3637", "128", checkpoints_buf);






  while (n___2 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3641", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3641", "128", checkpoints_buf);
    tmp___6 = mb___2;

    mb___2 ++;

    tmp___7 = ma___2;

    ma___2 ++;

    *tmp___6 = (double )*tmp___7;

    n___2 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3637", "128", checkpoints_buf);






  break;
  case 4: 
  ma___3 = (uint32 *)origdata;

  mb___3 = data;

  n___3 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3654", "128", checkpoints_buf);






  while (n___3 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3658", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___3);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3658", "128", checkpoints_buf);
    tmp___8 = mb___3;

    mb___3 ++;

    tmp___9 = ma___3;

    ma___3 ++;

    *tmp___8 = (double )*tmp___9;

    n___3 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3654", "128", checkpoints_buf);






  break;
  case 9: 
  ma___4 = (int32 *)origdata;

  mb___4 = data;

  n___4 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3671", "128", checkpoints_buf);






  while (n___4 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3675", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)ma___4);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3675", "128", checkpoints_buf);
    tmp___10 = mb___4;

    mb___4 ++;

    tmp___11 = ma___4;

    ma___4 ++;

    *tmp___10 = (double )*tmp___11;

    n___4 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3671", "128", checkpoints_buf);






  break;
  case 16: 
  ma___5 = (uint64 *)origdata;

  mb___5 = data;

  n___5 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3688", "128", checkpoints_buf);






  while (n___5 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3692", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(ma___5);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3692", "128", checkpoints_buf);
    tmp___12 = mb___5;

    mb___5 ++;

    tmp___13 = ma___5;

    ma___5 ++;

    *tmp___12 = (double )*tmp___13;

    n___5 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3688", "128", checkpoints_buf);






  break;
  case 17: 
  ma___6 = (int64 *)origdata;

  mb___6 = data;

  n___6 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3705", "128", checkpoints_buf);






  while (n___6 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3709", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)ma___6);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3709", "128", checkpoints_buf);
    tmp___14 = mb___6;

    mb___6 ++;

    tmp___15 = ma___6;

    ma___6 ++;

    *tmp___14 = (double )*tmp___15;

    n___6 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3705", "128", checkpoints_buf);






  break;
  case 5: 
  ma___7 = (uint32 *)origdata;

  mb___7 = data;

  n___7 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3722", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3722", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3722", "0", checkpoints_buf);

  while (n___7 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3726", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___7);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3726", "128", checkpoints_buf);
    tmp___16 = ma___7;

    ma___7 ++;

    maa = *tmp___16;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3732", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___7);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3732", "128", checkpoints_buf);
    tmp___17 = ma___7;

    ma___7 ++;

    mab = *tmp___17;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3738", "0", checkpoints_buf);
    if (mab == 0U) {
      tmp___18 = mb___7;

      mb___7 ++;

      *tmp___18 = 0.0;

    } else {
      tmp___19 = mb___7;

      mb___7 ++;

      *tmp___19 = (double )maa / (double )mab;

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3738", "0", checkpoints_buf);
    n___7 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3722", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3722", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3722", "0", checkpoints_buf);

  break;
  case 10: 
  ma___8 = (uint32 *)origdata;

  mb___8 = data;

  n___8 = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3750", "128", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3750", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3750", "0", checkpoints_buf);

  while (n___8 < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3754", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___8);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3754", "128", checkpoints_buf);
    maa___0 = *((int32 *)ma___8);

    ma___8 ++;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3759", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma___8);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3759", "128", checkpoints_buf);
    tmp___20 = ma___8;

    ma___8 ++;

    mab___0 = *tmp___20;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3765", "0", checkpoints_buf);
    if (mab___0 == 0U) {
      tmp___21 = mb___8;

      mb___8 ++;

      *tmp___21 = 0.0;

    } else {
      tmp___22 = mb___8;

      mb___8 ++;

      *tmp___22 = (double )maa___0 / (double )mab___0;

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3765", "0", checkpoints_buf);
    n___8 ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3750", "128", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3750", "128", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3750", "0", checkpoints_buf);

  break;

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3774", "128", checkpoints_buf);
  case 11: 
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong((uint32 *)origdata, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3774", "128", checkpoints_buf);
  ma___9 = (float *)origdata;

  mb___9 = data;

  n___9 = (uint32 )0;









  while (n___9 < count) {


    tmp___23 = mb___9;

    mb___9 ++;

    tmp___24 = ma___9;

    ma___9 ++;

    *tmp___23 = (double )*tmp___24;

    n___9 ++;

  }








  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3792", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3792", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryIfd8Array(TIFF *tif ,
                                                          TIFFDirEntry *direntry ,
                                                          uint64 **value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 count ;
  void *origdata ;
  uint64 *data ;
  void *tmp ;
  uint32 *ma ;
  uint64 *mb ;
  uint32 n ;
  uint64 *tmp___0 ;
  uint32 *tmp___1 ;

  {
  switch ((int )direntry->tdir_type) {
  case 18: 
  case 13: 
  case 16: 
  case 4: 
  break;
  default: 
  return ((enum TIFFReadDirEntryErr )2);
  }


  err = TIFFReadDirEntryArray(tif, direntry, & count, (uint32 )8, & origdata);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3802", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {
    *value = (uint64 *)0;


    return (err);
  } else
  if ((unsigned int )origdata == (unsigned int )((void *)0)) {
    *value = (uint64 *)0;


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3802", "0", checkpoints_buf);
  switch ((int )direntry->tdir_type) {
  case 18: 
  case 16: 
  *value = (uint64 *)origdata;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3811", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8(*value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3811", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
  }


  tmp = _TIFFmalloc((tmsize_t )(count * 8U));


  data = (uint64 *)tmp;

  if ((unsigned int )data == (unsigned int )((uint64 *)0)) {

    _TIFFfree(origdata);

    return ((enum TIFFReadDirEntryErr )7);
  } else {

  }
  switch ((int )direntry->tdir_type) {
  case 13: 
  case 4: 
  ma = (uint32 *)origdata;

  mb = data;

  n = (uint32 )0;




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3825", "128", checkpoints_buf);






  while (n < count) {



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3829", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(ma);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3829", "128", checkpoints_buf);
    tmp___0 = mb;

    mb ++;

    tmp___1 = ma;

    ma ++;

    *tmp___0 = (uint64 )*tmp___1;

    n ++;

  }



  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3825", "128", checkpoints_buf);






  break;
  }

  _TIFFfree(origdata);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3840", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    _TIFFfree((void *)data);


    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3840", "0", checkpoints_buf);
  *value = data;

  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryPersampleShort(TIFF *tif ,
                                                               TIFFDirEntry *direntry ,
                                                               uint16 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint16 *m ;
  uint16 *na ;
  uint16 nb ;
  uint16 *tmp ;
  uint16 *tmp___0 ;

  {

  if (direntry->tdir_count != (uint64 )tif->tif_dir.td_samplesperpixel) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }



  err = TIFFReadDirEntryShortArray(tif, direntry, & m);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3850", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3850", "0", checkpoints_buf);
  na = m;

  nb = tif->tif_dir.td_samplesperpixel;

  tmp = na;

  na ++;

  *value = *tmp;

  nb = (uint16 )((int )nb - 1);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3859", "0", checkpoints_buf);



  while (1) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3860", "0", checkpoints_buf);
    if ((int )nb > 0) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3860", "0", checkpoints_buf);
    tmp___0 = na;

    na ++;

    if ((int )*tmp___0 != (int )*value) {
      err = (enum TIFFReadDirEntryErr )5;

      break;
    } else {

    }
    nb = (uint16 )((int )nb - 1);

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3859", "0", checkpoints_buf);




  _TIFFfree((void *)m);


  return (err);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryPersampleDouble(TIFF *tif ,
                                                                TIFFDirEntry *direntry ,
                                                                double *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  double *m ;
  double *na ;
  uint16 nb ;
  double *tmp ;
  double *tmp___0 ;

  {

  if (direntry->tdir_count != (uint64 )tif->tif_dir.td_samplesperpixel) {
    return ((enum TIFFReadDirEntryErr )1);
  } else {

  }



  err = TIFFReadDirEntryDoubleArray(tif, direntry, & m);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3876", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    return (err);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3876", "0", checkpoints_buf);
  na = m;

  nb = tif->tif_dir.td_samplesperpixel;

  tmp = na;

  na ++;

  *value = *tmp;

  nb = (uint16 )((int )nb - 1);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3885", "0", checkpoints_buf);





  while (1) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3886", "0", checkpoints_buf);
    if ((int )nb > 0) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3886", "0", checkpoints_buf);
    tmp___0 = na;

    na ++;



    if (*tmp___0 != *value) {
      err = (enum TIFFReadDirEntryErr )5;

      break;
    } else {

    }


    nb = (uint16 )((int )nb - 1);

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3885", "0", checkpoints_buf);






  _TIFFfree((void *)m);


  return (err);
}
}
static void TIFFReadDirEntryCheckedByte(TIFF *tif , TIFFDirEntry *direntry ,
                                        uint8 *value ) 
{ 


  {
  *value = *((uint8 *)(& direntry->tdir_offset));

  return;
}
}
static void TIFFReadDirEntryCheckedSbyte(TIFF *tif , TIFFDirEntry *direntry ,
                                         int8 *value ) 
{ 


  {
  *value = *((int8 *)(& direntry->tdir_offset));

  return;
}
}
static void TIFFReadDirEntryCheckedShort(TIFF *tif , TIFFDirEntry *direntry ,
                                         uint16 *value ) 
{ 


  {
  *value = *((uint16 *)(& direntry->tdir_offset));


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3903", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabShort(value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3903", "128", checkpoints_buf);
  return;
}
}
static void TIFFReadDirEntryCheckedSshort(TIFF *tif , TIFFDirEntry *direntry ,
                                          int16 *value ) 
{ 


  {
  *value = *((int16 *)(& direntry->tdir_offset));


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3908", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabShort((uint16 *)value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3908", "128", checkpoints_buf);
  return;
}
}
static void TIFFReadDirEntryCheckedLong(TIFF *tif , TIFFDirEntry *direntry ,
                                        uint32 *value ) 
{ 


  {
  *value = *((uint32 *)(& direntry->tdir_offset));


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3913", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong(value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3913", "128", checkpoints_buf);
  return;
}
}
static void TIFFReadDirEntryCheckedSlong(TIFF *tif , TIFFDirEntry *direntry ,
                                         int32 *value ) 
{ 


  {
  *value = *((int32 *)(& direntry->tdir_offset));


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3918", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong((uint32 *)value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3918", "128", checkpoints_buf);
  return;
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedLong8(TIFF *tif ,
                                                             TIFFDirEntry *direntry ,
                                                             uint64 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 offset ;

  {

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3922", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    offset = *((uint32 *)(& direntry->tdir_offset));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3924", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& offset);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3924", "128", checkpoints_buf);


    err = TIFFReadDirEntryData(tif, (uint64 )offset, (tmsize_t )8, (void *)value);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3928", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3928", "0", checkpoints_buf);
  } else {
    *value = direntry->tdir_offset;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3922", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3932", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong8(value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3932", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedSlong8(TIFF *tif ,
                                                              TIFFDirEntry *direntry ,
                                                              int64 *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 offset ;

  {

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3936", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    offset = *((uint32 *)(& direntry->tdir_offset));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3938", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& offset);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3938", "128", checkpoints_buf);


    err = TIFFReadDirEntryData(tif, (uint64 )offset, (tmsize_t )8, (void *)value);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3942", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3942", "0", checkpoints_buf);
  } else {
    *value = *((int64 *)(& direntry->tdir_offset));

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3936", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3946", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong8((uint64 *)value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3946", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedRational(TIFF *tif ,
                                                                TIFFDirEntry *direntry ,
                                                                double *value ) 
{ 
  uint32 m[2] ;
  enum TIFFReadDirEntryErr err ;
  uint32 offset ;

  {
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3950", "8", checkpoints_buf);
  if (sizeof(double ) == 8U) {

  } else {

    __assert_fail("sizeof(double)==8", "tif_dirread.c", 2800U,
                  "TIFFReadDirEntryCheckedRational");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3950", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3953", "8", checkpoints_buf);
  if (sizeof(uint64 ) == 8U) {

  } else {

    __assert_fail("sizeof(uint64)==8", "tif_dirread.c", 2801U,
                  "TIFFReadDirEntryCheckedRational");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3953", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3956", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirread.c", 2802U,
                  "TIFFReadDirEntryCheckedRational");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3956", "4", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3959", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    offset = *((uint32 *)(& direntry->tdir_offset));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3961", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& offset);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3961", "128", checkpoints_buf);


    err = TIFFReadDirEntryData(tif, (uint64 )offset, (tmsize_t )8, (void *)(m));


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3965", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3965", "0", checkpoints_buf);
  } else {
    *((uint64 *)(m)) = direntry->tdir_offset;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3959", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3969", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong(m, (tmsize_t )2);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3969", "128", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3972", "0", checkpoints_buf);
  if (m[0] == 0U) {
    *value = 0.0;

  } else {
    *value = (double )m[0] / (double )m[1];

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3972", "0", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedSrational(TIFF *tif ,
                                                                 TIFFDirEntry *direntry ,
                                                                 double *value ) 
{ 
  uint32 m[2] ;
  enum TIFFReadDirEntryErr err ;
  uint32 offset ;

  {
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3976", "8", checkpoints_buf);
  if (sizeof(double ) == 8U) {

  } else {

    __assert_fail("sizeof(double)==8", "tif_dirread.c", 2828U,
                  "TIFFReadDirEntryCheckedSrational");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3976", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3979", "8", checkpoints_buf);
  if (sizeof(uint64 ) == 8U) {

  } else {

    __assert_fail("sizeof(uint64)==8", "tif_dirread.c", 2829U,
                  "TIFFReadDirEntryCheckedSrational");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3979", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3982", "4", checkpoints_buf);
  if (sizeof(int32 ) == 4U) {

  } else {

    __assert_fail("sizeof(int32)==4", "tif_dirread.c", 2830U,
                  "TIFFReadDirEntryCheckedSrational");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3982", "4", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3985", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirread.c", 2831U,
                  "TIFFReadDirEntryCheckedSrational");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3985", "4", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3988", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    offset = *((uint32 *)(& direntry->tdir_offset));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3990", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& offset);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3990", "128", checkpoints_buf);


    err = TIFFReadDirEntryData(tif, (uint64 )offset, (tmsize_t )8, (void *)(m));


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3994", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "3994", "0", checkpoints_buf);
  } else {
    *((uint64 *)(m)) = direntry->tdir_offset;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3988", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3998", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong(m, (tmsize_t )2);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "3998", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4001", "0", checkpoints_buf);
  if ((int32 )m[0] == 0) {
    *value = 0.0;

  } else {
    *value = (double )((int32 )m[0]) / (double )m[1];

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4001", "0", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
}
}
static void TIFFReadDirEntryCheckedFloat(TIFF *tif , TIFFDirEntry *direntry ,
                                         float *value ) 
{ 


  {
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4005", "4", checkpoints_buf);
  if (sizeof(float ) == 4U) {

  } else {

    __assert_fail("sizeof(float)==4", "tif_dirread.c", 2856U,
                  "TIFFReadDirEntryCheckedFloat");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4005", "4", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4008", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirread.c", 2857U,
                  "TIFFReadDirEntryCheckedFloat");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4008", "4", checkpoints_buf);
  *((uint32 *)value) = *((uint32 *)(& direntry->tdir_offset));


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4012", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong((uint32 *)value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4012", "128", checkpoints_buf);
  return;
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckedDouble(TIFF *tif ,
                                                              TIFFDirEntry *direntry ,
                                                              double *value ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 offset ;

  {
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4016", "8", checkpoints_buf);
  if (sizeof(double ) == 8U) {

  } else {

    __assert_fail("sizeof(double)==8", "tif_dirread.c", 2865U,
                  "TIFFReadDirEntryCheckedDouble");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4016", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4019", "8", checkpoints_buf);
  if (sizeof(uint64 ) == 8U) {

  } else {

    __assert_fail("sizeof(uint64)==8", "tif_dirread.c", 2866U,
                  "TIFFReadDirEntryCheckedDouble");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4019", "8", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4022", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    offset = *((uint32 *)(& direntry->tdir_offset));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4024", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& offset);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4024", "128", checkpoints_buf);


    err = TIFFReadDirEntryData(tif, (uint64 )offset, (tmsize_t )8, (void *)value);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4028", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      return (err);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4028", "0", checkpoints_buf);
  } else {
    *((uint64 *)value) = direntry->tdir_offset;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4022", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4032", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong8((uint64 *)value);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4032", "128", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSbyte(int8 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4036", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4036", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteShort(uint16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 255);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4039", "255", checkpoints_buf);
  if ((int )value > 255) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 255);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4039", "255", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSshort(int16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4042", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    sprintf(checkpoints_buf, "%d", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4044", "255", checkpoints_buf);
    if ((int )value > 255) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }
    sprintf(checkpoints_buf, "%d", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4044", "255", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4042", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteLong(uint32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%u", 255);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4047", "255", checkpoints_buf);
  if (value > 255U) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%u", 255);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4047", "255", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSlong(int32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4050", "0", checkpoints_buf);
  if (value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%d", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4052", "255", checkpoints_buf);
    if (value > 255) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%d", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4052", "255", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4050", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteLong8(uint64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%llu", 255);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4055", "255", checkpoints_buf);
  if (value > 255ULL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%llu", 255);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4055", "255", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeByteSlong8(int64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4058", "0", checkpoints_buf);
  if (value < 0LL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%lld", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4060", "255", checkpoints_buf);
    if (value > 255LL) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%lld", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4060", "255", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4058", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteByte(uint8 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4063", "127", checkpoints_buf);
  if ((int )value > 127) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4063", "127", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteShort(uint16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4066", "127", checkpoints_buf);
  if ((int )value > 127) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4066", "127", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteSshort(int16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4069", "-128", checkpoints_buf);
  if ((int )value < -128) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    sprintf(checkpoints_buf, "%d", 127);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4071", "127", checkpoints_buf);
    if ((int )value > 127) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }
    sprintf(checkpoints_buf, "%d", 127);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4071", "127", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4069", "-128", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteLong(uint32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%u", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4074", "127", checkpoints_buf);
  if (value > 127U) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%u", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4074", "127", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteSlong(int32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4077", "-128", checkpoints_buf);
  if (value < -128) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%d", 127);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4079", "127", checkpoints_buf);
    if (value > 127) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%d", 127);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4079", "127", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4077", "-128", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteLong8(uint64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%llu", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4082", "127", checkpoints_buf);
  if (value > 127ULL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%llu", 127);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4082", "127", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSbyteSlong8(int64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%lld", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4085", "-128", checkpoints_buf);
  if (value < -128LL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%lld", 127);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4087", "127", checkpoints_buf);
    if (value > 127LL) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%lld", 127);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4087", "127", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4085", "-128", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSbyte(int8 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4090", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4090", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSshort(int16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4093", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4093", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortLong(uint32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%u", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4096", "65535", checkpoints_buf);
  if (value > 65535U) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%u", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4096", "65535", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSlong(int32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4099", "0", checkpoints_buf);
  if (value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4101", "65535", checkpoints_buf);
    if (value > 65535) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4101", "65535", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4099", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortLong8(uint64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4104", "65535", checkpoints_buf);
  if (value > 65535ULL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4104", "65535", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeShortSlong8(int64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4107", "0", checkpoints_buf);
  if (value < 0LL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%lld", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4109", "65535", checkpoints_buf);
    if (value > 65535LL) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%lld", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4109", "65535", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4107", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortShort(uint16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 32767);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4112", "32767", checkpoints_buf);
  if ((int )value > 32767) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 32767);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4112", "32767", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortLong(uint32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%u", 32767);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4115", "32767", checkpoints_buf);
  if (value > 32767U) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%u", 32767);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4115", "32767", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortSlong(int32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%d", -32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4118", "-32768", checkpoints_buf);
  if (value < -32768) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%d", 32767);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4120", "32767", checkpoints_buf);
    if (value > 32767) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%d", 32767);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4120", "32767", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", -32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4118", "-32768", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortLong8(uint64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%llu", 32767);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4123", "32767", checkpoints_buf);
  if (value > 32767ULL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%llu", 32767);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4123", "32767", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSshortSlong8(int64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%lld", -32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4126", "-32768", checkpoints_buf);
  if (value < -32768LL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%lld", 32767);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4128", "32767", checkpoints_buf);
    if (value > 32767LL) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%lld", 32767);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4128", "32767", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", -32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4126", "-32768", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSbyte(int8 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4131", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4131", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSshort(int16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4134", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4134", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSlong(int32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4137", "0", checkpoints_buf);
  if (value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4137", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongLong8(uint64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%llu", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4140", "4294967295", checkpoints_buf);
  if (value > 4294967295ULL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%llu", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4140", "4294967295", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLongSlong8(int64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4143", "0", checkpoints_buf);
  if (value < 0LL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%lld", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4145", "4294967295", checkpoints_buf);
    if (value > 4294967295LL) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%lld", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4145", "4294967295", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4143", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlongLong(uint32 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%ul", 2147483647);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4148", "2147483647", checkpoints_buf);
  if ((unsigned long )value > 2147483647UL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%ul", 2147483647);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4148", "2147483647", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlongLong8(uint64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%llu", 2147483647);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4151", "2147483647", checkpoints_buf);
  if (value > 2147483647ULL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%llu", 2147483647);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4151", "2147483647", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlongSlong8(int64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%lld", 2147483648);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4154", "2147483648", checkpoints_buf);
  if (value < 2147483648LL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {

    sprintf(checkpoints_buf, "%lld", 2147483647);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4156", "2147483647", checkpoints_buf);
    if (value > 2147483647LL) {
      return ((enum TIFFReadDirEntryErr )4);
    } else {
      return ((enum TIFFReadDirEntryErr )0);
    }

    sprintf(checkpoints_buf, "%lld", 2147483647);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4156", "2147483647", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", 2147483648);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4154", "2147483648", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Sbyte(int8 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4159", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4159", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Sshort(int16 value ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4162", "0", checkpoints_buf);
  if ((int )value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4162", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Slong(int32 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4165", "0", checkpoints_buf);
  if (value < 0) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4165", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeLong8Slong8(int64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4168", "0", checkpoints_buf);
  if (value < 0LL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%lld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4168", "0", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryCheckRangeSlong8Long8(uint64 value ) 
{ 


  {

  sprintf(checkpoints_buf, "%llu", 9223372036854775807);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4171", "9223372036854775807", checkpoints_buf);
  if (value > 9223372036854775807ULL) {
    return ((enum TIFFReadDirEntryErr )4);
  } else {
    return ((enum TIFFReadDirEntryErr )0);
  }

  sprintf(checkpoints_buf, "%llu", 9223372036854775807);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4171", "9223372036854775807", checkpoints_buf);
}
}
static enum TIFFReadDirEntryErr TIFFReadDirEntryData(TIFF *tif , uint64 offset ,
                                                     tmsize_t size , void *dest ) 
{ 
  uint64 tmp ;
  tmsize_t tmp___0 ;
  tmsize_t ma ;
  tmsize_t mb ;

  {

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4174", "0", checkpoints_buf);
  if (size > 0L) {

  } else {

    __assert_fail("size>0", "tif_dirread.c", 3224U, "TIFFReadDirEntryData");

  }

  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4174", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4177", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4177", "0", checkpoints_buf);
  if (! ((tif->tif_flags & 2048U) != 0U)) {


    tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, offset, 0);




    if (tmp == offset) {

    } else {
      return ((enum TIFFReadDirEntryErr )3);
    }




    tmp___0 = (*(tif->tif_readproc))(tif->tif_clientdata, dest, size);




    if (tmp___0 == size) {

    } else {
      return ((enum TIFFReadDirEntryErr )3);
    }


  } else {
    ma = (tmsize_t )offset;

    mb = ma + size;


    if ((uint64 )ma != offset) {
      return ((enum TIFFReadDirEntryErr )3);
    } else {


      if (mb < ma) {
        return ((enum TIFFReadDirEntryErr )3);
      } else {


        if (mb < size) {
          return ((enum TIFFReadDirEntryErr )3);
        } else {


          if (mb > tif->tif_size) {
            return ((enum TIFFReadDirEntryErr )3);
          } else {

          }


        }


      }


    }


    _TIFFmemcpy(dest, (void const   *)(tif->tif_base + ma), size);

  }

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4177", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4177", "0", checkpoints_buf);
  return ((enum TIFFReadDirEntryErr )0);
}
}
static void TIFFReadDirEntryOutputErr(TIFF *tif , enum TIFFReadDirEntryErr err ,
                                      char const   *module ,
                                      char const   *tagname , int recover ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", recover);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4199", "recover", checkpoints_buf);
  if (! recover) {
    switch ((unsigned int )err) {

    case 1U: 
    TIFFErrorExt(tif->tif_clientdata, module, "Incorrect count for \"%s\"",
                 tagname);

    break;

    case 2U: 
    TIFFErrorExt(tif->tif_clientdata, module, "Incompatible type for \"%s\"",
                 tagname);

    break;

    case 3U: 
    TIFFErrorExt(tif->tif_clientdata, module,
                 "IO error during reading of \"%s\"", tagname);

    break;

    case 4U: 
    TIFFErrorExt(tif->tif_clientdata, module, "Incorrect value for \"%s\"",
                 tagname);

    break;

    case 5U: 
    TIFFErrorExt(tif->tif_clientdata, module,
                 "Cannot handle different values per sample for \"%s\"", tagname);

    break;

    case 6U: 
    TIFFErrorExt(tif->tif_clientdata, module,
                 "Sanity check on size of \"%s\" value failed", tagname);

    break;

    case 7U: 
    TIFFErrorExt(tif->tif_clientdata, module, "Out of memory reading of \"%s\"",
                 tagname);

    break;

    default: 
    __assert_fail("0", "tif_dirread.c", 3281U, "TIFFReadDirEntryOutputErr");

    break;
    }
  } else {
    switch ((unsigned int )err) {

    case 1U: 
    TIFFErrorExt(tif->tif_clientdata, module,
                 "Incorrect count for \"%s\"; tag ignored", tagname);

    break;

    case 2U: 
    TIFFWarningExt(tif->tif_clientdata, module,
                   "Incompatible type for \"%s\"; tag ignored", tagname);

    break;

    case 3U: 
    TIFFWarningExt(tif->tif_clientdata, module,
                   "IO error during reading of \"%s\"; tag ignored", tagname);

    break;

    case 4U: 
    TIFFWarningExt(tif->tif_clientdata, module,
                   "Incorrect value for \"%s\"; tag ignored", tagname);

    break;

    case 5U: 
    TIFFWarningExt(tif->tif_clientdata, module,
                   "Cannot handle different values per sample for \"%s\"; tag ignored",
                   tagname);

    break;

    case 6U: 
    TIFFWarningExt(tif->tif_clientdata, module,
                   "Sanity check on size of \"%s\" value failed; tag ignored",
                   tagname);

    break;

    case 7U: 
    TIFFWarningExt(tif->tif_clientdata, module,
                   "Out of memory reading of \"%s\"; tag ignored", tagname);

    break;

    default: 
    __assert_fail("0", "tif_dirread.c", 3322U, "TIFFReadDirEntryOutputErr");

    break;
    }
  }
  sprintf(checkpoints_buf, "%d", recover);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4199", "recover", checkpoints_buf);
  return;
}
}
int TIFFReadDirectory(TIFF *tif ) ;
static char const   module[18]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'D',      (char const   )'i',      (char const   )'r',      (char const   )'e', 
        (char const   )'c',      (char const   )'t',      (char const   )'o',      (char const   )'r', 
        (char const   )'y',      (char const   )'\000'};
int TIFFReadDirectory(TIFF *tif ) 
{ 
  TIFFDirEntry *dir ;
  uint16 dircount ;
  TIFFDirEntry *dp ;
  uint16 di ;
  TIFFField const   *fip ;
  uint32 fii ;
  toff_t nextdiroff ;
  int tmp ;
  int tmp___0 ;
  uint16 value ;
  enum TIFFReadDirEntryErr err ;
  int tmp___1 ;
  int tmp___2 ;
  TIFFField *tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  char const   *tmp___6 ;
  char const   *tmp___7 ;
  uint16 value___0 ;
  enum TIFFReadDirEntryErr err___0 ;
  TIFFField const   *tmp___8 ;
  int tmp___9 ;
  double value___1 ;
  enum TIFFReadDirEntryErr err___1 ;
  TIFFField const   *tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  int tmp___13 ;
  enum TIFFReadDirEntryErr err___2 ;
  uint32 countpersample ;
  uint32 countrequired ;
  uint32 incrementpersample ;
  uint16 *value___2 ;
  TIFFField const   *tmp___14 ;
  uint16 valueo ;
  uint32 value___3 ;
  enum TIFFReadDirEntryErr tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  TIFFField const   *tmp___20 ;
  int tmp___21 ;
  TIFFField const   *tmp___22 ;
  int tmp___23 ;
  TIFFField const   *tmp___24 ;
  int tmp___25 ;
  uint64 tmp___26 ;
  uint64 tmp___27 ;
  uint32 strip ;
  tmsize_t tmp___28 ;

  {
  tif->tif_diroff = tif->tif_nextdiroff;

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4236", "tmp", checkpoints_buf);

  tmp = TIFFCheckDirOffset(tif, tif->tif_nextdiroff);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4236", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4237", "tmp", checkpoints_buf);
  if (tmp) {

  } else {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4239", "0", checkpoints_buf);
    return (0);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4237", "tmp", checkpoints_buf);

  (*(tif->tif_cleanup))(tif);

  tif->tif_curdir = (uint16 )((int )tif->tif_curdir + 1);

  nextdiroff = tif->tif_nextdiroff;



  dircount = TIFFFetchDirectory(tif, nextdiroff, & dir, & tif->tif_nextdiroff);



  if (! dircount) {

    TIFFErrorExt(tif->tif_clientdata, module,
                 "Failed to read directory at offset %llu", nextdiroff);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4246", "0", checkpoints_buf);
    return (0);
  } else {

  }


  TIFFReadDirectoryCheckOrder(tif, dir, dircount);

  tif->tif_flags &= 4294967231U;


  TIFFFreeDirectory(tif);


  TIFFDefaultDirectory(tif);


  TIFFSetField(tif, (uint32 )284, 1);



  dp = TIFFReadDirectoryFindEntry(tif, dir, dircount, (uint16 )277);



  if (dp) {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4255", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFFetchNormalTag(tif, dp, 0);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4255", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4256", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      goto bad;
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4256", "tmp___0", checkpoints_buf);
    dp->tdir_tag = (uint16 )0;

  } else {

  }



  dp = TIFFReadDirectoryFindEntry(tif, dir, dircount, (uint16 )259);



  if (dp) {


    err = TIFFReadDirEntryShort(tif, dp, & value);


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4264", "1", checkpoints_buf);
    if ((unsigned int )err == 1U) {


      err = TIFFReadDirEntryPersampleShort(tif, dp, & value);


    } else {

    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4264", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4267", "0", checkpoints_buf);
    if ((unsigned int )err != 0U) {

      TIFFReadDirEntryOutputErr(tif, err, module, "Compression", 0);

      goto bad;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4267", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4271", "tmp___1", checkpoints_buf);

    tmp___1 = TIFFSetField(tif, (uint32 )259, (int )value);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4271", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4272", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {
      goto bad;
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4272", "tmp___1", checkpoints_buf);
    dp->tdir_tag = (uint16 )0;

  } else {
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4276", "tmp___2", checkpoints_buf);

    tmp___2 = TIFFSetField(tif, (uint32 )259, 1);
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4276", "tmp___2", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4277", "tmp___2", checkpoints_buf);
    if (tmp___2) {

    } else {
      goto bad;
    }
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4277", "tmp___2", checkpoints_buf);
  }

  di = (uint16 )0;

  dp = dir;

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4282", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4282", "0", checkpoints_buf);


  while ((int )di < (int )dircount) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4286", "0", checkpoints_buf);
    if ((int )dp->tdir_tag != 0) {

      TIFFReadDirectoryFindFieldInfo(tif, dp->tdir_tag, & fii);


      sprintf(checkpoints_buf, "%u", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4288", "4294967295", checkpoints_buf);
      if (fii == 4294967295U) {

        TIFFWarningExt(tif->tif_clientdata, module,
                       "Unknown field with tag %d (0x%x) encountered",
                       (int )dp->tdir_tag, (int )dp->tdir_tag);



        tmp___3 = _TIFFCreateAnonField(tif, (uint32 )dp->tdir_tag,
                                       (TIFFDataType )dp->tdir_type);


        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4291", "tmp___4", checkpoints_buf);

        tmp___4 = _TIFFMergeFields(tif, (TIFFField const   *)tmp___3, (uint32 )1);
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4291", "tmp___4", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4292", "tmp___4", checkpoints_buf);
        if (tmp___4) {

          TIFFReadDirectoryFindFieldInfo(tif, dp->tdir_tag, & fii);


          sprintf(checkpoints_buf, "%u", 4294967295);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4294", "4294967295", checkpoints_buf);
          if (fii != 4294967295U) {

          } else {

            __assert_fail("fii!=(uint32)(-1)", "tif_dirread.c", 3446U,
                          "TIFFReadDirectory");

          }

          sprintf(checkpoints_buf, "%u", 4294967295);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4294", "4294967295", checkpoints_buf);
        } else {

          TIFFWarningExt(tif->tif_clientdata, module,
                         "Registering anonymous field with tag %d (0x%x) failed",
                         (int )dp->tdir_tag, (int )dp->tdir_tag);

          dp->tdir_tag = (uint16 )0;

        }
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4292", "tmp___4", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%u", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4288", "4294967295", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4286", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4301", "0", checkpoints_buf);
    if ((int )dp->tdir_tag != 0) {
      fip = (TIFFField const   *)*(tif->tif_fields + fii);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4303", "0", checkpoints_buf);
      if ((int const   )fip->field_bit == 0) {
        dp->tdir_tag = (uint16 )0;

      } else {
        switch ((int )dp->tdir_tag) {
        case 325: 
        case 324: 
        case 279: 
        case 273: 
        tif->tif_dir.td_fieldsset[(int const   )fip->field_bit / 32] |= 1UL << ((int const   )fip->field_bit & 31);

        break;
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4308", "tmp___5", checkpoints_buf);

        case 338: 
        case 278: 
        case 284: 
        case 32998: 
        case 322: 
        case 323: 
        case 32997: 
        case 257: 
        case 256: 
        tmp___5 = TIFFFetchNormalTag(tif, dp, 0);
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4308", "tmp___5", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4309", "tmp___5", checkpoints_buf);
        if (tmp___5) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4309", "tmp___5", checkpoints_buf);
        dp->tdir_tag = (uint16 )0;

        break;
        }
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4303", "0", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4301", "0", checkpoints_buf);
    di = (uint16 )((int )di + 1);

    dp ++;

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4282", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4282", "0", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4317", "6", checkpoints_buf);
  if ((int )tif->tif_dir.td_compression == 6) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4318", "2", checkpoints_buf);
    if ((int )tif->tif_dir.td_planarconfig == 2) {


      dp = TIFFReadDirectoryFindEntry(tif, dir, dircount, (uint16 )273);


      if ((unsigned int )dp != (unsigned int )((TIFFDirEntry *)0)) {

        sprintf(checkpoints_buf, "%llu", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4321", "1", checkpoints_buf);
        if (dp->tdir_count == 1ULL) {


          dp = TIFFReadDirectoryFindEntry(tif, dir, dircount, (uint16 )279);


          if ((unsigned int )dp != (unsigned int )((TIFFDirEntry *)0)) {

            sprintf(checkpoints_buf, "%llu", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4324", "1", checkpoints_buf);
            if (dp->tdir_count == 1ULL) {
              tif->tif_dir.td_planarconfig = (uint16 )1;


              TIFFWarningExt(tif->tif_clientdata, module,
                             "Planarconfig tag value assumed incorrect, assuming data is contig instead of chunky");

            } else {

            }

            sprintf(checkpoints_buf, "%llu", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4324", "1", checkpoints_buf);
          } else {

          }
        } else {

        }

        sprintf(checkpoints_buf, "%llu", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4321", "1", checkpoints_buf);
      } else {

      }
    } else {

    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4318", "2", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4317", "6", checkpoints_buf);

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4333", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4333", "1", checkpoints_buf);
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 1))) {

    MissingRequired(tif, "ImageLength");

    goto bad;
  } else {

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4333", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4333", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4337", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4337", "2", checkpoints_buf);
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 2))) {


    tif->tif_dir.td_nstrips = TIFFNumberOfStrips(tif);


    tif->tif_dir.td_tilewidth = tif->tif_dir.td_imagewidth;

    tif->tif_dir.td_tilelength = tif->tif_dir.td_rowsperstrip;

    tif->tif_dir.td_tiledepth = tif->tif_dir.td_imagedepth;

    tif->tif_flags &= 4294966271U;

  } else {


    tif->tif_dir.td_nstrips = TIFFNumberOfTiles(tif);


    tif->tif_flags |= 1024U;

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4337", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4337", "2", checkpoints_buf);

  if (! tif->tif_dir.td_nstrips) {

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4346", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4346", "0", checkpoints_buf);
    if ((tif->tif_flags & 1024U) != 0U) {
      tmp___6 = "tiles";

    } else {
      tmp___6 = "strips";

    }

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4346", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4346", "0", checkpoints_buf);

    TIFFErrorExt(tif->tif_clientdata, module, "Cannot handle zero number of %s",
                 tmp___6);

    goto bad;
  } else {

  }

  tif->tif_dir.td_stripsperimage = tif->tif_dir.td_nstrips;

  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4353", "2", checkpoints_buf);
  if ((int )tif->tif_dir.td_planarconfig == 2) {
    tif->tif_dir.td_stripsperimage /= (uint32 )tif->tif_dir.td_samplesperpixel;

  } else {

  }
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4353", "2", checkpoints_buf);

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4356", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 25);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4356", "25", checkpoints_buf);
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 25))) {
    sprintf(checkpoints_buf, "%d", 6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4357", "6", checkpoints_buf);
    if ((int )tif->tif_dir.td_compression == 6) {

      sprintf(checkpoints_buf, "%u", 1024);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4358", "1024", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4358", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4358", "0", checkpoints_buf);
      if (((tif->tif_flags & 1024U) != 0U) == 0) {

        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4359", "1", checkpoints_buf);
        if (tif->tif_dir.td_nstrips == 1U) {
          tif->tif_dir.td_fieldsset[0] |= 1UL << 25;

        } else {
          goto _L___0;
        }

        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4359", "1", checkpoints_buf);
      } else {
        goto _L___0;
      }

      sprintf(checkpoints_buf, "%u", 1024);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4358", "1024", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4358", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4358", "0", checkpoints_buf);
    } else {

      sprintf(checkpoints_buf, "%u", 1024);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4363", "1024", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4363", "0", checkpoints_buf);
      _L___0: /* CIL Label */ 
      _L: /* CIL Label */ 
      if ((tif->tif_flags & 1024U) != 0U) {
        tmp___7 = "TileOffsets";

      } else {
        tmp___7 = "StripOffsets";

      }

      sprintf(checkpoints_buf, "%u", 1024);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4363", "1024", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4363", "0", checkpoints_buf);

      MissingRequired(tif, tmp___7);

      goto bad;
    }
    sprintf(checkpoints_buf, "%d", 6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4357", "6", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4356", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 25);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4356", "25", checkpoints_buf);
  di = (uint16 )0;

  dp = dir;



  while ((int )di < (int )dircount) {
    switch ((int )dp->tdir_tag) {
    case 0: 
    break;


    case 339: 
    case 32996: 
    case 258: 
    case 281: 
    case 280: 
    err___0 = TIFFReadDirEntryShort(tif, dp, & value___0);


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4378", "1", checkpoints_buf);
    if ((unsigned int )err___0 == 1U) {


      err___0 = TIFFReadDirEntryPersampleShort(tif, dp, & value___0);


    } else {

    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4378", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4381", "0", checkpoints_buf);
    if ((unsigned int )err___0 != 0U) {


      tmp___8 = TIFFFieldWithTag(tif, (uint32 )dp->tdir_tag);



      TIFFReadDirEntryOutputErr(tif, err___0, module,
                                (char const   *)tmp___8->field_name, 0);

      goto bad;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4381", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4386", "tmp___9", checkpoints_buf);

    tmp___9 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (int )value___0);
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4386", "tmp___9", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4387", "tmp___9", checkpoints_buf);
    if (tmp___9) {

    } else {
      goto bad;
    }
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4387", "tmp___9", checkpoints_buf);
    break;


    case 341: 
    case 340: 
    err___1 = TIFFReadDirEntryPersampleDouble(tif, dp, & value___1);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4392", "0", checkpoints_buf);
    if ((unsigned int )err___1 != 0U) {


      tmp___10 = TIFFFieldWithTag(tif, (uint32 )dp->tdir_tag);



      TIFFReadDirEntryOutputErr(tif, err___1, module,
                                (char const   *)tmp___10->field_name, 0);

      goto bad;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4392", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4397", "tmp___11", checkpoints_buf);

    tmp___11 = TIFFSetField(tif, (uint32 )dp->tdir_tag, value___1);
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4397", "tmp___11", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4398", "tmp___11", checkpoints_buf);
    if (tmp___11) {

    } else {
      goto bad;
    }
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4398", "tmp___11", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%d", tmp___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4402", "tmp___12", checkpoints_buf);

    case 324: 
    case 273: 
    tmp___12 = TIFFFetchStripThing(tif, dp, tif->tif_dir.td_nstrips,
                                   & tif->tif_dir.td_stripoffset);
    sprintf(checkpoints_buf, "%d", tmp___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4402", "tmp___12", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4403", "tmp___12", checkpoints_buf);
    if (tmp___12) {

    } else {
      goto bad;
    }
    sprintf(checkpoints_buf, "%d", tmp___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4403", "tmp___12", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4407", "tmp___13", checkpoints_buf);

    case 325: 
    case 279: 
    tmp___13 = TIFFFetchStripThing(tif, dp, tif->tif_dir.td_nstrips,
                                   & tif->tif_dir.td_stripbytecount);
    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4407", "tmp___13", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4408", "tmp___13", checkpoints_buf);
    if (tmp___13) {

    } else {
      goto bad;
    }
    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4408", "tmp___13", checkpoints_buf);
    break;
    case 301: 
    case 320: 
    countpersample = (uint32 )(1L << (int )tif->tif_dir.td_bitspersample);

    sprintf(checkpoints_buf, "%d", 301);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4413", "301", checkpoints_buf);
    if ((int )dp->tdir_tag == 301) {

      if (dp->tdir_count == (uint64 )countpersample) {
        countrequired = countpersample;

        incrementpersample = (uint32 )0;

      } else {
        countrequired = 3U * countpersample;

        incrementpersample = countpersample;

      }

    } else {
      countrequired = 3U * countpersample;

      incrementpersample = countpersample;

    }
    sprintf(checkpoints_buf, "%d", 301);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4413", "301", checkpoints_buf);

    if (dp->tdir_count != (uint64 )countrequired) {
      err___2 = (enum TIFFReadDirEntryErr )1;

    } else {


      err___2 = TIFFReadDirEntryShortArray(tif, dp, & value___2);


    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4424", "0", checkpoints_buf);
    if ((unsigned int )err___2 != 0U) {


      tmp___14 = TIFFFieldWithTag(tif, (uint32 )dp->tdir_tag);



      TIFFReadDirEntryOutputErr(tif, err___2, module,
                                (char const   *)tmp___14->field_name, 1);

    } else {

      TIFFSetField(tif, (uint32 )dp->tdir_tag, value___2,
                   value___2 + incrementpersample,
                   value___2 + 2U * incrementpersample);


      _TIFFfree((void *)value___2);

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4424", "0", checkpoints_buf);
    break;


    case 255: 
    tmp___15 = TIFFReadDirEntryShort(tif, dp, & valueo);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4431", "0", checkpoints_buf);
    if ((unsigned int )tmp___15 == 0U) {
      switch ((int )valueo) {
      case 2: 
      value___3 = (uint32 )1;

      break;
      case 3: 
      value___3 = (uint32 )2;

      break;
      default: 
      value___3 = (uint32 )0;

      break;
      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4439", "0", checkpoints_buf);
      if (value___3 != 0U) {

        TIFFSetField(tif, (uint32 )254, value___3);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4439", "0", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4431", "0", checkpoints_buf);
    break;

    default: 
    TIFFFetchNormalTag(tif, dp, 1);

    break;
    }
    di = (uint16 )((int )di + 1);

    dp ++;

  }


  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4448", "6", checkpoints_buf);
  if ((int )tif->tif_dir.td_compression == 6) {

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4449", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4449", "8", checkpoints_buf);
    if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 8))) {

      TIFFWarningExt(tif->tif_clientdata, module,
                     "Photometric tag is missing, assuming data is YCbCr");

      sprintf(checkpoints_buf, "%d", tmp___16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4451", "tmp___16", checkpoints_buf);

      tmp___16 = TIFFSetField(tif, (uint32 )262, 6);
      sprintf(checkpoints_buf, "%d", tmp___16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4451", "tmp___16", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4452", "tmp___16", checkpoints_buf);
      if (tmp___16) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4452", "tmp___16", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4455", "2", checkpoints_buf);
      if ((int )tif->tif_dir.td_photometric == 2) {
        tif->tif_dir.td_photometric = (uint16 )6;


        TIFFWarningExt(tif->tif_clientdata, module,
                       "Photometric tag value assumed incorrect, assuming data is YCbCr instead of RGB");

      } else {

      }
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4455", "2", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4449", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4449", "8", checkpoints_buf);

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4459", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4459", "6", checkpoints_buf);
    if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 6))) {

      TIFFWarningExt(tif->tif_clientdata, module,
                     "BitsPerSample tag is missing, assuming 8 bits per sample");

      sprintf(checkpoints_buf, "%d", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4461", "tmp___17", checkpoints_buf);

      tmp___17 = TIFFSetField(tif, (uint32 )258, 8);
      sprintf(checkpoints_buf, "%d", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4461", "tmp___17", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4462", "tmp___17", checkpoints_buf);
      if (tmp___17) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4462", "tmp___17", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4459", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4459", "6", checkpoints_buf);

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4466", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4466", "16", checkpoints_buf);
    if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 16))) {
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4467", "2", checkpoints_buf);
      if ((int )tif->tif_dir.td_photometric == 2) {
        goto _L___2;
      } else {
        sprintf(checkpoints_buf, "%d", 6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4469", "6", checkpoints_buf);
        if ((int )tif->tif_dir.td_photometric == 6) {

          _L___2: /* CIL Label */ 
          TIFFWarningExt(tif->tif_clientdata, module,
                         "SamplesPerPixel tag is missing, assuming correct SamplesPerPixel value is 3");

          sprintf(checkpoints_buf, "%d", tmp___18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4471", "tmp___18", checkpoints_buf);

          tmp___18 = TIFFSetField(tif, (uint32 )277, 3);
          sprintf(checkpoints_buf, "%d", tmp___18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4471", "tmp___18", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4472", "tmp___18", checkpoints_buf);
          if (tmp___18) {

          } else {
            goto bad;
          }
          sprintf(checkpoints_buf, "%d", tmp___18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4472", "tmp___18", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4475", "0", checkpoints_buf);
          if ((int )tif->tif_dir.td_photometric == 0) {
            goto _L___1;
          } else {
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4477", "1", checkpoints_buf);
            if ((int )tif->tif_dir.td_photometric == 1) {

              _L___1: /* CIL Label */ 
              TIFFWarningExt(tif->tif_clientdata, module,
                             "SamplesPerPixel tag is missing, assuming correct SamplesPerPixel value is 1");

              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4479", "tmp___19", checkpoints_buf);

              tmp___19 = TIFFSetField(tif, (uint32 )277, 1);
              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4479", "tmp___19", checkpoints_buf);

              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4480", "tmp___19", checkpoints_buf);
              if (tmp___19) {

              } else {
                goto bad;
              }
              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4480", "tmp___19", checkpoints_buf);
            } else {

            }
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4477", "1", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4475", "0", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4469", "6", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4467", "2", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4466", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4466", "16", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4448", "6", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4486", "3", checkpoints_buf);
  if ((int )tif->tif_dir.td_photometric == 3) {

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4487", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 26);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4487", "26", checkpoints_buf);
    if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 26))) {

      MissingRequired(tif, "Colormap");

      goto bad;
    } else {

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4487", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 26);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4487", "26", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4486", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4492", "6", checkpoints_buf);
  if ((int )tif->tif_dir.td_compression != 6) {

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4493", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4493", "24", checkpoints_buf);
    if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 24))) {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4494", "1", checkpoints_buf);
      if ((int )tif->tif_dir.td_planarconfig == 1) {

        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4495", "1", checkpoints_buf);
        if (tif->tif_dir.td_nstrips > 1U) {

          MissingRequired(tif, "StripByteCounts");

          goto bad;
        } else {
          goto _L___3;
        }

        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4495", "1", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4499", "2", checkpoints_buf);
        _L___3: /* CIL Label */ 
        if ((int )tif->tif_dir.td_planarconfig == 2) {

          if (tif->tif_dir.td_nstrips != (uint32 )tif->tif_dir.td_samplesperpixel) {

            MissingRequired(tif, "StripByteCounts");

            goto bad;
          } else {

          }

        } else {

        }
        sprintf(checkpoints_buf, "%d", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4499", "2", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4494", "1", checkpoints_buf);


      tmp___20 = TIFFFieldWithTag(tif, (uint32 )279);



      TIFFWarningExt(tif->tif_clientdata, module,
                     "TIFF directory is missing required \"%s\" field, calculating from imagelength",
                     tmp___20->field_name);

      sprintf(checkpoints_buf, "%d", tmp___21);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4507", "tmp___21", checkpoints_buf);

      tmp___21 = EstimateStripByteCounts(tif, dir, dircount);
      sprintf(checkpoints_buf, "%d", tmp___21);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4507", "tmp___21", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___21);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4508", "tmp___21", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4508", "0", checkpoints_buf);
      if (tmp___21 < 0) {
        goto bad;
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___21);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4508", "tmp___21", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4508", "0", checkpoints_buf);
    } else {

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4511", "1", checkpoints_buf);
      if (tif->tif_dir.td_nstrips == 1U) {

        sprintf(checkpoints_buf, "%llu", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4512", "0", checkpoints_buf);
        if (*(tif->tif_dir.td_stripoffset + 0) != 0ULL) {

          sprintf(checkpoints_buf, "%llu", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4513", "0", checkpoints_buf);
          if (*(tif->tif_dir.td_stripbytecount + 0) == 0ULL) {

            sprintf(checkpoints_buf, "%llu", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4514", "0", checkpoints_buf);
            if (*(tif->tif_dir.td_stripoffset + 0) != 0ULL) {
              goto _L___5;
            } else {
              goto _L___7;
            }

            sprintf(checkpoints_buf, "%llu", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4514", "0", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4517", "1", checkpoints_buf);
            _L___7: /* CIL Label */ 
            if ((int )tif->tif_dir.td_compression == 1) {


              tmp___26 = (*(tif->tif_sizeproc))(tif->tif_clientdata);





              if (*(tif->tif_dir.td_stripbytecount + 0) > tmp___26 - *(tif->tif_dir.td_stripoffset + 0)) {
                goto _L___5;
              } else {
                goto _L___6;
              }



            } else {

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4522", "0", checkpoints_buf);
              _L___6: /* CIL Label */ 
              if (tif->tif_mode == 0) {
                sprintf(checkpoints_buf, "%d", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "4523", "1", checkpoints_buf);
                if ((int )tif->tif_dir.td_compression == 1) {


                  tmp___27 = TIFFScanlineSize64(tif);




                  if (*(tif->tif_dir.td_stripbytecount + 0) < tmp___27 * (uint64 )tif->tif_dir.td_imagelength) {


                    _L___5: /* CIL Label */ 
                    tmp___22 = TIFFFieldWithTag(tif, (uint32 )279);



                    TIFFWarningExt(tif->tif_clientdata, module,
                                   "Bogus \"%s\" field, ignoring and calculating from imagelength",
                                   tmp___22->field_name);

                    sprintf(checkpoints_buf, "%d", tmp___23);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4528", "tmp___23", checkpoints_buf);

                    tmp___23 = EstimateStripByteCounts(tif, dir, dircount);
                    sprintf(checkpoints_buf, "%d", tmp___23);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4528", "tmp___23", checkpoints_buf);

                    sprintf(checkpoints_buf, "%d", tmp___23);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4529", "tmp___23", checkpoints_buf);
                    sprintf(checkpoints_buf, "%d", 0);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4529", "0", checkpoints_buf);
                    if (tmp___23 < 0) {
                      goto bad;
                    } else {

                    }
                    sprintf(checkpoints_buf, "%d", tmp___23);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4529", "tmp___23", checkpoints_buf);
                    sprintf(checkpoints_buf, "%d", 0);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4529", "0", checkpoints_buf);
                  } else {
                    goto _L___8;
                  }


                } else {
                  goto _L___8;
                }
                sprintf(checkpoints_buf, "%d", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "4523", "1", checkpoints_buf);
              } else {
                goto _L___8;
              }

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4522", "0", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4517", "1", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%llu", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4513", "0", checkpoints_buf);
        } else {
          goto _L___8;
        }

        sprintf(checkpoints_buf, "%llu", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4512", "0", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4536", "1", checkpoints_buf);
        _L___8: /* CIL Label */ 
        _L___4: /* CIL Label */ 
        if ((int )tif->tif_dir.td_planarconfig == 1) {

          sprintf(checkpoints_buf, "%u", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4537", "2", checkpoints_buf);
          if (tif->tif_dir.td_nstrips > 2U) {
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4538", "1", checkpoints_buf);
            if ((int )tif->tif_dir.td_compression == 1) {


              if (*(tif->tif_dir.td_stripbytecount + 0) != *(tif->tif_dir.td_stripbytecount + 1)) {

                sprintf(checkpoints_buf, "%llu", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "4540", "0", checkpoints_buf);
                if (*(tif->tif_dir.td_stripbytecount + 0) != 0ULL) {

                  sprintf(checkpoints_buf, "%llu", 0);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "4541", "0", checkpoints_buf);
                  if (*(tif->tif_dir.td_stripbytecount + 1) != 0ULL) {


                    tmp___24 = TIFFFieldWithTag(tif, (uint32 )279);



                    TIFFWarningExt(tif->tif_clientdata, module,
                                   "Wrong \"%s\" field, ignoring and calculating from imagelength",
                                   tmp___24->field_name);

                    sprintf(checkpoints_buf, "%d", tmp___25);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4544", "tmp___25", checkpoints_buf);

                    tmp___25 = EstimateStripByteCounts(tif, dir, dircount);
                    sprintf(checkpoints_buf, "%d", tmp___25);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4544", "tmp___25", checkpoints_buf);

                    sprintf(checkpoints_buf, "%d", tmp___25);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4545", "tmp___25", checkpoints_buf);
                    sprintf(checkpoints_buf, "%d", 0);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4545", "0", checkpoints_buf);
                    if (tmp___25 < 0) {
                      goto bad;
                    } else {

                    }
                    sprintf(checkpoints_buf, "%d", tmp___25);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4545", "tmp___25", checkpoints_buf);
                    sprintf(checkpoints_buf, "%d", 0);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "4545", "0", checkpoints_buf);
                  } else {

                  }

                  sprintf(checkpoints_buf, "%llu", 0);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "4541", "0", checkpoints_buf);
                } else {

                }

                sprintf(checkpoints_buf, "%llu", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "4540", "0", checkpoints_buf);
              } else {

              }


            } else {

            }
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4538", "1", checkpoints_buf);
          } else {

          }

          sprintf(checkpoints_buf, "%u", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4537", "2", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4536", "1", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4511", "1", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4493", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4493", "24", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4492", "6", checkpoints_buf);

  if (dir) {

    _TIFFfree((void *)dir);

    dir = (TIFFDirEntry *)((void *)0);

  } else {

  }


  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4559", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4559", "19", checkpoints_buf);
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 19))) {
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4560", "16", checkpoints_buf);
    if ((int )tif->tif_dir.td_bitspersample >= 16) {
      tif->tif_dir.td_maxsamplevalue = (uint16 )65535;

    } else {
      tif->tif_dir.td_maxsamplevalue = (uint16 )((1L << (int )tif->tif_dir.td_bitspersample) - 1L);

    }
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4560", "16", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4559", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4559", "19", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4564", "1", checkpoints_buf);
  if (tif->tif_dir.td_nstrips > 1U) {
    tif->tif_dir.td_stripbytecountsorted = 1;

    strip = (uint32 )1;






    while (strip < tif->tif_dir.td_nstrips) {




      if (*(tif->tif_dir.td_stripoffset + (strip - 1U)) > *(tif->tif_dir.td_stripoffset + strip)) {
        tif->tif_dir.td_stripbytecountsorted = 0;

        break;
      } else {

      }


      strip ++;

    }





  } else {

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4564", "1", checkpoints_buf);

  (*(tif->tif_fixuptags))(tif);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4578", "1", checkpoints_buf);
  if ((int )tif->tif_dir.td_planarconfig == 1) {

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4579", "1", checkpoints_buf);
    if (tif->tif_dir.td_nstrips == 1U) {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4580", "1", checkpoints_buf);
      if ((int )tif->tif_dir.td_compression == 1) {

        sprintf(checkpoints_buf, "%u", 33792);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4581", "33792", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 32768);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4581", "32768", checkpoints_buf);
        if ((tif->tif_flags & 33792U) == 32768U) {

          ChopUpSingleUncompressedStrip(tif);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 33792);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4581", "33792", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 32768);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4581", "32768", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4580", "1", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4579", "1", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4578", "1", checkpoints_buf);
  tif->tif_row = (uint32 )-1;

  tif->tif_curstrip = (uint32 )-1;

  tif->tif_col = (uint32 )-1;

  tif->tif_curtile = (uint32 )-1;

  tif->tif_tilesize = (tmsize_t )-1;



  tif->tif_scanlinesize = TIFFScanlineSize(tif);



  if (! tif->tif_scanlinesize) {

    TIFFErrorExt(tif->tif_clientdata, module, "Cannot handle zero scanline size");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4595", "0", checkpoints_buf);
    return (0);
  } else {

  }


  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4597", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4597", "0", checkpoints_buf);
  if ((tif->tif_flags & 1024U) != 0U) {


    tif->tif_tilesize = TIFFTileSize(tif);



    if (! tif->tif_tilesize) {

      TIFFErrorExt(tif->tif_clientdata, module, "Cannot handle zero tile size");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4601", "0", checkpoints_buf);
      return (0);
    } else {

    }

  } else {


    tmp___28 = TIFFStripSize(tif);



    if (tmp___28) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module, "Cannot handle zero strip size");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4607", "0", checkpoints_buf);
      return (0);
    }

  }

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4597", "1024", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4597", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4608", "1", checkpoints_buf);
  return (1);

  bad: 
  if (dir) {

    _TIFFfree((void *)dir);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4612", "0", checkpoints_buf);
  return (0);
}
}
static void TIFFReadDirectoryCheckOrder(TIFF *tif , TIFFDirEntry *dir ,
                                        uint16 dircount ) ;
static char const   module___0[28]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'D',      (char const   )'i',      (char const   )'r',      (char const   )'e', 
        (char const   )'c',      (char const   )'t',      (char const   )'o',      (char const   )'r', 
        (char const   )'y',      (char const   )'C',      (char const   )'h',      (char const   )'e', 
        (char const   )'c',      (char const   )'k',      (char const   )'O',      (char const   )'r', 
        (char const   )'d',      (char const   )'e',      (char const   )'r',      (char const   )'\000'};
static void TIFFReadDirectoryCheckOrder(TIFF *tif , TIFFDirEntry *dir ,
                                        uint16 dircount ) 
{ 
  uint16 m ;
  uint16 n ;
  TIFFDirEntry *o ;

  {
  m = (uint16 )0;

  n = (uint16 )0;

  o = dir;




  while ((int )n < (int )dircount) {
    if ((int )o->tdir_tag < (int )m) {

      TIFFWarningExt(tif->tif_clientdata, module___0,
                     "Invalid TIFF directory; tags are not sorted in ascending order");

      break;
    } else {

    }
    m = (uint16 )((int )o->tdir_tag + 1);

    n = (uint16 )((int )n + 1);

    o ++;

  }



  return;
}
}
static TIFFDirEntry *TIFFReadDirectoryFindEntry(TIFF *tif , TIFFDirEntry *dir ,
                                                uint16 dircount , uint16 tagid ) 
{ 
  TIFFDirEntry *m ;
  uint16 n ;

  {
  m = dir;

  n = (uint16 )0;



  while ((int )n < (int )dircount) {
    if ((int )m->tdir_tag == (int )tagid) {

      return (m);
    } else {

    }
    m ++;

    n = (uint16 )((int )n + 1);

  }


  return ((TIFFDirEntry *)0);
}
}
static void TIFFReadDirectoryFindFieldInfo(TIFF *tif , uint16 tagid ,
                                           uint32 *fii ) 
{ 
  int32 ma ;
  int32 mb ;
  int32 mc ;

  {
  ma = -1;

  mc = (int32 )tif->tif_nfields;


  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4642", "1", checkpoints_buf);




  while (1) {

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4643", "1", checkpoints_buf);

    if (ma + 1 == mc) {
      *fii = (uint32 )-1;

      return;
    } else {

    }

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4643", "1", checkpoints_buf);

    mb = (ma + mc) / 2;


    if ((*(tif->tif_fields + mb))->field_tag == (uint32 )tagid) {
      break;
    } else {

    }


    if ((*(tif->tif_fields + mb))->field_tag < (uint32 )tagid) {
      ma = mb;

    } else {
      mc = mb;

    }

  }

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4642", "1", checkpoints_buf);





  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4654", "0", checkpoints_buf);


  while (1) {

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4655", "0", checkpoints_buf);
    if (mb == 0) {
      break;
    } else {

    }

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4655", "0", checkpoints_buf);

    if ((*(tif->tif_fields + (mb - 1)))->field_tag != (uint32 )tagid) {
      break;
    } else {

    }

    mb --;

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4654", "0", checkpoints_buf);


  *fii = (uint32 )mb;

  return;
}
}
int TIFFReadCustomDirectory(TIFF *tif , uint64 diroff ,
                            TIFFFieldArray const   *infoarray ) ;
static char const   module___1[24]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'a',      (char const   )'d', 
        (char const   )'C',      (char const   )'u',      (char const   )'s',      (char const   )'t', 
        (char const   )'o',      (char const   )'m',      (char const   )'D',      (char const   )'i', 
        (char const   )'r',      (char const   )'e',      (char const   )'c',      (char const   )'t', 
        (char const   )'o',      (char const   )'r',      (char const   )'y',      (char const   )'\000'};
int TIFFReadCustomDirectory(TIFF *tif , uint64 diroff ,
                            TIFFFieldArray const   *infoarray ) 
{ 
  TIFFDirEntry *dir ;
  uint16 dircount ;
  TIFFDirEntry *dp ;
  uint16 di ;
  TIFFField const   *fip ;
  uint32 fii ;
  TIFFField *tmp ;
  int tmp___0 ;
  uint32 expected ;
  int tmp___1 ;

  {

  _TIFFSetupFields(tif, infoarray);



  dircount = TIFFFetchDirectory(tif, diroff, & dir, (uint64 *)((void *)0));



  if (! dircount) {

    TIFFErrorExt(tif->tif_clientdata, module___1,
                 "Failed to read custom directory at offset %llu", diroff);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4668", "0", checkpoints_buf);
    return (0);
  } else {

  }


  TIFFFreeDirectory(tif);


  TIFFReadDirectoryCheckOrder(tif, dir, dircount);

  di = (uint16 )0;

  dp = dir;



  sprintf(checkpoints_buf, "%u", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4674", "65535", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4674", "0", checkpoints_buf);


  while ((int )di < (int )dircount) {

    TIFFReadDirectoryFindFieldInfo(tif, dp->tdir_tag, & fii);


    sprintf(checkpoints_buf, "%u", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4679", "65535", checkpoints_buf);
    if (fii == 65535U) {

      TIFFWarningExt(tif->tif_clientdata, module___1,
                     "Unknown field with tag %d (0x%x) encountered",
                     (int )dp->tdir_tag, (int )dp->tdir_tag);



      tmp = _TIFFCreateAnonField(tif, (uint32 )dp->tdir_tag,
                                 (TIFFDataType )dp->tdir_type);


      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4682", "tmp___0", checkpoints_buf);

      tmp___0 = _TIFFMergeFields(tif, (TIFFField const   *)tmp, (uint32 )1);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4682", "tmp___0", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4683", "tmp___0", checkpoints_buf);
      if (tmp___0) {

        TIFFReadDirectoryFindFieldInfo(tif, dp->tdir_tag, & fii);


        sprintf(checkpoints_buf, "%u", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4685", "65535", checkpoints_buf);
        if (fii != 65535U) {

        } else {

          __assert_fail("fii!=0xFFFF", "tif_dirread.c", 4023U,
                        "TIFFReadCustomDirectory");

        }

        sprintf(checkpoints_buf, "%u", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4685", "65535", checkpoints_buf);
      } else {

        TIFFWarningExt(tif->tif_clientdata, module___1,
                       "Registering anonymous field with tag %d (0x%x) failed",
                       (int )dp->tdir_tag, (int )dp->tdir_tag);

        dp->tdir_tag = (uint16 )0;

      }
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4683", "tmp___0", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%u", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4679", "65535", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4691", "0", checkpoints_buf);
    if ((int )dp->tdir_tag != 0) {
      fip = (TIFFField const   *)*(tif->tif_fields + fii);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4693", "0", checkpoints_buf);
      if ((int const   )fip->field_bit == 0) {
        dp->tdir_tag = (uint16 )0;

      } else {
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4695", "0", checkpoints_buf);




        while (1) {
          sprintf(checkpoints_buf, "%u", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4696", "0", checkpoints_buf);
          if ((unsigned int const   )fip->field_type != 0U) {
            if ((unsigned int const   )fip->field_type != (unsigned int const   )dp->tdir_type) {

            } else {
              break;
            }
          } else {
            break;
          }
          sprintf(checkpoints_buf, "%u", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4696", "0", checkpoints_buf);
          fii ++;



          if (fii == tif->tif_nfields) {
            fii = (uint32 )65535;

            break;
          } else {

            if ((*(tif->tif_fields + fii))->field_tag != (uint32 )dp->tdir_tag) {
              fii = (uint32 )65535;

              break;
            } else {

            }

          }


          fip = (TIFFField const   *)*(tif->tif_fields + fii);

        }
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4695", "0", checkpoints_buf);





        sprintf(checkpoints_buf, "%u", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4710", "65535", checkpoints_buf);
        if (fii == 65535U) {

          TIFFWarningExt(tif->tif_clientdata, module___1,
                         "Wrong data type %d for \"%s\"; tag ignored",
                         (int )dp->tdir_type, fip->field_name);

          dp->tdir_tag = (uint16 )0;

        } else {
          sprintf(checkpoints_buf, "%d", -1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4713", "-1", checkpoints_buf);
          if ((int const   )fip->field_readcount != -1) {
            sprintf(checkpoints_buf, "%d", -3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4714", "-3", checkpoints_buf);
            if ((int const   )fip->field_readcount != -3) {
              sprintf(checkpoints_buf, "%d", -2);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4715", "-2", checkpoints_buf);
              if ((int const   )fip->field_readcount == -2) {
                expected = (uint32 )tif->tif_dir.td_samplesperpixel;

              } else {
                expected = (uint32 )fip->field_readcount;

              }
              sprintf(checkpoints_buf, "%d", -2);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4715", "-2", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4718", "tmp___1", checkpoints_buf);

              tmp___1 = CheckDirCount(tif, dp, expected);
              sprintf(checkpoints_buf, "%d", tmp___1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4718", "tmp___1", checkpoints_buf);

              sprintf(checkpoints_buf, "%d", tmp___1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4719", "tmp___1", checkpoints_buf);
              if (tmp___1) {

              } else {
                dp->tdir_tag = (uint16 )0;

              }
              sprintf(checkpoints_buf, "%d", tmp___1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "4719", "tmp___1", checkpoints_buf);
            } else {

            }
            sprintf(checkpoints_buf, "%d", -3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "4714", "-3", checkpoints_buf);
          } else {

          }
          sprintf(checkpoints_buf, "%d", -1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "4713", "-1", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4710", "65535", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4693", "0", checkpoints_buf);
      switch ((int )dp->tdir_tag) {

      case 37382: 
      TIFFFetchSubjectDistance(tif, dp);

      break;

      default: 
      TIFFFetchNormalTag(tif, dp, 1);

      break;
      }
    } else {

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4691", "0", checkpoints_buf);
    di = (uint16 )((int )di + 1);

    dp ++;

  }


  sprintf(checkpoints_buf, "%u", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4674", "65535", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4674", "0", checkpoints_buf);



  if (dir) {

    _TIFFfree((void *)dir);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4735", "1", checkpoints_buf);
  return (1);
}
}
int TIFFReadEXIFDirectory(TIFF *tif , uint64 diroff ) 
{ 
  TIFFFieldArray const   *exifFieldArray ;
  int tmp ;

  {


  exifFieldArray = _TIFFGetExifFields();


  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4737", "tmp", checkpoints_buf);

  tmp = TIFFReadCustomDirectory(tif, diroff, exifFieldArray);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4737", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4738", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int EstimateStripByteCounts(TIFF *tif , TIFFDirEntry *dir ,
                                   uint16 dircount ) ;
static char const   module___2[24]  = 
  {      (char const   )'E',      (char const   )'s',      (char const   )'t',      (char const   )'i', 
        (char const   )'m',      (char const   )'a',      (char const   )'t',      (char const   )'e', 
        (char const   )'S',      (char const   )'t',      (char const   )'r',      (char const   )'i', 
        (char const   )'p',      (char const   )'B',      (char const   )'y',      (char const   )'t', 
        (char const   )'e',      (char const   )'C',      (char const   )'o',      (char const   )'u', 
        (char const   )'n',      (char const   )'t',      (char const   )'s',      (char const   )'\000'};
static int EstimateStripByteCounts(TIFF *tif , TIFFDirEntry *dir ,
                                   uint16 dircount ) 
{ 
  TIFFDirEntry *dp ;
  TIFFDirectory *td ;
  uint32 strip ;
  void *tmp ;
  uint64 space ;
  uint64 filesize ;
  uint16 n ;
  uint32 typewidth ;
  int tmp___0 ;
  uint64 datasize ;
  int tmp___1 ;
  uint64 bytespertile ;
  uint64 tmp___2 ;
  uint64 rowbytes ;
  uint64 tmp___3 ;
  uint32 rowsperstrip ;

  {
  td = & tif->tif_dir;


  if (td->td_stripbytecount) {

    _TIFFfree((void *)td->td_stripbytecount);

  } else {

  }



  tmp = _TIFFCheckMalloc(tif, (tmsize_t )td->td_nstrips,
                         (tmsize_t )sizeof(uint64 ),
                         "for \"StripByteCounts\" array");


  td->td_stripbytecount = (uint64 *)tmp;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4745", "1", checkpoints_buf);
  if ((int )td->td_compression != 1) {


    filesize = (*(tif->tif_sizeproc))(tif->tif_clientdata);



    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4747", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      space = (uint64 )(((sizeof(TIFFHeaderClassic ) + 2U) + (unsigned int )((int )dircount * 12)) + 4U);

    } else {
      space = (uint64 )(((sizeof(TIFFHeaderBig ) + 8U) + (unsigned int )((int )dircount * 20)) + 8U);

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4747", "524288", checkpoints_buf);
    dp = dir;

    n = dircount;

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "tmp___0", checkpoints_buf);


    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "tmp___1", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "0", checkpoints_buf);


    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "524288", checkpoints_buf);



    while (1) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4753", "0", checkpoints_buf);
      if ((int )n > 0) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4753", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4756", "tmp___0", checkpoints_buf);

      tmp___0 = TIFFDataWidth((TIFFDataType )dp->tdir_type);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4756", "tmp___0", checkpoints_buf);

      typewidth = (uint32 )tmp___0;

      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4758", "tmp___1", checkpoints_buf);

      tmp___1 = TIFFDataWidth((TIFFDataType )dp->tdir_type);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4758", "tmp___1", checkpoints_buf);

      typewidth = (uint32 )tmp___1;


      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4760", "0", checkpoints_buf);
      if (typewidth == 0U) {

        TIFFErrorExt(tif->tif_clientdata, module___2,
                     "Cannot determine size of unknown tag type %d",
                     (int )dp->tdir_type);

        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4762", "-1", checkpoints_buf);
        return (-1);
      } else {

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4760", "0", checkpoints_buf);
      datasize = (uint64 )typewidth * dp->tdir_count;


      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4765", "524288", checkpoints_buf);
      if (! (tif->tif_flags & 524288U)) {

        sprintf(checkpoints_buf, "%llu", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4766", "4", checkpoints_buf);
        if (datasize <= 4ULL) {
          datasize = (uint64 )0;

        } else {

        }

        sprintf(checkpoints_buf, "%llu", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4766", "4", checkpoints_buf);
      } else {

        sprintf(checkpoints_buf, "%llu", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4769", "8", checkpoints_buf);
        if (datasize <= 8ULL) {
          datasize = (uint64 )0;

        } else {

        }

        sprintf(checkpoints_buf, "%llu", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4769", "8", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4765", "524288", checkpoints_buf);
      space += datasize;

      n = (uint16 )((int )n - 1);

      dp ++;

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "tmp___0", checkpoints_buf);


    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "tmp___1", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "0", checkpoints_buf);


    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4752", "524288", checkpoints_buf);



    space = filesize - space;

    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4776", "2", checkpoints_buf);
    if ((int )td->td_planarconfig == 2) {
      space /= (uint64 )td->td_samplesperpixel;

    } else {

    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4776", "2", checkpoints_buf);
    strip = (uint32 )0;





    while (strip < td->td_nstrips) {


      *(td->td_stripbytecount + strip) = space;

      strip ++;

    }




    strip --;




    if (*(td->td_stripoffset + strip) + *(td->td_stripbytecount + strip) > filesize) {
      *(td->td_stripbytecount + strip) = filesize - *(td->td_stripoffset + strip);

    } else {

    }



  } else {

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4790", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4790", "0", checkpoints_buf);
    if ((tif->tif_flags & 1024U) != 0U) {


      tmp___2 = TIFFTileSize64(tif);


      bytespertile = tmp___2;

      strip = (uint32 )0;





      while (strip < td->td_nstrips) {


        *(td->td_stripbytecount + strip) = bytespertile;

        strip ++;

      }




    } else {


      tmp___3 = TIFFScanlineSize64(tif);


      rowbytes = tmp___3;

      rowsperstrip = td->td_imagelength / td->td_stripsperimage;

      strip = (uint32 )0;





      while (strip < td->td_nstrips) {


        *(td->td_stripbytecount + strip) = rowbytes * (uint64 )rowsperstrip;

        strip ++;

      }




    }

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4790", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4790", "0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4745", "1", checkpoints_buf);
  tif->tif_dir.td_fieldsset[0] |= 1UL << 24;


  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4811", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 17);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4811", "17", checkpoints_buf);
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 17))) {
    td->td_rowsperstrip = td->td_imagelength;

  } else {

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4811", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 17);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4811", "17", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4814", "1", checkpoints_buf);
  return (1);
}
}
static void MissingRequired(TIFF *tif , char const   *tagname ) ;
static char const   module___3[16]  = 
  {      (char const   )'M',      (char const   )'i',      (char const   )'s',      (char const   )'s', 
        (char const   )'i',      (char const   )'n',      (char const   )'g',      (char const   )'R', 
        (char const   )'e',      (char const   )'q',      (char const   )'u',      (char const   )'i', 
        (char const   )'r',      (char const   )'e',      (char const   )'d',      (char const   )'\000'};
static void MissingRequired(TIFF *tif , char const   *tagname ) 
{ 


  {

  TIFFErrorExt(tif->tif_clientdata, module___3,
               "TIFF directory is missing required \"%s\" field", tagname);

  return;
}
}
static int TIFFCheckDirOffset(TIFF *tif , uint64 diroff ) 
{ 
  uint16 n ;
  uint64 *new_dirlist ;
  void *tmp ;

  {

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4817", "0", checkpoints_buf);
  if (diroff == 0ULL) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4818", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4817", "0", checkpoints_buf);
  n = (uint16 )0;




  while (1) {
    if ((int )n < (int )tif->tif_dirnumber) {

      if (tif->tif_dirlist) {

      } else {
        break;
      }

    } else {
      break;
    }


    if (*(tif->tif_dirlist + n) == diroff) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4828", "0", checkpoints_buf);
      return (0);
    } else {

    }


    n = (uint16 )((int )n + 1);

  }



  tif->tif_dirnumber = (uint16 )((int )tif->tif_dirnumber + 1);

  if ((int )tif->tif_dirnumber > (int )tif->tif_dirlistsize) {


    tmp = _TIFFCheckRealloc(tif, (void *)tif->tif_dirlist,
                            (tmsize_t )tif->tif_dirnumber,
                            (tmsize_t )(2U * sizeof(uint64 )), "for IFD list");


    new_dirlist = (uint64 *)tmp;


    if (! new_dirlist) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4836", "0", checkpoints_buf);
      return (0);
    } else {

    }

    tif->tif_dirlistsize = (uint16 )(2 * (int )tif->tif_dirnumber);

    tif->tif_dirlist = new_dirlist;

  } else {

  }
  *(tif->tif_dirlist + ((int )tif->tif_dirnumber - 1)) = diroff;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4842", "1", checkpoints_buf);
  return (1);
}
}
static int CheckDirCount(TIFF *tif , TIFFDirEntry *dir , uint32 count ) 
{ 
  TIFFField const   *tmp ;
  TIFFField const   *tmp___0 ;

  {

  if ((uint64 )count > dir->tdir_count) {


    tmp = TIFFFieldWithTag(tif, (uint32 )dir->tdir_tag);



    TIFFWarningExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                   "incorrect count for field \"%s\" (%llu, expecting %lu); tag ignored",
                   tmp->field_name, dir->tdir_count, count);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4846", "0", checkpoints_buf);
    return (0);
  } else {

    if ((uint64 )count < dir->tdir_count) {


      tmp___0 = TIFFFieldWithTag(tif, (uint32 )dir->tdir_tag);



      TIFFWarningExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "incorrect count for field \"%s\" (%llu, expecting %lu); tag trimmed",
                     tmp___0->field_name, dir->tdir_count, count);

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4850", "1", checkpoints_buf);
      return (1);
    } else {

    }

  }

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4852", "1", checkpoints_buf);
  return (1);
}
}
static uint16 TIFFFetchDirectory(TIFF *tif , uint64 diroff ,
                                 TIFFDirEntry **pdir , uint64 *nextdiroff ) ;
static char const   module___4[19]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'F',      (char const   )'e',      (char const   )'t',      (char const   )'c', 
        (char const   )'h',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'\000'};
static uint16 TIFFFetchDirectory(TIFF *tif , uint64 diroff ,
                                 TIFFDirEntry **pdir , uint64 *nextdiroff ) 
{ 
  void *origdir ;
  uint16 dircount16 ;
  uint32 dirsize ;
  TIFFDirEntry *dir ;
  uint8 *ma ;
  TIFFDirEntry *mb ;
  uint16 n ;
  uint64 tmp ;
  tmsize_t tmp___0 ;
  uint64 dircount64 ;
  tmsize_t tmp___1 ;
  tmsize_t tmp___2 ;
  uint32 nextdiroff32 ;
  tmsize_t tmp___3 ;
  tmsize_t tmp___4 ;
  tmsize_t m ;
  tmsize_t off ;
  tmsize_t m___0 ;
  uint64 dircount64___0 ;
  uint32 nextdiroff32___0 ;
  void *tmp___5 ;

  {

  if (pdir) {

  } else {

    __assert_fail("pdir", "tif_dirread.c", 4269U, "TIFFFetchDirectory");

  }

  tif->tif_diroff = diroff;


  if (nextdiroff) {
    *nextdiroff = (uint64 )0;

  } else {

  }


  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4860", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4860", "0", checkpoints_buf);
  if (! ((tif->tif_flags & 2048U) != 0U)) {


    tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_diroff, 0);




    if (tmp == tif->tif_diroff) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___4,
                   "%s: Seek error accessing TIFF directory", tif->tif_name);

      return ((uint16 )0);
    }



    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4866", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {


      tmp___0 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                       (void *)(& dircount16),
                                       (tmsize_t )sizeof(uint16 ));


      if ((unsigned long )tmp___0 == (unsigned long )sizeof(uint16 )) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "%s: Can not read TIFF directory count", tif->tif_name);

        return ((uint16 )0);
      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4872", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort(& dircount16);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4872", "128", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4875", "4096", checkpoints_buf);
      if ((int )dircount16 > 4096) {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "Sanity check on directory count failed, this is probably not a valid IFD offset");

        return ((uint16 )0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4875", "4096", checkpoints_buf);
      dirsize = (uint32 )12;

    } else {


      tmp___1 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                       (void *)(& dircount64),
                                       (tmsize_t )sizeof(uint64 ));


      if ((unsigned long )tmp___1 == (unsigned long )sizeof(uint64 )) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "%s: Can not read TIFF directory count", tif->tif_name);

        return ((uint16 )0);
      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4885", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& dircount64);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4885", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4888", "4096", checkpoints_buf);
      if (dircount64 > 4096ULL) {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "Sanity check on directory count failed, this is probably not a valid IFD offset");

        return ((uint16 )0);
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4888", "4096", checkpoints_buf);
      dircount16 = (uint16 )dircount64;

      dirsize = (uint32 )20;

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4866", "524288", checkpoints_buf);


    origdir = _TIFFCheckMalloc(tif, (tmsize_t )dircount16, (tmsize_t )dirsize,
                               "to read TIFF directory");


    if ((unsigned int )origdir == (unsigned int )((void *)0)) {
      return ((uint16 )0);
    } else {

    }


    tmp___2 = (*(tif->tif_readproc))(tif->tif_clientdata, origdir,
                                     (tmsize_t )((uint32 )dircount16 * dirsize));



    if (tmp___2 == (tmsize_t )((uint32 )dircount16 * dirsize)) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___4,
                   "%.100s: Can not read TIFF directory", tif->tif_name);


      _TIFFfree(origdir);

      return ((uint16 )0);
    }


    if (nextdiroff) {

      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4905", "524288", checkpoints_buf);
      if (! (tif->tif_flags & 524288U)) {


        tmp___3 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& nextdiroff32),
                                         (tmsize_t )sizeof(uint32 ));


        if ((unsigned long )tmp___3 == (unsigned long )sizeof(uint32 )) {

        } else {
          nextdiroff32 = (uint32 )0;

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4910", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong(& nextdiroff32);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4910", "128", checkpoints_buf);
        *nextdiroff = (uint64 )nextdiroff32;

      } else {


        tmp___4 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)nextdiroff,
                                         (tmsize_t )sizeof(uint64 ));


        if ((unsigned long )tmp___4 == (unsigned long )sizeof(uint64 )) {

        } else {
          *nextdiroff = (uint64 )0;

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4918", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong8(nextdiroff);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4918", "128", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4905", "524288", checkpoints_buf);
    } else {

    }

  } else {
    off = (tmsize_t )tif->tif_diroff;


    if ((uint64 )off != tif->tif_diroff) {

      TIFFErrorExt(tif->tif_clientdata, module___4,
                   "Can not read TIFF directory count");

      return ((uint16 )0);
    } else {

    }


    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4927", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      m = (tmsize_t )((unsigned long )off + (unsigned long )sizeof(uint16 ));



      if (m < off) {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "Can not read TIFF directory count");

        return ((uint16 )0);
      } else {

        if (m < (tmsize_t )sizeof(uint16 )) {

          TIFFErrorExt(tif->tif_clientdata, module___4,
                       "Can not read TIFF directory count");

          return ((uint16 )0);
        } else {


          if (m > tif->tif_size) {

            TIFFErrorExt(tif->tif_clientdata, module___4,
                         "Can not read TIFF directory count");

            return ((uint16 )0);
          } else {

            _TIFFmemcpy((void *)(& dircount16),
                        (void const   *)(tif->tif_base + off),
                        (tmsize_t )sizeof(uint16 ));

          }


        }

      }


      off = (tmsize_t )((unsigned long )off + (unsigned long )sizeof(uint16 ));


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4940", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort(& dircount16);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4940", "128", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4943", "4096", checkpoints_buf);
      if ((int )dircount16 > 4096) {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "Sanity check on directory count failed, this is probably not a valid IFD offset");

        return ((uint16 )0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4943", "4096", checkpoints_buf);
      dirsize = (uint32 )12;

    } else {
      m___0 = (tmsize_t )((unsigned long )off + (unsigned long )sizeof(uint64 ));



      if (m___0 < off) {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "Can not read TIFF directory count");

        return ((uint16 )0);
      } else {

        if (m___0 < (tmsize_t )sizeof(uint64 )) {

          TIFFErrorExt(tif->tif_clientdata, module___4,
                       "Can not read TIFF directory count");

          return ((uint16 )0);
        } else {


          if (m___0 > tif->tif_size) {

            TIFFErrorExt(tif->tif_clientdata, module___4,
                         "Can not read TIFF directory count");

            return ((uint16 )0);
          } else {

            _TIFFmemcpy((void *)(& dircount64___0),
                        (void const   *)(tif->tif_base + off),
                        (tmsize_t )sizeof(uint64 ));

          }


        }

      }


      off = (tmsize_t )((unsigned long )off + (unsigned long )sizeof(uint64 ));


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4960", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& dircount64___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4960", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4963", "4096", checkpoints_buf);
      if (dircount64___0 > 4096ULL) {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "Sanity check on directory count failed, this is probably not a valid IFD offset");

        return ((uint16 )0);
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 4096);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4963", "4096", checkpoints_buf);
      dircount16 = (uint16 )dircount64___0;

      dirsize = (uint32 )20;

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "4927", "524288", checkpoints_buf);


    origdir = _TIFFCheckMalloc(tif, (tmsize_t )dircount16, (tmsize_t )dirsize,
                               "to read TIFF directory");


    if ((unsigned int )origdir == (unsigned int )((void *)0)) {
      return ((uint16 )0);
    } else {

    }
    m = (tmsize_t )((unsigned long )off + (unsigned long )((uint32 )dircount16 * dirsize));



    if (m < off) {

      TIFFErrorExt(tif->tif_clientdata, module___4,
                   "Can not read TIFF directory");


      _TIFFfree(origdir);

      return ((uint16 )0);
    } else {

      if (m < (tmsize_t )((uint32 )dircount16 * dirsize)) {

        TIFFErrorExt(tif->tif_clientdata, module___4,
                     "Can not read TIFF directory");


        _TIFFfree(origdir);

        return ((uint16 )0);
      } else {


        if (m > tif->tif_size) {

          TIFFErrorExt(tif->tif_clientdata, module___4,
                       "Can not read TIFF directory");


          _TIFFfree(origdir);

          return ((uint16 )0);
        } else {

          _TIFFmemcpy(origdir, (void const   *)(tif->tif_base + off),
                      (tmsize_t )((uint32 )dircount16 * dirsize));

        }


      }

    }



    if (nextdiroff) {
      off = (tmsize_t )((unsigned long )off + (unsigned long )((uint32 )dircount16 * dirsize));


      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4989", "524288", checkpoints_buf);
      if (! (tif->tif_flags & 524288U)) {
        m = (tmsize_t )((unsigned long )off + (unsigned long )sizeof(uint32 ));



        if (m < off) {
          nextdiroff32___0 = (uint32 )0;

        } else {

          if (m < (tmsize_t )sizeof(uint32 )) {
            nextdiroff32___0 = (uint32 )0;

          } else {


            if (m > tif->tif_size) {
              nextdiroff32___0 = (uint32 )0;

            } else {

              _TIFFmemcpy((void *)(& nextdiroff32___0),
                          (void const   *)(tif->tif_base + off),
                          (tmsize_t )sizeof(uint32 ));

            }


          }

        }



        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4998", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong(& nextdiroff32___0);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "4998", "128", checkpoints_buf);
        *nextdiroff = (uint64 )nextdiroff32___0;

      } else {
        m = (tmsize_t )((unsigned long )off + (unsigned long )sizeof(uint64 ));



        if (m < off) {
          *nextdiroff = (uint64 )0;

        } else {

          if (m < (tmsize_t )sizeof(uint64 )) {
            *nextdiroff = (uint64 )0;

          } else {


            if (m > tif->tif_size) {
              *nextdiroff = (uint64 )0;

            } else {

              _TIFFmemcpy((void *)nextdiroff,
                          (void const   *)(tif->tif_base + off),
                          (tmsize_t )sizeof(uint64 ));

            }


          }

        }



        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5010", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong8(nextdiroff);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5010", "128", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "4989", "524288", checkpoints_buf);
    } else {

    }

  }

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4860", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "4860", "0", checkpoints_buf);


  tmp___5 = _TIFFCheckMalloc(tif, (tmsize_t )dircount16,
                             (tmsize_t )sizeof(TIFFDirEntry ),
                             "to read TIFF directory");


  dir = (TIFFDirEntry *)tmp___5;

  if ((unsigned int )dir == (unsigned int )((TIFFDirEntry *)0)) {

    _TIFFfree(origdir);

    return ((uint16 )0);
  } else {

  }
  ma = (uint8 *)origdir;

  mb = dir;

  n = (uint16 )0;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5023", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5023", "128", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5023", "524288", checkpoints_buf);


  while ((int )n < (int )dircount16) {

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5027", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5027", "128", checkpoints_buf);
    {
    mb->tdir_tag = *((uint16 *)ma);

    if (nextdiroff) {
      *nextdiroff = (uint64 )0;
    } else {

    }
    }
    ma += sizeof(uint16 );


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5032", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)ma);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5032", "128", checkpoints_buf);
    mb->tdir_type = *((uint16 *)ma);

    ma += sizeof(uint16 );


    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5037", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5038", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong((uint32 *)ma);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5038", "128", checkpoints_buf);
      mb->tdir_count = (uint64 )*((uint32 *)ma);

      ma += sizeof(uint32 );

      *((uint32 *)(& mb->tdir_offset)) = *((uint32 *)ma);

      ma += sizeof(uint32 );

    } else {

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5045", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8((uint64 *)ma);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5045", "128", checkpoints_buf);
      mb->tdir_count = *((uint64 *)ma);

      ma += sizeof(uint64 );

      mb->tdir_offset = *((uint64 *)ma);

      ma += sizeof(uint64 );

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5037", "524288", checkpoints_buf);
    mb ++;

    n = (uint16 )((int )n + 1);

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5023", "128", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5023", "128", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5023", "524288", checkpoints_buf);



  _TIFFfree(origdir);

  *pdir = dir;


  return (dircount16);
}
}
static int TIFFFetchNormalTag(TIFF *tif , TIFFDirEntry *dp , int recover ) ;
static char const   module___5[19]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'F',      (char const   )'e',      (char const   )'t',      (char const   )'c', 
        (char const   )'h',      (char const   )'N',      (char const   )'o',      (char const   )'r', 
        (char const   )'m',      (char const   )'a',      (char const   )'l',      (char const   )'T', 
        (char const   )'a',      (char const   )'g',      (char const   )'\000'};
static int TIFFFetchNormalTag(TIFF *tif , TIFFDirEntry *dp , int recover ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 fii ;
  TIFFField const   *fip ;
  uint8 *data ;
  uint8 *ma ;
  uint32 mb ;
  int n ;
  uint8 *o ;
  void *tmp ;
  uint8 data___0 ;
  int tmp___0 ;
  uint16 data___1 ;
  int tmp___1 ;
  uint32 data___2 ;
  int tmp___2 ;
  uint64 data___3 ;
  int tmp___3 ;
  double data___4 ;
  int tmp___4 ;
  uint64 data___5 ;
  int tmp___5 ;
  uint16 *data___6 ;
  int m ;
  uint8 *data___7 ;
  int m___0 ;
  uint16 *data___8 ;
  int m___1 ;
  uint32 *data___9 ;
  int m___2 ;
  float *data___10 ;
  int m___3 ;
  uint8 *data___11 ;
  int m___4 ;
  uint8 *data___12 ;
  int m___5 ;
  uint16 *data___13 ;
  int m___6 ;
  uint32 *data___14 ;
  int m___7 ;
  uint64 *data___15 ;
  int m___8 ;
  float *data___16 ;
  int m___9 ;
  double *data___17 ;
  int m___10 ;
  uint64 *data___18 ;
  int m___11 ;
  uint8 *data___19 ;
  int m___12 ;
  uint8 *data___20 ;
  int m___13 ;
  int8 *data___21 ;
  int m___14 ;
  uint16 *data___22 ;
  int m___15 ;
  int16 *data___23 ;
  int m___16 ;
  uint32 *data___24 ;
  int m___17 ;
  int32 *data___25 ;
  int m___18 ;
  uint64 *data___26 ;
  int m___19 ;
  int64 *data___27 ;
  int m___20 ;
  float *data___28 ;
  int m___21 ;
  double *data___29 ;
  int m___22 ;
  uint64 *data___30 ;
  int m___23 ;

  {

  TIFFReadDirectoryFindFieldInfo(tif, dp->tdir_tag, & fii);


  sprintf(checkpoints_buf, "%u", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5058", "4294967295", checkpoints_buf);
  if (fii != 4294967295U) {

  } else {

    __assert_fail("fii!=0xFFFFFFFF", "tif_dirread.c", 4513U,
                  "TIFFFetchNormalTag");

  }

  sprintf(checkpoints_buf, "%u", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5058", "4294967295", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5061", "4294967295", checkpoints_buf);
  if (fii == 4294967295U) {

    TIFFErrorExt(tif->tif_clientdata, "TIFFFetchNormalTag",
                 "No definition found for tag %d", (int )dp->tdir_tag);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5063", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5061", "4294967295", checkpoints_buf);
  fip = (TIFFField const   *)*(tif->tif_fields + fii);

  sprintf(checkpoints_buf, "%u", 51);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5066", "51", checkpoints_buf);
  if ((unsigned int const   )fip->set_field_type != 51U) {

  } else {

    __assert_fail("fip->set_field_type!=TIFF_SETGET_OTHER", "tif_dirread.c",
                  4522U, "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%u", 51);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5066", "51", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 13);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5069", "13", checkpoints_buf);
  if ((unsigned int const   )fip->set_field_type != 13U) {

  } else {

    __assert_fail("fip->set_field_type!=TIFF_SETGET_INT", "tif_dirread.c",
                  4523U, "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%u", 13);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5069", "13", checkpoints_buf);
  err = (enum TIFFReadDirEntryErr )0;

  switch ((unsigned int const   )fip->set_field_type) {
  case 0U: 
  break;
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5075", "0", checkpoints_buf);
  case 1U: 
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4532U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5075", "0", checkpoints_buf);


  err = TIFFReadDirEntryByteArray(tif, dp, & data);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5079", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    ma = data;

    mb = (uint32 )0;


    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5082", "0", checkpoints_buf);


    while (mb < (uint32 )dp->tdir_count) {

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5086", "0", checkpoints_buf);
      if ((int )*ma == 0) {
        break;
      } else {

      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5086", "0", checkpoints_buf);
      ma ++;

      mb ++;

    }

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5082", "0", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5091", "1", checkpoints_buf);
    if (mb + 1U < (uint32 )dp->tdir_count) {

      TIFFWarningExt(tif->tif_clientdata, module___5,
                     "ASCII value for tag \"%s\" contains null byte in value; value incorrectly truncated during reading due to implementation limitations",
                     fip->field_name);

    } else {

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5093", "1", checkpoints_buf);
      if (mb + 1U > (uint32 )dp->tdir_count) {

        TIFFWarningExt(tif->tif_clientdata, module___5,
                       "ASCII value for tag \"%s\" does not end in null byte",
                       fip->field_name);


        sprintf(checkpoints_buf, "%llu", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5095", "1", checkpoints_buf);
        if ((uint64 )((uint32 )dp->tdir_count + 1U) != dp->tdir_count + 1ULL) {
          o = (uint8 *)((void *)0);

        } else {


          tmp = _TIFFmalloc((tmsize_t )((uint32 )dp->tdir_count + 1U));


          o = (uint8 *)tmp;

        }

        sprintf(checkpoints_buf, "%llu", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5095", "1", checkpoints_buf);
        if ((unsigned int )o == (unsigned int )((void *)0)) {
          if ((unsigned int )data != (unsigned int )((void *)0)) {

            _TIFFfree((void *)data);

          } else {

          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "5103", "0", checkpoints_buf);
          return (0);
        } else {

        }

        _TIFFmemcpy((void *)o, (void const   *)data,
                    (tmsize_t )((uint32 )dp->tdir_count));

        *(o + (uint32 )dp->tdir_count) = (uint8 )0;

        if ((unsigned int )data != (unsigned int )((uint8 *)0)) {

          _TIFFfree((void *)data);

        } else {

        }
        data = o;

      } else {

      }

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5093", "1", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5091", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5112", "n", checkpoints_buf);

    n = TIFFSetField(tif, (uint32 )dp->tdir_tag, data);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5112", "n", checkpoints_buf);

    if ((unsigned int )data != (unsigned int )((uint8 *)0)) {

      _TIFFfree((void *)data);

    } else {

    }
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5116", "n", checkpoints_buf);
    if (! n) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5117", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5116", "n", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5079", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5121", "1", checkpoints_buf);
  case 2U: 
  if ((int const   )fip->field_readcount == 1) {

  } else {

    __assert_fail("fip->field_readcount==1", "tif_dirread.c", 4581U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5121", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5124", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4582U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5124", "0", checkpoints_buf);


  err = TIFFReadDirEntryByte(tif, dp, & data___0);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5128", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5129", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (int )data___0);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5129", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5130", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5132", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5130", "tmp___0", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5128", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5135", "1", checkpoints_buf);
  case 4U: 
  if ((int const   )fip->field_readcount == 1) {

  } else {

    __assert_fail("fip->field_readcount==1", "tif_dirread.c", 4594U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5135", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5138", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4595U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5138", "0", checkpoints_buf);


  err = TIFFReadDirEntryShort(tif, dp, & data___1);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5142", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5143", "tmp___1", checkpoints_buf);

    tmp___1 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (int )data___1);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5143", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5144", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5146", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5144", "tmp___1", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5142", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5149", "1", checkpoints_buf);
  case 6U: 
  if ((int const   )fip->field_readcount == 1) {

  } else {

    __assert_fail("fip->field_readcount==1", "tif_dirread.c", 4607U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5149", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5152", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4608U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5152", "0", checkpoints_buf);


  err = TIFFReadDirEntryLong(tif, dp, & data___2);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5156", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5157", "tmp___2", checkpoints_buf);

    tmp___2 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___2);
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5157", "tmp___2", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5158", "tmp___2", checkpoints_buf);
    if (tmp___2) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5160", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5158", "tmp___2", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5156", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5163", "1", checkpoints_buf);
  case 8U: 
  if ((int const   )fip->field_readcount == 1) {

  } else {

    __assert_fail("fip->field_readcount==1", "tif_dirread.c", 4620U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5163", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5166", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4621U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5166", "0", checkpoints_buf);


  err = TIFFReadDirEntryLong8(tif, dp, & data___3);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5170", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5171", "tmp___3", checkpoints_buf);

    tmp___3 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___3);
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5171", "tmp___3", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5172", "tmp___3", checkpoints_buf);
    if (tmp___3) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5174", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5172", "tmp___3", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5170", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5177", "1", checkpoints_buf);
  case 11U: 
  if ((int const   )fip->field_readcount == 1) {

  } else {

    __assert_fail("fip->field_readcount==1", "tif_dirread.c", 4633U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5177", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5180", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4634U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5180", "0", checkpoints_buf);


  err = TIFFReadDirEntryDouble(tif, dp, & data___4);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5184", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5185", "tmp___4", checkpoints_buf);

    tmp___4 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___4);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5185", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5186", "tmp___4", checkpoints_buf);
    if (tmp___4) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5188", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5186", "tmp___4", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5184", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5191", "1", checkpoints_buf);
  case 12U: 
  if ((int const   )fip->field_readcount == 1) {

  } else {

    __assert_fail("fip->field_readcount==1", "tif_dirread.c", 4646U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5191", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5194", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4647U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5194", "0", checkpoints_buf);


  err = TIFFReadDirEntryIfd8(tif, dp, & data___5);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5198", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5199", "tmp___5", checkpoints_buf);

    tmp___5 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___5);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5199", "tmp___5", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5200", "tmp___5", checkpoints_buf);
    if (tmp___5) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5202", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5200", "tmp___5", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5198", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5205", "2", checkpoints_buf);
  case 14U: 
  if ((int const   )fip->field_readcount == 2) {

  } else {

    __assert_fail("fip->field_readcount==2", "tif_dirread.c", 4659U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5205", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5208", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4660U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5208", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5211", "2", checkpoints_buf);
  if (dp->tdir_count != 2ULL) {

    __assert_fail("0", "tif_dirread.c", 4662U, "TIFFFetchNormalTag");

  } else {


    err = TIFFReadDirEntryShortArray(tif, dp, & data___6);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5214", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5215", "m", checkpoints_buf);

      m = TIFFSetField(tif, (uint32 )dp->tdir_tag, (int )*(data___6 + 0),
                       (int )*(data___6 + 1));
      sprintf(checkpoints_buf, "%d", m);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5215", "m", checkpoints_buf);


      _TIFFfree((void *)data___6);

      sprintf(checkpoints_buf, "%d", m);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5217", "m", checkpoints_buf);
      if (! m) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5218", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5217", "m", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5214", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5211", "2", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5222", "1", checkpoints_buf);
  case 16U: 
  if ((int const   )fip->field_readcount >= 1) {

  } else {

    __assert_fail("fip->field_readcount>=1", "tif_dirread.c", 4680U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5222", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5225", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4681U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5225", "0", checkpoints_buf);

  if (dp->tdir_count != (uint64 )fip->field_readcount) {

    __assert_fail("0", "tif_dirread.c", 4683U, "TIFFFetchNormalTag");

  } else {


    err = TIFFReadDirEntryByteArray(tif, dp, & data___7);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5231", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5232", "m___0", checkpoints_buf);

      m___0 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___7);
      sprintf(checkpoints_buf, "%d", m___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5232", "m___0", checkpoints_buf);

      if ((unsigned int )data___7 != (unsigned int )((uint8 *)0)) {

        _TIFFfree((void *)data___7);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5236", "m___0", checkpoints_buf);
      if (! m___0) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5237", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5236", "m___0", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5231", "0", checkpoints_buf);
  }

  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5241", "1", checkpoints_buf);
  case 18U: 
  if ((int const   )fip->field_readcount >= 1) {

  } else {

    __assert_fail("fip->field_readcount>=1", "tif_dirread.c", 4702U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5241", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5244", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4703U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5244", "0", checkpoints_buf);

  if (dp->tdir_count != (uint64 )fip->field_readcount) {

    __assert_fail("0", "tif_dirread.c", 4705U, "TIFFFetchNormalTag");

  } else {


    err = TIFFReadDirEntryShortArray(tif, dp, & data___8);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5250", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5251", "m___1", checkpoints_buf);

      m___1 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___8);
      sprintf(checkpoints_buf, "%d", m___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5251", "m___1", checkpoints_buf);

      if ((unsigned int )data___8 != (unsigned int )((uint16 *)0)) {

        _TIFFfree((void *)data___8);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5255", "m___1", checkpoints_buf);
      if (! m___1) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5256", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5255", "m___1", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5250", "0", checkpoints_buf);
  }

  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5260", "1", checkpoints_buf);
  case 20U: 
  if ((int const   )fip->field_readcount >= 1) {

  } else {

    __assert_fail("fip->field_readcount>=1", "tif_dirread.c", 4724U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5260", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5263", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4725U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5263", "0", checkpoints_buf);

  if (dp->tdir_count != (uint64 )fip->field_readcount) {

    __assert_fail("0", "tif_dirread.c", 4727U, "TIFFFetchNormalTag");

  } else {


    err = TIFFReadDirEntryLongArray(tif, dp, & data___9);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5269", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5270", "m___2", checkpoints_buf);

      m___2 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___9);
      sprintf(checkpoints_buf, "%d", m___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5270", "m___2", checkpoints_buf);

      if ((unsigned int )data___9 != (unsigned int )((uint32 *)0)) {

        _TIFFfree((void *)data___9);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5274", "m___2", checkpoints_buf);
      if (! m___2) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5275", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5274", "m___2", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5269", "0", checkpoints_buf);
  }

  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5279", "1", checkpoints_buf);
  case 24U: 
  if ((int const   )fip->field_readcount >= 1) {

  } else {

    __assert_fail("fip->field_readcount>=1", "tif_dirread.c", 4746U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5279", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5282", "0", checkpoints_buf);
  if ((int const   )fip->field_passcount == 0) {

  } else {

    __assert_fail("fip->field_passcount==0", "tif_dirread.c", 4747U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5282", "0", checkpoints_buf);

  if (dp->tdir_count != (uint64 )fip->field_readcount) {

    __assert_fail("0", "tif_dirread.c", 4749U, "TIFFFetchNormalTag");

  } else {


    err = TIFFReadDirEntryFloatArray(tif, dp, & data___10);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5288", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5289", "m___3", checkpoints_buf);

      m___3 = TIFFSetField(tif, (uint32 )dp->tdir_tag, data___10);
      sprintf(checkpoints_buf, "%d", m___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5289", "m___3", checkpoints_buf);

      if ((unsigned int )data___10 != (unsigned int )((float *)0)) {

        _TIFFfree((void *)data___10);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5293", "m___3", checkpoints_buf);
      if (! m___3) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5294", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5293", "m___3", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5288", "0", checkpoints_buf);
  }

  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5298", "-1", checkpoints_buf);
  case 27U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4768U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5298", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5301", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4769U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5301", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5304", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryByteArray(tif, dp, & data___11);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5307", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5308", "m___4", checkpoints_buf);

      m___4 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                           (int )((uint16 )dp->tdir_count), data___11);
      sprintf(checkpoints_buf, "%d", m___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5308", "m___4", checkpoints_buf);

      if ((unsigned int )data___11 != (unsigned int )((uint8 *)0)) {

        _TIFFfree((void *)data___11);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5312", "m___4", checkpoints_buf);
      if (! m___4) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5313", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5312", "m___4", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5307", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5304", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5317", "-1", checkpoints_buf);
  case 28U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4790U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5317", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5320", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4791U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5320", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5323", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryByteArray(tif, dp, & data___12);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5326", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5327", "m___5", checkpoints_buf);

      m___5 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                           (int )((uint16 )dp->tdir_count), data___12);
      sprintf(checkpoints_buf, "%d", m___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5327", "m___5", checkpoints_buf);

      if ((unsigned int )data___12 != (unsigned int )((uint8 *)0)) {

        _TIFFfree((void *)data___12);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5331", "m___5", checkpoints_buf);
      if (! m___5) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5332", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5331", "m___5", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5326", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5323", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5336", "-1", checkpoints_buf);
  case 30U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4812U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5336", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5339", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4813U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5339", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5342", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryShortArray(tif, dp, & data___13);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5345", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5346", "m___6", checkpoints_buf);

      m___6 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                           (int )((uint16 )dp->tdir_count), data___13);
      sprintf(checkpoints_buf, "%d", m___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5346", "m___6", checkpoints_buf);

      if ((unsigned int )data___13 != (unsigned int )((uint16 *)0)) {

        _TIFFfree((void *)data___13);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5350", "m___6", checkpoints_buf);
      if (! m___6) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5351", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5350", "m___6", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5345", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5342", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5355", "-1", checkpoints_buf);
  case 32U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4834U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5355", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5358", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4835U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5358", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5361", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryLongArray(tif, dp, & data___14);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5364", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5365", "m___7", checkpoints_buf);

      m___7 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                           (int )((uint16 )dp->tdir_count), data___14);
      sprintf(checkpoints_buf, "%d", m___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5365", "m___7", checkpoints_buf);

      if ((unsigned int )data___14 != (unsigned int )((uint32 *)0)) {

        _TIFFfree((void *)data___14);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5369", "m___7", checkpoints_buf);
      if (! m___7) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5370", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5369", "m___7", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5364", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5361", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5374", "-1", checkpoints_buf);
  case 34U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4856U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5374", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5377", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4857U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5377", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5380", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryLong8Array(tif, dp, & data___15);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5383", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5384", "m___8", checkpoints_buf);

      m___8 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                           (int )((uint16 )dp->tdir_count), data___15);
      sprintf(checkpoints_buf, "%d", m___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5384", "m___8", checkpoints_buf);

      if ((unsigned int )data___15 != (unsigned int )((uint64 *)0)) {

        _TIFFfree((void *)data___15);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5388", "m___8", checkpoints_buf);
      if (! m___8) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5389", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5388", "m___8", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5383", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5380", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5393", "-1", checkpoints_buf);
  case 36U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4878U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5393", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5396", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4879U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5396", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5399", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryFloatArray(tif, dp, & data___16);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5402", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5403", "m___9", checkpoints_buf);

      m___9 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                           (int )((uint16 )dp->tdir_count), data___16);
      sprintf(checkpoints_buf, "%d", m___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5403", "m___9", checkpoints_buf);

      if ((unsigned int )data___16 != (unsigned int )((float *)0)) {

        _TIFFfree((void *)data___16);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5407", "m___9", checkpoints_buf);
      if (! m___9) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5408", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5407", "m___9", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5402", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5399", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5412", "-1", checkpoints_buf);
  case 37U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4900U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5412", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5415", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4901U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5415", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5418", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryDoubleArray(tif, dp, & data___17);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5421", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5422", "m___10", checkpoints_buf);

      m___10 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                            (int )((uint16 )dp->tdir_count), data___17);
      sprintf(checkpoints_buf, "%d", m___10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5422", "m___10", checkpoints_buf);

      if ((unsigned int )data___17 != (unsigned int )((double *)0)) {

        _TIFFfree((void *)data___17);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5426", "m___10", checkpoints_buf);
      if (! m___10) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5427", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5426", "m___10", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5421", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5418", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5431", "-1", checkpoints_buf);
  case 38U: 
  if ((int const   )fip->field_readcount == -1) {

  } else {

    __assert_fail("fip->field_readcount==-1", "tif_dirread.c", 4922U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5431", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5434", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4923U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5434", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5437", "65535", checkpoints_buf);
  if (dp->tdir_count > 65535ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {


    err = TIFFReadDirEntryIfd8Array(tif, dp, & data___18);


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5440", "0", checkpoints_buf);
    if ((unsigned int )err == 0U) {
      sprintf(checkpoints_buf, "%d", m___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5441", "m___11", checkpoints_buf);

      m___11 = TIFFSetField(tif, (uint32 )dp->tdir_tag,
                            (int )((uint16 )dp->tdir_count), data___18);
      sprintf(checkpoints_buf, "%d", m___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5441", "m___11", checkpoints_buf);

      if ((unsigned int )data___18 != (unsigned int )((uint64 *)0)) {

        _TIFFfree((void *)data___18);

      } else {

      }
      sprintf(checkpoints_buf, "%d", m___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5445", "m___11", checkpoints_buf);
      if (! m___11) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5446", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", m___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5445", "m___11", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5440", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5437", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5450", "-3", checkpoints_buf);
  case 39U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 4944U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5450", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5453", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4945U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5453", "1", checkpoints_buf);


  err = TIFFReadDirEntryByteArray(tif, dp, & data___19);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5457", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5458", "m___12", checkpoints_buf);

    m___12 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___19);
    sprintf(checkpoints_buf, "%d", m___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5458", "m___12", checkpoints_buf);

    if ((unsigned int )data___19 != (unsigned int )((uint8 *)0)) {

      _TIFFfree((void *)data___19);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5462", "m___12", checkpoints_buf);
    if (! m___12) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5463", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5462", "m___12", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5457", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5467", "-3", checkpoints_buf);
  case 40U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 4961U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5467", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5470", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4962U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5470", "1", checkpoints_buf);


  err = TIFFReadDirEntryByteArray(tif, dp, & data___20);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5474", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5475", "m___13", checkpoints_buf);

    m___13 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___20);
    sprintf(checkpoints_buf, "%d", m___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5475", "m___13", checkpoints_buf);

    if ((unsigned int )data___20 != (unsigned int )((uint8 *)0)) {

      _TIFFfree((void *)data___20);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5479", "m___13", checkpoints_buf);
    if (! m___13) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5480", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5479", "m___13", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5474", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5484", "-3", checkpoints_buf);
  case 41U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 4978U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5484", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5487", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4979U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5487", "1", checkpoints_buf);


  err = TIFFReadDirEntrySbyteArray(tif, dp, & data___21);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5491", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___14);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5492", "m___14", checkpoints_buf);

    m___14 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___21);
    sprintf(checkpoints_buf, "%d", m___14);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5492", "m___14", checkpoints_buf);

    if ((unsigned int )data___21 != (unsigned int )((int8 *)0)) {

      _TIFFfree((void *)data___21);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___14);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5496", "m___14", checkpoints_buf);
    if (! m___14) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5497", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___14);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5496", "m___14", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5491", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5501", "-3", checkpoints_buf);
  case 42U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 4995U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5501", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5504", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 4996U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5504", "1", checkpoints_buf);


  err = TIFFReadDirEntryShortArray(tif, dp, & data___22);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5508", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___15);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5509", "m___15", checkpoints_buf);

    m___15 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___22);
    sprintf(checkpoints_buf, "%d", m___15);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5509", "m___15", checkpoints_buf);

    if ((unsigned int )data___22 != (unsigned int )((uint16 *)0)) {

      _TIFFfree((void *)data___22);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___15);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5513", "m___15", checkpoints_buf);
    if (! m___15) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5514", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___15);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5513", "m___15", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5508", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5518", "-3", checkpoints_buf);
  case 43U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5012U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5518", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5521", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5013U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5521", "1", checkpoints_buf);


  err = TIFFReadDirEntrySshortArray(tif, dp, & data___23);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5525", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5526", "m___16", checkpoints_buf);

    m___16 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___23);
    sprintf(checkpoints_buf, "%d", m___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5526", "m___16", checkpoints_buf);

    if ((unsigned int )data___23 != (unsigned int )((int16 *)0)) {

      _TIFFfree((void *)data___23);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5530", "m___16", checkpoints_buf);
    if (! m___16) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5531", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5530", "m___16", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5525", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5535", "-3", checkpoints_buf);
  case 44U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5029U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5535", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5538", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5030U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5538", "1", checkpoints_buf);


  err = TIFFReadDirEntryLongArray(tif, dp, & data___24);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5542", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5543", "m___17", checkpoints_buf);

    m___17 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___24);
    sprintf(checkpoints_buf, "%d", m___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5543", "m___17", checkpoints_buf);

    if ((unsigned int )data___24 != (unsigned int )((uint32 *)0)) {

      _TIFFfree((void *)data___24);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5547", "m___17", checkpoints_buf);
    if (! m___17) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5548", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5547", "m___17", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5542", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5552", "-3", checkpoints_buf);
  case 45U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5046U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5552", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5555", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5047U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5555", "1", checkpoints_buf);


  err = TIFFReadDirEntrySlongArray(tif, dp, & data___25);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5559", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5560", "m___18", checkpoints_buf);

    m___18 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___25);
    sprintf(checkpoints_buf, "%d", m___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5560", "m___18", checkpoints_buf);

    if ((unsigned int )data___25 != (unsigned int )((int32 *)0)) {

      _TIFFfree((void *)data___25);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5564", "m___18", checkpoints_buf);
    if (! m___18) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5565", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5564", "m___18", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5559", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5569", "-3", checkpoints_buf);
  case 46U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5063U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5569", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5572", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5064U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5572", "1", checkpoints_buf);


  err = TIFFReadDirEntryLong8Array(tif, dp, & data___26);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5576", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5577", "m___19", checkpoints_buf);

    m___19 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___26);
    sprintf(checkpoints_buf, "%d", m___19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5577", "m___19", checkpoints_buf);

    if ((unsigned int )data___26 != (unsigned int )((uint64 *)0)) {

      _TIFFfree((void *)data___26);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5581", "m___19", checkpoints_buf);
    if (! m___19) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5582", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5581", "m___19", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5576", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5586", "-3", checkpoints_buf);
  case 47U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5080U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5586", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5589", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5081U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5589", "1", checkpoints_buf);


  err = TIFFReadDirEntrySlong8Array(tif, dp, & data___27);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5593", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5594", "m___20", checkpoints_buf);

    m___20 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___27);
    sprintf(checkpoints_buf, "%d", m___20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5594", "m___20", checkpoints_buf);

    if ((unsigned int )data___27 != (unsigned int )((int64 *)0)) {

      _TIFFfree((void *)data___27);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5598", "m___20", checkpoints_buf);
    if (! m___20) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5599", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5598", "m___20", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5593", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5603", "-3", checkpoints_buf);
  case 48U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5097U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5603", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5606", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5098U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5606", "1", checkpoints_buf);


  err = TIFFReadDirEntryFloatArray(tif, dp, & data___28);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5610", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___21);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5611", "m___21", checkpoints_buf);

    m___21 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___28);
    sprintf(checkpoints_buf, "%d", m___21);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5611", "m___21", checkpoints_buf);

    if ((unsigned int )data___28 != (unsigned int )((float *)0)) {

      _TIFFfree((void *)data___28);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___21);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5615", "m___21", checkpoints_buf);
    if (! m___21) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5616", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___21);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5615", "m___21", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5610", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5620", "-3", checkpoints_buf);
  case 49U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5114U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5620", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5623", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5115U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5623", "1", checkpoints_buf);


  err = TIFFReadDirEntryDoubleArray(tif, dp, & data___29);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5627", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___22);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5628", "m___22", checkpoints_buf);

    m___22 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___29);
    sprintf(checkpoints_buf, "%d", m___22);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5628", "m___22", checkpoints_buf);

    if ((unsigned int )data___29 != (unsigned int )((double *)0)) {

      _TIFFfree((void *)data___29);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___22);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5632", "m___22", checkpoints_buf);
    if (! m___22) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5633", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___22);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5632", "m___22", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5627", "0", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5637", "-3", checkpoints_buf);
  case 50U: 
  if ((int const   )fip->field_readcount == -3) {

  } else {

    __assert_fail("fip->field_readcount==-3", "tif_dirread.c", 5131U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", -3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5637", "-3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5640", "1", checkpoints_buf);
  if ((int const   )fip->field_passcount == 1) {

  } else {

    __assert_fail("fip->field_passcount==1", "tif_dirread.c", 5132U,
                  "TIFFFetchNormalTag");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5640", "1", checkpoints_buf);


  err = TIFFReadDirEntryIfd8Array(tif, dp, & data___30);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5644", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {
    sprintf(checkpoints_buf, "%d", m___23);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5645", "m___23", checkpoints_buf);

    m___23 = TIFFSetField(tif, (uint32 )dp->tdir_tag, (uint32 )dp->tdir_count,
                          data___30);
    sprintf(checkpoints_buf, "%d", m___23);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5645", "m___23", checkpoints_buf);

    if ((unsigned int )data___30 != (unsigned int )((uint64 *)0)) {

      _TIFFfree((void *)data___30);

    } else {

    }
    sprintf(checkpoints_buf, "%d", m___23);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5649", "m___23", checkpoints_buf);
    if (! m___23) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5650", "0", checkpoints_buf);
      return (0);
    } else {

    }
    sprintf(checkpoints_buf, "%d", m___23);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5649", "m___23", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5644", "0", checkpoints_buf);
  break;

  default: 
  __assert_fail("0", "tif_dirread.c", 5146U, "TIFFFetchNormalTag");

  break;
  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5656", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {

    TIFFReadDirEntryOutputErr(tif, err, module___5,
                              (char const   *)fip->field_name, recover);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5658", "0", checkpoints_buf);
    return (0);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5656", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5660", "1", checkpoints_buf);
  return (1);
}
}
static int TIFFFetchStripThing(TIFF *tif , TIFFDirEntry *dir , uint32 nstrips ,
                               uint64 **lpp ) ;
static char const   module___6[20]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'F',      (char const   )'e',      (char const   )'t',      (char const   )'c', 
        (char const   )'h',      (char const   )'S',      (char const   )'t',      (char const   )'r', 
        (char const   )'i',      (char const   )'p',      (char const   )'T',      (char const   )'h', 
        (char const   )'i',      (char const   )'n',      (char const   )'g',      (char const   )'\000'};
static int TIFFFetchStripThing(TIFF *tif , TIFFDirEntry *dir , uint32 nstrips ,
                               uint64 **lpp ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint64 *data ;
  TIFFField const   *tmp ;
  uint64 *resizeddata ;
  void *tmp___0 ;

  {


  err = TIFFReadDirEntryLong8Array(tif, dir, & data);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5662", "0", checkpoints_buf);
  if ((unsigned int )err != 0U) {


    tmp = TIFFFieldWithTag(tif, (uint32 )dir->tdir_tag);



    TIFFReadDirEntryOutputErr(tif, err, module___6,
                              (char const   *)tmp->field_name, 0);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5665", "0", checkpoints_buf);
    return (0);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5662", "0", checkpoints_buf);

  if (dir->tdir_count != (uint64 )nstrips) {


    tmp___0 = _TIFFCheckMalloc(tif, (tmsize_t )nstrips,
                               (tmsize_t )sizeof(uint64 ), "for strip array");


    resizeddata = (uint64 *)tmp___0;

    if ((unsigned int )resizeddata == (unsigned int )((uint64 *)0)) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5671", "0", checkpoints_buf);
      return (0);
    } else {

    }

    if (dir->tdir_count < (uint64 )nstrips) {

      _TIFFmemcpy((void *)resizeddata, (void const   *)data,
                  (tmsize_t )((uint32 )dir->tdir_count * sizeof(uint64 )));


      _TIFFmemset((void *)(resizeddata + (uint32 )dir->tdir_count), 0,
                  (tmsize_t )((nstrips - (uint32 )dir->tdir_count) * sizeof(uint64 )));

    } else {

      _TIFFmemcpy((void *)resizeddata, (void const   *)data,
                  (tmsize_t )(nstrips * sizeof(uint64 )));

    }


    _TIFFfree((void *)data);

    data = resizeddata;

  } else {

  }

  *lpp = data;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5681", "1", checkpoints_buf);
  return (1);
}
}
static int TIFFFetchSubjectDistance(TIFF *tif , TIFFDirEntry *dir ) ;
static char const   module___7[25]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'F',      (char const   )'e',      (char const   )'t',      (char const   )'c', 
        (char const   )'h',      (char const   )'S',      (char const   )'u',      (char const   )'b', 
        (char const   )'j',      (char const   )'e',      (char const   )'c',      (char const   )'t', 
        (char const   )'D',      (char const   )'i',      (char const   )'s',      (char const   )'t', 
        (char const   )'a',      (char const   )'n',      (char const   )'c',      (char const   )'e', 
        (char const   )'\000'};
static int TIFFFetchSubjectDistance(TIFF *tif , TIFFDirEntry *dir ) 
{ 
  enum TIFFReadDirEntryErr err ;
  uint32 m[2] ;
  uint32 offset ;
  double n ;
  int tmp ;

  {
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5682", "8", checkpoints_buf);
  if (sizeof(double ) == 8U) {

  } else {

    __assert_fail("sizeof(double)==8", "tif_dirread.c", 5202U,
                  "TIFFFetchSubjectDistance");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5682", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5685", "8", checkpoints_buf);
  if (sizeof(uint64 ) == 8U) {

  } else {

    __assert_fail("sizeof(uint64)==8", "tif_dirread.c", 5203U,
                  "TIFFFetchSubjectDistance");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5685", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5688", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirread.c", 5204U,
                  "TIFFFetchSubjectDistance");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5688", "4", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5691", "1", checkpoints_buf);
  if (dir->tdir_count != 1ULL) {
    err = (enum TIFFReadDirEntryErr )1;

  } else {
    sprintf(checkpoints_buf, "%d", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5693", "5", checkpoints_buf);
    if ((int )dir->tdir_type != 5) {
      err = (enum TIFFReadDirEntryErr )2;

    } else {

      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5695", "524288", checkpoints_buf);
      if (! (tif->tif_flags & 524288U)) {
        offset = *((uint32 *)(& dir->tdir_offset));


        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5697", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong(& offset);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5697", "128", checkpoints_buf);


        err = TIFFReadDirEntryData(tif, (uint64 )offset, (tmsize_t )8,
                                   (void *)(m));


      } else {
        *((uint64 *)(m)) = dir->tdir_offset;

        err = (enum TIFFReadDirEntryErr )0;

      }

      sprintf(checkpoints_buf, "%u", 524288);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5695", "524288", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5693", "5", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5691", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5703", "0", checkpoints_buf);
  if ((unsigned int )err == 0U) {

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5704", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabArrayOfLong(m, (tmsize_t )2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5704", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5707", "0", checkpoints_buf);
    if (m[0] == 0U) {
      n = 0.0;
      sprintf(checkpoints_buf, "%lf", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5708", "n", checkpoints_buf);
    } else {

      sprintf(checkpoints_buf, "%u", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5709", "4294967295", checkpoints_buf);
      if (m[0] == 4294967295U) {
        n = - 1.0;
        sprintf(checkpoints_buf, "%lf", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5710", "n", checkpoints_buf);
      } else {
        n = (double )m[0] / (double )m[1];
        sprintf(checkpoints_buf, "%lf", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "5711", "n", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "5709", "4294967295", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5707", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5712", "tmp", checkpoints_buf);

    tmp = TIFFSetField(tif, (uint32 )dir->tdir_tag, n);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5712", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5713", "tmp", checkpoints_buf);
    return (tmp);
  } else {

    TIFFReadDirEntryOutputErr(tif, err, module___7, "SubjectDistance", 1);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5715", "0", checkpoints_buf);
    return (0);
  }
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5703", "0", checkpoints_buf);
}
}
static void ChopUpSingleUncompressedStrip(TIFF *tif ) 
{ 
  register TIFFDirectory *td ;
  uint64 bytecount ;
  uint64 offset ;
  uint32 rowblock ;
  uint64 rowblockbytes ;
  uint64 stripbytes ;
  uint32 strip ;
  uint64 nstrips64 ;
  uint32 nstrips32 ;
  uint32 rowsperstrip ;
  uint64 *newcounts ;
  uint64 *newoffsets ;
  uint32 rowblocksperstrip ;
  void *tmp ;
  void *tmp___0 ;
  uint32 tmp___1 ;

  {
  td = & tif->tif_dir;

  bytecount = *(td->td_stripbytecount + 0);

  offset = *(td->td_stripoffset + 0);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5719", "1", checkpoints_buf);
  if ((int )td->td_planarconfig == 1) {

  } else {

    __assert_fail("td->td_planarconfig == 1", "tif_dirread.c", 5274U,
                  "ChopUpSingleUncompressedStrip");

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5719", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5722", "6", checkpoints_buf);
  if ((int )td->td_photometric == 6) {

    sprintf(checkpoints_buf, "%u", 16384);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5723", "16384", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5723", "0", checkpoints_buf);
    if (! ((tif->tif_flags & 16384U) != 0U)) {
      rowblock = (uint32 )td->td_ycbcrsubsampling[1];

    } else {
      rowblock = (uint32 )1;

    }

    sprintf(checkpoints_buf, "%u", 16384);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5723", "16384", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5723", "0", checkpoints_buf);
  } else {
    rowblock = (uint32 )1;

  }
  sprintf(checkpoints_buf, "%d", 6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5722", "6", checkpoints_buf);


  rowblockbytes = TIFFVTileSize64(tif, rowblock);



  sprintf(checkpoints_buf, "%llu", 8192);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5728", "8192", checkpoints_buf);
  if (rowblockbytes > 8192ULL) {
    stripbytes = rowblockbytes;

    rowsperstrip = rowblock;

  } else {

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5731", "0", checkpoints_buf);
    if (rowblockbytes > 0ULL) {
      rowblocksperstrip = (uint32 )(8192ULL / rowblockbytes);

      rowsperstrip = rowblocksperstrip * rowblock;

      stripbytes = (uint64 )rowblocksperstrip * rowblockbytes;

    } else {
      return;
    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5731", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 8192);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5728", "8192", checkpoints_buf);


  if (rowsperstrip >= td->td_rowsperstrip) {
    return;
  } else {

  }


  nstrips64 = (bytecount + (stripbytes - 1ULL)) / stripbytes;


  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5740", "0", checkpoints_buf);
  if (nstrips64 == 0ULL) {
    return;
  } else {

    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5742", "4294967295", checkpoints_buf);
    if (nstrips64 > 4294967295ULL) {
      return;
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "5742", "4294967295", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "5740", "0", checkpoints_buf);
  nstrips32 = (uint32 )nstrips64;



  tmp = _TIFFCheckMalloc(tif, (tmsize_t )nstrips32, (tmsize_t )sizeof(uint64 ),
                         "for chopped \"StripByteCounts\" array");


  newcounts = (uint64 *)tmp;



  tmp___0 = _TIFFCheckMalloc(tif, (tmsize_t )nstrips32,
                             (tmsize_t )sizeof(uint64 ),
                             "for chopped \"StripOffsets\" array");


  newoffsets = (uint64 *)tmp___0;

  if ((unsigned int )newcounts == (unsigned int )((void *)0)) {
    goto _L;
  } else
  if ((unsigned int )newoffsets == (unsigned int )((void *)0)) {
    _L: /* CIL Label */ 
    if ((unsigned int )newcounts != (unsigned int )((void *)0)) {

      _TIFFfree((void *)newcounts);

    } else {

    }
    if ((unsigned int )newoffsets != (unsigned int )((void *)0)) {

      _TIFFfree((void *)newoffsets);

    } else {

    }
    return;
  } else {

  }
  strip = (uint32 )0;










  while (strip < nstrips32) {




    if (stripbytes > bytecount) {
      stripbytes = bytecount;

    } else {

    }


    *(newcounts + strip) = stripbytes;

    *(newoffsets + strip) = offset;

    offset += stripbytes;

    bytecount -= stripbytes;

    strip ++;

  }









  tmp___1 = nstrips32;

  td->td_nstrips = tmp___1;

  td->td_stripsperimage = tmp___1;


  TIFFSetField(tif, (uint32 )278, rowsperstrip);


  _TIFFfree((void *)td->td_stripbytecount);


  _TIFFfree((void *)td->td_stripoffset);

  td->td_stripbytecount = newcounts;

  td->td_stripoffset = newoffsets;

  td->td_stripbytecountsorted = 1;

  return;
}
}
