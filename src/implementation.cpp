#ifndef SIMDJSON_SRC_IMPLEMENTATION_CPP
#define SIMDJSON_SRC_IMPLEMENTATION_CPP

#include <base.h>
#include <simdjson/generic/dependencies.h>
#include <simdjson/implementation.h>
#include <internal/isadetection.h>

#include <initializer_list>
#include <type_traits>

namespace simdjson {

bool implementation::supported_by_runtime_system() const { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#define SIMDJSON_CONDITIONAL_INCLUDE

#if SIMDJSON_IMPLEMENTATION_ARM64
#include <simdjson/arm64/implementation.h>
namespace simdjson {
namespace internal {
static const arm64::implementation* get_arm64_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif // SIMDJSON_IMPLEMENTATION_ARM64

#if SIMDJSON_IMPLEMENTATION_FALLBACK
#include <simdjson/fallback/implementation.h>
namespace simdjson {
namespace internal {
static const fallback::implementation* get_fallback_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif // SIMDJSON_IMPLEMENTATION_FALLBACK


#if SIMDJSON_IMPLEMENTATION_HASWELL
#include <simdjson/haswell/implementation.h>
namespace simdjson {
namespace internal {
static const haswell::implementation* get_haswell_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif

#if SIMDJSON_IMPLEMENTATION_ICELAKE
#include <simdjson/icelake/implementation.h>
namespace simdjson {
namespace internal {
static const icelake::implementation* get_icelake_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif

#if SIMDJSON_IMPLEMENTATION_PPC64
#include <simdjson/ppc64/implementation.h>
namespace simdjson {
namespace internal {
static const ppc64::implementation* get_ppc64_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif // SIMDJSON_IMPLEMENTATION_PPC64

#if SIMDJSON_IMPLEMENTATION_WESTMERE
#include <simdjson/westmere/implementation.h>
namespace simdjson {
namespace internal {
static const simdjson::westmere::implementation* get_westmere_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif // SIMDJSON_IMPLEMENTATION_WESTMERE

#if SIMDJSON_IMPLEMENTATION_LASX
#include <simdjson/lasx/implementation.h>
namespace simdjson {
namespace internal {
static const simdjson::lasx::implementation* get_lasx_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif // SIMDJSON_IMPLEMENTATION_LASX

#if SIMDJSON_IMPLEMENTATION_LSX
#include <simdjson/lsx/implementation.h>
namespace simdjson {
namespace internal {
static const simdjson::lsx::implementation* get_lsx_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif // SIMDJSON_IMPLEMENTATION_LSX

#if SIMDJSON_IMPLEMENTATION_RVV_VLS
#include <simdjson/rvv-vls/implementation.h>
namespace simdjson {
namespace internal {
static const simdjson::rvv_vls::implementation* get_rvv_vls_singleton() { __builtin_trap() /* STUB: not implemented */; }
} // namespace internal
} // namespace simdjson
#endif // SIMDJSON_IMPLEMENTATION_RVV_VLS

#undef SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace internal {

// When there is a single implementation, we should not pay a price
// for dispatching to the best implementation. We should just use the
// one we have. This is a compile-time check.
#define SIMDJSON_SINGLE_IMPLEMENTATION (SIMDJSON_IMPLEMENTATION_ICELAKE \
             + SIMDJSON_IMPLEMENTATION_HASWELL + SIMDJSON_IMPLEMENTATION_WESTMERE \
             + SIMDJSON_IMPLEMENTATION_ARM64 + SIMDJSON_IMPLEMENTATION_PPC64 \
             + SIMDJSON_IMPLEMENTATION_LSX + SIMDJSON_IMPLEMENTATION_LASX \
             + SIMDJSON_IMPLEMENTATION_RVV_VLS + SIMDJSON_IMPLEMENTATION_FALLBACK == 1)

#if SIMDJSON_SINGLE_IMPLEMENTATION
  simdjson_really_inline static const implementation* get_single_implementation() { __builtin_trap() /* STUB: not implemented */; }
#endif

// Static array of known implementations. We're hoping these get baked into the executable
// without requiring a static initializer.

/**
 * @private Detects best supported implementation on first use, and sets it
 */
class detect_best_supported_implementation_on_first_use final : public implementation {
public:
  std::string name() const noexcept final { __builtin_trap() /* STUB: not implemented */; }
  std::string description() const noexcept final { __builtin_trap() /* STUB: not implemented */; }
  uint32_t required_instruction_sets() const noexcept final { __builtin_trap() /* STUB: not implemented */; }
  simdjson_warn_unused error_code create_dom_parser_implementation(
    size_t capacity,
    size_t max_length,
    std::unique_ptr<internal::dom_parser_implementation>& dst
  ) const noexcept final { __builtin_trap() /* STUB: not implemented */; }
  simdjson_warn_unused error_code minify(const uint8_t *buf, size_t len, uint8_t *dst, size_t &dst_len) const noexcept final { __builtin_trap() /* STUB: not implemented */; }
  simdjson_warn_unused bool validate_utf8(const char * buf, size_t len) const noexcept final override { __builtin_trap() /* STUB: not implemented */; }
  simdjson_inline detect_best_supported_implementation_on_first_use() noexcept : implementation("best_supported_detector", "Detects the best supported implementation and sets it", 0) { __builtin_trap() /* STUB: not implemented */; }
private:
  const implementation *set_best() const noexcept;
};

static_assert(std::is_trivially_destructible<detect_best_supported_implementation_on_first_use>::value, "detect_best_supported_implementation_on_first_use should be trivially destructible");

static const std::initializer_list<const implementation *>& get_available_implementation_pointers() { __builtin_trap() /* STUB: not implemented */; }

// So we can return UNSUPPORTED_ARCHITECTURE from the parser when there is no support
class unsupported_implementation final : public implementation {
public:
  simdjson_warn_unused error_code create_dom_parser_implementation(
    size_t,
    size_t,
    std::unique_ptr<internal::dom_parser_implementation>&
  ) const noexcept final { __builtin_trap() /* STUB: not implemented */; }
  simdjson_warn_unused error_code minify(const uint8_t *, size_t, uint8_t *, size_t &) const noexcept final override { __builtin_trap() /* STUB: not implemented */; }
  simdjson_warn_unused bool validate_utf8(const char *, size_t) const noexcept final override { __builtin_trap() /* STUB: not implemented */; }
  unsupported_implementation() : implementation("unsupported", "Unsupported CPU (no detected SIMD instructions)", 0) { __builtin_trap() /* STUB: not implemented */; }
};

static_assert(std::is_trivially_destructible<unsupported_implementation>::value, "unsupported_singleton should be trivially destructible");

const unsupported_implementation* get_unsupported_singleton() { __builtin_trap() /* STUB: not implemented */; }

size_t available_implementation_list::size() const noexcept { __builtin_trap() /* STUB: not implemented */; }
const implementation * const *available_implementation_list::begin() const noexcept { __builtin_trap() /* STUB: not implemented */; }
const implementation * const *available_implementation_list::end() const noexcept { __builtin_trap() /* STUB: not implemented */; }
const implementation *available_implementation_list::detect_best_supported() const noexcept { __builtin_trap() /* STUB: not implemented */; }

const implementation *detect_best_supported_implementation_on_first_use::set_best() const noexcept { __builtin_trap() /* STUB: not implemented */; }

} // namespace internal

SIMDJSON_DLLIMPORTEXPORT const internal::available_implementation_list& get_available_implementations() { __builtin_trap() /* STUB: not implemented */; }

SIMDJSON_DLLIMPORTEXPORT internal::atomic_ptr<const implementation>& get_active_implementation() { __builtin_trap() /* STUB: not implemented */; }

simdjson_warn_unused error_code minify(const char *buf, size_t len, char *dst, size_t &dst_len) noexcept { __builtin_trap() /* STUB: not implemented */; }
simdjson_warn_unused bool validate_utf8(const char *buf, size_t len) noexcept { __builtin_trap() /* STUB: not implemented */; }
const implementation * builtin_implementation() { __builtin_trap() /* STUB: not implemented */; }

} // namespace simdjson

#endif // SIMDJSON_SRC_IMPLEMENTATION_CPP
