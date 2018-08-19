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
   uint16 SubsamplingHor ;
   uint16 SubsamplingVer ;
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
typedef long wchar_t;
struct __anonstruct___wait_terminated_39 {
   unsigned int __w_termsig : 7 ;
   unsigned int __w_coredump : 1 ;
   unsigned int __w_retcode : 8 ;
   unsigned int  : 16 ;
};
struct __anonstruct___wait_stopped_40 {
   unsigned int __w_stopval : 8 ;
   unsigned int __w_stopsig : 8 ;
   unsigned int  : 16 ;
};
union __anonunion___WAIT_STATUS_41 {
   union wait *__uptr ;
   int *__iptr ;
};
struct __anonstruct_div_t_42 {
   int quot ;
   int rem ;
};
struct __anonstruct_ldiv_t_43 {
   long quot ;
   long rem ;
};
struct __anonstruct_lldiv_t_44 {
   long long quot ;
   long long rem ;
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
TIFFField const   *TIFFFindField(TIFF *tif , uint32 tag , TIFFDataType dt ) ;
TIFFField const   *TIFFFieldWithTag(TIFF *tif , uint32 tag ) ;
TIFFField const   *TIFFFieldWithName(TIFF *tif , char const   *field_name ) ;
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
int TIFFDataWidth(TIFFDataType type ) ;
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
int TIFFMergeFieldInfo(TIFF *tif , TIFFFieldInfo const   *info , uint32 n ) ;
TIFFFieldInfo const   *TIFFFindFieldInfo(TIFF *tif , uint32 tag ,
                                         TIFFDataType dt ) ;
TIFFFieldInfo const   *TIFFFindFieldInfoByName(TIFF *tif ,
                                               char const   *field_name ,
                                               TIFFDataType dt ) ;
TIFFFieldArray const   *_TIFFGetFields(void) ;
TIFFFieldArray const   *_TIFFGetExifFields(void) ;
void _TIFFSetupFields(TIFF *tif , TIFFFieldArray const   *fieldarray ) ;
void _TIFFPrintFieldInfo(TIFF *tif , FILE *fd ) ;
int _TIFFMergeFields(TIFF *tif , TIFFField const   *info , uint32 n ) ;
TIFFField const   *_TIFFFindOrRegisterField(TIFF *tif , uint32 tag ,
                                            TIFFDataType dt ) ;
TIFFField *_TIFFCreateAnonField(TIFF *tif , uint32 tag ,
                                TIFFDataType field_type ) ;
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
int _TIFFDataSize(TIFFDataType type ) ;
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
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) a64l)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *alloca(size_t __size ) ;
static struct _TIFFFieldArray  const  tiffFieldArray ;
static struct _TIFFFieldArray  const  exifFieldArray ;
static TIFFField const   tiffFields[138]  = 
  {      {(uint32 )254, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)5,
      (unsigned char)1, (unsigned char)0, (char *)"SubfileType",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )255, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)5,
      (unsigned char)1, (unsigned char)0, (char *)"OldSubfileType",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )256, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)1,
      (unsigned char)0, (unsigned char)0, (char *)"ImageWidth",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )257, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)1,
      (unsigned char)1, (unsigned char)0, (char *)"ImageLength",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )258, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)6,
      (unsigned char)0, (unsigned char)0, (char *)"BitsPerSample",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )259, (short)-1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)7,
      (unsigned char)0, (unsigned char)0, (char *)"Compression",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )262, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)8,
      (unsigned char)0, (unsigned char)0, (char *)"PhotometricInterpretation",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )263, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)9,
      (unsigned char)1, (unsigned char)0, (char *)"Threshholding",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )264, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)0,
      (unsigned char)1, (unsigned char)0, (char *)"CellWidth",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )265, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)0,
      (unsigned char)1, (unsigned char)0, (char *)"CellLength",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )266, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)10,
      (unsigned char)0, (unsigned char)0, (char *)"FillOrder",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )269, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"DocumentName",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )270, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ImageDescription",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )271, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Make",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )272, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Model",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )273, (short)-1, (short)-1, (TIFFDataType )16, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)25,
      (unsigned char)0, (unsigned char)0, (char *)"StripOffsets",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )274, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)15,
      (unsigned char)0, (unsigned char)0, (char *)"Orientation",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )277, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)16,
      (unsigned char)0, (unsigned char)0, (char *)"SamplesPerPixel",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )278, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)17,
      (unsigned char)0, (unsigned char)0, (char *)"RowsPerStrip",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )279, (short)-1, (short)-1, (TIFFDataType )16, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)24,
      (unsigned char)0, (unsigned char)0, (char *)"StripByteCounts",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )280, (short)-2, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)18,
      (unsigned char)1, (unsigned char)0, (char *)"MinSampleValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )281, (short)-2, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)19,
      (unsigned char)1, (unsigned char)0, (char *)"MaxSampleValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )282, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)3,
      (unsigned char)1, (unsigned char)0, (char *)"XResolution",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )283, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)3,
      (unsigned char)1, (unsigned char)0, (char *)"YResolution",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )284, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)20,
      (unsigned char)0, (unsigned char)0, (char *)"PlanarConfiguration",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )285, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"PageName",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )286, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)4,
      (unsigned char)1, (unsigned char)0, (char *)"XPosition",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )287, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)4,
      (unsigned char)1, (unsigned char)0, (char *)"YPosition",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )288, (short)-1, (short)-1, (TIFFDataType )16, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)0,
      (unsigned char)0, (unsigned char)0, (char *)"FreeOffsets",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )289, (short)-1, (short)-1, (TIFFDataType )16, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)0,
      (unsigned char)0, (unsigned char)0, (char *)"FreeByteCounts",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )290, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)0,
      (unsigned char)1, (unsigned char)0, (char *)"GrayResponseUnit",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )291, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)0,
      (unsigned char)1, (unsigned char)0, (char *)"GrayResponseCurve",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )296, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)22,
      (unsigned char)1, (unsigned char)0, (char *)"ResolutionUnit",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )297, (short)2, (short)2, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )14, (TIFFSetGetFieldType )0, (unsigned short)23,
      (unsigned char)1, (unsigned char)0, (char *)"PageNumber",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )300, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)0,
      (unsigned char)1, (unsigned char)0, (char *)"ColorResponseUnit",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )301, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )51, (TIFFSetGetFieldType )0, (unsigned short)44,
      (unsigned char)1, (unsigned char)0, (char *)"TransferFunction",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )305, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Software",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )306, (short)20, (short)20, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"DateTime",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )315, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Artist",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )316, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"HostComputer",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )318, (short)2, (short)2, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"WhitePoint",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )319, (short)6, (short)6, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"PrimaryChromaticities",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )320, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )51, (TIFFSetGetFieldType )0, (unsigned short)26,
      (unsigned char)1, (unsigned char)0, (char *)"ColorMap",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )321, (short)2, (short)2, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )14, (TIFFSetGetFieldType )0, (unsigned short)37,
      (unsigned char)1, (unsigned char)0, (char *)"HalftoneHints",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )322, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)2,
      (unsigned char)0, (unsigned char)0, (char *)"TileWidth",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )323, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)2,
      (unsigned char)0, (unsigned char)0, (char *)"TileLength",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )324, (short)-1, (short)1, (TIFFDataType )16, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)25,
      (unsigned char)0, (unsigned char)0, (char *)"TileOffsets",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )325, (short)-1, (short)1, (TIFFDataType )16, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)24,
      (unsigned char)0, (unsigned char)0, (char *)"TileByteCounts",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )330, (short)-1, (short)-1, (TIFFDataType )18, (uint32 )0,
      (TIFFSetGetFieldType )38, (TIFFSetGetFieldType )0, (unsigned short)49,
      (unsigned char)1, (unsigned char)1, (char *)"SubIFD",
      (TIFFFieldArray *)(& tiffFieldArray)}, 
        {(uint32 )332, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"InkSet",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )333, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )27, (TIFFSetGetFieldType )0, (unsigned short)46,
      (unsigned char)1, (unsigned char)1, (char *)"InkNames",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )334, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"NumberOfInks",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )336, (short)2, (short)2, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )14, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"DotRange",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )337, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"TargetPrinter",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )338, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )30, (TIFFSetGetFieldType )0, (unsigned short)31,
      (unsigned char)0, (unsigned char)1, (char *)"ExtraSamples",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )339, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)32,
      (unsigned char)0, (unsigned char)0, (char *)"SampleFormat",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )340, (short)-2, (short)-1, (TIFFDataType )0, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)33,
      (unsigned char)1, (unsigned char)0, (char *)"SMinSampleValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )341, (short)-2, (short)-1, (TIFFDataType )0, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)34,
      (unsigned char)1, (unsigned char)0, (char *)"SMaxSampleValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )343, (short)-1, (short)-3, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"ClipPath",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )344, (short)1, (short)1, (TIFFDataType )9, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"XClipPathUnits",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )344, (short)1, (short)1, (TIFFDataType )6, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"XClipPathUnits",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )345, (short)1, (short)1, (TIFFDataType )9, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"YClipPathUnits",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )529, (short)3, (short)3, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"YCbCrCoefficients",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )530, (short)2, (short)2, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )14, (TIFFSetGetFieldType )0, (unsigned short)39,
      (unsigned char)0, (unsigned char)0, (char *)"YCbCrSubsampling",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )531, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)40,
      (unsigned char)0, (unsigned char)0, (char *)"YCbCrPositioning",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )532, (short)6, (short)6, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ReferenceBlackWhite",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )700, (short)-3, (short)-3, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )40, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"XMLPacket",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )32995, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)31,
      (unsigned char)0, (unsigned char)0, (char *)"Matteing",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )32996, (short)-2, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)32,
      (unsigned char)0, (unsigned char)0, (char *)"DataType",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )32997, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)35,
      (unsigned char)0, (unsigned char)0, (char *)"ImageDepth",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )32998, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)36,
      (unsigned char)0, (unsigned char)0, (char *)"TileDepth",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33300, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ImageFullWidth",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33301, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ImageFullLength",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33302, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"TextureFormat",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33303, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"TextureWrapModes",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33304, (short)1, (short)1, (TIFFDataType )11, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FieldOfViewCotangent",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33305, (short)16, (short)16, (TIFFDataType )11, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"MatrixWorldToScreen",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33306, (short)16, (short)16, (TIFFDataType )11, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"MatrixWorldToCamera",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33432, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Copyright",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33723, (short)-3, (short)-3, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )44, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"RichTIFFIPTC",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34377, (short)-3, (short)-3, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )40, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"Photoshop",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34665, (short)1, (short)1, (TIFFDataType )18, (uint32 )0,
      (TIFFSetGetFieldType )12, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"EXIFIFDOffset",
      (TIFFFieldArray *)(& exifFieldArray)}, 
        {(uint32 )34675, (short)-3, (short)-3, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )40, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"ICC Profile",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34853, (short)1, (short)1, (TIFFDataType )18, (uint32 )0,
      (TIFFSetGetFieldType )12, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"GPSIFDOffset",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34908, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )6, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FaxRecvParams",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34909, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )1, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FaxSubAddress",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34910, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )6, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FaxRecvTime",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34911, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )1, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FaxDcs",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37439, (short)1, (short)1, (TIFFDataType )12, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"StoNits",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )40965, (short)1, (short)1, (TIFFDataType )18, (uint32 )0,
      (TIFFSetGetFieldType )0, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"InteroperabilityIFDOffset",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50706, (short)4, (short)4, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )16, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"DNGVersion",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50707, (short)4, (short)4, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )16, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"DNGBackwardVersion",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50708, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"UniqueCameraModel",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50709, (short)-1, (short)-1, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"LocalizedCameraModel",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50710, (short)-1, (short)-1, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"CFAPlaneColor",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50711, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"CFALayout",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50712, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )30, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"LinearizationTable",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50713, (short)2, (short)2, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )18, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"BlackLevelRepeatDim",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50714, (short)-1, (short)-1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"BlackLevel",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50715, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"BlackLevelDeltaH",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50716, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"BlackLevelDeltaV",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50717, (short)-1, (short)-1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )32, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"WhiteLevel",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50718, (short)2, (short)2, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"DefaultScale",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50780, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"BestQualityScale",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50719, (short)2, (short)2, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"DefaultCropOrigin",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50720, (short)2, (short)2, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"DefaultCropSize",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50721, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"ColorMatrix1",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50722, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"ColorMatrix2",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50723, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"CameraCalibration1",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50724, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"CameraCalibration2",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50725, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"ReductionMatrix1",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50726, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"ReductionMatrix2",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50727, (short)-1, (short)-1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"AnalogBalance",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50728, (short)-1, (short)-1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"AsShotNeutral",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50729, (short)2, (short)2, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"AsShotWhiteXY",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50730, (short)1, (short)1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"BaselineExposure",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50731, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"BaselineNoise",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50732, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"BaselineSharpness",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50733, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"BayerGreenSplit",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50734, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"LinearResponseLimit",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50735, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"CameraSerialNumber",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50736, (short)4, (short)4, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )24, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"LensInfo",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50737, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"ChromaBlurRadius",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50738, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"AntiAliasStrength",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50739, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"ShadowScale",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50740, (short)-1, (short)-1, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"DNGPrivateData",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50741, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"MakerNoteSafety",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50778, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"CalibrationIlluminant1",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50779, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"CalibrationIlluminant2",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50781, (short)16, (short)16, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )16, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"RawDataUniqueID",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50827, (short)-1, (short)-1, (TIFFDataType )1, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"OriginalRawFileName",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50828, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"OriginalRawFileData",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50829, (short)4, (short)4, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )20, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)0, (char *)"ActiveArea",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50830, (short)-1, (short)-1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )32, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"MaskedAreas",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50831, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"AsShotICCProfile",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50832, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"AsShotPreProfileMatrix",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50833, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"CurrentICCProfile",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )50834, (short)-1, (short)-1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )36, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)0, (unsigned char)1, (char *)"CurrentPreProfileMatrix",
      (TIFFFieldArray *)((void *)0)}};
static TIFFField const   exifFields[56]  = 
  {      {(uint32 )33434, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ExposureTime",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )33437, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FNumber",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34850, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ExposureProgram",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34852, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SpectralSensitivity",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34855, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )30, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"ISOSpeedRatings",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )34856, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1,
      (char *)"OptoelectricConversionFactor", (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )36864, (short)4, (short)4, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )16, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ExifVersion",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )36867, (short)20, (short)20, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"DateTimeOriginal",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )36868, (short)20, (short)20, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"DateTimeDigitized",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37121, (short)4, (short)4, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )16, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ComponentsConfiguration",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37122, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"CompressedBitsPerPixel",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37377, (short)1, (short)1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ShutterSpeedValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37378, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ApertureValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37379, (short)1, (short)1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"BrightnessValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37380, (short)1, (short)1, (TIFFDataType )10, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ExposureBiasValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37381, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"MaxApertureValue",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37382, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SubjectDistance",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37383, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"MeteringMode",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37384, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"LightSource",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37385, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Flash",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37386, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FocalLength",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37396, (short)-1, (short)-1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )30, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"SubjectArea",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37500, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"MakerNote",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37510, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"UserComment",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37520, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SubSecTime",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37521, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SubSecTimeOriginal",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )37522, (short)-1, (short)-1, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SubSecTimeDigitized",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )40960, (short)4, (short)4, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )16, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FlashpixVersion",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )40961, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ColorSpace",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )40962, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"PixelXDimension",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )40963, (short)1, (short)1, (TIFFDataType )4, (uint32 )0,
      (TIFFSetGetFieldType )6, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"PixelYDimension",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )40964, (short)13, (short)13, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"RelatedSoundFile",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41483, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FlashEnergy",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41484, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"SpatialFrequencyResponse",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41486, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FocalPlaneXResolution",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41487, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FocalPlaneYResolution",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41488, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FocalPlaneResolutionUnit",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41492, (short)2, (short)2, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )18, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SubjectLocation",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41493, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ExposureIndex",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41495, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SensingMethod",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41728, (short)1, (short)1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )2, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FileSource",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41729, (short)1, (short)1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )2, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SceneType",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41730, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"CFAPattern",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41985, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"CustomRendered",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41986, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ExposureMode",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41987, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"WhiteBalance",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41988, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"DigitalZoomRatio",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41989, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"FocalLengthIn35mmFilm",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41990, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SceneCaptureType",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41991, (short)1, (short)1, (TIFFDataType )5, (uint32 )0,
      (TIFFSetGetFieldType )11, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"GainControl",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41992, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Contrast",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41993, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Saturation",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41994, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"Sharpness",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41995, (short)-1, (short)-1, (TIFFDataType )7, (uint32 )0,
      (TIFFSetGetFieldType )28, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)1, (char *)"DeviceSettingDescription",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )41996, (short)1, (short)1, (TIFFDataType )3, (uint32 )0,
      (TIFFSetGetFieldType )4, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"SubjectDistanceRange",
      (TIFFFieldArray *)((void *)0)}, 
        {(uint32 )42016, (short)33, (short)33, (TIFFDataType )2, (uint32 )0,
      (TIFFSetGetFieldType )1, (TIFFSetGetFieldType )0, (unsigned short)65,
      (unsigned char)1, (unsigned char)0, (char *)"ImageUniqueID",
      (TIFFFieldArray *)((void *)0)}};
static struct _TIFFFieldArray  const  tiffFieldArray  =    {(TIFFFieldArrayType )0, (uint32 )0,
    sizeof(tiffFields) / sizeof(tiffFields[0]), (TIFFField *)(tiffFields)};
static struct _TIFFFieldArray  const  exifFieldArray  =    {(TIFFFieldArrayType )1, (uint32 )0,
    sizeof(exifFields) / sizeof(exifFields[0]), (TIFFField *)(exifFields)};
TIFFFieldArray const   *_TIFFGetFields(void) 
{ 


  {
  return (& tiffFieldArray);
}
}
TIFFFieldArray const   *_TIFFGetExifFields(void) 
{ 


  {
  return (& exifFieldArray);
}
}
void _TIFFSetupFields(TIFF *tif , TIFFFieldArray const   *fieldarray ) 
{ 
  uint32 i ;
  TIFFField *fld ;
  size_t tmp ;
  size_t tmp___0 ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___4 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  size_t tmp___10 ;
  size_t tmp___11 ;
  int tmp___12 ;

  {

  if (tif->tif_fields) {

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "254", "0", checkpoints_buf);
    if (tif->tif_nfields > 0U) {
      i = (uint32 )0;




      sprintf(checkpoints_buf, "%d", 65);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "256", "65", checkpoints_buf);

      while (i < tif->tif_nfields) {


        fld = *(tif->tif_fields + i);

        sprintf(checkpoints_buf, "%d", 65);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "261", "65", checkpoints_buf);
        if ((int )fld->field_bit == 65) {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "262", "0", checkpoints_buf);
          if (0) {
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "263", "0", checkpoints_buf);
            if (0) {


              __s1_len = strlen("Tag ");




              __s2_len = strlen((char const   *)fld->field_name);


              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "266", "1", checkpoints_buf);
              if (! ((size_t )((void const   *)("Tag " + 1)) - (size_t )((void const   *)"Tag ") == 1U)) {
                goto _L___0;
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "268", "4", checkpoints_buf);
                if (__s1_len >= 4U) {
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                  "269", "1", checkpoints_buf);
                  _L___0: /* CIL Label */ 
                  if (! ((size_t )((void const   *)(fld->field_name + 1)) - (size_t )((void const   *)fld->field_name) == 1U)) {
                    tmp___7 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___7);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                    "270", "tmp___7", checkpoints_buf);
                  } else {

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                    "271", "4", checkpoints_buf);
                    if (__s2_len >= 4U) {
                      tmp___7 = 1;
                      sprintf(checkpoints_buf, "%d", tmp___7);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                      "272", "tmp___7", checkpoints_buf);
                    } else {
                      tmp___7 = 0;
                      sprintf(checkpoints_buf, "%d", tmp___7);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                      "273", "tmp___7", checkpoints_buf);
                    }

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                    "271", "4", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                  "269", "1", checkpoints_buf);
                } else {
                  tmp___7 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___7);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                  "274", "tmp___7", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "268", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "266", "1", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___7);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "275", "tmp___7", checkpoints_buf);
              if (tmp___7) {
                sprintf(checkpoints_buf, "%d", tmp___2);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "276", "tmp___2", checkpoints_buf);

                tmp___2 = __builtin_strcmp("Tag ",
                                           (char const   *)fld->field_name);
                sprintf(checkpoints_buf, "%d", tmp___2);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "276", "tmp___2", checkpoints_buf);

                tmp___6 = tmp___2;
                sprintf(checkpoints_buf, "%d", tmp___6);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "277", "tmp___6", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", tmp___5);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "278", "tmp___5", checkpoints_buf);

                tmp___5 = __builtin_strcmp("Tag ",
                                           (char const   *)fld->field_name);
                sprintf(checkpoints_buf, "%d", tmp___5);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "278", "tmp___5", checkpoints_buf);

                tmp___6 = tmp___5;
                sprintf(checkpoints_buf, "%d", tmp___6);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                                "279", "tmp___6", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", tmp___7);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "275", "tmp___7", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "280", "tmp___5", checkpoints_buf);

              tmp___5 = __builtin_strcmp("Tag ", (char const   *)fld->field_name);
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "280", "tmp___5", checkpoints_buf);

              tmp___6 = tmp___5;
              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "281", "tmp___6", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "263", "0", checkpoints_buf);
            tmp___9 = tmp___6;
            sprintf(checkpoints_buf, "%d", tmp___9);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "282", "tmp___9", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___8);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "283", "tmp___8", checkpoints_buf);

            tmp___8 = strncmp("Tag ", (char const   *)fld->field_name,
                              (size_t )4);
            sprintf(checkpoints_buf, "%d", tmp___8);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "283", "tmp___8", checkpoints_buf);

            tmp___9 = tmp___8;
            sprintf(checkpoints_buf, "%d", tmp___9);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "284", "tmp___9", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "262", "0", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "285", "tmp___9", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "285", "0", checkpoints_buf);
          if (tmp___9 == 0) {

            _TIFFfree((void *)fld->field_name);


            _TIFFfree((void *)fld);

          } else {

          }
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "285", "tmp___9", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "285", "0", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", 65);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "261", "65", checkpoints_buf);
        i ++;

      }



      sprintf(checkpoints_buf, "%d", 65);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "256", "65", checkpoints_buf);


      _TIFFfree((void *)tif->tif_fields);

      tif->tif_fields = (TIFFField **)((void *)0);

      tif->tif_nfields = (uint32 )0;

    } else {

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "254", "0", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "296", "tmp___12", checkpoints_buf);

  tmp___12 = _TIFFMergeFields(tif, (TIFFField const   *)fieldarray->fields,
                              (uint32 )fieldarray->count);
  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "296", "tmp___12", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "297", "tmp___12", checkpoints_buf);
  if (tmp___12) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, "_TIFFSetupFields",
                 "Setting up field info failed");

  }
  sprintf(checkpoints_buf, "%d", tmp___12);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "297", "tmp___12", checkpoints_buf);
  return;
}
}
static int tagCompare(void const   *a , void const   *b ) 
{ 
  TIFFField const   *ta ;
  TIFFField const   *tb ;
  int tmp ;

  {
  ta = *((TIFFField const   **)a);

  tb = *((TIFFField const   **)b);



  if (ta->field_tag != tb->field_tag) {
    return ((int )ta->field_tag - (int )tb->field_tag);
  } else {
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "305", "0", checkpoints_buf);
    if ((unsigned int const   )ta->field_type == 0U) {
      tmp = 0;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "306", "tmp", checkpoints_buf);
    } else {
      tmp = (int )tb->field_type - (int )ta->field_type;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "307", "tmp", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "305", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "308", "tmp", checkpoints_buf);
    return (tmp);
  }


}
}
static int tagNameCompare(void const   *a , void const   *b ) 
{ 
  TIFFField const   *ta ;
  TIFFField const   *tb ;
  int ret ;
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

  {
  ta = *((TIFFField const   **)a);

  tb = *((TIFFField const   **)b);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "311", "0", checkpoints_buf);
  if (0) {


    __s1_len = strlen((char const   *)ta->field_name);




    __s2_len = strlen((char const   *)tb->field_name);


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "314", "1", checkpoints_buf);
    if (! ((size_t )((void const   *)(ta->field_name + 1)) - (size_t )((void const   *)ta->field_name) == 1U)) {
      goto _L___0;
    } else {

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "316", "4", checkpoints_buf);
      if (__s1_len >= 4U) {
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "317", "1", checkpoints_buf);
        _L___0: /* CIL Label */ 
        if (! ((size_t )((void const   *)(tb->field_name + 1)) - (size_t )((void const   *)tb->field_name) == 1U)) {
          tmp___5 = 1;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "318", "tmp___5", checkpoints_buf);
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "319", "4", checkpoints_buf);
          if (__s2_len >= 4U) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "320", "tmp___5", checkpoints_buf);
          } else {
            tmp___5 = 0;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "321", "tmp___5", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "319", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "317", "1", checkpoints_buf);
      } else {
        tmp___5 = 0;
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "322", "tmp___5", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "316", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "314", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "323", "tmp___5", checkpoints_buf);
    if (tmp___5) {
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "324", "tmp___0", checkpoints_buf);

      tmp___0 = __builtin_strcmp((char const   *)ta->field_name,
                                 (char const   *)tb->field_name);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "324", "tmp___0", checkpoints_buf);

      tmp___4 = tmp___0;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "325", "tmp___4", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "326", "tmp___3", checkpoints_buf);

      tmp___3 = __builtin_strcmp((char const   *)ta->field_name,
                                 (char const   *)tb->field_name);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "326", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "327", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "323", "tmp___5", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "328", "tmp___3", checkpoints_buf);

    tmp___3 = __builtin_strcmp((char const   *)ta->field_name,
                               (char const   *)tb->field_name);
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "328", "tmp___3", checkpoints_buf);

    tmp___4 = tmp___3;
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "329", "tmp___4", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "311", "0", checkpoints_buf);
  ret = tmp___4;
  sprintf(checkpoints_buf, "%d", ret);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "330", "ret", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", ret);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "331", "ret", checkpoints_buf);
  if (ret) {
    sprintf(checkpoints_buf, "%d", ret);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "332", "ret", checkpoints_buf);
    return (ret);
  } else {
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "333", "0", checkpoints_buf);
    if ((unsigned int const   )ta->field_type == 0U) {
      tmp___6 = 0;
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "334", "tmp___6", checkpoints_buf);
    } else {
      tmp___6 = (int )tb->field_type - (int )ta->field_type;
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "335", "tmp___6", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "333", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "336", "tmp___6", checkpoints_buf);
    return (tmp___6);
  }
  sprintf(checkpoints_buf, "%d", ret);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "331", "ret", checkpoints_buf);
}
}
int _TIFFMergeFields(TIFF *tif , TIFFField const   *info , uint32 n ) 
{ 
  char module[17] ;
  char reason[17] ;
  TIFFField **tp ;
  uint32 i ;
  TIFFField const   *fip ;
  TIFFField const   *tmp ;
  void *tmp___0 ;
  void *tmp___1 ;
  TIFFField **tmp___2 ;
  uint32 tmp___3 ;

  {
  module[0] = (char )'_';

  module[1] = (char )'T';

  module[2] = (char )'I';

  module[3] = (char )'F';

  module[4] = (char )'F';

  module[5] = (char )'M';

  module[6] = (char )'e';

  module[7] = (char )'r';

  module[8] = (char )'g';

  module[9] = (char )'e';

  module[10] = (char )'F';

  module[11] = (char )'i';

  module[12] = (char )'e';

  module[13] = (char )'l';

  module[14] = (char )'d';

  module[15] = (char )'s';

  module[16] = (char )'\000';

  reason[0] = (char )'f';

  reason[1] = (char )'o';

  reason[2] = (char )'r';

  reason[3] = (char )' ';

  reason[4] = (char )'f';

  reason[5] = (char )'i';

  reason[6] = (char )'e';

  reason[7] = (char )'l';

  reason[8] = (char )'d';

  reason[9] = (char )'s';

  reason[10] = (char )' ';

  reason[11] = (char )'a';

  reason[12] = (char )'r';

  reason[13] = (char )'r';

  reason[14] = (char )'a';

  reason[15] = (char )'y';

  reason[16] = (char )'\000';

  i = (uint32 )0;


  tif->tif_foundfield = (TIFFField const   *)((void *)0);


  if (tif->tif_fields) {

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "385", "0", checkpoints_buf);
    if (tif->tif_nfields > 0U) {


      tmp___0 = _TIFFCheckRealloc(tif, (void *)tif->tif_fields,
                                  (tmsize_t )(tif->tif_nfields + n),
                                  (tmsize_t )sizeof(TIFFField *),
                                  (char const   *)(reason));


      tif->tif_fields = (TIFFField **)tmp___0;

    } else {


      tmp___1 = _TIFFCheckMalloc(tif, (tmsize_t )n,
                                 (tmsize_t )sizeof(TIFFField *),
                                 (char const   *)(reason));


      tif->tif_fields = (TIFFField **)tmp___1;

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "385", "0", checkpoints_buf);
  } else {


    tmp___1 = _TIFFCheckMalloc(tif, (tmsize_t )n,
                               (tmsize_t )sizeof(TIFFField *),
                               (char const   *)(reason));


    tif->tif_fields = (TIFFField **)tmp___1;

  }


  if (! tif->tif_fields) {

    TIFFErrorExt(tif->tif_clientdata, (char const   *)(module),
                 "Failed to allocate fields array");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "394", "0", checkpoints_buf);
    return (0);
  } else {

  }

  tp = tif->tif_fields + tif->tif_nfields;

  i = (uint32 )0;







  while (i < n) {


    tmp___2 = tp;

    tp ++;

    *tmp___2 = (TIFFField *)(info + i);

    i ++;

  }






  tmp___3 = tif->tif_nfields + n;

  tif->tif_nfields = tmp___3;


  qsort((void *)tif->tif_fields, tmp___3, sizeof(TIFFField *), & tagCompare);

  return ((int )n);
}
}
void _TIFFPrintFieldInfo(TIFF *tif , FILE *fd ) 
{ 
  uint32 i ;
  TIFFField const   *fip ;
  char const   *tmp ;
  char const   *tmp___0 ;

  {

  fprintf((FILE */* __restrict  */)fd,
          (char const   */* __restrict  */)"%s: \n", tif->tif_name);

  i = (uint32 )0;








  while (i < tif->tif_nfields) {


    fip = (TIFFField const   *)*(tif->tif_fields + i);


    if (fip->field_passcount) {
      tmp = "TRUE";

    } else {
      tmp = "FALSE";

    }


    if (fip->field_oktochange) {
      tmp___0 = "TRUE";

    } else {
      tmp___0 = "FALSE";

    }


    fprintf((FILE */* __restrict  */)fd,
            (char const   */* __restrict  */)"field[%2d] %5lu, %2d, %2d, %d, %2d, %5s, %5s, %s\n",
            (int )i, (unsigned long )fip->field_tag,
            (int const   )fip->field_readcount,
            (int const   )fip->field_writecount,
            (unsigned int const   )fip->field_type,
            (int const   )fip->field_bit, tmp___0, tmp, fip->field_name);

    i ++;

  }







  return;
}
}
int TIFFDataWidth(TIFFDataType type ) 
{ 


  {
  switch ((unsigned int )type) {
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "427", "1", checkpoints_buf);
  case 7U: 
  case 6U: 
  case 2U: 
  case 1U: 
  case 0U: 
  return (1);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "428", "2", checkpoints_buf);
  case 8U: 
  case 3U: 
  return (2);
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "429", "4", checkpoints_buf);
  case 13U: 
  case 11U: 
  case 9U: 
  case 4U: 
  return (4);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "430", "8", checkpoints_buf);
  case 18U: 
  case 17U: 
  case 16U: 
  case 12U: 
  case 10U: 
  case 5U: 
  return (8);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "431", "0", checkpoints_buf);
  default: 
  return (0);
  }
}
}
int _TIFFDataSize(TIFFDataType type ) 
{ 


  {
  switch ((unsigned int )type) {
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "433", "1", checkpoints_buf);
  case 7U: 
  case 2U: 
  case 6U: 
  case 1U: 
  return (1);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "434", "2", checkpoints_buf);
  case 8U: 
  case 3U: 
  return (2);
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "435", "4", checkpoints_buf);
  case 10U: 
  case 5U: 
  case 13U: 
  case 11U: 
  case 9U: 
  case 4U: 
  return (4);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "436", "8", checkpoints_buf);
  case 18U: 
  case 17U: 
  case 16U: 
  case 12U: 
  return (8);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "437", "0", checkpoints_buf);
  default: 
  return (0);
  }
}
}
TIFFField const   *TIFFFindField(TIFF *tif , uint32 tag , TIFFDataType dt ) 
{ 
  TIFFField key ;
  TIFFField *pkey ;
  TIFFField const   **ret ;
  void *tmp ;
  TIFFField const   *tmp___0 ;

  {
  key.field_tag = (uint32 )0;

  key.field_readcount = (short)0;

  key.field_writecount = (short)0;

  key.field_type = (TIFFDataType )0;

  key.reserved = (uint32 )0;

  key.set_field_type = (TIFFSetGetFieldType )0;

  key.get_field_type = (TIFFSetGetFieldType )0;

  key.field_bit = (unsigned short)0;

  key.field_oktochange = (unsigned char)0;

  key.field_passcount = (unsigned char)0;

  key.field_name = (char *)((void *)0);

  key.field_subfields = (TIFFFieldArray *)((void *)0);

  pkey = & key;


  if (tif->tif_foundfield) {

    if ((tif->tif_foundfield)->field_tag == (uint32 const   )tag) {
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "453", "0", checkpoints_buf);
      if ((unsigned int )dt == 0U) {

        return (tif->tif_foundfield);
      } else
      if ((unsigned int )dt == (unsigned int )(tif->tif_foundfield)->field_type) {

        return (tif->tif_foundfield);
      } else {

      }
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "453", "0", checkpoints_buf);
    } else {

    }

  } else {

  }


  if (! tif->tif_fields) {
    return ((TIFFField const   *)((void *)0));
  } else {

  }

  key.field_tag = tag;

  key.field_type = dt;



  tmp = bsearch((void const   *)(& pkey), (void const   *)tif->tif_fields,
                tif->tif_nfields, sizeof(TIFFField *), & tagCompare);


  ret = (TIFFField const   **)tmp;


  if (ret) {
    tmp___0 = *ret;

  } else {
    tmp___0 = (TIFFField const   *)((void *)0);

  }

  tif->tif_foundfield = tmp___0;


  return (tmp___0);
}
}
TIFFField const   *_TIFFFindFieldByName(TIFF *tif , char const   *field_name ,
                                        TIFFDataType dt ) 
{ 
  TIFFField key ;
  TIFFField *pkey ;
  TIFFField const   **ret ;
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
  void *tmp___6 ;
  TIFFField const   *tmp___7 ;

  {
  key.field_tag = (uint32 )0;

  key.field_readcount = (short)0;

  key.field_writecount = (short)0;

  key.field_type = (TIFFDataType )0;

  key.reserved = (uint32 )0;

  key.set_field_type = (TIFFSetGetFieldType )0;

  key.get_field_type = (TIFFSetGetFieldType )0;

  key.field_bit = (unsigned short)0;

  key.field_oktochange = (unsigned char)0;

  key.field_passcount = (unsigned char)0;

  key.field_name = (char *)((void *)0);

  key.field_subfields = (TIFFFieldArray *)((void *)0);

  pkey = & key;


  if (tif->tif_foundfield) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "486", "0", checkpoints_buf);
    if (0) {


      __s1_len = strlen((char const   *)(tif->tif_foundfield)->field_name);




      __s2_len = strlen(field_name);


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "489", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)((tif->tif_foundfield)->field_name + 1)) - (size_t )((void const   *)(tif->tif_foundfield)->field_name) == 1U)) {
        goto _L___0;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "491", "4", checkpoints_buf);
        if (__s1_len >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "492", "1", checkpoints_buf);
          _L___0: /* CIL Label */ 
          if (! ((size_t )((void const   *)(field_name + 1)) - (size_t )((void const   *)field_name) == 1U)) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "493", "tmp___5", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "494", "4", checkpoints_buf);
            if (__s2_len >= 4U) {
              tmp___5 = 1;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "495", "tmp___5", checkpoints_buf);
            } else {
              tmp___5 = 0;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                              "496", "tmp___5", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "494", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "492", "1", checkpoints_buf);
        } else {
          tmp___5 = 0;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "497", "tmp___5", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "491", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "489", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "498", "tmp___5", checkpoints_buf);
      if (tmp___5) {
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "499", "tmp___0", checkpoints_buf);

        tmp___0 = __builtin_strcmp((char const   *)(tif->tif_foundfield)->field_name,
                                   field_name);
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "499", "tmp___0", checkpoints_buf);

        tmp___4 = tmp___0;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "500", "tmp___4", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "501", "tmp___3", checkpoints_buf);

        tmp___3 = __builtin_strcmp((char const   *)(tif->tif_foundfield)->field_name,
                                   field_name);
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "501", "tmp___3", checkpoints_buf);

        tmp___4 = tmp___3;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "502", "tmp___4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "498", "tmp___5", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "503", "tmp___3", checkpoints_buf);

      tmp___3 = __builtin_strcmp((char const   *)(tif->tif_foundfield)->field_name,
                                 field_name);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "503", "tmp___3", checkpoints_buf);

      tmp___4 = tmp___3;
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "504", "tmp___4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "486", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "505", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "505", "0", checkpoints_buf);
    if (tmp___4 == 0) {
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "506", "0", checkpoints_buf);
      if ((unsigned int )dt == 0U) {

        return (tif->tif_foundfield);
      } else
      if ((unsigned int )dt == (unsigned int )(tif->tif_foundfield)->field_type) {

        return (tif->tif_foundfield);
      } else {

      }
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "506", "0", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "505", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "505", "0", checkpoints_buf);
  } else {

  }


  if (! tif->tif_fields) {
    return ((TIFFField const   *)((void *)0));
  } else {

  }

  key.field_name = (char *)field_name;

  key.field_type = dt;



  tmp___6 = lfind((void const   *)(& pkey), (void const   *)tif->tif_fields,
                  & tif->tif_nfields, sizeof(TIFFField *), & tagNameCompare);


  ret = (TIFFField const   **)tmp___6;


  if (ret) {
    tmp___7 = *ret;

  } else {
    tmp___7 = (TIFFField const   *)((void *)0);

  }

  tif->tif_foundfield = tmp___7;


  return (tmp___7);
}
}
TIFFField const   *TIFFFieldWithTag(TIFF *tif , uint32 tag ) 
{ 
  TIFFField const   *fip ;
  TIFFField const   *tmp ;

  {


  tmp = TIFFFindField(tif, tag, (TIFFDataType )0);


  fip = tmp;


  if (! fip) {

    TIFFErrorExt(tif->tif_clientdata, "TIFFFieldWithTag",
                 "Internal error, unknown tag 0x%x", tag);

    if ((unsigned int )fip != (unsigned int )((void *)0)) {

    } else {

      __assert_fail("fip != ((void *)0)", "tif_dirinfo.c", 524U,
                    "TIFFFieldWithTag");

    }
  } else {

  }


  return (fip);
}
}
TIFFField const   *TIFFFieldWithName(TIFF *tif , char const   *field_name ) 
{ 
  TIFFField const   *fip ;
  TIFFField const   *tmp ;

  {


  tmp = _TIFFFindFieldByName(tif, field_name, (TIFFDataType )0);


  fip = tmp;


  if (! fip) {

    TIFFErrorExt(tif->tif_clientdata, "TIFFFieldWithName",
                 "Internal error, unknown tag %s", field_name);

    if ((unsigned int )fip != (unsigned int )((void *)0)) {

    } else {

      __assert_fail("fip != ((void *)0)", "tif_dirinfo.c", 538U,
                    "TIFFFieldWithName");

    }
  } else {

  }


  return (fip);
}
}
TIFFField const   *_TIFFFindOrRegisterField(TIFF *tif , uint32 tag ,
                                            TIFFDataType dt ) 
{ 
  TIFFField const   *fld ;
  TIFFField *tmp ;
  int tmp___0 ;

  {


  fld = TIFFFindField(tif, tag, dt);


  if ((unsigned int )fld == (unsigned int )((void *)0)) {


    tmp = _TIFFCreateAnonField(tif, tag, dt);


    fld = (TIFFField const   *)tmp;

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "547", "tmp___0", checkpoints_buf);

    tmp___0 = _TIFFMergeFields(tif, fld, (uint32 )1);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "547", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "548", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      return ((TIFFField const   *)((void *)0));
    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "548", "tmp___0", checkpoints_buf);
  } else {

  }

  return (fld);
}
}
TIFFField *_TIFFCreateAnonField(TIFF *tif , uint32 tag ,
                                TIFFDataType field_type ) 
{ 
  TIFFField *fld ;
  void *tmp ;
  void *tmp___0 ;

  {


  tmp = _TIFFmalloc((tmsize_t )sizeof(TIFFField ));


  fld = (TIFFField *)tmp;

  if ((unsigned int )fld == (unsigned int )((void *)0)) {
    return ((TIFFField *)((void *)0));
  } else {

  }

  _TIFFmemset((void *)fld, 0, (tmsize_t )sizeof(TIFFField ));

  fld->field_tag = tag;

  fld->field_readcount = (short)-3;

  fld->field_writecount = (short)-3;

  fld->field_type = field_type;

  fld->reserved = (uint32 )0;

  switch ((unsigned int )field_type) {
  case 7U: 
  case 1U: 
  fld->set_field_type = (TIFFSetGetFieldType )40;

  fld->get_field_type = (TIFFSetGetFieldType )40;

  break;
  case 2U: 
  fld->set_field_type = (TIFFSetGetFieldType )39;

  fld->get_field_type = (TIFFSetGetFieldType )39;

  break;
  case 3U: 
  fld->set_field_type = (TIFFSetGetFieldType )42;

  fld->get_field_type = (TIFFSetGetFieldType )42;

  break;
  case 4U: 
  fld->set_field_type = (TIFFSetGetFieldType )44;

  fld->get_field_type = (TIFFSetGetFieldType )44;

  break;
  case 11U: 
  case 10U: 
  case 5U: 
  fld->set_field_type = (TIFFSetGetFieldType )48;

  fld->get_field_type = (TIFFSetGetFieldType )48;

  break;
  case 6U: 
  fld->set_field_type = (TIFFSetGetFieldType )41;

  fld->get_field_type = (TIFFSetGetFieldType )41;

  break;
  case 8U: 
  fld->set_field_type = (TIFFSetGetFieldType )43;

  fld->get_field_type = (TIFFSetGetFieldType )43;

  break;
  case 9U: 
  fld->set_field_type = (TIFFSetGetFieldType )45;

  fld->get_field_type = (TIFFSetGetFieldType )45;

  break;
  case 12U: 
  fld->set_field_type = (TIFFSetGetFieldType )49;

  fld->get_field_type = (TIFFSetGetFieldType )49;

  break;
  case 18U: 
  case 13U: 
  fld->set_field_type = (TIFFSetGetFieldType )50;

  fld->get_field_type = (TIFFSetGetFieldType )50;

  break;
  case 16U: 
  fld->set_field_type = (TIFFSetGetFieldType )46;

  fld->get_field_type = (TIFFSetGetFieldType )46;

  break;
  case 17U: 
  fld->set_field_type = (TIFFSetGetFieldType )47;

  fld->get_field_type = (TIFFSetGetFieldType )47;

  break;
  default: 
  fld->set_field_type = (TIFFSetGetFieldType )0;

  fld->get_field_type = (TIFFSetGetFieldType )0;

  break;
  }
  fld->field_bit = (unsigned short)65;

  fld->field_oktochange = (unsigned char)1;

  fld->field_passcount = (unsigned char)1;



  tmp___0 = _TIFFmalloc((tmsize_t )32);


  fld->field_name = (char *)tmp___0;

  if ((unsigned int )fld->field_name == (unsigned int )((void *)0)) {

    _TIFFfree((void *)fld);

    return ((TIFFField *)((void *)0));
  } else {

  }
  fld->field_subfields = (TIFFFieldArray *)((void *)0);


  sprintf((char */* __restrict  */)fld->field_name,
          (char const   */* __restrict  */)"Tag %d", (int )tag);


  return (fld);
}
}
static TIFFSetGetFieldType _TIFFSetGetType(TIFFDataType type , short count ,
                                           unsigned char passcount ) 
{ 


  {
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "616", "2", checkpoints_buf);
  if ((unsigned int )type == 2U) {
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "617", "-1", checkpoints_buf);
    if ((int )count == -1) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "618", "0", checkpoints_buf);
      if ((int )passcount == 0) {
        return ((TIFFSetGetFieldType )1);
      } else {
        goto _L___3;
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "618", "0", checkpoints_buf);
    } else {
      goto _L___3;
    }
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "617", "-1", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "622", "1", checkpoints_buf);
    _L___3: /* CIL Label */ 
    _L___2: /* CIL Label */ 
    if ((int )count == 1) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "623", "0", checkpoints_buf);
      if ((int )passcount == 0) {
        switch ((unsigned int )type) {
        case 7U: 
        case 1U: 
        return ((TIFFSetGetFieldType )2);
        case 2U: 
        return ((TIFFSetGetFieldType )1);
        case 3U: 
        return ((TIFFSetGetFieldType )4);
        case 4U: 
        return ((TIFFSetGetFieldType )6);
        case 11U: 
        case 10U: 
        case 5U: 
        return ((TIFFSetGetFieldType )10);
        case 6U: 
        return ((TIFFSetGetFieldType )3);
        case 8U: 
        return ((TIFFSetGetFieldType )5);
        case 9U: 
        return ((TIFFSetGetFieldType )7);
        case 12U: 
        return ((TIFFSetGetFieldType )11);
        case 18U: 
        case 13U: 
        return ((TIFFSetGetFieldType )12);
        case 16U: 
        return ((TIFFSetGetFieldType )8);
        case 17U: 
        return ((TIFFSetGetFieldType )9);
        default: 
        return ((TIFFSetGetFieldType )0);
        }
      } else {
        goto _L___1;
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "623", "0", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "639", "1", checkpoints_buf);
      _L___1: /* CIL Label */ 
      if ((int )count >= 1) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "640", "0", checkpoints_buf);
        if ((int )passcount == 0) {
          switch ((unsigned int )type) {
          case 7U: 
          case 1U: 
          return ((TIFFSetGetFieldType )16);
          case 2U: 
          return ((TIFFSetGetFieldType )15);
          case 3U: 
          return ((TIFFSetGetFieldType )18);
          case 4U: 
          return ((TIFFSetGetFieldType )20);
          case 11U: 
          case 10U: 
          case 5U: 
          return ((TIFFSetGetFieldType )24);
          case 6U: 
          return ((TIFFSetGetFieldType )17);
          case 8U: 
          return ((TIFFSetGetFieldType )19);
          case 9U: 
          return ((TIFFSetGetFieldType )21);
          case 12U: 
          return ((TIFFSetGetFieldType )25);
          case 18U: 
          case 13U: 
          return ((TIFFSetGetFieldType )26);
          case 16U: 
          return ((TIFFSetGetFieldType )22);
          case 17U: 
          return ((TIFFSetGetFieldType )23);
          default: 
          return ((TIFFSetGetFieldType )0);
          }
        } else {
          goto _L___0;
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "640", "0", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "656", "-1", checkpoints_buf);
        _L___0: /* CIL Label */ 
        if ((int )count == -1) {
          sprintf(checkpoints_buf, "%d", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "657", "1", checkpoints_buf);
          if ((int )passcount == 1) {
            switch ((unsigned int )type) {
            case 7U: 
            case 1U: 
            return ((TIFFSetGetFieldType )28);
            case 2U: 
            return ((TIFFSetGetFieldType )27);
            case 3U: 
            return ((TIFFSetGetFieldType )30);
            case 4U: 
            return ((TIFFSetGetFieldType )32);
            case 11U: 
            case 10U: 
            case 5U: 
            return ((TIFFSetGetFieldType )36);
            case 6U: 
            return ((TIFFSetGetFieldType )29);
            case 8U: 
            return ((TIFFSetGetFieldType )31);
            case 9U: 
            return ((TIFFSetGetFieldType )33);
            case 12U: 
            return ((TIFFSetGetFieldType )37);
            case 18U: 
            case 13U: 
            return ((TIFFSetGetFieldType )38);
            case 16U: 
            return ((TIFFSetGetFieldType )34);
            case 17U: 
            return ((TIFFSetGetFieldType )35);
            default: 
            return ((TIFFSetGetFieldType )0);
            }
          } else {
            goto _L;
          }
          sprintf(checkpoints_buf, "%d", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "657", "1", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", -3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "673", "-3", checkpoints_buf);
          _L: /* CIL Label */ 
          if ((int )count == -3) {
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "674", "1", checkpoints_buf);
            if ((int )passcount == 1) {
              switch ((unsigned int )type) {
              case 7U: 
              case 1U: 
              return ((TIFFSetGetFieldType )40);
              case 2U: 
              return ((TIFFSetGetFieldType )39);
              case 3U: 
              return ((TIFFSetGetFieldType )42);
              case 4U: 
              return ((TIFFSetGetFieldType )44);
              case 11U: 
              case 10U: 
              case 5U: 
              return ((TIFFSetGetFieldType )48);
              case 6U: 
              return ((TIFFSetGetFieldType )41);
              case 8U: 
              return ((TIFFSetGetFieldType )43);
              case 9U: 
              return ((TIFFSetGetFieldType )45);
              case 12U: 
              return ((TIFFSetGetFieldType )49);
              case 18U: 
              case 13U: 
              return ((TIFFSetGetFieldType )50);
              case 16U: 
              return ((TIFFSetGetFieldType )46);
              case 17U: 
              return ((TIFFSetGetFieldType )47);
              default: 
              return ((TIFFSetGetFieldType )0);
              }
            } else {

            }
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                            "674", "1", checkpoints_buf);
          } else {

          }
          sprintf(checkpoints_buf, "%d", -3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                          "673", "-3", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                        "656", "-1", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                      "639", "1", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "622", "1", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "616", "2", checkpoints_buf);
  return ((TIFFSetGetFieldType )0);
}
}
int TIFFMergeFieldInfo(TIFF *tif , TIFFFieldInfo const   *info , uint32 n ) 
{ 
  char module[19] ;
  char reason[17] ;
  TIFFField *tp ;
  uint32 i ;
  uint32 nfields ;
  void *tmp ;
  void *tmp___0 ;
  uint32 tmp___1 ;
  void *tmp___2 ;
  int tmp___3 ;

  {
  module[0] = (char )'T';

  module[1] = (char )'I';

  module[2] = (char )'F';

  module[3] = (char )'F';

  module[4] = (char )'M';

  module[5] = (char )'e';

  module[6] = (char )'r';

  module[7] = (char )'g';

  module[8] = (char )'e';

  module[9] = (char )'F';

  module[10] = (char )'i';

  module[11] = (char )'e';

  module[12] = (char )'l';

  module[13] = (char )'d';

  module[14] = (char )'I';

  module[15] = (char )'n';

  module[16] = (char )'f';

  module[17] = (char )'o';

  module[18] = (char )'\000';

  reason[0] = (char )'f';

  reason[1] = (char )'o';

  reason[2] = (char )'r';

  reason[3] = (char )' ';

  reason[4] = (char )'f';

  reason[5] = (char )'i';

  reason[6] = (char )'e';

  reason[7] = (char )'l';

  reason[8] = (char )'d';

  reason[9] = (char )'s';

  reason[10] = (char )' ';

  reason[11] = (char )'a';

  reason[12] = (char )'r';

  reason[13] = (char )'r';

  reason[14] = (char )'a';

  reason[15] = (char )'y';

  reason[16] = (char )'\000';


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "728", "0", checkpoints_buf);
  if (tif->tif_nfieldscompat > 0U) {


    tmp = _TIFFCheckRealloc(tif, (void *)tif->tif_fieldscompat,
                            (tmsize_t )(tif->tif_nfieldscompat + 1U),
                            (tmsize_t )sizeof(TIFFFieldArray ),
                            (char const   *)(reason));


    tif->tif_fieldscompat = (TIFFFieldArray *)tmp;

  } else {


    tmp___0 = _TIFFCheckMalloc(tif, (tmsize_t )1,
                               (tmsize_t )sizeof(TIFFFieldArray ),
                               (char const   *)(reason));


    tif->tif_fieldscompat = (TIFFFieldArray *)tmp___0;

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "728", "0", checkpoints_buf);

  if (! tif->tif_fieldscompat) {

    TIFFErrorExt(tif->tif_clientdata, (char const   *)(module),
                 "Failed to allocate fields array");

    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "735", "-1", checkpoints_buf);
    return (-1);
  } else {

  }

  tmp___1 = tif->tif_nfieldscompat;

  (tif->tif_nfieldscompat) ++;

  nfields = tmp___1;

  (tif->tif_fieldscompat + nfields)->type = (TIFFFieldArrayType )2;

  (tif->tif_fieldscompat + nfields)->allocated_size = n;

  (tif->tif_fieldscompat + nfields)->count = n;



  tmp___2 = _TIFFCheckMalloc(tif, (tmsize_t )n, (tmsize_t )sizeof(TIFFField ),
                             (char const   *)(reason));


  (tif->tif_fieldscompat + nfields)->fields = (TIFFField *)tmp___2;


  if (! (tif->tif_fieldscompat + nfields)->fields) {

    TIFFErrorExt(tif->tif_clientdata, (char const   *)(module),
                 "Failed to allocate fields array");

    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "747", "-1", checkpoints_buf);
    return (-1);
  } else {

  }

  tp = (tif->tif_fieldscompat + nfields)->fields;

  i = (uint32 )0;



















  while (i < n) {


    tp->field_tag = (uint32 )(info + i)->field_tag;

    tp->field_readcount = (short )(info + i)->field_readcount;

    tp->field_writecount = (short )(info + i)->field_writecount;

    tp->field_type = (TIFFDataType )(info + i)->field_type;

    tp->reserved = (uint32 )0;



    tp->set_field_type = _TIFFSetGetType((TIFFDataType )(info + i)->field_type,
                                         (short )(info + i)->field_readcount,
                                         (unsigned char )(info + i)->field_passcount);




    tp->get_field_type = _TIFFSetGetType((TIFFDataType )(info + i)->field_type,
                                         (short )(info + i)->field_readcount,
                                         (unsigned char )(info + i)->field_passcount);


    tp->field_bit = (unsigned short )(info + i)->field_bit;

    tp->field_oktochange = (unsigned char )(info + i)->field_oktochange;

    tp->field_passcount = (unsigned char )(info + i)->field_passcount;

    tp->field_name = (char *)(info + i)->field_name;

    tp->field_subfields = (TIFFFieldArray *)((void *)0);

    tp ++;

    i ++;

  }


















  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "769", "tmp___3", checkpoints_buf);

  tmp___3 = _TIFFMergeFields(tif,
                             (TIFFField const   *)(tif->tif_fieldscompat + nfields)->fields,
                             n);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "769", "tmp___3", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "770", "tmp___3", checkpoints_buf);
  if (tmp___3) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, (char const   *)(module),
                 "Setting up field info failed");

    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                    "773", "-1", checkpoints_buf);
    return (-1);
  }
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "770", "tmp___3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-07-19-ce4b7af-7d6e298",
                  "774", "0", checkpoints_buf);
  return (0);
}
}
TIFFFieldInfo const   *TIFFFindFieldInfoByName(TIFF *tif ,
                                               char const   *field_name ,
                                               TIFFDataType dt ) 
{ 


  {
  return ((TIFFFieldInfo const   *)((void *)0));
}
}
TIFFFieldInfo const   *TIFFFindFieldInfo(TIFF *tif , uint32 tag ,
                                         TIFFDataType dt ) 
{ 


  {
  return ((TIFFFieldInfo const   *)((void *)0));
}
}