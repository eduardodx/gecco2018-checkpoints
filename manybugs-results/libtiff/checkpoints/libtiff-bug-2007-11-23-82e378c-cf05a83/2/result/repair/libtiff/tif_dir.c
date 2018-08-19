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
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "280", "0", checkpoints_buf);
    return (0);
  } else {

  }

  tmp___1 = __builtin_va_arg(ap, uint16 *);

  va = tmp___1;


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "284", "0", checkpoints_buf);
  if (*v > 0U) {
    if ((unsigned int )va == (unsigned int )((void *)0)) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "286", "0", checkpoints_buf);
      return (0);
    } else {

    }
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "284", "0", checkpoints_buf);
  i = (uint32 )0;



  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "290", "2", checkpoints_buf);

  while (i < *v) {


    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "294", "2", checkpoints_buf);
    if ((int )*(va + i) > 2) {
      sprintf(checkpoints_buf, "%d", 999);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "295", "999", checkpoints_buf);
      if ((int )*(va + i) == 999) {
        *(va + i) = (uint16 )2;

      } else {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "297", "0", checkpoints_buf);
        return (0);
      }
      sprintf(checkpoints_buf, "%d", 999);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "295", "999", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "294", "2", checkpoints_buf);
    i ++;

  }


  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "290", "2", checkpoints_buf);

  td->td_extrasamples = (uint16 )*v;


  _TIFFsetShortArray(& td->td_sampleinfo, va, (uint32 )td->td_extrasamples);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "302", "1", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "305", "0", checkpoints_buf);
  if (slen > 0U) {
    ep = s + slen;

    cp = s;

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "308", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "308", "0", checkpoints_buf);



    while (1) {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "309", "0", checkpoints_buf);
      if ((int )i > 0) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "309", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "312", "0", checkpoints_buf);

      while (1) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "313", "0", checkpoints_buf);
        if ((int const   )*cp != 0) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "313", "0", checkpoints_buf);
        if ((unsigned int )cp >= (unsigned int )ep) {
          goto bad;
        } else {

        }
        cp ++;

      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "312", "0", checkpoints_buf);

      cp ++;

      i = (uint16 )((int )i - 1);

    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "308", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "308", "0", checkpoints_buf);



    return ((uint32 )(cp - s));
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "305", "0", checkpoints_buf);

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
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "327", "status", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "340", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "341", "16", checkpoints_buf);
    if ((int )td->td_bitspersample == 16) {
      tif->tif_postdecode = & _TIFFSwab16BitData;

    } else {
      sprintf(checkpoints_buf, "%d", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "343", "24", checkpoints_buf);
      if ((int )td->td_bitspersample == 24) {
        tif->tif_postdecode = & _TIFFSwab24BitData;

      } else {
        sprintf(checkpoints_buf, "%d", 32);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "345", "32", checkpoints_buf);
        if ((int )td->td_bitspersample == 32) {
          tif->tif_postdecode = & _TIFFSwab32BitData;

        } else {
          sprintf(checkpoints_buf, "%d", 64);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "347", "64", checkpoints_buf);
          if ((int )td->td_bitspersample == 64) {
            tif->tif_postdecode = & _TIFFSwab64BitData;

          } else {
            sprintf(checkpoints_buf, "%d", 128);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "349", "128", checkpoints_buf);
            if ((int )td->td_bitspersample == 128) {
              tif->tif_postdecode = & _TIFFSwab64BitData;

            } else {

            }
            sprintf(checkpoints_buf, "%d", 128);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "349", "128", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 64);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "347", "64", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 32);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "345", "32", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "343", "24", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "341", "16", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "340", "128", checkpoints_buf);
  break;

  case 259U: 
  tmp___8 = __builtin_va_arg(ap, uint16_vap );

  v = (uint32 )((uint16 )tmp___8);


  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "356", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "356", "7", checkpoints_buf);
  if (tif->tif_dir.td_fieldsset[0] & (1UL << 7)) {

    if ((uint32 )td->td_compression == v) {
      break;
    } else {

    }


    (*(tif->tif_cleanup))(tif);

    tif->tif_flags &= 4294967263U;

  } else {

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "356", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "356", "7", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "363", "status", checkpoints_buf);

  status = TIFFSetCompressionScheme(tif, (int )v);
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "363", "status", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "364", "status", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "364", "0", checkpoints_buf);
  if (status != 0) {
    td->td_compression = (uint16 )v;

  } else {
    status = 0;
    sprintf(checkpoints_buf, "%d", status);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "366", "status", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "364", "status", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "364", "0", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "376", "2", checkpoints_buf);
  if (v != 2U) {

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "377", "1", checkpoints_buf);
    if (v != 1U) {
      goto badvalue;
    } else {

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "377", "1", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "376", "2", checkpoints_buf);
  td->td_fillorder = (uint16 )v;

  break;

  case 274U: 
  tmp___16 = __builtin_va_arg(ap, uint16_vap );

  v = (uint32 )((uint16 )tmp___16);


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "385", "1", checkpoints_buf);
  if (v < 1U) {
    goto badvalue;
  } else {
    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "387", "8", checkpoints_buf);

    if (8U < v) {
      goto badvalue;
    } else {
      td->td_orientation = (uint16 )v;

    }
    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "387", "8", checkpoints_buf);

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "385", "1", checkpoints_buf);
  break;

  case 277U: 
  tmp___18 = __builtin_va_arg(ap, uint16_vap );

  v = (uint32 )((uint16 )tmp___18);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "393", "0", checkpoints_buf);
  if (v == 0U) {
    goto badvalue;
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "393", "0", checkpoints_buf);
  td->td_samplesperpixel = (uint16 )v;

  break;

  case 278U: 
  tmp___20 = __builtin_va_arg(ap, uint32 );

  v32 = tmp___20;


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "400", "0", checkpoints_buf);
  if (v32 == 0U) {
    goto badvalue32;
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "400", "0", checkpoints_buf);
  td->td_rowsperstrip = v32;

  {

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "404", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "404", "2", checkpoints_buf);
  if (! (tif->tif_dir.td_fieldsset[0] & (1UL << 2))) {
    td->td_tilelength = v32;

    td->td_tilewidth = td->td_imagewidth;

  } else {

  }

  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "404", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "404", "2", checkpoints_buf);

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


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "429", "1", checkpoints_buf);
  if (v != 1U) {

    sprintf(checkpoints_buf, "%u", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "430", "2", checkpoints_buf);
    if (v != 2U) {
      goto badvalue;
    } else {

    }

    sprintf(checkpoints_buf, "%u", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "430", "2", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "429", "1", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "444", "1", checkpoints_buf);
  if (v < 1U) {
    goto badvalue;
  } else {
    sprintf(checkpoints_buf, "%u", 3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "446", "3", checkpoints_buf);

    if (3U < v) {
      goto badvalue;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "446", "3", checkpoints_buf);

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "444", "1", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", tmp___55);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "469", "tmp___55", checkpoints_buf);

  case 338U: 
  tmp___55 = setExtraSamples(td, ap, & v);
  sprintf(checkpoints_buf, "%d", tmp___55);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "469", "tmp___55", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___55);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "470", "tmp___55", checkpoints_buf);
  if (tmp___55) {

  } else {
    goto badvalue;
  }
  sprintf(checkpoints_buf, "%d", tmp___55);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "470", "tmp___55", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "483", "16", checkpoints_buf);
  if (v32 % 16U) {

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "484", "0", checkpoints_buf);
    if (tif->tif_mode != 0) {
      goto badvalue32;
    } else {

    }

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "484", "0", checkpoints_buf);

    TIFFWarningExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                   "Nonstandard tile width %d, convert file", v32);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "483", "16", checkpoints_buf);
  td->td_tilewidth = v32;

  tif->tif_flags |= 1024U;

  break;

  case 323U: 
  tmp___61 = __builtin_va_arg(ap, uint32 );

  v32 = tmp___61;


  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "494", "16", checkpoints_buf);
  if (v32 % 16U) {

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "495", "0", checkpoints_buf);
    if (tif->tif_mode != 0) {
      goto badvalue32;
    } else {

    }

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "495", "0", checkpoints_buf);

    TIFFWarningExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                   "Nonstandard tile length %d, convert file", v32);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 16);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "494", "16", checkpoints_buf);
  td->td_tilelength = v32;

  tif->tif_flags |= 1024U;

  break;

  case 32998U: 
  tmp___63 = __builtin_va_arg(ap, uint32 );

  v32 = tmp___63;


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "505", "0", checkpoints_buf);
  if (v32 == 0U) {
    goto badvalue32;
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "505", "0", checkpoints_buf);
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


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "526", "1", checkpoints_buf);
  if (v < 1U) {
    goto badvalue;
  } else {
    sprintf(checkpoints_buf, "%u", 6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "528", "6", checkpoints_buf);

    if (6U < v) {
      goto badvalue;
    } else {

    }
    sprintf(checkpoints_buf, "%u", 6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "528", "6", checkpoints_buf);

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "526", "1", checkpoints_buf);
  td->td_sampleformat = (uint16 )v;

  sprintf(checkpoints_buf, "%d", 5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "532", "5", checkpoints_buf);
  if ((int )td->td_sampleformat == 5) {
    sprintf(checkpoints_buf, "%d", 32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "533", "32", checkpoints_buf);
    if ((int )td->td_bitspersample == 32) {
      if ((unsigned int )tif->tif_postdecode == (unsigned int )(& _TIFFSwab32BitData)) {
        tif->tif_postdecode = & _TIFFSwab16BitData;

      } else {
        goto _L___1;
      }
    } else {
      goto _L___1;
    }
    sprintf(checkpoints_buf, "%d", 32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "533", "32", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "538", "5", checkpoints_buf);
    _L___1: /* CIL Label */ 
    _L___0: /* CIL Label */ 
    if ((int )td->td_sampleformat == 5) {
      goto _L;
    } else {
      sprintf(checkpoints_buf, "%d", 6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "540", "6", checkpoints_buf);
      if ((int )td->td_sampleformat == 6) {
        sprintf(checkpoints_buf, "%d", 64);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "541", "64", checkpoints_buf);
        _L: /* CIL Label */ 
        if ((int )td->td_bitspersample == 64) {
          if ((unsigned int )tif->tif_postdecode == (unsigned int )(& _TIFFSwab64BitData)) {
            tif->tif_postdecode = & _TIFFSwab32BitData;

          } else {

          }
        } else {

        }
        sprintf(checkpoints_buf, "%d", 64);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "541", "64", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", 6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "540", "6", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "538", "5", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 5);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "532", "5", checkpoints_buf);
  break;

  case 32997U: 
  tmp___69 = __builtin_va_arg(ap, uint32 );

  td->td_imagedepth = tmp___69;

  break;

  sprintf(checkpoints_buf, "%u", 8192);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "551", "8192", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "551", "0", checkpoints_buf);
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
    sprintf(checkpoints_buf, "%d", status);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "557", "status", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 8192);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "551", "8192", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "551", "0", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "567", "1", checkpoints_buf);
  case 301U: 
  if ((int )td->td_samplesperpixel - (int )td->td_extrasamples > 1) {
    v = (uint32 )3;

  } else {
    v = (uint32 )1;

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "567", "1", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "584", "status", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "585", "0", checkpoints_buf);
  if (v > 0U) {

    _TIFFsetNString(& td->td_inknames, s, v);

    td->td_inknameslen = (int )v;

  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "585", "0", checkpoints_buf);
  break;


  default: 
  tmp___85 = TIFFFindField(tif, tag, (TIFFDataType )0);


  fip = tmp___85;

  if ((unsigned int )fip == (unsigned int )((void *)0)) {
    goto _L___2;
  } else {
    sprintf(checkpoints_buf, "%d", 65);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "594", "65", checkpoints_buf);
    if ((int const   )fip->field_bit != 65) {

      _L___2: /* CIL Label */ 
      if (fip) {
        tmp___86 = (char const   */* const  */)fip->field_name;

      } else {
        tmp___86 = (char const   */* const  */)"Unknown";

      }


      sprintf(checkpoints_buf, "%u", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "598", "65535", checkpoints_buf);
      if (tag > 65535U) {
        tmp___87 = "pseudo-";

      } else {
        tmp___87 = "";

      }

      sprintf(checkpoints_buf, "%u", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "598", "65535", checkpoints_buf);

      TIFFErrorExt(tif->tif_clientdata, module,
                   "%s: Invalid %stag \"%s\" (not supported by codec)",
                   tif->tif_name, tmp___87, tmp___86);

      status = 0;
      sprintf(checkpoints_buf, "%d", status);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "602", "status", checkpoints_buf);
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", 65);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "594", "65", checkpoints_buf);
  }
  tv = (TIFFTagValue *)((void *)0);

  iCustom = 0;
  sprintf(checkpoints_buf, "%d", iCustom);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "606", "iCustom", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", iCustom);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "607", "iCustom", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", iCustom);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "607", "iCustom", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", iCustom);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "608", "iCustom", checkpoints_buf);

    if (iCustom < td->td_customValueCount) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", iCustom);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "608", "iCustom", checkpoints_buf);


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
    sprintf(checkpoints_buf, "%d", iCustom);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "619", "iCustom", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", iCustom);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "607", "iCustom", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", iCustom);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "607", "iCustom", checkpoints_buf);
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
      sprintf(checkpoints_buf, "%d", status);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "626", "status", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", tv_size);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "635", "tv_size", checkpoints_buf);

  tv_size = _TIFFDataSize((TIFFDataType )fip->field_type);
  sprintf(checkpoints_buf, "%d", tv_size);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "635", "tv_size", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tv_size);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "636", "tv_size", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "636", "0", checkpoints_buf);
  if (tv_size == 0) {
    status = 0;
    sprintf(checkpoints_buf, "%d", status);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "637", "status", checkpoints_buf);

    TIFFErrorExt(tif->tif_clientdata, module,
                 "%s: Bad field type %d for \"%s\"", tif->tif_name,
                 (unsigned int const   )fip->field_type, fip->field_name);

    goto end;
  } else {

  }
  sprintf(checkpoints_buf, "%d", tv_size);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "636", "tv_size", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "636", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "641", "2", checkpoints_buf);
  if ((unsigned int const   )fip->field_type == 2U) {

    if (fip->field_passcount) {
      sprintf(checkpoints_buf, "%d", -3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "643", "-3", checkpoints_buf);
      if ((int const   )fip->field_writecount == -3) {

      } else {

        __assert_fail("fip->field_writecount==-3", "tif_dir.c", 474U,
                      "_TIFFVSetField");

      }
      sprintf(checkpoints_buf, "%d", -3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "643", "-3", checkpoints_buf);

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
      sprintf(checkpoints_buf, "%d", -3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "657", "-3", checkpoints_buf);
      if ((int const   )fip->field_writecount == -3) {

        tmp___97 = __builtin_va_arg(ap, uint32 );

        tv->count = (int )tmp___97;

      } else {

        tmp___99 = __builtin_va_arg(ap, int );

        tv->count = tmp___99;

      }
      sprintf(checkpoints_buf, "%d", -3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "657", "-3", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "662", "-1", checkpoints_buf);
      if ((int const   )fip->field_writecount == -1) {
        tv->count = 1;

      } else {
        sprintf(checkpoints_buf, "%d", -3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "664", "-3", checkpoints_buf);
        if ((int const   )fip->field_writecount == -3) {
          tv->count = 1;

        } else {
          sprintf(checkpoints_buf, "%d", -2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "666", "-2", checkpoints_buf);
          if ((int const   )fip->field_writecount == -2) {
            tv->count = (int )td->td_samplesperpixel;

          } else {
            tv->count = (int )fip->field_writecount;

          }
          sprintf(checkpoints_buf, "%d", -2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "666", "-2", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", -3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "664", "-3", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "662", "-1", checkpoints_buf);
    }



    tv->value = _TIFFCheckMalloc(tif, (tmsize_t )tv_size, (tmsize_t )tv->count,
                                 "Tag Value");



    if (! tv->value) {
      status = 0;
      sprintf(checkpoints_buf, "%d", status);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "671", "status", checkpoints_buf);
      goto end;
    } else {

    }


    if (fip->field_passcount) {
      goto _L___7;
    } else {
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "676", "-1", checkpoints_buf);
      if ((int const   )fip->field_writecount == -1) {
        goto _L___7;
      } else {
        sprintf(checkpoints_buf, "%d", -3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "678", "-3", checkpoints_buf);
        if ((int const   )fip->field_writecount == -3) {
          goto _L___7;
        } else {
          sprintf(checkpoints_buf, "%d", -2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "680", "-2", checkpoints_buf);
          if ((int const   )fip->field_writecount == -2) {
            goto _L___7;
          } else {

            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "682", "1", checkpoints_buf);
            if (tv->count > 1) {

              sprintf(checkpoints_buf, "%u", 297);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "683", "297", checkpoints_buf);
              _L___7: /* CIL Label */ 
              if (fip->field_tag != 297U) {

                sprintf(checkpoints_buf, "%u", 321);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "684", "321", checkpoints_buf);
                if (fip->field_tag != 321U) {

                  sprintf(checkpoints_buf, "%u", 530);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "685", "530", checkpoints_buf);
                  if (fip->field_tag != 530U) {

                    sprintf(checkpoints_buf, "%u", 336);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "686", "336", checkpoints_buf);
                    if (fip->field_tag != 336U) {

                      tmp___101 = __builtin_va_arg(ap, void *);


                      _TIFFmemcpy(tv->value, (void const   *)tmp___101,
                                  (tmsize_t )(tv->count * tv_size));

                    } else {
                      goto _L___6;
                    }

                    sprintf(checkpoints_buf, "%u", 336);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "686", "336", checkpoints_buf);
                  } else {
                    goto _L___6;
                  }

                  sprintf(checkpoints_buf, "%u", 530);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "685", "530", checkpoints_buf);
                } else {
                  goto _L___6;
                }

                sprintf(checkpoints_buf, "%u", 321);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "684", "321", checkpoints_buf);
              } else {
                goto _L___6;
              }

              sprintf(checkpoints_buf, "%u", 297);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "683", "297", checkpoints_buf);
            } else {
              _L___6: /* CIL Label */ 
              _L___5: /* CIL Label */ 
              _L___4: /* CIL Label */ 
              _L___3: /* CIL Label */ 
              val = (char *)tv->value;

              i___0 = 0;
              sprintf(checkpoints_buf, "%d", i___0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "694", "i___0", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", i___0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "695", "i___0", checkpoints_buf);

              sprintf(checkpoints_buf, "%d", i___0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "695", "i___0", checkpoints_buf);

              while (1) {
                sprintf(checkpoints_buf, "%d", i___0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "696", "i___0", checkpoints_buf);

                if (i___0 < tv->count) {

                } else {
                  break;
                }
                sprintf(checkpoints_buf, "%d", i___0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "696", "i___0", checkpoints_buf);

                switch ((unsigned int const   )fip->field_type) {

                case 7U: 
                case 1U: 
                tmp___103 = __builtin_va_arg(ap, int );

                v___0 = (uint8 )tmp___103;


                _TIFFmemcpy((void *)val, (void const   *)(& v___0),
                            (tmsize_t )tv_size);

                break;

                case 6U: 
                tmp___105 = __builtin_va_arg(ap, int );

                v___1 = (int8 )tmp___105;


                _TIFFmemcpy((void *)val, (void const   *)(& v___1),
                            (tmsize_t )tv_size);

                break;

                case 3U: 
                tmp___107 = __builtin_va_arg(ap, int );

                v___2 = (uint16 )tmp___107;


                _TIFFmemcpy((void *)val, (void const   *)(& v___2),
                            (tmsize_t )tv_size);

                break;

                case 8U: 
                tmp___109 = __builtin_va_arg(ap, int );

                v___3 = (int16 )tmp___109;


                _TIFFmemcpy((void *)val, (void const   *)(& v___3),
                            (tmsize_t )tv_size);

                break;

                case 13U: 
                case 4U: 
                tmp___111 = __builtin_va_arg(ap, uint32 );

                v___4 = tmp___111;


                _TIFFmemcpy((void *)val, (void const   *)(& v___4),
                            (tmsize_t )tv_size);

                break;

                case 9U: 
                tmp___113 = __builtin_va_arg(ap, int32 );

                v___5 = tmp___113;


                _TIFFmemcpy((void *)val, (void const   *)(& v___5),
                            (tmsize_t )tv_size);

                break;

                case 18U: 
                case 16U: 
                tmp___115 = __builtin_va_arg(ap, uint64 );

                v___6 = tmp___115;


                _TIFFmemcpy((void *)val, (void const   *)(& v___6),
                            (tmsize_t )tv_size);

                break;

                case 17U: 
                tmp___117 = __builtin_va_arg(ap, int64 );

                v___7 = tmp___117;


                _TIFFmemcpy((void *)val, (void const   *)(& v___7),
                            (tmsize_t )tv_size);

                break;

                case 11U: 
                case 10U: 
                case 5U: 
                tmp___119 = __builtin_va_arg(ap, double );

                v___8 = (float )tmp___119;
                sprintf(checkpoints_buf, "%f", v___8);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "733", "v___8", checkpoints_buf);

                _TIFFmemcpy((void *)val, (void const   *)(& v___8),
                            (tmsize_t )tv_size);

                break;

                case 12U: 
                tmp___121 = __builtin_va_arg(ap, double );

                v___9 = tmp___121;
                sprintf(checkpoints_buf, "%lf", v___9);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "737", "v___9", checkpoints_buf);

                _TIFFmemcpy((void *)val, (void const   *)(& v___9),
                            (tmsize_t )tv_size);

                break;

                default: 
                _TIFFmemset((void *)val, 0, (tmsize_t )tv_size);

                status = 0;
                sprintf(checkpoints_buf, "%d", status);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "741", "status", checkpoints_buf);
                break;
                }
                i___0 ++;
                sprintf(checkpoints_buf, "%d", i___0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "743", "i___0", checkpoints_buf);
                val += tv_size;

              }
              sprintf(checkpoints_buf, "%d", i___0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "695", "i___0", checkpoints_buf);

              sprintf(checkpoints_buf, "%d", i___0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "695", "i___0", checkpoints_buf);

            }

            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "682", "1", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", -2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "680", "-2", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", -3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "678", "-3", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", -1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "676", "-1", checkpoints_buf);
    }

  }
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "641", "2", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "745", "status", checkpoints_buf);
  if (status) {


    tmp___122 = TIFFFieldWithTag(tif, tag);




    tmp___123 = TIFFFieldWithTag(tif, tag);


    tif->tif_dir.td_fieldsset[(int const   )tmp___122->field_bit / 32] |= 1UL << ((int const   )tmp___123->field_bit & 31);

    tif->tif_flags |= 8U;

  } else {

  }
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "745", "status", checkpoints_buf);

  end: 
  __builtin_va_end(ap);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "752", "status", checkpoints_buf);
  return (status);


  badvalue: 
  tmp___124 = TIFFFieldWithTag(tif, tag);



  TIFFErrorExt(tif->tif_clientdata, module, "%s: Bad value %d for \"%s\" tag",
               tif->tif_name, v, tmp___124->field_name);


  __builtin_va_end(ap);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "756", "0", checkpoints_buf);
  return (0);


  badvalue32: 
  tmp___125 = TIFFFieldWithTag(tif, tag);



  TIFFErrorExt(tif->tif_clientdata, module, "%s: Bad value %ld for \"%s\" tag",
               tif->tif_name, v32, tmp___125->field_name);


  __builtin_va_end(ap);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "760", "0", checkpoints_buf);
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

    sprintf(checkpoints_buf, "%u", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "764", "65535", checkpoints_buf);
    if (tag > 65535U) {
      tmp___0 = "pseudo-";

    } else {
      tmp___0 = "";

    }

    sprintf(checkpoints_buf, "%u", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "764", "65535", checkpoints_buf);

    TIFFErrorExt(tif->tif_clientdata, "TIFFSetField", "%s: Unknown %stag %u",
                 tif->tif_name, tmp___0, tag);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "768", "0", checkpoints_buf);
    return (0);
  } else {

  }


  sprintf(checkpoints_buf, "%u", 257);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "770", "257", checkpoints_buf);
  if (tag != 257U) {

    sprintf(checkpoints_buf, "%u", 64);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "771", "64", checkpoints_buf);
    if (tif->tif_flags & 64U) {

      if (! fip->field_oktochange) {

        TIFFErrorExt(tif->tif_clientdata, "TIFFSetField",
                     "%s: Cannot modify tag \"%s\" while writing",
                     tif->tif_name, fip->field_name);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "774", "0", checkpoints_buf);
        return (0);
      } else {

      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 64);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "771", "64", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 257);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "770", "257", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "778", "1", checkpoints_buf);
  return (1);
}
}
int TIFFSetField(TIFF *tif , uint32 tag  , ...) 
{ 
  va_list ap ;
  int status ;

  {

  __builtin_va_start(ap, tag);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "780", "status", checkpoints_buf);

  status = TIFFVSetField(tif, tag, ap);
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "780", "status", checkpoints_buf);


  __builtin_va_end(ap);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "782", "status", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "783", "tmp___2", checkpoints_buf);

  tmp___2 = OkToChangeTag(tif, tag);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "783", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "784", "tmp___2", checkpoints_buf);
  if (tmp___2) {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "785", "tmp___0", checkpoints_buf);

    tmp___0 = (*(tif->tif_tagmethods.vsetfield))(tif, tag, ap);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "785", "tmp___0", checkpoints_buf);

    tmp___1 = tmp___0;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "786", "tmp___1", checkpoints_buf);
  } else {
    tmp___1 = 0;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "787", "tmp___1", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "784", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "788", "tmp___1", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", ret_val);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "790", "ret_val", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "879", "1", checkpoints_buf);
  if ((int )td->td_extrasamples == 1) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "880", "1", checkpoints_buf);
    if ((int )*(td->td_sampleinfo + 0) == 1) {
      tmp___61 = 1;
      sprintf(checkpoints_buf, "%d", tmp___61);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "881", "tmp___61", checkpoints_buf);
    } else {
      tmp___61 = 0;
      sprintf(checkpoints_buf, "%d", tmp___61);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "882", "tmp___61", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "880", "1", checkpoints_buf);
  } else {
    tmp___61 = 0;
    sprintf(checkpoints_buf, "%d", tmp___61);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "883", "tmp___61", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "879", "1", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "935", "1", checkpoints_buf);
  if ((int )td->td_samplesperpixel - (int )td->td_extrasamples > 1) {

    tmp___97 = __builtin_va_arg(ap, uint16 **);

    *tmp___97 = td->td_transferfunction[1];


    tmp___99 = __builtin_va_arg(ap, uint16 **);

    *tmp___99 = td->td_transferfunction[2];

  } else {

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "935", "1", checkpoints_buf);
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
  } else {
    sprintf(checkpoints_buf, "%d", 65);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "949", "65", checkpoints_buf);
    if ((int const   )fip->field_bit != 65) {

      _L: /* CIL Label */ 
      if (fip) {
        tmp___103 = (char const   */* const  */)fip->field_name;

      } else {
        tmp___103 = (char const   */* const  */)"Unknown";

      }


      sprintf(checkpoints_buf, "%u", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "953", "65535", checkpoints_buf);
      if (tag > 65535U) {
        tmp___104 = "pseudo-";

      } else {
        tmp___104 = "";

      }

      sprintf(checkpoints_buf, "%u", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "953", "65535", checkpoints_buf);

      TIFFErrorExt(tif->tif_clientdata, "_TIFFVGetField",
                   "%s: Invalid %stag \"%s\" (not supported by codec)",
                   tif->tif_name, tmp___104, tmp___103);

      ret_val = 0;
      sprintf(checkpoints_buf, "%d", ret_val);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "957", "ret_val", checkpoints_buf);
      break;
    } else {

    }
    sprintf(checkpoints_buf, "%d", 65);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "949", "65", checkpoints_buf);
  }
  ret_val = 0;
  sprintf(checkpoints_buf, "%d", ret_val);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "960", "ret_val", checkpoints_buf);
  i = 0;
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "961", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "962", "i", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "962", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "963", "i", checkpoints_buf);

    if (i < td->td_customValueCount) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "963", "i", checkpoints_buf);

    tv = td->td_customValues + i;


    if ((tv->info)->field_tag != (uint32 const   )tag) {
      goto __Cont;
    } else {

    }


    if (fip->field_passcount) {
      sprintf(checkpoints_buf, "%d", -3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "971", "-3", checkpoints_buf);
      if ((int const   )fip->field_readcount == -3) {

        tmp___106 = __builtin_va_arg(ap, uint32 *);

        *tmp___106 = (uint32 )tv->count;

      } else {

        tmp___108 = __builtin_va_arg(ap, uint16 *);

        *tmp___108 = (uint16 )tv->count;

      }
      sprintf(checkpoints_buf, "%d", -3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "971", "-3", checkpoints_buf);

      tmp___110 = __builtin_va_arg(ap, void **);

      *tmp___110 = tv->value;

      ret_val = 1;
      sprintf(checkpoints_buf, "%d", ret_val);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "978", "ret_val", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%u", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "979", "2", checkpoints_buf);
      if ((unsigned int const   )fip->field_type == 2U) {
        goto _L___4;
      } else {
        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "981", "-1", checkpoints_buf);
        if ((int const   )fip->field_readcount == -1) {
          goto _L___4;
        } else {
          sprintf(checkpoints_buf, "%d", -3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "983", "-3", checkpoints_buf);
          if ((int const   )fip->field_readcount == -3) {
            goto _L___4;
          } else {
            sprintf(checkpoints_buf, "%d", -2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "985", "-2", checkpoints_buf);
            if ((int const   )fip->field_readcount == -2) {
              goto _L___4;
            } else {

              sprintf(checkpoints_buf, "%d", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "987", "1", checkpoints_buf);
              if (tv->count > 1) {

                sprintf(checkpoints_buf, "%u", 297);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "988", "297", checkpoints_buf);
                _L___4: /* CIL Label */ 
                if (fip->field_tag != 297U) {

                  sprintf(checkpoints_buf, "%u", 321);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "989", "321", checkpoints_buf);
                  if (fip->field_tag != 321U) {

                    sprintf(checkpoints_buf, "%u", 530);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "990", "530", checkpoints_buf);
                    if (fip->field_tag != 530U) {

                      sprintf(checkpoints_buf, "%u", 336);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                      "991", "336", checkpoints_buf);
                      if (fip->field_tag != 336U) {

                        tmp___112 = __builtin_va_arg(ap, void **);

                        *tmp___112 = tv->value;

                        ret_val = 1;
                        sprintf(checkpoints_buf, "%d", ret_val);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                        "994", "ret_val", checkpoints_buf);
                      } else {
                        goto _L___3;
                      }

                      sprintf(checkpoints_buf, "%u", 336);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                      "991", "336", checkpoints_buf);
                    } else {
                      goto _L___3;
                    }

                    sprintf(checkpoints_buf, "%u", 530);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                    "990", "530", checkpoints_buf);
                  } else {
                    goto _L___3;
                  }

                  sprintf(checkpoints_buf, "%u", 321);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "989", "321", checkpoints_buf);
                } else {
                  goto _L___3;
                }

                sprintf(checkpoints_buf, "%u", 297);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "988", "297", checkpoints_buf);
              } else {
                _L___3: /* CIL Label */ 
                _L___2: /* CIL Label */ 
                _L___1: /* CIL Label */ 
                _L___0: /* CIL Label */ 
                val = (char *)tv->value;

                j = 0;
                sprintf(checkpoints_buf, "%d", j);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1000", "j", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", j);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1001", "j", checkpoints_buf);

                sprintf(checkpoints_buf, "%d", j);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1001", "j", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", tmp___113);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1001", "tmp___113", checkpoints_buf);


                while (1) {
                  sprintf(checkpoints_buf, "%d", j);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1002", "j", checkpoints_buf);

                  if (j < tv->count) {

                  } else {
                    break;
                  }
                  sprintf(checkpoints_buf, "%d", j);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1002", "j", checkpoints_buf);

                  switch ((unsigned int const   )fip->field_type) {

                  case 7U: 
                  case 1U: 
                  tmp___115 = __builtin_va_arg(ap, uint8 *);

                  *tmp___115 = *((uint8 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1008", "ret_val", checkpoints_buf);
                  break;

                  case 6U: 
                  tmp___117 = __builtin_va_arg(ap, int8 *);

                  *tmp___117 = *((int8 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1012", "ret_val", checkpoints_buf);
                  break;

                  case 3U: 
                  tmp___119 = __builtin_va_arg(ap, uint16 *);

                  *tmp___119 = *((uint16 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1016", "ret_val", checkpoints_buf);
                  break;

                  case 8U: 
                  tmp___121 = __builtin_va_arg(ap, int16 *);

                  *tmp___121 = *((int16 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1020", "ret_val", checkpoints_buf);
                  break;

                  case 13U: 
                  case 4U: 
                  tmp___123 = __builtin_va_arg(ap, uint32 *);

                  *tmp___123 = *((uint32 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1024", "ret_val", checkpoints_buf);
                  break;

                  case 9U: 
                  tmp___125 = __builtin_va_arg(ap, int32 *);

                  *tmp___125 = *((int32 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1028", "ret_val", checkpoints_buf);
                  break;

                  case 18U: 
                  case 16U: 
                  tmp___127 = __builtin_va_arg(ap, uint64 *);

                  *tmp___127 = *((uint64 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1032", "ret_val", checkpoints_buf);
                  break;

                  case 17U: 
                  tmp___129 = __builtin_va_arg(ap, int64 *);

                  *tmp___129 = *((int64 *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1036", "ret_val", checkpoints_buf);
                  break;

                  case 11U: 
                  case 10U: 
                  case 5U: 
                  tmp___131 = __builtin_va_arg(ap, float *);

                  *tmp___131 = *((float *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1040", "ret_val", checkpoints_buf);
                  break;

                  case 12U: 
                  tmp___133 = __builtin_va_arg(ap, double *);

                  *tmp___133 = *((double *)val);

                  ret_val = 1;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1044", "ret_val", checkpoints_buf);
                  break;
                  default: 
                  ret_val = 0;
                  sprintf(checkpoints_buf, "%d", ret_val);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1046", "ret_val", checkpoints_buf);
                  break;
                  }
                  j ++;
                  sprintf(checkpoints_buf, "%d", j);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1048", "j", checkpoints_buf);
                  sprintf(checkpoints_buf, "%d", tmp___113);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1049", "tmp___113", checkpoints_buf);

                  tmp___113 = _TIFFDataSize((TIFFDataType )(tv->info)->field_type);
                  sprintf(checkpoints_buf, "%d", tmp___113);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                  "1049", "tmp___113", checkpoints_buf);

                  val += tmp___113;

                }
                sprintf(checkpoints_buf, "%d", j);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1001", "j", checkpoints_buf);

                sprintf(checkpoints_buf, "%d", j);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1001", "j", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", tmp___113);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1001", "tmp___113", checkpoints_buf);


              }

              sprintf(checkpoints_buf, "%d", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "987", "1", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", -2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "985", "-2", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", -3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "983", "-3", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", -1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "981", "-1", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "979", "2", checkpoints_buf);
    }

    break;
    __Cont: /* CIL Label */ 
    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1052", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "962", "i", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "962", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", ret_val);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1053", "ret_val", checkpoints_buf);
  return (ret_val);
}
}
int TIFFGetField(TIFF *tif , uint32 tag  , ...) 
{ 
  int status ;
  va_list ap ;

  {

  __builtin_va_start(ap, tag);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1055", "status", checkpoints_buf);

  status = TIFFVGetField(tif, tag, ap);
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1055", "status", checkpoints_buf);


  __builtin_va_end(ap);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1057", "status", checkpoints_buf);
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

    sprintf(checkpoints_buf, "%u", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1061", "65535", checkpoints_buf);
    if (tag > 65535U) {
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1062", "tmp___0", checkpoints_buf);

      tmp___0 = (*(tif->tif_tagmethods.vgetfield))(tif, tag, ap);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1062", "tmp___0", checkpoints_buf);

      tmp___1 = tmp___0;
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1063", "tmp___1", checkpoints_buf);
    } else {

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1064", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 31);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1064", "31", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[(int const   )fip->field_bit / 32] & (1UL << ((int const   )fip->field_bit & 31))) {
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1065", "tmp___0", checkpoints_buf);

        tmp___0 = (*(tif->tif_tagmethods.vgetfield))(tif, tag, ap);
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1065", "tmp___0", checkpoints_buf);

        tmp___1 = tmp___0;
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1066", "tmp___1", checkpoints_buf);
      } else {
        tmp___1 = 0;
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1067", "tmp___1", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1064", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 31);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1064", "31", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1061", "65535", checkpoints_buf);
  } else {
    tmp___1 = 0;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1068", "tmp___1", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1069", "tmp___1", checkpoints_buf);
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
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1118", "i", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1119", "i", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1119", "i", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1120", "i", checkpoints_buf);

    if (i < td->td_customValueCount) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1120", "i", checkpoints_buf);


    if ((td->td_customValues + i)->value) {

      _TIFFfree((td->td_customValues + i)->value);

    } else {

    }

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1126", "i", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1119", "i", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1119", "i", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1142", "0", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1174", "1", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1175", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1175", "0", checkpoints_buf);
  if ((tif->tif_flags & 2048U) != 0U) {
    poff = *nextdir;


    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1177", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      poffa = (tmsize_t )poff;

      poffb = (tmsize_t )((unsigned long )poffa + (unsigned long )sizeof(uint16 ));


      if ((uint64 )poffa != poff) {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1182", "0", checkpoints_buf);
        return (0);
      } else {


        if (poffb < poffa) {

          TIFFErrorExt(tif->tif_clientdata, module___0,
                       "Error fetching directory count");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "1185", "0", checkpoints_buf);
          return (0);
        } else {

          if (poffb < (tmsize_t )sizeof(uint16 )) {

            TIFFErrorExt(tif->tif_clientdata, module___0,
                         "Error fetching directory count");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "1188", "0", checkpoints_buf);
            return (0);
          } else {


            if (poffb > tif->tif_size) {

              TIFFErrorExt(tif->tif_clientdata, module___0,
                           "Error fetching directory count");

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "1191", "0", checkpoints_buf);
              return (0);
            } else {

            }


          }

        }


      }


      _TIFFmemcpy((void *)(& dircount), (void const   *)(tif->tif_base + poffa),
                  (tmsize_t )sizeof(uint16 ));


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1194", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort(& dircount);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1194", "128", checkpoints_buf);
      poffc = poffb + (tmsize_t )((int )dircount * 12);

      poffd = (tmsize_t )((unsigned long )poffc + (unsigned long )sizeof(uint32 ));



      if (poffc < poffb) {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1201", "0", checkpoints_buf);
        return (0);
      } else {

        if (poffc < (tmsize_t )((int )dircount * 12)) {

          TIFFErrorExt(tif->tif_clientdata, module___0,
                       "Error fetching directory link");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "1204", "0", checkpoints_buf);
          return (0);
        } else {


          if (poffd < poffc) {

            TIFFErrorExt(tif->tif_clientdata, module___0,
                         "Error fetching directory link");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "1207", "0", checkpoints_buf);
            return (0);
          } else {

            if (poffd < (tmsize_t )sizeof(uint32 )) {

              TIFFErrorExt(tif->tif_clientdata, module___0,
                           "Error fetching directory link");

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "1210", "0", checkpoints_buf);
              return (0);
            } else {


              if (poffd > tif->tif_size) {

                TIFFErrorExt(tif->tif_clientdata, module___0,
                             "Error fetching directory link");

                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1213", "0", checkpoints_buf);
                return (0);
              } else {

              }


            }

          }


        }

      }


      if ((unsigned int )off != (unsigned int )((void *)0)) {
        *off = (uint64 )poffc;

      } else {

      }

      _TIFFmemcpy((void *)(& nextdir32),
                  (void const   *)(tif->tif_base + poffc),
                  (tmsize_t )sizeof(uint32 ));


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1219", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong(& nextdir32);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1219", "128", checkpoints_buf);
      *nextdir = (uint64 )nextdir32;

    } else {
      poffa___0 = (tmsize_t )poff;

      poffb___0 = (tmsize_t )((unsigned long )poffa___0 + (unsigned long )sizeof(uint64 ));


      if ((uint64 )poffa___0 != poff) {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1227", "0", checkpoints_buf);
        return (0);
      } else {


        if (poffb___0 < poffa___0) {

          TIFFErrorExt(tif->tif_clientdata, module___0,
                       "Error fetching directory count");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "1230", "0", checkpoints_buf);
          return (0);
        } else {

          if (poffb___0 < (tmsize_t )sizeof(uint64 )) {

            TIFFErrorExt(tif->tif_clientdata, module___0,
                         "Error fetching directory count");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "1233", "0", checkpoints_buf);
            return (0);
          } else {


            if (poffb___0 > tif->tif_size) {

              TIFFErrorExt(tif->tif_clientdata, module___0,
                           "Error fetching directory count");

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "1236", "0", checkpoints_buf);
              return (0);
            } else {

            }


          }

        }


      }


      _TIFFmemcpy((void *)(& dircount64),
                  (void const   *)(tif->tif_base + poffa___0),
                  (tmsize_t )sizeof(uint64 ));


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1239", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& dircount64);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1239", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1242", "65535", checkpoints_buf);
      if (dircount64 > 65535ULL) {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Sanity check on directory count failed");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1244", "0", checkpoints_buf);
        return (0);
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1242", "65535", checkpoints_buf);
      dircount16 = (uint16 )dircount64;

      poffc___0 = poffb___0 + (tmsize_t )((int )dircount16 * 20);

      poffd___0 = (tmsize_t )((unsigned long )poffc___0 + (unsigned long )sizeof(uint64 ));



      if (poffc___0 < poffb___0) {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory link");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1251", "0", checkpoints_buf);
        return (0);
      } else {

        if (poffc___0 < (tmsize_t )((int )dircount16 * 20)) {

          TIFFErrorExt(tif->tif_clientdata, module___0,
                       "Error fetching directory link");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "1254", "0", checkpoints_buf);
          return (0);
        } else {


          if (poffd___0 < poffc___0) {

            TIFFErrorExt(tif->tif_clientdata, module___0,
                         "Error fetching directory link");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                            "1257", "0", checkpoints_buf);
            return (0);
          } else {

            if (poffd___0 < (tmsize_t )sizeof(uint64 )) {

              TIFFErrorExt(tif->tif_clientdata, module___0,
                           "Error fetching directory link");

              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                              "1260", "0", checkpoints_buf);
              return (0);
            } else {


              if (poffd___0 > tif->tif_size) {

                TIFFErrorExt(tif->tif_clientdata, module___0,
                             "Error fetching directory link");

                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                                "1263", "0", checkpoints_buf);
                return (0);
              } else {

              }


            }

          }


        }

      }


      if ((unsigned int )off != (unsigned int )((void *)0)) {
        *off = (uint64 )poffc___0;

      } else {

      }

      _TIFFmemcpy((void *)nextdir, (void const   *)(tif->tif_base + poffc___0),
                  (tmsize_t )sizeof(uint64 ));


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1269", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(nextdir);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1269", "128", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1177", "524288", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1272", "1", checkpoints_buf);
    return (1);
  } else {

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1273", "524288", checkpoints_buf);
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

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "1280", "0", checkpoints_buf);
          return (0);
        }
      } else {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "%s: Error fetching directory count", tif->tif_name);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1282", "0", checkpoints_buf);
        return (0);
      }



      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1283", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort(& dircount___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1283", "128", checkpoints_buf);
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

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1293", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1294", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong(& nextdir32___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1294", "128", checkpoints_buf);
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

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                          "1304", "0", checkpoints_buf);
          return (0);
        }
      } else {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "%s: Error fetching directory count", tif->tif_name);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1306", "0", checkpoints_buf);
        return (0);
      }



      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1307", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& dircount64___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1307", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1310", "65535", checkpoints_buf);
      if (dircount64___0 > 65535ULL) {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error fetching directory count");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1312", "0", checkpoints_buf);
        return (0);
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1310", "65535", checkpoints_buf);
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

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                        "1322", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1323", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(nextdir);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1323", "128", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1273", "524288", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1326", "1", checkpoints_buf);
    return (1);
  }

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1175", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1175", "0", checkpoints_buf);
}
}
uint16 TIFFNumberOfDirectories(TIFF *tif ) 
{ 
  uint64 nextdir ;
  uint16 n ;
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1327", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    nextdir = (uint64 )tif->tif_header.classic.tiff_diroff;

  } else {
    nextdir = tif->tif_header.big.tiff_diroff;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1327", "524288", checkpoints_buf);
  n = (uint16 )0;


  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1331", "0", checkpoints_buf);

  while (1) {

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1332", "0", checkpoints_buf);
    if (nextdir != 0ULL) {
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1333", "tmp", checkpoints_buf);

      tmp = TIFFAdvanceDirectory(tif, & nextdir, (uint64 *)((void *)0));
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1333", "tmp", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1334", "tmp", checkpoints_buf);
      if (tmp) {

      } else {
        break;
      }
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1334", "tmp", checkpoints_buf);
    } else {
      break;
    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1332", "0", checkpoints_buf);
    n = (uint16 )((int )n + 1);

  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1331", "0", checkpoints_buf);


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

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1340", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    nextdir = (uint64 )tif->tif_header.classic.tiff_diroff;

  } else {
    nextdir = tif->tif_header.big.tiff_diroff;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1340", "524288", checkpoints_buf);
  n = dirn;

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1344", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1344", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1344", "tmp", checkpoints_buf);

  while (1) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1345", "0", checkpoints_buf);
    if ((int )n > 0) {

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1346", "0", checkpoints_buf);
      if (nextdir != 0ULL) {

      } else {
        break;
      }

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1346", "0", checkpoints_buf);
    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1345", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1350", "tmp", checkpoints_buf);

    tmp = TIFFAdvanceDirectory(tif, & nextdir, (uint64 *)((void *)0));
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1350", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1351", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1353", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1351", "tmp", checkpoints_buf);
    n = (uint16 )((int )n - 1);

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1344", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1344", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1344", "tmp", checkpoints_buf);

  tif->tif_nextdiroff = nextdir;

  tif->tif_curdir = (uint16 )(((int )dirn - (int )n) - 1);

  tif->tif_dirnumber = (uint16 )0;

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1358", "tmp___0", checkpoints_buf);

  tmp___0 = TIFFReadDirectory(tif);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1358", "tmp___0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1359", "tmp___0", checkpoints_buf);
  return (tmp___0);
}
}
int TIFFSetSubDirectory(TIFF *tif , uint64 diroff ) 
{ 
  int tmp ;

  {
  tif->tif_nextdiroff = diroff;

  tif->tif_dirnumber = (uint16 )0;

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1362", "tmp", checkpoints_buf);

  tmp = TIFFReadDirectory(tif);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1362", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1363", "tmp", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1365", "0", checkpoints_buf);
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

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1366", "0", checkpoints_buf);
  if (tif->tif_mode == 0) {

    TIFFErrorExt(tif->tif_clientdata, module___1,
                 "Can not unlink directory in read-only file");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1368", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1366", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1370", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    nextdir = (uint64 )tif->tif_header.classic.tiff_diroff;

    off = (uint64 )4;

  } else {
    nextdir = tif->tif_header.big.tiff_diroff;

    off = (uint64 )8;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1370", "524288", checkpoints_buf);
  n = (uint16 )((int )dirn - 1);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "tmp", checkpoints_buf);

  while (1) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1377", "0", checkpoints_buf);
    if ((int )n > 0) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1377", "0", checkpoints_buf);

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1380", "0", checkpoints_buf);
    if (nextdir == 0ULL) {

      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Directory %d does not exist", (int )dirn);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1382", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1380", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1384", "tmp", checkpoints_buf);

    tmp = TIFFAdvanceDirectory(tif, & nextdir, & off);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1384", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1385", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1387", "0", checkpoints_buf);
      return (0);
    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1385", "tmp", checkpoints_buf);
    n = (uint16 )((int )n - 1);

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1376", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1389", "tmp___0", checkpoints_buf);

  tmp___0 = TIFFAdvanceDirectory(tif, & nextdir, (uint64 *)((void *)0));
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1389", "tmp___0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1390", "tmp___0", checkpoints_buf);
  if (tmp___0) {

  } else {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1392", "0", checkpoints_buf);
    return (0);
  }
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1390", "tmp___0", checkpoints_buf);

  (*(tif->tif_seekproc))(tif->tif_clientdata, off, 0);


  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1394", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    nextdir32 = (uint32 )nextdir;


    if ((uint64 )nextdir32 == nextdir) {

    } else {

      __assert_fail("(uint64)nextdir32==nextdir", "tif_dir.c", 1429U,
                    "TIFFUnlinkDirectory");

    }


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1399", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& nextdir32);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1399", "128", checkpoints_buf);


    tmp___1 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                      (void *)(& nextdir32),
                                      (tmsize_t )sizeof(uint32 ));


    if ((unsigned long )tmp___1 == (unsigned long )sizeof(uint32 )) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Error writing directory link");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1406", "0", checkpoints_buf);
      return (0);
    }
  } else {

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1407", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(& nextdir);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                    "1407", "128", checkpoints_buf);


    tmp___2 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& nextdir),
                                      (tmsize_t )sizeof(uint64 ));


    if ((unsigned long )tmp___2 == (unsigned long )sizeof(uint64 )) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___1,
                   "Error writing directory link");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                      "1414", "0", checkpoints_buf);
      return (0);
    }
  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1394", "524288", checkpoints_buf);

  (*(tif->tif_cleanup))(tif);


  sprintf(checkpoints_buf, "%u", 512);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1416", "512", checkpoints_buf);
  if (tif->tif_flags & 512U) {

    if (tif->tif_rawdata) {

      _TIFFfree((void *)tif->tif_rawdata);

      tif->tif_rawdata = (uint8 *)((void *)0);

      tif->tif_rawcc = (tmsize_t )0;

    } else {

    }

  } else {

  }

  sprintf(checkpoints_buf, "%u", 512);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1416", "512", checkpoints_buf);
  tif->tif_flags &= 4294963119U;


  TIFFFreeDirectory(tif);


  TIFFDefaultDirectory(tif);

  tif->tif_diroff = (uint64 )0;

  tif->tif_nextdiroff = (uint64 )0;

  tif->tif_curoff = (uint64 )0;

  tif->tif_row = (uint32 )-1;

  tif->tif_curstrip = (uint32 )-1;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2007-11-23-82e378c-cf05a83",
                  "1431", "1", checkpoints_buf);
  return (1);
}
}
