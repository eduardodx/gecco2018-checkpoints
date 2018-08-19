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
typedef long long int64;
typedef unsigned long long uint64;
typedef int uint16_vap;
struct __anonstruct_TIFFHeaderCommon_30 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
};
typedef struct __anonstruct_TIFFHeaderCommon_30 TIFFHeaderCommon;
struct __anonstruct_TIFFHeaderClassic_31 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint32 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderClassic_31 TIFFHeaderClassic;
struct __anonstruct_TIFFHeaderBig_32 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint16 tiff_offsetsize ;
   uint16 tiff_unused ;
   uint64 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderBig_32 TIFFHeaderBig;
enum __anonenum_TIFFDataType_33 {
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
typedef enum __anonenum_TIFFDataType_33 TIFFDataType;
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
struct __anonstruct_TIFFDisplay_34 {
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
typedef struct __anonstruct_TIFFDisplay_34 TIFFDisplay;
struct __anonstruct_TIFFYCbCrToRGB_35 {
   TIFFRGBValue *clamptab ;
   int *Cr_r_tab ;
   int *Cb_b_tab ;
   int32 *Cr_g_tab ;
   int32 *Cb_g_tab ;
   int32 *Y_tab ;
};
typedef struct __anonstruct_TIFFYCbCrToRGB_35 TIFFYCbCrToRGB;
struct __anonstruct_TIFFCIELabToRGB_36 {
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
typedef struct __anonstruct_TIFFCIELabToRGB_36 TIFFCIELabToRGB;
struct _TIFFRGBAImage;
typedef struct _TIFFRGBAImage TIFFRGBAImage;
typedef void (*tileContigRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                  uint32  , uint32  , uint32  , int32  ,
                                  int32  , unsigned char * );
typedef void (*tileSeparateRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                    uint32  , uint32  , uint32  , int32  ,
                                    int32  , unsigned char * , unsigned char * ,
                                    unsigned char * , unsigned char * );
union __anonunion_put_37 {
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
   union __anonunion_put_37 put ;
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
struct __anonstruct_TIFFCodec_38 {
   char *name ;
   uint16 scheme ;
   int (*init)(TIFF * , int  ) ;
};
typedef struct __anonstruct_TIFFCodec_38 TIFFCodec;
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
struct __anonstruct_TIFFTagMethods_39 {
   int (*vsetfield)(TIFF * , uint32  , va_list  ) ;
   int (*vgetfield)(TIFF * , uint32  , va_list  ) ;
   void (*printdir)(TIFF * , FILE * , long  ) ;
};
typedef struct __anonstruct_TIFFTagMethods_39 TIFFTagMethods;
struct __anonstruct_TIFFFieldInfo_40 {
   ttag_t field_tag ;
   short field_readcount ;
   short field_writecount ;
   TIFFDataType field_type ;
   unsigned short field_bit ;
   unsigned char field_oktochange ;
   unsigned char field_passcount ;
   char *field_name ;
};
typedef struct __anonstruct_TIFFFieldInfo_40 TIFFFieldInfo;
struct cpTag {
   uint16 tag ;
   uint16 count ;
   TIFFDataType type ;
};
typedef int (*copyFunc)(TIFF *in , TIFF *out , uint32 l , uint32 w ,
                        uint16 samplesperpixel );
typedef int (*readFunc)(TIFF * , uint8 * , uint32  , uint32  , tsample_t  );
typedef int (*writeFunc)(TIFF * , uint8 * , uint32  , uint32  , tsample_t  );
typedef void biasFn(void *image , void *bias , uint32 pixels );
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
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "251", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "251", "-128", checkpoints_buf);
  if (__c >= -128) {
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "252", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "252", "256", checkpoints_buf);
    if (__c < 256) {


      tmp = __ctype_tolower_loc();


      tmp___0 = *(*tmp + __c);

    } else {
      tmp___0 = (__int32_t const   )__c;

    }
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "252", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "252", "256", checkpoints_buf);
  } else {
    tmp___0 = (__int32_t const   )__c;

  }
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "251", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
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
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "258", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "258", "-128", checkpoints_buf);
  if (__c >= -128) {
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "259", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "259", "256", checkpoints_buf);
    if (__c < 256) {


      tmp = __ctype_toupper_loc();


      tmp___0 = *(*tmp + __c);

    } else {
      tmp___0 = (__int32_t const   )__c;

    }
    sprintf(checkpoints_buf, "%d", __c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "259", "__c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 256);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "259", "256", checkpoints_buf);
  } else {
    tmp___0 = (__int32_t const   )__c;

  }
  sprintf(checkpoints_buf, "%d", __c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "258", "__c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -128);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
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
                            toff_t (*)(thandle_t  , toff_t  , int  ) ,
                            int (*)(thandle_t  ) , toff_t (*)(thandle_t  ) ,
                            int (*)(thandle_t  , void **base , toff_t *size ) ,
                            void (*)(thandle_t  , void *base , toff_t size ) ) ;
extern char const   *TIFFFileName(TIFF * ) ;
extern char const   *TIFFSetFileName(TIFF * , char const   * ) ;
extern void ( /* format attribute */  TIFFError)(char const   * ,
                                                 char const   *  , ...) ;
extern void ( /* format attribute */  TIFFErrorExt)(thandle_t  ,
                                                    char const   * ,
                                                    char const   *  , ...) ;
extern void ( /* format attribute */  TIFFWarning)(char const   * ,
                                                   char const   *  , ...) ;
extern void ( /* format attribute */  TIFFWarningExt)(thandle_t  ,
                                                      char const   * ,
                                                      char const   *  , ...) ;
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
static int outtiled  =    -1;
static uint32 tilewidth  ;
static uint32 tilelength  ;
static uint16 config  ;
static uint16 compression  ;
static uint16 predictor  ;
static uint16 fillorder  ;
static uint16 orientation  ;
static uint32 rowsperstrip  ;
static uint32 g3opts  ;
static int ignore  =    0;
static uint32 defg3opts  =    (uint32 )-1;
static int quality  =    75;
static int jpegcolormode  =    1;
static uint16 defcompression  =    (uint16 )-1;
static uint16 defpredictor  =    (uint16 )-1;
static int tiffcp(TIFF *in , TIFF *out ) ;
static int processCompressOptions(char *opt ) ;
static void usage(void) ;
static char comma  =    (char )',';
static TIFF *bias  =    (TIFF *)((void *)0);
static int pageNum  =    0;
static int nextSrcImage(TIFF *tif , char **imageSpec ) 
{ 
  char *start ;
  tdir_t nextImage ;
  long tmp ;
  char const   *tmp___0 ;
  int tmp___1 ;
  char const   *tmp___2 ;

  {
  if ((int )*(*imageSpec) == (int )comma) {
    start = *imageSpec + 1;

    sprintf(checkpoints_buf, "%ld", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "267", "tmp", checkpoints_buf);

    tmp = strtol((char const   */* __restrict  */)start,
                 (char **/* __restrict  */)imageSpec, 0);
    sprintf(checkpoints_buf, "%ld", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "267", "tmp", checkpoints_buf);

    nextImage = (tdir_t )tmp;

    if ((unsigned int )start == (unsigned int )*imageSpec) {


      nextImage = TIFFCurrentDirectory(tif);


    } else {

    }

    if (*(*imageSpec)) {
      if ((int )*(*imageSpec) == (int )comma) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "274", "0", checkpoints_buf);
        if ((int )*(*imageSpec + 1) == 0) {
          *imageSpec = (char *)((void *)0);

        } else {

        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "274", "0", checkpoints_buf);
      } else {


        tmp___0 = TIFFFileName(tif);



        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"Expected a %c separated image # list after %s\n",
                (int )comma, tmp___0);


        exit(-4);

      }
    } else {

    }

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "281", "tmp___1", checkpoints_buf);

    tmp___1 = TIFFSetDirectory(tif, nextImage);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "281", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "282", "tmp___1", checkpoints_buf);
    if (tmp___1) {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "283", "1", checkpoints_buf);
      return (1);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "282", "tmp___1", checkpoints_buf);


    tmp___2 = TIFFFileName(tif);



    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s%c%d not found!\n", tmp___2,
            (int )comma, (int )nextImage);

  } else {

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "288", "0", checkpoints_buf);
  return (0);
}
}
static TIFF *openSrcImage(char **imageSpec ) 
{ 
  TIFF *tif ;
  char *fn ;
  void *tmp ;
  char *tmp___0 ;
  int tmp___1 ;

  {
  fn = *imageSpec;



  tmp___0 = __builtin_strchr(fn, (int )comma);


  *imageSpec = tmp___0;


  if (*imageSpec) {
    *(*imageSpec) = (char )'\000';



    tif = TIFFOpen((char const   *)fn, "r");



    if (! *(*imageSpec + 1)) {
      *imageSpec = (char *)((void *)0);


      return (tif);
    } else {

    }


    if (tif) {
      *(*imageSpec) = comma;

      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "301", "tmp___1", checkpoints_buf);

      tmp___1 = nextSrcImage(tif, imageSpec);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "301", "tmp___1", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "302", "tmp___1", checkpoints_buf);
      if (tmp___1) {

      } else {

        TIFFClose(tif);

        tif = (TIFF *)((void *)0);

      }
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "302", "tmp___1", checkpoints_buf);
    } else {

    }

  } else {


    tif = TIFFOpen((char const   *)fn, "r");


  }


  return (tif);
}
}
int main(int argc , char **argv ) 
{ 
  uint16 defconfig ;
  uint16 deffillorder ;
  uint32 deftilewidth ;
  uint32 deftilelength ;
  uint32 defrowsperstrip ;
  uint64 diroff ;
  TIFF *in ;
  TIFF *out ;
  char mode[10] ;
  char *mp ;
  int c ;
  char *tmp ;
  uint16 samples ;
  char **biasFn ;
  int tmp___0 ;
  int tmp___1 ;
  size_t __s1_len ;
  size_t __s2_len ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  unsigned char const   *__s2 ;
  register int __result ;
  int tmp___5 ;
  unsigned char const   *__s1 ;
  register int __result___0 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
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
  int tmp___16 ;
  unsigned long tmp___17 ;
  size_t __s1_len___1 ;
  size_t __s2_len___1 ;
  int tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  unsigned char const   *__s2___1 ;
  register int __result___3 ;
  int tmp___21 ;
  unsigned char const   *__s1___1 ;
  register int __result___4 ;
  int tmp___22 ;
  int tmp___23 ;
  int tmp___24 ;
  size_t __s1_len___2 ;
  size_t __s2_len___2 ;
  int tmp___25 ;
  int tmp___26 ;
  int tmp___27 ;
  unsigned char const   *__s2___2 ;
  register int __result___5 ;
  int tmp___28 ;
  unsigned char const   *__s1___2 ;
  register int __result___6 ;
  int tmp___29 ;
  int tmp___30 ;
  int tmp___31 ;
  long tmp___32 ;
  int tmp___33 ;
  char *tmp___34 ;
  char *tmp___35 ;
  char *tmp___36 ;
  char *tmp___37 ;
  char *tmp___38 ;
  char *imageCursor ;
  char const   *tmp___39 ;
  int tmp___40 ;
  int tmp___41 ;
  int tmp___42 ;
  int tmp___43 ;
  int tmp___44 ;

  {
  defconfig = (uint16 )-1;

  deffillorder = (uint16 )0;

  deftilewidth = (uint32 )-1;

  deftilelength = (uint32 )-1;

  defrowsperstrip = (uint32 )0;

  diroff = (uint64 )0;

  mp = mode;

  tmp = mp;

  mp ++;

  *tmp = (char )'w';

  *mp = (char )'\000';

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "320", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "320", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "320", "-1", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "321", "c", checkpoints_buf);

    c = getopt(argc, (char * const  *)argv, ",:b:c:f:l:o:z:p:r:w:aistBLMC8");
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "321", "c", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "322", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "322", "-1", checkpoints_buf);
    if (c != -1) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "322", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "322", "-1", checkpoints_buf);
    switch (c) {
    sprintf(checkpoints_buf, "%d", 61);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "326", "61", checkpoints_buf);
    case 44: 
    if ((int )*(optarg + 0) != 61) {

      usage();

    } else {

    }
    sprintf(checkpoints_buf, "%d", 61);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "326", "61", checkpoints_buf);
    comma = *(optarg + 1);
    sprintf(checkpoints_buf, "%c", comma);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "329", "comma", checkpoints_buf);
    break;

    case 98: 
    if (bias) {

      fputs((char const   */* __restrict  */)"Only 1 bias image may be specified\n",
            (FILE */* __restrict  */)stderr);


      exit(-2);

    } else {

    }

    samples = (uint16 )-1;

    biasFn = & optarg;



    bias = openSrcImage(biasFn);



    if (! bias) {

      exit(-5);

    } else {

    }

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "341", "tmp___0", checkpoints_buf);

    tmp___0 = TIFFIsTiled(bias);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "341", "tmp___0", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "342", "tmp___0", checkpoints_buf);
    if (tmp___0) {

      fputs((char const   */* __restrict  */)"Bias image must be organized in strips\n",
            (FILE */* __restrict  */)stderr);


      exit(-7);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "342", "tmp___0", checkpoints_buf);

    TIFFGetField(bias, (uint32 )277, & samples);

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "347", "1", checkpoints_buf);
    if ((int )samples != 1) {

      fputs((char const   */* __restrict  */)"Bias image must be monochrome\n",
            (FILE */* __restrict  */)stderr);


      exit(-7);

    } else {

    }
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "347", "1", checkpoints_buf);
    break;
    case 97: 
    mode[0] = (char )'a';

    break;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "354", "tmp___1", checkpoints_buf);

    case 99: 
    tmp___1 = processCompressOptions(optarg);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "354", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "355", "tmp___1", checkpoints_buf);
    if (tmp___1) {

    } else {

      usage();

    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "355", "tmp___1", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "359", "0", checkpoints_buf);
    case 102: 
    if (0) {


      __s1_len___0 = strlen((char const   *)optarg);




      __s2_len___0 = strlen("lsb2msb");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "362", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
        goto _L___2;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "364", "4", checkpoints_buf);
        if (__s1_len___0 >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "365", "1", checkpoints_buf);
          _L___2: /* CIL Label */ 
          if (! ((size_t )((void const   *)("lsb2msb" + 1)) - (size_t )((void const   *)"lsb2msb") == 1U)) {
            tmp___15 = 1;
            sprintf(checkpoints_buf, "%d", tmp___15);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "366", "tmp___15", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "367", "4", checkpoints_buf);
            if (__s2_len___0 >= 4U) {
              tmp___15 = 1;
              sprintf(checkpoints_buf, "%d", tmp___15);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "368", "tmp___15", checkpoints_buf);
            } else {
              tmp___15 = 0;
              sprintf(checkpoints_buf, "%d", tmp___15);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "369", "tmp___15", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "367", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "365", "1", checkpoints_buf);
        } else {
          tmp___15 = 0;
          sprintf(checkpoints_buf, "%d", tmp___15);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "370", "tmp___15", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "364", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "362", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___15);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "371", "tmp___15", checkpoints_buf);
      if (tmp___15) {
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "372", "tmp___10", checkpoints_buf);

        tmp___10 = __builtin_strcmp((char const   *)optarg, "lsb2msb");
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "372", "tmp___10", checkpoints_buf);

        tmp___14 = tmp___10;
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "373", "tmp___14", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "374", "tmp___13", checkpoints_buf);

        tmp___13 = __builtin_strcmp((char const   *)optarg, "lsb2msb");
        sprintf(checkpoints_buf, "%d", tmp___13);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "374", "tmp___13", checkpoints_buf);

        tmp___14 = tmp___13;
        sprintf(checkpoints_buf, "%d", tmp___14);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "375", "tmp___14", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___15);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "371", "tmp___15", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___13);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "376", "tmp___13", checkpoints_buf);

      tmp___13 = __builtin_strcmp((char const   *)optarg, "lsb2msb");
      sprintf(checkpoints_buf, "%d", tmp___13);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "376", "tmp___13", checkpoints_buf);

      tmp___14 = tmp___13;
      sprintf(checkpoints_buf, "%d", tmp___14);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "377", "tmp___14", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "359", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___14);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "378", "tmp___14", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "378", "0", checkpoints_buf);
    if (tmp___14 == 0) {
      deffillorder = (uint16 )2;

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "380", "0", checkpoints_buf);
      if (0) {


        __s1_len = strlen((char const   *)optarg);




        __s2_len = strlen("msb2lsb");


        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "383", "1", checkpoints_buf);
        if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
          goto _L___0;
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "385", "4", checkpoints_buf);
          if (__s1_len >= 4U) {
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "386", "1", checkpoints_buf);
            _L___0: /* CIL Label */ 
            if (! ((size_t )((void const   *)("msb2lsb" + 1)) - (size_t )((void const   *)"msb2lsb") == 1U)) {
              tmp___8 = 1;
              sprintf(checkpoints_buf, "%d", tmp___8);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "387", "tmp___8", checkpoints_buf);
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "388", "4", checkpoints_buf);
              if (__s2_len >= 4U) {
                tmp___8 = 1;
                sprintf(checkpoints_buf, "%d", tmp___8);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "389", "tmp___8", checkpoints_buf);
              } else {
                tmp___8 = 0;
                sprintf(checkpoints_buf, "%d", tmp___8);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "390", "tmp___8", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "388", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "386", "1", checkpoints_buf);
          } else {
            tmp___8 = 0;
            sprintf(checkpoints_buf, "%d", tmp___8);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "391", "tmp___8", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "385", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "383", "1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "392", "tmp___8", checkpoints_buf);
        if (tmp___8) {
          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "393", "tmp___3", checkpoints_buf);

          tmp___3 = __builtin_strcmp((char const   *)optarg, "msb2lsb");
          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "393", "tmp___3", checkpoints_buf);

          tmp___7 = tmp___3;
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "394", "tmp___7", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___6);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "395", "tmp___6", checkpoints_buf);

          tmp___6 = __builtin_strcmp((char const   *)optarg, "msb2lsb");
          sprintf(checkpoints_buf, "%d", tmp___6);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "395", "tmp___6", checkpoints_buf);

          tmp___7 = tmp___6;
          sprintf(checkpoints_buf, "%d", tmp___7);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "396", "tmp___7", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___8);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "392", "tmp___8", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "397", "tmp___6", checkpoints_buf);

        tmp___6 = __builtin_strcmp((char const   *)optarg, "msb2lsb");
        sprintf(checkpoints_buf, "%d", tmp___6);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "397", "tmp___6", checkpoints_buf);

        tmp___7 = tmp___6;
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "398", "tmp___7", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "380", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "399", "tmp___7", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "399", "0", checkpoints_buf);
      if (tmp___7 == 0) {
        deffillorder = (uint16 )1;

      } else {

        usage();

      }
      sprintf(checkpoints_buf, "%d", tmp___7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "399", "tmp___7", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "399", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___14);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "378", "tmp___14", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "378", "0", checkpoints_buf);
    break;
    case 105: 
    ignore = 1;
    sprintf(checkpoints_buf, "%d", ignore);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "403", "ignore", checkpoints_buf);
    break;
    case 108: 
    outtiled = 1;
    sprintf(checkpoints_buf, "%d", outtiled);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "405", "outtiled", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "406", "tmp___16", checkpoints_buf);

    tmp___16 = atoi((char const   *)optarg);
    sprintf(checkpoints_buf, "%d", tmp___16);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "406", "tmp___16", checkpoints_buf);

    deftilelength = (uint32 )tmp___16;

    break;
    sprintf(checkpoints_buf, "%ul", tmp___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "409", "tmp___17", checkpoints_buf);

    case 111: 
    tmp___17 = strtoul((char const   */* __restrict  */)optarg,
                       (char **/* __restrict  */)((void *)0), 0);
    sprintf(checkpoints_buf, "%ul", tmp___17);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "409", "tmp___17", checkpoints_buf);

    diroff = (uint64 )tmp___17;

    break;
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "412", "0", checkpoints_buf);
    case 112: 
    if (0) {


      __s1_len___2 = strlen((char const   *)optarg);




      __s2_len___2 = strlen("separate");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "415", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
        goto _L___6;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "417", "4", checkpoints_buf);
        if (__s1_len___2 >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "418", "1", checkpoints_buf);
          _L___6: /* CIL Label */ 
          if (! ((size_t )((void const   *)("separate" + 1)) - (size_t )((void const   *)"separate") == 1U)) {
            tmp___31 = 1;
            sprintf(checkpoints_buf, "%d", tmp___31);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "419", "tmp___31", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "420", "4", checkpoints_buf);
            if (__s2_len___2 >= 4U) {
              tmp___31 = 1;
              sprintf(checkpoints_buf, "%d", tmp___31);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "421", "tmp___31", checkpoints_buf);
            } else {
              tmp___31 = 0;
              sprintf(checkpoints_buf, "%d", tmp___31);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "422", "tmp___31", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "420", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "418", "1", checkpoints_buf);
        } else {
          tmp___31 = 0;
          sprintf(checkpoints_buf, "%d", tmp___31);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "423", "tmp___31", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "417", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "415", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___31);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "424", "tmp___31", checkpoints_buf);
      if (tmp___31) {
        sprintf(checkpoints_buf, "%d", tmp___26);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "425", "tmp___26", checkpoints_buf);

        tmp___26 = __builtin_strcmp((char const   *)optarg, "separate");
        sprintf(checkpoints_buf, "%d", tmp___26);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "425", "tmp___26", checkpoints_buf);

        tmp___30 = tmp___26;
        sprintf(checkpoints_buf, "%d", tmp___30);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "426", "tmp___30", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___29);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "427", "tmp___29", checkpoints_buf);

        tmp___29 = __builtin_strcmp((char const   *)optarg, "separate");
        sprintf(checkpoints_buf, "%d", tmp___29);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "427", "tmp___29", checkpoints_buf);

        tmp___30 = tmp___29;
        sprintf(checkpoints_buf, "%d", tmp___30);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "428", "tmp___30", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___31);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "424", "tmp___31", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___29);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "429", "tmp___29", checkpoints_buf);

      tmp___29 = __builtin_strcmp((char const   *)optarg, "separate");
      sprintf(checkpoints_buf, "%d", tmp___29);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "429", "tmp___29", checkpoints_buf);

      tmp___30 = tmp___29;
      sprintf(checkpoints_buf, "%d", tmp___30);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "430", "tmp___30", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "412", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "431", "tmp___30", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "431", "0", checkpoints_buf);
    if (tmp___30 == 0) {
      defconfig = (uint16 )2;

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "433", "0", checkpoints_buf);
      if (0) {


        __s1_len___1 = strlen((char const   *)optarg);




        __s2_len___1 = strlen("contig");


        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "436", "1", checkpoints_buf);
        if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
          goto _L___4;
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "438", "4", checkpoints_buf);
          if (__s1_len___1 >= 4U) {
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "439", "1", checkpoints_buf);
            _L___4: /* CIL Label */ 
            if (! ((size_t )((void const   *)("contig" + 1)) - (size_t )((void const   *)"contig") == 1U)) {
              tmp___24 = 1;
              sprintf(checkpoints_buf, "%d", tmp___24);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "440", "tmp___24", checkpoints_buf);
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "441", "4", checkpoints_buf);
              if (__s2_len___1 >= 4U) {
                tmp___24 = 1;
                sprintf(checkpoints_buf, "%d", tmp___24);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "442", "tmp___24", checkpoints_buf);
              } else {
                tmp___24 = 0;
                sprintf(checkpoints_buf, "%d", tmp___24);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "443", "tmp___24", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "441", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "439", "1", checkpoints_buf);
          } else {
            tmp___24 = 0;
            sprintf(checkpoints_buf, "%d", tmp___24);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "444", "tmp___24", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "438", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "436", "1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___24);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "445", "tmp___24", checkpoints_buf);
        if (tmp___24) {
          sprintf(checkpoints_buf, "%d", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "446", "tmp___19", checkpoints_buf);

          tmp___19 = __builtin_strcmp((char const   *)optarg, "contig");
          sprintf(checkpoints_buf, "%d", tmp___19);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "446", "tmp___19", checkpoints_buf);

          tmp___23 = tmp___19;
          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "447", "tmp___23", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___22);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "448", "tmp___22", checkpoints_buf);

          tmp___22 = __builtin_strcmp((char const   *)optarg, "contig");
          sprintf(checkpoints_buf, "%d", tmp___22);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "448", "tmp___22", checkpoints_buf);

          tmp___23 = tmp___22;
          sprintf(checkpoints_buf, "%d", tmp___23);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "449", "tmp___23", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___24);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "445", "tmp___24", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "450", "tmp___22", checkpoints_buf);

        tmp___22 = __builtin_strcmp((char const   *)optarg, "contig");
        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "450", "tmp___22", checkpoints_buf);

        tmp___23 = tmp___22;
        sprintf(checkpoints_buf, "%d", tmp___23);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "451", "tmp___23", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "433", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___23);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "452", "tmp___23", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "452", "0", checkpoints_buf);
      if (tmp___23 == 0) {
        defconfig = (uint16 )1;

      } else {

        usage();

      }
      sprintf(checkpoints_buf, "%d", tmp___23);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "452", "tmp___23", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "452", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___30);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "431", "tmp___30", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "431", "0", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%ld", tmp___32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "456", "tmp___32", checkpoints_buf);

    case 114: 
    tmp___32 = atol((char const   *)optarg);
    sprintf(checkpoints_buf, "%ld", tmp___32);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "456", "tmp___32", checkpoints_buf);

    defrowsperstrip = (uint32 )tmp___32;

    break;
    case 115: 
    outtiled = 0;
    sprintf(checkpoints_buf, "%d", outtiled);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "459", "outtiled", checkpoints_buf);
    break;
    case 116: 
    outtiled = 1;
    sprintf(checkpoints_buf, "%d", outtiled);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "461", "outtiled", checkpoints_buf);
    break;
    case 119: 
    outtiled = 1;
    sprintf(checkpoints_buf, "%d", outtiled);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "463", "outtiled", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___33);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "464", "tmp___33", checkpoints_buf);

    tmp___33 = atoi((char const   *)optarg);
    sprintf(checkpoints_buf, "%d", tmp___33);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "464", "tmp___33", checkpoints_buf);

    deftilewidth = (uint32 )tmp___33;

    break;
    case 66: 
    tmp___34 = mp;

    mp ++;

    *tmp___34 = (char )'b';

    *mp = (char )'\000';

    break;
    case 76: 
    tmp___35 = mp;

    mp ++;

    *tmp___35 = (char )'l';

    *mp = (char )'\000';

    break;
    case 77: 
    tmp___36 = mp;

    mp ++;

    *tmp___36 = (char )'m';

    *mp = (char )'\000';

    break;
    case 67: 
    tmp___37 = mp;

    mp ++;

    *tmp___37 = (char )'c';

    *mp = (char )'\000';

    break;
    case 56: 
    tmp___38 = mp;

    mp ++;

    *tmp___38 = (char )'8';

    *mp = (char )'\000';

    break;

    case 63: 
    usage();

    }
  }
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "320", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "320", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "320", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "493", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "493", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "493", "2", checkpoints_buf);
  if (argc - optind < 2) {

    usage();

  } else {

  }
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "493", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "493", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "493", "2", checkpoints_buf);


  out = TIFFOpen((char const   *)*(argv + (argc - 1)), (char const   *)(mode));


  if ((unsigned int )out == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", -2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "498", "-2", checkpoints_buf);
    return (-2);
  } else {

  }
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "500", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "500", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "500", "2", checkpoints_buf);
  if (argc - optind == 2) {
    pageNum = -1;
    sprintf(checkpoints_buf, "%d", pageNum);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "501", "pageNum", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "500", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "500", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "500", "2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "1", checkpoints_buf);




  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "0", checkpoints_buf);








  sprintf(checkpoints_buf, "%d", tmp___41);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "tmp___41", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___41);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "tmp___41", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "optind", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "504", "optind", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", argc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "504", "argc", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "504", "1", checkpoints_buf);
    if (optind < argc - 1) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "504", "optind", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", argc);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "504", "argc", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "504", "1", checkpoints_buf);
    imageCursor = *(argv + optind);



    in = openSrcImage(& imageCursor);


    if ((unsigned int )in == (unsigned int )((void *)0)) {
      sprintf(checkpoints_buf, "%d", -3);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "510", "-3", checkpoints_buf);
      return (-3);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "512", "0", checkpoints_buf);
    if (diroff != 0ULL) {
      sprintf(checkpoints_buf, "%d", tmp___40);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "513", "tmp___40", checkpoints_buf);

      tmp___40 = TIFFSetSubDirectory(in, diroff);
      sprintf(checkpoints_buf, "%d", tmp___40);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "513", "tmp___40", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___40);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "514", "tmp___40", checkpoints_buf);
      if (tmp___40) {

      } else {


        tmp___39 = TIFFFileName(in);



        TIFFError(tmp___39, "Error, setting subdirectory at %llu", diroff);


        TIFFClose(out);

        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "519", "1", checkpoints_buf);
        return (1);
      }
      sprintf(checkpoints_buf, "%d", tmp___40);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "514", "tmp___40", checkpoints_buf);
    } else {

    }

    sprintf(checkpoints_buf, "%llu", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "512", "0", checkpoints_buf);








    sprintf(checkpoints_buf, "%d", tmp___41);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "521", "tmp___41", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___41);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "521", "tmp___41", checkpoints_buf);

    while (1) {
      config = defconfig;

      compression = defcompression;

      predictor = defpredictor;

      fillorder = deffillorder;

      rowsperstrip = defrowsperstrip;

      tilewidth = deftilewidth;

      tilelength = deftilelength;

      g3opts = defg3opts;

      sprintf(checkpoints_buf, "%d", tmp___41);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "530", "tmp___41", checkpoints_buf);

      tmp___41 = tiffcp(in, out);
      sprintf(checkpoints_buf, "%d", tmp___41);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "530", "tmp___41", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___41);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "531", "tmp___41", checkpoints_buf);
      if (tmp___41) {
        sprintf(checkpoints_buf, "%d", tmp___42);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "532", "tmp___42", checkpoints_buf);

        tmp___42 = TIFFWriteDirectory(out);
        sprintf(checkpoints_buf, "%d", tmp___42);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "532", "tmp___42", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___42);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "533", "tmp___42", checkpoints_buf);
        if (tmp___42) {

        } else {

          TIFFClose(out);

          sprintf(checkpoints_buf, "%d", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "536", "1", checkpoints_buf);
          return (1);
        }
        sprintf(checkpoints_buf, "%d", tmp___42);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "533", "tmp___42", checkpoints_buf);
      } else {

        TIFFClose(out);

        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "538", "1", checkpoints_buf);
        return (1);
      }
      sprintf(checkpoints_buf, "%d", tmp___41);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "531", "tmp___41", checkpoints_buf);

      if (imageCursor) {
        sprintf(checkpoints_buf, "%d", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "540", "tmp___43", checkpoints_buf);

        tmp___43 = nextSrcImage(in, & imageCursor);
        sprintf(checkpoints_buf, "%d", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "540", "tmp___43", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "541", "tmp___43", checkpoints_buf);
        if (tmp___43) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", tmp___43);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "541", "tmp___43", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___44);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "544", "tmp___44", checkpoints_buf);

        tmp___44 = TIFFReadDirectory(in);
        sprintf(checkpoints_buf, "%d", tmp___44);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "544", "tmp___44", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___44);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "545", "tmp___44", checkpoints_buf);
        if (tmp___44) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", tmp___44);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "545", "tmp___44", checkpoints_buf);
      }

    }








    sprintf(checkpoints_buf, "%d", tmp___41);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "521", "tmp___41", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___41);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "521", "tmp___41", checkpoints_buf);


    TIFFClose(in);

    optind ++;
    sprintf(checkpoints_buf, "%d", optind);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "549", "optind", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "argc", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "1", checkpoints_buf);




  sprintf(checkpoints_buf, "%llu", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "0", checkpoints_buf);








  sprintf(checkpoints_buf, "%d", tmp___41);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "tmp___41", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___41);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "tmp___41", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "503", "optind", checkpoints_buf);

  TIFFClose(out);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "551", "0", checkpoints_buf);
  return (0);
}
}
static void processG3Options(char *cp ) 
{ 
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
  size_t tmp___12 ;
  size_t tmp___13 ;
  size_t __s1_len___0 ;
  size_t __s2_len___0 ;
  int tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  unsigned char const   *__s2___0 ;
  register int __result___1 ;
  int tmp___17 ;
  unsigned char const   *__s1___0 ;
  register int __result___2 ;
  int tmp___18 ;
  int tmp___19 ;
  int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  size_t tmp___23 ;
  size_t tmp___24 ;
  size_t tmp___25 ;
  size_t tmp___26 ;
  size_t __s1_len___1 ;
  size_t __s2_len___1 ;
  int tmp___27 ;
  int tmp___28 ;
  int tmp___29 ;
  unsigned char const   *__s2___1 ;
  register int __result___3 ;
  int tmp___30 ;
  unsigned char const   *__s1___1 ;
  register int __result___4 ;
  int tmp___31 ;
  int tmp___32 ;
  int tmp___33 ;
  int tmp___34 ;
  int tmp___35 ;
  size_t tmp___36 ;
  size_t tmp___37 ;
  void *tmp___38 ;
  char *tmp___39 ;
  void *tmp___40 ;
  char *tmp___41 ;

  {


  tmp___41 = __builtin_strchr(cp, ':');


  cp = tmp___41;


  if (cp) {

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "555", "4294967295", checkpoints_buf);
    if (defg3opts == 4294967295U) {
      defg3opts = (uint32 )0;

    } else {

    }

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "555", "4294967295", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "558", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___35);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "558", "tmp___35", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "558", "0", checkpoints_buf);




    while (1) {
      cp ++;

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "560", "0", checkpoints_buf);
      if (0) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "561", "0", checkpoints_buf);
        if (0) {


          __s1_len___1 = strlen((char const   *)cp);




          __s2_len___1 = strlen("1d");


          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "564", "1", checkpoints_buf);
          if (! ((size_t )((void const   *)(cp + 1)) - (size_t )((void const   *)cp) == 1U)) {
            goto _L___4;
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "566", "4", checkpoints_buf);
            if (__s1_len___1 >= 4U) {
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "567", "1", checkpoints_buf);
              _L___4: /* CIL Label */ 
              if (! ((size_t )((void const   *)("1d" + 1)) - (size_t )((void const   *)"1d") == 1U)) {
                tmp___33 = 1;
                sprintf(checkpoints_buf, "%d", tmp___33);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "568", "tmp___33", checkpoints_buf);
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "569", "4", checkpoints_buf);
                if (__s2_len___1 >= 4U) {
                  tmp___33 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___33);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "570", "tmp___33", checkpoints_buf);
                } else {
                  tmp___33 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___33);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "571", "tmp___33", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "569", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "567", "1", checkpoints_buf);
            } else {
              tmp___33 = 0;
              sprintf(checkpoints_buf, "%d", tmp___33);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "572", "tmp___33", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "566", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "564", "1", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___33);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "573", "tmp___33", checkpoints_buf);
          if (tmp___33) {
            sprintf(checkpoints_buf, "%d", tmp___28);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "574", "tmp___28", checkpoints_buf);

            tmp___28 = __builtin_strcmp((char const   *)cp, "1d");
            sprintf(checkpoints_buf, "%d", tmp___28);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "574", "tmp___28", checkpoints_buf);

            tmp___32 = tmp___28;
            sprintf(checkpoints_buf, "%d", tmp___32);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "575", "tmp___32", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___31);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "576", "tmp___31", checkpoints_buf);

            tmp___31 = __builtin_strcmp((char const   *)cp, "1d");
            sprintf(checkpoints_buf, "%d", tmp___31);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "576", "tmp___31", checkpoints_buf);

            tmp___32 = tmp___31;
            sprintf(checkpoints_buf, "%d", tmp___32);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "577", "tmp___32", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___33);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "573", "tmp___33", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___31);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "578", "tmp___31", checkpoints_buf);

          tmp___31 = __builtin_strcmp((char const   *)cp, "1d");
          sprintf(checkpoints_buf, "%d", tmp___31);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "578", "tmp___31", checkpoints_buf);

          tmp___32 = tmp___31;
          sprintf(checkpoints_buf, "%d", tmp___32);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "579", "tmp___32", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "561", "0", checkpoints_buf);
        tmp___35 = tmp___32;
        sprintf(checkpoints_buf, "%d", tmp___35);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "580", "tmp___35", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___34);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "581", "tmp___34", checkpoints_buf);

        tmp___34 = strncmp((char const   *)cp, "1d", (size_t )2);
        sprintf(checkpoints_buf, "%d", tmp___34);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "581", "tmp___34", checkpoints_buf);

        tmp___35 = tmp___34;
        sprintf(checkpoints_buf, "%d", tmp___35);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "582", "tmp___35", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "560", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___35);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "583", "tmp___35", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "583", "0", checkpoints_buf);
      if (tmp___35 == 0) {
        defg3opts &= 4294967294U;

      } else {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "585", "0", checkpoints_buf);
        if (0) {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "586", "0", checkpoints_buf);
          if (0) {


            __s1_len___0 = strlen((char const   *)cp);




            __s2_len___0 = strlen("2d");


            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "589", "1", checkpoints_buf);
            if (! ((size_t )((void const   *)(cp + 1)) - (size_t )((void const   *)cp) == 1U)) {
              goto _L___2;
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "591", "4", checkpoints_buf);
              if (__s1_len___0 >= 4U) {
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "592", "1", checkpoints_buf);
                _L___2: /* CIL Label */ 
                if (! ((size_t )((void const   *)("2d" + 1)) - (size_t )((void const   *)"2d") == 1U)) {
                  tmp___20 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___20);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "593", "tmp___20", checkpoints_buf);
                } else {

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "594", "4", checkpoints_buf);
                  if (__s2_len___0 >= 4U) {
                    tmp___20 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___20);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "595", "tmp___20", checkpoints_buf);
                  } else {
                    tmp___20 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___20);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "596", "tmp___20", checkpoints_buf);
                  }

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "594", "4", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "592", "1", checkpoints_buf);
              } else {
                tmp___20 = 0;
                sprintf(checkpoints_buf, "%d", tmp___20);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "597", "tmp___20", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "591", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "589", "1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___20);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "598", "tmp___20", checkpoints_buf);
            if (tmp___20) {
              sprintf(checkpoints_buf, "%d", tmp___15);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "599", "tmp___15", checkpoints_buf);

              tmp___15 = __builtin_strcmp((char const   *)cp, "2d");
              sprintf(checkpoints_buf, "%d", tmp___15);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "599", "tmp___15", checkpoints_buf);

              tmp___19 = tmp___15;
              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "600", "tmp___19", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___18);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "601", "tmp___18", checkpoints_buf);

              tmp___18 = __builtin_strcmp((char const   *)cp, "2d");
              sprintf(checkpoints_buf, "%d", tmp___18);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "601", "tmp___18", checkpoints_buf);

              tmp___19 = tmp___18;
              sprintf(checkpoints_buf, "%d", tmp___19);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "602", "tmp___19", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___20);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "598", "tmp___20", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___18);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "603", "tmp___18", checkpoints_buf);

            tmp___18 = __builtin_strcmp((char const   *)cp, "2d");
            sprintf(checkpoints_buf, "%d", tmp___18);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "603", "tmp___18", checkpoints_buf);

            tmp___19 = tmp___18;
            sprintf(checkpoints_buf, "%d", tmp___19);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "604", "tmp___19", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "586", "0", checkpoints_buf);
          tmp___22 = tmp___19;
          sprintf(checkpoints_buf, "%d", tmp___22);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "605", "tmp___22", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___21);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "606", "tmp___21", checkpoints_buf);

          tmp___21 = strncmp((char const   *)cp, "2d", (size_t )2);
          sprintf(checkpoints_buf, "%d", tmp___21);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "606", "tmp___21", checkpoints_buf);

          tmp___22 = tmp___21;
          sprintf(checkpoints_buf, "%d", tmp___22);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "607", "tmp___22", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "585", "0", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "608", "tmp___22", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "608", "0", checkpoints_buf);
        if (tmp___22 == 0) {
          defg3opts |= 1U;

        } else {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "610", "0", checkpoints_buf);
          if (0) {
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "611", "0", checkpoints_buf);
            if (0) {


              __s1_len = strlen((char const   *)cp);




              __s2_len = strlen("fill");


              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "614", "1", checkpoints_buf);
              if (! ((size_t )((void const   *)(cp + 1)) - (size_t )((void const   *)cp) == 1U)) {
                goto _L___0;
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "616", "4", checkpoints_buf);
                if (__s1_len >= 4U) {
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "617", "1", checkpoints_buf);
                  _L___0: /* CIL Label */ 
                  if (! ((size_t )((void const   *)("fill" + 1)) - (size_t )((void const   *)"fill") == 1U)) {
                    tmp___7 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___7);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "618", "tmp___7", checkpoints_buf);
                  } else {

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "619", "4", checkpoints_buf);
                    if (__s2_len >= 4U) {
                      tmp___7 = 1;
                      sprintf(checkpoints_buf, "%d", tmp___7);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "620", "tmp___7", checkpoints_buf);
                    } else {
                      tmp___7 = 0;
                      sprintf(checkpoints_buf, "%d", tmp___7);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "621", "tmp___7", checkpoints_buf);
                    }

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "619", "4", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "617", "1", checkpoints_buf);
                } else {
                  tmp___7 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___7);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "622", "tmp___7", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "616", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "614", "1", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___7);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "623", "tmp___7", checkpoints_buf);
              if (tmp___7) {
                sprintf(checkpoints_buf, "%d", tmp___2);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "624", "tmp___2", checkpoints_buf);

                tmp___2 = __builtin_strcmp((char const   *)cp, "fill");
                sprintf(checkpoints_buf, "%d", tmp___2);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "624", "tmp___2", checkpoints_buf);

                tmp___6 = tmp___2;
                sprintf(checkpoints_buf, "%d", tmp___6);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "625", "tmp___6", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", tmp___5);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "626", "tmp___5", checkpoints_buf);

                tmp___5 = __builtin_strcmp((char const   *)cp, "fill");
                sprintf(checkpoints_buf, "%d", tmp___5);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "626", "tmp___5", checkpoints_buf);

                tmp___6 = tmp___5;
                sprintf(checkpoints_buf, "%d", tmp___6);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "627", "tmp___6", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", tmp___7);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "623", "tmp___7", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "628", "tmp___5", checkpoints_buf);

              tmp___5 = __builtin_strcmp((char const   *)cp, "fill");
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "628", "tmp___5", checkpoints_buf);

              tmp___6 = tmp___5;
              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "629", "tmp___6", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "611", "0", checkpoints_buf);
            tmp___9 = tmp___6;
            sprintf(checkpoints_buf, "%d", tmp___9);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "630", "tmp___9", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___8);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "631", "tmp___8", checkpoints_buf);

            tmp___8 = strncmp((char const   *)cp, "fill", (size_t )4);
            sprintf(checkpoints_buf, "%d", tmp___8);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "631", "tmp___8", checkpoints_buf);

            tmp___9 = tmp___8;
            sprintf(checkpoints_buf, "%d", tmp___9);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "632", "tmp___9", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "610", "0", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "633", "tmp___9", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "633", "0", checkpoints_buf);
          if (tmp___9 == 0) {
            defg3opts |= 4U;

          } else {

            usage();

          }
          sprintf(checkpoints_buf, "%d", tmp___9);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "633", "tmp___9", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "633", "0", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___22);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "608", "tmp___22", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "608", "0", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___35);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "583", "tmp___35", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "583", "0", checkpoints_buf);


      tmp___39 = __builtin_strchr(cp, ':');


      cp = tmp___39;


      if (cp) {

      } else {
        break;
      }

    }

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "558", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___35);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "558", "tmp___35", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "558", "0", checkpoints_buf);




  } else {

  }

  return;
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
  size_t tmp___56 ;
  size_t tmp___57 ;
  size_t __s1_len___3 ;
  size_t __s2_len___3 ;
  int tmp___58 ;
  int tmp___59 ;
  int tmp___60 ;
  unsigned char const   *__s2___3 ;
  register int __result___7 ;
  int tmp___61 ;
  unsigned char const   *__s1___3 ;
  register int __result___8 ;
  int tmp___62 ;
  int tmp___63 ;
  int tmp___64 ;
  int tmp___65 ;
  int tmp___66 ;
  size_t tmp___67 ;
  size_t tmp___68 ;
  size_t tmp___69 ;
  size_t tmp___70 ;
  size_t __s1_len___4 ;
  size_t __s2_len___4 ;
  int tmp___71 ;
  int tmp___72 ;
  int tmp___73 ;
  unsigned char const   *__s2___4 ;
  register int __result___9 ;
  int tmp___74 ;
  unsigned char const   *__s1___4 ;
  register int __result___10 ;
  int tmp___75 ;
  int tmp___76 ;
  int tmp___77 ;
  int tmp___78 ;
  int tmp___79 ;
  size_t tmp___80 ;
  size_t tmp___81 ;
  size_t __s1_len___5 ;
  size_t __s2_len___5 ;
  int tmp___82 ;
  int tmp___83 ;
  int tmp___84 ;
  unsigned char const   *__s2___5 ;
  register int __result___11 ;
  int tmp___85 ;
  unsigned char const   *__s1___5 ;
  register int __result___12 ;
  int tmp___86 ;
  int tmp___87 ;
  int tmp___88 ;
  size_t __s1_len___6 ;
  size_t __s2_len___6 ;
  int tmp___89 ;
  int tmp___90 ;
  int tmp___91 ;
  unsigned char const   *__s2___6 ;
  register int __result___13 ;
  int tmp___92 ;
  unsigned char const   *__s1___6 ;
  register int __result___14 ;
  int tmp___93 ;
  int tmp___94 ;
  int tmp___95 ;

  {
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "643", "0", checkpoints_buf);
  if (0) {


    __s1_len___6 = strlen((char const   *)opt);




    __s2_len___6 = strlen("none");


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "646", "1", checkpoints_buf);
    if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
      goto _L___14;
    } else {

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "648", "4", checkpoints_buf);
      if (__s1_len___6 >= 4U) {
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "649", "1", checkpoints_buf);
        _L___14: /* CIL Label */ 
        if (! ((size_t )((void const   *)("none" + 1)) - (size_t )((void const   *)"none") == 1U)) {
          tmp___95 = 1;
          sprintf(checkpoints_buf, "%d", tmp___95);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "650", "tmp___95", checkpoints_buf);
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "651", "4", checkpoints_buf);
          if (__s2_len___6 >= 4U) {
            tmp___95 = 1;
            sprintf(checkpoints_buf, "%d", tmp___95);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "652", "tmp___95", checkpoints_buf);
          } else {
            tmp___95 = 0;
            sprintf(checkpoints_buf, "%d", tmp___95);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "653", "tmp___95", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "651", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "649", "1", checkpoints_buf);
      } else {
        tmp___95 = 0;
        sprintf(checkpoints_buf, "%d", tmp___95);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "654", "tmp___95", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%u", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "648", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "646", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___95);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "655", "tmp___95", checkpoints_buf);
    if (tmp___95) {
      sprintf(checkpoints_buf, "%d", tmp___90);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "656", "tmp___90", checkpoints_buf);

      tmp___90 = __builtin_strcmp((char const   *)opt, "none");
      sprintf(checkpoints_buf, "%d", tmp___90);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "656", "tmp___90", checkpoints_buf);

      tmp___94 = tmp___90;
      sprintf(checkpoints_buf, "%d", tmp___94);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "657", "tmp___94", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___93);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "658", "tmp___93", checkpoints_buf);

      tmp___93 = __builtin_strcmp((char const   *)opt, "none");
      sprintf(checkpoints_buf, "%d", tmp___93);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "658", "tmp___93", checkpoints_buf);

      tmp___94 = tmp___93;
      sprintf(checkpoints_buf, "%d", tmp___94);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "659", "tmp___94", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___95);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "655", "tmp___95", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", tmp___93);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "660", "tmp___93", checkpoints_buf);

    tmp___93 = __builtin_strcmp((char const   *)opt, "none");
    sprintf(checkpoints_buf, "%d", tmp___93);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "660", "tmp___93", checkpoints_buf);

    tmp___94 = tmp___93;
    sprintf(checkpoints_buf, "%d", tmp___94);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "661", "tmp___94", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "643", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___94);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "662", "tmp___94", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "662", "0", checkpoints_buf);
  if (tmp___94 == 0) {
    defcompression = (uint16 )1;

  } else {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "664", "0", checkpoints_buf);
    if (0) {


      __s1_len___5 = strlen((char const   *)opt);




      __s2_len___5 = strlen("packbits");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "667", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
        goto _L___12;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "669", "4", checkpoints_buf);
        if (__s1_len___5 >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "670", "1", checkpoints_buf);
          _L___12: /* CIL Label */ 
          if (! ((size_t )((void const   *)("packbits" + 1)) - (size_t )((void const   *)"packbits") == 1U)) {
            tmp___88 = 1;
            sprintf(checkpoints_buf, "%d", tmp___88);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "671", "tmp___88", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "672", "4", checkpoints_buf);
            if (__s2_len___5 >= 4U) {
              tmp___88 = 1;
              sprintf(checkpoints_buf, "%d", tmp___88);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "673", "tmp___88", checkpoints_buf);
            } else {
              tmp___88 = 0;
              sprintf(checkpoints_buf, "%d", tmp___88);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "674", "tmp___88", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "672", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "670", "1", checkpoints_buf);
        } else {
          tmp___88 = 0;
          sprintf(checkpoints_buf, "%d", tmp___88);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "675", "tmp___88", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "669", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "667", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___88);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "676", "tmp___88", checkpoints_buf);
      if (tmp___88) {
        sprintf(checkpoints_buf, "%d", tmp___83);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "677", "tmp___83", checkpoints_buf);

        tmp___83 = __builtin_strcmp((char const   *)opt, "packbits");
        sprintf(checkpoints_buf, "%d", tmp___83);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "677", "tmp___83", checkpoints_buf);

        tmp___87 = tmp___83;
        sprintf(checkpoints_buf, "%d", tmp___87);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "678", "tmp___87", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___86);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "679", "tmp___86", checkpoints_buf);

        tmp___86 = __builtin_strcmp((char const   *)opt, "packbits");
        sprintf(checkpoints_buf, "%d", tmp___86);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "679", "tmp___86", checkpoints_buf);

        tmp___87 = tmp___86;
        sprintf(checkpoints_buf, "%d", tmp___87);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "680", "tmp___87", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___88);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "676", "tmp___88", checkpoints_buf);
    } else {
      tmp___33 = tmp___32;
      tmp___87 = tmp___86;
      sprintf(checkpoints_buf, "%d", tmp___87);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "682", "tmp___87", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "664", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___87);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "683", "tmp___87", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "683", "0", checkpoints_buf);
    if (tmp___87 == 0) {
      defcompression = (uint16 )32773;

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "685", "0", checkpoints_buf);
      if (0) {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "686", "0", checkpoints_buf);
        if (0) {


          __s1_len___4 = strlen((char const   *)opt);




          __s2_len___4 = strlen("jpeg");


          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "689", "1", checkpoints_buf);
          if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
            goto _L___10;
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "691", "4", checkpoints_buf);
            if (__s1_len___4 >= 4U) {
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "692", "1", checkpoints_buf);
              _L___10: /* CIL Label */ 
              if (! ((size_t )((void const   *)("jpeg" + 1)) - (size_t )((void const   *)"jpeg") == 1U)) {
                tmp___77 = 1;
                sprintf(checkpoints_buf, "%d", tmp___77);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "693", "tmp___77", checkpoints_buf);
              } else {

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "694", "4", checkpoints_buf);
                if (__s2_len___4 >= 4U) {
                  tmp___77 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___77);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "695", "tmp___77", checkpoints_buf);
                } else {
                  tmp___77 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___77);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "696", "tmp___77", checkpoints_buf);
                }

                sprintf(checkpoints_buf, "%u", 4);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "694", "4", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%u", 1);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "692", "1", checkpoints_buf);
            } else {
              tmp___77 = 0;
              sprintf(checkpoints_buf, "%d", tmp___77);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "697", "tmp___77", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "691", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "689", "1", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___77);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "698", "tmp___77", checkpoints_buf);
          if (tmp___77) {
            sprintf(checkpoints_buf, "%d", tmp___72);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "699", "tmp___72", checkpoints_buf);

            tmp___72 = __builtin_strcmp((char const   *)opt, "jpeg");
            sprintf(checkpoints_buf, "%d", tmp___72);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "699", "tmp___72", checkpoints_buf);

            tmp___76 = tmp___72;
            sprintf(checkpoints_buf, "%d", tmp___76);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "700", "tmp___76", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___75);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "701", "tmp___75", checkpoints_buf);

            tmp___75 = __builtin_strcmp((char const   *)opt, "jpeg");
            sprintf(checkpoints_buf, "%d", tmp___75);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "701", "tmp___75", checkpoints_buf);

            tmp___76 = tmp___75;
            sprintf(checkpoints_buf, "%d", tmp___76);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "702", "tmp___76", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___77);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "698", "tmp___77", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___75);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "703", "tmp___75", checkpoints_buf);

          tmp___75 = __builtin_strcmp((char const   *)opt, "jpeg");
          sprintf(checkpoints_buf, "%d", tmp___75);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "703", "tmp___75", checkpoints_buf);

          tmp___76 = tmp___75;
          sprintf(checkpoints_buf, "%d", tmp___76);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "704", "tmp___76", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "686", "0", checkpoints_buf);
        tmp___79 = tmp___76;
        sprintf(checkpoints_buf, "%d", tmp___79);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "705", "tmp___79", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___78);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "706", "tmp___78", checkpoints_buf);

        tmp___78 = strncmp((char const   *)opt, "jpeg", (size_t )4);
        sprintf(checkpoints_buf, "%d", tmp___78);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "706", "tmp___78", checkpoints_buf);

        tmp___79 = tmp___78;
        sprintf(checkpoints_buf, "%d", tmp___79);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "707", "tmp___79", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "685", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___79);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "708", "tmp___79", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "708", "0", checkpoints_buf);
      if (tmp___79 == 0) {


        tmp___0 = __builtin_strchr(opt, ':');


        cp = tmp___0;

        defcompression = (uint16 )7;




        sprintf(checkpoints_buf, "%d", 2048);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "712", "2048", checkpoints_buf);



        while (cp) {



          tmp___1 = __ctype_b_loc();


          sprintf(checkpoints_buf, "%d", 2048);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "717", "2048", checkpoints_buf);
          if ((int const   )*(*tmp___1 + (int )*(cp + 1)) & 2048) {
            sprintf(checkpoints_buf, "%d", quality);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "718", "quality", checkpoints_buf);

            quality = atoi((char const   *)(cp + 1));
            sprintf(checkpoints_buf, "%d", quality);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "718", "quality", checkpoints_buf);

          } else {
            sprintf(checkpoints_buf, "%d", 114);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "719", "114", checkpoints_buf);
            if ((int )*(cp + 1) == 114) {
              jpegcolormode = 0;
              sprintf(checkpoints_buf, "%d", jpegcolormode);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "720", "jpegcolormode", checkpoints_buf);
            } else {

              usage();

            }
            sprintf(checkpoints_buf, "%d", 114);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "719", "114", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 2048);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "717", "2048", checkpoints_buf);


          tmp___3 = __builtin_strchr(cp + 1, ':');


          cp = tmp___3;

        }



        sprintf(checkpoints_buf, "%d", 2048);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "712", "2048", checkpoints_buf);



      } else {
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "724", "0", checkpoints_buf);
        if (0) {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "725", "0", checkpoints_buf);
          if (0) {


            __s1_len___3 = strlen((char const   *)opt);




            __s2_len___3 = strlen("g3");


            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "728", "1", checkpoints_buf);
            if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
              goto _L___8;
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "730", "4", checkpoints_buf);
              if (__s1_len___3 >= 4U) {
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "731", "1", checkpoints_buf);
                _L___8: /* CIL Label */ 
                if (! ((size_t )((void const   *)("g3" + 1)) - (size_t )((void const   *)"g3") == 1U)) {
                  tmp___64 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___64);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "732", "tmp___64", checkpoints_buf);
                } else {

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "733", "4", checkpoints_buf);
                  if (__s2_len___3 >= 4U) {
                    tmp___64 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___64);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "734", "tmp___64", checkpoints_buf);
                  } else {
                    tmp___64 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___64);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "735", "tmp___64", checkpoints_buf);
                  }

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "733", "4", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "731", "1", checkpoints_buf);
              } else {
                tmp___64 = 0;
                sprintf(checkpoints_buf, "%d", tmp___64);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "736", "tmp___64", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "730", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "728", "1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___64);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "737", "tmp___64", checkpoints_buf);
            if (tmp___64) {
              sprintf(checkpoints_buf, "%d", tmp___59);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "738", "tmp___59", checkpoints_buf);

              tmp___59 = __builtin_strcmp((char const   *)opt, "g3");
              sprintf(checkpoints_buf, "%d", tmp___59);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "738", "tmp___59", checkpoints_buf);

              tmp___63 = tmp___59;
              sprintf(checkpoints_buf, "%d", tmp___63);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "739", "tmp___63", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___62);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "740", "tmp___62", checkpoints_buf);

              tmp___62 = __builtin_strcmp((char const   *)opt, "g3");
              sprintf(checkpoints_buf, "%d", tmp___62);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "740", "tmp___62", checkpoints_buf);

              tmp___63 = tmp___62;
              sprintf(checkpoints_buf, "%d", tmp___63);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "741", "tmp___63", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___64);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "737", "tmp___64", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___62);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "742", "tmp___62", checkpoints_buf);

            tmp___62 = __builtin_strcmp((char const   *)opt, "g3");
            sprintf(checkpoints_buf, "%d", tmp___62);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "742", "tmp___62", checkpoints_buf);

            tmp___63 = tmp___62;
            sprintf(checkpoints_buf, "%d", tmp___63);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "743", "tmp___63", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "725", "0", checkpoints_buf);
          tmp___66 = tmp___63;
          sprintf(checkpoints_buf, "%d", tmp___66);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "744", "tmp___66", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___65);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "745", "tmp___65", checkpoints_buf);

          tmp___65 = strncmp((char const   *)opt, "g3", (size_t )2);
          sprintf(checkpoints_buf, "%d", tmp___65);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "745", "tmp___65", checkpoints_buf);

          tmp___66 = tmp___65;
          sprintf(checkpoints_buf, "%d", tmp___66);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "746", "tmp___66", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "724", "0", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___66);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "747", "tmp___66", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "747", "0", checkpoints_buf);
        if (tmp___66 == 0) {

          processG3Options(opt);

          defcompression = (uint16 )3;

        } else {
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "750", "0", checkpoints_buf);
          if (0) {


            __s1_len___2 = strlen((char const   *)opt);




            __s2_len___2 = strlen("g4");


            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "753", "1", checkpoints_buf);
            if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
              goto _L___6;
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "755", "4", checkpoints_buf);
              if (__s1_len___2 >= 4U) {
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "756", "1", checkpoints_buf);
                _L___6: /* CIL Label */ 
                if (! ((size_t )((void const   *)("g4" + 1)) - (size_t )((void const   *)"g4") == 1U)) {
                  tmp___55 = 1;
                  sprintf(checkpoints_buf, "%d", tmp___55);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "757", "tmp___55", checkpoints_buf);
                } else {

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "758", "4", checkpoints_buf);
                  if (__s2_len___2 >= 4U) {
                    tmp___55 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___55);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "759", "tmp___55", checkpoints_buf);
                  } else {
                    tmp___55 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___55);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "760", "tmp___55", checkpoints_buf);
                  }

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "758", "4", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "756", "1", checkpoints_buf);
              } else {
                tmp___55 = 0;
                sprintf(checkpoints_buf, "%d", tmp___55);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "761", "tmp___55", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "755", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "753", "1", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___55);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "762", "tmp___55", checkpoints_buf);
            if (tmp___55) {
              sprintf(checkpoints_buf, "%d", tmp___50);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "763", "tmp___50", checkpoints_buf);

              tmp___50 = __builtin_strcmp((char const   *)opt, "g4");
              sprintf(checkpoints_buf, "%d", tmp___50);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "763", "tmp___50", checkpoints_buf);

              tmp___54 = tmp___50;
              sprintf(checkpoints_buf, "%d", tmp___54);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "764", "tmp___54", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___53);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "765", "tmp___53", checkpoints_buf);

              tmp___53 = __builtin_strcmp((char const   *)opt, "g4");
              sprintf(checkpoints_buf, "%d", tmp___53);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "765", "tmp___53", checkpoints_buf);

              tmp___54 = tmp___53;
              sprintf(checkpoints_buf, "%d", tmp___54);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "766", "tmp___54", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___55);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "762", "tmp___55", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", tmp___53);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "767", "tmp___53", checkpoints_buf);

            tmp___53 = __builtin_strcmp((char const   *)opt, "g4");
            sprintf(checkpoints_buf, "%d", tmp___53);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "767", "tmp___53", checkpoints_buf);

            tmp___54 = tmp___53;
            sprintf(checkpoints_buf, "%d", tmp___54);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "768", "tmp___54", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "750", "0", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", tmp___54);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "769", "tmp___54", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "769", "0", checkpoints_buf);
          if (tmp___54 == 0) {
            defcompression = (uint16 )4;

          } else {
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "771", "0", checkpoints_buf);
            if (0) {
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "772", "0", checkpoints_buf);
              if (0) {


                __s1_len___1 = strlen((char const   *)opt);




                __s2_len___1 = strlen("lzw");


                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "775", "1", checkpoints_buf);
                if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
                  goto _L___4;
                } else {

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "777", "4", checkpoints_buf);
                  if (__s1_len___1 >= 4U) {
                    sprintf(checkpoints_buf, "%u", 1);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "778", "1", checkpoints_buf);
                    _L___4: /* CIL Label */ 
                    if (! ((size_t )((void const   *)("lzw" + 1)) - (size_t )((void const   *)"lzw") == 1U)) {
                      tmp___44 = 1;
                      sprintf(checkpoints_buf, "%d", tmp___44);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "779", "tmp___44", checkpoints_buf);
                    } else {

                      sprintf(checkpoints_buf, "%u", 4);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "780", "4", checkpoints_buf);
                      if (__s2_len___1 >= 4U) {
                        tmp___44 = 1;
                        sprintf(checkpoints_buf, "%d", tmp___44);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "781", "tmp___44", checkpoints_buf);
                      } else {
                        tmp___44 = 0;
                        sprintf(checkpoints_buf, "%d", tmp___44);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "782", "tmp___44", checkpoints_buf);
                      }

                      sprintf(checkpoints_buf, "%u", 4);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "780", "4", checkpoints_buf);
                    }
                    sprintf(checkpoints_buf, "%u", 1);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "778", "1", checkpoints_buf);
                  } else {
                    tmp___44 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___44);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "783", "tmp___44", checkpoints_buf);
                  }

                  sprintf(checkpoints_buf, "%u", 4);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "777", "4", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%u", 1);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "775", "1", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", tmp___44);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "784", "tmp___44", checkpoints_buf);
                if (tmp___44) {
                  sprintf(checkpoints_buf, "%d", tmp___39);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "785", "tmp___39", checkpoints_buf);

                  tmp___39 = __builtin_strcmp((char const   *)opt, "lzw");
                  sprintf(checkpoints_buf, "%d", tmp___39);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "785", "tmp___39", checkpoints_buf);

                  tmp___43 = tmp___39;
                  sprintf(checkpoints_buf, "%d", tmp___43);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "786", "tmp___43", checkpoints_buf);
                } else {
                  sprintf(checkpoints_buf, "%d", tmp___42);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "787", "tmp___42", checkpoints_buf);

                  tmp___42 = __builtin_strcmp((char const   *)opt, "lzw");
                  sprintf(checkpoints_buf, "%d", tmp___42);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "787", "tmp___42", checkpoints_buf);

                  tmp___43 = tmp___42;
                  sprintf(checkpoints_buf, "%d", tmp___43);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "788", "tmp___43", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%d", tmp___44);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "784", "tmp___44", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", tmp___42);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "789", "tmp___42", checkpoints_buf);

                tmp___42 = __builtin_strcmp((char const   *)opt, "lzw");
                sprintf(checkpoints_buf, "%d", tmp___42);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "789", "tmp___42", checkpoints_buf);

                tmp___43 = tmp___42;
                sprintf(checkpoints_buf, "%d", tmp___43);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "790", "tmp___43", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "772", "0", checkpoints_buf);
              tmp___46 = tmp___43;
              sprintf(checkpoints_buf, "%d", tmp___46);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "791", "tmp___46", checkpoints_buf);
            } else {
              sprintf(checkpoints_buf, "%d", tmp___45);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "792", "tmp___45", checkpoints_buf);

              tmp___45 = strncmp((char const   *)opt, "lzw", (size_t )3);
              sprintf(checkpoints_buf, "%d", tmp___45);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "792", "tmp___45", checkpoints_buf);

              tmp___46 = tmp___45;
              sprintf(checkpoints_buf, "%d", tmp___46);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "793", "tmp___46", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "771", "0", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___46);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "794", "tmp___46", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "794", "0", checkpoints_buf);
            if (tmp___46 == 0) {


              tmp___5 = __builtin_strchr(opt, ':');


              cp___0 = tmp___5;


              if (cp___0) {
                sprintf(checkpoints_buf, "%d", tmp___6);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "798", "tmp___6", checkpoints_buf);

                tmp___6 = atoi((char const   *)(cp___0 + 1));
                sprintf(checkpoints_buf, "%d", tmp___6);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "798", "tmp___6", checkpoints_buf);

                defpredictor = (uint16 )tmp___6;

              } else {

              }

              defcompression = (uint16 )5;

            } else {
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "802", "0", checkpoints_buf);
              if (0) {
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "803", "0", checkpoints_buf);
                if (0) {


                  __s1_len___0 = strlen((char const   *)opt);




                  __s2_len___0 = strlen("zip");


                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "806", "1", checkpoints_buf);
                  if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
                    goto _L___2;
                  } else {

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "808", "4", checkpoints_buf);
                    if (__s1_len___0 >= 4U) {
                      sprintf(checkpoints_buf, "%u", 1);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "809", "1", checkpoints_buf);
                      _L___2: /* CIL Label */ 
                      if (! ((size_t )((void const   *)("zip" + 1)) - (size_t )((void const   *)"zip") == 1U)) {
                        tmp___31 = 1;
                        sprintf(checkpoints_buf, "%d", tmp___31);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "810", "tmp___31", checkpoints_buf);
                      } else {

                        sprintf(checkpoints_buf, "%u", 4);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "811", "4", checkpoints_buf);
                        if (__s2_len___0 >= 4U) {
                          tmp___31 = 1;
                          sprintf(checkpoints_buf, "%d", tmp___31);
                          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                          "812", "tmp___31", checkpoints_buf);
                        } else {
                          tmp___31 = 0;
                          sprintf(checkpoints_buf, "%d", tmp___31);
                          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                          "813", "tmp___31", checkpoints_buf);
                        }

                        sprintf(checkpoints_buf, "%u", 4);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "811", "4", checkpoints_buf);
                      }
                      sprintf(checkpoints_buf, "%u", 1);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "809", "1", checkpoints_buf);
                    } else {
                      tmp___31 = 0;
                      sprintf(checkpoints_buf, "%d", tmp___31);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "814", "tmp___31", checkpoints_buf);
                    }

                    sprintf(checkpoints_buf, "%u", 4);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "808", "4", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%u", 1);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "806", "1", checkpoints_buf);
                  sprintf(checkpoints_buf, "%d", tmp___31);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "815", "tmp___31", checkpoints_buf);
                  if (tmp___31) {
                    sprintf(checkpoints_buf, "%d", tmp___26);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "816", "tmp___26", checkpoints_buf);

                    tmp___26 = __builtin_strcmp((char const   *)opt, "zip");
                    sprintf(checkpoints_buf, "%d", tmp___26);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "816", "tmp___26", checkpoints_buf);

                    tmp___30 = tmp___26;
                    sprintf(checkpoints_buf, "%d", tmp___30);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "817", "tmp___30", checkpoints_buf);
                  } else {
                    sprintf(checkpoints_buf, "%d", tmp___29);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "818", "tmp___29", checkpoints_buf);

                    tmp___29 = __builtin_strcmp((char const   *)opt, "zip");
                    sprintf(checkpoints_buf, "%d", tmp___29);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "818", "tmp___29", checkpoints_buf);

                    tmp___30 = tmp___29;
                    sprintf(checkpoints_buf, "%d", tmp___30);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "819", "tmp___30", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%d", tmp___31);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "815", "tmp___31", checkpoints_buf);
                } else {
                  sprintf(checkpoints_buf, "%d", tmp___29);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "820", "tmp___29", checkpoints_buf);

                  tmp___29 = __builtin_strcmp((char const   *)opt, "zip");
                  sprintf(checkpoints_buf, "%d", tmp___29);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "820", "tmp___29", checkpoints_buf);

                  tmp___30 = tmp___29;
                  sprintf(checkpoints_buf, "%d", tmp___30);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "821", "tmp___30", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "803", "0", checkpoints_buf);
                tmp___33 = tmp___30;
                sprintf(checkpoints_buf, "%d", tmp___33);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "822", "tmp___33", checkpoints_buf);
              } else {
                sprintf(checkpoints_buf, "%d", tmp___32);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "823", "tmp___32", checkpoints_buf);

                tmp___32 = strncmp((char const   *)opt, "zip", (size_t )3);
                sprintf(checkpoints_buf, "%d", tmp___32);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "823", "tmp___32", checkpoints_buf);

                tmp___86 = __builtin_strcmp((char const   *)opt, "packbits");
              }
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "802", "0", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___33);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "825", "tmp___33", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "825", "0", checkpoints_buf);
              if (tmp___33 == 0) {


                tmp___8 = __builtin_strchr(opt, ':');


                cp___1 = tmp___8;


                if (cp___1) {
                  sprintf(checkpoints_buf, "%d", tmp___9);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "829", "tmp___9", checkpoints_buf);

                  tmp___9 = atoi((char const   *)(cp___1 + 1));
                  sprintf(checkpoints_buf, "%d", tmp___9);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "829", "tmp___9", checkpoints_buf);

                  defpredictor = (uint16 )tmp___9;

                } else {

                }

                defcompression = (uint16 )8;

              } else {
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "833", "0", checkpoints_buf);
                if (0) {
                  sprintf(checkpoints_buf, "%d", 0);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "834", "0", checkpoints_buf);
                  if (0) {


                    __s1_len = strlen((char const   *)opt);




                    __s2_len = strlen("jbig");


                    sprintf(checkpoints_buf, "%u", 1);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "837", "1", checkpoints_buf);
                    if (! ((size_t )((void const   *)(opt + 1)) - (size_t )((void const   *)opt) == 1U)) {
                      goto _L___0;
                    } else {

                      sprintf(checkpoints_buf, "%u", 4);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "839", "4", checkpoints_buf);
                      if (__s1_len >= 4U) {
                        sprintf(checkpoints_buf, "%u", 1);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "840", "1", checkpoints_buf);
                        _L___0: /* CIL Label */ 
                        if (! ((size_t )((void const   *)("jbig" + 1)) - (size_t )((void const   *)"jbig") == 1U)) {
                          tmp___18 = 1;
                          sprintf(checkpoints_buf, "%d", tmp___18);
                          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                          "841", "tmp___18", checkpoints_buf);
                        } else {

                          sprintf(checkpoints_buf, "%u", 4);
                          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                          "842", "4", checkpoints_buf);
                          if (__s2_len >= 4U) {
                            tmp___18 = 1;
                            sprintf(checkpoints_buf, "%d", tmp___18);
                            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                            "843", "tmp___18", checkpoints_buf);
                          } else {
                            tmp___18 = 0;
                            sprintf(checkpoints_buf, "%d", tmp___18);
                            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                            "844", "tmp___18", checkpoints_buf);
                          }

                          sprintf(checkpoints_buf, "%u", 4);
                          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                          "842", "4", checkpoints_buf);
                        }
                        sprintf(checkpoints_buf, "%u", 1);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "840", "1", checkpoints_buf);
                      } else {
                        tmp___18 = 0;
                        sprintf(checkpoints_buf, "%d", tmp___18);
                        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                        "845", "tmp___18", checkpoints_buf);
                      }

                      sprintf(checkpoints_buf, "%u", 4);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "839", "4", checkpoints_buf);
                    }
                    sprintf(checkpoints_buf, "%u", 1);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "837", "1", checkpoints_buf);
                    sprintf(checkpoints_buf, "%d", tmp___18);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "846", "tmp___18", checkpoints_buf);
                    if (tmp___18) {
                      sprintf(checkpoints_buf, "%d", tmp___13);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "847", "tmp___13", checkpoints_buf);

                      tmp___13 = __builtin_strcmp((char const   *)opt, "jbig");
                      sprintf(checkpoints_buf, "%d", tmp___13);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "847", "tmp___13", checkpoints_buf);

                      tmp___17 = tmp___13;
                      sprintf(checkpoints_buf, "%d", tmp___17);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "848", "tmp___17", checkpoints_buf);
                    } else {
                      sprintf(checkpoints_buf, "%d", tmp___16);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "849", "tmp___16", checkpoints_buf);

                      tmp___16 = __builtin_strcmp((char const   *)opt, "jbig");
                      sprintf(checkpoints_buf, "%d", tmp___16);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "849", "tmp___16", checkpoints_buf);

                      tmp___17 = tmp___16;
                      sprintf(checkpoints_buf, "%d", tmp___17);
                      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                      "850", "tmp___17", checkpoints_buf);
                    }
                    sprintf(checkpoints_buf, "%d", tmp___18);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "846", "tmp___18", checkpoints_buf);
                  } else {
                    sprintf(checkpoints_buf, "%d", tmp___16);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "851", "tmp___16", checkpoints_buf);

                    tmp___16 = __builtin_strcmp((char const   *)opt, "jbig");
                    sprintf(checkpoints_buf, "%d", tmp___16);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "851", "tmp___16", checkpoints_buf);

                    tmp___17 = tmp___16;
                    sprintf(checkpoints_buf, "%d", tmp___17);
                    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                    "852", "tmp___17", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%d", 0);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "834", "0", checkpoints_buf);
                  tmp___20 = tmp___17;
                  sprintf(checkpoints_buf, "%d", tmp___20);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "853", "tmp___20", checkpoints_buf);
                } else {
                  sprintf(checkpoints_buf, "%d", tmp___19);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "854", "tmp___19", checkpoints_buf);

                  tmp___19 = strncmp((char const   *)opt, "jbig", (size_t )4);
                  sprintf(checkpoints_buf, "%d", tmp___19);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "854", "tmp___19", checkpoints_buf);

                  tmp___20 = tmp___19;
                  sprintf(checkpoints_buf, "%d", tmp___20);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "855", "tmp___20", checkpoints_buf);
                }
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "833", "0", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", tmp___20);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "856", "tmp___20", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "856", "0", checkpoints_buf);
                if (tmp___20 == 0) {
                  defcompression = (uint16 )34661;

                } else {
                  sprintf(checkpoints_buf, "%d", 0);
                  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                  "858", "0", checkpoints_buf);
                  return (0);
                }
                sprintf(checkpoints_buf, "%d", tmp___20);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "856", "tmp___20", checkpoints_buf);
                sprintf(checkpoints_buf, "%d", 0);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "856", "0", checkpoints_buf);
              }
              sprintf(checkpoints_buf, "%d", tmp___33);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "825", "tmp___33", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "825", "0", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%d", tmp___46);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "794", "tmp___46", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "794", "0", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___54);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "769", "tmp___54", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "769", "0", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___66);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "747", "tmp___66", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "747", "0", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___79);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "708", "tmp___79", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "708", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___87);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "683", "tmp___87", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "683", "0", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___94);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "662", "tmp___94", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "662", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "859", "1", checkpoints_buf);
  return (1);
}
}
char *stuff[49]  = 
  {      (char *)"usage: tiffcp [options] input... output",      (char *)"where options are:",      (char *)" -a              append to output instead of overwriting",      (char *)" -o offset       set initial directory offset", 
        (char *)" -p contig       pack samples contiguously (e.g. RGBRGB...)",      (char *)" -p separate     store samples separately (e.g. RRR...GGG...BBB...)",      (char *)" -s              write output in strips",      (char *)" -t              write output in tiles", 
        (char *)" -8              write BigTIFF instead of default ClassicTIFF",      (char *)" -i              ignore read errors",      (char *)" -b file[,#]     bias (dark) monochrome image to be subtracted from all others",      (char *)" -,=%            use % rather than , to separate image #\'s (per Note below)", 
        (char *)"",      (char *)" -r #            make each strip have no more than # rows",      (char *)" -w #            set output tile width (pixels)",      (char *)" -l #            set output tile length (pixels)", 
        (char *)"",      (char *)" -f lsb2msb      force lsb-to-msb FillOrder for output",      (char *)" -f msb2lsb      force msb-to-lsb FillOrder for output",      (char *)"", 
        (char *)" -c lzw[:opts]   compress output with Lempel-Ziv & Welch encoding",      (char *)" -c zip[:opts]   compress output with deflate encoding",      (char *)" -c jpeg[:opts]  compress output with JPEG encoding",      (char *)" -c jbig         compress output with ISO JBIG encoding", 
        (char *)" -c packbits     compress output with packbits encoding",      (char *)" -c g3[:opts]    compress output with CCITT Group 3 encoding",      (char *)" -c g4           compress output with CCITT Group 4 encoding",      (char *)" -c none         use no compression algorithm on output", 
        (char *)"",      (char *)"Group 3 options:",      (char *)" 1d              use default CCITT Group 3 1D-encoding",      (char *)" 2d              use optional CCITT Group 3 2D-encoding", 
        (char *)" fill            byte-align EOL codes",      (char *)"For example, -c g3:2d:fill to get G3-2D-encoded data with byte-aligned EOLs",      (char *)"",      (char *)"JPEG options:", 
        (char *)" #               set compression quality level (0-100, default 75)",      (char *)" r               output color image as RGB rather than YCbCr",      (char *)"For example, -c jpeg:r:50 to get JPEG-encoded RGB data with 50% comp. quality",      (char *)"", 
        (char *)"LZW and deflate options:",      (char *)" #               set predictor value",      (char *)"For example, -c lzw:2 to get LZW-encoded data with horizontal differencing",      (char *)"", 
        (char *)"Note that input filenames may be of the form filename,x,y,z",      (char *)"where x, y, and z specify image numbers in the filename to copy.",      (char *)"example:  tiffcp -c none -b esp.tif,1 esp.tif,0 test.tif",      (char *)"  subtract 2nd image in esp.tif from 1st yielding uncompressed result test.tif", 
        (char *)((void *)0)};
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
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "863", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "864", "i", checkpoints_buf);
  while ((unsigned int )stuff[i] != (unsigned int )((void *)0)) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s\n", stuff[i]);

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "869", "i", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "864", "i", checkpoints_buf);

  exit(-1);

}
}
static void cpTag(TIFF *in , TIFF *out , uint16 tag , uint16 count ,
                  TIFFDataType type ) 
{ 
  uint16 shortv ;
  int tmp ;
  uint16 shortv1 ;
  uint16 shortv2 ;
  int tmp___0 ;
  uint16 *tr ;
  uint16 *tg ;
  uint16 *tb ;
  uint16 *ta ;
  int tmp___1 ;
  uint16 shortv1___0 ;
  uint16 *shortav ;
  int tmp___2 ;
  uint32 longv ;
  int tmp___3 ;
  float floatv ;
  int tmp___4 ;
  float *floatav ;
  int tmp___5 ;
  char *stringv ;
  int tmp___6 ;
  double doublev ;
  int tmp___7 ;
  double *doubleav ;
  int tmp___8 ;
  char const   *tmp___9 ;

  {
  switch ((unsigned int )type) {
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "872", "1", checkpoints_buf);
  case 3U: 
  if ((int )count == 1) {
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "873", "tmp", checkpoints_buf);

    tmp = TIFFGetField(in, (uint32 )tag, & shortv);
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "873", "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "874", "tmp", checkpoints_buf);
    if (tmp) {

      TIFFSetField(out, (uint32 )tag, (int )shortv);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "874", "tmp", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "877", "2", checkpoints_buf);
    if ((int )count == 2) {
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "878", "tmp___0", checkpoints_buf);

      tmp___0 = TIFFGetField(in, (uint32 )tag, & shortv1, & shortv2);
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "878", "tmp___0", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "879", "tmp___0", checkpoints_buf);
      if (tmp___0) {

        TIFFSetField(out, (uint32 )tag, (int )shortv1, (int )shortv2);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "879", "tmp___0", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "882", "4", checkpoints_buf);
      if ((int )count == 4) {
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "883", "tmp___1", checkpoints_buf);

        tmp___1 = TIFFGetField(in, (uint32 )tag, & tr, & tg, & tb, & ta);
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "883", "tmp___1", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "884", "tmp___1", checkpoints_buf);
        if (tmp___1) {

          TIFFSetField(out, (uint32 )tag, tr, tg, tb, ta);

        } else {

        }
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "884", "tmp___1", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "887", "65535", checkpoints_buf);
        if ((int )count == 65535) {
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "888", "tmp___2", checkpoints_buf);

          tmp___2 = TIFFGetField(in, (uint32 )tag, & shortv1___0, & shortav);
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "888", "tmp___2", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "889", "tmp___2", checkpoints_buf);
          if (tmp___2) {

            TIFFSetField(out, (uint32 )tag, (int )shortv1___0, shortav);

          } else {

          }
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "889", "tmp___2", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", 65535);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "887", "65535", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "882", "4", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "877", "2", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "872", "1", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "894", "tmp___3", checkpoints_buf);

  case 4U: 
  tmp___3 = TIFFGetField(in, (uint32 )tag, & longv);
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "894", "tmp___3", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "895", "tmp___3", checkpoints_buf);
  if (tmp___3) {

    TIFFSetField(out, (uint32 )tag, longv);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "895", "tmp___3", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "899", "1", checkpoints_buf);
  case 5U: 
  if ((int )count == 1) {
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "900", "tmp___4", checkpoints_buf);

    tmp___4 = TIFFGetField(in, (uint32 )tag, & floatv);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "900", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "901", "tmp___4", checkpoints_buf);
    if (tmp___4) {

      TIFFSetField(out, (uint32 )tag, (double )floatv);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "901", "tmp___4", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "904", "65535", checkpoints_buf);
    if ((int )count == 65535) {
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "905", "tmp___5", checkpoints_buf);

      tmp___5 = TIFFGetField(in, (uint32 )tag, & floatav);
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "905", "tmp___5", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "906", "tmp___5", checkpoints_buf);
      if (tmp___5) {

        TIFFSetField(out, (uint32 )tag, floatav);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___5);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "906", "tmp___5", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "904", "65535", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "899", "1", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "911", "tmp___6", checkpoints_buf);

  case 2U: 
  tmp___6 = TIFFGetField(in, (uint32 )tag, & stringv);
  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "911", "tmp___6", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "912", "tmp___6", checkpoints_buf);
  if (tmp___6) {

    TIFFSetField(out, (uint32 )tag, stringv);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___6);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "912", "tmp___6", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "916", "1", checkpoints_buf);
  case 12U: 
  if ((int )count == 1) {
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "917", "tmp___7", checkpoints_buf);

    tmp___7 = TIFFGetField(in, (uint32 )tag, & doublev);
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "917", "tmp___7", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "918", "tmp___7", checkpoints_buf);
    if (tmp___7) {

      TIFFSetField(out, (uint32 )tag, doublev);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___7);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "918", "tmp___7", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "921", "65535", checkpoints_buf);
    if ((int )count == 65535) {
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "922", "tmp___8", checkpoints_buf);

      tmp___8 = TIFFGetField(in, (uint32 )tag, & doubleav);
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "922", "tmp___8", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "923", "tmp___8", checkpoints_buf);
      if (tmp___8) {

        TIFFSetField(out, (uint32 )tag, doubleav);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "923", "tmp___8", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 65535);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "921", "65535", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "916", "1", checkpoints_buf);
  break;


  default: 
  tmp___9 = TIFFFileName(in);



  TIFFError(tmp___9, "Data type %d is not supported, tag %d skipped.",
            (int )tag, (unsigned int )type);

  }
  return;
}
}
static struct cpTag tags[33]  = 
  {      {(uint16 )254, (uint16 )1, (TIFFDataType )4}, 
        {(uint16 )263, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )269, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )270, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )271, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )272, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )280, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )281, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )282, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )283, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )285, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )286, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )287, (uint16 )1, (TIFFDataType )5}, 
        {(uint16 )296, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )305, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )306, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )315, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )316, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )318, (uint16 )-1, (TIFFDataType )5}, 
        {(uint16 )319, (uint16 )-1, (TIFFDataType )5}, 
        {(uint16 )321, (uint16 )2, (TIFFDataType )3}, 
        {(uint16 )332, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )336, (uint16 )2, (TIFFDataType )3}, 
        {(uint16 )337, (uint16 )1, (TIFFDataType )2}, 
        {(uint16 )339, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )529, (uint16 )-1, (TIFFDataType )5}, 
        {(uint16 )530, (uint16 )2, (TIFFDataType )3}, 
        {(uint16 )531, (uint16 )1, (TIFFDataType )3}, 
        {(uint16 )532, (uint16 )-1, (TIFFDataType )5}, 
        {(uint16 )338, (uint16 )-1, (TIFFDataType )3}, 
        {(uint16 )340, (uint16 )1, (TIFFDataType )12}, 
        {(uint16 )341, (uint16 )1, (TIFFDataType )12}, 
        {(uint16 )37439, (uint16 )1, (TIFFDataType )12}};
static copyFunc pickCopyFunc(TIFF *in , TIFF *out , uint16 bitspersample ,
                             uint16 samplesperpixel ) ;
static int tiffcp(TIFF *in , TIFF *out ) 
{ 
  uint16 bitspersample ;
  uint16 samplesperpixel ;
  int (*cf)(TIFF *in , TIFF *out , uint32 l , uint32 w , uint16 samplesperpixel ) ;
  uint32 width ;
  uint32 length ;
  struct cpTag *p ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  uint16 input_compression ;
  uint16 input_photometric ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  char const   *tmp___7 ;
  char const   *tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int tmp___11 ;
  int tmp___12 ;
  uint32 len32 ;
  void **data ;
  int tmp___13 ;
  uint16 ninks ;
  char const   *inknames ;
  int inknameslen ;
  size_t tmp___14 ;
  char const   *cp ;
  void *tmp___15 ;
  char *tmp___16 ;
  size_t tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;
  unsigned short pg0 ;
  unsigned short pg1 ;
  int tmp___20 ;
  int tmp___21 ;
  int tmp___22 ;
  int tmp___23 ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "931", "tmp", checkpoints_buf);

  tmp = TIFFGetField(in, (uint32 )256, & width);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "931", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "932", "tmp", checkpoints_buf);
  if (tmp) {

    TIFFSetField(out, (uint32 )256, width);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "932", "tmp", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "935", "tmp___0", checkpoints_buf);

  tmp___0 = TIFFGetField(in, (uint32 )257, & length);
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "935", "tmp___0", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "936", "tmp___0", checkpoints_buf);
  if (tmp___0) {

    TIFFSetField(out, (uint32 )257, length);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "936", "tmp___0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "939", "tmp___1", checkpoints_buf);

  tmp___1 = TIFFGetField(in, (uint32 )258, & bitspersample);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "939", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "940", "tmp___1", checkpoints_buf);
  if (tmp___1) {

    TIFFSetField(out, (uint32 )258, (int )bitspersample);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "940", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "943", "tmp___2", checkpoints_buf);

  tmp___2 = TIFFGetField(in, (uint32 )277, & samplesperpixel);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "943", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "944", "tmp___2", checkpoints_buf);
  if (tmp___2) {

    TIFFSetField(out, (uint32 )277, (int )samplesperpixel);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "944", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "947", "65535", checkpoints_buf);
  if ((int )compression != 65535) {

    TIFFSetField(out, (uint32 )259, (int )compression);

  } else {
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "949", "tmp___3", checkpoints_buf);

    tmp___3 = TIFFGetField(in, (uint32 )259, & compression);
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "949", "tmp___3", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "950", "tmp___3", checkpoints_buf);
    if (tmp___3) {

      TIFFSetField(out, (uint32 )259, (int )compression);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___3);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "950", "tmp___3", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "947", "65535", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "953", "7", checkpoints_buf);
  if ((int )compression == 7) {
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "954", "tmp___4", checkpoints_buf);

    tmp___4 = TIFFGetField(in, (uint32 )259, & input_compression);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "954", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "955", "tmp___4", checkpoints_buf);
    if (tmp___4) {
      sprintf(checkpoints_buf, "%d", 7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "956", "7", checkpoints_buf);
      if ((int )input_compression == 7) {

        TIFFSetField(in, (uint32 )65538, 1);

      } else {

      }
      sprintf(checkpoints_buf, "%d", 7);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "956", "7", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "955", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "960", "tmp___5", checkpoints_buf);

    tmp___5 = TIFFGetField(in, (uint32 )262, & input_photometric);
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "960", "tmp___5", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "961", "tmp___5", checkpoints_buf);
    if (tmp___5) {
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "962", "2", checkpoints_buf);
      if ((int )input_photometric == 2) {
        sprintf(checkpoints_buf, "%d", jpegcolormode);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "963", "jpegcolormode", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "963", "1", checkpoints_buf);
        if (jpegcolormode == 1) {

          TIFFSetField(out, (uint32 )262, 6);

        } else {

          TIFFSetField(out, (uint32 )262, 2);

        }
        sprintf(checkpoints_buf, "%d", jpegcolormode);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "963", "jpegcolormode", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "963", "1", checkpoints_buf);
      } else {

        TIFFSetField(out, (uint32 )262, (int )input_photometric);

      }
      sprintf(checkpoints_buf, "%d", 2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "962", "2", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___5);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "961", "tmp___5", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 34676);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "968", "34676", checkpoints_buf);
    if ((int )compression == 34676) {
      goto _L;
    } else {
      sprintf(checkpoints_buf, "%d", 34677);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "970", "34677", checkpoints_buf);
      if ((int )compression == 34677) {
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "971", "1", checkpoints_buf);
        _L: /* CIL Label */ 
        if ((int )samplesperpixel == 1) {
          tmp___6 = 32844;
          sprintf(checkpoints_buf, "%d", tmp___6);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "972", "tmp___6", checkpoints_buf);
        } else {
          tmp___6 = 32845;
          sprintf(checkpoints_buf, "%d", tmp___6);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "973", "tmp___6", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "971", "1", checkpoints_buf);

        TIFFSetField(out, (uint32 )262, tmp___6);

      } else {

        cpTag(in, out, (uint16 )262, (uint16 )1, (TIFFDataType )3);

      }
      sprintf(checkpoints_buf, "%d", 34677);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "970", "34677", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 34676);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "968", "34676", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "953", "7", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "976", "0", checkpoints_buf);
  if ((int )fillorder != 0) {

    TIFFSetField(out, (uint32 )266, (int )fillorder);

  } else {

    cpTag(in, out, (uint16 )266, (uint16 )1, (TIFFDataType )3);

  }
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "976", "0", checkpoints_buf);

  TIFFGetFieldDefaulted(in, (uint32 )274, & orientation);

  switch ((int )orientation) {


  case 7: 
  case 3: 
  tmp___7 = TIFFFileName(in);



  TIFFWarning(tmp___7, "using bottom-left orientation");

  orientation = (uint16 )4;

  case 4: 
  case 8: 
  break;


  default: 
  case 6: 
  case 2: 
  tmp___8 = TIFFFileName(in);



  TIFFWarning(tmp___8, "using top-left orientation");

  orientation = (uint16 )1;

  case 1: 
  case 5: 
  break;
  }

  TIFFSetField(out, (uint32 )274, (int )orientation);

  sprintf(checkpoints_buf, "%d", outtiled);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "990", "outtiled", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "990", "-1", checkpoints_buf);
  if (outtiled == -1) {
    sprintf(checkpoints_buf, "%d", outtiled);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "991", "outtiled", checkpoints_buf);

    outtiled = TIFFIsTiled(in);
    sprintf(checkpoints_buf, "%d", outtiled);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "991", "outtiled", checkpoints_buf);

  } else {

  }
  sprintf(checkpoints_buf, "%d", outtiled);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "990", "outtiled", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "990", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", outtiled);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "993", "outtiled", checkpoints_buf);
  if (outtiled) {

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "994", "4294967295", checkpoints_buf);
    if (tilewidth == 4294967295U) {

      TIFFGetField(in, (uint32 )322, & tilewidth);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "994", "4294967295", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "997", "4294967295", checkpoints_buf);
    if (tilelength == 4294967295U) {

      TIFFGetField(in, (uint32 )323, & tilelength);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "997", "4294967295", checkpoints_buf);

    TIFFDefaultTileSize(out, & tilewidth, & tilelength);


    TIFFSetField(out, (uint32 )322, tilewidth);


    TIFFSetField(out, (uint32 )323, tilelength);

  } else {

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1003", "0", checkpoints_buf);
    if (rowsperstrip == 0U) {
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1004", "tmp___9", checkpoints_buf);

      tmp___9 = TIFFGetField(in, (uint32 )278, & rowsperstrip);
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1004", "tmp___9", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1005", "tmp___9", checkpoints_buf);
      if (tmp___9) {

      } else {


        rowsperstrip = TIFFDefaultStripSize(out, rowsperstrip);


      }
      sprintf(checkpoints_buf, "%d", tmp___9);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1005", "tmp___9", checkpoints_buf);


      if (rowsperstrip > length) {

        sprintf(checkpoints_buf, "%u", 4294967295);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1009", "4294967295", checkpoints_buf);
        if (rowsperstrip != 4294967295U) {
          rowsperstrip = length;

        } else {

        }

        sprintf(checkpoints_buf, "%u", 4294967295);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1009", "4294967295", checkpoints_buf);
      } else {

      }


    } else {

      sprintf(checkpoints_buf, "%u", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1013", "4294967295", checkpoints_buf);
      if (rowsperstrip == 4294967295U) {
        rowsperstrip = length;

      } else {

      }

      sprintf(checkpoints_buf, "%u", 4294967295);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1013", "4294967295", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1003", "0", checkpoints_buf);

    TIFFSetField(out, (uint32 )278, rowsperstrip);

  }
  sprintf(checkpoints_buf, "%d", outtiled);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "993", "outtiled", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1017", "65535", checkpoints_buf);
  if ((int )config != 65535) {

    TIFFSetField(out, (uint32 )284, (int )config);

  } else {
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1019", "tmp___10", checkpoints_buf);

    tmp___10 = TIFFGetField(in, (uint32 )284, & config);
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1019", "tmp___10", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1020", "tmp___10", checkpoints_buf);
    if (tmp___10) {

      TIFFSetField(out, (uint32 )284, (int )config);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___10);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1020", "tmp___10", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1017", "65535", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1023", "4", checkpoints_buf);
  if ((int )samplesperpixel <= 4) {

    cpTag(in, out, (uint16 )301, (uint16 )4, (TIFFDataType )3);

  } else {

  }
  sprintf(checkpoints_buf, "%d", 4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1023", "4", checkpoints_buf);

  cpTag(in, out, (uint16 )320, (uint16 )4, (TIFFDataType )3);

  switch ((int )compression) {

  case 7: 
  TIFFSetField(out, (uint32 )65537, quality);


  TIFFSetField(out, (uint32 )65538, jpegcolormode);

  break;

  case 34661: 
  cpTag(in, out, (uint16 )34908, (uint16 )1, (TIFFDataType )4);


  cpTag(in, out, (uint16 )34910, (uint16 )1, (TIFFDataType )4);


  cpTag(in, out, (uint16 )34909, (uint16 )1, (TIFFDataType )2);


  cpTag(in, out, (uint16 )34911, (uint16 )1, (TIFFDataType )2);

  break;
  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1036", "65535", checkpoints_buf);
  case 32946: 
  case 8: 
  case 5: 
  if ((int )predictor != 65535) {

    TIFFSetField(out, (uint32 )317, (int )predictor);

  } else {
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1038", "tmp___11", checkpoints_buf);

    tmp___11 = TIFFGetField(in, (uint32 )317, & predictor);
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1038", "tmp___11", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1039", "tmp___11", checkpoints_buf);
    if (tmp___11) {

      TIFFSetField(out, (uint32 )317, (int )predictor);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1039", "tmp___11", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1036", "65535", checkpoints_buf);
  break;
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1043", "3", checkpoints_buf);
  case 4: 
  case 3: 
  if ((int )compression == 3) {

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1044", "4294967295", checkpoints_buf);
    if (g3opts != 4294967295U) {

      TIFFSetField(out, (uint32 )292, g3opts);

    } else {
      sprintf(checkpoints_buf, "%d", tmp___12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1046", "tmp___12", checkpoints_buf);

      tmp___12 = TIFFGetField(in, (uint32 )292, & g3opts);
      sprintf(checkpoints_buf, "%d", tmp___12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1046", "tmp___12", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1047", "tmp___12", checkpoints_buf);
      if (tmp___12) {

        TIFFSetField(out, (uint32 )292, g3opts);

      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1047", "tmp___12", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%u", 4294967295);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1044", "4294967295", checkpoints_buf);
  } else {

    cpTag(in, out, (uint16 )293, (uint16 )1, (TIFFDataType )4);

  }
  sprintf(checkpoints_buf, "%d", 3);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1043", "3", checkpoints_buf);

  cpTag(in, out, (uint16 )326, (uint16 )1, (TIFFDataType )4);


  cpTag(in, out, (uint16 )327, (uint16 )1, (TIFFDataType )4);


  cpTag(in, out, (uint16 )328, (uint16 )1, (TIFFDataType )4);


  cpTag(in, out, (uint16 )34908, (uint16 )1, (TIFFDataType )4);


  cpTag(in, out, (uint16 )34910, (uint16 )1, (TIFFDataType )4);


  cpTag(in, out, (uint16 )34909, (uint16 )1, (TIFFDataType )2);

  break;
  }
  sprintf(checkpoints_buf, "%d", tmp___13);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1058", "tmp___13", checkpoints_buf);

  tmp___13 = TIFFGetField(in, (uint32 )34675, & len32, & data);
  sprintf(checkpoints_buf, "%d", tmp___13);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1058", "tmp___13", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___13);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1059", "tmp___13", checkpoints_buf);
  if (tmp___13) {

    TIFFSetField(out, (uint32 )34675, len32, data);

  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___13);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1059", "tmp___13", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1062", "tmp___19", checkpoints_buf);

  tmp___19 = TIFFGetField(in, (uint32 )334, & ninks);
  sprintf(checkpoints_buf, "%d", tmp___19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1062", "tmp___19", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1063", "tmp___19", checkpoints_buf);
  if (tmp___19) {

    TIFFSetField(out, (uint32 )334, (int )ninks);

    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1065", "tmp___18", checkpoints_buf);

    tmp___18 = TIFFGetField(in, (uint32 )333, & inknames);
    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1065", "tmp___18", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1066", "tmp___18", checkpoints_buf);
    if (tmp___18) {


      tmp___14 = strlen(inknames);


      inknameslen = (int )(tmp___14 + 1U);
      sprintf(checkpoints_buf, "%d", inknameslen);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1068", "inknameslen", checkpoints_buf);
      cp = inknames;

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1070", "1", checkpoints_buf);






      sprintf(checkpoints_buf, "%d", inknameslen);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1070", "inknameslen", checkpoints_buf);

      while (1) {
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1071", "1", checkpoints_buf);
        if ((int )ninks > 1) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1071", "1", checkpoints_buf);


        tmp___15 = __rawmemchr((void const   *)cp, '\000');


        cp = (char const   *)((char *)tmp___15);

        cp ++;



        tmp___17 = strlen(cp);


        inknameslen = (int )((size_t )inknameslen + (tmp___17 + 1U));
        sprintf(checkpoints_buf, "%d", inknameslen);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1078", "inknameslen", checkpoints_buf);
        ninks = (uint16 )((int )ninks - 1);

      }
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1070", "1", checkpoints_buf);






      sprintf(checkpoints_buf, "%d", inknameslen);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1070", "inknameslen", checkpoints_buf);


      TIFFSetField(out, (uint32 )333, inknameslen, inknames);

    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___18);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1066", "tmp___18", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___19);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1063", "tmp___19", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___21);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1083", "tmp___21", checkpoints_buf);

  tmp___21 = TIFFGetField(in, (uint32 )297, & pg0, & pg1);
  sprintf(checkpoints_buf, "%d", tmp___21);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1083", "tmp___21", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___21);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1084", "tmp___21", checkpoints_buf);
  if (tmp___21) {
    sprintf(checkpoints_buf, "%d", pageNum);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1085", "pageNum", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1085", "0", checkpoints_buf);
    if (pageNum < 0) {

      TIFFSetField(out, (uint32 )297, (int )pg0, (int )pg1);

    } else {
      tmp___20 = pageNum;
      sprintf(checkpoints_buf, "%d", tmp___20);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1087", "tmp___20", checkpoints_buf);
      pageNum ++;
      sprintf(checkpoints_buf, "%d", pageNum);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1088", "pageNum", checkpoints_buf);

      TIFFSetField(out, (uint32 )297, tmp___20, 0);

    }
    sprintf(checkpoints_buf, "%d", pageNum);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1085", "pageNum", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1085", "0", checkpoints_buf);
  } else {

  }
  sprintf(checkpoints_buf, "%d", tmp___21);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1084", "tmp___21", checkpoints_buf);
  p = tags;



  while ((unsigned int )p < (unsigned int )(& tags[sizeof(tags) / sizeof(tags[0])])) {

    cpTag(in, out, p->tag, p->count, p->type);

    p ++;

  }




  cf = pickCopyFunc(in, out, bitspersample, samplesperpixel);



  if (cf) {
    sprintf(checkpoints_buf, "%d", tmp___22);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1100", "tmp___22", checkpoints_buf);

    tmp___22 = (*cf)(in, out, length, width, samplesperpixel);
    sprintf(checkpoints_buf, "%d", tmp___22);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1100", "tmp___22", checkpoints_buf);

    tmp___23 = tmp___22;
    sprintf(checkpoints_buf, "%d", tmp___23);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1101", "tmp___23", checkpoints_buf);
  } else {
    tmp___23 = 0;
    sprintf(checkpoints_buf, "%d", tmp___23);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1102", "tmp___23", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", tmp___23);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1103", "tmp___23", checkpoints_buf);
  return (tmp___23);
}
}
static int cpContig2ContigByRow(TIFF *in , TIFF *out , uint32 imagelength ,
                                uint32 imagewidth , tsample_t spp ) 
{ 
  tdata_t buf ;
  tmsize_t tmp ;
  void *tmp___0 ;
  uint32 row ;
  char const   *tmp___1 ;
  int tmp___2 ;
  char const   *tmp___3 ;
  int tmp___4 ;

  {


  tmp = TIFFScanlineSize(in);




  tmp___0 = _TIFFmalloc(tmp);


  buf = tmp___0;

  row = (uint32 )0;



  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "0", checkpoints_buf);

  while (row < imagelength) {


    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1112", "tmp___2", checkpoints_buf);

    tmp___2 = TIFFReadScanline(in, buf, row, (uint16 )0);
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1112", "tmp___2", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1113", "tmp___2", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1113", "0", checkpoints_buf);
    if (tmp___2 < 0) {
      sprintf(checkpoints_buf, "%d", ignore);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1114", "ignore", checkpoints_buf);
      if (! ignore) {


        tmp___1 = TIFFFileName(in);



        TIFFError(tmp___1, "Error, can\'t read scanline %lu",
                  (unsigned long )row);

        goto bad;
      } else {

      }
      sprintf(checkpoints_buf, "%d", ignore);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1114", "ignore", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1113", "tmp___2", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1113", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1120", "tmp___4", checkpoints_buf);

    tmp___4 = TIFFWriteScanline(out, buf, row, (uint16 )0);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1120", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1121", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1121", "0", checkpoints_buf);
    if (tmp___4 < 0) {


      tmp___3 = TIFFFileName(out);



      TIFFError(tmp___3, "Error, can\'t write scanline %lu", (unsigned long )row);

      goto bad;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1121", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1121", "0", checkpoints_buf);
    row ++;

  }


  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1108", "0", checkpoints_buf);


  _TIFFfree(buf);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1128", "1", checkpoints_buf);
  return (1);

  bad: 
  _TIFFfree(buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1130", "0", checkpoints_buf);
  return (0);
}
}
static void subtract8(void *i , void *b , uint32 pixels ) 
{ 
  uint8 *image ;
  uint8 *bias___0 ;
  uint32 tmp ;

  {
  image = (uint8 *)i;

  bias___0 = (uint8 *)b;






  while (1) {
    tmp = pixels;

    pixels --;


    if (tmp) {

    } else {
      break;
    }

    if ((int )*image > (int )*bias___0) {
      *image = (uint8 )((int )*image - (int )*bias___0);

    } else {
      *image = (uint8 )0;

    }
    image ++;

    bias___0 ++;

  }





  return;
}
}
static void subtract16(void *i , void *b , uint32 pixels ) 
{ 
  uint16 *image ;
  uint16 *bias___0 ;
  uint32 tmp ;

  {
  image = (uint16 *)i;

  bias___0 = (uint16 *)b;






  while (1) {
    tmp = pixels;

    pixels --;


    if (tmp) {

    } else {
      break;
    }

    if ((int )*image > (int )*bias___0) {
      *image = (uint16 )((int )*image - (int )*bias___0);

    } else {
      *image = (uint16 )0;

    }
    image ++;

    bias___0 ++;

  }





  return;
}
}
static void subtract32(void *i , void *b , uint32 pixels ) 
{ 
  uint32 *image ;
  uint32 *bias___0 ;
  uint32 tmp ;

  {
  image = (uint32 *)i;

  bias___0 = (uint32 *)b;








  while (1) {
    tmp = pixels;

    pixels --;


    if (tmp) {

    } else {
      break;
    }



    if (*image > *bias___0) {
      *image -= *bias___0;

    } else {
      *image = (uint32 )0;

    }


    image ++;

    bias___0 ++;

  }







  return;
}
}
static biasFn *lineSubtractFn(unsigned int bits ) 
{ 


  {
  switch (bits) {
  case 8U: 
  return (& subtract8);
  case 16U: 
  return (& subtract16);
  case 32U: 
  return (& subtract32);
  }
  return ((biasFn *)((void *)0));
}
}
static int cpBiasedContig2Contig(TIFF *in , TIFF *out , uint32 imagelength ,
                                 uint32 imagewidth , tsample_t spp ) 
{ 
  tsize_t biasSize ;
  tmsize_t tmp ;
  tsize_t bufSize ;
  tmsize_t tmp___0 ;
  tdata_t buf ;
  tdata_t biasBuf ;
  uint32 biasWidth ;
  uint32 biasLength ;
  uint16 sampleBits ;
  biasFn *subtractLine ;
  uint32 row ;
  char const   *tmp___1 ;
  int tmp___2 ;
  char const   *tmp___3 ;
  int tmp___4 ;
  char const   *tmp___5 ;
  int tmp___6 ;
  uint16 tmp___7 ;
  char const   *tmp___8 ;
  uint16 tmp___9 ;
  char const   *tmp___10 ;
  uint16 tmp___11 ;
  char const   *tmp___12 ;
  char const   *tmp___13 ;
  uint16 tmp___14 ;
  char const   *tmp___15 ;
  char const   *tmp___16 ;

  {
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1178", "1", checkpoints_buf);
  if ((int )spp == 1) {


    tmp = TIFFScanlineSize(bias);


    biasSize = tmp;



    tmp___0 = TIFFScanlineSize(in);


    bufSize = tmp___0;

    biasWidth = (uint32 )0;

    biasLength = (uint32 )0;


    TIFFGetField(bias, (uint32 )256, & biasWidth);


    TIFFGetField(bias, (uint32 )257, & biasLength);



    if (biasSize == bufSize) {


      if (imagelength == biasLength) {


        if (imagewidth == biasWidth) {
          sampleBits = (uint16 )0;


          TIFFGetField(in, (uint32 )258, & sampleBits);



          subtractLine = lineSubtractFn((unsigned int )sampleBits);



          if (subtractLine) {


            buf = _TIFFmalloc(bufSize);




            biasBuf = _TIFFmalloc(bufSize);


            row = (uint32 )0;



            sprintf(checkpoints_buf, "%d", tmp___2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___2", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___2", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "0", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___4", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___4", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "0", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___6", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___6", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "0", checkpoints_buf);

            while (row < imagelength) {


              sprintf(checkpoints_buf, "%d", tmp___2);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1201", "tmp___2", checkpoints_buf);

              tmp___2 = TIFFReadScanline(in, buf, row, (uint16 )0);
              sprintf(checkpoints_buf, "%d", tmp___2);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1201", "tmp___2", checkpoints_buf);

              sprintf(checkpoints_buf, "%d", tmp___2);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1202", "tmp___2", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1202", "0", checkpoints_buf);
              if (tmp___2 < 0) {
                sprintf(checkpoints_buf, "%d", ignore);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "1203", "ignore", checkpoints_buf);
                if (! ignore) {


                  tmp___1 = TIFFFileName(in);



                  TIFFError(tmp___1, "Error, can\'t read scanline %lu",
                            (unsigned long )row);

                  goto bad;
                } else {

                }
                sprintf(checkpoints_buf, "%d", ignore);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "1203", "ignore", checkpoints_buf);
              } else {

              }
              sprintf(checkpoints_buf, "%d", tmp___2);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1202", "tmp___2", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1202", "0", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", tmp___4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1209", "tmp___4", checkpoints_buf);

              tmp___4 = TIFFReadScanline(bias, biasBuf, row, (uint16 )0);
              sprintf(checkpoints_buf, "%d", tmp___4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1209", "tmp___4", checkpoints_buf);

              sprintf(checkpoints_buf, "%d", tmp___4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1210", "tmp___4", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1210", "0", checkpoints_buf);
              if (tmp___4 < 0) {
                sprintf(checkpoints_buf, "%d", ignore);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "1211", "ignore", checkpoints_buf);
                if (! ignore) {


                  tmp___3 = TIFFFileName(in);



                  TIFFError(tmp___3, "Error, can\'t read biased scanline %lu",
                            (unsigned long )row);

                  goto bad;
                } else {

                }
                sprintf(checkpoints_buf, "%d", ignore);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                                "1211", "ignore", checkpoints_buf);
              } else {

              }
              sprintf(checkpoints_buf, "%d", tmp___4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1210", "tmp___4", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1210", "0", checkpoints_buf);

              (*subtractLine)(buf, biasBuf, imagewidth);

              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1218", "tmp___6", checkpoints_buf);

              tmp___6 = TIFFWriteScanline(out, buf, row, (uint16 )0);
              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1218", "tmp___6", checkpoints_buf);

              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1219", "tmp___6", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1219", "0", checkpoints_buf);
              if (tmp___6 < 0) {


                tmp___5 = TIFFFileName(out);



                TIFFError(tmp___5, "Error, can\'t write scanline %lu",
                          (unsigned long )row);

                goto bad;
              } else {

              }
              sprintf(checkpoints_buf, "%d", tmp___6);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1219", "tmp___6", checkpoints_buf);
              sprintf(checkpoints_buf, "%d", 0);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                              "1219", "0", checkpoints_buf);
              row ++;

            }


            sprintf(checkpoints_buf, "%d", tmp___2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___2", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___2);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___2", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "0", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___4", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___4", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "0", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___6", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___6);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "tmp___6", checkpoints_buf);
            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1197", "0", checkpoints_buf);


            _TIFFfree(buf);


            _TIFFfree(biasBuf);



            tmp___7 = TIFFCurrentDirectory(bias);



            TIFFSetDirectory(bias, tmp___7);

            sprintf(checkpoints_buf, "%d", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1229", "1", checkpoints_buf);
            return (1);

            bad: 
            _TIFFfree(buf);


            _TIFFfree(biasBuf);

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1232", "0", checkpoints_buf);
            return (0);
          } else {


            tmp___8 = TIFFFileName(in);



            TIFFError(tmp___8, "No support for biasing %d bit pixels\n",
                      (int )sampleBits);

            sprintf(checkpoints_buf, "%d", 0);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1235", "0", checkpoints_buf);
            return (0);
          }

        } else {

        }


      } else {

      }


    } else {

    }




    tmp___9 = TIFFCurrentDirectory(in);




    tmp___10 = TIFFFileName(in);




    tmp___11 = TIFFCurrentDirectory(bias);




    tmp___12 = TIFFFileName(bias);




    tmp___13 = TIFFFileName(in);



    TIFFError(tmp___13, "Bias image %s,%d\nis not the same size as %s,%d\n",
              tmp___12, (int )tmp___11, tmp___10, (int )tmp___9);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1245", "0", checkpoints_buf);
    return (0);
  } else {


    tmp___14 = TIFFCurrentDirectory(in);




    tmp___15 = TIFFFileName(in);




    tmp___16 = TIFFFileName(in);



    TIFFError(tmp___16, "Can\'t bias %s,%d as it has >1 Sample/Pixel\n",
              tmp___15, (int )tmp___14);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1250", "0", checkpoints_buf);
    return (0);
  }
  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1178", "1", checkpoints_buf);
}
}
static int cpDecodedStrips(TIFF *in , TIFF *out , uint32 imagelength ,
                           uint32 imagewidth , tsample_t spp ) 
{ 
  tsize_t stripsize ;
  tmsize_t tmp ;
  tdata_t buf ;
  void *tmp___0 ;
  tstrip_t s ;
  tstrip_t ns ;
  uint32 tmp___1 ;
  uint32 row ;
  tsize_t cc ;
  tmsize_t tmp___2 ;
  tmsize_t tmp___3 ;
  char const   *tmp___4 ;
  tmsize_t tmp___5 ;
  char const   *tmp___6 ;
  tmsize_t tmp___7 ;
  char const   *tmp___8 ;

  {


  tmp = TIFFStripSize(in);


  stripsize = tmp;



  tmp___0 = _TIFFmalloc(stripsize);


  buf = tmp___0;


  if (buf) {


    tmp___1 = TIFFNumberOfStrips(in);


    ns = tmp___1;

    row = (uint32 )0;

    s = (tstrip_t )0;










    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1260", "0", checkpoints_buf);



    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1260", "0", checkpoints_buf);


    while (s < ns) {





      if (row + rowsperstrip > imagelength) {


        tmp___2 = TIFFVStripSize(in, imagelength - row);


        tmp___3 = tmp___2;

      } else {
        tmp___3 = stripsize;

      }



      cc = tmp___3;



      tmp___5 = TIFFReadEncodedStrip(in, s, buf, cc);



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1270", "0", checkpoints_buf);
      if (tmp___5 < 0L) {
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1271", "ignore", checkpoints_buf);
        if (! ignore) {


          tmp___4 = TIFFFileName(in);



          TIFFError(tmp___4, "Error, can\'t read strip %lu", (unsigned long )s);

          goto bad;
        } else {

        }
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1271", "ignore", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1270", "0", checkpoints_buf);


      tmp___7 = TIFFWriteEncodedStrip(out, s, buf, cc);



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1278", "0", checkpoints_buf);
      if (tmp___7 < 0L) {


        tmp___6 = TIFFFileName(out);



        TIFFError(tmp___6, "Error, can\'t write strip %lu", (unsigned long )s);

        goto bad;
      } else {

      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1278", "0", checkpoints_buf);
      row += rowsperstrip;

      s ++;

    }









    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1260", "0", checkpoints_buf);



    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1260", "0", checkpoints_buf);



    _TIFFfree(buf);

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1286", "1", checkpoints_buf);
    return (1);
  } else {


    tmp___8 = TIFFFileName(in);



    TIFFError(tmp___8,
              "Error, can\'t allocate memory buffer of size %lu to read strips",
              (unsigned long )stripsize);

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1289", "0", checkpoints_buf);
    return (0);
  }


  bad: 
  _TIFFfree(buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1291", "0", checkpoints_buf);
  return (0);
}
}
static int cpSeparate2SeparateByRow(TIFF *in , TIFF *out , uint32 imagelength ,
                                    uint32 imagewidth , tsample_t spp ) 
{ 
  tdata_t buf ;
  tmsize_t tmp ;
  void *tmp___0 ;
  uint32 row ;
  tsample_t s ;
  char const   *tmp___1 ;
  int tmp___2 ;
  char const   *tmp___3 ;
  int tmp___4 ;

  {


  tmp = TIFFScanlineSize(in);




  tmp___0 = _TIFFmalloc(tmp);


  buf = tmp___0;

  s = (tsample_t )0;




  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "0", checkpoints_buf);


  while ((int )s < (int )spp) {
    row = (uint32 )0;



    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___2", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___2", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "0", checkpoints_buf);

    while (row < imagelength) {


      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1305", "tmp___2", checkpoints_buf);

      tmp___2 = TIFFReadScanline(in, buf, row, s);
      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1305", "tmp___2", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1306", "tmp___2", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1306", "0", checkpoints_buf);
      if (tmp___2 < 0) {
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1307", "ignore", checkpoints_buf);
        if (! ignore) {


          tmp___1 = TIFFFileName(in);



          TIFFError(tmp___1, "Error, can\'t read scanline %lu",
                    (unsigned long )row);

          goto bad;
        } else {

        }
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1307", "ignore", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1306", "tmp___2", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1306", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1313", "tmp___4", checkpoints_buf);

      tmp___4 = TIFFWriteScanline(out, buf, row, s);
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1313", "tmp___4", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1314", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1314", "0", checkpoints_buf);
      if (tmp___4 < 0) {


        tmp___3 = TIFFFileName(out);



        TIFFError(tmp___3, "Error, can\'t write scanline %lu",
                  (unsigned long )row);

        goto bad;
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1314", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1314", "0", checkpoints_buf);
      row ++;

    }


    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___2", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___2", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1301", "0", checkpoints_buf);

    s = (tsample_t )((int )s + 1);

  }



  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___2", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1296", "0", checkpoints_buf);



  _TIFFfree(buf);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1322", "1", checkpoints_buf);
  return (1);

  bad: 
  _TIFFfree(buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1324", "0", checkpoints_buf);
  return (0);
}
}
static int cpContig2SeparateByRow(TIFF *in , TIFF *out , uint32 imagelength ,
                                  uint32 imagewidth , tsample_t spp ) 
{ 
  tdata_t inbuf ;
  tmsize_t tmp ;
  void *tmp___0 ;
  tdata_t outbuf ;
  tmsize_t tmp___1 ;
  void *tmp___2 ;
  register uint8 *inp ;
  register uint8 *outp ;
  register uint32 n ;
  uint32 row ;
  tsample_t s ;
  char const   *tmp___3 ;
  int tmp___4 ;
  uint8 *tmp___5 ;
  uint32 tmp___6 ;
  char const   *tmp___7 ;
  int tmp___8 ;

  {


  tmp = TIFFScanlineSize(in);




  tmp___0 = _TIFFmalloc(tmp);


  inbuf = tmp___0;



  tmp___1 = TIFFScanlineSize(out);




  tmp___2 = _TIFFmalloc(tmp___1);


  outbuf = tmp___2;

  s = (tsample_t )0;




  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___8", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "0", checkpoints_buf);


  while ((int )s < (int )spp) {
    row = (uint32 )0;



    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "0", checkpoints_buf);






    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "0", checkpoints_buf);




    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___8", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "0", checkpoints_buf);

    while (row < imagelength) {


      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1341", "tmp___4", checkpoints_buf);

      tmp___4 = TIFFReadScanline(in, inbuf, row, (uint16 )0);
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1341", "tmp___4", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1342", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1342", "0", checkpoints_buf);
      if (tmp___4 < 0) {
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1343", "ignore", checkpoints_buf);
        if (! ignore) {


          tmp___3 = TIFFFileName(in);



          TIFFError(tmp___3, "Error, can\'t read scanline %lu",
                    (unsigned long )row);

          goto bad;
        } else {

        }
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1343", "ignore", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1342", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1342", "0", checkpoints_buf);
      inp = (uint8 *)inbuf + (int )s;

      outp = (uint8 *)outbuf;

      n = imagewidth;




      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1352", "0", checkpoints_buf);




      while (1) {
        tmp___6 = n;

        n --;


        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1355", "0", checkpoints_buf);
        if (tmp___6 > 0U) {

        } else {
          break;
        }

        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1355", "0", checkpoints_buf);
        tmp___5 = outp;

        outp ++;

        *tmp___5 = *inp;

        inp += (int )spp;

      }



      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1352", "0", checkpoints_buf);




      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1362", "tmp___8", checkpoints_buf);

      tmp___8 = TIFFWriteScanline(out, outbuf, row, s);
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1362", "tmp___8", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1363", "tmp___8", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1363", "0", checkpoints_buf);
      if (tmp___8 < 0) {


        tmp___7 = TIFFFileName(out);



        TIFFError(tmp___7, "Error, can\'t write scanline %lu",
                  (unsigned long )row);

        goto bad;
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___8);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1363", "tmp___8", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1363", "0", checkpoints_buf);
      row ++;

    }


    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "0", checkpoints_buf);






    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "0", checkpoints_buf);




    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___8", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1337", "0", checkpoints_buf);

    s = (tsample_t )((int )s + 1);

  }



  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___8", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1332", "0", checkpoints_buf);



  if (inbuf) {

    _TIFFfree(inbuf);

  } else {

  }


  if (outbuf) {

    _TIFFfree(outbuf);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1376", "1", checkpoints_buf);
  return (1);

  bad: 
  if (inbuf) {

    _TIFFfree(inbuf);

  } else {

  }


  if (outbuf) {

    _TIFFfree(outbuf);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1383", "0", checkpoints_buf);
  return (0);
}
}
static int cpSeparate2ContigByRow(TIFF *in , TIFF *out , uint32 imagelength ,
                                  uint32 imagewidth , tsample_t spp ) 
{ 
  tdata_t inbuf ;
  tmsize_t tmp ;
  void *tmp___0 ;
  tdata_t outbuf ;
  tmsize_t tmp___1 ;
  void *tmp___2 ;
  register uint8 *inp ;
  register uint8 *outp ;
  register uint32 n ;
  uint32 row ;
  tsample_t s ;
  char const   *tmp___3 ;
  int tmp___4 ;
  uint8 *tmp___5 ;
  uint32 tmp___6 ;
  char const   *tmp___7 ;
  int tmp___8 ;

  {


  tmp = TIFFScanlineSize(in);




  tmp___0 = _TIFFmalloc(tmp);


  inbuf = tmp___0;



  tmp___1 = TIFFScanlineSize(out);




  tmp___2 = _TIFFmalloc(tmp___1);


  outbuf = tmp___2;

  row = (uint32 )0;




  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "0", checkpoints_buf);





  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___8", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "0", checkpoints_buf);

  while (row < imagelength) {


    s = (tsample_t )0;

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "0", checkpoints_buf);






    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "0", checkpoints_buf);





    while ((int )s < (int )spp) {
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1400", "tmp___4", checkpoints_buf);

      tmp___4 = TIFFReadScanline(in, inbuf, row, s);
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1400", "tmp___4", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1401", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1401", "0", checkpoints_buf);
      if (tmp___4 < 0) {
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1402", "ignore", checkpoints_buf);
        if (! ignore) {


          tmp___3 = TIFFFileName(in);



          TIFFError(tmp___3, "Error, can\'t read scanline %lu",
                    (unsigned long )row);

          goto bad;
        } else {

        }
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1402", "ignore", checkpoints_buf);
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1401", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1401", "0", checkpoints_buf);
      inp = (uint8 *)inbuf;

      outp = (uint8 *)outbuf + (int )s;

      n = imagewidth;




      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1411", "0", checkpoints_buf);




      while (1) {
        tmp___6 = n;

        n --;


        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1414", "0", checkpoints_buf);
        if (tmp___6 > 0U) {

        } else {
          break;
        }

        sprintf(checkpoints_buf, "%u", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1414", "0", checkpoints_buf);
        tmp___5 = inp;

        inp ++;

        *outp = *tmp___5;

        outp += (int )spp;

      }



      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1411", "0", checkpoints_buf);




      s = (tsample_t )((int )s + 1);

    }
    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "tmp___4", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___4);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "tmp___4", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "0", checkpoints_buf);






    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1396", "0", checkpoints_buf);





    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1422", "tmp___8", checkpoints_buf);

    tmp___8 = TIFFWriteScanline(out, outbuf, row, (uint16 )0);
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1422", "tmp___8", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1423", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1423", "0", checkpoints_buf);
    if (tmp___8 < 0) {


      tmp___7 = TIFFFileName(out);



      TIFFError(tmp___7, "Error, can\'t write scanline %lu", (unsigned long )row);

      goto bad;
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1423", "tmp___8", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1423", "0", checkpoints_buf);
    row ++;

  }



  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___4", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___4);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___4", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "0", checkpoints_buf);





  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___8", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "tmp___8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1391", "0", checkpoints_buf);


  if (inbuf) {

    _TIFFfree(inbuf);

  } else {

  }


  if (outbuf) {

    _TIFFfree(outbuf);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1435", "1", checkpoints_buf);
  return (1);

  bad: 
  if (inbuf) {

    _TIFFfree(inbuf);

  } else {

  }


  if (outbuf) {

    _TIFFfree(outbuf);

  } else {

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1442", "0", checkpoints_buf);
  return (0);
}
}
static void cpStripToTile(uint8 *out , uint8 *in , uint32 rows , uint32 cols ,
                          int outskew , int inskew ) 
{ 
  uint32 j ;
  uint8 *tmp ;
  uint8 *tmp___0 ;
  uint32 tmp___1 ;
  uint32 tmp___2 ;

  {



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1443", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1443", "0", checkpoints_buf);







  while (1) {
    tmp___2 = rows;

    rows --;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1446", "0", checkpoints_buf);
    if (tmp___2 > 0U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1446", "0", checkpoints_buf);
    j = cols;




    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1450", "0", checkpoints_buf);





    while (1) {
      tmp___1 = j;

      j --;


      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1453", "0", checkpoints_buf);
      if (tmp___1 > 0U) {

      } else {
        break;
      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1453", "0", checkpoints_buf);
      tmp = out;

      out ++;

      tmp___0 = in;

      in ++;

      *tmp = *tmp___0;

    }



    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1450", "0", checkpoints_buf);





    out += outskew;

    in += inskew;

  }



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1443", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1443", "0", checkpoints_buf);







  return;
}
}
static void cpContigBufToSeparateBuf(uint8 *out , uint8 *in , uint32 rows ,
                                     uint32 cols , int outskew , int inskew ,
                                     tsample_t spp , int bytes_per_sample ) 
{ 
  uint32 j ;
  int n ;
  uint8 *tmp ;
  uint8 *tmp___0 ;
  int tmp___1 ;
  uint32 tmp___2 ;
  uint32 tmp___3 ;

  {



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "tmp___1", checkpoints_buf);








  while (1) {
    tmp___3 = rows;

    rows --;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1467", "0", checkpoints_buf);
    if (tmp___3 > 0U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1467", "0", checkpoints_buf);
    j = cols;




    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "tmp___1", checkpoints_buf);






    while (1) {
      tmp___2 = j;

      j --;


      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1474", "0", checkpoints_buf);
      if (tmp___2 > 0U) {

      } else {
        break;
      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1474", "0", checkpoints_buf);
      n = bytes_per_sample;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1477", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1478", "tmp___1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1478", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1478", "tmp___1", checkpoints_buf);





      while (1) {
        tmp___1 = n;
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1479", "tmp___1", checkpoints_buf);
        n --;
        sprintf(checkpoints_buf, "%d", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1480", "n", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1481", "tmp___1", checkpoints_buf);
        if (tmp___1) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1481", "tmp___1", checkpoints_buf);
        tmp = out;

        out ++;

        tmp___0 = in;

        in ++;

        *tmp = *tmp___0;

      }
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1478", "tmp___1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1478", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1478", "tmp___1", checkpoints_buf);





      in += ((int )spp - 1) * bytes_per_sample;

    }



    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1471", "tmp___1", checkpoints_buf);






    out += outskew;

    in += inskew;

  }



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1464", "tmp___1", checkpoints_buf);








  return;
}
}
static void cpSeparateBufToContigBuf(uint8 *out , uint8 *in , uint32 rows ,
                                     uint32 cols , int outskew , int inskew ,
                                     tsample_t spp , int bytes_per_sample ) 
{ 
  uint32 j ;
  int n ;
  uint8 *tmp ;
  uint8 *tmp___0 ;
  int tmp___1 ;
  uint32 tmp___2 ;
  uint32 tmp___3 ;

  {



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "tmp___1", checkpoints_buf);








  while (1) {
    tmp___3 = rows;

    rows --;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1496", "0", checkpoints_buf);
    if (tmp___3 > 0U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1496", "0", checkpoints_buf);
    j = cols;




    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "tmp___1", checkpoints_buf);






    while (1) {
      tmp___2 = j;

      j --;


      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1503", "0", checkpoints_buf);
      if (tmp___2 > 0U) {

      } else {
        break;
      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1503", "0", checkpoints_buf);
      n = bytes_per_sample;
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1506", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1507", "tmp___1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1507", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1507", "tmp___1", checkpoints_buf);





      while (1) {
        tmp___1 = n;
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1508", "tmp___1", checkpoints_buf);
        n --;
        sprintf(checkpoints_buf, "%d", n);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1509", "n", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1510", "tmp___1", checkpoints_buf);
        if (tmp___1) {

        } else {
          break;
        }
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1510", "tmp___1", checkpoints_buf);
        tmp = out;

        out ++;

        tmp___0 = in;

        in ++;

        *tmp = *tmp___0;

      }
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1507", "tmp___1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", n);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1507", "n", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1507", "tmp___1", checkpoints_buf);





      out += ((int )spp - 1) * bytes_per_sample;

    }



    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", n);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "n", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1500", "tmp___1", checkpoints_buf);






    out += outskew;

    in += inskew;

  }



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "0", checkpoints_buf);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "0", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", n);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "n", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1493", "tmp___1", checkpoints_buf);








  return;
}
}
static int cpImage(TIFF *in , TIFF *out ,
                   int (*fin)(TIFF * , uint8 * , uint32  , uint32  , tsample_t  ) ,
                   int (*fout)(TIFF * , uint8 * , uint32  , uint32  ,
                               tsample_t  ) , uint32 imagelength ,
                   uint32 imagewidth , tsample_t spp ) 
{ 
  int status ;
  tdata_t buf ;
  tsize_t scanlinesize ;
  tmsize_t tmp ;
  tsize_t bytes ;
  int tmp___0 ;
  char const   *tmp___1 ;
  char const   *tmp___2 ;

  {
  status = 0;
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1522", "status", checkpoints_buf);
  buf = (void *)0;



  tmp = TIFFRasterScanlineSize(in);


  scanlinesize = tmp;

  bytes = scanlinesize * (tsize_t )imagelength;


  if (scanlinesize) {

    if (imagelength) {


      if (bytes / (tsize_t )imagelength == scanlinesize) {


        buf = _TIFFmalloc(bytes);



        if (buf) {
          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1532", "tmp___0", checkpoints_buf);

          tmp___0 = (*fin)(in, (uint8 *)buf, imagelength, imagewidth, spp);
          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1532", "tmp___0", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1533", "tmp___0", checkpoints_buf);
          if (tmp___0) {
            sprintf(checkpoints_buf, "%d", status);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1534", "status", checkpoints_buf);

            status = (*fout)(out, (uint8 *)buf, imagelength, imagewidth, spp);
            sprintf(checkpoints_buf, "%d", status);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1534", "status", checkpoints_buf);

          } else {

          }
          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1533", "tmp___0", checkpoints_buf);

          _TIFFfree(buf);

        } else {


          tmp___1 = TIFFFileName(in);



          TIFFError(tmp___1, "Error, can\'t allocate space for image buffer");

        }

      } else {


        tmp___2 = TIFFFileName(in);



        TIFFError(tmp___2, "Error, no space for image buffer");

      }


    } else {


      tmp___2 = TIFFFileName(in);



      TIFFError(tmp___2, "Error, no space for image buffer");

    }

  } else {


    tmp___2 = TIFFFileName(in);



    TIFFError(tmp___2, "Error, no space for image buffer");

  }

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1545", "status", checkpoints_buf);
  return (status);
}
}
static int readContigStripsIntoBuffer(TIFF *in , uint8 *buf ,
                                      uint32 imagelength , uint32 imagewidth ,
                                      tsample_t spp ) 
{ 
  tsize_t scanlinesize ;
  tmsize_t tmp ;
  uint8 *bufp ;
  uint32 row ;
  char const   *tmp___0 ;
  int tmp___1 ;

  {


  tmp = TIFFScanlineSize(in);


  scanlinesize = tmp;

  bufp = buf;

  row = (uint32 )0;



  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1550", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1550", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1550", "0", checkpoints_buf);


  while (row < imagelength) {


    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1554", "tmp___1", checkpoints_buf);

    tmp___1 = TIFFReadScanline(in, (tdata_t )bufp, row, (uint16 )0);
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1554", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1555", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1555", "0", checkpoints_buf);
    if (tmp___1 < 0) {
      sprintf(checkpoints_buf, "%d", ignore);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1556", "ignore", checkpoints_buf);
      if (! ignore) {


        tmp___0 = TIFFFileName(in);



        TIFFError(tmp___0, "Error, can\'t read scanline %lu",
                  (unsigned long )row);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1559", "0", checkpoints_buf);
        return (0);
      } else {

      }
      sprintf(checkpoints_buf, "%d", ignore);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1556", "ignore", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1555", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1555", "0", checkpoints_buf);
    bufp += scanlinesize;

    row ++;

  }


  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1550", "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1550", "tmp___1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1550", "0", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1564", "1", checkpoints_buf);
  return (1);
}
}
static int readSeparateStripsIntoBuffer(TIFF *in , uint8 *buf ,
                                        uint32 imagelength , uint32 imagewidth ,
                                        tsample_t spp ) 
{ 
  int status ;
  tsize_t scanlinesize ;
  tmsize_t tmp ;
  tdata_t scanline ;
  uint8 *bufp ;
  uint32 row ;
  tsample_t s ;
  uint8 *bp ;
  tsize_t n ;
  uint8 *sbuf ;
  char const   *tmp___0 ;
  int tmp___1 ;
  uint8 *tmp___2 ;
  tsize_t tmp___3 ;

  {
  status = 1;
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1565", "status", checkpoints_buf);


  tmp = TIFFScanlineSize(in);


  scanlinesize = tmp;


  if (! scanlinesize) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1569", "0", checkpoints_buf);
    return (0);
  } else {

  }



  scanline = _TIFFmalloc(scanlinesize);



  if (scanline) {
    bufp = buf;

    row = (uint32 )0;







    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "0", checkpoints_buf);



    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "0", checkpoints_buf);







    while (row < imagelength) {


      s = (tsample_t )0;




      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "tmp___1", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "tmp___1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "0", checkpoints_buf);



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "0", checkpoints_buf);





      while ((int )s < (int )spp) {
        bp = bufp + (int )s;

        n = scanlinesize;

        sbuf = (uint8 *)scanline;

        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1587", "tmp___1", checkpoints_buf);

        tmp___1 = TIFFReadScanline(in, scanline, row, s);
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1587", "tmp___1", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1588", "tmp___1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1588", "0", checkpoints_buf);
        if (tmp___1 < 0) {
          sprintf(checkpoints_buf, "%d", ignore);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1589", "ignore", checkpoints_buf);
          if (! ignore) {


            tmp___0 = TIFFFileName(in);



            TIFFError(tmp___0, "Error, can\'t read scanline %lu",
                      (unsigned long )row);

            status = 0;
            sprintf(checkpoints_buf, "%d", status);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1592", "status", checkpoints_buf);
            goto done;
          } else {

          }
          sprintf(checkpoints_buf, "%d", ignore);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1589", "ignore", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", tmp___1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1588", "tmp___1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1588", "0", checkpoints_buf);



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1596", "0", checkpoints_buf);




        while (1) {
          tmp___3 = n;

          n --;


          sprintf(checkpoints_buf, "%ld", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1599", "0", checkpoints_buf);
          if (tmp___3 > 0L) {

          } else {
            break;
          }

          sprintf(checkpoints_buf, "%ld", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1599", "0", checkpoints_buf);
          tmp___2 = sbuf;

          sbuf ++;

          *bp = *tmp___2;

          bp += (int )spp;

        }



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1596", "0", checkpoints_buf);




        s = (tsample_t )((int )s + 1);

      }



      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "tmp___1", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "tmp___1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "0", checkpoints_buf);



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1580", "0", checkpoints_buf);





      bufp += scanlinesize * (tsize_t )spp;

      row ++;

    }






    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "tmp___1", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "tmp___1", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "0", checkpoints_buf);



    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1575", "0", checkpoints_buf);







  } else {

  }


  done: 
  _TIFFfree(scanline);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1611", "status", checkpoints_buf);
  return (status);
}
}
static int readContigTilesIntoBuffer(TIFF *in , uint8 *buf ,
                                     uint32 imagelength , uint32 imagewidth ,
                                     tsample_t spp ) 
{ 
  int status ;
  tdata_t tilebuf ;
  tmsize_t tmp ;
  void *tmp___0 ;
  uint32 imagew ;
  tmsize_t tmp___1 ;
  uint32 tilew ;
  tmsize_t tmp___2 ;
  int iskew ;
  uint8 *bufp ;
  uint32 tw ;
  uint32 tl ;
  uint32 row ;
  uint32 nrow ;
  uint32 tmp___3 ;
  uint32 colb ;
  uint32 col ;
  char const   *tmp___4 ;
  tmsize_t tmp___5 ;
  uint32 width ;
  uint32 oskew ;

  {
  status = 1;
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1612", "status", checkpoints_buf);


  tmp = TIFFTileSize(in);




  tmp___0 = _TIFFmalloc(tmp);


  tilebuf = tmp___0;



  tmp___1 = TIFFScanlineSize(in);


  imagew = (uint32 )tmp___1;



  tmp___2 = TIFFTileRowSize(in);


  tilew = (uint32 )tmp___2;

  iskew = (int )(imagew - tilew);
  sprintf(checkpoints_buf, "%d", iskew);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1620", "iskew", checkpoints_buf);
  bufp = buf;

  if ((unsigned int )tilebuf == (unsigned int )((tdata_t )0)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1623", "0", checkpoints_buf);
    return (0);
  } else {

  }

  TIFFGetField(in, (uint32 )322, & tw);


  TIFFGetField(in, (uint32 )323, & tl);

  row = (uint32 )0;














  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1628", "0", checkpoints_buf);







  while (row < imagelength) {





    if (row + tl > imagelength) {
      tmp___3 = imagelength - row;

    } else {
      tmp___3 = tl;

    }



    nrow = tmp___3;

    colb = (uint32 )0;

    col = (uint32 )0;






    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1638", "0", checkpoints_buf);





    while (col < imagewidth) {




      tmp___5 = TIFFReadTile(in, tilebuf, col, row, (uint32 )0, (uint16 )0);



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1643", "0", checkpoints_buf);
      if (tmp___5 < 0L) {
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1644", "ignore", checkpoints_buf);
        if (! ignore) {


          tmp___4 = TIFFFileName(in);



          TIFFError(tmp___4, "Error, can\'t read tile at %lu %lu",
                    (unsigned long )col, (unsigned long )row);

          status = 0;
          sprintf(checkpoints_buf, "%d", status);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1647", "status", checkpoints_buf);
          goto done;
        } else {

        }
        sprintf(checkpoints_buf, "%d", ignore);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1644", "ignore", checkpoints_buf);
      } else {

      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1643", "0", checkpoints_buf);



      if (colb + tilew > imagew) {
        width = imagew - colb;

        oskew = tilew - width;


        cpStripToTile(bufp + colb, (uint8 *)tilebuf, nrow, width,
                      (int )(oskew + (uint32 )iskew), (int )oskew);

      } else {

        cpStripToTile(bufp + colb, (uint8 *)tilebuf, nrow, tilew, iskew, 0);

      }



      colb += tilew;

      col += tw;

    }





    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1638", "0", checkpoints_buf);





    bufp += imagew * nrow;

    row += tl;

  }













  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1628", "0", checkpoints_buf);








  done: 
  _TIFFfree(tilebuf);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1661", "status", checkpoints_buf);
  return (status);
}
}
static int readSeparateTilesIntoBuffer(TIFF *in , uint8 *buf ,
                                       uint32 imagelength , uint32 imagewidth ,
                                       tsample_t spp ) 
{ 
  int status ;
  uint32 imagew ;
  tmsize_t tmp ;
  uint32 tilew ;
  tmsize_t tmp___0 ;
  int iskew ;
  tdata_t tilebuf ;
  tmsize_t tmp___1 ;
  void *tmp___2 ;
  uint8 *bufp ;
  uint32 tw ;
  uint32 tl ;
  uint32 row ;
  uint16 bps ;
  uint16 bytes_per_sample ;
  uint32 nrow ;
  uint32 tmp___3 ;
  uint32 colb ;
  uint32 col ;
  tsample_t s ;
  char const   *tmp___4 ;
  tmsize_t tmp___5 ;
  uint32 width ;
  int oskew ;

  {
  status = 1;
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1662", "status", checkpoints_buf);


  tmp = TIFFRasterScanlineSize(in);


  imagew = (uint32 )tmp;



  tmp___0 = TIFFTileRowSize(in);


  tilew = (uint32 )tmp___0;

  iskew = (int )(imagew - tilew * (uint32 )spp);
  sprintf(checkpoints_buf, "%d", iskew);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1667", "iskew", checkpoints_buf);


  tmp___1 = TIFFTileSize(in);




  tmp___2 = _TIFFmalloc(tmp___1);


  tilebuf = tmp___2;

  bufp = buf;

  if ((unsigned int )tilebuf == (unsigned int )((tdata_t )0)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1673", "0", checkpoints_buf);
    return (0);
  } else {

  }

  TIFFGetField(in, (uint32 )322, & tw);


  TIFFGetField(in, (uint32 )323, & tl);


  TIFFGetField(in, (uint32 )258, & bps);

  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1678", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1678", "0", checkpoints_buf);
  if ((int )bps % 8 == 0) {

  } else {

    __assert_fail("bps % 8 == 0", "tiffcp.c", 1285U,
                  "readSeparateTilesIntoBuffer");

  }
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1678", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1678", "0", checkpoints_buf);
  bytes_per_sample = (uint16 )((int )bps / 8);

  row = (uint32 )0;















  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1683", "0", checkpoints_buf);








  while (row < imagelength) {





    if (row + tl > imagelength) {
      tmp___3 = imagelength - row;

    } else {
      tmp___3 = tl;

    }



    nrow = tmp___3;

    colb = (uint32 )0;

    col = (uint32 )0;







    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1693", "0", checkpoints_buf);






    while (col < imagewidth) {


      s = (tsample_t )0;




      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1698", "0", checkpoints_buf);




      while ((int )s < (int )spp) {


        tmp___5 = TIFFReadTile(in, tilebuf, col, row, (uint32 )0, s);



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1703", "0", checkpoints_buf);
        if (tmp___5 < 0L) {
          sprintf(checkpoints_buf, "%d", ignore);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1704", "ignore", checkpoints_buf);
          if (! ignore) {


            tmp___4 = TIFFFileName(in);



            TIFFError(tmp___4, "Error, can\'t read tile at %lu %lu, sample %lu",
                      (unsigned long )col, (unsigned long )row,
                      (unsigned long )s);

            status = 0;
            sprintf(checkpoints_buf, "%d", status);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1707", "status", checkpoints_buf);
            goto done;
          } else {

          }
          sprintf(checkpoints_buf, "%d", ignore);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1704", "ignore", checkpoints_buf);
        } else {

        }

        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1703", "0", checkpoints_buf);



        if (colb + tilew * (uint32 )spp > imagew) {
          width = imagew - colb;

          oskew = (int )(tilew * (uint32 )spp - width);
          sprintf(checkpoints_buf, "%d", oskew);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1713", "oskew", checkpoints_buf);

          cpSeparateBufToContigBuf((bufp + colb) + (int )s * (int )bytes_per_sample,
                                   (uint8 *)tilebuf, nrow,
                                   width / (uint32 )((int )spp * (int )bytes_per_sample),
                                   oskew + iskew, oskew / (int )spp, spp,
                                   (int )bytes_per_sample);

        } else {

          cpSeparateBufToContigBuf((bufp + colb) + (int )s * (int )bytes_per_sample,
                                   (uint8 *)tilebuf, nrow, tw, iskew, 0, spp,
                                   (int )bytes_per_sample);

        }



        s = (tsample_t )((int )s + 1);

      }



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1698", "0", checkpoints_buf);




      colb += tilew * (uint32 )spp;

      col += tw;

    }






    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1693", "0", checkpoints_buf);






    bufp += imagew * nrow;

    row += tl;

  }














  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1683", "0", checkpoints_buf);









  done: 
  _TIFFfree(tilebuf);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1722", "status", checkpoints_buf);
  return (status);
}
}
static int writeBufferToContigStrips(TIFF *out , uint8 *buf ,
                                     uint32 imagelength , uint32 imagewidth ,
                                     tsample_t spp ) 
{ 
  uint32 row ;
  uint32 rowsperstrip___0 ;
  tstrip_t strip ;
  uint32 nrows ;
  uint32 tmp ;
  tsize_t stripsize ;
  tmsize_t tmp___0 ;
  char const   *tmp___1 ;
  tstrip_t tmp___2 ;
  tmsize_t tmp___3 ;

  {
  strip = (tstrip_t )0;


  TIFFGetFieldDefaulted(out, (uint32 )278, & rowsperstrip___0);

  row = (uint32 )0;















  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1726", "0", checkpoints_buf);


  while (row < imagelength) {





    if (row + rowsperstrip___0 > imagelength) {
      tmp = imagelength - row;

    } else {
      tmp = rowsperstrip___0;

    }



    nrows = tmp;



    tmp___0 = TIFFVStripSize(out, nrows);


    stripsize = tmp___0;

    tmp___2 = strip;

    strip ++;



    tmp___3 = TIFFWriteEncodedStrip(out, tmp___2, (void *)buf, stripsize);



    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1739", "0", checkpoints_buf);
    if (tmp___3 < 0L) {


      tmp___1 = TIFFFileName(out);



      TIFFError(tmp___1, "Error, can\'t write strip %u", strip - 1U);

      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1742", "0", checkpoints_buf);
      return (0);
    } else {

    }

    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1739", "0", checkpoints_buf);
    buf += stripsize;

    row += rowsperstrip___0;

  }














  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1726", "0", checkpoints_buf);


  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1746", "1", checkpoints_buf);
  return (1);
}
}
static int writeBufferToSeparateStrips(TIFF *out , uint8 *buf ,
                                       uint32 imagelength , uint32 imagewidth ,
                                       tsample_t spp ) 
{ 
  uint32 rowsize ;
  uint32 rowsperstrip___0 ;
  tdata_t obuf ;
  tmsize_t tmp ;
  void *tmp___0 ;
  tstrip_t strip ;
  tsample_t s ;
  uint32 row ;
  uint32 nrows ;
  uint32 tmp___1 ;
  tsize_t stripsize ;
  tmsize_t tmp___2 ;
  char const   *tmp___3 ;
  tstrip_t tmp___4 ;
  tmsize_t tmp___5 ;

  {
  rowsize = imagewidth * (uint32 )spp;



  tmp = TIFFStripSize(out);




  tmp___0 = _TIFFmalloc(tmp);


  obuf = tmp___0;

  strip = (tstrip_t )0;

  if ((unsigned int )obuf == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1753", "0", checkpoints_buf);
    return (0);
  } else {

  }

  TIFFGetFieldDefaulted(out, (uint32 )278, & rowsperstrip___0);

  s = (tsample_t )0;

















  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1757", "0", checkpoints_buf);


  while ((int )s < (int )spp) {
    row = (uint32 )0;
















    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1762", "0", checkpoints_buf);

    while (row < imagelength) {





      if (row + rowsperstrip___0 > imagelength) {
        tmp___1 = imagelength - row;

      } else {
        tmp___1 = rowsperstrip___0;

      }



      nrows = tmp___1;



      tmp___2 = TIFFVStripSize(out, nrows);


      stripsize = tmp___2;


      cpContigBufToSeparateBuf((uint8 *)obuf, (buf + row * rowsize) + (int )s,
                               nrows, imagewidth, 0, 0, spp, 1);

      tmp___4 = strip;

      strip ++;



      tmp___5 = TIFFWriteEncodedStrip(out, tmp___4, obuf, stripsize);



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1776", "0", checkpoints_buf);
      if (tmp___5 < 0L) {


        tmp___3 = TIFFFileName(out);



        TIFFError(tmp___3, "Error, can\'t write strip %u", strip - 1U);


        _TIFFfree(obuf);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1780", "0", checkpoints_buf);
        return (0);
      } else {

      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1776", "0", checkpoints_buf);
      row += rowsperstrip___0;

    }















    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1762", "0", checkpoints_buf);

    s = (tsample_t )((int )s + 1);

  }
















  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1757", "0", checkpoints_buf);



  _TIFFfree(obuf);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1785", "1", checkpoints_buf);
  return (1);
}
}
static int writeBufferToContigTiles(TIFF *out , uint8 *buf ,
                                    uint32 imagelength , uint32 imagewidth ,
                                    tsample_t spp ) 
{ 
  uint32 imagew ;
  tmsize_t tmp ;
  uint32 tilew ;
  tmsize_t tmp___0 ;
  int iskew ;
  tdata_t obuf ;
  tmsize_t tmp___1 ;
  void *tmp___2 ;
  uint8 *bufp ;
  uint32 tl ;
  uint32 tw ;
  uint32 row ;
  uint32 nrow ;
  uint32 tmp___3 ;
  uint32 colb ;
  uint32 col ;
  uint32 width ;
  int oskew ;
  char const   *tmp___4 ;
  tmsize_t tmp___5 ;

  {


  tmp = TIFFScanlineSize(out);


  imagew = (uint32 )tmp;



  tmp___0 = TIFFTileRowSize(out);


  tilew = (uint32 )tmp___0;

  iskew = (int )(imagew - tilew);
  sprintf(checkpoints_buf, "%d", iskew);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1790", "iskew", checkpoints_buf);


  tmp___1 = TIFFTileSize(out);




  tmp___2 = _TIFFmalloc(tmp___1);


  obuf = tmp___2;

  bufp = buf;

  if ((unsigned int )obuf == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1796", "0", checkpoints_buf);
    return (0);
  } else {

  }

  TIFFGetField(out, (uint32 )323, & tl);


  TIFFGetField(out, (uint32 )322, & tw);

  row = (uint32 )0;

















  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1801", "0", checkpoints_buf);




  while (row < imagelength) {





    if (row + tl > imagelength) {
      tmp___3 = imagelength - row;

    } else {
      tmp___3 = tl;

    }



    nrow = tmp___3;

    colb = (uint32 )0;

    col = (uint32 )0;









    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1811", "0", checkpoints_buf);


    while (col < imagewidth) {





      if (colb + tilew > imagew) {
        width = imagew - colb;

        oskew = (int )(tilew - width);
        sprintf(checkpoints_buf, "%d", oskew);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1817", "oskew", checkpoints_buf);

        cpStripToTile((uint8 *)obuf, bufp + colb, nrow, width, oskew,
                      oskew + iskew);

      } else {

        cpStripToTile((uint8 *)obuf, bufp + colb, nrow, tilew, 0, iskew);

      }





      tmp___5 = TIFFWriteTile(out, obuf, col, row, (uint32 )0, (uint16 )0);



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1821", "0", checkpoints_buf);
      if (tmp___5 < 0L) {


        tmp___4 = TIFFFileName(out);



        TIFFError(tmp___4, "Error, can\'t write tile at %lu %lu",
                  (unsigned long )col, (unsigned long )row);


        _TIFFfree(obuf);

        sprintf(checkpoints_buf, "%d", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1825", "0", checkpoints_buf);
        return (0);
      } else {

      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1821", "0", checkpoints_buf);
      colb += tilew;

      col += tw;

    }








    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1811", "0", checkpoints_buf);


    bufp += nrow * imagew;

    row += tilelength;

  }
















  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1801", "0", checkpoints_buf);





  _TIFFfree(obuf);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1832", "1", checkpoints_buf);
  return (1);
}
}
static int writeBufferToSeparateTiles(TIFF *out , uint8 *buf ,
                                      uint32 imagelength , uint32 imagewidth ,
                                      tsample_t spp ) 
{ 
  uint32 imagew ;
  tmsize_t tmp ;
  tsize_t tilew ;
  tmsize_t tmp___0 ;
  uint32 iimagew ;
  tmsize_t tmp___1 ;
  int iskew ;
  tdata_t obuf ;
  tmsize_t tmp___2 ;
  void *tmp___3 ;
  uint8 *bufp ;
  uint32 tl ;
  uint32 tw ;
  uint32 row ;
  uint16 bps ;
  uint16 bytes_per_sample ;
  uint32 nrow ;
  uint32 tmp___4 ;
  uint32 colb ;
  uint32 col ;
  tsample_t s ;
  uint32 width ;
  int oskew ;
  char const   *tmp___5 ;
  tmsize_t tmp___6 ;

  {


  tmp = TIFFScanlineSize(out);


  imagew = (uint32 )tmp;



  tmp___0 = TIFFTileRowSize(out);


  tilew = tmp___0;



  tmp___1 = TIFFRasterScanlineSize(out);


  iimagew = (uint32 )tmp___1;

  iskew = (int )((unsigned long )iimagew - (unsigned long )(tilew * (tsize_t )spp));
  sprintf(checkpoints_buf, "%d", iskew);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1839", "iskew", checkpoints_buf);


  tmp___2 = TIFFTileSize(out);




  tmp___3 = _TIFFmalloc(tmp___2);


  obuf = tmp___3;

  bufp = buf;

  if ((unsigned int )obuf == (unsigned int )((void *)0)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1845", "0", checkpoints_buf);
    return (0);
  } else {

  }

  TIFFGetField(out, (uint32 )323, & tl);


  TIFFGetField(out, (uint32 )322, & tw);


  TIFFGetField(out, (uint32 )258, & bps);

  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1850", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1850", "0", checkpoints_buf);
  if ((int )bps % 8 == 0) {

  } else {

    __assert_fail("bps % 8 == 0", "tiffcp.c", 1460U,
                  "writeBufferToSeparateTiles");

  }
  sprintf(checkpoints_buf, "%d", 8);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1850", "8", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1850", "0", checkpoints_buf);
  bytes_per_sample = (uint16 )((int )bps / 8);

  row = (uint32 )0;















  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1855", "0", checkpoints_buf);





  while (row < imagelength) {





    if (row + tl > imagelength) {
      tmp___4 = imagelength - row;

    } else {
      tmp___4 = tl;

    }



    nrow = tmp___4;

    colb = (uint32 )0;

    col = (uint32 )0;







    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1865", "0", checkpoints_buf);



    while (col < imagewidth) {


      s = (tsample_t )0;




      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1870", "0", checkpoints_buf);

      while ((int )s < (int )spp) {
        if ((unsigned long )colb + (unsigned long )tilew > (unsigned long )imagew) {
          width = imagew - colb;

          oskew = (int )((unsigned long )tilew - (unsigned long )width);
          sprintf(checkpoints_buf, "%d", oskew);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1876", "oskew", checkpoints_buf);

          cpContigBufToSeparateBuf((uint8 *)obuf,
                                   (bufp + colb * (uint32 )spp) + (int )s, nrow,
                                   width / (uint32 )bytes_per_sample, oskew,
                                   oskew * (int )spp + iskew, spp,
                                   (int )bytes_per_sample);

        } else {

          cpContigBufToSeparateBuf((uint8 *)obuf,
                                   (bufp + colb * (uint32 )spp) + (int )s, nrow,
                                   tilewidth, 0, iskew, spp,
                                   (int )bytes_per_sample);

        }


        tmp___6 = TIFFWriteTile(out, obuf, col, row, (uint32 )0, s);



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1880", "0", checkpoints_buf);
        if (tmp___6 < 0L) {


          tmp___5 = TIFFFileName(out);



          TIFFError(tmp___5, "Error, can\'t write tile at %lu %lu sample %lu",
                    (unsigned long )col, (unsigned long )row, (unsigned long )s);


          _TIFFfree(obuf);

          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1884", "0", checkpoints_buf);
          return (0);
        } else {

        }

        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1880", "0", checkpoints_buf);
        s = (tsample_t )((int )s + 1);

      }



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1870", "0", checkpoints_buf);

      colb = (uint32 )((unsigned long )colb + (unsigned long )tilew);

      col += tw;

    }






    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1865", "0", checkpoints_buf);



    bufp += nrow * iimagew;

    row += tl;

  }














  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1855", "0", checkpoints_buf);






  _TIFFfree(obuf);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1892", "1", checkpoints_buf);
  return (1);
}
}
static int cpContigStrips2ContigTiles(TIFF *in , TIFF *out ,
                                      uint32 imagelength , uint32 imagewidth ,
                                      tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1893", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readContigStripsIntoBuffer,
                & writeBufferToContigTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1893", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1894", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpContigStrips2SeparateTiles(TIFF *in , TIFF *out ,
                                        uint32 imagelength , uint32 imagewidth ,
                                        tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1895", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readContigStripsIntoBuffer,
                & writeBufferToSeparateTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1895", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1896", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpSeparateStrips2ContigTiles(TIFF *in , TIFF *out ,
                                        uint32 imagelength , uint32 imagewidth ,
                                        tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1897", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readSeparateStripsIntoBuffer,
                & writeBufferToContigTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1897", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1898", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpSeparateStrips2SeparateTiles(TIFF *in , TIFF *out ,
                                          uint32 imagelength ,
                                          uint32 imagewidth , tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1899", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readSeparateStripsIntoBuffer,
                & writeBufferToSeparateTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1899", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1900", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpContigTiles2ContigTiles(TIFF *in , TIFF *out , uint32 imagelength ,
                                     uint32 imagewidth , tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1901", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readContigTilesIntoBuffer,
                & writeBufferToContigTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1901", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1902", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpContigTiles2SeparateTiles(TIFF *in , TIFF *out ,
                                       uint32 imagelength , uint32 imagewidth ,
                                       tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1903", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readContigTilesIntoBuffer,
                & writeBufferToSeparateTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1903", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1904", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpSeparateTiles2ContigTiles(TIFF *in , TIFF *out ,
                                       uint32 imagelength , uint32 imagewidth ,
                                       tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1905", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readSeparateTilesIntoBuffer,
                & writeBufferToContigTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1905", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1906", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpSeparateTiles2SeparateTiles(TIFF *in , TIFF *out ,
                                         uint32 imagelength ,
                                         uint32 imagewidth , tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1907", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readSeparateTilesIntoBuffer,
                & writeBufferToSeparateTiles, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1907", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1908", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpContigTiles2ContigStrips(TIFF *in , TIFF *out ,
                                      uint32 imagelength , uint32 imagewidth ,
                                      tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1909", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readContigTilesIntoBuffer,
                & writeBufferToContigStrips, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1909", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1910", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpContigTiles2SeparateStrips(TIFF *in , TIFF *out ,
                                        uint32 imagelength , uint32 imagewidth ,
                                        tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1911", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readContigTilesIntoBuffer,
                & writeBufferToSeparateStrips, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1911", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1912", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpSeparateTiles2ContigStrips(TIFF *in , TIFF *out ,
                                        uint32 imagelength , uint32 imagewidth ,
                                        tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1913", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readSeparateTilesIntoBuffer,
                & writeBufferToContigStrips, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1913", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1914", "tmp", checkpoints_buf);
  return (tmp);
}
}
static int cpSeparateTiles2SeparateStrips(TIFF *in , TIFF *out ,
                                          uint32 imagelength ,
                                          uint32 imagewidth , tsample_t spp ) 
{ 
  int tmp ;

  {
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1915", "tmp", checkpoints_buf);

  tmp = cpImage(in, out, & readSeparateTilesIntoBuffer,
                & writeBufferToSeparateStrips, imagelength, imagewidth, spp);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1915", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1916", "tmp", checkpoints_buf);
  return (tmp);
}
}
static copyFunc pickCopyFunc(TIFF *in , TIFF *out , uint16 bitspersample ,
                             uint16 samplesperpixel ) 
{ 
  uint16 shortv ;
  uint32 w ;
  uint32 l ;
  uint32 tw ;
  uint32 tl ;
  int bychunk ;
  char const   *tmp ;
  uint32 irps ;
  int tmp___0 ;
  char const   *tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;
  int tmp___6 ;
  int tmp___7 ;
  int tmp___8 ;
  int tmp___9 ;
  int tmp___10 ;
  int (*tmp___11)(TIFF *in , TIFF *out , uint32 imagelength ,
                  uint32 imagewidth , tsample_t spp ) ;
  char const   *tmp___12 ;

  {

  TIFFGetField(in, (uint32 )284, & shortv);

  if ((int )shortv != (int )config) {
    sprintf(checkpoints_buf, "%d", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1919", "8", checkpoints_buf);
    if ((int )bitspersample != 8) {
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1920", "1", checkpoints_buf);
      if ((int )samplesperpixel > 1) {


        tmp = TIFFFileName(in);



        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: Cannot handle different planar configuration w/ bits/sample != 8\n",
                tmp);

        return ((copyFunc )((void *)0));
      } else {

      }
      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1920", "1", checkpoints_buf);
    } else {

    }
    sprintf(checkpoints_buf, "%d", 8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1919", "8", checkpoints_buf);
  } else {

  }

  TIFFGetField(in, (uint32 )256, & w);


  TIFFGetField(in, (uint32 )257, & l);

  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1929", "tmp___7", checkpoints_buf);

  tmp___7 = TIFFIsTiled(out);
  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1929", "tmp___7", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1930", "tmp___7", checkpoints_buf);
  if (tmp___7) {
    goto _L;
  } else {
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1932", "tmp___8", checkpoints_buf);

    tmp___8 = TIFFIsTiled(in);
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1932", "tmp___8", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1933", "tmp___8", checkpoints_buf);
    if (tmp___8) {

      _L: /* CIL Label */ 
      if (bias) {


        tmp___1 = TIFFFileName(in);



        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"%s: Cannot handle tiled configuration w/bias image\n",
                tmp___1);

        return ((copyFunc )((void *)0));
      } else {

      }

      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1939", "tmp___6", checkpoints_buf);

      tmp___6 = TIFFIsTiled(out);
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1939", "tmp___6", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1940", "tmp___6", checkpoints_buf);
      if (tmp___6) {
        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1941", "tmp___2", checkpoints_buf);

        tmp___2 = TIFFGetField(in, (uint32 )322, & tw);
        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1941", "tmp___2", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1942", "tmp___2", checkpoints_buf);
        if (tmp___2) {

        } else {
          tw = w;

        }
        sprintf(checkpoints_buf, "%d", tmp___2);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1942", "tmp___2", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1945", "tmp___3", checkpoints_buf);

        tmp___3 = TIFFGetField(in, (uint32 )323, & tl);
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1945", "tmp___3", checkpoints_buf);

        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1946", "tmp___3", checkpoints_buf);
        if (tmp___3) {

        } else {
          tl = l;

        }
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1946", "tmp___3", checkpoints_buf);


        if (tw == tilewidth) {


          if (tl == tilelength) {
            tmp___4 = 1;
            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1951", "tmp___4", checkpoints_buf);
          } else {
            tmp___4 = 0;
            sprintf(checkpoints_buf, "%d", tmp___4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1952", "tmp___4", checkpoints_buf);
          }


        } else {
          tmp___4 = 0;
          sprintf(checkpoints_buf, "%d", tmp___4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1953", "tmp___4", checkpoints_buf);
        }


        bychunk = tmp___4;
        sprintf(checkpoints_buf, "%d", bychunk);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1954", "bychunk", checkpoints_buf);
      } else {

        TIFFGetField(in, (uint32 )322, & tw);


        TIFFGetField(in, (uint32 )323, & tl);



        if (tw == w) {


          if (tl == rowsperstrip) {
            tmp___5 = 1;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1959", "tmp___5", checkpoints_buf);
          } else {
            tmp___5 = 0;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                            "1960", "tmp___5", checkpoints_buf);
          }


        } else {
          tmp___5 = 0;
          sprintf(checkpoints_buf, "%d", tmp___5);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1961", "tmp___5", checkpoints_buf);
        }


        bychunk = tmp___5;
        sprintf(checkpoints_buf, "%d", bychunk);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1962", "bychunk", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___6);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1940", "tmp___6", checkpoints_buf);
    } else {
      irps = (uint32 )-1L;


      TIFFGetField(in, (uint32 )278, & irps);


      if (! bias) {


        if (rowsperstrip == irps) {
          tmp___0 = 1;
          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1967", "tmp___0", checkpoints_buf);
        } else {
          tmp___0 = 0;
          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                          "1968", "tmp___0", checkpoints_buf);
        }


      } else {
        tmp___0 = 0;
        sprintf(checkpoints_buf, "%d", tmp___0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                        "1969", "tmp___0", checkpoints_buf);
      }

      bychunk = tmp___0;
      sprintf(checkpoints_buf, "%d", bychunk);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                      "1970", "bychunk", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___8);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                    "1933", "tmp___8", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp___7);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1930", "tmp___7", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1971", "tmp___9", checkpoints_buf);

  tmp___9 = TIFFIsTiled(in);
  sprintf(checkpoints_buf, "%d", tmp___9);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1971", "tmp___9", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1972", "tmp___10", checkpoints_buf);

  tmp___10 = TIFFIsTiled(out);
  sprintf(checkpoints_buf, "%d", tmp___10);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-06-30-b44af47-e0b51f3",
                  "1972", "tmp___10", checkpoints_buf);

  switch ((long )((((((int )shortv << 11) | ((int )config << 3)) | (tmp___9 << 2)) | (tmp___10 << 1)) | bychunk)) {
  case (long )((((1 << 11) | (1 << 3)) | (1 << 1)) | 1): 
  case (long )(((1 << 11) | (1 << 3)) | (1 << 1)): 
  return (& cpContigStrips2ContigTiles);
  case (long )((((1 << 11) | (2 << 3)) | (1 << 1)) | 1): 
  case (long )(((1 << 11) | (2 << 3)) | (1 << 1)): 
  return (& cpContigStrips2SeparateTiles);
  case (long )((((2 << 11) | (1 << 3)) | (1 << 1)) | 1): 
  case (long )(((2 << 11) | (1 << 3)) | (1 << 1)): 
  return (& cpSeparateStrips2ContigTiles);
  case (long )((((2 << 11) | (2 << 3)) | (1 << 1)) | 1): 
  case (long )(((2 << 11) | (2 << 3)) | (1 << 1)): 
  return (& cpSeparateStrips2SeparateTiles);
  case (long )(((((1 << 11) | (1 << 3)) | (1 << 2)) | (1 << 1)) | 1): 
  case (long )((((1 << 11) | (1 << 3)) | (1 << 2)) | (1 << 1)): 
  return (& cpContigTiles2ContigTiles);
  case (long )(((((1 << 11) | (2 << 3)) | (1 << 2)) | (1 << 1)) | 1): 
  case (long )((((1 << 11) | (2 << 3)) | (1 << 2)) | (1 << 1)): 
  return (& cpContigTiles2SeparateTiles);
  case (long )(((((2 << 11) | (1 << 3)) | (1 << 2)) | (1 << 1)) | 1): 
  case (long )((((2 << 11) | (1 << 3)) | (1 << 2)) | (1 << 1)): 
  return (& cpSeparateTiles2ContigTiles);
  case (long )(((((2 << 11) | (2 << 3)) | (1 << 2)) | (1 << 1)) | 1): 
  case (long )((((2 << 11) | (2 << 3)) | (1 << 2)) | (1 << 1)): 
  return (& cpSeparateTiles2SeparateTiles);
  case (long )((((1 << 11) | (1 << 3)) | (1 << 2)) | 1): 
  case (long )(((1 << 11) | (1 << 3)) | (1 << 2)): 
  return (& cpContigTiles2ContigStrips);
  case (long )((((1 << 11) | (2 << 3)) | (1 << 2)) | 1): 
  case (long )(((1 << 11) | (2 << 3)) | (1 << 2)): 
  return (& cpContigTiles2SeparateStrips);
  case (long )((((2 << 11) | (1 << 3)) | (1 << 2)) | 1): 
  case (long )(((2 << 11) | (1 << 3)) | (1 << 2)): 
  return (& cpSeparateTiles2ContigStrips);
  case (long )((((2 << 11) | (2 << 3)) | (1 << 2)) | 1): 
  case (long )(((2 << 11) | (2 << 3)) | (1 << 2)): 
  return (& cpSeparateTiles2SeparateStrips);

  case (long )((1 << 11) | (1 << 3)): 
  if (bias) {
    tmp___11 = & cpBiasedContig2Contig;

  } else {
    tmp___11 = & cpContig2ContigByRow;

  }


  return (tmp___11);
  case (long )(((1 << 11) | (1 << 3)) | 1): 
  return (& cpDecodedStrips);
  case (long )(((1 << 11) | (2 << 3)) | 1): 
  case (long )((1 << 11) | (2 << 3)): 
  return (& cpContig2SeparateByRow);
  case (long )(((2 << 11) | (1 << 3)) | 1): 
  case (long )((2 << 11) | (1 << 3)): 
  return (& cpSeparate2ContigByRow);
  case (long )(((2 << 11) | (2 << 3)) | 1): 
  case (long )((2 << 11) | (2 << 3)): 
  return (& cpSeparate2SeparateByRow);
  }


  tmp___12 = TIFFFileName(in);



  fprintf((FILE */* __restrict  */)stderr,
          (char const   */* __restrict  */)"tiffcp: %s: Don\'t know how to copy/convert image.\n",
          tmp___12);

  return ((copyFunc )((void *)0));
}
}
