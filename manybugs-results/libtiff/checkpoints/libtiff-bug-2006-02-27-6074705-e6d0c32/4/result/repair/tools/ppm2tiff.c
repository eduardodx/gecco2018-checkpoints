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
enum __anonenum_26 {
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
typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
enum __anonenum_27 {
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
enum __anonenum_28 {
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
enum __anonenum_29 {
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
enum TIFFIgnoreSense {
    TIS_STORE = 0,
    TIS_EXTRACT = 1,
    TIS_EMPTY = 2
} ;
struct __anonstruct_TIFFHeader_30 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint32 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeader_30 TIFFHeader;
struct __anonstruct_TIFFDirEntry_31 {
   uint16 tdir_tag ;
   uint16 tdir_type ;
   uint32 tdir_count ;
   uint32 tdir_offset ;
};
typedef struct __anonstruct_TIFFDirEntry_31 TIFFDirEntry;
enum __anonenum_TIFFDataType_32 {
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
    TIFF_IFD = 13
} ;
typedef enum __anonenum_TIFFDataType_32 TIFFDataType;
struct tiff;
typedef struct tiff TIFF;
typedef uint32 ttag_t;
typedef uint16 tdir_t;
typedef uint16 tsample_t;
typedef uint32 tstrip_t;
typedef uint32 ttile_t;
typedef int32 tsize_t;
typedef void *tdata_t;
typedef uint32 toff_t;
typedef void *thandle_t;
typedef unsigned char TIFFRGBValue;
struct __anonstruct_TIFFDisplay_33 {
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
typedef struct __anonstruct_TIFFDisplay_33 TIFFDisplay;
struct __anonstruct_TIFFYCbCrToRGB_34 {
   TIFFRGBValue *clamptab ;
   int *Cr_r_tab ;
   int *Cb_b_tab ;
   int32 *Cr_g_tab ;
   int32 *Cb_g_tab ;
   int32 *Y_tab ;
};
typedef struct __anonstruct_TIFFYCbCrToRGB_34 TIFFYCbCrToRGB;
struct __anonstruct_TIFFCIELabToRGB_35 {
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
typedef struct __anonstruct_TIFFCIELabToRGB_35 TIFFCIELabToRGB;
struct _TIFFRGBAImage;
typedef struct _TIFFRGBAImage TIFFRGBAImage;
typedef void (*tileContigRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                  uint32  , uint32  , uint32  , int32  ,
                                  int32  , unsigned char * );
typedef void (*tileSeparateRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                    uint32  , uint32  , uint32  , int32  ,
                                    int32  , unsigned char * , unsigned char * ,
                                    unsigned char * , unsigned char * );
union __anonunion_put_36 {
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
   union __anonunion_put_36 put ;
   TIFFRGBValue *Map ;
   uint32 **BWmap ;
   uint32 **PALmap ;
   TIFFYCbCrToRGB *ycbcr ;
   TIFFCIELabToRGB *cielab ;
   int row_offset ;
   int col_offset ;
};
typedef int (*TIFFInitMethod)(TIFF * , int  );
struct __anonstruct_TIFFCodec_37 {
   char *name ;
   uint16 scheme ;
   int (*init)(TIFF * , int  ) ;
};
typedef struct __anonstruct_TIFFCodec_37 TIFFCodec;
typedef void (*TIFFErrorHandler)(char const   * , char const   * , va_list  );
typedef void (*TIFFErrorHandlerExt)(thandle_t  , char const   * ,
                                    char const   * , va_list  );
typedef tsize_t (*TIFFReadWriteProc)(thandle_t  , tdata_t  , tsize_t  );
typedef toff_t (*TIFFSeekProc)(thandle_t  , toff_t  , int  );
typedef int (*TIFFCloseProc)(thandle_t  );
typedef toff_t (*TIFFSizeProc)(thandle_t  );
typedef int (*TIFFMapFileProc)(thandle_t  , tdata_t * , toff_t * );
typedef void (*TIFFUnmapFileProc)(thandle_t  , tdata_t  , toff_t  );
typedef void (*TIFFExtendProc)(TIFF * );
struct __anonstruct_TIFFFieldInfo_38 {
   ttag_t field_tag ;
   short field_readcount ;
   short field_writecount ;
   TIFFDataType field_type ;
   unsigned short field_bit ;
   unsigned char field_oktochange ;
   unsigned char field_passcount ;
   char *field_name ;
};
typedef struct __anonstruct_TIFFFieldInfo_38 TIFFFieldInfo;
struct _TIFFTagValue {
   TIFFFieldInfo const   *info ;
   int count ;
   void *value ;
};
typedef struct _TIFFTagValue TIFFTagValue;
typedef int (*TIFFVSetMethod)(TIFF * , ttag_t  , va_list  );
typedef int (*TIFFVGetMethod)(TIFF * , ttag_t  , va_list  );
typedef void (*TIFFPrintMethod)(TIFF * , FILE * , long  );
struct __anonstruct_TIFFTagMethods_39 {
   int (*vsetfield)(TIFF * , ttag_t  , va_list  ) ;
   int (*vgetfield)(TIFF * , ttag_t  , va_list  ) ;
   void (*printdir)(TIFF * , FILE * , long  ) ;
};
typedef struct __anonstruct_TIFFTagMethods_39 TIFFTagMethods;
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
__inline extern  __attribute__((__nothrow__)) int tolower(int __c ) ;
__inline extern  __attribute__((__nothrow__)) int toupper(int __c ) ;
extern  __attribute__((__nothrow__)) int isblank(int  ) ;
extern  __attribute__((__nothrow__)) int isascii(int __c ) ;
extern  __attribute__((__nothrow__)) int toascii(int __c ) ;
extern  __attribute__((__nothrow__)) int _toupper(int  ) ;
extern  __attribute__((__nothrow__)) int _tolower(int  ) ;
__inline extern  __attribute__((__nothrow__)) int tolower(int __c ) ;
__inline extern int tolower(int __c ) 
{ 
  __int32_t const   **tmp ;
  __int32_t tmp___0 ;

  {
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "251", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "251", "-128", checkpoints_buf);
  if (__c >= -128) {
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "252", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "252", "256", checkpoints_buf);
    if (__c < 256) {


      tmp = __ctype_tolower_loc();


      tmp___0 = *(*tmp + __c);

    } else {
      tmp___0 = (__int32_t const   )__c;

    }
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "252", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "252", "256", checkpoints_buf);
  } else {
    tmp___0 = (__int32_t const   )__c;

  }
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "251", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "251", "-128", checkpoints_buf);
  return ((int )tmp___0);
}
}
__inline extern  __attribute__((__nothrow__)) int toupper(int __c ) ;
__inline extern int toupper(int __c ) 
{ 
  __int32_t const   **tmp ;
  __int32_t tmp___0 ;

  {
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "258", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "258", "-128", checkpoints_buf);
  if (__c >= -128) {
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "259", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "259", "256", checkpoints_buf);
    if (__c < 256) {


      tmp = __ctype_toupper_loc();


      tmp___0 = *(*tmp + __c);

    } else {
      tmp___0 = (__int32_t const   )__c;

    }
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "259", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "259", "256", checkpoints_buf);
  } else {
    tmp___0 = (__int32_t const   )__c;

  }
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "258", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "258", "-128", checkpoints_buf);
  return ((int )tmp___0);
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
extern tdata_t _TIFFmalloc(tsize_t  ) ;
extern tdata_t _TIFFrealloc(tdata_t  , tsize_t  ) ;
extern void _TIFFmemset(tdata_t  , int  , tsize_t  ) ;
extern void _TIFFmemcpy(tdata_t  , tdata_t const    , tsize_t  ) ;
extern int _TIFFmemcmp(tdata_t const    , tdata_t const    , tsize_t  ) ;
extern void _TIFFfree(tdata_t  ) ;
extern int TIFFGetTagListCount(TIFF * ) ;
extern ttag_t TIFFGetTagListEntry(TIFF * , int tag_index ) ;
extern void TIFFMergeFieldInfo(TIFF * , TIFFFieldInfo const   * , int  ) ;
extern TIFFFieldInfo const   *TIFFFindFieldInfo(TIFF * , ttag_t  ,
                                                TIFFDataType  ) ;
extern TIFFFieldInfo const   *TIFFFindFieldInfoByName(TIFF * , char const   * ,
                                                      TIFFDataType  ) ;
extern TIFFFieldInfo const   *TIFFFieldWithTag(TIFF * , ttag_t  ) ;
extern TIFFFieldInfo const   *TIFFFieldWithName(TIFF * , char const   * ) ;
extern TIFFTagMethods *TIFFAccessTagMethods(TIFF * ) ;
extern void *TIFFGetClientInfo(TIFF * , char const   * ) ;
extern void TIFFSetClientInfo(TIFF * , void * , char const   * ) ;
extern void TIFFCleanup(TIFF * ) ;
extern void TIFFClose(TIFF * ) ;
extern int TIFFFlush(TIFF * ) ;
extern int TIFFFlushData(TIFF * ) ;
extern int TIFFGetField(TIFF * , ttag_t   , ...) ;
extern int TIFFVGetField(TIFF * , ttag_t  , va_list  ) ;
extern int TIFFGetFieldDefaulted(TIFF * , ttag_t   , ...) ;
extern int TIFFVGetFieldDefaulted(TIFF * , ttag_t  , va_list  ) ;
extern int TIFFReadDirectory(TIFF * ) ;
extern int TIFFReadCustomDirectory(TIFF * , toff_t  , TIFFFieldInfo const   * ,
                                   size_t  ) ;
extern int TIFFReadEXIFDirectory(TIFF * , toff_t  ) ;
extern tsize_t TIFFScanlineSize(TIFF * ) ;
extern tsize_t TIFFRasterScanlineSize(TIFF * ) ;
extern tsize_t TIFFStripSize(TIFF * ) ;
extern tsize_t TIFFRawStripSize(TIFF * , tstrip_t  ) ;
extern tsize_t TIFFVStripSize(TIFF * , uint32  ) ;
extern tsize_t TIFFTileRowSize(TIFF * ) ;
extern tsize_t TIFFTileSize(TIFF * ) ;
extern tsize_t TIFFVTileSize(TIFF * , uint32  ) ;
extern uint32 TIFFDefaultStripSize(TIFF * , uint32  ) ;
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
extern tdir_t TIFFCurrentDirectory(TIFF * ) ;
extern tdir_t TIFFNumberOfDirectories(TIFF * ) ;
extern uint32 TIFFCurrentDirOffset(TIFF * ) ;
extern tstrip_t TIFFCurrentStrip(TIFF * ) ;
extern ttile_t TIFFCurrentTile(TIFF * ) ;
extern int TIFFReadBufferSetup(TIFF * , tdata_t  , tsize_t  ) ;
extern int TIFFWriteBufferSetup(TIFF * , tdata_t  , tsize_t  ) ;
extern int TIFFSetupStrips(TIFF * ) ;
extern int TIFFWriteCheck(TIFF * , int  , char const   * ) ;
extern void TIFFFreeDirectory(TIFF * ) ;
extern int TIFFCreateDirectory(TIFF * ) ;
extern int TIFFLastDirectory(TIFF * ) ;
extern int TIFFSetDirectory(TIFF * , tdir_t  ) ;
extern int TIFFSetSubDirectory(TIFF * , uint32  ) ;
extern int TIFFUnlinkDirectory(TIFF * , tdir_t  ) ;
extern int TIFFSetField(TIFF * , ttag_t   , ...) ;
extern int TIFFVSetField(TIFF * , ttag_t  , va_list  ) ;
extern int TIFFWriteDirectory(TIFF * ) ;
extern int TIFFCheckpointDirectory(TIFF * ) ;
extern int TIFFRewriteDirectory(TIFF * ) ;
extern int TIFFReassignTagToIgnore(enum TIFFIgnoreSense  , int  ) ;
extern void TIFFPrintDirectory(TIFF * , FILE * , long  ) ;
extern int TIFFReadScanline(TIFF * , tdata_t  , uint32  , tsample_t  ) ;
extern int TIFFWriteScanline(TIFF * , tdata_t  , uint32  , tsample_t  ) ;
extern int TIFFReadRGBAImage(TIFF * , uint32  , uint32  , uint32 * , int  ) ;
extern int TIFFReadRGBAImageOriented(TIFF * , uint32  , uint32  , uint32 * ,
                                     int  , int  ) ;
extern int TIFFReadRGBAStrip(TIFF * , tstrip_t  , uint32 * ) ;
extern int TIFFReadRGBATile(TIFF * , uint32  , uint32  , uint32 * ) ;
extern int TIFFRGBAImageOK(TIFF * , char * ) ;
extern int TIFFRGBAImageBegin(TIFFRGBAImage * , TIFF * , int  , char * ) ;
extern int TIFFRGBAImageGet(TIFFRGBAImage * , uint32 * , uint32  , uint32  ) ;
extern void TIFFRGBAImageEnd(TIFFRGBAImage * ) ;
extern TIFF *TIFFOpen(char const   * , char const   * ) ;
extern TIFF *TIFFFdOpen(int  , char const   * , char const   * ) ;
extern TIFF *TIFFClientOpen(char const   * , char const   * , thandle_t  ,
                            tsize_t (*)(thandle_t  , tdata_t  , tsize_t  ) ,
                            tsize_t (*)(thandle_t  , tdata_t  , tsize_t  ) ,
                            toff_t (*)(thandle_t  , toff_t  , int  ) ,
                            int (*)(thandle_t  ) , toff_t (*)(thandle_t  ) ,
                            int (*)(thandle_t  , tdata_t * , toff_t * ) ,
                            void (*)(thandle_t  , tdata_t  , toff_t  ) ) ;
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
extern ttile_t TIFFComputeTile(TIFF * , uint32  , uint32  , uint32  ,
                               tsample_t  ) ;
extern int TIFFCheckTile(TIFF * , uint32  , uint32  , uint32  , tsample_t  ) ;
extern ttile_t TIFFNumberOfTiles(TIFF * ) ;
extern tsize_t TIFFReadTile(TIFF * , tdata_t  , uint32  , uint32  , uint32  ,
                            tsample_t  ) ;
extern tsize_t TIFFWriteTile(TIFF * , tdata_t  , uint32  , uint32  , uint32  ,
                             tsample_t  ) ;
extern tstrip_t TIFFComputeStrip(TIFF * , uint32  , tsample_t  ) ;
extern tstrip_t TIFFNumberOfStrips(TIFF * ) ;
extern tsize_t TIFFReadEncodedStrip(TIFF * , tstrip_t  , tdata_t  , tsize_t  ) ;
extern tsize_t TIFFReadRawStrip(TIFF * , tstrip_t  , tdata_t  , tsize_t  ) ;
extern tsize_t TIFFReadEncodedTile(TIFF * , ttile_t  , tdata_t  , tsize_t  ) ;
extern tsize_t TIFFReadRawTile(TIFF * , ttile_t  , tdata_t  , tsize_t  ) ;
extern tsize_t TIFFWriteEncodedStrip(TIFF * , tstrip_t  , tdata_t  , tsize_t  ) ;
extern tsize_t TIFFWriteRawStrip(TIFF * , tstrip_t  , tdata_t  , tsize_t  ) ;
extern tsize_t TIFFWriteEncodedTile(TIFF * , ttile_t  , tdata_t  , tsize_t  ) ;
extern tsize_t TIFFWriteRawTile(TIFF * , ttile_t  , tdata_t  , tsize_t  ) ;
extern int TIFFDataWidth(TIFFDataType  ) ;
extern void TIFFSetWriteOffset(TIFF * , toff_t  ) ;
extern void TIFFSwabShort(uint16 * ) ;
extern void TIFFSwabLong(uint32 * ) ;
extern void TIFFSwabDouble(double * ) ;
extern void TIFFSwabArrayOfShort(uint16 * , unsigned long  ) ;
extern void TIFFSwabArrayOfTriples(uint8 * , unsigned long  ) ;
extern void TIFFSwabArrayOfLong(uint32 * , unsigned long  ) ;
extern void TIFFSwabArrayOfDouble(double * , unsigned long  ) ;
extern void TIFFReverseBits(unsigned char * , unsigned long  ) ;
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
static uint16 compression  =    (uint16 )32773;
static uint16 predictor  =    (uint16 )0;
static int quality  =    75;
static int jpegcolormode  =    1;
static void usage(void) ;
static int processCompressOptions(char *opt ) ;
static void BadPPM(char *file ) 
{ 


  {

  fprintf((FILE */* __restrict  */)stderr,
          (char const   */* __restrict  */)"%s: Not a PPM file.\n", file);


}
}
int main(int argc , char **argv ) 
{ 
  uint16 photometric ;
  uint32 rowsperstrip ;
  double resolution ;
  unsigned char *buf ;
  tsize_t linebytes ;
  uint16 spp ;
  TIFF *out ;
  FILE *in ;
  unsigned int w ;
  unsigned int h ;
  unsigned int prec ;
  unsigned int row ;
  char *infile ;
  int c ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  void *tmp___5 ;
  char *tmp___6 ;
  void *tmp___7 ;
  char *tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  tdata_t tmp___12 ;
  tsize_t tmp___13 ;
  tdata_t tmp___14 ;
  tsize_t tmp___15 ;
  uint32 tmp___16 ;
  size_t tmp___17 ;
  int tmp___18 ;

  {
  photometric = (uint16 )0;

  rowsperstrip = (uint32 )-1;

  resolution = (double )-1;
  sprintf(checkpoints_buf, "%lf", resolution);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "269", "resolution", checkpoints_buf);
  buf = (unsigned char *)((void *)0);

  spp = (uint16 )1;

  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "272", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "272", "2", checkpoints_buf);
  if (argc < 2) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s: Too few arguments\n",
            *(argv + 0));


    usage();

  } else {

  }
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "272", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "272", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "276", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "276", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "276", "-1", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "277", "c", checkpoints_buf);

    c = getopt(argc, (char * const  *)argv, "c:r:R:");
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "277", "c", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "278", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "278", "-1", checkpoints_buf);
    if (c != -1) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "278", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "278", "-1", checkpoints_buf);
    switch (c) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "282", "tmp", checkpoints_buf);

    case 99: 
    tmp = processCompressOptions(optarg);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "282", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "283", "tmp", checkpoints_buf);
    if (tmp) {

    } else {

      usage();

    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "283", "tmp", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "287", "tmp___0", checkpoints_buf);

    case 114: 
    tmp___0 = atoi((char const   *)optarg);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "287", "tmp___0", checkpoints_buf);

    rowsperstrip = (uint32 )tmp___0;

    break;
    sprintf(checkpoints_buf, "%lf", resolution);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "290", "resolution", checkpoints_buf);

    case 82: 
    resolution = atof((char const   *)optarg);
    sprintf(checkpoints_buf, "%lf", resolution);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "290", "resolution", checkpoints_buf);

    break;

    case 63: 
    usage();

    }
  }
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "276", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "276", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "276", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "293", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "293", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "293", "argc", checkpoints_buf);
  if (optind + 2 < argc) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s: Too many arguments\n",
            *(argv + 0));


    usage();

  } else {

  }
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "293", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "293", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "293", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "297", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "297", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "297", "1", checkpoints_buf);
  if (argc - optind > 1) {
    tmp___1 = optind;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "298", "tmp___1", checkpoints_buf);
    optind ++;
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "299", "optind", checkpoints_buf);
    infile = *(argv + tmp___1);



    in = fopen((char const   */* __restrict  */)infile,
               (char const   */* __restrict  */)"r");


    if ((unsigned int )in == (unsigned int )((void *)0)) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: Can not open.\n", infile);

      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "304", "-1", checkpoints_buf);
      return (-1);
    } else {

    }
  } else {
    infile = (char *)"<stdin>";

    in = stdin;

  }
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "297", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "297", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "297", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "308", "tmp___2", checkpoints_buf);

  tmp___2 = fgetc(in);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "308", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "309", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 80);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "309", "80", checkpoints_buf);
  if (tmp___2 != 80) {

    BadPPM(infile);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "309", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 80);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "309", "80", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "312", "tmp___3", checkpoints_buf);

  tmp___3 = fgetc(in);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "312", "tmp___3", checkpoints_buf);

  switch (tmp___3) {
  case 53: 
  spp = (uint16 )1;

  photometric = (uint16 )1;

  break;
  case 54: 
  spp = (uint16 )3;

  photometric = (uint16 )2;

  sprintf(checkpoints_buf, "%d", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "319", "7", checkpoints_buf);
  if ((int )compression == 7) {
    sprintf(checkpoints_buf, "%d", jpegcolormode);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "320", "jpegcolormode", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "320", "1", checkpoints_buf);
    if (jpegcolormode == 1) {
      photometric = (uint16 )6;

    } else {

    }
    sprintf(checkpoints_buf, "%d", jpegcolormode);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "320", "jpegcolormode", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "320", "1", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "319", "7", checkpoints_buf);
  break;

  default: 
  BadPPM(infile);

  }
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "c", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 35);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "35", checkpoints_buf);

  while (1) {
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "327", "tmp___4", checkpoints_buf);

    tmp___4 = feof(in);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "327", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "328", "tmp___4", checkpoints_buf);
    if (tmp___4) {

      BadPPM(infile);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "328", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "331", "c", checkpoints_buf);

    c = fgetc(in);
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "331", "c", checkpoints_buf);



    tmp___6 = __builtin_strchr((char *)" \t\r\n", c);



    if (tmp___6) {
      continue;
    } else {

    }

    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "336", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 35);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "336", "35", checkpoints_buf);
    if (c == 35) {
      sprintf(checkpoints_buf, "%d", c);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "337", "c", checkpoints_buf);




      while (1) {
        sprintf(checkpoints_buf, "%d", c);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "338", "c", checkpoints_buf);

        c = fgetc(in);
        sprintf(checkpoints_buf, "%d", c);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "338", "c", checkpoints_buf);



        tmp___8 = __builtin_strchr((char *)"\r\n", c);



        if (tmp___8) {
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "341", "tmp___9", checkpoints_buf);

          tmp___9 = feof(in);
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "341", "tmp___9", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "342", "tmp___9", checkpoints_buf);
          if (tmp___9) {

          } else {
            break;
          }
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "342", "tmp___9", checkpoints_buf);
        } else {

        }

      }
      sprintf(checkpoints_buf, "%d", c);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "337", "c", checkpoints_buf);




      continue;
    } else {

    }
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "336", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 35);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "336", "35", checkpoints_buf);

    ungetc(c, in);

    break;
  }
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "c", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 35);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "326", "35", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "350", "tmp___10", checkpoints_buf);

  tmp___10 = fscanf((FILE */* __restrict  */)in,
                    (char const   */* __restrict  */)" %u %u %u", & w, & h,
                    & prec);
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "350", "tmp___10", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "351", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "351", "3", checkpoints_buf);
  if (tmp___10 != 3) {

    BadPPM(infile);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "351", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "351", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "354", "tmp___11", checkpoints_buf);

  tmp___11 = fgetc(in);
  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "354", "tmp___11", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "355", "tmp___11", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "355", "10", checkpoints_buf);
  if (tmp___11 != 10) {

    BadPPM(infile);

  } else {
    sprintf(checkpoints_buf, "%u", prec);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "357", "prec", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "357", "255", checkpoints_buf);
    if (prec != 255U) {

      BadPPM(infile);

    } else {

    }
    sprintf(checkpoints_buf, "%u", prec);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "357", "prec", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 255);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "357", "255", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___11);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "355", "tmp___11", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "355", "10", checkpoints_buf);


  out = TIFFOpen((char const   *)*(argv + optind), "w");


  if ((unsigned int )out == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", -4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "362", "-4", checkpoints_buf);
    return (-4);
  } else {

  }

  TIFFSetField(out, (ttag_t )256, w);


  TIFFSetField(out, (ttag_t )257, h);


  TIFFSetField(out, (ttag_t )274, 1);


  TIFFSetField(out, (ttag_t )277, (int )spp);


  TIFFSetField(out, (ttag_t )258, 8);


  TIFFSetField(out, (ttag_t )284, 1);


  TIFFSetField(out, (ttag_t )262, (int )photometric);


  TIFFSetField(out, (ttag_t )259, (int )compression);

  switch ((int )compression) {

  case 7: 
  TIFFSetField(out, (ttag_t )65537, quality);


  TIFFSetField(out, (ttag_t )65538, jpegcolormode);

  break;
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "376", "0", checkpoints_buf);
  case 32946: 
  case 5: 
  if ((int )predictor != 0) {

    TIFFSetField(out, (ttag_t )317, (int )predictor);

  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "376", "0", checkpoints_buf);
  break;
  }
  linebytes = (tsize_t )((unsigned int )spp * w);



  tmp___15 = TIFFScanlineSize(out);




  if (tmp___15 > linebytes) {


    tmp___12 = _TIFFmalloc(linebytes);


    buf = (unsigned char *)tmp___12;

  } else {


    tmp___13 = TIFFScanlineSize(out);




    tmp___14 = _TIFFmalloc(tmp___13);


    buf = (unsigned char *)tmp___14;

  }




  tmp___16 = TIFFDefaultStripSize(out, rowsperstrip);



  TIFFSetField(out, (ttag_t )278, tmp___16);

  sprintf(checkpoints_buf, "%lf", resolution);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "390", "resolution", checkpoints_buf);
  if (resolution > (double )0) {

    TIFFSetField(out, (ttag_t )282, resolution);


    TIFFSetField(out, (ttag_t )283, resolution);


    TIFFSetField(out, (ttag_t )296, 2);

  } else {

  }
  sprintf(checkpoints_buf, "%lf", resolution);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "390", "resolution", checkpoints_buf);
  row = 0U;
  sprintf(checkpoints_buf, "%u", row);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "395", "row", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", row);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "row", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "h", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "tmp___18", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "tmp___18", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", row);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "row", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%u", row);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "397", "row", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "397", "h", checkpoints_buf);
    if (row < h) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%u", row);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "397", "row", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", h);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "397", "h", checkpoints_buf);


    tmp___17 = fread((void */* __restrict  */)buf, (size_t )linebytes,
                     (size_t )1, (FILE */* __restrict  */)in);



    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "401", "1", checkpoints_buf);
    if (tmp___17 != 1U) {

      fprintf((FILE */* __restrict  */)stderr,
              (char const   */* __restrict  */)"%s: scanline %lu: Read error.\n",
              infile, (unsigned long )row);

      break;
    } else {

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "401", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "405", "tmp___18", checkpoints_buf);

    tmp___18 = TIFFWriteScanline(out, (tdata_t )buf, row, (tsample_t )0);
    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "405", "tmp___18", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "406", "tmp___18", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "406", "0", checkpoints_buf);
    if (tmp___18 < 0) {
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "406", "tmp___18", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "406", "0", checkpoints_buf);
    row ++;
    sprintf(checkpoints_buf, "%u", row);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "409", "row", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", row);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "row", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", h);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "h", checkpoints_buf);



  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "tmp___18", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___18);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "tmp___18", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", row);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "396", "row", checkpoints_buf);

  TIFFClose(out);


  if (buf) {

    _TIFFfree((tdata_t )buf);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "414", "0", checkpoints_buf);
  return (0);
}
}
static int processCompressOptions(char *opt ) 
{ 
  char *cp ;
  void *tmp ;
  char *tmp___0 ;
  unsigned short const   **tmp___1 ;
  void *tmp___2 ;
  char *tmp___3 ;
  char *cp___0 ;
  void *tmp___4 ;
  char *tmp___5 ;
  int tmp___6 ;
  char *cp___1 ;
  void *tmp___7 ;
  char *tmp___8 ;
  int tmp___9 ;
  size_t tmp___10 ;
  size_t tmp___11 ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp___12 ;
  int tmp___13 ;
  int tmp___14 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___15 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  size_t tmp___21 ;
  size_t tmp___22 ;
  size_t tmp___23 ;
  size_t tmp___24 ;
  size_t __s1_len___0 ;
  size_t __s2_len___0 ;
  int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  unsigned char const   *__s2___0 ;
  register int __result___1 ;
  int tmp___28 ;
  unsigned char const   *__s1___0 ;
  register int __result___2 ;
  int tmp___29 ;
  int tmp___30 ;
  int tmp___31 ;
  int tmp___32 ;
  int tmp___33 ;
  size_t tmp___34 ;
  size_t tmp___35 ;
  size_t tmp___36 ;
  size_t tmp___37 ;
  size_t __s1_len___1 ;
  size_t __s2_len___1 ;
  int tmp___38 ;
  int tmp___39 ;
  int tmp___40 ;
  unsigned char const   *__s2___1 ;
  register int __result___3 ;
  int tmp___41 ;
  unsigned char const   *__s1___1 ;
  register int __result___4 ;
  int tmp___42 ;
  int tmp___43 ;
  int tmp___44 ;
  int tmp___45 ;
  int tmp___46 ;
  size_t tmp___47 ;
  size_t tmp___48 ;
  size_t __s1_len___2 ;
  size_t __s2_len___2 ;
  int tmp___49 ;
  int tmp___50 ;
  int tmp___51 ;
  unsigned char const   *__s2___2 ;
  register int __result___5 ;
  int tmp___52 ;
  unsigned char const   *__s1___2 ;
  register int __result___6 ;
  int tmp___53 ;
  int tmp___54 ;
  int tmp___55 ;
  size_t __s1_len___3 ;
  size_t __s2_len___3 ;
  int tmp___56 ;
  int tmp___57 ;
  int tmp___58 ;
  unsigned char const   *__s2___3 ;
  register int __result___7 ;
  int tmp___59 ;
  unsigned char const   *__s1___3 ;
  register int __result___8 ;
  int tmp___60 ;
  int tmp___61 ;
  int tmp___62 ;

  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "415", "0", checkpoints_buf);
  if (0) {


    __s1_len___3 = strlen((char const   *)opt);




    __s2_len___3 = strlen("none");


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "418", "1", checkpoints_buf);
    if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
      goto _L___8;
    } else {

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "420", "4", checkpoints_buf);
      if (__s1_len___3 >= 4U) {
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "421", "1", checkpoints_buf);
        _L___8: /* CIL Label */ 
        if (! ((size_t )((void const   *)("none" + 1)) - (size_t )((void const   *)"none") == 1U)) {
          tmp___62 = 1;
          sprintf(checkpoints_buf, "%d", tmp___62);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "422", "tmp___62", checkpoints_buf);
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "423", "4", checkpoints_buf);
          if (__s2_len___3 >= 4U) {
            tmp___62 = 1;
            sprintf(checkpoints_buf, "%d", tmp___62);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "424", "tmp___62", checkpoints_buf);
          } else {
            tmp___62 = 0;
            sprintf(checkpoints_buf, "%d", tmp___62);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "425", "tmp___62", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "423", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "421", "1", checkpoints_buf);
      } else {
        tmp___62 = 0;
        sprintf(checkpoints_buf, "%d", tmp___62);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "426", "tmp___62", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "420", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "418", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___62);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "427", "tmp___62", checkpoints_buf);
    if (tmp___62) {
      sprintf(checkpoints_buf, "%d", tmp___57);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "428", "tmp___57", checkpoints_buf);

      tmp___57 = __builtin_strcmp((char const   *)opt, "none");
      sprintf(checkpoints_buf, "%d", tmp___57);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "428", "tmp___57", checkpoints_buf);

      tmp___61 = tmp___57;
      sprintf(checkpoints_buf, "%d", tmp___61);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "429", "tmp___61", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___60);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "430", "tmp___60", checkpoints_buf);

      tmp___60 = __builtin_strcmp((char const   *)opt, "none");
      sprintf(checkpoints_buf, "%d", tmp___60);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "430", "tmp___60", checkpoints_buf);

      tmp___61 = tmp___60;
      sprintf(checkpoints_buf, "%d", tmp___61);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "431", "tmp___61", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___62);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "427", "tmp___62", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___60);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "432", "tmp___60", checkpoints_buf);

    tmp___60 = __builtin_strcmp((char const   *)opt, "none");
    sprintf(checkpoints_buf, "%d", tmp___60);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "432", "tmp___60", checkpoints_buf);

    tmp___61 = tmp___60;
    sprintf(checkpoints_buf, "%d", tmp___61);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "433", "tmp___61", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "415", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___61);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "434", "tmp___61", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "434", "0", checkpoints_buf);
  if (tmp___61 == 0) {
    compression = (uint16 )1;

  } else {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "436", "0", checkpoints_buf);
    if (0) {


      __s1_len___2 = strlen((char const   *)opt);




      __s2_len___2 = strlen("packbits");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "439", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
        goto _L___6;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "441", "4", checkpoints_buf);
        if (__s1_len___2 >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "442", "1", checkpoints_buf);
          _L___6: /* CIL Label */ 
          if (! ((size_t )((void const   *)("packbits" + 1)) - (size_t )((void const   *)"packbits") == 1U)) {
            tmp___55 = 1;
            sprintf(checkpoints_buf, "%d", tmp___55);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "443", "tmp___55", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "444", "4", checkpoints_buf);
            if (__s2_len___2 >= 4U) {
              tmp___55 = 1;
              sprintf(checkpoints_buf, "%d", tmp___55);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "445", "tmp___55", checkpoints_buf);
            } else {
              tmp___55 = 0;
              sprintf(checkpoints_buf, "%d", tmp___55);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "446", "tmp___55", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "444", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "442", "1", checkpoints_buf);
        } else {
          tmp___55 = 0;
          sprintf(checkpoints_buf, "%d", tmp___55);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "447", "tmp___55", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "441", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "439", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___55);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "448", "tmp___55", checkpoints_buf);
      if (tmp___55) {
        sprintf(checkpoints_buf, "%d", tmp___50);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "449", "tmp___50", checkpoints_buf);

        tmp___50 = __builtin_strcmp((char const   *)opt, "packbits");
        sprintf(checkpoints_buf, "%d", tmp___50);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "449", "tmp___50", checkpoints_buf);

        tmp___54 = tmp___50;
        sprintf(checkpoints_buf, "%d", tmp___54);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "450", "tmp___54", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___53);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "451", "tmp___53", checkpoints_buf);

        tmp___53 = __builtin_strcmp((char const   *)opt, "packbits");
        sprintf(checkpoints_buf, "%d", tmp___53);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "451", "tmp___53", checkpoints_buf);

        tmp___54 = tmp___53;
        sprintf(checkpoints_buf, "%d", tmp___54);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "452", "tmp___54", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___55);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "448", "tmp___55", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___53);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "453", "tmp___53", checkpoints_buf);

      tmp___53 = __builtin_strcmp((char const   *)opt, "packbits");
      sprintf(checkpoints_buf, "%d", tmp___53);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "453", "tmp___53", checkpoints_buf);

      tmp___54 = tmp___53;
      sprintf(checkpoints_buf, "%d", tmp___54);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "454", "tmp___54", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "436", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___54);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "455", "tmp___54", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "455", "0", checkpoints_buf);
    if (tmp___54 == 0) {
      compression = (uint16 )32773;

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "457", "0", checkpoints_buf);
      if (0) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "458", "0", checkpoints_buf);
        if (0) {


          __s1_len___1 = strlen((char const   *)opt);




          __s2_len___1 = strlen("jpeg");


          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "461", "1", checkpoints_buf);
          if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
            goto _L___4;
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "463", "4", checkpoints_buf);
            if (__s1_len___1 >= 4U) {
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "464", "1", checkpoints_buf);
              _L___4: /* CIL Label */ 
              if (! ((size_t )((void const   *)("jpeg" + 1)) - (size_t )((void const   *)"jpeg") == 1U)) {
                tmp___44 = 1;
                sprintf(checkpoints_buf, "%d", tmp___44);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "465", "tmp___44", checkpoints_buf);
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "466", "4", checkpoints_buf);
                if (__s2_len___1 >= 4U) {
                  tmp___44 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___44);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "467", "tmp___44", checkpoints_buf);
                } else {
                  tmp___44 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___44);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "468", "tmp___44", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "466", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "464", "1", checkpoints_buf);
            } else {
              tmp___44 = 0;
              sprintf(checkpoints_buf, "%d", tmp___44);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "469", "tmp___44", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "463", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "461", "1", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___44);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "470", "tmp___44", checkpoints_buf);
          if (tmp___44) {
            sprintf(checkpoints_buf, "%d", tmp___39);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "471", "tmp___39", checkpoints_buf);

            tmp___39 = __builtin_strcmp((char const   *)opt, "jpeg");
            sprintf(checkpoints_buf, "%d", tmp___39);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "471", "tmp___39", checkpoints_buf);

            tmp___43 = tmp___39;
            sprintf(checkpoints_buf, "%d", tmp___43);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "472", "tmp___43", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___42);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "473", "tmp___42", checkpoints_buf);

            tmp___42 = __builtin_strcmp((char const   *)opt, "jpeg");
            sprintf(checkpoints_buf, "%d", tmp___42);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "473", "tmp___42", checkpoints_buf);

            tmp___43 = tmp___42;
            sprintf(checkpoints_buf, "%d", tmp___43);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "474", "tmp___43", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___44);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "470", "tmp___44", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___42);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "475", "tmp___42", checkpoints_buf);

          tmp___42 = __builtin_strcmp((char const   *)opt, "jpeg");
          sprintf(checkpoints_buf, "%d", tmp___42);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "475", "tmp___42", checkpoints_buf);

          tmp___43 = tmp___42;
          sprintf(checkpoints_buf, "%d", tmp___43);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "476", "tmp___43", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "458", "0", checkpoints_buf);
        tmp___46 = tmp___43;
        sprintf(checkpoints_buf, "%d", tmp___46);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "477", "tmp___46", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___45);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "478", "tmp___45", checkpoints_buf);

        tmp___45 = strncmp((char const   *)opt, "jpeg", (size_t )4);
        sprintf(checkpoints_buf, "%d", tmp___45);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "478", "tmp___45", checkpoints_buf);

        tmp___46 = tmp___45;
        sprintf(checkpoints_buf, "%d", tmp___46);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "479", "tmp___46", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "457", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___46);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "480", "tmp___46", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "480", "0", checkpoints_buf);
      if (tmp___46 == 0) {


        tmp___0 = __builtin_strchr(opt, ':');


        cp = tmp___0;

        compression = (uint16 )7;




        sprintf(checkpoints_buf, "%d", 2048);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "484", "2048", checkpoints_buf);



        while (cp) {



          tmp___1 = __ctype_b_loc();


          sprintf(checkpoints_buf, "%d", 2048);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "489", "2048", checkpoints_buf);
          if ((int const   )*(*tmp___1 + (int )*(cp + 1)) & 2048) {
            sprintf(checkpoints_buf, "%d", quality);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "490", "quality", checkpoints_buf);

            quality = atoi((char const   *)(cp + 1));
            sprintf(checkpoints_buf, "%d", quality);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "490", "quality", checkpoints_buf);

          } else {
            sprintf(checkpoints_buf, "%d", 114);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "491", "114", checkpoints_buf);
            if ((int )*(cp + 1) == 114) {
              jpegcolormode = 0;
              sprintf(checkpoints_buf, "%d", jpegcolormode);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "492", "jpegcolormode", checkpoints_buf);
            } else {

              usage();

            }
            sprintf(checkpoints_buf, "%d", 114);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "491", "114", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 2048);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "489", "2048", checkpoints_buf);


          tmp___3 = __builtin_strchr(cp + 1, ':');


          cp = tmp___3;

        }



        sprintf(checkpoints_buf, "%d", 2048);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "484", "2048", checkpoints_buf);



      } else {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "496", "0", checkpoints_buf);
        if (0) {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "497", "0", checkpoints_buf);
          if (0) {


            __s1_len___0 = strlen((char const   *)opt);




            __s2_len___0 = strlen("lzw");


            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "500", "1", checkpoints_buf);
            if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
              goto _L___2;
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "502", "4", checkpoints_buf);
              if (__s1_len___0 >= 4U) {
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "503", "1", checkpoints_buf);
                _L___2: /* CIL Label */ 
                if (! ((size_t )((void const   *)("lzw" + 1)) - (size_t )((void const   *)"lzw") == 1U)) {
                  tmp___31 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___31);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "504", "tmp___31", checkpoints_buf);
                } else {

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "505", "4", checkpoints_buf);
                  if (__s2_len___0 >= 4U) {
                    tmp___31 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___31);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                    "506", "tmp___31", checkpoints_buf);
                  } else {
                    tmp___31 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___31);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                    "507", "tmp___31", checkpoints_buf);
                  }

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "505", "4", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "503", "1", checkpoints_buf);
              } else {
                tmp___31 = 0;
                sprintf(checkpoints_buf, "%d", tmp___31);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "508", "tmp___31", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "502", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "500", "1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___31);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "509", "tmp___31", checkpoints_buf);
            if (tmp___31) {
              sprintf(checkpoints_buf, "%d", tmp___26);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "510", "tmp___26", checkpoints_buf);

              tmp___26 = __builtin_strcmp((char const   *)opt, "lzw");
              sprintf(checkpoints_buf, "%d", tmp___26);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "510", "tmp___26", checkpoints_buf);

              tmp___30 = tmp___26;
              sprintf(checkpoints_buf, "%d", tmp___30);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "511", "tmp___30", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___29);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "512", "tmp___29", checkpoints_buf);

              tmp___29 = __builtin_strcmp((char const   *)opt, "lzw");
              sprintf(checkpoints_buf, "%d", tmp___29);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "512", "tmp___29", checkpoints_buf);

              tmp___30 = tmp___29;
              sprintf(checkpoints_buf, "%d", tmp___30);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "513", "tmp___30", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___31);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "509", "tmp___31", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___29);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "514", "tmp___29", checkpoints_buf);

            tmp___29 = __builtin_strcmp((char const   *)opt, "lzw");
            sprintf(checkpoints_buf, "%d", tmp___29);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "514", "tmp___29", checkpoints_buf);

            tmp___30 = tmp___29;
            sprintf(checkpoints_buf, "%d", tmp___30);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "515", "tmp___30", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "497", "0", checkpoints_buf);
          tmp___33 = tmp___30;
          sprintf(checkpoints_buf, "%d", tmp___33);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "516", "tmp___33", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___32);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "517", "tmp___32", checkpoints_buf);

          tmp___32 = strncmp((char const   *)opt, "lzw", (size_t )3);
          sprintf(checkpoints_buf, "%d", tmp___32);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "517", "tmp___32", checkpoints_buf);

          tmp___33 = tmp___32;
          sprintf(checkpoints_buf, "%d", tmp___33);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "518", "tmp___33", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "496", "0", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___33);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "519", "tmp___33", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "519", "0", checkpoints_buf);
        if (tmp___33 == 0) {


          tmp___5 = __builtin_strchr(opt, ':');


          cp___0 = tmp___5;


          if (cp___0) {
            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "523", "tmp___6", checkpoints_buf);

            tmp___6 = atoi((char const   *)(cp___0 + 1));
            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "523", "tmp___6", checkpoints_buf);

            predictor = (uint16 )tmp___6;

          } else {

          }

          compression = (uint16 )5;

        } else {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "527", "0", checkpoints_buf);
          if (0) {
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "528", "0", checkpoints_buf);
            if (0) {


              __s1_len = strlen((char const   *)opt);




              __s2_len = strlen("zip");


              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "531", "1", checkpoints_buf);
              if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
                goto _L___0;
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "533", "4", checkpoints_buf);
                if (__s1_len >= 4U) {
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "534", "1", checkpoints_buf);
                  _L___0: /* CIL Label */ 
                  if (! ((size_t )((void const   *)("zip" + 1)) - (size_t )((void const   *)"zip") == 1U)) {
                    tmp___18 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___18);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                    "535", "tmp___18", checkpoints_buf);
                  } else {

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                    "536", "4", checkpoints_buf);
                    if (__s2_len >= 4U) {
                      tmp___18 = 1;
                      sprintf(checkpoints_buf, "%d", tmp___18);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                      "537", "tmp___18", checkpoints_buf);
                    } else {
                      tmp___18 = 0;
                      sprintf(checkpoints_buf, "%d", tmp___18);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                      "538", "tmp___18", checkpoints_buf);
                    }

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                    "536", "4", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "534", "1", checkpoints_buf);
                } else {
                  tmp___18 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___18);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                  "539", "tmp___18", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "533", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "531", "1", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___18);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "540", "tmp___18", checkpoints_buf);
              if (tmp___18) {
                sprintf(checkpoints_buf, "%d", tmp___13);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "541", "tmp___13", checkpoints_buf);

                tmp___13 = __builtin_strcmp((char const   *)opt, "zip");
                sprintf(checkpoints_buf, "%d", tmp___13);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "541", "tmp___13", checkpoints_buf);

                tmp___17 = tmp___13;
                sprintf(checkpoints_buf, "%d", tmp___17);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "542", "tmp___17", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", tmp___16);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "543", "tmp___16", checkpoints_buf);

                tmp___16 = __builtin_strcmp((char const   *)opt, "zip");
                sprintf(checkpoints_buf, "%d", tmp___16);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "543", "tmp___16", checkpoints_buf);

                tmp___17 = tmp___16;
                sprintf(checkpoints_buf, "%d", tmp___17);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                                "544", "tmp___17", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", tmp___18);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "540", "tmp___18", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___16);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "545", "tmp___16", checkpoints_buf);

              tmp___16 = __builtin_strcmp((char const   *)opt, "zip");
              sprintf(checkpoints_buf, "%d", tmp___16);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "545", "tmp___16", checkpoints_buf);

              tmp___17 = tmp___16;
              sprintf(checkpoints_buf, "%d", tmp___17);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "546", "tmp___17", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "528", "0", checkpoints_buf);
            tmp___20 = tmp___17;
            sprintf(checkpoints_buf, "%d", tmp___20);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "547", "tmp___20", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___19);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "548", "tmp___19", checkpoints_buf);

            tmp___19 = strncmp((char const   *)opt, "zip", (size_t )3);
            sprintf(checkpoints_buf, "%d", tmp___19);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "548", "tmp___19", checkpoints_buf);

            tmp___20 = tmp___19;
            sprintf(checkpoints_buf, "%d", tmp___20);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "549", "tmp___20", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "527", "0", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___20);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "550", "tmp___20", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "550", "0", checkpoints_buf);
          if (tmp___20 == 0) {


            tmp___8 = __builtin_strchr(opt, ':');


            cp___1 = tmp___8;


            if (cp___1) {
              sprintf(checkpoints_buf, "%d", tmp___9);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "554", "tmp___9", checkpoints_buf);

              tmp___9 = atoi((char const   *)(cp___1 + 1));
              sprintf(checkpoints_buf, "%d", tmp___9);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                              "554", "tmp___9", checkpoints_buf);

              predictor = (uint16 )tmp___9;

            } else {

            }

            compression = (uint16 )32946;

          } else {
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                            "558", "0", checkpoints_buf);
            return (0);
          }
          sprintf(checkpoints_buf, "%d", tmp___20);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "550", "tmp___20", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                          "550", "0", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___33);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "519", "tmp___33", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                        "519", "0", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___46);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "480", "tmp___46", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                      "480", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___54);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "455", "tmp___54", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "455", "0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___61);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "434", "tmp___61", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "434", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "559", "1", checkpoints_buf);
  return (1);
}
}
char *stuff[18]  = 
  {      (char *)"usage: ppm2tiff [options] input.ppm output.tif",      (char *)"where options are:",      (char *)" -r #\t\tmake each strip have no more than # rows",      (char *)" -R #\t\tset x&y resolution (dpi)", 
        (char *)"",      (char *)" -c jpeg[:opts]  compress output with JPEG encoding",      (char *)" -c lzw[:opts]\tcompress output with Lempel-Ziv & Welch encoding",      (char *)" -c zip[:opts]\tcompress output with deflate encoding", 
        (char *)" -c packbits\tcompress output with packbits encoding (the default)",      (char *)" -c none\tuse no compression algorithm on output",      (char *)"",      (char *)"JPEG options:", 
        (char *)" #\t\tset compression quality level (0-100, default 75)",      (char *)" r\t\toutput color image as RGB rather than YCbCr",      (char *)"LZW and deflate options:",      (char *)" #\t\tset predictor value", 
        (char *)"For example, -c lzw:2 to get LZW-encoded data with horizontal differencing",      (char *)((void *)0)};
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
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "563", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "564", "i", checkpoints_buf);
  while ((unsigned int )stuff[i] != (unsigned int )((void *)0)) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s\n", stuff[i]);

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                    "569", "i", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2006-02-27-6074705-e6d0c32",
                  "564", "i", checkpoints_buf);

  exit(-1);

}
}
