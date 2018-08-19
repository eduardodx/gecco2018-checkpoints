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
typedef __time_t time_t;
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
struct timezone {
   int tz_minuteswest ;
   int tz_dsttime ;
};
typedef struct timezone * __restrict  __timezone_ptr_t;
enum __itimer_which {
    ITIMER_REAL = 0,
    ITIMER_VIRTUAL = 1,
    ITIMER_PROF = 2
} ;
struct itimerval {
   struct timeval it_interval ;
   struct timeval it_value ;
};
typedef int __itimer_which_t;
typedef int ptrdiff_t;
typedef long wchar_t;
typedef signed char gint8;
typedef unsigned char guint8;
typedef short gint16;
typedef unsigned short guint16;
typedef int gint32;
typedef unsigned int guint32;
typedef long long gint64;
typedef unsigned long long guint64;
typedef int gssize;
typedef unsigned int gsize;
typedef gint64 goffset;
typedef int gintptr;
typedef unsigned int guintptr;
struct _GStaticMutex;
typedef struct _GStaticMutex GStaticMutex;
struct _GMutex;
union __anonunion_static_mutex_4 {
   char pad[24] ;
   double dummy_double ;
   void *dummy_pointer ;
   long dummy_long ;
};
struct _GStaticMutex {
   struct _GMutex *runtime_mutex ;
   union __anonunion_static_mutex_4 static_mutex ;
};
union _GSystemThread;
typedef union _GSystemThread GSystemThread;
union _GSystemThread {
   char data[4] ;
   double dummy_double ;
   void *dummy_pointer ;
   long dummy_long ;
};
typedef int GPid;
typedef char gchar;
typedef short gshort;
typedef long glong;
typedef int gint;
typedef gint gboolean;
typedef unsigned char guchar;
typedef unsigned short gushort;
typedef unsigned long gulong;
typedef unsigned int guint;
typedef float gfloat;
typedef double gdouble;
typedef void *gpointer;
typedef void const   *gconstpointer;
typedef gint (*GCompareFunc)(gconstpointer a , gconstpointer b );
typedef gint (*GCompareDataFunc)(gconstpointer a , gconstpointer b ,
                                 gpointer user_data );
typedef gboolean (*GEqualFunc)(gconstpointer a , gconstpointer b );
typedef void (*GDestroyNotify)(gpointer data );
typedef void (*GFunc)(gpointer data , gpointer user_data );
typedef guint (*GHashFunc)(gconstpointer key );
typedef void (*GHFunc)(gpointer key , gpointer value , gpointer user_data );
typedef void (*GFreeFunc)(gpointer data );
typedef gchar const   *(*GTranslateFunc)(gchar const   *str , gpointer data );
union _GDoubleIEEE754;
typedef union _GDoubleIEEE754 GDoubleIEEE754;
union _GFloatIEEE754;
typedef union _GFloatIEEE754 GFloatIEEE754;
struct __anonstruct_mpn_5 {
   guint mantissa : 23 ;
   guint biased_exponent : 8 ;
   guint sign : 1 ;
};
union _GFloatIEEE754 {
   gfloat v_float ;
   struct __anonstruct_mpn_5 mpn ;
};
struct __anonstruct_mpn_6 {
   guint mantissa_low : 32 ;
   guint mantissa_high : 20 ;
   guint biased_exponent : 11 ;
   guint sign : 1 ;
};
union _GDoubleIEEE754 {
   gdouble v_double ;
   struct __anonstruct_mpn_6 mpn ;
};
struct _GTimeVal;
typedef struct _GTimeVal GTimeVal;
struct _GTimeVal {
   glong tv_sec ;
   glong tv_usec ;
};
struct _GArray;
typedef struct _GArray GArray;
struct _GByteArray;
typedef struct _GByteArray GByteArray;
struct _GPtrArray;
typedef struct _GPtrArray GPtrArray;
struct _GArray {
   gchar *data ;
   guint len ;
};
struct _GByteArray {
   guint8 *data ;
   guint len ;
};
struct _GPtrArray {
   gpointer *pdata ;
   guint len ;
};
typedef __builtin_va_list __gnuc_va_list;
typedef __gnuc_va_list va_list;
typedef guint32 GQuark;
struct _GError;
typedef struct _GError GError;
struct _GError {
   GQuark domain ;
   gint code ;
   gchar *message ;
};
enum __anonenum_GUserDirectory_7 {
    G_USER_DIRECTORY_DESKTOP = 0,
    G_USER_DIRECTORY_DOCUMENTS = 1,
    G_USER_DIRECTORY_DOWNLOAD = 2,
    G_USER_DIRECTORY_MUSIC = 3,
    G_USER_DIRECTORY_PICTURES = 4,
    G_USER_DIRECTORY_PUBLIC_SHARE = 5,
    G_USER_DIRECTORY_TEMPLATES = 6,
    G_USER_DIRECTORY_VIDEOS = 7,
    G_USER_N_DIRECTORIES = 8
} ;
typedef enum __anonenum_GUserDirectory_7 GUserDirectory;
struct _GDebugKey;
typedef struct _GDebugKey GDebugKey;
struct _GDebugKey {
   gchar const   *key ;
   guint value ;
};
typedef void (*GVoidFunc)(void);
struct _GTrashStack;
typedef struct _GTrashStack GTrashStack;
struct _GTrashStack {
   GTrashStack *next ;
};
enum __anonenum_GThreadError_8 {
    G_THREAD_ERROR_AGAIN = 0
} ;
typedef enum __anonenum_GThreadError_8 GThreadError;
typedef gpointer (*GThreadFunc)(gpointer data );
enum __anonenum_GThreadPriority_9 {
    G_THREAD_PRIORITY_LOW = 0,
    G_THREAD_PRIORITY_NORMAL = 1,
    G_THREAD_PRIORITY_HIGH = 2,
    G_THREAD_PRIORITY_URGENT = 3
} ;
typedef enum __anonenum_GThreadPriority_9 GThreadPriority;
struct _GThread;
typedef struct _GThread GThread;
struct _GThread {
   gpointer (*func)(gpointer data ) ;
   gpointer data ;
   gboolean joinable ;
   GThreadPriority priority ;
};
typedef struct _GMutex GMutex;
struct _GCond;
typedef struct _GCond GCond;
struct _GPrivate;
typedef struct _GPrivate GPrivate;
struct _GStaticPrivate;
typedef struct _GStaticPrivate GStaticPrivate;
struct _GThreadFunctions;
typedef struct _GThreadFunctions GThreadFunctions;
struct _GThreadFunctions {
   GMutex *(*mutex_new)(void) ;
   void (*mutex_lock)(GMutex *mutex ) ;
   gboolean (*mutex_trylock)(GMutex *mutex ) ;
   void (*mutex_unlock)(GMutex *mutex ) ;
   void (*mutex_free)(GMutex *mutex ) ;
   GCond *(*cond_new)(void) ;
   void (*cond_signal)(GCond *cond ) ;
   void (*cond_broadcast)(GCond *cond ) ;
   void (*cond_wait)(GCond *cond , GMutex *mutex ) ;
   gboolean (*cond_timed_wait)(GCond *cond , GMutex *mutex , GTimeVal *end_time ) ;
   void (*cond_free)(GCond *cond ) ;
   GPrivate *(*private_new)(void (*destructor)(gpointer data ) ) ;
   gpointer (*private_get)(GPrivate *private_key ) ;
   void (*private_set)(GPrivate *private_key , gpointer data ) ;
   void (*thread_create)(gpointer (*func)(gpointer data ) , gpointer data ,
                         gulong stack_size , gboolean joinable ,
                         gboolean bound , GThreadPriority priority ,
                         gpointer thread , GError **error ) ;
   void (*thread_yield)(void) ;
   void (*thread_join)(gpointer thread ) ;
   void (*thread_exit)(void) ;
   void (*thread_set_priority)(gpointer thread , GThreadPriority priority ) ;
   void (*thread_self)(gpointer thread ) ;
   gboolean (*thread_equal)(gpointer thread1 , gpointer thread2 ) ;
};
struct _GStaticPrivate {
   guint index ;
};
struct _GStaticRecMutex;
typedef struct _GStaticRecMutex GStaticRecMutex;
struct _GStaticRecMutex {
   GStaticMutex mutex ;
   guint depth ;
   GSystemThread owner ;
};
struct _GStaticRWLock;
typedef struct _GStaticRWLock GStaticRWLock;
struct _GStaticRWLock {
   GStaticMutex mutex ;
   GCond *read_cond ;
   GCond *write_cond ;
   guint read_counter ;
   gboolean have_writer ;
   guint want_to_read ;
   guint want_to_write ;
};
enum __anonenum_GOnceStatus_10 {
    G_ONCE_STATUS_NOTCALLED = 0,
    G_ONCE_STATUS_PROGRESS = 1,
    G_ONCE_STATUS_READY = 2
} ;
typedef enum __anonenum_GOnceStatus_10 GOnceStatus;
struct _GOnce;
typedef struct _GOnce GOnce;
struct _GOnce {
   GOnceStatus volatile   status ;
   gpointer volatile   retval ;
};
struct _GAsyncQueue;
typedef struct _GAsyncQueue GAsyncQueue;
typedef __sig_atomic_t sig_atomic_t;
typedef __pid_t pid_t;
typedef __uid_t uid_t;
union sigval {
   int sival_int ;
   void *sival_ptr ;
};
typedef union sigval sigval_t;
struct __anonstruct__kill_12 {
   __pid_t si_pid ;
   __uid_t si_uid ;
};
struct __anonstruct__timer_13 {
   int si_tid ;
   int si_overrun ;
   sigval_t si_sigval ;
};
struct __anonstruct__rt_14 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   sigval_t si_sigval ;
};
struct __anonstruct__sigchld_15 {
   __pid_t si_pid ;
   __uid_t si_uid ;
   int si_status ;
   __clock_t si_utime ;
   __clock_t si_stime ;
};
struct __anonstruct__sigfault_16 {
   void *si_addr ;
};
struct __anonstruct__sigpoll_17 {
   long si_band ;
   int si_fd ;
};
union __anonunion__sifields_11 {
   int _pad[128U / sizeof(int ) - 3U] ;
   struct __anonstruct__kill_12 _kill ;
   struct __anonstruct__timer_13 _timer ;
   struct __anonstruct__rt_14 _rt ;
   struct __anonstruct__sigchld_15 _sigchld ;
   struct __anonstruct__sigfault_16 _sigfault ;
   struct __anonstruct__sigpoll_17 _sigpoll ;
};
struct siginfo {
   int si_signo ;
   int si_errno ;
   int si_code ;
   union __anonunion__sifields_11 _sifields ;
};
typedef struct siginfo siginfo_t;
enum __anonenum_18 {
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
enum __anonenum_19 {
    ILL_ILLOPC = 1,
    ILL_ILLOPN = 2,
    ILL_ILLADR = 3,
    ILL_ILLTRP = 4,
    ILL_PRVOPC = 5,
    ILL_PRVREG = 6,
    ILL_COPROC = 7,
    ILL_BADSTK = 8
} ;
enum __anonenum_20 {
    FPE_INTDIV = 1,
    FPE_INTOVF = 2,
    FPE_FLTDIV = 3,
    FPE_FLTOVF = 4,
    FPE_FLTUND = 5,
    FPE_FLTRES = 6,
    FPE_FLTINV = 7,
    FPE_FLTSUB = 8
} ;
enum __anonenum_21 {
    SEGV_MAPERR = 1,
    SEGV_ACCERR = 2
} ;
enum __anonenum_22 {
    BUS_ADRALN = 1,
    BUS_ADRERR = 2,
    BUS_OBJERR = 3
} ;
enum __anonenum_23 {
    TRAP_BRKPT = 1,
    TRAP_TRACE = 2
} ;
enum __anonenum_24 {
    CLD_EXITED = 1,
    CLD_KILLED = 2,
    CLD_DUMPED = 3,
    CLD_TRAPPED = 4,
    CLD_STOPPED = 5,
    CLD_CONTINUED = 6
} ;
enum __anonenum_25 {
    POLL_IN = 1,
    POLL_OUT = 2,
    POLL_MSG = 3,
    POLL_ERR = 4,
    POLL_PRI = 5,
    POLL_HUP = 6
} ;
struct __anonstruct__sigev_thread_27 {
   void (*_function)(sigval_t  ) ;
   void *_attribute ;
};
union __anonunion__sigev_un_26 {
   int _pad[64U / sizeof(int ) - 3U] ;
   __pid_t _tid ;
   struct __anonstruct__sigev_thread_27 _sigev_thread ;
};
struct sigevent {
   sigval_t sigev_value ;
   int sigev_signo ;
   int sigev_notify ;
   union __anonunion__sigev_un_26 _sigev_un ;
};
typedef struct sigevent sigevent_t;
enum __anonenum_28 {
    SIGEV_SIGNAL = 0,
    SIGEV_NONE = 1,
    SIGEV_THREAD = 2,
    SIGEV_THREAD_ID = 4
} ;
typedef void (*__sighandler_t)(int  );
typedef void (*sig_t)(int  );
union __anonunion___sigaction_handler_29 {
   void (*sa_handler)(int  ) ;
   void (*sa_sigaction)(int  , siginfo_t * , void * ) ;
};
struct sigaction {
   union __anonunion___sigaction_handler_29 __sigaction_handler ;
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
struct __anonstruct___kernel_fd_set_30 {
   unsigned long fds_bits[1024U / (8U * sizeof(unsigned long ))] ;
};
typedef struct __anonstruct___kernel_fd_set_30 __kernel_fd_set;
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
struct __anonstruct___kernel_fsid_t_31 {
   int val[2] ;
};
typedef struct __anonstruct___kernel_fsid_t_31 __kernel_fsid_t;
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
union __anonunion____missing_field_name_32 {
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
   union __anonunion____missing_field_name_32 __annonCompField1 ;
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
enum __anonenum_33 {
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
struct __anonstruct_mcontext_t_34 {
   gregset_t gregs ;
   fpregset_t fpregs ;
   unsigned long oldmask ;
   unsigned long cr2 ;
};
typedef struct __anonstruct_mcontext_t_34 mcontext_t;
struct ucontext {
   unsigned long uc_flags ;
   struct ucontext *uc_link ;
   stack_t uc_stack ;
   mcontext_t uc_mcontext ;
   __sigset_t uc_sigmask ;
   struct _libc_fpstate __fpregs_mem ;
};
typedef struct ucontext ucontext_t;
typedef unsigned long pthread_t;
union __anonunion_pthread_attr_t_35 {
   char __size[36] ;
   long __align ;
};
union __anonunion____missing_field_name_37 {
   int __spins ;
   __pthread_slist_t __list ;
};
union __anonunion_pthread_mutex_t_36 {
   struct __pthread_mutex_s __data ;
   char __size[24] ;
   long __align ;
};
union __anonunion_pthread_mutexattr_t_38 {
   char __size[4] ;
   long __align ;
};
struct __anonstruct___data_40 {
   int __lock ;
   unsigned int __futex ;
   unsigned long long __total_seq ;
   unsigned long long __wakeup_seq ;
   unsigned long long __woken_seq ;
   void *__mutex ;
   unsigned int __nwaiters ;
   unsigned int __broadcast_seq ;
};
union __anonunion_pthread_cond_t_39 {
   struct __anonstruct___data_40 __data ;
   char __size[48] ;
   long long __align ;
};
union __anonunion_pthread_condattr_t_41 {
   char __size[4] ;
   long __align ;
};
typedef unsigned int pthread_key_t;
typedef int pthread_once_t;
struct __anonstruct___data_43 {
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
union __anonunion_pthread_rwlock_t_42 {
   struct __anonstruct___data_43 __data ;
   char __size[32] ;
   long __align ;
};
union __anonunion_pthread_rwlockattr_t_44 {
   char __size[8] ;
   long __align ;
};
typedef int volatile   pthread_spinlock_t;
union __anonunion_pthread_barrier_t_45 {
   char __size[20] ;
   long __align ;
};
union __anonunion_pthread_barrierattr_t_46 {
   char __size[4] ;
   int __align ;
};
typedef __clock_t clock_t;
typedef __clockid_t clockid_t;
typedef __timer_t timer_t;
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
enum __anonenum_GBookmarkFileError_47 {
    G_BOOKMARK_FILE_ERROR_INVALID_URI = 0,
    G_BOOKMARK_FILE_ERROR_INVALID_VALUE = 1,
    G_BOOKMARK_FILE_ERROR_APP_NOT_REGISTERED = 2,
    G_BOOKMARK_FILE_ERROR_URI_NOT_FOUND = 3,
    G_BOOKMARK_FILE_ERROR_READ = 4,
    G_BOOKMARK_FILE_ERROR_UNKNOWN_ENCODING = 5,
    G_BOOKMARK_FILE_ERROR_WRITE = 6,
    G_BOOKMARK_FILE_ERROR_FILE_NOT_FOUND = 7
} ;
typedef enum __anonenum_GBookmarkFileError_47 GBookmarkFileError;
struct _GBookmarkFile;
typedef struct _GBookmarkFile GBookmarkFile;
enum __anonenum_GSliceConfig_48 {
    G_SLICE_CONFIG_ALWAYS_MALLOC = 1,
    G_SLICE_CONFIG_BYPASS_MAGAZINES = 2,
    G_SLICE_CONFIG_WORKING_SET_MSECS = 3,
    G_SLICE_CONFIG_COLOR_INCREMENT = 4,
    G_SLICE_CONFIG_CHUNK_SIZES = 5,
    G_SLICE_CONFIG_CONTENTION_COUNTER = 6
} ;
typedef enum __anonenum_GSliceConfig_48 GSliceConfig;
struct _GMemVTable;
typedef struct _GMemVTable GMemVTable;
struct _GMemVTable {
   gpointer (*malloc)(gsize n_bytes ) ;
   gpointer (*realloc)(gpointer mem , gsize n_bytes ) ;
   void (*free)(gpointer mem ) ;
   gpointer (*calloc)(gsize n_blocks , gsize n_block_bytes ) ;
   gpointer (*try_malloc)(gsize n_bytes ) ;
   gpointer (*try_realloc)(gpointer mem , gsize n_bytes ) ;
};
struct _GAllocator;
typedef struct _GAllocator GAllocator;
struct _GMemChunk;
typedef struct _GMemChunk GMemChunk;
struct _GList;
typedef struct _GList GList;
struct _GList {
   gpointer data ;
   GList *next ;
   GList *prev ;
};
struct _GCache;
typedef struct _GCache GCache;
typedef gpointer (*GCacheNewFunc)(gpointer key );
typedef gpointer (*GCacheDupFunc)(gpointer value );
typedef void (*GCacheDestroyFunc)(gpointer value );
enum __anonenum_GChecksumType_49 {
    G_CHECKSUM_MD5 = 0,
    G_CHECKSUM_SHA1 = 1,
    G_CHECKSUM_SHA256 = 2
} ;
typedef enum __anonenum_GChecksumType_49 GChecksumType;
struct _GChecksum;
typedef struct _GChecksum GChecksum;
struct _GCompletion;
typedef struct _GCompletion GCompletion;
typedef gchar *(*GCompletionFunc)(gpointer  );
typedef gint (*GCompletionStrncmpFunc)(gchar const   *s1 , gchar const   *s2 ,
                                       gsize n );
struct _GCompletion {
   GList *items ;
   gchar *(*func)(gpointer  ) ;
   gchar *prefix ;
   GList *cache ;
   gint (*strncmp_func)(gchar const   *s1 , gchar const   *s2 , gsize n ) ;
};
enum __anonenum_GConvertError_50 {
    G_CONVERT_ERROR_NO_CONVERSION = 0,
    G_CONVERT_ERROR_ILLEGAL_SEQUENCE = 1,
    G_CONVERT_ERROR_FAILED = 2,
    G_CONVERT_ERROR_PARTIAL_INPUT = 3,
    G_CONVERT_ERROR_BAD_URI = 4,
    G_CONVERT_ERROR_NOT_ABSOLUTE_PATH = 5
} ;
typedef enum __anonenum_GConvertError_50 GConvertError;
struct _GIConv;
typedef struct _GIConv *GIConv;
struct _GData;
typedef struct _GData GData;
typedef void (*GDataForeachFunc)(GQuark key_id , gpointer data ,
                                 gpointer user_data );
typedef gint32 GTime;
typedef guint16 GDateYear;
typedef guint8 GDateDay;
struct _GDate;
typedef struct _GDate GDate;
enum __anonenum_GDateDMY_51 {
    G_DATE_DAY = 0,
    G_DATE_MONTH = 1,
    G_DATE_YEAR = 2
} ;
typedef enum __anonenum_GDateDMY_51 GDateDMY;
enum __anonenum_GDateWeekday_52 {
    G_DATE_BAD_WEEKDAY = 0,
    G_DATE_MONDAY = 1,
    G_DATE_TUESDAY = 2,
    G_DATE_WEDNESDAY = 3,
    G_DATE_THURSDAY = 4,
    G_DATE_FRIDAY = 5,
    G_DATE_SATURDAY = 6,
    G_DATE_SUNDAY = 7
} ;
typedef enum __anonenum_GDateWeekday_52 GDateWeekday;
enum __anonenum_GDateMonth_53 {
    G_DATE_BAD_MONTH = 0,
    G_DATE_JANUARY = 1,
    G_DATE_FEBRUARY = 2,
    G_DATE_MARCH = 3,
    G_DATE_APRIL = 4,
    G_DATE_MAY = 5,
    G_DATE_JUNE = 6,
    G_DATE_JULY = 7,
    G_DATE_AUGUST = 8,
    G_DATE_SEPTEMBER = 9,
    G_DATE_OCTOBER = 10,
    G_DATE_NOVEMBER = 11,
    G_DATE_DECEMBER = 12
} ;
typedef enum __anonenum_GDateMonth_53 GDateMonth;
struct _GDate {
   guint julian_days : 32 ;
   guint julian : 1 ;
   guint dmy : 1 ;
   guint day : 6 ;
   guint month : 4 ;
   guint year : 16 ;
};
struct _GDir;
typedef struct _GDir GDir;
enum __anonenum_GFileError_54 {
    G_FILE_ERROR_EXIST = 0,
    G_FILE_ERROR_ISDIR = 1,
    G_FILE_ERROR_ACCES = 2,
    G_FILE_ERROR_NAMETOOLONG = 3,
    G_FILE_ERROR_NOENT = 4,
    G_FILE_ERROR_NOTDIR = 5,
    G_FILE_ERROR_NXIO = 6,
    G_FILE_ERROR_NODEV = 7,
    G_FILE_ERROR_ROFS = 8,
    G_FILE_ERROR_TXTBSY = 9,
    G_FILE_ERROR_FAULT = 10,
    G_FILE_ERROR_LOOP = 11,
    G_FILE_ERROR_NOSPC = 12,
    G_FILE_ERROR_NOMEM = 13,
    G_FILE_ERROR_MFILE = 14,
    G_FILE_ERROR_NFILE = 15,
    G_FILE_ERROR_BADF = 16,
    G_FILE_ERROR_INVAL = 17,
    G_FILE_ERROR_PIPE = 18,
    G_FILE_ERROR_AGAIN = 19,
    G_FILE_ERROR_INTR = 20,
    G_FILE_ERROR_IO = 21,
    G_FILE_ERROR_PERM = 22,
    G_FILE_ERROR_NOSYS = 23,
    G_FILE_ERROR_FAILED = 24
} ;
typedef enum __anonenum_GFileError_54 GFileError;
enum __anonenum_GFileTest_55 {
    G_FILE_TEST_IS_REGULAR = 1,
    G_FILE_TEST_IS_SYMLINK = 2,
    G_FILE_TEST_IS_DIR = 4,
    G_FILE_TEST_IS_EXECUTABLE = 8,
    G_FILE_TEST_EXISTS = 16
} ;
typedef enum __anonenum_GFileTest_55 GFileTest;
struct _GHashTable;
typedef struct _GHashTable GHashTable;
typedef gboolean (*GHRFunc)(gpointer key , gpointer value , gpointer user_data );
struct _GHashTableIter;
typedef struct _GHashTableIter GHashTableIter;
struct _GHashTableIter {
   gpointer dummy1 ;
   gpointer dummy2 ;
   gpointer dummy3 ;
   int dummy4 ;
   gboolean dummy5 ;
   gpointer dummy6 ;
};
struct _GHook;
typedef struct _GHook GHook;
struct _GHookList;
typedef struct _GHookList GHookList;
typedef gint (*GHookCompareFunc)(GHook *new_hook , GHook *sibling );
typedef gboolean (*GHookFindFunc)(GHook *hook , gpointer data );
typedef void (*GHookMarshaller)(GHook *hook , gpointer marshal_data );
typedef gboolean (*GHookCheckMarshaller)(GHook *hook , gpointer marshal_data );
typedef void (*GHookFunc)(gpointer data );
typedef gboolean (*GHookCheckFunc)(gpointer data );
typedef void (*GHookFinalizeFunc)(GHookList *hook_list , GHook *hook );
enum __anonenum_GHookFlagMask_56 {
    G_HOOK_FLAG_ACTIVE = 1,
    G_HOOK_FLAG_IN_CALL = 2,
    G_HOOK_FLAG_MASK = 15
} ;
typedef enum __anonenum_GHookFlagMask_56 GHookFlagMask;
struct _GHookList {
   gulong seq_id ;
   guint hook_size : 16 ;
   guint is_setup : 1 ;
   GHook *hooks ;
   gpointer dummy3 ;
   void (*finalize_hook)(GHookList *hook_list , GHook *hook ) ;
   gpointer dummy[2] ;
};
struct _GHook {
   gpointer data ;
   GHook *next ;
   GHook *prev ;
   guint ref_count ;
   gulong hook_id ;
   guint flags ;
   gpointer func ;
   void (*destroy)(gpointer data ) ;
};
struct _GPollFD;
typedef struct _GPollFD GPollFD;
typedef gint (*GPollFunc)(GPollFD *ufds , guint nfsd , gint timeout_ );
struct _GPollFD {
   gint fd ;
   gushort events ;
   gushort revents ;
};
struct _GSList;
typedef struct _GSList GSList;
struct _GSList {
   gpointer data ;
   GSList *next ;
};
struct _GMainContext;
typedef struct _GMainContext GMainContext;
struct _GMainLoop;
typedef struct _GMainLoop GMainLoop;
struct _GSource;
typedef struct _GSource GSource;
struct _GSourceCallbackFuncs;
typedef struct _GSourceCallbackFuncs GSourceCallbackFuncs;
struct _GSourceFuncs;
typedef struct _GSourceFuncs GSourceFuncs;
typedef gboolean (*GSourceFunc)(gpointer data );
typedef void (*GChildWatchFunc)(GPid pid , gint status , gpointer data );
struct _GSource {
   gpointer callback_data ;
   GSourceCallbackFuncs *callback_funcs ;
   GSourceFuncs *source_funcs ;
   guint ref_count ;
   GMainContext *context ;
   gint priority ;
   guint flags ;
   guint source_id ;
   GSList *poll_fds ;
   GSource *prev ;
   GSource *next ;
   gpointer reserved1 ;
   gpointer reserved2 ;
};
struct _GSourceCallbackFuncs {
   void (*ref)(gpointer cb_data ) ;
   void (*unref)(gpointer cb_data ) ;
   void (*get)(gpointer cb_data , GSource *source , GSourceFunc *func ,
               gpointer *data ) ;
};
typedef void (*GSourceDummyMarshal)(void);
struct _GSourceFuncs {
   gboolean (*prepare)(GSource *source , gint *timeout_ ) ;
   gboolean (*check)(GSource *source ) ;
   gboolean (*dispatch)(GSource *source , gboolean (*callback)(gpointer data ) ,
                        gpointer user_data ) ;
   void (*finalize)(GSource *source ) ;
   gboolean (*closure_callback)(gpointer data ) ;
   void (*closure_marshal)(void) ;
};
typedef guint32 gunichar;
typedef guint16 gunichar2;
enum __anonenum_GUnicodeType_57 {
    G_UNICODE_CONTROL = 0,
    G_UNICODE_FORMAT = 1,
    G_UNICODE_UNASSIGNED = 2,
    G_UNICODE_PRIVATE_USE = 3,
    G_UNICODE_SURROGATE = 4,
    G_UNICODE_LOWERCASE_LETTER = 5,
    G_UNICODE_MODIFIER_LETTER = 6,
    G_UNICODE_OTHER_LETTER = 7,
    G_UNICODE_TITLECASE_LETTER = 8,
    G_UNICODE_UPPERCASE_LETTER = 9,
    G_UNICODE_COMBINING_MARK = 10,
    G_UNICODE_ENCLOSING_MARK = 11,
    G_UNICODE_NON_SPACING_MARK = 12,
    G_UNICODE_DECIMAL_NUMBER = 13,
    G_UNICODE_LETTER_NUMBER = 14,
    G_UNICODE_OTHER_NUMBER = 15,
    G_UNICODE_CONNECT_PUNCTUATION = 16,
    G_UNICODE_DASH_PUNCTUATION = 17,
    G_UNICODE_CLOSE_PUNCTUATION = 18,
    G_UNICODE_FINAL_PUNCTUATION = 19,
    G_UNICODE_INITIAL_PUNCTUATION = 20,
    G_UNICODE_OTHER_PUNCTUATION = 21,
    G_UNICODE_OPEN_PUNCTUATION = 22,
    G_UNICODE_CURRENCY_SYMBOL = 23,
    G_UNICODE_MODIFIER_SYMBOL = 24,
    G_UNICODE_MATH_SYMBOL = 25,
    G_UNICODE_OTHER_SYMBOL = 26,
    G_UNICODE_LINE_SEPARATOR = 27,
    G_UNICODE_PARAGRAPH_SEPARATOR = 28,
    G_UNICODE_SPACE_SEPARATOR = 29
} ;
typedef enum __anonenum_GUnicodeType_57 GUnicodeType;
enum __anonenum_GUnicodeBreakType_58 {
    G_UNICODE_BREAK_MANDATORY = 0,
    G_UNICODE_BREAK_CARRIAGE_RETURN = 1,
    G_UNICODE_BREAK_LINE_FEED = 2,
    G_UNICODE_BREAK_COMBINING_MARK = 3,
    G_UNICODE_BREAK_SURROGATE = 4,
    G_UNICODE_BREAK_ZERO_WIDTH_SPACE = 5,
    G_UNICODE_BREAK_INSEPARABLE = 6,
    G_UNICODE_BREAK_NON_BREAKING_GLUE = 7,
    G_UNICODE_BREAK_CONTINGENT = 8,
    G_UNICODE_BREAK_SPACE = 9,
    G_UNICODE_BREAK_AFTER = 10,
    G_UNICODE_BREAK_BEFORE = 11,
    G_UNICODE_BREAK_BEFORE_AND_AFTER = 12,
    G_UNICODE_BREAK_HYPHEN = 13,
    G_UNICODE_BREAK_NON_STARTER = 14,
    G_UNICODE_BREAK_OPEN_PUNCTUATION = 15,
    G_UNICODE_BREAK_CLOSE_PUNCTUATION = 16,
    G_UNICODE_BREAK_QUOTATION = 17,
    G_UNICODE_BREAK_EXCLAMATION = 18,
    G_UNICODE_BREAK_IDEOGRAPHIC = 19,
    G_UNICODE_BREAK_NUMERIC = 20,
    G_UNICODE_BREAK_INFIX_SEPARATOR = 21,
    G_UNICODE_BREAK_SYMBOL = 22,
    G_UNICODE_BREAK_ALPHABETIC = 23,
    G_UNICODE_BREAK_PREFIX = 24,
    G_UNICODE_BREAK_POSTFIX = 25,
    G_UNICODE_BREAK_COMPLEX_CONTEXT = 26,
    G_UNICODE_BREAK_AMBIGUOUS = 27,
    G_UNICODE_BREAK_UNKNOWN = 28,
    G_UNICODE_BREAK_NEXT_LINE = 29,
    G_UNICODE_BREAK_WORD_JOINER = 30,
    G_UNICODE_BREAK_HANGUL_L_JAMO = 31,
    G_UNICODE_BREAK_HANGUL_V_JAMO = 32,
    G_UNICODE_BREAK_HANGUL_T_JAMO = 33,
    G_UNICODE_BREAK_HANGUL_LV_SYLLABLE = 34,
    G_UNICODE_BREAK_HANGUL_LVT_SYLLABLE = 35
} ;
typedef enum __anonenum_GUnicodeBreakType_58 GUnicodeBreakType;
enum __anonenum_GUnicodeScript_59 {
    G_UNICODE_SCRIPT_INVALID_CODE = -1,
    G_UNICODE_SCRIPT_COMMON = 0,
    G_UNICODE_SCRIPT_INHERITED = 1,
    G_UNICODE_SCRIPT_ARABIC = 2,
    G_UNICODE_SCRIPT_ARMENIAN = 3,
    G_UNICODE_SCRIPT_BENGALI = 4,
    G_UNICODE_SCRIPT_BOPOMOFO = 5,
    G_UNICODE_SCRIPT_CHEROKEE = 6,
    G_UNICODE_SCRIPT_COPTIC = 7,
    G_UNICODE_SCRIPT_CYRILLIC = 8,
    G_UNICODE_SCRIPT_DESERET = 9,
    G_UNICODE_SCRIPT_DEVANAGARI = 10,
    G_UNICODE_SCRIPT_ETHIOPIC = 11,
    G_UNICODE_SCRIPT_GEORGIAN = 12,
    G_UNICODE_SCRIPT_GOTHIC = 13,
    G_UNICODE_SCRIPT_GREEK = 14,
    G_UNICODE_SCRIPT_GUJARATI = 15,
    G_UNICODE_SCRIPT_GURMUKHI = 16,
    G_UNICODE_SCRIPT_HAN = 17,
    G_UNICODE_SCRIPT_HANGUL = 18,
    G_UNICODE_SCRIPT_HEBREW = 19,
    G_UNICODE_SCRIPT_HIRAGANA = 20,
    G_UNICODE_SCRIPT_KANNADA = 21,
    G_UNICODE_SCRIPT_KATAKANA = 22,
    G_UNICODE_SCRIPT_KHMER = 23,
    G_UNICODE_SCRIPT_LAO = 24,
    G_UNICODE_SCRIPT_LATIN = 25,
    G_UNICODE_SCRIPT_MALAYALAM = 26,
    G_UNICODE_SCRIPT_MONGOLIAN = 27,
    G_UNICODE_SCRIPT_MYANMAR = 28,
    G_UNICODE_SCRIPT_OGHAM = 29,
    G_UNICODE_SCRIPT_OLD_ITALIC = 30,
    G_UNICODE_SCRIPT_ORIYA = 31,
    G_UNICODE_SCRIPT_RUNIC = 32,
    G_UNICODE_SCRIPT_SINHALA = 33,
    G_UNICODE_SCRIPT_SYRIAC = 34,
    G_UNICODE_SCRIPT_TAMIL = 35,
    G_UNICODE_SCRIPT_TELUGU = 36,
    G_UNICODE_SCRIPT_THAANA = 37,
    G_UNICODE_SCRIPT_THAI = 38,
    G_UNICODE_SCRIPT_TIBETAN = 39,
    G_UNICODE_SCRIPT_CANADIAN_ABORIGINAL = 40,
    G_UNICODE_SCRIPT_YI = 41,
    G_UNICODE_SCRIPT_TAGALOG = 42,
    G_UNICODE_SCRIPT_HANUNOO = 43,
    G_UNICODE_SCRIPT_BUHID = 44,
    G_UNICODE_SCRIPT_TAGBANWA = 45,
    G_UNICODE_SCRIPT_BRAILLE = 46,
    G_UNICODE_SCRIPT_CYPRIOT = 47,
    G_UNICODE_SCRIPT_LIMBU = 48,
    G_UNICODE_SCRIPT_OSMANYA = 49,
    G_UNICODE_SCRIPT_SHAVIAN = 50,
    G_UNICODE_SCRIPT_LINEAR_B = 51,
    G_UNICODE_SCRIPT_TAI_LE = 52,
    G_UNICODE_SCRIPT_UGARITIC = 53,
    G_UNICODE_SCRIPT_NEW_TAI_LUE = 54,
    G_UNICODE_SCRIPT_BUGINESE = 55,
    G_UNICODE_SCRIPT_GLAGOLITIC = 56,
    G_UNICODE_SCRIPT_TIFINAGH = 57,
    G_UNICODE_SCRIPT_SYLOTI_NAGRI = 58,
    G_UNICODE_SCRIPT_OLD_PERSIAN = 59,
    G_UNICODE_SCRIPT_KHAROSHTHI = 60,
    G_UNICODE_SCRIPT_UNKNOWN = 61,
    G_UNICODE_SCRIPT_BALINESE = 62,
    G_UNICODE_SCRIPT_CUNEIFORM = 63,
    G_UNICODE_SCRIPT_PHOENICIAN = 64,
    G_UNICODE_SCRIPT_PHAGS_PA = 65,
    G_UNICODE_SCRIPT_NKO = 66,
    G_UNICODE_SCRIPT_KAYAH_LI = 67,
    G_UNICODE_SCRIPT_LEPCHA = 68,
    G_UNICODE_SCRIPT_REJANG = 69,
    G_UNICODE_SCRIPT_SUNDANESE = 70,
    G_UNICODE_SCRIPT_SAURASHTRA = 71,
    G_UNICODE_SCRIPT_CHAM = 72,
    G_UNICODE_SCRIPT_OL_CHIKI = 73,
    G_UNICODE_SCRIPT_VAI = 74,
    G_UNICODE_SCRIPT_CARIAN = 75,
    G_UNICODE_SCRIPT_LYCIAN = 76,
    G_UNICODE_SCRIPT_LYDIAN = 77
} ;
typedef enum __anonenum_GUnicodeScript_59 GUnicodeScript;
enum __anonenum_GNormalizeMode_60 {
    G_NORMALIZE_DEFAULT = 0,
    G_NORMALIZE_NFD = 0,
    G_NORMALIZE_DEFAULT_COMPOSE = 1,
    G_NORMALIZE_NFC = 1,
    G_NORMALIZE_ALL = 2,
    G_NORMALIZE_NFKD = 2,
    G_NORMALIZE_ALL_COMPOSE = 3,
    G_NORMALIZE_NFKC = 3
} ;
typedef enum __anonenum_GNormalizeMode_60 GNormalizeMode;
struct _GString;
typedef struct _GString GString;
struct _GStringChunk;
typedef struct _GStringChunk GStringChunk;
struct _GString {
   gchar *str ;
   gsize len ;
   gsize allocated_len ;
};
struct _GIOChannel;
typedef struct _GIOChannel GIOChannel;
struct _GIOFuncs;
typedef struct _GIOFuncs GIOFuncs;
enum __anonenum_GIOError_61 {
    G_IO_ERROR_NONE = 0,
    G_IO_ERROR_AGAIN = 1,
    G_IO_ERROR_INVAL = 2,
    G_IO_ERROR_UNKNOWN = 3
} ;
typedef enum __anonenum_GIOError_61 GIOError;
enum __anonenum_GIOChannelError_62 {
    G_IO_CHANNEL_ERROR_FBIG = 0,
    G_IO_CHANNEL_ERROR_INVAL = 1,
    G_IO_CHANNEL_ERROR_IO = 2,
    G_IO_CHANNEL_ERROR_ISDIR = 3,
    G_IO_CHANNEL_ERROR_NOSPC = 4,
    G_IO_CHANNEL_ERROR_NXIO = 5,
    G_IO_CHANNEL_ERROR_OVERFLOW = 6,
    G_IO_CHANNEL_ERROR_PIPE = 7,
    G_IO_CHANNEL_ERROR_FAILED = 8
} ;
typedef enum __anonenum_GIOChannelError_62 GIOChannelError;
enum __anonenum_GIOStatus_63 {
    G_IO_STATUS_ERROR = 0,
    G_IO_STATUS_NORMAL = 1,
    G_IO_STATUS_EOF = 2,
    G_IO_STATUS_AGAIN = 3
} ;
typedef enum __anonenum_GIOStatus_63 GIOStatus;
enum __anonenum_GSeekType_64 {
    G_SEEK_CUR = 0,
    G_SEEK_SET = 1,
    G_SEEK_END = 2
} ;
typedef enum __anonenum_GSeekType_64 GSeekType;
enum __anonenum_GIOCondition_65 {
    G_IO_IN = 1,
    G_IO_OUT = 4,
    G_IO_PRI = 2,
    G_IO_ERR = 8,
    G_IO_HUP = 16,
    G_IO_NVAL = 32
} ;
typedef enum __anonenum_GIOCondition_65 GIOCondition;
enum __anonenum_GIOFlags_66 {
    G_IO_FLAG_APPEND = 1,
    G_IO_FLAG_NONBLOCK = 2,
    G_IO_FLAG_IS_READABLE = 4,
    G_IO_FLAG_IS_WRITEABLE = 8,
    G_IO_FLAG_IS_SEEKABLE = 16,
    G_IO_FLAG_MASK = 31,
    G_IO_FLAG_GET_MASK = 31,
    G_IO_FLAG_SET_MASK = 3
} ;
typedef enum __anonenum_GIOFlags_66 GIOFlags;
struct _GIOChannel {
   gint ref_count ;
   GIOFuncs *funcs ;
   gchar *encoding ;
   GIConv read_cd ;
   GIConv write_cd ;
   gchar *line_term ;
   guint line_term_len ;
   gsize buf_size ;
   GString *read_buf ;
   GString *encoded_read_buf ;
   GString *write_buf ;
   gchar partial_write_buf[6] ;
   guint use_buffer : 1 ;
   guint do_encode : 1 ;
   guint close_on_unref : 1 ;
   guint is_readable : 1 ;
   guint is_writeable : 1 ;
   guint is_seekable : 1 ;
   gpointer reserved1 ;
   gpointer reserved2 ;
};
typedef gboolean (*GIOFunc)(GIOChannel *source , GIOCondition condition ,
                            gpointer data );
struct _GIOFuncs {
   GIOStatus (*io_read)(GIOChannel *channel , gchar *buf , gsize count ,
                        gsize *bytes_read , GError **err ) ;
   GIOStatus (*io_write)(GIOChannel *channel , gchar const   *buf ,
                         gsize count , gsize *bytes_written , GError **err ) ;
   GIOStatus (*io_seek)(GIOChannel *channel , gint64 offset , GSeekType type ,
                        GError **err ) ;
   GIOStatus (*io_close)(GIOChannel *channel , GError **err ) ;
   GSource *(*io_create_watch)(GIOChannel *channel , GIOCondition condition ) ;
   void (*io_free)(GIOChannel *channel ) ;
   GIOStatus (*io_set_flags)(GIOChannel *channel , GIOFlags flags ,
                             GError **err ) ;
   GIOFlags (*io_get_flags)(GIOChannel *channel ) ;
};
enum __anonenum_GKeyFileError_67 {
    G_KEY_FILE_ERROR_UNKNOWN_ENCODING = 0,
    G_KEY_FILE_ERROR_PARSE = 1,
    G_KEY_FILE_ERROR_NOT_FOUND = 2,
    G_KEY_FILE_ERROR_KEY_NOT_FOUND = 3,
    G_KEY_FILE_ERROR_GROUP_NOT_FOUND = 4,
    G_KEY_FILE_ERROR_INVALID_VALUE = 5
} ;
typedef enum __anonenum_GKeyFileError_67 GKeyFileError;
struct _GKeyFile;
typedef struct _GKeyFile GKeyFile;
enum __anonenum_GKeyFileFlags_68 {
    G_KEY_FILE_NONE = 0,
    G_KEY_FILE_KEEP_COMMENTS = 1,
    G_KEY_FILE_KEEP_TRANSLATIONS = 2
} ;
typedef enum __anonenum_GKeyFileFlags_68 GKeyFileFlags;
struct _GMappedFile;
typedef struct _GMappedFile GMappedFile;
enum __anonenum_GMarkupError_69 {
    G_MARKUP_ERROR_BAD_UTF8 = 0,
    G_MARKUP_ERROR_EMPTY = 1,
    G_MARKUP_ERROR_PARSE = 2,
    G_MARKUP_ERROR_UNKNOWN_ELEMENT = 3,
    G_MARKUP_ERROR_UNKNOWN_ATTRIBUTE = 4,
    G_MARKUP_ERROR_INVALID_CONTENT = 5,
    G_MARKUP_ERROR_MISSING_ATTRIBUTE = 6
} ;
typedef enum __anonenum_GMarkupError_69 GMarkupError;
enum __anonenum_GMarkupParseFlags_70 {
    G_MARKUP_DO_NOT_USE_THIS_UNSUPPORTED_FLAG = 1,
    G_MARKUP_TREAT_CDATA_AS_TEXT = 2,
    G_MARKUP_PREFIX_ERROR_POSITION = 4
} ;
typedef enum __anonenum_GMarkupParseFlags_70 GMarkupParseFlags;
struct _GMarkupParseContext;
typedef struct _GMarkupParseContext GMarkupParseContext;
struct _GMarkupParser;
typedef struct _GMarkupParser GMarkupParser;
struct _GMarkupParser {
   void (*start_element)(GMarkupParseContext *context ,
                         gchar const   *element_name ,
                         gchar const   **attribute_names ,
                         gchar const   **attribute_values , gpointer user_data ,
                         GError **error ) ;
   void (*end_element)(GMarkupParseContext *context ,
                       gchar const   *element_name , gpointer user_data ,
                       GError **error ) ;
   void (*text)(GMarkupParseContext *context , gchar const   *text ,
                gsize text_len , gpointer user_data , GError **error ) ;
   void (*passthrough)(GMarkupParseContext *context ,
                       gchar const   *passthrough_text , gsize text_len ,
                       gpointer user_data , GError **error ) ;
   void (*error)(GMarkupParseContext *context , GError *error ,
                 gpointer user_data ) ;
};
enum __anonenum_GMarkupCollectType_71 {
    G_MARKUP_COLLECT_INVALID = 0,
    G_MARKUP_COLLECT_STRING = 1,
    G_MARKUP_COLLECT_STRDUP = 2,
    G_MARKUP_COLLECT_BOOLEAN = 3,
    G_MARKUP_COLLECT_TRISTATE = 4,
    G_MARKUP_COLLECT_OPTIONAL = 65536
} ;
typedef enum __anonenum_GMarkupCollectType_71 GMarkupCollectType;
enum __anonenum_GLogLevelFlags_72 {
    G_LOG_FLAG_RECURSION = 1,
    G_LOG_FLAG_FATAL = 2,
    G_LOG_LEVEL_ERROR = 4,
    G_LOG_LEVEL_CRITICAL = 8,
    G_LOG_LEVEL_WARNING = 16,
    G_LOG_LEVEL_MESSAGE = 32,
    G_LOG_LEVEL_INFO = 64,
    G_LOG_LEVEL_DEBUG = 128,
    G_LOG_LEVEL_MASK = -4
} ;
typedef enum __anonenum_GLogLevelFlags_72 GLogLevelFlags;
typedef void (*GLogFunc)(gchar const   *log_domain , GLogLevelFlags log_level ,
                         gchar const   *message , gpointer user_data );
typedef void (*GPrintFunc)(gchar const   *string );
struct _GNode;
typedef struct _GNode GNode;
enum __anonenum_GTraverseFlags_73 {
    G_TRAVERSE_LEAVES = 1,
    G_TRAVERSE_NON_LEAVES = 2,
    G_TRAVERSE_ALL = 3,
    G_TRAVERSE_MASK = 3,
    G_TRAVERSE_LEAFS = 1,
    G_TRAVERSE_NON_LEAFS = 2
} ;
typedef enum __anonenum_GTraverseFlags_73 GTraverseFlags;
enum __anonenum_GTraverseType_74 {
    G_IN_ORDER = 0,
    G_PRE_ORDER = 1,
    G_POST_ORDER = 2,
    G_LEVEL_ORDER = 3
} ;
typedef enum __anonenum_GTraverseType_74 GTraverseType;
typedef gboolean (*GNodeTraverseFunc)(GNode *node , gpointer data );
typedef void (*GNodeForeachFunc)(GNode *node , gpointer data );
typedef gpointer (*GCopyFunc)(gconstpointer src , gpointer data );
struct _GNode {
   gpointer data ;
   GNode *next ;
   GNode *prev ;
   GNode *parent ;
   GNode *children ;
};
struct _GOptionContext;
typedef struct _GOptionContext GOptionContext;
struct _GOptionGroup;
typedef struct _GOptionGroup GOptionGroup;
struct _GOptionEntry;
typedef struct _GOptionEntry GOptionEntry;
enum __anonenum_GOptionFlags_75 {
    G_OPTION_FLAG_HIDDEN = 1,
    G_OPTION_FLAG_IN_MAIN = 2,
    G_OPTION_FLAG_REVERSE = 4,
    G_OPTION_FLAG_NO_ARG = 8,
    G_OPTION_FLAG_FILENAME = 16,
    G_OPTION_FLAG_OPTIONAL_ARG = 32,
    G_OPTION_FLAG_NOALIAS = 64
} ;
typedef enum __anonenum_GOptionFlags_75 GOptionFlags;
enum __anonenum_GOptionArg_76 {
    G_OPTION_ARG_NONE = 0,
    G_OPTION_ARG_STRING = 1,
    G_OPTION_ARG_INT = 2,
    G_OPTION_ARG_CALLBACK = 3,
    G_OPTION_ARG_FILENAME = 4,
    G_OPTION_ARG_STRING_ARRAY = 5,
    G_OPTION_ARG_FILENAME_ARRAY = 6,
    G_OPTION_ARG_DOUBLE = 7,
    G_OPTION_ARG_INT64 = 8
} ;
typedef enum __anonenum_GOptionArg_76 GOptionArg;
typedef gboolean (*GOptionArgFunc)(gchar const   *option_name ,
                                   gchar const   *value , gpointer data ,
                                   GError **error );
typedef gboolean (*GOptionParseFunc)(GOptionContext *context ,
                                     GOptionGroup *group , gpointer data ,
                                     GError **error );
typedef void (*GOptionErrorFunc)(GOptionContext *context , GOptionGroup *group ,
                                 gpointer data , GError **error );
enum __anonenum_GOptionError_77 {
    G_OPTION_ERROR_UNKNOWN_OPTION = 0,
    G_OPTION_ERROR_BAD_VALUE = 1,
    G_OPTION_ERROR_FAILED = 2
} ;
typedef enum __anonenum_GOptionError_77 GOptionError;
struct _GOptionEntry {
   gchar const   *long_name ;
   gchar short_name ;
   gint flags ;
   GOptionArg arg ;
   gpointer arg_data ;
   gchar const   *description ;
   gchar const   *arg_description ;
};
struct _GPatternSpec;
typedef struct _GPatternSpec GPatternSpec;
struct _GQueue;
typedef struct _GQueue GQueue;
struct _GQueue {
   GList *head ;
   GList *tail ;
   guint length ;
};
struct _GRand;
typedef struct _GRand GRand;
struct _GRelation;
typedef struct _GRelation GRelation;
struct _GTuples;
typedef struct _GTuples GTuples;
struct _GTuples {
   guint len ;
};
enum __anonenum_GRegexError_78 {
    G_REGEX_ERROR_COMPILE = 0,
    G_REGEX_ERROR_OPTIMIZE = 1,
    G_REGEX_ERROR_REPLACE = 2,
    G_REGEX_ERROR_MATCH = 3,
    G_REGEX_ERROR_INTERNAL = 4,
    G_REGEX_ERROR_STRAY_BACKSLASH = 101,
    G_REGEX_ERROR_MISSING_CONTROL_CHAR = 102,
    G_REGEX_ERROR_UNRECOGNIZED_ESCAPE = 103,
    G_REGEX_ERROR_QUANTIFIERS_OUT_OF_ORDER = 104,
    G_REGEX_ERROR_QUANTIFIER_TOO_BIG = 105,
    G_REGEX_ERROR_UNTERMINATED_CHARACTER_CLASS = 106,
    G_REGEX_ERROR_INVALID_ESCAPE_IN_CHARACTER_CLASS = 107,
    G_REGEX_ERROR_RANGE_OUT_OF_ORDER = 108,
    G_REGEX_ERROR_NOTHING_TO_REPEAT = 109,
    G_REGEX_ERROR_UNRECOGNIZED_CHARACTER = 112,
    G_REGEX_ERROR_POSIX_NAMED_CLASS_OUTSIDE_CLASS = 113,
    G_REGEX_ERROR_UNMATCHED_PARENTHESIS = 114,
    G_REGEX_ERROR_INEXISTENT_SUBPATTERN_REFERENCE = 115,
    G_REGEX_ERROR_UNTERMINATED_COMMENT = 118,
    G_REGEX_ERROR_EXPRESSION_TOO_LARGE = 120,
    G_REGEX_ERROR_MEMORY_ERROR = 121,
    G_REGEX_ERROR_VARIABLE_LENGTH_LOOKBEHIND = 125,
    G_REGEX_ERROR_MALFORMED_CONDITION = 126,
    G_REGEX_ERROR_TOO_MANY_CONDITIONAL_BRANCHES = 127,
    G_REGEX_ERROR_ASSERTION_EXPECTED = 128,
    G_REGEX_ERROR_UNKNOWN_POSIX_CLASS_NAME = 130,
    G_REGEX_ERROR_POSIX_COLLATING_ELEMENTS_NOT_SUPPORTED = 131,
    G_REGEX_ERROR_HEX_CODE_TOO_LARGE = 134,
    G_REGEX_ERROR_INVALID_CONDITION = 135,
    G_REGEX_ERROR_SINGLE_BYTE_MATCH_IN_LOOKBEHIND = 136,
    G_REGEX_ERROR_INFINITE_LOOP = 140,
    G_REGEX_ERROR_MISSING_SUBPATTERN_NAME_TERMINATOR = 142,
    G_REGEX_ERROR_DUPLICATE_SUBPATTERN_NAME = 143,
    G_REGEX_ERROR_MALFORMED_PROPERTY = 146,
    G_REGEX_ERROR_UNKNOWN_PROPERTY = 147,
    G_REGEX_ERROR_SUBPATTERN_NAME_TOO_LONG = 148,
    G_REGEX_ERROR_TOO_MANY_SUBPATTERNS = 149,
    G_REGEX_ERROR_INVALID_OCTAL_VALUE = 151,
    G_REGEX_ERROR_TOO_MANY_BRANCHES_IN_DEFINE = 154,
    G_REGEX_ERROR_DEFINE_REPETION = 155,
    G_REGEX_ERROR_INCONSISTENT_NEWLINE_OPTIONS = 156,
    G_REGEX_ERROR_MISSING_BACK_REFERENCE = 157
} ;
typedef enum __anonenum_GRegexError_78 GRegexError;
enum __anonenum_GRegexCompileFlags_79 {
    G_REGEX_CASELESS = 1,
    G_REGEX_MULTILINE = 2,
    G_REGEX_DOTALL = 4,
    G_REGEX_EXTENDED = 8,
    G_REGEX_ANCHORED = 16,
    G_REGEX_DOLLAR_ENDONLY = 32,
    G_REGEX_UNGREEDY = 512,
    G_REGEX_RAW = 2048,
    G_REGEX_NO_AUTO_CAPTURE = 4096,
    G_REGEX_OPTIMIZE = 8192,
    G_REGEX_DUPNAMES = 524288,
    G_REGEX_NEWLINE_CR = 1048576,
    G_REGEX_NEWLINE_LF = 2097152,
    G_REGEX_NEWLINE_CRLF = 3145728
} ;
typedef enum __anonenum_GRegexCompileFlags_79 GRegexCompileFlags;
enum __anonenum_GRegexMatchFlags_80 {
    G_REGEX_MATCH_ANCHORED = 16,
    G_REGEX_MATCH_NOTBOL = 128,
    G_REGEX_MATCH_NOTEOL = 256,
    G_REGEX_MATCH_NOTEMPTY = 1024,
    G_REGEX_MATCH_PARTIAL = 32768,
    G_REGEX_MATCH_NEWLINE_CR = 1048576,
    G_REGEX_MATCH_NEWLINE_LF = 2097152,
    G_REGEX_MATCH_NEWLINE_CRLF = 3145728,
    G_REGEX_MATCH_NEWLINE_ANY = 4194304
} ;
typedef enum __anonenum_GRegexMatchFlags_80 GRegexMatchFlags;
struct _GRegex;
typedef struct _GRegex GRegex;
struct _GMatchInfo;
typedef struct _GMatchInfo GMatchInfo;
typedef gboolean (*GRegexEvalCallback)(GMatchInfo const   *match_info ,
                                       GString *result , gpointer user_data );
struct _GScanner;
typedef struct _GScanner GScanner;
struct _GScannerConfig;
typedef struct _GScannerConfig GScannerConfig;
union _GTokenValue;
typedef union _GTokenValue GTokenValue;
typedef void (*GScannerMsgFunc)(GScanner *scanner , gchar *message ,
                                gboolean error );
enum __anonenum_GErrorType_81 {
    G_ERR_UNKNOWN = 0,
    G_ERR_UNEXP_EOF = 1,
    G_ERR_UNEXP_EOF_IN_STRING = 2,
    G_ERR_UNEXP_EOF_IN_COMMENT = 3,
    G_ERR_NON_DIGIT_IN_CONST = 4,
    G_ERR_DIGIT_RADIX = 5,
    G_ERR_FLOAT_RADIX = 6,
    G_ERR_FLOAT_MALFORMED = 7
} ;
typedef enum __anonenum_GErrorType_81 GErrorType;
enum __anonenum_GTokenType_82 {
    G_TOKEN_EOF = 0,
    G_TOKEN_LEFT_PAREN = 40,
    G_TOKEN_RIGHT_PAREN = 41,
    G_TOKEN_LEFT_CURLY = 123,
    G_TOKEN_RIGHT_CURLY = 125,
    G_TOKEN_LEFT_BRACE = 91,
    G_TOKEN_RIGHT_BRACE = 93,
    G_TOKEN_EQUAL_SIGN = 61,
    G_TOKEN_COMMA = 44,
    G_TOKEN_NONE = 256,
    G_TOKEN_ERROR = 257,
    G_TOKEN_CHAR = 258,
    G_TOKEN_BINARY = 259,
    G_TOKEN_OCTAL = 260,
    G_TOKEN_INT = 261,
    G_TOKEN_HEX = 262,
    G_TOKEN_FLOAT = 263,
    G_TOKEN_STRING = 264,
    G_TOKEN_SYMBOL = 265,
    G_TOKEN_IDENTIFIER = 266,
    G_TOKEN_IDENTIFIER_NULL = 267,
    G_TOKEN_COMMENT_SINGLE = 268,
    G_TOKEN_COMMENT_MULTI = 269,
    G_TOKEN_LAST = 270
} ;
typedef enum __anonenum_GTokenType_82 GTokenType;
union _GTokenValue {
   gpointer v_symbol ;
   gchar *v_identifier ;
   gulong v_binary ;
   gulong v_octal ;
   gulong v_int ;
   guint64 v_int64 ;
   gdouble v_float ;
   gulong v_hex ;
   gchar *v_string ;
   gchar *v_comment ;
   guchar v_char ;
   guint v_error ;
};
struct _GScannerConfig {
   gchar *cset_skip_characters ;
   gchar *cset_identifier_first ;
   gchar *cset_identifier_nth ;
   gchar *cpair_comment_single ;
   guint case_sensitive : 1 ;
   guint skip_comment_multi : 1 ;
   guint skip_comment_single : 1 ;
   guint scan_comment_multi : 1 ;
   guint scan_identifier : 1 ;
   guint scan_identifier_1char : 1 ;
   guint scan_identifier_NULL : 1 ;
   guint scan_symbols : 1 ;
   guint scan_binary : 1 ;
   guint scan_octal : 1 ;
   guint scan_float : 1 ;
   guint scan_hex : 1 ;
   guint scan_hex_dollar : 1 ;
   guint scan_string_sq : 1 ;
   guint scan_string_dq : 1 ;
   guint numbers_2_int : 1 ;
   guint int_2_float : 1 ;
   guint identifier_2_string : 1 ;
   guint char_2_token : 1 ;
   guint symbol_2_token : 1 ;
   guint scope_0_fallback : 1 ;
   guint store_int64 : 1 ;
   guint padding_dummy ;
};
struct _GScanner {
   gpointer user_data ;
   guint max_parse_errors ;
   guint parse_errors ;
   gchar const   *input_name ;
   GData *qdata ;
   GScannerConfig *config ;
   GTokenType token ;
   GTokenValue value ;
   guint line ;
   guint position ;
   GTokenType next_token ;
   GTokenValue next_value ;
   guint next_line ;
   guint next_position ;
   GHashTable *symbol_table ;
   gint input_fd ;
   gchar const   *text ;
   gchar const   *text_end ;
   gchar *buffer ;
   guint scope_id ;
   void (*msg_handler)(GScanner *scanner , gchar *message , gboolean error ) ;
};
struct _GSequence;
typedef struct _GSequence GSequence;
struct _GSequenceNode;
typedef struct _GSequenceNode GSequenceIter;
typedef gint (*GSequenceIterCompareFunc)(GSequenceIter *a , GSequenceIter *b ,
                                         gpointer data );
enum __anonenum_GShellError_83 {
    G_SHELL_ERROR_BAD_QUOTING = 0,
    G_SHELL_ERROR_EMPTY_STRING = 1,
    G_SHELL_ERROR_FAILED = 2
} ;
typedef enum __anonenum_GShellError_83 GShellError;
enum __anonenum_GSpawnError_84 {
    G_SPAWN_ERROR_FORK = 0,
    G_SPAWN_ERROR_READ = 1,
    G_SPAWN_ERROR_CHDIR = 2,
    G_SPAWN_ERROR_ACCES = 3,
    G_SPAWN_ERROR_PERM = 4,
    G_SPAWN_ERROR_2BIG = 5,
    G_SPAWN_ERROR_NOEXEC = 6,
    G_SPAWN_ERROR_NAMETOOLONG = 7,
    G_SPAWN_ERROR_NOENT = 8,
    G_SPAWN_ERROR_NOMEM = 9,
    G_SPAWN_ERROR_NOTDIR = 10,
    G_SPAWN_ERROR_LOOP = 11,
    G_SPAWN_ERROR_TXTBUSY = 12,
    G_SPAWN_ERROR_IO = 13,
    G_SPAWN_ERROR_NFILE = 14,
    G_SPAWN_ERROR_MFILE = 15,
    G_SPAWN_ERROR_INVAL = 16,
    G_SPAWN_ERROR_ISDIR = 17,
    G_SPAWN_ERROR_LIBBAD = 18,
    G_SPAWN_ERROR_FAILED = 19
} ;
typedef enum __anonenum_GSpawnError_84 GSpawnError;
typedef void (*GSpawnChildSetupFunc)(gpointer user_data );
enum __anonenum_GSpawnFlags_85 {
    G_SPAWN_LEAVE_DESCRIPTORS_OPEN = 1,
    G_SPAWN_DO_NOT_REAP_CHILD = 2,
    G_SPAWN_SEARCH_PATH = 4,
    G_SPAWN_STDOUT_TO_DEV_NULL = 8,
    G_SPAWN_STDERR_TO_DEV_NULL = 16,
    G_SPAWN_CHILD_INHERITS_STDIN = 32,
    G_SPAWN_FILE_AND_ARGV_ZERO = 64
} ;
typedef enum __anonenum_GSpawnFlags_85 GSpawnFlags;
enum __anonenum_GAsciiType_86 {
    G_ASCII_ALNUM = 1,
    G_ASCII_ALPHA = 2,
    G_ASCII_CNTRL = 4,
    G_ASCII_DIGIT = 8,
    G_ASCII_GRAPH = 16,
    G_ASCII_LOWER = 32,
    G_ASCII_PRINT = 64,
    G_ASCII_PUNCT = 128,
    G_ASCII_SPACE = 256,
    G_ASCII_UPPER = 512,
    G_ASCII_XDIGIT = 1024
} ;
typedef enum __anonenum_GAsciiType_86 GAsciiType;
struct GTestCase;
typedef struct GTestCase GTestCase;
struct GTestSuite;
typedef struct GTestSuite GTestSuite;
enum __anonenum_GTestTrapFlags_87 {
    G_TEST_TRAP_SILENCE_STDOUT = 128,
    G_TEST_TRAP_SILENCE_STDERR = 256,
    G_TEST_TRAP_INHERIT_STDIN = 512
} ;
typedef enum __anonenum_GTestTrapFlags_87 GTestTrapFlags;
struct __anonstruct_GTestConfig_88 {
   gboolean test_initialized ;
   gboolean test_quick ;
   gboolean test_perf ;
   gboolean test_verbose ;
   gboolean test_quiet ;
};
typedef struct __anonstruct_GTestConfig_88 GTestConfig;
enum __anonenum_GTestLogType_89 {
    G_TEST_LOG_NONE = 0,
    G_TEST_LOG_ERROR = 1,
    G_TEST_LOG_START_BINARY = 2,
    G_TEST_LOG_LIST_CASE = 3,
    G_TEST_LOG_SKIP_CASE = 4,
    G_TEST_LOG_START_CASE = 5,
    G_TEST_LOG_STOP_CASE = 6,
    G_TEST_LOG_MIN_RESULT = 7,
    G_TEST_LOG_MAX_RESULT = 8,
    G_TEST_LOG_MESSAGE = 9
} ;
typedef enum __anonenum_GTestLogType_89 GTestLogType;
struct __anonstruct_GTestLogMsg_90 {
   GTestLogType log_type ;
   guint n_strings ;
   gchar **strings ;
   guint n_nums ;
   long double *nums ;
};
typedef struct __anonstruct_GTestLogMsg_90 GTestLogMsg;
struct __anonstruct_GTestLogBuffer_91 {
   GString *data ;
   GSList *msgs ;
};
typedef struct __anonstruct_GTestLogBuffer_91 GTestLogBuffer;
typedef gboolean (*GTestLogFatalFunc)(gchar const   *log_domain ,
                                      GLogLevelFlags log_level ,
                                      gchar const   *message ,
                                      gpointer user_data );
struct _GThreadPool;
typedef struct _GThreadPool GThreadPool;
struct _GThreadPool {
   void (*func)(gpointer data , gpointer user_data ) ;
   gpointer user_data ;
   gboolean exclusive ;
};
struct _GTimer;
typedef struct _GTimer GTimer;
struct _GTree;
typedef struct _GTree GTree;
typedef gboolean (*GTraverseFunc)(gpointer key , gpointer value , gpointer data );
struct _GVariantType;
typedef struct _GVariantType GVariantType;
struct _GVariant;
typedef struct _GVariant GVariant;
enum __anonenum_GVariantClass_92 {
    G_VARIANT_CLASS_BOOLEAN = 98,
    G_VARIANT_CLASS_BYTE = 121,
    G_VARIANT_CLASS_INT16 = 110,
    G_VARIANT_CLASS_UINT16 = 113,
    G_VARIANT_CLASS_INT32 = 105,
    G_VARIANT_CLASS_UINT32 = 117,
    G_VARIANT_CLASS_INT64 = 120,
    G_VARIANT_CLASS_UINT64 = 116,
    G_VARIANT_CLASS_HANDLE = 104,
    G_VARIANT_CLASS_DOUBLE = 100,
    G_VARIANT_CLASS_STRING = 115,
    G_VARIANT_CLASS_OBJECT_PATH = 111,
    G_VARIANT_CLASS_SIGNATURE = 103,
    G_VARIANT_CLASS_VARIANT = 118,
    G_VARIANT_CLASS_MAYBE = 109,
    G_VARIANT_CLASS_ARRAY = 97,
    G_VARIANT_CLASS_TUPLE = 40,
    G_VARIANT_CLASS_DICT_ENTRY = 123
} ;
typedef enum __anonenum_GVariantClass_92 GVariantClass;
struct _GVariantIter;
typedef struct _GVariantIter GVariantIter;
struct _GVariantIter {
   gsize x[16] ;
};
struct _GVariantBuilder;
typedef struct _GVariantBuilder GVariantBuilder;
struct _GVariantBuilder {
   gsize x[16] ;
};
struct nstr_phdr {
   gint64 rec_offset ;
   gint32 rec_len ;
   guint8 nicno_offset ;
   guint8 nicno_len ;
   guint8 dir_offset ;
   guint8 dir_len ;
   guint8 eth_offset ;
   guint8 pcb_offset ;
   guint8 l_pcb_offset ;
   guint8 rec_type ;
   guint8 vlantag_offset ;
   guint8 coreid_offset ;
};
struct eth_phdr {
   gint fcs_len ;
};
struct x25_phdr {
   guint8 flags ;
};
struct isdn_phdr {
   gboolean uton ;
   guint8 channel ;
};
struct atm_phdr {
   guint32 flags ;
   guint8 aal ;
   guint8 type ;
   guint8 subtype ;
   guint16 vpi ;
   guint16 vci ;
   guint8 aal2_cid ;
   guint16 channel ;
   guint16 cells ;
   guint16 aal5t_u2u ;
   guint16 aal5t_len ;
   guint32 aal5t_chksum ;
};
struct ascend_phdr {
   guint16 type ;
   char user[64] ;
   guint32 sess ;
   char call_num[64] ;
   guint32 chunk ;
   guint32 task ;
};
struct p2p_phdr {
   int sent ;
};
struct ieee_802_11_phdr {
   gint fcs_len ;
   guint8 channel ;
   guint8 data_rate ;
   guint8 signal_level ;
};
struct cosine_phdr {
   guint8 encap ;
   guint8 direction ;
   char if_name[128] ;
   guint16 pro ;
   guint16 off ;
   guint16 pri ;
   guint16 rm ;
   guint16 err ;
};
struct irda_phdr {
   guint16 pkttype ;
};
struct nettl_phdr {
   guint16 subsys ;
   guint32 devid ;
   guint32 kind ;
   gint32 pid ;
   guint16 uid ;
};
struct mtp2_phdr {
   guint8 sent ;
   guint8 annex_a_used ;
   guint16 link_number ;
};
struct __anonstruct_atm_94 {
   guint16 vp ;
   guint16 vc ;
   guint16 cid ;
};
union __anonunion_k12_input_info_t_93 {
   struct __anonstruct_atm_94 atm ;
   guint32 ds0mask ;
};
typedef union __anonunion_k12_input_info_t_93 k12_input_info_t;
struct k12_phdr {
   guint32 input ;
   gchar const   *input_name ;
   gchar const   *stack_file ;
   guint32 input_type ;
   k12_input_info_t input_info ;
   guchar *extra_info ;
   guint32 extra_length ;
   void *stuff ;
};
struct lapd_phdr {
   guint16 pkttype ;
   guint8 we_network ;
};
struct wtap;
struct wtap;
union __anonunion_inner_pseudo_header_95 {
   struct isdn_phdr isdn ;
   struct atm_phdr atm ;
   struct p2p_phdr p2p ;
};
struct catapult_dct2000_phdr {
   union __anonunion_inner_pseudo_header_95 inner_pseudo_header ;
   gint64 seek_off ;
   struct wtap *wth ;
};
struct libpcap_bt_phdr {
   guint32 direction ;
};
struct libpcap_ppp_phdr {
   guint8 direction ;
};
struct erf_phdr {
   guint64 ts ;
   guint8 type ;
   guint8 flags ;
   guint16 rlen ;
   guint16 lctr ;
   guint16 wlen ;
};
struct erf_ehdr {
   guint64 ehdr ;
};
union __anonunion_subhdr_96 {
   guint16 eth_hdr ;
   guint32 mc_hdr ;
};
struct erf_mc_phdr {
   struct erf_phdr phdr ;
   struct erf_ehdr ehdr_list[8] ;
   union __anonunion_subhdr_96 subhdr ;
};
struct sita_phdr {
   guint8 flags ;
   guint8 signals ;
   guint8 errors1 ;
   guint8 errors2 ;
   guint8 proto ;
};
struct bthci_phdr {
   gboolean sent ;
   guint8 channel ;
};
struct l1event_phdr {
   gboolean uton ;
};
struct i2c_phdr {
   guint8 is_event ;
   guint8 bus ;
   guint32 flags ;
};
struct gsm_um_phdr {
   gboolean uplink ;
   guint8 channel ;
   guint8 bsic ;
   guint16 arfcn ;
   guint32 tdma_frame ;
   guint8 error ;
   guint16 timeshift ;
};
union wtap_pseudo_header {
   struct eth_phdr eth ;
   struct x25_phdr x25 ;
   struct isdn_phdr isdn ;
   struct atm_phdr atm ;
   struct ascend_phdr ascend ;
   struct p2p_phdr p2p ;
   struct ieee_802_11_phdr ieee_802_11 ;
   struct cosine_phdr cosine ;
   struct irda_phdr irda ;
   struct nettl_phdr nettl ;
   struct mtp2_phdr mtp2 ;
   struct k12_phdr k12 ;
   struct lapd_phdr lapd ;
   struct catapult_dct2000_phdr dct2000 ;
   struct erf_mc_phdr erf ;
   struct sita_phdr sita ;
   struct bthci_phdr bthci ;
   struct l1event_phdr l1event ;
   struct i2c_phdr i2c ;
   struct gsm_um_phdr gsm_um ;
   struct nstr_phdr nstr ;
};
struct wtap_nstime {
   time_t secs ;
   int nsecs ;
};
struct wtap_pkthdr {
   struct wtap_nstime ts ;
   guint32 caplen ;
   guint32 len ;
   int pkt_encap ;
};
struct Buffer;
struct Buffer;
struct wtap_dumper;
struct wtap_dumper;
typedef struct wtap wtap;
typedef struct wtap_dumper wtap_dumper;
struct file_type_info {
   char const   *name ;
   char const   *short_name ;
   char const   *file_extensions ;
   char const   *file_extension_default ;
   gboolean writing_must_seek ;
   gboolean has_name_resolution ;
   int (*can_write_encap)(int  ) ;
   int (*dump_open)(wtap_dumper * , int * ) ;
};
typedef int (*wtap_open_routine_t)(struct wtap * , int * , char ** );
typedef void (*wtap_new_ipv4_callback_t)(guint const   addr ,
                                         gchar const   *name );
typedef void (*wtap_new_ipv6_callback_t)(void const   *addrp ,
                                         gchar const   *name );
struct addrinfo;
struct addrinfo;
struct __anonstruct_ipv4_addr_97 {
   guint32 addr ;
   guint32 nmask ;
};
typedef struct __anonstruct_ipv4_addr_97 ipv4_addr;
struct __anonstruct_nstime_t_98 {
   time_t secs ;
   int nsecs ;
};
typedef struct __anonstruct_nstime_t_98 nstime_t;
enum __anonenum_to_str_time_res_t_99 {
    TO_STR_TIME_RES_T_SECS = 0,
    TO_STR_TIME_RES_T_DSECS = 1,
    TO_STR_TIME_RES_T_CSECS = 2,
    TO_STR_TIME_RES_T_MSECS = 3,
    TO_STR_TIME_RES_T_USECS = 4,
    TO_STR_TIME_RES_T_NSECS = 5
} ;
typedef enum __anonenum_to_str_time_res_t_99 to_str_time_res_t;
enum __anonenum_absolute_time_display_e_100 {
    ABSOLUTE_TIME_LOCAL = 1000,
    ABSOLUTE_TIME_UTC = 1001,
    ABSOLUTE_TIME_DOY_UTC = 1002
} ;
typedef enum __anonenum_absolute_time_display_e_100 absolute_time_display_e;
struct e_in6_addr {
   guint8 bytes[16] ;
};
struct _e_guid_t {
   guint32 data1 ;
   guint16 data2 ;
   guint16 data3 ;
   guint8 data4[8] ;
};
typedef struct _e_guid_t e_guid_t;
typedef int __jmp_buf[6];
struct __jmp_buf_tag {
   __jmp_buf __jmpbuf ;
   int __mask_was_saved ;
   __sigset_t __saved_mask ;
};
typedef struct __jmp_buf_tag jmp_buf[1];
typedef struct __jmp_buf_tag sigjmp_buf[1];
struct __anonstruct___wait_terminated_101 {
   unsigned int __w_termsig : 7 ;
   unsigned int __w_coredump : 1 ;
   unsigned int __w_retcode : 8 ;
   unsigned int  : 16 ;
};
struct __anonstruct___wait_stopped_102 {
   unsigned int __w_stopval : 8 ;
   unsigned int __w_stopsig : 8 ;
   unsigned int  : 16 ;
};
union __anonunion___WAIT_STATUS_103 {
   union wait *__uptr ;
   int *__iptr ;
};
struct __anonstruct_div_t_104 {
   int quot ;
   int rem ;
};
struct __anonstruct_ldiv_t_105 {
   long quot ;
   long rem ;
};
struct __anonstruct_lldiv_t_106 {
   long long quot ;
   long long rem ;
};
typedef __u_char u_char;
typedef __u_short u_short;
typedef __u_int u_int;
typedef __u_long u_long;
typedef __gid_t gid_t;
typedef __mode_t mode_t;
typedef __id_t id_t;
typedef __daddr_t daddr_t;
typedef __caddr_t caddr_t;
typedef __key_t key_t;
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
typedef __blksize_t blksize_t;
typedef int (*__compar_fn_t)(void const   * , void const   * );
enum __anonenum_107 {
    except_no_call = 0,
    except_call = 1
} ;
struct __anonstruct_except_id_t_108 {
   unsigned long except_group ;
   unsigned long except_code ;
};
typedef struct __anonstruct_except_id_t_108 except_id_t;
struct __anonstruct_except_t_109 {
   except_id_t volatile   except_id ;
   char const   * volatile  except_message ;
   void * volatile  except_dyndata ;
};
typedef struct __anonstruct_except_t_109 except_t;
struct except_cleanup {
   void (*except_func)(void * ) ;
   void *except_context ;
};
struct except_catch {
   except_id_t const   *except_id ;
   size_t except_size ;
   except_t except_obj ;
   jmp_buf except_jmp ;
};
enum except_stacktype {
    XCEPT_CLEANUP = 0,
    XCEPT_CATCHER = 1
} ;
union __anonunion_except_info_110 {
   struct except_catch *except_catcher ;
   struct except_cleanup *except_cleanup ;
};
struct except_stacknode {
   struct except_stacknode *except_down ;
   enum except_stacktype except_type ;
   union __anonunion_except_info_110 except_info ;
};
enum __anonenum_tvbuff_type_111 {
    TVBUFF_REAL_DATA = 0,
    TVBUFF_SUBSET = 1,
    TVBUFF_COMPOSITE = 2
} ;
typedef enum __anonenum_tvbuff_type_111 tvbuff_type;
struct tvbuff;
struct __anonstruct_tvb_backing_t_112 {
   struct tvbuff *tvb ;
   guint offset ;
   guint length ;
};
typedef struct __anonstruct_tvb_backing_t_112 tvb_backing_t;
struct __anonstruct_tvb_comp_t_113 {
   GSList *tvbs ;
   guint *start_offsets ;
   guint *end_offsets ;
};
typedef struct __anonstruct_tvb_comp_t_113 tvb_comp_t;
typedef void (*tvbuff_free_cb_t)(void * );
union __anonunion_tvbuffs_114 {
   tvb_backing_t subset ;
   tvb_comp_t composite ;
};
struct tvbuff {
   tvbuff_type type ;
   gboolean initialized ;
   guint usage_count ;
   struct tvbuff *ds_tvb ;
   GSList *used_in ;
   union __anonunion_tvbuffs_114 tvbuffs ;
   guint8 const   *real_data ;
   guint length ;
   guint reported_length ;
   gint raw_offset ;
   void (*free_cb)(void * ) ;
};
typedef struct tvbuff tvbuff_t;
struct dgt_set_t {
   unsigned char const   out[15] ;
};
typedef struct dgt_set_t dgt_set_t;
struct _ep_stack_frame_t;
typedef struct _ep_stack_frame_t **ep_stack_t;
struct _ep_stack_frame_t {
   void *payload ;
   struct _ep_stack_frame_t *below ;
   struct _ep_stack_frame_t *above ;
};
struct _emem_chunk_t;
struct _emem_chunk_t;
struct ws_memory_slab {
   gint const   item_size ;
   gint const   count ;
   struct _emem_chunk_t *chunk_list ;
   void *freed ;
};
struct __anonstruct_u_115 {
   guint32 rb_color : 1 ;
   guint32 is_subtree : 1 ;
};
struct _emem_tree_node_t {
   struct _emem_tree_node_t *parent ;
   struct _emem_tree_node_t *left ;
   struct _emem_tree_node_t *right ;
   struct __anonstruct_u_115 u ;
   guint32 key32 ;
   void *data ;
};
typedef struct _emem_tree_node_t emem_tree_node_t;
struct _emem_tree_t {
   struct _emem_tree_t *next ;
   int type ;
   char const   *name ;
   emem_tree_node_t *tree ;
   void *(*malloc)(size_t  ) ;
};
typedef struct _emem_tree_t emem_tree_t;
struct _emem_tree_key_t {
   guint32 length ;
   guint32 *key ;
};
typedef struct _emem_tree_key_t emem_tree_key_t;
typedef gboolean (*tree_foreach_func)(void *value , void *userdata );
struct _emem_strbuf_t {
   gchar *str ;
   gsize len ;
   gsize alloc_len ;
   gsize max_alloc_len ;
};
typedef struct _emem_strbuf_t emem_strbuf_t;
enum ftenum {
    FT_NONE = 0,
    FT_PROTOCOL = 1,
    FT_BOOLEAN = 2,
    FT_UINT8 = 3,
    FT_UINT16 = 4,
    FT_UINT24 = 5,
    FT_UINT32 = 6,
    FT_UINT64 = 7,
    FT_INT8 = 8,
    FT_INT16 = 9,
    FT_INT24 = 10,
    FT_INT32 = 11,
    FT_INT64 = 12,
    FT_FLOAT = 13,
    FT_DOUBLE = 14,
    FT_ABSOLUTE_TIME = 15,
    FT_RELATIVE_TIME = 16,
    FT_STRING = 17,
    FT_STRINGZ = 18,
    FT_EBCDIC = 19,
    FT_UINT_STRING = 20,
    FT_ETHER = 21,
    FT_BYTES = 22,
    FT_UINT_BYTES = 23,
    FT_IPv4 = 24,
    FT_IPv6 = 25,
    FT_IPXNET = 26,
    FT_FRAMENUM = 27,
    FT_PCRE = 28,
    FT_GUID = 29,
    FT_OID = 30,
    FT_EUI64 = 31,
    FT_NUM_TYPES = 32
} ;
typedef enum ftenum ftenum_t;
struct _ftype_t;
typedef struct _ftype_t ftype_t;
enum ftrepr {
    FTREPR_DISPLAY = 0,
    FTREPR_DFILTER = 1
} ;
typedef enum ftrepr ftrepr_t;
enum __anonenum_drange_node_end_t_116 {
    DRANGE_NODE_END_T_UNINITIALIZED = 0,
    DRANGE_NODE_END_T_LENGTH = 1,
    DRANGE_NODE_END_T_OFFSET = 2,
    DRANGE_NODE_END_T_TO_THE_END = 3
} ;
typedef enum __anonenum_drange_node_end_t_116 drange_node_end_t;
struct _drange_node {
   gint start_offset ;
   gint length ;
   gint end_offset ;
   drange_node_end_t ending ;
};
typedef struct _drange_node drange_node;
struct _drange {
   GSList *range_list ;
   gboolean has_total_length ;
   gint total_length ;
   gint min_start_offset ;
   gint max_start_offset ;
};
typedef struct _drange drange;
union __anonunion_value_117 {
   guint32 uinteger ;
   gint32 sinteger ;
   guint64 integer64 ;
   gdouble floating ;
   gchar *string ;
   guchar *ustring ;
   GByteArray *bytes ;
   ipv4_addr ipv4 ;
   e_guid_t guid ;
   nstime_t time ;
   tvbuff_t *tvb ;
   GRegex *re ;
};
struct _fvalue_t {
   ftype_t *ftype ;
   union __anonunion_value_117 value ;
   gboolean fvalue_gboolean1 ;
};
typedef struct _fvalue_t fvalue_t;
typedef void (*FvalueNewFunc)(fvalue_t * );
typedef void (*FvalueFreeFunc)(fvalue_t * );
typedef void (*LogFunc)(char const   *  , ...);
typedef gboolean (*FvalueFromUnparsed)(fvalue_t * , char * , gboolean  ,
                                       void (*)(char const   *  , ...) );
typedef gboolean (*FvalueFromString)(fvalue_t * , char * ,
                                     void (*)(char const   *  , ...) );
typedef void (*FvalueToStringRepr)(fvalue_t * , ftrepr_t  , char * );
typedef int (*FvalueStringReprLen)(fvalue_t * , ftrepr_t  );
typedef void (*FvalueSetFunc)(fvalue_t * , gpointer  , gboolean  );
typedef void (*FvalueSetUnsignedIntegerFunc)(fvalue_t * , guint32  );
typedef void (*FvalueSetSignedIntegerFunc)(fvalue_t * , gint32  );
typedef void (*FvalueSetInteger64Func)(fvalue_t * , guint64  );
typedef void (*FvalueSetFloatingFunc)(fvalue_t * , gdouble  );
typedef gpointer (*FvalueGetFunc)(fvalue_t * );
typedef guint32 (*FvalueGetUnsignedIntegerFunc)(fvalue_t * );
typedef gint32 (*FvalueGetSignedIntegerFunc)(fvalue_t * );
typedef guint64 (*FvalueGetInteger64Func)(fvalue_t * );
typedef double (*FvalueGetFloatingFunc)(fvalue_t * );
typedef gboolean (*FvalueCmp)(fvalue_t * , fvalue_t * );
typedef guint (*FvalueLen)(fvalue_t * );
typedef void (*FvalueSlice)(fvalue_t * , GByteArray * , guint offset ,
                            guint length );
struct _ftype_t {
   ftenum_t ftype ;
   char const   *name ;
   char const   *pretty_name ;
   int wire_size ;
   void (*new_value)(fvalue_t * ) ;
   void (*free_value)(fvalue_t * ) ;
   gboolean (*val_from_unparsed)(fvalue_t * , char * , gboolean  ,
                                 void (*)(char const   *  , ...) ) ;
   gboolean (*val_from_string)(fvalue_t * , char * ,
                               void (*)(char const   *  , ...) ) ;
   void (*val_to_string_repr)(fvalue_t * , ftrepr_t  , char * ) ;
   int (*len_string_repr)(fvalue_t * , ftrepr_t  ) ;
   void (*set_value)(fvalue_t * , gpointer  , gboolean  ) ;
   void (*set_value_uinteger)(fvalue_t * , guint32  ) ;
   void (*set_value_sinteger)(fvalue_t * , gint32  ) ;
   void (*set_value_integer64)(fvalue_t * , guint64  ) ;
   void (*set_value_floating)(fvalue_t * , gdouble  ) ;
   gpointer (*get_value)(fvalue_t * ) ;
   guint32 (*get_value_uinteger)(fvalue_t * ) ;
   gint32 (*get_value_sinteger)(fvalue_t * ) ;
   guint64 (*get_value_integer64)(fvalue_t * ) ;
   double (*get_value_floating)(fvalue_t * ) ;
   gboolean (*cmp_eq)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_ne)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_gt)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_ge)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_lt)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_le)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_bitwise_and)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_contains)(fvalue_t * , fvalue_t * ) ;
   gboolean (*cmp_matches)(fvalue_t * , fvalue_t * ) ;
   guint (*len)(fvalue_t * ) ;
   void (*slice)(fvalue_t * , GByteArray * , guint offset , guint length ) ;
};
enum __anonenum_register_action_e_118 {
    RA_NONE = 0,
    RA_DISSECTORS = 1,
    RA_LISTENERS = 2,
    RA_REGISTER = 3,
    RA_PLUGIN_REGISTER = 4,
    RA_HANDOFF = 5,
    RA_PLUGIN_HANDOFF = 6,
    RA_PREFERENCES = 7,
    RA_CONFIGURATION = 8
} ;
typedef enum __anonenum_register_action_e_118 register_action_e;
typedef void (*register_cb)(register_action_e action , char const   *message ,
                            gpointer client_data );
struct _value_string;
struct _value_string;
typedef void (*custom_fmt_func_t)(gchar * , guint32  );
struct _protocol;
struct _protocol;
typedef struct _protocol protocol_t;
enum __anonenum_base_display_e_119 {
    BASE_NONE = 0,
    BASE_DEC = 1,
    BASE_HEX = 2,
    BASE_OCT = 3,
    BASE_DEC_HEX = 4,
    BASE_HEX_DEC = 5,
    BASE_CUSTOM = 6
} ;
typedef enum __anonenum_base_display_e_119 base_display_e;
enum __anonenum_hf_ref_type_120 {
    HF_REF_TYPE_NONE = 0,
    HF_REF_TYPE_INDIRECT = 1,
    HF_REF_TYPE_DIRECT = 2
} ;
typedef enum __anonenum_hf_ref_type_120 hf_ref_type;
struct _header_field_info;
typedef struct _header_field_info header_field_info;
struct _header_field_info {
   char const   *name ;
   char const   *abbrev ;
   enum ftenum type ;
   int display ;
   void const   *strings ;
   guint32 bitmask ;
   char const   *blurb ;
   int id ;
   int parent ;
   hf_ref_type ref_type ;
   int bitshift ;
   header_field_info *same_name_next ;
   header_field_info *same_name_prev ;
};
struct hf_register_info {
   int *p_id ;
   header_field_info hfinfo ;
};
typedef struct hf_register_info hf_register_info;
struct _item_label_t {
   char representation[240] ;
};
typedef struct _item_label_t item_label_t;
struct field_info {
   header_field_info *hfinfo ;
   gint start ;
   gint length ;
   gint appendix_start ;
   gint appendix_length ;
   gint tree_type ;
   item_label_t *rep ;
   guint32 flags ;
   tvbuff_t *ds_tvb ;
   fvalue_t value ;
};
typedef struct field_info field_info;
struct __anonstruct_tree_data_t_121 {
   GHashTable *interesting_hfids ;
   gboolean visible ;
   gboolean fake_protocols ;
   gint count ;
};
typedef struct __anonstruct_tree_data_t_121 tree_data_t;
struct _proto_node {
   struct _proto_node *first_child ;
   struct _proto_node *last_child ;
   struct _proto_node *next ;
   struct _proto_node *parent ;
   field_info *finfo ;
   tree_data_t *tree_data ;
};
typedef struct _proto_node proto_node;
typedef proto_node proto_tree;
typedef proto_node proto_item;
typedef void (*proto_tree_foreach_func)(proto_node * , gpointer  );
typedef gboolean (*proto_tree_traverse_func)(proto_node * , gpointer  );
typedef void (*prefix_initializer_t)(char const   *match );
struct __anonstruct_col_expr_t_122 {
   gchar const   **col_expr ;
   gchar **col_expr_val ;
};
typedef struct __anonstruct_col_expr_t_122 col_expr_t;
struct _dfilter_t;
struct _column_info {
   gint num_cols ;
   gint *col_fmt ;
   gboolean **fmt_matx ;
   gint *col_first ;
   gint *col_last ;
   gchar **col_title ;
   gchar **col_custom_field ;
   gint *col_custom_occurrence ;
   gint *col_custom_field_id ;
   struct _dfilter_t **col_custom_dfilter ;
   gchar const   **col_data ;
   gchar **col_buf ;
   int *col_fence ;
   col_expr_t col_expr ;
   gboolean writable ;
   gboolean columns_changed ;
};
typedef struct _column_info column_info;
enum __anonenum_123 {
    COL_8021Q_VLAN_ID = 0,
    COL_ABS_DATE_TIME = 1,
    COL_ABS_TIME = 2,
    COL_CIRCUIT_ID = 3,
    COL_DSTIDX = 4,
    COL_SRCIDX = 5,
    COL_VSAN = 6,
    COL_CUMULATIVE_BYTES = 7,
    COL_CUSTOM = 8,
    COL_DCE_CALL = 9,
    COL_DCE_CTX = 10,
    COL_DELTA_TIME = 11,
    COL_DELTA_CONV_TIME = 12,
    COL_DELTA_TIME_DIS = 13,
    COL_RES_DST = 14,
    COL_UNRES_DST = 15,
    COL_RES_DST_PORT = 16,
    COL_UNRES_DST_PORT = 17,
    COL_DEF_DST = 18,
    COL_DEF_DST_PORT = 19,
    COL_EXPERT = 20,
    COL_IF_DIR = 21,
    COL_OXID = 22,
    COL_RXID = 23,
    COL_FR_DLCI = 24,
    COL_FREQ_CHAN = 25,
    COL_BSSGP_TLLI = 26,
    COL_HPUX_DEVID = 27,
    COL_HPUX_SUBSYS = 28,
    COL_DEF_DL_DST = 29,
    COL_DEF_DL_SRC = 30,
    COL_RES_DL_DST = 31,
    COL_UNRES_DL_DST = 32,
    COL_RES_DL_SRC = 33,
    COL_UNRES_DL_SRC = 34,
    COL_RSSI = 35,
    COL_TX_RATE = 36,
    COL_DSCP_VALUE = 37,
    COL_INFO = 38,
    COL_COS_VALUE = 39,
    COL_RES_NET_DST = 40,
    COL_UNRES_NET_DST = 41,
    COL_RES_NET_SRC = 42,
    COL_UNRES_NET_SRC = 43,
    COL_DEF_NET_DST = 44,
    COL_DEF_NET_SRC = 45,
    COL_NUMBER = 46,
    COL_PACKET_LENGTH = 47,
    COL_PROTOCOL = 48,
    COL_REL_TIME = 49,
    COL_REL_CONV_TIME = 50,
    COL_DEF_SRC = 51,
    COL_DEF_SRC_PORT = 52,
    COL_RES_SRC = 53,
    COL_UNRES_SRC = 54,
    COL_RES_SRC_PORT = 55,
    COL_UNRES_SRC_PORT = 56,
    COL_TEI = 57,
    COL_CLS_TIME = 58,
    NUM_COL_FMTS = 59
} ;
struct __anonstruct_flags_124 {
   unsigned int passed_dfilter : 1 ;
   unsigned int encoding : 2 ;
   unsigned int visited : 1 ;
   unsigned int marked : 1 ;
   unsigned int ref_time : 1 ;
   unsigned int ignored : 1 ;
};
struct _frame_data {
   GSList *pfd ;
   guint32 num ;
   guint32 pkt_len ;
   guint32 cap_len ;
   guint32 cum_bytes ;
   gint64 file_off ;
   guint16 subnum ;
   gint16 lnk_t ;
   struct __anonstruct_flags_124 flags ;
   void const   *color_filter ;
   nstime_t abs_ts ;
   nstime_t rel_ts ;
   nstime_t del_dis_ts ;
   nstime_t del_cap_ts ;
};
typedef struct _frame_data frame_data;
struct __anonstruct_data_source_125 {
   tvbuff_t *tvb ;
   gboolean name_initialized ;
   char const   *name ;
};
typedef struct __anonstruct_data_source_125 data_source;
struct _epan_dissect_t;
typedef struct _epan_dissect_t epan_dissect_t;
typedef struct _dfilter_t dfilter_t;
struct epan_session;
typedef struct epan_session epan_t;
enum __anonenum_address_type_126 {
    AT_NONE = 0,
    AT_ETHER = 1,
    AT_IPv4 = 2,
    AT_IPv6 = 3,
    AT_IPX = 4,
    AT_SNA = 5,
    AT_ATALK = 6,
    AT_VINES = 7,
    AT_OSI = 8,
    AT_ARCNET = 9,
    AT_FC = 10,
    AT_SS7PC = 11,
    AT_STRINGZ = 12,
    AT_EUI64 = 13,
    AT_URI = 14,
    AT_TIPC = 15,
    AT_IB = 16,
    AT_USB = 17
} ;
typedef enum __anonenum_address_type_126 address_type;
struct _address {
   address_type type ;
   int len ;
   void const   *data ;
};
typedef struct _address address;
enum __anonenum_port_type_127 {
    PT_NONE = 0,
    PT_SCTP = 1,
    PT_TCP = 2,
    PT_UDP = 3,
    PT_DCCP = 4,
    PT_IPX = 5,
    PT_NCP = 6,
    PT_EXCHG = 7,
    PT_DDP = 8,
    PT_SBCCS = 9,
    PT_IDP = 10,
    PT_TIPC = 11,
    PT_USB = 12,
    PT_I2C = 13,
    PT_IBQP = 14
} ;
typedef enum __anonenum_port_type_127 port_type;
enum __anonenum_circuit_type_128 {
    CT_NONE = 0,
    CT_DLCI = 1,
    CT_ISDN = 2,
    CT_X25 = 3,
    CT_ISUP = 4,
    CT_IAX2 = 5,
    CT_H223 = 6,
    CT_BICC = 7
} ;
typedef enum __anonenum_circuit_type_128 circuit_type;
struct _sccp_msg_info_t;
struct _packet_info {
   char const   *current_proto ;
   column_info *cinfo ;
   frame_data *fd ;
   union wtap_pseudo_header *pseudo_header ;
   GSList *data_src ;
   address dl_src ;
   address dl_dst ;
   address net_src ;
   address net_dst ;
   address src ;
   address dst ;
   guint32 ethertype ;
   guint32 ipproto ;
   guint32 ipxptype ;
   guint32 mpls_label ;
   circuit_type ctype ;
   guint32 circuit_id ;
   char const   *noreassembly_reason ;
   gboolean fragmented ;
   gboolean in_error_pkt ;
   port_type ptype ;
   guint32 srcport ;
   guint32 destport ;
   guint32 match_uint ;
   char const   *match_string ;
   guint16 can_desegment ;
   guint16 saved_can_desegment ;
   int desegment_offset ;
   guint32 desegment_len ;
   guint16 want_pdu_tracking ;
   guint32 bytes_until_next_pdu ;
   int iplen ;
   int iphdrlen ;
   guint8 ip_ttl ;
   int p2p_dir ;
   guint16 oxid ;
   guint16 rxid ;
   guint8 r_ctl ;
   guint8 sof_eof ;
   guint16 src_idx ;
   guint16 dst_idx ;
   guint16 vsan ;
   guint16 dcectxid ;
   int dcetransporttype ;
   guint16 dcetransportsalt ;
   guint16 decrypt_gssapi_tvb ;
   tvbuff_t *gssapi_wrap_tvb ;
   tvbuff_t *gssapi_encrypted_tvb ;
   tvbuff_t *gssapi_decrypted_tvb ;
   gboolean gssapi_data_encrypted ;
   guint32 ppid ;
   guint32 ppids[2] ;
   void *private_data ;
   GString *layer_names ;
   guint16 link_number ;
   guint8 annex_a_used ;
   guint16 profinet_type ;
   void *profinet_conv ;
   void *usb_conv_info ;
   void *tcp_tree ;
   char const   *dcerpc_procedure_name ;
   struct _sccp_msg_info_t *sccp_info ;
   guint16 clnp_srcref ;
   guint16 clnp_dstref ;
   guint16 zbee_cluster_id ;
   guint8 zbee_stack_vers ;
   int link_dir ;
};
typedef struct _packet_info packet_info;
struct e_in6_addr;
struct _value_string {
   guint32 value ;
   gchar const   *strptr ;
};
typedef struct _value_string value_string;
struct _string_string {
   gchar const   *value ;
   gchar const   *strptr ;
};
typedef struct _string_string string_string;
struct _range_string {
   guint32 value_min ;
   guint32 value_max ;
   gchar const   *strptr ;
};
typedef struct _range_string range_string;
struct _value_string_ext;
struct _value_string_ext;
typedef value_string const   *(*_value_string_match2_t)(guint32 const    ,
                                                        struct _value_string_ext  const  * );
struct _value_string_ext {
   value_string const   *(*_vs_match2)(guint32 const    ,
                                       struct _value_string_ext  const  * ) ;
   guint32 _vs_first_value ;
   guint _vs_num_entries ;
   value_string const   *_vs_p ;
   gchar const   *_vs_name ;
};
typedef struct _value_string_ext value_string_ext;
struct true_false_string {
   char const   *true_string ;
   char const   *false_string ;
};
typedef struct true_false_string true_false_string;
struct _packet_counts {
   gint sctp ;
   gint tcp ;
   gint udp ;
   gint icmp ;
   gint ospf ;
   gint gre ;
   gint netbios ;
   gint ipx ;
   gint vines ;
   gint other ;
   gint total ;
   gint arp ;
   gint i2c_event ;
   gint i2c_data ;
};
typedef struct _packet_counts packet_counts;
enum __anonenum_packet_char_enc_129 {
    PACKET_CHAR_ENC_CHAR_ASCII = 0,
    PACKET_CHAR_ENC_CHAR_EBCDIC = 1
} ;
typedef enum __anonenum_packet_char_enc_129 packet_char_enc;
struct dissector_handle;
struct dissector_handle;
typedef struct dissector_handle *dissector_handle_t;
struct dissector_table;
struct dissector_table;
typedef struct dissector_table *dissector_table_t;
typedef void (*dissector_t)(tvbuff_t * , packet_info * , proto_tree * );
typedef int (*new_dissector_t)(tvbuff_t * , packet_info * , proto_tree * );
typedef gboolean (*heur_dissector_t)(tvbuff_t *tvb , packet_info *pinfo ,
                                     proto_tree *tree );
typedef void (*DATFunc)(gchar const   *table_name , ftenum_t selector_type ,
                        gpointer key , gpointer value , gpointer user_data );
typedef void (*DATFunc_handle)(gchar const   *table_name , gpointer value ,
                               gpointer user_data );
typedef void (*DATFunc_table)(gchar const   *table_name ,
                              gchar const   *ui_name , gpointer user_data );
struct dtbl_entry;
typedef struct dtbl_entry dtbl_entry_t;
typedef GSList *heur_dissector_list_t;
struct _fragment_data {
   struct _fragment_data *next ;
   guint32 frame ;
   guint32 offset ;
   guint32 len ;
   guint32 datalen ;
   guint32 reassembled_in ;
   guint32 flags ;
   unsigned char *data ;
};
typedef struct _fragment_data fragment_data;
typedef void *(*fragment_key_copier)(void const   *key );
struct _fragment_items {
   gint *ett_fragment ;
   gint *ett_fragments ;
   int *hf_fragments ;
   int *hf_fragment ;
   int *hf_fragment_overlap ;
   int *hf_fragment_overlap_conflict ;
   int *hf_fragment_multiple_tails ;
   int *hf_fragment_too_long_fragment ;
   int *hf_fragment_error ;
   int *hf_fragment_count ;
   int *hf_reassembled_in ;
   int *hf_reassembled_length ;
   char const   *tag ;
};
typedef struct _fragment_items fragment_items;
struct conversation_key {
   struct conversation_key *next ;
   address addr1 ;
   address addr2 ;
   port_type ptype ;
   guint32 port1 ;
   guint32 port2 ;
};
typedef struct conversation_key conversation_key;
struct conversation {
   struct conversation *next ;
   guint32 index ;
   guint32 setup_frame ;
   GSList *data_list ;
   dissector_handle_t dissector_handle ;
   guint options ;
   conversation_key *key_ptr ;
};
typedef struct conversation conversation_t;
struct _e_uuid_t {
   guint32 Data1 ;
   guint16 Data2 ;
   guint16 Data3 ;
   guint8 Data4[8] ;
};
typedef struct _e_uuid_t e_uuid_t;
struct _e_ctx_hnd {
   guint32 attributes ;
   e_uuid_t uuid ;
};
typedef struct _e_ctx_hnd e_ctx_hnd;
struct _e_dce_cn_common_hdr_t {
   guint8 rpc_ver ;
   guint8 rpc_ver_minor ;
   guint8 ptype ;
   guint8 flags ;
   guint8 drep[4] ;
   guint16 frag_len ;
   guint16 auth_len ;
   guint32 call_id ;
};
typedef struct _e_dce_cn_common_hdr_t e_dce_cn_common_hdr_t;
struct _e_dce_dg_common_hdr_t {
   guint8 rpc_ver ;
   guint8 ptype ;
   guint8 flags1 ;
   guint8 flags2 ;
   guint8 drep[3] ;
   guint8 serial_hi ;
   e_uuid_t obj_id ;
   e_uuid_t if_id ;
   e_uuid_t act_id ;
   guint32 server_boot ;
   guint32 if_ver ;
   guint32 seqnum ;
   guint16 opnum ;
   guint16 ihint ;
   guint16 ahint ;
   guint16 frag_len ;
   guint16 frag_num ;
   guint8 auth_proto ;
   guint8 serial_lo ;
};
typedef struct _e_dce_dg_common_hdr_t e_dce_dg_common_hdr_t;
struct _dcerpc_auth_info {
   guint8 auth_pad_len ;
   guint8 auth_level ;
   guint8 auth_type ;
   guint32 auth_size ;
   tvbuff_t *auth_data ;
};
typedef struct _dcerpc_auth_info dcerpc_auth_info;
typedef guint32 guint1632;
typedef guint64 guint3264;
typedef int dcerpc_dissect_fnct_t(tvbuff_t *tvb , int offset ,
                                  packet_info *pinfo , proto_tree *tree ,
                                  guint8 *drep );
typedef void dcerpc_callback_fnct_t(packet_info *pinfo , proto_tree *tree ,
                                    proto_item *item , tvbuff_t *tvb ,
                                    int start_offset , int end_offset ,
                                    void *callback_args );
struct _dcerpc_sub_dissector {
   guint16 num ;
   gchar const   *name ;
   dcerpc_dissect_fnct_t *dissect_rqst ;
   dcerpc_dissect_fnct_t *dissect_resp ;
};
typedef struct _dcerpc_sub_dissector dcerpc_sub_dissector;
struct _dcerpc_call_value {
   e_uuid_t uuid ;
   guint16 ver ;
   e_uuid_t object_uuid ;
   guint16 opnum ;
   guint32 req_frame ;
   nstime_t req_time ;
   guint32 rep_frame ;
   guint32 max_ptr ;
   void *se_data ;
   void *private_data ;
   e_ctx_hnd *pol ;
   guint32 flags ;
};
typedef struct _dcerpc_call_value dcerpc_call_value;
struct _dcerpc_info {
   conversation_t *conv ;
   guint32 call_id ;
   guint16 smb_fid ;
   guint8 ptype ;
   gboolean conformant_run ;
   gboolean no_align ;
   gint32 conformant_eaten ;
   guint32 array_max_count ;
   guint32 array_max_count_offset ;
   guint32 array_offset ;
   guint32 array_offset_offset ;
   guint32 array_actual_count ;
   guint32 array_actual_count_offset ;
   int hf_index ;
   dcerpc_call_value *call_data ;
   void *private_data ;
};
typedef struct _dcerpc_info dcerpc_info;
struct _dcerpc_uuid_key {
   e_uuid_t uuid ;
   guint16 ver ;
};
typedef struct _dcerpc_uuid_key dcerpc_uuid_key;
struct _dcerpc_uuid_value {
   protocol_t *proto ;
   int proto_id ;
   int ett ;
   gchar const   *name ;
   dcerpc_sub_dissector *procs ;
   int opnum_hf ;
};
typedef struct _dcerpc_uuid_value dcerpc_uuid_value;
typedef tvbuff_t *dcerpc_decode_data_fnct_t(tvbuff_t *data_tvb ,
                                            tvbuff_t *auth_tvb , int offset ,
                                            packet_info *pinfo ,
                                            dcerpc_auth_info *auth_info );
struct _dcerpc_auth_subdissector_fns {
   dcerpc_dissect_fnct_t *bind_fn ;
   dcerpc_dissect_fnct_t *bind_ack_fn ;
   dcerpc_dissect_fnct_t *auth3_fn ;
   dcerpc_dissect_fnct_t *req_verf_fn ;
   dcerpc_dissect_fnct_t *resp_verf_fn ;
   dcerpc_decode_data_fnct_t *req_data_fn ;
   dcerpc_decode_data_fnct_t *resp_data_fn ;
};
typedef struct _dcerpc_auth_subdissector_fns dcerpc_auth_subdissector_fns;
struct decode_dcerpc_bind_values_s {
   address addr_a ;
   address addr_b ;
   port_type ptype ;
   guint32 port_a ;
   guint32 port_b ;
   guint16 ctx_id ;
   guint16 smb_fid ;
   GString *ifname ;
   e_uuid_t uuid ;
   guint16 ver ;
};
typedef struct decode_dcerpc_bind_values_s decode_dcerpc_bind_values_t;
struct _dcerpc_bind_value;
struct pol_value {
   struct pol_value *next ;
   guint32 open_frame ;
   guint32 close_frame ;
   guint32 first_frame ;
   guint32 last_frame ;
   char *name ;
   guint32 type ;
};
typedef struct pol_value pol_value;
struct _fragment_key {
   address src ;
   address dst ;
   guint32 id ;
};
typedef struct _fragment_key fragment_key;
struct _dcerpc_fragment_key {
   address src ;
   address dst ;
   guint32 id ;
   e_uuid_t act_id ;
};
typedef struct _dcerpc_fragment_key dcerpc_fragment_key;
struct _reassembled_key {
   guint32 id ;
   guint32 frame ;
};
typedef struct _reassembled_key reassembled_key;
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
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) gettimeofday)(struct timeval * __restrict  __tv ,
                                                                                         __timezone_ptr_t __tz ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) settimeofday)(struct timeval  const  *__tv ,
                                                                                         struct timezone  const  *__tz ) ;
extern  __attribute__((__nothrow__)) int adjtime(struct timeval  const  *__delta ,
                                                 struct timeval *__olddelta ) ;
extern  __attribute__((__nothrow__)) int getitimer(__itimer_which_t __which ,
                                                   struct itimerval *__value ) ;
extern  __attribute__((__nothrow__)) int setitimer(__itimer_which_t __which ,
                                                   struct itimerval  const  * __restrict  __new ,
                                                   struct itimerval * __restrict  __old ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) utimes)(char const   *__file ,
                                                                                   struct timeval  const  *__tvp ) ;
extern  __attribute__((__nothrow__)) int ( __attribute__((__nonnull__(1))) lutimes)(char const   *__file ,
                                                                                    struct timeval  const  *__tvp ) ;
extern  __attribute__((__nothrow__)) int futimes(int __fd ,
                                                 struct timeval  const  *__tvp ) ;
extern GArray *g_array_new(gboolean zero_terminated , gboolean clear_ ,
                           guint element_size ) ;
extern GArray *g_array_sized_new(gboolean zero_terminated , gboolean clear_ ,
                                 guint element_size , guint reserved_size ) ;
extern gchar *g_array_free(GArray *array , gboolean free_segment ) ;
extern GArray *g_array_ref(GArray *array ) ;
extern void g_array_unref(GArray *array ) ;
extern guint g_array_get_element_size(GArray *array ) ;
extern GArray *g_array_append_vals(GArray *array , gconstpointer data ,
                                   guint len ) ;
extern GArray *g_array_prepend_vals(GArray *array , gconstpointer data ,
                                    guint len ) ;
extern GArray *g_array_insert_vals(GArray *array , guint index_ ,
                                   gconstpointer data , guint len ) ;
extern GArray *g_array_set_size(GArray *array , guint length ) ;
extern GArray *g_array_remove_index(GArray *array , guint index_ ) ;
extern GArray *g_array_remove_index_fast(GArray *array , guint index_ ) ;
extern GArray *g_array_remove_range(GArray *array , guint index_ , guint length ) ;
extern void g_array_sort(GArray *array , gint (*compare_func)(gconstpointer a ,
                                                              gconstpointer b ) ) ;
extern void g_array_sort_with_data(GArray *array ,
                                   gint (*compare_func)(gconstpointer a ,
                                                        gconstpointer b ,
                                                        gpointer user_data ) ,
                                   gpointer user_data ) ;
extern GPtrArray *g_ptr_array_new(void) ;
extern GPtrArray *g_ptr_array_new_with_free_func(void (*element_free_func)(gpointer data ) ) ;
extern GPtrArray *g_ptr_array_sized_new(guint reserved_size ) ;
extern gpointer *g_ptr_array_free(GPtrArray *array , gboolean free_seg ) ;
extern GPtrArray *g_ptr_array_ref(GPtrArray *array ) ;
extern void g_ptr_array_unref(GPtrArray *array ) ;
extern void g_ptr_array_set_free_func(GPtrArray *array ,
                                      void (*element_free_func)(gpointer data ) ) ;
extern void g_ptr_array_set_size(GPtrArray *array , gint length ) ;
extern gpointer g_ptr_array_remove_index(GPtrArray *array , guint index_ ) ;
extern gpointer g_ptr_array_remove_index_fast(GPtrArray *array , guint index_ ) ;
extern gboolean g_ptr_array_remove(GPtrArray *array , gpointer data ) ;
extern gboolean g_ptr_array_remove_fast(GPtrArray *array , gpointer data ) ;
extern void g_ptr_array_remove_range(GPtrArray *array , guint index_ ,
                                     guint length ) ;
extern void g_ptr_array_add(GPtrArray *array , gpointer data ) ;
extern void g_ptr_array_sort(GPtrArray *array ,
                             gint (*compare_func)(gconstpointer a ,
                                                  gconstpointer b ) ) ;
extern void g_ptr_array_sort_with_data(GPtrArray *array ,
                                       gint (*compare_func)(gconstpointer a ,
                                                            gconstpointer b ,
                                                            gpointer user_data ) ,
                                       gpointer user_data ) ;
extern void g_ptr_array_foreach(GPtrArray *array ,
                                void (*func)(gpointer data , gpointer user_data ) ,
                                gpointer user_data ) ;
extern GByteArray *g_byte_array_new(void) ;
extern GByteArray *g_byte_array_sized_new(guint reserved_size ) ;
extern guint8 *g_byte_array_free(GByteArray *array , gboolean free_segment ) ;
extern GByteArray *g_byte_array_ref(GByteArray *array ) ;
extern void g_byte_array_unref(GByteArray *array ) ;
extern GByteArray *g_byte_array_append(GByteArray *array ,
                                       guint8 const   *data , guint len ) ;
extern GByteArray *g_byte_array_prepend(GByteArray *array ,
                                        guint8 const   *data , guint len ) ;
extern GByteArray *g_byte_array_set_size(GByteArray *array , guint length ) ;
extern GByteArray *g_byte_array_remove_index(GByteArray *array , guint index_ ) ;
extern GByteArray *g_byte_array_remove_index_fast(GByteArray *array ,
                                                  guint index_ ) ;
extern GByteArray *g_byte_array_remove_range(GByteArray *array , guint index_ ,
                                             guint length ) ;
extern void g_byte_array_sort(GByteArray *array ,
                              gint (*compare_func)(gconstpointer a ,
                                                   gconstpointer b ) ) ;
extern void g_byte_array_sort_with_data(GByteArray *array ,
                                        gint (*compare_func)(gconstpointer a ,
                                                             gconstpointer b ,
                                                             gpointer user_data ) ,
                                        gpointer user_data ) ;
extern GQuark g_quark_try_string(gchar const   *string ) ;
extern GQuark g_quark_from_static_string(gchar const   *string ) ;
extern GQuark g_quark_from_string(gchar const   *string ) ;
extern gchar const   *g_quark_to_string(GQuark quark )  __attribute__((__const__)) ;
extern gchar const   *g_intern_string(gchar const   *string ) ;
extern gchar const   *g_intern_static_string(gchar const   *string ) ;
extern GError *( /* format attribute */  g_error_new)(GQuark domain ,
                                                      gint code ,
                                                      gchar const   *format 
                                                      , ...) ;
extern GError *g_error_new_literal(GQuark domain , gint code ,
                                   gchar const   *message ) ;
extern GError *g_error_new_valist(GQuark domain , gint code ,
                                  gchar const   *format , va_list args ) ;
extern void g_error_free(GError *error ) ;
extern GError *g_error_copy(GError const   *error ) ;
extern gboolean g_error_matches(GError const   *error , GQuark domain ,
                                gint code ) ;
extern void ( /* format attribute */  g_set_error)(GError **err ,
                                                   GQuark domain , gint code ,
                                                   gchar const   *format  , ...) ;
extern void g_set_error_literal(GError **err , GQuark domain , gint code ,
                                gchar const   *message ) ;
extern void g_propagate_error(GError **dest , GError *src ) ;
extern void g_clear_error(GError **err ) ;
extern void ( /* format attribute */  g_prefix_error)(GError **err ,
                                                      gchar const   *format 
                                                      , ...) ;
extern void ( /* format attribute */  g_propagate_prefixed_error)(GError **dest ,
                                                                  GError *src ,
                                                                  gchar const   *format 
                                                                  , ...) ;
extern gchar const   *g_get_user_name(void) ;
extern gchar const   *g_get_real_name(void) ;
extern gchar const   *g_get_home_dir(void) ;
extern gchar const   *g_get_tmp_dir(void) ;
extern gchar const   *g_get_host_name(void) ;
extern gchar *g_get_prgname(void) ;
extern void g_set_prgname(gchar const   *prgname ) ;
extern gchar const   *g_get_application_name(void) ;
extern void g_set_application_name(gchar const   *application_name ) ;
extern void g_reload_user_special_dirs_cache(void) ;
extern gchar const   *g_get_user_data_dir(void) ;
extern gchar const   *g_get_user_config_dir(void) ;
extern gchar const   *g_get_user_cache_dir(void) ;
extern gchar const   * const  *g_get_system_data_dirs(void) ;
extern gchar const   * const  *g_get_system_config_dirs(void) ;
extern gchar const   * const  *g_get_language_names(void) ;
extern gchar const   *g_get_user_special_dir(GUserDirectory directory ) ;
extern guint g_parse_debug_string(gchar const   *string ,
                                  GDebugKey const   *keys , guint nkeys ) ;
extern gint ( /* format attribute */  g_snprintf)(gchar *string , gulong n ,
                                                  gchar const   *format  , ...) ;
extern gint g_vsnprintf(gchar *string , gulong n , gchar const   *format ,
                        va_list args ) ;
extern gboolean g_path_is_absolute(gchar const   *file_name ) ;
extern gchar const   *g_path_skip_root(gchar const   *file_name ) ;
extern gchar const   *g_basename(gchar const   *file_name ) ;
extern gchar *g_get_current_dir(void) ;
extern gchar *g_path_get_basename(gchar const   *file_name )  __attribute__((__malloc__)) ;
extern gchar *g_path_get_dirname(gchar const   *file_name )  __attribute__((__malloc__)) ;
extern void g_nullify_pointer(gpointer *nullify_location ) ;
extern gchar const   *g_getenv(gchar const   *variable ) ;
extern gboolean g_setenv(gchar const   *variable , gchar const   *value ,
                         gboolean overwrite ) ;
extern void g_unsetenv(gchar const   *variable ) ;
extern gchar **g_listenv(void) ;
extern gchar const   *_g_getenv_nomalloc(gchar const   *variable ,
                                         gchar *buffer ) ;
extern void g_atexit(void (*func)(void) ) ;
extern gchar *g_find_program_in_path(gchar const   *program ) ;
__inline static gint g_bit_nth_lsf(gulong mask , gint nth_bit )  __attribute__((__unused__,
__const__)) ;
__inline static gint g_bit_nth_msf(gulong mask , gint nth_bit )  __attribute__((__unused__,
__const__)) ;
__inline static guint g_bit_storage(gulong number )  __attribute__((__unused__,
__const__)) ;
__inline static void g_trash_stack_push(GTrashStack **stack_p , gpointer data_p )  __attribute__((__unused__)) ;
__inline static gpointer g_trash_stack_pop(GTrashStack **stack_p )  __attribute__((__unused__)) ;
__inline static gpointer g_trash_stack_peek(GTrashStack **stack_p )  __attribute__((__unused__)) ;
__inline static guint g_trash_stack_height(GTrashStack **stack_p )  __attribute__((__unused__)) ;
__inline static gint g_bit_nth_lsf(gulong mask , gint nth_bit )  __attribute__((__unused__,
__const__)) ;
__inline static gint g_bit_nth_lsf(gulong mask , gint nth_bit ) 
{ 
  int _g_boolean_var_ ;
  long tmp ;

  {

  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "178", "-1",
                  checkpoints_buf);
  if (nth_bit < -1) {
    _g_boolean_var_ = 1;
    sprintf(checkpoints_buf, "%d", _g_boolean_var_);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "179",
                    "_g_boolean_var_", checkpoints_buf);
  } else {
    _g_boolean_var_ = 0;
    sprintf(checkpoints_buf, "%d", _g_boolean_var_);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "180",
                    "_g_boolean_var_", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "178", "-1",
                  checkpoints_buf);
  sprintf(checkpoints_buf, "%ld", tmp);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "181", "tmp",
                  checkpoints_buf);

  tmp = __builtin_expect((long )_g_boolean_var_, 0L);
  sprintf(checkpoints_buf, "%ld", tmp);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "181", "tmp",
                  checkpoints_buf);

  sprintf(checkpoints_buf, "%ld", tmp);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "182", "tmp",
                  checkpoints_buf);
  if (tmp) {
    nth_bit = -1;

  } else {

  }
  sprintf(checkpoints_buf, "%ld", tmp);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "182", "tmp",
                  checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 31);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "185", "31",
                  checkpoints_buf);


  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "185", "1",
                  checkpoints_buf);

  while (1) {

    sprintf(checkpoints_buf, "%d", 31);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "186",
                    "31", checkpoints_buf);
    if (nth_bit < 31) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%d", 31);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "186",
                    "31", checkpoints_buf);
    nth_bit ++;


    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "190", "1",
                    checkpoints_buf);

    if (mask & (1UL << nth_bit)) {

      return (nth_bit);
    } else {

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "190", "1",
                    checkpoints_buf);

  }

  sprintf(checkpoints_buf, "%d", 31);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "185", "31",
                  checkpoints_buf);


  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "185", "1",
                  checkpoints_buf);

  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "193", "-1",
                  checkpoints_buf);
  return (-1);
}
}
__inline static gint g_bit_nth_msf(gulong mask , gint nth_bit )  __attribute__((__unused__,
__const__)) ;
__inline static gint g_bit_nth_msf(gulong mask , gint nth_bit ) 
{ 
  int _g_boolean_var_ ;
  long tmp ;

  {

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "194", "0",
                  checkpoints_buf);
  if (nth_bit < 0) {
    nth_bit = 32;

  } else {

    sprintf(checkpoints_buf, "%d", 32);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "196",
                    "32", checkpoints_buf);
    if (nth_bit > 32) {
      _g_boolean_var_ = 1;
      sprintf(checkpoints_buf, "%d", _g_boolean_var_);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "197",
                      "_g_boolean_var_", checkpoints_buf);
    } else {
      _g_boolean_var_ = 0;
      sprintf(checkpoints_buf, "%d", _g_boolean_var_);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "198",
                      "_g_boolean_var_", checkpoints_buf);
    }

    sprintf(checkpoints_buf, "%d", 32);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "196",
                    "32", checkpoints_buf);
    sprintf(checkpoints_buf, "%ld", tmp);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "199",
                    "tmp", checkpoints_buf);

    tmp = __builtin_expect((long )_g_boolean_var_, 0L);
    sprintf(checkpoints_buf, "%ld", tmp);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "199",
                    "tmp", checkpoints_buf);

    sprintf(checkpoints_buf, "%ld", tmp);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "200",
                    "tmp", checkpoints_buf);
    if (tmp) {
      nth_bit = 32;

    } else {

    }
    sprintf(checkpoints_buf, "%ld", tmp);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "200",
                    "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "194", "0",
                  checkpoints_buf);

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "203", "0",
                  checkpoints_buf);


  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "203", "1",
                  checkpoints_buf);

  while (1) {

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "204", "0",
                    checkpoints_buf);
    if (nth_bit > 0) {

    } else {
      break;
    }

    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "204", "0",
                    checkpoints_buf);
    nth_bit --;


    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "208", "1",
                    checkpoints_buf);

    if (mask & (1UL << nth_bit)) {

      return (nth_bit);
    } else {

    }

    sprintf(checkpoints_buf, "%ul", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "208", "1",
                    checkpoints_buf);

  }

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "203", "0",
                  checkpoints_buf);


  sprintf(checkpoints_buf, "%ul", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "203", "1",
                  checkpoints_buf);

  sprintf(checkpoints_buf, "%d", -1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "211", "-1",
                  checkpoints_buf);
  return (-1);
}
}
__inline static guint g_bit_storage(gulong number )  __attribute__((__unused__,
__const__)) ;
__inline static guint g_bit_storage(gulong number ) 
{ 
  int _g_boolean_var_ ;
  long tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int _g_boolean_var____0 ;
  long tmp___2 ;

  {

  if (number) {
    _g_boolean_var____0 = 1;
    sprintf(checkpoints_buf, "%d", _g_boolean_var____0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "213",
                    "_g_boolean_var____0", checkpoints_buf);
  } else {
    _g_boolean_var____0 = 0;
    sprintf(checkpoints_buf, "%d", _g_boolean_var____0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "214",
                    "_g_boolean_var____0", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%ld", tmp___2);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "215",
                  "tmp___2", checkpoints_buf);

  tmp___2 = __builtin_expect((long )_g_boolean_var____0, 1L);
  sprintf(checkpoints_buf, "%ld", tmp___2);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "215",
                  "tmp___2", checkpoints_buf);

  sprintf(checkpoints_buf, "%ld", tmp___2);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "216",
                  "tmp___2", checkpoints_buf);
  if (tmp___2) {
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "217",
                    "tmp___0", checkpoints_buf);

    tmp___0 = __builtin_clzl(number);
    sprintf(checkpoints_buf, "%d", tmp___0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "217",
                    "tmp___0", checkpoints_buf);

    tmp___1 = (31 ^ tmp___0) + 1;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "218",
                    "tmp___1", checkpoints_buf);
  } else {
    tmp___1 = 1;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "219",
                    "tmp___1", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%ld", tmp___2);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "216",
                  "tmp___2", checkpoints_buf);
  return ((guint )tmp___1);
}
}
__inline static void g_trash_stack_push(GTrashStack **stack_p , gpointer data_p )  __attribute__((__unused__)) ;
__inline static void g_trash_stack_push(GTrashStack **stack_p , gpointer data_p ) 
{ 
  GTrashStack *data ;

  {
  data = (GTrashStack *)data_p;

  data->next = *stack_p;

  *stack_p = data;

  return;
}
}
__inline static gpointer g_trash_stack_pop(GTrashStack **stack_p )  __attribute__((__unused__)) ;
__inline static gpointer g_trash_stack_pop(GTrashStack **stack_p ) 
{ 
  GTrashStack *data ;

  {
  data = *stack_p;


  if (data) {
    *stack_p = data->next;

    data->next = (GTrashStack *)((void *)0);

  } else {

  }

  return ((gpointer )data);
}
}
__inline static gpointer g_trash_stack_peek(GTrashStack **stack_p )  __attribute__((__unused__)) ;
__inline static gpointer g_trash_stack_peek(GTrashStack **stack_p ) 
{ 
  GTrashStack *data ;

  {
  data = *stack_p;

  return ((gpointer )data);
}
}
__inline static guint g_trash_stack_height(GTrashStack **stack_p )  __attribute__((__unused__)) ;
__inline static guint g_trash_stack_height(GTrashStack **stack_p ) 
{ 
  GTrashStack *data ;
  guint i ;

  {
  i = (guint )0;

  data = *stack_p;




  while (data) {

    i ++;

    data = data->next;

  }




  return (i);
}
}
extern guint const   glib_major_version ;
extern guint const   glib_minor_version ;
extern guint const   glib_micro_version ;
extern guint const   glib_interface_age ;
extern guint const   glib_binary_age ;
extern gchar const   *glib_check_version(guint required_major ,
                                         guint required_minor ,
                                         guint required_micro ) ;
extern gint g_atomic_int_exchange_and_add(gint volatile __attribute__((__may_alias__))  *atomic ,
                                          gint val ) ;
extern void g_atomic_int_add(gint volatile __attribute__((__may_alias__))  *atomic ,
                             gint val ) ;
extern gboolean g_atomic_int_compare_and_exchange(gint volatile __attribute__((__may_alias__))  *atomic ,
                                                  gint oldval , gint newval ) ;
extern gboolean g_atomic_pointer_compare_and_exchange(gpointer volatile __attribute__((__may_alias__))  *atomic ,
                                                      gpointer oldval ,
                                                      gpointer newval ) ;
extern gint g_atomic_int_get(gint volatile __attribute__((__may_alias__))  *atomic ) ;
extern void g_atomic_int_set(gint volatile __attribute__((__may_alias__))  *atomic ,
                             gint newval ) ;
extern gpointer g_atomic_pointer_get(gpointer volatile __attribute__((__may_alias__))  *atomic ) ;
extern void g_atomic_pointer_set(gpointer volatile __attribute__((__may_alias__))  *atomic ,
                                 gpointer newval ) ;
extern GQuark g_thread_error_quark(void) ;
extern GThreadFunctions g_thread_functions_for_glib_use ;
extern gboolean g_thread_use_default_impl ;
extern gboolean g_threads_got_initialized ;
extern guint64 (*g_thread_gettime)(void) ;
extern void g_thread_init(GThreadFunctions *vtable ) ;
extern void g_thread_init_with_errorcheck_mutexes(GThreadFunctions *vtable ) ;
extern gboolean g_thread_get_initialized(void) ;
extern GMutex *g_static_mutex_get_mutex_impl(GMutex **mutex ) ;
extern GThread *g_thread_create_full(gpointer (*func)(gpointer data ) ,
                                     gpointer data , gulong stack_size ,
                                     gboolean joinable , gboolean bound ,
                                     GThreadPriority priority , GError **error ) ;
extern GThread *g_thread_self(void) ;
extern void g_thread_exit(gpointer retval ) ;
extern gpointer g_thread_join(GThread *thread ) ;
extern void g_thread_set_priority(GThread *thread , GThreadPriority priority ) ;
extern void g_static_mutex_init(GStaticMutex *mutex ) ;
extern void g_static_mutex_free(GStaticMutex *mutex ) ;
extern void g_static_private_init(GStaticPrivate *private_key ) ;
extern gpointer g_static_private_get(GStaticPrivate *private_key ) ;
extern void g_static_private_set(GStaticPrivate *private_key , gpointer data ,
                                 void (*notify)(gpointer data ) ) ;
extern void g_static_private_free(GStaticPrivate *private_key ) ;
extern void g_static_rec_mutex_init(GStaticRecMutex *mutex ) ;
extern void g_static_rec_mutex_lock(GStaticRecMutex *mutex ) ;
extern gboolean g_static_rec_mutex_trylock(GStaticRecMutex *mutex ) ;
extern void g_static_rec_mutex_unlock(GStaticRecMutex *mutex ) ;
extern void g_static_rec_mutex_lock_full(GStaticRecMutex *mutex , guint depth ) ;
extern guint g_static_rec_mutex_unlock_full(GStaticRecMutex *mutex ) ;
extern void g_static_rec_mutex_free(GStaticRecMutex *mutex ) ;
extern void g_static_rw_lock_init(GStaticRWLock *lock ) ;
extern void g_static_rw_lock_reader_lock(GStaticRWLock *lock ) ;
extern gboolean g_static_rw_lock_reader_trylock(GStaticRWLock *lock ) ;
extern void g_static_rw_lock_reader_unlock(GStaticRWLock *lock ) ;
extern void g_static_rw_lock_writer_lock(GStaticRWLock *lock ) ;
extern gboolean g_static_rw_lock_writer_trylock(GStaticRWLock *lock ) ;
extern void g_static_rw_lock_writer_unlock(GStaticRWLock *lock ) ;
extern void g_static_rw_lock_free(GStaticRWLock *lock ) ;
extern void g_thread_foreach(void (*thread_func)(gpointer data ,
                                                 gpointer user_data ) ,
                             gpointer user_data ) ;
extern gpointer g_once_impl(GOnce *once , gpointer (*func)(gpointer data ) ,
                            gpointer arg ) ;
__inline static gboolean g_once_init_enter(gsize volatile   *value_location )  __attribute__((__unused__)) ;
extern gboolean g_once_init_enter_impl(gsize volatile   *value_location ) ;
extern void g_once_init_leave(gsize volatile   *value_location ,
                              gsize initialization_value ) ;
__inline static gboolean g_once_init_enter(gsize volatile   *value_location )  __attribute__((__unused__)) ;
__inline static gboolean g_once_init_enter(gsize volatile   *value_location ) 
{ 
  gboolean tmp ;
  int _g_boolean_var_ ;
  gpointer tmp___0 ;
  long tmp___1 ;

  {


  tmp___0 = g_atomic_pointer_get((gpointer volatile __attribute__((__may_alias__))  *)((void *)value_location));


  if ((unsigned int )tmp___0 != (unsigned int )((void *)0)) {
    _g_boolean_var_ = 1;
    sprintf(checkpoints_buf, "%d", _g_boolean_var_);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "244",
                    "_g_boolean_var_", checkpoints_buf);
  } else {
    _g_boolean_var_ = 0;
    sprintf(checkpoints_buf, "%d", _g_boolean_var_);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "245",
                    "_g_boolean_var_", checkpoints_buf);
  }
  sprintf(checkpoints_buf, "%ld", tmp___1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "246",
                  "tmp___1", checkpoints_buf);

  tmp___1 = __builtin_expect((long )_g_boolean_var_, 1L);
  sprintf(checkpoints_buf, "%ld", tmp___1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "246",
                  "tmp___1", checkpoints_buf);

  sprintf(checkpoints_buf, "%ld", tmp___1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "247",
                  "tmp___1", checkpoints_buf);
  if (tmp___1) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "248", "0",
                    checkpoints_buf);
    return (0);
  } else {


    tmp = g_once_init_enter_impl(value_location);



    return (tmp);
  }
  sprintf(checkpoints_buf, "%ld", tmp___1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "247",
                  "tmp___1", checkpoints_buf);
}
}
extern void glib_dummy_decl(void) ;
extern GAsyncQueue *g_async_queue_new(void) ;
extern GAsyncQueue *g_async_queue_new_full(void (*item_free_func)(gpointer data ) ) ;
extern void g_async_queue_lock(GAsyncQueue *queue ) ;
extern void g_async_queue_unlock(GAsyncQueue *queue ) ;
extern GAsyncQueue *g_async_queue_ref(GAsyncQueue *queue ) ;
extern void g_async_queue_unref(GAsyncQueue *queue ) ;
extern void g_async_queue_ref_unlocked(GAsyncQueue *queue ) ;
extern void g_async_queue_unref_and_unlock(GAsyncQueue *queue ) ;
extern void g_async_queue_push(GAsyncQueue *queue , gpointer data ) ;
extern void g_async_queue_push_unlocked(GAsyncQueue *queue , gpointer data ) ;
extern void g_async_queue_push_sorted(GAsyncQueue *queue , gpointer data ,
                                      gint (*func)(gconstpointer a ,
                                                   gconstpointer b ,
                                                   gpointer user_data ) ,
                                      gpointer user_data ) ;
extern void g_async_queue_push_sorted_unlocked(GAsyncQueue *queue ,
                                               gpointer data ,
                                               gint (*func)(gconstpointer a ,
                                                            gconstpointer b ,
                                                            gpointer user_data ) ,
                                               gpointer user_data ) ;
extern gpointer g_async_queue_pop(GAsyncQueue *queue ) ;
extern gpointer g_async_queue_pop_unlocked(GAsyncQueue *queue ) ;
extern gpointer g_async_queue_try_pop(GAsyncQueue *queue ) ;
extern gpointer g_async_queue_try_pop_unlocked(GAsyncQueue *queue ) ;
extern gpointer g_async_queue_timed_pop(GAsyncQueue *queue , GTimeVal *end_time ) ;
extern gpointer g_async_queue_timed_pop_unlocked(GAsyncQueue *queue ,
                                                 GTimeVal *end_time ) ;
extern gint g_async_queue_length(GAsyncQueue *queue ) ;
extern gint g_async_queue_length_unlocked(GAsyncQueue *queue ) ;
extern void g_async_queue_sort(GAsyncQueue *queue ,
                               gint (*func)(gconstpointer a , gconstpointer b ,
                                            gpointer user_data ) ,
                               gpointer user_data ) ;
extern void g_async_queue_sort_unlocked(GAsyncQueue *queue ,
                                        gint (*func)(gconstpointer a ,
                                                     gconstpointer b ,
                                                     gpointer user_data ) ,
                                        gpointer user_data ) ;
extern GMutex *_g_async_queue_get_mutex(GAsyncQueue *queue ) ;
__inline extern int __sigismember(__sigset_t const   *__set , int __sig ) ;
__inline extern int __sigaddset(__sigset_t *__set , int __sig ) ;
__inline extern int __sigdelset(__sigset_t *__set , int __sig ) ;
__inline extern int __sigismember(__sigset_t const   *__set , int __sig ) 
{ 
  unsigned long __mask ;
  unsigned long __word ;
  int tmp ;

  {
  __mask = 1UL << (unsigned int )(__sig - 1) % (8U * sizeof(unsigned long ));
  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "251",
                  "__mask", checkpoints_buf);
  __word = (unsigned long )((unsigned int )(__sig - 1) / (8U * sizeof(unsigned long )));
  sprintf(checkpoints_buf, "%ul", __word);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "252",
                  "__word", checkpoints_buf);

  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "253",
                  "__mask", checkpoints_buf);
  if (__set->__val[__word] & __mask) {
    tmp = 1;
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "254",
                    "tmp", checkpoints_buf);
  } else {
    tmp = 0;
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "255",
                    "tmp", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "253",
                  "__mask", checkpoints_buf);
  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "256", "tmp",
                  checkpoints_buf);
  return (tmp);
}
}
__inline extern int __sigaddset(__sigset_t *__set , int __sig ) 
{ 
  unsigned long __mask ;
  unsigned long __word ;

  {
  __mask = 1UL << (unsigned int )(__sig - 1) % (8U * sizeof(unsigned long ));
  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "257",
                  "__mask", checkpoints_buf);
  __word = (unsigned long )((unsigned int )(__sig - 1) / (8U * sizeof(unsigned long )));
  sprintf(checkpoints_buf, "%ul", __word);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "258",
                  "__word", checkpoints_buf);
  __set->__val[__word] |= __mask;

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "260", "0",
                  checkpoints_buf);
  return (0);
}
}
__inline extern int __sigdelset(__sigset_t *__set , int __sig ) 
{ 
  unsigned long __mask ;
  unsigned long __word ;

  {
  __mask = 1UL << (unsigned int )(__sig - 1) % (8U * sizeof(unsigned long ));
  sprintf(checkpoints_buf, "%ul", __mask);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "261",
                  "__mask", checkpoints_buf);
  __word = (unsigned long )((unsigned int )(__sig - 1) / (8U * sizeof(unsigned long )));
  sprintf(checkpoints_buf, "%ul", __word);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "262",
                  "__word", checkpoints_buf);
  __set->__val[__word] &= ~ __mask;

  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "264", "0",
                  checkpoints_buf);
  return (0);
}
}
extern  __attribute__((__nothrow__)) __sighandler_t __sysv_signal(int __sig ,
                                                                  void (*__handler)(int  ) ) ;
extern  __attribute__((__nothrow__)) __sighandler_t signal(int __sig ,
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
extern  __attribute__((__nothrow__)) int pthread_sigmask(int __how ,
                                                         __sigset_t const   * __restrict  __newmask ,
                                                         __sigset_t * __restrict  __oldmask ) ;
extern  __attribute__((__nothrow__)) int pthread_kill(pthread_t __threadid ,
                                                      int __signo ) ;
extern  __attribute__((__nothrow__)) int __libc_current_sigrtmin(void) ;
extern  __attribute__((__nothrow__)) int __libc_current_sigrtmax(void) ;
extern void g_on_error_query(gchar const   *prg_name ) ;
extern void g_on_error_stack_trace(gchar const   *prg_name ) ;
extern gsize g_base64_encode_step(guchar const   *in , gsize len ,
                                  gboolean break_lines , gchar *out ,
                                  gint *state , gint *save ) ;
extern gsize g_base64_encode_close(gboolean break_lines , gchar *out ,
                                   gint *state , gint *save ) ;
extern gchar *g_base64_encode(guchar const   *data , gsize len )  __attribute__((__malloc__)) ;
extern gsize g_base64_decode_step(gchar const   *in , gsize len , guchar *out ,
                                  gint *state , guint *save ) ;
extern guchar *g_base64_decode(gchar const   *text , gsize *out_len )  __attribute__((__malloc__)) ;
extern guchar *g_base64_decode_inplace(gchar *text , gsize *out_len ) ;
extern void g_bit_lock(gint volatile   *address , gint lock_bit ) ;
extern gboolean g_bit_trylock(gint volatile   *address , gint lock_bit ) ;
extern void g_bit_unlock(gint volatile   *address , gint lock_bit ) ;
extern  __attribute__((__nothrow__)) clock_t clock(void) ;
extern  __attribute__((__nothrow__)) time_t time(time_t *__timer ) ;
extern  __attribute__((__nothrow__)) double difftime(time_t __time1 ,
                                                     time_t __time0 )  __attribute__((__const__)) ;
extern  __attribute__((__nothrow__)) time_t mktime(struct tm *__tp ) ;
extern  __attribute__((__nothrow__)) size_t strftime(char * __restrict  __s ,
                                                     size_t __maxsize ,
                                                     char const   * __restrict  __format ,
                                                     struct tm  const  * __restrict  __tp ) ;
extern  __attribute__((__nothrow__)) size_t strftime_l(char * __restrict  __s ,
                                                       size_t __maxsize ,
                                                       char const   * __restrict  __format ,
                                                       struct tm  const  * __restrict  __tp ,
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
extern GQuark g_bookmark_file_error_quark(void) ;
extern GBookmarkFile *g_bookmark_file_new(void) ;
extern void g_bookmark_file_free(GBookmarkFile *bookmark ) ;
extern gboolean g_bookmark_file_load_from_file(GBookmarkFile *bookmark ,
                                               gchar const   *filename ,
                                               GError **error ) ;
extern gboolean g_bookmark_file_load_from_data(GBookmarkFile *bookmark ,
                                               gchar const   *data ,
                                               gsize length , GError **error ) ;
extern gboolean g_bookmark_file_load_from_data_dirs(GBookmarkFile *bookmark ,
                                                    gchar const   *file ,
                                                    gchar **full_path ,
                                                    GError **error ) ;
extern gchar *g_bookmark_file_to_data(GBookmarkFile *bookmark , gsize *length ,
                                      GError **error )  __attribute__((__malloc__)) ;
extern gboolean g_bookmark_file_to_file(GBookmarkFile *bookmark ,
                                        gchar const   *filename ,
                                        GError **error ) ;
extern void g_bookmark_file_set_title(GBookmarkFile *bookmark ,
                                      gchar const   *uri , gchar const   *title ) ;
extern gchar *g_bookmark_file_get_title(GBookmarkFile *bookmark ,
                                        gchar const   *uri , GError **error )  __attribute__((__malloc__)) ;
extern void g_bookmark_file_set_description(GBookmarkFile *bookmark ,
                                            gchar const   *uri ,
                                            gchar const   *description ) ;
extern gchar *g_bookmark_file_get_description(GBookmarkFile *bookmark ,
                                              gchar const   *uri ,
                                              GError **error )  __attribute__((__malloc__)) ;
extern void g_bookmark_file_set_mime_type(GBookmarkFile *bookmark ,
                                          gchar const   *uri ,
                                          gchar const   *mime_type ) ;
extern gchar *g_bookmark_file_get_mime_type(GBookmarkFile *bookmark ,
                                            gchar const   *uri , GError **error )  __attribute__((__malloc__)) ;
extern void g_bookmark_file_set_groups(GBookmarkFile *bookmark ,
                                       gchar const   *uri ,
                                       gchar const   **groups , gsize length ) ;
extern void g_bookmark_file_add_group(GBookmarkFile *bookmark ,
                                      gchar const   *uri , gchar const   *group ) ;
extern gboolean g_bookmark_file_has_group(GBookmarkFile *bookmark ,
                                          gchar const   *uri ,
                                          gchar const   *group , GError **error ) ;
extern gchar **g_bookmark_file_get_groups(GBookmarkFile *bookmark ,
                                          gchar const   *uri , gsize *length ,
                                          GError **error )  __attribute__((__malloc__)) ;
extern void g_bookmark_file_add_application(GBookmarkFile *bookmark ,
                                            gchar const   *uri ,
                                            gchar const   *name ,
                                            gchar const   *exec ) ;
extern gboolean g_bookmark_file_has_application(GBookmarkFile *bookmark ,
                                                gchar const   *uri ,
                                                gchar const   *name ,
                                                GError **error ) ;
extern gchar **g_bookmark_file_get_applications(GBookmarkFile *bookmark ,
                                                gchar const   *uri ,
                                                gsize *length , GError **error )  __attribute__((__malloc__)) ;
extern gboolean g_bookmark_file_set_app_info(GBookmarkFile *bookmark ,
                                             gchar const   *uri ,
                                             gchar const   *name ,
                                             gchar const   *exec , gint count ,
                                             time_t stamp , GError **error ) ;
extern gboolean g_bookmark_file_get_app_info(GBookmarkFile *bookmark ,
                                             gchar const   *uri ,
                                             gchar const   *name ,
                                             gchar **exec , guint *count ,
                                             time_t *stamp , GError **error ) ;
extern void g_bookmark_file_set_is_private(GBookmarkFile *bookmark ,
                                           gchar const   *uri ,
                                           gboolean is_private ) ;
extern gboolean g_bookmark_file_get_is_private(GBookmarkFile *bookmark ,
                                               gchar const   *uri ,
                                               GError **error ) ;
extern void g_bookmark_file_set_icon(GBookmarkFile *bookmark ,
                                     gchar const   *uri , gchar const   *href ,
                                     gchar const   *mime_type ) ;
extern gboolean g_bookmark_file_get_icon(GBookmarkFile *bookmark ,
                                         gchar const   *uri , gchar **href ,
                                         gchar **mime_type , GError **error ) ;
extern void g_bookmark_file_set_added(GBookmarkFile *bookmark ,
                                      gchar const   *uri , time_t added ) ;
extern time_t g_bookmark_file_get_added(GBookmarkFile *bookmark ,
                                        gchar const   *uri , GError **error ) ;
extern void g_bookmark_file_set_modified(GBookmarkFile *bookmark ,
                                         gchar const   *uri , time_t modified ) ;
extern time_t g_bookmark_file_get_modified(GBookmarkFile *bookmark ,
                                           gchar const   *uri , GError **error ) ;
extern void g_bookmark_file_set_visited(GBookmarkFile *bookmark ,
                                        gchar const   *uri , time_t visited ) ;
extern time_t g_bookmark_file_get_visited(GBookmarkFile *bookmark ,
                                          gchar const   *uri , GError **error ) ;
extern gboolean g_bookmark_file_has_item(GBookmarkFile *bookmark ,
                                         gchar const   *uri ) ;
extern gint g_bookmark_file_get_size(GBookmarkFile *bookmark ) ;
extern gchar **g_bookmark_file_get_uris(GBookmarkFile *bookmark , gsize *length )  __attribute__((__malloc__)) ;
extern gboolean g_bookmark_file_remove_group(GBookmarkFile *bookmark ,
                                             gchar const   *uri ,
                                             gchar const   *group ,
                                             GError **error ) ;
extern gboolean g_bookmark_file_remove_application(GBookmarkFile *bookmark ,
                                                   gchar const   *uri ,
                                                   gchar const   *name ,
                                                   GError **error ) ;
extern gboolean g_bookmark_file_remove_item(GBookmarkFile *bookmark ,
                                            gchar const   *uri , GError **error ) ;
extern gboolean g_bookmark_file_move_item(GBookmarkFile *bookmark ,
                                          gchar const   *old_uri ,
                                          gchar const   *new_uri ,
                                          GError **error ) ;
extern gpointer g_slice_alloc(gsize block_size )  __attribute__((__malloc__,
__alloc_size__(1))) ;
extern gpointer g_slice_alloc0(gsize block_size )  __attribute__((__malloc__,
__alloc_size__(1))) ;
extern gpointer g_slice_copy(gsize block_size , gconstpointer mem_block )  __attribute__((__malloc__,
__alloc_size__(1))) ;
extern void g_slice_free1(gsize block_size , gpointer mem_block ) ;
extern void g_slice_free_chain_with_offset(gsize block_size ,
                                           gpointer mem_chain ,
                                           gsize next_offset ) ;
extern void g_slice_set_config(GSliceConfig ckey , gint64 value ) ;
extern gint64 g_slice_get_config(GSliceConfig ckey ) ;
extern gint64 *g_slice_get_config_state(GSliceConfig ckey , gint64 address ,
                                        guint *n_values ) ;
extern void g_free(gpointer mem ) ;
extern gpointer g_malloc(gsize n_bytes )  __attribute__((__malloc__,
__alloc_size__(1))) ;
extern gpointer g_malloc0(gsize n_bytes )  __attribute__((__malloc__,
__alloc_size__(1))) ;
extern gpointer ( __attribute__((__warn_unused_result__)) g_realloc)(gpointer mem ,
                                                                     gsize n_bytes ) ;
extern gpointer g_try_malloc(gsize n_bytes )  __attribute__((__malloc__,
__alloc_size__(1))) ;
extern gpointer g_try_malloc0(gsize n_bytes )  __attribute__((__malloc__,
__alloc_size__(1))) ;
extern gpointer ( __attribute__((__warn_unused_result__)) g_try_realloc)(gpointer mem ,
                                                                         gsize n_bytes ) ;
extern gpointer g_malloc_n(gsize n_blocks , gsize n_block_bytes )  __attribute__((__malloc__,
__alloc_size__(1,2))) ;
extern gpointer g_malloc0_n(gsize n_blocks , gsize n_block_bytes )  __attribute__((__malloc__,
__alloc_size__(1,2))) ;
extern gpointer ( __attribute__((__warn_unused_result__)) g_realloc_n)(gpointer mem ,
                                                                       gsize n_blocks ,
                                                                       gsize n_block_bytes ) ;
extern gpointer g_try_malloc_n(gsize n_blocks , gsize n_block_bytes )  __attribute__((__malloc__,
__alloc_size__(1,2))) ;
extern gpointer g_try_malloc0_n(gsize n_blocks , gsize n_block_bytes )  __attribute__((__malloc__,
__alloc_size__(1,2))) ;
extern gpointer ( __attribute__((__warn_unused_result__)) g_try_realloc_n)(gpointer mem ,
                                                                           gsize n_blocks ,
                                                                           gsize n_block_bytes ) ;
extern void g_mem_set_vtable(GMemVTable *vtable ) ;
extern gboolean g_mem_is_system_malloc(void) ;
extern gboolean g_mem_gc_friendly ;
extern GMemVTable *glib_mem_profiler_table ;
extern void g_mem_profile(void) ;
extern GMemChunk *g_mem_chunk_new(gchar const   *name , gint atom_size ,
                                  gsize area_size , gint type ) ;
extern void g_mem_chunk_destroy(GMemChunk *mem_chunk ) ;
extern gpointer g_mem_chunk_alloc(GMemChunk *mem_chunk ) ;
extern gpointer g_mem_chunk_alloc0(GMemChunk *mem_chunk ) ;
extern void g_mem_chunk_free(GMemChunk *mem_chunk , gpointer mem ) ;
extern void g_mem_chunk_clean(GMemChunk *mem_chunk ) ;
extern void g_mem_chunk_reset(GMemChunk *mem_chunk ) ;
extern void g_mem_chunk_print(GMemChunk *mem_chunk ) ;
extern void g_mem_chunk_info(void) ;
extern void g_blow_chunks(void) ;
extern GAllocator *g_allocator_new(gchar const   *name , guint n_preallocs ) ;
extern void g_allocator_free(GAllocator *allocator ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_alloc)(void) ;
extern void g_list_free(GList *list ) ;
extern void g_list_free_1(GList *list ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_append)(GList *list ,
                                                                       gpointer data ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_prepend)(GList *list ,
                                                                        gpointer data ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_insert)(GList *list ,
                                                                       gpointer data ,
                                                                       gint position ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_insert_sorted)(GList *list ,
                                                                              gpointer data ,
                                                                              gint (*func)(gconstpointer a ,
                                                                                           gconstpointer b ) ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_insert_sorted_with_data)(GList *list ,
                                                                                        gpointer data ,
                                                                                        gint (*func)(gconstpointer a ,
                                                                                                     gconstpointer b ,
                                                                                                     gpointer user_data ) ,
                                                                                        gpointer user_data ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_insert_before)(GList *list ,
                                                                              GList *sibling ,
                                                                              gpointer data ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_concat)(GList *list1 ,
                                                                       GList *list2 ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_remove)(GList *list ,
                                                                       gconstpointer data ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_remove_all)(GList *list ,
                                                                           gconstpointer data ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_remove_link)(GList *list ,
                                                                            GList *llink ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_delete_link)(GList *list ,
                                                                            GList *link_ ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_reverse)(GList *list ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_copy)(GList *list ) ;
extern GList *g_list_nth(GList *list , guint n ) ;
extern GList *g_list_nth_prev(GList *list , guint n ) ;
extern GList *g_list_find(GList *list , gconstpointer data ) ;
extern GList *g_list_find_custom(GList *list , gconstpointer data ,
                                 gint (*func)(gconstpointer a , gconstpointer b ) ) ;
extern gint g_list_position(GList *list , GList *llink ) ;
extern gint g_list_index(GList *list , gconstpointer data ) ;
extern GList *g_list_last(GList *list ) ;
extern GList *g_list_first(GList *list ) ;
extern guint g_list_length(GList *list ) ;
extern void g_list_foreach(GList *list , void (*func)(gpointer data ,
                                                      gpointer user_data ) ,
                           gpointer user_data ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_sort)(GList *list ,
                                                                     gint (*compare_func)(gconstpointer a ,
                                                                                          gconstpointer b ) ) ;
extern GList *( __attribute__((__warn_unused_result__)) g_list_sort_with_data)(GList *list ,
                                                                               gint (*compare_func)(gconstpointer a ,
                                                                                                    gconstpointer b ,
                                                                                                    gpointer user_data ) ,
                                                                               gpointer user_data ) ;
extern gpointer g_list_nth_data(GList *list , guint n ) ;
extern void g_list_push_allocator(gpointer allocator ) ;
extern void g_list_pop_allocator(void) ;
extern GCache *g_cache_new(gpointer (*value_new_func)(gpointer key ) ,
                           void (*value_destroy_func)(gpointer value ) ,
                           gpointer (*key_dup_func)(gpointer value ) ,
                           void (*key_destroy_func)(gpointer value ) ,
                           guint (*hash_key_func)(gconstpointer key ) ,
                           guint (*hash_value_func)(gconstpointer key ) ,
                           gboolean (*key_equal_func)(gconstpointer a ,
                                                      gconstpointer b ) ) ;
extern void g_cache_destroy(GCache *cache ) ;
extern gpointer g_cache_insert(GCache *cache , gpointer key ) ;
extern void g_cache_remove(GCache *cache , gconstpointer value ) ;
extern void g_cache_key_foreach(GCache *cache ,
                                void (*func)(gpointer key , gpointer value ,
                                             gpointer user_data ) ,
                                gpointer user_data ) ;
extern void g_cache_value_foreach(GCache *cache ,
                                  void (*func)(gpointer key , gpointer value ,
                                               gpointer user_data ) ,
                                  gpointer user_data ) ;
extern gssize g_checksum_type_get_length(GChecksumType checksum_type ) ;
extern GChecksum *g_checksum_new(GChecksumType checksum_type ) ;
extern void g_checksum_reset(GChecksum *checksum ) ;
extern GChecksum *g_checksum_copy(GChecksum const   *checksum ) ;
extern void g_checksum_free(GChecksum *checksum ) ;
extern void g_checksum_update(GChecksum *checksum , guchar const   *data ,
                              gssize length ) ;
extern gchar const   *g_checksum_get_string(GChecksum *checksum ) ;
extern void g_checksum_get_digest(GChecksum *checksum , guint8 *buffer ,
                                  gsize *digest_len ) ;
extern gchar *g_compute_checksum_for_data(GChecksumType checksum_type ,
                                          guchar const   *data , gsize length ) ;
extern gchar *g_compute_checksum_for_string(GChecksumType checksum_type ,
                                            gchar const   *str , gssize length ) ;
extern GCompletion *g_completion_new(gchar *(*func)(gpointer  ) ) ;
extern void g_completion_add_items(GCompletion *cmp , GList *items ) ;
extern void g_completion_remove_items(GCompletion *cmp , GList *items ) ;
extern void g_completion_clear_items(GCompletion *cmp ) ;
extern GList *g_completion_complete(GCompletion *cmp , gchar const   *prefix ,
                                    gchar **new_prefix ) ;
extern GList *g_completion_complete_utf8(GCompletion *cmp ,
                                         gchar const   *prefix ,
                                         gchar **new_prefix ) ;
extern void g_completion_set_compare(GCompletion *cmp ,
                                     gint (*strncmp_func)(gchar const   *s1 ,
                                                          gchar const   *s2 ,
                                                          gsize n ) ) ;
extern void g_completion_free(GCompletion *cmp ) ;
extern GQuark g_convert_error_quark(void) ;
extern GIConv g_iconv_open(gchar const   *to_codeset ,
                           gchar const   *from_codeset ) ;
extern gsize g_iconv(GIConv converter , gchar **inbuf , gsize *inbytes_left ,
                     gchar **outbuf , gsize *outbytes_left ) ;
extern gint g_iconv_close(GIConv converter ) ;
extern gchar *g_convert(gchar const   *str , gssize len ,
                        gchar const   *to_codeset ,
                        gchar const   *from_codeset , gsize *bytes_read ,
                        gsize *bytes_written , GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_convert_with_iconv(gchar const   *str , gssize len ,
                                   GIConv converter , gsize *bytes_read ,
                                   gsize *bytes_written , GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_convert_with_fallback(gchar const   *str , gssize len ,
                                      gchar const   *to_codeset ,
                                      gchar const   *from_codeset ,
                                      gchar const   *fallback ,
                                      gsize *bytes_read , gsize *bytes_written ,
                                      GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_locale_to_utf8(gchar const   *opsysstring , gssize len ,
                               gsize *bytes_read , gsize *bytes_written ,
                               GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_locale_from_utf8(gchar const   *utf8string , gssize len ,
                                 gsize *bytes_read , gsize *bytes_written ,
                                 GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_filename_to_utf8(gchar const   *opsysstring , gssize len ,
                                 gsize *bytes_read , gsize *bytes_written ,
                                 GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_filename_from_utf8(gchar const   *utf8string , gssize len ,
                                   gsize *bytes_read , gsize *bytes_written ,
                                   GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_filename_from_uri(gchar const   *uri , gchar **hostname ,
                                  GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_filename_to_uri(gchar const   *filename ,
                                gchar const   *hostname , GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_filename_display_name(gchar const   *filename )  __attribute__((__malloc__)) ;
extern gboolean g_get_filename_charsets(gchar const   ***charsets ) ;
extern gchar *g_filename_display_basename(gchar const   *filename )  __attribute__((__malloc__)) ;
extern gchar **g_uri_list_extract_uris(gchar const   *uri_list )  __attribute__((__malloc__)) ;
extern void g_datalist_init(GData **datalist ) ;
extern void g_datalist_clear(GData **datalist ) ;
extern gpointer g_datalist_id_get_data(GData **datalist , GQuark key_id ) ;
extern void g_datalist_id_set_data_full(GData **datalist , GQuark key_id ,
                                        gpointer data ,
                                        void (*destroy_func)(gpointer data ) ) ;
extern gpointer g_datalist_id_remove_no_notify(GData **datalist , GQuark key_id ) ;
extern void g_datalist_foreach(GData **datalist ,
                               void (*func)(GQuark key_id , gpointer data ,
                                            gpointer user_data ) ,
                               gpointer user_data ) ;
extern void g_datalist_set_flags(GData **datalist , guint flags ) ;
extern void g_datalist_unset_flags(GData **datalist , guint flags ) ;
extern guint g_datalist_get_flags(GData **datalist ) ;
extern void g_dataset_destroy(gconstpointer dataset_location ) ;
extern gpointer g_dataset_id_get_data(gconstpointer dataset_location ,
                                      GQuark key_id ) ;
extern void g_dataset_id_set_data_full(gconstpointer dataset_location ,
                                       GQuark key_id , gpointer data ,
                                       void (*destroy_func)(gpointer data ) ) ;
extern gpointer g_dataset_id_remove_no_notify(gconstpointer dataset_location ,
                                              GQuark key_id ) ;
extern void g_dataset_foreach(gconstpointer dataset_location ,
                              void (*func)(GQuark key_id , gpointer data ,
                                           gpointer user_data ) ,
                              gpointer user_data ) ;
extern GDate *g_date_new(void) ;
extern GDate *g_date_new_dmy(GDateDay day , GDateMonth month , GDateYear year ) ;
extern GDate *g_date_new_julian(guint32 julian_day ) ;
extern void g_date_free(GDate *date ) ;
extern gboolean g_date_valid(GDate const   *date ) ;
extern gboolean g_date_valid_day(GDateDay day )  __attribute__((__const__)) ;
extern gboolean g_date_valid_month(GDateMonth month )  __attribute__((__const__)) ;
extern gboolean g_date_valid_year(GDateYear year )  __attribute__((__const__)) ;
extern gboolean g_date_valid_weekday(GDateWeekday weekday )  __attribute__((__const__)) ;
extern gboolean g_date_valid_julian(guint32 julian_date )  __attribute__((__const__)) ;
extern gboolean g_date_valid_dmy(GDateDay day , GDateMonth month ,
                                 GDateYear year )  __attribute__((__const__)) ;
extern GDateWeekday g_date_get_weekday(GDate const   *date ) ;
extern GDateMonth g_date_get_month(GDate const   *date ) ;
extern GDateYear g_date_get_year(GDate const   *date ) ;
extern GDateDay g_date_get_day(GDate const   *date ) ;
extern guint32 g_date_get_julian(GDate const   *date ) ;
extern guint g_date_get_day_of_year(GDate const   *date ) ;
extern guint g_date_get_monday_week_of_year(GDate const   *date ) ;
extern guint g_date_get_sunday_week_of_year(GDate const   *date ) ;
extern guint g_date_get_iso8601_week_of_year(GDate const   *date ) ;
extern void g_date_clear(GDate *date , guint n_dates ) ;
extern void g_date_set_parse(GDate *date , gchar const   *str ) ;
extern void g_date_set_time_t(GDate *date , time_t timet ) ;
extern void g_date_set_time_val(GDate *date , GTimeVal *timeval ) ;
extern void g_date_set_time(GDate *date , GTime time_ ) ;
extern void g_date_set_month(GDate *date , GDateMonth month ) ;
extern void g_date_set_day(GDate *date , GDateDay day ) ;
extern void g_date_set_year(GDate *date , GDateYear year ) ;
extern void g_date_set_dmy(GDate *date , GDateDay day , GDateMonth month ,
                           GDateYear y ) ;
extern void g_date_set_julian(GDate *date , guint32 julian_date ) ;
extern gboolean g_date_is_first_of_month(GDate const   *date ) ;
extern gboolean g_date_is_last_of_month(GDate const   *date ) ;
extern void g_date_add_days(GDate *date , guint n_days ) ;
extern void g_date_subtract_days(GDate *date , guint n_days ) ;
extern void g_date_add_months(GDate *date , guint n_months ) ;
extern void g_date_subtract_months(GDate *date , guint n_months ) ;
extern void g_date_add_years(GDate *date , guint n_years ) ;
extern void g_date_subtract_years(GDate *date , guint n_years ) ;
extern gboolean g_date_is_leap_year(GDateYear year )  __attribute__((__const__)) ;
extern guint8 g_date_get_days_in_month(GDateMonth month , GDateYear year )  __attribute__((__const__)) ;
extern guint8 g_date_get_monday_weeks_in_year(GDateYear year )  __attribute__((__const__)) ;
extern guint8 g_date_get_sunday_weeks_in_year(GDateYear year )  __attribute__((__const__)) ;
extern gint g_date_days_between(GDate const   *date1 , GDate const   *date2 ) ;
extern gint g_date_compare(GDate const   *lhs , GDate const   *rhs ) ;
extern void g_date_to_struct_tm(GDate const   *date , struct tm *tm ) ;
extern void g_date_clamp(GDate *date , GDate const   *min_date ,
                         GDate const   *max_date ) ;
extern void g_date_order(GDate *date1 , GDate *date2 ) ;
extern gsize g_date_strftime(gchar *s , gsize slen , gchar const   *format ,
                             GDate const   *date ) ;
extern GDir *g_dir_open(gchar const   *path , guint flags , GError **error ) ;
extern gchar const   *g_dir_read_name(GDir *dir ) ;
extern void g_dir_rewind(GDir *dir ) ;
extern void g_dir_close(GDir *dir ) ;
extern GQuark g_file_error_quark(void) ;
extern GFileError g_file_error_from_errno(gint err_no ) ;
extern gboolean g_file_test(gchar const   *filename , GFileTest test ) ;
extern gboolean g_file_get_contents(gchar const   *filename , gchar **contents ,
                                    gsize *length , GError **error ) ;
extern gboolean g_file_set_contents(gchar const   *filename ,
                                    gchar const   *contents , gssize length ,
                                    GError **error ) ;
extern gchar *g_file_read_link(gchar const   *filename , GError **error ) ;
extern gint g_mkstemp(gchar *tmpl ) ;
extern gint g_mkstemp_full(gchar *tmpl , int flags , int mode ) ;
extern gint g_file_open_tmp(gchar const   *tmpl , gchar **name_used ,
                            GError **error ) ;
extern char *g_format_size_for_display(goffset size ) ;
extern gchar *g_build_path(gchar const   *separator ,
                           gchar const   *first_element  , ...)  __attribute__((__sentinel__,
__malloc__)) ;
extern gchar *g_build_pathv(gchar const   *separator , gchar **args )  __attribute__((__malloc__)) ;
extern gchar *g_build_filename(gchar const   *first_element  , ...)  __attribute__((__sentinel__,
__malloc__)) ;
extern gchar *g_build_filenamev(gchar **args )  __attribute__((__malloc__)) ;
extern int g_mkdir_with_parents(gchar const   *pathname , int mode ) ;
extern GHashTable *g_hash_table_new(guint (*hash_func)(gconstpointer key ) ,
                                    gboolean (*key_equal_func)(gconstpointer a ,
                                                               gconstpointer b ) ) ;
extern GHashTable *g_hash_table_new_full(guint (*hash_func)(gconstpointer key ) ,
                                         gboolean (*key_equal_func)(gconstpointer a ,
                                                                    gconstpointer b ) ,
                                         void (*key_destroy_func)(gpointer data ) ,
                                         void (*value_destroy_func)(gpointer data ) ) ;
extern void g_hash_table_destroy(GHashTable *hash_table ) ;
extern void g_hash_table_insert(GHashTable *hash_table , gpointer key ,
                                gpointer value ) ;
extern void g_hash_table_replace(GHashTable *hash_table , gpointer key ,
                                 gpointer value ) ;
extern gboolean g_hash_table_remove(GHashTable *hash_table , gconstpointer key ) ;
extern void g_hash_table_remove_all(GHashTable *hash_table ) ;
extern gboolean g_hash_table_steal(GHashTable *hash_table , gconstpointer key ) ;
extern void g_hash_table_steal_all(GHashTable *hash_table ) ;
extern gpointer g_hash_table_lookup(GHashTable *hash_table , gconstpointer key ) ;
extern gboolean g_hash_table_lookup_extended(GHashTable *hash_table ,
                                             gconstpointer lookup_key ,
                                             gpointer *orig_key ,
                                             gpointer *value ) ;
extern void g_hash_table_foreach(GHashTable *hash_table ,
                                 void (*func)(gpointer key , gpointer value ,
                                              gpointer user_data ) ,
                                 gpointer user_data ) ;
extern gpointer g_hash_table_find(GHashTable *hash_table ,
                                  gboolean (*predicate)(gpointer key ,
                                                        gpointer value ,
                                                        gpointer user_data ) ,
                                  gpointer user_data ) ;
extern guint g_hash_table_foreach_remove(GHashTable *hash_table ,
                                         gboolean (*func)(gpointer key ,
                                                          gpointer value ,
                                                          gpointer user_data ) ,
                                         gpointer user_data ) ;
extern guint g_hash_table_foreach_steal(GHashTable *hash_table ,
                                        gboolean (*func)(gpointer key ,
                                                         gpointer value ,
                                                         gpointer user_data ) ,
                                        gpointer user_data ) ;
extern guint g_hash_table_size(GHashTable *hash_table ) ;
extern GList *g_hash_table_get_keys(GHashTable *hash_table ) ;
extern GList *g_hash_table_get_values(GHashTable *hash_table ) ;
extern void g_hash_table_iter_init(GHashTableIter *iter ,
                                   GHashTable *hash_table ) ;
extern gboolean g_hash_table_iter_next(GHashTableIter *iter , gpointer *key ,
                                       gpointer *value ) ;
extern GHashTable *g_hash_table_iter_get_hash_table(GHashTableIter *iter ) ;
extern void g_hash_table_iter_remove(GHashTableIter *iter ) ;
extern void g_hash_table_iter_steal(GHashTableIter *iter ) ;
extern GHashTable *g_hash_table_ref(GHashTable *hash_table ) ;
extern void g_hash_table_unref(GHashTable *hash_table ) ;
extern gboolean g_str_equal(gconstpointer v1 , gconstpointer v2 ) ;
extern guint g_str_hash(gconstpointer v ) ;
extern gboolean g_int_equal(gconstpointer v1 , gconstpointer v2 ) ;
extern guint g_int_hash(gconstpointer v ) ;
extern gboolean g_int64_equal(gconstpointer v1 , gconstpointer v2 ) ;
extern guint g_int64_hash(gconstpointer v ) ;
extern gboolean g_double_equal(gconstpointer v1 , gconstpointer v2 ) ;
extern guint g_double_hash(gconstpointer v ) ;
extern guint g_direct_hash(gconstpointer v )  __attribute__((__const__)) ;
extern gboolean g_direct_equal(gconstpointer v1 , gconstpointer v2 )  __attribute__((__const__)) ;
extern void g_hook_list_init(GHookList *hook_list , guint hook_size ) ;
extern void g_hook_list_clear(GHookList *hook_list ) ;
extern GHook *g_hook_alloc(GHookList *hook_list ) ;
extern void g_hook_free(GHookList *hook_list , GHook *hook ) ;
extern GHook *g_hook_ref(GHookList *hook_list , GHook *hook ) ;
extern void g_hook_unref(GHookList *hook_list , GHook *hook ) ;
extern gboolean g_hook_destroy(GHookList *hook_list , gulong hook_id ) ;
extern void g_hook_destroy_link(GHookList *hook_list , GHook *hook ) ;
extern void g_hook_prepend(GHookList *hook_list , GHook *hook ) ;
extern void g_hook_insert_before(GHookList *hook_list , GHook *sibling ,
                                 GHook *hook ) ;
extern void g_hook_insert_sorted(GHookList *hook_list , GHook *hook ,
                                 gint (*func)(GHook *new_hook , GHook *sibling ) ) ;
extern GHook *g_hook_get(GHookList *hook_list , gulong hook_id ) ;
extern GHook *g_hook_find(GHookList *hook_list , gboolean need_valids ,
                          gboolean (*func)(GHook *hook , gpointer data ) ,
                          gpointer data ) ;
extern GHook *g_hook_find_data(GHookList *hook_list , gboolean need_valids ,
                               gpointer data ) ;
extern GHook *g_hook_find_func(GHookList *hook_list , gboolean need_valids ,
                               gpointer func ) ;
extern GHook *g_hook_find_func_data(GHookList *hook_list ,
                                    gboolean need_valids , gpointer func ,
                                    gpointer data ) ;
extern GHook *g_hook_first_valid(GHookList *hook_list , gboolean may_be_in_call ) ;
extern GHook *g_hook_next_valid(GHookList *hook_list , GHook *hook ,
                                gboolean may_be_in_call ) ;
extern gint g_hook_compare_ids(GHook *new_hook , GHook *sibling ) ;
extern void g_hook_list_invoke(GHookList *hook_list , gboolean may_recurse ) ;
extern void g_hook_list_invoke_check(GHookList *hook_list ,
                                     gboolean may_recurse ) ;
extern void g_hook_list_marshal(GHookList *hook_list , gboolean may_recurse ,
                                void (*marshaller)(GHook *hook ,
                                                   gpointer marshal_data ) ,
                                gpointer marshal_data ) ;
extern void g_hook_list_marshal_check(GHookList *hook_list ,
                                      gboolean may_recurse ,
                                      gboolean (*marshaller)(GHook *hook ,
                                                             gpointer marshal_data ) ,
                                      gpointer marshal_data ) ;
extern gboolean g_hostname_is_non_ascii(gchar const   *hostname ) ;
extern gboolean g_hostname_is_ascii_encoded(gchar const   *hostname ) ;
extern gboolean g_hostname_is_ip_address(gchar const   *hostname ) ;
extern gchar *g_hostname_to_ascii(gchar const   *hostname ) ;
extern gchar *g_hostname_to_unicode(gchar const   *hostname ) ;
extern gint g_poll(GPollFD *fds , guint nfds , gint timeout ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_alloc)(void) ;
extern void g_slist_free(GSList *list ) ;
extern void g_slist_free_1(GSList *list ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_append)(GSList *list ,
                                                                         gpointer data ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_prepend)(GSList *list ,
                                                                          gpointer data ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_insert)(GSList *list ,
                                                                         gpointer data ,
                                                                         gint position ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_insert_sorted)(GSList *list ,
                                                                                gpointer data ,
                                                                                gint (*func)(gconstpointer a ,
                                                                                             gconstpointer b ) ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_insert_sorted_with_data)(GSList *list ,
                                                                                          gpointer data ,
                                                                                          gint (*func)(gconstpointer a ,
                                                                                                       gconstpointer b ,
                                                                                                       gpointer user_data ) ,
                                                                                          gpointer user_data ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_insert_before)(GSList *slist ,
                                                                                GSList *sibling ,
                                                                                gpointer data ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_concat)(GSList *list1 ,
                                                                         GSList *list2 ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_remove)(GSList *list ,
                                                                         gconstpointer data ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_remove_all)(GSList *list ,
                                                                             gconstpointer data ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_remove_link)(GSList *list ,
                                                                              GSList *link_ ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_delete_link)(GSList *list ,
                                                                              GSList *link_ ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_reverse)(GSList *list ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_copy)(GSList *list ) ;
extern GSList *g_slist_nth(GSList *list , guint n ) ;
extern GSList *g_slist_find(GSList *list , gconstpointer data ) ;
extern GSList *g_slist_find_custom(GSList *list , gconstpointer data ,
                                   gint (*func)(gconstpointer a ,
                                                gconstpointer b ) ) ;
extern gint g_slist_position(GSList *list , GSList *llink ) ;
extern gint g_slist_index(GSList *list , gconstpointer data ) ;
extern GSList *g_slist_last(GSList *list ) ;
extern guint g_slist_length(GSList *list ) ;
extern void g_slist_foreach(GSList *list , void (*func)(gpointer data ,
                                                        gpointer user_data ) ,
                            gpointer user_data ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_sort)(GSList *list ,
                                                                       gint (*compare_func)(gconstpointer a ,
                                                                                            gconstpointer b ) ) ;
extern GSList *( __attribute__((__warn_unused_result__)) g_slist_sort_with_data)(GSList *list ,
                                                                                 gint (*compare_func)(gconstpointer a ,
                                                                                                      gconstpointer b ,
                                                                                                      gpointer user_data ) ,
                                                                                 gpointer user_data ) ;
extern gpointer g_slist_nth_data(GSList *list , guint n ) ;
extern void g_slist_push_allocator(gpointer dummy ) ;
extern void g_slist_pop_allocator(void) ;
extern GMainContext *g_main_context_new(void) ;
extern GMainContext *g_main_context_ref(GMainContext *context ) ;
extern void g_main_context_unref(GMainContext *context ) ;
extern GMainContext *g_main_context_default(void) ;
extern gboolean g_main_context_iteration(GMainContext *context ,
                                         gboolean may_block ) ;
extern gboolean g_main_context_pending(GMainContext *context ) ;
extern GSource *g_main_context_find_source_by_id(GMainContext *context ,
                                                 guint source_id ) ;
extern GSource *g_main_context_find_source_by_user_data(GMainContext *context ,
                                                        gpointer user_data ) ;
extern GSource *g_main_context_find_source_by_funcs_user_data(GMainContext *context ,
                                                              GSourceFuncs *funcs ,
                                                              gpointer user_data ) ;
extern void g_main_context_wakeup(GMainContext *context ) ;
extern gboolean g_main_context_acquire(GMainContext *context ) ;
extern void g_main_context_release(GMainContext *context ) ;
extern gboolean g_main_context_is_owner(GMainContext *context ) ;
extern gboolean g_main_context_wait(GMainContext *context , GCond *cond ,
                                    GMutex *mutex ) ;
extern gboolean g_main_context_prepare(GMainContext *context , gint *priority ) ;
extern gint g_main_context_query(GMainContext *context , gint max_priority ,
                                 gint *timeout_ , GPollFD *fds , gint n_fds ) ;
extern gint g_main_context_check(GMainContext *context , gint max_priority ,
                                 GPollFD *fds , gint n_fds ) ;
extern void g_main_context_dispatch(GMainContext *context ) ;
extern void g_main_context_set_poll_func(GMainContext *context ,
                                         gint (*func)(GPollFD *ufds ,
                                                      guint nfsd ,
                                                      gint timeout_ ) ) ;
extern GPollFunc g_main_context_get_poll_func(GMainContext *context ) ;
extern void g_main_context_add_poll(GMainContext *context , GPollFD *fd ,
                                    gint priority ) ;
extern void g_main_context_remove_poll(GMainContext *context , GPollFD *fd ) ;
extern gint g_main_depth(void) ;
extern GSource *g_main_current_source(void) ;
extern void g_main_context_push_thread_default(GMainContext *context ) ;
extern void g_main_context_pop_thread_default(GMainContext *context ) ;
extern GMainContext *g_main_context_get_thread_default(void) ;
extern GMainLoop *g_main_loop_new(GMainContext *context , gboolean is_running ) ;
extern void g_main_loop_run(GMainLoop *loop ) ;
extern void g_main_loop_quit(GMainLoop *loop ) ;
extern GMainLoop *g_main_loop_ref(GMainLoop *loop ) ;
extern void g_main_loop_unref(GMainLoop *loop ) ;
extern gboolean g_main_loop_is_running(GMainLoop *loop ) ;
extern GMainContext *g_main_loop_get_context(GMainLoop *loop ) ;
extern GSource *g_source_new(GSourceFuncs *source_funcs , guint struct_size ) ;
extern GSource *g_source_ref(GSource *source ) ;
extern void g_source_unref(GSource *source ) ;
extern guint g_source_attach(GSource *source , GMainContext *context ) ;
extern void g_source_destroy(GSource *source ) ;
extern void g_source_set_priority(GSource *source , gint priority ) ;
extern gint g_source_get_priority(GSource *source ) ;
extern void g_source_set_can_recurse(GSource *source , gboolean can_recurse ) ;
extern gboolean g_source_get_can_recurse(GSource *source ) ;
extern guint g_source_get_id(GSource *source ) ;
extern GMainContext *g_source_get_context(GSource *source ) ;
extern void g_source_set_callback(GSource *source ,
                                  gboolean (*func)(gpointer data ) ,
                                  gpointer data ,
                                  void (*notify)(gpointer data ) ) ;
extern void g_source_set_funcs(GSource *source , GSourceFuncs *funcs ) ;
extern gboolean g_source_is_destroyed(GSource *source ) ;
extern void g_source_set_callback_indirect(GSource *source ,
                                           gpointer callback_data ,
                                           GSourceCallbackFuncs *callback_funcs ) ;
extern void g_source_add_poll(GSource *source , GPollFD *fd ) ;
extern void g_source_remove_poll(GSource *source , GPollFD *fd ) ;
extern void g_source_get_current_time(GSource *source , GTimeVal *timeval ) ;
extern GSource *g_idle_source_new(void) ;
extern GSource *g_child_watch_source_new(GPid pid ) ;
extern GSource *g_timeout_source_new(guint interval ) ;
extern GSource *g_timeout_source_new_seconds(guint interval ) ;
extern void g_get_current_time(GTimeVal *result ) ;
extern gboolean g_source_remove(guint tag ) ;
extern gboolean g_source_remove_by_user_data(gpointer user_data ) ;
extern gboolean g_source_remove_by_funcs_user_data(GSourceFuncs *funcs ,
                                                   gpointer user_data ) ;
extern guint g_timeout_add_full(gint priority , guint interval ,
                                gboolean (*function)(gpointer data ) ,
                                gpointer data , void (*notify)(gpointer data ) ) ;
extern guint g_timeout_add(guint interval ,
                           gboolean (*function)(gpointer data ) , gpointer data ) ;
extern guint g_timeout_add_seconds_full(gint priority , guint interval ,
                                        gboolean (*function)(gpointer data ) ,
                                        gpointer data ,
                                        void (*notify)(gpointer data ) ) ;
extern guint g_timeout_add_seconds(guint interval ,
                                   gboolean (*function)(gpointer data ) ,
                                   gpointer data ) ;
extern guint g_child_watch_add_full(gint priority , GPid pid ,
                                    void (*function)(GPid pid , gint status ,
                                                     gpointer data ) ,
                                    gpointer data ,
                                    void (*notify)(gpointer data ) ) ;
extern guint g_child_watch_add(GPid pid , void (*function)(GPid pid ,
                                                           gint status ,
                                                           gpointer data ) ,
                               gpointer data ) ;
extern guint g_idle_add(gboolean (*function)(gpointer data ) , gpointer data ) ;
extern guint g_idle_add_full(gint priority ,
                             gboolean (*function)(gpointer data ) ,
                             gpointer data , void (*notify)(gpointer data ) ) ;
extern gboolean g_idle_remove_by_data(gpointer data ) ;
extern GSourceFuncs g_timeout_funcs ;
extern GSourceFuncs g_child_watch_funcs ;
extern GSourceFuncs g_idle_funcs ;
extern gboolean g_get_charset(char const   **charset ) ;
extern gboolean g_unichar_isalnum(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isalpha(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_iscntrl(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isdigit(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isgraph(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_islower(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isprint(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_ispunct(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isspace(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isupper(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isxdigit(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_istitle(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_isdefined(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_iswide(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_iswide_cjk(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_iszerowidth(gunichar c )  __attribute__((__const__)) ;
extern gboolean g_unichar_ismark(gunichar c )  __attribute__((__const__)) ;
extern gunichar g_unichar_toupper(gunichar c )  __attribute__((__const__)) ;
extern gunichar g_unichar_tolower(gunichar c )  __attribute__((__const__)) ;
extern gunichar g_unichar_totitle(gunichar c )  __attribute__((__const__)) ;
extern gint g_unichar_digit_value(gunichar c )  __attribute__((__const__)) ;
extern gint g_unichar_xdigit_value(gunichar c )  __attribute__((__const__)) ;
extern GUnicodeType g_unichar_type(gunichar c )  __attribute__((__const__)) ;
extern GUnicodeBreakType g_unichar_break_type(gunichar c )  __attribute__((__const__)) ;
extern gint g_unichar_combining_class(gunichar uc )  __attribute__((__const__)) ;
extern void g_unicode_canonical_ordering(gunichar *string , gsize len ) ;
extern gunichar *g_unicode_canonical_decomposition(gunichar ch ,
                                                   gsize *result_len )  __attribute__((__malloc__)) ;
extern gchar const   * const  g_utf8_skip ;
extern gunichar g_utf8_get_char(gchar const   *p )  __attribute__((__pure__)) ;
extern gunichar g_utf8_get_char_validated(gchar const   *p , gssize max_len )  __attribute__((__pure__)) ;
extern gchar *g_utf8_offset_to_pointer(gchar const   *str , glong offset )  __attribute__((__pure__)) ;
extern glong g_utf8_pointer_to_offset(gchar const   *str , gchar const   *pos )  __attribute__((__pure__)) ;
extern gchar *g_utf8_prev_char(gchar const   *p )  __attribute__((__pure__)) ;
extern gchar *g_utf8_find_next_char(gchar const   *p , gchar const   *end )  __attribute__((__pure__)) ;
extern gchar *g_utf8_find_prev_char(gchar const   *str , gchar const   *p )  __attribute__((__pure__)) ;
extern glong g_utf8_strlen(gchar const   *p , gssize max )  __attribute__((__pure__)) ;
extern gchar *g_utf8_strncpy(gchar *dest , gchar const   *src , gsize n ) ;
extern gchar *g_utf8_strchr(gchar const   *p , gssize len , gunichar c ) ;
extern gchar *g_utf8_strrchr(gchar const   *p , gssize len , gunichar c ) ;
extern gchar *g_utf8_strreverse(gchar const   *str , gssize len ) ;
extern gunichar2 *g_utf8_to_utf16(gchar const   *str , glong len ,
                                  glong *items_read , glong *items_written ,
                                  GError **error )  __attribute__((__malloc__)) ;
extern gunichar *g_utf8_to_ucs4(gchar const   *str , glong len ,
                                glong *items_read , glong *items_written ,
                                GError **error )  __attribute__((__malloc__)) ;
extern gunichar *g_utf8_to_ucs4_fast(gchar const   *str , glong len ,
                                     glong *items_written )  __attribute__((__malloc__)) ;
extern gunichar *g_utf16_to_ucs4(gunichar2 const   *str , glong len ,
                                 glong *items_read , glong *items_written ,
                                 GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_utf16_to_utf8(gunichar2 const   *str , glong len ,
                              glong *items_read , glong *items_written ,
                              GError **error )  __attribute__((__malloc__)) ;
extern gunichar2 *g_ucs4_to_utf16(gunichar const   *str , glong len ,
                                  glong *items_read , glong *items_written ,
                                  GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_ucs4_to_utf8(gunichar const   *str , glong len ,
                             glong *items_read , glong *items_written ,
                             GError **error )  __attribute__((__malloc__)) ;
extern gint g_unichar_to_utf8(gunichar c , gchar *outbuf ) ;
extern gboolean g_utf8_validate(gchar const   *str , gssize max_len ,
                                gchar const   **end ) ;
extern gboolean g_unichar_validate(gunichar ch )  __attribute__((__const__)) ;
extern gchar *g_utf8_strup(gchar const   *str , gssize len )  __attribute__((__malloc__)) ;
extern gchar *g_utf8_strdown(gchar const   *str , gssize len )  __attribute__((__malloc__)) ;
extern gchar *g_utf8_casefold(gchar const   *str , gssize len )  __attribute__((__malloc__)) ;
extern gchar *g_utf8_normalize(gchar const   *str , gssize len ,
                               GNormalizeMode mode )  __attribute__((__malloc__)) ;
extern gint g_utf8_collate(gchar const   *str1 , gchar const   *str2 )  __attribute__((__pure__)) ;
extern gchar *g_utf8_collate_key(gchar const   *str , gssize len )  __attribute__((__malloc__)) ;
extern gchar *g_utf8_collate_key_for_filename(gchar const   *str , gssize len )  __attribute__((__malloc__)) ;
extern gboolean g_unichar_get_mirror_char(gunichar ch , gunichar *mirrored_ch ) ;
extern GUnicodeScript g_unichar_get_script(gunichar ch )  __attribute__((__const__)) ;
extern gchar *_g_utf8_make_valid(gchar const   *name ) ;
extern GStringChunk *g_string_chunk_new(gsize size ) ;
extern void g_string_chunk_free(GStringChunk *chunk ) ;
extern void g_string_chunk_clear(GStringChunk *chunk ) ;
extern gchar *g_string_chunk_insert(GStringChunk *chunk , gchar const   *string ) ;
extern gchar *g_string_chunk_insert_len(GStringChunk *chunk ,
                                        gchar const   *string , gssize len ) ;
extern gchar *g_string_chunk_insert_const(GStringChunk *chunk ,
                                          gchar const   *string ) ;
extern GString *g_string_new(gchar const   *init ) ;
extern GString *g_string_new_len(gchar const   *init , gssize len ) ;
extern GString *g_string_sized_new(gsize dfl_size ) ;
extern gchar *g_string_free(GString *string , gboolean free_segment ) ;
extern gboolean g_string_equal(GString const   *v , GString const   *v2 ) ;
extern guint g_string_hash(GString const   *str ) ;
extern GString *g_string_assign(GString *string , gchar const   *rval ) ;
extern GString *g_string_truncate(GString *string , gsize len ) ;
extern GString *g_string_set_size(GString *string , gsize len ) ;
extern GString *g_string_insert_len(GString *string , gssize pos ,
                                    gchar const   *val , gssize len ) ;
extern GString *g_string_append(GString *string , gchar const   *val ) ;
extern GString *g_string_append_len(GString *string , gchar const   *val ,
                                    gssize len ) ;
extern GString *g_string_append_c(GString *string , gchar c ) ;
extern GString *g_string_append_unichar(GString *string , gunichar wc ) ;
extern GString *g_string_prepend(GString *string , gchar const   *val ) ;
extern GString *g_string_prepend_c(GString *string , gchar c ) ;
extern GString *g_string_prepend_unichar(GString *string , gunichar wc ) ;
extern GString *g_string_prepend_len(GString *string , gchar const   *val ,
                                     gssize len ) ;
extern GString *g_string_insert(GString *string , gssize pos ,
                                gchar const   *val ) ;
extern GString *g_string_insert_c(GString *string , gssize pos , gchar c ) ;
extern GString *g_string_insert_unichar(GString *string , gssize pos ,
                                        gunichar wc ) ;
extern GString *g_string_overwrite(GString *string , gsize pos ,
                                   gchar const   *val ) ;
extern GString *g_string_overwrite_len(GString *string , gsize pos ,
                                       gchar const   *val , gssize len ) ;
extern GString *g_string_erase(GString *string , gssize pos , gssize len ) ;
extern GString *g_string_ascii_down(GString *string ) ;
extern GString *g_string_ascii_up(GString *string ) ;
extern void g_string_vprintf(GString *string , gchar const   *format ,
                             va_list args ) ;
extern void ( /* format attribute */  g_string_printf)(GString *string ,
                                                       gchar const   *format 
                                                       , ...) ;
extern void g_string_append_vprintf(GString *string , gchar const   *format ,
                                    va_list args ) ;
extern void ( /* format attribute */  g_string_append_printf)(GString *string ,
                                                              gchar const   *format 
                                                              , ...) ;
extern GString *g_string_append_uri_escaped(GString *string ,
                                            char const   *unescaped ,
                                            char const   *reserved_chars_allowed ,
                                            gboolean allow_utf8 ) ;
__inline static GString *g_string_append_c_inline(GString *gstring , gchar c ) 
{ 
  gsize tmp ;

  {

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "265", "1",
                  checkpoints_buf);

  if (gstring->len + 1U < gstring->allocated_len) {
    tmp = gstring->len;

    (gstring->len) ++;

    *(gstring->str + tmp) = c;

    *(gstring->str + gstring->len) = (gchar )0;

  } else {

    g_string_insert_c(gstring, -1, c);

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "265", "1",
                  checkpoints_buf);


  return (gstring);
}
}
extern GString *g_string_down(GString *string ) ;
extern GString *g_string_up(GString *string ) ;
extern void g_io_channel_init(GIOChannel *channel ) ;
extern GIOChannel *g_io_channel_ref(GIOChannel *channel ) ;
extern void g_io_channel_unref(GIOChannel *channel ) ;
extern GIOError g_io_channel_read(GIOChannel *channel , gchar *buf ,
                                  gsize count , gsize *bytes_read ) ;
extern GIOError g_io_channel_write(GIOChannel *channel , gchar const   *buf ,
                                   gsize count , gsize *bytes_written ) ;
extern GIOError g_io_channel_seek(GIOChannel *channel , gint64 offset ,
                                  GSeekType type ) ;
extern void g_io_channel_close(GIOChannel *channel ) ;
extern GIOStatus g_io_channel_shutdown(GIOChannel *channel , gboolean flush ,
                                       GError **err ) ;
extern guint g_io_add_watch_full(GIOChannel *channel , gint priority ,
                                 GIOCondition condition ,
                                 gboolean (*func)(GIOChannel *source ,
                                                  GIOCondition condition ,
                                                  gpointer data ) ,
                                 gpointer user_data ,
                                 void (*notify)(gpointer data ) ) ;
extern GSource *g_io_create_watch(GIOChannel *channel , GIOCondition condition ) ;
extern guint g_io_add_watch(GIOChannel *channel , GIOCondition condition ,
                            gboolean (*func)(GIOChannel *source ,
                                             GIOCondition condition ,
                                             gpointer data ) ,
                            gpointer user_data ) ;
extern void g_io_channel_set_buffer_size(GIOChannel *channel , gsize size ) ;
extern gsize g_io_channel_get_buffer_size(GIOChannel *channel ) ;
extern GIOCondition g_io_channel_get_buffer_condition(GIOChannel *channel ) ;
extern GIOStatus g_io_channel_set_flags(GIOChannel *channel , GIOFlags flags ,
                                        GError **error ) ;
extern GIOFlags g_io_channel_get_flags(GIOChannel *channel ) ;
extern void g_io_channel_set_line_term(GIOChannel *channel ,
                                       gchar const   *line_term , gint length ) ;
extern gchar const   *g_io_channel_get_line_term(GIOChannel *channel ,
                                                 gint *length ) ;
extern void g_io_channel_set_buffered(GIOChannel *channel , gboolean buffered ) ;
extern gboolean g_io_channel_get_buffered(GIOChannel *channel ) ;
extern GIOStatus g_io_channel_set_encoding(GIOChannel *channel ,
                                           gchar const   *encoding ,
                                           GError **error ) ;
extern gchar const   *g_io_channel_get_encoding(GIOChannel *channel ) ;
extern void g_io_channel_set_close_on_unref(GIOChannel *channel ,
                                            gboolean do_close ) ;
extern gboolean g_io_channel_get_close_on_unref(GIOChannel *channel ) ;
extern GIOStatus g_io_channel_flush(GIOChannel *channel , GError **error ) ;
extern GIOStatus g_io_channel_read_line(GIOChannel *channel ,
                                        gchar **str_return , gsize *length ,
                                        gsize *terminator_pos , GError **error ) ;
extern GIOStatus g_io_channel_read_line_string(GIOChannel *channel ,
                                               GString *buffer ,
                                               gsize *terminator_pos ,
                                               GError **error ) ;
extern GIOStatus g_io_channel_read_to_end(GIOChannel *channel ,
                                          gchar **str_return , gsize *length ,
                                          GError **error ) ;
extern GIOStatus g_io_channel_read_chars(GIOChannel *channel , gchar *buf ,
                                         gsize count , gsize *bytes_read ,
                                         GError **error ) ;
extern GIOStatus g_io_channel_read_unichar(GIOChannel *channel ,
                                           gunichar *thechar , GError **error ) ;
extern GIOStatus g_io_channel_write_chars(GIOChannel *channel ,
                                          gchar const   *buf , gssize count ,
                                          gsize *bytes_written , GError **error ) ;
extern GIOStatus g_io_channel_write_unichar(GIOChannel *channel ,
                                            gunichar thechar , GError **error ) ;
extern GIOStatus g_io_channel_seek_position(GIOChannel *channel ,
                                            gint64 offset , GSeekType type ,
                                            GError **error ) ;
extern GIOChannel *g_io_channel_new_file(gchar const   *filename ,
                                         gchar const   *mode , GError **error ) ;
extern GQuark g_io_channel_error_quark(void) ;
extern GIOChannelError g_io_channel_error_from_errno(gint en ) ;
extern GIOChannel *g_io_channel_unix_new(int fd ) ;
extern gint g_io_channel_unix_get_fd(GIOChannel *channel ) ;
extern GSourceFuncs g_io_watch_funcs ;
extern GQuark g_key_file_error_quark(void) ;
extern GKeyFile *g_key_file_new(void) ;
extern void g_key_file_free(GKeyFile *key_file ) ;
extern void g_key_file_set_list_separator(GKeyFile *key_file , gchar separator ) ;
extern gboolean g_key_file_load_from_file(GKeyFile *key_file ,
                                          gchar const   *file ,
                                          GKeyFileFlags flags , GError **error ) ;
extern gboolean g_key_file_load_from_data(GKeyFile *key_file ,
                                          gchar const   *data , gsize length ,
                                          GKeyFileFlags flags , GError **error ) ;
extern gboolean g_key_file_load_from_dirs(GKeyFile *key_file ,
                                          gchar const   *file ,
                                          gchar const   **search_dirs ,
                                          gchar **full_path ,
                                          GKeyFileFlags flags , GError **error ) ;
extern gboolean g_key_file_load_from_data_dirs(GKeyFile *key_file ,
                                               gchar const   *file ,
                                               gchar **full_path ,
                                               GKeyFileFlags flags ,
                                               GError **error ) ;
extern gchar *g_key_file_to_data(GKeyFile *key_file , gsize *length ,
                                 GError **error )  __attribute__((__malloc__)) ;
extern gchar *g_key_file_get_start_group(GKeyFile *key_file )  __attribute__((__malloc__)) ;
extern gchar **g_key_file_get_groups(GKeyFile *key_file , gsize *length )  __attribute__((__malloc__)) ;
extern gchar **g_key_file_get_keys(GKeyFile *key_file ,
                                   gchar const   *group_name , gsize *length ,
                                   GError **error )  __attribute__((__malloc__)) ;
extern gboolean g_key_file_has_group(GKeyFile *key_file ,
                                     gchar const   *group_name ) ;
extern gboolean g_key_file_has_key(GKeyFile *key_file ,
                                   gchar const   *group_name ,
                                   gchar const   *key , GError **error ) ;
extern gchar *g_key_file_get_value(GKeyFile *key_file ,
                                   gchar const   *group_name ,
                                   gchar const   *key , GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_value(GKeyFile *key_file ,
                                 gchar const   *group_name ,
                                 gchar const   *key , gchar const   *value ) ;
extern gchar *g_key_file_get_string(GKeyFile *key_file ,
                                    gchar const   *group_name ,
                                    gchar const   *key , GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_string(GKeyFile *key_file ,
                                  gchar const   *group_name ,
                                  gchar const   *key , gchar const   *string ) ;
extern gchar *g_key_file_get_locale_string(GKeyFile *key_file ,
                                           gchar const   *group_name ,
                                           gchar const   *key ,
                                           gchar const   *locale ,
                                           GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_locale_string(GKeyFile *key_file ,
                                         gchar const   *group_name ,
                                         gchar const   *key ,
                                         gchar const   *locale ,
                                         gchar const   *string ) ;
extern gboolean g_key_file_get_boolean(GKeyFile *key_file ,
                                       gchar const   *group_name ,
                                       gchar const   *key , GError **error ) ;
extern void g_key_file_set_boolean(GKeyFile *key_file ,
                                   gchar const   *group_name ,
                                   gchar const   *key , gboolean value ) ;
extern gint g_key_file_get_integer(GKeyFile *key_file ,
                                   gchar const   *group_name ,
                                   gchar const   *key , GError **error ) ;
extern void g_key_file_set_integer(GKeyFile *key_file ,
                                   gchar const   *group_name ,
                                   gchar const   *key , gint value ) ;
extern gdouble g_key_file_get_double(GKeyFile *key_file ,
                                     gchar const   *group_name ,
                                     gchar const   *key , GError **error ) ;
extern void g_key_file_set_double(GKeyFile *key_file ,
                                  gchar const   *group_name ,
                                  gchar const   *key , gdouble value ) ;
extern gchar **g_key_file_get_string_list(GKeyFile *key_file ,
                                          gchar const   *group_name ,
                                          gchar const   *key , gsize *length ,
                                          GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_string_list(GKeyFile *key_file ,
                                       gchar const   *group_name ,
                                       gchar const   *key ,
                                       gchar const   * const  *list ,
                                       gsize length ) ;
extern gchar **g_key_file_get_locale_string_list(GKeyFile *key_file ,
                                                 gchar const   *group_name ,
                                                 gchar const   *key ,
                                                 gchar const   *locale ,
                                                 gsize *length , GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_locale_string_list(GKeyFile *key_file ,
                                              gchar const   *group_name ,
                                              gchar const   *key ,
                                              gchar const   *locale ,
                                              gchar const   * const  *list ,
                                              gsize length ) ;
extern gboolean *g_key_file_get_boolean_list(GKeyFile *key_file ,
                                             gchar const   *group_name ,
                                             gchar const   *key ,
                                             gsize *length , GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_boolean_list(GKeyFile *key_file ,
                                        gchar const   *group_name ,
                                        gchar const   *key , gboolean *list ,
                                        gsize length ) ;
extern gint *g_key_file_get_integer_list(GKeyFile *key_file ,
                                         gchar const   *group_name ,
                                         gchar const   *key , gsize *length ,
                                         GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_double_list(GKeyFile *key_file ,
                                       gchar const   *group_name ,
                                       gchar const   *key , gdouble *list ,
                                       gsize length ) ;
extern gdouble *g_key_file_get_double_list(GKeyFile *key_file ,
                                           gchar const   *group_name ,
                                           gchar const   *key , gsize *length ,
                                           GError **error )  __attribute__((__malloc__)) ;
extern void g_key_file_set_integer_list(GKeyFile *key_file ,
                                        gchar const   *group_name ,
                                        gchar const   *key , gint *list ,
                                        gsize length ) ;
extern gboolean g_key_file_set_comment(GKeyFile *key_file ,
                                       gchar const   *group_name ,
                                       gchar const   *key ,
                                       gchar const   *comment , GError **error ) ;
extern gchar *g_key_file_get_comment(GKeyFile *key_file ,
                                     gchar const   *group_name ,
                                     gchar const   *key , GError **error )  __attribute__((__malloc__)) ;
extern gboolean g_key_file_remove_comment(GKeyFile *key_file ,
                                          gchar const   *group_name ,
                                          gchar const   *key , GError **error ) ;
extern gboolean g_key_file_remove_key(GKeyFile *key_file ,
                                      gchar const   *group_name ,
                                      gchar const   *key , GError **error ) ;
extern gboolean g_key_file_remove_group(GKeyFile *key_file ,
                                        gchar const   *group_name ,
                                        GError **error ) ;
extern GMappedFile *g_mapped_file_new(gchar const   *filename ,
                                      gboolean writable , GError **error )  __attribute__((__malloc__)) ;
extern gsize g_mapped_file_get_length(GMappedFile *file ) ;
extern gchar *g_mapped_file_get_contents(GMappedFile *file ) ;
extern GMappedFile *g_mapped_file_ref(GMappedFile *file ) ;
extern void g_mapped_file_unref(GMappedFile *file ) ;
extern void g_mapped_file_free(GMappedFile *file ) ;
extern GQuark g_markup_error_quark(void) ;
extern GMarkupParseContext *g_markup_parse_context_new(GMarkupParser const   *parser ,
                                                       GMarkupParseFlags flags ,
                                                       gpointer user_data ,
                                                       void (*user_data_dnotify)(gpointer data ) ) ;
extern void g_markup_parse_context_free(GMarkupParseContext *context ) ;
extern gboolean g_markup_parse_context_parse(GMarkupParseContext *context ,
                                             gchar const   *text ,
                                             gssize text_len , GError **error ) ;
extern void g_markup_parse_context_push(GMarkupParseContext *context ,
                                        GMarkupParser *parser ,
                                        gpointer user_data ) ;
extern gpointer g_markup_parse_context_pop(GMarkupParseContext *context ) ;
extern gboolean g_markup_parse_context_end_parse(GMarkupParseContext *context ,
                                                 GError **error ) ;
extern gchar const   *g_markup_parse_context_get_element(GMarkupParseContext *context ) ;
extern GSList const   *g_markup_parse_context_get_element_stack(GMarkupParseContext *context ) ;
extern void g_markup_parse_context_get_position(GMarkupParseContext *context ,
                                                gint *line_number ,
                                                gint *char_number ) ;
extern gpointer g_markup_parse_context_get_user_data(GMarkupParseContext *context ) ;
extern gchar *g_markup_escape_text(gchar const   *text , gssize length ) ;
extern gchar *( /* format attribute */  g_markup_printf_escaped)(char const   *format 
                                                                 , ...) ;
extern gchar *g_markup_vprintf_escaped(char const   *format , va_list args ) ;
extern gboolean g_markup_collect_attributes(gchar const   *element_name ,
                                            gchar const   **attribute_names ,
                                            gchar const   **attribute_values ,
                                            GError **error ,
                                            GMarkupCollectType first_type ,
                                            gchar const   *first_attr  , ...) ;
extern gsize g_printf_string_upper_bound(gchar const   *format , va_list args ) ;
extern guint g_log_set_handler(gchar const   *log_domain ,
                               GLogLevelFlags log_levels ,
                               void (*log_func)(gchar const   *log_domain ,
                                                GLogLevelFlags log_level ,
                                                gchar const   *message ,
                                                gpointer user_data ) ,
                               gpointer user_data ) ;
extern void g_log_remove_handler(gchar const   *log_domain , guint handler_id ) ;
extern void g_log_default_handler(gchar const   *log_domain ,
                                  GLogLevelFlags log_level ,
                                  gchar const   *message , gpointer unused_data ) ;
extern GLogFunc g_log_set_default_handler(void (*log_func)(gchar const   *log_domain ,
                                                           GLogLevelFlags log_level ,
                                                           gchar const   *message ,
                                                           gpointer user_data ) ,
                                          gpointer user_data ) ;
extern void ( /* format attribute */  g_log)(gchar const   *log_domain ,
                                             GLogLevelFlags log_level ,
                                             gchar const   *format  , ...) ;
extern void g_logv(gchar const   *log_domain , GLogLevelFlags log_level ,
                   gchar const   *format , va_list args ) ;
extern GLogLevelFlags g_log_set_fatal_mask(gchar const   *log_domain ,
                                           GLogLevelFlags fatal_mask ) ;
extern GLogLevelFlags g_log_set_always_fatal(GLogLevelFlags fatal_mask ) ;
extern void __attribute__((__visibility__("hidden")))  _g_log_fallback_handler(gchar const   *log_domain ,
                                                                               GLogLevelFlags log_level ,
                                                                               gchar const   *message ,
                                                                               gpointer unused_data ) ;
extern void g_return_if_fail_warning(char const   *log_domain ,
                                     char const   *pretty_function ,
                                     char const   *expression ) ;
extern void g_warn_message(char const   *domain , char const   *file ,
                           int line , char const   *func ,
                           char const   *warnexpr ) ;
extern  __attribute__((__noreturn__)) void g_assert_warning(char const   *log_domain ,
                                                            char const   *file ,
                                                            int const   line ,
                                                            char const   *pretty_function ,
                                                            char const   *expression ) ;
extern void ( /* format attribute */  g_print)(gchar const   *format  , ...) ;
extern GPrintFunc g_set_print_handler(void (*func)(gchar const   *string ) ) ;
extern void ( /* format attribute */  g_printerr)(gchar const   *format  , ...) ;
extern GPrintFunc g_set_printerr_handler(void (*func)(gchar const   *string ) ) ;
extern GNode *g_node_new(gpointer data ) ;
extern void g_node_destroy(GNode *root ) ;
extern void g_node_unlink(GNode *node ) ;
extern GNode *g_node_copy_deep(GNode *node ,
                               gpointer (*copy_func)(gconstpointer src ,
                                                     gpointer data ) ,
                               gpointer data ) ;
extern GNode *g_node_copy(GNode *node ) ;
extern GNode *g_node_insert(GNode *parent , gint position , GNode *node ) ;
extern GNode *g_node_insert_before(GNode *parent , GNode *sibling , GNode *node ) ;
extern GNode *g_node_insert_after(GNode *parent , GNode *sibling , GNode *node ) ;
extern GNode *g_node_prepend(GNode *parent , GNode *node ) ;
extern guint g_node_n_nodes(GNode *root , GTraverseFlags flags ) ;
extern GNode *g_node_get_root(GNode *node ) ;
extern gboolean g_node_is_ancestor(GNode *node , GNode *descendant ) ;
extern guint g_node_depth(GNode *node ) ;
extern GNode *g_node_find(GNode *root , GTraverseType order ,
                          GTraverseFlags flags , gpointer data ) ;
extern void g_node_traverse(GNode *root , GTraverseType order ,
                            GTraverseFlags flags , gint max_depth ,
                            gboolean (*func)(GNode *node , gpointer data ) ,
                            gpointer data ) ;
extern guint g_node_max_height(GNode *root ) ;
extern void g_node_children_foreach(GNode *node , GTraverseFlags flags ,
                                    void (*func)(GNode *node , gpointer data ) ,
                                    gpointer data ) ;
extern void g_node_reverse_children(GNode *node ) ;
extern guint g_node_n_children(GNode *node ) ;
extern GNode *g_node_nth_child(GNode *node , guint n ) ;
extern GNode *g_node_last_child(GNode *node ) ;
extern GNode *g_node_find_child(GNode *node , GTraverseFlags flags ,
                                gpointer data ) ;
extern gint g_node_child_position(GNode *node , GNode *child ) ;
extern gint g_node_child_index(GNode *node , gpointer data ) ;
extern GNode *g_node_first_sibling(GNode *node ) ;
extern GNode *g_node_last_sibling(GNode *node ) ;
extern void g_node_push_allocator(gpointer dummy ) ;
extern void g_node_pop_allocator(void) ;
extern GQuark g_option_error_quark(void) ;
extern GOptionContext *g_option_context_new(gchar const   *parameter_string ) ;
extern void g_option_context_set_summary(GOptionContext *context ,
                                         gchar const   *summary ) ;
extern gchar const   *g_option_context_get_summary(GOptionContext *context ) ;
extern void g_option_context_set_description(GOptionContext *context ,
                                             gchar const   *description ) ;
extern gchar const   *g_option_context_get_description(GOptionContext *context ) ;
extern void g_option_context_free(GOptionContext *context ) ;
extern void g_option_context_set_help_enabled(GOptionContext *context ,
                                              gboolean help_enabled ) ;
extern gboolean g_option_context_get_help_enabled(GOptionContext *context ) ;
extern void g_option_context_set_ignore_unknown_options(GOptionContext *context ,
                                                        gboolean ignore_unknown ) ;
extern gboolean g_option_context_get_ignore_unknown_options(GOptionContext *context ) ;
extern void g_option_context_add_main_entries(GOptionContext *context ,
                                              GOptionEntry const   *entries ,
                                              gchar const   *translation_domain ) ;
extern gboolean g_option_context_parse(GOptionContext *context , gint *argc ,
                                       gchar ***argv , GError **error ) ;
extern void g_option_context_set_translate_func(GOptionContext *context ,
                                                gchar const   *(*func)(gchar const   *str ,
                                                                       gpointer data ) ,
                                                gpointer data ,
                                                void (*destroy_notify)(gpointer data ) ) ;
extern void g_option_context_set_translation_domain(GOptionContext *context ,
                                                    gchar const   *domain ) ;
extern void g_option_context_add_group(GOptionContext *context ,
                                       GOptionGroup *group ) ;
extern void g_option_context_set_main_group(GOptionContext *context ,
                                            GOptionGroup *group ) ;
extern GOptionGroup *g_option_context_get_main_group(GOptionContext *context ) ;
extern gchar *g_option_context_get_help(GOptionContext *context ,
                                        gboolean main_help ,
                                        GOptionGroup *group ) ;
extern GOptionGroup *g_option_group_new(gchar const   *name ,
                                        gchar const   *description ,
                                        gchar const   *help_description ,
                                        gpointer user_data ,
                                        void (*destroy)(gpointer data ) ) ;
extern void g_option_group_set_parse_hooks(GOptionGroup *group ,
                                           gboolean (*pre_parse_func)(GOptionContext *context ,
                                                                      GOptionGroup *group ,
                                                                      gpointer data ,
                                                                      GError **error ) ,
                                           gboolean (*post_parse_func)(GOptionContext *context ,
                                                                       GOptionGroup *group ,
                                                                       gpointer data ,
                                                                       GError **error ) ) ;
extern void g_option_group_set_error_hook(GOptionGroup *group ,
                                          void (*error_func)(GOptionContext *context ,
                                                             GOptionGroup *group ,
                                                             gpointer data ,
                                                             GError **error ) ) ;
extern void g_option_group_free(GOptionGroup *group ) ;
extern void g_option_group_add_entries(GOptionGroup *group ,
                                       GOptionEntry const   *entries ) ;
extern void g_option_group_set_translate_func(GOptionGroup *group ,
                                              gchar const   *(*func)(gchar const   *str ,
                                                                     gpointer data ) ,
                                              gpointer data ,
                                              void (*destroy_notify)(gpointer data ) ) ;
extern void g_option_group_set_translation_domain(GOptionGroup *group ,
                                                  gchar const   *domain ) ;
extern GPatternSpec *g_pattern_spec_new(gchar const   *pattern ) ;
extern void g_pattern_spec_free(GPatternSpec *pspec ) ;
extern gboolean g_pattern_spec_equal(GPatternSpec *pspec1 ,
                                     GPatternSpec *pspec2 ) ;
extern gboolean g_pattern_match(GPatternSpec *pspec , guint string_length ,
                                gchar const   *string ,
                                gchar const   *string_reversed ) ;
extern gboolean g_pattern_match_string(GPatternSpec *pspec ,
                                       gchar const   *string ) ;
extern gboolean g_pattern_match_simple(gchar const   *pattern ,
                                       gchar const   *string ) ;
extern guint g_spaced_primes_closest(guint num )  __attribute__((__const__)) ;
extern void g_qsort_with_data(gconstpointer pbase , gint total_elems ,
                              gsize size ,
                              gint (*compare_func)(gconstpointer a ,
                                                   gconstpointer b ,
                                                   gpointer user_data ) ,
                              gpointer user_data ) ;
extern GQueue *g_queue_new(void) ;
extern void g_queue_free(GQueue *queue ) ;
extern void g_queue_init(GQueue *queue ) ;
extern void g_queue_clear(GQueue *queue ) ;
extern gboolean g_queue_is_empty(GQueue *queue ) ;
extern guint g_queue_get_length(GQueue *queue ) ;
extern void g_queue_reverse(GQueue *queue ) ;
extern GQueue *g_queue_copy(GQueue *queue ) ;
extern void g_queue_foreach(GQueue *queue , void (*func)(gpointer data ,
                                                         gpointer user_data ) ,
                            gpointer user_data ) ;
extern GList *g_queue_find(GQueue *queue , gconstpointer data ) ;
extern GList *g_queue_find_custom(GQueue *queue , gconstpointer data ,
                                  gint (*func)(gconstpointer a ,
                                               gconstpointer b ) ) ;
extern void g_queue_sort(GQueue *queue ,
                         gint (*compare_func)(gconstpointer a ,
                                              gconstpointer b ,
                                              gpointer user_data ) ,
                         gpointer user_data ) ;
extern void g_queue_push_head(GQueue *queue , gpointer data ) ;
extern void g_queue_push_tail(GQueue *queue , gpointer data ) ;
extern void g_queue_push_nth(GQueue *queue , gpointer data , gint n ) ;
extern gpointer g_queue_pop_head(GQueue *queue ) ;
extern gpointer g_queue_pop_tail(GQueue *queue ) ;
extern gpointer g_queue_pop_nth(GQueue *queue , guint n ) ;
extern gpointer g_queue_peek_head(GQueue *queue ) ;
extern gpointer g_queue_peek_tail(GQueue *queue ) ;
extern gpointer g_queue_peek_nth(GQueue *queue , guint n ) ;
extern gint g_queue_index(GQueue *queue , gconstpointer data ) ;
extern void g_queue_remove(GQueue *queue , gconstpointer data ) ;
extern void g_queue_remove_all(GQueue *queue , gconstpointer data ) ;
extern void g_queue_insert_before(GQueue *queue , GList *sibling ,
                                  gpointer data ) ;
extern void g_queue_insert_after(GQueue *queue , GList *sibling , gpointer data ) ;
extern void g_queue_insert_sorted(GQueue *queue , gpointer data ,
                                  gint (*func)(gconstpointer a ,
                                               gconstpointer b ,
                                               gpointer user_data ) ,
                                  gpointer user_data ) ;
extern void g_queue_push_head_link(GQueue *queue , GList *link_ ) ;
extern void g_queue_push_tail_link(GQueue *queue , GList *link_ ) ;
extern void g_queue_push_nth_link(GQueue *queue , gint n , GList *link_ ) ;
extern GList *g_queue_pop_head_link(GQueue *queue ) ;
extern GList *g_queue_pop_tail_link(GQueue *queue ) ;
extern GList *g_queue_pop_nth_link(GQueue *queue , guint n ) ;
extern GList *g_queue_peek_head_link(GQueue *queue ) ;
extern GList *g_queue_peek_tail_link(GQueue *queue ) ;
extern GList *g_queue_peek_nth_link(GQueue *queue , guint n ) ;
extern gint g_queue_link_index(GQueue *queue , GList *link_ ) ;
extern void g_queue_unlink(GQueue *queue , GList *link_ ) ;
extern void g_queue_delete_link(GQueue *queue , GList *link_ ) ;
extern GRand *g_rand_new_with_seed(guint32 seed ) ;
extern GRand *g_rand_new_with_seed_array(guint32 const   *seed ,
                                         guint seed_length ) ;
extern GRand *g_rand_new(void) ;
extern void g_rand_free(GRand *rand_ ) ;
extern GRand *g_rand_copy(GRand *rand_ ) ;
extern void g_rand_set_seed(GRand *rand_ , guint32 seed ) ;
extern void g_rand_set_seed_array(GRand *rand_ , guint32 const   *seed ,
                                  guint seed_length ) ;
extern guint32 g_rand_int(GRand *rand_ ) ;
extern gint32 g_rand_int_range(GRand *rand_ , gint32 begin , gint32 end ) ;
extern gdouble g_rand_double(GRand *rand_ ) ;
extern gdouble g_rand_double_range(GRand *rand_ , gdouble begin , gdouble end ) ;
extern void g_random_set_seed(guint32 seed ) ;
extern guint32 g_random_int(void) ;
extern gint32 g_random_int_range(gint32 begin , gint32 end ) ;
extern gdouble g_random_double(void) ;
extern gdouble g_random_double_range(gdouble begin , gdouble end ) ;
extern GRelation *g_relation_new(gint fields ) ;
extern void g_relation_destroy(GRelation *relation ) ;
extern void g_relation_index(GRelation *relation , gint field ,
                             guint (*hash_func)(gconstpointer key ) ,
                             gboolean (*key_equal_func)(gconstpointer a ,
                                                        gconstpointer b ) ) ;
extern void g_relation_insert(GRelation *relation  , ...) ;
extern gint g_relation_delete(GRelation *relation , gconstpointer key ,
                              gint field ) ;
extern GTuples *g_relation_select(GRelation *relation , gconstpointer key ,
                                  gint field ) ;
extern gint g_relation_count(GRelation *relation , gconstpointer key ,
                             gint field ) ;
extern gboolean g_relation_exists(GRelation *relation  , ...) ;
extern void g_relation_print(GRelation *relation ) ;
extern void g_tuples_destroy(GTuples *tuples ) ;
extern gpointer g_tuples_index(GTuples *tuples , gint index_ , gint field ) ;
extern GQuark g_regex_error_quark(void) ;
extern GRegex *g_regex_new(gchar const   *pattern ,
                           GRegexCompileFlags compile_options ,
                           GRegexMatchFlags match_options , GError **error ) ;
extern GRegex *g_regex_ref(GRegex *regex ) ;
extern void g_regex_unref(GRegex *regex ) ;
extern gchar const   *g_regex_get_pattern(GRegex const   *regex ) ;
extern gint g_regex_get_max_backref(GRegex const   *regex ) ;
extern gint g_regex_get_capture_count(GRegex const   *regex ) ;
extern gint g_regex_get_string_number(GRegex const   *regex ,
                                      gchar const   *name ) ;
extern gchar *g_regex_escape_string(gchar const   *string , gint length ) ;
extern gboolean g_regex_match_simple(gchar const   *pattern ,
                                     gchar const   *string ,
                                     GRegexCompileFlags compile_options ,
                                     GRegexMatchFlags match_options ) ;
extern gboolean g_regex_match(GRegex const   *regex , gchar const   *string ,
                              GRegexMatchFlags match_options ,
                              GMatchInfo **match_info ) ;
extern gboolean g_regex_match_full(GRegex const   *regex ,
                                   gchar const   *string , gssize string_len ,
                                   gint start_position ,
                                   GRegexMatchFlags match_options ,
                                   GMatchInfo **match_info , GError **error ) ;
extern gboolean g_regex_match_all(GRegex const   *regex ,
                                  gchar const   *string ,
                                  GRegexMatchFlags match_options ,
                                  GMatchInfo **match_info ) ;
extern gboolean g_regex_match_all_full(GRegex const   *regex ,
                                       gchar const   *string ,
                                       gssize string_len , gint start_position ,
                                       GRegexMatchFlags match_options ,
                                       GMatchInfo **match_info , GError **error ) ;
extern gchar **g_regex_split_simple(gchar const   *pattern ,
                                    gchar const   *string ,
                                    GRegexCompileFlags compile_options ,
                                    GRegexMatchFlags match_options ) ;
extern gchar **g_regex_split(GRegex const   *regex , gchar const   *string ,
                             GRegexMatchFlags match_options ) ;
extern gchar **g_regex_split_full(GRegex const   *regex ,
                                  gchar const   *string , gssize string_len ,
                                  gint start_position ,
                                  GRegexMatchFlags match_options ,
                                  gint max_tokens , GError **error ) ;
extern gchar *g_regex_replace(GRegex const   *regex , gchar const   *string ,
                              gssize string_len , gint start_position ,
                              gchar const   *replacement ,
                              GRegexMatchFlags match_options , GError **error ) ;
extern gchar *g_regex_replace_literal(GRegex const   *regex ,
                                      gchar const   *string ,
                                      gssize string_len , gint start_position ,
                                      gchar const   *replacement ,
                                      GRegexMatchFlags match_options ,
                                      GError **error ) ;
extern gchar *g_regex_replace_eval(GRegex const   *regex ,
                                   gchar const   *string , gssize string_len ,
                                   gint start_position ,
                                   GRegexMatchFlags match_options ,
                                   gboolean (*eval)(GMatchInfo const   *match_info ,
                                                    GString *result ,
                                                    gpointer user_data ) ,
                                   gpointer user_data , GError **error ) ;
extern gboolean g_regex_check_replacement(gchar const   *replacement ,
                                          gboolean *has_references ,
                                          GError **error ) ;
extern GRegex *g_match_info_get_regex(GMatchInfo const   *match_info ) ;
extern gchar const   *g_match_info_get_string(GMatchInfo const   *match_info ) ;
extern void g_match_info_free(GMatchInfo *match_info ) ;
extern gboolean g_match_info_next(GMatchInfo *match_info , GError **error ) ;
extern gboolean g_match_info_matches(GMatchInfo const   *match_info ) ;
extern gint g_match_info_get_match_count(GMatchInfo const   *match_info ) ;
extern gboolean g_match_info_is_partial_match(GMatchInfo const   *match_info ) ;
extern gchar *g_match_info_expand_references(GMatchInfo const   *match_info ,
                                             gchar const   *string_to_expand ,
                                             GError **error ) ;
extern gchar *g_match_info_fetch(GMatchInfo const   *match_info ,
                                 gint match_num ) ;
extern gboolean g_match_info_fetch_pos(GMatchInfo const   *match_info ,
                                       gint match_num , gint *start_pos ,
                                       gint *end_pos ) ;
extern gchar *g_match_info_fetch_named(GMatchInfo const   *match_info ,
                                       gchar const   *name ) ;
extern gboolean g_match_info_fetch_named_pos(GMatchInfo const   *match_info ,
                                             gchar const   *name ,
                                             gint *start_pos , gint *end_pos ) ;
extern gchar **g_match_info_fetch_all(GMatchInfo const   *match_info ) ;
extern GScanner *g_scanner_new(GScannerConfig const   *config_templ ) ;
extern void g_scanner_destroy(GScanner *scanner ) ;
extern void g_scanner_input_file(GScanner *scanner , gint input_fd ) ;
extern void g_scanner_sync_file_offset(GScanner *scanner ) ;
extern void g_scanner_input_text(GScanner *scanner , gchar const   *text ,
                                 guint text_len ) ;
extern GTokenType g_scanner_get_next_token(GScanner *scanner ) ;
extern GTokenType g_scanner_peek_next_token(GScanner *scanner ) ;
extern GTokenType g_scanner_cur_token(GScanner *scanner ) ;
extern GTokenValue g_scanner_cur_value(GScanner *scanner ) ;
extern guint g_scanner_cur_line(GScanner *scanner ) ;
extern guint g_scanner_cur_position(GScanner *scanner ) ;
extern gboolean g_scanner_eof(GScanner *scanner ) ;
extern guint g_scanner_set_scope(GScanner *scanner , guint scope_id ) ;
extern void g_scanner_scope_add_symbol(GScanner *scanner , guint scope_id ,
                                       gchar const   *symbol , gpointer value ) ;
extern void g_scanner_scope_remove_symbol(GScanner *scanner , guint scope_id ,
                                          gchar const   *symbol ) ;
extern gpointer g_scanner_scope_lookup_symbol(GScanner *scanner ,
                                              guint scope_id ,
                                              gchar const   *symbol ) ;
extern void g_scanner_scope_foreach_symbol(GScanner *scanner , guint scope_id ,
                                           void (*func)(gpointer key ,
                                                        gpointer value ,
                                                        gpointer user_data ) ,
                                           gpointer user_data ) ;
extern gpointer g_scanner_lookup_symbol(GScanner *scanner ,
                                        gchar const   *symbol ) ;
extern void g_scanner_unexp_token(GScanner *scanner ,
                                  GTokenType expected_token ,
                                  gchar const   *identifier_spec ,
                                  gchar const   *symbol_spec ,
                                  gchar const   *symbol_name ,
                                  gchar const   *message , gint is_error ) ;
extern void ( /* format attribute */  g_scanner_error)(GScanner *scanner ,
                                                       gchar const   *format 
                                                       , ...) ;
extern void ( /* format attribute */  g_scanner_warn)(GScanner *scanner ,
                                                      gchar const   *format 
                                                      , ...) ;
extern GSequence *g_sequence_new(void (*data_destroy)(gpointer data ) ) ;
extern void g_sequence_free(GSequence *seq ) ;
extern gint g_sequence_get_length(GSequence *seq ) ;
extern void g_sequence_foreach(GSequence *seq ,
                               void (*func)(gpointer data , gpointer user_data ) ,
                               gpointer user_data ) ;
extern void g_sequence_foreach_range(GSequenceIter *begin , GSequenceIter *end ,
                                     void (*func)(gpointer data ,
                                                  gpointer user_data ) ,
                                     gpointer user_data ) ;
extern void g_sequence_sort(GSequence *seq ,
                            gint (*cmp_func)(gconstpointer a ,
                                             gconstpointer b ,
                                             gpointer user_data ) ,
                            gpointer cmp_data ) ;
extern void g_sequence_sort_iter(GSequence *seq ,
                                 gint (*cmp_func)(GSequenceIter *a ,
                                                  GSequenceIter *b ,
                                                  gpointer data ) ,
                                 gpointer cmp_data ) ;
extern GSequenceIter *g_sequence_get_begin_iter(GSequence *seq ) ;
extern GSequenceIter *g_sequence_get_end_iter(GSequence *seq ) ;
extern GSequenceIter *g_sequence_get_iter_at_pos(GSequence *seq , gint pos ) ;
extern GSequenceIter *g_sequence_append(GSequence *seq , gpointer data ) ;
extern GSequenceIter *g_sequence_prepend(GSequence *seq , gpointer data ) ;
extern GSequenceIter *g_sequence_insert_before(GSequenceIter *iter ,
                                               gpointer data ) ;
extern void g_sequence_move(GSequenceIter *src , GSequenceIter *dest ) ;
extern void g_sequence_swap(GSequenceIter *a , GSequenceIter *b ) ;
extern GSequenceIter *g_sequence_insert_sorted(GSequence *seq , gpointer data ,
                                               gint (*cmp_func)(gconstpointer a ,
                                                                gconstpointer b ,
                                                                gpointer user_data ) ,
                                               gpointer cmp_data ) ;
extern GSequenceIter *g_sequence_insert_sorted_iter(GSequence *seq ,
                                                    gpointer data ,
                                                    gint (*iter_cmp)(GSequenceIter *a ,
                                                                     GSequenceIter *b ,
                                                                     gpointer data ) ,
                                                    gpointer cmp_data ) ;
extern void g_sequence_sort_changed(GSequenceIter *iter ,
                                    gint (*cmp_func)(gconstpointer a ,
                                                     gconstpointer b ,
                                                     gpointer user_data ) ,
                                    gpointer cmp_data ) ;
extern void g_sequence_sort_changed_iter(GSequenceIter *iter ,
                                         gint (*iter_cmp)(GSequenceIter *a ,
                                                          GSequenceIter *b ,
                                                          gpointer data ) ,
                                         gpointer cmp_data ) ;
extern void g_sequence_remove(GSequenceIter *iter ) ;
extern void g_sequence_remove_range(GSequenceIter *begin , GSequenceIter *end ) ;
extern void g_sequence_move_range(GSequenceIter *dest , GSequenceIter *begin ,
                                  GSequenceIter *end ) ;
extern GSequenceIter *g_sequence_search(GSequence *seq , gpointer data ,
                                        gint (*cmp_func)(gconstpointer a ,
                                                         gconstpointer b ,
                                                         gpointer user_data ) ,
                                        gpointer cmp_data ) ;
extern GSequenceIter *g_sequence_search_iter(GSequence *seq , gpointer data ,
                                             gint (*iter_cmp)(GSequenceIter *a ,
                                                              GSequenceIter *b ,
                                                              gpointer data ) ,
                                             gpointer cmp_data ) ;
extern gpointer g_sequence_get(GSequenceIter *iter ) ;
extern void g_sequence_set(GSequenceIter *iter , gpointer data ) ;
extern gboolean g_sequence_iter_is_begin(GSequenceIter *iter ) ;
extern gboolean g_sequence_iter_is_end(GSequenceIter *iter ) ;
extern GSequenceIter *g_sequence_iter_next(GSequenceIter *iter ) ;
extern GSequenceIter *g_sequence_iter_prev(GSequenceIter *iter ) ;
extern gint g_sequence_iter_get_position(GSequenceIter *iter ) ;
extern GSequenceIter *g_sequence_iter_move(GSequenceIter *iter , gint delta ) ;
extern GSequence *g_sequence_iter_get_sequence(GSequenceIter *iter ) ;
extern gint g_sequence_iter_compare(GSequenceIter *a , GSequenceIter *b ) ;
extern GSequenceIter *g_sequence_range_get_midpoint(GSequenceIter *begin ,
                                                    GSequenceIter *end ) ;
extern GQuark g_shell_error_quark(void) ;
extern gchar *g_shell_quote(gchar const   *unquoted_string ) ;
extern gchar *g_shell_unquote(gchar const   *quoted_string , GError **error ) ;
extern gboolean g_shell_parse_argv(gchar const   *command_line , gint *argcp ,
                                   gchar ***argvp , GError **error ) ;
extern GQuark g_spawn_error_quark(void) ;
extern gboolean g_spawn_async(gchar const   *working_directory , gchar **argv ,
                              gchar **envp , GSpawnFlags flags ,
                              void (*child_setup)(gpointer user_data ) ,
                              gpointer user_data , GPid *child_pid ,
                              GError **error ) ;
extern gboolean g_spawn_async_with_pipes(gchar const   *working_directory ,
                                         gchar **argv , gchar **envp ,
                                         GSpawnFlags flags ,
                                         void (*child_setup)(gpointer user_data ) ,
                                         gpointer user_data , GPid *child_pid ,
                                         gint *standard_input ,
                                         gint *standard_output ,
                                         gint *standard_error , GError **error ) ;
extern gboolean g_spawn_sync(gchar const   *working_directory , gchar **argv ,
                             gchar **envp , GSpawnFlags flags ,
                             void (*child_setup)(gpointer user_data ) ,
                             gpointer user_data , gchar **standard_output ,
                             gchar **standard_error , gint *exit_status ,
                             GError **error ) ;
extern gboolean g_spawn_command_line_sync(gchar const   *command_line ,
                                          gchar **standard_output ,
                                          gchar **standard_error ,
                                          gint *exit_status , GError **error ) ;
extern gboolean g_spawn_command_line_async(gchar const   *command_line ,
                                           GError **error ) ;
extern void g_spawn_close_pid(GPid pid ) ;
extern guint16 const   * const  g_ascii_table ;
extern gchar g_ascii_tolower(gchar c )  __attribute__((__const__)) ;
extern gchar g_ascii_toupper(gchar c )  __attribute__((__const__)) ;
extern gint g_ascii_digit_value(gchar c )  __attribute__((__const__)) ;
extern gint g_ascii_xdigit_value(gchar c )  __attribute__((__const__)) ;
extern gchar *g_strdelimit(gchar *string , gchar const   *delimiters ,
                           gchar new_delimiter ) ;
extern gchar *g_strcanon(gchar *string , gchar const   *valid_chars ,
                         gchar substitutor ) ;
extern gchar const   *g_strerror(gint errnum )  __attribute__((__const__)) ;
extern gchar const   *g_strsignal(gint signum )  __attribute__((__const__)) ;
extern gchar *g_strreverse(gchar *string ) ;
extern gsize g_strlcpy(gchar *dest , gchar const   *src , gsize dest_size ) ;
extern gsize g_strlcat(gchar *dest , gchar const   *src , gsize dest_size ) ;
extern gchar *g_strstr_len(gchar const   *haystack , gssize haystack_len ,
                           gchar const   *needle ) ;
extern gchar *g_strrstr(gchar const   *haystack , gchar const   *needle ) ;
extern gchar *g_strrstr_len(gchar const   *haystack , gssize haystack_len ,
                            gchar const   *needle ) ;
extern gboolean g_str_has_suffix(gchar const   *str , gchar const   *suffix ) ;
extern gboolean g_str_has_prefix(gchar const   *str , gchar const   *prefix ) ;
extern gdouble g_strtod(gchar const   *nptr , gchar **endptr ) ;
extern gdouble g_ascii_strtod(gchar const   *nptr , gchar **endptr ) ;
extern guint64 g_ascii_strtoull(gchar const   *nptr , gchar **endptr ,
                                guint base ) ;
extern gint64 g_ascii_strtoll(gchar const   *nptr , gchar **endptr , guint base ) ;
extern gchar *g_ascii_dtostr(gchar *buffer , gint buf_len , gdouble d ) ;
extern gchar *g_ascii_formatd(gchar *buffer , gint buf_len ,
                              gchar const   *format , gdouble d ) ;
extern gchar *g_strchug(gchar *string ) ;
extern gchar *g_strchomp(gchar *string ) ;
extern gint g_ascii_strcasecmp(gchar const   *s1 , gchar const   *s2 ) ;
extern gint g_ascii_strncasecmp(gchar const   *s1 , gchar const   *s2 , gsize n ) ;
extern gchar *g_ascii_strdown(gchar const   *str , gssize len )  __attribute__((__malloc__)) ;
extern gchar *g_ascii_strup(gchar const   *str , gssize len )  __attribute__((__malloc__)) ;
extern gint g_strcasecmp(gchar const   *s1 , gchar const   *s2 ) ;
extern gint g_strncasecmp(gchar const   *s1 , gchar const   *s2 , guint n ) ;
extern gchar *g_strdown(gchar *string ) ;
extern gchar *g_strup(gchar *string ) ;
extern gchar *g_strdup(gchar const   *str )  __attribute__((__malloc__)) ;
extern gchar *( /* format attribute */  g_strdup_printf)(gchar const   *format 
                                                         , ...)  __attribute__((__malloc__)) ;
extern gchar *g_strdup_vprintf(gchar const   *format , va_list args )  __attribute__((__malloc__)) ;
extern gchar *g_strndup(gchar const   *str , gsize n )  __attribute__((__malloc__)) ;
extern gchar *g_strnfill(gsize length , gchar fill_char )  __attribute__((__malloc__)) ;
extern gchar *g_strconcat(gchar const   *string1  , ...)  __attribute__((__sentinel__,
__malloc__)) ;
extern gchar *g_strjoin(gchar const   *separator  , ...)  __attribute__((__sentinel__,
__malloc__)) ;
extern gchar *g_strcompress(gchar const   *source )  __attribute__((__malloc__)) ;
extern gchar *g_strescape(gchar const   *source , gchar const   *exceptions )  __attribute__((__malloc__)) ;
extern gpointer g_memdup(gconstpointer mem , guint byte_size )  __attribute__((__malloc__,
__alloc_size__(2))) ;
extern gchar **g_strsplit(gchar const   *string , gchar const   *delimiter ,
                          gint max_tokens )  __attribute__((__malloc__)) ;
extern gchar **g_strsplit_set(gchar const   *string ,
                              gchar const   *delimiters , gint max_tokens )  __attribute__((__malloc__)) ;
extern gchar *g_strjoinv(gchar const   *separator , gchar **str_array )  __attribute__((__malloc__)) ;
extern void g_strfreev(gchar **str_array ) ;
extern gchar **g_strdupv(gchar **str_array )  __attribute__((__malloc__)) ;
extern guint g_strv_length(gchar **str_array ) ;
extern gchar *g_stpcpy(gchar *dest , char const   *src ) ;
extern gchar const   *g_strip_context(gchar const   *msgid ,
                                      gchar const   *msgval )  __attribute__((__format_arg__(1))) ;
extern gchar const   *g_dgettext(gchar const   *domain , gchar const   *msgid )  __attribute__((__format_arg__(2))) ;
extern gchar const   *g_dngettext(gchar const   *domain , gchar const   *msgid ,
                                  gchar const   *msgid_plural , gulong n )  __attribute__((__format_arg__(3))) ;
extern gchar const   *g_dpgettext(gchar const   *domain ,
                                  gchar const   *msgctxtid , gsize msgidoffset )  __attribute__((__format_arg__(2))) ;
extern gchar const   *g_dpgettext2(gchar const   *domain ,
                                   gchar const   *context ,
                                   gchar const   *msgid )  __attribute__((__format_arg__(3))) ;
extern int g_strcmp0(char const   *str1 , char const   *str2 ) ;
extern void ( /* format attribute */  g_test_minimized_result)(double minimized_quantity ,
                                                               char const   *format 
                                                               , ...) ;
extern void ( /* format attribute */  g_test_maximized_result)(double maximized_quantity ,
                                                               char const   *format 
                                                               , ...) ;
extern void g_test_init(int *argc , char ***argv  , ...) ;
extern int g_test_run(void) ;
extern void g_test_add_func(char const   *testpath , void (*test_func)(void) ) ;
extern void g_test_add_data_func(char const   *testpath ,
                                 gconstpointer test_data ,
                                 void (*test_func)(gconstpointer  ) ) ;
extern void ( /* format attribute */  g_test_message)(char const   *format 
                                                      , ...) ;
extern void g_test_bug_base(char const   *uri_pattern ) ;
extern void g_test_bug(char const   *bug_uri_snippet ) ;
extern void g_test_timer_start(void) ;
extern double g_test_timer_elapsed(void) ;
extern double g_test_timer_last(void) ;
extern void g_test_queue_free(gpointer gfree_pointer ) ;
extern void g_test_queue_destroy(void (*destroy_func)(gpointer data ) ,
                                 gpointer destroy_data ) ;
extern gboolean g_test_trap_fork(guint64 usec_timeout ,
                                 GTestTrapFlags test_trap_flags ) ;
extern gboolean g_test_trap_has_passed(void) ;
extern gboolean g_test_trap_reached_timeout(void) ;
extern gint32 g_test_rand_int(void) ;
extern gint32 g_test_rand_int_range(gint32 begin , gint32 end ) ;
extern double g_test_rand_double(void) ;
extern double g_test_rand_double_range(double range_start , double range_end ) ;
extern GTestCase *g_test_create_case(char const   *test_name , gsize data_size ,
                                     gconstpointer test_data ,
                                     void (*data_setup)(void) ,
                                     void (*data_test)(void) ,
                                     void (*data_teardown)(void) ) ;
extern GTestSuite *g_test_create_suite(char const   *suite_name ) ;
extern GTestSuite *g_test_get_root(void) ;
extern void g_test_suite_add(GTestSuite *suite , GTestCase *test_case ) ;
extern void g_test_suite_add_suite(GTestSuite *suite , GTestSuite *nestedsuite ) ;
extern int g_test_run_suite(GTestSuite *suite ) ;
extern void g_test_trap_assertions(char const   *domain , char const   *file ,
                                   int line , char const   *func ,
                                   guint64 assertion_flags ,
                                   char const   *pattern ) ;
extern  __attribute__((__noreturn__)) void g_assertion_message(char const   *domain ,
                                                               char const   *file ,
                                                               int line ,
                                                               char const   *func ,
                                                               char const   *message ) ;
extern  __attribute__((__noreturn__)) void g_assertion_message_expr(char const   *domain ,
                                                                    char const   *file ,
                                                                    int line ,
                                                                    char const   *func ,
                                                                    char const   *expr ) ;
extern  __attribute__((__noreturn__)) void g_assertion_message_cmpstr(char const   *domain ,
                                                                      char const   *file ,
                                                                      int line ,
                                                                      char const   *func ,
                                                                      char const   *expr ,
                                                                      char const   *arg1 ,
                                                                      char const   *cmp ,
                                                                      char const   *arg2 ) ;
extern  __attribute__((__noreturn__)) void g_assertion_message_cmpnum(char const   *domain ,
                                                                      char const   *file ,
                                                                      int line ,
                                                                      char const   *func ,
                                                                      char const   *expr ,
                                                                      long double arg1 ,
                                                                      char const   *cmp ,
                                                                      long double arg2 ,
                                                                      char numtype ) ;
extern  __attribute__((__noreturn__)) void g_assertion_message_error(char const   *domain ,
                                                                     char const   *file ,
                                                                     int line ,
                                                                     char const   *func ,
                                                                     char const   *expr ,
                                                                     GError *error ,
                                                                     GQuark error_domain ,
                                                                     int error_code ) ;
extern void g_test_add_vtable(char const   *testpath , gsize data_size ,
                              gconstpointer test_data ,
                              void (*data_setup)(void) ,
                              void (*data_test)(void) ,
                              void (*data_teardown)(void) ) ;
extern GTestConfig const   * const  g_test_config_vars ;
extern char const   *g_test_log_type_name(GTestLogType log_type ) ;
extern GTestLogBuffer *g_test_log_buffer_new(void) ;
extern void g_test_log_buffer_free(GTestLogBuffer *tbuffer ) ;
extern void g_test_log_buffer_push(GTestLogBuffer *tbuffer , guint n_bytes ,
                                   guint8 const   *bytes ) ;
extern GTestLogMsg *g_test_log_buffer_pop(GTestLogBuffer *tbuffer ) ;
extern void g_test_log_msg_free(GTestLogMsg *tmsg ) ;
extern void g_test_log_set_fatal_handler(gboolean (*log_func)(gchar const   *log_domain ,
                                                              GLogLevelFlags log_level ,
                                                              gchar const   *message ,
                                                              gpointer user_data ) ,
                                         gpointer user_data ) ;
extern GThreadPool *g_thread_pool_new(void (*func)(gpointer data ,
                                                   gpointer user_data ) ,
                                      gpointer user_data , gint max_threads ,
                                      gboolean exclusive , GError **error ) ;
extern void g_thread_pool_push(GThreadPool *pool , gpointer data ,
                               GError **error ) ;
extern void g_thread_pool_set_max_threads(GThreadPool *pool , gint max_threads ,
                                          GError **error ) ;
extern gint g_thread_pool_get_max_threads(GThreadPool *pool ) ;
extern guint g_thread_pool_get_num_threads(GThreadPool *pool ) ;
extern guint g_thread_pool_unprocessed(GThreadPool *pool ) ;
extern void g_thread_pool_free(GThreadPool *pool , gboolean immediate ,
                               gboolean wait_ ) ;
extern void g_thread_pool_set_max_unused_threads(gint max_threads ) ;
extern gint g_thread_pool_get_max_unused_threads(void) ;
extern guint g_thread_pool_get_num_unused_threads(void) ;
extern void g_thread_pool_stop_unused_threads(void) ;
extern void g_thread_pool_set_sort_function(GThreadPool *pool ,
                                            gint (*func)(gconstpointer a ,
                                                         gconstpointer b ,
                                                         gpointer user_data ) ,
                                            gpointer user_data ) ;
extern void g_thread_pool_set_max_idle_time(guint interval ) ;
extern guint g_thread_pool_get_max_idle_time(void) ;
extern GTimer *g_timer_new(void) ;
extern void g_timer_destroy(GTimer *timer ) ;
extern void g_timer_start(GTimer *timer ) ;
extern void g_timer_stop(GTimer *timer ) ;
extern void g_timer_reset(GTimer *timer ) ;
extern void g_timer_continue(GTimer *timer ) ;
extern gdouble g_timer_elapsed(GTimer *timer , gulong *microseconds ) ;
extern void g_usleep(gulong microseconds ) ;
extern void g_time_val_add(GTimeVal *time_ , glong microseconds ) ;
extern gboolean g_time_val_from_iso8601(gchar const   *iso_date ,
                                        GTimeVal *time_ ) ;
extern gchar *g_time_val_to_iso8601(GTimeVal *time_ )  __attribute__((__malloc__)) ;
extern GTree *g_tree_new(gint (*key_compare_func)(gconstpointer a ,
                                                  gconstpointer b ) ) ;
extern GTree *g_tree_new_with_data(gint (*key_compare_func)(gconstpointer a ,
                                                            gconstpointer b ,
                                                            gpointer user_data ) ,
                                   gpointer key_compare_data ) ;
extern GTree *g_tree_new_full(gint (*key_compare_func)(gconstpointer a ,
                                                       gconstpointer b ,
                                                       gpointer user_data ) ,
                              gpointer key_compare_data ,
                              void (*key_destroy_func)(gpointer data ) ,
                              void (*value_destroy_func)(gpointer data ) ) ;
extern GTree *g_tree_ref(GTree *tree ) ;
extern void g_tree_unref(GTree *tree ) ;
extern void g_tree_destroy(GTree *tree ) ;
extern void g_tree_insert(GTree *tree , gpointer key , gpointer value ) ;
extern void g_tree_replace(GTree *tree , gpointer key , gpointer value ) ;
extern gboolean g_tree_remove(GTree *tree , gconstpointer key ) ;
extern gboolean g_tree_steal(GTree *tree , gconstpointer key ) ;
extern gpointer g_tree_lookup(GTree *tree , gconstpointer key ) ;
extern gboolean g_tree_lookup_extended(GTree *tree , gconstpointer lookup_key ,
                                       gpointer *orig_key , gpointer *value ) ;
extern void g_tree_foreach(GTree *tree , gboolean (*func)(gpointer key ,
                                                          gpointer value ,
                                                          gpointer data ) ,
                           gpointer user_data ) ;
extern void g_tree_traverse(GTree *tree ,
                            gboolean (*traverse_func)(gpointer key ,
                                                      gpointer value ,
                                                      gpointer data ) ,
                            GTraverseType traverse_type , gpointer user_data ) ;
extern gpointer g_tree_search(GTree *tree ,
                              gint (*search_func)(gconstpointer a ,
                                                  gconstpointer b ) ,
                              gconstpointer user_data ) ;
extern gint g_tree_height(GTree *tree ) ;
extern gint g_tree_nnodes(GTree *tree ) ;
extern char *g_uri_unescape_string(char const   *escaped_string ,
                                   char const   *illegal_characters ) ;
extern char *g_uri_unescape_segment(char const   *escaped_string ,
                                    char const   *escaped_string_end ,
                                    char const   *illegal_characters ) ;
extern char *g_uri_parse_scheme(char const   *uri ) ;
extern char *g_uri_escape_string(char const   *unescaped ,
                                 char const   *reserved_chars_allowed ,
                                 gboolean allow_utf8 ) ;
extern gboolean g_variant_type_string_is_valid(gchar const   *type_string ) ;
extern gboolean g_variant_type_string_scan(gchar const   *string ,
                                           gchar const   *limit ,
                                           gchar const   **endptr ) ;
extern void g_variant_type_free(GVariantType *type ) ;
extern GVariantType *g_variant_type_copy(GVariantType const   *type ) ;
extern GVariantType *g_variant_type_new(gchar const   *type_string ) ;
extern gsize g_variant_type_get_string_length(GVariantType const   *type ) ;
extern gchar const   *g_variant_type_peek_string(GVariantType const   *type ) ;
extern gchar *g_variant_type_dup_string(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_definite(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_container(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_basic(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_maybe(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_array(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_tuple(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_dict_entry(GVariantType const   *type ) ;
extern gboolean g_variant_type_is_variant(GVariantType const   *type ) ;
extern guint g_variant_type_hash(gconstpointer type ) ;
extern gboolean g_variant_type_equal(gconstpointer type1 , gconstpointer type2 ) ;
extern gboolean g_variant_type_is_subtype_of(GVariantType const   *type ,
                                             GVariantType const   *supertype ) ;
extern GVariantType const   *g_variant_type_element(GVariantType const   *type ) ;
extern GVariantType const   *g_variant_type_first(GVariantType const   *type ) ;
extern GVariantType const   *g_variant_type_next(GVariantType const   *type ) ;
extern gsize g_variant_type_n_items(GVariantType const   *type ) ;
extern GVariantType const   *g_variant_type_key(GVariantType const   *type ) ;
extern GVariantType const   *g_variant_type_value(GVariantType const   *type ) ;
extern GVariantType *g_variant_type_new_array(GVariantType const   *element ) ;
extern GVariantType *g_variant_type_new_maybe(GVariantType const   *element ) ;
extern GVariantType *g_variant_type_new_tuple(GVariantType const   * const  *items ,
                                              gint length ) ;
extern GVariantType *g_variant_type_new_dict_entry(GVariantType const   *key ,
                                                   GVariantType const   *value ) ;
extern GVariantType const   *g_variant_type_checked_(gchar const   * ) ;
extern void g_variant_unref(GVariant *value ) ;
extern GVariant *g_variant_ref(GVariant *value ) ;
extern GVariant *g_variant_ref_sink(GVariant *value ) ;
extern GVariantType const   *g_variant_get_type(GVariant *value ) ;
extern gchar const   *g_variant_get_type_string(GVariant *value ) ;
extern gboolean g_variant_is_of_type(GVariant *value ,
                                     GVariantType const   *type ) ;
extern gboolean g_variant_is_container(GVariant *value ) ;
extern GVariantClass g_variant_classify(GVariant *value ) ;
extern GVariant *g_variant_new_boolean(gboolean boolean ) ;
extern GVariant *g_variant_new_byte(guchar byte ) ;
extern GVariant *g_variant_new_int16(gint16 int16 ) ;
extern GVariant *g_variant_new_uint16(guint16 uint16 ) ;
extern GVariant *g_variant_new_int32(gint32 int32 ) ;
extern GVariant *g_variant_new_uint32(guint32 uint32 ) ;
extern GVariant *g_variant_new_int64(gint64 int64 ) ;
extern GVariant *g_variant_new_uint64(guint64 uint64 ) ;
extern GVariant *g_variant_new_handle(gint32 handle ) ;
extern GVariant *g_variant_new_double(gdouble floating ) ;
extern GVariant *g_variant_new_string(gchar const   *string ) ;
extern GVariant *g_variant_new_object_path(gchar const   *object_path ) ;
extern gboolean g_variant_is_object_path(gchar const   *string ) ;
extern GVariant *g_variant_new_signature(gchar const   *signature ) ;
extern gboolean g_variant_is_signature(gchar const   *string ) ;
extern GVariant *g_variant_new_variant(GVariant *value ) ;
extern GVariant *g_variant_new_strv(gchar const   * const  *strv ,
                                    gssize length ) ;
extern gboolean g_variant_get_boolean(GVariant *value ) ;
extern guchar g_variant_get_byte(GVariant *value ) ;
extern gint16 g_variant_get_int16(GVariant *value ) ;
extern guint16 g_variant_get_uint16(GVariant *value ) ;
extern gint32 g_variant_get_int32(GVariant *value ) ;
extern guint32 g_variant_get_uint32(GVariant *value ) ;
extern gint64 g_variant_get_int64(GVariant *value ) ;
extern guint64 g_variant_get_uint64(GVariant *value ) ;
extern gint32 g_variant_get_handle(GVariant *value ) ;
extern gdouble g_variant_get_double(GVariant *value ) ;
extern GVariant *g_variant_get_variant(GVariant *value ) ;
extern gchar const   *g_variant_get_string(GVariant *value , gsize *length ) ;
extern gchar *g_variant_dup_string(GVariant *value , gsize *length ) ;
extern gchar const   **g_variant_get_strv(GVariant *value , gsize *length ) ;
extern gchar **g_variant_dup_strv(GVariant *value , gsize *length ) ;
extern GVariant *g_variant_new_maybe(GVariantType const   *child_type ,
                                     GVariant *child ) ;
extern GVariant *g_variant_new_array(GVariantType const   *child_type ,
                                     GVariant * const  *children ,
                                     gsize n_children ) ;
extern GVariant *g_variant_new_tuple(GVariant * const  *children ,
                                     gsize n_children ) ;
extern GVariant *g_variant_new_dict_entry(GVariant *key , GVariant *value ) ;
extern GVariant *g_variant_get_maybe(GVariant *value ) ;
extern gsize g_variant_n_children(GVariant *value ) ;
extern void g_variant_get_child(GVariant *value , gsize index_ ,
                                gchar const   *format_string  , ...) ;
extern GVariant *g_variant_get_child_value(GVariant *value , gsize index_ ) ;
extern gconstpointer g_variant_get_fixed_array(GVariant *value ,
                                               gsize *n_elements ,
                                               gsize element_size ) ;
extern gsize g_variant_get_size(GVariant *value ) ;
extern gconstpointer g_variant_get_data(GVariant *value ) ;
extern void g_variant_store(GVariant *value , gpointer data ) ;
extern gchar *g_variant_print(GVariant *value , gboolean type_annotate ) ;
extern GString *g_variant_print_string(GVariant *value , GString *string ,
                                       gboolean type_annotate ) ;
extern guint g_variant_hash(gconstpointer value ) ;
extern gboolean g_variant_equal(gconstpointer one , gconstpointer two ) ;
extern GVariant *g_variant_get_normal_form(GVariant *value ) ;
extern gboolean g_variant_is_normal_form(GVariant *value ) ;
extern GVariant *g_variant_byteswap(GVariant *value ) ;
extern GVariant *g_variant_new_from_data(GVariantType const   *type ,
                                         gconstpointer data , gsize size ,
                                         gboolean trusted ,
                                         void (*notify)(gpointer data ) ,
                                         gpointer user_data ) ;
extern GVariantIter *g_variant_iter_new(GVariant *value ) ;
extern gsize g_variant_iter_init(GVariantIter *iter , GVariant *value ) ;
extern GVariantIter *g_variant_iter_copy(GVariantIter *iter ) ;
extern gsize g_variant_iter_n_children(GVariantIter *iter ) ;
extern void g_variant_iter_free(GVariantIter *iter ) ;
extern GVariant *g_variant_iter_next_value(GVariantIter *iter ) ;
extern gboolean g_variant_iter_next(GVariantIter *iter ,
                                    gchar const   *format_string  , ...) ;
extern gboolean g_variant_iter_loop(GVariantIter *iter ,
                                    gchar const   *format_string  , ...) ;
extern GQuark g_variant_parser_get_error_quark(void) ;
extern GVariantBuilder *g_variant_builder_new(GVariantType const   *type ) ;
extern void g_variant_builder_unref(GVariantBuilder *builder ) ;
extern GVariantBuilder *g_variant_builder_ref(GVariantBuilder *builder ) ;
extern void g_variant_builder_init(GVariantBuilder *builder ,
                                   GVariantType const   *type ) ;
extern GVariant *g_variant_builder_end(GVariantBuilder *builder ) ;
extern void g_variant_builder_clear(GVariantBuilder *builder ) ;
extern void g_variant_builder_open(GVariantBuilder *builder ,
                                   GVariantType const   *type ) ;
extern void g_variant_builder_close(GVariantBuilder *builder ) ;
extern void g_variant_builder_add_value(GVariantBuilder *builder ,
                                        GVariant *value ) ;
extern void g_variant_builder_add(GVariantBuilder *builder ,
                                  gchar const   *format_string  , ...) ;
extern GVariant *g_variant_new(gchar const   *format_string  , ...) ;
extern void g_variant_get(GVariant *value , gchar const   *format_string  , ...) ;
extern GVariant *g_variant_new_va(gchar const   *format_string ,
                                  gchar const   **endptr , va_list *app ) ;
extern void g_variant_get_va(GVariant *value , gchar const   *format_string ,
                             gchar const   **endptr , va_list *app ) ;
extern GVariant *g_variant_parse(GVariantType const   *type ,
                                 gchar const   *text , gchar const   *limit ,
                                 gchar const   **endptr , GError **error ) ;
extern GVariant *g_variant_new_parsed(gchar const   *format  , ...) ;
extern GVariant *g_variant_new_parsed_va(gchar const   *format , va_list *app ) ;
extern struct wtap *wtap_open_offline(char const   *filename , int *err ,
                                      gchar **err_info , gboolean do_random ) ;
extern void wtap_cleareof(wtap *wth ) ;
extern void wtap_set_cb_new_ipv4(wtap *wth ,
                                 void (*add_new_ipv4)(guint const   addr ,
                                                      gchar const   *name ) ) ;
extern void wtap_set_cb_new_ipv6(wtap *wth ,
                                 void (*add_new_ipv6)(void const   *addrp ,
                                                      gchar const   *name ) ) ;
extern gboolean wtap_read(wtap *wth , int *err , gchar **err_info ,
                          gint64 *data_offset ) ;
extern gboolean wtap_seek_read(wtap *wth , gint64 seek_off ,
                               union wtap_pseudo_header *pseudo_header ,
                               guint8 *pd , int len , int *err ,
                               gchar **err_info ) ;
extern struct wtap_pkthdr *wtap_phdr(wtap *wth ) ;
extern union wtap_pseudo_header *wtap_pseudoheader(wtap *wth ) ;
extern guint8 *wtap_buf_ptr(wtap *wth ) ;
extern gint64 wtap_read_so_far(wtap *wth ) ;
extern gint64 wtap_file_size(wtap *wth , int *err ) ;
extern int wtap_snapshot_length(wtap *wth ) ;
extern int wtap_file_type(wtap *wth ) ;
extern int wtap_file_encap(wtap *wth ) ;
extern int wtap_file_tsprecision(wtap *wth ) ;
extern void wtap_sequential_close(wtap *wth ) ;
extern void wtap_close(wtap *wth ) ;
extern gboolean wtap_dump_can_open(int filetype ) ;
extern gboolean wtap_dump_can_write_encap(int filetype , int encap ) ;
extern gboolean wtap_dump_can_compress(int filetype ) ;
extern wtap_dumper *wtap_dump_open(char const   *filename , int filetype ,
                                   int encap , int snaplen ,
                                   gboolean compressed , int *err ) ;
extern wtap_dumper *wtap_dump_fdopen(int fd , int filetype , int encap ,
                                     int snaplen , gboolean compressed ,
                                     int *err ) ;
extern gboolean wtap_dump(wtap_dumper * , struct wtap_pkthdr  const  * ,
                          union wtap_pseudo_header  const  *pseudo_header ,
                          guchar const   * , int *err ) ;
extern void wtap_dump_flush(wtap_dumper * ) ;
extern gint64 wtap_get_bytes_dumped(wtap_dumper * ) ;
extern void wtap_set_bytes_dumped(wtap_dumper *wdh , gint64 bytes_dumped ) ;
extern gboolean wtap_dump_set_addrinfo_list(wtap_dumper *wdh ,
                                            struct addrinfo *addrinfo_list ) ;
extern gboolean wtap_dump_close(wtap_dumper * , int * ) ;
extern char const   *wtap_file_type_string(int filetype ) ;
extern char const   *wtap_file_type_short_string(int filetype ) ;
extern int wtap_short_string_to_file_type(char const   *short_name ) ;
extern char const   *wtap_file_extensions_string(int filetype ) ;
extern char const   *wtap_file_extension_default_string(int filetype ) ;
extern char const   *wtap_encap_string(int encap ) ;
extern char const   *wtap_encap_short_string(int encap ) ;
extern int wtap_short_string_to_encap(char const   *short_name ) ;
extern char const   *wtap_strerror(int err ) ;
extern int wtap_get_num_encap_types(void) ;
extern int wtap_get_num_file_types(void) ;
extern void wtap_register_open_routine(int (*)(struct wtap * , int * , char ** ) ,
                                       gboolean has_magic ) ;
extern int wtap_register_file_type(struct file_type_info  const  *fi ) ;
extern int wtap_register_encap_type(char *name , char *short_name ) ;
extern ipv4_addr *ipv4_addr_new(void) ;
extern void ipv4_addr_free(ipv4_addr *ipv4 ) ;
extern void ipv4_addr_set_host_order_addr(ipv4_addr *ipv4 ,
                                          guint32 const   new_addr ) ;
extern void ipv4_addr_set_net_order_addr(ipv4_addr *ipv4 ,
                                         guint32 const   new_addr ) ;
extern void ipv4_addr_set_netmask_bits(ipv4_addr *ipv4 ,
                                       guint const   new_nmask_bits ) ;
extern guint32 ipv4_get_net_order_addr(ipv4_addr *ipv4 ) ;
extern guint32 ipv4_get_host_order_addr(ipv4_addr *ipv4 ) ;
extern void ipv4_addr_str_buf(ipv4_addr const   *ipv4 , gchar *buf ) ;
extern gboolean ipv4_addr_eq(ipv4_addr *a , ipv4_addr *b ) ;
extern gboolean ipv4_addr_gt(ipv4_addr *a , ipv4_addr *b ) ;
extern gboolean ipv4_addr_ge(ipv4_addr *a , ipv4_addr *b ) ;
extern gboolean ipv4_addr_lt(ipv4_addr *a , ipv4_addr *b ) ;
extern gboolean ipv4_addr_le(ipv4_addr *a , ipv4_addr *b ) ;
extern void nstime_set_zero(nstime_t *nstime ) ;
extern gboolean nstime_is_zero(nstime_t *nstime ) ;
extern void nstime_set_unset(nstime_t *nstime ) ;
extern gboolean nstime_is_unset(nstime_t *nstime ) ;
extern void nstime_delta(nstime_t *delta , nstime_t const   *b ,
                         nstime_t const   *a ) ;
extern void nstime_sum(nstime_t *sum , nstime_t const   *b ,
                       nstime_t const   *a ) ;
extern void nstime_diff(nstime_t *diff , nstime_t const   *b ,
                        nstime_t const   *a ) ;
extern int nstime_cmp(nstime_t const   *a , nstime_t const   *b ) ;
extern double nstime_to_msec(nstime_t const   *nstime ) ;
extern double nstime_to_sec(nstime_t const   *nstime ) ;
extern double wtap_nstime_to_sec(struct wtap_nstime  const  *nstime ) ;
extern void guids_init(void) ;
extern void guids_add_guid(e_guid_t *guid , gchar const   *name ) ;
extern gchar const   *guids_get_guid_name(e_guid_t *guid ) ;
extern gchar const   *guids_resolve_guid_to_str(e_guid_t *guid ) ;
extern  __attribute__((__nothrow__)) int setjmp(struct __jmp_buf_tag *__env ) ;
extern  __attribute__((__nothrow__)) int __sigsetjmp(struct __jmp_buf_tag *__env ,
                                                     int __savemask ) ;
extern  __attribute__((__nothrow__)) int _setjmp(struct __jmp_buf_tag *__env ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void longjmp(struct __jmp_buf_tag *__env , int __val ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void _longjmp(struct __jmp_buf_tag *__env , int __val ) ;
extern  __attribute__((__nothrow__,
__noreturn__)) void siglongjmp(struct __jmp_buf_tag *__env , int __val ) ;
extern  __attribute__((__nothrow__)) long ( __attribute__((__nonnull__(1))) a64l)(char const   *__s )  __attribute__((__pure__)) ;
extern  __attribute__((__nothrow__)) void *alloca(size_t __size ) ;
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
extern void except_setup_clean(struct except_stacknode * ,
                               struct except_cleanup * , void (*)(void * ) ,
                               void * ) ;
extern void except_setup_try(struct except_stacknode * , struct except_catch * ,
                             except_id_t const   * , size_t  ) ;
extern struct except_stacknode *except_pop(void) ;
extern int except_init(void) ;
extern void except_deinit(void) ;
extern  __attribute__((__noreturn__)) void except_rethrow(except_t * ) ;
extern  __attribute__((__noreturn__)) void except_throw(long  , long  ,
                                                        char const   * ) ;
extern  __attribute__((__noreturn__)) void except_throwd(long  , long  ,
                                                         char const   * ,
                                                         void * ) ;
extern  __attribute__((__noreturn__)) void except_throwf(long  , long  ,
                                                         char const   *  , ...) ;
extern void (*except_unhandled_catcher(void (*)(except_t * ) ))(except_t * ) ;
extern unsigned long except_code(except_t * ) ;
extern unsigned long except_group(except_t * ) ;
extern char const   *except_message(except_t * ) ;
extern void *except_data(except_t * ) ;
extern void *except_take_data(except_t * ) ;
extern void except_set_allocator(void *(*)(size_t  ) , void (*)(void * ) ) ;
extern void *except_alloc(size_t  ) ;
extern void except_free(void * ) ;
extern void tvbuff_init(void) ;
extern void tvbuff_cleanup(void) ;
extern tvbuff_t *tvb_new(tvbuff_type  ) ;
extern void tvb_free(tvbuff_t * ) ;
extern void tvb_free_chain(tvbuff_t * ) ;
extern guint tvb_increment_usage_count(tvbuff_t * , guint const   count ) ;
extern guint tvb_decrement_usage_count(tvbuff_t * , guint const   count ) ;
extern void tvb_set_free_cb(tvbuff_t * , void (* const  )(void * ) ) ;
extern void tvb_set_child_real_data_tvbuff(tvbuff_t *parent , tvbuff_t *child ) ;
extern tvbuff_t *tvb_new_child_real_data(tvbuff_t *parent ,
                                         guint8 const   *data ,
                                         guint const   length ,
                                         gint const   reported_length ) ;
extern void tvb_set_real_data(tvbuff_t * , guint8 const   *data ,
                              guint const   length ,
                              gint const   reported_length ) ;
extern tvbuff_t *tvb_new_real_data(guint8 const   *data , guint const   length ,
                                   gint const   reported_length ) ;
extern void tvb_set_subset(tvbuff_t *tvb , tvbuff_t *backing ,
                           gint const   backing_offset ,
                           gint const   backing_length ,
                           gint const   reported_length ) ;
extern tvbuff_t *tvb_new_subset(tvbuff_t *backing ,
                                gint const   backing_offset ,
                                gint const   backing_length ,
                                gint const   reported_length ) ;
extern tvbuff_t *tvb_new_subset_remaining(tvbuff_t *backing ,
                                          gint const   backing_offset ) ;
extern void tvb_composite_append(tvbuff_t *tvb , tvbuff_t *member ) ;
extern void tvb_composite_prepend(tvbuff_t *tvb , tvbuff_t *member ) ;
extern tvbuff_t *tvb_new_composite(void) ;
extern void tvb_composite_finalize(tvbuff_t *tvb ) ;
extern guint tvb_length(tvbuff_t const   * ) ;
extern gint tvb_length_remaining(tvbuff_t const   * , gint const   offset ) ;
extern guint tvb_ensure_length_remaining(tvbuff_t const   * ,
                                         gint const   offset ) ;
extern gboolean tvb_bytes_exist(tvbuff_t const   * , gint const   offset ,
                                gint const   length ) ;
extern void tvb_ensure_bytes_exist(tvbuff_t const   *tvb , gint const   offset ,
                                   gint const   length ) ;
extern gboolean tvb_offset_exists(tvbuff_t const   * , gint const   offset ) ;
extern guint tvb_reported_length(tvbuff_t const   * ) ;
extern gint tvb_reported_length_remaining(tvbuff_t const   *tvb ,
                                          gint const   offset ) ;
extern void tvb_set_reported_length(tvbuff_t * , guint const    ) ;
extern guint tvb_offset_from_real_beginning(tvbuff_t const   *tvb ) ;
extern guint8 tvb_get_guint8(tvbuff_t * , gint const   offset ) ;
extern guint16 tvb_get_ntohs(tvbuff_t * , gint const   offset ) ;
extern guint32 tvb_get_ntoh24(tvbuff_t * , gint const   offset ) ;
extern guint32 tvb_get_ntohl(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_ntoh40(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_ntoh48(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_ntoh56(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_ntoh64(tvbuff_t * , gint const   offset ) ;
extern gfloat tvb_get_ntohieee_float(tvbuff_t * , gint const   offset ) ;
extern gdouble tvb_get_ntohieee_double(tvbuff_t * , gint const   offset ) ;
extern guint16 tvb_get_letohs(tvbuff_t * , gint const   offset ) ;
extern guint32 tvb_get_letoh24(tvbuff_t * , gint const   offset ) ;
extern guint32 tvb_get_letohl(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_letoh40(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_letoh48(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_letoh56(tvbuff_t * , gint const   offset ) ;
extern guint64 tvb_get_letoh64(tvbuff_t * , gint const   offset ) ;
extern gfloat tvb_get_letohieee_float(tvbuff_t * , gint const   offset ) ;
extern gdouble tvb_get_letohieee_double(tvbuff_t * , gint const   offset ) ;
extern guint32 tvb_get_ipv4(tvbuff_t * , gint const   offset ) ;
extern void tvb_get_ipv6(tvbuff_t * , gint const   offset ,
                         struct e_in6_addr *addr ) ;
extern void tvb_get_ntohguid(tvbuff_t *tvb , gint const   offset ,
                             e_guid_t *guid ) ;
extern void tvb_get_letohguid(tvbuff_t *tvb , gint const   offset ,
                              e_guid_t *guid ) ;
extern void tvb_get_guid(tvbuff_t *tvb , gint const   offset , e_guid_t *guid ,
                         guint const   representation ) ;
extern guint8 tvb_get_bits8(tvbuff_t *tvb , gint bit_offset ,
                            gint const   no_of_bits ) ;
extern guint16 tvb_get_bits16(tvbuff_t *tvb , gint bit_offset ,
                              gint const   no_of_bits ,
                              gboolean const   little_endian ) ;
extern guint32 tvb_get_bits32(tvbuff_t *tvb , gint bit_offset ,
                              gint const   no_of_bits ,
                              gboolean const   little_endian ) ;
extern guint64 tvb_get_bits64(tvbuff_t *tvb , gint bit_offset ,
                              gint const   no_of_bits ,
                              gboolean const   little_endian ) ;
extern guint32 tvb_get_bits(tvbuff_t *tvb , gint const   bit_offset ,
                            gint const   no_of_bits ,
                            gboolean const   little_endian ) ;
extern void *tvb_memcpy(tvbuff_t * , void *target , gint const   offset ,
                        size_t length ) ;
extern void *tvb_memdup(tvbuff_t * , gint const   offset , size_t length ) ;
extern void *ep_tvb_memdup(tvbuff_t *tvb , gint const   offset , size_t length ) ;
extern guint8 const   *tvb_get_ptr(tvbuff_t * , gint const   offset ,
                                   gint const   length ) ;
extern gint tvb_find_guint8(tvbuff_t * , gint const   offset ,
                            gint const   maxlength , guint8 const   needle ) ;
extern gint tvb_pbrk_guint8(tvbuff_t * , gint const   offset ,
                            gint const   maxlength , guint8 const   *needles ,
                            guchar *found_needle ) ;
extern guint tvb_strsize(tvbuff_t *tvb , gint const   offset ) ;
extern gint tvb_strnlen(tvbuff_t * , gint const   offset ,
                        guint const   maxlength ) ;
extern char *tvb_fake_unicode(tvbuff_t *tvb , int offset , int const   len ,
                              gboolean const   little_endian ) ;
extern char *tvb_get_ephemeral_faked_unicode(tvbuff_t *tvb , int offset ,
                                             int const   len ,
                                             gboolean const   little_endian ) ;
extern gchar *tvb_format_text(tvbuff_t *tvb , gint const   offset ,
                              gint const   size ) ;
extern gchar *tvb_format_text_wsp(tvbuff_t *tvb , gint const   offset ,
                                  gint const   size ) ;
extern gchar *tvb_format_stringzpad(tvbuff_t *tvb , gint const   offset ,
                                    gint const   size ) ;
extern gchar *tvb_format_stringzpad_wsp(tvbuff_t *tvb , gint const   offset ,
                                        gint const   size ) ;
extern guint8 *tvb_get_string(tvbuff_t *tvb , gint const   offset ,
                              gint const   length ) ;
extern gchar *tvb_get_unicode_string(tvbuff_t *tvb , gint const   offset ,
                                     gint length , guint const   encoding ) ;
extern guint8 *tvb_get_ephemeral_string(tvbuff_t *tvb , gint const   offset ,
                                        gint const   length ) ;
extern gchar *tvb_get_ephemeral_unicode_string(tvbuff_t *tvb ,
                                               gint const   offset ,
                                               gint length ,
                                               guint const   encoding ) ;
extern guint8 *tvb_get_seasonal_string(tvbuff_t *tvb , gint const   offset ,
                                       gint const   length ) ;
extern guint8 *tvb_get_stringz(tvbuff_t *tvb , gint const   offset ,
                               gint *lengthp ) ;
extern guint8 const   *tvb_get_const_stringz(tvbuff_t *tvb ,
                                             gint const   offset ,
                                             gint *lengthp ) ;
extern guint8 *tvb_get_ephemeral_stringz(tvbuff_t *tvb , gint const   offset ,
                                         gint *lengthp ) ;
extern gchar *tvb_get_ephemeral_unicode_stringz(tvbuff_t *tvb ,
                                                gint const   offset ,
                                                gint *lengthp ,
                                                guint const   encoding ) ;
extern guint8 *tvb_get_seasonal_stringz(tvbuff_t *tvb , gint const   offset ,
                                        gint *lengthp ) ;
extern gint tvb_get_nstringz(tvbuff_t *tvb , gint const   offset ,
                             guint const   bufsize , guint8 *buffer ) ;
extern gint tvb_get_nstringz0(tvbuff_t *tvb , gint const   offset ,
                              guint const   bufsize , guint8 *buffer ) ;
extern gint tvb_find_line_end(tvbuff_t *tvb , gint const   offset , int len ,
                              gint *next_offset , gboolean const   desegment ) ;
extern gint tvb_find_line_end_unquoted(tvbuff_t *tvb , gint const   offset ,
                                       int len , gint *next_offset ) ;
extern gint tvb_skip_wsp(tvbuff_t *tvb , gint const   offset ,
                         gint const   maxlength ) ;
extern gint tvb_skip_wsp_return(tvbuff_t *tvb , gint const   offset ) ;
extern gint tvb_strneql(tvbuff_t *tvb , gint const   offset ,
                        gchar const   *str , size_t const   size ) ;
extern gint tvb_strncaseeql(tvbuff_t *tvb , gint const   offset ,
                            gchar const   *str , size_t const   size ) ;
extern gint tvb_memeql(tvbuff_t *tvb , gint const   offset ,
                       guint8 const   *str , size_t size ) ;
extern gchar *tvb_bytes_to_str_punct(tvbuff_t *tvb , gint const   offset ,
                                     gint const   len , gchar const   punct ) ;
extern gchar *tvb_bytes_to_str(tvbuff_t *tvb , gint const   offset ,
                               gint const   len ) ;
extern gchar *tvb_bcd_dig_to_ep_str(tvbuff_t *tvb , gint const   offset ,
                                    gint const   len , dgt_set_t *dgt ,
                                    gboolean skip_first ) ;
extern gint tvb_find_tvb(tvbuff_t *haystack_tvb , tvbuff_t *needle_tvb ,
                         gint const   haystack_offset ) ;
extern tvbuff_t *tvb_uncompress(tvbuff_t *tvb , int const   offset ,
                                int comprlen ) ;
extern tvbuff_t *tvb_child_uncompress(tvbuff_t *parent , tvbuff_t *tvb ,
                                      int const   offset , int comprlen ) ;
extern void emem_init(void) ;
extern void *ep_alloc(size_t size )  __attribute__((__malloc__)) ;
extern void *ep_alloc0(size_t size )  __attribute__((__malloc__)) ;
extern gchar *ep_strdup(gchar const   *src )  __attribute__((__malloc__)) ;
extern gchar *ep_strndup(gchar const   *src , size_t len )  __attribute__((__malloc__)) ;
extern void *ep_memdup(void const   *src , size_t len )  __attribute__((__malloc__)) ;
extern gchar *ep_strdup_vprintf(gchar const   *fmt , va_list ap )  __attribute__((__malloc__)) ;
extern gchar *( /* format attribute */  ep_strdup_printf)(gchar const   *fmt 
                                                          , ...)  __attribute__((__malloc__)) ;
extern gchar *ep_strconcat(gchar const   *string  , ...)  __attribute__((__sentinel__,
__malloc__)) ;
extern gchar **ep_strsplit(gchar const   *string , gchar const   *delimiter ,
                           int max_tokens ) ;
extern void ep_free_all(void) ;
extern ep_stack_t ep_stack_new(void)  __attribute__((__malloc__)) ;
extern void *ep_stack_push(ep_stack_t stack , void *item ) ;
extern void *ep_stack_pop(ep_stack_t stack ) ;
extern void *se_alloc(size_t size )  __attribute__((__malloc__)) ;
extern void *se_alloc0(size_t size )  __attribute__((__malloc__)) ;
extern gchar *se_strdup(gchar const   *src )  __attribute__((__malloc__)) ;
extern gchar *se_strndup(gchar const   *src , size_t len )  __attribute__((__malloc__)) ;
extern void *se_memdup(void const   *src , size_t len )  __attribute__((__malloc__)) ;
extern gchar *se_strdup_vprintf(gchar const   *fmt , va_list ap )  __attribute__((__malloc__)) ;
extern gchar *( /* format attribute */  se_strdup_printf)(gchar const   *fmt 
                                                          , ...)  __attribute__((__malloc__)) ;
extern void se_free_all(void) ;
extern void *sl_alloc(struct ws_memory_slab *mem_chunk ) ;
extern void *sl_alloc0(struct ws_memory_slab *mem_chunk ) ;
extern void sl_free(struct ws_memory_slab *mem_chunk , gpointer ptr ) ;
extern void sl_free_all(struct ws_memory_slab *mem_chunk ) ;
extern emem_tree_t *se_tree_create(int type , char const   *name )  __attribute__((__malloc__)) ;
extern emem_tree_t *se_tree_create_non_persistent(int type , char const   *name )  __attribute__((__malloc__)) ;
extern emem_tree_t *pe_tree_create(int type , char const   *name )  __attribute__((__malloc__)) ;
extern void emem_tree_insert32(emem_tree_t *se_tree , guint32 key , void *data ) ;
extern void *emem_tree_lookup32(emem_tree_t *se_tree , guint32 key ) ;
extern void *emem_tree_lookup32_le(emem_tree_t *se_tree , guint32 key ) ;
extern void emem_tree_insert32_array(emem_tree_t *se_tree ,
                                     emem_tree_key_t *key , void *data ) ;
extern void *emem_tree_lookup32_array(emem_tree_t *se_tree ,
                                      emem_tree_key_t *key ) ;
extern void *emem_tree_lookup32_array_le(emem_tree_t *se_tree ,
                                         emem_tree_key_t *key ) ;
extern void emem_tree_insert_string(emem_tree_t *h , gchar const   *k ,
                                    void *v , guint32 flags ) ;
extern void *emem_tree_lookup_string(emem_tree_t *h , gchar const   *k ,
                                     guint32 flags ) ;
extern gboolean emem_tree_foreach(emem_tree_t *emem_tree ,
                                  gboolean (*callback)(void *value ,
                                                       void *userdata ) ,
                                  void *user_data ) ;
extern emem_strbuf_t *ep_strbuf_new(gchar const   *init )  __attribute__((__malloc__)) ;
extern emem_strbuf_t *ep_strbuf_new_label(gchar const   *init )  __attribute__((__malloc__)) ;
extern emem_strbuf_t *ep_strbuf_sized_new(gsize alloc_len , gsize max_alloc_len )  __attribute__((__malloc__)) ;
extern void ep_strbuf_append_vprintf(emem_strbuf_t *strbuf ,
                                     gchar const   *format , va_list ap ) ;
extern void ( /* format attribute */  ep_strbuf_printf)(emem_strbuf_t *strbuf ,
                                                        gchar const   *format 
                                                        , ...) ;
extern void ( /* format attribute */  ep_strbuf_append_printf)(emem_strbuf_t *strbuf ,
                                                               gchar const   *format 
                                                               , ...) ;
extern emem_strbuf_t *ep_strbuf_append(emem_strbuf_t *strbuf ,
                                       gchar const   *str ) ;
extern emem_strbuf_t *ep_strbuf_append_c(emem_strbuf_t *strbuf ,
                                         gchar const   c ) ;
extern emem_strbuf_t *ep_strbuf_truncate(emem_strbuf_t *strbuf , gsize len ) ;
extern void emem_print_tree(emem_tree_t *emem_tree ) ;
extern gboolean ep_verify_pointer(void const   *ptr ) ;
extern gboolean se_verify_pointer(void const   *ptr ) ;
extern void ftypes_initialize(void) ;
extern char const   *ftype_name(ftenum_t ftype ) ;
extern char const   *ftype_pretty_name(ftenum_t ftype ) ;
extern int ftype_length(ftenum_t ftype ) ;
extern gboolean ftype_can_slice(enum ftenum ftype ) ;
extern gboolean ftype_can_eq(enum ftenum ftype ) ;
extern gboolean ftype_can_ne(enum ftenum ftype ) ;
extern gboolean ftype_can_gt(enum ftenum ftype ) ;
extern gboolean ftype_can_ge(enum ftenum ftype ) ;
extern gboolean ftype_can_lt(enum ftenum ftype ) ;
extern gboolean ftype_can_le(enum ftenum ftype ) ;
extern gboolean ftype_can_bitwise_and(enum ftenum ftype ) ;
extern gboolean ftype_can_contains(enum ftenum ftype ) ;
extern gboolean ftype_can_matches(enum ftenum ftype ) ;
extern drange_node *drange_node_new(void) ;
extern void drange_node_free(drange_node *drnode ) ;
extern void drange_node_free_list(GSList *list ) ;
extern gint drange_node_get_start_offset(drange_node *drnode ) ;
extern gint drange_node_get_length(drange_node *drnode ) ;
extern gint drange_node_get_end_offset(drange_node *drnode ) ;
extern drange_node_end_t drange_node_get_ending(drange_node *drnode ) ;
extern void drange_node_set_start_offset(drange_node *drnode , gint offset ) ;
extern void drange_node_set_length(drange_node *drnode , gint length ) ;
extern void drange_node_set_end_offset(drange_node *drnode , gint offset ) ;
extern void drange_node_set_to_the_end(drange_node *drnode ) ;
extern drange *drange_new(void) ;
extern drange *drange_new_from_list(GSList *list ) ;
extern void drange_free(drange *dr ) ;
extern gboolean drange_has_total_length(drange *dr ) ;
extern gint drange_get_total_length(drange *dr ) ;
extern gint drange_get_min_start_offset(drange *dr ) ;
extern gint drange_get_max_start_offset(drange *dr ) ;
extern void drange_append_drange_node(drange *dr , drange_node *drnode ) ;
extern void drange_prepend_drange_node(drange *dr , drange_node *drnode ) ;
extern void drange_foreach_drange_node(drange *dr ,
                                       void (*func)(gpointer data ,
                                                    gpointer user_data ) ,
                                       gpointer funcdata ) ;
extern fvalue_t *fvalue_new(ftenum_t ftype ) ;
extern void fvalue_init(fvalue_t *fv , ftenum_t ftype ) ;
extern struct ws_memory_slab fvalue_t_slab ;
extern fvalue_t *fvalue_from_unparsed(ftenum_t ftype , char *s ,
                                      gboolean allow_partial_value ,
                                      void (*logfunc)(char const   *  , ...) ) ;
extern fvalue_t *fvalue_from_string(ftenum_t ftype , char *s ,
                                    void (*logfunc)(char const   *  , ...) ) ;
extern int fvalue_string_repr_len(fvalue_t *fv , ftrepr_t rtype ) ;
extern char *fvalue_to_string_repr(fvalue_t *fv , ftrepr_t rtype , char *buf ) ;
extern ftype_t *fvalue_ftype(fvalue_t *fv ) ;
extern char const   *fvalue_type_name(fvalue_t *fv ) ;
extern void fvalue_set(fvalue_t *fv , gpointer value , gboolean already_copied ) ;
extern void fvalue_set_uinteger(fvalue_t *fv , guint32 value ) ;
extern void fvalue_set_sinteger(fvalue_t *fv , gint32 value ) ;
extern void fvalue_set_integer64(fvalue_t *fv , guint64 value ) ;
extern void fvalue_set_floating(fvalue_t *fv , gdouble value ) ;
extern gpointer fvalue_get(fvalue_t *fv ) ;
extern guint32 fvalue_get_uinteger(fvalue_t *fv ) ;
extern gint32 fvalue_get_sinteger(fvalue_t *fv ) ;
extern guint64 fvalue_get_integer64(fvalue_t *fv ) ;
extern double fvalue_get_floating(fvalue_t *fv ) ;
extern gboolean fvalue_eq(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_ne(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_gt(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_ge(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_lt(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_le(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_bitwise_and(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_contains(fvalue_t *a , fvalue_t *b ) ;
extern gboolean fvalue_matches(fvalue_t *a , fvalue_t *b ) ;
extern guint fvalue_length(fvalue_t *fv ) ;
extern fvalue_t *fvalue_slice(fvalue_t *fv , drange *dr ) ;
extern void register_all_protocols(void (*cb)(register_action_e action ,
                                              char const   *message ,
                                              gpointer client_data ) ,
                                   gpointer client_data ) ;
extern void register_all_protocol_handoffs(void (*cb)(register_action_e action ,
                                                      char const   *message ,
                                                      gpointer client_data ) ,
                                           gpointer client_data ) ;
extern void register_all_tap_listeners(void) ;
extern gulong register_count(void) ;
extern int hf_text_only ;
extern gboolean proto_tree_traverse_post_order(proto_tree *tree ,
                                               gboolean (*func)(proto_node * ,
                                                                gpointer  ) ,
                                               gpointer data ) ;
extern void proto_tree_children_foreach(proto_tree *tree ,
                                        void (*func)(proto_node * , gpointer  ) ,
                                        gpointer data ) ;
extern void proto_init(void (*register_all_protocols_func)(void (*cb)(register_action_e action ,
                                                                      char const   *message ,
                                                                      gpointer client_data ) ,
                                                           gpointer client_data ) ,
                       void (*register_all_handoffs_func)(void (*cb)(register_action_e action ,
                                                                     char const   *message ,
                                                                     gpointer client_data ) ,
                                                          gpointer client_data ) ,
                       void (*cb)(register_action_e action ,
                                  char const   *message , gpointer client_data ) ,
                       void *client_data ) ;
extern void proto_cleanup(void) ;
extern gboolean proto_field_is_referenced(proto_tree *tree , int proto_id ) ;
extern proto_tree *( __attribute__((__warn_unused_result__)) proto_item_add_subtree)(proto_item *ti ,
                                                                                     gint const   idx ) ;
extern proto_tree *proto_item_get_subtree(proto_item const   *ti ) ;
extern proto_item *proto_item_get_parent(proto_item const   *ti ) ;
extern proto_item *proto_item_get_parent_nth(proto_item *ti , int gen ) ;
extern void ( /* format attribute */  proto_item_set_text)(proto_item *ti ,
                                                           char const   *format 
                                                           , ...) ;
extern void ( /* format attribute */  proto_item_append_text)(proto_item *ti ,
                                                              char const   *format 
                                                              , ...) ;
extern void ( /* format attribute */  proto_item_prepend_text)(proto_item *ti ,
                                                               char const   *format 
                                                               , ...) ;
extern void proto_item_set_len(proto_item *ti , gint const   length ) ;
extern void proto_item_set_end(proto_item *ti , tvbuff_t *tvb , gint end ) ;
extern int proto_item_get_len(proto_item const   *ti ) ;
extern gboolean proto_item_set_expert_flags(proto_item *ti , int const   group ,
                                            guint const   severity ) ;
extern proto_tree *proto_tree_create_root(void) ;
extern void proto_tree_free(proto_tree *tree ) ;
extern gboolean proto_tree_set_visible(proto_tree *tree , gboolean visible ) ;
extern void proto_tree_set_fake_protocols(proto_tree *tree ,
                                          gboolean fake_protocols ) ;
extern void proto_tree_prime_hfid(proto_tree *tree , int const   hfid ) ;
extern proto_item *proto_tree_get_parent(proto_tree const   *tree ) ;
extern proto_tree *proto_tree_get_root(proto_tree *tree ) ;
extern void proto_tree_move_item(proto_tree *tree , proto_item *fixed_item ,
                                 proto_item *item_to_move ) ;
extern void proto_tree_set_appendix(proto_tree *tree , tvbuff_t *tvb ,
                                    gint start , gint const   length ) ;
extern proto_item *proto_tree_add_item(proto_tree *tree , int const   hfindex ,
                                       tvbuff_t *tvb , gint const   start ,
                                       gint length , guint const   encoding ) ;
extern proto_item *( /* format attribute */  proto_tree_add_text)(proto_tree *tree ,
                                                                  tvbuff_t *tvb ,
                                                                  gint start ,
                                                                  gint length ,
                                                                  char const   *format 
                                                                  , ...) ;
extern proto_item *proto_tree_add_text_valist(proto_tree *tree , tvbuff_t *tvb ,
                                              gint start , gint length ,
                                              char const   *format , va_list ap ) ;
extern proto_item *( /* format attribute */  proto_tree_add_none_format)(proto_tree *tree ,
                                                                         int const   hfindex ,
                                                                         tvbuff_t *tvb ,
                                                                         gint const   start ,
                                                                         gint length ,
                                                                         char const   *format 
                                                                         , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_protocol_format)(proto_tree *tree ,
                                                                             int hfindex ,
                                                                             tvbuff_t *tvb ,
                                                                             gint start ,
                                                                             gint length ,
                                                                             char const   *format 
                                                                             , ...) ;
extern proto_item *proto_tree_add_bytes(proto_tree *tree , int hfindex ,
                                        tvbuff_t *tvb , gint start ,
                                        gint length , guint8 const   *start_ptr ) ;
extern proto_item *( /* format attribute */  proto_tree_add_bytes_format_value)(proto_tree *tree ,
                                                                                int hfindex ,
                                                                                tvbuff_t *tvb ,
                                                                                gint start ,
                                                                                gint length ,
                                                                                guint8 const   *start_ptr ,
                                                                                char const   *format 
                                                                                , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_bytes_format)(proto_tree *tree ,
                                                                          int hfindex ,
                                                                          tvbuff_t *tvb ,
                                                                          gint start ,
                                                                          gint length ,
                                                                          guint8 const   *start_ptr ,
                                                                          char const   *format 
                                                                          , ...) ;
extern proto_item *proto_tree_add_time(proto_tree *tree , int hfindex ,
                                       tvbuff_t *tvb , gint start ,
                                       gint length , nstime_t *value_ptr ) ;
extern proto_item *( /* format attribute */  proto_tree_add_time_format_value)(proto_tree *tree ,
                                                                               int hfindex ,
                                                                               tvbuff_t *tvb ,
                                                                               gint start ,
                                                                               gint length ,
                                                                               nstime_t *value_ptr ,
                                                                               char const   *format 
                                                                               , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_time_format)(proto_tree *tree ,
                                                                         int hfindex ,
                                                                         tvbuff_t *tvb ,
                                                                         gint start ,
                                                                         gint length ,
                                                                         nstime_t *value_ptr ,
                                                                         char const   *format 
                                                                         , ...) ;
extern proto_item *proto_tree_add_ipxnet(proto_tree *tree , int hfindex ,
                                         tvbuff_t *tvb , gint start ,
                                         gint length , guint32 value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_ipxnet_format_value)(proto_tree *tree ,
                                                                                 int hfindex ,
                                                                                 tvbuff_t *tvb ,
                                                                                 gint start ,
                                                                                 gint length ,
                                                                                 guint32 value ,
                                                                                 char const   *format 
                                                                                 , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_ipxnet_format)(proto_tree *tree ,
                                                                           int hfindex ,
                                                                           tvbuff_t *tvb ,
                                                                           gint start ,
                                                                           gint length ,
                                                                           guint32 value ,
                                                                           char const   *format 
                                                                           , ...) ;
extern proto_item *proto_tree_add_ipv4(proto_tree *tree , int hfindex ,
                                       tvbuff_t *tvb , gint start ,
                                       gint length , guint32 value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_ipv4_format_value)(proto_tree *tree ,
                                                                               int hfindex ,
                                                                               tvbuff_t *tvb ,
                                                                               gint start ,
                                                                               gint length ,
                                                                               guint32 value ,
                                                                               char const   *format 
                                                                               , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_ipv4_format)(proto_tree *tree ,
                                                                         int hfindex ,
                                                                         tvbuff_t *tvb ,
                                                                         gint start ,
                                                                         gint length ,
                                                                         guint32 value ,
                                                                         char const   *format 
                                                                         , ...) ;
extern proto_item *proto_tree_add_ipv6(proto_tree *tree , int hfindex ,
                                       tvbuff_t *tvb , gint start ,
                                       gint length , guint8 const   *value_ptr ) ;
extern proto_item *( /* format attribute */  proto_tree_add_ipv6_format_value)(proto_tree *tree ,
                                                                               int hfindex ,
                                                                               tvbuff_t *tvb ,
                                                                               gint start ,
                                                                               gint length ,
                                                                               guint8 const   *value_ptr ,
                                                                               char const   *format 
                                                                               , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_ipv6_format)(proto_tree *tree ,
                                                                         int hfindex ,
                                                                         tvbuff_t *tvb ,
                                                                         gint start ,
                                                                         gint length ,
                                                                         guint8 const   *value_ptr ,
                                                                         char const   *format 
                                                                         , ...) ;
extern proto_item *proto_tree_add_ether(proto_tree *tree , int hfindex ,
                                        tvbuff_t *tvb , gint start ,
                                        gint length , guint8 const   *value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_ether_format_value)(proto_tree *tree ,
                                                                                int hfindex ,
                                                                                tvbuff_t *tvb ,
                                                                                gint start ,
                                                                                gint length ,
                                                                                guint8 const   *value ,
                                                                                char const   *format 
                                                                                , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_ether_format)(proto_tree *tree ,
                                                                          int hfindex ,
                                                                          tvbuff_t *tvb ,
                                                                          gint start ,
                                                                          gint length ,
                                                                          guint8 const   *value ,
                                                                          char const   *format 
                                                                          , ...) ;
extern proto_item *proto_tree_add_guid(proto_tree *tree , int hfindex ,
                                       tvbuff_t *tvb , gint start ,
                                       gint length ,
                                       e_guid_t const   *value_ptr ) ;
extern proto_item *( /* format attribute */  proto_tree_add_guid_format_value)(proto_tree *tree ,
                                                                               int hfindex ,
                                                                               tvbuff_t *tvb ,
                                                                               gint start ,
                                                                               gint length ,
                                                                               e_guid_t const   *value_ptr ,
                                                                               char const   *format 
                                                                               , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_guid_format)(proto_tree *tree ,
                                                                         int hfindex ,
                                                                         tvbuff_t *tvb ,
                                                                         gint start ,
                                                                         gint length ,
                                                                         e_guid_t const   *value_ptr ,
                                                                         char const   *format 
                                                                         , ...) ;
extern proto_item *proto_tree_add_oid(proto_tree *tree , int hfindex ,
                                      tvbuff_t *tvb , gint start , gint length ,
                                      guint8 const   *value_ptr ) ;
extern proto_item *( /* format attribute */  proto_tree_add_oid_format_value)(proto_tree *tree ,
                                                                              int hfindex ,
                                                                              tvbuff_t *tvb ,
                                                                              gint start ,
                                                                              gint length ,
                                                                              guint8 const   *value_ptr ,
                                                                              char const   *format 
                                                                              , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_oid_format)(proto_tree *tree ,
                                                                        int hfindex ,
                                                                        tvbuff_t *tvb ,
                                                                        gint start ,
                                                                        gint length ,
                                                                        guint8 const   *value_ptr ,
                                                                        char const   *format 
                                                                        , ...) ;
extern proto_item *proto_tree_add_string(proto_tree *tree , int hfindex ,
                                         tvbuff_t *tvb , gint start ,
                                         gint length , char const   *value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_string_format_value)(proto_tree *tree ,
                                                                                 int hfindex ,
                                                                                 tvbuff_t *tvb ,
                                                                                 gint start ,
                                                                                 gint length ,
                                                                                 char const   *value ,
                                                                                 char const   *format 
                                                                                 , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_string_format)(proto_tree *tree ,
                                                                           int hfindex ,
                                                                           tvbuff_t *tvb ,
                                                                           gint start ,
                                                                           gint length ,
                                                                           char const   *value ,
                                                                           char const   *format 
                                                                           , ...) ;
extern proto_item *proto_tree_add_boolean(proto_tree *tree , int hfindex ,
                                          tvbuff_t *tvb , gint start ,
                                          gint length , guint32 value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_boolean_format_value)(proto_tree *tree ,
                                                                                  int hfindex ,
                                                                                  tvbuff_t *tvb ,
                                                                                  gint start ,
                                                                                  gint length ,
                                                                                  guint32 value ,
                                                                                  char const   *format 
                                                                                  , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_boolean_format)(proto_tree *tree ,
                                                                            int hfindex ,
                                                                            tvbuff_t *tvb ,
                                                                            gint start ,
                                                                            gint length ,
                                                                            guint32 value ,
                                                                            char const   *format 
                                                                            , ...) ;
extern proto_item *proto_tree_add_float(proto_tree *tree , int hfindex ,
                                        tvbuff_t *tvb , gint start ,
                                        gint length , float value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_float_format_value)(proto_tree *tree ,
                                                                                int hfindex ,
                                                                                tvbuff_t *tvb ,
                                                                                gint start ,
                                                                                gint length ,
                                                                                float value ,
                                                                                char const   *format 
                                                                                , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_float_format)(proto_tree *tree ,
                                                                          int hfindex ,
                                                                          tvbuff_t *tvb ,
                                                                          gint start ,
                                                                          gint length ,
                                                                          float value ,
                                                                          char const   *format 
                                                                          , ...) ;
extern proto_item *proto_tree_add_double(proto_tree *tree , int hfindex ,
                                         tvbuff_t *tvb , gint start ,
                                         gint length , double value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_double_format_value)(proto_tree *tree ,
                                                                                 int hfindex ,
                                                                                 tvbuff_t *tvb ,
                                                                                 gint start ,
                                                                                 gint length ,
                                                                                 double value ,
                                                                                 char const   *format 
                                                                                 , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_double_format)(proto_tree *tree ,
                                                                           int hfindex ,
                                                                           tvbuff_t *tvb ,
                                                                           gint start ,
                                                                           gint length ,
                                                                           double value ,
                                                                           char const   *format 
                                                                           , ...) ;
extern proto_item *proto_tree_add_uint(proto_tree *tree , int hfindex ,
                                       tvbuff_t *tvb , gint start ,
                                       gint length , guint32 value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_uint_format_value)(proto_tree *tree ,
                                                                               int hfindex ,
                                                                               tvbuff_t *tvb ,
                                                                               gint start ,
                                                                               gint length ,
                                                                               guint32 value ,
                                                                               char const   *format 
                                                                               , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_uint_format)(proto_tree *tree ,
                                                                         int hfindex ,
                                                                         tvbuff_t *tvb ,
                                                                         gint start ,
                                                                         gint length ,
                                                                         guint32 value ,
                                                                         char const   *format 
                                                                         , ...) ;
extern proto_item *proto_tree_add_uint64(proto_tree *tree , int hfindex ,
                                         tvbuff_t *tvb , gint start ,
                                         gint length , guint64 value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_uint64_format_value)(proto_tree *tree ,
                                                                                 int hfindex ,
                                                                                 tvbuff_t *tvb ,
                                                                                 gint start ,
                                                                                 gint length ,
                                                                                 guint64 value ,
                                                                                 char const   *format 
                                                                                 , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_uint64_format)(proto_tree *tree ,
                                                                           int hfindex ,
                                                                           tvbuff_t *tvb ,
                                                                           gint start ,
                                                                           gint length ,
                                                                           guint64 value ,
                                                                           char const   *format 
                                                                           , ...) ;
extern proto_item *proto_tree_add_int(proto_tree *tree , int hfindex ,
                                      tvbuff_t *tvb , gint start , gint length ,
                                      gint32 value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_int_format_value)(proto_tree *tree ,
                                                                              int hfindex ,
                                                                              tvbuff_t *tvb ,
                                                                              gint start ,
                                                                              gint length ,
                                                                              gint32 value ,
                                                                              char const   *format 
                                                                              , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_int_format)(proto_tree *tree ,
                                                                        int hfindex ,
                                                                        tvbuff_t *tvb ,
                                                                        gint start ,
                                                                        gint length ,
                                                                        gint32 value ,
                                                                        char const   *format 
                                                                        , ...) ;
extern proto_item *proto_tree_add_int64(proto_tree *tree , int hfindex ,
                                        tvbuff_t *tvb , gint start ,
                                        gint length , gint64 value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_int64_format_value)(proto_tree *tree ,
                                                                                int hfindex ,
                                                                                tvbuff_t *tvb ,
                                                                                gint start ,
                                                                                gint length ,
                                                                                gint64 value ,
                                                                                char const   *format 
                                                                                , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_int64_format)(proto_tree *tree ,
                                                                          int hfindex ,
                                                                          tvbuff_t *tvb ,
                                                                          gint start ,
                                                                          gint length ,
                                                                          gint64 value ,
                                                                          char const   *format 
                                                                          , ...) ;
extern proto_item *proto_tree_add_eui64(proto_tree *tree , int hfindex ,
                                        tvbuff_t *tvb , gint start ,
                                        gint length , guint64 const   value ) ;
extern proto_item *( /* format attribute */  proto_tree_add_eui64_format_value)(proto_tree *tree ,
                                                                                int hfindex ,
                                                                                tvbuff_t *tvb ,
                                                                                gint start ,
                                                                                gint length ,
                                                                                guint64 const   value ,
                                                                                char const   *format 
                                                                                , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_eui64_format)(proto_tree *tree ,
                                                                          int hfindex ,
                                                                          tvbuff_t *tvb ,
                                                                          gint start ,
                                                                          gint length ,
                                                                          guint64 const   value ,
                                                                          char const   *format 
                                                                          , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_debug_text)(proto_tree *tree ,
                                                                        char const   *format 
                                                                        , ...) ;
extern void proto_item_append_string(proto_item *pi , char const   *str ) ;
extern void proto_item_fill_label(field_info *fi , gchar *label_str ) ;
extern int proto_register_protocol(char const   *name ,
                                   char const   *short_name ,
                                   char const   *filter_name ) ;
extern void proto_mark_private(int const   proto_id ) ;
extern gboolean proto_is_private(int const   proto_id ) ;
extern void proto_register_prefix(char const   *prefix ,
                                  void (*initializer)(char const   *match ) ) ;
extern void proto_initialize_all_prefixes(void) ;
extern void proto_register_field_array(int const   parent ,
                                       hf_register_info *hf ,
                                       int const   num_records ) ;
extern void proto_register_subtree_array(gint * const  *indices ,
                                         int const   num_indices ) ;
extern int proto_registrar_n(void) ;
extern char const   *proto_registrar_get_name(int const   n ) ;
extern char const   *proto_registrar_get_abbrev(int const   n ) ;
extern header_field_info *proto_registrar_get_nth(guint hfindex ) ;
extern header_field_info *proto_registrar_get_byname(char const   *field_name ) ;
extern int proto_registrar_get_ftype(int const   n ) ;
extern int proto_registrar_get_parent(int const   n ) ;
extern gboolean proto_registrar_is_protocol(int const   n ) ;
extern gint proto_registrar_get_length(int const   n ) ;
extern int proto_get_first_protocol(void **cookie ) ;
extern int proto_get_next_protocol(void **cookie ) ;
extern header_field_info *proto_get_first_protocol_field(int const   proto_id ,
                                                         void **cookle ) ;
extern header_field_info *proto_get_next_protocol_field(void **cookle ) ;
extern int proto_get_id_by_filter_name(gchar const   *filter_name ) ;
extern gboolean proto_can_toggle_protocol(int const   proto_id ) ;
extern protocol_t *find_protocol_by_id(int const   proto_id ) ;
extern char const   *proto_get_protocol_name(int const   proto_id ) ;
extern int proto_get_id(protocol_t const   *protocol ) ;
extern char const   *proto_get_protocol_short_name(protocol_t const   *protocol ) ;
extern char const   *proto_get_protocol_long_name(protocol_t const   *protocol ) ;
extern gboolean proto_is_protocol_enabled(protocol_t const   *protocol ) ;
extern char const   *proto_get_protocol_filter_name(int const   proto_id ) ;
extern void proto_set_decoding(int const   proto_id , gboolean const   enabled ) ;
extern void proto_enable_all(void) ;
extern void proto_set_cant_toggle(int const   proto_id ) ;
extern gboolean proto_check_for_protocol_or_field(proto_tree const   *tree ,
                                                  int const   id ) ;
extern GPtrArray *proto_get_finfo_ptr_array(proto_tree const   *tree ,
                                            int const   hfindex ) ;
extern gboolean proto_tracking_interesting_fields(proto_tree const   *tree ) ;
extern GPtrArray *proto_find_finfo(proto_tree *tree , int const   hfindex ) ;
extern GPtrArray *proto_all_finfos(proto_tree *tree ) ;
extern void proto_registrar_dump_protocols(void) ;
extern void proto_registrar_dump_values(void) ;
extern void proto_registrar_dump_fields(int const   format ) ;
extern gboolean *tree_is_expanded ;
extern int num_tree_types ;
extern int hfinfo_bitwidth(header_field_info const   *hfinfo ) ;
extern void p_add_proto_data(frame_data *fd , int proto , void *proto_data ) ;
extern void *p_get_proto_data(frame_data *fd , int proto ) ;
extern void p_remove_proto_data(frame_data *fd , int proto ) ;
extern gint frame_data_compare(frame_data const   *fdata1 ,
                               frame_data const   *fdata2 , int field ) ;
extern void frame_data_cleanup(frame_data *fdata ) ;
extern void frame_data_init(frame_data *fdata , guint32 num ,
                            struct wtap_pkthdr  const  *phdr , gint64 offset ,
                            guint32 cum_bytes ) ;
extern void frame_data_set_before_dissect(frame_data *fdata ,
                                          nstime_t *elapsed_time ,
                                          nstime_t *first_ts ,
                                          nstime_t *prev_dis_ts ,
                                          nstime_t *prev_cap_ts ) ;
extern void frame_data_set_after_dissect(frame_data *fdata ,
                                         guint32 *cum_bytes ,
                                         nstime_t *prev_dis_ts ) ;
extern void dfilter_init(void) ;
extern void dfilter_cleanup(void) ;
extern gboolean dfilter_compile(gchar const   *text , dfilter_t **dfp ) ;
extern void dfilter_free(dfilter_t *df ) ;
extern gchar const   *dfilter_error_msg ;
extern gboolean dfilter_apply_edt(dfilter_t *df , epan_dissect_t *edt ) ;
extern gboolean dfilter_apply(dfilter_t *df , proto_tree *tree ) ;
extern void dfilter_prime_proto_tree(dfilter_t const   *df , proto_tree *tree ) ;
extern GPtrArray *dfilter_deprecated_tokens(dfilter_t *df ) ;
extern void dfilter_dump(dfilter_t *df ) ;
extern void epan_init(void (*register_all_protocols_func)(void (*cb)(register_action_e action ,
                                                                     char const   *message ,
                                                                     gpointer client_data ) ,
                                                          gpointer client_data ) ,
                      void (*register_all_handoffs_func)(void (*cb)(register_action_e action ,
                                                                    char const   *message ,
                                                                    gpointer client_data ) ,
                                                         gpointer client_data ) ,
                      void (*cb)(register_action_e action ,
                                 char const   *message , gpointer client_data ) ,
                      void *client_data ,
                      void (*report_failure_fcn_p)(char const   * , va_list  ) ,
                      void (*report_open_failure_fcn_p)(char const   * , int  ,
                                                        gboolean  ) ,
                      void (*report_read_failure_fcn_p)(char const   * , int  ) ,
                      void (*report_write_failure_fcn_p)(char const   * , int  ) ) ;
extern void epan_cleanup(void) ;
extern void epan_conversation_init(void) ;
extern void epan_conversation_cleanup(void) ;
extern void epan_circuit_init(void) ;
extern void epan_circuit_cleanup(void) ;
extern epan_t *epan_new(void) ;
extern void epan_free(epan_t * ) ;
extern gchar *epan_get_version(void) ;
extern epan_dissect_t *epan_dissect_init(epan_dissect_t *edt ,
                                         gboolean const   create_proto_tree ,
                                         gboolean const   proto_tree_visible ) ;
extern epan_dissect_t *epan_dissect_new(gboolean const   create_proto_tree ,
                                        gboolean const   proto_tree_visible ) ;
extern void epan_dissect_fake_protocols(epan_dissect_t *edt ,
                                        gboolean const   fake_protocols ) ;
extern void epan_dissect_run(epan_dissect_t *edt , void *pseudo_header ,
                             guint8 const   *data , frame_data *fd ,
                             column_info *cinfo ) ;
extern void epan_dissect_prime_dfilter(epan_dissect_t *edt ,
                                       dfilter_t const   *dfcode ) ;
extern void epan_dissect_fill_in_columns(epan_dissect_t *edt ,
                                         gboolean const   fill_col_exprs ,
                                         gboolean const   fill_fd_colums ) ;
extern void epan_dissect_cleanup(epan_dissect_t *edt ) ;
extern void epan_dissect_free(epan_dissect_t *edt ) ;
extern gchar const   *epan_custom_set(epan_dissect_t *edt , int id ,
                                      gint occurrence , gchar *result ,
                                      gchar *expr , int const   size ) ;
extern void epan_get_compiled_version_info(GString *str ) ;
extern void epan_get_runtime_version_info(GString *str ) ;
extern gboolean proto_can_match_selected(field_info *finfo ,
                                         epan_dissect_t *edt ) ;
extern char *proto_construct_match_selected_string(field_info *finfo ,
                                                   epan_dissect_t *edt ) ;
extern field_info *proto_find_field_from_offset(proto_tree *tree ,
                                                guint offset , tvbuff_t *tvb ) ;
extern proto_item *proto_tree_add_bitmask(proto_tree *tree , tvbuff_t *tvb ,
                                          guint const   offset ,
                                          int const   hf_hdr ,
                                          gint const   ett ,
                                          int const   **fields ,
                                          gboolean const   little_endian ) ;
extern proto_item *proto_tree_add_bitmask_text(proto_tree *tree ,
                                               tvbuff_t *tvb ,
                                               guint const   offset ,
                                               guint const   len ,
                                               char const   *name ,
                                               char const   *fallback ,
                                               gint const   ett ,
                                               int const   **fields ,
                                               gboolean const   little_endian ,
                                               int const   flags ) ;
extern proto_item *proto_tree_add_bits_item(proto_tree *tree ,
                                            int const   hf_index ,
                                            tvbuff_t *tvb ,
                                            gint const   bit_offset ,
                                            gint const   no_of_bits ,
                                            gboolean const   little_endian ) ;
extern proto_item *proto_tree_add_bits_ret_val(proto_tree *tree ,
                                               int const   hf_index ,
                                               tvbuff_t *tvb ,
                                               gint const   bit_offset ,
                                               gint const   no_of_bits ,
                                               guint64 *return_value ,
                                               gboolean const   little_endian ) ;
extern proto_item *( /* format attribute */  proto_tree_add_uint_bits_format_value)(proto_tree *tree ,
                                                                                    int const   hf_index ,
                                                                                    tvbuff_t *tvb ,
                                                                                    gint const   bit_offset ,
                                                                                    gint const   no_of_bits ,
                                                                                    guint32 value ,
                                                                                    char const   *format 
                                                                                    , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_boolean_bits_format_value)(proto_tree *tree ,
                                                                                       int const   hf_index ,
                                                                                       tvbuff_t *tvb ,
                                                                                       gint const   bit_offset ,
                                                                                       gint const   no_of_bits ,
                                                                                       guint32 value ,
                                                                                       char const   *format 
                                                                                       , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_int_bits_format_value)(proto_tree *tree ,
                                                                                   int const   hf_index ,
                                                                                   tvbuff_t *tvb ,
                                                                                   gint const   bit_offset ,
                                                                                   gint const   no_of_bits ,
                                                                                   gint32 value ,
                                                                                   char const   *format 
                                                                                   , ...) ;
extern proto_item *( /* format attribute */  proto_tree_add_float_bits_format_value)(proto_tree *tree ,
                                                                                     int const   hf_index ,
                                                                                     tvbuff_t *tvb ,
                                                                                     gint const   bit_offset ,
                                                                                     gint const   no_of_bits ,
                                                                                     float value ,
                                                                                     char const   *format 
                                                                                     , ...) ;
extern guchar proto_check_field_name(gchar const   *field_name ) ;
extern gchar const   *proto_custom_set(proto_tree *tree , int const   field_id ,
                                       gint occurrence , gchar *result ,
                                       gchar *expr , int const   size ) ;
extern gchar *ep_address_to_str(address const   * ) ;
extern gchar *se_address_to_str(address const   * ) ;
extern void address_to_str_buf(address const   *addr , gchar *buf , int buf_len ) ;
extern gchar *bytestring_to_str(guint8 const   * , guint32 const    ,
                                char const    ) ;
extern gchar *ether_to_str(guint8 const   * ) ;
extern gchar *tvb_ether_to_str(tvbuff_t *tvb , gint const   offset ) ;
extern gchar const   *ip_to_str(guint8 const   * ) ;
extern gchar const   *tvb_ip_to_str(tvbuff_t *tvb , gint const   offset ) ;
extern void ip_to_str_buf(guint8 const   *ad , gchar *buf , int const   buf_len ) ;
extern gchar *fc_to_str(guint8 const   * ) ;
extern gchar *fcwwn_to_str(guint8 const   * ) ;
extern gchar *tvb_fc_to_str(tvbuff_t *tvb , gint const   offset ) ;
extern gchar *tvb_fcwwn_to_str(tvbuff_t *tvb , gint const   offset ) ;
extern gchar *ip6_to_str(struct e_in6_addr  const  * ) ;
extern gchar *tvb_ip6_to_str(tvbuff_t *tvb , gint const   offset ) ;
extern void ip6_to_str_buf(struct e_in6_addr  const  * , gchar * ) ;
extern gchar *ipx_addr_to_str(guint32 const    , guint8 const   * ) ;
extern gchar *ipxnet_to_string(guint8 const   *ad ) ;
extern gchar *ipxnet_to_str_punct(guint32 const   ad , char const   punct ) ;
extern gchar *tvb_vines_addr_to_str(tvbuff_t *tvb , gint const   offset ) ;
extern gchar *eui64_to_str(guint64 const   ad ) ;
extern gchar *tvb_eui64_to_str(tvbuff_t *tvb , gint const   offset ,
                               guint const   encoding ) ;
extern gchar *time_secs_to_str(gint32 const   time_val ) ;
extern gchar *time_secs_to_str_unsigned(guint32 const    ) ;
extern gchar *time_msecs_to_str(gint32 time_val ) ;
extern gchar *abs_time_to_str(nstime_t const   * ,
                              absolute_time_display_e const   fmt ,
                              gboolean show_zone ) ;
extern gchar *abs_time_secs_to_str(time_t const    ,
                                   absolute_time_display_e const   fmt ,
                                   gboolean show_zone ) ;
extern void display_signed_time(gchar * , int  , gint32 const    , gint32  ,
                                to_str_time_res_t const    ) ;
extern void display_epoch_time(gchar * , int  , time_t const    , gint32  ,
                               to_str_time_res_t const    ) ;
extern gchar *guint32_to_str(guint32 const   u ) ;
extern void guint32_to_str_buf(guint32 u , gchar *buf , int buf_len ) ;
extern gchar *rel_time_to_str(nstime_t const   * ) ;
extern gchar *rel_time_to_secs_str(nstime_t const   * ) ;
extern gchar *guid_to_str(e_guid_t const   * ) ;
extern gchar *guid_to_str_buf(e_guid_t const   * , gchar * , int  ) ;
extern char *decode_bits_in_field(gint const   bit_offset ,
                                  gint const   no_of_bits ,
                                  guint64 const   value ) ;
extern char *other_decode_bitfield_value(char *buf , guint32 const   val ,
                                         guint32 const   mask ,
                                         int const   width ) ;
extern char *decode_bitfield_value(char *buf , guint32 const   val ,
                                   guint32 const   mask , int const   width ) ;
extern char const   *decode_boolean_bitfield(guint32 const   val ,
                                             guint32 const   mask ,
                                             int const   width ,
                                             char const   *truedesc ,
                                             char const   *falsedesc ) ;
extern char const   *decode_numeric_bitfield(guint32 const   val ,
                                             guint32 const   mask ,
                                             int const   width ,
                                             char const   *fmt ) ;
extern gchar const   *match_strval_idx(guint32 const   val ,
                                       value_string const   *vs , gint *idx ) ;
extern gchar const   *match_strval(guint32 const   val ,
                                   value_string const   *vs ) ;
extern gchar const   *val_to_str(guint32 const   val ,
                                 value_string const   *vs , char const   *fmt ) ;
extern gchar const   *val_to_str_const(guint32 const   val ,
                                       value_string const   *vs ,
                                       char const   *unknown_str ) ;
extern gchar const   *match_strstr_idx(gchar const   *val ,
                                       string_string const   *vs , gint *idx ) ;
extern gchar const   *match_strstr(gchar const   *val ,
                                   string_string const   *vs ) ;
extern gchar const   *str_to_str(gchar const   *val ,
                                 string_string const   *vs , char const   *fmt ) ;
extern gboolean value_string_ext_validate(value_string_ext const   *vse ) ;
extern gchar const   *value_string_ext_match_type_str(value_string_ext const   *vse ) ;
extern value_string const   *_match_strval_ext_init(guint32 const   val ,
                                                    value_string_ext const   *vse ) ;
extern value_string_ext *value_string_ext_new(value_string *vs ,
                                              guint vs_tot_num_entries ,
                                              gchar *vs_name ) ;
extern gchar const   *match_strval_ext(guint32 const   val ,
                                       value_string_ext const   *vse ) ;
extern gchar const   *match_strval_idx_ext(guint32 const   val ,
                                           value_string_ext *vse , gint *idx ) ;
extern gchar const   *val_to_str_ext(guint32 const   val ,
                                     value_string_ext const   *vs ,
                                     char const   *fmt ) ;
extern gchar const   *val_to_str_ext_const(guint32 const   val ,
                                           value_string_ext const   *vs ,
                                           char const   *unknown_str ) ;
extern char const   *decode_enumerated_bitfield(guint32 const   val ,
                                                guint32 const   mask ,
                                                int const   width ,
                                                value_string const   *tab ,
                                                char const   *fmt ) ;
extern char const   *decode_enumerated_bitfield_shifted(guint32 const   val ,
                                                        guint32 const   mask ,
                                                        int const   width ,
                                                        value_string const   *tab ,
                                                        char const   *fmt ) ;
extern gchar const   *rval_to_str(guint32 const   val ,
                                  range_string const   *rs , char const   *fmt ) ;
extern gchar const   *match_strrval_idx(guint32 const   val ,
                                        range_string const   *rs , gint *idx ) ;
extern gchar const   *match_strrval(guint32 const   val ,
                                    range_string const   *rs ) ;
extern void col_setup(column_info *cinfo , gint const   num_cols ) ;
extern void col_init(column_info *cinfo ) ;
extern void col_set_fmt_time(frame_data const   *fd , column_info *cinfo ,
                             gint const   fmt , gint const   col ) ;
extern void col_fill_in_frame_data(frame_data const   *fd , column_info *cinfo ,
                                   gint const   col ,
                                   gboolean const   fill_col_exprs ) ;
extern void col_fill_in(packet_info *pinfo , gboolean const   fill_col_exprs ,
                        gboolean const   fill_fd_colums ) ;
extern void col_fill_in_error(column_info *cinfo , frame_data *fdata ,
                              gboolean const   fill_col_exprs ,
                              gboolean const   fill_fd_colums ) ;
extern gboolean col_get_writable(column_info *cinfo ) ;
extern void col_set_writable(column_info *cinfo , gboolean const   writable ) ;
extern gint check_col(column_info *cinfo , gint const   col ) ;
extern void col_set_fence(column_info *cinfo , gint const   col ) ;
extern void col_clear(column_info *cinfo , gint const   col ) ;
extern void col_set_str(column_info *cinfo , gint const   col ,
                        gchar const   *str ) ;
extern void col_add_str(column_info *cinfo , gint const   col ,
                        gchar const   *str ) ;
extern void ( /* format attribute */  col_add_fstr)(column_info *cinfo ,
                                                    gint const   col ,
                                                    gchar const   *format  , ...) ;
extern void col_custom_set_edt(epan_dissect_t *edt , column_info *cinfo ) ;
extern void col_custom_prime_edt(epan_dissect_t *edt , column_info *cinfo ) ;
extern gboolean have_custom_cols(column_info *cinfo ) ;
extern gboolean col_has_time_fmt(column_info *cinfo , gint const   col ) ;
extern gboolean col_based_on_frame_data(column_info *cinfo , gint const   col ) ;
extern void col_append_str(column_info *cinfo , gint const   col ,
                           gchar const   *str ) ;
extern void ( /* format attribute */  col_append_fstr)(column_info *cinfo ,
                                                       gint const   col ,
                                                       gchar const   *format 
                                                       , ...) ;
extern void ( /* format attribute */  col_prepend_fstr)(column_info *cinfo ,
                                                        gint const   col ,
                                                        gchar const   *format 
                                                        , ...) ;
extern void ( /* format attribute */  col_prepend_fence_fstr)(column_info *cinfo ,
                                                              gint const   col ,
                                                              gchar const   *format 
                                                              , ...) ;
extern void col_append_sep_str(column_info *cinfo , gint const   col ,
                               gchar const   *sep , gchar const   *str ) ;
extern void ( /* format attribute */  col_append_sep_fstr)(column_info *cinfo ,
                                                           gint const   col ,
                                                           gchar const   *sep ,
                                                           gchar const   *format 
                                                           , ...) ;
extern void col_set_time(column_info *cinfo , int const   col ,
                         nstime_t const   *ts , char *fieldname ) ;
extern true_false_string const   tfs_true_false ;
extern true_false_string const   tfs_yes_no ;
extern true_false_string const   tfs_set_notset ;
extern true_false_string const   tfs_enabled_disabled ;
extern true_false_string const   tfs_ok_error ;
extern true_false_string const   tfs_error_ok ;
extern true_false_string const   tfs_success_fail ;
extern true_false_string const   tfs_fail_success ;
extern true_false_string const   tfs_on_off ;
extern true_false_string const   tfs_ack_nack ;
extern true_false_string const   tfs_odd_even ;
extern true_false_string const   tfs_allow_block ;
extern true_false_string const   tfs_restricted_allowed ;
extern true_false_string const   tfs_accept_reject ;
extern true_false_string const   tfs_more_nomore ;
extern true_false_string const   tfs_present_absent ;
extern true_false_string const   tfs_present_not_present ;
extern true_false_string const   tfs_active_inactive ;
extern true_false_string const   tfs_found_not_found ;
extern true_false_string const   tfs_command_response ;
extern true_false_string const   tfs_capable_not_capable ;
extern true_false_string const   tfs_supported_not_supported ;
extern true_false_string const   tfs_used_notused ;
extern true_false_string const   tfs_high_low ;
extern true_false_string const   tfs_pressed_not_pressed ;
extern true_false_string const   tfs_implemented_not_implemented ;
extern true_false_string const   tfs_requested_not_requested ;
extern true_false_string const   tfs_reliable_not_reliable ;
extern true_false_string const   tfs_allowed_not_allowed ;
extern true_false_string const   tfs_accepted_not_accepted ;
extern true_false_string const   tfs_detected_not_detected ;
extern void packet_init(void) ;
extern void packet_cleanup(void) ;
extern dissector_handle_t dtbl_entry_get_handle(dtbl_entry_t *dtbl_entry ) ;
extern dissector_handle_t dtbl_entry_get_initial_handle(dtbl_entry_t *entry ) ;
extern void dissector_table_foreach_changed(char const   *name ,
                                            void (*func)(gchar const   *table_name ,
                                                         ftenum_t selector_type ,
                                                         gpointer key ,
                                                         gpointer value ,
                                                         gpointer user_data ) ,
                                            gpointer user_data ) ;
extern void dissector_table_foreach(char const   *name ,
                                    void (*func)(gchar const   *table_name ,
                                                 ftenum_t selector_type ,
                                                 gpointer key , gpointer value ,
                                                 gpointer user_data ) ,
                                    gpointer user_data ) ;
extern void dissector_all_tables_foreach_changed(void (*func)(gchar const   *table_name ,
                                                              ftenum_t selector_type ,
                                                              gpointer key ,
                                                              gpointer value ,
                                                              gpointer user_data ) ,
                                                 gpointer user_data ) ;
extern void dissector_table_foreach_handle(char const   *name ,
                                           void (*func)(gchar const   *table_name ,
                                                        gpointer value ,
                                                        gpointer user_data ) ,
                                           gpointer user_data ) ;
extern void dissector_all_tables_foreach_table(void (*func)(gchar const   *table_name ,
                                                            gchar const   *ui_name ,
                                                            gpointer user_data ) ,
                                               gpointer user_data ) ;
extern dissector_table_t register_dissector_table(char const   *name ,
                                                  char const   *ui_name ,
                                                  ftenum_t const   type ,
                                                  int const   base ) ;
extern dissector_table_t find_dissector_table(char const   *name ) ;
extern char const   *get_dissector_table_ui_name(char const   *name ) ;
extern ftenum_t get_dissector_table_selector_type(char const   *name ) ;
extern int get_dissector_table_base(char const   *name ) ;
extern void dissector_add_uint(char const   *abbrev , guint32 const   pattern ,
                               dissector_handle_t handle ) ;
extern void dissector_delete_uint(char const   *name , guint32 const   pattern ,
                                  dissector_handle_t handle ) ;
extern void dissector_change_uint(char const   *abbrev ,
                                  guint32 const   pattern ,
                                  dissector_handle_t handle ) ;
extern void dissector_reset_uint(char const   *name , guint32 const   pattern ) ;
extern gboolean dissector_try_uint(dissector_table_t sub_dissectors ,
                                   guint32 const   uint_val , tvbuff_t *tvb ,
                                   packet_info *pinfo , proto_tree *tree ) ;
extern gboolean dissector_try_uint_new(dissector_table_t sub_dissectors ,
                                       guint32 const   uint_val ,
                                       tvbuff_t *tvb , packet_info *pinfo ,
                                       proto_tree *tree ,
                                       gboolean const   add_proto_name ) ;
extern dissector_handle_t dissector_get_uint_handle(dissector_table_t const   sub_dissectors ,
                                                    guint32 const   uint_val ) ;
extern void dissector_add_string(char const   *name , gchar const   *pattern ,
                                 dissector_handle_t handle ) ;
extern void dissector_delete_string(char const   *name ,
                                    gchar const   *pattern ,
                                    dissector_handle_t handle ) ;
extern void dissector_change_string(char const   *name ,
                                    gchar const   *pattern ,
                                    dissector_handle_t handle ) ;
extern void dissector_reset_string(char const   *name , gchar const   *pattern ) ;
extern gboolean dissector_try_string(dissector_table_t sub_dissectors ,
                                     gchar const   *string , tvbuff_t *tvb ,
                                     packet_info *pinfo , proto_tree *tree ) ;
extern dissector_handle_t dissector_get_string_handle(dissector_table_t sub_dissectors ,
                                                      gchar const   *string ) ;
extern void dissector_add_handle(char const   *name , dissector_handle_t handle ) ;
extern void register_heur_dissector_list(char const   *name ,
                                         heur_dissector_list_t *list ) ;
extern gboolean dissector_try_heuristic(heur_dissector_list_t sub_dissectors ,
                                        tvbuff_t *tvb , packet_info *pinfo ,
                                        proto_tree *tree ) ;
extern void heur_dissector_add(char const   *name ,
                               gboolean (*dissector)(tvbuff_t *tvb ,
                                                     packet_info *pinfo ,
                                                     proto_tree *tree ) ,
                               int const   proto ) ;
extern void heur_dissector_delete(char const   *name ,
                                  gboolean (*dissector)(tvbuff_t *tvb ,
                                                        packet_info *pinfo ,
                                                        proto_tree *tree ) ,
                                  int const   proto ) ;
extern void register_dissector(char const   *name ,
                               void (*dissector)(tvbuff_t * , packet_info * ,
                                                 proto_tree * ) ,
                               int const   proto ) ;
extern void new_register_dissector(char const   *name ,
                                   int (*dissector)(tvbuff_t * , packet_info * ,
                                                    proto_tree * ) ,
                                   int const   proto ) ;
extern char const   *dissector_handle_get_long_name(dissector_handle_t const   handle ) ;
extern char const   *dissector_handle_get_short_name(dissector_handle_t const   handle ) ;
extern int dissector_handle_get_protocol_index(dissector_handle_t const   handle ) ;
extern dissector_handle_t find_dissector(char const   *name ) ;
extern dissector_handle_t create_dissector_handle(void (*dissector)(tvbuff_t * ,
                                                                    packet_info * ,
                                                                    proto_tree * ) ,
                                                  int const   proto ) ;
extern dissector_handle_t new_create_dissector_handle(int (*dissector)(tvbuff_t * ,
                                                                       packet_info * ,
                                                                       proto_tree * ) ,
                                                      int const   proto ) ;
extern int call_dissector(dissector_handle_t handle , tvbuff_t *tvb ,
                          packet_info *pinfo , proto_tree *tree ) ;
extern int call_dissector_only(dissector_handle_t handle , tvbuff_t *tvb ,
                               packet_info *pinfo , proto_tree *tree ) ;
extern void dissect_init(void) ;
extern void dissect_cleanup(void) ;
extern void set_actual_length(tvbuff_t *tvb , guint const   specified_len ) ;
extern void register_init_routine(void (*func)(void) ) ;
extern void init_dissection(void) ;
extern void cleanup_dissection(void) ;
extern void register_postseq_cleanup_routine(void (*func)(void) ) ;
extern void postseq_cleanup_all_protocols(void) ;
extern void register_final_registration_routine(void (*func)(void) ) ;
extern void final_registration_all_protocols(void) ;
extern void add_new_data_source(packet_info *pinfo , tvbuff_t *tvb ,
                                char const   *name ) ;
extern char const   *get_data_source_name(data_source *src ) ;
extern void free_data_sources(packet_info *pinfo ) ;
extern void dissect_packet(epan_dissect_t *edt ,
                           union wtap_pseudo_header *pseudo_header ,
                           guchar const   *pd , frame_data *fd ,
                           column_info *cinfo ) ;
extern void capture_ethertype(guint16 etype , guchar const   *pd , int offset ,
                              int len , packet_counts *ld ) ;
extern void ethertype(guint16 etype , tvbuff_t *tvb ,
                      int offset_after_ethertype , packet_info *pinfo ,
                      proto_tree *tree , proto_tree *fh_tree , int etype_id ,
                      int trailer_id , int fcs_len ) ;
extern void dissector_dump_decodes(void) ;
extern void register_postdissector(dissector_handle_t  ) ;
extern gboolean have_postdissector(void) ;
extern void call_all_postdissectors(tvbuff_t *tvb , packet_info *pinfo ,
                                    proto_tree *tree ) ;
void fragment_table_init(GHashTable **fragment_table ) ;
void dcerpc_fragment_table_init(GHashTable **fragment_table ) ;
void reassembled_table_init(GHashTable **reassembled_table ) ;
void reassemble_cleanup(void) ;
void reassemble_init(void) ;
fragment_data *fragment_add(tvbuff_t *tvb , int const   offset ,
                            packet_info const   *pinfo , guint32 const   id ,
                            GHashTable *fragment_table ,
                            guint32 const   frag_offset ,
                            guint32 const   frag_data_len ,
                            gboolean const   more_frags ) ;
fragment_data *fragment_add_multiple_ok(tvbuff_t *tvb , int const   offset ,
                                        packet_info const   *pinfo ,
                                        guint32 const   id ,
                                        GHashTable *fragment_table ,
                                        guint32 const   frag_offset ,
                                        guint32 const   frag_data_len ,
                                        gboolean const   more_frags ) ;
fragment_data *fragment_add_check(tvbuff_t *tvb , int const   offset ,
                                  packet_info const   *pinfo ,
                                  guint32 const   id ,
                                  GHashTable *fragment_table ,
                                  GHashTable *reassembled_table ,
                                  guint32 const   frag_offset ,
                                  guint32 const   frag_data_len ,
                                  gboolean const   more_frags ) ;
fragment_data *fragment_add_seq_key(tvbuff_t *tvb , int const   offset ,
                                    packet_info const   *pinfo , void *key ,
                                    void *(*key_copier)(void const   *key ) ,
                                    GHashTable *fragment_table ,
                                    guint32 frag_number ,
                                    guint32 const   frag_data_len ,
                                    gboolean const   more_frags ,
                                    guint32 const   flags ) ;
fragment_data *fragment_add_seq(tvbuff_t *tvb , int const   offset ,
                                packet_info const   *pinfo ,
                                guint32 const   id ,
                                GHashTable *fragment_table ,
                                guint32 const   frag_number ,
                                guint32 const   frag_data_len ,
                                gboolean const   more_frags ) ;
fragment_data *fragment_add_dcerpc_dg(tvbuff_t *tvb , int const   offset ,
                                      packet_info const   *pinfo ,
                                      guint32 const   id , void *v_act_id ,
                                      GHashTable *fragment_table ,
                                      guint32 const   frag_number ,
                                      guint32 const   frag_data_len ,
                                      gboolean const   more_frags ) ;
fragment_data *fragment_add_seq_check(tvbuff_t *tvb , int const   offset ,
                                      packet_info const   *pinfo ,
                                      guint32 const   id ,
                                      GHashTable *fragment_table ,
                                      GHashTable *reassembled_table ,
                                      guint32 const   frag_number ,
                                      guint32 const   frag_data_len ,
                                      gboolean const   more_frags ) ;
fragment_data *fragment_add_seq_802_11(tvbuff_t *tvb , int const   offset ,
                                       packet_info const   *pinfo ,
                                       guint32 const   id ,
                                       GHashTable *fragment_table ,
                                       GHashTable *reassembled_table ,
                                       guint32 const   frag_number ,
                                       guint32 const   frag_data_len ,
                                       gboolean const   more_frags ) ;
fragment_data *fragment_add_seq_next(tvbuff_t *tvb , int const   offset ,
                                     packet_info const   *pinfo ,
                                     guint32 const   id ,
                                     GHashTable *fragment_table ,
                                     GHashTable *reassembled_table ,
                                     guint32 const   frag_data_len ,
                                     gboolean const   more_frags ) ;
void fragment_start_seq_check(packet_info const   *pinfo , guint32 const   id ,
                              GHashTable *fragment_table ,
                              guint32 const   tot_len ) ;
fragment_data *fragment_end_seq_next(packet_info const   *pinfo ,
                                     guint32 const   id ,
                                     GHashTable *fragment_table ,
                                     GHashTable *reassembled_table ) ;
void fragment_set_tot_len(packet_info const   *pinfo , guint32 const   id ,
                          GHashTable *fragment_table , guint32 const   tot_len ) ;
guint32 fragment_get_tot_len(packet_info const   *pinfo , guint32 const   id ,
                             GHashTable *fragment_table ) ;
void fragment_set_partial_reassembly(packet_info const   *pinfo ,
                                     guint32 const   id ,
                                     GHashTable *fragment_table ) ;
fragment_data *fragment_get(packet_info const   *pinfo , guint32 const   id ,
                            GHashTable *fragment_table ) ;
fragment_data *fragment_get_reassembled(guint32 const   id ,
                                        GHashTable *reassembled_table ) ;
fragment_data *fragment_get_reassembled_id(packet_info const   *pinfo ,
                                           guint32 const   id ,
                                           GHashTable *reassembled_table ) ;
unsigned char *fragment_delete(packet_info const   *pinfo , guint32 const   id ,
                               GHashTable *fragment_table ) ;
tvbuff_t *process_reassembled_data(tvbuff_t *tvb , int const   offset ,
                                   packet_info *pinfo , char const   *name ,
                                   fragment_data *fd_head ,
                                   fragment_items const   *fit ,
                                   gboolean *update_col_infop ,
                                   proto_tree *tree ) ;
gboolean show_fragment_tree(fragment_data *fd_head ,
                            fragment_items const   *fit , proto_tree *tree ,
                            packet_info *pinfo , tvbuff_t *tvb ,
                            proto_item **fi ) ;
gboolean show_fragment_seq_tree(fragment_data *fd_head ,
                                fragment_items const   *fit , proto_tree *tree ,
                                packet_info *pinfo , tvbuff_t *tvb ,
                                proto_item **fi ) ;
extern void conversation_cleanup(void) ;
extern void conversation_init(void) ;
extern conversation_t *conversation_new(guint32 const   setup_frame ,
                                        address const   *addr1 ,
                                        address const   *addr2 ,
                                        port_type const   ptype ,
                                        guint32 const   port1 ,
                                        guint32 const   port2 ,
                                        guint const   options ) ;
extern conversation_t *find_conversation(guint32 const   frame_num ,
                                         address const   *addr_a ,
                                         address const   *addr_b ,
                                         port_type const   ptype ,
                                         guint32 const   port_a ,
                                         guint32 const   port_b ,
                                         guint const   options ) ;
extern conversation_t *find_or_create_conversation(packet_info *pinfo ) ;
extern void conversation_add_proto_data(conversation_t *conv ,
                                        int const   proto , void *proto_data ) ;
extern void *conversation_get_proto_data(conversation_t const   *conv ,
                                         int const   proto ) ;
extern void conversation_delete_proto_data(conversation_t *conv ,
                                           int const   proto ) ;
extern void conversation_set_dissector(conversation_t *conversation ,
                                       dissector_handle_t const   handle ) ;
extern gboolean try_conversation_dissector(address const   *addr_a ,
                                           address const   *addr_b ,
                                           port_type const   ptype ,
                                           guint32 const   port_a ,
                                           guint32 const   port_b ,
                                           tvbuff_t *tvb , packet_info *pinfo ,
                                           proto_tree *tree ) ;
extern void conversation_set_port2(conversation_t *conv , guint32 const   port ) ;
extern void conversation_set_addr2(conversation_t *conv , address const   *addr ) ;
extern guint16 dcerpc_tvb_get_ntohs(tvbuff_t *tvb , gint offset , guint8 *drep ) ;
extern guint32 dcerpc_tvb_get_ntohl(tvbuff_t *tvb , gint offset , guint8 *drep ) ;
extern void dcerpc_tvb_get_uuid(tvbuff_t *tvb , gint offset , guint8 *drep ,
                                e_uuid_t *uuid ) ;
extern int dissect_dcerpc_uint8(tvbuff_t *tvb , gint offset ,
                                packet_info *pinfo , proto_tree *tree ,
                                guint8 *drep , int hfindex , guint8 *pdata ) ;
extern int dissect_dcerpc_uint16(tvbuff_t *tvb , gint offset ,
                                 packet_info *pinfo , proto_tree *tree ,
                                 guint8 *drep , int hfindex , guint16 *pdata ) ;
extern int dissect_dcerpc_uint32(tvbuff_t *tvb , gint offset ,
                                 packet_info *pinfo , proto_tree *tree ,
                                 guint8 *drep , int hfindex , guint32 *pdata ) ;
extern int dissect_dcerpc_uint64(tvbuff_t *tvb , gint offset ,
                                 packet_info *pinfo , proto_tree *tree ,
                                 guint8 *drep , int hfindex , guint64 *pdata ) ;
extern int dissect_dcerpc_float(tvbuff_t *tvb , gint offset ,
                                packet_info *pinfo , proto_tree *tree ,
                                guint8 *drep , int hfindex , gfloat *pdata ) ;
extern int dissect_dcerpc_double(tvbuff_t *tvb , gint offset ,
                                 packet_info *pinfo , proto_tree *tree ,
                                 guint8 *drep , int hfindex , gdouble *pdata ) ;
extern int dissect_dcerpc_time_t(tvbuff_t *tvb , gint offset ,
                                 packet_info *pinfo , proto_tree *tree ,
                                 guint8 *drep , int hfindex , guint32 *pdata ) ;
extern int dissect_dcerpc_uuid_t(tvbuff_t *tvb , gint offset ,
                                 packet_info *pinfo , proto_tree *tree ,
                                 guint8 *drep , int hfindex , e_uuid_t *pdata ) ;
extern int dissect_ndr_uint8(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                             proto_tree *tree , guint8 *drep , int hfindex ,
                             guint8 *pdata ) ;
extern int PIDL_dissect_uint8(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                              proto_tree *tree , guint8 *drep , int hfindex ,
                              guint32 param ) ;
extern int dissect_ndr_uint16(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                              proto_tree *tree , guint8 *drep , int hfindex ,
                              guint16 *pdata ) ;
extern int PIDL_dissect_uint16(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , int hfindex , guint32 param ) ;
extern int dissect_ndr_uint32(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                              proto_tree *tree , guint8 *drep , int hfindex ,
                              guint32 *pdata ) ;
extern int PIDL_dissect_uint32(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , int hfindex , guint32 param ) ;
extern int dissect_ndr_duint32(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , int hfindex , guint64 *pdata ) ;
extern int dissect_ndr_uint64(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                              proto_tree *tree , guint8 *drep , int hfindex ,
                              guint64 *pdata ) ;
extern int PIDL_dissect_uint64(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , int hfindex , guint32 param ) ;
extern int dissect_ndr_float(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                             proto_tree *tree , guint8 *drep , int hfindex ,
                             gfloat *pdata ) ;
extern int dissect_ndr_double(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                              proto_tree *tree , guint8 *drep , int hfindex ,
                              gdouble *pdata ) ;
extern int dissect_ndr_time_t(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                              proto_tree *tree , guint8 *drep , int hfindex ,
                              guint32 *pdata ) ;
extern int dissect_ndr_uuid_t(tvbuff_t *tvb , gint offset , packet_info *pinfo ,
                              proto_tree *tree , guint8 *drep , int hfindex ,
                              e_uuid_t *pdata ) ;
extern int dissect_ndr_ctx_hnd(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , int hfindex , e_ctx_hnd *pdata ) ;
extern int dissect_ndr_uint1632(tvbuff_t *tvb , gint offset ,
                                packet_info *pinfo , proto_tree *tree ,
                                guint8 *drep , int hfindex , guint1632 *pdata ) ;
extern int dissect_ndr_uint3264(tvbuff_t *tvb , gint offset ,
                                packet_info *pinfo , proto_tree *tree ,
                                guint8 *drep , int hfindex , guint3264 *pdata ) ;
extern int dissect_ndr_pointer_cb(tvbuff_t *tvb , gint offset ,
                                  packet_info *pinfo , proto_tree *tree ,
                                  guint8 *drep , dcerpc_dissect_fnct_t *fnct ,
                                  int type , char const   *text , int hf_index ,
                                  dcerpc_callback_fnct_t *callback ,
                                  void *callback_args ) ;
extern int dissect_ndr_pointer(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , dcerpc_dissect_fnct_t *fnct ,
                               int type , char const   *text , int hf_index ) ;
extern int dissect_deferred_pointers(packet_info *pinfo , tvbuff_t *tvb ,
                                     int offset , guint8 *drep ) ;
extern int dissect_ndr_embedded_pointer(tvbuff_t *tvb , gint offset ,
                                        packet_info *pinfo , proto_tree *tree ,
                                        guint8 *drep ,
                                        dcerpc_dissect_fnct_t *fnct , int type ,
                                        char const   *text , int hf_index ) ;
extern int dissect_ndr_toplevel_pointer(tvbuff_t *tvb , gint offset ,
                                        packet_info *pinfo , proto_tree *tree ,
                                        guint8 *drep ,
                                        dcerpc_dissect_fnct_t *fnct , int type ,
                                        char const   *text , int hf_index ) ;
extern int dissect_ndr_ucarray(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , dcerpc_dissect_fnct_t *fnct ) ;
extern int dissect_ndr_ucvarray(tvbuff_t *tvb , gint offset ,
                                packet_info *pinfo , proto_tree *tree ,
                                guint8 *drep , dcerpc_dissect_fnct_t *fnct ) ;
extern int dissect_ndr_uvarray(tvbuff_t *tvb , gint offset ,
                               packet_info *pinfo , proto_tree *tree ,
                               guint8 *drep , dcerpc_dissect_fnct_t *fnct ) ;
extern int dissect_ndr_byte_array(tvbuff_t *tvb , int offset ,
                                  packet_info *pinfo , proto_tree *tree ,
                                  guint8 *drep ) ;
extern int dissect_ndr_cvstring(tvbuff_t *tvb , int offset ,
                                packet_info *pinfo , proto_tree *tree ,
                                guint8 *drep , int size_is , int hfinfo ,
                                gboolean add_subtree , char **data ) ;
extern int dissect_ndr_char_cvstring(tvbuff_t *tvb , int offset ,
                                     packet_info *pinfo , proto_tree *tree ,
                                     guint8 *drep ) ;
extern int dissect_ndr_wchar_cvstring(tvbuff_t *tvb , int offset ,
                                      packet_info *pinfo , proto_tree *tree ,
                                      guint8 *drep ) ;
extern int PIDL_dissect_cvstring(tvbuff_t *tvb , int offset ,
                                 packet_info *pinfo , proto_tree *tree ,
                                 guint8 *drep , int chsize , int hfindex ,
                                 guint32 param ) ;
extern int dissect_ndr_vstring(tvbuff_t *tvb , int offset , packet_info *pinfo ,
                               proto_tree *tree , guint8 *drep , int size_is ,
                               int hfinfo , gboolean add_subtree , char **data ) ;
extern int dissect_ndr_char_vstring(tvbuff_t *tvb , int offset ,
                                    packet_info *pinfo , proto_tree *tree ,
                                    guint8 *drep ) ;
extern int dissect_ndr_wchar_vstring(tvbuff_t *tvb , int offset ,
                                     packet_info *pinfo , proto_tree *tree ,
                                     guint8 *drep ) ;
extern void dcerpc_init_uuid(int proto , int ett , e_uuid_t *uuid ,
                             guint16 ver , dcerpc_sub_dissector *procs ,
                             int opnum_hf ) ;
extern char const   *dcerpc_get_proto_name(e_uuid_t *uuid , guint16 ver ) ;
extern int dcerpc_get_proto_hf_opnum(e_uuid_t *uuid , guint16 ver ) ;
extern dcerpc_sub_dissector *dcerpc_get_proto_sub_dissector(e_uuid_t *uuid ,
                                                            guint16 ver ) ;
extern value_string *value_string_from_subdissectors(dcerpc_sub_dissector *sd ) ;
extern GHookList dcerpc_hooks_init_protos ;
extern GHashTable *dcerpc_uuids ;
extern void register_dcerpc_auth_subdissector(guint8 auth_level ,
                                              guint8 auth_type ,
                                              dcerpc_auth_subdissector_fns *fns ) ;
extern struct _dcerpc_bind_value *dcerpc_add_conv_to_bind_table(decode_dcerpc_bind_values_t *binding ) ;
extern guint16 dcerpc_get_transport_salt(packet_info *pinfo ) ;
extern void init_ndr_pointer_list(packet_info *pinfo ) ;
extern int hf_dcerpc_drep_byteorder ;
static void LINK_FRAG(fragment_data *fd_head , fragment_data *fd ) 
{ 
  fragment_data *fd_i ;

  {
  fd_i = fd_head;





  while (fd_i->next) {



    if (fd->offset < (fd_i->next)->offset) {
      break;
    } else {

    }


    fd_i = fd_i->next;

  }




  fd->next = fd_i->next;

  fd_i->next = fd;

  return;
}
}
static void *fragment_key_copy(void const   *k ) 
{ 
  fragment_key const   *key ;
  fragment_key *new_key ;
  gpointer tmp ;
  guint8 *COPY_ADDRESS_data ;
  gpointer tmp___0 ;
  guint8 *COPY_ADDRESS_data___0 ;
  gpointer tmp___1 ;

  {
  key = (fragment_key const   *)k;



  tmp = g_slice_alloc(sizeof(fragment_key ));


  new_key = (fragment_key *)tmp;

  new_key->src.type = (address_type )key->src.type;

  new_key->src.len = (int )key->src.len;



  tmp___0 = g_malloc((gsize )key->src.len);


  COPY_ADDRESS_data = (guint8 *)tmp___0;


  memcpy((void */* __restrict  */)COPY_ADDRESS_data,
         (void const   */* __restrict  */)key->src.data, (size_t )key->src.len);

  new_key->src.data = (void const   *)COPY_ADDRESS_data;

  new_key->dst.type = (address_type )key->dst.type;

  new_key->dst.len = (int )key->dst.len;



  tmp___1 = g_malloc((gsize )key->dst.len);


  COPY_ADDRESS_data___0 = (guint8 *)tmp___1;


  memcpy((void */* __restrict  */)COPY_ADDRESS_data___0,
         (void const   */* __restrict  */)key->dst.data, (size_t )key->dst.len);

  new_key->dst.data = (void const   *)COPY_ADDRESS_data___0;

  new_key->id = (guint32 )key->id;

  return ((void *)new_key);
}
}
static void *dcerpc_fragment_key_copy(void const   *k ) 
{ 
  dcerpc_fragment_key const   *key ;
  dcerpc_fragment_key *new_key ;
  gpointer tmp ;
  guint8 *COPY_ADDRESS_data ;
  gpointer tmp___0 ;
  guint8 *COPY_ADDRESS_data___0 ;
  gpointer tmp___1 ;

  {
  key = (dcerpc_fragment_key const   *)k;



  tmp = g_slice_alloc(sizeof(dcerpc_fragment_key ));


  new_key = (dcerpc_fragment_key *)tmp;

  new_key->src.type = (address_type )key->src.type;

  new_key->src.len = (int )key->src.len;



  tmp___0 = g_malloc((gsize )key->src.len);


  COPY_ADDRESS_data = (guint8 *)tmp___0;


  memcpy((void */* __restrict  */)COPY_ADDRESS_data,
         (void const   */* __restrict  */)key->src.data, (size_t )key->src.len);

  new_key->src.data = (void const   *)COPY_ADDRESS_data;

  new_key->dst.type = (address_type )key->dst.type;

  new_key->dst.len = (int )key->dst.len;



  tmp___1 = g_malloc((gsize )key->dst.len);


  COPY_ADDRESS_data___0 = (guint8 *)tmp___1;


  memcpy((void */* __restrict  */)COPY_ADDRESS_data___0,
         (void const   */* __restrict  */)key->dst.data, (size_t )key->dst.len);

  new_key->dst.data = (void const   *)COPY_ADDRESS_data___0;

  new_key->id = (guint32 )key->id;

  new_key->act_id = (e_uuid_t )key->act_id;

  return ((void *)new_key);
}
}
static gint fragment_equal(gconstpointer k1 , gconstpointer k2 ) 
{ 
  fragment_key const   *key1 ;
  fragment_key const   *key2 ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;

  {
  key1 = (fragment_key const   *)k1;

  key2 = (fragment_key const   *)k2;



  if (key1->id == key2->id) {
    if ((unsigned int const   )key1->src.type == (unsigned int const   )key2->src.type) {
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "334",
                      "0", checkpoints_buf);
      if ((unsigned int const   )key1->src.type == 0U) {
        goto _L;
      } else {


        if (key1->src.len == key2->src.len) {
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "337", "tmp___2", checkpoints_buf);

          tmp___2 = memcmp((void const   *)key1->src.data,
                           (void const   *)key2->src.data,
                           (size_t )key1->src.len);
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "337", "tmp___2", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "338", "tmp___2", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "338", "0", checkpoints_buf);
          if (tmp___2 == 0) {
            _L: /* CIL Label */ 
            if ((unsigned int const   )key1->dst.type == (unsigned int const   )key2->dst.type) {
              sprintf(checkpoints_buf, "%u", 0);
              checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                              "340", "0", checkpoints_buf);
              if ((unsigned int const   )key1->dst.type == 0U) {
                tmp___1 = 1;
                sprintf(checkpoints_buf, "%d", tmp___1);
                checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                "341", "tmp___1", checkpoints_buf);
              } else {


                if (key1->dst.len == key2->dst.len) {
                  sprintf(checkpoints_buf, "%d", tmp___3);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "343", "tmp___3", checkpoints_buf);

                  tmp___3 = memcmp((void const   *)key1->dst.data,
                                   (void const   *)key2->dst.data,
                                   (size_t )key1->dst.len);
                  sprintf(checkpoints_buf, "%d", tmp___3);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "343", "tmp___3", checkpoints_buf);

                  sprintf(checkpoints_buf, "%d", tmp___3);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "344", "tmp___3", checkpoints_buf);
                  sprintf(checkpoints_buf, "%d", 0);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "344", "0", checkpoints_buf);
                  if (tmp___3 == 0) {
                    tmp___1 = 1;
                    sprintf(checkpoints_buf, "%d", tmp___1);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "345", "tmp___1", checkpoints_buf);
                  } else {
                    tmp___1 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___1);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "346", "tmp___1", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%d", tmp___3);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "344", "tmp___3", checkpoints_buf);
                  sprintf(checkpoints_buf, "%d", 0);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "344", "0", checkpoints_buf);
                } else {
                  tmp___1 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___1);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "347", "tmp___1", checkpoints_buf);
                }


              }
              sprintf(checkpoints_buf, "%u", 0);
              checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                              "340", "0", checkpoints_buf);
            } else {
              tmp___1 = 0;
              sprintf(checkpoints_buf, "%d", tmp___1);
              checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                              "348", "tmp___1", checkpoints_buf);
            }
          } else {
            tmp___1 = 0;
            sprintf(checkpoints_buf, "%d", tmp___1);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "349", "tmp___1", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "338", "tmp___2", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "338", "0", checkpoints_buf);
        } else {
          tmp___1 = 0;
          sprintf(checkpoints_buf, "%d", tmp___1);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "350", "tmp___1", checkpoints_buf);
        }


      }
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "334",
                      "0", checkpoints_buf);
    } else {
      tmp___1 = 0;
      sprintf(checkpoints_buf, "%d", tmp___1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "351",
                      "tmp___1", checkpoints_buf);
    }
  } else {
    tmp___1 = 0;
    sprintf(checkpoints_buf, "%d", tmp___1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "352",
                    "tmp___1", checkpoints_buf);
  }


  sprintf(checkpoints_buf, "%d", tmp___1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "353",
                  "tmp___1", checkpoints_buf);
  return (tmp___1);
}
}
static guint fragment_hash(gconstpointer k ) 
{ 
  fragment_key const   *key ;
  guint hash_val ;

  {
  key = (fragment_key const   *)k;

  hash_val = (guint )0;

  hash_val += (guint )key->id;


  return (hash_val);
}
}
static gint dcerpc_fragment_equal(gconstpointer k1 , gconstpointer k2 ) 
{ 
  dcerpc_fragment_key const   *key1 ;
  dcerpc_fragment_key const   *key2 ;
  int tmp ;
  int tmp___0 ;
  int tmp___1 ;
  int tmp___2 ;
  int tmp___3 ;
  int tmp___4 ;
  int tmp___5 ;

  {
  key1 = (dcerpc_fragment_key const   *)k1;

  key2 = (dcerpc_fragment_key const   *)k2;



  if (key1->id == key2->id) {
    if ((unsigned int const   )key1->src.type == (unsigned int const   )key2->src.type) {
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "362",
                      "0", checkpoints_buf);
      if ((unsigned int const   )key1->src.type == 0U) {
        goto _L___0;
      } else {


        if (key1->src.len == key2->src.len) {
          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "365", "tmp___3", checkpoints_buf);

          tmp___3 = memcmp((void const   *)key1->src.data,
                           (void const   *)key2->src.data,
                           (size_t )key1->src.len);
          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "365", "tmp___3", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "366", "tmp___3", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "366", "0", checkpoints_buf);
          if (tmp___3 == 0) {
            _L___0: /* CIL Label */ 
            if ((unsigned int const   )key1->dst.type == (unsigned int const   )key2->dst.type) {
              sprintf(checkpoints_buf, "%u", 0);
              checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                              "368", "0", checkpoints_buf);
              if ((unsigned int const   )key1->dst.type == 0U) {
                goto _L;
              } else {


                if (key1->dst.len == key2->dst.len) {
                  sprintf(checkpoints_buf, "%d", tmp___4);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "371", "tmp___4", checkpoints_buf);

                  tmp___4 = memcmp((void const   *)key1->dst.data,
                                   (void const   *)key2->dst.data,
                                   (size_t )key1->dst.len);
                  sprintf(checkpoints_buf, "%d", tmp___4);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "371", "tmp___4", checkpoints_buf);

                  sprintf(checkpoints_buf, "%d", tmp___4);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "372", "tmp___4", checkpoints_buf);
                  sprintf(checkpoints_buf, "%d", 0);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "372", "0", checkpoints_buf);
                  if (tmp___4 == 0) {
                    sprintf(checkpoints_buf, "%d", tmp___5);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "373", "tmp___5", checkpoints_buf);

                    _L: /* CIL Label */ 
                    tmp___5 = memcmp((void const   *)(& key1->act_id),
                                     (void const   *)(& key2->act_id),
                                     sizeof(e_uuid_t ));
                    sprintf(checkpoints_buf, "%d", tmp___5);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "373", "tmp___5", checkpoints_buf);

                    sprintf(checkpoints_buf, "%d", tmp___5);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "374", "tmp___5", checkpoints_buf);
                    sprintf(checkpoints_buf, "%d", 0);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "374", "0", checkpoints_buf);
                    if (tmp___5 == 0) {
                      tmp___2 = 1;
                      sprintf(checkpoints_buf, "%d", tmp___2);
                      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                      "375", "tmp___2", checkpoints_buf);
                    } else {
                      tmp___2 = 0;
                      sprintf(checkpoints_buf, "%d", tmp___2);
                      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                      "376", "tmp___2", checkpoints_buf);
                    }
                    sprintf(checkpoints_buf, "%d", tmp___5);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "374", "tmp___5", checkpoints_buf);
                    sprintf(checkpoints_buf, "%d", 0);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "374", "0", checkpoints_buf);
                  } else {
                    tmp___2 = 0;
                    sprintf(checkpoints_buf, "%d", tmp___2);
                    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                    "377", "tmp___2", checkpoints_buf);
                  }
                  sprintf(checkpoints_buf, "%d", tmp___4);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "372", "tmp___4", checkpoints_buf);
                  sprintf(checkpoints_buf, "%d", 0);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "372", "0", checkpoints_buf);
                } else {
                  tmp___2 = 0;
                  sprintf(checkpoints_buf, "%d", tmp___2);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "378", "tmp___2", checkpoints_buf);
                }


              }
              sprintf(checkpoints_buf, "%u", 0);
              checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                              "368", "0", checkpoints_buf);
            } else {
              tmp___2 = 0;
              sprintf(checkpoints_buf, "%d", tmp___2);
              checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                              "379", "tmp___2", checkpoints_buf);
            }
          } else {
            tmp___2 = 0;
            sprintf(checkpoints_buf, "%d", tmp___2);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "380", "tmp___2", checkpoints_buf);
          }
          sprintf(checkpoints_buf, "%d", tmp___3);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "366", "tmp___3", checkpoints_buf);
          sprintf(checkpoints_buf, "%d", 0);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "366", "0", checkpoints_buf);
        } else {
          tmp___2 = 0;
          sprintf(checkpoints_buf, "%d", tmp___2);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "381", "tmp___2", checkpoints_buf);
        }


      }
      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "362",
                      "0", checkpoints_buf);
    } else {
      tmp___2 = 0;
      sprintf(checkpoints_buf, "%d", tmp___2);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "382",
                      "tmp___2", checkpoints_buf);
    }
  } else {
    tmp___2 = 0;
    sprintf(checkpoints_buf, "%d", tmp___2);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "383",
                    "tmp___2", checkpoints_buf);
  }


  sprintf(checkpoints_buf, "%d", tmp___2);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "384",
                  "tmp___2", checkpoints_buf);
  return (tmp___2);
}
}
static guint dcerpc_fragment_hash(gconstpointer k ) 
{ 
  dcerpc_fragment_key const   *key ;
  guint hash_val ;

  {
  key = (dcerpc_fragment_key const   *)k;

  hash_val = (guint )0;

  hash_val += (guint )key->id;

  hash_val += (guint )key->act_id.Data1;

  hash_val += (guint )((int const   )key->act_id.Data2 << 16);

  hash_val += (guint )key->act_id.Data3;


  return (hash_val);
}
}
static gint reassembled_equal(gconstpointer k1 , gconstpointer k2 ) 
{ 
  reassembled_key const   *key1 ;
  reassembled_key const   *key2 ;
  int tmp ;

  {
  key1 = (reassembled_key const   *)k1;

  key2 = (reassembled_key const   *)k2;



  if (key1->frame == key2->frame) {


    if (key1->id == key2->id) {
      tmp = 1;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "396",
                      "tmp", checkpoints_buf);
    } else {
      tmp = 0;
      sprintf(checkpoints_buf, "%d", tmp);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "397",
                      "tmp", checkpoints_buf);
    }


  } else {
    tmp = 0;
    sprintf(checkpoints_buf, "%d", tmp);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "398",
                    "tmp", checkpoints_buf);
  }


  sprintf(checkpoints_buf, "%d", tmp);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "399", "tmp",
                  checkpoints_buf);
  return (tmp);
}
}
static guint reassembled_hash(gconstpointer k ) 
{ 
  reassembled_key const   *key ;

  {
  key = (reassembled_key const   *)k;

  return ((guint )key->frame);
}
}
static gboolean free_all_fragments(gpointer key_arg  __attribute__((__unused__)) ,
                                   gpointer value ,
                                   gpointer user_data  __attribute__((__unused__)) ) 
{ 
  fragment_data *fd_head ;
  fragment_data *tmp_fd ;

  {
  fd_head = (fragment_data *)value;





  while ((unsigned int )fd_head != (unsigned int )((void *)0)) {
    tmp_fd = fd_head->next;


    if (fd_head->data) {

      sprintf(checkpoints_buf, "%u", 32);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "409",
                      "32", checkpoints_buf);
      if (! (fd_head->flags & 32U)) {

        g_free((gpointer )fd_head->data);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 32);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "409",
                      "32", checkpoints_buf);
    } else {

    }


    while (1) {

      g_slice_free1(sizeof(fragment_data ), (gpointer )fd_head);

      break;
    }

    fd_head = tmp_fd;

  }





}
}
static fragment_data *new_head(guint32 const   flags ) 
{ 
  fragment_data *fd_head ;
  gpointer tmp ;

  {


  tmp = g_slice_alloc0(sizeof(fragment_data ));


  fd_head = (fragment_data *)tmp;

  fd_head->flags = (guint32 )flags;


  return (fd_head);
}
}
static gboolean free_all_reassembled_fragments(gpointer key_arg ,
                                               gpointer value ,
                                               gpointer user_data  __attribute__((__unused__)) ) 
{ 
  fragment_data *fd_head ;
  fragment_data *tmp_fd ;
  reassembled_key *key ;

  {
  key = (reassembled_key *)key_arg;

  fd_head = (fragment_data *)value;






  while ((unsigned int )fd_head != (unsigned int )((void *)0)) {
    tmp_fd = fd_head->next;


    if (fd_head->data) {

      sprintf(checkpoints_buf, "%u", 32);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "430",
                      "32", checkpoints_buf);
      if (! (fd_head->flags & 32U)) {

        g_free((gpointer )fd_head->data);

        fd_head->data = (unsigned char *)((void *)0);

      } else {

      }

      sprintf(checkpoints_buf, "%u", 32);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "430",
                      "32", checkpoints_buf);
    } else {
      return (1);
    }



    if (key->frame == fd_head->reassembled_in) {

      while (1) {

        g_slice_free1(sizeof(fragment_data ), (gpointer )fd_head);

        break;
      }

    } else {

    }


    fd_head = tmp_fd;

  }





  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "441", "1",
                  checkpoints_buf);
  return (1);
}
}
static void fragment_free_key(void *ptr ) 
{ 
  fragment_key *key ;

  {
  key = (fragment_key *)ptr;


  if (key) {

    g_free((gpointer )key->src.data);


    g_free((gpointer )key->dst.data);


    while (1) {

      g_slice_free1(sizeof(fragment_key ), (gpointer )key);

      break;
    }

  } else {

  }

  return;
}
}
static void dcerpc_fragment_free_key(void *ptr ) 
{ 
  dcerpc_fragment_key *key ;

  {
  key = (dcerpc_fragment_key *)ptr;


  if (key) {

    g_free((gpointer )key->src.data);


    g_free((gpointer )key->dst.data);


    while (1) {

      g_slice_free1(sizeof(dcerpc_fragment_key ), (gpointer )key);

      break;
    }

  } else {

  }

  return;
}
}
static void reassembled_key_free(void *ptr ) 
{ 
  reassembled_key *key ;

  {
  key = (reassembled_key *)ptr;


  while (1) {

    g_slice_free1(sizeof(reassembled_key ), (gpointer )key);

    break;
  }

  return;
}
}
void fragment_table_init(GHashTable **fragment_table ) 
{ 


  {
  if ((unsigned int )*fragment_table != (unsigned int )((void *)0)) {

    g_hash_table_foreach_remove(*fragment_table, & free_all_fragments, (void *)0);

  } else {


    *fragment_table = g_hash_table_new_full(& fragment_hash, & fragment_equal,
                                            & fragment_free_key,
                                            (void (*)(gpointer data ))((void *)0));


  }
  return;
}
}
void dcerpc_fragment_table_init(GHashTable **fragment_table ) 
{ 


  {
  if ((unsigned int )*fragment_table != (unsigned int )((void *)0)) {

    g_hash_table_foreach_remove(*fragment_table, & free_all_fragments, (void *)0);

  } else {


    *fragment_table = g_hash_table_new_full(& dcerpc_fragment_hash,
                                            & dcerpc_fragment_equal,
                                            & dcerpc_fragment_free_key,
                                            (void (*)(gpointer data ))((void *)0));


  }
  return;
}
}
void reassembled_table_init(GHashTable **reassembled_table ) 
{ 


  {
  if ((unsigned int )*reassembled_table != (unsigned int )((void *)0)) {

    g_hash_table_foreach_remove(*reassembled_table,
                                & free_all_reassembled_fragments, (void *)0);

  } else {


    *reassembled_table = g_hash_table_new_full(& reassembled_hash,
                                               & reassembled_equal,
                                               & reassembled_key_free,
                                               (void (*)(gpointer data ))((void *)0));


  }
  return;
}
}
void reassemble_cleanup(void) 
{ 


  {
  return;
}
}
void reassemble_init(void) 
{ 


  {
  return;
}
}
unsigned char *fragment_delete(packet_info const   *pinfo , guint32 const   id ,
                               GHashTable *fragment_table ) 
{ 
  fragment_data *fd_head ;
  fragment_data *fd ;
  fragment_key key ;
  unsigned char *data ;
  gpointer tmp ;
  fragment_data *tmp_fd ;

  {
  data = (unsigned char *)((void *)0);

  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;

  if ((unsigned int )fd_head == (unsigned int )((void *)0)) {
    return ((unsigned char *)((void *)0));
  } else {

  }
  data = fd_head->data;

  fd = fd_head->next;




  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "490", "32",
                  checkpoints_buf);


  while (fd) {

    tmp_fd = fd->next;


    sprintf(checkpoints_buf, "%u", 32);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "495",
                    "32", checkpoints_buf);
    if (! (fd->flags & 32U)) {

      g_free((gpointer )fd->data);

    } else {

    }

    sprintf(checkpoints_buf, "%u", 32);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "495",
                    "32", checkpoints_buf);

    while (1) {

      g_slice_free1(sizeof(fragment_data ), (gpointer )fd);

      break;
    }

    fd = tmp_fd;

  }



  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "490", "32",
                  checkpoints_buf);



  while (1) {

    g_slice_free1(sizeof(fragment_data ), (gpointer )fd_head);

    break;
  }


  g_hash_table_remove(fragment_table, (gconstpointer )(& key));


  return (data);
}
}
fragment_data *fragment_get(packet_info const   *pinfo , guint32 const   id ,
                            GHashTable *fragment_table ) 
{ 
  fragment_data *fd_head ;
  fragment_key key ;
  gpointer tmp ;

  {
  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;


  return (fd_head);
}
}
fragment_data *fragment_get_reassembled(guint32 const   id ,
                                        GHashTable *reassembled_table ) 
{ 
  fragment_data *fd_head ;
  reassembled_key key ;
  gpointer tmp ;

  {
  key.frame = (guint32 )id;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(reassembled_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;


  return (fd_head);
}
}
fragment_data *fragment_get_reassembled_id(packet_info const   *pinfo ,
                                           guint32 const   id ,
                                           GHashTable *reassembled_table ) 
{ 
  fragment_data *fd_head ;
  reassembled_key key ;
  gpointer tmp ;

  {
  key.frame = (pinfo->fd)->num;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(reassembled_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;


  return (fd_head);
}
}
void fragment_set_tot_len(packet_info const   *pinfo , guint32 const   id ,
                          GHashTable *fragment_table , guint32 const   tot_len ) 
{ 
  fragment_data *fd_head ;
  fragment_key key ;
  gpointer tmp ;

  {
  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;


  if (fd_head) {
    fd_head->datalen = (guint32 )tot_len;

    fd_head->flags |= 1024U;

  } else {

  }

  return;
}
}
guint32 fragment_get_tot_len(packet_info const   *pinfo , guint32 const   id ,
                             GHashTable *fragment_table ) 
{ 
  fragment_data *fd_head ;
  fragment_key key ;
  gpointer tmp ;

  {
  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;


  if (fd_head) {

    return (fd_head->datalen);
  } else {

  }

  return ((guint32 )0);
}
}
void fragment_set_partial_reassembly(packet_info const   *pinfo ,
                                     guint32 const   id ,
                                     GHashTable *fragment_table ) 
{ 
  fragment_data *fd_head ;
  fragment_key key ;
  gpointer tmp ;

  {
  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;


  if (fd_head) {
    fd_head->flags |= 64U;

  } else {

  }

  return;
}
}
static void fragment_unhash(GHashTable *fragment_table , fragment_key *key ) 
{ 


  {

  g_hash_table_remove(fragment_table, (gconstpointer )key);

  return;
}
}
static void fragment_reassembled(fragment_data *fd_head ,
                                 packet_info const   *pinfo ,
                                 GHashTable *reassembled_table ,
                                 guint32 const   id ) 
{ 
  reassembled_key *new_key ;
  fragment_data *fd ;
  gpointer tmp ;
  gpointer tmp___0 ;

  {
  if ((unsigned int )fd_head->next == (unsigned int )((void *)0)) {


    tmp = g_slice_alloc(sizeof(reassembled_key ));


    new_key = (reassembled_key *)tmp;

    new_key->frame = (pinfo->fd)->num;

    new_key->id = (guint32 )id;


    g_hash_table_insert(reassembled_table, (gpointer )new_key,
                        (gpointer )fd_head);

  } else {
    fd = fd_head->next;








    while ((unsigned int )fd != (unsigned int )((void *)0)) {


      tmp___0 = g_slice_alloc(sizeof(reassembled_key ));


      new_key = (reassembled_key *)tmp___0;

      new_key->frame = fd->frame;

      new_key->id = (guint32 )id;


      g_hash_table_insert(reassembled_table, (gpointer )new_key,
                          (gpointer )fd_head);

      fd = fd->next;

    }







  }
  fd_head->flags |= 1U;

  fd_head->reassembled_in = (pinfo->fd)->num;

  return;
}
}
static gboolean fragment_add_work(fragment_data *fd_head , tvbuff_t *tvb ,
                                  int const   offset ,
                                  packet_info const   *pinfo ,
                                  guint32 const   frag_offset ,
                                  guint32 const   frag_data_len ,
                                  gboolean const   more_frags ) 
{ 
  fragment_data *fd ;
  fragment_data *fd_i ;
  guint32 max ;
  guint32 dfpos ;
  unsigned char *old_data ;
  gpointer tmp ;
  guint32 end_offset ;
  guint8 const   *tmp___0 ;
  int tmp___1 ;
  gpointer tmp___2 ;
  gpointer tmp___3 ;
  guint32 tmp___4 ;
  int tmp___5 ;

  {


  tmp = g_slice_alloc(sizeof(fragment_data ));


  fd = (fragment_data *)tmp;

  fd->next = (struct _fragment_data *)((void *)0);

  fd->flags = (guint32 )0;

  fd->frame = (pinfo->fd)->num;



  if (fd->frame > fd_head->frame) {
    fd_head->frame = fd->frame;

  } else {

  }


  fd->offset = (guint32 )frag_offset;

  fd->len = (guint32 )frag_data_len;

  fd->data = (unsigned char *)((void *)0);


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "584", "1",
                  checkpoints_buf);
  if (fd_head->flags & 1U) {


    if (frag_offset + frag_data_len >= (guint32 const   )fd_head->datalen) {

      sprintf(checkpoints_buf, "%u", 64);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "586",
                      "64", checkpoints_buf);
      if (fd_head->flags & 64U) {
        fd_i = fd_head->next;





        while (fd_i) {


          if (! fd_i->data) {
            fd_i->data = fd_head->data + fd_i->offset;

            fd_i->flags |= 32U;

          } else {

          }

          fd_i->flags &= 4294967271U;

          fd_i = fd_i->next;

        }




        fd_head->flags &= 4294966206U;

        fd_head->flags &= 4294967271U;

        fd_head->datalen = (guint32 )0;

        fd_head->reassembled_in = (guint32 )0;

      } else {

      }

      sprintf(checkpoints_buf, "%u", 64);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "586",
                      "64", checkpoints_buf);
    } else {

    }


  } else {

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "584", "1",
                  checkpoints_buf);

  if (! more_frags) {

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "606",
                    "1024", checkpoints_buf);
    if (fd_head->flags & 1024U) {



      if (fd_head->datalen != fd->offset + fd->len) {
        fd->flags |= 8U;

        fd_head->flags |= 8U;

      } else {

      }



    } else {
      fd_head->datalen = fd->offset + fd->len;

      fd_head->flags |= 1024U;

    }

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "606",
                    "1024", checkpoints_buf);
  } else {

  }


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "614", "1",
                  checkpoints_buf);
  if (fd_head->flags & 1U) {
    end_offset = fd->offset + fd->len;

    fd->flags |= 2U;

    fd_head->flags |= 2U;



    if (end_offset > fd_head->datalen) {
      fd->flags |= 16U;

      fd_head->flags |= 16U;

    } else {


      if (end_offset < fd->offset) {
        fd->flags |= 16U;

        fd_head->flags |= 16U;

      } else {


        if (end_offset < fd->len) {
          fd->flags |= 16U;

          fd_head->flags |= 16U;

        } else {


          tmp___0 = tvb_get_ptr(tvb, offset, (gint const   )fd->len);


          sprintf(checkpoints_buf, "%d", tmp___1);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "628", "tmp___1", checkpoints_buf);

          tmp___1 = memcmp((void const   *)(fd_head->data + fd->offset),
                           (void const   *)tmp___0, fd->len);
          sprintf(checkpoints_buf, "%d", tmp___1);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "628", "tmp___1", checkpoints_buf);

          sprintf(checkpoints_buf, "%d", tmp___1);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "629", "tmp___1", checkpoints_buf);
          if (tmp___1) {
            fd->flags |= 4U;

            fd_head->flags |= 4U;

          } else {

          }
          sprintf(checkpoints_buf, "%d", tmp___1);
          checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                          "629", "tmp___1", checkpoints_buf);
        }


      }


    }



    LINK_FRAG(fd_head, fd);

    sprintf(checkpoints_buf, "%d", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "634", "1",
                    checkpoints_buf);
    return (1);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "614", "1",
                  checkpoints_buf);


  tmp___2 = g_malloc(fd->len);


  fd->data = (unsigned char *)tmp___2;


  tvb_memcpy(tvb, (void *)fd->data, offset, fd->len);


  LINK_FRAG(fd_head, fd);


  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "640",
                  "1024", checkpoints_buf);
  if (! (fd_head->flags & 1024U)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "641", "0",
                    checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "640",
                  "1024", checkpoints_buf);
  max = (guint32 )0;

  fd_i = fd_head->next;





  while (fd_i) {



    if (fd_i->offset <= max) {



      if (fd_i->offset + fd_i->len > max) {
        max = fd_i->offset + fd_i->len;

      } else {

      }



    } else {

    }


    fd_i = fd_i->next;

  }






  if (max < fd_head->datalen) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "656", "0",
                    checkpoints_buf);
    return (0);
  } else {

  }




  if (max > fd_head->datalen) {
    fd->flags |= 16U;

    fd_head->flags |= 16U;

  } else {

  }


  old_data = fd_head->data;



  tmp___3 = g_malloc(max);


  fd_head->data = (unsigned char *)tmp___3;

  dfpos = (guint32 )0;

  fd_i = fd_head;




  while (fd_i) {


    if (fd_i->len) {



      if (fd_i->offset + fd_i->len > dfpos) {



        if (fd_i->offset + fd_i->len > max) {

          g_log((gchar const   *)((gchar *)0), (GLogLevelFlags )16,
                "Reassemble error in frame %u: offset %u + len %u > max %u",
                (pinfo->fd)->num, fd_i->offset, fd_i->len, max);

        } else {


          if (dfpos < fd_i->offset) {

            g_log((gchar const   *)((gchar *)0), (GLogLevelFlags )16,
                  "Reassemble error in frame %u: dfpos %u < offset %u",
                  (pinfo->fd)->num, dfpos, fd_i->offset);

          } else {



            if (dfpos - fd_i->offset > fd_i->len) {

              g_log((gchar const   *)((gchar *)0), (GLogLevelFlags )16,
                    "Reassemble error in frame %u: dfpos %u - offset %u > len %u",
                    (pinfo->fd)->num, dfpos, fd_i->offset, fd_i->len);

            } else {

              if (! fd_head->data) {

                g_log((gchar const   *)((gchar *)0), (GLogLevelFlags )16,
                      "Reassemble error in frame %u: no data", (pinfo->fd)->num);

              } else {


                if (fd_i->offset < dfpos) {
                  fd_i->flags |= 2U;

                  fd_head->flags |= 2U;




                  if (fd_i->len < dfpos - fd_i->offset) {
                    tmp___4 = fd_i->len;

                  } else {
                    tmp___4 = dfpos - fd_i->offset;

                  }



                  sprintf(checkpoints_buf, "%d", tmp___5);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "687", "tmp___5", checkpoints_buf);

                  tmp___5 = memcmp((void const   *)(fd_head->data + fd_i->offset),
                                   (void const   *)fd_i->data, tmp___4);
                  sprintf(checkpoints_buf, "%d", tmp___5);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "687", "tmp___5", checkpoints_buf);

                  sprintf(checkpoints_buf, "%d", tmp___5);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "688", "tmp___5", checkpoints_buf);
                  if (tmp___5) {
                    fd_i->flags |= 4U;

                    fd_head->flags |= 4U;

                  } else {

                  }
                  sprintf(checkpoints_buf, "%d", tmp___5);
                  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                                  "688", "tmp___5", checkpoints_buf);
                } else {

                }



                memcpy((void */* __restrict  */)(fd_head->data + dfpos),
                       (void const   */* __restrict  */)(fd_i->data + (dfpos - fd_i->offset)),
                       fd_i->len - (dfpos - fd_i->offset));

              }

            }



          }


        }



      } else {



        if (fd_i->offset + fd_i->len < fd_i->offset) {

          g_log((gchar const   *)((gchar *)0), (GLogLevelFlags )16,
                "Reassemble error in frame %u: offset %u + len %u < offset",
                (pinfo->fd)->num, fd_i->offset, fd_i->len);

        } else {

        }



      }




      sprintf(checkpoints_buf, "%u", 32);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "697",
                      "32", checkpoints_buf);
      if (fd_i->flags & 32U) {
        fd_i->flags &= 4294967263U;

      } else {

        g_free((gpointer )fd_i->data);

      }

      sprintf(checkpoints_buf, "%u", 32);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "697",
                      "32", checkpoints_buf);
      fd_i->data = (unsigned char *)((void *)0);




      if (dfpos > fd_i->offset + fd_i->len) {
        dfpos = dfpos;

      } else {
        dfpos = fd_i->offset + fd_i->len;

      }



    } else {

    }

    fd_i = fd_i->next;

  }




  g_free((gpointer )old_data);

  fd_head->flags |= 1U;

  fd_head->reassembled_in = (pinfo->fd)->num;

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "709", "1",
                  checkpoints_buf);
  return (1);
}
}
static fragment_data *fragment_add_common(tvbuff_t *tvb , int const   offset ,
                                          packet_info const   *pinfo ,
                                          guint32 const   id ,
                                          GHashTable *fragment_table ,
                                          guint32 const   frag_offset ,
                                          guint32 const   frag_data_len ,
                                          gboolean const   more_frags ,
                                          gboolean const   check_already_added ) 
{ 
  fragment_key key ;
  fragment_key *new_key ;
  fragment_data *fd_head ;
  fragment_data *fd_item ;
  gboolean already_added ;
  gchar *tmp ;
  char *tmp___0 ;
  gboolean tmp___1 ;
  gpointer tmp___2 ;
  gpointer tmp___3 ;
  guint8 *COPY_ADDRESS_data ;
  gpointer tmp___4 ;
  guint8 *COPY_ADDRESS_data___0 ;
  gpointer tmp___5 ;
  gboolean tmp___6 ;

  {
  already_added = (gboolean )(pinfo->fd)->flags.visited;



  tmp___1 = tvb_bytes_exist((tvbuff_t const   *)tvb, offset,
                            (gint const   )frag_data_len);



  if (tmp___1) {

  } else {


    tmp___0 = getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG");


    if ((unsigned int )tmp___0 != (unsigned int )((void *)0)) {

      abort();

    } else {


      tmp = ep_strdup_printf("%s:%u: failed assertion \"%s\"", "reassemble.c",
                             1038, "tvb_bytes_exist(tvb, offset, frag_data_len)");



      except_throw(1L, 4L, (char const   *)tmp);

    }
  }

  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp___2 = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp___2;


  if (! already_added) {

    if (check_already_added) {
      if ((unsigned int )fd_head != (unsigned int )((void *)0)) {


        if ((pinfo->fd)->num <= fd_head->frame) {
          fd_item = fd_head->next;





          while (fd_item) {



            if ((pinfo->fd)->num == fd_item->frame) {

              if (frag_offset == (guint32 const   )fd_item->offset) {
                already_added = 1;

              } else {

              }

            } else {

            }


            fd_item = fd_item->next;

          }




        } else {

        }


      } else {

      }
    } else {

    }

  } else {

  }


  if (already_added) {
    if ((unsigned int )fd_head != (unsigned int )((void *)0)) {

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "745",
                      "1", checkpoints_buf);
      if (fd_head->flags & 1U) {

        return (fd_head);
      } else {
        return ((fragment_data *)((void *)0));
      }

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "745",
                      "1", checkpoints_buf);
    } else {
      return ((fragment_data *)((void *)0));
    }
  } else {

  }

  if ((unsigned int )fd_head == (unsigned int )((void *)0)) {


    fd_head = new_head((guint32 const   )0);




    tmp___3 = g_slice_alloc(sizeof(fragment_key ));


    new_key = (fragment_key *)tmp___3;

    new_key->src.type = key.src.type;

    new_key->src.len = key.src.len;



    tmp___4 = g_malloc((gsize )key.src.len);


    COPY_ADDRESS_data = (guint8 *)tmp___4;


    memcpy((void */* __restrict  */)COPY_ADDRESS_data,
           (void const   */* __restrict  */)key.src.data, (size_t )key.src.len);

    new_key->src.data = (void const   *)COPY_ADDRESS_data;

    new_key->dst.type = key.dst.type;

    new_key->dst.len = key.dst.len;



    tmp___5 = g_malloc((gsize )key.dst.len);


    COPY_ADDRESS_data___0 = (guint8 *)tmp___5;


    memcpy((void */* __restrict  */)COPY_ADDRESS_data___0,
           (void const   */* __restrict  */)key.dst.data, (size_t )key.dst.len);

    new_key->dst.data = (void const   *)COPY_ADDRESS_data___0;

    new_key->id = key.id;


    g_hash_table_insert(fragment_table, (gpointer )new_key, (gpointer )fd_head);

  } else {

  }


  tmp___6 = fragment_add_work(fd_head, tvb, offset, pinfo, frag_offset,
                              frag_data_len, more_frags);



  if (tmp___6) {

    return (fd_head);
  } else {
    return ((fragment_data *)((void *)0));
  }

}
}
fragment_data *fragment_add(tvbuff_t *tvb , int const   offset ,
                            packet_info const   *pinfo , guint32 const   id ,
                            GHashTable *fragment_table ,
                            guint32 const   frag_offset ,
                            guint32 const   frag_data_len ,
                            gboolean const   more_frags ) 
{ 
  fragment_data *tmp ;

  {


  tmp = fragment_add_common(tvb, offset, pinfo, id, fragment_table, frag_offset,
                            frag_data_len, more_frags, (gboolean const   )1);



  return (tmp);
}
}
fragment_data *fragment_add_multiple_ok(tvbuff_t *tvb , int const   offset ,
                                        packet_info const   *pinfo ,
                                        guint32 const   id ,
                                        GHashTable *fragment_table ,
                                        guint32 const   frag_offset ,
                                        guint32 const   frag_data_len ,
                                        gboolean const   more_frags ) 
{ 
  fragment_data *tmp ;

  {


  tmp = fragment_add_common(tvb, offset, pinfo, id, fragment_table, frag_offset,
                            frag_data_len, more_frags, (gboolean const   )0);



  return (tmp);
}
}
fragment_data *fragment_add_check(tvbuff_t *tvb , int const   offset ,
                                  packet_info const   *pinfo ,
                                  guint32 const   id ,
                                  GHashTable *fragment_table ,
                                  GHashTable *reassembled_table ,
                                  guint32 const   frag_offset ,
                                  guint32 const   frag_data_len ,
                                  gboolean const   more_frags ) 
{ 
  reassembled_key reass_key ;
  fragment_key key ;
  fragment_key *new_key ;
  fragment_key *old_key ;
  gpointer orig_key ;
  gpointer value ;
  fragment_data *fd_head ;
  gpointer tmp ;
  gpointer tmp___0 ;
  guint8 *COPY_ADDRESS_data ;
  gpointer tmp___1 ;
  guint8 *COPY_ADDRESS_data___0 ;
  gpointer tmp___2 ;
  gboolean tmp___3 ;
  guint tmp___4 ;
  guint tmp___5 ;
  gboolean tmp___6 ;

  {

  if ((pinfo->fd)->flags.visited) {
    reass_key.frame = (pinfo->fd)->num;

    reass_key.id = (guint32 )id;



    tmp = g_hash_table_lookup(reassembled_table, (gconstpointer )(& reass_key));


    return ((fragment_data *)tmp);
  } else {

  }

  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp___3 = g_hash_table_lookup_extended(fragment_table,
                                         (gconstpointer )(& key), & orig_key,
                                         & value);



  if (tmp___3) {
    fd_head = (fragment_data *)value;

  } else {


    fd_head = new_head((guint32 const   )0);




    tmp___0 = g_slice_alloc(sizeof(fragment_key ));


    new_key = (fragment_key *)tmp___0;

    new_key->src.type = key.src.type;

    new_key->src.len = key.src.len;



    tmp___1 = g_malloc((gsize )key.src.len);


    COPY_ADDRESS_data = (guint8 *)tmp___1;


    memcpy((void */* __restrict  */)COPY_ADDRESS_data,
           (void const   */* __restrict  */)key.src.data, (size_t )key.src.len);

    new_key->src.data = (void const   *)COPY_ADDRESS_data;

    new_key->dst.type = key.dst.type;

    new_key->dst.len = key.dst.len;



    tmp___2 = g_malloc((gsize )key.dst.len);


    COPY_ADDRESS_data___0 = (guint8 *)tmp___2;


    memcpy((void */* __restrict  */)COPY_ADDRESS_data___0,
           (void const   */* __restrict  */)key.dst.data, (size_t )key.dst.len);

    new_key->dst.data = (void const   *)COPY_ADDRESS_data___0;

    new_key->id = key.id;


    g_hash_table_insert(fragment_table, (gpointer )new_key, (gpointer )fd_head);

    orig_key = (gpointer )new_key;

  }



  tmp___4 = tvb_reported_length((tvbuff_t const   *)tvb);




  tmp___5 = tvb_length((tvbuff_t const   *)tvb);




  if (tmp___4 > tmp___5) {
    return ((fragment_data *)((void *)0));
  } else {

  }




  tmp___6 = fragment_add_work(fd_head, tvb, offset, pinfo, frag_offset,
                              frag_data_len, more_frags);



  if (tmp___6) {
    old_key = (fragment_key *)orig_key;


    fragment_unhash(fragment_table, old_key);


    fragment_reassembled(fd_head, pinfo, reassembled_table, id);


    return (fd_head);
  } else {
    return ((fragment_data *)((void *)0));
  }

}
}
static void fragment_defragment_and_free(fragment_data *fd_head ,
                                         packet_info const   *pinfo ) 
{ 
  fragment_data *fd_i ;
  fragment_data *last_fd ;
  guint32 dfpos ;
  guint32 size ;
  void *old_data ;
  gpointer tmp ;
  int tmp___0 ;

  {
  fd_i = (fragment_data *)((void *)0);

  last_fd = (fragment_data *)((void *)0);

  dfpos = (guint32 )0;

  size = (guint32 )0;

  old_data = (void *)0;

  fd_i = fd_head->next;





  while (fd_i) {


    if (! last_fd) {
      size += fd_i->len;

    } else {


      if (last_fd->offset != fd_i->offset) {
        size += fd_i->len;

      } else {

      }


    }

    last_fd = fd_i;

    fd_i = fd_i->next;

  }




  old_data = (void *)fd_head->data;



  tmp = g_malloc(size);


  fd_head->data = (unsigned char *)tmp;

  fd_head->len = size;

  last_fd = (fragment_data *)((void *)0);

  fd_i = fd_head->next;





  while (fd_i) {


    if (fd_i->len) {

      if (! last_fd) {

        memcpy((void */* __restrict  */)(fd_head->data + dfpos),
               (void const   */* __restrict  */)fd_i->data, fd_i->len);

        dfpos += fd_i->len;

      } else {


        if (last_fd->offset != fd_i->offset) {

          memcpy((void */* __restrict  */)(fd_head->data + dfpos),
                 (void const   */* __restrict  */)fd_i->data, fd_i->len);

          dfpos += fd_i->len;

        } else {
          fd_i->flags |= 2U;

          fd_head->flags |= 2U;



          if (last_fd->len != fd_i->len) {
            fd_i->flags |= 4U;

            fd_head->flags |= 4U;

          } else {
            sprintf(checkpoints_buf, "%d", tmp___0);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "858", "tmp___0", checkpoints_buf);

            tmp___0 = memcmp((void const   *)last_fd->data,
                             (void const   *)fd_i->data, last_fd->len);
            sprintf(checkpoints_buf, "%d", tmp___0);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "858", "tmp___0", checkpoints_buf);

            sprintf(checkpoints_buf, "%d", tmp___0);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "859", "tmp___0", checkpoints_buf);
            if (tmp___0) {
              fd_i->flags |= 4U;

              fd_head->flags |= 4U;

            } else {

            }
            sprintf(checkpoints_buf, "%d", tmp___0);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "859", "tmp___0", checkpoints_buf);
          }


        }


      }

    } else {

    }

    last_fd = fd_i;

    fd_i = fd_i->next;

  }




  fd_i = fd_head->next;



  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "867", "32",
                  checkpoints_buf);


  while (fd_i) {


    sprintf(checkpoints_buf, "%u", 32);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "871",
                    "32", checkpoints_buf);
    if (fd_i->flags & 32U) {
      fd_i->flags &= 4294967263U;

    } else {

      g_free((gpointer )fd_i->data);

    }

    sprintf(checkpoints_buf, "%u", 32);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "871",
                    "32", checkpoints_buf);
    fd_i->data = (unsigned char *)((void *)0);

    fd_i = fd_i->next;

  }


  sprintf(checkpoints_buf, "%u", 32);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "867", "32",
                  checkpoints_buf);



  g_free(old_data);

  fd_head->flags |= 1U;

  fd_head->reassembled_in = (pinfo->fd)->num;

  return;
}
}
static gboolean fragment_add_seq_work(fragment_data *fd_head , tvbuff_t *tvb ,
                                      int const   offset ,
                                      packet_info const   *pinfo ,
                                      guint32 const   frag_number ,
                                      guint32 const   frag_data_len ,
                                      gboolean const   more_frags ,
                                      guint32 const   flags  __attribute__((__unused__)) ) 
{ 
  fragment_data *fd ;
  fragment_data *fd_i ;
  fragment_data *last_fd ;
  guint32 max ;
  guint32 dfpos ;
  guint32 lastdfpos ;
  gpointer tmp ;
  gchar *tmp___0 ;
  char *tmp___1 ;
  guint8 const   *tmp___2 ;
  int tmp___3 ;
  gpointer tmp___4 ;

  {

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "880", "1",
                  checkpoints_buf);
  if (fd_head->flags & 1U) {

    if (frag_number >= (guint32 const   )fd_head->datalen) {

      sprintf(checkpoints_buf, "%u", 64);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "882",
                      "64", checkpoints_buf);
      if (fd_head->flags & 64U) {
        lastdfpos = (guint32 )0;

        dfpos = (guint32 )0;

        fd_i = fd_head->next;





        while (fd_i) {


          if (! fd_i->data) {

            sprintf(checkpoints_buf, "%u", 2);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "891", "2", checkpoints_buf);
            if (fd_i->flags & 2U) {
              fd_i->data = fd_head->data + lastdfpos;

            } else {
              fd_i->data = fd_head->data + dfpos;

              lastdfpos = dfpos;

              dfpos += fd_i->len;

            }

            sprintf(checkpoints_buf, "%u", 2);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "891", "2", checkpoints_buf);
            fd_i->flags |= 32U;

          } else {

          }

          fd_i->flags &= 4294967271U;

          fd_i = fd_i->next;

        }




        fd_head->flags &= 4294966206U;

        fd_head->flags &= 4294967271U;

        fd_head->datalen = (guint32 )0;

        fd_head->reassembled_in = (guint32 )0;

      } else {

      }

      sprintf(checkpoints_buf, "%u", 64);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "882",
                      "64", checkpoints_buf);
    } else {

    }

  } else {

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "880", "1",
                  checkpoints_buf);


  tmp = g_slice_alloc(sizeof(fragment_data ));


  fd = (fragment_data *)tmp;

  fd->next = (struct _fragment_data *)((void *)0);

  fd->flags = (guint32 )0;

  fd->frame = (pinfo->fd)->num;

  fd->offset = (guint32 )frag_number;

  fd->len = (guint32 )frag_data_len;

  fd->data = (unsigned char *)((void *)0);


  if (! more_frags) {

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "916",
                    "1024", checkpoints_buf);
    if (fd_head->flags & 1024U) {


      if (fd_head->datalen != fd->offset) {
        fd->flags |= 8U;

        fd_head->flags |= 8U;

      } else {

      }


    } else {
      fd_head->datalen = fd->offset;

      fd_head->flags |= 1024U;

    }

    sprintf(checkpoints_buf, "%u", 1024);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "916",
                    "1024", checkpoints_buf);
  } else {

  }


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "924", "1",
                  checkpoints_buf);
  if (fd_head->flags & 1U) {
    fd->flags |= 2U;

    fd_head->flags |= 2U;



    if (fd->offset > fd_head->datalen) {
      fd->flags |= 16U;

      fd_head->flags |= 16U;


      LINK_FRAG(fd_head, fd);

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "931",
                      "1", checkpoints_buf);
      return (1);
    } else {

    }


    dfpos = (guint32 )0;

    last_fd = (fragment_data *)((void *)0);

    fd_i = fd_head->next;





    while (1) {

      if (fd_i) {


        if (fd_i->offset != fd->offset) {

        } else {
          break;
        }


      } else {
        break;
      }


      if (! last_fd) {
        dfpos += fd_i->len;

      } else {


        if (last_fd->offset != fd_i->offset) {
          dfpos += fd_i->len;

        } else {

        }


      }

      last_fd = fd_i;

      fd_i = fd_i->next;

    }





    if (fd_i) {


      if (fd_i->len != fd->len) {
        fd->flags |= 4U;

        fd_head->flags |= 4U;


        LINK_FRAG(fd_head, fd);

        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "954",
                        "1", checkpoints_buf);
        return (1);
      } else {

      }





      if (fd_head->len >= dfpos + fd->len) {

      } else {


        tmp___1 = getenv("WIRESHARK_ABORT_ON_DISSECTOR_BUG");


        if ((unsigned int )tmp___1 != (unsigned int )((void *)0)) {

          abort();

        } else {


          tmp___0 = ep_strdup_printf("%s:%u: failed assertion \"%s\"",
                                     "reassemble.c", 1446,
                                     "fd_head->len >= dfpos + fd->len");



          except_throw(1L, 4L, (char const   *)tmp___0);

        }
      }





      tmp___2 = tvb_get_ptr(tvb, offset, (gint const   )fd->len);


      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "964",
                      "tmp___3", checkpoints_buf);

      tmp___3 = memcmp((void const   *)(fd_head->data + dfpos),
                       (void const   *)tmp___2, fd->len);
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "964",
                      "tmp___3", checkpoints_buf);

      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "965",
                      "tmp___3", checkpoints_buf);
      if (tmp___3) {
        fd->flags |= 4U;

        fd_head->flags |= 4U;


        LINK_FRAG(fd_head, fd);

        sprintf(checkpoints_buf, "%d", 1);
        checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "969",
                        "1", checkpoints_buf);
        return (1);
      } else {

      }
      sprintf(checkpoints_buf, "%d", tmp___3);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "965",
                      "tmp___3", checkpoints_buf);

      LINK_FRAG(fd_head, fd);

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "972",
                      "1", checkpoints_buf);
      return (1);
    } else {

      LINK_FRAG(fd_head, fd);

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "974",
                      "1", checkpoints_buf);
      return (1);
    }

  } else {

  }

  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "924", "1",
                  checkpoints_buf);

  if (fd->len) {


    tmp___4 = g_malloc(fd->len);


    fd->data = (unsigned char *)tmp___4;


    tvb_memcpy(tvb, (void *)fd->data, offset, fd->len);

  } else {

  }


  LINK_FRAG(fd_head, fd);


  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "982",
                  "1024", checkpoints_buf);
  if (! (fd_head->flags & 1024U)) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "983", "0",
                    checkpoints_buf);
    return (0);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 1024);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "982",
                  "1024", checkpoints_buf);
  max = (guint32 )0;

  fd_i = fd_head->next;





  while (fd_i) {



    if (fd_i->offset == max) {
      max ++;

    } else {

    }


    fd_i = fd_i->next;

  }






  if (max <= fd_head->datalen) {
    sprintf(checkpoints_buf, "%d", 0);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "996", "0",
                    checkpoints_buf);
    return (0);
  } else {

  }




  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "998", "1",
                  checkpoints_buf);
  if (max > fd_head->datalen + 1U) {
    fd->flags |= 16U;

    fd_head->flags |= 16U;

  } else {

  }


  sprintf(checkpoints_buf, "%u", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "998", "1",
                  checkpoints_buf);

  fragment_defragment_and_free(fd_head, pinfo);

  sprintf(checkpoints_buf, "%d", 1);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1003", "1",
                  checkpoints_buf);
  return (1);
}
}
fragment_data *fragment_add_seq(tvbuff_t *tvb , int const   offset ,
                                packet_info const   *pinfo ,
                                guint32 const   id ,
                                GHashTable *fragment_table ,
                                guint32 const   frag_number ,
                                guint32 const   frag_data_len ,
                                gboolean const   more_frags ) 
{ 
  fragment_key key ;
  fragment_data *tmp ;

  {
  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp = fragment_add_seq_key(tvb, offset, pinfo, (void *)(& key),
                             & fragment_key_copy, fragment_table,
                             (guint32 )frag_number, frag_data_len, more_frags,
                             (guint32 const   )0);



  return (tmp);
}
}
fragment_data *fragment_add_dcerpc_dg(tvbuff_t *tvb , int const   offset ,
                                      packet_info const   *pinfo ,
                                      guint32 const   id , void *v_act_id ,
                                      GHashTable *fragment_table ,
                                      guint32 const   frag_number ,
                                      guint32 const   frag_data_len ,
                                      gboolean const   more_frags ) 
{ 
  e_uuid_t *act_id ;
  dcerpc_fragment_key key ;
  fragment_data *tmp ;

  {
  act_id = (e_uuid_t *)v_act_id;

  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;

  key.act_id = *act_id;



  tmp = fragment_add_seq_key(tvb, offset, pinfo, (void *)(& key),
                             & dcerpc_fragment_key_copy, fragment_table,
                             (guint32 )frag_number, frag_data_len, more_frags,
                             (guint32 const   )0);



  return (tmp);
}
}
fragment_data *fragment_add_seq_key(tvbuff_t *tvb , int const   offset ,
                                    packet_info const   *pinfo , void *key ,
                                    void *(*key_copier)(void const   *key ) ,
                                    GHashTable *fragment_table ,
                                    guint32 frag_number ,
                                    guint32 const   frag_data_len ,
                                    gboolean const   more_frags ,
                                    guint32 const   flags ) 
{ 
  fragment_data *fd_head ;
  gpointer tmp ;
  fragment_data *fd ;
  gpointer orig_key ;
  gboolean tmp___0 ;
  fragment_data *tmp___1 ;
  gboolean tmp___2 ;
  gboolean tmp___3 ;

  {


  tmp = g_hash_table_lookup(fragment_table, (gconstpointer )key);


  fd_head = (fragment_data *)tmp;


  if ((pinfo->fd)->flags.visited) {
    if ((unsigned int )fd_head != (unsigned int )((void *)0)) {

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1020",
                      "1", checkpoints_buf);
      if (fd_head->flags & 1U) {

        return (fd_head);
      } else {
        return ((fragment_data *)((void *)0));
      }

      sprintf(checkpoints_buf, "%u", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1020",
                      "1", checkpoints_buf);
    } else {
      return ((fragment_data *)((void *)0));
    }
  } else {

  }

  if ((unsigned int )fd_head == (unsigned int )((void *)0)) {


    fd_head = new_head((guint32 const   )256);



    sprintf(checkpoints_buf, "%u", 3);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1027",
                    "3", checkpoints_buf);
    if (flags & 3U) {

      if (! more_frags) {
        fd_head->reassembled_in = (pinfo->fd)->num;


        return (fd_head);
      } else {

      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 3);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1027",
                    "3", checkpoints_buf);
    if ((unsigned int )key_copier != (unsigned int )((void *)0)) {


      key = (*key_copier)((void const   *)key);


    } else {

    }

    g_hash_table_insert(fragment_table, key, (gpointer )fd_head);


    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1037",
                    "1", checkpoints_buf);
    if (flags & 1U) {
      frag_number = (guint32 )0;

    } else {

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1037",
                    "1", checkpoints_buf);
  } else {

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1040",
                    "1", checkpoints_buf);
    if (flags & 1U) {
      fd = fd_head;


      while ((unsigned int )fd != (unsigned int )((void *)0)) {
        if ((unsigned int )fd->next == (unsigned int )((void *)0)) {
          frag_number = fd->offset + 1U;

        } else {

        }
        fd = fd->next;

      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1040",
                    "1", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1051", "4",
                  checkpoints_buf);
  if (flags & 4U) {


    tmp___2 = tvb_bytes_exist((tvbuff_t const   *)tvb, offset,
                              (gint const   )frag_data_len);



    if (tmp___2) {

    } else {

      if (! more_frags) {


        tmp___0 = g_hash_table_lookup_extended(fragment_table,
                                               (gconstpointer )key, & orig_key,
                                               (gpointer *)((void *)0));



        if (tmp___0) {

          fragment_unhash(fragment_table, (fragment_key *)orig_key);

        } else {

        }

      } else {

      }

      fd_head->flags |= 512U;


      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1062",
                      "0", checkpoints_buf);
      if (frag_number == 0U) {
        tmp___1 = fd_head;

      } else {
        tmp___1 = (fragment_data *)((void *)0);

      }

      sprintf(checkpoints_buf, "%u", 0);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1062",
                      "0", checkpoints_buf);

      return (tmp___1);
    }

  } else {

  }

  sprintf(checkpoints_buf, "%u", 4);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1051", "4",
                  checkpoints_buf);


  tmp___3 = fragment_add_seq_work(fd_head, tvb, offset, pinfo,
                                  (guint32 const   )frag_number, frag_data_len,
                                  more_frags, flags);



  if (tmp___3) {

    return (fd_head);
  } else {
    return ((fragment_data *)((void *)0));
  }

}
}
static fragment_data *fragment_add_seq_check_work(tvbuff_t *tvb ,
                                                  int const   offset ,
                                                  packet_info const   *pinfo ,
                                                  guint32 const   id ,
                                                  GHashTable *fragment_table ,
                                                  GHashTable *reassembled_table ,
                                                  guint32 const   frag_number ,
                                                  guint32 const   frag_data_len ,
                                                  gboolean const   more_frags ,
                                                  guint32 const   flags ) 
{ 
  reassembled_key reass_key ;
  fragment_key key ;
  fragment_data *fd_head ;
  gpointer tmp ;
  gpointer orig_key ;
  gboolean tmp___0 ;

  {

  if ((pinfo->fd)->flags.visited) {
    reass_key.frame = (pinfo->fd)->num;

    reass_key.id = (guint32 )id;



    tmp = g_hash_table_lookup(reassembled_table, (gconstpointer )(& reass_key));


    return ((fragment_data *)tmp);
  } else {

  }

  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  fd_head = fragment_add_seq_key(tvb, offset, pinfo, (void *)(& key),
                                 & fragment_key_copy, fragment_table,
                                 (guint32 )frag_number, frag_data_len,
                                 more_frags, flags | 4U);



  if (fd_head) {

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1082",
                    "512", checkpoints_buf);
    if (fd_head->flags & 512U) {

      return (fd_head);
    } else {

    }

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1082",
                    "512", checkpoints_buf);


    tmp___0 = g_hash_table_lookup_extended(fragment_table,
                                           (gconstpointer )(& key), & orig_key,
                                           (gpointer *)((void *)0));



    if (tmp___0) {

      fragment_unhash(fragment_table, (fragment_key *)orig_key);

    } else {

    }


    fragment_reassembled(fd_head, pinfo, reassembled_table, id);


    return (fd_head);
  } else {
    return ((fragment_data *)((void *)0));
  }

}
}
fragment_data *fragment_add_seq_check(tvbuff_t *tvb , int const   offset ,
                                      packet_info const   *pinfo ,
                                      guint32 const   id ,
                                      GHashTable *fragment_table ,
                                      GHashTable *reassembled_table ,
                                      guint32 const   frag_number ,
                                      guint32 const   frag_data_len ,
                                      gboolean const   more_frags ) 
{ 
  fragment_data *tmp ;

  {


  tmp = fragment_add_seq_check_work(tvb, offset, pinfo, id, fragment_table,
                                    reassembled_table, frag_number,
                                    frag_data_len, more_frags,
                                    (guint32 const   )0);



  return (tmp);
}
}
fragment_data *fragment_add_seq_802_11(tvbuff_t *tvb , int const   offset ,
                                       packet_info const   *pinfo ,
                                       guint32 const   id ,
                                       GHashTable *fragment_table ,
                                       GHashTable *reassembled_table ,
                                       guint32 const   frag_number ,
                                       guint32 const   frag_data_len ,
                                       gboolean const   more_frags ) 
{ 
  fragment_data *tmp ;

  {


  tmp = fragment_add_seq_check_work(tvb, offset, pinfo, id, fragment_table,
                                    reassembled_table, frag_number,
                                    frag_data_len, more_frags,
                                    (guint32 const   )2);



  return (tmp);
}
}
fragment_data *fragment_add_seq_next(tvbuff_t *tvb , int const   offset ,
                                     packet_info const   *pinfo ,
                                     guint32 const   id ,
                                     GHashTable *fragment_table ,
                                     GHashTable *reassembled_table ,
                                     guint32 const   frag_data_len ,
                                     gboolean const   more_frags ) 
{ 
  fragment_data *tmp ;

  {


  tmp = fragment_add_seq_check_work(tvb, offset, pinfo, id, fragment_table,
                                    reassembled_table, (guint32 const   )0,
                                    frag_data_len, more_frags,
                                    (guint32 const   )1);



  return (tmp);
}
}
void fragment_start_seq_check(packet_info const   *pinfo , guint32 const   id ,
                              GHashTable *fragment_table ,
                              guint32 const   tot_len ) 
{ 
  fragment_key key ;
  fragment_key *new_key ;
  fragment_data *fd_head ;
  gpointer tmp ;
  gpointer tmp___0 ;
  void *tmp___1 ;

  {

  if ((pinfo->fd)->flags.visited) {
    return;
  } else {

  }

  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp;

  if ((unsigned int )fd_head == (unsigned int )((void *)0)) {


    tmp___0 = g_slice_alloc(sizeof(fragment_data ));


    fd_head = (fragment_data *)tmp___0;

    fd_head->next = (struct _fragment_data *)((void *)0);

    fd_head->datalen = (guint32 )tot_len;

    fd_head->offset = (guint32 )0;

    fd_head->len = (guint32 )0;

    fd_head->flags = (guint32 )1280;

    fd_head->data = (unsigned char *)((void *)0);

    fd_head->reassembled_in = (guint32 )0;



    tmp___1 = fragment_key_copy((void const   *)(& key));


    new_key = (fragment_key *)tmp___1;


    g_hash_table_insert(fragment_table, (gpointer )new_key, (gpointer )fd_head);

  } else {

  }
  return;
}
}
fragment_data *fragment_end_seq_next(packet_info const   *pinfo ,
                                     guint32 const   id ,
                                     GHashTable *fragment_table ,
                                     GHashTable *reassembled_table ) 
{ 
  reassembled_key reass_key ;
  reassembled_key *new_key ;
  fragment_key key ;
  fragment_data *fd_head ;
  gpointer tmp ;
  gpointer tmp___0 ;
  gpointer orig_key ;
  gboolean tmp___1 ;
  gpointer tmp___2 ;

  {

  if ((pinfo->fd)->flags.visited) {
    reass_key.frame = (pinfo->fd)->num;

    reass_key.id = (guint32 )id;



    tmp = g_hash_table_lookup(reassembled_table, (gconstpointer )(& reass_key));


    return ((fragment_data *)tmp);
  } else {

  }

  key.src = (address )pinfo->src;

  key.dst = (address )pinfo->dst;

  key.id = (guint32 )id;



  tmp___0 = g_hash_table_lookup(fragment_table, (gconstpointer )(& key));


  fd_head = (fragment_data *)tmp___0;


  if (fd_head) {

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1133",
                    "512", checkpoints_buf);
    if (fd_head->flags & 512U) {
      return ((fragment_data *)((void *)0));
    } else {

    }

    sprintf(checkpoints_buf, "%u", 512);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1133",
                    "512", checkpoints_buf);
    fd_head->datalen = fd_head->offset;

    fd_head->flags |= 1024U;


    fragment_defragment_and_free(fd_head, pinfo);



    tmp___1 = g_hash_table_lookup_extended(fragment_table,
                                           (gconstpointer )(& key), & orig_key,
                                           (gpointer *)((void *)0));



    if (tmp___1) {

      fragment_unhash(fragment_table, (fragment_key *)orig_key);

    } else {

    }


    fragment_reassembled(fd_head, pinfo, reassembled_table, id);

    if ((unsigned int )fd_head->next != (unsigned int )((void *)0)) {


      tmp___2 = g_slice_alloc(sizeof(reassembled_key ));


      new_key = (reassembled_key *)tmp___2;

      new_key->frame = (pinfo->fd)->num;

      new_key->id = (guint32 )id;


      g_hash_table_insert(reassembled_table, (gpointer )new_key,
                          (gpointer )fd_head);

    } else {

    }

    return (fd_head);
  } else {
    return ((fragment_data *)((void *)0));
  }

}
}
tvbuff_t *process_reassembled_data(tvbuff_t *tvb , int const   offset ,
                                   packet_info *pinfo , char const   *name ,
                                   fragment_data *fd_head ,
                                   fragment_items const   *fit ,
                                   gboolean *update_col_infop ,
                                   proto_tree *tree ) 
{ 
  tvbuff_t *next_tvb ;
  gboolean update_col_info ;
  proto_item *frag_tree_item ;
  gboolean tmp ;
  int tmp___0 ;
  gboolean tmp___1 ;
  int tmp___2 ;

  {
  if ((unsigned int )fd_head != (unsigned int )((void *)0)) {


    if ((pinfo->fd)->num == fd_head->reassembled_in) {
      if ((unsigned int )fd_head->next != (unsigned int )((void *)0)) {

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1156",
                        "256", checkpoints_buf);
        if (fd_head->flags & 256U) {


          next_tvb = tvb_new_real_data((guint8 const   *)fd_head->data,
                                       (guint const   )fd_head->len,
                                       (gint const   )fd_head->len);


        } else {


          next_tvb = tvb_new_real_data((guint8 const   *)fd_head->data,
                                       (guint const   )fd_head->datalen,
                                       (gint const   )fd_head->datalen);


        }

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1156",
                        "256", checkpoints_buf);

        tvb_set_child_real_data_tvbuff(tvb, next_tvb);


        add_new_data_source(pinfo, next_tvb, name);


        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1161",
                        "256", checkpoints_buf);
        if (fd_head->flags & 256U) {


          tmp = show_fragment_seq_tree(fd_head, fit, tree, pinfo, next_tvb,
                                       & frag_tree_item);



          if (tmp) {
            tmp___0 = 0;
            sprintf(checkpoints_buf, "%d", tmp___0);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "1164", "tmp___0", checkpoints_buf);
          } else {
            tmp___0 = 1;
            sprintf(checkpoints_buf, "%d", tmp___0);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "1165", "tmp___0", checkpoints_buf);
          }

          update_col_info = tmp___0;

        } else {


          tmp___1 = show_fragment_tree(fd_head, fit, tree, pinfo, next_tvb,
                                       & frag_tree_item);



          if (tmp___1) {
            tmp___2 = 0;
            sprintf(checkpoints_buf, "%d", tmp___2);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "1169", "tmp___2", checkpoints_buf);
          } else {
            tmp___2 = 1;
            sprintf(checkpoints_buf, "%d", tmp___2);
            checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2",
                            "1170", "tmp___2", checkpoints_buf);
          }

          update_col_info = tmp___2;

        }

        sprintf(checkpoints_buf, "%u", 256);
        checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1161",
                        "256", checkpoints_buf);
      } else {


        next_tvb = tvb_new_subset_remaining(tvb, offset);


        pinfo->fragmented = 0;

        update_col_info = 1;

      }
      if ((unsigned int )update_col_infop != (unsigned int )((void *)0)) {
        *update_col_infop = update_col_info;

      } else {

      }
    } else {
      goto _L;
    }


  } else {
    _L: /* CIL Label */ 
    next_tvb = (tvbuff_t *)((void *)0);

    if ((unsigned int )fd_head != (unsigned int )((void *)0)) {
      if ((unsigned int )fit->hf_reassembled_in != (unsigned int )((void *)0)) {

        proto_tree_add_uint(tree, *(fit->hf_reassembled_in), tvb, 0, 0,
                            fd_head->reassembled_in);

      } else {

      }
    } else {

    }
  }

  return (next_tvb);
}
}
static void show_fragment(fragment_data *fd , int const   offset ,
                          fragment_items const   *fit , proto_tree *ft ,
                          proto_item *fi , gboolean const   first_frag ,
                          guint32 const   count , tvbuff_t *tvb ) 
{ 
  proto_item *fei ;
  int hf ;
  gchar *name ;
  char const   *tmp ;
  char const   *tmp___0 ;
  guint tmp___1 ;
  char const   *tmp___2 ;
  guint tmp___3 ;
  guint tmp___4 ;
  char const   *tmp___5 ;
  proto_tree *fet ;

  {
  fei = (proto_item *)((void *)0);


  if (first_frag) {

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1188",
                    "1", checkpoints_buf);
    if (count == 1U) {


      tmp = proto_registrar_get_name((int const   )*(fit->hf_fragment));




      name = g_strdup(tmp);


    } else {


      tmp___0 = proto_registrar_get_name((int const   )*(fit->hf_fragments));




      name = g_strdup(tmp___0);


    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1188",
                    "1", checkpoints_buf);


    tmp___3 = tvb_length((tvbuff_t const   *)tvb);



    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1194",
                    "1", checkpoints_buf);
    if (tmp___3 == 1U) {
      tmp___2 = "";

    } else {
      tmp___2 = "s";

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1194",
                    "1", checkpoints_buf);


    tmp___4 = tvb_length((tvbuff_t const   *)tvb);



    proto_item_set_text(fi, "%u %s (%u byte%s): ", count, name, tmp___4, tmp___2);


    g_free((gpointer )name);

  } else {

    proto_item_append_text(fi, ", ");

  }


  proto_item_append_text(fi, "#%u(%u)", fd->frame, fd->len);


  sprintf(checkpoints_buf, "%u", 28);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1202", "28",
                  checkpoints_buf);
  if (fd->flags & 28U) {
    hf = *(fit->hf_fragment_error);
    sprintf(checkpoints_buf, "%d", hf);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1203",
                    "hf", checkpoints_buf);
  } else {
    hf = *(fit->hf_fragment);
    sprintf(checkpoints_buf, "%d", hf);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1204",
                    "hf", checkpoints_buf);
  }

  sprintf(checkpoints_buf, "%u", 28);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1202", "28",
                  checkpoints_buf);

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1205", "0",
                  checkpoints_buf);
  if (fd->len == 0U) {


    fei = proto_tree_add_uint_format(ft, hf, tvb, (gint )offset, (gint )fd->len,
                                     fd->frame, "Frame: %u (no data)", fd->frame);


  } else {

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1207",
                    "1", checkpoints_buf);
    if (fd->len == 1U) {
      tmp___5 = "";

    } else {
      tmp___5 = "s";

    }

    sprintf(checkpoints_buf, "%u", 1);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1207",
                    "1", checkpoints_buf);


    fei = proto_tree_add_uint_format(ft, hf, tvb, (gint )offset, (gint )fd->len,
                                     fd->frame,
                                     "Frame: %u, payload: %u-%u (%u byte%s)",
                                     fd->frame, offset,
                                     ((guint32 )offset + fd->len) - 1U, fd->len,
                                     tmp___5);


  }

  sprintf(checkpoints_buf, "%u", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1205", "0",
                  checkpoints_buf);

  while (1) {

    if (fei) {

      while (1) {

        if (fei->finfo) {
          (fei->finfo)->flags |= 2U;

        } else {

        }

        break;
      }

    } else {

    }

    break;
  }


  sprintf(checkpoints_buf, "%u", 30);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1220", "30",
                  checkpoints_buf);
  if (fd->flags & 30U) {
    fet = (proto_tree *)((void *)0);



    fet = proto_item_add_subtree(fei, (gint const   )*(fit->ett_fragment));



    sprintf(checkpoints_buf, "%u", 2);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1223",
                    "2", checkpoints_buf);
    if (fd->flags & 2U) {


      fei = proto_tree_add_boolean(fet, *(fit->hf_fragment_overlap), tvb, 0, 0,
                                   (guint32 )1);



      while (1) {

        if (fei) {

          while (1) {

            if (fei->finfo) {
              (fei->finfo)->flags |= 2U;

            } else {

            }

            break;
          }

        } else {

        }

        break;
      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 2);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1223",
                    "2", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 4);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1235",
                    "4", checkpoints_buf);
    if (fd->flags & 4U) {


      fei = proto_tree_add_boolean(fet, *(fit->hf_fragment_overlap_conflict),
                                   tvb, 0, 0, (guint32 )1);



      while (1) {

        if (fei) {

          while (1) {

            if (fei->finfo) {
              (fei->finfo)->flags |= 2U;

            } else {

            }

            break;
          }

        } else {

        }

        break;
      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 4);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1235",
                    "4", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1247",
                    "8", checkpoints_buf);
    if (fd->flags & 8U) {


      fei = proto_tree_add_boolean(fet, *(fit->hf_fragment_multiple_tails), tvb,
                                   0, 0, (guint32 )1);



      while (1) {

        if (fei) {

          while (1) {

            if (fei->finfo) {
              (fei->finfo)->flags |= 2U;

            } else {

            }

            break;
          }

        } else {

        }

        break;
      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 8);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1247",
                    "8", checkpoints_buf);

    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1259",
                    "16", checkpoints_buf);
    if (fd->flags & 16U) {


      fei = proto_tree_add_boolean(fet, *(fit->hf_fragment_too_long_fragment),
                                   tvb, 0, 0, (guint32 )1);



      while (1) {

        if (fei) {

          while (1) {

            if (fei->finfo) {
              (fei->finfo)->flags |= 2U;

            } else {

            }

            break;
          }

        } else {

        }

        break;
      }

    } else {

    }

    sprintf(checkpoints_buf, "%u", 16);
    checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1259",
                    "16", checkpoints_buf);
  } else {

  }

  sprintf(checkpoints_buf, "%u", 30);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1220", "30",
                  checkpoints_buf);
  return;
}
}
static gboolean show_fragment_errs_in_col(fragment_data *fd_head ,
                                          fragment_items const   *fit ,
                                          packet_info *pinfo ) 
{ 
  gint tmp ;

  {

  sprintf(checkpoints_buf, "%u", 28);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1273", "28",
                  checkpoints_buf);
  if (fd_head->flags & 28U) {


    tmp = check_col(pinfo->cinfo, (gint const   )38);



    if (tmp) {

      col_add_fstr(pinfo->cinfo, (gint const   )38, "[Illegal %s]", fit->tag);

      sprintf(checkpoints_buf, "%d", 1);
      checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1277",
                      "1", checkpoints_buf);
      return (1);
    } else {

    }

  } else {

  }

  sprintf(checkpoints_buf, "%u", 28);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1273", "28",
                  checkpoints_buf);
  sprintf(checkpoints_buf, "%d", 0);
  checkpoints_log("/root/experiments/wireshark-bug-37112-37111/2", "1280", "0",
                  checkpoints_buf);
  return (0);
}
}
gboolean show_fragment_tree(fragment_data *fd_head ,
                            fragment_items const   *fit , proto_tree *tree ,
                            packet_info *pinfo , tvbuff_t *tvb ,
                            proto_item **fi ) 
{ 
  fragment_data *fd ;
  proto_tree *ft ;
  gboolean first_frag ;
  guint32 count ;
  proto_item *fli ;
  proto_item *tmp ;
  proto_item *fli___0 ;
  guint tmp___0 ;
  proto_item *tmp___1 ;
  gboolean tmp___2 ;

  {
  count = (guint32 )0;

  pinfo->fragmented = 0;



  *fi = proto_tree_add_item(tree, (int const   )*(fit->hf_fragments), tvb,
                            (gint const   )0, -1, (guint const   )0);



  while (1) {

    if (*fi) {

      while (1) {

        if ((*fi)->finfo) {
          ((*fi)->finfo)->flags |= 2U;

        } else {

        }

        break;
      }

    } else {

    }

    break;
  }



  ft = proto_item_add_subtree(*fi, (gint const   )*(fit->ett_fragments));


  first_frag = 1;

  fd = fd_head->next;



  while ((unsigned int )fd != (unsigned int )((void *)0)) {
    count ++;

    fd = fd->next;

  }


  fd = fd_head->next;




  while ((unsigned int )fd != (unsigned int )((void *)0)) {

    show_fragment(fd, (int const   )fd->offset, fit, ft, *fi,
                  (gboolean const   )first_frag, (guint32 const   )count, tvb);

    first_frag = 0;

    fd = fd->next;

  }




  if (fit->hf_fragment_count) {


    tmp = proto_tree_add_uint(ft, *(fit->hf_fragment_count), tvb, 0, 0, count);


    fli = tmp;


    while (1) {

      if (fli) {

        while (1) {

          if (fli->finfo) {
            (fli->finfo)->flags |= 2U;

          } else {

          }

          break;
        }

      } else {

      }

      break;
    }

  } else {

  }


  if (fit->hf_reassembled_length) {


    tmp___0 = tvb_length((tvbuff_t const   *)tvb);




    tmp___1 = proto_tree_add_uint(ft, *(fit->hf_reassembled_length), tvb, 0, 0,
                                  tmp___0);


    fli___0 = tmp___1;


    while (1) {

      if (fli___0) {

        while (1) {

          if (fli___0->finfo) {
            (fli___0->finfo)->flags |= 2U;

          } else {

          }

          break;
        }

      } else {

      }

      break;
    }

  } else {

  }



  tmp___2 = show_fragment_errs_in_col(fd_head, fit, pinfo);



  return (tmp___2);
}
}
gboolean show_fragment_seq_tree(fragment_data *fd_head ,
                                fragment_items const   *fit , proto_tree *tree ,
                                packet_info *pinfo , tvbuff_t *tvb ,
                                proto_item **fi ) 
{ 
  guint32 offset ;
  guint32 next_offset ;
  guint32 count ;
  fragment_data *fd ;
  fragment_data *last_fd ;
  proto_tree *ft ;
  gboolean first_frag ;
  proto_item *fli ;
  proto_item *tmp ;
  proto_item *fli___0 ;
  guint tmp___0 ;
  proto_item *tmp___1 ;
  gboolean tmp___2 ;

  {
  count = (guint32 )0;

  pinfo->fragmented = 0;



  *fi = proto_tree_add_item(tree, (int const   )*(fit->hf_fragments), tvb,
                            (gint const   )0, -1, (guint const   )0);



  while (1) {

    if (*fi) {

      while (1) {

        if ((*fi)->finfo) {
          ((*fi)->finfo)->flags |= 2U;

        } else {

        }

        break;
      }

    } else {

    }

    break;
  }



  ft = proto_item_add_subtree(*fi, (gint const   )*(fit->ett_fragments));


  offset = (guint32 )0;

  next_offset = (guint32 )0;

  last_fd = (fragment_data *)((void *)0);

  first_frag = 1;

  fd = fd_head->next;



  while ((unsigned int )fd != (unsigned int )((void *)0)) {
    count ++;

    fd = fd->next;

  }


  fd = fd_head->next;





  while ((unsigned int )fd != (unsigned int )((void *)0)) {
    if ((unsigned int )last_fd == (unsigned int )((void *)0)) {
      offset = next_offset;

      next_offset += fd->len;

    } else {


      if (last_fd->offset != fd->offset) {
        offset = next_offset;

        next_offset += fd->len;

      } else {

      }


    }
    last_fd = fd;


    show_fragment(fd, (int const   )offset, fit, ft, *fi,
                  (gboolean const   )first_frag, (guint32 const   )count, tvb);

    first_frag = 0;

    fd = fd->next;

  }





  if (fit->hf_fragment_count) {


    tmp = proto_tree_add_uint(ft, *(fit->hf_fragment_count), tvb, 0, 0, count);


    fli = tmp;


    while (1) {

      if (fli) {

        while (1) {

          if (fli->finfo) {
            (fli->finfo)->flags |= 2U;

          } else {

          }

          break;
        }

      } else {

      }

      break;
    }

  } else {

  }


  if (fit->hf_reassembled_length) {


    tmp___0 = tvb_length((tvbuff_t const   *)tvb);




    tmp___1 = proto_tree_add_uint(ft, *(fit->hf_reassembled_length), tvb, 0, 0,
                                  tmp___0);


    fli___0 = tmp___1;


    while (1) {

      if (fli___0) {

        while (1) {

          if (fli___0->finfo) {
            (fli___0->finfo)->flags |= 2U;

          } else {

          }

          break;
        }

      } else {

      }

      break;
    }

  } else {

  }



  tmp___2 = show_fragment_errs_in_col(fd_head, fit, pinfo);



  return (tmp___2);
}
}
