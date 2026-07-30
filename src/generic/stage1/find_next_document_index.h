#ifndef SIMDJSON_SRC_GENERIC_STAGE1_FIND_NEXT_DOCUMENT_INDEX_H

#ifndef SIMDJSON_CONDITIONAL_INCLUDE
#define SIMDJSON_SRC_GENERIC_STAGE1_FIND_NEXT_DOCUMENT_INDEX_H
#include <generic/stage1/base.h>
#include <simdjson/generic/dom_parser_implementation.h>
#endif // SIMDJSON_CONDITIONAL_INCLUDE

namespace simdjson {
namespace SIMDJSON_IMPLEMENTATION {
namespace {
namespace stage1 {

/**
  * This algorithm is used to quickly identify the last structural position that
  * makes up a complete document.
  *
  * It does this by going backwards and finding the last *document boundary* (a
  * place where one value follows another without a comma between them). If the
  * last document (the characters after the boundary) has an equal number of
  * start and end brackets, it is considered complete.
  *
  * Simply put, we iterate over the structural characters, starting from
  * the end. We consider that we found the end of a JSON document when the
  * first element of the pair is NOT one of these characters: '{' '[' ':' ','
  * and when the second element is NOT one of these characters: '}' ']' ':' ','.
  *
  * This simple comparison works most of the time, but it does not cover cases
  * where the batch's structural indexes contain a perfect amount of documents.
  * In such a case, we do not have access to the structural index which follows
  * the last document, therefore, we do not have access to the second element in
  * the pair, and that means we cannot identify the last document. To fix this
  * issue, we keep a count of the open and closed curly/square braces we found
  * while searching for the pair. When we find a pair AND the count of open and
  * closed curly/square braces is the same, we know that we just passed a
  * complete document, therefore the last json buffer location is the end of the
  * batch.
  */
simdjson_inline uint32_t find_next_document_index(dom_parser_implementation &parser) { __builtin_trap() /* STUB: not implemented */; }

/**
 * Sentinel value returned to indicate a document started but didn't fit
 * (CAPACITY error), as opposed to 0 which means no document content found
 * (EMPTY).
 */
constexpr uint32_t DOCUMENT_TOO_LARGE = UINT32_MAX;

/**
 * For RFC 7464 JSON text sequences, filter RS from structural indexes and
 * find batch boundaries.
 *
 * In JSON sequence mode, RS (0x1E) marks the start of each JSON text.
 * RS bytes appear in structural_indexes as they are classified as scalars.
 * This function:
 * 1. Scans structural_indexes to find and count RS positions
 * 2. Filters RS out of structural_indexes in-place
 * 3. Determines batch boundaries based on RS positions
 *
 * @param parser The parser with structural_indexes and buf.
 * @param len The length of the current batch buffer.
 * @param is_final True if this is the final batch (no more data coming).
 * @param next_batch_start Output: offset where the next batch should start.
 * @return The number of structural indexes to keep (after RS filtering),
 *         0 if no document content found (EMPTY),
 *         or DOCUMENT_TOO_LARGE if a document started but didn't fit (CAPACITY).
 */
simdjson_inline uint32_t find_next_document_index_json_sequence(
    dom_parser_implementation &parser,
    size_t len,
    bool is_final,
    uint32_t &next_batch_start) { __builtin_trap() /* STUB: not implemented */; }

/**
 * Filter comma-delimited documents by removing root-level commas from
 * structural indexes.
 *
 * For comma-delimited format like `{...},{...},{...}`, we need to remove
 * the commas that separate documents (depth 0) while preserving commas
 * inside arrays and objects (depth > 0).
 *
 * After filtering, the structural indexes look like whitespace-delimited
 * documents, so find_next_document_index() works unchanged.
 *
 * @param parser The parser with structural_indexes and buf.
 * @param len The length of the current batch buffer.
 * @param is_final True if this is the final batch (no more data coming).
 * @param next_batch_start Output: offset where the next batch should start.
 * @return The number of structural indexes to keep,
 *         0 if no document content found (EMPTY),
 *         or DOCUMENT_TOO_LARGE if a document started but didn't fit (CAPACITY).
 */
simdjson_inline uint32_t filter_comma_delimited(
    dom_parser_implementation &parser,
    size_t len,
    bool is_final,
    uint32_t &next_batch_start) { __builtin_trap() /* STUB: not implemented */; }

} // namespace stage1
} // unnamed namespace
} // namespace SIMDJSON_IMPLEMENTATION
} // namespace simdjson

#endif // SIMDJSON_SRC_GENERIC_STAGE1_FIND_NEXT_DOCUMENT_INDEX_H
