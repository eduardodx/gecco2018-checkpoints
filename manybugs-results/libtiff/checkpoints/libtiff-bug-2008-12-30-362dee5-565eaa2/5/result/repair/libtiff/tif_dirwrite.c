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
typedef uint64 toff_t;
typedef uint32 ttag_t;
typedef uint16 tdir_t;
typedef uint16 tsample_t;
typedef uint32 tstrile_t;
typedef tstrile_t tstrip_t;
typedef tstrile_t ttile_t;
typedef tmsize_t tsize_t;
typedef void *tdata_t;
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
typedef toff_t (*TIFFSeekProc)(thandle_t  , toff_t  , int  );
typedef int (*TIFFCloseProc)(thandle_t  );
typedef toff_t (*TIFFSizeProc)(thandle_t  );
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
union __anonunion_tdir_offset_38 {
   uint16 toff_short ;
   uint32 toff_long ;
   uint64 toff_long8 ;
};
struct __anonstruct_TIFFDirEntry_37 {
   uint16 tdir_tag ;
   uint16 tdir_type ;
   uint64 tdir_count ;
   union __anonunion_tdir_offset_38 tdir_offset ;
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
union __anonunion_tif_header_39 {
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
   union __anonunion_tif_header_39 tif_header ;
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
   toff_t (*tif_seekproc)(thandle_t  , toff_t  , int  ) ;
   int (*tif_closeproc)(thandle_t  ) ;
   toff_t (*tif_sizeproc)(thandle_t  ) ;
   void (*tif_postdecode)(TIFF *tif , uint8 *buf , tmsize_t size ) ;
   TIFFField **tif_fields ;
   size_t tif_nfields ;
   TIFFField const   *tif_foundfield ;
   TIFFTagMethods tif_tagmethods ;
   TIFFClientInfoLink *tif_clientinfo ;
   TIFFFieldArray *tif_fieldscompat ;
   size_t tif_nfieldscompat ;
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
extern int TIFFReadCustomDirectory(TIFF *tif , toff_t diroff ,
                                   TIFFFieldArray const   *infoarray ) ;
extern int TIFFReadEXIFDirectory(TIFF *tif , toff_t diroff ) ;
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
extern int TIFFUnsetField(TIFF * , uint32  ) ;
int TIFFWriteDirectory(TIFF *tif ) ;
int TIFFCheckpointDirectory(TIFF *tif ) ;
int TIFFRewriteDirectory(TIFF *tif ) ;
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
                            toff_t (*)(thandle_t  , toff_t  , int  ) ,
                            int (*)(thandle_t  ) , toff_t (*)(thandle_t  ) ,
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
extern void TIFFSetWriteOffset(TIFF *tif , toff_t off ) ;
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
int _TIFFRewriteField(TIFF *tif , uint16 tag , TIFFDataType in_datatype ,
                      tmsize_t count , void *data ) ;
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
static int TIFFWriteDirectorySec(TIFF *tif , int isimage , int imagedone ,
                                 uint64 *pdiroff ) ;
static int TIFFWriteDirectoryTagSampleformatPerSample(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag , double value ) ;
static int TIFFWriteDirectoryTagAscii(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint32 count , char *value ) ;
static int TIFFWriteDirectoryTagUndefinedArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint8 *value ) ;
static int TIFFWriteDirectoryTagByteArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint8 *value ) ;
static int TIFFWriteDirectoryTagBytePerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint8 value ) ;
static int TIFFWriteDirectoryTagSbyteArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int8 *value ) ;
static int TIFFWriteDirectoryTagSbytePerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int8 value ) ;
static int TIFFWriteDirectoryTagShort(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint16 value ) ;
static int TIFFWriteDirectoryTagShortArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint16 *value ) ;
static int TIFFWriteDirectoryTagShortPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint16 value ) ;
static int TIFFWriteDirectoryTagSshortArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int16 *value ) ;
static int TIFFWriteDirectoryTagSshortPerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                int16 value ) ;
static int TIFFWriteDirectoryTagLong(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint32 value ) ;
static int TIFFWriteDirectoryTagLongArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint32 *value ) ;
static int TIFFWriteDirectoryTagLongPerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 value ) ;
static int TIFFWriteDirectoryTagSlongArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int32 *value ) ;
static int TIFFWriteDirectoryTagSlongPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int32 value ) ;
static int TIFFWriteDirectoryTagLong8Array(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint64 *value ) ;
static int TIFFWriteDirectoryTagSlong8Array(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int64 *value ) ;
static int TIFFWriteDirectoryTagRational(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         double value ) ;
static int TIFFWriteDirectoryTagRationalArray(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 count , float *value ) ;
static int TIFFWriteDirectoryTagSrationalArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , float *value ) ;
static int TIFFWriteDirectoryTagFloatArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , float *value ) ;
static int TIFFWriteDirectoryTagFloatPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               float value ) ;
static int TIFFWriteDirectoryTagDoubleArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , double *value ) ;
static int TIFFWriteDirectoryTagDoublePerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) ;
static int TIFFWriteDirectoryTagIfdArray(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         uint32 count , uint32 *value ) ;
static int TIFFWriteDirectoryTagShortLong(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 value ) ;
static int TIFFWriteDirectoryTagLongLong8Array(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint64 *value ) ;
static int TIFFWriteDirectoryTagIfdIfd8Array(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint32 count , uint64 *value ) ;
static int TIFFWriteDirectoryTagColormap(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir ) ;
static int TIFFWriteDirectoryTagTransferfunction(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ) ;
static int TIFFWriteDirectoryTagSubifd(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir ) ;
static int TIFFWriteDirectoryTagCheckedAscii(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint32 count , char *value ) ;
static int TIFFWriteDirectoryTagCheckedUndefinedArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      uint8 *value ) ;
static int TIFFWriteDirectoryTagCheckedByteArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint8 *value ) ;
static int TIFFWriteDirectoryTagCheckedSbyteArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int8 *value ) ;
static int TIFFWriteDirectoryTagCheckedShort(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint16 value ) ;
static int TIFFWriteDirectoryTagCheckedShortArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint16 *value ) ;
static int TIFFWriteDirectoryTagCheckedSshortArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int16 *value ) ;
static int TIFFWriteDirectoryTagCheckedLong(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 value ) ;
static int TIFFWriteDirectoryTagCheckedLongArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint32 *value ) ;
static int TIFFWriteDirectoryTagCheckedSlongArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int32 *value ) ;
static int TIFFWriteDirectoryTagCheckedLong8Array(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint64 *value ) ;
static int TIFFWriteDirectoryTagCheckedSlong8Array(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int64 *value ) ;
static int TIFFWriteDirectoryTagCheckedRational(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) ;
static int TIFFWriteDirectoryTagCheckedRationalArray(TIFF *tif , uint32 *ndir ,
                                                     TIFFDirEntry *dir ,
                                                     uint16 tag , uint32 count ,
                                                     float *value ) ;
static int TIFFWriteDirectoryTagCheckedSrationalArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      float *value ) ;
static int TIFFWriteDirectoryTagCheckedFloatArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  float *value ) ;
static int TIFFWriteDirectoryTagCheckedDoubleArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   double *value ) ;
static int TIFFWriteDirectoryTagCheckedIfdArray(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                uint32 count , uint32 *value ) ;
static int TIFFWriteDirectoryTagCheckedIfd8Array(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint64 *value ) ;
static int TIFFWriteDirectoryTagData(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint16 datatype , uint32 count ,
                                     uint32 datalength , void *data ) ;
static int TIFFLinkDirectory(TIFF *tif ) ;
int TIFFWriteDirectory(TIFF *tif ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "243", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectorySec(tif, 1, 1, (uint64 *)((void *)0));
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "243", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "244", "tmp", checkpoints_buf);
  return (tmp);
}
}
int TIFFCheckpointDirectory(TIFF *tif ) 
{ 
  int rc ;
  toff_t tmp ;

  {
  if ((unsigned int )tif->tif_dir.td_stripoffset == (unsigned int )((void *)0)) {

    TIFFSetupStrips(tif);

  } else {

  }
  sprintf(checkpoints_buf, "%d", rc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "248", "rc", checkpoints_buf);

  rc = TIFFWriteDirectorySec(tif, 1, 0, (uint64 *)((void *)0));
  sprintf(checkpoints_buf, "%d", rc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "248", "rc", checkpoints_buf);



  tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )0, 2);



  TIFFSetWriteOffset(tif, tmp);

  sprintf(checkpoints_buf, "%d", rc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "251", "rc", checkpoints_buf);
  return (rc);
}
}
int TIFFWriteCustomDirectory(TIFF *tif , uint64 *pdiroff ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "252", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectorySec(tif, 0, 0, pdiroff);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "252", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "253", "tmp", checkpoints_buf);
  return (tmp);
}
}
int TIFFRewriteDirectory(TIFF *tif ) ;
static char const   module[21]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'w',      (char const   )'r', 
        (char const   )'i',      (char const   )'t',      (char const   )'e',      (char const   )'D', 
        (char const   )'i',      (char const   )'r',      (char const   )'e',      (char const   )'c', 
        (char const   )'t',      (char const   )'o',      (char const   )'r',      (char const   )'y', 
        (char const   )'\000'};
int TIFFRewriteDirectory(TIFF *tif ) 
{ 
  int tmp ;
  tmsize_t tmp___0 ;
  uint32 nextdir ;
  uint16 dircount ;
  uint32 nextnextdir ;
  toff_t tmp___1 ;
  tmsize_t tmp___2 ;
  tmsize_t tmp___3 ;
  uint32 m ;
  tmsize_t tmp___4 ;
  tmsize_t tmp___5 ;
  uint64 nextdir___0 ;
  uint64 dircount64 ;
  uint16 dircount___0 ;
  uint64 nextnextdir___0 ;
  toff_t tmp___6 ;
  tmsize_t tmp___7 ;
  tmsize_t tmp___8 ;
  uint64 m___0 ;
  tmsize_t tmp___9 ;
  int tmp___10 ;

  {

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "254", "0", checkpoints_buf);
  if (tif->tif_diroff == 0ULL) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "255", "tmp", checkpoints_buf);

    tmp = TIFFWriteDirectory(tif);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "255", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "256", "tmp", checkpoints_buf);
    return (tmp);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "254", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "258", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {

    if ((uint64 )tif->tif_header.classic.tiff_diroff == tif->tif_diroff) {
      tif->tif_header.classic.tiff_diroff = (uint32 )0;

      tif->tif_diroff = (uint64 )0;


      (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )4, 0);



      tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                        (void *)(& tif->tif_header.classic.tiff_diroff),
                                        (tmsize_t )4);



      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "264", "4", checkpoints_buf);
      if (tmp___0 == 4L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "Error updating TIFF header");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "267", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "264", "4", checkpoints_buf);
    } else {
      nextdir = tif->tif_header.classic.tiff_diroff;





      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "269", "128", checkpoints_buf);




      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "269", "4", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "269", "128", checkpoints_buf);


      while (1) {


        tmp___1 = (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )nextdir,
                                         0);



        if (tmp___1 == (toff_t )nextdir) {


          tmp___2 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                           (void *)(& dircount), (tmsize_t )2);



          sprintf(checkpoints_buf, "%ld", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "273", "2", checkpoints_buf);
          if (tmp___2 == 2L) {

          } else {

            TIFFErrorExt(tif->tif_clientdata, module,
                         "Error fetching directory count");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "276", "0", checkpoints_buf);
            return (0);
          }

          sprintf(checkpoints_buf, "%ld", 2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "273", "2", checkpoints_buf);
        } else {

          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error fetching directory count");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "278", "0", checkpoints_buf);
          return (0);
        }


        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "279", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabShort(& dircount);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "279", "128", checkpoints_buf);

        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (toff_t )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                               0);



        tmp___3 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& nextnextdir), (tmsize_t )4);



        sprintf(checkpoints_buf, "%ld", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "284", "4", checkpoints_buf);
        if (tmp___3 == 4L) {

        } else {

          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error fetching directory link");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "287", "0", checkpoints_buf);
          return (0);
        }

        sprintf(checkpoints_buf, "%ld", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "284", "4", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "288", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong(& nextnextdir);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "288", "128", checkpoints_buf);

        if ((uint64 )nextnextdir == tif->tif_diroff) {
          m = (uint32 )0;


          (*(tif->tif_seekproc))(tif->tif_clientdata,
                                 (toff_t )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                                 0);



          tmp___4 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m),
                                            (tmsize_t )4);



          sprintf(checkpoints_buf, "%ld", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "295", "4", checkpoints_buf);
          if (tmp___4 == 4L) {

          } else {

            TIFFErrorExt(tif->tif_clientdata, module,
                         "Error writing directory link");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "298", "0", checkpoints_buf);
            return (0);
          }

          sprintf(checkpoints_buf, "%ld", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "295", "4", checkpoints_buf);
          tif->tif_diroff = (uint64 )0;

          break;
        } else {

        }

        nextdir = nextnextdir;

      }




      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "269", "128", checkpoints_buf);




      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "269", "4", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "269", "128", checkpoints_buf);


    }

  } else {


    if (tif->tif_header.big.tiff_diroff == tif->tif_diroff) {
      tif->tif_header.big.tiff_diroff = (uint64 )0;

      tif->tif_diroff = (uint64 )0;


      (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )8, 0);



      tmp___5 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                        (void *)(& tif->tif_header.big.tiff_diroff),
                                        (tmsize_t )8);



      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "308", "8", checkpoints_buf);
      if (tmp___5 == 8L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "Error updating TIFF header");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "311", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "308", "8", checkpoints_buf);
    } else {
      nextdir___0 = tif->tif_header.big.tiff_diroff;






      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "65535", checkpoints_buf);





      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "8", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "128", checkpoints_buf);



      while (1) {


        tmp___6 = (*(tif->tif_seekproc))(tif->tif_clientdata, nextdir___0, 0);




        if (tmp___6 == nextdir___0) {


          tmp___7 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                           (void *)(& dircount64), (tmsize_t )8);



          sprintf(checkpoints_buf, "%ld", 8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "317", "8", checkpoints_buf);
          if (tmp___7 == 8L) {

          } else {

            TIFFErrorExt(tif->tif_clientdata, module,
                         "Error fetching directory count");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "320", "0", checkpoints_buf);
            return (0);
          }

          sprintf(checkpoints_buf, "%ld", 8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "317", "8", checkpoints_buf);
        } else {

          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error fetching directory count");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "322", "0", checkpoints_buf);
          return (0);
        }



        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "323", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong8(& dircount64);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "323", "128", checkpoints_buf);

        sprintf(checkpoints_buf, "%llu", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "326", "65535", checkpoints_buf);
        if (dircount64 > 65535ULL) {

          TIFFErrorExt(tif->tif_clientdata, module,
                       "Sanity check on tag count failed, likely corrupt TIFF");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "328", "0", checkpoints_buf);
          return (0);
        } else {

        }

        sprintf(checkpoints_buf, "%llu", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "326", "65535", checkpoints_buf);
        dircount___0 = (uint16 )dircount64;


        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                               0);



        tmp___8 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& nextnextdir___0),
                                         (tmsize_t )8);



        sprintf(checkpoints_buf, "%ld", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "333", "8", checkpoints_buf);
        if (tmp___8 == 8L) {

        } else {

          TIFFErrorExt(tif->tif_clientdata, module,
                       "Error fetching directory link");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "336", "0", checkpoints_buf);
          return (0);
        }

        sprintf(checkpoints_buf, "%ld", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "333", "8", checkpoints_buf);

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "337", "128", checkpoints_buf);
        if (tif->tif_flags & 128U) {

          TIFFSwabLong8(& nextnextdir___0);

        } else {

        }

        sprintf(checkpoints_buf, "%u", 128);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "337", "128", checkpoints_buf);


        if (nextnextdir___0 == tif->tif_diroff) {
          m___0 = (uint64 )0;


          (*(tif->tif_seekproc))(tif->tif_clientdata,
                                 (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                                 0);



          tmp___9 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                            (void *)(& m___0), (tmsize_t )8);



          sprintf(checkpoints_buf, "%ld", 8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "344", "8", checkpoints_buf);
          if (tmp___9 == 8L) {

          } else {

            TIFFErrorExt(tif->tif_clientdata, module,
                         "Error writing directory link");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "347", "0", checkpoints_buf);
            return (0);
          }

          sprintf(checkpoints_buf, "%ld", 8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "344", "8", checkpoints_buf);
          tif->tif_diroff = (uint64 )0;

          break;
        } else {

        }


        nextdir___0 = nextnextdir___0;

      }





      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "65535", checkpoints_buf);





      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "8", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "313", "128", checkpoints_buf);



    }


  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "258", "524288", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "352", "tmp___10", checkpoints_buf);

  tmp___10 = TIFFWriteDirectory(tif);
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "352", "tmp___10", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "353", "tmp___10", checkpoints_buf);
  return (tmp___10);
}
}
static int TIFFWriteDirectorySec(TIFF *tif , int isimage , int imagedone ,
                                 uint64 *pdiroff ) ;
static char const   module___0[22]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'S',      (char const   )'e', 
        (char const   )'c',      (char const   )'\000'};
static int TIFFWriteDirectorySec(TIFF *tif , int isimage , int imagedone ,
                                 uint64 *pdiroff ) 
{ 
  uint32 ndir ;
  TIFFDirEntry *dir ;
  uint32 dirsize ;
  void *dirmem ;
  uint32 m ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
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
  int tmp___13 ;
  int tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  uint16 na ;
  uint16 *nb ;
  int tmp___28 ;
  int tmp___29 ;
  int tmp___30 ;
  int tmp___31 ;
  int tmp___32 ;
  int tmp___33 ;
  int tmp___34 ;
  int tmp___35 ;
  int tmp___36 ;
  int tmp___37 ;
  int tmp___38 ;
  int tmp___39 ;
  uint32 n ;
  TIFFField const   *o ;
  uint32 pa ;
  char *pb ;
  size_t tmp___40 ;
  int tmp___41 ;
  uint16 p ;
  int tmp___42 ;
  uint32 p___0 ;
  int tmp___43 ;
  uint32 pa___0 ;
  void *pb___0 ;
  int tmp___44 ;
  int tmp___45 ;
  int tmp___46 ;
  int tmp___47 ;
  int tmp___48 ;
  int tmp___49 ;
  int tmp___50 ;
  int tmp___51 ;
  int tmp___52 ;
  int tmp___53 ;
  int tmp___54 ;
  int tmp___55 ;
  int tmp___56 ;
  int tmp___57 ;
  int tmp___58 ;
  int tmp___59 ;
  int tmp___60 ;
  void *tmp___61 ;
  int tmp___62 ;
  toff_t tmp___63 ;
  uint32 na___0 ;
  TIFFDirEntry *nb___0 ;
  uint8 *n___0 ;
  uint32 nTmp ;
  TIFFDirEntry *o___0 ;
  uint8 *n___1 ;
  TIFFDirEntry *o___1 ;
  toff_t tmp___64 ;
  tmsize_t tmp___65 ;

  {

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "354", "0", checkpoints_buf);
  if (tif->tif_mode == 0) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "355", "1", checkpoints_buf);
    return (1);
  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "354", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", imagedone);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "357", "imagedone", checkpoints_buf);
  if (imagedone) {

    sprintf(checkpoints_buf, "%u", 4096);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "358", "4096", checkpoints_buf);
    if (tif->tif_flags & 4096U) {
      tif->tif_flags &= 4294963199U;

      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "360", "tmp", checkpoints_buf);

      tmp = (*(tif->tif_postencode))(tif);
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "360", "tmp", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "361", "tmp", checkpoints_buf);
      if (tmp) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Error post-encoding before directory write");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "364", "0", checkpoints_buf);
        return (0);
      }
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "361", "tmp", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%u", 4096);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "358", "4096", checkpoints_buf);

    (*(tif->tif_close))(tif);


    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "367", "0", checkpoints_buf);
    if (tif->tif_rawcc > 0L) {

      sprintf(checkpoints_buf, "%u", 64);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "368", "64", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "368", "0", checkpoints_buf);
      if ((tif->tif_flags & 64U) != 0U) {
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "369", "tmp___0", checkpoints_buf);

        tmp___0 = TIFFFlushData1(tif);
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "369", "tmp___0", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "370", "tmp___0", checkpoints_buf);
        if (tmp___0) {

        } else {

          TIFFErrorExt(tif->tif_clientdata, module___0,
                       "Error flushing data before directory write");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "373", "0", checkpoints_buf);
          return (0);
        }
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "370", "tmp___0", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%u", 64);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "368", "64", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "368", "0", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "367", "0", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "376", "512", checkpoints_buf);
    if (tif->tif_flags & 512U) {

      if (tif->tif_rawdata) {

        _TIFFfree((void *)tif->tif_rawdata);

        tif->tif_rawdata = (uint8 *)((void *)0);

        tif->tif_rawcc = (tmsize_t )0;

        tif->tif_rawdatasize = (tmsize_t )0;

      } else {

      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "376", "512", checkpoints_buf);
    tif->tif_flags &= 4294967215U;

  } else {

  }
  sprintf(checkpoints_buf, "%d", imagedone);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "357", "imagedone", checkpoints_buf);
  dir = (TIFFDirEntry *)((void *)0);

  dirmem = (void *)0;

  dirsize = (uint32 )0;


  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "isimage", checkpoints_buf);






  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "isimage", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "524288", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "524288", checkpoints_buf);



  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "isimage", checkpoints_buf);
  while (1) {
    ndir = (uint32 )0;

    sprintf(checkpoints_buf, "%d", isimage);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "391", "isimage", checkpoints_buf);
    if (isimage) {

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "392", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "392", "1", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 1)) {
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "393", "tmp___1", checkpoints_buf);

        tmp___1 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )256,
                                                 tif->tif_dir.td_imagewidth);
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "393", "tmp___1", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "394", "tmp___1", checkpoints_buf);
        if (tmp___1) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "394", "tmp___1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "397", "tmp___2", checkpoints_buf);

        tmp___2 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )257,
                                                 tif->tif_dir.td_imagelength);
        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "397", "tmp___2", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "398", "tmp___2", checkpoints_buf);
        if (tmp___2) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "398", "tmp___2", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "392", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "392", "1", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "402", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "402", "2", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 2)) {
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "403", "tmp___3", checkpoints_buf);

        tmp___3 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )322,
                                                 tif->tif_dir.td_tilewidth);
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "403", "tmp___3", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "404", "tmp___3", checkpoints_buf);
        if (tmp___3) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "404", "tmp___3", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "407", "tmp___4", checkpoints_buf);

        tmp___4 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir, (uint16 )323,
                                                 tif->tif_dir.td_tilelength);
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "407", "tmp___4", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "408", "tmp___4", checkpoints_buf);
        if (tmp___4) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "408", "tmp___4", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "402", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "402", "2", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "412", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "412", "3", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 3)) {
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "413", "tmp___5", checkpoints_buf);

        tmp___5 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )282,
                                                (double )tif->tif_dir.td_xresolution);
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "413", "tmp___5", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "414", "tmp___5", checkpoints_buf);
        if (tmp___5) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "414", "tmp___5", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "417", "tmp___6", checkpoints_buf);

        tmp___6 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )283,
                                                (double )tif->tif_dir.td_yresolution);
        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "417", "tmp___6", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "418", "tmp___6", checkpoints_buf);
        if (tmp___6) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "418", "tmp___6", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "412", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "412", "3", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "422", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "422", "4", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 4)) {
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "423", "tmp___7", checkpoints_buf);

        tmp___7 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )286,
                                                (double )tif->tif_dir.td_xposition);
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "423", "tmp___7", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "424", "tmp___7", checkpoints_buf);
        if (tmp___7) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "424", "tmp___7", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "427", "tmp___8", checkpoints_buf);

        tmp___8 = TIFFWriteDirectoryTagRational(tif, & ndir, dir, (uint16 )287,
                                                (double )tif->tif_dir.td_yposition);
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "427", "tmp___8", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "428", "tmp___8", checkpoints_buf);
        if (tmp___8) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "428", "tmp___8", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "422", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "422", "4", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "432", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "432", "5", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 5)) {
        sprintf(checkpoints_buf, "%d", tmp___9);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "433", "tmp___9", checkpoints_buf);

        tmp___9 = TIFFWriteDirectoryTagLong(tif, & ndir, dir, (uint16 )254,
                                            tif->tif_dir.td_subfiletype);
        sprintf(checkpoints_buf, "%d", tmp___9);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "433", "tmp___9", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___9);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "434", "tmp___9", checkpoints_buf);
        if (tmp___9) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___9);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "434", "tmp___9", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "432", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "432", "5", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "438", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "438", "6", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 6)) {
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "439", "tmp___10", checkpoints_buf);

        tmp___10 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )258,
                                                       tif->tif_dir.td_bitspersample);
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "439", "tmp___10", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "440", "tmp___10", checkpoints_buf);
        if (tmp___10) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "440", "tmp___10", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "438", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "438", "6", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "444", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "444", "7", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 7)) {
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "445", "tmp___11", checkpoints_buf);

        tmp___11 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )259,
                                              tif->tif_dir.td_compression);
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "445", "tmp___11", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "446", "tmp___11", checkpoints_buf);
        if (tmp___11) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "446", "tmp___11", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "444", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "444", "7", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "450", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "450", "8", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 8)) {
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "451", "tmp___12", checkpoints_buf);

        tmp___12 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )262,
                                              tif->tif_dir.td_photometric);
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "451", "tmp___12", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "452", "tmp___12", checkpoints_buf);
        if (tmp___12) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___12);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "452", "tmp___12", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "450", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "450", "8", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "456", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "456", "9", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 9)) {
        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "457", "tmp___13", checkpoints_buf);

        tmp___13 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )263,
                                              tif->tif_dir.td_threshholding);
        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "457", "tmp___13", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "458", "tmp___13", checkpoints_buf);
        if (tmp___13) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "458", "tmp___13", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "456", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "456", "9", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "462", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "462", "10", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 10)) {
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "463", "tmp___14", checkpoints_buf);

        tmp___14 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )266,
                                              tif->tif_dir.td_fillorder);
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "463", "tmp___14", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "464", "tmp___14", checkpoints_buf);
        if (tmp___14) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "464", "tmp___14", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "462", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "462", "10", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "468", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 15);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "468", "15", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 15)) {
        sprintf(checkpoints_buf, "%d", tmp___15);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "469", "tmp___15", checkpoints_buf);

        tmp___15 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )274,
                                              tif->tif_dir.td_orientation);
        sprintf(checkpoints_buf, "%d", tmp___15);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "469", "tmp___15", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___15);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "470", "tmp___15", checkpoints_buf);
        if (tmp___15) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___15);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "470", "tmp___15", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "468", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 15);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "468", "15", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "474", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "474", "16", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 16)) {
        sprintf(checkpoints_buf, "%d", tmp___16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "475", "tmp___16", checkpoints_buf);

        tmp___16 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )277,
                                              tif->tif_dir.td_samplesperpixel);
        sprintf(checkpoints_buf, "%d", tmp___16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "475", "tmp___16", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "476", "tmp___16", checkpoints_buf);
        if (tmp___16) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "476", "tmp___16", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "474", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "474", "16", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "480", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "480", "17", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 17)) {
        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "481", "tmp___17", checkpoints_buf);

        tmp___17 = TIFFWriteDirectoryTagShortLong(tif, & ndir, dir,
                                                  (uint16 )278,
                                                  tif->tif_dir.td_rowsperstrip);
        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "481", "tmp___17", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "482", "tmp___17", checkpoints_buf);
        if (tmp___17) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "482", "tmp___17", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "480", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "480", "17", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "486", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 18);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "486", "18", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 18)) {
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "487", "tmp___18", checkpoints_buf);

        tmp___18 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )280,
                                                       tif->tif_dir.td_minsamplevalue);
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "487", "tmp___18", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "488", "tmp___18", checkpoints_buf);
        if (tmp___18) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___18);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "488", "tmp___18", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "486", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 18);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "486", "18", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "492", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 19);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "492", "19", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 19)) {
        sprintf(checkpoints_buf, "%d", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "493", "tmp___19", checkpoints_buf);

        tmp___19 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )281,
                                                       tif->tif_dir.td_maxsamplevalue);
        sprintf(checkpoints_buf, "%d", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "493", "tmp___19", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "494", "tmp___19", checkpoints_buf);
        if (tmp___19) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___19);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "494", "tmp___19", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "492", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 19);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "492", "19", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "498", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 20);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "498", "20", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 20)) {
        sprintf(checkpoints_buf, "%d", tmp___20);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "499", "tmp___20", checkpoints_buf);

        tmp___20 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )284,
                                              tif->tif_dir.td_planarconfig);
        sprintf(checkpoints_buf, "%d", tmp___20);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "499", "tmp___20", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___20);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "500", "tmp___20", checkpoints_buf);
        if (tmp___20) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___20);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "500", "tmp___20", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "498", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 20);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "498", "20", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "504", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 22);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "504", "22", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 22)) {
        sprintf(checkpoints_buf, "%d", tmp___21);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "505", "tmp___21", checkpoints_buf);

        tmp___21 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )296,
                                              tif->tif_dir.td_resolutionunit);
        sprintf(checkpoints_buf, "%d", tmp___21);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "505", "tmp___21", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___21);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "506", "tmp___21", checkpoints_buf);
        if (tmp___21) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___21);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "506", "tmp___21", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "504", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 22);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "504", "22", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "510", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 23);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "510", "23", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 23)) {
        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "511", "tmp___22", checkpoints_buf);

        tmp___22 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                   (uint16 )297, (uint32 )2,
                                                   & tif->tif_dir.td_pagenumber[0]);
        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "511", "tmp___22", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "512", "tmp___22", checkpoints_buf);
        if (tmp___22) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "512", "tmp___22", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "510", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 23);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "510", "23", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "516", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "516", "24", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 24)) {

        sprintf(checkpoints_buf, "%u", 1024);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "517", "1024", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "517", "0", checkpoints_buf);
        if (! ((tif->tif_flags & 1024U) != 0U)) {
          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "518", "tmp___23", checkpoints_buf);

          tmp___23 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )279,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripbytecount);
          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "518", "tmp___23", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "519", "tmp___23", checkpoints_buf);
          if (tmp___23) {

          } else {
            goto bad;
          }
          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "519", "tmp___23", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "522", "tmp___24", checkpoints_buf);

          tmp___24 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )325,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripbytecount);
          sprintf(checkpoints_buf, "%d", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "522", "tmp___24", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "523", "tmp___24", checkpoints_buf);
          if (tmp___24) {

          } else {
            goto bad;
          }
          sprintf(checkpoints_buf, "%d", tmp___24);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "523", "tmp___24", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 1024);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "517", "1024", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "517", "0", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "516", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "516", "24", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "527", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 25);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "527", "25", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 25)) {

        sprintf(checkpoints_buf, "%u", 1024);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "528", "1024", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "528", "0", checkpoints_buf);
        if (! ((tif->tif_flags & 1024U) != 0U)) {
          sprintf(checkpoints_buf, "%d", tmp___25);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "529", "tmp___25", checkpoints_buf);

          tmp___25 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )273,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripoffset);
          sprintf(checkpoints_buf, "%d", tmp___25);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "529", "tmp___25", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___25);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "530", "tmp___25", checkpoints_buf);
          if (tmp___25) {

          } else {
            goto bad;
          }
          sprintf(checkpoints_buf, "%d", tmp___25);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "530", "tmp___25", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___26);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "533", "tmp___26", checkpoints_buf);

          tmp___26 = TIFFWriteDirectoryTagLongLong8Array(tif, & ndir, dir,
                                                         (uint16 )324,
                                                         tif->tif_dir.td_nstrips,
                                                         tif->tif_dir.td_stripoffset);
          sprintf(checkpoints_buf, "%d", tmp___26);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "533", "tmp___26", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___26);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "534", "tmp___26", checkpoints_buf);
          if (tmp___26) {

          } else {
            goto bad;
          }
          sprintf(checkpoints_buf, "%d", tmp___26);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "534", "tmp___26", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 1024);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "528", "1024", checkpoints_buf);
        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "528", "0", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "527", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 25);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "527", "25", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "538", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 26);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "538", "26", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 26)) {
        sprintf(checkpoints_buf, "%d", tmp___27);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "539", "tmp___27", checkpoints_buf);

        tmp___27 = TIFFWriteDirectoryTagColormap(tif, & ndir, dir);
        sprintf(checkpoints_buf, "%d", tmp___27);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "539", "tmp___27", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___27);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "540", "tmp___27", checkpoints_buf);
        if (tmp___27) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___27);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "540", "tmp___27", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "538", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 26);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "538", "26", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "544", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 31);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "544", "31", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[0] & (1UL << 31)) {

        if (tif->tif_dir.td_extrasamples) {

          TIFFGetFieldDefaulted(tif, (uint32 )338, & na, & nb);

          sprintf(checkpoints_buf, "%d", tmp___28);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "547", "tmp___28", checkpoints_buf);

          tmp___28 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                     (uint16 )338, (uint32 )na,
                                                     nb);
          sprintf(checkpoints_buf, "%d", tmp___28);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "547", "tmp___28", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___28);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "548", "tmp___28", checkpoints_buf);
          if (tmp___28) {

          } else {
            goto bad;
          }
          sprintf(checkpoints_buf, "%d", tmp___28);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "548", "tmp___28", checkpoints_buf);
        } else {

        }

      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "544", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 31);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "544", "31", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "553", "1", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & 1UL) {
        sprintf(checkpoints_buf, "%d", tmp___29);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "554", "tmp___29", checkpoints_buf);

        tmp___29 = TIFFWriteDirectoryTagShortPerSample(tif, & ndir, dir,
                                                       (uint16 )339,
                                                       tif->tif_dir.td_sampleformat);
        sprintf(checkpoints_buf, "%d", tmp___29);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "554", "tmp___29", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___29);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "555", "tmp___29", checkpoints_buf);
        if (tmp___29) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___29);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "555", "tmp___29", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "553", "1", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "559", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "559", "1", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 1)) {
        sprintf(checkpoints_buf, "%d", tmp___30);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "560", "tmp___30", checkpoints_buf);

        tmp___30 = TIFFWriteDirectoryTagSampleformatPerSample(tif, & ndir, dir,
                                                              (uint16 )340,
                                                              tif->tif_dir.td_sminsamplevalue);
        sprintf(checkpoints_buf, "%d", tmp___30);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "560", "tmp___30", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___30);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "561", "tmp___30", checkpoints_buf);
        if (tmp___30) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___30);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "561", "tmp___30", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "559", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "559", "1", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "565", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "565", "2", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 2)) {
        sprintf(checkpoints_buf, "%d", tmp___31);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "566", "tmp___31", checkpoints_buf);

        tmp___31 = TIFFWriteDirectoryTagSampleformatPerSample(tif, & ndir, dir,
                                                              (uint16 )341,
                                                              tif->tif_dir.td_smaxsamplevalue);
        sprintf(checkpoints_buf, "%d", tmp___31);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "566", "tmp___31", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___31);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "567", "tmp___31", checkpoints_buf);
        if (tmp___31) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___31);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "567", "tmp___31", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "565", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "565", "2", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "571", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "571", "3", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 3)) {
        sprintf(checkpoints_buf, "%d", tmp___32);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "572", "tmp___32", checkpoints_buf);

        tmp___32 = TIFFWriteDirectoryTagLong(tif, & ndir, dir, (uint16 )32997,
                                             tif->tif_dir.td_imagedepth);
        sprintf(checkpoints_buf, "%d", tmp___32);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "572", "tmp___32", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___32);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "573", "tmp___32", checkpoints_buf);
        if (tmp___32) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___32);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "573", "tmp___32", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "571", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "571", "3", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "577", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "577", "4", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 4)) {
        sprintf(checkpoints_buf, "%d", tmp___33);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "578", "tmp___33", checkpoints_buf);

        tmp___33 = TIFFWriteDirectoryTagLong(tif, & ndir, dir, (uint16 )32998,
                                             tif->tif_dir.td_tiledepth);
        sprintf(checkpoints_buf, "%d", tmp___33);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "578", "tmp___33", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___33);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "579", "tmp___33", checkpoints_buf);
        if (tmp___33) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___33);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "579", "tmp___33", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "577", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "577", "4", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "583", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "583", "5", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 5)) {
        sprintf(checkpoints_buf, "%d", tmp___34);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "584", "tmp___34", checkpoints_buf);

        tmp___34 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                   (uint16 )321, (uint32 )2,
                                                   & tif->tif_dir.td_halftonehints[0]);
        sprintf(checkpoints_buf, "%d", tmp___34);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "584", "tmp___34", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___34);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "585", "tmp___34", checkpoints_buf);
        if (tmp___34) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___34);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "585", "tmp___34", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "583", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "583", "5", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "589", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "589", "7", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 7)) {
        sprintf(checkpoints_buf, "%d", tmp___35);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "590", "tmp___35", checkpoints_buf);

        tmp___35 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                   (uint16 )530, (uint32 )2,
                                                   & tif->tif_dir.td_ycbcrsubsampling[0]);
        sprintf(checkpoints_buf, "%d", tmp___35);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "590", "tmp___35", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___35);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "591", "tmp___35", checkpoints_buf);
        if (tmp___35) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___35);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "591", "tmp___35", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "589", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "589", "7", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "595", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "595", "8", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 8)) {
        sprintf(checkpoints_buf, "%d", tmp___36);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "596", "tmp___36", checkpoints_buf);

        tmp___36 = TIFFWriteDirectoryTagShort(tif, & ndir, dir, (uint16 )531,
                                              tif->tif_dir.td_ycbcrpositioning);
        sprintf(checkpoints_buf, "%d", tmp___36);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "596", "tmp___36", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___36);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "597", "tmp___36", checkpoints_buf);
        if (tmp___36) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___36);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "597", "tmp___36", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "595", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "595", "8", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "601", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "601", "12", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 12)) {
        sprintf(checkpoints_buf, "%d", tmp___37);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "602", "tmp___37", checkpoints_buf);

        tmp___37 = TIFFWriteDirectoryTagTransferfunction(tif, & ndir, dir);
        sprintf(checkpoints_buf, "%d", tmp___37);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "602", "tmp___37", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___37);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "603", "tmp___37", checkpoints_buf);
        if (tmp___37) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___37);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "603", "tmp___37", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "601", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "601", "12", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "607", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 14);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "607", "14", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 14)) {
        sprintf(checkpoints_buf, "%d", tmp___38);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "608", "tmp___38", checkpoints_buf);

        tmp___38 = TIFFWriteDirectoryTagAscii(tif, & ndir, dir, (uint16 )333,
                                              (uint32 )tif->tif_dir.td_inknameslen,
                                              tif->tif_dir.td_inknames);
        sprintf(checkpoints_buf, "%d", tmp___38);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "608", "tmp___38", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___38);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "609", "tmp___38", checkpoints_buf);
        if (tmp___38) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___38);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "609", "tmp___38", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "607", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 14);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "607", "14", checkpoints_buf);

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "613", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "613", "17", checkpoints_buf);
      if (tif->tif_dir.td_fieldsset[1] & (1UL << 17)) {
        sprintf(checkpoints_buf, "%d", tmp___39);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "614", "tmp___39", checkpoints_buf);

        tmp___39 = TIFFWriteDirectoryTagSubifd(tif, & ndir, dir);
        sprintf(checkpoints_buf, "%d", tmp___39);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "614", "tmp___39", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___39);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "615", "tmp___39", checkpoints_buf);
        if (tmp___39) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___39);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "615", "tmp___39", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ul", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "613", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "613", "17", checkpoints_buf);
      n = (uint32 )0;




      sprintf(checkpoints_buf, "%d", 66);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "620", "66", checkpoints_buf);

      while (n < tif->tif_nfields) {


        o = (TIFFField const   *)*(tif->tif_fields + n);

        sprintf(checkpoints_buf, "%d", 66);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "625", "66", checkpoints_buf);
        if ((int const   )o->field_bit >= 66) {

          sprintf(checkpoints_buf, "%ul", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "626", "1", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 31);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "626", "31", checkpoints_buf);
          if (tif->tif_dir.td_fieldsset[(int const   )o->field_bit / 32] & (1UL << ((int const   )o->field_bit & 31))) {
            switch ((unsigned int const   )o->get_field_type) {
            sprintf(checkpoints_buf, "%u", 2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "628", "2", checkpoints_buf);
            case 1U: 
            if ((unsigned int const   )o->field_type == 2U) {

            } else {

              __assert_fail("o->field_type==TIFF_ASCII", "tif_dirwrite.c", 616U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%u", 2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "628", "2", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", -1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "631", "-1", checkpoints_buf);
            if ((int const   )o->field_readcount == -1) {

            } else {

              __assert_fail("o->field_readcount==-1", "tif_dirwrite.c", 617U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", -1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "631", "-1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "634", "0", checkpoints_buf);
            if ((int const   )o->field_passcount == 0) {

            } else {

              __assert_fail("o->field_passcount==0", "tif_dirwrite.c", 618U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "634", "0", checkpoints_buf);

            TIFFGetField(tif, (uint32 )o->field_tag, & pb);



            tmp___40 = strlen((char const   *)pb);


            pa = tmp___40;

            sprintf(checkpoints_buf, "%d", tmp___41);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "640", "tmp___41", checkpoints_buf);

            tmp___41 = TIFFWriteDirectoryTagAscii(tif, & ndir, dir,
                                                  (uint16 )o->field_tag, pa, pb);
            sprintf(checkpoints_buf, "%d", tmp___41);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "640", "tmp___41", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___41);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "641", "tmp___41", checkpoints_buf);
            if (tmp___41) {

            } else {
              goto bad;
            }
            sprintf(checkpoints_buf, "%d", tmp___41);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "641", "tmp___41", checkpoints_buf);
            break;
            sprintf(checkpoints_buf, "%u", 3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "645", "3", checkpoints_buf);
            case 4U: 
            if ((unsigned int const   )o->field_type == 3U) {

            } else {

              __assert_fail("o->field_type==TIFF_SHORT", "tif_dirwrite.c", 628U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%u", 3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "645", "3", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "648", "1", checkpoints_buf);
            if ((int const   )o->field_readcount == 1) {

            } else {

              __assert_fail("o->field_readcount==1", "tif_dirwrite.c", 629U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "648", "1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "651", "0", checkpoints_buf);
            if ((int const   )o->field_passcount == 0) {

            } else {

              __assert_fail("o->field_passcount==0", "tif_dirwrite.c", 630U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "651", "0", checkpoints_buf);

            TIFFGetField(tif, (uint32 )o->field_tag, & p);

            sprintf(checkpoints_buf, "%d", tmp___42);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "655", "tmp___42", checkpoints_buf);

            tmp___42 = TIFFWriteDirectoryTagShort(tif, & ndir, dir,
                                                  (uint16 )o->field_tag, p);
            sprintf(checkpoints_buf, "%d", tmp___42);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "655", "tmp___42", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___42);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "656", "tmp___42", checkpoints_buf);
            if (tmp___42) {

            } else {
              goto bad;
            }
            sprintf(checkpoints_buf, "%d", tmp___42);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "656", "tmp___42", checkpoints_buf);
            break;
            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "660", "4", checkpoints_buf);
            case 6U: 
            if ((unsigned int const   )o->field_type == 4U) {

            } else {

              __assert_fail("o->field_type==TIFF_LONG", "tif_dirwrite.c", 639U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "660", "4", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "663", "1", checkpoints_buf);
            if ((int const   )o->field_readcount == 1) {

            } else {

              __assert_fail("o->field_readcount==1", "tif_dirwrite.c", 640U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "663", "1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "666", "0", checkpoints_buf);
            if ((int const   )o->field_passcount == 0) {

            } else {

              __assert_fail("o->field_passcount==0", "tif_dirwrite.c", 641U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "666", "0", checkpoints_buf);

            TIFFGetField(tif, (uint32 )o->field_tag, & p___0);

            sprintf(checkpoints_buf, "%d", tmp___43);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "670", "tmp___43", checkpoints_buf);

            tmp___43 = TIFFWriteDirectoryTagLong(tif, & ndir, dir,
                                                 (uint16 )o->field_tag, p___0);
            sprintf(checkpoints_buf, "%d", tmp___43);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "670", "tmp___43", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___43);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "671", "tmp___43", checkpoints_buf);
            if (tmp___43) {

            } else {
              goto bad;
            }
            sprintf(checkpoints_buf, "%d", tmp___43);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "671", "tmp___43", checkpoints_buf);
            break;
            sprintf(checkpoints_buf, "%u", 7);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "675", "7", checkpoints_buf);
            case 40U: 
            if ((unsigned int const   )o->field_type == 7U) {

            } else {

              __assert_fail("o->field_type==TIFF_UNDEFINED", "tif_dirwrite.c",
                            651U, "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%u", 7);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "675", "7", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", -3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "678", "-3", checkpoints_buf);
            if ((int const   )o->field_readcount == -3) {

            } else {

              __assert_fail("o->field_readcount==-3", "tif_dirwrite.c", 652U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", -3);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "678", "-3", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "681", "1", checkpoints_buf);
            if ((int const   )o->field_passcount == 1) {

            } else {

              __assert_fail("o->field_passcount==1", "tif_dirwrite.c", 653U,
                            "TIFFWriteDirectorySec");

            }
            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "681", "1", checkpoints_buf);

            TIFFGetField(tif, (uint32 )o->field_tag, & pa___0, & pb___0);

            sprintf(checkpoints_buf, "%d", tmp___44);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "685", "tmp___44", checkpoints_buf);

            tmp___44 = TIFFWriteDirectoryTagUndefinedArray(tif, & ndir, dir,
                                                           (uint16 )o->field_tag,
                                                           pa___0,
                                                           (uint8 *)pb___0);
            sprintf(checkpoints_buf, "%d", tmp___44);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "685", "tmp___44", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___44);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "686", "tmp___44", checkpoints_buf);
            if (tmp___44) {

            } else {
              goto bad;
            }
            sprintf(checkpoints_buf, "%d", tmp___44);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "686", "tmp___44", checkpoints_buf);
            break;

            default: 
            __assert_fail("0", "tif_dirwrite.c", 660U, "TIFFWriteDirectorySec");

            break;
            }
          } else {

          }

          sprintf(checkpoints_buf, "%ul", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "626", "1", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 31);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "626", "31", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", 66);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "625", "66", checkpoints_buf);
        n ++;

      }



      sprintf(checkpoints_buf, "%d", 66);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "620", "66", checkpoints_buf);

    } else {

    }
    sprintf(checkpoints_buf, "%d", isimage);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "391", "isimage", checkpoints_buf);
    m = (uint32 )0;



    while (m < (uint32 )tif->tif_dir.td_customValueCount) {

      switch ((unsigned int const   )((tif->tif_dir.td_customValues + m)->info)->field_type) {
      sprintf(checkpoints_buf, "%d", tmp___45);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "702", "tmp___45", checkpoints_buf);

      case 2U: 
      tmp___45 = TIFFWriteDirectoryTagAscii(tif, & ndir, dir,
                                            (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                            (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                            (char *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___45);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "702", "tmp___45", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___45);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "703", "tmp___45", checkpoints_buf);
      if (tmp___45) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___45);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "703", "tmp___45", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___46);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "707", "tmp___46", checkpoints_buf);

      case 7U: 
      tmp___46 = TIFFWriteDirectoryTagUndefinedArray(tif, & ndir, dir,
                                                     (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                     (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                     (uint8 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___46);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "707", "tmp___46", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___46);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "708", "tmp___46", checkpoints_buf);
      if (tmp___46) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___46);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "708", "tmp___46", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___47);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "712", "tmp___47", checkpoints_buf);

      case 1U: 
      tmp___47 = TIFFWriteDirectoryTagByteArray(tif, & ndir, dir,
                                                (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                (uint8 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___47);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "712", "tmp___47", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___47);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "713", "tmp___47", checkpoints_buf);
      if (tmp___47) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___47);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "713", "tmp___47", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___48);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "717", "tmp___48", checkpoints_buf);

      case 6U: 
      tmp___48 = TIFFWriteDirectoryTagSbyteArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (int8 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___48);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "717", "tmp___48", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___48);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "718", "tmp___48", checkpoints_buf);
      if (tmp___48) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___48);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "718", "tmp___48", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___49);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "722", "tmp___49", checkpoints_buf);

      case 3U: 
      tmp___49 = TIFFWriteDirectoryTagShortArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (uint16 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___49);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "722", "tmp___49", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___49);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "723", "tmp___49", checkpoints_buf);
      if (tmp___49) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___49);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "723", "tmp___49", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___50);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "727", "tmp___50", checkpoints_buf);

      case 8U: 
      tmp___50 = TIFFWriteDirectoryTagSshortArray(tif, & ndir, dir,
                                                  (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                  (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                  (int16 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___50);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "727", "tmp___50", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___50);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "728", "tmp___50", checkpoints_buf);
      if (tmp___50) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___50);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "728", "tmp___50", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___51);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "732", "tmp___51", checkpoints_buf);

      case 4U: 
      tmp___51 = TIFFWriteDirectoryTagLongArray(tif, & ndir, dir,
                                                (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                (uint32 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___51);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "732", "tmp___51", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___51);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "733", "tmp___51", checkpoints_buf);
      if (tmp___51) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___51);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "733", "tmp___51", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___52);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "737", "tmp___52", checkpoints_buf);

      case 9U: 
      tmp___52 = TIFFWriteDirectoryTagSlongArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (int32 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___52);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "737", "tmp___52", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___52);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "738", "tmp___52", checkpoints_buf);
      if (tmp___52) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___52);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "738", "tmp___52", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___53);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "742", "tmp___53", checkpoints_buf);

      case 16U: 
      tmp___53 = TIFFWriteDirectoryTagLong8Array(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (uint64 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___53);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "742", "tmp___53", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___53);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "743", "tmp___53", checkpoints_buf);
      if (tmp___53) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___53);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "743", "tmp___53", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___54);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "747", "tmp___54", checkpoints_buf);

      case 17U: 
      tmp___54 = TIFFWriteDirectoryTagSlong8Array(tif, & ndir, dir,
                                                  (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                  (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                  (int64 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___54);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "747", "tmp___54", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___54);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "748", "tmp___54", checkpoints_buf);
      if (tmp___54) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___54);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "748", "tmp___54", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___55);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "752", "tmp___55", checkpoints_buf);

      case 5U: 
      tmp___55 = TIFFWriteDirectoryTagRationalArray(tif, & ndir, dir,
                                                    (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                    (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                    (float *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___55);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "752", "tmp___55", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___55);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "753", "tmp___55", checkpoints_buf);
      if (tmp___55) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___55);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "753", "tmp___55", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___56);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "757", "tmp___56", checkpoints_buf);

      case 10U: 
      tmp___56 = TIFFWriteDirectoryTagSrationalArray(tif, & ndir, dir,
                                                     (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                     (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                     (float *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___56);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "757", "tmp___56", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___56);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "758", "tmp___56", checkpoints_buf);
      if (tmp___56) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___56);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "758", "tmp___56", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___57);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "762", "tmp___57", checkpoints_buf);

      case 11U: 
      tmp___57 = TIFFWriteDirectoryTagFloatArray(tif, & ndir, dir,
                                                 (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                 (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                 (float *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___57);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "762", "tmp___57", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___57);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "763", "tmp___57", checkpoints_buf);
      if (tmp___57) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___57);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "763", "tmp___57", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___58);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "767", "tmp___58", checkpoints_buf);

      case 12U: 
      tmp___58 = TIFFWriteDirectoryTagDoubleArray(tif, & ndir, dir,
                                                  (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                  (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                  (double *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___58);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "767", "tmp___58", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___58);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "768", "tmp___58", checkpoints_buf);
      if (tmp___58) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___58);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "768", "tmp___58", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "772", "tmp___59", checkpoints_buf);

      case 13U: 
      tmp___59 = TIFFWriteDirectoryTagIfdArray(tif, & ndir, dir,
                                               (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                               (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                               (uint32 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "772", "tmp___59", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "773", "tmp___59", checkpoints_buf);
      if (tmp___59) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___59);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "773", "tmp___59", checkpoints_buf);
      break;
      sprintf(checkpoints_buf, "%d", tmp___60);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "777", "tmp___60", checkpoints_buf);

      case 18U: 
      tmp___60 = TIFFWriteDirectoryTagIfdIfd8Array(tif, & ndir, dir,
                                                   (uint16 )((tif->tif_dir.td_customValues + m)->info)->field_tag,
                                                   (uint32 )(tif->tif_dir.td_customValues + m)->count,
                                                   (uint64 *)(tif->tif_dir.td_customValues + m)->value);
      sprintf(checkpoints_buf, "%d", tmp___60);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "777", "tmp___60", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___60);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "778", "tmp___60", checkpoints_buf);
      if (tmp___60) {

      } else {
        goto bad;
      }
      sprintf(checkpoints_buf, "%d", tmp___60);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "778", "tmp___60", checkpoints_buf);
      break;

      default: 
      __assert_fail("0", "tif_dirwrite.c", 736U, "TIFFWriteDirectorySec");

      break;
      }
      m ++;

    }


    if ((unsigned int )dir != (unsigned int )((void *)0)) {
      break;
    } else {

    }


    tmp___61 = _TIFFmalloc((tmsize_t )(ndir * sizeof(TIFFDirEntry )));


    dir = (TIFFDirEntry *)tmp___61;

    if ((unsigned int )dir == (unsigned int )((void *)0)) {

      TIFFErrorExt(tif->tif_clientdata, module___0, "Out of memory");

      goto bad;
    } else {

    }
    sprintf(checkpoints_buf, "%d", isimage);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "794", "isimage", checkpoints_buf);
    if (isimage) {

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "795", "0", checkpoints_buf);
      if (tif->tif_diroff == 0ULL) {
        sprintf(checkpoints_buf, "%d", tmp___62);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "796", "tmp___62", checkpoints_buf);

        tmp___62 = TIFFLinkDirectory(tif);
        sprintf(checkpoints_buf, "%d", tmp___62);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "796", "tmp___62", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___62);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "797", "tmp___62", checkpoints_buf);
        if (tmp___62) {

        } else {
          goto bad;
        }
        sprintf(checkpoints_buf, "%d", tmp___62);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "797", "tmp___62", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "795", "0", checkpoints_buf);
    } else {


      tmp___63 = (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )0, 2);


      tif->tif_diroff = (tmp___63 + 1ULL) & 0xfffffffffffffffeULL;

    }
    sprintf(checkpoints_buf, "%d", isimage);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "794", "isimage", checkpoints_buf);
    if ((unsigned int )pdiroff != (unsigned int )((void *)0)) {
      *pdiroff = tif->tif_diroff;

    } else {

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "806", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      dirsize = (2U + ndir * 12U) + 4U;

    } else {
      dirsize = (8U + ndir * 20U) + 8U;

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "806", "524288", checkpoints_buf);
    tif->tif_dataoff = tif->tif_diroff + (uint64 )dirsize;


    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "810", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      tif->tif_dataoff = (uint64 )((uint32 )tif->tif_dataoff);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "810", "524288", checkpoints_buf);


    if (tif->tif_dataoff < tif->tif_diroff) {

      TIFFErrorExt(tif->tif_clientdata, module___0,
                   "Maximum TIFF file size exceeded");

      goto bad;
    } else {

      if (tif->tif_dataoff < (uint64 )dirsize) {

        TIFFErrorExt(tif->tif_clientdata, module___0,
                     "Maximum TIFF file size exceeded");

        goto bad;
      } else {

      }

    }



    sprintf(checkpoints_buf, "%llu", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "820", "1", checkpoints_buf);
    if (tif->tif_dataoff & 1ULL) {
      (tif->tif_dataoff) ++;

    } else {

    }

    sprintf(checkpoints_buf, "%llu", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "820", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", isimage);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "823", "isimage", checkpoints_buf);
    if (isimage) {
      tif->tif_curdir = (uint16 )((int )tif->tif_curdir + 1);

    } else {

    }
    sprintf(checkpoints_buf, "%d", isimage);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "823", "isimage", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "isimage", checkpoints_buf);






  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "isimage", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "524288", checkpoints_buf);


  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "524288", checkpoints_buf);



  sprintf(checkpoints_buf, "%llu", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "389", "isimage", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "826", "isimage", checkpoints_buf);
  if (isimage) {

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "827", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "827", "17", checkpoints_buf);
    if (tif->tif_dir.td_fieldsset[1] & (1UL << 17)) {

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "828", "0", checkpoints_buf);
      if (tif->tif_subifdoff == 0ULL) {
        na___0 = (uint32 )0;

        nb___0 = dir;



        sprintf(checkpoints_buf, "%d", 330);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "831", "330", checkpoints_buf);


        while (1) {


          if (na___0 < ndir) {

          } else {

            __assert_fail("na<ndir", "tif_dirwrite.c", 782U,
                          "TIFFWriteDirectorySec");

          }


          sprintf(checkpoints_buf, "%d", 330);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "835", "330", checkpoints_buf);
          if ((int )nb___0->tdir_tag == 330) {
            break;
          } else {

          }
          sprintf(checkpoints_buf, "%d", 330);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "835", "330", checkpoints_buf);
          na___0 ++;

          nb___0 ++;

        }


        sprintf(checkpoints_buf, "%d", 330);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "831", "330", checkpoints_buf);



        sprintf(checkpoints_buf, "%u", 524288);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "840", "524288", checkpoints_buf);
        if (! (tif->tif_flags & 524288U)) {
          tif->tif_subifdoff = ((tif->tif_diroff + 2ULL) + (uint64 )(na___0 * 12U)) + 8ULL;

        } else {
          tif->tif_subifdoff = ((tif->tif_diroff + 8ULL) + (uint64 )(na___0 * 20U)) + 12ULL;

        }

        sprintf(checkpoints_buf, "%u", 524288);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "840", "524288", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "828", "0", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "827", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "827", "17", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", isimage);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "826", "isimage", checkpoints_buf);


  dirmem = _TIFFmalloc((tmsize_t )dirsize);


  if ((unsigned int )dirmem == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___0, "Out of memory");

    goto bad;
  } else {

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "851", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    n___0 = (uint8 *)dirmem;

    *((uint16 *)n___0) = (uint16 )ndir;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "854", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort((uint16 *)n___0);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "854", "128", checkpoints_buf);
    n___0 += 2;

    o___0 = dir;

    m = (uint32 )0;





    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "860", "128", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "860", "128", checkpoints_buf);




    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "860", "128", checkpoints_buf);





    while (m < ndir) {


      *((uint16 *)n___0) = o___0->tdir_tag;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "865", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort((uint16 *)n___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "865", "128", checkpoints_buf);
      n___0 += 2;

      *((uint16 *)n___0) = o___0->tdir_type;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "870", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort((uint16 *)n___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "870", "128", checkpoints_buf);
      n___0 += 2;

      nTmp = (uint32 )o___0->tdir_count;


      _TIFFmemcpy((void *)n___0, (void const   *)(& nTmp), (tmsize_t )4);


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "876", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong((uint32 *)n___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "876", "128", checkpoints_buf);
      n___0 += 4;


      _TIFFmemcpy((void *)n___0, (void const   *)(& o___0->tdir_offset),
                  (tmsize_t )4);

      n___0 += 4;

      o___0 ++;

      m ++;

    }




    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "860", "128", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "860", "128", checkpoints_buf);




    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "860", "128", checkpoints_buf);





    nTmp = (uint32 )tif->tif_nextdiroff;


    _TIFFmemcpy((void *)n___0, (void const   *)(& nTmp), (tmsize_t )4);

  } else {
    n___1 = (uint8 *)dirmem;

    *((uint64 *)n___1) = (uint64 )ndir;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "888", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)n___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "888", "128", checkpoints_buf);
    n___1 += 8;

    o___1 = dir;

    m = (uint32 )0;





    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "894", "128", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "894", "128", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "894", "128", checkpoints_buf);





    while (m < ndir) {


      *((uint16 *)n___1) = o___1->tdir_tag;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "899", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort((uint16 *)n___1);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "899", "128", checkpoints_buf);
      n___1 += 2;

      *((uint16 *)n___1) = o___1->tdir_type;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "904", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort((uint16 *)n___1);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "904", "128", checkpoints_buf);
      n___1 += 2;


      _TIFFmemcpy((void *)n___1, (void const   *)(& o___1->tdir_count),
                  (tmsize_t )8);


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "909", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8((uint64 *)n___1);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "909", "128", checkpoints_buf);
      n___1 += 8;


      _TIFFmemcpy((void *)n___1, (void const   *)(& o___1->tdir_offset),
                  (tmsize_t )8);

      n___1 += 8;

      o___1 ++;

      m ++;

    }




    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "894", "128", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "894", "128", checkpoints_buf);



    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "894", "128", checkpoints_buf);






    _TIFFmemcpy((void *)n___1, (void const   *)(& tif->tif_nextdiroff),
                (tmsize_t )8);

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "851", "524288", checkpoints_buf);

  _TIFFfree((void *)dir);

  dir = (TIFFDirEntry *)((void *)0);



  tmp___64 = (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_diroff, 0);




  if (tmp___64 == tif->tif_diroff) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, module___0, "IO error writing directory");

    goto bad;
  }




  tmp___65 = (*(tif->tif_writeproc))(tif->tif_clientdata, dirmem,
                                     (tmsize_t )dirsize);



  if (tmp___65 == (tmsize_t )dirsize) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, module___0, "IO error writing directory");

    goto bad;
  }


  _TIFFfree(dirmem);

  sprintf(checkpoints_buf, "%d", imagedone);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "931", "imagedone", checkpoints_buf);
  if (imagedone) {

    TIFFFreeDirectory(tif);

    tif->tif_flags &= 4294967287U;

    tif->tif_flags &= 4292870143U;


    (*(tif->tif_cleanup))(tif);


    TIFFCreateDirectory(tif);

  } else {

  }
  sprintf(checkpoints_buf, "%d", imagedone);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "931", "imagedone", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "938", "1", checkpoints_buf);
  return (1);
  bad: 
  if ((unsigned int )dir != (unsigned int )((void *)0)) {

    _TIFFfree((void *)dir);

  } else {

  }
  if ((unsigned int )dirmem != (unsigned int )((void *)0)) {

    _TIFFfree(dirmem);

  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "945", "0", checkpoints_buf);
  return (0);
}
}
static int TIFFWriteDirectoryTagSampleformatPerSample(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag , double value ) 
{ 
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;

  {
  switch ((int )tif->tif_dir.td_sampleformat) {
  sprintf(checkpoints_buf, "%d", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "947", "32", checkpoints_buf);
  case 3: 
  if ((int )tif->tif_dir.td_bitspersample <= 32) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "948", "tmp", checkpoints_buf);

    tmp = TIFFWriteDirectoryTagFloatPerSample(tif, ndir, dir, tag, (float )value);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "948", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "949", "tmp", checkpoints_buf);
    return (tmp);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "950", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFWriteDirectoryTagDoublePerSample(tif, ndir, dir, tag, value);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "950", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "951", "tmp___0", checkpoints_buf);
    return (tmp___0);
  }
  sprintf(checkpoints_buf, "%d", 32);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "947", "32", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "952", "8", checkpoints_buf);
  case 2: 
  if ((int )tif->tif_dir.td_bitspersample <= 8) {
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "953", "tmp___1", checkpoints_buf);

    tmp___1 = TIFFWriteDirectoryTagSbytePerSample(tif, ndir, dir, tag,
                                                  (int8 )value);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "953", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "954", "tmp___1", checkpoints_buf);
    return (tmp___1);
  } else {
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "955", "16", checkpoints_buf);
    if ((int )tif->tif_dir.td_bitspersample <= 16) {
      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "956", "tmp___2", checkpoints_buf);

      tmp___2 = TIFFWriteDirectoryTagSshortPerSample(tif, ndir, dir, tag,
                                                     (int16 )value);
      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "956", "tmp___2", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "957", "tmp___2", checkpoints_buf);
      return (tmp___2);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "958", "tmp___3", checkpoints_buf);

      tmp___3 = TIFFWriteDirectoryTagSlongPerSample(tif, ndir, dir, tag,
                                                    (int32 )value);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "958", "tmp___3", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "959", "tmp___3", checkpoints_buf);
      return (tmp___3);
    }
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "955", "16", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "952", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "960", "8", checkpoints_buf);
  case 1: 
  if ((int )tif->tif_dir.td_bitspersample <= 8) {
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "961", "tmp___4", checkpoints_buf);

    tmp___4 = TIFFWriteDirectoryTagBytePerSample(tif, ndir, dir, tag,
                                                 (uint8 )value);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "961", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "962", "tmp___4", checkpoints_buf);
    return (tmp___4);
  } else {
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "963", "16", checkpoints_buf);
    if ((int )tif->tif_dir.td_bitspersample <= 16) {
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "964", "tmp___5", checkpoints_buf);

      tmp___5 = TIFFWriteDirectoryTagShortPerSample(tif, ndir, dir, tag,
                                                    (uint16 )value);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "964", "tmp___5", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "965", "tmp___5", checkpoints_buf);
      return (tmp___5);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "966", "tmp___6", checkpoints_buf);

      tmp___6 = TIFFWriteDirectoryTagLongPerSample(tif, ndir, dir, tag,
                                                   (uint32 )value);
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "966", "tmp___6", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "967", "tmp___6", checkpoints_buf);
      return (tmp___6);
    }
    sprintf(checkpoints_buf, "%d", 16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "963", "16", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "960", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "968", "1", checkpoints_buf);
  default: 
  return (1);
  }
}
}
static int TIFFWriteDirectoryTagAscii(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint32 count , char *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "971", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "973", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedAscii(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "973", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "974", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagUndefinedArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint8 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "977", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "979", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedUndefinedArray(tif, ndir, dir, tag, count,
                                                   value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "979", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "980", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagByteArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint8 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "983", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "985", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedByteArray(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "985", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "986", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagBytePerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint8 value ) ;
static char const   module___1[35]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'B',      (char const   )'y',      (char const   )'t', 
        (char const   )'e',      (char const   )'P',      (char const   )'e',      (char const   )'r', 
        (char const   )'S',      (char const   )'a',      (char const   )'m',      (char const   )'p', 
        (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagBytePerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint8 value ) 
{ 
  uint8 *m ;
  uint8 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "989", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(uint8 )));


  m = (uint8 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___1, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "995", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1006", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedByteArray(tif, ndir, dir, tag,
                                            (uint32 )tif->tif_dir.td_samplesperpixel,
                                            m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1006", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1008", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagSbyteArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int8 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1011", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1013", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedSbyteArray(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1013", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1014", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSbytePerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int8 value ) ;
static char const   module___2[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'b',      (char const   )'y', 
        (char const   )'t',      (char const   )'e',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagSbytePerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int8 value ) 
{ 
  int8 *m ;
  int8 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1017", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(int8 )));


  m = (int8 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___2, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1023", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1034", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedSbyteArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1034", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1036", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagShort(TIFF *tif , uint32 *ndir ,
                                      TIFFDirEntry *dir , uint16 tag ,
                                      uint16 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1039", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1041", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedShort(tif, ndir, dir, tag, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1041", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1042", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagShortArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint16 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1045", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1047", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1047", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1048", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagShortPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint16 value ) ;
static char const   module___3[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'h',      (char const   )'o', 
        (char const   )'r',      (char const   )'t',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagShortPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint16 value ) 
{ 
  uint16 *m ;
  uint16 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1051", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(uint16 )));


  m = (uint16 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___3, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1057", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1068", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1068", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1070", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagSshortArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int16 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1073", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1075", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedSshortArray(tif, ndir, dir, tag, count,
                                                value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1075", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1076", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSshortPerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                int16 value ) ;
static char const   module___4[37]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'s',      (char const   )'h', 
        (char const   )'o',      (char const   )'r',      (char const   )'t',      (char const   )'P', 
        (char const   )'e',      (char const   )'r',      (char const   )'S',      (char const   )'a', 
        (char const   )'m',      (char const   )'p',      (char const   )'l',      (char const   )'e', 
        (char const   )'\000'};
static int TIFFWriteDirectoryTagSshortPerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                int16 value ) 
{ 
  int16 *m ;
  int16 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1079", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(int16 )));


  m = (int16 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___4, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1085", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1096", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedSshortArray(tif, ndir, dir, tag,
                                              (uint32 )tif->tif_dir.td_samplesperpixel,
                                              m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1096", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1098", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagLong(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint32 value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1101", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1103", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedLong(tif, ndir, dir, tag, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1103", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1104", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagLongArray(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 count , uint32 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1107", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1109", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedLongArray(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1109", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1110", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagLongPerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 value ) ;
static char const   module___5[35]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'L',      (char const   )'o',      (char const   )'n', 
        (char const   )'g',      (char const   )'P',      (char const   )'e',      (char const   )'r', 
        (char const   )'S',      (char const   )'a',      (char const   )'m',      (char const   )'p', 
        (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagLongPerSample(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 value ) 
{ 
  uint32 *m ;
  uint32 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1113", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(uint32 )));


  m = (uint32 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___5, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1119", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1130", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedLongArray(tif, ndir, dir, tag,
                                            (uint32 )tif->tif_dir.td_samplesperpixel,
                                            m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1130", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1132", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagSlongArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , int32 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1135", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1137", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedSlongArray(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1137", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1138", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSlongPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int32 value ) ;
static char const   module___6[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'l',      (char const   )'o', 
        (char const   )'n',      (char const   )'g',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagSlongPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               int32 value ) 
{ 
  int32 *m ;
  int32 *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1141", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(int32 )));


  m = (int32 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___6, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1147", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1158", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedSlongArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1158", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1160", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagLong8Array(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , uint64 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1163", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1165", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedLong8Array(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1165", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1166", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSlong8Array(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , int64 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1169", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1171", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedSlong8Array(tif, ndir, dir, tag, count,
                                                value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1171", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1172", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagRational(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         double value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1175", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1177", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedRational(tif, ndir, dir, tag, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1177", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1178", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagRationalArray(TIFF *tif , uint32 *ndir ,
                                              TIFFDirEntry *dir , uint16 tag ,
                                              uint32 count , float *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1181", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1183", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedRationalArray(tif, ndir, dir, tag, count,
                                                  value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1183", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1184", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagSrationalArray(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , float *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1187", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1189", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedSrationalArray(tif, ndir, dir, tag, count,
                                                   value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1189", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1190", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagFloatArray(TIFF *tif , uint32 *ndir ,
                                           TIFFDirEntry *dir , uint16 tag ,
                                           uint32 count , float *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1193", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1195", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedFloatArray(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1195", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1196", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagFloatPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               float value ) ;
static char const   module___7[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'F',      (char const   )'l',      (char const   )'o', 
        (char const   )'a',      (char const   )'t',      (char const   )'P',      (char const   )'e', 
        (char const   )'r',      (char const   )'S',      (char const   )'a',      (char const   )'m', 
        (char const   )'p',      (char const   )'l',      (char const   )'e',      (char const   )'\000'};
static int TIFFWriteDirectoryTagFloatPerSample(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               float value ) 
{ 
  float *m ;
  float *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1199", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(float )));


  m = (float *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___7, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1205", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1216", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedFloatArray(tif, ndir, dir, tag,
                                             (uint32 )tif->tif_dir.td_samplesperpixel,
                                             m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1216", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1218", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagDoubleArray(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 count , double *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1221", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1223", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedDoubleArray(tif, ndir, dir, tag, count,
                                                value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1223", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1224", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagDoublePerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) ;
static char const   module___8[37]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'D',      (char const   )'o',      (char const   )'u', 
        (char const   )'b',      (char const   )'l',      (char const   )'e',      (char const   )'P', 
        (char const   )'e',      (char const   )'r',      (char const   )'S',      (char const   )'a', 
        (char const   )'m',      (char const   )'p',      (char const   )'l',      (char const   )'e', 
        (char const   )'\000'};
static int TIFFWriteDirectoryTagDoublePerSample(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) 
{ 
  double *m ;
  double *na ;
  uint16 nb ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1227", "1", checkpoints_buf);
    return (1);
  } else {

  }


  tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_samplesperpixel * sizeof(double )));


  m = (double *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___8, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1233", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = m;

  nb = (uint16 )0;




  while ((int )nb < (int )tif->tif_dir.td_samplesperpixel) {
    *na = value;

    na ++;

    nb = (uint16 )((int )nb + 1);

  }



  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1244", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedDoubleArray(tif, ndir, dir, tag,
                                              (uint32 )tif->tif_dir.td_samplesperpixel,
                                              m);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1244", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1246", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagIfdArray(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir , uint16 tag ,
                                         uint32 count , uint32 *value ) 
{ 
  int tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1249", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1251", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagCheckedIfdArray(tif, ndir, dir, tag, count, value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1251", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1252", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagShortLong(TIFF *tif , uint32 *ndir ,
                                          TIFFDirEntry *dir , uint16 tag ,
                                          uint32 value ) 
{ 
  int tmp ;
  int tmp___0 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1255", "1", checkpoints_buf);
    return (1);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1257", "65535", checkpoints_buf);
  if (value <= 65535U) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1258", "tmp", checkpoints_buf);

    tmp = TIFFWriteDirectoryTagCheckedShort(tif, ndir, dir, tag, (uint16 )value);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1258", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1259", "tmp", checkpoints_buf);
    return (tmp);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1260", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFWriteDirectoryTagCheckedLong(tif, ndir, dir, tag, value);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1260", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1261", "tmp___0", checkpoints_buf);
    return (tmp___0);
  }

  sprintf(checkpoints_buf, "%u", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1257", "65535", checkpoints_buf);
}
}
static int TIFFWriteDirectoryTagLongLong8Array(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint64 *value ) ;
static char const   module___9[36]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'L',      (char const   )'o',      (char const   )'n', 
        (char const   )'g',      (char const   )'L',      (char const   )'o',      (char const   )'n', 
        (char const   )'g',      (char const   )'8',      (char const   )'A',      (char const   )'r', 
        (char const   )'r',      (char const   )'a',      (char const   )'y',      (char const   )'\000'};
static int TIFFWriteDirectoryTagLongLong8Array(TIFF *tif , uint32 *ndir ,
                                               TIFFDirEntry *dir , uint16 tag ,
                                               uint32 count , uint64 *value ) 
{ 
  uint64 *ma ;
  uint32 mb ;
  uint32 *p ;
  uint32 *q ;
  int o ;
  int tmp ;
  void *tmp___0 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1264", "1", checkpoints_buf);
    return (1);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1266", "524288", checkpoints_buf);
  if (tif->tif_flags & 524288U) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1267", "tmp", checkpoints_buf);

    tmp = TIFFWriteDirectoryTagCheckedLong8Array(tif, ndir, dir, tag, count,
                                                 value);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1267", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1268", "tmp", checkpoints_buf);
    return (tmp);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1266", "524288", checkpoints_buf);


  tmp___0 = _TIFFmalloc((tmsize_t )(count * sizeof(uint32 )));


  p = (uint32 *)tmp___0;

  if ((unsigned int )p == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___9, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1274", "0", checkpoints_buf);
    return (0);
  } else {

  }
  q = p;

  ma = value;

  mb = (uint32 )0;




  sprintf(checkpoints_buf, "%llu", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1279", "4294967295", checkpoints_buf);




  while (mb < count) {



    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1283", "4294967295", checkpoints_buf);
    if (*ma > 4294967295ULL) {

      TIFFErrorExt(tif->tif_clientdata, module___9,
                   "Attempt to write value larger than 0xFFFFFFFF in Classic TIFF file.");


      _TIFFfree((void *)p);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1286", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1283", "4294967295", checkpoints_buf);
    *q = (uint32 )*ma;

    ma ++;

    mb ++;

    q ++;

  }



  sprintf(checkpoints_buf, "%llu", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1279", "4294967295", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1292", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedLongArray(tif, ndir, dir, tag, count, p);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1292", "o", checkpoints_buf);


  _TIFFfree((void *)p);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1294", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagIfdIfd8Array(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint32 count , uint64 *value ) ;
static char const   module___10[34]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'I',      (char const   )'f',      (char const   )'d', 
        (char const   )'I',      (char const   )'f',      (char const   )'d',      (char const   )'8', 
        (char const   )'A',      (char const   )'r',      (char const   )'r',      (char const   )'a', 
        (char const   )'y',      (char const   )'\000'};
static int TIFFWriteDirectoryTagIfdIfd8Array(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint32 count , uint64 *value ) 
{ 
  uint64 *ma ;
  uint32 mb ;
  uint32 *p ;
  uint32 *q ;
  int o ;
  int tmp ;
  void *tmp___0 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1297", "1", checkpoints_buf);
    return (1);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1299", "524288", checkpoints_buf);
  if (tif->tif_flags & 524288U) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1300", "tmp", checkpoints_buf);

    tmp = TIFFWriteDirectoryTagCheckedIfd8Array(tif, ndir, dir, tag, count,
                                                value);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1300", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1301", "tmp", checkpoints_buf);
    return (tmp);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1299", "524288", checkpoints_buf);


  tmp___0 = _TIFFmalloc((tmsize_t )(count * sizeof(uint32 )));


  p = (uint32 *)tmp___0;

  if ((unsigned int )p == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___10, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1307", "0", checkpoints_buf);
    return (0);
  } else {

  }
  q = p;

  ma = value;

  mb = (uint32 )0;




  sprintf(checkpoints_buf, "%llu", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1312", "4294967295", checkpoints_buf);




  while (mb < count) {



    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1316", "4294967295", checkpoints_buf);
    if (*ma > 4294967295ULL) {

      TIFFErrorExt(tif->tif_clientdata, module___10,
                   "Attempt to write value larger than 0xFFFFFFFF in Classic TIFF file.");


      _TIFFfree((void *)p);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1319", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1316", "4294967295", checkpoints_buf);
    *q = (uint32 )*ma;

    ma ++;

    mb ++;

    q ++;

  }



  sprintf(checkpoints_buf, "%llu", 4294967295);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1312", "4294967295", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1325", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedIfdArray(tif, ndir, dir, tag, count, p);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1325", "o", checkpoints_buf);


  _TIFFfree((void *)p);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1327", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagColormap(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir ) ;
static char const   module___11[30]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'C',      (char const   )'o',      (char const   )'l', 
        (char const   )'o',      (char const   )'r',      (char const   )'m',      (char const   )'a', 
        (char const   )'p',      (char const   )'\000'};
static int TIFFWriteDirectoryTagColormap(TIFF *tif , uint32 *ndir ,
                                         TIFFDirEntry *dir ) 
{ 
  uint32 m ;
  uint16 *n ;
  int o ;
  void *tmp ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1330", "1", checkpoints_buf);
    return (1);
  } else {

  }
  m = (uint32 )(1 << (int )tif->tif_dir.td_bitspersample);



  tmp = _TIFFmalloc((tmsize_t )((3U * m) * sizeof(uint16 )));


  n = (uint16 *)tmp;

  if ((unsigned int )n == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___11, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1337", "0", checkpoints_buf);
    return (0);
  } else {

  }

  _TIFFmemcpy((void *)(n + 0), (void const   *)tif->tif_dir.td_colormap[0],
              (tmsize_t )(m * sizeof(uint16 )));


  _TIFFmemcpy((void *)(n + m), (void const   *)tif->tif_dir.td_colormap[1],
              (tmsize_t )(m * sizeof(uint16 )));


  _TIFFmemcpy((void *)(n + 2U * m), (void const   *)tif->tif_dir.td_colormap[2],
              (tmsize_t )(m * sizeof(uint16 )));

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1342", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, (uint16 )320,
                                             3U * m, n);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1342", "o", checkpoints_buf);


  _TIFFfree((void *)n);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1344", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagTransferfunction(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ) ;
static char const   module___12[38]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'T',      (char const   )'r',      (char const   )'a', 
        (char const   )'n',      (char const   )'s',      (char const   )'f',      (char const   )'e', 
        (char const   )'r',      (char const   )'f',      (char const   )'u',      (char const   )'n', 
        (char const   )'c',      (char const   )'t',      (char const   )'i',      (char const   )'o', 
        (char const   )'n',      (char const   )'\000'};
static int TIFFWriteDirectoryTagTransferfunction(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ) 
{ 
  uint32 m ;
  uint16 n ;
  uint16 *o ;
  int p ;
  int tmp ;
  int tmp___0 ;
  void *tmp___1 ;

  {
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1347", "1", checkpoints_buf);
    return (1);
  } else {

  }
  m = (uint32 )(1 << (int )tif->tif_dir.td_bitspersample);

  n = (uint16 )((int )tif->tif_dir.td_samplesperpixel - (int )tif->tif_dir.td_extrasamples);

  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1351", "3", checkpoints_buf);
  if ((int )n > 3) {
    n = (uint16 )3;

  } else {

  }
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1351", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1354", "3", checkpoints_buf);
  if ((int )n == 3) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1355", "tmp", checkpoints_buf);

    tmp = _TIFFmemcmp((void const   *)tif->tif_dir.td_transferfunction[0],
                      (void const   *)tif->tif_dir.td_transferfunction[2],
                      (tmsize_t )(m * sizeof(uint16 )));
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1355", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1356", "tmp", checkpoints_buf);
    if (tmp) {

    } else {
      n = (uint16 )2;

    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1356", "tmp", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1354", "3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1360", "2", checkpoints_buf);
  if ((int )n == 2) {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1361", "tmp___0", checkpoints_buf);

    tmp___0 = _TIFFmemcmp((void const   *)tif->tif_dir.td_transferfunction[0],
                          (void const   *)tif->tif_dir.td_transferfunction[1],
                          (tmsize_t )(m * sizeof(uint16 )));
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1361", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1362", "tmp___0", checkpoints_buf);
    if (tmp___0) {

    } else {
      n = (uint16 )1;

    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1362", "tmp___0", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1360", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1366", "0", checkpoints_buf);
  if ((int )n == 0) {
    n = (uint16 )1;

  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1366", "0", checkpoints_buf);


  tmp___1 = _TIFFmalloc((tmsize_t )(((uint32 )n * m) * sizeof(uint16 )));


  o = (uint16 *)tmp___1;

  if ((unsigned int )o == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___12, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1373", "0", checkpoints_buf);
    return (0);
  } else {

  }

  _TIFFmemcpy((void *)(o + 0),
              (void const   *)tif->tif_dir.td_transferfunction[0],
              (tmsize_t )(m * sizeof(uint16 )));

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1376", "1", checkpoints_buf);
  if ((int )n > 1) {

    _TIFFmemcpy((void *)(o + m),
                (void const   *)tif->tif_dir.td_transferfunction[1],
                (tmsize_t )(m * sizeof(uint16 )));

  } else {

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1376", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1379", "2", checkpoints_buf);
  if ((int )n > 2) {

    _TIFFmemcpy((void *)(o + 2U * m),
                (void const   *)tif->tif_dir.td_transferfunction[2],
                (tmsize_t )(m * sizeof(uint16 )));

  } else {

  }
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1379", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", p);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1382", "p", checkpoints_buf);

  p = TIFFWriteDirectoryTagCheckedShortArray(tif, ndir, dir, (uint16 )301,
                                             (uint32 )n * m, o);
  sprintf(checkpoints_buf, "%d", p);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1382", "p", checkpoints_buf);


  _TIFFfree((void *)o);

  sprintf(checkpoints_buf, "%d", p);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1384", "p", checkpoints_buf);
  return (p);
}
}
static int TIFFWriteDirectoryTagSubifd(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir ) ;
static char const   module___13[28]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'S',      (char const   )'u',      (char const   )'b', 
        (char const   )'i',      (char const   )'f',      (char const   )'d',      (char const   )'\000'};
static int TIFFWriteDirectoryTagSubifd(TIFF *tif , uint32 *ndir ,
                                       TIFFDirEntry *dir ) 
{ 
  uint64 m ;
  int n ;
  uint32 *o ;
  uint64 *pa ;
  uint32 *pb ;
  uint16 p ;
  void *tmp ;
  uint32 *tmp___0 ;
  uint64 *tmp___1 ;

  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1385", "0", checkpoints_buf);
  if ((int )tif->tif_dir.td_nsubifd == 0) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1386", "1", checkpoints_buf);
    return (1);
  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1385", "0", checkpoints_buf);
  if ((unsigned int )dir == (unsigned int )((void *)0)) {
    (*ndir) ++;

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1390", "1", checkpoints_buf);
    return (1);
  } else {

  }
  m = tif->tif_dataoff;


  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1393", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {


    tmp = _TIFFmalloc((tmsize_t )((unsigned int )tif->tif_dir.td_nsubifd * sizeof(uint32 )));


    o = (uint32 *)tmp;

    if ((unsigned int )o == (unsigned int )((void *)0)) {

      TIFFErrorExt(tif->tif_clientdata, module___13, "Out of memory");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1398", "0", checkpoints_buf);
      return (0);
    } else {

    }
    pa = tif->tif_dir.td_subifd;

    pb = o;

    {
    p = (uint16 )0;


    }

    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1403", "4294967295", checkpoints_buf);






    while ((int )p < (int )tif->tif_dir.td_nsubifd) {

      sprintf(checkpoints_buf, "%llu", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1407", "4294967295", checkpoints_buf);
      if (*pa <= 4294967295ULL) {

      } else {

        __assert_fail("*pa<=0xFFFFFFFFUL", "tif_dirwrite.c", 1745U,
                      "TIFFWriteDirectoryTagSubifd");

      }

      sprintf(checkpoints_buf, "%llu", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1407", "4294967295", checkpoints_buf);
      tmp___0 = pb;

      pb ++;

      tmp___1 = pa;

      pa ++;

      *tmp___0 = (uint32 )*tmp___1;

      p = (uint16 )((int )p + 1);

    }

    sprintf(checkpoints_buf, "%llu", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1403", "4294967295", checkpoints_buf);






    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1416", "n", checkpoints_buf);

    n = TIFFWriteDirectoryTagCheckedIfdArray(tif, ndir, dir, (uint16 )330,
                                             (uint32 )tif->tif_dir.td_nsubifd, o);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1416", "n", checkpoints_buf);


    _TIFFfree((void *)o);

  } else {
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1418", "n", checkpoints_buf);

    n = TIFFWriteDirectoryTagCheckedIfd8Array(tif, ndir, dir, (uint16 )330,
                                              (uint32 )tif->tif_dir.td_nsubifd,
                                              tif->tif_dir.td_subifd);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1418", "n", checkpoints_buf);

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1393", "524288", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1419", "n", checkpoints_buf);
  if (! n) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1420", "0", checkpoints_buf);
    return (0);
  } else {

  }
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1419", "n", checkpoints_buf);
  tif->tif_flags |= 8192U;

  tif->tif_nsubifd = tif->tif_dir.td_nsubifd;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1424", "1", checkpoints_buf);
  if ((int )tif->tif_dir.td_nsubifd == 1) {
    tif->tif_subifdoff = (uint64 )0;

  } else {
    tif->tif_subifdoff = m;

  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1424", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1427", "1", checkpoints_buf);
  return (1);
}
}
static int TIFFWriteDirectoryTagCheckedAscii(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint32 count , char *value ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1428", "1", checkpoints_buf);
  if (sizeof(char ) == 1U) {

  } else {

    __assert_fail("sizeof(char)==1", "tif_dirwrite.c", 1775U,
                  "TIFFWriteDirectoryTagCheckedAscii");

  }
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1428", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1431", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )2, count, count,
                                  (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1431", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1432", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedUndefinedArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      uint8 *value ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1433", "1", checkpoints_buf);
  if (sizeof(uint8 ) == 1U) {

  } else {

    __assert_fail("sizeof(uint8)==1", "tif_dirwrite.c", 1782U,
                  "TIFFWriteDirectoryTagCheckedUndefinedArray");

  }
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1433", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1436", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )7, count, count,
                                  (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1436", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1437", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedByteArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint8 *value ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1438", "1", checkpoints_buf);
  if (sizeof(uint8 ) == 1U) {

  } else {

    __assert_fail("sizeof(uint8)==1", "tif_dirwrite.c", 1798U,
                  "TIFFWriteDirectoryTagCheckedByteArray");

  }
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1438", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1441", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )1, count, count,
                                  (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1441", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1442", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSbyteArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int8 *value ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1443", "1", checkpoints_buf);
  if (sizeof(int8 ) == 1U) {

  } else {

    __assert_fail("sizeof(int8)==1", "tif_dirwrite.c", 1814U,
                  "TIFFWriteDirectoryTagCheckedSbyteArray");

  }
  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1443", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1446", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )6, count, count,
                                  (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1446", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1447", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedShort(TIFF *tif , uint32 *ndir ,
                                             TIFFDirEntry *dir , uint16 tag ,
                                             uint16 value ) 
{ 
  uint16 m ;
  int tmp ;

  {
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1448", "2", checkpoints_buf);
  if (sizeof(uint16 ) == 2U) {

  } else {

    __assert_fail("sizeof(uint16)==2", "tif_dirwrite.c", 1822U,
                  "TIFFWriteDirectoryTagCheckedShort");

  }
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1448", "2", checkpoints_buf);
  m = value;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1452", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabShort(& m);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1452", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1455", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )3, (uint32 )1,
                                  (uint32 )2, (void *)(& m));
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1455", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1456", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedShortArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint16 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 2147483648);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1457", "2147483648", checkpoints_buf);
  if (count < 2147483648U) {

  } else {

    __assert_fail("count<0x80000000", "tif_dirwrite.c", 1832U,
                  "TIFFWriteDirectoryTagCheckedShortArray");

  }

  sprintf(checkpoints_buf, "%u", 2147483648);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1457", "2147483648", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1460", "2", checkpoints_buf);
  if (sizeof(uint16 ) == 2U) {

  } else {

    __assert_fail("sizeof(uint16)==2", "tif_dirwrite.c", 1833U,
                  "TIFFWriteDirectoryTagCheckedShortArray");

  }
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1460", "2", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1463", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfShort(value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1463", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1466", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )3, count,
                                  count * 2U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1466", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1467", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSshortArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int16 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 2147483648);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1468", "2147483648", checkpoints_buf);
  if (count < 2147483648U) {

  } else {

    __assert_fail("count<0x80000000", "tif_dirwrite.c", 1855U,
                  "TIFFWriteDirectoryTagCheckedSshortArray");

  }

  sprintf(checkpoints_buf, "%u", 2147483648);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1468", "2147483648", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1471", "2", checkpoints_buf);
  if (sizeof(int16 ) == 2U) {

  } else {

    __assert_fail("sizeof(int16)==2", "tif_dirwrite.c", 1856U,
                  "TIFFWriteDirectoryTagCheckedSshortArray");

  }
  sprintf(checkpoints_buf, "%u", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1471", "2", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1474", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfShort((uint16 *)value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1474", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1477", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )8, count,
                                  count * 2U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1477", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1478", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedLong(TIFF *tif , uint32 *ndir ,
                                            TIFFDirEntry *dir , uint16 tag ,
                                            uint32 value ) 
{ 
  uint32 m ;
  int tmp ;

  {
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1479", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1866U,
                  "TIFFWriteDirectoryTagCheckedLong");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1479", "4", checkpoints_buf);
  m = value;


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1483", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong(& m);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1483", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1486", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )4, (uint32 )1,
                                  (uint32 )4, (void *)(& m));
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1486", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1487", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedLongArray(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint32 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1488", "1073741824", checkpoints_buf);
  if (count < 1073741824U) {

  } else {

    __assert_fail("count<0x40000000", "tif_dirwrite.c", 1876U,
                  "TIFFWriteDirectoryTagCheckedLongArray");

  }

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1488", "1073741824", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1491", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1877U,
                  "TIFFWriteDirectoryTagCheckedLongArray");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1491", "4", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1494", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong(value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1494", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1497", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )4, count,
                                  count * 4U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1497", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1498", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSlongArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  int32 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1499", "1073741824", checkpoints_buf);
  if (count < 1073741824U) {

  } else {

    __assert_fail("count<0x40000000", "tif_dirwrite.c", 1899U,
                  "TIFFWriteDirectoryTagCheckedSlongArray");

  }

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1499", "1073741824", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1502", "4", checkpoints_buf);
  if (sizeof(int32 ) == 4U) {

  } else {

    __assert_fail("sizeof(int32)==4", "tif_dirwrite.c", 1900U,
                  "TIFFWriteDirectoryTagCheckedSlongArray");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1502", "4", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1505", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong((uint32 *)value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1505", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1508", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )9, count,
                                  count * 4U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1508", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1509", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedLong8Array(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  uint64 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1510", "536870912", checkpoints_buf);
  if (count < 536870912U) {

  } else {

    __assert_fail("count<0x20000000", "tif_dirwrite.c", 1923U,
                  "TIFFWriteDirectoryTagCheckedLong8Array");

  }

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1510", "536870912", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1513", "8", checkpoints_buf);
  if (sizeof(uint64 ) == 8U) {

  } else {

    __assert_fail("sizeof(uint64)==8", "tif_dirwrite.c", 1924U,
                  "TIFFWriteDirectoryTagCheckedLong8Array");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1513", "8", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1516", "524288", checkpoints_buf);
  if (tif->tif_flags & 524288U) {

  } else {

    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 1925U,
                  "TIFFWriteDirectoryTagCheckedLong8Array");

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1516", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1519", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8(value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1519", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1522", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )16, count,
                                  count * 8U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1522", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1523", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedSlong8Array(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   int64 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1524", "536870912", checkpoints_buf);
  if (count < 536870912U) {

  } else {

    __assert_fail("count<0x20000000", "tif_dirwrite.c", 1948U,
                  "TIFFWriteDirectoryTagCheckedSlong8Array");

  }

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1524", "536870912", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1527", "8", checkpoints_buf);
  if (sizeof(int64 ) == 8U) {

  } else {

    __assert_fail("sizeof(int64)==8", "tif_dirwrite.c", 1949U,
                  "TIFFWriteDirectoryTagCheckedSlong8Array");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1527", "8", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1530", "524288", checkpoints_buf);
  if (tif->tif_flags & 524288U) {

  } else {

    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 1950U,
                  "TIFFWriteDirectoryTagCheckedSlong8Array");

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1530", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1533", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8((uint64 *)value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1533", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1536", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )17, count,
                                  count * 8U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1536", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1537", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedRational(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                double value ) 
{ 
  uint32 m[2] ;
  int tmp ;

  {
  sprintf(checkpoints_buf, "%lf", value);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1538", "value", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1538", "0.000000", checkpoints_buf);
  if (value >= 0.0) {

  } else {

    __assert_fail("value>=0.0", "tif_dirwrite.c", 1960U,
                  "TIFFWriteDirectoryTagCheckedRational");

  }
  sprintf(checkpoints_buf, "%lf", value);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1538", "value", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1538", "0.000000", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1541", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1961U,
                  "TIFFWriteDirectoryTagCheckedRational");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1541", "4", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", value);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1544", "value", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1544", "0.000000", checkpoints_buf);
  if (value <= 0.0) {
    m[0] = (uint32 )0;

    m[1] = (uint32 )1;

  } else {
    sprintf(checkpoints_buf, "%lf", value);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1547", "value", checkpoints_buf);
    if (value == (double )((uint32 )value)) {
      m[0] = (uint32 )value;

      m[1] = (uint32 )1;

    } else {
      sprintf(checkpoints_buf, "%lf", value);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1550", "value", checkpoints_buf);
      sprintf(checkpoints_buf, "%lf", 1.000000);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1550", "1.000000", checkpoints_buf);
      if (value < 1.0) {
        m[0] = (uint32 )(value * (double )4294967295U);

        m[1] = 4294967295U;

      } else {
        m[0] = 4294967295U;

        m[1] = (uint32 )((double )4294967295U / value);

      }
      sprintf(checkpoints_buf, "%lf", value);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1550", "value", checkpoints_buf);
      sprintf(checkpoints_buf, "%lf", 1.000000);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1550", "1.000000", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%lf", value);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1547", "value", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%lf", value);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1544", "value", checkpoints_buf);
  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1544", "0.000000", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1555", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabLong(& m[0]);


    TIFFSwabLong(& m[1]);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1555", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1559", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )5, (uint32 )1,
                                  (uint32 )8, (void *)(& m[0]));
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1559", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1560", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedRationalArray(TIFF *tif , uint32 *ndir ,
                                                     TIFFDirEntry *dir ,
                                                     uint16 tag , uint32 count ,
                                                     float *value ) ;
static char const   module___14[42]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'C',      (char const   )'h',      (char const   )'e', 
        (char const   )'c',      (char const   )'k',      (char const   )'e',      (char const   )'d', 
        (char const   )'R',      (char const   )'a',      (char const   )'t',      (char const   )'i', 
        (char const   )'o',      (char const   )'n',      (char const   )'a',      (char const   )'l', 
        (char const   )'A',      (char const   )'r',      (char const   )'r',      (char const   )'a', 
        (char const   )'y',      (char const   )'\000'};
static int TIFFWriteDirectoryTagCheckedRationalArray(TIFF *tif , uint32 *ndir ,
                                                     TIFFDirEntry *dir ,
                                                     uint16 tag , uint32 count ,
                                                     float *value ) 
{ 
  uint32 *m ;
  float *na ;
  uint32 *nb ;
  uint32 nc ;
  int o ;
  void *tmp ;

  {
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1561", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 1999U,
                  "TIFFWriteDirectoryTagCheckedRationalArray");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1561", "4", checkpoints_buf);


  tmp = _TIFFmalloc((tmsize_t )((count * 2U) * sizeof(uint32 )));


  m = (uint32 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___14, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1568", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = value;

  nb = m;

  nc = (uint32 )0;



  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1573", "0.000000", checkpoints_buf);



  while (nc < count) {


    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1577", "0.000000", checkpoints_buf);
    if ((double )*na <= 0.0) {
      *(nb + 0) = (uint32 )0;

      *(nb + 1) = (uint32 )1;

    } else {

      if (*na == (float )((uint32 )*na)) {
        *(nb + 0) = (uint32 )*na;

        *(nb + 1) = (uint32 )1;

      } else {
        sprintf(checkpoints_buf, "%lf", 1.000000);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1583", "1.000000", checkpoints_buf);
        if ((double )*na < 1.0) {
          *(nb + 0) = (uint32 )(*na * (float )4294967295U);

          *(nb + 1) = 4294967295U;

        } else {
          *(nb + 0) = 4294967295U;

          *(nb + 1) = (uint32 )((float )4294967295U / *na);

        }
        sprintf(checkpoints_buf, "%lf", 1.000000);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1583", "1.000000", checkpoints_buf);
      }

    }
    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1577", "0.000000", checkpoints_buf);
    na ++;

    nb += 2;

    nc ++;

  }


  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1573", "0.000000", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1591", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong(m, (tmsize_t )(count * 2U));

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1591", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1594", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )5, count,
                                count * 8U, (void *)(m + 0));
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1594", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1596", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagCheckedSrationalArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      float *value ) ;
static char const   module___15[43]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'C',      (char const   )'h',      (char const   )'e', 
        (char const   )'c',      (char const   )'k',      (char const   )'e',      (char const   )'d', 
        (char const   )'S',      (char const   )'r',      (char const   )'a',      (char const   )'t', 
        (char const   )'i',      (char const   )'o',      (char const   )'n',      (char const   )'a', 
        (char const   )'l',      (char const   )'A',      (char const   )'r',      (char const   )'r', 
        (char const   )'a',      (char const   )'y',      (char const   )'\000'};
static int TIFFWriteDirectoryTagCheckedSrationalArray(TIFF *tif , uint32 *ndir ,
                                                      TIFFDirEntry *dir ,
                                                      uint16 tag ,
                                                      uint32 count ,
                                                      float *value ) 
{ 
  int32 *m ;
  float *na ;
  int32 *nb ;
  uint32 nc ;
  int o ;
  void *tmp ;

  {
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1597", "4", checkpoints_buf);
  if (sizeof(int32 ) == 4U) {

  } else {

    __assert_fail("sizeof(int32)==4", "tif_dirwrite.c", 2045U,
                  "TIFFWriteDirectoryTagCheckedSrationalArray");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1597", "4", checkpoints_buf);


  tmp = _TIFFmalloc((tmsize_t )((count * 2U) * sizeof(int32 )));


  m = (int32 *)tmp;

  if ((unsigned int )m == (unsigned int )((void *)0)) {

    TIFFErrorExt(tif->tif_clientdata, module___15, "Out of memory");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1604", "0", checkpoints_buf);
    return (0);
  } else {

  }
  na = value;

  nb = m;

  nc = (uint32 )0;



  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1609", "0.000000", checkpoints_buf);



  while (nc < count) {


    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1613", "0.000000", checkpoints_buf);
    if ((double )*na < 0.0) {

      if (*na == (float )((int32 )*na)) {
        *(nb + 0) = (int32 )*na;

        *(nb + 1) = 1;

      } else {
        sprintf(checkpoints_buf, "%lf", 1.000000);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1617", "1.000000", checkpoints_buf);
        if ((double )*na > - 1.0) {
          *(nb + 0) = - ((int32 )(- *na * (float )2147483647));

          *(nb + 1) = 2147483647;

        } else {
          *(nb + 0) = -2147483647;

          *(nb + 1) = (int32 )((float )2147483647 / - *na);

        }
        sprintf(checkpoints_buf, "%lf", 1.000000);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1617", "1.000000", checkpoints_buf);
      }

    } else {

      if (*na == (float )((int32 )*na)) {
        *(nb + 0) = (int32 )*na;

        *(nb + 1) = 1;

      } else {
        sprintf(checkpoints_buf, "%lf", 1.000000);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1625", "1.000000", checkpoints_buf);
        if ((double )*na < 1.0) {
          *(nb + 0) = (int32 )(*na * (float )2147483647);

          *(nb + 1) = 2147483647;

        } else {
          *(nb + 0) = 2147483647;

          *(nb + 1) = (int32 )((float )2147483647 / *na);

        }
        sprintf(checkpoints_buf, "%lf", 1.000000);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1625", "1.000000", checkpoints_buf);
      }

    }
    sprintf(checkpoints_buf, "%lf", 0.000000);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1613", "0.000000", checkpoints_buf);
    na ++;

    nb += 2;

    nc ++;

  }


  sprintf(checkpoints_buf, "%lf", 0.000000);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1609", "0.000000", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1633", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong((uint32 *)m, (tmsize_t )(count * 2U));

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1633", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1636", "o", checkpoints_buf);

  o = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )10, count,
                                count * 8U, (void *)(m + 0));
  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1636", "o", checkpoints_buf);


  _TIFFfree((void *)m);

  sprintf(checkpoints_buf, "%d", o);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1638", "o", checkpoints_buf);
  return (o);
}
}
static int TIFFWriteDirectoryTagCheckedFloatArray(TIFF *tif , uint32 *ndir ,
                                                  TIFFDirEntry *dir ,
                                                  uint16 tag , uint32 count ,
                                                  float *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1639", "1073741824", checkpoints_buf);
  if (count < 1073741824U) {

  } else {

    __assert_fail("count<0x40000000", "tif_dirwrite.c", 2115U,
                  "TIFFWriteDirectoryTagCheckedFloatArray");

  }

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1639", "1073741824", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1642", "4", checkpoints_buf);
  if (sizeof(float ) == 4U) {

  } else {

    __assert_fail("sizeof(float)==4", "tif_dirwrite.c", 2116U,
                  "TIFFWriteDirectoryTagCheckedFloatArray");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1642", "4", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1645", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfFloat(value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1645", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1648", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )11, count,
                                  count * 4U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1648", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1649", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedDoubleArray(TIFF *tif , uint32 *ndir ,
                                                   TIFFDirEntry *dir ,
                                                   uint16 tag , uint32 count ,
                                                   double *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1650", "536870912", checkpoints_buf);
  if (count < 536870912U) {

  } else {

    __assert_fail("count<0x20000000", "tif_dirwrite.c", 2140U,
                  "TIFFWriteDirectoryTagCheckedDoubleArray");

  }

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1650", "536870912", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1653", "8", checkpoints_buf);
  if (sizeof(double ) == 8U) {

  } else {

    __assert_fail("sizeof(double)==8", "tif_dirwrite.c", 2141U,
                  "TIFFWriteDirectoryTagCheckedDoubleArray");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1653", "8", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1656", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfDouble(value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1656", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1659", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )12, count,
                                  count * 8U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1659", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1660", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedIfdArray(TIFF *tif , uint32 *ndir ,
                                                TIFFDirEntry *dir , uint16 tag ,
                                                uint32 count , uint32 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1661", "1073741824", checkpoints_buf);
  if (count < 1073741824U) {

  } else {

    __assert_fail("count<0x40000000", "tif_dirwrite.c", 2151U,
                  "TIFFWriteDirectoryTagCheckedIfdArray");

  }

  sprintf(checkpoints_buf, "%u", 1073741824);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1661", "1073741824", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1664", "4", checkpoints_buf);
  if (sizeof(uint32 ) == 4U) {

  } else {

    __assert_fail("sizeof(uint32)==4", "tif_dirwrite.c", 2152U,
                  "TIFFWriteDirectoryTagCheckedIfdArray");

  }
  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1664", "4", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1667", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong(value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1667", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1670", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )13, count,
                                  count * 4U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1670", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1671", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagCheckedIfd8Array(TIFF *tif , uint32 *ndir ,
                                                 TIFFDirEntry *dir ,
                                                 uint16 tag , uint32 count ,
                                                 uint64 *value ) 
{ 
  int tmp ;

  {

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1672", "536870912", checkpoints_buf);
  if (count < 536870912U) {

  } else {

    __assert_fail("count<0x20000000", "tif_dirwrite.c", 2161U,
                  "TIFFWriteDirectoryTagCheckedIfd8Array");

  }

  sprintf(checkpoints_buf, "%u", 536870912);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1672", "536870912", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1675", "8", checkpoints_buf);
  if (sizeof(uint64 ) == 8U) {

  } else {

    __assert_fail("sizeof(uint64)==8", "tif_dirwrite.c", 2162U,
                  "TIFFWriteDirectoryTagCheckedIfd8Array");

  }
  sprintf(checkpoints_buf, "%u", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1675", "8", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1678", "524288", checkpoints_buf);
  if (tif->tif_flags & 524288U) {

  } else {

    __assert_fail("tif->tif_flags&0x80000", "tif_dirwrite.c", 2163U,
                  "TIFFWriteDirectoryTagCheckedIfd8Array");

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1678", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1681", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabArrayOfLong8(value, (tmsize_t )count);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1681", "128", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1684", "tmp", checkpoints_buf);

  tmp = TIFFWriteDirectoryTagData(tif, ndir, dir, tag, (uint16 )18, count,
                                  count * 8U, (void *)value);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1684", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1685", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int TIFFWriteDirectoryTagData(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint16 datatype , uint32 count ,
                                     uint32 datalength , void *data ) ;
static char const   module___16[26]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'W',      (char const   )'r',      (char const   )'i',      (char const   )'t', 
        (char const   )'e',      (char const   )'D',      (char const   )'i',      (char const   )'r', 
        (char const   )'e',      (char const   )'c',      (char const   )'t',      (char const   )'o', 
        (char const   )'r',      (char const   )'y',      (char const   )'T',      (char const   )'a', 
        (char const   )'g',      (char const   )'D',      (char const   )'a',      (char const   )'t', 
        (char const   )'a',      (char const   )'\000'};
static int TIFFWriteDirectoryTagData(TIFF *tif , uint32 *ndir ,
                                     TIFFDirEntry *dir , uint16 tag ,
                                     uint16 datatype , uint32 count ,
                                     uint32 datalength , void *data ) 
{ 
  uint32 m ;
  uint32 n ;
  uint64 na ;
  uint64 nb ;
  toff_t tmp ;
  tmsize_t tmp___0 ;
  uint32 o ;
  unsigned int tmp___1 ;

  {
  m = (uint32 )0;




  while (m < *ndir) {


    if ((int )(dir + m)->tdir_tag != (int )tag) {

    } else {

      __assert_fail("dir[m].tdir_tag!=tag", "tif_dirwrite.c", 2177U,
                    "TIFFWriteDirectoryTagData");

    }
    if ((int )(dir + m)->tdir_tag > (int )tag) {
      break;
    } else {

    }
    m ++;

  }





  if (m < *ndir) {
    n = *ndir;





    while (n > m) {


      *(dir + n) = *(dir + (n - 1U));

      n --;

    }




  } else {

  }


  (dir + m)->tdir_tag = tag;

  (dir + m)->tdir_type = datatype;

  (dir + m)->tdir_count = (uint64 )count;

  (dir + m)->tdir_offset.toff_long8 = (uint64 )0;


  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1711", "524288", checkpoints_buf);
  if (tif->tif_flags & 524288U) {
    tmp___1 = 8U;
    sprintf(checkpoints_buf, "%u", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1712", "tmp___1", checkpoints_buf);
  } else {
    tmp___1 = 4U;
    sprintf(checkpoints_buf, "%u", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1713", "tmp___1", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1711", "524288", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1714", "tmp___1", checkpoints_buf);
  if (datalength <= tmp___1) {

    _TIFFmemcpy((void *)(& (dir + m)->tdir_offset), (void const   *)data,
                (tmsize_t )datalength);

  } else {
    na = tif->tif_dataoff;

    nb = na + (uint64 )datalength;


    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1718", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      nb = (uint64 )((uint32 )nb);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1718", "524288", checkpoints_buf);


    if (nb < na) {

      TIFFErrorExt(tif->tif_clientdata, module___16,
                   "Maximum TIFF file size exceeded");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1723", "0", checkpoints_buf);
      return (0);
    } else {

      if (nb < (uint64 )datalength) {

        TIFFErrorExt(tif->tif_clientdata, module___16,
                     "Maximum TIFF file size exceeded");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1726", "0", checkpoints_buf);
        return (0);
      } else {

      }

    }




    tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, na, 0);




    if (tmp == na) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___16, "IO error writing tag data");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1732", "0", checkpoints_buf);
      return (0);
    }


    sprintf(checkpoints_buf, "%ul", 2147483648);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1733", "2147483648", checkpoints_buf);
    if ((unsigned long )datalength < 2147483648UL) {

    } else {

      __assert_fail("datalength<0x80000000UL", "tif_dirwrite.c", 2211U,
                    "TIFFWriteDirectoryTagData");

    }
    sprintf(checkpoints_buf, "%ul", 2147483648);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1733", "2147483648", checkpoints_buf);


    tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata, data,
                                      (tmsize_t )datalength);



    if (tmp___0 == (tmsize_t )datalength) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___16, "IO error writing tag data");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1740", "0", checkpoints_buf);
      return (0);
    }

    tif->tif_dataoff = nb;


    sprintf(checkpoints_buf, "%llu", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1742", "1", checkpoints_buf);
    if (tif->tif_dataoff & 1ULL) {
      (tif->tif_dataoff) ++;

    } else {

    }

    sprintf(checkpoints_buf, "%llu", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1742", "1", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1745", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      o = (uint32 )na;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1747", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong(& o);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1747", "128", checkpoints_buf);

      _TIFFmemcpy((void *)(& (dir + m)->tdir_offset), (void const   *)(& o),
                  (tmsize_t )4);

    } else {
      (dir + m)->tdir_offset.toff_long8 = na;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1752", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& (dir + m)->tdir_offset.toff_long8);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1752", "128", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1745", "524288", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1714", "tmp___1", checkpoints_buf);
  (*ndir) ++;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1756", "1", checkpoints_buf);
  return (1);
}
}
static int TIFFLinkDirectory(TIFF *tif ) ;
static char const   module___17[18]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'L',      (char const   )'i',      (char const   )'n',      (char const   )'k', 
        (char const   )'D',      (char const   )'i',      (char const   )'r',      (char const   )'e', 
        (char const   )'c',      (char const   )'t',      (char const   )'o',      (char const   )'r', 
        (char const   )'y',      (char const   )'\000'};
static int TIFFLinkDirectory(TIFF *tif ) 
{ 
  toff_t tmp ;
  uint32 m ;
  tmsize_t tmp___0 ;
  uint64 m___0 ;
  tmsize_t tmp___1 ;
  uint32 m___1 ;
  uint32 nextdir ;
  tmsize_t tmp___2 ;
  uint16 dircount ;
  uint32 nextnextdir ;
  toff_t tmp___3 ;
  tmsize_t tmp___4 ;
  tmsize_t tmp___5 ;
  tmsize_t tmp___6 ;
  uint64 m___2 ;
  uint64 nextdir___0 ;
  tmsize_t tmp___7 ;
  uint64 dircount64 ;
  uint16 dircount___0 ;
  uint64 nextnextdir___0 ;
  toff_t tmp___8 ;
  tmsize_t tmp___9 ;
  tmsize_t tmp___10 ;
  tmsize_t tmp___11 ;

  {


  tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )0, 2);


  tif->tif_diroff = (tmp + 1ULL) & 0xfffffffffffffffeULL;


  sprintf(checkpoints_buf, "%u", 8192);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1759", "8192", checkpoints_buf);
  if (tif->tif_flags & 8192U) {

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1760", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      m = (uint32 )tif->tif_diroff;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1762", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong(& m);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1762", "128", checkpoints_buf);

      (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_subifdoff, 0);



      tmp___0 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m),
                                        (tmsize_t )4);



      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1767", "4", checkpoints_buf);
      if (tmp___0 == 4L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error writing SubIFD directory link");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1770", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1767", "4", checkpoints_buf);
      tif->tif_nsubifd = (uint16 )((int )tif->tif_nsubifd - 1);


      if (tif->tif_nsubifd) {
        tif->tif_subifdoff += 4ULL;

      } else {
        tif->tif_flags &= 4294959103U;

      }

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1775", "1", checkpoints_buf);
      return (1);
    } else {
      m___0 = tif->tif_diroff;


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1777", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& m___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1777", "128", checkpoints_buf);

      (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_subifdoff, 0);



      tmp___1 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m___0),
                                        (tmsize_t )8);



      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1782", "8", checkpoints_buf);
      if (tmp___1 == 8L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error writing SubIFD directory link");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1785", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1782", "8", checkpoints_buf);
      tif->tif_nsubifd = (uint16 )((int )tif->tif_nsubifd - 1);


      if (tif->tif_nsubifd) {
        tif->tif_subifdoff += 8ULL;

      } else {
        tif->tif_flags &= 4294959103U;

      }

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1790", "1", checkpoints_buf);
      return (1);
    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1760", "524288", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 8192);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1759", "8192", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1792", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    m___1 = (uint32 )tif->tif_diroff;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1794", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& m___1);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1794", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1797", "0", checkpoints_buf);
    if (tif->tif_header.classic.tiff_diroff == 0U) {
      tif->tif_header.classic.tiff_diroff = (uint32 )tif->tif_diroff;


      (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )4, 0);



      tmp___2 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m___1),
                                        (tmsize_t )4);



      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1801", "4", checkpoints_buf);
      if (tmp___2 == 4L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "Error writing TIFF header");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1804", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1801", "4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1805", "1", checkpoints_buf);
      return (1);
    } else {

    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1797", "0", checkpoints_buf);
    nextdir = tif->tif_header.classic.tiff_diroff;





    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "128", checkpoints_buf);




    sprintf(checkpoints_buf, "%ld", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "4", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "0", checkpoints_buf);

    while (1) {


      tmp___3 = (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )nextdir, 0);



      if (tmp___3 == (toff_t )nextdir) {


        tmp___4 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& dircount), (tmsize_t )2);



        sprintf(checkpoints_buf, "%ld", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1812", "2", checkpoints_buf);
        if (tmp___4 == 2L) {

        } else {

          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error fetching directory count");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "1815", "0", checkpoints_buf);
          return (0);
        }

        sprintf(checkpoints_buf, "%ld", 2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1812", "2", checkpoints_buf);
      } else {

        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory count");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1817", "0", checkpoints_buf);
        return (0);
      }


      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1818", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabShort(& dircount);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1818", "128", checkpoints_buf);

      (*(tif->tif_seekproc))(tif->tif_clientdata,
                             (toff_t )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                             0);



      tmp___5 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                       (void *)(& nextnextdir), (tmsize_t )4);



      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1823", "4", checkpoints_buf);
      if (tmp___5 == 4L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory link");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1826", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1823", "4", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1827", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong(& nextnextdir);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1827", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1830", "0", checkpoints_buf);
      if (nextnextdir == 0U) {

        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (toff_t )((nextdir + 2U) + (uint32 )((int )dircount * 12)),
                               0);



        tmp___6 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                          (void *)(& m___1), (tmsize_t )4);



        sprintf(checkpoints_buf, "%ld", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1833", "4", checkpoints_buf);
        if (tmp___6 == 4L) {

        } else {

          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error writing directory link");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "1836", "0", checkpoints_buf);
          return (0);
        }

        sprintf(checkpoints_buf, "%ld", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1833", "4", checkpoints_buf);
        break;
      } else {

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1830", "0", checkpoints_buf);
      nextdir = nextnextdir;

    }




    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "128", checkpoints_buf);




    sprintf(checkpoints_buf, "%ld", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "4", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1808", "0", checkpoints_buf);

  } else {
    m___2 = tif->tif_diroff;


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1841", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(& m___2);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1841", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1844", "0", checkpoints_buf);
    if (tif->tif_header.big.tiff_diroff == 0ULL) {
      tif->tif_header.big.tiff_diroff = tif->tif_diroff;


      (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )8, 0);



      tmp___7 = (*(tif->tif_writeproc))(tif->tif_clientdata, (void *)(& m___2),
                                        (tmsize_t )8);



      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1848", "8", checkpoints_buf);
      if (tmp___7 == 8L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, (char const   *)tif->tif_name,
                     "Error writing TIFF header");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1851", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1848", "8", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1852", "1", checkpoints_buf);
      return (1);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1844", "0", checkpoints_buf);
    nextdir___0 = tif->tif_header.big.tiff_diroff;






    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%llu", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "65535", checkpoints_buf);





    sprintf(checkpoints_buf, "%ld", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "8", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "0", checkpoints_buf);

    while (1) {


      tmp___8 = (*(tif->tif_seekproc))(tif->tif_clientdata, nextdir___0, 0);




      if (tmp___8 == nextdir___0) {


        tmp___9 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                         (void *)(& dircount64), (tmsize_t )8);



        sprintf(checkpoints_buf, "%ld", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1859", "8", checkpoints_buf);
        if (tmp___9 == 8L) {

        } else {

          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error fetching directory count");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "1862", "0", checkpoints_buf);
          return (0);
        }

        sprintf(checkpoints_buf, "%ld", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1859", "8", checkpoints_buf);
      } else {

        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory count");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1864", "0", checkpoints_buf);
        return (0);
      }



      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1865", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& dircount64);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1865", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1868", "65535", checkpoints_buf);
      if (dircount64 > 65535ULL) {

        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Sanity check on tag count failed, likely corrupt TIFF");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1870", "0", checkpoints_buf);
        return (0);
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 65535);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1868", "65535", checkpoints_buf);
      dircount___0 = (uint16 )dircount64;


      (*(tif->tif_seekproc))(tif->tif_clientdata,
                             (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                             0);



      tmp___10 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                        (void *)(& nextnextdir___0),
                                        (tmsize_t )8);



      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1875", "8", checkpoints_buf);
      if (tmp___10 == 8L) {

      } else {

        TIFFErrorExt(tif->tif_clientdata, module___17,
                     "Error fetching directory link");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1878", "0", checkpoints_buf);
        return (0);
      }

      sprintf(checkpoints_buf, "%ld", 8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1875", "8", checkpoints_buf);

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1879", "128", checkpoints_buf);
      if (tif->tif_flags & 128U) {

        TIFFSwabLong8(& nextnextdir___0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 128);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1879", "128", checkpoints_buf);

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1882", "0", checkpoints_buf);
      if (nextnextdir___0 == 0ULL) {

        (*(tif->tif_seekproc))(tif->tif_clientdata,
                               (nextdir___0 + 8ULL) + (uint64 )((int )dircount___0 * 20),
                               0);



        tmp___11 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                           (void *)(& m___2), (tmsize_t )8);



        sprintf(checkpoints_buf, "%ld", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1885", "8", checkpoints_buf);
        if (tmp___11 == 8L) {

        } else {

          TIFFErrorExt(tif->tif_clientdata, module___17,
                       "Error writing directory link");

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "1888", "0", checkpoints_buf);
          return (0);
        }

        sprintf(checkpoints_buf, "%ld", 8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1885", "8", checkpoints_buf);
        break;
      } else {

      }

      sprintf(checkpoints_buf, "%llu", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1882", "0", checkpoints_buf);
      nextdir___0 = nextnextdir___0;

    }





    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%llu", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "65535", checkpoints_buf);





    sprintf(checkpoints_buf, "%ld", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "8", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "128", checkpoints_buf);

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1855", "0", checkpoints_buf);

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1792", "524288", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1892", "1", checkpoints_buf);
  return (1);
}
}
int _TIFFRewriteField(TIFF *tif , uint16 tag , TIFFDataType in_datatype ,
                      tmsize_t count , void *data ) ;
static char const   module___18[15]  = 
  {      (char const   )'T',      (char const   )'I',      (char const   )'F',      (char const   )'F', 
        (char const   )'R',      (char const   )'e',      (char const   )'s',      (char const   )'e', 
        (char const   )'t',      (char const   )'F',      (char const   )'i',      (char const   )'e', 
        (char const   )'l',      (char const   )'d',      (char const   )'\000'};
int _TIFFRewriteField(TIFF *tif , uint16 tag , TIFFDataType in_datatype ,
                      tmsize_t count , void *data ) 
{ 
  TIFFField const   *fip ;
  uint16 dircount ;
  tmsize_t dirsize ;
  uint8 direntry_raw[20] ;
  uint16 entry_tag ;
  uint16 entry_type ;
  uint64 entry_count ;
  uint64 entry_offset ;
  int value_in_entry ;
  uint64 read_offset ;
  uint8 *buf_to_write ;
  TIFFDataType datatype ;
  toff_t tmp ;
  tmsize_t tmp___0 ;
  uint64 dircount64 ;
  tmsize_t tmp___1 ;
  tmsize_t tmp___2 ;
  uint32 value ;
  int tmp___3 ;
  int tmp___4 ;
  void *tmp___5 ;
  int tmp___6 ;
  tmsize_t i ;
  tmsize_t i___0 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  toff_t tmp___13 ;
  int tmp___14 ;
  tmsize_t tmp___15 ;
  int tmp___16 ;
  int tmp___17 ;
  tmsize_t tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  uint32 value___0 ;
  toff_t tmp___21 ;
  tmsize_t tmp___22 ;

  {
  fip = (TIFFField const   *)((void *)0);

  entry_tag = (uint16 )0;

  entry_type = (uint16 )0;

  entry_count = (uint64 )0;

  entry_offset = (uint64 )0;

  value_in_entry = 0;
  sprintf(checkpoints_buf, "%d", value_in_entry);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1898", "value_in_entry", checkpoints_buf);
  buf_to_write = (uint8 *)((void *)0);



  fip = TIFFFindField(tif, (uint32 )tag, (TIFFDataType )0);



  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1901", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1901", "0", checkpoints_buf);
  if ((tif->tif_flags & 2048U) != 0U) {

    TIFFErrorExt(tif->tif_clientdata, module___18,
                 "Memory mapped files not currently supported for this operation.");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1903", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 2048);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1901", "2048", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1901", "0", checkpoints_buf);

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1905", "0", checkpoints_buf);
  if (tif->tif_diroff == 0ULL) {

    TIFFErrorExt(tif->tif_clientdata, module___18,
                 "Attempt to reset field on directory not already on disk.");

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1907", "0", checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1905", "0", checkpoints_buf);


  tmp = (*(tif->tif_seekproc))(tif->tif_clientdata, tif->tif_diroff, 0);




  if (tmp == tif->tif_diroff) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, module___18,
                 "%s: Seek error accessing TIFF directory", tif->tif_name);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1913", "0", checkpoints_buf);
    return (0);
  }


  read_offset = tif->tif_diroff;


  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1915", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {


    tmp___0 = (*(tif->tif_readproc))(tif->tif_clientdata, (void *)(& dircount),
                                     (tmsize_t )sizeof(uint16 ));


    if ((unsigned long )tmp___0 == (unsigned long )sizeof(uint16 )) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___18,
                   "%s: Can not read TIFF directory count", tif->tif_name);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1920", "0", checkpoints_buf);
      return (0);
    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1921", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(& dircount);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1921", "128", checkpoints_buf);
    dirsize = (tmsize_t )12;

    read_offset += 2ULL;

  } else {


    tmp___1 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                     (void *)(& dircount64),
                                     (tmsize_t )sizeof(uint64 ));


    if ((unsigned long )tmp___1 == (unsigned long )sizeof(uint64 )) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___18,
                   "%s: Can not read TIFF directory count", tif->tif_name);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1930", "0", checkpoints_buf);
      return (0);
    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1931", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(& dircount64);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1931", "128", checkpoints_buf);
    dircount = (uint16 )dircount64;

    dirsize = (tmsize_t )20;

    read_offset += 8ULL;

  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1915", "524288", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1937", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1937", "128", checkpoints_buf);

  while (1) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1938", "0", checkpoints_buf);
    if ((int )dircount > 0) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1938", "0", checkpoints_buf);


    tmp___2 = (*(tif->tif_readproc))(tif->tif_clientdata,
                                     (void *)(direntry_raw), dirsize);




    if (tmp___2 == dirsize) {

    } else {

      TIFFErrorExt(tif->tif_clientdata, module___18,
                   "%s: Can not read TIFF directory entry.", tif->tif_name);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1945", "0", checkpoints_buf);
      return (0);
    }



    memcpy((void */* __restrict  */)(& entry_tag),
           (void const   */* __restrict  */)(direntry_raw + 0), sizeof(uint16 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1947", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabShort(& entry_tag);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1947", "128", checkpoints_buf);
    if ((int )entry_tag == (int )tag) {
      break;
    } else {

    }
    read_offset += (uint64 )dirsize;

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1937", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1937", "128", checkpoints_buf);

  if ((int )entry_tag != (int )tag) {

    TIFFErrorExt(tif->tif_clientdata, module___18, "%s: Could not find tag %d.",
                 tif->tif_name, (int )tag);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1956", "0", checkpoints_buf);
    return (0);
  } else {

  }

  memcpy((void */* __restrict  */)(& entry_type),
         (void const   */* __restrict  */)(direntry_raw + 2), sizeof(uint16 ));


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1959", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabShort(& entry_type);

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1959", "128", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1962", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {

    memcpy((void */* __restrict  */)(& value),
           (void const   */* __restrict  */)(direntry_raw + 4), sizeof(uint32 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1964", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& value);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1964", "128", checkpoints_buf);
    entry_count = (uint64 )value;


    memcpy((void */* __restrict  */)(& value),
           (void const   */* __restrict  */)(direntry_raw + 8), sizeof(uint32 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1969", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong(& value);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1969", "128", checkpoints_buf);
    entry_offset = (uint64 )value;

  } else {

    memcpy((void */* __restrict  */)(& entry_count),
           (void const   */* __restrict  */)(direntry_raw + 4), sizeof(uint64 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1974", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(& entry_count);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1974", "128", checkpoints_buf);

    memcpy((void */* __restrict  */)(& entry_offset),
           (void const   */* __restrict  */)(direntry_raw + 12), sizeof(uint64 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1978", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8(& entry_offset);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1978", "128", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1962", "524288", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1981", "tmp___3", checkpoints_buf);

  tmp___3 = TIFFDataWidth(in_datatype);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1981", "tmp___3", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1982", "tmp___3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1982", "8", checkpoints_buf);
  if (tmp___3 == 8) {

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1983", "524288", checkpoints_buf);
    if (! (tif->tif_flags & 524288U)) {
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1984", "16", checkpoints_buf);
      if ((unsigned int )in_datatype == 16U) {
        datatype = (TIFFDataType )4;

      } else {
        sprintf(checkpoints_buf, "%u", 17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1986", "17", checkpoints_buf);
        if ((unsigned int )in_datatype == 17U) {
          datatype = (TIFFDataType )9;

        } else {
          sprintf(checkpoints_buf, "%u", 18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "1988", "18", checkpoints_buf);
          if ((unsigned int )in_datatype == 18U) {
            datatype = (TIFFDataType )13;

          } else {
            datatype = in_datatype;

          }
          sprintf(checkpoints_buf, "%u", 18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "1988", "18", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 17);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "1986", "17", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "1984", "16", checkpoints_buf);
    } else {
      datatype = in_datatype;

    }

    sprintf(checkpoints_buf, "%u", 524288);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1983", "524288", checkpoints_buf);
  } else {
    datatype = in_datatype;

  }
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1982", "tmp___3", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1982", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1993", "tmp___4", checkpoints_buf);

  tmp___4 = TIFFDataWidth(datatype);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "1993", "tmp___4", checkpoints_buf);



  tmp___5 = _TIFFCheckMalloc(tif, count, (tmsize_t )tmp___4, "for field buffer.");


  buf_to_write = (uint8 *)tmp___5;


  if (! buf_to_write) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "1997", "0", checkpoints_buf);
    return (0);
  } else {

  }

  if ((unsigned int )datatype == (unsigned int )in_datatype) {
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2000", "tmp___6", checkpoints_buf);

    tmp___6 = TIFFDataWidth(datatype);
    sprintf(checkpoints_buf, "%d", tmp___6);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2000", "tmp___6", checkpoints_buf);


    memcpy((void */* __restrict  */)buf_to_write,
           (void const   */* __restrict  */)data,
           (size_t )(count * (tmsize_t )tmp___6));

  } else {
    sprintf(checkpoints_buf, "%u", 9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2002", "9", checkpoints_buf);
    if ((unsigned int )datatype == 9U) {
      sprintf(checkpoints_buf, "%u", 17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2003", "17", checkpoints_buf);
      if ((unsigned int )in_datatype == 17U) {
        i = (tmsize_t )0;






        while (i < count) {


          *((int32 *)buf_to_write + i) = (int32 )*((int64 *)data + i);


          if ((int64 )*((int32 *)buf_to_write + i) != *((int64 *)data + i)) {

            _TIFFfree((void *)buf_to_write);


            TIFFErrorExt(tif->tif_clientdata, module___18,
                         "Value exceeds 32bit range of output type.");

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                            "2013", "0", checkpoints_buf);
            return (0);
          } else {

          }

          i ++;

        }





      } else {
        goto _L___1;
      }
      sprintf(checkpoints_buf, "%u", 17);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2003", "17", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2017", "4", checkpoints_buf);
      _L___1: /* CIL Label */ 
      if ((unsigned int )datatype == 4U) {
        sprintf(checkpoints_buf, "%u", 16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2018", "16", checkpoints_buf);
        if ((unsigned int )in_datatype == 16U) {
          goto _L;
        } else {
          goto _L___0;
        }
        sprintf(checkpoints_buf, "%u", 16);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2018", "16", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%u", 13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2021", "13", checkpoints_buf);
        _L___0: /* CIL Label */ 
        if ((unsigned int )datatype == 13U) {
          sprintf(checkpoints_buf, "%u", 18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2022", "18", checkpoints_buf);
          if ((unsigned int )in_datatype == 18U) {
            _L: /* CIL Label */ 
            i___0 = (tmsize_t )0;






            while (i___0 < count) {


              *((uint32 *)buf_to_write + i___0) = (uint32 )*((uint64 *)data + i___0);


              if ((uint64 )*((uint32 *)buf_to_write + i___0) != *((uint64 *)data + i___0)) {

                _TIFFfree((void *)buf_to_write);


                TIFFErrorExt(tif->tif_clientdata, module___18,
                             "Value exceeds 32bit range of output type.");

                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                                "2032", "0", checkpoints_buf);
                return (0);
              } else {

              }

              i___0 ++;

            }





          } else {

          }
          sprintf(checkpoints_buf, "%u", 18);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2022", "18", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%u", 13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2021", "13", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2017", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 9);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2002", "9", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2037", "tmp___10", checkpoints_buf);

  tmp___10 = TIFFDataWidth(datatype);
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2037", "tmp___10", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2038", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2038", "1", checkpoints_buf);
  if (tmp___10 > 1) {

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2039", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2040", "tmp___9", checkpoints_buf);

      tmp___9 = TIFFDataWidth(datatype);
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2040", "tmp___9", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2041", "tmp___9", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2041", "2", checkpoints_buf);
      if (tmp___9 == 2) {

        TIFFSwabArrayOfShort((uint16 *)buf_to_write, count);

      } else {
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2043", "tmp___8", checkpoints_buf);

        tmp___8 = TIFFDataWidth(datatype);
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2043", "tmp___8", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2044", "tmp___8", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2044", "4", checkpoints_buf);
        if (tmp___8 == 4) {

          TIFFSwabArrayOfLong((uint32 *)buf_to_write, count);

        } else {
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2046", "tmp___7", checkpoints_buf);

          tmp___7 = TIFFDataWidth(datatype);
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2046", "tmp___7", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2047", "tmp___7", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2047", "8", checkpoints_buf);
          if (tmp___7 == 8) {

            TIFFSwabArrayOfLong8((uint64 *)buf_to_write, count);

          } else {

          }
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2047", "tmp___7", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 8);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                          "2047", "8", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2044", "tmp___8", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2044", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2041", "tmp___9", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2041", "2", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2039", "128", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2038", "tmp___10", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2038", "1", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2052", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2053", "tmp___11", checkpoints_buf);

    tmp___11 = TIFFDataWidth(datatype);
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2053", "tmp___11", checkpoints_buf);


    sprintf(checkpoints_buf, "%ld", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2054", "4", checkpoints_buf);
    if ((tmsize_t )tmp___11 * count <= 4L) {
      entry_offset = read_offset + 8ULL;

      value_in_entry = 1;
      sprintf(checkpoints_buf, "%d", value_in_entry);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2056", "value_in_entry", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%ld", 4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2054", "4", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2058", "tmp___12", checkpoints_buf);

    tmp___12 = TIFFDataWidth(datatype);
    sprintf(checkpoints_buf, "%d", tmp___12);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2058", "tmp___12", checkpoints_buf);


    sprintf(checkpoints_buf, "%ld", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2059", "8", checkpoints_buf);
    if ((tmsize_t )tmp___12 * count <= 8L) {
      entry_offset = read_offset + 12ULL;

      value_in_entry = 1;
      sprintf(checkpoints_buf, "%d", value_in_entry);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2061", "value_in_entry", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%ld", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2059", "8", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2052", "524288", checkpoints_buf);

  if (entry_count == (uint64 )count) {
    if ((int )entry_type == (int )((uint16 )datatype)) {


      tmp___13 = (*(tif->tif_seekproc))(tif->tif_clientdata, entry_offset, 0);




      if (tmp___13 == entry_offset) {

      } else {

        _TIFFfree((void *)buf_to_write);


        TIFFErrorExt(tif->tif_clientdata, module___18,
                     "%s: Seek error accessing TIFF directory", tif->tif_name);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2070", "0", checkpoints_buf);
        return (0);
      }


      sprintf(checkpoints_buf, "%d", tmp___14);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2071", "tmp___14", checkpoints_buf);

      tmp___14 = TIFFDataWidth(datatype);
      sprintf(checkpoints_buf, "%d", tmp___14);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2071", "tmp___14", checkpoints_buf);



      tmp___15 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                         (void *)buf_to_write,
                                         count * (tmsize_t )tmp___14);


      sprintf(checkpoints_buf, "%d", tmp___16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2073", "tmp___16", checkpoints_buf);

      tmp___16 = TIFFDataWidth(datatype);
      sprintf(checkpoints_buf, "%d", tmp___16);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2073", "tmp___16", checkpoints_buf);



      if (tmp___15 == count * (tmsize_t )tmp___16) {

      } else {

        _TIFFfree((void *)buf_to_write);


        TIFFErrorExt(tif->tif_clientdata, module___18,
                     "Error writing directory link");

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                        "2078", "0", checkpoints_buf);
        return (0);
      }



      _TIFFfree((void *)buf_to_write);

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2080", "1", checkpoints_buf);
      return (1);
    } else {

    }
  } else {

  }

  sprintf(checkpoints_buf, "%d", value_in_entry);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2083", "value_in_entry", checkpoints_buf);
  if (! value_in_entry) {


    entry_offset = (*(tif->tif_seekproc))(tif->tif_clientdata, (toff_t )0, 2);


    sprintf(checkpoints_buf, "%d", tmp___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2085", "tmp___17", checkpoints_buf);

    tmp___17 = TIFFDataWidth(datatype);
    sprintf(checkpoints_buf, "%d", tmp___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2085", "tmp___17", checkpoints_buf);



    tmp___18 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                       (void *)buf_to_write,
                                       count * (tmsize_t )tmp___17);


    sprintf(checkpoints_buf, "%d", tmp___19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2087", "tmp___19", checkpoints_buf);

    tmp___19 = TIFFDataWidth(datatype);
    sprintf(checkpoints_buf, "%d", tmp___19);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2087", "tmp___19", checkpoints_buf);



    if (tmp___18 == count * (tmsize_t )tmp___19) {

    } else {

      _TIFFfree((void *)buf_to_write);


      TIFFErrorExt(tif->tif_clientdata, module___18,
                   "Error writing directory link");

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                      "2092", "0", checkpoints_buf);
      return (0);
    }



    _TIFFfree((void *)buf_to_write);

  } else {
    sprintf(checkpoints_buf, "%d", tmp___20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2094", "tmp___20", checkpoints_buf);

    tmp___20 = TIFFDataWidth(datatype);
    sprintf(checkpoints_buf, "%d", tmp___20);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2094", "tmp___20", checkpoints_buf);


    memcpy((void */* __restrict  */)(& entry_offset),
           (void const   */* __restrict  */)buf_to_write,
           (size_t )(count * (tmsize_t )tmp___20));

  }
  sprintf(checkpoints_buf, "%d", value_in_entry);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2083", "value_in_entry", checkpoints_buf);
  entry_type = (uint16 )datatype;


  memcpy((void */* __restrict  */)(direntry_raw + 2),
         (void const   */* __restrict  */)(& entry_type), sizeof(uint16 ));


  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2098", "128", checkpoints_buf);
  if (tif->tif_flags & 128U) {

    TIFFSwabShort((uint16 *)(direntry_raw + 2));

  } else {

  }

  sprintf(checkpoints_buf, "%u", 128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2098", "128", checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2101", "524288", checkpoints_buf);
  if (! (tif->tif_flags & 524288U)) {
    value___0 = (uint32 )entry_count;


    memcpy((void */* __restrict  */)(direntry_raw + 4),
           (void const   */* __restrict  */)(& value___0), sizeof(uint32 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2104", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)(direntry_raw + 4));

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2104", "128", checkpoints_buf);
    value___0 = (uint32 )entry_offset;


    memcpy((void */* __restrict  */)(direntry_raw + 8),
           (void const   */* __restrict  */)(& value___0), sizeof(uint32 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2109", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong((uint32 *)(direntry_raw + 8));

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2109", "128", checkpoints_buf);
  } else {

    memcpy((void */* __restrict  */)(direntry_raw + 4),
           (void const   */* __restrict  */)(& entry_count), sizeof(uint64 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2113", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)(direntry_raw + 4));

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2113", "128", checkpoints_buf);

    memcpy((void */* __restrict  */)(direntry_raw + 12),
           (void const   */* __restrict  */)(& entry_offset), sizeof(uint64 ));


    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2117", "128", checkpoints_buf);
    if (tif->tif_flags & 128U) {

      TIFFSwabLong8((uint64 *)(direntry_raw + 12));

    } else {

    }

    sprintf(checkpoints_buf, "%u", 128);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2117", "128", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 524288);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2101", "524288", checkpoints_buf);


  tmp___21 = (*(tif->tif_seekproc))(tif->tif_clientdata, read_offset, 0);




  if (tmp___21 == read_offset) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, module___18,
                 "%s: Seek error accessing TIFF directory", tif->tif_name);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2124", "0", checkpoints_buf);
    return (0);
  }




  tmp___22 = (*(tif->tif_writeproc))(tif->tif_clientdata,
                                     (void *)(direntry_raw), dirsize);




  if (tmp___22 == dirsize) {

  } else {

    TIFFErrorExt(tif->tif_clientdata, module___18,
                 "%s: Can not write TIFF directory entry.", tif->tif_name);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                    "2129", "0", checkpoints_buf);
    return (0);
  }


  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2008-12-30-362dee5-565eaa2",
                  "2130", "1", checkpoints_buf);
  return (1);
}
}