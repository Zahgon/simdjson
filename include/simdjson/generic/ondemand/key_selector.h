#ifndef SIMDJSON_GENERIC_ONDEMAND_KEY_SELECTOR_H
#define SIMDJSON_GENERIC_ONDEMAND_KEY_SELECTOR_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#include "simdjson/base.h"
#include "simdjson/common_defs.h"
#include "simdjson/constevalutil.h"
#include "simdjson/generic/ondemand/raw_json_string.h"
#endif // SIMDJSON_CONDITIONAL_INCLUDE

#include <array>
#include <string>      // std::string (key_selector::describe)
#include <string_view>
#include <cstddef>
#include <cstdint>
#include <cstring>     // std::memcpy (portable unaligned window load)
#include <utility>     // std::index_sequence (window candidate dispatch)
#include <type_traits> // std::integral_constant (window candidate dispatch)

#if defined(__aarch64__) || defined(__ARM_NEON)
  #include <arm_neon.h>
  #define SIMDJSON_KEY_SELECTOR_HAS_NEON 1
#else
  #define SIMDJSON_KEY_SELECTOR_HAS_NEON 0
#endif
#if defined(__SSE2__)
  #include <emmintrin.h>
  #define SIMDJSON_KEY_SELECTOR_HAS_SSE2 1
#else
  #define SIMDJSON_KEY_SELECTOR_HAS_SSE2 0
#endif
#if defined(__loongarch_sx)
  #include <lsxintrin.h>
  #define SIMDJSON_KEY_SELECTOR_HAS_LSX 1
#else
  #define SIMDJSON_KEY_SELECTOR_HAS_LSX 0
#endif

#if SIMDJSON_SUPPORTS_CONCEPTS

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace ondemand {

namespace key_selector_detail {

// ============================================================================
// Compile-time perfect-hash generator.
// It scales to ~100 keys at compile time by determining association values one (position, character)
// symbol at a time (gperf-style) instead of an exhaustive offset search, and
// falls back to a Hash-and-Displace construction for large/awkward key sets.
//
// Only flat tables survive to runtime; the lookup is a few additions plus a
// single SIMD key comparison (see match_raw below).
// ============================================================================

// Maximum number of character positions the gperf hash may combine.
static constexpr std::size_t MAX_POSITIONS = 16;
// Sentinel "position" meaning "the last character of the key".
static constexpr std::size_t LAST_CHAR = std::size_t(-1);
// Runtime-encoded sentinels (stored in uint8 tables).
static constexpr std::uint8_t POS_LAST_CHAR = 0xFF; // positions_[i] == last char
static constexpr std::uint8_t HD_MODE       = 0xFF; // num_positions == H&D mode
// Flags stored in positions[2] in H&D mode to select the key-hash variant.
static constexpr std::size_t HD_HASH_2BYTE_FLAG = 2;
static constexpr std::size_t HD_HASH_4BYTE_FLAG = 4;

constexpr std::size_t next_power_of_2(std::size_t n) noexcept { return {}; }

// Character at a given position (LAST_CHAR means last character), or 256 if out
// of bounds.
constexpr std::size_t char_at(std::string_view key, std::size_t pos) noexcept { return {}; }

// Count key pairs that a set of positions fails to distinguish. Keys whose
// lengths differ modulo the table size are separated by the length term in the
// hash, so they need no position coverage.
template <std::size_t N>
consteval std::size_t count_undistinguished_pairs(
    const std::array<std::string_view, N>& keys,
    const std::size_t* positions,
    std::size_t num_positions,
    std::size_t modulus) { return {}; }

template <std::size_t N>
consteval bool positions_distinguish(
    const std::array<std::string_view, N>& keys,
    const std::size_t* positions,
    std::size_t num_positions,
    std::size_t modulus) { return {}; }

// Number of distinct (length % modulus, char_at(key, pos)) pairs at a position.
template <std::size_t N>
consteval std::size_t discriminating_power(
    const std::array<std::string_view, N>& keys,
    std::size_t pos,
    std::size_t modulus) { return {}; }

template <std::size_t N>
consteval std::size_t max_key_length(const std::array<std::string_view, N>& keys) { return {}; }

// Bounded backtracking DFS for a minimal set of distinguishing positions.
template <std::size_t N>
consteval bool backtracking_search(
    const std::array<std::string_view, N>& keys,
    const std::size_t* candidates,
    std::size_t num_candidates,
    std::size_t* positions,
    std::size_t& num_positions_out,
    std::size_t& budget,
    std::size_t modulus) { return {}; }

// Phase 1: select character positions that distinguish all colliding pairs.
template <std::size_t N>
consteval std::size_t select_positions(
    const std::array<std::string_view, N>& keys,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::size_t modulus) { return {}; }

// Result of PHF computation. A max-sized slot_to_key array lets the same struct
// type carry any chosen table size.
template <std::size_t N>
struct phf_result {
    // Allow up to 8x the minimum table size. Sparser tables solve faster.
    static constexpr std::size_t MAX_TABLE_SIZE = next_power_of_2(N) * 8;
    std::size_t table_size{};
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS> asso_values{};
    std::size_t num_positions{};
    std::array<std::size_t, MAX_POSITIONS> positions{};
    std::array<std::size_t, MAX_TABLE_SIZE> slot_to_key{};
};

// Partition-based asso_values search (gperf-style). Determines asso_values one
// (position, character) symbol at a time; never revisits a value. Equivalence
// classes (keys sharing the same undetermined symbols) keep the search cheap.
template <std::size_t N, std::size_t M>
consteval bool try_generate_gperf(
    const std::array<std::string_view, N>& keys,
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS>& asso_values,
    std::size_t& num_positions,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::array<std::size_t, M>& slot_to_key) { return {}; }

template <std::size_t N, std::size_t M>
consteval bool try_compute_phf(const std::array<std::string_view, N>& keys, phf_result<N>& result) { return {}; }

template <std::size_t N, std::size_t M, std::size_t MaxM>
consteval bool try_gperf_po2(const std::array<std::string_view, N>& keys, phf_result<N>& result) { return {}; }

// --- Hash-and-Displace fallback --------------------------------------------

constexpr std::size_t hd_bucket_hash(std::string_view key) noexcept { return {}; }
constexpr std::size_t hd_safe_char(const char* p, std::size_t len, std::size_t idx) noexcept { return {}; }
constexpr std::size_t hd_key_hash_2(std::string_view key) noexcept { return {}; }
constexpr std::size_t hd_key_hash_4(std::string_view key) noexcept { return {}; }

template <std::size_t N, std::size_t M>
consteval bool try_hash_and_displace(
    const std::array<std::string_view, N>& keys,
    std::array<std::array<std::size_t, 256>, MAX_POSITIONS>& asso_values,
    std::size_t& num_positions,
    std::array<std::size_t, MAX_POSITIONS>& positions,
    std::array<std::size_t, M>& slot_to_key) { return {}; }

template <std::size_t N, std::size_t M>
consteval bool try_compute_phf_hd(const std::array<std::string_view, N>& keys, phf_result<N>& result) { return {}; }

template <std::size_t N, std::size_t M>
consteval phf_result<N> compute_phf_hd_po2(const std::array<std::string_view, N>& keys) { return {}; }

// Compute a perfect hash for `keys`: try gperf at power-of-two sizes (capped so
// the runtime tables stay within uint8 indices), then fall back to H&D.
template <std::size_t N>
consteval phf_result<N> compute_phf(const std::array<std::string_view, N>& keys) { return {}; }

// ============================================================================
// Runtime tables (flat, uint8) derived from a phf_result.
// ============================================================================

template <std::size_t N, std::size_t TableSize, std::size_t MaxKeyLen>
struct phf_data {
    std::array<std::array<std::uint8_t, 256>, MAX_POSITIONS> asso_values{};
    std::array<std::uint8_t, MAX_POSITIONS>                  positions{};
    std::uint8_t                                             num_positions{};
    std::uint8_t                                             hd_hash_variant{}; // 2 or 4 (H&D only)
    std::array<std::uint8_t, TableSize>                      slot_to_key{};
    // slot_key_bytes[s] holds the key stored at slot s, zero-padded to a 16-byte
    // multiple so the SIMD comparison can read a whole register.
    std::array<std::array<char, ((MaxKeyLen + 15) / 16) * 16>, TableSize> slot_key_bytes{};
    std::array<std::uint8_t, TableSize>                      slot_key_len{};
};

template <std::size_t N>
constexpr std::size_t compute_max_key_len(const std::array<std::string_view, N>& keys) noexcept { return {}; }

// Validate keys and build the runtime tables from the computed perfect hash.
template <std::size_t N, std::size_t TableSize, std::size_t MaxKeyLen>
consteval phf_data<N, TableSize, MaxKeyLen>
build_phf_data(const std::array<std::string_view, N>& keys, const phf_result<N>& result) { return {}; }

// --- SIMD runtime primitives ------------------------------------------------

// The runtime matchers read whole 16-byte blocks up to offset 63 (four blocks)
// for keys as long as the 63-character maximum. That read must stay within the
// buffer's trailing padding, so the padding has to exceed the largest offset we
// touch.
static_assert(SIMDJSON_PADDING > 63,
              "key_selector requires SIMDJSON_PADDING > 63 for its SIMD key reads");

// Scan for the terminating '"' starting at p. Returns its byte offset (= key
// length). Caller guarantees SIMDJSON_PADDING (== 64) bytes past the JSON buffer,
// so reading whole 16-byte blocks up to offset 63 is always safe.
template <std::size_t MaxKeyLen>
simdjson_really_inline std::size_t scan_key_length(const char* p) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Byte-equal of p[0..len) against stored[0..len). stored is zero-padded past
// `len`. Input is read over 16, 32, 48, or 64 bytes (padded JSON buffer
// guaranteed; SIMDJSON_PADDING == 64).
template <std::size_t MaxKeyLen>
simdjson_really_inline bool compare_key_bytes(
    const char* p, const char* stored, std::size_t len) noexcept { __builtin_trap() /* STUB: not implemented */; }

// --- Single 8-bit window fast path ------------------------------------------
//
// Many small key sets can be told apart by inspecting a *single* 8-bit window of
// the key bytes -- and that window need not be byte-aligned. Because every JSON
// key is terminated by a '"', the bytes at and before a key's length are well
// defined for any key at least that long: byte i is the key character when i is
// inside the key and the closing quote when i == len. So we read two bytes at a
// fixed offset, extract 8 consecutive bits at a fixed intra-byte shift, and if
// that value is distinct for every key, a 256-entry table maps it straight to a
// candidate key. The match then needs no hash and -- in the length-free overload
// -- no SIMD length scan: load two bytes, shift, mask, index the table, and
// confirm the candidate with one comparison.
//
// Allowing an *unaligned* window (a shift of 1..7) mixes bits from two adjacent
// bytes and discriminates key sets that no single aligned byte can. For example,
// the partial_tweets keys {created_at,id,text,in_reply_to_status_id,user,
// retweet_count,favorite_count} share a colliding byte at every aligned position
// 0,1,2, yet the 8 bits starting at bit offset 2 are unique across all seven.
// Simpler cases fall out as the shift==0 special case: {"id","screen_name"}
// splits on byte 0, {"jo","joe"} on the quote at byte 2.
//
// The window is confined to the first (shortest key length + 1) bytes so the
// two-byte read never crosses a key's closing quote into uncontrolled value
// bytes; that final byte is the shortest key's quote.
template <std::size_t N, std::size_t MaxKeyLen>
struct window_data {
    static constexpr std::size_t KEY_STRIDE = ((MaxKeyLen + 15) / 16) * 16;
    bool                                            ok{false};
    std::uint8_t                                    byte_offset{0}; // first byte of the 2-byte read
    std::uint8_t                                    shift{0};       // intra-byte bit shift (0..7)
    std::array<std::uint8_t, 256>                   window_to_key{}; // window byte -> key index, N if none
    std::array<std::uint8_t, N>                     key_len{};
    std::array<std::array<char, KEY_STRIDE>, N>     key_bytes{};     // zero-padded
};

// Byte seen at `idx` for key `i`: a key character when idx is inside the key, or
// the closing '"' when idx == len (callers keep idx <= every key's length).
template <std::size_t N>
constexpr unsigned window_byte_at(const std::array<std::string_view, N>& keys,
                                  std::size_t i, std::size_t idx) noexcept { return {}; }

// The 8-bit window value for key `i` at (byte_offset, shift): the little-endian
// pair (byte[off], byte[off+1]) shifted right by `shift` and truncated. Matches
// the runtime read exactly.
template <std::size_t N>
constexpr unsigned window_value(const std::array<std::string_view, N>& keys,
                                std::size_t i, std::size_t byte_offset, std::size_t shift) noexcept { return {}; }

template <std::size_t N, std::size_t MaxKeyLen>
consteval window_data<N, MaxKeyLen>
compute_window(const std::array<std::string_view, N>& keys) { return {}; }

// Read the 8-bit window at (byte_offset, shift) from a padded key pointer.
simdjson_really_inline std::uint8_t read_window(const char* p, std::size_t byte_offset,
                                                std::size_t shift) noexcept { __builtin_trap() /* STUB: not implemented */; }

// Verify a window candidate. The window table already mapped the key to the
// single possible index `ki` (< N); here we confirm it. Folding over 0..N-1
// turns the runtime `ki` into a compile-time index in the matching arm, so the
// candidate's length and bytes are constants for compare_key_bytes -- the same
// specialization the ordered find_field path gets from a CT-length
// unsafe_is_equal, and what keeps this path competitive. The closing-quote check
// (p[L] == '"') both confirms the key ends exactly at the candidate's length and
// rejects a wrong-length key, so this works whether or not the caller knew len.
template <std::size_t N, std::size_t MaxKeyLen, std::size_t... Is>
simdjson_really_inline std::size_t
match_window_candidate(const char* p, std::uint8_t ki,
                       const window_data<N, MaxKeyLen>& w,
                       std::index_sequence<Is...>) noexcept { __builtin_trap() /* STUB: not implemented */; }

// --- describe() string helpers (constexpr; no std::to_string, which is not) ---

// Append the decimal form of v to s.
constexpr void append_uint(std::string& s, std::size_t v) { }

// Append a byte as its decimal value, plus the printable character in quotes
// when it is in the printable ASCII range (e.g. "110 ('n')").
constexpr void append_byte(std::string& s, unsigned b) { }

} // namespace key_selector_detail

/**
 * Stateless, compile-time key selector.
 *
 * Usage:
 *   using sel_t = key_selector<"id", "text", "user">;
 *   std::size_t i = sel_t::match_raw(raw_key); // returns sel_t::size() on miss
 *
 * The perfect hash is built at compile time (gperf-style, with a
 * Hash-and-Displace fallback) and only flat tables survive to runtime. All
 * tables are static constexpr, so the lookup fully inlines.
 *
 * Limitations:
 *   - Each key must be at most 63 characters long (and no longer than
 *     SIMDJSON_PADDING). Longer keys trigger a compile-time error.
 *   - The number of keys should be moderate. The hard limit is 255 keys;
 *     compilation time grows with the number of keys, so prefer a few dozen at
 *     most per selector.
 *   - Keys must be distinct, non-empty, and free of backslash, double-quote and
 *     null bytes (matching is done against the raw, unescaped JSON key bytes).
 */
template <constevalutil::fixed_string... Keys>
struct key_selector {
    static constexpr std::size_t N = sizeof...(Keys);
    static_assert(N > 0,   "key_selector requires at least one key");
    static_assert(N <= 255,"key_selector supports at most 255 keys");

    static constexpr std::array<std::string_view, N> keys{ Keys.view()... };
    static constexpr std::size_t max_key_len = key_selector_detail::compute_max_key_len<N>(keys);
    static_assert(max_key_len <= SIMDJSON_PADDING,
                  "key longer than SIMDJSON_PADDING is not supported");
    // The SIMD key-length scan covers offsets 0..63 (four 16-byte blocks), which
    // stays within the 64-byte padding guarantee. A 64-character key's closing
    // quote would land at offset 64 and be missed on NEON/SSE2/LSX while still
    // matching in scalar builds, so cap at 63 to keep implementations in agreement.
    static_assert(max_key_len <= 63,
                  "key_selector keys must be at most 63 characters long");

    static constexpr auto result = key_selector_detail::compute_phf<N>(keys);
    static constexpr std::size_t table_size = result.table_size;

    static constexpr auto phf =
        key_selector_detail::build_phf_data<N, table_size, max_key_len>(keys, result);

    // Single 8-bit-window discriminator (when one exists). Detected at compile
    // time and selected with `if constexpr` below, so the hash path is compiled
    // out for key sets that qualify, and this is compiled out for those that do
    // not.
    static constexpr auto window =
        key_selector_detail::compute_window<N, max_key_len>(keys);

    static constexpr std::size_t size() noexcept { return {}; }

    /**
     * Look up a JSON key whose length is already known. p must point at the first
     * key byte (just after the opening quote) in a padded simdjson buffer, and len
     * must be the number of raw key bytes (the distance to the closing quote).
     * Returns the selector index in [0, N) on match, or N on miss.
     *
     * Prefer this overload when the caller can obtain the key length cheaply (for
     * example, object::for_each derives it from the structural index rather than
     * re-scanning for the closing quote).
     */
    static simdjson_really_inline std::size_t match_raw(const char* p, std::size_t len) noexcept {
        if (len == 0 || len > max_key_len) { return N; }

        if constexpr (window.ok) {
            // One 8-bit window selects the only possible candidate key;
            // match_window_candidate confirms it (bytes + closing quote). p sits
            // in a padded buffer and the window stays within the shortest key +
            // quote, so the two-byte read is always in bounds. len is unused here
            // because the quote check already pins the key's end.
            std::uint8_t ki = window.window_to_key[
                key_selector_detail::read_window(p, window.byte_offset, window.shift)];
            if (ki >= N) { return N; }
            return key_selector_detail::match_window_candidate(
                p, ki, window, std::make_index_sequence<N>{});
        }

        std::size_t slot;
        if (phf.num_positions == key_selector_detail::HD_MODE) {
            // Hash-and-Displace: bucket displacement + per-key hash.
            std::string_view key(p, len);
            std::size_t bucket = key_selector_detail::hd_bucket_hash(key);
            std::size_t kh = (phf.hd_hash_variant == key_selector_detail::HD_HASH_2BYTE_FLAG)
                ? key_selector_detail::hd_key_hash_2(key)
                : key_selector_detail::hd_key_hash_4(key);
            slot = (phf.asso_values[0][bucket] + kh) & (table_size - 1);
        } else {
            // gperf: h = len + sum of asso_values over the selected positions.
            // positions / num_positions / asso_values are compile-time constants,
            // so this loop fully unrolls. The idx < len guard mirrors the
            // generator's char_at()-> 256 -> skip behavior for out-of-range
            // positions (required: arbitrary positions may exceed a key's length).
            std::size_t h = len;
            for (std::uint8_t i = 0; i < phf.num_positions; ++i) {
                std::uint8_t pos = phf.positions[i];
                std::size_t idx = (pos == key_selector_detail::POS_LAST_CHAR)
                                  ? (len - std::size_t{1})
                                  : static_cast<std::size_t>(pos);
                if (idx < len) {
                    h += phf.asso_values[i][static_cast<unsigned char>(p[idx])];
                }
            }
            slot = h & (table_size - 1);
        }

        std::uint8_t ki = phf.slot_to_key[slot];
        if (ki >= N) { return N; }
        if (phf.slot_key_len[slot] != len) { return N; }
        if (!key_selector_detail::compare_key_bytes<max_key_len>(
                p, phf.slot_key_bytes[slot].data(), len)) { return N; }
        return ki;
    }

    /**
     * Look up a JSON key. rjs must point just after an opening quote in a padded
     * simdjson buffer. Returns the selector index in [0, N) on match, or N on miss.
     * The key length is recovered with a SIMD scan for the closing quote; callers
     * that already know the length should use the (p, len) overload above.
     */
    static simdjson_really_inline std::size_t match_raw(raw_json_string rjs) noexcept { __builtin_trap() /* STUB: not implemented */; }

    /** Return the key text at selector index i (i in [0, N)). */
    static constexpr std::string_view key_at(std::size_t i) noexcept { return {}; }

    /**
     * Return a complete, human-readable, multi-line description of how this
     * selector classifies a key: which algorithm was selected at compile time
     * (single 8-bit window, gperf-style perfect hash, or hash-and-displace), the
     * exact bytes/positions it inspects, and the contents of the lookup tables
     * (which window bytes or hash slots map to which key). The text mirrors what
     * match_raw() does step by step.
     *
     * Everything it reports is derived from the compile-time tables, so describe()
     * is itself usable in a constant expression:
     *
     *   static_assert(!key_selector<"name", "city">::describe().empty());
     *
     * It allocates a std::string and is meant for documentation, debugging and
     * tests, not for any hot path.
     */
    static constexpr std::string describe() { return {}; }
};

namespace key_selector_detail {
template <typename> struct is_key_selector : std::false_type {};
template <constevalutil::fixed_string... Keys>
struct is_key_selector<key_selector<Keys...>> : std::true_type {};
} // namespace key_selector_detail

/**
 * Matches any instantiation of key_selector<Keys...>. Used to constrain
 * object::for_each so that passing a non-selector type yields a clear
 * constraint error rather than a cascade of failures inside for_each.
 */
template <typename T>
concept key_selector_type = key_selector_detail::is_key_selector<T>::value;

} // namespace ondemand
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SUPPORTS_CONCEPTS

#endif // SIMDJSON_GENERIC_ONDEMAND_KEY_SELECTOR_H
