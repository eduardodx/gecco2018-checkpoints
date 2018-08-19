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
typedef __useconds_t useconds_t;
typedef __intptr_t intptr_t;
typedef __socklen_t socklen_t;
enum __anonenum_26 {
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
enum __anonenum_27 {
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
enum __anonenum_28 {
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
enum __anonenum_ACTION_29 {
    FIND = 0,
    ENTER = 1
} ;
typedef enum __anonenum_ACTION_29 ACTION;
struct entry {
   char *key ;
   void *data ;
};
typedef struct entry ENTRY;
struct _ENTRY;
struct _ENTRY;
enum __anonenum_VISIT_30 {
    preorder = 0,
    postorder = 1,
    endorder = 2,
    leaf = 3
} ;
typedef enum __anonenum_VISIT_30 VISIT;
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
struct __anonstruct_TIFFHeaderCommon_31 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
};
typedef struct __anonstruct_TIFFHeaderCommon_31 TIFFHeaderCommon;
struct __anonstruct_TIFFHeaderClassic_32 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint32 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderClassic_32 TIFFHeaderClassic;
struct __anonstruct_TIFFHeaderBig_33 {
   uint16 tiff_magic ;
   uint16 tiff_version ;
   uint16 tiff_offsetsize ;
   uint16 tiff_unused ;
   uint64 tiff_diroff ;
};
typedef struct __anonstruct_TIFFHeaderBig_33 TIFFHeaderBig;
enum __anonenum_TIFFDataType_34 {
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
typedef enum __anonenum_TIFFDataType_34 TIFFDataType;
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
struct __anonstruct_TIFFDisplay_35 {
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
typedef struct __anonstruct_TIFFDisplay_35 TIFFDisplay;
struct __anonstruct_TIFFYCbCrToRGB_36 {
   TIFFRGBValue *clamptab ;
   int *Cr_r_tab ;
   int *Cb_b_tab ;
   int32 *Cr_g_tab ;
   int32 *Cb_g_tab ;
   int32 *Y_tab ;
};
typedef struct __anonstruct_TIFFYCbCrToRGB_36 TIFFYCbCrToRGB;
struct __anonstruct_TIFFCIELabToRGB_37 {
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
typedef struct __anonstruct_TIFFCIELabToRGB_37 TIFFCIELabToRGB;
struct _TIFFRGBAImage;
typedef struct _TIFFRGBAImage TIFFRGBAImage;
typedef void (*tileContigRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                  uint32  , uint32  , uint32  , int32  ,
                                  int32  , unsigned char * );
typedef void (*tileSeparateRoutine)(TIFFRGBAImage * , uint32 * , uint32  ,
                                    uint32  , uint32  , uint32  , int32  ,
                                    int32  , unsigned char * , unsigned char * ,
                                    unsigned char * , unsigned char * );
union __anonunion_put_38 {
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
   union __anonunion_put_38 put ;
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
struct __anonstruct_TIFFCodec_39 {
   char *name ;
   uint16 scheme ;
   int (*init)(TIFF * , int  ) ;
};
typedef struct __anonstruct_TIFFCodec_39 TIFFCodec;
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
struct __anonstruct_TIFFTagMethods_40 {
   int (*vsetfield)(TIFF * , uint32  , va_list  ) ;
   int (*vgetfield)(TIFF * , uint32  , va_list  ) ;
   void (*printdir)(TIFF * , FILE * , long  ) ;
};
typedef struct __anonstruct_TIFFTagMethods_40 TIFFTagMethods;
struct __anonstruct_TIFFFieldInfo_41 {
   ttag_t field_tag ;
   short field_readcount ;
   short field_writecount ;
   TIFFDataType field_type ;
   unsigned short field_bit ;
   unsigned char field_oktochange ;
   unsigned char field_passcount ;
   char *field_name ;
};
typedef struct __anonstruct_TIFFFieldInfo_41 TIFFFieldInfo;
struct __anonstruct_TIFFTagValue_42 {
   TIFFField const   *info ;
   int count ;
   void *value ;
};
typedef struct __anonstruct_TIFFTagValue_42 TIFFTagValue;
struct __anonstruct_TIFFDirectory_43 {
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
typedef struct __anonstruct_TIFFDirectory_43 TIFFDirectory;
enum __anonenum_TIFFSetGetFieldType_44 {
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
typedef enum __anonenum_TIFFSetGetFieldType_44 TIFFSetGetFieldType;
enum __anonenum_TIFFFieldArrayType_45 {
    tfiatImage = 0,
    tfiatExif = 1,
    tfiatOther = 2
} ;
typedef enum __anonenum_TIFFFieldArrayType_45 TIFFFieldArrayType;
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
union __anonunion_tdir_offset_47 {
   uint16 toff_short ;
   uint32 toff_long ;
   uint64 toff_long8 ;
};
struct __anonstruct_TIFFDirEntry_46 {
   uint16 tdir_tag ;
   uint16 tdir_type ;
   uint64 tdir_count ;
   union __anonunion_tdir_offset_47 tdir_offset ;
};
typedef struct __anonstruct_TIFFDirEntry_46 TIFFDirEntry;
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
union __anonunion_tif_header_48 {
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
   union __anonunion_tif_header_48 tif_header ;
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
extern int fcntl(int __fd , int __cmd  , ...) ;
extern int ( __attribute__((__nonnull__(1))) open)(char const   *__file ,
                                                   int __oflag  , ...)  __asm__("open64")  ;
extern int ( __attribute__((__nonnull__(2))) openat)(int __fd ,
                                                     char const   *__file ,
                                                     int __oflag  , ...)  __asm__("openat64")  ;
extern int ( __attribute__((__nonnull__(1))) creat)(char const   *__file ,
                                                    __mode_t __mode )  __asm__("creat64")  ;
extern  __attribute__((__nothrow__)) int posix_fadvise(int __fd ,
                                                       __off64_t __offset ,
                                                       __off64_t __len ,
                                                       int __advise )  __asm__("posix_fadvise64")  ;
extern int posix_fallocate(int __fd , __off64_t __offset , __off64_t __len )  __asm__("posix_fallocate64")  ;
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
extern int _TIFFRewriteField(TIFF * , uint16  , TIFFDataType  , tmsize_t  ,
                             void * ) ;
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
static void (*old_error_handler)(char const   * , char const   * , va_list  )  =    (void (*)(char const   * ,
             char const   * , va_list  ))0;
static int status  =    0;
static int showdata  =    0;
static int rawdata  =    0;
static int showwords  =    0;
static int readdata  =    0;
static int stoponerr  =    1;
static void usage(void) ;
static void tiffinfo(TIFF *tif , uint16 order , long flags ) ;
static void PrivateErrorHandler(char const   *module , char const   *fmt ,
                                va_list ap ) 
{ 


  {

  if (old_error_handler) {

    (*old_error_handler)(module, fmt, ap);

  } else {

  }

  status = 1;
  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "254", "status", checkpoints_buf);
  return;
}
}
int main(int argc , char **argv ) 
{ 
  int dirnum ;
  int multiplefiles ;
  int c ;
  uint16 order ;
  TIFF *tif ;
  long flags ;
  uint64 diroff ;
  int chopstrips ;
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
  unsigned long tmp___13 ;
  char const   *tmp___14 ;
  int tmp___15 ;
  int tmp___16 ;
  toff_t offset ;
  int tmp___17 ;
  int tmp___18 ;
  int tmp___19 ;

  {
  dirnum = -1;
  sprintf(checkpoints_buf, "%d", dirnum);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "256", "dirnum", checkpoints_buf);
  order = (uint16 )0;

  flags = 0L;
  sprintf(checkpoints_buf, "%ld", flags);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "258", "flags", checkpoints_buf);
  diroff = (uint64 )0;

  chopstrips = 0;
  sprintf(checkpoints_buf, "%d", chopstrips);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "260", "chopstrips", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "261", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "261", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "261", "-1", checkpoints_buf);
  while (1) {
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "262", "c", checkpoints_buf);

    c = getopt(argc, (char * const  *)argv, "f:o:cdDSjilmrsvwz0123456789");
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "262", "c", checkpoints_buf);

    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "263", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "263", "-1", checkpoints_buf);
    if (c != -1) {

    } else {
      break;
    }
    sprintf(checkpoints_buf, "%d", c);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "263", "c", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", -1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "263", "-1", checkpoints_buf);
    switch (c) {
    sprintf(checkpoints_buf, "%d", dirnum);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "267", "dirnum", checkpoints_buf);

    case 57: 
    case 56: 
    case 55: 
    case 54: 
    case 53: 
    case 52: 
    case 51: 
    case 50: 
    case 49: 
    case 48: 
    dirnum = atoi((char const   *)(*(argv + (optind - 1)) + 1));
    sprintf(checkpoints_buf, "%d", dirnum);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "267", "dirnum", checkpoints_buf);

    break;
    case 100: 
    showdata ++;
    sprintf(checkpoints_buf, "%d", showdata);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "269", "showdata", checkpoints_buf);
    case 68: 
    readdata ++;
    sprintf(checkpoints_buf, "%d", readdata);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "270", "readdata", checkpoints_buf);
    break;
    case 99: 
    flags |= 6L;
    sprintf(checkpoints_buf, "%ld", flags);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "272", "flags", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "274", "0", checkpoints_buf);
    case 102: 
    if (0) {


      __s1_len___0 = strlen((char const   *)optarg);




      __s2_len___0 = strlen("lsb2msb");


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "277", "1", checkpoints_buf);
      if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
        goto _L___2;
      } else {

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "279", "4", checkpoints_buf);
        if (__s1_len___0 >= 4U) {
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "280", "1", checkpoints_buf);
          _L___2: /* CIL Label */ 
          if (! ((size_t )((void const   *)("lsb2msb" + 1)) - (size_t )((void const   *)"lsb2msb") == 1U)) {
            tmp___12 = 1;
            sprintf(checkpoints_buf, "%d", tmp___12);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "281", "tmp___12", checkpoints_buf);
          } else {

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "282", "4", checkpoints_buf);
            if (__s2_len___0 >= 4U) {
              tmp___12 = 1;
              sprintf(checkpoints_buf, "%d", tmp___12);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                              "283", "tmp___12", checkpoints_buf);
            } else {
              tmp___12 = 0;
              sprintf(checkpoints_buf, "%d", tmp___12);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                              "284", "tmp___12", checkpoints_buf);
            }

            sprintf(checkpoints_buf, "%u", 4);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "282", "4", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%u", 1);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "280", "1", checkpoints_buf);
        } else {
          tmp___12 = 0;
          sprintf(checkpoints_buf, "%d", tmp___12);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "285", "tmp___12", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%u", 4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "279", "4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "277", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "286", "tmp___12", checkpoints_buf);
      if (tmp___12) {
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "287", "tmp___7", checkpoints_buf);

        tmp___7 = __builtin_strcmp((char const   *)optarg, "lsb2msb");
        sprintf(checkpoints_buf, "%d", tmp___7);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "287", "tmp___7", checkpoints_buf);

        tmp___11 = tmp___7;
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "288", "tmp___11", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "289", "tmp___10", checkpoints_buf);

        tmp___10 = __builtin_strcmp((char const   *)optarg, "lsb2msb");
        sprintf(checkpoints_buf, "%d", tmp___10);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "289", "tmp___10", checkpoints_buf);

        tmp___11 = tmp___10;
        sprintf(checkpoints_buf, "%d", tmp___11);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "290", "tmp___11", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", tmp___12);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "286", "tmp___12", checkpoints_buf);
    } else {
      sprintf(checkpoints_buf, "%d", tmp___10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "291", "tmp___10", checkpoints_buf);

      tmp___10 = __builtin_strcmp((char const   *)optarg, "lsb2msb");
      sprintf(checkpoints_buf, "%d", tmp___10);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "291", "tmp___10", checkpoints_buf);

      tmp___11 = tmp___10;
      sprintf(checkpoints_buf, "%d", tmp___11);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "292", "tmp___11", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "274", "0", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "293", "tmp___11", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "293", "0", checkpoints_buf);
    if (tmp___11 == 0) {
      order = (uint16 )2;

    } else {
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "295", "0", checkpoints_buf);
      if (0) {


        __s1_len = strlen((char const   *)optarg);




        __s2_len = strlen("msb2lsb");


        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "298", "1", checkpoints_buf);
        if (! ((size_t )((void const   *)(optarg + 1)) - (size_t )((void const   *)optarg) == 1U)) {
          goto _L___0;
        } else {

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "300", "4", checkpoints_buf);
          if (__s1_len >= 4U) {
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "301", "1", checkpoints_buf);
            _L___0: /* CIL Label */ 
            if (! ((size_t )((void const   *)("msb2lsb" + 1)) - (size_t )((void const   *)"msb2lsb") == 1U)) {
              tmp___5 = 1;
              sprintf(checkpoints_buf, "%d", tmp___5);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                              "302", "tmp___5", checkpoints_buf);
            } else {

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                              "303", "4", checkpoints_buf);
              if (__s2_len >= 4U) {
                tmp___5 = 1;
                sprintf(checkpoints_buf, "%d", tmp___5);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                                "304", "tmp___5", checkpoints_buf);
              } else {
                tmp___5 = 0;
                sprintf(checkpoints_buf, "%d", tmp___5);
                checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                                "305", "tmp___5", checkpoints_buf);
              }

              sprintf(checkpoints_buf, "%u", 4);
              checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                              "303", "4", checkpoints_buf);
            }
            sprintf(checkpoints_buf, "%u", 1);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "301", "1", checkpoints_buf);
          } else {
            tmp___5 = 0;
            sprintf(checkpoints_buf, "%d", tmp___5);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "306", "tmp___5", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%u", 4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "300", "4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%u", 1);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "298", "1", checkpoints_buf);
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "307", "tmp___5", checkpoints_buf);
        if (tmp___5) {
          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "308", "tmp___0", checkpoints_buf);

          tmp___0 = __builtin_strcmp((char const   *)optarg, "msb2lsb");
          sprintf(checkpoints_buf, "%d", tmp___0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "308", "tmp___0", checkpoints_buf);

          tmp___4 = tmp___0;
          sprintf(checkpoints_buf, "%d", tmp___4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "309", "tmp___4", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "310", "tmp___3", checkpoints_buf);

          tmp___3 = __builtin_strcmp((char const   *)optarg, "msb2lsb");
          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "310", "tmp___3", checkpoints_buf);

          tmp___4 = tmp___3;
          sprintf(checkpoints_buf, "%d", tmp___4);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "311", "tmp___4", checkpoints_buf);
        }
        sprintf(checkpoints_buf, "%d", tmp___5);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "307", "tmp___5", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "312", "tmp___3", checkpoints_buf);

        tmp___3 = __builtin_strcmp((char const   *)optarg, "msb2lsb");
        sprintf(checkpoints_buf, "%d", tmp___3);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "312", "tmp___3", checkpoints_buf);

        tmp___4 = tmp___3;
        sprintf(checkpoints_buf, "%d", tmp___4);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "313", "tmp___4", checkpoints_buf);
      }
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "295", "0", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "314", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "314", "0", checkpoints_buf);
      if (tmp___4 == 0) {
        order = (uint16 )1;

      } else {

        usage();

      }
      sprintf(checkpoints_buf, "%d", tmp___4);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "314", "tmp___4", checkpoints_buf);
      sprintf(checkpoints_buf, "%d", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "314", "0", checkpoints_buf);
    }
    sprintf(checkpoints_buf, "%d", tmp___11);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "293", "tmp___11", checkpoints_buf);
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "293", "0", checkpoints_buf);
    break;
    case 105: 
    stoponerr = 0;
    sprintf(checkpoints_buf, "%d", stoponerr);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "318", "stoponerr", checkpoints_buf);
    break;
    sprintf(checkpoints_buf, "%ul", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "320", "tmp___13", checkpoints_buf);

    case 111: 
    tmp___13 = strtoul((char const   */* __restrict  */)optarg,
                       (char **/* __restrict  */)((void *)0), 0);
    sprintf(checkpoints_buf, "%ul", tmp___13);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "320", "tmp___13", checkpoints_buf);

    diroff = (uint64 )tmp___13;

    break;
    case 106: 
    flags |= 768L;
    sprintf(checkpoints_buf, "%ld", flags);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "323", "flags", checkpoints_buf);
    break;
    case 114: 
    rawdata = 1;
    sprintf(checkpoints_buf, "%d", rawdata);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "325", "rawdata", checkpoints_buf);
    break;
    case 115: 
    flags |= 1L;
    sprintf(checkpoints_buf, "%ld", flags);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "327", "flags", checkpoints_buf);
    break;
    case 119: 
    showwords = 1;
    sprintf(checkpoints_buf, "%d", showwords);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "329", "showwords", checkpoints_buf);
    break;
    case 122: 
    chopstrips = 1;
    sprintf(checkpoints_buf, "%d", chopstrips);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "331", "chopstrips", checkpoints_buf);
    break;

    case 63: 
    usage();

    }
  }
  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "261", "c", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", c);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "261", "c", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "261", "-1", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "334", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "334", "argc", checkpoints_buf);
  if (optind >= argc) {

    usage();

  } else {

  }
  sprintf(checkpoints_buf, "%d", optind);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "334", "optind", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", argc);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "334", "argc", checkpoints_buf);
  old_error_handler = _TIFFerrorHandler;


  TIFFSetErrorHandler(& PrivateErrorHandler);

  multiplefiles = argc - optind > 1;
  sprintf(checkpoints_buf, "%d", multiplefiles);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "339", "multiplefiles", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", status);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "378", "status", checkpoints_buf);
  return (status);
}
}
char *stuff[16]  = 
  {      (char *)"usage: tiffinfo [options] input...",      (char *)"where options are:",      (char *)" -D\t\tread data",      (char *)" -i\t\tignore read errors", 
        (char *)" -c\t\tdisplay data for grey/color response curve or colormap",      (char *)" -d\t\tdisplay raw/decoded image data",      (char *)" -f lsb2msb\tforce lsb-to-msb FillOrder for input",      (char *)" -f msb2lsb\tforce msb-to-lsb FillOrder for input", 
        (char *)" -j\t\tshow JPEG tables",      (char *)" -o offset\tset initial directory offset",      (char *)" -r\t\tread/display raw image data instead of decoded data",      (char *)" -s\t\tdisplay strip offsets and byte counts", 
        (char *)" -w\t\tdisplay raw data in words rather than bytes",      (char *)" -z\t\tenable strip chopping",      (char *)" -#\t\tset initial directory (first directory is # 0)",      (char *)((void *)0)};
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
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "382", "i", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "383", "i", checkpoints_buf);
  while ((unsigned int )stuff[i] != (unsigned int )((void *)0)) {

    fprintf((FILE */* __restrict  */)stderr,
            (char const   */* __restrict  */)"%s\n", stuff[i]);

    i ++;
    sprintf(checkpoints_buf, "%d", i);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "388", "i", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", i);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "383", "i", checkpoints_buf);

  exit(-1);

}
}
static void ShowStrip(tstrip_t strip , unsigned char *pp , uint32 nrow ,
                      tsize_t scanline ) 
{ 
  register tsize_t cc ;
  unsigned char *tmp ;
  uint32 tmp___0 ;

  {

  printf((char const   */* __restrict  */)"Strip %lu:\n", (unsigned long )strip);




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "0", checkpoints_buf);







  sprintf(checkpoints_buf, "%ld", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 24);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "24", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "0", checkpoints_buf);


  while (1) {
    tmp___0 = nrow;

    nrow --;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "394", "0", checkpoints_buf);
    if (tmp___0 > 0U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "394", "0", checkpoints_buf);
    cc = (tsize_t )0;







    sprintf(checkpoints_buf, "%ld", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "398", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%ld", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "398", "24", checkpoints_buf);
    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "398", "0", checkpoints_buf);

    while (cc < scanline) {


      tmp = pp;

      pp ++;


      printf((char const   */* __restrict  */)" %02x", (int )*tmp);


      sprintf(checkpoints_buf, "%ld", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "405", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%ld", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "405", "24", checkpoints_buf);
      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "405", "0", checkpoints_buf);
      if ((cc + 1L) % 24L == 0L) {

        putchar('\n');

      } else {

      }

      sprintf(checkpoints_buf, "%ld", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "405", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%ld", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "405", "24", checkpoints_buf);
      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "405", "0", checkpoints_buf);
      cc ++;

    }






    sprintf(checkpoints_buf, "%ld", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "398", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%ld", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "398", "24", checkpoints_buf);
    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "398", "0", checkpoints_buf);


    putchar('\n');

  }



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "0", checkpoints_buf);







  sprintf(checkpoints_buf, "%ld", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 24);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "24", checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "391", "0", checkpoints_buf);


  return;
}
}
void TIFFReadContigStripData(TIFF *tif ) 
{ 
  unsigned char *buf ;
  tsize_t scanline ;
  tmsize_t tmp ;
  tmsize_t tmp___0 ;
  void *tmp___1 ;
  uint32 row ;
  uint32 h ;
  uint32 rowsperstrip ;
  uint32 nrow ;
  uint32 tmp___2 ;
  tstrip_t strip ;
  uint32 tmp___3 ;
  tmsize_t tmp___4 ;

  {


  tmp = TIFFScanlineSize(tif);


  scanline = tmp;



  tmp___0 = TIFFStripSize(tif);




  tmp___1 = _TIFFmalloc(tmp___0);


  buf = (unsigned char *)tmp___1;


  if (buf) {
    rowsperstrip = (uint32 )-1;


    TIFFGetField(tif, (uint32 )257, & h);


    TIFFGetField(tif, (uint32 )278, & rowsperstrip);

    row = (uint32 )0;













    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "421", "0", checkpoints_buf);

    while (row < h) {





      if (row + rowsperstrip > h) {
        tmp___2 = h - row;

      } else {
        tmp___2 = rowsperstrip;

      }



      nrow = tmp___2;



      tmp___3 = TIFFComputeStrip(tif, row, (uint16 )0);


      strip = tmp___3;



      tmp___4 = TIFFReadEncodedStrip(tif, strip, (void *)buf,
                                     (tmsize_t )((unsigned long )nrow * (unsigned long )scanline));



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "432", "0", checkpoints_buf);
      if (tmp___4 < 0L) {
        sprintf(checkpoints_buf, "%d", stoponerr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "433", "stoponerr", checkpoints_buf);
        if (stoponerr) {
          break;
        } else {

        }
        sprintf(checkpoints_buf, "%d", stoponerr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "433", "stoponerr", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", showdata);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "436", "showdata", checkpoints_buf);
        if (showdata) {

          ShowStrip(strip, buf, nrow, scanline);

        } else {

        }
        sprintf(checkpoints_buf, "%d", showdata);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "436", "showdata", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "432", "0", checkpoints_buf);
      row += rowsperstrip;

    }












    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "421", "0", checkpoints_buf);


    _TIFFfree((void *)buf);

  } else {

  }

  return;
}
}
void TIFFReadSeparateStripData(TIFF *tif ) 
{ 
  unsigned char *buf ;
  tsize_t scanline ;
  tmsize_t tmp ;
  tmsize_t tmp___0 ;
  void *tmp___1 ;
  uint32 row ;
  uint32 h ;
  uint32 rowsperstrip ;
  tsample_t s ;
  tsample_t samplesperpixel ;
  uint32 nrow ;
  uint32 tmp___2 ;
  tstrip_t strip ;
  uint32 tmp___3 ;
  tmsize_t tmp___4 ;

  {


  tmp = TIFFScanlineSize(tif);


  scanline = tmp;



  tmp___0 = TIFFStripSize(tif);




  tmp___1 = _TIFFmalloc(tmp___0);


  buf = (unsigned char *)tmp___1;


  if (buf) {
    rowsperstrip = (uint32 )-1;


    TIFFGetField(tif, (uint32 )257, & h);


    TIFFGetField(tif, (uint32 )278, & rowsperstrip);


    TIFFGetField(tif, (uint32 )277, & samplesperpixel);

    row = (uint32 )0;














    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "454", "0", checkpoints_buf);


    while (row < h) {


      s = (tsample_t )0;











      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "459", "0", checkpoints_buf);

      while ((int )s < (int )samplesperpixel) {



        if (row + rowsperstrip > h) {
          tmp___2 = h - row;

        } else {
          tmp___2 = rowsperstrip;

        }



        nrow = tmp___2;



        tmp___3 = TIFFComputeStrip(tif, row, s);


        strip = tmp___3;



        tmp___4 = TIFFReadEncodedStrip(tif, strip, (void *)buf,
                                       (tmsize_t )((unsigned long )nrow * (unsigned long )scanline));



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "470", "0", checkpoints_buf);
        if (tmp___4 < 0L) {
          sprintf(checkpoints_buf, "%d", stoponerr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "471", "stoponerr", checkpoints_buf);
          if (stoponerr) {
            break;
          } else {

          }
          sprintf(checkpoints_buf, "%d", stoponerr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "471", "stoponerr", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", showdata);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "474", "showdata", checkpoints_buf);
          if (showdata) {

            ShowStrip(strip, buf, nrow, scanline);

          } else {

          }
          sprintf(checkpoints_buf, "%d", showdata);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "474", "showdata", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "470", "0", checkpoints_buf);
        s = (tsample_t )((int )s + 1);

      }










      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "459", "0", checkpoints_buf);

      row += rowsperstrip;

    }













    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "454", "0", checkpoints_buf);



    _TIFFfree((void *)buf);

  } else {

  }

  return;
}
}
static void ShowTile(uint32 row , uint32 col , tsample_t sample ,
                     unsigned char *pp , uint32 nrow , tsize_t rowsize ) 
{ 
  uint32 cc ;
  unsigned char *tmp ;
  uint32 tmp___0 ;

  {

  printf((char const   */* __restrict  */)"Tile (%lu,%lu", (unsigned long )row,
         (unsigned long )col);

  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "483", "65535", checkpoints_buf);
  if ((int )sample != 65535) {

    printf((char const   */* __restrict  */)",%u", (int )sample);

  } else {

  }
  sprintf(checkpoints_buf, "%d", 65535);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "483", "65535", checkpoints_buf);

  printf((char const   */* __restrict  */)"):\n");




  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 24);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "24", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "0", checkpoints_buf);


  while (1) {
    tmp___0 = nrow;

    nrow --;


    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "490", "0", checkpoints_buf);
    if (tmp___0 > 0U) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "490", "0", checkpoints_buf);
    cc = (uint32 )0;






    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "494", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "494", "24", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "494", "0", checkpoints_buf);

    while (cc < (uint32 )rowsize) {

      tmp = pp;

      pp ++;


      printf((char const   */* __restrict  */)" %02x", (int )*tmp);


      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "501", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "501", "24", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "501", "0", checkpoints_buf);
      if ((cc + 1U) % 24U == 0U) {

        putchar('\n');

      } else {

      }

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "501", "1", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 24);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "501", "24", checkpoints_buf);
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "501", "0", checkpoints_buf);
      cc ++;

    }





    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "494", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "494", "24", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "494", "0", checkpoints_buf);


    putchar('\n');

  }



  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "0", checkpoints_buf);






  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 24);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "24", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "487", "0", checkpoints_buf);


  return;
}
}
void TIFFReadContigTileData(TIFF *tif ) 
{ 
  unsigned char *buf ;
  tsize_t rowsize ;
  tmsize_t tmp ;
  tmsize_t tmp___0 ;
  void *tmp___1 ;
  uint32 tw ;
  uint32 th ;
  uint32 w ;
  uint32 h ;
  uint32 row ;
  uint32 col ;
  tmsize_t tmp___2 ;

  {


  tmp = TIFFTileRowSize(tif);


  rowsize = tmp;



  tmp___0 = TIFFTileSize(tif);




  tmp___1 = _TIFFmalloc(tmp___0);


  buf = (unsigned char *)tmp___1;


  if (buf) {

    TIFFGetField(tif, (uint32 )256, & w);


    TIFFGetField(tif, (uint32 )257, & h);


    TIFFGetField(tif, (uint32 )322, & tw);


    TIFFGetField(tif, (uint32 )323, & th);

    row = (uint32 )0;









    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "518", "0", checkpoints_buf);


    while (row < h) {


      col = (uint32 )0;






      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "523", "0", checkpoints_buf);

      while (col < w) {




        tmp___2 = TIFFReadTile(tif, (void *)buf, col, row, (uint32 )0,
                               (uint16 )0);



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "528", "0", checkpoints_buf);
        if (tmp___2 < 0L) {
          sprintf(checkpoints_buf, "%d", stoponerr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "529", "stoponerr", checkpoints_buf);
          if (stoponerr) {
            break;
          } else {

          }
          sprintf(checkpoints_buf, "%d", stoponerr);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "529", "stoponerr", checkpoints_buf);
        } else {
          sprintf(checkpoints_buf, "%d", showdata);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "532", "showdata", checkpoints_buf);
          if (showdata) {

            ShowTile(row, col, (tsample_t )-1, buf, th, rowsize);

          } else {

          }
          sprintf(checkpoints_buf, "%d", showdata);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "532", "showdata", checkpoints_buf);
        }

        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "528", "0", checkpoints_buf);
        col += tw;

      }





      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "523", "0", checkpoints_buf);

      row += th;

    }








    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "518", "0", checkpoints_buf);



    _TIFFfree((void *)buf);

  } else {

  }

  return;
}
}
void TIFFReadSeparateTileData(TIFF *tif ) 
{ 
  unsigned char *buf ;
  tsize_t rowsize ;
  tmsize_t tmp ;
  tmsize_t tmp___0 ;
  void *tmp___1 ;
  uint32 tw ;
  uint32 th ;
  uint32 w ;
  uint32 h ;
  uint32 row ;
  uint32 col ;
  tsample_t s ;
  tsample_t samplesperpixel ;
  tmsize_t tmp___2 ;

  {


  tmp = TIFFTileRowSize(tif);


  rowsize = tmp;



  tmp___0 = TIFFTileSize(tif);




  tmp___1 = _TIFFmalloc(tmp___0);


  buf = (unsigned char *)tmp___1;


  if (buf) {

    TIFFGetField(tif, (uint32 )256, & w);


    TIFFGetField(tif, (uint32 )257, & h);


    TIFFGetField(tif, (uint32 )322, & tw);


    TIFFGetField(tif, (uint32 )323, & th);


    TIFFGetField(tif, (uint32 )277, & samplesperpixel);

    row = (uint32 )0;










    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "552", "0", checkpoints_buf);



    while (row < h) {


      col = (uint32 )0;







      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "557", "0", checkpoints_buf);


      while (col < w) {


        s = (tsample_t )0;




        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "562", "0", checkpoints_buf);

        while ((int )s < (int )samplesperpixel) {


          tmp___2 = TIFFReadTile(tif, (void *)buf, col, row, (uint32 )0, s);



          sprintf(checkpoints_buf, "%ld", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "567", "0", checkpoints_buf);
          if (tmp___2 < 0L) {
            sprintf(checkpoints_buf, "%d", stoponerr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "568", "stoponerr", checkpoints_buf);
            if (stoponerr) {
              break;
            } else {

            }
            sprintf(checkpoints_buf, "%d", stoponerr);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "568", "stoponerr", checkpoints_buf);
          } else {
            sprintf(checkpoints_buf, "%d", showdata);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "571", "showdata", checkpoints_buf);
            if (showdata) {

              ShowTile(row, col, s, buf, th, rowsize);

            } else {

            }
            sprintf(checkpoints_buf, "%d", showdata);
            checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                            "571", "showdata", checkpoints_buf);
          }

          sprintf(checkpoints_buf, "%ld", 0);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "567", "0", checkpoints_buf);
          s = (tsample_t )((int )s + 1);

        }



        sprintf(checkpoints_buf, "%ld", 0);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "562", "0", checkpoints_buf);

        col += tw;

      }






      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "557", "0", checkpoints_buf);


      row += th;

    }









    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "552", "0", checkpoints_buf);




    _TIFFfree((void *)buf);

  } else {

  }

  return;
}
}
void TIFFReadData(TIFF *tif ) 
{ 
  uint16 config ;
  int tmp ;

  {

  TIFFGetField(tif, (uint32 )284, & config);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "581", "tmp", checkpoints_buf);

  tmp = TIFFIsTiled(tif);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "581", "tmp", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "582", "tmp", checkpoints_buf);
  if (tmp) {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "583", "1", checkpoints_buf);
    if ((int )config == 1) {

      TIFFReadContigTileData(tif);

    } else {

      TIFFReadSeparateTileData(tif);

    }
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "583", "1", checkpoints_buf);
  } else {
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "586", "1", checkpoints_buf);
    if ((int )config == 1) {

      TIFFReadContigStripData(tif);

    } else {

      TIFFReadSeparateStripData(tif);

    }
    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "586", "1", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "582", "tmp", checkpoints_buf);
  return;
}
}
static void ShowRawBytes(unsigned char *pp , uint32 n ) 
{ 
  uint32 i ;
  unsigned char *tmp ;

  {
  i = (uint32 )0;







  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "591", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 24);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "591", "24", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "591", "0", checkpoints_buf);

  while (i < n) {


    tmp = pp;

    pp ++;


    printf((char const   */* __restrict  */)" %02x", (int )*tmp);


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "598", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "598", "24", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "598", "0", checkpoints_buf);
    if ((i + 1U) % 24U == 0U) {

      printf((char const   */* __restrict  */)"\n ");

    } else {

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "598", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 24);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "598", "24", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "598", "0", checkpoints_buf);
    i ++;

  }






  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "591", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 24);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "591", "24", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "591", "0", checkpoints_buf);


  putchar('\n');

  return;
}
}
static void ShowRawWords(uint16 *pp , uint32 n ) 
{ 
  uint32 i ;
  uint16 *tmp ;

  {
  i = (uint32 )0;







  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "605", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 15);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "605", "15", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "605", "0", checkpoints_buf);

  while (i < n) {


    tmp = pp;

    pp ++;


    printf((char const   */* __restrict  */)" %04x", (int )*tmp);


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "612", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 15);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "612", "15", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "612", "0", checkpoints_buf);
    if ((i + 1U) % 15U == 0U) {

      printf((char const   */* __restrict  */)"\n ");

    } else {

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "612", "1", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 15);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "612", "15", checkpoints_buf);
    sprintf(checkpoints_buf, "%u", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "612", "0", checkpoints_buf);
    i ++;

  }






  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "605", "1", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 15);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "605", "15", checkpoints_buf);
  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "605", "0", checkpoints_buf);


  putchar('\n');

  return;
}
}
void TIFFReadRawData(TIFF *tif , int bitrev ) 
{ 
  tstrip_t nstrips ;
  uint32 tmp ;
  char const   *what ;
  int tmp___0 ;
  char const   *tmp___1 ;
  int tmp___2 ;
  uint64 *stripbc ;
  uint32 bufsize ;
  tdata_t buf ;
  void *tmp___3 ;
  tstrip_t s ;
  tmsize_t tmp___4 ;

  {


  tmp = TIFFNumberOfStrips(tif);


  nstrips = tmp;

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "620", "tmp___2", checkpoints_buf);

  tmp___2 = TIFFIsTiled(tif);
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "620", "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "621", "tmp___2", checkpoints_buf);
  if (tmp___2) {
    tmp___1 = "Tile";

  } else {
    tmp___1 = "Strip";

  }
  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "621", "tmp___2", checkpoints_buf);
  what = tmp___1;


  TIFFGetField(tif, (uint32 )279, & stripbc);


  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "626", "0", checkpoints_buf);
  if (nstrips > 0U) {
    bufsize = (uint32 )*(stripbc + 0);



    tmp___3 = _TIFFmalloc((tmsize_t )bufsize);


    buf = tmp___3;

    s = (tstrip_t )0;







    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "631", "0", checkpoints_buf);

    while (s < nstrips) {



      if (*(stripbc + s) > (uint64 )bufsize) {


        buf = _TIFFrealloc(buf, (tmsize_t )*(stripbc + s));


        bufsize = (uint32 )*(stripbc + s);

      } else {

      }

      if ((unsigned int )buf == (unsigned int )((void *)0)) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"Cannot allocate buffer to read strip %lu\n",
                (unsigned long )s);

        break;
      } else {

      }


      tmp___4 = TIFFReadRawStrip(tif, s, buf, (tmsize_t )*(stripbc + s));



      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "644", "0", checkpoints_buf);
      if (tmp___4 < 0L) {

        fprintf((FILE */* __restrict  */)stderr,
                (char const   */* __restrict  */)"Error reading strip %lu\n",
                (unsigned long )s);

        sprintf(checkpoints_buf, "%d", stoponerr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "646", "stoponerr", checkpoints_buf);
        if (stoponerr) {
          break;
        } else {

        }
        sprintf(checkpoints_buf, "%d", stoponerr);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "646", "stoponerr", checkpoints_buf);
      } else {
        sprintf(checkpoints_buf, "%d", showdata);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "649", "showdata", checkpoints_buf);
        if (showdata) {
          sprintf(checkpoints_buf, "%d", bitrev);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "650", "bitrev", checkpoints_buf);
          if (bitrev) {

            TIFFReverseBits((uint8 *)buf, (tmsize_t )*(stripbc + s));


            printf((char const   */* __restrict  */)"%s %lu: (bit reversed)\n ",
                   what, (unsigned long )s);

          } else {

            printf((char const   */* __restrict  */)"%s %lu:\n ", what,
                   (unsigned long )s);

          }
          sprintf(checkpoints_buf, "%d", bitrev);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "650", "bitrev", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", showwords);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "654", "showwords", checkpoints_buf);
          if (showwords) {

            ShowRawWords((uint16 *)buf, (uint32 )*(stripbc + s) >> 1);

          } else {

            ShowRawBytes((unsigned char *)buf, (uint32 )*(stripbc + s));

          }
          sprintf(checkpoints_buf, "%d", showwords);
          checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                          "654", "showwords", checkpoints_buf);
        } else {

        }
        sprintf(checkpoints_buf, "%d", showdata);
        checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                        "649", "showdata", checkpoints_buf);
      }

      sprintf(checkpoints_buf, "%ld", 0);
      checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                      "644", "0", checkpoints_buf);
      s ++;

    }






    sprintf(checkpoints_buf, "%ld", 0);
    checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                    "631", "0", checkpoints_buf);

    if ((unsigned int )buf != (unsigned int )((void *)0)) {

      _TIFFfree(buf);

    } else {

    }
  } else {

  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "626", "0", checkpoints_buf);
  return;
}
}
static void tiffinfo(TIFF *tif , uint16 order , long flags ) 
{ 
  uint16 o ;

  {

  TIFFPrintDirectory(tif, stdout, flags);

  sprintf(checkpoints_buf, "%d", readdata);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "665", "readdata", checkpoints_buf);
  if (! readdata) {
    return;
  } else {

  }
  sprintf(checkpoints_buf, "%d", readdata);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "665", "readdata", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", rawdata);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "668", "rawdata", checkpoints_buf);
  if (rawdata) {

    if (order) {

      TIFFGetFieldDefaulted(tif, (uint32 )266, & o);


      TIFFReadRawData(tif, (int )o != (int )order);

    } else {

      TIFFReadRawData(tif, 0);

    }

  } else {

    if (order) {

      TIFFSetField(tif, (uint32 )266, (int )order);

    } else {

    }


    TIFFReadData(tif);

  }
  sprintf(checkpoints_buf, "%d", rawdata);
  checkpoints_log("/root/mountpoint-genprog/genprog-many-bugs/libtiff-bug-2009-08-28-e8a47d4-023b6df",
                  "668", "rawdata", checkpoints_buf);
  return;
}
}
