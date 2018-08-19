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
union __anonunion___WAIT_STATUS_3 {
   union wait *__uptr ;
   int *__iptr ;
};
struct __anonstruct_div_t_4 {
   int quot ;
   int rem ;
};
struct __anonstruct_ldiv_t_5 {
   long quot ;
   long rem ;
};
struct __anonstruct_lldiv_t_6 {
   long long quot ;
   long long rem ;
};
struct __locale_data;
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
struct __anonstruct___fsid_t_7 {
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
typedef __ino64_t ino64_t;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __uid_t uid_t;
typedef __off64_t off64_t;
typedef __pid_t pid_t;
typedef __id_t id_t;
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
typedef unsigned char u_int8_t;
typedef unsigned short u_int16_t;
typedef unsigned int u_int32_t;
typedef unsigned long long u_int64_t;
typedef int __sig_atomic_t;
struct __anonstruct___sigset_t_8 {
   unsigned long __val[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef __sigset_t sigset_t;
typedef long __fd_mask;
struct __anonstruct_fd_set_9 {
   __fd_mask fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef unsigned long pthread_t;
union __anonunion_pthread_attr_t_10 {
   char __size[36] ;
   long __align ;
};
union __anonunion____missing_field_name_12 {
   int __spins ;
   __pthread_slist_t __list ;
};
union __anonunion_pthread_mutex_t_11 {
   struct __pthread_mutex_s __data ;
   char __size[24] ;
   long __align ;
};
union __anonunion_pthread_mutexattr_t_13 {
   char __size[4] ;
   long __align ;
};
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
union __anonunion_pthread_condattr_t_16 {
   char __size[4] ;
   long __align ;
};
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
union __anonunion_pthread_rwlockattr_t_19 {
   char __size[8] ;
   long __align ;
};
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_20 {
   char __size[20] ;
   long __align ;
};
union __anonunion_pthread_barrierattr_t_21 {
   char __size[4] ;
   int __align ;
};
typedef int (*__compar_fn_t)(void const   * , void const   * );
typedef int (*comparison_fn_t)(void const   * , void const   * );
typedef int (*__compar_d_fn_t)(void const   * , void const   * , void * );
typedef void *voidp;
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
struct __anonstruct__G_fpos_t_24 {
   __off_t __pos ;
   __mbstate_t __state ;
};
struct __anonstruct__G_fpos64_t_25 {
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
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) a64l)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *alloca(size_t __size ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemps64)(char *__template ,
                                                         int __suffixlen ) ;
extern int ( __attribute__((__nonnull__(1))) mkostemps64)(char *__template ,
                                                          int __suffixlen ,
                                                          int __flags ) ;
extern struct _IO_FILE_plus _IO_2_1_stdin_ ;
extern struct _IO_FILE_plus _IO_2_1_stdout_ ;
extern struct _IO_FILE_plus _IO_2_1_stderr_ ;
extern void _IO_cookie_init(struct _IO_cookie_file *__cfile , int __read_write ,
                            void *__cookie , _IO_cookie_io_functions_t __fns ) ;
extern  __attribute__((__nothrow__)) void _IO_flockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) void _IO_funlockfile(_IO_FILE * ) ;
extern  __attribute__((__nothrow__)) int _IO_ftrylockfile(_IO_FILE * ) ;
extern int fputs_unlocked(char const   * __restrict  __s ,
                          FILE * __restrict  __stream ) ;
extern int sys_nerr ;
extern char const   * const  sys_errlist[] ;
extern int _sys_nerr ;
extern char const   * const  _sys_errlist[] ;
extern int rpl_fflush(FILE *gl_stream ) ;
extern int _gl_cxxalias_dummy ;
extern int ( __attribute__((__nonnull__(1))) fpurge)(FILE *gl_stream ) ;
extern int ( __attribute__((__nonnull__(1))) rpl_fseeko)(FILE *fp ,
                                                         off_t offset ,
                                                         int whence ) ;
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
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1))) rawmemchr)(void const   *__s ,
                                                                                        int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(2,3))) __strtok_r)(char * __restrict  __s ,
                                                                                           char const   * __restrict  __delim ,
                                                                                           char ** __restrict  __save_ptr ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1,2))) __mempcpy)(void * __restrict  __dest ,
                                                                                          void const   * __restrict  __src ,
                                                                                          size_t __n ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) index)(char const   *__s ,
                                                                                    int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) rindex)(char const   *__s ,
                                                                                     int __c )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ffsl(long __l )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ffsll(long long __ll )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strcasecmp)(char const   *__s1 ,
                                                                                         char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,3))) strcasecmp_l)(char const   *__s1 ,
                                                                                             char const   *__s2 ,
                                                                                             __locale_t __loc )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,4))) strncasecmp_l)(char const   *__s1 ,
                                                                                              char const   *__s2 ,
                                                                                              size_t __n ,
                                                                                              __locale_t __loc )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) __stpcpy)(char * __restrict  __dest ,
                                                                                         char const   * __restrict  __src ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) strverscmp)(char const   *__s1 ,
                                                                                         char const   *__s2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) strfry)(char *__string ) ;
extern  __attribute__((__nothrow__)) void *( __attribute__((__nonnull__(1))) memfrob)(void *__s ,
                                                                                      size_t __n ) ;
extern char *__strsep_g(char **__stringp , char const   *__delim ) ;
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
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "257", "i", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "258", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "258", "i", checkpoints_buf);
  while (1) {
    (c[*p]) ++;

    p ++;

    i --;
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "261", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "262", "i", checkpoints_buf);
    if (i) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "262", "i", checkpoints_buf);
  }


  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "258", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "258", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "265", "n", checkpoints_buf);
  if (c[0] == n) {


    tmp = malloc(2U * sizeof(*q));


    q = (struct huft *)tmp;


    if (! q) {
      sprintf(checkpoints_buf, "%d", 3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "269", "3", checkpoints_buf);
      return (3);
    } else {

    }

    hufts += 2U;
    sprintf(checkpoints_buf, "%u", hufts);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "271", "hufts", checkpoints_buf);
    (q + 0)->v.t = (struct huft *)((void *)0);

    (q + 1)->e = (uch )99;

    (q + 1)->b = (uch )1;

    *t = q + 1;

    *m = 1;

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "277", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "265", "n", checkpoints_buf);
  l = *m;
  sprintf(checkpoints_buf, "%d", l);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "279", "l", checkpoints_buf);
  j = 1U;
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "280", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "281", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "281", "16", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "281", "j", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "282", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "282", "16", checkpoints_buf);
    if (j <= 16U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "282", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "282", "16", checkpoints_buf);

    if (c[j]) {
      break;
    } else {

    }

    j ++;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "288", "j", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "281", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "281", "16", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "281", "j", checkpoints_buf);
  k = (int )j;
  sprintf(checkpoints_buf, "%d", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "289", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "290", "j", checkpoints_buf);
  if ((unsigned int )l < j) {
    l = (int )j;
    sprintf(checkpoints_buf, "%d", l);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "291", "l", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "290", "j", checkpoints_buf);
  i = 16U;
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "293", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "294", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "294", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "295", "i", checkpoints_buf);
    if (i) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "295", "i", checkpoints_buf);

    if (c[i]) {
      break;
    } else {

    }

    i --;
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "301", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "294", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "294", "i", checkpoints_buf);
  g = (int )i;
  sprintf(checkpoints_buf, "%d", g);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "302", "g", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "303", "i", checkpoints_buf);
  if ((unsigned int )l > i) {
    l = (int )i;
    sprintf(checkpoints_buf, "%d", l);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "304", "l", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "303", "i", checkpoints_buf);
  *m = l;

  y = 1 << j;
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "307", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "y", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "309", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "309", "i", checkpoints_buf);
    if (j < i) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "309", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "309", "i", checkpoints_buf);
    y = (int )((unsigned int )y - c[j]);
    sprintf(checkpoints_buf, "%d", y);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "312", "y", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", y);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "313", "y", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "313", "0", checkpoints_buf);
    if (y < 0) {
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "314", "2", checkpoints_buf);
      return (2);
    } else {

    }
    sprintf(checkpoints_buf, "%d", y);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "313", "y", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "313", "0", checkpoints_buf);
    j ++;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "316", "j", checkpoints_buf);
    y <<= 1;
    sprintf(checkpoints_buf, "%d", y);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "317", "y", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "308", "y", checkpoints_buf);
  y = (int )((unsigned int )y - c[i]);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "318", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "319", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "319", "0", checkpoints_buf);
  if (y < 0) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "320", "2", checkpoints_buf);
    return (2);
  } else {

  }
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "319", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "319", "0", checkpoints_buf);
  c[i] += (unsigned int )y;

  j = 0U;
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "323", "j", checkpoints_buf);
  x[1] = j;

  p = c + 1;

  xp = x + 2;

  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "327", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "327", "i", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "327", "j", checkpoints_buf);

  while (1) {
    i --;
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "328", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "329", "i", checkpoints_buf);
    if (i) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "329", "i", checkpoints_buf);
    tmp___0 = xp;

    xp ++;

    tmp___1 = p;

    p ++;

    j += *tmp___1;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "336", "j", checkpoints_buf);
    *tmp___0 = j;

  }
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "327", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "327", "i", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "327", "j", checkpoints_buf);

  p = b;

  i = 0U;
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "339", "i", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "n", checkpoints_buf);
  while (1) {
    tmp___3 = p;

    p ++;

    j = *tmp___3;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "343", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "344", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "344", "0", checkpoints_buf);
    if (j != 0U) {
      tmp___2 = x[j];
      sprintf(checkpoints_buf, "%u", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "345", "tmp___2", checkpoints_buf);
      (x[j]) ++;

      v[tmp___2] = i;

    } else {

    }
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "344", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "344", "0", checkpoints_buf);
    i ++;
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "349", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "350", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "350", "n", checkpoints_buf);
    if (i < n) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "350", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "350", "n", checkpoints_buf);
  }


  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "340", "n", checkpoints_buf);
  n = x[g];
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "353", "n", checkpoints_buf);
  i = 0U;
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "354", "i", checkpoints_buf);
  x[0] = i;

  p = v;

  h = -1;
  sprintf(checkpoints_buf, "%d", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "357", "h", checkpoints_buf);
  w = - l;
  sprintf(checkpoints_buf, "%d", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "358", "w", checkpoints_buf);
  u[0] = (struct huft *)((void *)0);

  q = (struct huft *)((void *)0);

  z = 0U;
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "361", "z", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", g);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "g", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", a);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "tmp___7", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", a);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "tmp___7", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", l);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "l", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "h", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", f);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "f", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", f);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "f", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", a);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", hufts);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "hufts", checkpoints_buf);





  sprintf(checkpoints_buf, "%d", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "h", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", f);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "f", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "h", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "363", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", g);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "363", "g", checkpoints_buf);
    if (k <= g) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "363", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", g);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "363", "g", checkpoints_buf);
    a = c[k];
    sprintf(checkpoints_buf, "%u", a);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "366", "a", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "tmp___7", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", a);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "a", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "tmp___7", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "w", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", l);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "l", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "h", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "w", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", f);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "f", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", f);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "f", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", a);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "a", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", hufts);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "hufts", checkpoints_buf);





    sprintf(checkpoints_buf, "%d", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "h", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", f);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "f", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "h", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "w", checkpoints_buf);
    while (1) {
      tmp___7 = a;
      sprintf(checkpoints_buf, "%u", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "368", "tmp___7", checkpoints_buf);
      a --;
      sprintf(checkpoints_buf, "%u", a);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "369", "a", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "370", "tmp___7", checkpoints_buf);
      if (tmp___7) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%u", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "370", "tmp___7", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", l);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "l", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", h);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "h", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "z", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "z", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", f);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "f", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", f);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "f", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", a);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "a", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "z", checkpoints_buf);



      sprintf(checkpoints_buf, "%u", hufts);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "hufts", checkpoints_buf);





      sprintf(checkpoints_buf, "%d", h);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "h", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%d", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "374", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "374", "w", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", l);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "374", "l", checkpoints_buf);
        if (k > w + l) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "374", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "374", "w", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", l);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "374", "l", checkpoints_buf);
        h ++;
        sprintf(checkpoints_buf, "%d", h);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "377", "h", checkpoints_buf);
        w += l;
        sprintf(checkpoints_buf, "%d", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "378", "w", checkpoints_buf);
        z = (unsigned int )(g - w);
        sprintf(checkpoints_buf, "%u", z);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "379", "z", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", z);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "380", "z", checkpoints_buf);
        if (z > (unsigned int )l) {
          z = (unsigned int )l;
          sprintf(checkpoints_buf, "%u", z);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "381", "z", checkpoints_buf);
        } else {
          z = z;
          sprintf(checkpoints_buf, "%u", z);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "382", "z", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", z);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "380", "z", checkpoints_buf);
        j = (unsigned int )(k - w);
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "383", "j", checkpoints_buf);
        f = (unsigned int )(1 << j);
        sprintf(checkpoints_buf, "%u", f);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "384", "f", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", f);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "385", "f", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", a);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "385", "a", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "385", "1", checkpoints_buf);
        if (f > a + 1U) {
          f -= a + 1U;
          sprintf(checkpoints_buf, "%u", f);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "386", "f", checkpoints_buf);
          xp = c + k;

          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "388", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", z);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "388", "z", checkpoints_buf);
          if (j < z) {
            sprintf(checkpoints_buf, "%u", j);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "j", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", j);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "j", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", z);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "z", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", f);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "f", checkpoints_buf);

            sprintf(checkpoints_buf, "%u", f);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "f", checkpoints_buf);

            sprintf(checkpoints_buf, "%u", f);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "f", checkpoints_buf);
            while (1) {
              j ++;
              sprintf(checkpoints_buf, "%u", j);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "390", "j", checkpoints_buf);
              sprintf(checkpoints_buf, "%u", j);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "391", "j", checkpoints_buf);
              sprintf(checkpoints_buf, "%u", z);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "391", "z", checkpoints_buf);
              if (j < z) {

              } else {
                break;
              }
              sprintf(checkpoints_buf, "%u", j);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "391", "j", checkpoints_buf);
              sprintf(checkpoints_buf, "%u", z);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "391", "z", checkpoints_buf);
              f <<= 1;
              sprintf(checkpoints_buf, "%u", f);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "394", "f", checkpoints_buf);
              xp ++;

              sprintf(checkpoints_buf, "%u", f);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "396", "f", checkpoints_buf);

              if (f <= *xp) {
                break;
              } else {

              }
              sprintf(checkpoints_buf, "%u", f);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "396", "f", checkpoints_buf);

              f -= *xp;
              sprintf(checkpoints_buf, "%u", f);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "399", "f", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", j);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "j", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", j);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "j", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", z);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "z", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", f);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "f", checkpoints_buf);

            sprintf(checkpoints_buf, "%u", f);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "f", checkpoints_buf);

            sprintf(checkpoints_buf, "%u", f);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "389", "f", checkpoints_buf);
          } else {

          }
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "388", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", z);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "388", "z", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%u", f);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "385", "f", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", a);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "385", "a", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "385", "1", checkpoints_buf);
        z = (unsigned int )(1 << j);
        sprintf(checkpoints_buf, "%u", z);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "402", "z", checkpoints_buf);


        tmp___4 = malloc((z + 1U) * sizeof(struct huft ));


        q = (struct huft *)tmp___4;

        if ((unsigned int )q == (unsigned int )((struct huft *)((void *)0))) {
          sprintf(checkpoints_buf, "%d", h);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "406", "h", checkpoints_buf);
          if (h) {

            huft_free(u[0]);

          } else {

          }
          sprintf(checkpoints_buf, "%d", h);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "406", "h", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "409", "3", checkpoints_buf);
          return (3);
        } else {

        }
        hufts += z + 1U;
        sprintf(checkpoints_buf, "%u", hufts);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "411", "hufts", checkpoints_buf);
        *t = q + 1;

        t = & q->v.t;

        *t = (struct huft *)((void *)0);

        q ++;

        u[h] = q;

        sprintf(checkpoints_buf, "%d", h);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "417", "h", checkpoints_buf);
        if (h) {
          x[h] = i;

          r.b = (uch )l;

          r.e = (uch )(16U + j);

          r.v.t = q;

          j = i >> (w - l);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "422", "j", checkpoints_buf);
          *(u[h - 1] + j) = r;

        } else {

        }
        sprintf(checkpoints_buf, "%d", h);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "417", "h", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", l);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "l", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", h);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "h", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "z", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "z", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", f);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "f", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", f);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "f", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", a);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "a", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "z", checkpoints_buf);



      sprintf(checkpoints_buf, "%u", hufts);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "hufts", checkpoints_buf);





      sprintf(checkpoints_buf, "%d", h);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "373", "h", checkpoints_buf);
      r.b = (uch )(k - w);

      if ((unsigned int )p >= (unsigned int )(v + n)) {
        r.e = (uch )99;

      } else {

        sprintf(checkpoints_buf, "%u", s);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "428", "s", checkpoints_buf);
        if (*p < s) {

          sprintf(checkpoints_buf, "%u", 256);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "429", "256", checkpoints_buf);
          if (*p < 256U) {
            tmp___5 = 16;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "430", "tmp___5", checkpoints_buf);
          } else {
            tmp___5 = 15;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "431", "tmp___5", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 256);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "429", "256", checkpoints_buf);
          r.e = (uch )tmp___5;

          r.v.n = (ush )*p;

          p ++;

        } else {
          r.e = (uch )*(e + (*p - s));

          tmp___6 = p;

          p ++;

          r.v.n = *(d + (*tmp___6 - s));

        }

        sprintf(checkpoints_buf, "%u", s);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "428", "s", checkpoints_buf);
      }
      f = (unsigned int )(1 << (k - w));
      sprintf(checkpoints_buf, "%u", f);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "439", "f", checkpoints_buf);
      j = i >> w;
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "440", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "441", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "441", "z", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "441", "j", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "442", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", z);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "442", "z", checkpoints_buf);
        if (j < z) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "442", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", z);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "442", "z", checkpoints_buf);
        *(q + j) = r;

        j += f;
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "446", "j", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "441", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", z);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "441", "z", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "441", "j", checkpoints_buf);
      j = (unsigned int )(1 << (k - 1));
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "447", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "i", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "i", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "j", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%u", i);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "449", "i", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "449", "j", checkpoints_buf);
        if (i & j) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", i);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "449", "i", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "449", "j", checkpoints_buf);
        i ^= j;
        sprintf(checkpoints_buf, "%u", i);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "452", "i", checkpoints_buf);
        j >>= 1;
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "453", "j", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "i", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "i", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "448", "j", checkpoints_buf);
      i ^= j;
      sprintf(checkpoints_buf, "%u", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "454", "i", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "455", "i", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", h);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "455", "h", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "455", "w", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%u", i);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "456", "i", checkpoints_buf);

        if ((i & (unsigned int )((1 << w) - 1)) != x[h]) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", i);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "456", "i", checkpoints_buf);

        h --;
        sprintf(checkpoints_buf, "%d", h);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "459", "h", checkpoints_buf);
        w -= l;
        sprintf(checkpoints_buf, "%d", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "460", "w", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "455", "i", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", h);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "455", "h", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "455", "w", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "tmp___7", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", a);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "a", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "tmp___7", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "w", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", l);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "l", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "h", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "w", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", f);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "f", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", f);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "f", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", a);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "a", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", hufts);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "hufts", checkpoints_buf);





    sprintf(checkpoints_buf, "%d", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "h", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", f);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "f", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", z);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "z", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "i", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "h", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "367", "w", checkpoints_buf);
    k ++;
    sprintf(checkpoints_buf, "%d", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "461", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", g);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "g", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", a);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "tmp___7", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", a);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "tmp___7", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", l);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "l", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "h", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", f);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "f", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", f);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "f", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", a);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "a", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", hufts);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "hufts", checkpoints_buf);





  sprintf(checkpoints_buf, "%d", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "h", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", f);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "f", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", z);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "z", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "h", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "362", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "462", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "462", "0", checkpoints_buf);
  if (y != 0) {
    sprintf(checkpoints_buf, "%d", g);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "463", "g", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "463", "1", checkpoints_buf);
    if (g != 1) {
      tmp___8 = 1;
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "464", "tmp___8", checkpoints_buf);
    } else {
      {
      tmp___8 = 0;
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "465", "tmp___8", checkpoints_buf);
      inptr ++;
      }
    }
    sprintf(checkpoints_buf, "%d", g);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "463", "g", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "463", "1", checkpoints_buf);
  } else {
    tmp___8 = 0;
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "466", "tmp___8", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", y);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "462", "y", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "462", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "467", "tmp___8", checkpoints_buf);
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




  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "477", "0", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "479", "k", checkpoints_buf);
  w = outcnt;
  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "480", "w", checkpoints_buf);
  ml = (unsigned int )mask_bits[bl];
  sprintf(checkpoints_buf, "%u", ml);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "481", "ml", checkpoints_buf);
  md = (unsigned int )mask_bits[bd];
  sprintf(checkpoints_buf, "%u", md);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "482", "md", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "k", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "16", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "16", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "k", checkpoints_buf);
    while (1) {
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "485", "k", checkpoints_buf);
      if (k < (unsigned int )bl) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "485", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "488", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "488", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp = inptr;
        sprintf(checkpoints_buf, "%u", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "489", "tmp", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "490", "inptr", checkpoints_buf);
        tmp___1 = (int )inbuf[tmp];
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "491", "tmp___1", checkpoints_buf);
      } else {
        outcnt = w;
        sprintf(checkpoints_buf, "%u", outcnt);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "492", "outcnt", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "493", "tmp___0", checkpoints_buf);

        tmp___0 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "493", "tmp___0", checkpoints_buf);

        tmp___1 = tmp___0;
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "494", "tmp___1", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "488", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "488", "insize", checkpoints_buf);
      b |= (ulg )((uch )tmp___1) << k;

      k += 8U;
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "496", "k", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "484", "k", checkpoints_buf);
    t = tl + ((unsigned int )b & ml);

    e = (unsigned int )t->e;
    sprintf(checkpoints_buf, "%u", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "498", "e", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "499", "e", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "499", "16", checkpoints_buf);
    if (e > 16U) {
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 99);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "99", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "k", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "16", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "501", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 99);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "501", "99", checkpoints_buf);
        if (e == 99U) {
          sprintf(checkpoints_buf, "%d", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "502", "1", checkpoints_buf);
          return (1);
        } else {

        }
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "501", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 99);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "501", "99", checkpoints_buf);
        b >>= (int )t->b;

        k -= (unsigned int )t->b;
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "505", "k", checkpoints_buf);
        e -= 16U;
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "506", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "insize", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "k", checkpoints_buf);
        while (1) {
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "508", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "508", "e", checkpoints_buf);
          if (k < e) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "508", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "508", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "511", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "511", "insize", checkpoints_buf);
          if (inptr < insize) {
            tmp___2 = inptr;
            sprintf(checkpoints_buf, "%u", tmp___2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "512", "tmp___2", checkpoints_buf);
            inptr ++;
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "513", "inptr", checkpoints_buf);
            tmp___4 = (int )inbuf[tmp___2];
            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "514", "tmp___4", checkpoints_buf);
          } else {
            outcnt = w;
            sprintf(checkpoints_buf, "%u", outcnt);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "515", "outcnt", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "516", "tmp___3", checkpoints_buf);

            tmp___3 = fill_inbuf(0);
            sprintf(checkpoints_buf, "%d", tmp___3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "516", "tmp___3", checkpoints_buf);

            tmp___4 = tmp___3;
            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "517", "tmp___4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "511", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "511", "insize", checkpoints_buf);
          b |= (ulg )((uch )tmp___4) << k;

          k += 8U;
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "519", "k", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "insize", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "507", "k", checkpoints_buf);
        t = t->v.t + ((unsigned int )b & (unsigned int )mask_bits[e]);

        e = (unsigned int )t->e;
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "521", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "522", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "522", "16", checkpoints_buf);
        if (e > 16U) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "522", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "522", "16", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 99);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "99", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "k", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "500", "16", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "499", "e", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "499", "16", checkpoints_buf);
    b >>= (int )t->b;

    {
    k -= (unsigned int )t->b;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "527", "k", checkpoints_buf);
    d ++;
    }
    sprintf(checkpoints_buf, "%u", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "528", "e", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "528", "16", checkpoints_buf);
    if (e == 16U) {
      tmp___5 = w;
      sprintf(checkpoints_buf, "%u", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "529", "tmp___5", checkpoints_buf);
      w ++;
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "530", "w", checkpoints_buf);
      window[tmp___5] = (uch )t->v.n;

      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "532", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 32768);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "532", "32768", checkpoints_buf);
      if (w == 32768U) {
        outcnt = w;
        sprintf(checkpoints_buf, "%u", outcnt);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "533", "outcnt", checkpoints_buf);

        flush_window();

        w = 0U;
        sprintf(checkpoints_buf, "%u", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "535", "w", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "532", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 32768);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "532", "32768", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "537", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 15);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "537", "15", checkpoints_buf);
      if (e == 15U) {
        break;
      } else {

      }
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "537", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 15);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "537", "15", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "k", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "541", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "541", "e", checkpoints_buf);
        if (k < e) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "541", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "541", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "544", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "544", "insize", checkpoints_buf);
        if (inptr < insize) {
          tmp___6 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___6);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "545", "tmp___6", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "546", "inptr", checkpoints_buf);
          tmp___8 = (int )inbuf[tmp___6];
          sprintf(checkpoints_buf, "%d", tmp___8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "547", "tmp___8", checkpoints_buf);
        } else {
          outcnt = w;
          sprintf(checkpoints_buf, "%u", outcnt);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "548", "outcnt", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "549", "tmp___7", checkpoints_buf);

          tmp___7 = fill_inbuf(0);
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "549", "tmp___7", checkpoints_buf);

          tmp___8 = tmp___7;
          sprintf(checkpoints_buf, "%d", tmp___8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "550", "tmp___8", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "544", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "544", "insize", checkpoints_buf);
        b |= (ulg )((uch )tmp___8) << k;

        k += 8U;
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "552", "k", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "540", "k", checkpoints_buf);
      n = (unsigned int )t->v.n + ((unsigned int )b & (unsigned int )mask_bits[e]);
      sprintf(checkpoints_buf, "%u", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "553", "n", checkpoints_buf);
      b >>= e;

      k -= e;
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "555", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "k", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "557", "k", checkpoints_buf);
        if (k < (unsigned int )bd) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "557", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "560", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "560", "insize", checkpoints_buf);
        if (inptr < insize) {
          tmp___9 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "561", "tmp___9", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "562", "inptr", checkpoints_buf);
          tmp___11 = (int )inbuf[tmp___9];
          sprintf(checkpoints_buf, "%d", tmp___11);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "563", "tmp___11", checkpoints_buf);
        } else {
          outcnt = w;
          sprintf(checkpoints_buf, "%u", outcnt);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "564", "outcnt", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___10);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "565", "tmp___10", checkpoints_buf);

          tmp___10 = fill_inbuf(0);
          sprintf(checkpoints_buf, "%d", tmp___10);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "565", "tmp___10", checkpoints_buf);

          tmp___11 = tmp___10;
          sprintf(checkpoints_buf, "%d", tmp___11);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "566", "tmp___11", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "560", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "560", "insize", checkpoints_buf);
        b |= (ulg )((uch )tmp___11) << k;

        k += 8U;
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "568", "k", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "556", "k", checkpoints_buf);
      t = td + ((unsigned int )b & md);

      e = (unsigned int )t->e;
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "570", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "571", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "571", "16", checkpoints_buf);
      if (e > 16U) {
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 99);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "99", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "insize", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "k", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "16", checkpoints_buf);
        while (1) {
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "573", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 99);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "573", "99", checkpoints_buf);
          if (e == 99U) {
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "574", "1", checkpoints_buf);
            return (1);
          } else {

          }
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "573", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 99);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "573", "99", checkpoints_buf);
          b >>= (int )t->b;

          k -= (unsigned int )t->b;
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "577", "k", checkpoints_buf);
          e -= 16U;
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "578", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "insize", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "k", checkpoints_buf);
          while (1) {
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "580", "k", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", e);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "580", "e", checkpoints_buf);
            if (k < e) {

            } else {
              break;
            }
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "580", "k", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", e);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "580", "e", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "583", "inptr", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", insize);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "583", "insize", checkpoints_buf);
            if (inptr < insize) {
              tmp___12 = inptr;
              sprintf(checkpoints_buf, "%u", tmp___12);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "584", "tmp___12", checkpoints_buf);
              inptr ++;
              sprintf(checkpoints_buf, "%u", inptr);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "585", "inptr", checkpoints_buf);
              tmp___14 = (int )inbuf[tmp___12];
              sprintf(checkpoints_buf, "%d", tmp___14);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "586", "tmp___14", checkpoints_buf);
            } else {
              outcnt = w;
              sprintf(checkpoints_buf, "%u", outcnt);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "587", "outcnt", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___13);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "588", "tmp___13", checkpoints_buf);

              tmp___13 = fill_inbuf(0);
              sprintf(checkpoints_buf, "%d", tmp___13);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "588", "tmp___13", checkpoints_buf);

              tmp___14 = tmp___13;
              sprintf(checkpoints_buf, "%d", tmp___14);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "589", "tmp___14", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "583", "inptr", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", insize);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "583", "insize", checkpoints_buf);
            b |= (ulg )((uch )tmp___14) << k;

            k += 8U;
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "591", "k", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "insize", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "579", "k", checkpoints_buf);
          t = t->v.t + ((unsigned int )b & (unsigned int )mask_bits[e]);

          e = (unsigned int )t->e;
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "593", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "594", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 16);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "594", "16", checkpoints_buf);
          if (e > 16U) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "594", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 16);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "594", "16", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 99);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "99", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "insize", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "k", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "572", "16", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "571", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "571", "16", checkpoints_buf);
      b >>= (int )t->b;

      k -= (unsigned int )t->b;
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "599", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "k", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "601", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "601", "e", checkpoints_buf);
        if (k < e) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "601", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "601", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "604", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "604", "insize", checkpoints_buf);
        if (inptr < insize) {
          tmp___15 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___15);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "605", "tmp___15", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "606", "inptr", checkpoints_buf);
          tmp___17 = (int )inbuf[tmp___15];
          sprintf(checkpoints_buf, "%d", tmp___17);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "607", "tmp___17", checkpoints_buf);
        } else {
          outcnt = w;
          sprintf(checkpoints_buf, "%u", outcnt);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "608", "outcnt", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___16);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "609", "tmp___16", checkpoints_buf);

          tmp___16 = fill_inbuf(0);
          sprintf(checkpoints_buf, "%d", tmp___16);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "609", "tmp___16", checkpoints_buf);

          tmp___17 = tmp___16;
          sprintf(checkpoints_buf, "%d", tmp___17);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "610", "tmp___17", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "604", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "604", "insize", checkpoints_buf);
        b |= (ulg )((uch )tmp___17) << k;

        k += 8U;
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "612", "k", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "insize", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "600", "k", checkpoints_buf);
      d = (w - (unsigned int )t->v.n) - ((unsigned int )b & (unsigned int )mask_bits[e]);
      sprintf(checkpoints_buf, "%u", d);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "613", "d", checkpoints_buf);
      b >>= e;

      k -= e;
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "615", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", d);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "d", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", d);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "d", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", d);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "d", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 32768);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "32768", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "n", checkpoints_buf);
      while (1) {
        d &= 32767U;
        sprintf(checkpoints_buf, "%u", d);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "617", "d", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", d);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "618", "d", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "618", "w", checkpoints_buf);
        if (d > w) {
          tmp___19 = d;
          sprintf(checkpoints_buf, "%u", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "619", "tmp___19", checkpoints_buf);
        } else {
          tmp___19 = w;
          sprintf(checkpoints_buf, "%u", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "620", "tmp___19", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", d);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "618", "d", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "618", "w", checkpoints_buf);
        e = 32768U - tmp___19;
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "621", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "622", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "622", "n", checkpoints_buf);
        if (e > n) {
          e = n;
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "623", "e", checkpoints_buf);
        } else {
          e = e;
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "624", "e", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "622", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "622", "n", checkpoints_buf);
        n -= e;
        sprintf(checkpoints_buf, "%u", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "625", "n", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "626", "w", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", d);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "626", "d", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "626", "e", checkpoints_buf);
        if (w - d >= e) {

          memcpy((void */* __restrict  */)(window + w),
                 (void const   */* __restrict  */)(window + d), e);

          w += e;
          sprintf(checkpoints_buf, "%u", w);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "628", "w", checkpoints_buf);
          d += e;
          sprintf(checkpoints_buf, "%u", d);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "629", "d", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%u", tmp___20);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "tmp___20", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", w);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "w", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___21);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "tmp___21", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", d);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "d", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "e", checkpoints_buf);
          while (1) {
            tmp___20 = w;
            sprintf(checkpoints_buf, "%u", tmp___20);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "631", "tmp___20", checkpoints_buf);
            w ++;
            sprintf(checkpoints_buf, "%u", w);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "632", "w", checkpoints_buf);
            tmp___21 = d;
            sprintf(checkpoints_buf, "%u", tmp___21);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "633", "tmp___21", checkpoints_buf);
            d ++;
            sprintf(checkpoints_buf, "%u", d);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "634", "d", checkpoints_buf);
            window[tmp___20] = window[tmp___21];

            e --;
            sprintf(checkpoints_buf, "%u", e);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "636", "e", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", e);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "637", "e", checkpoints_buf);
            if (e) {

            } else {
              break;
            }
            sprintf(checkpoints_buf, "%u", e);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "637", "e", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", tmp___20);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "tmp___20", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", w);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "w", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___21);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "tmp___21", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", d);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "d", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "e", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", e);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "630", "e", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "626", "w", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", d);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "626", "d", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", e);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "626", "e", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "640", "w", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 32768);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "640", "32768", checkpoints_buf);
        if (w == 32768U) {
          outcnt = w;
          sprintf(checkpoints_buf, "%u", outcnt);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "641", "outcnt", checkpoints_buf);

          flush_window();

          w = 0U;
          sprintf(checkpoints_buf, "%u", w);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "643", "w", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%u", w);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "640", "w", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 32768);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "640", "32768", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "645", "n", checkpoints_buf);
        if (n) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%u", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "645", "n", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", d);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "d", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", d);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "d", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", d);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "d", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "e", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "w", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 32768);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "32768", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "616", "n", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "528", "e", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "528", "16", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "k", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "16", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "483", "16", checkpoints_buf);
  outcnt = w;
  sprintf(checkpoints_buf, "%u", outcnt);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "648", "outcnt", checkpoints_buf);
  bb = b;

  bk = k;
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "650", "bk", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "651", "0", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "653", "k", checkpoints_buf);
  w = outcnt;
  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "654", "w", checkpoints_buf);
  n = k & 7U;
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "655", "n", checkpoints_buf);
  b >>= n;

  k -= n;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "657", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "16", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "659", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "659", "16", checkpoints_buf);
    if (k < 16U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "659", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "659", "16", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "662", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "662", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp = inptr;
      sprintf(checkpoints_buf, "%u", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "663", "tmp", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "664", "inptr", checkpoints_buf);
      tmp___1 = (int )inbuf[tmp];
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "665", "tmp___1", checkpoints_buf);
    } else {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "666", "outcnt", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "667", "tmp___0", checkpoints_buf);

      tmp___0 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "667", "tmp___0", checkpoints_buf);

      tmp___1 = tmp___0;
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "668", "tmp___1", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "662", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "662", "insize", checkpoints_buf);
    b |= (ulg )((uch )tmp___1) << k;

    k += 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "670", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "16", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "658", "k", checkpoints_buf);
  n = (unsigned int )b & 65535U;
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "671", "n", checkpoints_buf);
  b >>= 16;

  k -= 16U;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "673", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "16", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "675", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "675", "16", checkpoints_buf);
    if (k < 16U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "675", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "675", "16", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "678", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "678", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp___2 = inptr;
      sprintf(checkpoints_buf, "%u", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "679", "tmp___2", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "680", "inptr", checkpoints_buf);
      tmp___4 = (int )inbuf[tmp___2];
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "681", "tmp___4", checkpoints_buf);
    } else {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "682", "outcnt", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "683", "tmp___3", checkpoints_buf);

      tmp___3 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "683", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "684", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "678", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "678", "insize", checkpoints_buf);
    b |= (ulg )((uch )tmp___4) << k;

    k += 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "686", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "16", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "674", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "687", "n", checkpoints_buf);
  if (n != (unsigned int )(~ b & 65535UL)) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "688", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "687", "n", checkpoints_buf);
  b >>= 16;

  k -= 16U;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "691", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "tmp___9", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "tmp___9", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "w", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "32768", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "k", checkpoints_buf);
  while (1) {
    tmp___9 = n;
    sprintf(checkpoints_buf, "%u", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "693", "tmp___9", checkpoints_buf);
    n --;
    sprintf(checkpoints_buf, "%u", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "694", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "695", "tmp___9", checkpoints_buf);
    if (tmp___9) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "695", "tmp___9", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "8", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "k", checkpoints_buf);
    while (1) {
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "699", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "699", "8", checkpoints_buf);
      if (k < 8U) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "699", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "699", "8", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "702", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "702", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___5 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "703", "tmp___5", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "704", "inptr", checkpoints_buf);
        tmp___7 = (int )inbuf[tmp___5];
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "705", "tmp___7", checkpoints_buf);
      } else {
        outcnt = w;
        sprintf(checkpoints_buf, "%u", outcnt);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "706", "outcnt", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "707", "tmp___6", checkpoints_buf);

        tmp___6 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "707", "tmp___6", checkpoints_buf);

        tmp___7 = tmp___6;
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "708", "tmp___7", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "702", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "702", "insize", checkpoints_buf);
      b |= (ulg )((uch )tmp___7) << k;

      k += 8U;
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "710", "k", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "8", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "698", "k", checkpoints_buf);
    tmp___8 = w;
    sprintf(checkpoints_buf, "%u", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "711", "tmp___8", checkpoints_buf);
    w ++;
    sprintf(checkpoints_buf, "%u", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "712", "w", checkpoints_buf);
    window[tmp___8] = (uch )b;

    sprintf(checkpoints_buf, "%u", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "714", "w", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 32768);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "714", "32768", checkpoints_buf);
    if (w == 32768U) {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "715", "outcnt", checkpoints_buf);

      flush_window();

      w = 0U;
      sprintf(checkpoints_buf, "%u", w);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "717", "w", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", w);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "714", "w", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 32768);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "714", "32768", checkpoints_buf);
    b >>= 8;

    k -= 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "720", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "tmp___9", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "tmp___9", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "w", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "32768", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "692", "k", checkpoints_buf);
  outcnt = w;
  sprintf(checkpoints_buf, "%u", outcnt);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "721", "outcnt", checkpoints_buf);
  bb = b;

  bk = k;
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "723", "bk", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "724", "0", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "725", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "726", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 144);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "726", "144", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "726", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "727", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 144);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "727", "144", checkpoints_buf);
    if (i < 144) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "727", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 144);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "727", "144", checkpoints_buf);
    l[i] = 8U;

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "731", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "726", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 144);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "726", "144", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "726", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "732", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "732", "256", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "732", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "733", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "733", "256", checkpoints_buf);
    if (i < 256) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "733", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "733", "256", checkpoints_buf);
    l[i] = 9U;

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "737", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "732", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 256);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "732", "256", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "732", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "738", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 280);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "738", "280", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "738", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "739", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 280);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "739", "280", checkpoints_buf);
    if (i < 280) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "739", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 280);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "739", "280", checkpoints_buf);
    l[i] = 7U;

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "743", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "738", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 280);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "738", "280", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "738", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "744", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "744", "288", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "744", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "745", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "745", "288", checkpoints_buf);
    if (i < 288) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "745", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "745", "288", checkpoints_buf);
    l[i] = 8U;

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "749", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "744", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "744", "288", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "744", "i", checkpoints_buf);
  bl = 7;
  sprintf(checkpoints_buf, "%d", bl);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "750", "bl", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "751", "i", checkpoints_buf);

  i = huft_build(l, 288U, 257U, cplens, cplext, & tl, & bl);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "751", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "752", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "752", "0", checkpoints_buf);
  if (i != 0) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "753", "i", checkpoints_buf);
    return (i);
  } else {

  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "752", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "752", "0", checkpoints_buf);
  i = 0;
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "755", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "756", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 30);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "756", "30", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "756", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "757", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "757", "30", checkpoints_buf);
    if (i < 30) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "757", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "757", "30", checkpoints_buf);
    l[i] = 5U;

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "761", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "756", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 30);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "756", "30", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "756", "i", checkpoints_buf);
  bd = 5;
  sprintf(checkpoints_buf, "%d", bd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "762", "bd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "763", "i", checkpoints_buf);

  i = huft_build(l, 30U, 0U, cpdist, cpdext, & td, & bd);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "763", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "764", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "764", "1", checkpoints_buf);
  if (i > 1) {

    huft_free(tl);

    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "766", "i", checkpoints_buf);
    return (i);
  } else {

  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "764", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "764", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "768", "tmp", checkpoints_buf);

  tmp = inflate_codes(tl, td, bl, bd);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "768", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "769", "tmp", checkpoints_buf);
  if (tmp) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "770", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "769", "tmp", checkpoints_buf);

  huft_free(tl);


  huft_free(td);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "774", "0", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "776", "k", checkpoints_buf);
  w = outcnt;
  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "777", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "5", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "779", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "779", "5", checkpoints_buf);
    if (k < 5U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "779", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "779", "5", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "782", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "782", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp = inptr;
      sprintf(checkpoints_buf, "%u", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "783", "tmp", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "784", "inptr", checkpoints_buf);
      tmp___1 = (int )inbuf[tmp];
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "785", "tmp___1", checkpoints_buf);
    } else {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "786", "outcnt", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "787", "tmp___0", checkpoints_buf);

      tmp___0 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "787", "tmp___0", checkpoints_buf);

      tmp___1 = tmp___0;
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "788", "tmp___1", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "782", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "782", "insize", checkpoints_buf);
    b |= (ulg )((uch )tmp___1) << k;

    k += 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "790", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "5", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "778", "k", checkpoints_buf);
  nl = 257U + ((unsigned int )b & 31U);
  sprintf(checkpoints_buf, "%u", nl);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "791", "nl", checkpoints_buf);
  b >>= 5;

  k -= 5U;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "793", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "5", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "795", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "795", "5", checkpoints_buf);
    if (k < 5U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "795", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "795", "5", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "798", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "798", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp___2 = inptr;
      sprintf(checkpoints_buf, "%u", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "799", "tmp___2", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "800", "inptr", checkpoints_buf);
      tmp___4 = (int )inbuf[tmp___2];
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "801", "tmp___4", checkpoints_buf);
    } else {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "802", "outcnt", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "803", "tmp___3", checkpoints_buf);

      tmp___3 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "803", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "804", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "798", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "798", "insize", checkpoints_buf);
    b |= (ulg )((uch )tmp___4) << k;

    k += 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "806", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "5", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "794", "k", checkpoints_buf);
  nd = 1U + ((unsigned int )b & 31U);
  sprintf(checkpoints_buf, "%u", nd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "807", "nd", checkpoints_buf);
  b >>= 5;

  k -= 5U;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "809", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "4", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "811", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "811", "4", checkpoints_buf);
    if (k < 4U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "811", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "811", "4", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "814", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "814", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp___5 = inptr;
      sprintf(checkpoints_buf, "%u", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "815", "tmp___5", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "816", "inptr", checkpoints_buf);
      tmp___7 = (int )inbuf[tmp___5];
      sprintf(checkpoints_buf, "%d", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "817", "tmp___7", checkpoints_buf);
    } else {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "818", "outcnt", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "819", "tmp___6", checkpoints_buf);

      tmp___6 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "819", "tmp___6", checkpoints_buf);

      tmp___7 = tmp___6;
      sprintf(checkpoints_buf, "%d", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "820", "tmp___7", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "814", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "814", "insize", checkpoints_buf);
    b |= (ulg )((uch )tmp___7) << k;

    k += 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "822", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "4", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "810", "k", checkpoints_buf);
  nb = 4U + ((unsigned int )b & 15U);
  sprintf(checkpoints_buf, "%u", nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "823", "nb", checkpoints_buf);
  b >>= 4;

  k -= 4U;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "825", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", nl);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "826", "nl", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 286);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "826", "286", checkpoints_buf);
  if (nl > 286U) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "827", "1", checkpoints_buf);
    return (1);
  } else {
    sprintf(checkpoints_buf, "%u", nd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "828", "nd", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "828", "30", checkpoints_buf);
    if (nd > 30U) {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "829", "1", checkpoints_buf);
      return (1);
    } else {

    }
    sprintf(checkpoints_buf, "%u", nd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "828", "nd", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "828", "30", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", nl);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "826", "nl", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 286);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "826", "286", checkpoints_buf);
  j = 0U;
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "831", "j", checkpoints_buf);
  {
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "nb", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "k", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "j", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "833", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", nb);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "833", "nb", checkpoints_buf);
    if (j < nb) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "833", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", nb);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "833", "nb", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "3", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "k", checkpoints_buf);
    while (1) {
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "837", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "837", "3", checkpoints_buf);
      if (k < 3U) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "837", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "837", "3", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "840", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "840", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___8 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "841", "tmp___8", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "842", "inptr", checkpoints_buf);
        tmp___10 = (int )inbuf[tmp___8];
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "843", "tmp___10", checkpoints_buf);
      } else {
        outcnt = w;
        sprintf(checkpoints_buf, "%u", outcnt);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "844", "outcnt", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___9);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "845", "tmp___9", checkpoints_buf);

        tmp___9 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___9);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "845", "tmp___9", checkpoints_buf);

        tmp___10 = tmp___9;
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "846", "tmp___10", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "840", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "840", "insize", checkpoints_buf);
      b |= (ulg )((uch )tmp___10) << k;

      k += 8U;
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "848", "k", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "3", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "836", "k", checkpoints_buf);
    ll[border[j]] = (unsigned int )b & 7U;

    b >>= 3;

    k -= 3U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "851", "k", checkpoints_buf);
    j ++;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "852", "j", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "nb", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "k", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "832", "j", checkpoints_buf);

  }
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "853", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "853", "19", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "853", "j", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "854", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "854", "19", checkpoints_buf);
    if (j < 19U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "854", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "854", "19", checkpoints_buf);
    ll[border[j]] = 0U;

    j ++;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "858", "j", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "853", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "853", "19", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "853", "j", checkpoints_buf);
  bl = 7;
  sprintf(checkpoints_buf, "%d", bl);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "859", "bl", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "860", "i", checkpoints_buf);

  i = huft_build(ll, 19U, 19U, (ush *)((void *)0), (ush *)((void *)0), & tl,
                 & bl);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "860", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "861", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "861", "0", checkpoints_buf);
  if (i != 0) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "862", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "862", "1", checkpoints_buf);
    if (i == 1) {

      huft_free(tl);

    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "862", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "862", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "865", "i", checkpoints_buf);
    return (i);
  } else {

  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "861", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "861", "0", checkpoints_buf);
  if ((unsigned int )tl == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "868", "2", checkpoints_buf);
    return (2);
  } else {

  }
  n = nl + nd;
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "870", "n", checkpoints_buf);
  m = (unsigned int )mask_bits[bl];
  sprintf(checkpoints_buf, "%u", m);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "871", "m", checkpoints_buf);
  l = 0U;
  sprintf(checkpoints_buf, "%u", l);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "872", "l", checkpoints_buf);
  i = (int )l;
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "873", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "k", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "j", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "16", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "875", "n", checkpoints_buf);
    if ((unsigned int )i < n) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "875", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "k", checkpoints_buf);
    while (1) {
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "879", "k", checkpoints_buf);
      if (k < (unsigned int )bl) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "879", "k", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "882", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "882", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___11 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "883", "tmp___11", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "884", "inptr", checkpoints_buf);
        tmp___13 = (int )inbuf[tmp___11];
        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "885", "tmp___13", checkpoints_buf);
      } else {
        outcnt = w;
        sprintf(checkpoints_buf, "%u", outcnt);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "886", "outcnt", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "887", "tmp___12", checkpoints_buf);

        tmp___12 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "887", "tmp___12", checkpoints_buf);

        tmp___13 = tmp___12;
        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "888", "tmp___13", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "882", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "882", "insize", checkpoints_buf);
      b |= (ulg )((uch )tmp___13) << k;

      k += 8U;
      sprintf(checkpoints_buf, "%u", k);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "890", "k", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "insize", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "878", "k", checkpoints_buf);
    td = tl + ((unsigned int )b & m);

    j = (unsigned int )td->b;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "892", "j", checkpoints_buf);
    b >>= j;

    k -= j;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "894", "k", checkpoints_buf);
    j = (unsigned int )td->v.n;
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "895", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "896", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "896", "16", checkpoints_buf);
    if (j < 16U) {
      tmp___14 = i;
      sprintf(checkpoints_buf, "%d", tmp___14);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "897", "tmp___14", checkpoints_buf);
      i ++;
      sprintf(checkpoints_buf, "%d", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "898", "i", checkpoints_buf);
      l = j;
      sprintf(checkpoints_buf, "%u", l);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "899", "l", checkpoints_buf);
      ll[tmp___14] = l;

    } else {
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "901", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "901", "16", checkpoints_buf);
      if (j == 16U) {
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "2", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "insize", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "k", checkpoints_buf);
        while (1) {
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "903", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "903", "2", checkpoints_buf);
          if (k < 2U) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "903", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "903", "2", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "906", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "906", "insize", checkpoints_buf);
          if (inptr < insize) {
            tmp___15 = inptr;
            sprintf(checkpoints_buf, "%u", tmp___15);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "907", "tmp___15", checkpoints_buf);
            inptr ++;
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "908", "inptr", checkpoints_buf);
            tmp___17 = (int )inbuf[tmp___15];
            sprintf(checkpoints_buf, "%d", tmp___17);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "909", "tmp___17", checkpoints_buf);
          } else {
            outcnt = w;
            sprintf(checkpoints_buf, "%u", outcnt);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "910", "outcnt", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___16);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "911", "tmp___16", checkpoints_buf);

            tmp___16 = fill_inbuf(0);
            sprintf(checkpoints_buf, "%d", tmp___16);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "911", "tmp___16", checkpoints_buf);

            tmp___17 = tmp___16;
            sprintf(checkpoints_buf, "%d", tmp___17);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "912", "tmp___17", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "906", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "906", "insize", checkpoints_buf);
          b |= (ulg )((uch )tmp___17) << k;

          k += 8U;
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "914", "k", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "2", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "insize", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "902", "k", checkpoints_buf);
        j = 3U + ((unsigned int )b & 3U);
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "915", "j", checkpoints_buf);
        b >>= 2;

        k -= 2U;
        sprintf(checkpoints_buf, "%u", k);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "917", "k", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "918", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "918", "n", checkpoints_buf);
        if ((unsigned int )i + j > n) {
          sprintf(checkpoints_buf, "%d", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "919", "1", checkpoints_buf);
          return (1);
        } else {

        }
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "918", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "918", "n", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "tmp___19", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "tmp___19", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "tmp___18", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", i);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "i", checkpoints_buf);

        while (1) {
          tmp___19 = j;
          sprintf(checkpoints_buf, "%u", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "922", "tmp___19", checkpoints_buf);
          j --;
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "923", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "924", "tmp___19", checkpoints_buf);
          if (tmp___19) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%u", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "924", "tmp___19", checkpoints_buf);
          tmp___18 = i;
          sprintf(checkpoints_buf, "%d", tmp___18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "927", "tmp___18", checkpoints_buf);
          i ++;
          sprintf(checkpoints_buf, "%d", i);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "928", "i", checkpoints_buf);
          ll[tmp___18] = l;

        }
        sprintf(checkpoints_buf, "%u", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "tmp___19", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "tmp___19", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "tmp___18", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", i);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "921", "i", checkpoints_buf);

      } else {
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "930", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "930", "17", checkpoints_buf);
        if (j == 17U) {
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "3", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "insize", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "k", checkpoints_buf);
          while (1) {
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "932", "k", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", 3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "932", "3", checkpoints_buf);
            if (k < 3U) {

            } else {
              break;
            }
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "932", "k", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", 3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "932", "3", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "935", "inptr", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", insize);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "935", "insize", checkpoints_buf);
            if (inptr < insize) {
              tmp___20 = inptr;
              sprintf(checkpoints_buf, "%u", tmp___20);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "936", "tmp___20", checkpoints_buf);
              inptr ++;
              sprintf(checkpoints_buf, "%u", inptr);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "937", "inptr", checkpoints_buf);
              tmp___22 = (int )inbuf[tmp___20];
              sprintf(checkpoints_buf, "%d", tmp___22);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "938", "tmp___22", checkpoints_buf);
            } else {
              outcnt = w;
              sprintf(checkpoints_buf, "%u", outcnt);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "939", "outcnt", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___21);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "940", "tmp___21", checkpoints_buf);

              tmp___21 = fill_inbuf(0);
              sprintf(checkpoints_buf, "%d", tmp___21);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "940", "tmp___21", checkpoints_buf);

              tmp___22 = tmp___21;
              sprintf(checkpoints_buf, "%d", tmp___22);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "941", "tmp___22", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "935", "inptr", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", insize);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "935", "insize", checkpoints_buf);
            b |= (ulg )((uch )tmp___22) << k;

            k += 8U;
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "943", "k", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "3", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "insize", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "931", "k", checkpoints_buf);
          j = 3U + ((unsigned int )b & 7U);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "944", "j", checkpoints_buf);
          b >>= 3;

          k -= 3U;
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "946", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "947", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", n);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "947", "n", checkpoints_buf);
          if ((unsigned int )i + j > n) {
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "948", "1", checkpoints_buf);
            return (1);
          } else {

          }
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "947", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", n);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "947", "n", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "tmp___24", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "tmp___24", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "tmp___23", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", i);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "i", checkpoints_buf);

          while (1) {
            tmp___24 = j;
            sprintf(checkpoints_buf, "%u", tmp___24);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "951", "tmp___24", checkpoints_buf);
            j --;
            sprintf(checkpoints_buf, "%u", j);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "952", "j", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", tmp___24);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "953", "tmp___24", checkpoints_buf);
            if (tmp___24) {

            } else {
              break;
            }
            sprintf(checkpoints_buf, "%u", tmp___24);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "953", "tmp___24", checkpoints_buf);
            tmp___23 = i;
            sprintf(checkpoints_buf, "%d", tmp___23);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "956", "tmp___23", checkpoints_buf);
            i ++;
            sprintf(checkpoints_buf, "%d", i);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "957", "i", checkpoints_buf);
            ll[tmp___23] = 0U;

          }
          sprintf(checkpoints_buf, "%u", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "tmp___24", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "tmp___24", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "tmp___23", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", i);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "950", "i", checkpoints_buf);

          l = 0U;
          sprintf(checkpoints_buf, "%u", l);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "959", "l", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "7", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "insize", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "k", checkpoints_buf);
          while (1) {
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "961", "k", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", 7);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "961", "7", checkpoints_buf);
            if (k < 7U) {

            } else {
              break;
            }
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "961", "k", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", 7);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "961", "7", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "964", "inptr", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", insize);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "964", "insize", checkpoints_buf);
            if (inptr < insize) {
              tmp___25 = inptr;
              sprintf(checkpoints_buf, "%u", tmp___25);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "965", "tmp___25", checkpoints_buf);
              inptr ++;
              sprintf(checkpoints_buf, "%u", inptr);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "966", "inptr", checkpoints_buf);
              tmp___27 = (int )inbuf[tmp___25];
              sprintf(checkpoints_buf, "%d", tmp___27);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "967", "tmp___27", checkpoints_buf);
            } else {
              outcnt = w;
              sprintf(checkpoints_buf, "%u", outcnt);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "968", "outcnt", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___26);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "969", "tmp___26", checkpoints_buf);

              tmp___26 = fill_inbuf(0);
              sprintf(checkpoints_buf, "%d", tmp___26);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "969", "tmp___26", checkpoints_buf);

              tmp___27 = tmp___26;
              sprintf(checkpoints_buf, "%d", tmp___27);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                              "970", "tmp___27", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "964", "inptr", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", insize);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "964", "insize", checkpoints_buf);
            b |= (ulg )((uch )tmp___27) << k;

            k += 8U;
            sprintf(checkpoints_buf, "%u", k);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "972", "k", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", 7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "7", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "insize", checkpoints_buf);

          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "960", "k", checkpoints_buf);
          j = 11U + ((unsigned int )b & 127U);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "973", "j", checkpoints_buf);
          b >>= 7;

          k -= 7U;
          sprintf(checkpoints_buf, "%u", k);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "975", "k", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "976", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", n);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "976", "n", checkpoints_buf);
          if ((unsigned int )i + j > n) {
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "977", "1", checkpoints_buf);
            return (1);
          } else {

          }
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "976", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", n);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "976", "n", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___29);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "tmp___29", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___29);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "tmp___29", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___28);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "tmp___28", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", i);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "i", checkpoints_buf);

          while (1) {
            tmp___29 = j;
            sprintf(checkpoints_buf, "%u", tmp___29);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "980", "tmp___29", checkpoints_buf);
            j --;
            sprintf(checkpoints_buf, "%u", j);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "981", "j", checkpoints_buf);
            sprintf(checkpoints_buf, "%u", tmp___29);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "982", "tmp___29", checkpoints_buf);
            if (tmp___29) {

            } else {
              break;
            }
            sprintf(checkpoints_buf, "%u", tmp___29);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "982", "tmp___29", checkpoints_buf);
            tmp___28 = i;
            sprintf(checkpoints_buf, "%d", tmp___28);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "985", "tmp___28", checkpoints_buf);
            i ++;
            sprintf(checkpoints_buf, "%d", i);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                            "986", "i", checkpoints_buf);
            ll[tmp___28] = 0U;

          }
          sprintf(checkpoints_buf, "%u", tmp___29);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "tmp___29", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", j);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "j", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___29);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "tmp___29", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___28);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "tmp___28", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", i);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "979", "i", checkpoints_buf);

          l = 0U;
          sprintf(checkpoints_buf, "%u", l);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                          "988", "l", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", j);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "930", "j", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                        "930", "17", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", j);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "901", "j", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "901", "16", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", j);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "896", "j", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "896", "16", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "k", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "j", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", j);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "j", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "874", "16", checkpoints_buf);

  huft_free(tl);

  bb = b;

  bk = k;
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "991", "bk", checkpoints_buf);
  bl = lbits;
  sprintf(checkpoints_buf, "%d", bl);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "992", "bl", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "993", "i", checkpoints_buf);

  i = huft_build(ll, nl, 257U, cplens, cplext, & tl, & bl);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "993", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "994", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "994", "0", checkpoints_buf);
  if (i != 0) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "995", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "995", "1", checkpoints_buf);
    if (i == 1) {

      huft_free(tl);

    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "995", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "995", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "998", "i", checkpoints_buf);
    return (i);
  } else {

  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "994", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "994", "0", checkpoints_buf);
  bd = dbits;
  sprintf(checkpoints_buf, "%d", bd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1000", "bd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1001", "i", checkpoints_buf);

  i = huft_build(ll + nl, nd, 0U, cpdist, cpdext, & td, & bd);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1001", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1002", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1002", "0", checkpoints_buf);
  if (i != 0) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1003", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1003", "1", checkpoints_buf);
    if (i == 1) {

      huft_free(td);

    } else {

    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1003", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1003", "1", checkpoints_buf);

    huft_free(tl);

    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1007", "i", checkpoints_buf);
    return (i);
  } else {

  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1002", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1002", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___30);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1009", "tmp___30", checkpoints_buf);

  tmp___30 = inflate_codes(tl, td, bl, bd);
  sprintf(checkpoints_buf, "%d", tmp___30);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1009", "tmp___30", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___30);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1010", "tmp___30", checkpoints_buf);
  if (tmp___30) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1011", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___30);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1010", "tmp___30", checkpoints_buf);

  huft_free(tl);


  huft_free(td);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1015", "0", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1017", "k", checkpoints_buf);
  w = outcnt;
  sprintf(checkpoints_buf, "%u", w);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1018", "w", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1020", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1020", "1", checkpoints_buf);
    if (k < 1U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1020", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1020", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1023", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1023", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp = inptr;
      sprintf(checkpoints_buf, "%u", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1024", "tmp", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1025", "inptr", checkpoints_buf);
      tmp___1 = (int )inbuf[tmp];
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1026", "tmp___1", checkpoints_buf);
    } else {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1027", "outcnt", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1028", "tmp___0", checkpoints_buf);

      tmp___0 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1028", "tmp___0", checkpoints_buf);

      tmp___1 = tmp___0;
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1029", "tmp___1", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1023", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1023", "insize", checkpoints_buf);
    b |= (ulg )((uch )tmp___1) << k;

    k += 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1031", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1019", "k", checkpoints_buf);
  *e = (int )b & 1;

  b >>= 1;

  k --;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1034", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "k", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1036", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1036", "2", checkpoints_buf);
    if (k < 2U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1036", "k", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1036", "2", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1039", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1039", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp___2 = inptr;
      sprintf(checkpoints_buf, "%u", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1040", "tmp___2", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1041", "inptr", checkpoints_buf);
      tmp___4 = (int )inbuf[tmp___2];
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1042", "tmp___4", checkpoints_buf);
    } else {
      outcnt = w;
      sprintf(checkpoints_buf, "%u", outcnt);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1043", "outcnt", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1044", "tmp___3", checkpoints_buf);

      tmp___3 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1044", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1045", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1039", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1039", "insize", checkpoints_buf);
    b |= (ulg )((uch )tmp___4) << k;

    k += 8U;
    sprintf(checkpoints_buf, "%u", k);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1047", "k", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "k", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "insize", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1035", "k", checkpoints_buf);
  t = (unsigned int )b & 3U;
  sprintf(checkpoints_buf, "%u", t);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1048", "t", checkpoints_buf);
  b >>= 2;

  k -= 2U;
  sprintf(checkpoints_buf, "%u", k);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1050", "k", checkpoints_buf);
  bb = b;

  bk = k;
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1052", "bk", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", t);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1053", "t", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1053", "2", checkpoints_buf);
  if (t == 2U) {
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1054", "tmp___5", checkpoints_buf);

    tmp___5 = inflate_dynamic();
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1054", "tmp___5", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1055", "tmp___5", checkpoints_buf);
    return (tmp___5);
  } else {

  }
  sprintf(checkpoints_buf, "%u", t);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1053", "t", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1053", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", t);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1057", "t", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1057", "0", checkpoints_buf);
  if (t == 0U) {
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1058", "tmp___6", checkpoints_buf);

    tmp___6 = inflate_stored();
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1058", "tmp___6", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1059", "tmp___6", checkpoints_buf);
    return (tmp___6);
  } else {

  }
  sprintf(checkpoints_buf, "%u", t);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1057", "t", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1057", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", t);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1061", "t", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1061", "1", checkpoints_buf);
  if (t == 1U) {
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1062", "tmp___7", checkpoints_buf);

    tmp___7 = inflate_fixed();
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1062", "tmp___7", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1063", "tmp___7", checkpoints_buf);
    return (tmp___7);
  } else {

  }
  sprintf(checkpoints_buf, "%u", t);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1061", "t", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1061", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1065", "2", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%u", outcnt);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1066", "outcnt", checkpoints_buf);
  bk = 0U;
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1067", "bk", checkpoints_buf);
  bb = (ulg )0;

  h = 0U;
  sprintf(checkpoints_buf, "%u", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1069", "h", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", hufts);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "hufts", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "r", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "r", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", hufts);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "hufts", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "h", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "e", checkpoints_buf);
  while (1) {
    hufts = 0U;
    sprintf(checkpoints_buf, "%u", hufts);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1071", "hufts", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", r);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1072", "r", checkpoints_buf);

    r = inflate_block(& e);
    sprintf(checkpoints_buf, "%d", r);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1072", "r", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", r);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1073", "r", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1073", "0", checkpoints_buf);
    if (r != 0) {
      sprintf(checkpoints_buf, "%d", r);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1074", "r", checkpoints_buf);
      return (r);
    } else {

    }
    sprintf(checkpoints_buf, "%d", r);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1073", "r", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1073", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", hufts);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1076", "hufts", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1076", "h", checkpoints_buf);
    if (hufts > h) {
      h = hufts;
      sprintf(checkpoints_buf, "%u", h);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                      "1077", "h", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%u", hufts);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1076", "hufts", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1076", "h", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1079", "e", checkpoints_buf);
    if (! e) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1079", "e", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", hufts);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "hufts", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "r", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "r", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", hufts);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "hufts", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "h", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1070", "e", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "bk", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "bk", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "inptr", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", bk);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1083", "bk", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1083", "8", checkpoints_buf);
    if (bk >= 8U) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", bk);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1083", "bk", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1083", "8", checkpoints_buf);
    bk -= 8U;
    sprintf(checkpoints_buf, "%u", bk);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1086", "bk", checkpoints_buf);
    inptr --;
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                    "1087", "inptr", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "bk", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", bk);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "bk", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1082", "inptr", checkpoints_buf);
  outcnt = outcnt;
  sprintf(checkpoints_buf, "%u", outcnt);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1088", "outcnt", checkpoints_buf);

  flush_window();

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-08-16-3fe0caeada-39a362ae9d",
                  "1090", "0", checkpoints_buf);
  return (0);
}
}
