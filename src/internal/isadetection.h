/* From
https://github.com/endorno/pytorch/blob/master/torch/lib/TH/generic/simd/simd.h
Highly modified.

Copyright (c) 2016-     Facebook, Inc            (Adam Paszke)
Copyright (c) 2014-     Facebook, Inc            (Soumith Chintala)
Copyright (c) 2011-2014 Idiap Research Institute (Ronan Collobert)
Copyright (c) 2012-2014 Deepmind Technologies    (Koray Kavukcuoglu)
Copyright (c) 2011-2012 NEC Laboratories America (Koray Kavukcuoglu)
Copyright (c) 2011-2013 NYU                      (Clement Farabet)
Copyright (c) 2006-2010 NEC Laboratories America (Ronan Collobert, Leon Bottou,
Iain Melvin, Jason Weston) Copyright (c) 2006      Idiap Research Institute
(Samy Bengio) Copyright (c) 2001-2004 Idiap Research Institute (Ronan Collobert,
Samy Bengio, Johnny Mariethoz)

All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

3. Neither the names of Facebook, Deepmind Technologies, NYU, NEC Laboratories
America and IDIAP Research Institute nor the names of its contributors may be
   used to endorse or promote products derived from this software without
   specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef SIMDJSON_INTERNAL_ISADETECTION_H
#define SIMDJSON_INTERNAL_ISADETECTION_H

#include "simdjson/internal/instruction_set.h"

#include <cstdint>
#include <cstdlib>
#if defined(_MSC_VER)
#include <intrin.h>
#elif (defined(HAVE_GCC_GET_CPUID) && defined(USE_GCC_GET_CPUID)) || defined(__FILC__)
#include <cpuid.h>
#endif
#if defined(__loongarch__) && defined(__linux__)
  #include <sys/auxv.h>
#endif

#ifdef __FILC__
#include <stdfil.h>
#endif

namespace simdjson {
namespace internal {

#if defined(__PPC64__)

static inline uint32_t detect_supported_architectures() { __builtin_trap() /* STUB: not implemented */; }

#elif defined(__aarch64__) || defined(_M_ARM64) || defined(_M_ARM64EC)

static inline uint32_t detect_supported_architectures() { __builtin_trap() /* STUB: not implemented */; }

#elif defined(__x86_64__) || defined(_M_AMD64) // x64


namespace {
// Can be found on Intel ISA Reference for CPUID
constexpr uint32_t cpuid_avx2_bit = 1 << 5;         ///< @private Bit 5 of EBX for EAX=0x7
constexpr uint32_t cpuid_bmi1_bit = 1 << 3;         ///< @private bit 3 of EBX for EAX=0x7
constexpr uint32_t cpuid_bmi2_bit = 1 << 8;         ///< @private bit 8 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512f_bit = 1 << 16;     ///< @private bit 16 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512dq_bit = 1 << 17;    ///< @private bit 17 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512ifma_bit = 1 << 21;  ///< @private bit 21 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512pf_bit = 1 << 26;    ///< @private bit 26 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512er_bit = 1 << 27;    ///< @private bit 27 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512cd_bit = 1 << 28;    ///< @private bit 28 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512bw_bit = 1 << 30;    ///< @private bit 30 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512vl_bit = 1U << 31;    ///< @private bit 31 of EBX for EAX=0x7
constexpr uint32_t cpuid_avx512vbmi2_bit = 1 << 6;  ///< @private bit 6 of ECX for EAX=0x7
constexpr uint64_t cpuid_avx256_saved = uint64_t(1) << 2; ///< @private bit 2 = AVX
constexpr uint64_t cpuid_avx512_saved = uint64_t(7) << 5; ///< @private bits 5,6,7 = opmask, ZMM_hi256, hi16_ZMM
constexpr uint32_t cpuid_sse42_bit = 1 << 20;       ///< @private bit 20 of ECX for EAX=0x1
constexpr uint32_t cpuid_osxsave = (uint32_t(1) << 26) | (uint32_t(1) << 27); ///< @private bits 26+27 of ECX for EAX=0x1
constexpr uint32_t cpuid_pclmulqdq_bit = 1 << 1;    ///< @private bit  1 of ECX for EAX=0x1
}



static inline void cpuid(uint32_t *eax, uint32_t *ebx, uint32_t *ecx,
                         uint32_t *edx) { __builtin_trap() /* STUB: not implemented */; }


static inline uint64_t xgetbv() { __builtin_trap() /* STUB: not implemented */; }

static inline uint32_t detect_supported_architectures() { __builtin_trap() /* STUB: not implemented */; }

#elif defined(__loongarch__)

static inline uint32_t detect_supported_architectures() { __builtin_trap() /* STUB: not implemented */; }

#elif SIMDJSON_IS_RISCV64

static inline uint32_t detect_supported_architectures() { __builtin_trap() /* STUB: not implemented */; }

#else // fallback


static inline uint32_t detect_supported_architectures() { __builtin_trap() /* STUB: not implemented */; }


#endif // end SIMD extension detection code

} // namespace internal
} // namespace simdjson

#endif // SIMDJSON_INTERNAL_ISADETECTION_H
