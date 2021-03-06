#ifndef GENPROG_CHECKPOINTS_H
#define GENPROG_CHECKPOINTS_H

//This file was created with Single-C-File
//Single-C-File was developed by Adrian Dawid.
/*
*  xxHash - Fast Hash algorithm
*  Copyright (C) 2012-2016, Yann Collet
*
*  BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)
*
*  Redistribution and use in source and binary forms, with or without
*  modification, are permitted provided that the following conditions are
*  met:
*
*  * Redistributions of source code must retain the above copyright
*  notice, this list of conditions and the following disclaimer.
*  * Redistributions in binary form must reproduce the above
*  copyright notice, this list of conditions and the following disclaimer
*  in the documentation and/or other materials provided with the
*  distribution.
*
*  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
*  A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
*  OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
*  SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
*  LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
*  DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
*  THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
*  (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
*  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*
*  You can contact the author at :
*  - xxHash homepage: http://www.xxhash.com
*  - xxHash source repository : https://github.com/Cyan4973/xxHash
*/
/* *************************************
*  Tuning parameters
***************************************/
/*!XXH_FORCE_MEMORY_ACCESS :
 * By default, access to unaligned memory is controlled by `memcpy()`, which is safe and portable.
 * Unfortunately, on some target/compiler combinations, the generated assembly is sub-optimal.
 * The below switch allow to select different access method for improved performance.
 * Method 0 (default) : use `memcpy()`. Safe and portable.
 * Method 1 : `__packed` statement. It depends on compiler extension (ie, not portable).
 *            This method is safe if your compiler supports it, and *generally* as fast or faster than `memcpy`.
 * Method 2 : direct access. This method doesn't depend on compiler but violate C standard.
 *            It can generate buggy code on targets which do not support unaligned memory accesses.
 *            But in some circumstances, it's the only known way to get the most performance (ie GCC + ARMv6)
 * See http://stackoverflow.com/a/32095106/646947 for details.
 * Prefer these methods in priority order (0 > 1 > 2)
 */
#ifndef XXH_FORCE_MEMORY_ACCESS   /* can be defined externally, on command line for example */
#  if defined(__GNUC__) && ( defined(__ARM_ARCH_6__) || defined(__ARM_ARCH_6J__) || defined(__ARM_ARCH_6K__) || defined(__ARM_ARCH_6Z__) || defined(__ARM_ARCH_6ZK__) || defined(__ARM_ARCH_6T2__) )
#    define XXH_FORCE_MEMORY_ACCESS 2
#  elif defined(__INTEL_COMPILER) || \
  (defined(__GNUC__) && ( defined(__ARM_ARCH_7__) || defined(__ARM_ARCH_7A__) || defined(__ARM_ARCH_7R__) || defined(__ARM_ARCH_7M__) || defined(__ARM_ARCH_7S__) ))
#    define XXH_FORCE_MEMORY_ACCESS 1
#  endif
#endif
/*!XXH_ACCEPT_NULL_INPUT_POINTER :
 * If the input pointer is a null pointer, xxHash default behavior is to trigger a memory access error, since it is a bad pointer.
 * When this option is enabled, xxHash output for null input pointers will be the same as a null-length input.
 * By default, this option is disabled. To enable it, uncomment below define :
 */
/* #define XXH_ACCEPT_NULL_INPUT_POINTER 1 */
/*!XXH_FORCE_NATIVE_FORMAT :
 * By default, xxHash library provides endian-independant Hash values, based on little-endian convention.
 * Results are therefore identical for little-endian and big-endian CPU.
 * This comes at a performance cost for big-endian CPU, since some swapping is required to emulate little-endian format.
 * Should endian-independance be of no importance for your application, you may set the #define below to 1,
 * to improve speed for Big-endian CPU.
 * This option has no impact on Little_Endian CPU.
 */
#ifndef XXH_FORCE_NATIVE_FORMAT   /* can be defined externally */
#  define XXH_FORCE_NATIVE_FORMAT 0
#endif
/*!XXH_FORCE_ALIGN_CHECK :
 * This is a minor performance trick, only useful with lots of very small keys.
 * It means : check for aligned/unaligned input.
 * The check costs one initial branch per hash; set to 0 when the input data
 * is guaranteed to be aligned.
 */
#ifndef XXH_FORCE_ALIGN_CHECK /* can be defined externally */
#  if defined(__i386) || defined(_M_IX86) || defined(__x86_64__) || defined(_M_X64)
#    define XXH_FORCE_ALIGN_CHECK 0
#  else
#    define XXH_FORCE_ALIGN_CHECK 1
#  endif
#endif
/* *************************************
*  Includes & Memory related functions
***************************************/
/*! Modify the local functions below should you wish to use some other memory routines
*   for malloc(), free() */
#include <stdlib.h>
static void* XXH_malloc(size_t s) { return malloc(s); }
static void  XXH_free  (void* p)  { free(p); }
/*! and for memcpy() */
#include <string.h>
static void* XXH_memcpy(void* dest, const void* src, size_t size) { return memcpy(dest,src,size); }
#define XXH_STATIC_LINKING_ONLY
/*
   xxHash - Extremely Fast Hash algorithm
   Header File
   Copyright (C) 2012-2016, Yann Collet.
   BSD 2-Clause License (http://www.opensource.org/licenses/bsd-license.php)
   Redistribution and use in source and binary forms, with or without
   modification, are permitted provided that the following conditions are
   met:
       * Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.
       * Redistributions in binary form must reproduce the above
   copyright notice, this list of conditions and the following disclaimer
   in the documentation and/or other materials provided with the
   distribution.
   THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
   "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
   LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
   A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
   OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
   SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
   LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
   DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
   THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
   (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
   OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
   You can contact the author at :
   - xxHash source repository : https://github.com/Cyan4973/xxHash
*/
/* Notice extracted from xxHash homepage :
xxHash is an extremely fast Hash algorithm, running at RAM speed limits.
It also successfully passes all tests from the SMHasher suite.
Comparison (single thread, Windows Seven 32 bits, using SMHasher on a Core 2 Duo @3GHz)
Name            Speed       Q.Score   Author
xxHash          5.4 GB/s     10
CrapWow         3.2 GB/s      2       Andrew
MumurHash 3a    2.7 GB/s     10       Austin Appleby
SpookyHash      2.0 GB/s     10       Bob Jenkins
SBox            1.4 GB/s      9       Bret Mulvey
Lookup3         1.2 GB/s      9       Bob Jenkins
SuperFastHash   1.2 GB/s      1       Paul Hsieh
CityHash64      1.05 GB/s    10       Pike & Alakuijala
FNV             0.55 GB/s     5       Fowler, Noll, Vo
CRC32           0.43 GB/s     9
MD5-32          0.33 GB/s    10       Ronald L. Rivest
SHA1-32         0.28 GB/s    10
Q.Score is a measure of quality of the hash function.
It depends on successfully passing SMHasher test set.
10 is a perfect score.
A 64-bits version, named XXH64, is available since r35.
It offers much better speed, but for 64-bits applications only.
Name     Speed on 64 bits    Speed on 32 bits
XXH64       13.8 GB/s            1.9 GB/s
XXH32        6.8 GB/s            6.0 GB/s
*/
#ifndef XXHASH_H_5627135585666179
#define XXHASH_H_5627135585666179 1
#if defined (__cplusplus)
extern "C" {
#endif
/* ****************************
*  Definitions
******************************/
#include <stddef.h>   /* size_t */
typedef enum { XXH_OK=0, XXH_ERROR } XXH_errorcode;
/* ****************************
*  API modifier
******************************/
/** XXH_PRIVATE_API
*   This is useful to include xxhash functions in `static` mode
*   in order to inline them, and remove their symbol from the public list.
*   Methodology :
*     #define XXH_PRIVATE_API
*     #include "xxhash.h"
*   `xxhash.c` is automatically included.
*   It's not useful to compile and link it as a separate module.
*/
#ifdef XXH_PRIVATE_API
#  ifndef XXH_STATIC_LINKING_ONLY
#    define XXH_STATIC_LINKING_ONLY
#  endif
#  if defined(__GNUC__)
#    define XXH_PUBLIC_API static __inline __attribute__((unused))
#  elif defined (__cplusplus) || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) /* C99 */)
#    define XXH_PUBLIC_API static inline
#  elif defined(_MSC_VER)
#    define XXH_PUBLIC_API static __inline
#  else
#    define XXH_PUBLIC_API static   /* this version may generate warnings for unused static functions; disable the relevant warning */
#  endif
#else
#  define XXH_PUBLIC_API   /* do nothing */
#endif /* XXH_PRIVATE_API */
/*!XXH_NAMESPACE, aka Namespace Emulation :
If you want to include _and expose_ xxHash functions from within your own library,
but also want to avoid symbol collisions with other libraries which may also include xxHash,
you can use XXH_NAMESPACE, to automatically prefix any public symbol from xxhash library
with the value of XXH_NAMESPACE (therefore, avoid NULL and numeric values).
Note that no change is required within the calling program as long as it includes `xxhash.h` :
regular symbol name will be automatically translated by this header.
*/
#ifdef XXH_NAMESPACE
#  define XXH_CAT(A,B) A##B
#  define XXH_NAME2(A,B) XXH_CAT(A,B)
#  define XXH_versionNumber XXH_NAME2(XXH_NAMESPACE, XXH_versionNumber)
#  define XXH32 XXH_NAME2(XXH_NAMESPACE, XXH32)
#  define XXH32_createState XXH_NAME2(XXH_NAMESPACE, XXH32_createState)
#  define XXH32_freeState XXH_NAME2(XXH_NAMESPACE, XXH32_freeState)
#  define XXH32_reset XXH_NAME2(XXH_NAMESPACE, XXH32_reset)
#  define XXH32_update XXH_NAME2(XXH_NAMESPACE, XXH32_update)
#  define XXH32_digest XXH_NAME2(XXH_NAMESPACE, XXH32_digest)
#  define XXH32_copyState XXH_NAME2(XXH_NAMESPACE, XXH32_copyState)
#  define XXH32_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH32_canonicalFromHash)
#  define XXH32_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH32_hashFromCanonical)
#  define XXH64 XXH_NAME2(XXH_NAMESPACE, XXH64)
#  define XXH64_createState XXH_NAME2(XXH_NAMESPACE, XXH64_createState)
#  define XXH64_freeState XXH_NAME2(XXH_NAMESPACE, XXH64_freeState)
#  define XXH64_reset XXH_NAME2(XXH_NAMESPACE, XXH64_reset)
#  define XXH64_update XXH_NAME2(XXH_NAMESPACE, XXH64_update)
#  define XXH64_digest XXH_NAME2(XXH_NAMESPACE, XXH64_digest)
#  define XXH64_copyState XXH_NAME2(XXH_NAMESPACE, XXH64_copyState)
#  define XXH64_canonicalFromHash XXH_NAME2(XXH_NAMESPACE, XXH64_canonicalFromHash)
#  define XXH64_hashFromCanonical XXH_NAME2(XXH_NAMESPACE, XXH64_hashFromCanonical)
#endif
/* *************************************
*  Version
***************************************/
#define XXH_VERSION_MAJOR    0
#define XXH_VERSION_MINOR    6
#define XXH_VERSION_RELEASE  2
#define XXH_VERSION_NUMBER  (XXH_VERSION_MAJOR *100*100 + XXH_VERSION_MINOR *100 + XXH_VERSION_RELEASE)
XXH_PUBLIC_API unsigned XXH_versionNumber (void);
/*-**********************************************************************
*  32-bits hash
************************************************************************/
typedef unsigned int       XXH32_hash_t;
/*! XXH32() :
    Calculate the 32-bits hash of sequence "length" bytes stored at memory address "input".
    The memory between input & input+length must be valid (allocated and read-accessible).
    "seed" can be used to alter the result predictably.
    Speed on Core 2 Duo @ 3 GHz (single thread, SMHasher benchmark) : 5.4 GB/s */
XXH_PUBLIC_API XXH32_hash_t XXH32 (const void* input, size_t length, unsigned int seed);
/*======   Streaming   ======*/
typedef struct XXH32_state_s XXH32_state_t;   /* incomplete type */
XXH_PUBLIC_API XXH32_state_t* XXH32_createState(void);
XXH_PUBLIC_API XXH_errorcode  XXH32_freeState(XXH32_state_t* statePtr);
XXH_PUBLIC_API void XXH32_copyState(XXH32_state_t* dst_state, const XXH32_state_t* src_state);
XXH_PUBLIC_API XXH_errorcode XXH32_reset  (XXH32_state_t* statePtr, unsigned int seed);
XXH_PUBLIC_API XXH_errorcode XXH32_update (XXH32_state_t* statePtr, const void* input, size_t length);
XXH_PUBLIC_API XXH32_hash_t  XXH32_digest (const XXH32_state_t* statePtr);
/*
These functions generate the xxHash of an input provided in multiple segments.
Note that, for small input, they are slower than single-call functions, due to state management.
For small input, prefer `XXH32()` and `XXH64()` .
XXH state must first be allocated, using XXH*_createState() .
Start a new hash by initializing state with a seed, using XXH*_reset().
Then, feed the hash state by calling XXH*_update() as many times as necessary.
Obviously, input must be allocated and read accessible.
The function returns an error code, with 0 meaning OK, and any other value meaning there is an error.
Finally, a hash value can be produced anytime, by using XXH*_digest().
This function returns the nn-bits hash as an int or long long.
It's still possible to continue inserting input into the hash state after a digest,
and generate some new hashes later on, by calling again XXH*_digest().
When done, free XXH state space if it was allocated dynamically.
*/
/*======   Canonical representation   ======*/
typedef struct { unsigned char digest[4]; } XXH32_canonical_t;
XXH_PUBLIC_API void XXH32_canonicalFromHash(XXH32_canonical_t* dst, XXH32_hash_t hash);
XXH_PUBLIC_API XXH32_hash_t XXH32_hashFromCanonical(const XXH32_canonical_t* src);
/* Default result type for XXH functions are primitive unsigned 32 and 64 bits.
*  The canonical representation uses human-readable write convention, aka big-endian (large digits first).
*  These functions allow transformation of hash result into and from its canonical format.
*  This way, hash values can be written into a file / memory, and remain comparable on different systems and programs.
*/
#ifndef XXH_NO_LONG_LONG
/*-**********************************************************************
*  64-bits hash
************************************************************************/
typedef unsigned long long XXH64_hash_t;
/*! XXH64() :
    Calculate the 64-bits hash of sequence of length "len" stored at memory address "input".
    "seed" can be used to alter the result predictably.
    This function runs faster on 64-bits systems, but slower on 32-bits systems (see benchmark).
*/
XXH_PUBLIC_API XXH64_hash_t XXH64 (const void* input, size_t length, unsigned long long seed);
/*======   Streaming   ======*/
typedef struct XXH64_state_s XXH64_state_t;   /* incomplete type */
XXH_PUBLIC_API XXH64_state_t* XXH64_createState(void);
XXH_PUBLIC_API XXH_errorcode  XXH64_freeState(XXH64_state_t* statePtr);
XXH_PUBLIC_API void XXH64_copyState(XXH64_state_t* dst_state, const XXH64_state_t* src_state);
XXH_PUBLIC_API XXH_errorcode XXH64_reset  (XXH64_state_t* statePtr, unsigned long long seed);
XXH_PUBLIC_API XXH_errorcode XXH64_update (XXH64_state_t* statePtr, const void* input, size_t length);
XXH_PUBLIC_API XXH64_hash_t  XXH64_digest (const XXH64_state_t* statePtr);
/*======   Canonical representation   ======*/
typedef struct { unsigned char digest[8]; } XXH64_canonical_t;
XXH_PUBLIC_API void XXH64_canonicalFromHash(XXH64_canonical_t* dst, XXH64_hash_t hash);
XXH_PUBLIC_API XXH64_hash_t XXH64_hashFromCanonical(const XXH64_canonical_t* src);
#endif  /* XXH_NO_LONG_LONG */
#ifdef XXH_STATIC_LINKING_ONLY
/* ================================================================================================
   This section contains definitions which are not guaranteed to remain stable.
   They may change in future versions, becoming incompatible with a different version of the library.
   They shall only be used with static linking.
   Never use these definitions in association with dynamic linking !
=================================================================================================== */
/* These definitions are only meant to allow allocation of XXH state
   statically, on stack, or in a struct for example.
   Do not use members directly. */
   struct XXH32_state_s {
       unsigned total_len_32;
       unsigned large_len;
       unsigned v1;
       unsigned v2;
       unsigned v3;
       unsigned v4;
       unsigned mem32[4];   /* buffer defined as U32 for alignment */
       unsigned memsize;
       unsigned reserved;   /* never read nor write, will be removed in a future version */
   };   /* typedef'd to XXH32_state_t */
#ifndef XXH_NO_LONG_LONG
   struct XXH64_state_s {
       unsigned long long total_len;
       unsigned long long v1;
       unsigned long long v2;
       unsigned long long v3;
       unsigned long long v4;
       unsigned long long mem64[4];   /* buffer defined as U64 for alignment */
       unsigned memsize;
       unsigned reserved[2];          /* never read nor write, will be removed in a future version */
   };   /* typedef'd to XXH64_state_t */
#endif
#  ifdef XXH_PRIVATE_API
#    include "xxhash.c"   /* include xxhash function bodies as `static`, for inlining */
#  endif
#endif /* XXH_STATIC_LINKING_ONLY */
#if defined (__cplusplus)
}
#endif
#endif /* XXHASH_H_5627135585666179 */
/* *************************************
*  Compiler Specific Options
***************************************/
#ifdef _MSC_VER    /* Visual Studio */
#  pragma warning(disable : 4127)      /* disable: C4127: conditional expression is constant */
#  define FORCE_INLINE static __forceinline
#else
#  if defined (__cplusplus) || defined (__STDC_VERSION__) && __STDC_VERSION__ >= 199901L   /* C99 */
#    ifdef __GNUC__
#      define FORCE_INLINE static inline __attribute__((always_inline))
#    else
#      define FORCE_INLINE static inline
#    endif
#  else
#    define FORCE_INLINE static
#  endif /* __STDC_VERSION__ */
#endif
/* *************************************
*  Basic Types
***************************************/
#ifndef MEM_MODULE
# if !defined (__VMS) && (defined (__cplusplus) || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) /* C99 */) )
#   include <stdint.h>
    typedef uint8_t  BYTE;
    typedef uint16_t U16;
    typedef uint32_t U32;
    typedef  int32_t S32;
# else
    typedef unsigned char      BYTE;
    typedef unsigned short     U16;
    typedef unsigned int       U32;
    typedef   signed int       S32;
# endif
#endif
#if (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==2))
/* Force direct memory access. Only works on CPU which support unaligned memory access in hardware */
static U32 XXH_read32(const void* memPtr) { return *(const U32*) memPtr; }
#elif (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==1))
/* __pack instructions are safer, but compiler specific, hence potentially problematic for some compilers */
/* currently only defined for gcc and icc */
typedef union { U32 u32; } __attribute__((packed)) unalign;
static U32 XXH_read32(const void* ptr) { return ((const unalign*)ptr)->u32; }
#else
/* portable and safe solution. Generally efficient.
 * see : http://stackoverflow.com/a/32095106/646947
 */
static U32 XXH_read32(const void* memPtr)
{
    U32 val;
    memcpy(&val, memPtr, sizeof(val));
    return val;
}
#endif   /* XXH_FORCE_DIRECT_MEMORY_ACCESS */
/* ****************************************
*  Compiler-specific Functions and Macros
******************************************/
#define XXH_GCC_VERSION (__GNUC__ * 100 + __GNUC_MINOR__)
/* Note : although _rotl exists for minGW (GCC under windows), performance seems poor */
#if defined(_MSC_VER)
#  define XXH_rotl32(x,r) _rotl(x,r)
#  define XXH_rotl64(x,r) _rotl64(x,r)
#else
#  define XXH_rotl32(x,r) ((x << r) | (x >> (32 - r)))
#  define XXH_rotl64(x,r) ((x << r) | (x >> (64 - r)))
#endif
#if defined(_MSC_VER)     /* Visual Studio */
#  define XXH_swap32 _byteswap_ulong
#elif XXH_GCC_VERSION >= 403
#  define XXH_swap32 __builtin_bswap32
#else
static U32 XXH_swap32 (U32 x)
{
    return  ((x << 24) & 0xff000000 ) |
            ((x <<  8) & 0x00ff0000 ) |
            ((x >>  8) & 0x0000ff00 ) |
            ((x >> 24) & 0x000000ff );
}
#endif
/* *************************************
*  Architecture Macros
***************************************/
typedef enum { XXH_bigEndian=0, XXH_littleEndian=1 } XXH_endianess;
/* XXH_CPU_LITTLE_ENDIAN can be defined externally, for example on the compiler command line */
#ifndef XXH_CPU_LITTLE_ENDIAN
    static const int g_one = 1;
#   define XXH_CPU_LITTLE_ENDIAN   (*(const char*)(&g_one))
#endif
/* ***************************
*  Memory reads
*****************************/
typedef enum { XXH_aligned, XXH_unaligned } XXH_alignment;
FORCE_INLINE U32 XXH_readLE32_align(const void* ptr, XXH_endianess endian, XXH_alignment align)
{
    if (align==XXH_unaligned)
        return endian==XXH_littleEndian ? XXH_read32(ptr) : XXH_swap32(XXH_read32(ptr));
    else
        return endian==XXH_littleEndian ? *(const U32*)ptr : XXH_swap32(*(const U32*)ptr);
}
FORCE_INLINE U32 XXH_readLE32(const void* ptr, XXH_endianess endian)
{
    return XXH_readLE32_align(ptr, endian, XXH_unaligned);
}
static U32 XXH_readBE32(const void* ptr)
{
    return XXH_CPU_LITTLE_ENDIAN ? XXH_swap32(XXH_read32(ptr)) : XXH_read32(ptr);
}
/* *************************************
*  Macros
***************************************/
#define XXH_STATIC_ASSERT(c)   { enum { XXH_static_assert = 1/(int)(!!(c)) }; }    /* use only *after* variable declarations */
XXH_PUBLIC_API unsigned XXH_versionNumber (void) { return XXH_VERSION_NUMBER; }
/* *******************************************************************
*  32-bits hash functions
*********************************************************************/
static const U32 PRIME32_1 = 2654435761U;
static const U32 PRIME32_2 = 2246822519U;
static const U32 PRIME32_3 = 3266489917U;
static const U32 PRIME32_4 =  668265263U;
static const U32 PRIME32_5 =  374761393U;
static U32 XXH32_round(U32 seed, U32 input)
{
    seed += input * PRIME32_2;
    seed  = XXH_rotl32(seed, 13);
    seed *= PRIME32_1;
    return seed;
}
FORCE_INLINE U32 XXH32_endian_align(const void* input, size_t len, U32 seed, XXH_endianess endian, XXH_alignment align)
{
    const BYTE* p = (const BYTE*)input;
    const BYTE* bEnd = p + len;
    U32 h32;
#define XXH_get32bits(p) XXH_readLE32_align(p, endian, align)
#ifdef XXH_ACCEPT_NULL_INPUT_POINTER
    if (p==NULL) {
        len=0;
        bEnd=p=(const BYTE*)(size_t)16;
    }
#endif
    if (len>=16) {
        const BYTE* const limit = bEnd - 16;
        U32 v1 = seed + PRIME32_1 + PRIME32_2;
        U32 v2 = seed + PRIME32_2;
        U32 v3 = seed + 0;
        U32 v4 = seed - PRIME32_1;
        do {
            v1 = XXH32_round(v1, XXH_get32bits(p)); p+=4;
            v2 = XXH32_round(v2, XXH_get32bits(p)); p+=4;
            v3 = XXH32_round(v3, XXH_get32bits(p)); p+=4;
            v4 = XXH32_round(v4, XXH_get32bits(p)); p+=4;
        } while (p<=limit);
        h32 = XXH_rotl32(v1, 1) + XXH_rotl32(v2, 7) + XXH_rotl32(v3, 12) + XXH_rotl32(v4, 18);
    } else {
        h32  = seed + PRIME32_5;
    }
    h32 += (U32) len;
    while (p+4<=bEnd) {
        h32 += XXH_get32bits(p) * PRIME32_3;
        h32  = XXH_rotl32(h32, 17) * PRIME32_4 ;
        p+=4;
    }
    while (p<bEnd) {
        h32 += (*p) * PRIME32_5;
        h32 = XXH_rotl32(h32, 11) * PRIME32_1 ;
        p++;
    }
    h32 ^= h32 >> 15;
    h32 *= PRIME32_2;
    h32 ^= h32 >> 13;
    h32 *= PRIME32_3;
    h32 ^= h32 >> 16;
    return h32;
}
XXH_PUBLIC_API unsigned int XXH32 (const void* input, size_t len, unsigned int seed)
{
#if 0
    /* Simple version, good for code maintenance, but unfortunately slow for small inputs */
    XXH32_state_t state;
    XXH32_reset(&state, seed);
    XXH32_update(&state, input, len);
    return XXH32_digest(&state);
#else
    XXH_endianess endian_detected = (XXH_endianess)XXH_CPU_LITTLE_ENDIAN;
    if (XXH_FORCE_ALIGN_CHECK) {
        if ((((size_t)input) & 3) == 0) {   /* Input is 4-bytes aligned, leverage the speed benefit */
            if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
                return XXH32_endian_align(input, len, seed, XXH_littleEndian, XXH_aligned);
            else
                return XXH32_endian_align(input, len, seed, XXH_bigEndian, XXH_aligned);
    }   }
    if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
        return XXH32_endian_align(input, len, seed, XXH_littleEndian, XXH_unaligned);
    else
        return XXH32_endian_align(input, len, seed, XXH_bigEndian, XXH_unaligned);
#endif
}
/*======   Hash streaming   ======*/
XXH_PUBLIC_API XXH32_state_t* XXH32_createState(void)
{
    return (XXH32_state_t*)XXH_malloc(sizeof(XXH32_state_t));
}
XXH_PUBLIC_API XXH_errorcode XXH32_freeState(XXH32_state_t* statePtr)
{
    XXH_free(statePtr);
    return XXH_OK;
}
XXH_PUBLIC_API void XXH32_copyState(XXH32_state_t* dstState, const XXH32_state_t* srcState)
{
    memcpy(dstState, srcState, sizeof(*dstState));
}
XXH_PUBLIC_API XXH_errorcode XXH32_reset(XXH32_state_t* statePtr, unsigned int seed)
{
    XXH32_state_t state;   /* using a local state to memcpy() in order to avoid strict-aliasing warnings */
    memset(&state, 0, sizeof(state)-4);   /* do not write into reserved, for future removal */
    state.v1 = seed + PRIME32_1 + PRIME32_2;
    state.v2 = seed + PRIME32_2;
    state.v3 = seed + 0;
    state.v4 = seed - PRIME32_1;
    memcpy(statePtr, &state, sizeof(state));
    return XXH_OK;
}
FORCE_INLINE XXH_errorcode XXH32_update_endian (XXH32_state_t* state, const void* input, size_t len, XXH_endianess endian)
{
    const BYTE* p = (const BYTE*)input;
    const BYTE* const bEnd = p + len;
#ifdef XXH_ACCEPT_NULL_INPUT_POINTER
    if (input==NULL) return XXH_ERROR;
#endif
    state->total_len_32 += (unsigned)len;
    state->large_len |= (len>=16) | (state->total_len_32>=16);
    if (state->memsize + len < 16)  {   /* fill in tmp buffer */
        XXH_memcpy((BYTE*)(state->mem32) + state->memsize, input, len);
        state->memsize += (unsigned)len;
        return XXH_OK;
    }
    if (state->memsize) {   /* some data left from previous update */
        XXH_memcpy((BYTE*)(state->mem32) + state->memsize, input, 16-state->memsize);
        {   const U32* p32 = state->mem32;
            state->v1 = XXH32_round(state->v1, XXH_readLE32(p32, endian)); p32++;
            state->v2 = XXH32_round(state->v2, XXH_readLE32(p32, endian)); p32++;
            state->v3 = XXH32_round(state->v3, XXH_readLE32(p32, endian)); p32++;
            state->v4 = XXH32_round(state->v4, XXH_readLE32(p32, endian)); p32++;
        }
        p += 16-state->memsize;
        state->memsize = 0;
    }
    if (p <= bEnd-16) {
        const BYTE* const limit = bEnd - 16;
        U32 v1 = state->v1;
        U32 v2 = state->v2;
        U32 v3 = state->v3;
        U32 v4 = state->v4;
        do {
            v1 = XXH32_round(v1, XXH_readLE32(p, endian)); p+=4;
            v2 = XXH32_round(v2, XXH_readLE32(p, endian)); p+=4;
            v3 = XXH32_round(v3, XXH_readLE32(p, endian)); p+=4;
            v4 = XXH32_round(v4, XXH_readLE32(p, endian)); p+=4;
        } while (p<=limit);
        state->v1 = v1;
        state->v2 = v2;
        state->v3 = v3;
        state->v4 = v4;
    }
    if (p < bEnd) {
        XXH_memcpy(state->mem32, p, (size_t)(bEnd-p));
        state->memsize = (unsigned)(bEnd-p);
    }
    return XXH_OK;
}
XXH_PUBLIC_API XXH_errorcode XXH32_update (XXH32_state_t* state_in, const void* input, size_t len)
{
    XXH_endianess endian_detected = (XXH_endianess)XXH_CPU_LITTLE_ENDIAN;
    if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
        return XXH32_update_endian(state_in, input, len, XXH_littleEndian);
    else
        return XXH32_update_endian(state_in, input, len, XXH_bigEndian);
}
FORCE_INLINE U32 XXH32_digest_endian (const XXH32_state_t* state, XXH_endianess endian)
{
    const BYTE * p = (const BYTE*)state->mem32;
    const BYTE* const bEnd = (const BYTE*)(state->mem32) + state->memsize;
    U32 h32;
    if (state->large_len) {
        h32 = XXH_rotl32(state->v1, 1) + XXH_rotl32(state->v2, 7) + XXH_rotl32(state->v3, 12) + XXH_rotl32(state->v4, 18);
    } else {
        h32 = state->v3 /* == seed */ + PRIME32_5;
    }
    h32 += state->total_len_32;
    while (p+4<=bEnd) {
        h32 += XXH_readLE32(p, endian) * PRIME32_3;
        h32  = XXH_rotl32(h32, 17) * PRIME32_4;
        p+=4;
    }
    while (p<bEnd) {
        h32 += (*p) * PRIME32_5;
        h32  = XXH_rotl32(h32, 11) * PRIME32_1;
        p++;
    }
    h32 ^= h32 >> 15;
    h32 *= PRIME32_2;
    h32 ^= h32 >> 13;
    h32 *= PRIME32_3;
    h32 ^= h32 >> 16;
    return h32;
}
XXH_PUBLIC_API unsigned int XXH32_digest (const XXH32_state_t* state_in)
{
    XXH_endianess endian_detected = (XXH_endianess)XXH_CPU_LITTLE_ENDIAN;
    if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
        return XXH32_digest_endian(state_in, XXH_littleEndian);
    else
        return XXH32_digest_endian(state_in, XXH_bigEndian);
}
/*======   Canonical representation   ======*/
/*! Default XXH result types are basic unsigned 32 and 64 bits.
*   The canonical representation follows human-readable write convention, aka big-endian (large digits first).
*   These functions allow transformation of hash result into and from its canonical format.
*   This way, hash values can be written into a file or buffer, and remain comparable across different systems and programs.
*/
XXH_PUBLIC_API void XXH32_canonicalFromHash(XXH32_canonical_t* dst, XXH32_hash_t hash)
{
    XXH_STATIC_ASSERT(sizeof(XXH32_canonical_t) == sizeof(XXH32_hash_t));
    if (XXH_CPU_LITTLE_ENDIAN) hash = XXH_swap32(hash);
    memcpy(dst, &hash, sizeof(*dst));
}
XXH_PUBLIC_API XXH32_hash_t XXH32_hashFromCanonical(const XXH32_canonical_t* src)
{
    return XXH_readBE32(src);
}
#ifndef XXH_NO_LONG_LONG
/* *******************************************************************
*  64-bits hash functions
*********************************************************************/
/*======   Memory access   ======*/
#ifndef MEM_MODULE
# define MEM_MODULE
# if !defined (__VMS) && (defined (__cplusplus) || (defined (__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L) /* C99 */) )
#   include <stdint.h>
    typedef uint64_t U64;
# else
    typedef unsigned long long U64;   /* if your compiler doesn't support unsigned long long, replace by another 64-bit type here. Note that xxhash.h will also need to be updated. */
# endif
#endif
#if (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==2))
/* Force direct memory access. Only works on CPU which support unaligned memory access in hardware */
static U64 XXH_read64(const void* memPtr) { return *(const U64*) memPtr; }
#elif (defined(XXH_FORCE_MEMORY_ACCESS) && (XXH_FORCE_MEMORY_ACCESS==1))
/* __pack instructions are safer, but compiler specific, hence potentially problematic for some compilers */
/* currently only defined for gcc and icc */
typedef union { U32 u32; U64 u64; } __attribute__((packed)) unalign64;
static U64 XXH_read64(const void* ptr) { return ((const unalign64*)ptr)->u64; }
#else
/* portable and safe solution. Generally efficient.
 * see : http://stackoverflow.com/a/32095106/646947
 */
static U64 XXH_read64(const void* memPtr)
{
    U64 val;
    memcpy(&val, memPtr, sizeof(val));
    return val;
}
#endif   /* XXH_FORCE_DIRECT_MEMORY_ACCESS */
#if defined(_MSC_VER)     /* Visual Studio */
#  define XXH_swap64 _byteswap_uint64
#elif XXH_GCC_VERSION >= 403
#  define XXH_swap64 __builtin_bswap64
#else
static U64 XXH_swap64 (U64 x)
{
    return  ((x << 56) & 0xff00000000000000ULL) |
            ((x << 40) & 0x00ff000000000000ULL) |
            ((x << 24) & 0x0000ff0000000000ULL) |
            ((x << 8)  & 0x000000ff00000000ULL) |
            ((x >> 8)  & 0x00000000ff000000ULL) |
            ((x >> 24) & 0x0000000000ff0000ULL) |
            ((x >> 40) & 0x000000000000ff00ULL) |
            ((x >> 56) & 0x00000000000000ffULL);
}
#endif
FORCE_INLINE U64 XXH_readLE64_align(const void* ptr, XXH_endianess endian, XXH_alignment align)
{
    if (align==XXH_unaligned)
        return endian==XXH_littleEndian ? XXH_read64(ptr) : XXH_swap64(XXH_read64(ptr));
    else
        return endian==XXH_littleEndian ? *(const U64*)ptr : XXH_swap64(*(const U64*)ptr);
}
FORCE_INLINE U64 XXH_readLE64(const void* ptr, XXH_endianess endian)
{
    return XXH_readLE64_align(ptr, endian, XXH_unaligned);
}
static U64 XXH_readBE64(const void* ptr)
{
    return XXH_CPU_LITTLE_ENDIAN ? XXH_swap64(XXH_read64(ptr)) : XXH_read64(ptr);
}
/*======   xxh64   ======*/
static const U64 PRIME64_1 = 11400714785074694791ULL;
static const U64 PRIME64_2 = 14029467366897019727ULL;
static const U64 PRIME64_3 =  1609587929392839161ULL;
static const U64 PRIME64_4 =  9650029242287828579ULL;
static const U64 PRIME64_5 =  2870177450012600261ULL;
static U64 XXH64_round(U64 acc, U64 input)
{
    acc += input * PRIME64_2;
    acc  = XXH_rotl64(acc, 31);
    acc *= PRIME64_1;
    return acc;
}
static U64 XXH64_mergeRound(U64 acc, U64 val)
{
    val  = XXH64_round(0, val);
    acc ^= val;
    acc  = acc * PRIME64_1 + PRIME64_4;
    return acc;
}
FORCE_INLINE U64 XXH64_endian_align(const void* input, size_t len, U64 seed, XXH_endianess endian, XXH_alignment align)
{
    const BYTE* p = (const BYTE*)input;
    const BYTE* const bEnd = p + len;
    U64 h64;
#define XXH_get64bits(p) XXH_readLE64_align(p, endian, align)
#ifdef XXH_ACCEPT_NULL_INPUT_POINTER
    if (p==NULL) {
        len=0;
        bEnd=p=(const BYTE*)(size_t)32;
    }
#endif
    if (len>=32) {
        const BYTE* const limit = bEnd - 32;
        U64 v1 = seed + PRIME64_1 + PRIME64_2;
        U64 v2 = seed + PRIME64_2;
        U64 v3 = seed + 0;
        U64 v4 = seed - PRIME64_1;
        do {
            v1 = XXH64_round(v1, XXH_get64bits(p)); p+=8;
            v2 = XXH64_round(v2, XXH_get64bits(p)); p+=8;
            v3 = XXH64_round(v3, XXH_get64bits(p)); p+=8;
            v4 = XXH64_round(v4, XXH_get64bits(p)); p+=8;
        } while (p<=limit);
        h64 = XXH_rotl64(v1, 1) + XXH_rotl64(v2, 7) + XXH_rotl64(v3, 12) + XXH_rotl64(v4, 18);
        h64 = XXH64_mergeRound(h64, v1);
        h64 = XXH64_mergeRound(h64, v2);
        h64 = XXH64_mergeRound(h64, v3);
        h64 = XXH64_mergeRound(h64, v4);
    } else {
        h64  = seed + PRIME64_5;
    }
    h64 += (U64) len;
    while (p+8<=bEnd) {
        U64 const k1 = XXH64_round(0, XXH_get64bits(p));
        h64 ^= k1;
        h64  = XXH_rotl64(h64,27) * PRIME64_1 + PRIME64_4;
        p+=8;
    }
    if (p+4<=bEnd) {
        h64 ^= (U64)(XXH_get32bits(p)) * PRIME64_1;
        h64 = XXH_rotl64(h64, 23) * PRIME64_2 + PRIME64_3;
        p+=4;
    }
    while (p<bEnd) {
        h64 ^= (*p) * PRIME64_5;
        h64 = XXH_rotl64(h64, 11) * PRIME64_1;
        p++;
    }
    h64 ^= h64 >> 33;
    h64 *= PRIME64_2;
    h64 ^= h64 >> 29;
    h64 *= PRIME64_3;
    h64 ^= h64 >> 32;
    return h64;
}
XXH_PUBLIC_API unsigned long long XXH64 (const void* input, size_t len, unsigned long long seed)
{
#if 0
    /* Simple version, good for code maintenance, but unfortunately slow for small inputs */
    XXH64_state_t state;
    XXH64_reset(&state, seed);
    XXH64_update(&state, input, len);
    return XXH64_digest(&state);
#else
    XXH_endianess endian_detected = (XXH_endianess)XXH_CPU_LITTLE_ENDIAN;
    if (XXH_FORCE_ALIGN_CHECK) {
        if ((((size_t)input) & 7)==0) {  /* Input is aligned, let's leverage the speed advantage */
            if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
                return XXH64_endian_align(input, len, seed, XXH_littleEndian, XXH_aligned);
            else
                return XXH64_endian_align(input, len, seed, XXH_bigEndian, XXH_aligned);
    }   }
    if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
        return XXH64_endian_align(input, len, seed, XXH_littleEndian, XXH_unaligned);
    else
        return XXH64_endian_align(input, len, seed, XXH_bigEndian, XXH_unaligned);
#endif
}
/*======   Hash Streaming   ======*/
XXH_PUBLIC_API XXH64_state_t* XXH64_createState(void)
{
    return (XXH64_state_t*)XXH_malloc(sizeof(XXH64_state_t));
}
XXH_PUBLIC_API XXH_errorcode XXH64_freeState(XXH64_state_t* statePtr)
{
    XXH_free(statePtr);
    return XXH_OK;
}
XXH_PUBLIC_API void XXH64_copyState(XXH64_state_t* dstState, const XXH64_state_t* srcState)
{
    memcpy(dstState, srcState, sizeof(*dstState));
}
XXH_PUBLIC_API XXH_errorcode XXH64_reset(XXH64_state_t* statePtr, unsigned long long seed)
{
    XXH64_state_t state;   /* using a local state to memcpy() in order to avoid strict-aliasing warnings */
    memset(&state, 0, sizeof(state)-8);   /* do not write into reserved, for future removal */
    state.v1 = seed + PRIME64_1 + PRIME64_2;
    state.v2 = seed + PRIME64_2;
    state.v3 = seed + 0;
    state.v4 = seed - PRIME64_1;
    memcpy(statePtr, &state, sizeof(state));
    return XXH_OK;
}
FORCE_INLINE XXH_errorcode XXH64_update_endian (XXH64_state_t* state, const void* input, size_t len, XXH_endianess endian)
{
    const BYTE* p = (const BYTE*)input;
    const BYTE* const bEnd = p + len;
#ifdef XXH_ACCEPT_NULL_INPUT_POINTER
    if (input==NULL) return XXH_ERROR;
#endif
    state->total_len += len;
    if (state->memsize + len < 32) {  /* fill in tmp buffer */
        XXH_memcpy(((BYTE*)state->mem64) + state->memsize, input, len);
        state->memsize += (U32)len;
        return XXH_OK;
    }
    if (state->memsize) {   /* tmp buffer is full */
        XXH_memcpy(((BYTE*)state->mem64) + state->memsize, input, 32-state->memsize);
        state->v1 = XXH64_round(state->v1, XXH_readLE64(state->mem64+0, endian));
        state->v2 = XXH64_round(state->v2, XXH_readLE64(state->mem64+1, endian));
        state->v3 = XXH64_round(state->v3, XXH_readLE64(state->mem64+2, endian));
        state->v4 = XXH64_round(state->v4, XXH_readLE64(state->mem64+3, endian));
        p += 32-state->memsize;
        state->memsize = 0;
    }
    if (p+32 <= bEnd) {
        const BYTE* const limit = bEnd - 32;
        U64 v1 = state->v1;
        U64 v2 = state->v2;
        U64 v3 = state->v3;
        U64 v4 = state->v4;
        do {
            v1 = XXH64_round(v1, XXH_readLE64(p, endian)); p+=8;
            v2 = XXH64_round(v2, XXH_readLE64(p, endian)); p+=8;
            v3 = XXH64_round(v3, XXH_readLE64(p, endian)); p+=8;
            v4 = XXH64_round(v4, XXH_readLE64(p, endian)); p+=8;
        } while (p<=limit);
        state->v1 = v1;
        state->v2 = v2;
        state->v3 = v3;
        state->v4 = v4;
    }
    if (p < bEnd) {
        XXH_memcpy(state->mem64, p, (size_t)(bEnd-p));
        state->memsize = (unsigned)(bEnd-p);
    }
    return XXH_OK;
}
XXH_PUBLIC_API XXH_errorcode XXH64_update (XXH64_state_t* state_in, const void* input, size_t len)
{
    XXH_endianess endian_detected = (XXH_endianess)XXH_CPU_LITTLE_ENDIAN;
    if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
        return XXH64_update_endian(state_in, input, len, XXH_littleEndian);
    else
        return XXH64_update_endian(state_in, input, len, XXH_bigEndian);
}
FORCE_INLINE U64 XXH64_digest_endian (const XXH64_state_t* state, XXH_endianess endian)
{
    const BYTE * p = (const BYTE*)state->mem64;
    const BYTE* const bEnd = (const BYTE*)state->mem64 + state->memsize;
    U64 h64;
    if (state->total_len >= 32) {
        U64 const v1 = state->v1;
        U64 const v2 = state->v2;
        U64 const v3 = state->v3;
        U64 const v4 = state->v4;
        h64 = XXH_rotl64(v1, 1) + XXH_rotl64(v2, 7) + XXH_rotl64(v3, 12) + XXH_rotl64(v4, 18);
        h64 = XXH64_mergeRound(h64, v1);
        h64 = XXH64_mergeRound(h64, v2);
        h64 = XXH64_mergeRound(h64, v3);
        h64 = XXH64_mergeRound(h64, v4);
    } else {
        h64  = state->v3 + PRIME64_5;
    }
    h64 += (U64) state->total_len;
    while (p+8<=bEnd) {
        U64 const k1 = XXH64_round(0, XXH_readLE64(p, endian));
        h64 ^= k1;
        h64  = XXH_rotl64(h64,27) * PRIME64_1 + PRIME64_4;
        p+=8;
    }
    if (p+4<=bEnd) {
        h64 ^= (U64)(XXH_readLE32(p, endian)) * PRIME64_1;
        h64  = XXH_rotl64(h64, 23) * PRIME64_2 + PRIME64_3;
        p+=4;
    }
    while (p<bEnd) {
        h64 ^= (*p) * PRIME64_5;
        h64  = XXH_rotl64(h64, 11) * PRIME64_1;
        p++;
    }
    h64 ^= h64 >> 33;
    h64 *= PRIME64_2;
    h64 ^= h64 >> 29;
    h64 *= PRIME64_3;
    h64 ^= h64 >> 32;
    return h64;
}
XXH_PUBLIC_API unsigned long long XXH64_digest (const XXH64_state_t* state_in)
{
    XXH_endianess endian_detected = (XXH_endianess)XXH_CPU_LITTLE_ENDIAN;
    if ((endian_detected==XXH_littleEndian) || XXH_FORCE_NATIVE_FORMAT)
        return XXH64_digest_endian(state_in, XXH_littleEndian);
    else
        return XXH64_digest_endian(state_in, XXH_bigEndian);
}
/*====== Canonical representation   ======*/
XXH_PUBLIC_API void XXH64_canonicalFromHash(XXH64_canonical_t* dst, XXH64_hash_t hash)
{
    XXH_STATIC_ASSERT(sizeof(XXH64_canonical_t) == sizeof(XXH64_hash_t));
    if (XXH_CPU_LITTLE_ENDIAN) hash = XXH_swap64(hash);
    memcpy(dst, &hash, sizeof(*dst));
}
XXH_PUBLIC_API XXH64_hash_t XXH64_hashFromCanonical(const XXH64_canonical_t* src)
{
    return XXH_readBE64(src);
}
#endif  /* XXH_NO_LONG_LONG */

/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>


/*
 * xxHash
 */


U32 checkpoints_hash(char *buf)
{
    XXH32_state_t state;
    XXH32_reset(&state, 0);   // <=== new line
    XXH32_update(&state, buf, strlen(buf));
    return XXH32_digest(&state);
}


/*
 * Helpers
 */

/**
 * C++ version 0.4 char* style "itoa":
 * Written by Lukás Chmela
 * Released under GPLv3.

 */
char* itoa(unsigned int value, char* result, int base) {
	// check that the base if valid
	if (base < 2 || base > 36) { *result = '\0'; return result; }

	char* ptr = result, *ptr1 = result, tmp_char;
	unsigned int tmp_value;

	do {
		tmp_value = value;
		value /= base;
		*ptr++ = "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcdefghijklmnopqrstuvwxyz" [35 + (tmp_value - value * base)];
	} while ( value );

	// Apply negative sign
	if (tmp_value < 0) *ptr++ = '-';
	*ptr-- = '\0';
	while(ptr1 < ptr) {
		tmp_char = *ptr;
		*ptr--= *ptr1;
		*ptr1++ = tmp_char;
	}
	return result;
}

char *ultostr(unsigned long value, char *ptr, int base)
{
  unsigned long t = 0, res = 0;
  unsigned long tmp = value;
  int count = 0;

  if (NULL == ptr)
  {
    return NULL;
  }

  if (tmp == 0)
  {
    count++;
  }

  while(tmp > 0)
  {
    tmp = tmp/base;
    count++;
  }

  ptr += count;

  *ptr = '\0';

  do
  {
    res = value - base * (t = value / base);
    if (res < 10)
    {
      * -- ptr = '0' + res;
    }
    else if ((res >= 10) && (res < 16))
    {
        * --ptr = 'A' - 10 + res;
    }
  } while ((value = t) != 0);

  return(ptr);
}

/*
 * Redis
 */


void print_hex(const char *buf)
{
    int i = 0;
    int len = strlen(buf);

    for (i = 0; i < len; ++i)
    {
        printf("%02x ", buf[i]);
    }
    printf("\n");
}


unsigned int
checkpoints_redis_get(const char *key, char *buf)
{
    FILE *pFile;
    size_t response_size;

    pFile = fopen(key, "rb");
    if (pFile == NULL) return 0;

    response_size = fread(buf, 1, 20, pFile);

    fclose(pFile);

    return response_size;
}


void checkpoints_redis_set(
    const char *key,
    const char *value,
    const unsigned int value_len
)
{
    FILE *pFile;
    pFile = fopen(key, "wb");
    fwrite(value, sizeof(char), value_len, pFile);
    fclose(pFile);
}


void checkpoints_log(
    char *path,
    char *stmt_id,
    char *var_name,
    char *value
)
{
    const char divider[]   = ":";
    const char base_path[] = "/dev/shm/";

    char path_hash[128];
    char key[128];
    char old_value_hash[128];
    char value_hash[128];
    char new_value[256];
    char new_value_hash[128];

    size_t path_hash_len;
    size_t stmt_id_len = strlen(stmt_id);
    size_t var_name_len = strlen(var_name);
    size_t old_value_hash_len;
    size_t value_hash_len;
    size_t new_value_hash_len;

    //

    memset(path_hash, '\0', 128);
    memset(key, '\0', 128);
    memset(old_value_hash, '\0', 128);
    memset(value_hash, '\0', 128);
    memset(new_value, '\0', 256);
    memset(new_value_hash, '\0', 128);

    // Path

    itoa(checkpoints_hash(path), path_hash, 10);
    path_hash_len = strlen(path_hash);

    // Key

    memcpy(key, base_path, 9);
    memcpy(key + 9, path_hash, path_hash_len);
    memcpy(key + 9 + path_hash_len, divider, 1);
    memcpy(key + 9 + path_hash_len + 1, stmt_id, stmt_id_len);
    memcpy(key + 9 + path_hash_len + 1 + stmt_id_len, divider, 1);
    memcpy(key + 9 + path_hash_len + 1 + stmt_id_len + 1, var_name, var_name_len);

    // Old value hash

    old_value_hash_len = checkpoints_redis_get(key, old_value_hash);

    // Value hash

    itoa(checkpoints_hash(value), value_hash, 10);
    value_hash_len  = strlen(value_hash);

    // New value

    memcpy(new_value, old_value_hash, old_value_hash_len);
    memcpy(new_value + old_value_hash_len, value_hash, value_hash_len);

    // New value hash

    itoa(checkpoints_hash(new_value), new_value_hash, 10);
    new_value_hash_len  = strlen(new_value_hash);

    // Set

    checkpoints_redis_set(key, new_value_hash, new_value_hash_len);
}

// char checkpoints_buf[256];

// int main(void)
// {
//     // Params
//     char path[]         = "/path/to/destiny";
//     char stmt_id[]      = "15";
//     char var_name[]     = "abc";
//     char value[]        = "3849";
//
//
//     int i = 0;
//
//     // // for (i = 0; i < 16000000; ++i) {
//     for (i = 0; i < 400000; ++i) {
//         checkpoints_log(path, stmt_id, var_name, value);
//     }
//
//     return 0;
// }

#endif
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
typedef int __key_t;
typedef int __clockid_t;
typedef void *__timer_t;
typedef long __blksize_t;
typedef long __blkcnt_t;
typedef unsigned long __fsblkcnt_t;
typedef unsigned long __fsfilcnt_t;
typedef long __fsword_t;
typedef long __syscall_slong_t;
typedef unsigned long __syscall_ulong_t;
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
typedef __builtin_va_list __gnuc_va_list;
struct _IO_jump_t;
struct _IO_jump_t;
typedef void _IO_lock_t;
struct _IO_FILE_plus;
struct _IO_FILE_plus;
typedef int __io_close_fn(void *__cookie );
typedef __gnuc_va_list va_list;
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
extern struct _IO_FILE_plus _IO_2_1_stdin_ ;
extern struct _IO_FILE_plus _IO_2_1_stdout_ ;
extern struct _IO_FILE_plus _IO_2_1_stderr_ ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) _IO_flockfile)(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__leaf__)) _IO_funlockfile)(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__leaf__)) _IO_ftrylockfile)(_IO_FILE * ) ;
extern int sys_nerr ;
extern char const   * const  sys_errlist[] ;
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
int main(void) 
{ 
  int a ;
  int b ;
  int c ;
  int d ;
  int e ;

  {

  printf((char const   */* __restrict  */)"Please enter 4 numbers separated by spaces > ");


  scanf((char const   */* __restrict  */)"%d %d %d %d", & a, & b, & c, & d);

  sprintf(checkpoints_buf, "%d", a);
  checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                  "3", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", b);
  checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                  "3", "b", checkpoints_buf);
  if (a < b) {
    sprintf(checkpoints_buf, "%d", a);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "4", "a", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "4", "c", checkpoints_buf);
    if (a < c) {
      sprintf(checkpoints_buf, "%d", a);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "5", "a", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", d);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "5", "d", checkpoints_buf);
      if (a < d) {
        e = a;
        sprintf(checkpoints_buf, "%d", e);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "6", "e", checkpoints_buf);
      } else {
        goto _L___2;
      }
      sprintf(checkpoints_buf, "%d", a);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "5", "a", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", d);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "5", "d", checkpoints_buf);
    } else {
      goto _L___2;
    }
    sprintf(checkpoints_buf, "%d", a);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "4", "a", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "4", "c", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", b);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "9", "b", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", a);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "9", "a", checkpoints_buf);
    _L___2: /* CIL Label */ 
    _L___1: /* CIL Label */ 
    if (b < a) {
      sprintf(checkpoints_buf, "%d", b);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "10", "b", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", c);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "10", "c", checkpoints_buf);
      if (b < c) {
        sprintf(checkpoints_buf, "%d", b);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "11", "b", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", d);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "11", "d", checkpoints_buf);
        if (b < d) {
          e = b;
          sprintf(checkpoints_buf, "%d", e);
          checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                          "12", "e", checkpoints_buf);
        } else {
          goto _L___0;
        }
        sprintf(checkpoints_buf, "%d", b);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "11", "b", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", d);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "11", "d", checkpoints_buf);
      } else {
        goto _L___0;
      }
      sprintf(checkpoints_buf, "%d", b);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "10", "b", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", c);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "10", "c", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", c);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "15", "c", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", a);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "15", "a", checkpoints_buf);
      _L___0: /* CIL Label */ 
      _L: /* CIL Label */ 
      if (c < a) {
        sprintf(checkpoints_buf, "%d", c);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "16", "c", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", b);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "16", "b", checkpoints_buf);
        if (c < b) {
          sprintf(checkpoints_buf, "%d", c);
          checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                          "17", "c", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", d);
          checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                          "17", "d", checkpoints_buf);
          if (c < d) {
            e = c;
            sprintf(checkpoints_buf, "%d", e);
            checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                            "18", "e", checkpoints_buf);
          } else {
            e = d;
            sprintf(checkpoints_buf, "%d", e);
            checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                            "19", "e", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", c);
          checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                          "17", "c", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", d);
          checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                          "17", "d", checkpoints_buf);
        } else {
          e = d;
          sprintf(checkpoints_buf, "%d", e);
          checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                          "20", "e", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", c);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "16", "c", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", b);
        checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                        "16", "b", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", c);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "15", "c", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", a);
      checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                      "15", "a", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", b);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "9", "b", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", a);
    checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                    "9", "a", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", a);
  checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                  "3", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", b);
  checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                  "3", "b", checkpoints_buf);

  printf((char const   */* __restrict  */)"%d is the smallest\n", e);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/workdir/experiment/smallest-36d8008b13f6475ca8fa4553fea10042b0a6c623665065672051445c3464d61b29b47cb66321844a0264505a0f5ccf5aa6de072aa266b5a8b0cf13198380a389-13",
                  "23", "0", checkpoints_buf);
  return (0);
}
}
