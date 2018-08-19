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
enum __anonenum_2 {
    _ISupper = 256,
    _ISlower = 512,
    _ISalpha = 1024,
    _ISdigit = 2048,
    _ISxdigit = 4096,
    _ISspace = 8192,
    _ISprint = 16384,
    _ISgraph = 32768,
    _ISblank = 1,
    _IScntrl = 2,
    _ISpunct = 4,
    _ISalnum = 8
} ;
struct __locale_data;
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
struct __anonstruct___sigset_t_3 {
   unsigned long __val[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef __sigset_t sigset_t;
typedef long __fd_mask;
struct __anonstruct_fd_set_4 {
   __fd_mask fds_bits[1024 / (8 * (int )sizeof(__fd_mask ))] ;
};
typedef __fd_mask fd_mask;
typedef __blksize_t blksize_t;
typedef __blkcnt64_t blkcnt64_t;
typedef __fsblkcnt64_t fsblkcnt64_t;
typedef __fsfilcnt64_t fsfilcnt64_t;
typedef unsigned long pthread_t;
union __anonunion_pthread_attr_t_5 {
   char __size[36] ;
   long __align ;
};
union __anonunion____missing_field_name_7 {
   int __spins ;
   __pthread_slist_t __list ;
};
union __anonunion_pthread_mutex_t_6 {
   struct __pthread_mutex_s __data ;
   char __size[24] ;
   long __align ;
};
union __anonunion_pthread_mutexattr_t_8 {
   char __size[4] ;
   long __align ;
};
struct __anonstruct___data_10 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_9 {
   struct __anonstruct___data_10 __data ;
   char __size[48] ;
   long long __align ;
};
union __anonunion_pthread_condattr_t_11 {
   char __size[4] ;
   long __align ;
};
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
struct __anonstruct___data_13 {
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
union __anonunion_pthread_rwlock_t_12 {
   struct __anonstruct___data_13 __data ;
   char __size[32] ;
   long __align ;
};
union __anonunion_pthread_rwlockattr_t_14 {
   char __size[8] ;
   long __align ;
};
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_15 {
   char __size[20] ;
   long __align ;
};
union __anonunion_pthread_barrierattr_t_16 {
   char __size[4] ;
   int __align ;
};
typedef __sig_atomic_t sig_atomic_t;
union sigval {
   int sival_int ;
   void *sival_ptr ;
};
typedef union sigval sigval_t;
struct __anonstruct__kill_18 {
   __pid_t si_pid ;
   __uid_t si_uid ;
};
struct __anonstruct__timer_19 {
   int si_tid ;
   int si_overrun ;
   sigval_t si_sigval ;
};
struct __anonstruct__rt_20 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   sigval_t si_sigval ;
};
struct __anonstruct__sigchld_21 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   int si_status ;
   __clock_t si_utime ;
   __clock_t si_stime ;
};
struct __anonstruct__sigfault_22 {
   void *si_addr ;
};
struct __anonstruct__sigpoll_23 {
   long si_band ;
   int si_fd ;
};
union __anonunion__sifields_17 {
   int _pad[128U / sizeof(int ) - 3U] ;
   struct __anonstruct__kill_18 _kill ;
   struct __anonstruct__timer_19 _timer ;
   struct __anonstruct__rt_20 _rt ;
   struct __anonstruct__sigchld_21 _sigchld ;
   struct __anonstruct__sigfault_22 _sigfault ;
   struct __anonstruct__sigpoll_23 _sigpoll ;
};
struct siginfo {
   int si_signo ;
   int si_errno ;
   int si_code ;
   union __anonunion__sifields_17 _sifields ;
};
typedef struct siginfo siginfo_t;
enum __anonenum_24 {
    SI_ASYNCNL = -60,
    SI_TKILL = -6,
    SI_SIGIO = -5,
    SI_ASYNCIO = -4,
    SI_MESGQ = -3,
    SI_TIMER = -2,
    SI_QUEUE = -1,
    SI_USER = 0,
    SI_KERNEL = 128
} ;
enum __anonenum_25 {
    ILL_ILLOPC = 1,
    ILL_ILLOPN = 2,
    ILL_ILLADR = 3,
    ILL_ILLTRP = 4,
    ILL_PRVOPC = 5,
    ILL_PRVREG = 6,
    ILL_COPROC = 7,
    ILL_BADSTK = 8
} ;
enum __anonenum_26 {
    FPE_INTDIV = 1,
    FPE_INTOVF = 2,
    FPE_FLTDIV = 3,
    FPE_FLTOVF = 4,
    FPE_FLTUND = 5,
    FPE_FLTRES = 6,
    FPE_FLTINV = 7,
    FPE_FLTSUB = 8
} ;
enum __anonenum_27 {
    SEGV_MAPERR = 1,
    SEGV_ACCERR = 2
} ;
enum __anonenum_28 {
    BUS_ADRALN = 1,
    BUS_ADRERR = 2,
    BUS_OBJERR = 3
} ;
enum __anonenum_29 {
    TRAP_BRKPT = 1,
    TRAP_TRACE = 2
} ;
enum __anonenum_30 {
    CLD_EXITED = 1,
    CLD_KILLED = 2,
    CLD_DUMPED = 3,
    CLD_TRAPPED = 4,
    CLD_STOPPED = 5,
    CLD_CONTINUED = 6
} ;
enum __anonenum_31 {
    POLL_IN = 1,
    POLL_OUT = 2,
    POLL_MSG = 3,
    POLL_ERR = 4,
    POLL_PRI = 5,
    POLL_HUP = 6
} ;
struct __anonstruct__sigev_thread_33 {
   void (*_function)(sigval_t  ) ;
   void *_attribute ;
};
union __anonunion__sigev_un_32 {
   int _pad[64U / sizeof(int ) - 3U] ;
   __pid_t _tid ;
   struct __anonstruct__sigev_thread_33 _sigev_thread ;
};
struct sigevent {
   sigval_t sigev_value ;
   int sigev_signo ;
   int sigev_notify ;
   union __anonunion__sigev_un_32 _sigev_un ;
};
typedef struct sigevent sigevent_t;
enum __anonenum_34 {
    SIGEV_SIGNAL = 0,
    SIGEV_NONE = 1,
    SIGEV_THREAD = 2,
    SIGEV_THREAD_ID = 4
} ;
typedef void (*__sighandler_t)(int  );
typedef void (*sighandler_t)(int  );
typedef void (*sig_t)(int  );
union __anonunion___sigaction_handler_35 {
   void (*sa_handler)(int  ) ;
   void (*sa_sigaction)(int  , siginfo_t * , void * ) ;
};
struct sigaction {
   union __anonunion___sigaction_handler_35 __sigaction_handler ;
   __sigset_t sa_mask ;
   int sa_flags ;
   void (*sa_restorer)(void) ;
};
struct sigvec {
   void (*sv_handler)(int  ) ;
   int sv_mask ;
   int sv_flags ;
};
typedef signed char __s8;
typedef unsigned char __u8;
typedef short __s16;
typedef unsigned short __u16;
typedef int __s32;
typedef unsigned int __u32;
typedef long long __s64;
typedef unsigned long long __u64;
typedef unsigned short umode_t;
struct __anonstruct___kernel_fd_set_36 {
   unsigned long fds_bits[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___kernel_fd_set_36 __kernel_fd_set;
typedef void (*__kernel_sighandler_t)(int  );
typedef int __kernel_key_t;
typedef int __kernel_mqd_t;
typedef unsigned long __kernel_ino_t;
typedef unsigned short __kernel_mode_t;
typedef unsigned short __kernel_nlink_t;
typedef long __kernel_off_t;
typedef int __kernel_pid_t;
typedef unsigned short __kernel_ipc_pid_t;
typedef unsigned short __kernel_uid_t;
typedef unsigned short __kernel_gid_t;
typedef unsigned int __kernel_size_t;
typedef int __kernel_ssize_t;
typedef int __kernel_ptrdiff_t;
typedef long __kernel_time_t;
typedef long __kernel_suseconds_t;
typedef long __kernel_clock_t;
typedef int __kernel_timer_t;
typedef int __kernel_clockid_t;
typedef int __kernel_daddr_t;
typedef char *__kernel_caddr_t;
typedef unsigned short __kernel_uid16_t;
typedef unsigned short __kernel_gid16_t;
typedef unsigned int __kernel_uid32_t;
typedef unsigned int __kernel_gid32_t;
typedef unsigned short __kernel_old_uid_t;
typedef unsigned short __kernel_old_gid_t;
typedef unsigned short __kernel_old_dev_t;
typedef long long __kernel_loff_t;
struct __anonstruct___kernel_fsid_t_37 {
   int val[2] ;
};
typedef struct __anonstruct___kernel_fsid_t_37 __kernel_fsid_t;
typedef __u16 __le16;
typedef __u16 __be16;
typedef __u32 __le32;
typedef __u32 __be32;
typedef __u64 __le64;
typedef __u64 __be64;
typedef __u16 __sum16;
typedef __u32 __wsum;
struct _fpx_sw_bytes {
   __u32 magic1 ;
   __u32 extended_size ;
   __u64 xstate_bv ;
   __u32 xstate_size ;
   __u32 padding[7] ;
};
struct _fpreg {
   unsigned short significand[4] ;
   unsigned short exponent ;
};
struct _fpxreg {
   unsigned short significand[4] ;
   unsigned short exponent ;
   unsigned short padding[3] ;
};
struct _xmmreg {
   unsigned long element[4] ;
};
union __anonunion____missing_field_name_38 {
   unsigned long padding2[12] ;
   struct _fpx_sw_bytes sw_reserved ;
};
struct _fpstate {
   unsigned long cw ;
   unsigned long sw ;
   unsigned long tag ;
   unsigned long ipoff ;
   unsigned long cssel ;
   unsigned long dataoff ;
   unsigned long datasel ;
   struct _fpreg _st[8] ;
   unsigned short status ;
   unsigned short magic ;
   unsigned long _fxsr_env[6] ;
   unsigned long mxcsr ;
   unsigned long reserved ;
   struct _fpxreg _fxsr_st[8] ;
   struct _xmmreg _xmm[8] ;
   unsigned long padding1[44] ;
   union __anonunion____missing_field_name_38 __annonCompField2 ;
};
struct sigcontext {
   unsigned short gs ;
   unsigned short __gsh ;
   unsigned short fs ;
   unsigned short __fsh ;
   unsigned short es ;
   unsigned short __esh ;
   unsigned short ds ;
   unsigned short __dsh ;
   unsigned long edi ;
   unsigned long esi ;
   unsigned long ebp ;
   unsigned long esp ;
   unsigned long ebx ;
   unsigned long edx ;
   unsigned long ecx ;
   unsigned long eax ;
   unsigned long trapno ;
   unsigned long err ;
   unsigned long eip ;
   unsigned short cs ;
   unsigned short __csh ;
   unsigned long eflags ;
   unsigned long esp_at_signal ;
   unsigned short ss ;
   unsigned short __ssh ;
   struct _fpstate *fpstate ;
   unsigned long oldmask ;
   unsigned long cr2 ;
};
struct _xsave_hdr {
   __u64 xstate_bv ;
   __u64 reserved1[2] ;
   __u64 reserved2[5] ;
};
struct _ymmh_state {
   __u32 ymmh_space[64] ;
};
struct _xstate {
   struct _fpstate fpstate ;
   struct _xsave_hdr xstate_hdr ;
   struct _ymmh_state ymmh ;
};
struct sigstack {
   void *ss_sp ;
   int ss_onstack ;
};
enum __anonenum_39 {
    SS_ONSTACK = 1,
    SS_DISABLE = 2
} ;
struct sigaltstack {
   void *ss_sp ;
   int ss_flags ;
   size_t ss_size ;
};
typedef struct sigaltstack stack_t;
typedef int greg_t;
typedef greg_t gregset_t[19];
enum __anonenum_40 {
    REG_GS = 0,
    REG_FS = 1,
    REG_ES = 2,
    REG_DS = 3,
    REG_EDI = 4,
    REG_ESI = 5,
    REG_EBP = 6,
    REG_ESP = 7,
    REG_EBX = 8,
    REG_EDX = 9,
    REG_ECX = 10,
    REG_EAX = 11,
    REG_TRAPNO = 12,
    REG_ERR = 13,
    REG_EIP = 14,
    REG_CS = 15,
    REG_EFL = 16,
    REG_UESP = 17,
    REG_SS = 18
} ;
struct _libc_fpreg {
   unsigned short significand[4] ;
   unsigned short exponent ;
};
struct _libc_fpstate {
   unsigned long cw ;
   unsigned long sw ;
   unsigned long tag ;
   unsigned long ipoff ;
   unsigned long cssel ;
   unsigned long dataoff ;
   unsigned long datasel ;
   struct _libc_fpreg _st[8] ;
   unsigned long status ;
};
typedef struct _libc_fpstate *fpregset_t;
struct __anonstruct_mcontext_t_41 {
   gregset_t gregs ;
   fpregset_t fpregs ;
   unsigned long oldmask ;
   unsigned long cr2 ;
};
typedef struct __anonstruct_mcontext_t_41 mcontext_t;
struct ucontext {
   unsigned long uc_flags ;
   struct ucontext *uc_link ;
   stack_t uc_stack ;
   mcontext_t uc_mcontext ;
   __sigset_t uc_sigmask ;
   struct _libc_fpstate __fpregs_mem ;
};
typedef struct ucontext ucontext_t;
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
struct stat64 {
   __dev_t st_dev ;
   unsigned int __pad1 ;
   __ino_t __st_ino ;
   __mode_t st_mode ;
   __nlink_t st_nlink ;
   __uid_t st_uid ;
   __gid_t st_gid ;
   __dev_t st_rdev ;
   unsigned int __pad2 ;
   __off64_t st_size ;
   __blksize_t st_blksize ;
   __blkcnt64_t st_blocks ;
   struct timespec st_atim ;
   struct timespec st_mtim ;
   struct timespec st_ctim ;
   __ino64_t st_ino ;
};
typedef int error_t;
typedef void *voidp;
typedef struct _IO_FILE FILE;
typedef struct _IO_FILE __FILE;
union __anonunion___value_43 {
   unsigned int __wch ;
   char __wchb[4] ;
};
struct __anonstruct___mbstate_t_42 {
   int __count ;
   union __anonunion___value_43 __value ;
};
struct __anonstruct__G_fpos_t_44 {
   __off_t __pos ;
   __mbstate_t __state ;
};
struct __anonstruct__G_fpos64_t_45 {
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
struct __anonstruct__IO_cookie_io_functions_t_46 {
   __io_read_fn *read ;
   __io_write_fn *write ;
   __io_seek_fn *seek ;
   __io_close_fn *close ;
};
typedef struct __anonstruct__IO_cookie_io_functions_t_46 _IO_cookie_io_functions_t;
typedef _IO_cookie_io_functions_t cookie_io_functions_t;
struct _IO_cookie_file;
struct _IO_cookie_file;
typedef __gnuc_va_list va_list;
typedef _G_fpos64_t fpos64_t;
struct obstack;
struct obstack;
typedef int ptrdiff_t;
typedef long wchar_t;
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
typedef unsigned char uch;
typedef unsigned short ush;
typedef unsigned long ulg;
typedef int file_t;
struct option {
   char const   *name ;
   int has_arg ;
   int *flag ;
   int val ;
};
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
enum __anonenum_47 {
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
enum __anonenum_48 {
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
enum __anonenum_49 {
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
struct __anonstruct___wait_terminated_50 {
   unsigned int __w_termsig : 7 ;
   unsigned int __w_coredump : 1 ;
   unsigned int __w_retcode : 8 ;
   unsigned int  : 16 ;
};
struct __anonstruct___wait_stopped_51 {
   unsigned int __w_stopval : 8 ;
   unsigned int __w_stopsig : 8 ;
   unsigned int  : 16 ;
};
union __anonunion___WAIT_STATUS_52 {
   union wait *__uptr ;
   int *__iptr ;
};
struct __anonstruct_div_t_53 {
   int quot ;
   int rem ;
};
struct __anonstruct_ldiv_t_54 {
   long quot ;
   long rem ;
};
struct __anonstruct_lldiv_t_55 {
   long long quot ;
   long long rem ;
};
typedef int (*__compar_fn_t)(void const   * , void const   * );
typedef int (*comparison_fn_t)(void const   * , void const   * );
typedef int (*__compar_d_fn_t)(void const   * , void const   * , void * );
struct flock {
   short l_type ;
   short l_whence ;
   __off64_t l_start ;
   __off64_t l_len ;
   __pid_t l_pid ;
};
struct flock64 {
   short l_type ;
   short l_whence ;
   __off64_t l_start ;
   __off64_t l_len ;
   __pid_t l_pid ;
};
enum __pid_type {
    F_OWNER_TID = 0,
    F_OWNER_PID = 1,
    F_OWNER_PGRP = 2,
    F_OWNER_GID = 2
} ;
struct f_owner_ex {
   enum __pid_type type ;
   __pid_t pid ;
};
struct dirent {
   __ino64_t d_ino ;
   __off64_t d_off ;
   unsigned short d_reclen ;
   unsigned char d_type ;
   char d_name[256] ;
};
struct dirent64 {
   __ino64_t d_ino ;
   __off64_t d_off ;
   unsigned short d_reclen ;
   unsigned char d_type ;
   char d_name[256] ;
};
enum __anonenum_56 {
    DT_UNKNOWN = 0,
    DT_FIFO = 1,
    DT_CHR = 2,
    DT_DIR = 4,
    DT_BLK = 6,
    DT_REG = 8,
    DT_LNK = 10,
    DT_SOCK = 12,
    DT_WHT = 14
} ;
struct __dirstream;
typedef struct __dirstream DIR;
static char *license_msg[6]  = {      (char *)"Copyright (C) 2007 Free Software Foundation, Inc.",      (char *)"Copyright (C) 1993 Jean-loup Gailly.",      (char *)"This is free software.  You may redistribute copies of it under the terms of",      (char *)"the GNU General Public License <http://www.gnu.org/licenses/gpl.html>.", 
        (char *)"There is NO WARRANTY, to the extent permitted by law.",      (char *)0};
extern  __attribute__((__nothrow__)) unsigned short const   **__ctype_b_loc(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) __int32_t const   **__ctype_tolower_loc(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) __int32_t const   **__ctype_toupper_loc(void)  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) int isalnum(int  ) ;
extern  __attribute__((__nothrow__)) int isalpha(int  ) ;
extern  __attribute__((__nothrow__)) int iscntrl(int  ) ;
extern  __attribute__((__nothrow__)) int isdigit(int  ) ;
extern  __attribute__((__nothrow__)) int islower(int  ) ;
extern  __attribute__((__nothrow__)) int isgraph(int  ) ;
extern  __attribute__((__nothrow__)) int isprint(int  ) ;
extern  __attribute__((__nothrow__)) int ispunct(int  ) ;
extern  __attribute__((__nothrow__)) int isspace(int  ) ;
extern  __attribute__((__nothrow__)) int isupper(int  ) ;
extern  __attribute__((__nothrow__)) int isxdigit(int  ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  tolower(int __c ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  toupper(int __c ) ;
extern  __attribute__((__nothrow__)) int isblank(int  ) ;
extern  __attribute__((__nothrow__)) int isctype(int __c , int __mask ) ;
extern  __attribute__((__nothrow__)) int isascii(int __c ) ;
extern  __attribute__((__nothrow__)) int toascii(int __c ) ;
extern  __attribute__((__nothrow__)) int _toupper(int  ) ;
extern  __attribute__((__nothrow__)) int _tolower(int  ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  tolower(int __c ) ;
__inline extern int __attribute__((__gnu_inline__))  tolower(int __c ) 
{ 
  __int32_t const   **tmp ;
  __int32_t tmp___0 ;

  {
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1", "-128", checkpoints_buf);
  if (__c >= -128) {
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "2", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "2", "256", checkpoints_buf);
    if (__c < 256) {


      tmp = __ctype_tolower_loc();


      tmp___0 = *(*tmp + __c);

    } else {
      tmp___0 = (__int32_t const   )__c;

    }
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "2", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "2", "256", checkpoints_buf);
  } else {
    tmp___0 = (__int32_t const   )__c;

  }
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1", "-128", checkpoints_buf);
  return ((int __attribute__((__gnu_inline__))  )tmp___0);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  toupper(int __c ) ;
__inline extern int __attribute__((__gnu_inline__))  toupper(int __c ) 
{ 
  __int32_t const   **tmp ;
  __int32_t tmp___0 ;

  {
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "8", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "8", "-128", checkpoints_buf);
  if (__c >= -128) {
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "9", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "9", "256", checkpoints_buf);
    if (__c < 256) {


      tmp = __ctype_toupper_loc();


      tmp___0 = *(*tmp + __c);

    } else {
      tmp___0 = (__int32_t const   )__c;

    }
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "9", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "9", "256", checkpoints_buf);
  } else {
    tmp___0 = (__int32_t const   )__c;

  }
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "8", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "8", "-128", checkpoints_buf);
  return ((int __attribute__((__gnu_inline__))  )tmp___0);
}
}
extern  __attribute__((__nothrow__)) int isalnum_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isalpha_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int iscntrl_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isdigit_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int islower_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isgraph_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isprint_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int ispunct_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isspace_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isupper_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isxdigit_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int isblank_l(int  , __locale_t  ) ;
extern  __attribute__((__nothrow__)) int __tolower_l(int __c , __locale_t __l ) ;
extern  __attribute__((__nothrow__)) int tolower_l(int __c , __locale_t __l ) ;
extern  __attribute__((__nothrow__)) int __toupper_l(int __c , __locale_t __l ) ;
extern  __attribute__((__nothrow__)) int toupper_l(int __c , __locale_t __l ) ;
__inline extern int __attribute__((__gnu_inline__))  __sigismember(__sigset_t const   *__set ,
                                                                   int __sig ) ;
__inline extern int __attribute__((__gnu_inline__))  __sigaddset(__sigset_t *__set ,
                                                                 int __sig ) ;
__inline extern int __attribute__((__gnu_inline__))  __sigdelset(__sigset_t *__set ,
                                                                 int __sig ) ;
__inline extern int __attribute__((__gnu_inline__))  __sigismember(__sigset_t const   *__set ,
                                                                   int __sig ) 
{ 
  unsigned long __mask ;
  unsigned long __word ;
  int tmp ;

  {
  __mask = 1UL << (unsigned int )(__sig - 1) % (8U * sizeof(unsigned long ));
  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "18", "__mask", checkpoints_buf);
  __word = (unsigned long )((unsigned int )(__sig - 1) / (8U * sizeof(unsigned long )));
  sprintf(checkpoints_buf, "%ul", __word);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "19", "__word", checkpoints_buf);

  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "20", "__mask", checkpoints_buf);
  if (__set->__val[__word] & __mask) {
    tmp = 1;
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "21", "tmp", checkpoints_buf);
  } else {
    tmp = 0;
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "22", "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "20", "__mask", checkpoints_buf);
  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern int __attribute__((__gnu_inline__))  __sigaddset(__sigset_t *__set ,
                                                                 int __sig ) 
{ 
  unsigned long __mask ;
  unsigned long __word ;

  {
  __mask = 1UL << (unsigned int )(__sig - 1) % (8U * sizeof(unsigned long ));
  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "24", "__mask", checkpoints_buf);
  __word = (unsigned long )((unsigned int )(__sig - 1) / (8U * sizeof(unsigned long )));
  sprintf(checkpoints_buf, "%ul", __word);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "25", "__word", checkpoints_buf);
  __set->__val[__word] |= __mask;

  return ((int __attribute__((__gnu_inline__))  )0);
}
}
__inline extern int __attribute__((__gnu_inline__))  __sigdelset(__sigset_t *__set ,
                                                                 int __sig ) 
{ 
  unsigned long __mask ;
  unsigned long __word ;

  {
  __mask = 1UL << (unsigned int )(__sig - 1) % (8U * sizeof(unsigned long ));
  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "28", "__mask", checkpoints_buf);
  __word = (unsigned long )((unsigned int )(__sig - 1) / (8U * sizeof(unsigned long )));
  sprintf(checkpoints_buf, "%ul", __word);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "29", "__word", checkpoints_buf);
  __set->__val[__word] &= ~ __mask;

  return ((int __attribute__((__gnu_inline__))  )0);
}
}
extern  __attribute__((__nothrow__)) __sighandler_t __sysv_signal(int __sig ,
                                                                  void (*__handler)(int  ) ) ;
extern  __attribute__((__nothrow__)) __sighandler_t sysv_signal(int __sig ,
                                                                void (*__handler)(int  ) ) ;
extern  __attribute__((__nothrow__)) __sighandler_t signal(int __sig ,
                                                           void (*__handler)(int  ) ) ;
extern  __attribute__((__nothrow__)) __sighandler_t bsd_signal(int __sig ,
                                                               void (*__handler)(int  ) ) ;
extern  __attribute__((__nothrow__)) int kill(__pid_t __pid , int __sig ) ;
extern  __attribute__((__nothrow__)) int killpg(__pid_t __pgrp , int __sig ) ;
extern  __attribute__((__nothrow__)) int raise(int __sig ) ;
extern  __attribute__((__nothrow__)) __sighandler_t ssignal(int __sig ,
                                                            void (*__handler)(int  ) ) ;
extern  __attribute__((__nothrow__)) int gsignal(int __sig ) ;
extern void psignal(int __sig , char const   *__s ) ;
extern void psiginfo(siginfo_t const   *__pinfo , char const   *__s ) ;
extern int __sigpause(int __sig_or_mask , int __is_sig ) ;
extern int sigpause(int __sig )  __asm__("__xpg_sigpause")  ;
extern  __attribute__((__nothrow__)) int sigblock(int __mask )  __attribute__((__deprecated__)) ;
extern  __attribute__((__nothrow__)) int sigsetmask(int __mask )  __attribute__((__deprecated__)) ;
extern  __attribute__((__nothrow__)) int siggetmask(void)  __attribute__((__deprecated__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sigemptyset)(sigset_t *__set ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sigfillset)(sigset_t *__set ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sigaddset)(sigset_t *__set ,
                                                                                      int __signo ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sigdelset)(sigset_t *__set ,
                                                                                      int __signo ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sigismember)(sigset_t const   *__set ,
                                                                                        int __signo ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sigisemptyset)(sigset_t const   *__set ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,3))) sigandset)(sigset_t *__set ,
                                                                                          sigset_t const   *__left ,
                                                                                          sigset_t const   *__right ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2,3))) sigorset)(sigset_t *__set ,
                                                                                         sigset_t const   *__left ,
                                                                                         sigset_t const   *__right ) ;
extern  __attribute__((__nothrow__)) int sigprocmask(int __how ,
                                                     sigset_t const   * __restrict  __set ,
                                                     sigset_t * __restrict  __oset ) ;
extern int ( __attribute__((__nonnull__(1))) sigsuspend)(sigset_t const   *__set ) ;
extern  __attribute__((__nothrow__)) int sigaction(int __sig ,
                                                   struct sigaction  const  * __restrict  __act ,
                                                   struct sigaction * __restrict  __oact ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) sigpending)(sigset_t *__set ) ;
extern int ( __attribute__((__nonnull__(1,2))) sigwait)(sigset_t const   * __restrict  __set ,
                                                        int * __restrict  __sig ) ;
extern int ( __attribute__((__nonnull__(1))) sigwaitinfo)(sigset_t const   * __restrict  __set ,
                                                          siginfo_t * __restrict  __info ) ;
extern int ( __attribute__((__nonnull__(1))) sigtimedwait)(sigset_t const   * __restrict  __set ,
                                                           siginfo_t * __restrict  __info ,
                                                           struct timespec  const  * __restrict  __timeout ) ;
extern  __attribute__((__nothrow__)) int sigqueue(__pid_t __pid , int __sig ,
                                                  union sigval  const  __val ) ;
extern char const   * const  _sys_siglist[65] ;
extern char const   * const  sys_siglist[65] ;
extern  __attribute__((__nothrow__)) int sigvec(int __sig ,
                                                struct sigvec  const  *__vec ,
                                                struct sigvec *__ovec ) ;
extern  __attribute__((__nothrow__)) int sigreturn(struct sigcontext *__scp ) ;
extern  __attribute__((__nothrow__)) int siginterrupt(int __sig ,
                                                      int __interrupt ) ;
extern  __attribute__((__nothrow__)) int sigstack(struct sigstack *__ss ,
                                                  struct sigstack *__oss )  __attribute__((__deprecated__)) ;
extern  __attribute__((__nothrow__)) int sigaltstack(struct sigaltstack  const  * __restrict  __ss ,
                                                     struct sigaltstack * __restrict  __oss ) ;
extern  __attribute__((__nothrow__)) int sighold(int __sig ) ;
extern  __attribute__((__nothrow__)) int sigrelse(int __sig ) ;
extern  __attribute__((__nothrow__)) int sigignore(int __sig ) ;
extern  __attribute__((__nothrow__)) __sighandler_t sigset(int __sig ,
                                                           void (*__disp)(int  ) ) ;
extern  __attribute__((__nothrow__)) int pthread_sigmask(int __how ,
                                                         __sigset_t const   * __restrict  __newmask ,
                                                         __sigset_t * __restrict  __oldmask ) ;
extern  __attribute__((__nothrow__)) int pthread_kill(pthread_t __threadid ,
                                                      int __signo ) ;
extern  __attribute__((__nothrow__)) int pthread_sigqueue(pthread_t __threadid ,
                                                          int __signo ,
                                                          union sigval  const  __value ) ;
extern  __attribute__((__nothrow__)) int __libc_current_sigrtmin(void) ;
extern  __attribute__((__nothrow__)) int __libc_current_sigrtmax(void) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) stat)(char const   * __restrict  __path ,
                                                                                                                             struct stat * __restrict  __statbuf )  __asm__("stat64")  ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) fstat)(int __fd ,
                                                                                                                            struct stat *__statbuf )  __asm__("fstat64")  ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) stat64)(char const   * __restrict  __path ,
                                                                                                                               struct stat64 * __restrict  __statbuf ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) fstat64)(int __fd ,
                                                                                                                              struct stat64 *__statbuf ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2,3))) fstatat)(int __fd ,
                                                                                                                                char const   * __restrict  __filename ,
                                                                                                                                struct stat * __restrict  __statbuf ,
                                                                                                                                int __flag )  __asm__("fstatat64")  ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2,3))) fstatat64)(int __fd ,
                                                                                                                                  char const   * __restrict  __filename ,
                                                                                                                                  struct stat64 * __restrict  __statbuf ,
                                                                                                                                  int __flag ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) lstat)(char const   * __restrict  __path ,
                                                                                                                              struct stat * __restrict  __statbuf )  __asm__("lstat64")  ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) lstat64)(char const   * __restrict  __path ,
                                                                                                                                struct stat64 * __restrict  __statbuf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) chmod)(char const   *__file ,
                                                                                  __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) lchmod)(char const   *__file ,
                                                                                   __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int fchmod(int __fd , __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) fchmodat)(int __fd ,
                                                                                     char const   *__file ,
                                                                                     __mode_t __mode ,
                                                                                     int __flag ) ;
extern  __attribute__((__nothrow__)) __mode_t umask(__mode_t __mask ) ;
extern  __attribute__((__nothrow__)) __mode_t getumask(void) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) mkdir)(char const   *__path ,
                                                                                  __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) mkdirat)(int __fd ,
                                                                                    char const   *__path ,
                                                                                    __mode_t __mode ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) mknod)(char const   *__path ,
                                                                                                                            __mode_t __mode ,
                                                                                                                            __dev_t __dev ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) mknodat)(int __fd ,
                                                                                                                              char const   *__path ,
                                                                                                                              __mode_t __mode ,
                                                                                                                              __dev_t __dev ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) mkfifo)(char const   *__path ,
                                                                                   __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) mkfifoat)(int __fd ,
                                                                                     char const   *__path ,
                                                                                     __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) utimensat)(int __fd ,
                                                                                      char const   *__path ,
                                                                                      struct timespec  const  *__times ,
                                                                                      int __flags ) ;
extern  __attribute__((__nothrow__)) int futimens(int __fd ,
                                                  struct timespec  const  *__times ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3))) __fxstat)(int __ver ,
                                                                                     int __fildes ,
                                                                                     struct stat *__stat_buf )  __asm__("__fxstat64")  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,3))) __xstat)(int __ver ,
                                                                                      char const   *__filename ,
                                                                                      struct stat *__stat_buf )  __asm__("__xstat64")  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,3))) __lxstat)(int __ver ,
                                                                                       char const   *__filename ,
                                                                                       struct stat *__stat_buf )  __asm__("__lxstat64")  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4))) __fxstatat)(int __ver ,
                                                                                         int __fildes ,
                                                                                         char const   *__filename ,
                                                                                         struct stat *__stat_buf ,
                                                                                         int __flag )  __asm__("__fxstatat64")  ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3))) __fxstat64)(int __ver ,
                                                                                       int __fildes ,
                                                                                       struct stat64 *__stat_buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,3))) __xstat64)(int __ver ,
                                                                                        char const   *__filename ,
                                                                                        struct stat64 *__stat_buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,3))) __lxstat64)(int __ver ,
                                                                                         char const   *__filename ,
                                                                                         struct stat64 *__stat_buf ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,4))) __fxstatat64)(int __ver ,
                                                                                           int __fildes ,
                                                                                           char const   *__filename ,
                                                                                           struct stat64 *__stat_buf ,
                                                                                           int __flag ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2,4))) __xmknod)(int __ver ,
                                                                                       char const   *__path ,
                                                                                       __mode_t __mode ,
                                                                                       __dev_t *__dev ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(3,5))) __xmknodat)(int __ver ,
                                                                                         int __fd ,
                                                                                         char const   *__path ,
                                                                                         __mode_t __mode ,
                                                                                         __dev_t *__dev ) ;
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) stat)(char const   * __restrict  __path ,
                                                                                                                             struct stat * __restrict  __statbuf )  __asm__("stat64")  ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) stat)(char const   * __restrict  __path ,
                                                                                               struct stat * __restrict  __statbuf ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "32", "tmp", checkpoints_buf);

  tmp = __xstat(3, (char const   *)__path, (struct stat *)__statbuf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "32", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) lstat)(char const   * __restrict  __path ,
                                                                                                                              struct stat * __restrict  __statbuf )  __asm__("lstat64")  ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) lstat)(char const   * __restrict  __path ,
                                                                                                struct stat * __restrict  __statbuf ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "34", "tmp", checkpoints_buf);

  tmp = __lxstat(3, (char const   *)__path, (struct stat *)__statbuf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "34", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) fstat)(int __fd ,
                                                                                                                            struct stat *__statbuf )  __asm__("fstat64")  ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) fstat)(int __fd ,
                                                                                              struct stat *__statbuf ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "36", "tmp", checkpoints_buf);

  tmp = __fxstat(3, __fd, __statbuf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "36", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2,3))) fstatat)(int __fd ,
                                                                                                                                char const   * __restrict  __filename ,
                                                                                                                                struct stat * __restrict  __statbuf ,
                                                                                                                                int __flag )  __asm__("fstatat64")  ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2,3))) fstatat)(int __fd ,
                                                                                                  char const   * __restrict  __filename ,
                                                                                                  struct stat * __restrict  __statbuf ,
                                                                                                  int __flag ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "38", "tmp", checkpoints_buf);

  tmp = __fxstatat(3, __fd, (char const   *)__filename,
                   (struct stat *)__statbuf, __flag);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "38", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) mknod)(char const   *__path ,
                                                                                                                            __mode_t __mode ,
                                                                                                                            __dev_t __dev ) ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1))) mknod)(char const   *__path ,
                                                                                              __mode_t __mode ,
                                                                                              __dev_t __dev ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "40", "tmp", checkpoints_buf);

  tmp = __xmknod(1, __path, __mode, & __dev);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "40", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) mknodat)(int __fd ,
                                                                                                                              char const   *__path ,
                                                                                                                              __mode_t __mode ,
                                                                                                                              __dev_t __dev ) ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) mknodat)(int __fd ,
                                                                                                char const   *__path ,
                                                                                                __mode_t __mode ,
                                                                                                __dev_t __dev ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "42", "tmp", checkpoints_buf);

  tmp = __xmknodat(1, __fd, __path, __mode, & __dev);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "42", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) stat64)(char const   * __restrict  __path ,
                                                                                                                               struct stat64 * __restrict  __statbuf ) ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) stat64)(char const   * __restrict  __path ,
                                                                                                 struct stat64 * __restrict  __statbuf ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "44", "tmp", checkpoints_buf);

  tmp = __xstat64(3, (char const   *)__path, (struct stat64 *)__statbuf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "44", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) lstat64)(char const   * __restrict  __path ,
                                                                                                                                struct stat64 * __restrict  __statbuf ) ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(1,2))) lstat64)(char const   * __restrict  __path ,
                                                                                                  struct stat64 * __restrict  __statbuf ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "46", "tmp", checkpoints_buf);

  tmp = __lxstat64(3, (char const   *)__path, (struct stat64 *)__statbuf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "46", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) fstat64)(int __fd ,
                                                                                                                              struct stat64 *__statbuf ) ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2))) fstat64)(int __fd ,
                                                                                                struct stat64 *__statbuf ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "48", "tmp", checkpoints_buf);

  tmp = __fxstat64(3, __fd, __statbuf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "48", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
__inline extern  __attribute__((__nothrow__)) int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2,3))) fstatat64)(int __fd ,
                                                                                                                                  char const   * __restrict  __filename ,
                                                                                                                                  struct stat64 * __restrict  __statbuf ,
                                                                                                                                  int __flag ) ;
__inline extern int __attribute__((__gnu_inline__))  ( __attribute__((__nonnull__(2,3))) fstatat64)(int __fd ,
                                                                                                    char const   * __restrict  __filename ,
                                                                                                    struct stat64 * __restrict  __statbuf ,
                                                                                                    int __flag ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "50", "tmp", checkpoints_buf);

  tmp = __fxstatat64(3, __fd, (char const   *)__filename,
                     (struct stat64 *)__statbuf, __flag);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "50", "tmp", checkpoints_buf);

  return ((int __attribute__((__gnu_inline__))  )tmp);
}
}
extern  __attribute__((__nothrow__)) int *__errno_location(void)  __attribute__((__const__)) ;
extern char *program_invocation_name ;
extern char *program_invocation_short_name ;
extern void close_stdin_set_file_name(char const   *file ) ;
extern void close_stdin(void) ;
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
extern int rpl_fseeko(FILE *fp , off_t offset , int whence ) ;
extern int rpl_fflush(FILE *gl_stream ) ;
extern int fpurge(FILE *gl_stream ) ;
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
int method ;
uch inbuf[32832]  ;
uch outbuf[18432]  ;
ush d_buf[32768]  ;
uch window[65536L]  ;
ush prev[1L << 16]  ;
unsigned int insize  ;
unsigned int inptr  ;
unsigned int outcnt  ;
off_t bytes_in  ;
off_t bytes_out  ;
extern off_t header_bytes ;
int ifd  ;
int ofd  ;
char ifname[1024]  ;
char ofname[1024]  ;
char *program_name  ;
struct timespec time_stamp  ;
off_t ifile_size  ;
extern int decrypt ;
int exit_code ;
int verbose ;
int quiet ;
int level ;
int test ;
int to_stdout ;
int save_orig_name  ;
extern int zip(int in , int out ) ;
extern int file_read(char *buf , unsigned int size ) ;
extern int unzip(int in , int out ) ;
extern int check_zipfile(int in ) ;
extern int unpack(int in , int out ) ;
extern int unlzh(int in , int out ) ;
 __attribute__((__noreturn__)) void abort_gzip(void) ;
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
extern  __attribute__((__noreturn__)) void gzip_error(char *m ) ;
extern  __attribute__((__noreturn__)) void xalloc_die(void) ;
extern void warning(char *m ) ;
extern void read_error(void) ;
extern void write_error(void) ;
extern void display_ratio(off_t num , off_t den , FILE *file ) ;
extern void fprint_off(FILE * , off_t  , int  ) ;
extern int inflate(void) ;
extern int yesno(void) ;
int maxbits ;
extern int block_mode ;
extern int lzw(int in , int out ) ;
extern int unlzw(int in , int out ) ;
extern int open_safer(char const   * , int   , ...) ;
extern int creat_safer(char const   * , mode_t  ) ;
extern char *optarg ;
extern int optind ;
extern int opterr ;
extern int optopt ;
extern  __attribute__((__nothrow__)) int getopt(int ___argc ,
                                                char * const  *___argv ,
                                                char const   *__shortopts ) ;
extern  __attribute__((__nothrow__)) int getopt_long(int ___argc ,
                                                     char * const  *___argv ,
                                                     char const   *__shortopts ,
                                                     struct option  const  *__longopts ,
                                                     int *__longind ) ;
extern  __attribute__((__nothrow__)) int getopt_long_only(int ___argc ,
                                                          char * const  *___argv ,
                                                          char const   *__shortopts ,
                                                          struct option  const  *__longopts ,
                                                          int *__longind ) ;
__inline static long get_stat_atime_ns(struct stat  const  *st ) 
{ 


  {
  return ((long )st->st_atim.tv_nsec);
}
}
__inline static long get_stat_ctime_ns(struct stat  const  *st ) 
{ 


  {
  return ((long )st->st_ctim.tv_nsec);
}
}
__inline static long get_stat_mtime_ns(struct stat  const  *st ) 
{ 


  {
  return ((long )st->st_mtim.tv_nsec);
}
}
__inline static long get_stat_birthtime_ns(struct stat  const  *st ) 
{ 


  {
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "296", "0", checkpoints_buf);
  return (0L);
}
}
__inline static struct timespec get_stat_atime(struct stat  const  *st ) 
{ 


  {
  return ((struct timespec )st->st_atim);
}
}
__inline static struct timespec get_stat_ctime(struct stat  const  *st ) 
{ 


  {
  return ((struct timespec )st->st_ctim);
}
}
__inline static struct timespec get_stat_mtime(struct stat  const  *st ) 
{ 


  {
  return ((struct timespec )st->st_mtim);
}
}
__inline static struct timespec get_stat_birthtime(struct stat  const  *st ) 
{ 
  struct timespec t ;

  {
  t.tv_sec = (__time_t )-1;

  t.tv_nsec = -1L;


  return (t);
}
}
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) access)(char const   *__name ,
                                                                                   int __type ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) euidaccess)(char const   *__name ,
                                                                                       int __type ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) eaccess)(char const   *__name ,
                                                                                    int __type ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(2))) faccessat)(int __fd ,
                                                                                      char const   *__file ,
                                                                                      int __type ,
                                                                                      int __flag ) ;
extern  __attribute__((__nothrow__)) __off64_t lseek(int __fd ,
                                                     __off64_t __offset ,
                                                     int __whence )  __asm__("lseek64")  ;
extern  __attribute__((__nothrow__)) __off64_t lseek64(int __fd ,
                                                       __off64_t __offset ,
                                                       int __whence ) ;
extern int close(int __fd ) ;
extern ssize_t read(int __fd , void *__buf , size_t __nbytes ) ;
extern ssize_t write(int __fd , void const   *__buf , size_t __n ) ;
extern ssize_t pread(int __fd , void *__buf , size_t __nbytes ,
                     __off64_t __offset )  __asm__("pread64")  ;
extern ssize_t pwrite(int __fd , void const   *__buf , size_t __nbytes ,
                      __off64_t __offset )  __asm__("pwrite64")  ;
extern ssize_t pread64(int __fd , void *__buf , size_t __nbytes ,
                       __off64_t __offset ) ;
extern ssize_t pwrite64(int __fd , void const   *__buf , size_t __n ,
                        __off64_t __offset ) ;
extern  __attribute__((__nothrow__)) int pipe(int *__pipedes ) ;
extern  __attribute__((__nothrow__)) int pipe2(int *__pipedes , int __flags ) ;
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
extern  __attribute__((__nothrow__)) char *get_current_dir_name(void) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1))) getwd)(char *__buf )  __attribute__((__deprecated__)) ;
extern  __attribute__((__nothrow__)) int dup(int __fd ) ;
extern  __attribute__((__nothrow__)) int dup2(int __fd , int __fd2 ) ;
extern  __attribute__((__nothrow__)) int dup3(int __fd , int __fd2 ,
                                              int __flags ) ;
extern char **__environ ;
extern char **environ ;
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
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) execvpe)(char const   *__file ,
                                                                                      char * const  *__argv ,
                                                                                      char * const  *__envp ) ;
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
extern  __attribute__((__nothrow__)) int group_member(__gid_t __gid ) ;
extern  __attribute__((__nothrow__)) int setuid(__uid_t __uid ) ;
extern  __attribute__((__nothrow__)) int setreuid(__uid_t __ruid ,
                                                  __uid_t __euid ) ;
extern  __attribute__((__nothrow__)) int seteuid(__uid_t __uid ) ;
extern  __attribute__((__nothrow__)) int setgid(__gid_t __gid ) ;
extern  __attribute__((__nothrow__)) int setregid(__gid_t __rgid ,
                                                  __gid_t __egid ) ;
extern  __attribute__((__nothrow__)) int setegid(__gid_t __gid ) ;
extern  __attribute__((__nothrow__)) int getresuid(__uid_t *__ruid ,
                                                   __uid_t *__euid ,
                                                   __uid_t *__suid ) ;
extern  __attribute__((__nothrow__)) int getresgid(__gid_t *__rgid ,
                                                   __gid_t *__egid ,
                                                   __gid_t *__sgid ) ;
extern  __attribute__((__nothrow__)) int setresuid(__uid_t __ruid ,
                                                   __uid_t __euid ,
                                                   __uid_t __suid ) ;
extern  __attribute__((__nothrow__)) int setresgid(__gid_t __rgid ,
                                                   __gid_t __egid ,
                                                   __gid_t __sgid ) ;
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
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) truncate64)(char const   *__file ,
                                                                                       __off64_t __length ) ;
extern  __attribute__((__nothrow__)) int ftruncate(int __fd ,
                                                   __off64_t __length )  __asm__("ftruncate64")  ;
extern  __attribute__((__nothrow__)) int ftruncate64(int __fd ,
                                                     __off64_t __length ) ;
extern  __attribute__((__nothrow__)) int brk(void *__addr ) ;
extern  __attribute__((__nothrow__)) void *sbrk(intptr_t __delta ) ;
extern  __attribute__((__nothrow__)) long syscall(long __sysno  , ...) ;
extern int lockf(int __fd , int __cmd , __off64_t __len )  __asm__("lockf64")  ;
extern int lockf64(int __fd , int __cmd , __off64_t __len ) ;
extern int fdatasync(int __fildes ) ;
extern  __attribute__((__nothrow__)) char *( __attribute__((__nonnull__(1,2))) crypt)(char const   *__key ,
                                                                                      char const   *__salt ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1))) encrypt)(char *__block ,
                                                                                     int __edflag ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) a64l)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *alloca(size_t __size ) ;
extern int ( __attribute__((__nonnull__(1))) mkstemps64)(char *__template ,
                                                         int __suffixlen ) ;
extern int ( __attribute__((__nonnull__(1))) mkostemps64)(char *__template ,
                                                          int __suffixlen ,
                                                          int __flags ) ;
extern  __attribute__((__nothrow__)) ssize_t readahead(int __fd ,
                                                       __off64_t __offset ,
                                                       size_t __count ) ;
extern int sync_file_range(int __fd , __off64_t __offset , __off64_t __count ,
                           unsigned int __flags ) ;
extern ssize_t vmsplice(int __fdout , struct iovec  const  *__iov ,
                        size_t __count , unsigned int __flags ) ;
extern ssize_t splice(int __fdin , __off64_t *__offin , int __fdout ,
                      __off64_t *__offout , size_t __len , unsigned int __flags ) ;
extern ssize_t tee(int __fdin , int __fdout , size_t __len ,
                   unsigned int __flags ) ;
extern int fallocate(int __fd , int __mode , __off64_t __offset ,
                     __off64_t __len )  __asm__("fallocate64")  ;
extern int fallocate64(int __fd , int __mode , __off64_t __offset ,
                       __off64_t __len ) ;
extern int fcntl(int __fd , int __cmd  , ...) ;
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file ,
                                                   int __oflag  , ...)  __asm__("open64")  ;
extern int ( __attribute__((__nonnull__(1))) open64)(char const   *__file ,
                                                     int __oflag  , ...) ;
extern int ( __attribute__((__nonnull__(2))) openat)(int __fd ,
                                                     char const   *__file ,
                                                     int __oflag  , ...)  __asm__("openat64")  ;
extern int ( __attribute__((__nonnull__(2))) openat64)(int __fd ,
                                                       char const   *__file ,
                                                       int __oflag  , ...) ;
extern int ( __attribute__((__nonnull__(1))) creat)(char const   *__file ,
                                                    __mode_t __mode )  __asm__("creat64")  ;
extern int ( __attribute__((__nonnull__(1))) creat64)(char const   *__file ,
                                                      __mode_t __mode ) ;
extern  __attribute__((__nothrow__)) int posix_fadvise(int __fd ,
                                                       __off64_t __offset ,
                                                       __off64_t __len ,
                                                       int __advise )  __asm__("posix_fadvise64")  ;
extern  __attribute__((__nothrow__)) int posix_fadvise64(int __fd ,
                                                         __off64_t __offset ,
                                                         __off64_t __len ,
                                                         int __advise ) ;
extern int posix_fallocate(int __fd , __off64_t __offset , __off64_t __len )  __asm__("posix_fallocate64")  ;
extern int posix_fallocate64(int __fd , __off64_t __offset , __off64_t __len ) ;
extern DIR *( __attribute__((__nonnull__(1))) opendir)(char const   *__name ) ;
extern DIR *fdopendir(int __fd ) ;
extern int ( __attribute__((__nonnull__(1))) closedir)(DIR *__dirp ) ;
extern struct dirent *( __attribute__((__nonnull__(1))) readdir)(DIR *__dirp )  __asm__("readdir64")  ;
extern struct dirent64 *( __attribute__((__nonnull__(1))) readdir64)(DIR *__dirp ) ;
extern int ( __attribute__((__nonnull__(1,2,3))) readdir_r)(DIR * __restrict  __dirp ,
                                                            struct dirent * __restrict  __entry ,
                                                            struct dirent ** __restrict  __result )  __asm__("readdir64_r")  ;
extern int ( __attribute__((__nonnull__(1,2,3))) readdir64_r)(DIR * __restrict  __dirp ,
                                                              struct dirent64 * __restrict  __entry ,
                                                              struct dirent64 ** __restrict  __result ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1))) rewinddir)(DIR *__dirp ) ;
extern  __attribute__((__nothrow__)) void ( __attribute__((__nonnull__(1))) seekdir)(DIR *__dirp ,
                                                                                     long __pos ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) telldir)(DIR *__dirp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) dirfd)(DIR *__dirp ) ;
extern int ( __attribute__((__nonnull__(1,2))) scandir)(char const   * __restrict  __dir ,
                                                        struct dirent *** __restrict  __namelist ,
                                                        int (*__selector)(struct dirent  const  * ) ,
                                                        int (*__cmp)(struct dirent  const  ** ,
                                                                     struct dirent  const  ** ) )  __asm__("scandir64")  ;
extern int ( __attribute__((__nonnull__(1,2))) scandir64)(char const   * __restrict  __dir ,
                                                          struct dirent64 *** __restrict  __namelist ,
                                                          int (*__selector)(struct dirent64  const  * ) ,
                                                          int (*__cmp)(struct dirent64  const  ** ,
                                                                       struct dirent64  const  ** ) ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) alphasort)(struct dirent  const  **__e1 ,
                                                                                        struct dirent  const  **__e2 )  __asm__("alphasort64") __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) alphasort64)(struct dirent64  const  **__e1 ,
                                                                                          struct dirent64  const  **__e2 )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) __ssize_t ( __attribute__((__nonnull__(2,4))) getdirentries)(int __fd ,
                                                                                                  char * __restrict  __buf ,
                                                                                                  size_t __nbytes ,
                                                                                                  __off64_t * __restrict  __basep )  __asm__("getdirentries64")  ;
extern  __attribute__((__nothrow__)) __ssize_t ( __attribute__((__nonnull__(2,4))) getdirentries64)(int __fd ,
                                                                                                    char * __restrict  __buf ,
                                                                                                    size_t __nbytes ,
                                                                                                    __off64_t * __restrict  __basep ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) versionsort)(struct dirent  const  **__e1 ,
                                                                                          struct dirent  const  **__e2 )  __asm__("versionsort64") __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1,2))) versionsort64)(struct dirent64  const  **__e1 ,
                                                                                            struct dirent64  const  **__e2 )  __attribute__((__pure__)) ;
extern int gl_futimens(int  , char const   * , struct timespec  const  * ) ;
extern int utimens(char const   * , struct timespec  const  * ) ;
int ascii  =    0;
int to_stdout  =    0;
int decompress  =    0;
int force  =    0;
int no_name  =    -1;
int no_time  =    -1;
int recursive  =    0;
int list  =    0;
int verbose  =    0;
int quiet  =    0;
int do_lzw  =    0;
int test  =    0;
int foreground  =    0;
int maxbits  =    16;
int method  =    8;
int level  =    6;
int exit_code  =    0;
int last_member  ;
int part_nb  ;
char *env  ;
char **args  =    (char **)((void *)0);
char *z_suffix  ;
size_t z_len  ;
static sigset_t caught_signals  ;
static int volatile   exiting_signal  ;
static int volatile   remove_ofname_fd  =    (int volatile   )-1;
off_t total_in  ;
off_t total_out  ;
struct stat istat  ;
static int handled_sig[6]  = {      2,      1,      13,      15, 
        24,      25};
struct option longopts[24]  = 
  {      {"ascii", 0, (int *)0, 'a'}, 
        {"to-stdout", 0, (int *)0, 'c'}, 
        {"stdout", 0, (int *)0, 'c'}, 
        {"decompress", 0, (int *)0, 'd'}, 
        {"uncompress", 0, (int *)0, 'd'}, 
        {"force", 0, (int *)0, 'f'}, 
        {"help", 0, (int *)0, 'h'}, 
        {"list", 0, (int *)0, 'l'}, 
        {"license", 0, (int *)0, 'L'}, 
        {"no-name", 0, (int *)0, 'n'}, 
        {"name", 0, (int *)0, 'N'}, 
        {"quiet", 0, (int *)0, 'q'}, 
        {"silent", 0, (int *)0, 'q'}, 
        {"recursive", 0, (int *)0, 'r'}, 
        {"suffix", 1, (int *)0, 'S'}, 
        {"test", 0, (int *)0, 't'}, 
        {"no-time", 0, (int *)0, 'T'}, 
        {"verbose", 0, (int *)0, 'v'}, 
        {"version", 0, (int *)0, 'V'}, 
        {"fast", 0, (int *)0, '1'}, 
        {"best", 0, (int *)0, '9'}, 
        {"lzw", 0, (int *)0, 'Z'}, 
        {"bits", 1, (int *)0, 'b'}, 
        {(char const   *)0, 0, (int *)0, 0}};
static  __attribute__((__noreturn__)) void try_help(void) ;
static void help(void) ;
static void license(void) ;
static void version(void) ;
static int input_eof(void) ;
static void treat_stdin(void) ;
static void treat_file(char *iname ) ;
static int create_outfile(void) ;
static char *get_suffix(char *name ) ;
static int open_input_file(char *iname , struct stat *sbuf ) ;
static int make_ofname(void) ;
static void shorten_name(char *name ) ;
static int get_method(int in ) ;
static void do_list(int ifd___0 , int method___0 ) ;
static int check_ofname(void) ;
static void copy_stat(struct stat *ifstat ) ;
static void install_signal_handlers(void) ;
static void remove_output_file(void) ;
static void abort_gzip_signal(int sig ) ;
static  __attribute__((__noreturn__)) void do_exit(int exitcode ) ;
int main(int argc , char **argv ) ;
int (*work)(int infile , int outfile )  =    & zip;
static void treat_dir(int fd , char *dir ) ;
static  __attribute__((__noreturn__)) void try_help(void) ;
static void try_help(void) 
{ 


  {

  fprintf((FILE */* __restrict  */)stderr,
          (char const   */* __restrict  */)"Try `%s --help\' for more information.\n",
          program_name);


  do_exit(1);

}
}
static void help(void) ;
static char *help_msg[25]  = 
  {      (char *)"Compress or uncompress FILEs (by default, compress FILES in-place).",      (char *)"",      (char *)"Mandatory arguments to long options are mandatory for short options too.",      (char *)"", 
        (char *)"  -c, --stdout      write on standard output, keep original files unchanged",      (char *)"  -d, --decompress  decompress",      (char *)"  -f, --force       force overwrite of output file and compress links",      (char *)"  -h, --help        give this help", 
        (char *)"  -l, --list        list compressed file contents",      (char *)"  -L, --license     display software license",      (char *)"  -n, --no-name     do not save or restore the original name and time stamp",      (char *)"  -N, --name        save or restore the original name and time stamp", 
        (char *)"  -q, --quiet       suppress all warnings",      (char *)"  -r, --recursive   operate recursively on directories",      (char *)"  -S, --suffix=SUF  use suffix SUF on compressed files",      (char *)"  -t, --test        test compressed file integrity", 
        (char *)"  -v, --verbose     verbose mode",      (char *)"  -V, --version     display version number",      (char *)"  -1, --fast        compress faster",      (char *)"  -9, --best        compress better", 
        (char *)"",      (char *)"With no FILE, or when FILE is -, read standard input.",      (char *)"",      (char *)"Report bugs to <bug-gzip@gnu.org>.", 
        (char *)0};
static void help(void) 
{ 
  char **p ;
  char **tmp ;

  {
  p = help_msg;


  printf((char const   */* __restrict  */)"Usage: %s [OPTION]... [FILE]...\n",
         program_name);





  while (*p) {

    tmp = p;

    p ++;


    printf((char const   */* __restrict  */)"%s\n", *tmp);

  }




  return;
}
}
static void license(void) 
{ 
  char **p ;
  char **tmp ;

  {
  p = license_msg;


  printf((char const   */* __restrict  */)"%s %s\n", program_name,
         "1.3.12.37-a1d3");





  while (*p) {

    tmp = p;

    p ++;


    printf((char const   */* __restrict  */)"%s\n", *tmp);

  }




  return;
}
}
static void version(void) 
{ 


  {

  license();


  printf((char const   */* __restrict  */)"\n");


  printf((char const   */* __restrict  */)"Written by Jean-loup Gailly.\n");

  return;
}
}
static void progerror(char *string ) 
{ 
  int e ;
  int *tmp ;
  int *tmp___0 ;

  {


  tmp = __errno_location();


  e = *tmp;
  sprintf(checkpoints_buf, "%d", e);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "338", "e", checkpoints_buf);

  fprintf((FILE */* __restrict  */)stderr,
          (char const   */* __restrict  */)"%s: ", program_name);



  tmp___0 = __errno_location();


  *tmp___0 = e;


  perror((char const   *)string);

  exit_code = 1;
  sprintf(checkpoints_buf, "%d", exit_code);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "343", "exit_code", checkpoints_buf);
  return;
}
}
int main(int argc , char **argv ) 
{ 
  int file_count ;
  size_t proglen ;
  int optc ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___2 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int __attribute__((__gnu_inline__))  tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;

  {


  program_name = gzip_base_name(*(argv + 0));




  proglen = strlen((char const   *)program_name);



  atexit(& close_stdin);

  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "348", "4", checkpoints_buf);

  if (4U < proglen) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "349", "0", checkpoints_buf);
    if (0) {


      __s1_len = strlen((char const   *)((program_name + proglen) - 4));




      __s2_len = strlen(".exe");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "352", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(((program_name + proglen) - 4) + 1)) - (size_t )((void const   *)((program_name + proglen) - 4)) == 1U)) {
        goto _L___0;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "354", "4", checkpoints_buf);
        if (__s1_len >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "355", "1", checkpoints_buf);
          _L___0: /* CIL Label */ 
          if (! ((size_t )((void const   *)(".exe" + 1)) - (size_t )((void const   *)".exe") == 1U)) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "356", "tmp___5", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "357", "4", checkpoints_buf);
            if (__s2_len >= 4U) {
              tmp___5 = 1;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "358", "tmp___5", checkpoints_buf);
            } else {
              tmp___5 = 0;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "359", "tmp___5", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "357", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "355", "1", checkpoints_buf);
        } else {
          tmp___5 = 0;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "360", "tmp___5", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "354", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "352", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "361", "tmp___5", checkpoints_buf);
      if (tmp___5) {
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "362", "tmp___0", checkpoints_buf);

        tmp___0 = __builtin_strcmp((char const   *)((program_name + proglen) - 4),
                                   ".exe");
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "362", "tmp___0", checkpoints_buf);

        tmp___4 = tmp___0;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "363", "tmp___4", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "364", "tmp___3", checkpoints_buf);

        tmp___3 = __builtin_strcmp((char const   *)((program_name + proglen) - 4),
                                   ".exe");
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "364", "tmp___3", checkpoints_buf);

        tmp___4 = tmp___3;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "365", "tmp___4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "361", "tmp___5", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "366", "tmp___3", checkpoints_buf);

      tmp___3 = __builtin_strcmp((char const   *)((program_name + proglen) - 4),
                                 ".exe");
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "366", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "367", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "349", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "368", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "368", "0", checkpoints_buf);
    if (tmp___4 == 0) {
      *(program_name + (proglen - 4U)) = (char )'\000';

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "368", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "368", "0", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "348", "4", checkpoints_buf);



  env = add_envopt(& argc, & argv, (char *)"GZIP");


  if ((unsigned int )env != (unsigned int )((void *)0)) {
    args = argv;

  } else {

  }
  z_suffix = (char *)".gz";



  z_len = strlen((char const   *)z_suffix);


  sprintf(checkpoints_buf, "%d", optc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "378", "optc", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", optc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "378", "optc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "378", "-1", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", optc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "379", "optc", checkpoints_buf);

    optc = getopt_long(argc, (char * const  *)argv,
                       "ab:cdfhH?lLmMnNqrS:tvVZ123456789",
                       (struct option  const  *)(longopts), (int *)0);
    sprintf(checkpoints_buf, "%d", optc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "379", "optc", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", optc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "380", "optc", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "380", "-1", checkpoints_buf);
    if (optc != -1) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", optc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "380", "optc", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "380", "-1", checkpoints_buf);
    switch (optc) {
    case 97: 
    ascii = 1;
    sprintf(checkpoints_buf, "%d", ascii);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "384", "ascii", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "386", "tmp___6", checkpoints_buf);

    case 98: 
    tmp___6 = atoi((char const   *)optarg);
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "386", "tmp___6", checkpoints_buf);

    maxbits = (int )tmp___6;
    sprintf(checkpoints_buf, "%d", maxbits);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "387", "maxbits", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", 48);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "388", "48", checkpoints_buf);

    while (*optarg) {

      sprintf(checkpoints_buf, "%d", 48);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "392", "48", checkpoints_buf);
      if (48 <= (int )*optarg) {
        sprintf(checkpoints_buf, "%d", 57);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "393", "57", checkpoints_buf);
        if ((int )*optarg <= 57) {

        } else {

          fprintf((FILE */* __restrict  */)stderr,
                  (char const   */* __restrict  */)"%s: -b operand is not an integer\n",
                  program_name);


          try_help();

        }
        sprintf(checkpoints_buf, "%d", 57);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "393", "57", checkpoints_buf);
      } else {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: -b operand is not an integer\n",
                program_name);


        try_help();

      }
      sprintf(checkpoints_buf, "%d", 48);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "392", "48", checkpoints_buf);
      optarg ++;

    }

    sprintf(checkpoints_buf, "%d", 48);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "388", "48", checkpoints_buf);

    break;
    case 99: 
    to_stdout = 1;
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "401", "to_stdout", checkpoints_buf);
    break;
    case 100: 
    decompress = 1;
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "403", "decompress", checkpoints_buf);
    break;
    case 102: 
    force ++;
    sprintf(checkpoints_buf, "%d", force);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "405", "force", checkpoints_buf);
    break;

    case 72: 
    case 104: 
    help();


    do_exit(0);

    break;
    case 108: 
    to_stdout = 1;
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "410", "to_stdout", checkpoints_buf);
    decompress = to_stdout;
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "411", "decompress", checkpoints_buf);
    list = decompress;
    sprintf(checkpoints_buf, "%d", list);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "412", "list", checkpoints_buf);
    break;

    case 76: 
    license();


    do_exit(0);

    break;
    case 109: 
    no_time = 1;
    sprintf(checkpoints_buf, "%d", no_time);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "417", "no_time", checkpoints_buf);
    break;
    case 77: 
    no_time = 0;
    sprintf(checkpoints_buf, "%d", no_time);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "419", "no_time", checkpoints_buf);
    break;
    case 110: 
    no_time = 1;
    sprintf(checkpoints_buf, "%d", no_time);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "421", "no_time", checkpoints_buf);
    no_name = no_time;
    sprintf(checkpoints_buf, "%d", no_name);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "422", "no_name", checkpoints_buf);
    break;
    case 78: 
    no_time = 0;
    sprintf(checkpoints_buf, "%d", no_time);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "424", "no_time", checkpoints_buf);
    no_name = no_time;
    sprintf(checkpoints_buf, "%d", no_name);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "425", "no_name", checkpoints_buf);
    break;
    case 113: 
    quiet = 1;
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "427", "quiet", checkpoints_buf);
    verbose = 0;
    sprintf(checkpoints_buf, "%d", verbose);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "428", "verbose", checkpoints_buf);
    break;
    case 114: 
    recursive = 1;
    sprintf(checkpoints_buf, "%d", recursive);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "430", "recursive", checkpoints_buf);
    break;


    case 83: 
    z_len = strlen((char const   *)optarg);


    z_suffix = optarg;

    break;
    case 116: 
    to_stdout = 1;
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "435", "to_stdout", checkpoints_buf);
    decompress = to_stdout;
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "436", "decompress", checkpoints_buf);
    test = decompress;
    sprintf(checkpoints_buf, "%d", test);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "437", "test", checkpoints_buf);
    break;
    case 118: 
    verbose ++;
    sprintf(checkpoints_buf, "%d", verbose);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "439", "verbose", checkpoints_buf);
    quiet = 0;
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "440", "quiet", checkpoints_buf);
    break;

    case 86: 
    version();


    do_exit(0);

    break;

    case 90: 
    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s: -Z not supported in this version\n",
            program_name);


    try_help();

    break;
    case 57: 
    case 56: 
    case 55: 
    case 54: 
    case 53: 
    case 52: 
    case 51: 
    case 50: 
    case 49: 
    level = optc - 48;
    sprintf(checkpoints_buf, "%d", level);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "448", "level", checkpoints_buf);
    break;

    default: 
    try_help();

    }
  }
  sprintf(checkpoints_buf, "%d", optc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "378", "optc", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", optc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "378", "optc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "378", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", no_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "451", "no_time", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "451", "0", checkpoints_buf);
  if (no_time < 0) {

  } else {

  }
  sprintf(checkpoints_buf, "%d", no_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "451", "no_time", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "451", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", no_name);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "454", "no_name", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "454", "0", checkpoints_buf);
  if (no_name < 0) {
    no_name = decompress;
    sprintf(checkpoints_buf, "%d", no_name);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "455", "no_name", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", no_name);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "454", "no_name", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "454", "0", checkpoints_buf);
  file_count = argc - optind;
  sprintf(checkpoints_buf, "%d", file_count);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "457", "file_count", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", ascii);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "458", "ascii", checkpoints_buf);
  if (ascii) {
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "459", "quiet", checkpoints_buf);
    if (! quiet) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: option --ascii ignored on this system\n",
              program_name);

    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "459", "quiet", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", ascii);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "458", "ascii", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "463", "0", checkpoints_buf);
  if (z_len == 0U) {
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "464", "decompress", checkpoints_buf);
    if (! decompress) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: incorrect suffix \'%s\'\n",
              program_name, z_suffix);


      do_exit(1);

    } else {
      goto _L___1;
    }
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "464", "decompress", checkpoints_buf);
  } else {

    sprintf(checkpoints_buf, "%u", 30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "468", "30", checkpoints_buf);
    _L___1: /* CIL Label */ 
    if (z_len > 30U) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: incorrect suffix \'%s\'\n",
              program_name, z_suffix);


      do_exit(1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "468", "30", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "463", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", do_lzw);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "472", "do_lzw", checkpoints_buf);
  if (do_lzw) {
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "473", "decompress", checkpoints_buf);
    if (! decompress) {
      work = & lzw;

    } else {

    }
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "473", "decompress", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", do_lzw);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "472", "do_lzw", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", quiet);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "477", "quiet", checkpoints_buf);
  if (quiet) {
    exiting_signal = (int volatile   )13;
    sprintf(checkpoints_buf, "%d", exiting_signal);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "478", "exiting_signal", checkpoints_buf);
  } else {
    exiting_signal = (int volatile   )0;
    sprintf(checkpoints_buf, "%d", exiting_signal);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "479", "exiting_signal", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", quiet);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "477", "quiet", checkpoints_buf);

  install_signal_handlers();

  sprintf(checkpoints_buf, "%d", file_count);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "481", "file_count", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "481", "0", checkpoints_buf);
  if (file_count != 0) {
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "482", "to_stdout", checkpoints_buf);
    if (to_stdout) {
      sprintf(checkpoints_buf, "%d", test);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "483", "test", checkpoints_buf);
      if (! test) {
        sprintf(checkpoints_buf, "%d", list);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "484", "list", checkpoints_buf);
        if (! list) {
          sprintf(checkpoints_buf, "%d", decompress);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "485", "decompress", checkpoints_buf);
          if (! decompress) {
            tmp___7 = 1;
            sprintf(checkpoints_buf, "%d", tmp___7);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "486", "tmp___7", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", ascii);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "487", "ascii", checkpoints_buf);
            if (! ascii) {
              tmp___7 = 1;
              sprintf(checkpoints_buf, "%d", tmp___7);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "488", "tmp___7", checkpoints_buf);
            } else {
              tmp___7 = 0;
              sprintf(checkpoints_buf, "%d", tmp___7);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "489", "tmp___7", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", ascii);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "487", "ascii", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", decompress);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "485", "decompress", checkpoints_buf);
        } else {
          tmp___7 = 0;
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "490", "tmp___7", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", list);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "484", "list", checkpoints_buf);
      } else {
        tmp___7 = 0;
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "491", "tmp___7", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", test);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "483", "test", checkpoints_buf);
    } else {
      tmp___7 = 0;
      sprintf(checkpoints_buf, "%d", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "492", "tmp___7", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "482", "to_stdout", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "optind", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", argc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "argc", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "optind", checkpoints_buf);

    while (1) {
      sprintf(checkpoints_buf, "%d", optind);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "494", "optind", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", argc);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "494", "argc", checkpoints_buf);
      if (optind < argc) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%d", optind);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "494", "optind", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", argc);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "494", "argc", checkpoints_buf);
      tmp___8 = optind;
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "497", "tmp___8", checkpoints_buf);
      optind ++;
      sprintf(checkpoints_buf, "%d", optind);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "498", "optind", checkpoints_buf);

      treat_file(*(argv + tmp___8));

    }
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "optind", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", argc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "argc", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "493", "optind", checkpoints_buf);

  } else {

    treat_stdin();

  }
  sprintf(checkpoints_buf, "%d", file_count);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "481", "file_count", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "481", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", list);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "501", "list", checkpoints_buf);
  if (list) {
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "502", "quiet", checkpoints_buf);
    if (! quiet) {
      sprintf(checkpoints_buf, "%d", file_count);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "503", "file_count", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "503", "1", checkpoints_buf);
      if (file_count > 1) {

        do_list(-1, -1);

      } else {

      }
      sprintf(checkpoints_buf, "%d", file_count);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "503", "file_count", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "503", "1", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "502", "quiet", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", list);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "501", "list", checkpoints_buf);

  do_exit(exit_code);

  sprintf(checkpoints_buf, "%d", exit_code);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "509", "exit_code", checkpoints_buf);
  return (exit_code);
}
}
static int input_eof(void) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "510", "decompress", checkpoints_buf);
  if (! decompress) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "511", "1", checkpoints_buf);
    return (1);
  } else {
    sprintf(checkpoints_buf, "%d", last_member);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "512", "last_member", checkpoints_buf);
    if (last_member) {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "513", "1", checkpoints_buf);
      return (1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", last_member);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "512", "last_member", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "510", "decompress", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "515", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "515", "insize", checkpoints_buf);
  if (inptr == insize) {
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "516", "insize", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 32768);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "516", "32768", checkpoints_buf);
    if (insize != 32768U) {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "517", "1", checkpoints_buf);
      return (1);
    } else {
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "518", "tmp", checkpoints_buf);

      tmp = fill_inbuf(1);
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "518", "tmp", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "519", "tmp", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "519", "-1", checkpoints_buf);
      if (tmp == -1) {
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "520", "1", checkpoints_buf);
        return (1);
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "519", "tmp", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "519", "-1", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "516", "insize", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 32768);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "516", "32768", checkpoints_buf);
    inptr = 0U;
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "522", "inptr", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%u", inptr);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "515", "inptr", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", insize);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "515", "insize", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "524", "0", checkpoints_buf);
  return (0);
}
}
static void treat_stdin(void) 
{ 
  char const   *tmp ;
  char const   *tmp___0 ;
  struct _IO_FILE *tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int __attribute__((__gnu_inline__))  tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;

  {
  sprintf(checkpoints_buf, "%d", force);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "525", "force", checkpoints_buf);
  if (! force) {
    if (! list) {
      if (! decompress) {
        tmp___5 = 1;
      } else
      if (! ascii) {
        tmp___5 = 1;
      } else {
        tmp___5 = 0;
      }
    } else {
      tmp___5 = 0;
    }
  } else {

  }
  sprintf(checkpoints_buf, "%d", force);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "525", "force", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "545", "decompress", checkpoints_buf);
  if (decompress) {
    tmp___4 = 1;
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "546", "tmp___4", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", ascii);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "547", "ascii", checkpoints_buf);
    if (! ascii) {
      tmp___4 = 1;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "548", "tmp___4", checkpoints_buf);
    } else {
      tmp___4 = 0;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "549", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", ascii);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "547", "ascii", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "545", "decompress", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", test);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "550", "test", checkpoints_buf);
  if (! test) {
    if (! list) {
      if (decompress) {
        tmp___1 = stdin;
      } else {
        tmp___1 = stdout;
      }
      tmp___2 = fileno(tmp___1);
      tmp___3 = isatty(tmp___2);
      if (tmp___3) {
        if (decompress) {
          tmp = "de";
        } else {
          tmp = "";
        }
        if (decompress) {
          tmp___0 = "read from";
        } else {
          tmp___0 = "written to";
        }
        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: compressed data not %s a terminal. Use -f to force %scompression.\n",
                program_name, tmp___0, tmp);
        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"For help, type: %s -h\n",
                program_name);
        do_exit(1);
      } else {

      }
    } else {

    }
  } else {
    tmp___5 = 0;
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "558", "tmp___5", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", test);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "550", "test", checkpoints_buf);

  strcpy((char */* __restrict  */)(ifname),
         (char const   */* __restrict  */)"stdin");


  strcpy((char */* __restrict  */)(ofname),
         (char const   */* __restrict  */)"stdout");

  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "561", "tmp___6", checkpoints_buf);

  tmp___6 = fileno(stdin);
  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "561", "tmp___6", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "562", "tmp___7", checkpoints_buf);

  tmp___7 = fstat(tmp___6, & istat);
  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "562", "tmp___7", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "563", "tmp___7", checkpoints_buf);
  if (tmp___7 != (int __attribute__((__gnu_inline__))  )0) {

    progerror((char *)"standard input");


    do_exit(1);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "563", "tmp___7", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 61440);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "567", "61440", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "567", "32768", checkpoints_buf);
  if ((istat.st_mode & 61440U) == 32768U) {
    ifile_size = istat.st_size;

  } else {
    ifile_size = (off_t )-1;

  }

  sprintf(checkpoints_buf, "%u", 61440);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "567", "61440", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "567", "32768", checkpoints_buf);
  time_stamp.tv_nsec = -1L;

  sprintf(checkpoints_buf, "%d", no_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "571", "no_time", checkpoints_buf);
  if (! no_time) {


    time_stamp = get_stat_mtime((struct stat  const  *)(& istat));


  } else {
    sprintf(checkpoints_buf, "%d", list);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "573", "list", checkpoints_buf);
    if (list) {


      time_stamp = get_stat_mtime((struct stat  const  *)(& istat));


    } else {

    }
    sprintf(checkpoints_buf, "%d", list);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "573", "list", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", no_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "571", "no_time", checkpoints_buf);

  clear_bufs();

  to_stdout = 1;
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "577", "to_stdout", checkpoints_buf);
  {
  part_nb = 0;
  sprintf(checkpoints_buf, "%d", part_nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "578", "part_nb", checkpoints_buf);

  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "579", "decompress", checkpoints_buf);
  if (decompress) {
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "580", "method", checkpoints_buf);

    method = get_method(ifd);
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "580", "method", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "581", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "581", "0", checkpoints_buf);
    if (method < 0) {

      do_exit(exit_code);

    } else {

    }
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "581", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "581", "0", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "579", "decompress", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", list);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "585", "list", checkpoints_buf);
  if (list) {

    do_list(ifd, method);

    return;
  } else {

  }
  sprintf(checkpoints_buf, "%d", list);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "585", "list", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___8", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___9", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___10", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___11", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___11", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "method", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "0", checkpoints_buf);

  while (1) {
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "590", "tmp___8", checkpoints_buf);

    tmp___8 = fileno(stdout);
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "590", "tmp___8", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "591", "tmp___9", checkpoints_buf);

    tmp___9 = fileno(stdin);
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "591", "tmp___9", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "592", "tmp___10", checkpoints_buf);

    tmp___10 = (*work)(tmp___9, tmp___8);
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "592", "tmp___10", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "593", "tmp___10", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "593", "0", checkpoints_buf);
    if (tmp___10 != 0) {
      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "593", "tmp___10", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "593", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "596", "tmp___11", checkpoints_buf);

    tmp___11 = input_eof();
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "596", "tmp___11", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "597", "tmp___11", checkpoints_buf);
    if (tmp___11) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "597", "tmp___11", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "600", "method", checkpoints_buf);

    method = get_method(ifd);
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "600", "method", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "601", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "601", "0", checkpoints_buf);
    if (method < 0) {
      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "601", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "601", "0", checkpoints_buf);
    bytes_out = (off_t )0;

  }
  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___8", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___9", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___10", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___11", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "tmp___11", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "method", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "589", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "605", "verbose", checkpoints_buf);
  if (verbose) {
    sprintf(checkpoints_buf, "%d", test);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "606", "test", checkpoints_buf);
    if (test) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)" OK\n");

    } else {
      sprintf(checkpoints_buf, "%d", decompress);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "608", "decompress", checkpoints_buf);
      if (! decompress) {

        display_ratio(bytes_in - (bytes_out - header_bytes), bytes_in, stderr);


        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"\n");

      } else {

      }
      sprintf(checkpoints_buf, "%d", decompress);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "608", "decompress", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", test);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "606", "test", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "605", "verbose", checkpoints_buf);
  return;
}
}
static void treat_file(char *iname ) 
{ 
  int cflag ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___2 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
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
  sigset_t oldset ;
  int unlink_errno ;
  int tmp___13 ;
  int tmp___14 ;
  int *tmp___15 ;
  int tmp___16 ;
  int *tmp___17 ;

  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "614", "0", checkpoints_buf);
  if (0) {


    __s1_len = strlen((char const   *)iname);




    __s2_len = strlen("-");


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "617", "1", checkpoints_buf);
    if (! ((size_t )((void const   *)(iname + 1)) - (size_t )((void const   *)iname) == 1U)) {
      goto _L___0;
    } else {

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "619", "4", checkpoints_buf);
      if (__s1_len >= 4U) {
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "620", "1", checkpoints_buf);
        _L___0: /* CIL Label */ 
        if (! ((size_t )((void const   *)("-" + 1)) - (size_t )((void const   *)"-") == 1U)) {
          tmp___5 = 1;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "621", "tmp___5", checkpoints_buf);
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "622", "4", checkpoints_buf);
          if (__s2_len >= 4U) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "623", "tmp___5", checkpoints_buf);
          } else {
            tmp___5 = 0;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "624", "tmp___5", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "622", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "620", "1", checkpoints_buf);
      } else {
        tmp___5 = 0;
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "625", "tmp___5", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "619", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "617", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "626", "tmp___5", checkpoints_buf);
    if (tmp___5) {
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "627", "tmp___0", checkpoints_buf);

      tmp___0 = __builtin_strcmp((char const   *)iname, "-");
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "627", "tmp___0", checkpoints_buf);

      tmp___4 = tmp___0;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "628", "tmp___4", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "629", "tmp___3", checkpoints_buf);

      tmp___3 = __builtin_strcmp((char const   *)iname, "-");
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "629", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "630", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "626", "tmp___5", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "631", "tmp___3", checkpoints_buf);

    tmp___3 = __builtin_strcmp((char const   *)iname, "-");
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "631", "tmp___3", checkpoints_buf);

    tmp___4 = tmp___3;
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "632", "tmp___4", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "614", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "633", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "633", "0", checkpoints_buf);
  if (tmp___4 == 0) {
    cflag = to_stdout;
    sprintf(checkpoints_buf, "%d", cflag);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "634", "cflag", checkpoints_buf);

    treat_stdin();

    to_stdout = cflag;
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "636", "to_stdout", checkpoints_buf);
    return;
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "633", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "633", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", ifd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "639", "ifd", checkpoints_buf);

  ifd = open_input_file(iname, & istat);
  sprintf(checkpoints_buf, "%d", ifd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "639", "ifd", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", ifd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "640", "ifd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "640", "0", checkpoints_buf);
  if (ifd < 0) {
    return;
  } else {

  }
  sprintf(checkpoints_buf, "%d", ifd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "640", "ifd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "640", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 61440);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "643", "61440", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16384);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "643", "16384", checkpoints_buf);
  if ((istat.st_mode & 61440U) == 16384U) {
    sprintf(checkpoints_buf, "%d", recursive);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "644", "recursive", checkpoints_buf);
    if (recursive) {

      treat_dir(ifd, iname);

      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", recursive);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "644", "recursive", checkpoints_buf);

    close(ifd);

    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "649", "quiet", checkpoints_buf);
    if (! quiet) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: %s is a directory -- ignored\n",
              program_name, ifname);

    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "649", "quiet", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "652", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "652", "0", checkpoints_buf);
    if (exit_code == 0) {
      exit_code = 2;
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "653", "exit_code", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "652", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "652", "0", checkpoints_buf);
    return;
  } else {

  }

  sprintf(checkpoints_buf, "%u", 61440);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "643", "61440", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 16384);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "643", "16384", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "657", "to_stdout", checkpoints_buf);
  if (! to_stdout) {

    sprintf(checkpoints_buf, "%u", 61440);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "658", "61440", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 32768);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "658", "32768", checkpoints_buf);
    if (! ((istat.st_mode & 61440U) == 32768U)) {
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "659", "quiet", checkpoints_buf);
      if (! quiet) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s is not a directory or a regular file - ignored\n",
                program_name, ifname);

      } else {

      }
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "659", "quiet", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "662", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "662", "0", checkpoints_buf);
      if (exit_code == 0) {
        exit_code = 2;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "663", "exit_code", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "662", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "662", "0", checkpoints_buf);

      close(ifd);

      return;
    } else {

    }

    sprintf(checkpoints_buf, "%u", 61440);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "658", "61440", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 32768);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "658", "32768", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 2048);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "668", "2048", checkpoints_buf);
    if (istat.st_mode & 2048U) {
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "669", "quiet", checkpoints_buf);
      if (! quiet) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s is set-user-ID on execution - ignored\n",
                program_name, ifname);

      } else {

      }
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "669", "quiet", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "672", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "672", "0", checkpoints_buf);
      if (exit_code == 0) {
        exit_code = 2;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "673", "exit_code", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "672", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "672", "0", checkpoints_buf);

      close(ifd);

      return;
    } else {

    }

    sprintf(checkpoints_buf, "%u", 2048);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "668", "2048", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "678", "1024", checkpoints_buf);
    if (istat.st_mode & 1024U) {
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "679", "quiet", checkpoints_buf);
      if (! quiet) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s is set-group-ID on execution - ignored\n",
                program_name, ifname);

      } else {

      }
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "679", "quiet", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "682", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "682", "0", checkpoints_buf);
      if (exit_code == 0) {
        exit_code = 2;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "683", "exit_code", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "682", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "682", "0", checkpoints_buf);

      close(ifd);

      return;
    } else {

    }

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "678", "1024", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", force);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "688", "force", checkpoints_buf);
    if (! force) {

      sprintf(checkpoints_buf, "%u", 512);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "689", "512", checkpoints_buf);
      if (istat.st_mode & 512U) {
        sprintf(checkpoints_buf, "%d", quiet);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "690", "quiet", checkpoints_buf);
        if (! quiet) {

          fprintf((FILE */* __restrict  */)stderr,
                  (char const   */* __restrict  */)"%s: %s has the sticky bit set - file ignored\n",
                  program_name, ifname);

        } else {

        }
        sprintf(checkpoints_buf, "%d", quiet);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "690", "quiet", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "693", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "693", "0", checkpoints_buf);
        if (exit_code == 0) {
          exit_code = 2;
          sprintf(checkpoints_buf, "%d", exit_code);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "694", "exit_code", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "693", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "693", "0", checkpoints_buf);

        close(ifd);

        return;
      } else {

      }

      sprintf(checkpoints_buf, "%u", 512);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "689", "512", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "699", "2", checkpoints_buf);

      if (2U <= istat.st_nlink) {
        sprintf(checkpoints_buf, "%d", quiet);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "700", "quiet", checkpoints_buf);
        if (! quiet) {

          sprintf(checkpoints_buf, "%u", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "701", "2", checkpoints_buf);
          if (istat.st_nlink == 2U) {
            tmp___6 = ' ';
            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "702", "tmp___6", checkpoints_buf);
          } else {
            tmp___6 = 's';
            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "703", "tmp___6", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "701", "2", checkpoints_buf);

          fprintf((FILE */* __restrict  */)stderr,
                  (char const   */* __restrict  */)"%s: %s has %lu other link%c -- unchanged\n",
                  program_name, ifname, (unsigned long )istat.st_nlink - 1UL,
                  tmp___6);

        } else {

        }
        sprintf(checkpoints_buf, "%d", quiet);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "700", "quiet", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "706", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "706", "0", checkpoints_buf);
        if (exit_code == 0) {
          exit_code = 2;
          sprintf(checkpoints_buf, "%d", exit_code);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "707", "exit_code", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "706", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "706", "0", checkpoints_buf);

        close(ifd);

        return;
      } else {

      }
      sprintf(checkpoints_buf, "%u", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "699", "2", checkpoints_buf);

    } else {

    }
    sprintf(checkpoints_buf, "%d", force);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "688", "force", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "657", "to_stdout", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 61440);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "714", "61440", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "714", "32768", checkpoints_buf);
  if ((istat.st_mode & 61440U) == 32768U) {
    ifile_size = istat.st_size;

  } else {
    ifile_size = (off_t )-1;

  }

  sprintf(checkpoints_buf, "%u", 61440);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "714", "61440", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 32768);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "714", "32768", checkpoints_buf);
  time_stamp.tv_nsec = -1L;

  sprintf(checkpoints_buf, "%d", no_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "718", "no_time", checkpoints_buf);
  if (! no_time) {


    time_stamp = get_stat_mtime((struct stat  const  *)(& istat));


  } else {
    sprintf(checkpoints_buf, "%d", list);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "720", "list", checkpoints_buf);
    if (list) {


      time_stamp = get_stat_mtime((struct stat  const  *)(& istat));


    } else {

    }
    sprintf(checkpoints_buf, "%d", list);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "720", "list", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", no_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "718", "no_time", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "723", "to_stdout", checkpoints_buf);
  if (to_stdout) {
    sprintf(checkpoints_buf, "%d", list);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "724", "list", checkpoints_buf);
    if (! list) {
      sprintf(checkpoints_buf, "%d", test);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "725", "test", checkpoints_buf);
      if (! test) {

        strcpy((char */* __restrict  */)(ofname),
               (char const   */* __restrict  */)"stdout");

      } else {
        goto _L___2;
      }
      sprintf(checkpoints_buf, "%d", test);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "725", "test", checkpoints_buf);
    } else {
      goto _L___2;
    }
    sprintf(checkpoints_buf, "%d", list);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "724", "list", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "729", "tmp___7", checkpoints_buf);

    _L___2: /* CIL Label */ 
    _L___1: /* CIL Label */ 
    tmp___7 = make_ofname();
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "729", "tmp___7", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "730", "tmp___7", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "730", "0", checkpoints_buf);
    if (tmp___7 != 0) {

      close(ifd);

      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "730", "tmp___7", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "730", "0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "723", "to_stdout", checkpoints_buf);

  clear_bufs();

  part_nb = 0;
  sprintf(checkpoints_buf, "%d", part_nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "735", "part_nb", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "736", "decompress", checkpoints_buf);
  if (decompress) {
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "737", "method", checkpoints_buf);

    method = get_method(ifd);
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "737", "method", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "738", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "738", "0", checkpoints_buf);
    if (method < 0) {

      close(ifd);

      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "738", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "738", "0", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "736", "decompress", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", list);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "743", "list", checkpoints_buf);
  if (list) {

    do_list(ifd, method);

    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "745", "tmp___8", checkpoints_buf);

    tmp___8 = close(ifd);
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "745", "tmp___8", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "746", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "746", "0", checkpoints_buf);
    if (tmp___8 != 0) {

      read_error();

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "746", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "746", "0", checkpoints_buf);
    return;
  } else {

  }
  sprintf(checkpoints_buf, "%d", list);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "743", "list", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "751", "to_stdout", checkpoints_buf);
  if (to_stdout) {
    sprintf(checkpoints_buf, "%d", ofd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "752", "ofd", checkpoints_buf);

    ofd = fileno(stdout);
    sprintf(checkpoints_buf, "%d", ofd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "752", "ofd", checkpoints_buf);

  } else {
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "753", "tmp___9", checkpoints_buf);

    tmp___9 = create_outfile();
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "753", "tmp___9", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "754", "tmp___9", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "754", "0", checkpoints_buf);
    if (tmp___9 != 0) {
      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "754", "tmp___9", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "754", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "757", "decompress", checkpoints_buf);
    if (! decompress) {
      sprintf(checkpoints_buf, "%d", save_orig_name);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "758", "save_orig_name", checkpoints_buf);
      if (save_orig_name) {
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "759", "verbose", checkpoints_buf);
        if (! verbose) {
          sprintf(checkpoints_buf, "%d", quiet);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "760", "quiet", checkpoints_buf);
          if (! quiet) {

            fprintf((FILE */* __restrict  */)stderr,
                    (char const   */* __restrict  */)"%s: %s compressed to %s\n",
                    program_name, ifname, ofname);

          } else {

          }
          sprintf(checkpoints_buf, "%d", quiet);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "760", "quiet", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "759", "verbose", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", save_orig_name);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "758", "save_orig_name", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "757", "decompress", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "751", "to_stdout", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", save_orig_name);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "766", "save_orig_name", checkpoints_buf);
  if (! save_orig_name) {
    save_orig_name = ! no_name;
    sprintf(checkpoints_buf, "%d", save_orig_name);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "767", "save_orig_name", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", save_orig_name);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "766", "save_orig_name", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "769", "verbose", checkpoints_buf);
  if (verbose) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s:\t", ifname);

  } else {

  }
  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "769", "verbose", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___10", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___11", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___11", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "method", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "0", checkpoints_buf);

  while (1) {
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "773", "tmp___10", checkpoints_buf);

    tmp___10 = (*work)(ifd, ofd);
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "773", "tmp___10", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "774", "tmp___10", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "774", "0", checkpoints_buf);
    if (tmp___10 != 0) {
      method = -1;
      sprintf(checkpoints_buf, "%d", method);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "775", "method", checkpoints_buf);
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "774", "tmp___10", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "774", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "778", "tmp___11", checkpoints_buf);

    tmp___11 = input_eof();
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "778", "tmp___11", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "779", "tmp___11", checkpoints_buf);
    if (tmp___11) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "779", "tmp___11", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "782", "method", checkpoints_buf);

    method = get_method(ifd);
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "782", "method", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "783", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "783", "0", checkpoints_buf);
    if (method < 0) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "783", "method", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "783", "0", checkpoints_buf);
    bytes_out = (off_t )0;

  }
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___10", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___11", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "tmp___11", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "method", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "772", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "787", "tmp___12", checkpoints_buf);

  tmp___12 = close(ifd);
  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "787", "tmp___12", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "788", "tmp___12", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "788", "0", checkpoints_buf);
  if (tmp___12 != 0) {

    read_error();

  } else {
    {

    ifd = open_input_file(iname, & istat);
    }
  }
  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "788", "tmp___12", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "788", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "791", "to_stdout", checkpoints_buf);
  if (! to_stdout) {

    copy_stat(& istat);

    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "793", "tmp___13", checkpoints_buf);

    tmp___13 = close(ofd);
    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "793", "tmp___13", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "794", "tmp___13", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "794", "0", checkpoints_buf);
    if (tmp___13 != 0) {

      write_error();

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "794", "tmp___13", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "794", "0", checkpoints_buf);

    sigprocmask(0, (sigset_t const   */* __restrict  */)(& caught_signals),
                (sigset_t */* __restrict  */)(& oldset));

    remove_ofname_fd = (int volatile   )-1;
    sprintf(checkpoints_buf, "%d", remove_ofname_fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "798", "remove_ofname_fd", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "799", "tmp___16", checkpoints_buf);

    tmp___16 = xunlink(ifname);
    sprintf(checkpoints_buf, "%d", tmp___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "799", "tmp___16", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "800", "tmp___16", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "800", "0", checkpoints_buf);
    if (tmp___16 == 0) {
      unlink_errno = 0;
      sprintf(checkpoints_buf, "%d", unlink_errno);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "801", "unlink_errno", checkpoints_buf);
    } else {


      tmp___15 = __errno_location();


      unlink_errno = *tmp___15;
      sprintf(checkpoints_buf, "%d", unlink_errno);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "803", "unlink_errno", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "800", "tmp___16", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "800", "0", checkpoints_buf);

    sigprocmask(2, (sigset_t const   */* __restrict  */)(& oldset),
                (sigset_t */* __restrict  */)((void *)0));

    sprintf(checkpoints_buf, "%d", unlink_errno);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "805", "unlink_errno", checkpoints_buf);
    if (unlink_errno) {
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "806", "quiet", checkpoints_buf);
      if (! quiet) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: ", program_name);

      } else {

      }
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "806", "quiet", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "809", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "809", "0", checkpoints_buf);
      if (exit_code == 0) {
        exit_code = 2;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "810", "exit_code", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "809", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "809", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "812", "quiet", checkpoints_buf);
      if (! quiet) {


        tmp___17 = __errno_location();


        *tmp___17 = unlink_errno;


        perror((char const   *)(ifname));

      } else {

      }
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "812", "quiet", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", unlink_errno);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "805", "unlink_errno", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "791", "to_stdout", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "819", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "819", "-1", checkpoints_buf);
  if (method == -1) {
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "820", "to_stdout", checkpoints_buf);
    if (! to_stdout) {

      remove_output_file();

    } else {

    }
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "820", "to_stdout", checkpoints_buf);
    return;
  } else {

  }
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "819", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "819", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "825", "verbose", checkpoints_buf);
  if (verbose) {
    sprintf(checkpoints_buf, "%d", test);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "826", "test", checkpoints_buf);
    if (test) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)" OK");

    } else {
      sprintf(checkpoints_buf, "%d", decompress);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "828", "decompress", checkpoints_buf);
      if (decompress) {

        display_ratio(bytes_out - (bytes_in - header_bytes), bytes_out, stderr);

      } else {

        display_ratio(bytes_in - (bytes_out - header_bytes), bytes_in, stderr);

      }
      sprintf(checkpoints_buf, "%d", decompress);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "828", "decompress", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", test);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "826", "test", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", test);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "831", "test", checkpoints_buf);
    if (! test) {
      sprintf(checkpoints_buf, "%d", to_stdout);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "832", "to_stdout", checkpoints_buf);
      if (! to_stdout) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)" -- replaced with %s", ofname);

      } else {

      }
      sprintf(checkpoints_buf, "%d", to_stdout);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "832", "to_stdout", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", test);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "831", "test", checkpoints_buf);

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"\n");

  } else {

  }
  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "825", "verbose", checkpoints_buf);
  return;
}
}
static int create_outfile(void) 
{ 
  int name_shortened ;
  int flags ;
  int tmp ;
  int open_errno ;
  sigset_t oldset ;
  int *tmp___0 ;
  int tmp___1 ;

  {
  name_shortened = 0;
  sprintf(checkpoints_buf, "%d", name_shortened);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "839", "name_shortened", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", ascii);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "840", "ascii", checkpoints_buf);
  if (ascii) {
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "841", "decompress", checkpoints_buf);
    if (decompress) {
      tmp = 0;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "842", "tmp", checkpoints_buf);
    } else {
      tmp = 0;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "843", "tmp", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "841", "decompress", checkpoints_buf);
  } else {
    tmp = 0;
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "844", "tmp", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", ascii);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "840", "ascii", checkpoints_buf);
  flags = 193 | tmp;
  sprintf(checkpoints_buf, "%d", flags);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "845", "flags", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", ofd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "ofd", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", remove_ofname_fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "remove_ofname_fd", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", open_errno);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "open_errno", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", ofd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "ofd", checkpoints_buf);
  while (1) {

    sigprocmask(0, (sigset_t const   */* __restrict  */)(& caught_signals),
                (sigset_t */* __restrict  */)(& oldset));

    sprintf(checkpoints_buf, "%d", ofd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "848", "ofd", checkpoints_buf);

    ofd = open_safer((char const   *)(ofname), flags, 384);
    sprintf(checkpoints_buf, "%d", ofd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "848", "ofd", checkpoints_buf);

    remove_ofname_fd = (int volatile   )ofd;
    sprintf(checkpoints_buf, "%d", remove_ofname_fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "849", "remove_ofname_fd", checkpoints_buf);


    tmp___0 = __errno_location();


    open_errno = *tmp___0;
    sprintf(checkpoints_buf, "%d", open_errno);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "851", "open_errno", checkpoints_buf);

    sigprocmask(2, (sigset_t const   */* __restrict  */)(& oldset),
                (sigset_t */* __restrict  */)((void *)0));

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "853", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", ofd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "853", "ofd", checkpoints_buf);
    if (0 <= ofd) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "853", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", ofd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "853", "ofd", checkpoints_buf);
    switch (open_errno) {

    case 36: 
    shorten_name(ofname);

    name_shortened = 1;
    sprintf(checkpoints_buf, "%d", name_shortened);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "858", "name_shortened", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "860", "tmp___1", checkpoints_buf);

    case 17: 
    tmp___1 = check_ofname();
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "860", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "861", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "861", "0", checkpoints_buf);
    if (tmp___1 != 0) {

      close(ifd);

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "863", "1", checkpoints_buf);
      return (1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "861", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "861", "0", checkpoints_buf);
    break;

    default: 
    progerror(ofname);


    close(ifd);

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "868", "1", checkpoints_buf);
    return (1);
    }
  }

  sprintf(checkpoints_buf, "%d", ofd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "ofd", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", remove_ofname_fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "remove_ofname_fd", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", open_errno);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "open_errno", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", ofd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "846", "ofd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", name_shortened);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "869", "name_shortened", checkpoints_buf);
  if (name_shortened) {
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "870", "decompress", checkpoints_buf);
    if (decompress) {
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "871", "quiet", checkpoints_buf);
      if (! quiet) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s: warning, name truncated\n",
                program_name, ofname);

      } else {

      }
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "871", "quiet", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "874", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "874", "0", checkpoints_buf);
      if (exit_code == 0) {
        exit_code = 2;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "875", "exit_code", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "874", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "874", "0", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "870", "decompress", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", name_shortened);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "869", "name_shortened", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "879", "0", checkpoints_buf);
  return (0);
}
}
static char *get_suffix(char *name ) ;
static char *known_suffixes[9]  = 
  {      (char *)((void *)0),      (char *)".gz",      (char *)".z",      (char *)".taz", 
        (char *)".tgz",      (char *)"-gz",      (char *)"-z",      (char *)"_z", 
        (char *)((void *)0)};
static char *get_suffix(char *name ) 
{ 
  int nlen ;
  int slen ;
  char suffix[33] ;
  char **suf ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___2 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  size_t tmp___6 ;
  size_t tmp___7 ;
  int s ;
  size_t tmp___8 ;
  size_t __s1_len___0 ;
  size_t __s2_len___0 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  unsigned char const   *__s2___0 ;
  register int __result___1 ;
  int tmp___12 ;
  unsigned char const   *__s1___0 ;
  register int __result___2 ;
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;

  {
  suf = known_suffixes;

  *suf = z_suffix;

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "882", "0", checkpoints_buf);
  if (0) {


    __s1_len = strlen((char const   *)z_suffix);




    __s2_len = strlen("z");


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "885", "1", checkpoints_buf);
    if (! ((size_t )((void const   *)(z_suffix + 1)) - (size_t )((void const   *)z_suffix) == 1U)) {
      goto _L___0;
    } else {

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "887", "4", checkpoints_buf);
      if (__s1_len >= 4U) {
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "888", "1", checkpoints_buf);
        _L___0: /* CIL Label */ 
        if (! ((size_t )((void const   *)("z" + 1)) - (size_t )((void const   *)"z") == 1U)) {
          tmp___5 = 1;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "889", "tmp___5", checkpoints_buf);
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "890", "4", checkpoints_buf);
          if (__s2_len >= 4U) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "891", "tmp___5", checkpoints_buf);
          } else {
            tmp___5 = 0;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "892", "tmp___5", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "890", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "888", "1", checkpoints_buf);
      } else {
        tmp___5 = 0;
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "893", "tmp___5", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "887", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "885", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "894", "tmp___5", checkpoints_buf);
    if (tmp___5) {
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "895", "tmp___0", checkpoints_buf);

      tmp___0 = __builtin_strcmp((char const   *)z_suffix, "z");
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "895", "tmp___0", checkpoints_buf);

      tmp___4 = tmp___0;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "896", "tmp___4", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "897", "tmp___3", checkpoints_buf);

      tmp___3 = __builtin_strcmp((char const   *)z_suffix, "z");
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "897", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "898", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "894", "tmp___5", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "899", "tmp___3", checkpoints_buf);

    tmp___3 = __builtin_strcmp((char const   *)z_suffix, "z");
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "899", "tmp___3", checkpoints_buf);

    tmp___4 = tmp___3;
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "900", "tmp___4", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "882", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "901", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "901", "0", checkpoints_buf);
  if (tmp___4 == 0) {
    suf ++;

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "901", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "901", "0", checkpoints_buf);


  tmp___6 = strlen((char const   *)name);


  nlen = (int )tmp___6;
  sprintf(checkpoints_buf, "%d", nlen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "905", "nlen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", nlen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "906", "nlen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "906", "32", checkpoints_buf);
  if (nlen <= 32) {

    strcpy((char */* __restrict  */)(suffix),
           (char const   */* __restrict  */)name);

  } else {

    strcpy((char */* __restrict  */)(suffix),
           (char const   */* __restrict  */)(((name + nlen) - 30) - 2));

  }
  sprintf(checkpoints_buf, "%d", nlen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "906", "nlen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "906", "32", checkpoints_buf);

  strlwr(suffix);



  tmp___7 = strlen((char const   *)(suffix));


  slen = (int )tmp___7;
  sprintf(checkpoints_buf, "%d", slen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "911", "slen", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", s);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "912", "s", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", slen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "912", "slen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", s);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "912", "s", checkpoints_buf);

  while (1) {


    tmp___8 = strlen((char const   *)*suf);


    s = (int )tmp___8;
    sprintf(checkpoints_buf, "%d", s);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "914", "s", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", slen);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "915", "slen", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", s);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "915", "s", checkpoints_buf);
    if (slen > s) {
      sprintf(checkpoints_buf, "%d", 47);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "916", "47", checkpoints_buf);
      if ((int )suffix[(slen - s) - 1] != 47) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "917", "0", checkpoints_buf);
        if (0) {


          __s1_len___0 = strlen((char const   *)((suffix + slen) - s));




          __s2_len___0 = strlen((char const   *)*suf);


          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "920", "1", checkpoints_buf);
          if (! ((size_t )((void const   *)(((suffix + slen) - s) + 1)) - (size_t )((void const   *)((suffix + slen) - s)) == 1U)) {
            goto _L___2;
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "922", "4", checkpoints_buf);
            if (__s1_len___0 >= 4U) {
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "923", "1", checkpoints_buf);
              _L___2: /* CIL Label */ 
              if (! ((size_t )((void const   *)(*suf + 1)) - (size_t )((void const   *)*suf) == 1U)) {
                tmp___15 = 1;
                sprintf(checkpoints_buf, "%d", tmp___15);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "924", "tmp___15", checkpoints_buf);
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "925", "4", checkpoints_buf);
                if (__s2_len___0 >= 4U) {
                  tmp___15 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___15);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "926", "tmp___15", checkpoints_buf);
                } else {
                  tmp___15 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___15);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "927", "tmp___15", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "925", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "923", "1", checkpoints_buf);
            } else {
              tmp___15 = 0;
              sprintf(checkpoints_buf, "%d", tmp___15);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "928", "tmp___15", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "922", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "920", "1", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___15);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "929", "tmp___15", checkpoints_buf);
          if (tmp___15) {
            sprintf(checkpoints_buf, "%d", tmp___10);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "930", "tmp___10", checkpoints_buf);

            tmp___10 = __builtin_strcmp((char const   *)((suffix + slen) - s),
                                        (char const   *)*suf);
            sprintf(checkpoints_buf, "%d", tmp___10);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "930", "tmp___10", checkpoints_buf);

            tmp___14 = tmp___10;
            sprintf(checkpoints_buf, "%d", tmp___14);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "931", "tmp___14", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___13);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "932", "tmp___13", checkpoints_buf);

            tmp___13 = __builtin_strcmp((char const   *)((suffix + slen) - s),
                                        (char const   *)*suf);
            sprintf(checkpoints_buf, "%d", tmp___13);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "932", "tmp___13", checkpoints_buf);

            tmp___14 = tmp___13;
            sprintf(checkpoints_buf, "%d", tmp___14);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "933", "tmp___14", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___15);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "929", "tmp___15", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___13);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "934", "tmp___13", checkpoints_buf);

          tmp___13 = __builtin_strcmp((char const   *)((suffix + slen) - s),
                                      (char const   *)*suf);
          sprintf(checkpoints_buf, "%d", tmp___13);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "934", "tmp___13", checkpoints_buf);

          tmp___14 = tmp___13;
          sprintf(checkpoints_buf, "%d", tmp___14);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "935", "tmp___14", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "917", "0", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "936", "tmp___14", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "936", "0", checkpoints_buf);
        if (tmp___14 == 0) {

          sprintf(checkpoints_buf, "%d", nlen);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "937", "nlen", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", s);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "937", "s", checkpoints_buf);
          return ((name + nlen) - s);
        } else {

        }
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "936", "tmp___14", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "936", "0", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 47);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "916", "47", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", slen);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "915", "slen", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", s);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "915", "s", checkpoints_buf);
    suf ++;

    if ((unsigned int )*suf != (unsigned int )((void *)0)) {

    } else {
      break;
    }
  }


  sprintf(checkpoints_buf, "%d", s);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "912", "s", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", slen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "912", "slen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", s);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "912", "s", checkpoints_buf);

  return ((char *)((void *)0));
}
}
static int open_and_stat(char *name , int flags , mode_t mode , struct stat *st ) 
{ 
  int fd ;
  int *tmp ;
  int __attribute__((__gnu_inline__))  tmp___0 ;
  int e ;
  int *tmp___1 ;
  int *tmp___2 ;
  int __attribute__((__gnu_inline__))  tmp___3 ;

  {
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "946", "to_stdout", checkpoints_buf);
  if (! to_stdout) {
    sprintf(checkpoints_buf, "%d", force);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "947", "force", checkpoints_buf);
    if (! force) {
      flags |= 131072;
      sprintf(checkpoints_buf, "%d", flags);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "948", "flags", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", force);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "947", "force", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", to_stdout);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "946", "to_stdout", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "951", "fd", checkpoints_buf);

  fd = open_safer((char const   *)name, flags, mode);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "951", "fd", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "952", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "952", "fd", checkpoints_buf);
  if (0 <= fd) {
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "953", "tmp___3", checkpoints_buf);

    tmp___3 = fstat(fd, st);
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "953", "tmp___3", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "954", "tmp___3", checkpoints_buf);
    if (tmp___3 != (int __attribute__((__gnu_inline__))  )0) {


      tmp___1 = __errno_location();


      e = *tmp___1;
      sprintf(checkpoints_buf, "%d", e);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "956", "e", checkpoints_buf);

      close(fd);



      tmp___2 = __errno_location();


      *tmp___2 = e;

      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "960", "-1", checkpoints_buf);
      return (-1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "954", "tmp___3", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "952", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "952", "fd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "963", "fd", checkpoints_buf);
  return (fd);
}
}
static int open_input_file(char *iname , struct stat *sbuf ) ;
static char *suffixes[6]  = {      (char *)((void *)0),      (char *)".gz",      (char *)".z",      (char *)"-z", 
        (char *)".Z",      (char *)((void *)0)};
static int open_input_file(char *iname , struct stat *sbuf ) 
{ 
  int ilen ;
  int z_suffix_errno ;
  char **suf ;
  char *s ;
  int fd ;
  int open_flags ;
  int tmp ;
  size_t tmp___0 ;
  int *tmp___1 ;
  size_t tmp___2 ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___6 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  char *s0 ;
  size_t tmp___10 ;
  int *tmp___11 ;
  int *tmp___12 ;
  size_t __s1_len___0 ;
  size_t __s2_len___0 ;
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;
  unsigned char const   *__s2___0 ;
  register int __result___1 ;
  int tmp___16 ;
  unsigned char const   *__s1___0 ;
  register int __result___2 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  int *tmp___20 ;

  {
  z_suffix_errno = 0;
  sprintf(checkpoints_buf, "%d", z_suffix_errno);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "964", "z_suffix_errno", checkpoints_buf);
  suf = suffixes;

  sprintf(checkpoints_buf, "%d", ascii);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "966", "ascii", checkpoints_buf);
  if (ascii) {
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "967", "decompress", checkpoints_buf);
    if (! decompress) {
      tmp = 0;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "968", "tmp", checkpoints_buf);
    } else {
      tmp = 0;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "969", "tmp", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", decompress);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "967", "decompress", checkpoints_buf);
  } else {
    tmp = 0;
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "970", "tmp", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", ascii);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "966", "ascii", checkpoints_buf);
  open_flags = 2304 | tmp;
  sprintf(checkpoints_buf, "%d", open_flags);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "971", "open_flags", checkpoints_buf);
  *suf = z_suffix;



  tmp___0 = strlen((char const   *)iname);


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "974", "1", checkpoints_buf);

  if (sizeof(ifname) - 1U <= tmp___0) {
    goto name_too_long;
  } else {

  }
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "974", "1", checkpoints_buf);


  strcpy((char */* __restrict  */)(ifname),
         (char const   */* __restrict  */)iname);

  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "978", "fd", checkpoints_buf);

  fd = open_and_stat(ifname, open_flags, (mode_t )384, sbuf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "978", "fd", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "979", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "979", "fd", checkpoints_buf);
  if (0 <= fd) {
    sprintf(checkpoints_buf, "%d", fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "980", "fd", checkpoints_buf);
    return (fd);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "979", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "979", "fd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "982", "decompress", checkpoints_buf);
  if (! decompress) {

    progerror(ifname);

    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "984", "-1", checkpoints_buf);
    return (-1);
  } else {


    tmp___1 = __errno_location();



    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "986", "2", checkpoints_buf);
    if (*tmp___1 != 2) {

      progerror(ifname);

      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "988", "-1", checkpoints_buf);
      return (-1);
    } else {

    }

    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "986", "2", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "982", "decompress", checkpoints_buf);


  s = get_suffix(ifname);


  if ((unsigned int )s != (unsigned int )((void *)0)) {

    progerror(ifname);

    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "993", "-1", checkpoints_buf);
    return (-1);
  } else {

  }


  tmp___2 = strlen((char const   *)(ifname));


  ilen = (int )tmp___2;
  sprintf(checkpoints_buf, "%d", ilen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "996", "ilen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "997", "0", checkpoints_buf);
  if (0) {


    __s1_len = strlen((char const   *)z_suffix);




    __s2_len = strlen(".gz");


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1000", "1", checkpoints_buf);
    if (! ((size_t )((void const   *)(z_suffix + 1)) - (size_t )((void const   *)z_suffix) == 1U)) {
      goto _L___0;
    } else {

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1002", "4", checkpoints_buf);
      if (__s1_len >= 4U) {
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1003", "1", checkpoints_buf);
        _L___0: /* CIL Label */ 
        if (! ((size_t )((void const   *)(".gz" + 1)) - (size_t )((void const   *)".gz") == 1U)) {
          tmp___9 = 1;
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1004", "tmp___9", checkpoints_buf);
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1005", "4", checkpoints_buf);
          if (__s2_len >= 4U) {
            tmp___9 = 1;
            sprintf(checkpoints_buf, "%d", tmp___9);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1006", "tmp___9", checkpoints_buf);
          } else {
            tmp___9 = 0;
            sprintf(checkpoints_buf, "%d", tmp___9);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1007", "tmp___9", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1005", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1003", "1", checkpoints_buf);
      } else {
        tmp___9 = 0;
        sprintf(checkpoints_buf, "%d", tmp___9);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1008", "tmp___9", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1002", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1000", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1009", "tmp___9", checkpoints_buf);
    if (tmp___9) {
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1010", "tmp___4", checkpoints_buf);

      tmp___4 = __builtin_strcmp((char const   *)z_suffix, ".gz");
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1010", "tmp___4", checkpoints_buf);

      tmp___8 = tmp___4;
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1011", "tmp___8", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1012", "tmp___7", checkpoints_buf);

      tmp___7 = __builtin_strcmp((char const   *)z_suffix, ".gz");
      sprintf(checkpoints_buf, "%d", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1012", "tmp___7", checkpoints_buf);

      tmp___8 = tmp___7;
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1013", "tmp___8", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1009", "tmp___9", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1014", "tmp___7", checkpoints_buf);

    tmp___7 = __builtin_strcmp((char const   *)z_suffix, ".gz");
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1014", "tmp___7", checkpoints_buf);

    tmp___8 = tmp___7;
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1015", "tmp___8", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "997", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1016", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1016", "0", checkpoints_buf);
  if (tmp___8 == 0) {
    suf ++;

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1016", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1016", "0", checkpoints_buf);







  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "fd", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "fd", checkpoints_buf);



  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "tmp___18", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "0", checkpoints_buf);

  while (1) {
    s = *suf;

    s0 = s;


    strcpy((char */* __restrict  */)(ifname),
           (char const   */* __restrict  */)iname);



    tmp___10 = strlen((char const   *)s);



    if (sizeof(ifname) <= (size_t )ilen + tmp___10) {
      goto name_too_long;
    } else {

    }


    strcat((char */* __restrict  */)(ifname), (char const   */* __restrict  */)s);

    sprintf(checkpoints_buf, "%d", fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1028", "fd", checkpoints_buf);

    fd = open_and_stat(ifname, open_flags, (mode_t )384, sbuf);
    sprintf(checkpoints_buf, "%d", fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1028", "fd", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1029", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1029", "fd", checkpoints_buf);
    if (0 <= fd) {
      sprintf(checkpoints_buf, "%d", fd);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1030", "fd", checkpoints_buf);
      return (fd);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1029", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1029", "fd", checkpoints_buf);


    tmp___11 = __errno_location();



    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1033", "2", checkpoints_buf);
    if (*tmp___11 != 2) {

      progerror(ifname);

      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1035", "-1", checkpoints_buf);
      return (-1);
    } else {

    }

    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1033", "2", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1037", "0", checkpoints_buf);
    if (0) {


      __s1_len___0 = strlen((char const   *)s0);




      __s2_len___0 = strlen((char const   *)z_suffix);


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1040", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(s0 + 1)) - (size_t )((void const   *)s0) == 1U)) {
        goto _L___2;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1042", "4", checkpoints_buf);
        if (__s1_len___0 >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1043", "1", checkpoints_buf);
          _L___2: /* CIL Label */ 
          if (! ((size_t )((void const   *)(z_suffix + 1)) - (size_t )((void const   *)z_suffix) == 1U)) {
            tmp___19 = 1;
            sprintf(checkpoints_buf, "%d", tmp___19);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1044", "tmp___19", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1045", "4", checkpoints_buf);
            if (__s2_len___0 >= 4U) {
              tmp___19 = 1;
              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1046", "tmp___19", checkpoints_buf);
            } else {
              tmp___19 = 0;
              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1047", "tmp___19", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1045", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1043", "1", checkpoints_buf);
        } else {
          tmp___19 = 0;
          sprintf(checkpoints_buf, "%d", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1048", "tmp___19", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1042", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1040", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___19);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1049", "tmp___19", checkpoints_buf);
      if (tmp___19) {
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1050", "tmp___14", checkpoints_buf);

        tmp___14 = __builtin_strcmp((char const   *)s0, (char const   *)z_suffix);
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1050", "tmp___14", checkpoints_buf);

        tmp___18 = tmp___14;
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1051", "tmp___18", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1052", "tmp___17", checkpoints_buf);

        tmp___17 = __builtin_strcmp((char const   *)s0, (char const   *)z_suffix);
        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1052", "tmp___17", checkpoints_buf);

        tmp___18 = tmp___17;
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1053", "tmp___18", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___19);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1049", "tmp___19", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1054", "tmp___17", checkpoints_buf);

      tmp___17 = __builtin_strcmp((char const   *)s0, (char const   *)z_suffix);
      sprintf(checkpoints_buf, "%d", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1054", "tmp___17", checkpoints_buf);

      tmp___18 = tmp___17;
      sprintf(checkpoints_buf, "%d", tmp___18);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1055", "tmp___18", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1037", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1056", "tmp___18", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1056", "0", checkpoints_buf);
    if (tmp___18 == 0) {


      tmp___12 = __errno_location();


      z_suffix_errno = *tmp___12;
      sprintf(checkpoints_buf, "%d", z_suffix_errno);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1058", "z_suffix_errno", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1056", "tmp___18", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1056", "0", checkpoints_buf);
    suf ++;

    if ((unsigned int )*suf != (unsigned int )((void *)0)) {

    } else {
      break;
    }
  }







  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "fd", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "fd", checkpoints_buf);



  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "tmp___18", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1019", "0", checkpoints_buf);


  strcpy((char */* __restrict  */)(ifname),
         (char const   */* __restrict  */)iname);


  strcat((char */* __restrict  */)(ifname),
         (char const   */* __restrict  */)z_suffix);



  tmp___20 = __errno_location();


  *tmp___20 = z_suffix_errno;


  progerror(ifname);

  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1069", "-1", checkpoints_buf);
  return (-1);

  name_too_long: 
  fprintf((FILE */* __restrict  */)stderr,
          (char const   */* __restrict  */)"%s: %s: file name too long\n",
          program_name, iname);

  exit_code = 1;
  sprintf(checkpoints_buf, "%d", exit_code);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1071", "exit_code", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1072", "-1", checkpoints_buf);
  return (-1);
}
}
static int make_ofname(void) 
{ 
  char *suff ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___2 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  size_t __s1_len___0 ;
  size_t __s2_len___0 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  unsigned char const   *__s2___0 ;
  register int __result___1 ;
  int tmp___9 ;
  unsigned char const   *__s1___0 ;
  register int __result___2 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  size_t tmp___13 ;

  {

  strcpy((char */* __restrict  */)(ofname),
         (char const   */* __restrict  */)(ifname));



  suff = get_suffix(ofname);


  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1075", "decompress", checkpoints_buf);
  if (decompress) {
    if ((unsigned int )suff == (unsigned int )((void *)0)) {
      sprintf(checkpoints_buf, "%d", recursive);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1077", "recursive", checkpoints_buf);
      if (! recursive) {
        sprintf(checkpoints_buf, "%d", list);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1078", "list", checkpoints_buf);
        if (list) {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1079", "0", checkpoints_buf);
          return (0);
        } else {
          sprintf(checkpoints_buf, "%d", test);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1080", "test", checkpoints_buf);
          if (test) {
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1081", "0", checkpoints_buf);
            return (0);
          } else {

          }
          sprintf(checkpoints_buf, "%d", test);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1080", "test", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", list);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1078", "list", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", recursive);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1077", "recursive", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1084", "verbose", checkpoints_buf);
      if (verbose) {
        goto _L;
      } else {
        sprintf(checkpoints_buf, "%d", recursive);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1086", "recursive", checkpoints_buf);
        if (! recursive) {
          sprintf(checkpoints_buf, "%d", quiet);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1087", "quiet", checkpoints_buf);
          if (! quiet) {
            sprintf(checkpoints_buf, "%d", quiet);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1088", "quiet", checkpoints_buf);
            _L: /* CIL Label */ 
            if (! quiet) {

              fprintf((FILE */* __restrict  */)stderr,
                      (char const   */* __restrict  */)"%s: %s: unknown suffix -- ignored\n",
                      program_name, ifname);

            } else {

            }
            sprintf(checkpoints_buf, "%d", quiet);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1088", "quiet", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", exit_code);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1091", "exit_code", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1091", "0", checkpoints_buf);
            if (exit_code == 0) {
              exit_code = 2;
              sprintf(checkpoints_buf, "%d", exit_code);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1092", "exit_code", checkpoints_buf);
            } else {

            }
            sprintf(checkpoints_buf, "%d", exit_code);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1091", "exit_code", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1091", "0", checkpoints_buf);
          } else {

          }
          sprintf(checkpoints_buf, "%d", quiet);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1087", "quiet", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", recursive);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1086", "recursive", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1084", "verbose", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1096", "2", checkpoints_buf);
      return (2);
    } else {

    }

    strlwr(suff);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1099", "0", checkpoints_buf);
    if (0) {


      __s1_len = strlen((char const   *)suff);




      __s2_len = strlen(".tgz");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1102", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(suff + 1)) - (size_t )((void const   *)suff) == 1U)) {
        goto _L___1;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1104", "4", checkpoints_buf);
        if (__s1_len >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1105", "1", checkpoints_buf);
          _L___1: /* CIL Label */ 
          if (! ((size_t )((void const   *)(".tgz" + 1)) - (size_t )((void const   *)".tgz") == 1U)) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1106", "tmp___5", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1107", "4", checkpoints_buf);
            if (__s2_len >= 4U) {
              tmp___5 = 1;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1108", "tmp___5", checkpoints_buf);
            } else {
              tmp___5 = 0;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1109", "tmp___5", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1107", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1105", "1", checkpoints_buf);
        } else {
          tmp___5 = 0;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1110", "tmp___5", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1104", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1102", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1111", "tmp___5", checkpoints_buf);
      if (tmp___5) {
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1112", "tmp___0", checkpoints_buf);

        tmp___0 = __builtin_strcmp((char const   *)suff, ".tgz");
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1112", "tmp___0", checkpoints_buf);

        tmp___4 = tmp___0;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1113", "tmp___4", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1114", "tmp___3", checkpoints_buf);

        tmp___3 = __builtin_strcmp((char const   *)suff, ".tgz");
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1114", "tmp___3", checkpoints_buf);

        tmp___4 = tmp___3;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1115", "tmp___4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1111", "tmp___5", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1116", "tmp___3", checkpoints_buf);

      tmp___3 = __builtin_strcmp((char const   *)suff, ".tgz");
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1116", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1117", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1099", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1118", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1118", "0", checkpoints_buf);
    if (tmp___4 == 0) {

      strcpy((char */* __restrict  */)suff,
             (char const   */* __restrict  */)".tar");

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1120", "0", checkpoints_buf);
      if (0) {


        __s1_len___0 = strlen((char const   *)suff);




        __s2_len___0 = strlen(".taz");


        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1123", "1", checkpoints_buf);
        if (! ((size_t )((void const   *)(suff + 1)) - (size_t )((void const   *)suff) == 1U)) {
          goto _L___3;
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1125", "4", checkpoints_buf);
          if (__s1_len___0 >= 4U) {
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1126", "1", checkpoints_buf);
            _L___3: /* CIL Label */ 
            if (! ((size_t )((void const   *)(".taz" + 1)) - (size_t )((void const   *)".taz") == 1U)) {
              tmp___12 = 1;
              sprintf(checkpoints_buf, "%d", tmp___12);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1127", "tmp___12", checkpoints_buf);
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1128", "4", checkpoints_buf);
              if (__s2_len___0 >= 4U) {
                tmp___12 = 1;
                sprintf(checkpoints_buf, "%d", tmp___12);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1129", "tmp___12", checkpoints_buf);
              } else {
                tmp___12 = 0;
                sprintf(checkpoints_buf, "%d", tmp___12);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1130", "tmp___12", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1128", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1126", "1", checkpoints_buf);
          } else {
            tmp___12 = 0;
            sprintf(checkpoints_buf, "%d", tmp___12);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1131", "tmp___12", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1125", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1123", "1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1132", "tmp___12", checkpoints_buf);
        if (tmp___12) {
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1133", "tmp___7", checkpoints_buf);

          tmp___7 = __builtin_strcmp((char const   *)suff, ".taz");
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1133", "tmp___7", checkpoints_buf);

          tmp___11 = tmp___7;
          sprintf(checkpoints_buf, "%d", tmp___11);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1134", "tmp___11", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___10);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1135", "tmp___10", checkpoints_buf);

          tmp___10 = __builtin_strcmp((char const   *)suff, ".taz");
          sprintf(checkpoints_buf, "%d", tmp___10);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1135", "tmp___10", checkpoints_buf);

          tmp___11 = tmp___10;
          sprintf(checkpoints_buf, "%d", tmp___11);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1136", "tmp___11", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1132", "tmp___12", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1137", "tmp___10", checkpoints_buf);

        tmp___10 = __builtin_strcmp((char const   *)suff, ".taz");
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1137", "tmp___10", checkpoints_buf);

        tmp___11 = tmp___10;
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1138", "tmp___11", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1120", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1139", "tmp___11", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1139", "0", checkpoints_buf);
      if (tmp___11 == 0) {

        strcpy((char */* __restrict  */)suff,
               (char const   */* __restrict  */)".tar");

      } else {
        *suff = (char )'\000';

      }
      sprintf(checkpoints_buf, "%d", tmp___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1139", "tmp___11", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1139", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1118", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1118", "0", checkpoints_buf);
  } else {

    if (suff) {
      sprintf(checkpoints_buf, "%d", force);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1143", "force", checkpoints_buf);
      if (! force) {
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1144", "verbose", checkpoints_buf);
        if (verbose) {

          fprintf((FILE */* __restrict  */)stderr,
                  (char const   */* __restrict  */)"%s: %s already has %s suffix -- unchanged\n",
                  program_name, ifname, suff);

        } else {
          sprintf(checkpoints_buf, "%d", recursive);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1146", "recursive", checkpoints_buf);
          if (! recursive) {
            sprintf(checkpoints_buf, "%d", quiet);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1147", "quiet", checkpoints_buf);
            if (! quiet) {

              fprintf((FILE */* __restrict  */)stderr,
                      (char const   */* __restrict  */)"%s: %s already has %s suffix -- unchanged\n",
                      program_name, ifname, suff);

            } else {

            }
            sprintf(checkpoints_buf, "%d", quiet);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1147", "quiet", checkpoints_buf);
          } else {

          }
          sprintf(checkpoints_buf, "%d", recursive);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1146", "recursive", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1144", "verbose", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1151", "2", checkpoints_buf);
        return (2);
      } else {
        goto _L___4;
      }
      sprintf(checkpoints_buf, "%d", force);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1143", "force", checkpoints_buf);
    } else {
      _L___4: /* CIL Label */ 
      save_orig_name = 0;
      sprintf(checkpoints_buf, "%d", save_orig_name);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1153", "save_orig_name", checkpoints_buf);


      tmp___13 = strlen((char const   *)(ofname));




      if (sizeof(ofname) <= tmp___13 + z_len) {
        goto name_too_long;
      } else {

      }



      strcat((char */* __restrict  */)(ofname),
             (char const   */* __restrict  */)z_suffix);

    }

  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1075", "decompress", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1159", "0", checkpoints_buf);
  return (0);
  sprintf(checkpoints_buf, "%d", quiet);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1160", "quiet", checkpoints_buf);
  name_too_long: 
  if (! quiet) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s: %s: file name too long\n",
            program_name, ifname);

  } else {

  }
  sprintf(checkpoints_buf, "%d", quiet);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1160", "quiet", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", exit_code);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1163", "exit_code", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1163", "0", checkpoints_buf);
  if (exit_code == 0) {
    exit_code = 2;
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1164", "exit_code", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", exit_code);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1163", "exit_code", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1163", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1166", "2", checkpoints_buf);
  return (2);
}
}
static int get_method(int in ) 
{ 
  uch flags ;
  char magic[2] ;
  int imagic1 ;
  ulg stamp ;
  unsigned int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned int tmp___2 ;
  int tmp___3 ;
  unsigned int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  unsigned int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  unsigned int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  unsigned int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;
  unsigned int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  unsigned int tmp___19 ;
  int tmp___20 ;
  int tmp___21 ;
  unsigned int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  unsigned int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  unsigned int tmp___28 ;
  unsigned int tmp___29 ;
  unsigned int part ;
  unsigned int tmp___30 ;
  int tmp___31 ;
  int tmp___32 ;
  unsigned int tmp___33 ;
  int tmp___34 ;
  int tmp___35 ;
  unsigned int len ;
  unsigned int tmp___36 ;
  int tmp___37 ;
  int tmp___38 ;
  unsigned int tmp___39 ;
  int tmp___40 ;
  int tmp___41 ;
  unsigned int tmp___42 ;
  unsigned int tmp___43 ;
  char c ;
  unsigned int tmp___44 ;
  int tmp___45 ;
  char *p ;
  char *tmp___46 ;
  char *base ;
  unsigned int tmp___47 ;
  int tmp___48 ;
  int tmp___49 ;
  char *tmp___50 ;
  size_t tmp___51 ;
  unsigned int tmp___52 ;
  int tmp___53 ;
  int tmp___54 ;
  int tmp___55 ;
  int tmp___56 ;
  int tmp___57 ;
  int tmp___58 ;
  int tmp___59 ;
  int tmp___60 ;
  int tmp___61 ;
  int tmp___62 ;
  int inbyte ;
  unsigned int tmp___63 ;
  int tmp___64 ;

  {
  sprintf(checkpoints_buf, "%d", force);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1167", "force", checkpoints_buf);
  if (force) {
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1168", "to_stdout", checkpoints_buf);
    if (to_stdout) {
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1169", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1169", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp = inptr;
        sprintf(checkpoints_buf, "%u", tmp);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1170", "tmp", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1171", "inptr", checkpoints_buf);
        tmp___1 = (int )inbuf[tmp];
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1172", "tmp___1", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1173", "tmp___0", checkpoints_buf);

        tmp___0 = fill_inbuf(1);
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1173", "tmp___0", checkpoints_buf);

        tmp___1 = tmp___0;
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1174", "tmp___1", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1169", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1169", "insize", checkpoints_buf);
      magic[0] = (char )tmp___1;

      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1176", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1176", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___2 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1177", "tmp___2", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1178", "inptr", checkpoints_buf);
        imagic1 = (int )inbuf[tmp___2];
        sprintf(checkpoints_buf, "%d", imagic1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1179", "imagic1", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1180", "tmp___3", checkpoints_buf);

        tmp___3 = fill_inbuf(1);
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1180", "tmp___3", checkpoints_buf);

        imagic1 = tmp___3;
        sprintf(checkpoints_buf, "%d", imagic1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1181", "imagic1", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1176", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1176", "insize", checkpoints_buf);
      magic[1] = (char )imagic1;

    } else {
      goto _L;
    }
    sprintf(checkpoints_buf, "%d", to_stdout);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1168", "to_stdout", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1184", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1184", "insize", checkpoints_buf);
    _L: /* CIL Label */ 
    if (inptr < insize) {
      tmp___4 = inptr;
      sprintf(checkpoints_buf, "%u", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1185", "tmp___4", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1186", "inptr", checkpoints_buf);
      tmp___6 = (int )inbuf[tmp___4];
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1187", "tmp___6", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1188", "tmp___5", checkpoints_buf);

      tmp___5 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1188", "tmp___5", checkpoints_buf);

      tmp___6 = tmp___5;
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1189", "tmp___6", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1184", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1184", "insize", checkpoints_buf);
    magic[0] = (char )tmp___6;

    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1191", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1191", "insize", checkpoints_buf);
    if (inptr < insize) {
      tmp___7 = inptr;
      sprintf(checkpoints_buf, "%u", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1192", "tmp___7", checkpoints_buf);
      inptr ++;
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1193", "inptr", checkpoints_buf);
      tmp___9 = (int )inbuf[tmp___7];
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1194", "tmp___9", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1195", "tmp___8", checkpoints_buf);

      tmp___8 = fill_inbuf(0);
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1195", "tmp___8", checkpoints_buf);

      tmp___9 = tmp___8;
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1196", "tmp___9", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", inptr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1191", "inptr", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", insize);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1191", "insize", checkpoints_buf);
    magic[1] = (char )tmp___9;

    imagic1 = 0;
    sprintf(checkpoints_buf, "%d", imagic1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1198", "imagic1", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", force);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1167", "force", checkpoints_buf);
  method = -1;
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1199", "method", checkpoints_buf);
  part_nb ++;
  sprintf(checkpoints_buf, "%d", part_nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1200", "part_nb", checkpoints_buf);
  header_bytes = (off_t )0;

  last_member = 0;
  sprintf(checkpoints_buf, "%d", last_member);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1202", "last_member", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___61);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1203", "tmp___61", checkpoints_buf);

  tmp___61 = memcmp((void const   *)(magic), (void const   *)"\037\213",
                    (size_t )2);
  sprintf(checkpoints_buf, "%d", tmp___61);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1203", "tmp___61", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___61);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1204", "tmp___61", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1204", "0", checkpoints_buf);
  if (tmp___61 == 0) {
    goto _L___4;
  } else {
    sprintf(checkpoints_buf, "%d", tmp___62);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1206", "tmp___62", checkpoints_buf);

    tmp___62 = memcmp((void const   *)(magic), (void const   *)"\037\236",
                      (size_t )2);
    sprintf(checkpoints_buf, "%d", tmp___62);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1206", "tmp___62", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___62);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1207", "tmp___62", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1207", "0", checkpoints_buf);
    if (tmp___62 == 0) {
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1208", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1208", "insize", checkpoints_buf);
      _L___4: /* CIL Label */ 
      if (inptr < insize) {
        tmp___10 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1209", "tmp___10", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1210", "inptr", checkpoints_buf);
        tmp___12 = (int )inbuf[tmp___10];
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1211", "tmp___12", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1212", "tmp___11", checkpoints_buf);

        tmp___11 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1212", "tmp___11", checkpoints_buf);

        tmp___12 = tmp___11;
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1213", "tmp___12", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1208", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1208", "insize", checkpoints_buf);
      method = tmp___12;
      sprintf(checkpoints_buf, "%d", method);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1214", "method", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", method);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1215", "method", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1215", "8", checkpoints_buf);
      if (method != 8) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s: unknown method %d -- not supported\n",
                program_name, ifname, method);

        exit_code = 1;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1217", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1218", "-1", checkpoints_buf);
        return (-1);
      } else {

      }
      sprintf(checkpoints_buf, "%d", method);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1215", "method", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1215", "8", checkpoints_buf);
      work = & unzip;

      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1221", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1221", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___13 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1222", "tmp___13", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1223", "inptr", checkpoints_buf);
        tmp___15 = (int )inbuf[tmp___13];
        sprintf(checkpoints_buf, "%d", tmp___15);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1224", "tmp___15", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1225", "tmp___14", checkpoints_buf);

        tmp___14 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1225", "tmp___14", checkpoints_buf);

        tmp___15 = tmp___14;
        sprintf(checkpoints_buf, "%d", tmp___15);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1226", "tmp___15", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1221", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1221", "insize", checkpoints_buf);
      flags = (uch )tmp___15;

      sprintf(checkpoints_buf, "%d", 32);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1228", "32", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1228", "0", checkpoints_buf);
      if (((int )flags & 32) != 0) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s is encrypted -- not supported\n",
                program_name, ifname);

        exit_code = 1;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1230", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1231", "-1", checkpoints_buf);
        return (-1);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 32);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1228", "32", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1228", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1233", "2", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1233", "0", checkpoints_buf);
      if (((int )flags & 2) != 0) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s is a multi-part gzip file -- not supported\n",
                program_name, ifname);

        exit_code = 1;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1235", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", force);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1236", "force", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1236", "1", checkpoints_buf);
        if (force <= 1) {
          sprintf(checkpoints_buf, "%d", -1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1237", "-1", checkpoints_buf);
          return (-1);
        } else {

        }
        sprintf(checkpoints_buf, "%d", force);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1236", "force", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1236", "1", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1233", "2", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1233", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 192);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1240", "192", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1240", "0", checkpoints_buf);
      if (((int )flags & 192) != 0) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: %s has flags 0x%x -- not supported\n",
                program_name, ifname, (int )flags);

        exit_code = 1;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1242", "exit_code", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", force);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1243", "force", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1243", "1", checkpoints_buf);
        if (force <= 1) {
          sprintf(checkpoints_buf, "%d", -1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1244", "-1", checkpoints_buf);
          return (-1);
        } else {

        }
        sprintf(checkpoints_buf, "%d", force);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1243", "force", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1243", "1", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 192);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1240", "192", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1240", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1247", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1247", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___16 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1248", "tmp___16", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1249", "inptr", checkpoints_buf);
        tmp___18 = (int )inbuf[tmp___16];
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1250", "tmp___18", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1251", "tmp___17", checkpoints_buf);

        tmp___17 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1251", "tmp___17", checkpoints_buf);

        tmp___18 = tmp___17;
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1252", "tmp___18", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1247", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1247", "insize", checkpoints_buf);
      stamp = (ulg )tmp___18;

      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1254", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1254", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___19 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1255", "tmp___19", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1256", "inptr", checkpoints_buf);
        tmp___21 = (int )inbuf[tmp___19];
        sprintf(checkpoints_buf, "%d", tmp___21);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1257", "tmp___21", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___20);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1258", "tmp___20", checkpoints_buf);

        tmp___20 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___20);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1258", "tmp___20", checkpoints_buf);

        tmp___21 = tmp___20;
        sprintf(checkpoints_buf, "%d", tmp___21);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1259", "tmp___21", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1254", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1254", "insize", checkpoints_buf);
      stamp |= (ulg )tmp___21 << 8;

      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1261", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1261", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___22 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1262", "tmp___22", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1263", "inptr", checkpoints_buf);
        tmp___24 = (int )inbuf[tmp___22];
        sprintf(checkpoints_buf, "%d", tmp___24);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1264", "tmp___24", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___23);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1265", "tmp___23", checkpoints_buf);

        tmp___23 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___23);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1265", "tmp___23", checkpoints_buf);

        tmp___24 = tmp___23;
        sprintf(checkpoints_buf, "%d", tmp___24);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1266", "tmp___24", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1261", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1261", "insize", checkpoints_buf);
      stamp |= (ulg )tmp___24 << 16;

      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1268", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1268", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___25 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___25);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1269", "tmp___25", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1270", "inptr", checkpoints_buf);
        tmp___27 = (int )inbuf[tmp___25];
        sprintf(checkpoints_buf, "%d", tmp___27);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1271", "tmp___27", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___26);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1272", "tmp___26", checkpoints_buf);

        tmp___26 = fill_inbuf(0);
        sprintf(checkpoints_buf, "%d", tmp___26);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1272", "tmp___26", checkpoints_buf);

        tmp___27 = tmp___26;
        sprintf(checkpoints_buf, "%d", tmp___27);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1273", "tmp___27", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1268", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1268", "insize", checkpoints_buf);
      stamp |= (ulg )tmp___27 << 24;


      sprintf(checkpoints_buf, "%ul", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1275", "0", checkpoints_buf);
      if (stamp != 0UL) {
        sprintf(checkpoints_buf, "%d", no_time);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1276", "no_time", checkpoints_buf);
        if (! no_time) {
          time_stamp.tv_sec = (__time_t )stamp;

          time_stamp.tv_nsec = 0L;

        } else {

        }
        sprintf(checkpoints_buf, "%d", no_time);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1276", "no_time", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1275", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1281", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1281", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___28 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___28);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1282", "tmp___28", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1283", "inptr", checkpoints_buf);
      } else {

        fill_inbuf(0);

      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1281", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1281", "insize", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1285", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1285", "insize", checkpoints_buf);
      if (inptr < insize) {
        tmp___29 = inptr;
        sprintf(checkpoints_buf, "%u", tmp___29);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1286", "tmp___29", checkpoints_buf);
        inptr ++;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1287", "inptr", checkpoints_buf);
      } else {

        fill_inbuf(0);

      }
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1285", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1285", "insize", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1289", "2", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1289", "0", checkpoints_buf);
      if (((int )flags & 2) != 0) {
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1290", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1290", "insize", checkpoints_buf);
        if (inptr < insize) {
          tmp___30 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___30);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1291", "tmp___30", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1292", "inptr", checkpoints_buf);
          tmp___32 = (int )inbuf[tmp___30];
          sprintf(checkpoints_buf, "%d", tmp___32);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1293", "tmp___32", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___31);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1294", "tmp___31", checkpoints_buf);

          tmp___31 = fill_inbuf(0);
          sprintf(checkpoints_buf, "%d", tmp___31);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1294", "tmp___31", checkpoints_buf);

          tmp___32 = tmp___31;
          sprintf(checkpoints_buf, "%d", tmp___32);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1295", "tmp___32", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1290", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1290", "insize", checkpoints_buf);
        part = (unsigned int )tmp___32;
        sprintf(checkpoints_buf, "%u", part);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1296", "part", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1297", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1297", "insize", checkpoints_buf);
        if (inptr < insize) {
          tmp___33 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___33);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1298", "tmp___33", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1299", "inptr", checkpoints_buf);
          tmp___35 = (int )inbuf[tmp___33];
          sprintf(checkpoints_buf, "%d", tmp___35);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1300", "tmp___35", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___34);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1301", "tmp___34", checkpoints_buf);

          tmp___34 = fill_inbuf(0);
          sprintf(checkpoints_buf, "%d", tmp___34);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1301", "tmp___34", checkpoints_buf);

          tmp___35 = tmp___34;
          sprintf(checkpoints_buf, "%d", tmp___35);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1302", "tmp___35", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1297", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1297", "insize", checkpoints_buf);
        part |= (unsigned int )tmp___35 << 8;
        sprintf(checkpoints_buf, "%u", part);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1303", "part", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1304", "verbose", checkpoints_buf);
        if (verbose) {

          fprintf((FILE */* __restrict  */)stderr,
                  (char const   */* __restrict  */)"%s: %s: part number %u\n",
                  program_name, ifname, part);

        } else {

        }
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1304", "verbose", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1289", "2", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1289", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1308", "4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1308", "0", checkpoints_buf);
      if (((int )flags & 4) != 0) {
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1309", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1309", "insize", checkpoints_buf);
        if (inptr < insize) {
          tmp___36 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___36);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1310", "tmp___36", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1311", "inptr", checkpoints_buf);
          tmp___38 = (int )inbuf[tmp___36];
          sprintf(checkpoints_buf, "%d", tmp___38);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1312", "tmp___38", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___37);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1313", "tmp___37", checkpoints_buf);

          tmp___37 = fill_inbuf(0);
          sprintf(checkpoints_buf, "%d", tmp___37);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1313", "tmp___37", checkpoints_buf);

          tmp___38 = tmp___37;
          sprintf(checkpoints_buf, "%d", tmp___38);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1314", "tmp___38", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1309", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1309", "insize", checkpoints_buf);
        len = (unsigned int )tmp___38;
        sprintf(checkpoints_buf, "%u", len);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1315", "len", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1316", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1316", "insize", checkpoints_buf);
        if (inptr < insize) {
          tmp___39 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___39);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1317", "tmp___39", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1318", "inptr", checkpoints_buf);
          tmp___41 = (int )inbuf[tmp___39];
          sprintf(checkpoints_buf, "%d", tmp___41);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1319", "tmp___41", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___40);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1320", "tmp___40", checkpoints_buf);

          tmp___40 = fill_inbuf(0);
          sprintf(checkpoints_buf, "%d", tmp___40);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1320", "tmp___40", checkpoints_buf);

          tmp___41 = tmp___40;
          sprintf(checkpoints_buf, "%d", tmp___41);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1321", "tmp___41", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1316", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1316", "insize", checkpoints_buf);
        len |= (unsigned int )tmp___41 << 8;
        sprintf(checkpoints_buf, "%u", len);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1322", "len", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1323", "verbose", checkpoints_buf);
        if (verbose) {

          fprintf((FILE */* __restrict  */)stderr,
                  (char const   */* __restrict  */)"%s: %s: extra field of %u bytes ignored\n",
                  program_name, ifname, len);

        } else {

        }
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1323", "verbose", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "tmp___43", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", len);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "len", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "tmp___43", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "insize", checkpoints_buf);
        while (1) {
          tmp___43 = len;
          sprintf(checkpoints_buf, "%u", tmp___43);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1327", "tmp___43", checkpoints_buf);
          len --;
          sprintf(checkpoints_buf, "%u", len);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1328", "len", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", tmp___43);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1329", "tmp___43", checkpoints_buf);
          if (tmp___43) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%u", tmp___43);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1329", "tmp___43", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1332", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1332", "insize", checkpoints_buf);
          if (inptr < insize) {
            tmp___42 = inptr;
            sprintf(checkpoints_buf, "%u", tmp___42);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1333", "tmp___42", checkpoints_buf);
            inptr ++;
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1334", "inptr", checkpoints_buf);
          } else {

            fill_inbuf(0);

          }
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1332", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1332", "insize", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "tmp___43", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", len);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "len", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "tmp___43", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1326", "insize", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1308", "4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1308", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1337", "8", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1337", "0", checkpoints_buf);
      if (((int )flags & 8) != 0) {
        sprintf(checkpoints_buf, "%d", no_name);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1338", "no_name", checkpoints_buf);
        if (no_name) {
          goto _L___0;
        } else {
          sprintf(checkpoints_buf, "%d", to_stdout);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1340", "to_stdout", checkpoints_buf);
          if (to_stdout) {
            sprintf(checkpoints_buf, "%d", list);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1341", "list", checkpoints_buf);
            if (! list) {
              goto _L___0;
            } else {
              goto _L___1;
            }
            sprintf(checkpoints_buf, "%d", list);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1341", "list", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", part_nb);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1344", "part_nb", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1344", "1", checkpoints_buf);
            _L___1: /* CIL Label */ 
            if (part_nb > 1) {
              sprintf(checkpoints_buf, "%u", inptr);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1345", "inptr", checkpoints_buf);
              sprintf(checkpoints_buf, "%u", insize);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1345", "insize", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1345", "0", checkpoints_buf);
              _L___0: /* CIL Label */ 
              while (1) {
                sprintf(checkpoints_buf, "%u", inptr);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1346", "inptr", checkpoints_buf);
                sprintf(checkpoints_buf, "%u", insize);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1346", "insize", checkpoints_buf);
                if (inptr < insize) {
                  tmp___44 = inptr;
                  sprintf(checkpoints_buf, "%u", tmp___44);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1347", "tmp___44", checkpoints_buf);
                  inptr ++;
                  sprintf(checkpoints_buf, "%u", inptr);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1348", "inptr", checkpoints_buf);
                  c = (char )inbuf[tmp___44];
                  sprintf(checkpoints_buf, "%c", c);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1349", "c", checkpoints_buf);
                } else {
                  sprintf(checkpoints_buf, "%d", tmp___45);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1350", "tmp___45", checkpoints_buf);

                  tmp___45 = fill_inbuf(0);
                  sprintf(checkpoints_buf, "%d", tmp___45);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1350", "tmp___45", checkpoints_buf);

                  c = (char )tmp___45;
                  sprintf(checkpoints_buf, "%c", c);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1351", "c", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", inptr);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1346", "inptr", checkpoints_buf);
                sprintf(checkpoints_buf, "%u", insize);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1346", "insize", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1352", "0", checkpoints_buf);
                if ((int )c != 0) {

                } else {
                  break;
                }
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1352", "0", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", inptr);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1345", "inptr", checkpoints_buf);
              sprintf(checkpoints_buf, "%u", insize);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1345", "insize", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1345", "0", checkpoints_buf);
            } else {


              tmp___46 = gzip_base_name(ofname);


              p = tmp___46;

              base = p;

              sprintf(checkpoints_buf, "%u", inptr);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1358", "inptr", checkpoints_buf);
              sprintf(checkpoints_buf, "%u", insize);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1358", "insize", checkpoints_buf);



              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1358", "0", checkpoints_buf);
              while (1) {
                sprintf(checkpoints_buf, "%u", inptr);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1359", "inptr", checkpoints_buf);
                sprintf(checkpoints_buf, "%u", insize);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1359", "insize", checkpoints_buf);
                if (inptr < insize) {
                  tmp___47 = inptr;
                  sprintf(checkpoints_buf, "%u", tmp___47);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1360", "tmp___47", checkpoints_buf);
                  inptr ++;
                  sprintf(checkpoints_buf, "%u", inptr);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1361", "inptr", checkpoints_buf);
                  tmp___49 = (int )inbuf[tmp___47];
                  sprintf(checkpoints_buf, "%d", tmp___49);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1362", "tmp___49", checkpoints_buf);
                } else {
                  sprintf(checkpoints_buf, "%d", tmp___48);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1363", "tmp___48", checkpoints_buf);

                  tmp___48 = fill_inbuf(0);
                  sprintf(checkpoints_buf, "%d", tmp___48);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1363", "tmp___48", checkpoints_buf);

                  tmp___49 = tmp___48;
                  sprintf(checkpoints_buf, "%d", tmp___49);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1364", "tmp___49", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", inptr);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1359", "inptr", checkpoints_buf);
                sprintf(checkpoints_buf, "%u", insize);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1359", "insize", checkpoints_buf);
                *p = (char )tmp___49;

                tmp___50 = p;

                p ++;

                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1368", "0", checkpoints_buf);
                if ((int )*tmp___50 == 0) {
                  break;
                } else {

                }
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1368", "0", checkpoints_buf);
                if ((unsigned int )p >= (unsigned int )(ofname + sizeof(ofname))) {

                  gzip_error((char *)"corrupted input -- file name too large");

                } else {

                }
              }
              sprintf(checkpoints_buf, "%u", inptr);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1358", "inptr", checkpoints_buf);
              sprintf(checkpoints_buf, "%u", insize);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1358", "insize", checkpoints_buf);



              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1358", "0", checkpoints_buf);


              p = gzip_base_name(base);




              tmp___51 = strlen((char const   *)p);



              memmove((void *)base, (void const   *)p, tmp___51 + 1U);

              sprintf(checkpoints_buf, "%d", list);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1377", "list", checkpoints_buf);
              if (! list) {

                if (base) {
                  list = 0;
                  sprintf(checkpoints_buf, "%d", list);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1379", "list", checkpoints_buf);
                } else {

                }

              } else {

              }
              sprintf(checkpoints_buf, "%d", list);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1377", "list", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", part_nb);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1344", "part_nb", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1344", "1", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", to_stdout);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1340", "to_stdout", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", no_name);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1338", "no_name", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1337", "8", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1337", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1383", "16", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1383", "0", checkpoints_buf);
      if (((int )flags & 16) != 0) {
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "insize", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___54);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "tmp___54", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "0", checkpoints_buf);
        while (1) {
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1385", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1385", "insize", checkpoints_buf);
          if (inptr < insize) {
            tmp___52 = inptr;
            sprintf(checkpoints_buf, "%u", tmp___52);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1386", "tmp___52", checkpoints_buf);
            inptr ++;
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1387", "inptr", checkpoints_buf);
            tmp___54 = (int )inbuf[tmp___52];
            sprintf(checkpoints_buf, "%d", tmp___54);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1388", "tmp___54", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___53);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1389", "tmp___53", checkpoints_buf);

            tmp___53 = fill_inbuf(0);
            sprintf(checkpoints_buf, "%d", tmp___53);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1389", "tmp___53", checkpoints_buf);

            tmp___54 = tmp___53;
            sprintf(checkpoints_buf, "%d", tmp___54);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1390", "tmp___54", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1385", "inptr", checkpoints_buf);
          sprintf(checkpoints_buf, "%u", insize);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1385", "insize", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___54);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1391", "tmp___54", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1391", "0", checkpoints_buf);
          if (tmp___54 != 0) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%d", tmp___54);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1391", "tmp___54", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1391", "0", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "insize", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___54);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "tmp___54", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1384", "0", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1383", "16", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1383", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", part_nb);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1395", "part_nb", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1395", "1", checkpoints_buf);
      if (part_nb == 1) {
        header_bytes = (off_t )(inptr + 2U * sizeof(long ));

      } else {

      }
      sprintf(checkpoints_buf, "%d", part_nb);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1395", "part_nb", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1395", "1", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1398", "tmp___59", checkpoints_buf);

      tmp___59 = memcmp((void const   *)(magic), (void const   *)"PK\003\004",
                        (size_t )2);
      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1398", "tmp___59", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1399", "tmp___59", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1399", "0", checkpoints_buf);
      if (tmp___59 == 0) {
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1400", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1400", "2", checkpoints_buf);
        if (inptr == 2U) {
          sprintf(checkpoints_buf, "%d", tmp___60);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1401", "tmp___60", checkpoints_buf);

          tmp___60 = memcmp((void const   *)((char *)(inbuf)),
                            (void const   *)"PK\003\004", (size_t )4);
          sprintf(checkpoints_buf, "%d", tmp___60);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1401", "tmp___60", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___60);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1402", "tmp___60", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1402", "0", checkpoints_buf);
          if (tmp___60 == 0) {
            inptr = 0U;
            sprintf(checkpoints_buf, "%u", inptr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1403", "inptr", checkpoints_buf);
            work = & unzip;

            sprintf(checkpoints_buf, "%d", tmp___55);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1405", "tmp___55", checkpoints_buf);

            tmp___55 = check_zipfile(in);
            sprintf(checkpoints_buf, "%d", tmp___55);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1405", "tmp___55", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___55);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1406", "tmp___55", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1406", "0", checkpoints_buf);
            if (tmp___55 != 0) {
              sprintf(checkpoints_buf, "%d", -1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1407", "-1", checkpoints_buf);
              return (-1);
            } else {

            }
            sprintf(checkpoints_buf, "%d", tmp___55);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1406", "tmp___55", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1406", "0", checkpoints_buf);
            last_member = 1;
            sprintf(checkpoints_buf, "%d", last_member);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1409", "last_member", checkpoints_buf);
          } else {
            goto _L___3;
          }
          sprintf(checkpoints_buf, "%d", tmp___60);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1402", "tmp___60", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1402", "0", checkpoints_buf);
        } else {
          goto _L___3;
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1400", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1400", "2", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___58);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1412", "tmp___58", checkpoints_buf);

        _L___3: /* CIL Label */ 
        _L___2: /* CIL Label */ 
        tmp___58 = memcmp((void const   *)(magic), (void const   *)"\037\036",
                          (size_t )2);
        sprintf(checkpoints_buf, "%d", tmp___58);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1412", "tmp___58", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___58);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1413", "tmp___58", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1413", "0", checkpoints_buf);
        if (tmp___58 == 0) {
          work = & unpack;

          method = 2;
          sprintf(checkpoints_buf, "%d", method);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1415", "method", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___57);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1416", "tmp___57", checkpoints_buf);

          tmp___57 = memcmp((void const   *)(magic), (void const   *)"\037\235",
                            (size_t )2);
          sprintf(checkpoints_buf, "%d", tmp___57);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1416", "tmp___57", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___57);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1417", "tmp___57", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1417", "0", checkpoints_buf);
          if (tmp___57 == 0) {
            work = & unlzw;

            method = 1;
            sprintf(checkpoints_buf, "%d", method);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1419", "method", checkpoints_buf);
            last_member = 1;
            sprintf(checkpoints_buf, "%d", last_member);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1420", "last_member", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___56);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1421", "tmp___56", checkpoints_buf);

            tmp___56 = memcmp((void const   *)(magic),
                              (void const   *)"\037\240", (size_t )2);
            sprintf(checkpoints_buf, "%d", tmp___56);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1421", "tmp___56", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___56);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1422", "tmp___56", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1422", "0", checkpoints_buf);
            if (tmp___56 == 0) {
              work = & unlzh;

              method = 3;
              sprintf(checkpoints_buf, "%d", method);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1424", "method", checkpoints_buf);
              last_member = 1;
              sprintf(checkpoints_buf, "%d", last_member);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1425", "last_member", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", force);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1426", "force", checkpoints_buf);
              if (force) {
                sprintf(checkpoints_buf, "%d", to_stdout);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1427", "to_stdout", checkpoints_buf);
                if (to_stdout) {
                  sprintf(checkpoints_buf, "%d", list);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1428", "list", checkpoints_buf);
                  if (! list) {
                    method = 0;
                    sprintf(checkpoints_buf, "%d", method);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                    "1429", "method", checkpoints_buf);
                    work = & copy;

                    inptr = 0U;
                    sprintf(checkpoints_buf, "%u", inptr);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                    "1431", "inptr", checkpoints_buf);
                    last_member = 1;
                    sprintf(checkpoints_buf, "%d", last_member);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                    "1432", "last_member", checkpoints_buf);
                  } else {

                  }
                  sprintf(checkpoints_buf, "%d", list);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                  "1428", "list", checkpoints_buf);
                } else {

                }
                sprintf(checkpoints_buf, "%d", to_stdout);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1427", "to_stdout", checkpoints_buf);
              } else {

              }
              sprintf(checkpoints_buf, "%d", force);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1426", "force", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___56);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1422", "tmp___56", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1422", "0", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___57);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1417", "tmp___57", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1417", "0", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___58);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1413", "tmp___58", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1413", "0", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1399", "tmp___59", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1399", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___62);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1207", "tmp___62", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1207", "0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___61);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1204", "tmp___61", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1204", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1436", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1436", "0", checkpoints_buf);
  if (method >= 0) {
    sprintf(checkpoints_buf, "%d", method);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1437", "method", checkpoints_buf);
    return (method);
  } else {

  }
  sprintf(checkpoints_buf, "%d", method);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1436", "method", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1436", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", part_nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1439", "part_nb", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1439", "1", checkpoints_buf);
  if (part_nb == 1) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"\n%s: %s: not in gzip format\n",
            program_name, ifname);

    exit_code = 1;
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1441", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1442", "-1", checkpoints_buf);
    return (-1);
  } else {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1443", "0", checkpoints_buf);
    if ((int )magic[0] == 0) {
      inbyte = imagic1;
      sprintf(checkpoints_buf, "%d", inbyte);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1444", "inbyte", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", inbyte);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "inbyte", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "insize", checkpoints_buf);
      while (1) {
        sprintf(checkpoints_buf, "%d", inbyte);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1446", "inbyte", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1446", "0", checkpoints_buf);
        if (inbyte == 0) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", inbyte);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1446", "inbyte", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1446", "0", checkpoints_buf);
        goto __Cont;
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1450", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1450", "insize", checkpoints_buf);
        __Cont: /* CIL Label */ 
        if (inptr < insize) {
          tmp___63 = inptr;
          sprintf(checkpoints_buf, "%u", tmp___63);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1451", "tmp___63", checkpoints_buf);
          inptr ++;
          sprintf(checkpoints_buf, "%u", inptr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1452", "inptr", checkpoints_buf);
          inbyte = (int )inbuf[tmp___63];
          sprintf(checkpoints_buf, "%d", inbyte);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1453", "inbyte", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___64);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1454", "tmp___64", checkpoints_buf);

          tmp___64 = fill_inbuf(1);
          sprintf(checkpoints_buf, "%d", tmp___64);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1454", "tmp___64", checkpoints_buf);

          inbyte = tmp___64;
          sprintf(checkpoints_buf, "%d", inbyte);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1455", "inbyte", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", inptr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1450", "inptr", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", insize);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1450", "insize", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", inbyte);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "inbyte", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", inptr);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "inptr", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", insize);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1445", "insize", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", inbyte);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1456", "inbyte", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1456", "-1", checkpoints_buf);
      if (inbyte == -1) {
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1457", "verbose", checkpoints_buf);
        if (verbose) {
          sprintf(checkpoints_buf, "%d", quiet);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1458", "quiet", checkpoints_buf);
          if (! quiet) {

            fprintf((FILE */* __restrict  */)stderr,
                    (char const   */* __restrict  */)"\n%s: %s: decompression OK, trailing zero bytes ignored\n",
                    program_name, ifname);

          } else {

          }
          sprintf(checkpoints_buf, "%d", quiet);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1458", "quiet", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", exit_code);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1461", "exit_code", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1461", "0", checkpoints_buf);
          if (exit_code == 0) {
            exit_code = 2;
            sprintf(checkpoints_buf, "%d", exit_code);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1462", "exit_code", checkpoints_buf);
          } else {

          }
          sprintf(checkpoints_buf, "%d", exit_code);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1461", "exit_code", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1461", "0", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1457", "verbose", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", -3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1465", "-3", checkpoints_buf);
        return (-3);
      } else {

      }
      sprintf(checkpoints_buf, "%d", inbyte);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1456", "inbyte", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1456", "-1", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1443", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1468", "quiet", checkpoints_buf);
    if (! quiet) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"\n%s: %s: decompression OK, trailing garbage ignored\n",
              program_name, ifname);

    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1468", "quiet", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1471", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1471", "0", checkpoints_buf);
    if (exit_code == 0) {
      exit_code = 2;
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1472", "exit_code", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1471", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1471", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1474", "-2", checkpoints_buf);
    return (-2);
  }
  sprintf(checkpoints_buf, "%d", part_nb);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1439", "part_nb", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1439", "1", checkpoints_buf);
}
}
static void do_list(int ifd___0 , int method___0 ) ;
static int first_time  =    1;
static void do_list(int ifd___0 , int method___0 ) ;
static char *methods[9]  = 
  {      (char *)"store",      (char *)"compr",      (char *)"pack ",      (char *)"lzh  ", 
        (char *)"",      (char *)"",      (char *)"",      (char *)"", 
        (char *)"defla"};
static void do_list(int ifd___0 , int method___0 ) 
{ 
  ulg crc ;
  int positive_off_t_width ;
  off_t o ;
  uch buf[8] ;
  ssize_t tmp ;
  struct tm *tm ;
  struct tm *tmp___0 ;

  {
  positive_off_t_width = 1;
  sprintf(checkpoints_buf, "%d", positive_off_t_width);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1475", "positive_off_t_width", checkpoints_buf);
  o = -1LL - (-1LL << (sizeof(off_t ) * 8U - 1U));

  sprintf(checkpoints_buf, "%lld", 9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1477", "9", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", positive_off_t_width);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1477", "positive_off_t_width", checkpoints_buf);

  while (1) {
    sprintf(checkpoints_buf, "%lld", 9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1478", "9", checkpoints_buf);

    if (9LL < o) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%lld", 9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1478", "9", checkpoints_buf);

    positive_off_t_width ++;
    sprintf(checkpoints_buf, "%d", positive_off_t_width);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1481", "positive_off_t_width", checkpoints_buf);
    o /= 10LL;

  }
  sprintf(checkpoints_buf, "%lld", 9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1477", "9", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", positive_off_t_width);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1477", "positive_off_t_width", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", first_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1483", "first_time", checkpoints_buf);
  if (first_time) {
    sprintf(checkpoints_buf, "%d", method___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1484", "method___0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1484", "0", checkpoints_buf);
    if (method___0 >= 0) {
      first_time = 0;
      sprintf(checkpoints_buf, "%d", first_time);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1485", "first_time", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1486", "verbose", checkpoints_buf);
      if (verbose) {

        printf((char const   */* __restrict  */)"method  crc     date  time  ");

      } else {

      }
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1486", "verbose", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1489", "quiet", checkpoints_buf);
      if (! quiet) {

        printf((char const   */* __restrict  */)"%*.*s %*.*s  ratio uncompressed_name\n",
               positive_off_t_width, positive_off_t_width, "compressed",
               positive_off_t_width, positive_off_t_width, "uncompressed");

      } else {

      }
      sprintf(checkpoints_buf, "%d", quiet);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1489", "quiet", checkpoints_buf);
    } else {
      goto _L;
    }
    sprintf(checkpoints_buf, "%d", method___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1484", "method___0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1484", "0", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", method___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1493", "method___0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1493", "0", checkpoints_buf);
    _L: /* CIL Label */ 
    if (method___0 < 0) {

      sprintf(checkpoints_buf, "%lld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1494", "0", checkpoints_buf);
      if (total_in <= 0LL) {
        return;
      } else {

        sprintf(checkpoints_buf, "%lld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1496", "0", checkpoints_buf);
        if (total_out <= 0LL) {
          return;
        } else {

        }

        sprintf(checkpoints_buf, "%lld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1496", "0", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%lld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1494", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1499", "verbose", checkpoints_buf);
      if (verbose) {

        printf((char const   */* __restrict  */)"                            ");

      } else {

      }
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1499", "verbose", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1502", "verbose", checkpoints_buf);
      if (verbose) {

        fprint_off(stdout, total_in, positive_off_t_width);


        printf((char const   */* __restrict  */)" ");


        fprint_off(stdout, total_out, positive_off_t_width);


        printf((char const   */* __restrict  */)" ");

      } else {
        sprintf(checkpoints_buf, "%d", quiet);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1507", "quiet", checkpoints_buf);
        if (! quiet) {

          fprint_off(stdout, total_in, positive_off_t_width);


          printf((char const   */* __restrict  */)" ");


          fprint_off(stdout, total_out, positive_off_t_width);


          printf((char const   */* __restrict  */)" ");

        } else {

        }
        sprintf(checkpoints_buf, "%d", quiet);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1507", "quiet", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", verbose);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1502", "verbose", checkpoints_buf);

      display_ratio(total_out - (total_in - header_bytes), total_out, stdout);


      printf((char const   */* __restrict  */)" (totals)\n");

      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", method___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1493", "method___0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1493", "0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", first_time);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1483", "first_time", checkpoints_buf);
  crc = (ulg )(~ 0);

  bytes_out = (off_t )-1L;

  bytes_in = ifile_size;

  sprintf(checkpoints_buf, "%d", method___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1520", "method___0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1520", "8", checkpoints_buf);
  if (method___0 == 8) {
    sprintf(checkpoints_buf, "%d", last_member);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1521", "last_member", checkpoints_buf);
    if (! last_member) {


      bytes_in = lseek(ifd___0, (off_t )-8, 2);



      sprintf(checkpoints_buf, "%lld", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1523", "-1", checkpoints_buf);
      if (bytes_in != -1LL) {
        bytes_in += 8LL;



        tmp = read(ifd___0, (void *)((char *)(buf)), sizeof(buf));


        if ((unsigned int )tmp != sizeof(buf)) {

          read_error();

        } else {

        }
        crc = (ulg )((int )((ush )buf[0]) | ((int )((ush )buf[1]) << 8)) | ((ulg )((int )((ush )*((buf + 2) + 0)) | ((int )((ush )*((buf + 2) + 1)) << 8)) << 16);

        bytes_out = (off_t )((ulg )((int )((ush )*((buf + 4) + 0)) | ((int )((ush )*((buf + 4) + 1)) << 8)) | ((ulg )((int )((ush )*(((buf + 4) + 2) + 0)) | ((int )((ush )*(((buf + 4) + 2) + 1)) << 8)) << 16));

      } else {

      }

      sprintf(checkpoints_buf, "%lld", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1523", "-1", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", last_member);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1521", "last_member", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", method___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1520", "method___0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1520", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1534", "verbose", checkpoints_buf);
  if (verbose) {


    tmp___0 = localtime((time_t const   *)(& time_stamp.tv_sec));


    tm = tmp___0;


    printf((char const   */* __restrict  */)"%5s %08lx ", methods[method___0],
           crc);


    if (tm) {

      printf((char const   */* __restrict  */)"%s%3d %02d:%02d ",
             "Jan\000Feb\000Mar\000Apr\000May\000Jun\000Jul\000Aug\000Sep\000Oct\000Nov\000Dec" + 4 * tm->tm_mon,
             tm->tm_mday, tm->tm_hour, tm->tm_min);

    } else {

      printf((char const   */* __restrict  */)"??? ?? ??:?? ");

    }

  } else {

  }
  sprintf(checkpoints_buf, "%d", verbose);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1534", "verbose", checkpoints_buf);

  fprint_off(stdout, bytes_in, positive_off_t_width);


  printf((char const   */* __restrict  */)" ");


  fprint_off(stdout, bytes_out, positive_off_t_width);


  printf((char const   */* __restrict  */)" ");


  sprintf(checkpoints_buf, "%lld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1546", "-1", checkpoints_buf);
  if (bytes_in == -1LL) {
    total_in = (off_t )-1L;

    header_bytes = (off_t )0;

    bytes_out = header_bytes;

    bytes_in = bytes_out;

  } else {

    sprintf(checkpoints_buf, "%lld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1551", "0", checkpoints_buf);
    if (total_in >= 0LL) {
      total_in += bytes_in;

    } else {

    }

    sprintf(checkpoints_buf, "%lld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1551", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1546", "-1", checkpoints_buf);

  sprintf(checkpoints_buf, "%lld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1554", "-1", checkpoints_buf);
  if (bytes_out == -1LL) {
    total_out = (off_t )-1L;

    header_bytes = (off_t )0;

    bytes_out = header_bytes;

    bytes_in = bytes_out;

  } else {

    sprintf(checkpoints_buf, "%lld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1559", "0", checkpoints_buf);
    if (total_out >= 0LL) {
      total_out += bytes_out;

    } else {

    }

    sprintf(checkpoints_buf, "%lld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1559", "0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%lld", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1554", "-1", checkpoints_buf);

  display_ratio(bytes_out - (bytes_in - header_bytes), bytes_out, stdout);


  printf((char const   */* __restrict  */)" %s\n", ofname);

  return;
}
}
static void shorten_name(char *name ) 
{ 
  int len ;
  char *trunc ;
  int plen ;
  int min_part ;
  char *p ;
  size_t tmp ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___3 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  char __r0 ;
  char __r1 ;
  char __r2 ;
  unsigned int tmp___7 ;
  size_t tmp___8 ;
  size_t __attribute__((__gnu_inline__))  tmp___9 ;
  size_t __attribute__((__gnu_inline__))  tmp___10 ;
  size_t __attribute__((__gnu_inline__))  tmp___11 ;
  unsigned int tmp___12 ;
  size_t __attribute__((__gnu_inline__))  tmp___13 ;
  size_t __attribute__((__gnu_inline__))  tmp___14 ;
  size_t __attribute__((__gnu_inline__))  tmp___15 ;
  size_t tmp___16 ;
  unsigned int tmp___17 ;
  char *tmp___18 ;

  {
  trunc = (char *)((void *)0);

  min_part = 3;
  sprintf(checkpoints_buf, "%d", min_part);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1566", "min_part", checkpoints_buf);


  tmp = strlen((char const   *)name);


  len = (int )tmp;
  sprintf(checkpoints_buf, "%d", len);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1568", "len", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1569", "decompress", checkpoints_buf);
  if (decompress) {
    sprintf(checkpoints_buf, "%d", len);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1570", "len", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1570", "1", checkpoints_buf);
    if (len <= 1) {

      gzip_error((char *)"name too short");

    } else {

    }
    sprintf(checkpoints_buf, "%d", len);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1570", "len", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1570", "1", checkpoints_buf);
    *(name + (len - 1)) = (char )'\000';

    return;
  } else {

  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1569", "decompress", checkpoints_buf);


  p = get_suffix(name);



  if (! p) {

    gzip_error((char *)"can\'t recover suffix\n");

  } else {

  }

  *p = (char )'\000';

  save_orig_name = 1;
  sprintf(checkpoints_buf, "%d", save_orig_name);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1581", "save_orig_name", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", len);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1582", "len", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1582", "4", checkpoints_buf);
  if (len > 4) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1583", "0", checkpoints_buf);
    if (0) {


      __s1_len = strlen((char const   *)(p - 4));




      __s2_len = strlen(".tar");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1586", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)((p - 4) + 1)) - (size_t )((void const   *)(p - 4)) == 1U)) {
        goto _L___0;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1588", "4", checkpoints_buf);
        if (__s1_len >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1589", "1", checkpoints_buf);
          _L___0: /* CIL Label */ 
          if (! ((size_t )((void const   *)(".tar" + 1)) - (size_t )((void const   *)".tar") == 1U)) {
            tmp___6 = 1;
            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1590", "tmp___6", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1591", "4", checkpoints_buf);
            if (__s2_len >= 4U) {
              tmp___6 = 1;
              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1592", "tmp___6", checkpoints_buf);
            } else {
              tmp___6 = 0;
              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1593", "tmp___6", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1591", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1589", "1", checkpoints_buf);
        } else {
          tmp___6 = 0;
          sprintf(checkpoints_buf, "%d", tmp___6);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1594", "tmp___6", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1588", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1586", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1595", "tmp___6", checkpoints_buf);
      if (tmp___6) {
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1596", "tmp___1", checkpoints_buf);

        tmp___1 = __builtin_strcmp((char const   *)(p - 4), ".tar");
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1596", "tmp___1", checkpoints_buf);

        tmp___5 = tmp___1;
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1597", "tmp___5", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1598", "tmp___4", checkpoints_buf);

        tmp___4 = __builtin_strcmp((char const   *)(p - 4), ".tar");
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1598", "tmp___4", checkpoints_buf);

        tmp___5 = tmp___4;
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1599", "tmp___5", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1595", "tmp___6", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1600", "tmp___4", checkpoints_buf);

      tmp___4 = __builtin_strcmp((char const   *)(p - 4), ".tar");
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1600", "tmp___4", checkpoints_buf);

      tmp___5 = tmp___4;
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1601", "tmp___5", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1583", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1602", "tmp___5", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1602", "0", checkpoints_buf);
    if (tmp___5 == 0) {

      strcpy((char */* __restrict  */)(p - 4),
             (char const   */* __restrict  */)".tgz");

      return;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1602", "tmp___5", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1602", "0", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", len);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1582", "len", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1582", "4", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", tmp___17);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "tmp___17", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", plen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "plen", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", plen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "plen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", min_part);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "min_part", checkpoints_buf);

  while (1) {


    p = strrchr((char const   *)name, '/');



    if (p) {
      p ++;

    } else {
      p = name;

    }


    sprintf(checkpoints_buf, "%u", tmp___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "tmp___17", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", plen);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "plen", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", plen);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "plen", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", min_part);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "min_part", checkpoints_buf);

    while (*p) {

      sprintf(checkpoints_buf, "%u", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1616", "tmp___17", checkpoints_buf);

      tmp___17 = __builtin_strcspn((char const   *)p, ".");
      sprintf(checkpoints_buf, "%u", tmp___17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1616", "tmp___17", checkpoints_buf);

      plen = (int )tmp___17;
      sprintf(checkpoints_buf, "%d", plen);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1617", "plen", checkpoints_buf);
      p += plen;

      sprintf(checkpoints_buf, "%d", plen);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1619", "plen", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", min_part);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1619", "min_part", checkpoints_buf);
      if (plen > min_part) {
        trunc = p - 1;

      } else {

      }
      sprintf(checkpoints_buf, "%d", plen);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1619", "plen", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", min_part);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1619", "min_part", checkpoints_buf);

      if (*p) {
        p ++;

      } else {

      }

    }

    sprintf(checkpoints_buf, "%u", tmp___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "tmp___17", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", plen);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "plen", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", plen);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "plen", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", min_part);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1612", "min_part", checkpoints_buf);

    if ((unsigned int )trunc == (unsigned int )((void *)0)) {
      min_part --;
      sprintf(checkpoints_buf, "%d", min_part);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1626", "min_part", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", min_part);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1627", "min_part", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1627", "0", checkpoints_buf);
      if (min_part != 0) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%d", min_part);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1627", "min_part", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1627", "0", checkpoints_buf);
    } else {
      break;
    }
  }




  sprintf(checkpoints_buf, "%u", tmp___17);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "tmp___17", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", plen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "plen", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", plen);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "plen", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", min_part);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1607", "min_part", checkpoints_buf);

  if ((unsigned int )trunc != (unsigned int )((void *)0)) {




    while (1) {
      *(trunc + 0) = *(trunc + 1);

      tmp___18 = trunc;

      trunc ++;


      if (*tmp___18) {

      } else {
        break;
      }

    }




    trunc --;

  } else {


    trunc = strrchr((char const   *)name, (int )*("." + 0));



    if (! trunc) {

      gzip_error((char *)"internal error in shorten_name");

    } else {

    }

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1644", "0", checkpoints_buf);
    if ((int )*(trunc + 1) == 0) {
      trunc --;

    } else {

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1644", "0", checkpoints_buf);
  }

  strcpy((char */* __restrict  */)trunc,
         (char const   */* __restrict  */)z_suffix);

  return;
}
}
static int check_ofname(void) 
{ 
  int ok ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;

  {
  sprintf(checkpoints_buf, "%d", force);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1649", "force", checkpoints_buf);
  if (! force) {
    ok = 0;
    sprintf(checkpoints_buf, "%d", ok);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1650", "ok", checkpoints_buf);

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s: %s already exists;",
            program_name, ofname);

    sprintf(checkpoints_buf, "%d", foreground);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1652", "foreground", checkpoints_buf);
    if (foreground) {
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1653", "tmp", checkpoints_buf);

      tmp = fileno(stdin);
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1653", "tmp", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1654", "tmp___0", checkpoints_buf);

      tmp___0 = isatty(tmp);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1654", "tmp___0", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1655", "tmp___0", checkpoints_buf);
      if (tmp___0) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)" do you wish to overwrite (y or n)? ");


        rpl_fflush(stderr);

        sprintf(checkpoints_buf, "%d", ok);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1658", "ok", checkpoints_buf);

        ok = yesno();
        sprintf(checkpoints_buf, "%d", ok);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1658", "ok", checkpoints_buf);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1655", "tmp___0", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", foreground);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1652", "foreground", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", ok);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1661", "ok", checkpoints_buf);
    if (! ok) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"\tnot overwritten\n");

      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1663", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1663", "0", checkpoints_buf);
      if (exit_code == 0) {
        exit_code = 2;
        sprintf(checkpoints_buf, "%d", exit_code);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1664", "exit_code", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1663", "exit_code", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1663", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1666", "1", checkpoints_buf);
      return (1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", ok);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1661", "ok", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", force);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1649", "force", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1669", "tmp___1", checkpoints_buf);

  tmp___1 = xunlink(ofname);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1669", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1670", "tmp___1", checkpoints_buf);
  if (tmp___1) {

    progerror(ofname);

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1672", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1670", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1674", "0", checkpoints_buf);
  return (0);
}
}
static void copy_stat(struct stat *ifstat ) 
{ 
  mode_t mode ;
  int r ;
  struct timespec timespec[2] ;
  int e ;
  int *tmp ;
  int *tmp___0 ;
  int tmp___1 ;
  int e___0 ;
  int *tmp___2 ;
  int *tmp___3 ;

  {
  mode = ifstat->st_mode & (unsigned int )((448 | (448 >> 3)) | ((448 >> 3) >> 3));



  timespec[0] = get_stat_atime((struct stat  const  *)ifstat);




  timespec[1] = get_stat_mtime((struct stat  const  *)ifstat);


  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1678", "decompress", checkpoints_buf);
  if (decompress) {
    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1679", "0", checkpoints_buf);

    if (0L <= time_stamp.tv_nsec) {


      if (timespec[1].tv_sec == time_stamp.tv_sec) {


        if (timespec[1].tv_nsec == time_stamp.tv_nsec) {

        } else {
          goto _L;
        }


      } else {
        _L: /* CIL Label */ 
        timespec[1] = time_stamp;

        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1685", "verbose", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1685", "1", checkpoints_buf);
        if (verbose > 1) {

          fprintf((FILE */* __restrict  */)stderr,
                  (char const   */* __restrict  */)"%s: time stamp restored\n",
                  ofname);

        } else {

        }
        sprintf(checkpoints_buf, "%d", verbose);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1685", "verbose", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1685", "1", checkpoints_buf);
      }


    } else {

    }
    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1679", "0", checkpoints_buf);

  } else {

  }
  sprintf(checkpoints_buf, "%d", decompress);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1678", "decompress", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1690", "tmp___1", checkpoints_buf);

  tmp___1 = gl_futimens(ofd, (char const   *)(ofname),
                        (struct timespec  const  *)(timespec));
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1690", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1691", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1691", "0", checkpoints_buf);
  if (tmp___1 != 0) {


    tmp = __errno_location();


    e = *tmp;
    sprintf(checkpoints_buf, "%d", e);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1693", "e", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1694", "quiet", checkpoints_buf);
    if (! quiet) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: ", program_name);

    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1694", "quiet", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1697", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1697", "0", checkpoints_buf);
    if (exit_code == 0) {
      exit_code = 2;
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1698", "exit_code", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1697", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1697", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1700", "quiet", checkpoints_buf);
    if (! quiet) {


      tmp___0 = __errno_location();


      *tmp___0 = e;


      perror((char const   *)(ofname));

    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1700", "quiet", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1691", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1691", "0", checkpoints_buf);

  fchown(ofd, ifstat->st_uid, ifstat->st_gid);

  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1707", "r", checkpoints_buf);

  r = fchmod(ofd, mode);
  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1707", "r", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1708", "r", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1708", "0", checkpoints_buf);
  if (r != 0) {


    tmp___2 = __errno_location();


    e___0 = *tmp___2;
    sprintf(checkpoints_buf, "%d", e___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1710", "e___0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1711", "quiet", checkpoints_buf);
    if (! quiet) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: ", program_name);

    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1711", "quiet", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1714", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1714", "0", checkpoints_buf);
    if (exit_code == 0) {
      exit_code = 2;
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1715", "exit_code", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", exit_code);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1714", "exit_code", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1714", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1717", "quiet", checkpoints_buf);
    if (! quiet) {


      tmp___3 = __errno_location();


      *tmp___3 = e___0;


      perror((char const   *)(ofname));

    } else {

    }
    sprintf(checkpoints_buf, "%d", quiet);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1717", "quiet", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", r);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1708", "r", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1708", "0", checkpoints_buf);
  return;
}
}
static void treat_dir(int fd , char *dir ) 
{ 
  struct dirent *dp ;
  DIR *dirp ;
  char nbuf[1024] ;
  int len ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___2 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  size_t __s1_len___0 ;
  size_t __s2_len___0 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  unsigned char const   *__s2___0 ;
  register int __result___1 ;
  int tmp___9 ;
  unsigned char const   *__s1___0 ;
  register int __result___2 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  size_t tmp___13 ;
  int tmp___14 ;
  size_t tmp___15 ;
  int *tmp___16 ;
  int *tmp___17 ;
  int tmp___18 ;

  {


  dirp = fdopendir(fd);


  if ((unsigned int )dirp == (unsigned int )((void *)0)) {

    progerror(dir);


    close(fd);

    return;
  } else {

  }





  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "0", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", len);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "len", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1023);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "1023", checkpoints_buf);
  while (1) {


    tmp___16 = __errno_location();


    *tmp___16 = 0;



    dp = readdir(dirp);


    if ((unsigned int )dp != (unsigned int )((void *)0)) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1737", "0", checkpoints_buf);
    if (0) {


      __s1_len = strlen((char const   *)(dp->d_name));




      __s2_len = strlen(".");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1740", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(dp->d_name + 1)) - (size_t )((void const   *)(dp->d_name)) == 1U)) {
        goto _L___0;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1742", "4", checkpoints_buf);
        if (__s1_len >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1743", "1", checkpoints_buf);
          _L___0: /* CIL Label */ 
          if (! ((size_t )((void const   *)("." + 1)) - (size_t )((void const   *)".") == 1U)) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1744", "tmp___5", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1745", "4", checkpoints_buf);
            if (__s2_len >= 4U) {
              tmp___5 = 1;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1746", "tmp___5", checkpoints_buf);
            } else {
              tmp___5 = 0;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1747", "tmp___5", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1745", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1743", "1", checkpoints_buf);
        } else {
          tmp___5 = 0;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1748", "tmp___5", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1742", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1740", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1749", "tmp___5", checkpoints_buf);
      if (tmp___5) {
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1750", "tmp___0", checkpoints_buf);

        tmp___0 = __builtin_strcmp((char const   *)(dp->d_name), ".");
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1750", "tmp___0", checkpoints_buf);

        tmp___4 = tmp___0;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1751", "tmp___4", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1752", "tmp___3", checkpoints_buf);

        tmp___3 = __builtin_strcmp((char const   *)(dp->d_name), ".");
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1752", "tmp___3", checkpoints_buf);

        tmp___4 = tmp___3;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1753", "tmp___4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1749", "tmp___5", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1754", "tmp___3", checkpoints_buf);

      tmp___3 = __builtin_strcmp((char const   *)(dp->d_name), ".");
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1754", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1755", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1737", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1756", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1756", "0", checkpoints_buf);
    if (tmp___4 == 0) {
      continue;
    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1758", "0", checkpoints_buf);
      if (0) {


        __s1_len___0 = strlen((char const   *)(dp->d_name));




        __s2_len___0 = strlen("..");


        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1761", "1", checkpoints_buf);
        if (! ((size_t )((void const   *)(dp->d_name + 1)) - (size_t )((void const   *)(dp->d_name)) == 1U)) {
          goto _L___2;
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1763", "4", checkpoints_buf);
          if (__s1_len___0 >= 4U) {
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1764", "1", checkpoints_buf);
            _L___2: /* CIL Label */ 
            if (! ((size_t )((void const   *)(".." + 1)) - (size_t )((void const   *)"..") == 1U)) {
              tmp___12 = 1;
              sprintf(checkpoints_buf, "%d", tmp___12);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1765", "tmp___12", checkpoints_buf);
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1766", "4", checkpoints_buf);
              if (__s2_len___0 >= 4U) {
                tmp___12 = 1;
                sprintf(checkpoints_buf, "%d", tmp___12);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1767", "tmp___12", checkpoints_buf);
              } else {
                tmp___12 = 0;
                sprintf(checkpoints_buf, "%d", tmp___12);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                                "1768", "tmp___12", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                              "1766", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1764", "1", checkpoints_buf);
          } else {
            tmp___12 = 0;
            sprintf(checkpoints_buf, "%d", tmp___12);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                            "1769", "tmp___12", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1763", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1761", "1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1770", "tmp___12", checkpoints_buf);
        if (tmp___12) {
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1771", "tmp___7", checkpoints_buf);

          tmp___7 = __builtin_strcmp((char const   *)(dp->d_name), "..");
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1771", "tmp___7", checkpoints_buf);

          tmp___11 = tmp___7;
          sprintf(checkpoints_buf, "%d", tmp___11);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1772", "tmp___11", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___10);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1773", "tmp___10", checkpoints_buf);

          tmp___10 = __builtin_strcmp((char const   *)(dp->d_name), "..");
          sprintf(checkpoints_buf, "%d", tmp___10);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1773", "tmp___10", checkpoints_buf);

          tmp___11 = tmp___10;
          sprintf(checkpoints_buf, "%d", tmp___11);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                          "1774", "tmp___11", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1770", "tmp___12", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1775", "tmp___10", checkpoints_buf);

        tmp___10 = __builtin_strcmp((char const   *)(dp->d_name), "..");
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1775", "tmp___10", checkpoints_buf);

        tmp___11 = tmp___10;
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1776", "tmp___11", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1758", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1777", "tmp___11", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1777", "0", checkpoints_buf);
      if (tmp___11 == 0) {
        continue;
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1777", "tmp___11", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1777", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1756", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1756", "0", checkpoints_buf);


    tmp___13 = strlen((char const   *)dir);


    len = (int )tmp___13;
    sprintf(checkpoints_buf, "%d", len);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1781", "len", checkpoints_buf);


    tmp___15 = strlen((char const   *)(dp->d_name));



    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1783", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 1023);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1783", "1023", checkpoints_buf);
    if (((size_t )len + tmp___15) + 1U < 1023U) {

      strcpy((char */* __restrict  */)(nbuf),
             (char const   */* __restrict  */)dir);

      sprintf(checkpoints_buf, "%d", len);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1785", "len", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1785", "0", checkpoints_buf);
      if (len != 0) {
        tmp___14 = len;
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1786", "tmp___14", checkpoints_buf);
        len ++;
        sprintf(checkpoints_buf, "%d", len);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1787", "len", checkpoints_buf);
        nbuf[tmp___14] = (char )'/';

      } else {

      }
      sprintf(checkpoints_buf, "%d", len);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1785", "len", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1785", "0", checkpoints_buf);

      strcpy((char */* __restrict  */)(nbuf + len),
             (char const   */* __restrict  */)(dp->d_name));


      treat_file(nbuf);

    } else {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: %s/%s: pathname too long\n",
              program_name, dir, dp->d_name);

      exit_code = 1;
      sprintf(checkpoints_buf, "%d", exit_code);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1793", "exit_code", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1783", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 1023);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1783", "1023", checkpoints_buf);
  }





  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "0", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", len);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "len", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 1023);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1730", "1023", checkpoints_buf);


  tmp___17 = __errno_location();



  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1795", "0", checkpoints_buf);
  if (*tmp___17 != 0) {

    progerror(dir);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1795", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1798", "tmp___18", checkpoints_buf);

  tmp___18 = closedir(dirp);
  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1798", "tmp___18", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1799", "tmp___18", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1799", "0", checkpoints_buf);
  if (tmp___18 != 0) {

    progerror(dir);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1799", "tmp___18", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1799", "0", checkpoints_buf);
  return;
}
}
static void install_signal_handlers(void) 
{ 
  int nsigs ;
  int i ;
  struct sigaction act ;
  int tmp ;

  {
  nsigs = (int )(sizeof(handled_sig) / sizeof(handled_sig[0]));
  sprintf(checkpoints_buf, "%d", nsigs);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1803", "nsigs", checkpoints_buf);

  sigemptyset(& caught_signals);

  i = 0;
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1805", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1806", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", nsigs);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1806", "nsigs", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1806", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1807", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", nsigs);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1807", "nsigs", checkpoints_buf);
    if (i < nsigs) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1807", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", nsigs);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1807", "nsigs", checkpoints_buf);

    sigaction(handled_sig[i],
              (struct sigaction  const  */* __restrict  */)((void *)0),
              (struct sigaction */* __restrict  */)(& act));

    if ((unsigned int )act.__sigaction_handler.sa_handler != (unsigned int )((void (*)(int  ))1)) {

      sigaddset(& caught_signals, handled_sig[i]);

    } else {

    }
    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1814", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1806", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", nsigs);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1806", "nsigs", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1806", "i", checkpoints_buf);
  act.__sigaction_handler.sa_handler = & abort_gzip_signal;

  act.sa_mask = caught_signals;

  act.sa_flags = 0;

  i = 0;
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1818", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", nsigs);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "nsigs", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "tmp", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1820", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", nsigs);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1820", "nsigs", checkpoints_buf);
    if (i < nsigs) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1820", "i", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", nsigs);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1820", "nsigs", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1823", "tmp", checkpoints_buf);

    tmp = sigismember((sigset_t const   *)(& caught_signals), handled_sig[i]);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1823", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1824", "tmp", checkpoints_buf);
    if (tmp) {
      sprintf(checkpoints_buf, "%d", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1825", "i", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1825", "0", checkpoints_buf);
      if (i == 0) {
        foreground = 1;
        sprintf(checkpoints_buf, "%d", foreground);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                        "1826", "foreground", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", i);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1825", "i", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                      "1825", "0", checkpoints_buf);

      sigaction(handled_sig[i],
                (struct sigaction  const  */* __restrict  */)(& act),
                (struct sigaction */* __restrict  */)((void *)0));

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1824", "tmp", checkpoints_buf);
    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1830", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", nsigs);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "nsigs", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "tmp", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1819", "i", checkpoints_buf);
  return;
}
}
static  __attribute__((__noreturn__)) void do_exit(int exitcode ) ;
static int in_exit  =    0;
static  __attribute__((__noreturn__)) void do_exit(int exitcode ) ;
static void do_exit(int exitcode ) 
{ 


  {
  sprintf(checkpoints_buf, "%d", in_exit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1832", "in_exit", checkpoints_buf);
  if (in_exit) {

    exit(exitcode);

  } else {

  }
  sprintf(checkpoints_buf, "%d", in_exit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1832", "in_exit", checkpoints_buf);
  in_exit = 1;
  sprintf(checkpoints_buf, "%d", in_exit);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1835", "in_exit", checkpoints_buf);

  free((void *)env);

  env = (char *)((void *)0);


  free((void *)args);

  args = (char **)((void *)0);


  exit(exitcode);

}
}
static void remove_output_file(void) 
{ 
  int fd ;
  sigset_t oldset ;

  {

  sigprocmask(0, (sigset_t const   */* __restrict  */)(& caught_signals),
              (sigset_t */* __restrict  */)(& oldset));

  fd = (int )remove_ofname_fd;
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1842", "fd", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1843", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1843", "fd", checkpoints_buf);
  if (0 <= fd) {
    remove_ofname_fd = (int volatile   )-1;
    sprintf(checkpoints_buf, "%d", remove_ofname_fd);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                    "1844", "remove_ofname_fd", checkpoints_buf);

    close(fd);


    xunlink(ofname);

  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1843", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", fd);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1843", "fd", checkpoints_buf);

  sigprocmask(2, (sigset_t const   */* __restrict  */)(& oldset),
              (sigset_t */* __restrict  */)((void *)0));

  return;
}
}
 __attribute__((__noreturn__)) void abort_gzip(void) ;
void abort_gzip(void) 
{ 


  {

  remove_output_file();


  do_exit(1);

}
}
static void abort_gzip_signal(int sig ) 
{ 


  {

  remove_output_file();

  sprintf(checkpoints_buf, "%d", sig);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1853", "sig", checkpoints_buf);
  if (sig == (int )exiting_signal) {

    _exit(2);

  } else {

  }
  sprintf(checkpoints_buf, "%d", sig);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/gzip-bug-2009-09-26-a1d3d4019d-f17cbd13a1",
                  "1853", "sig", checkpoints_buf);

  signal(sig, (void (*)(int  ))0);


  raise(sig);

  return;
}
}
