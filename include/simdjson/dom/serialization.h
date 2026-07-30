#ifndef SIMDJSON_SERIALIZATION_H
#define SIMDJSON_SERIALIZATION_H

#include "simdjson/dom/base.h"
#include "simdjson/dom/element.h"
#include "simdjson/dom/object.h"

namespace simdjson {

/**
 * The string_builder template and mini_formatter class
 * are not part of  our public API and are subject to change
 * at any time!
 */
namespace internal {

template <class formatter> class base_formatter {
public:
  /** Add a comma **/
  simdjson_inline void comma();
  /** Start an array, prints [ **/
  simdjson_inline void start_array();
  /** End an array, prints ] **/
  simdjson_inline void end_array();
  /** Start an array, prints { **/
  simdjson_inline void start_object();
  /** Start an array, prints } **/
  simdjson_inline void end_object();
  /** Prints a true **/
  simdjson_inline void true_atom();
  /** Prints a false **/
  simdjson_inline void false_atom();
  /** Prints a null **/
  simdjson_inline void null_atom();
  /** Prints a number **/
  simdjson_inline void number(int64_t x);
  /** Prints a number **/
  simdjson_inline void number(uint64_t x);
  /** Prints a number **/
  simdjson_inline void number(double x);
  /** Prints a key (string + colon) **/
  simdjson_inline void key(std::string_view unescaped);
  /** Prints a string. The string is escaped as needed. **/
  simdjson_inline void string(std::string_view unescaped);
  /** Clears out the content. **/
  simdjson_inline void clear();
  /**
   * Get access to the buffer, it is owned by the instance, but
   * the user can make a copy.
   **/
  simdjson_inline std::string_view str() const;

  /** Prints one character **/
  simdjson_inline void one_char(char c);

  /** Prints characters in [begin, end) verbatim. **/
  simdjson_inline void chars(const char *begin, const char *end);

  simdjson_inline void call_print_newline() { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline void call_print_indents(size_t depth) { __builtin_trap() /* STUB: not implemented */; }

  simdjson_inline void call_print_space() { __builtin_trap() /* STUB: not implemented */; }

protected:
  // implementation details (subject to change)
  /** Backing buffer **/
  struct vector_with_small_buffer {
    vector_with_small_buffer() = default;
    ~vector_with_small_buffer() { __builtin_trap() /* STUB: not implemented */; }

    vector_with_small_buffer(const vector_with_small_buffer &) = delete;
    vector_with_small_buffer &
    operator=(const vector_with_small_buffer &) = delete;

    void clear() { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline void push_back(char c) { __builtin_trap() /* STUB: not implemented */; }

    simdjson_inline void append(const char *begin, const char *end) { __builtin_trap() /* STUB: not implemented */; }

    std::string_view str() const { __builtin_trap() /* STUB: not implemented */; }

  private:
    void free_buffer() { __builtin_trap() /* STUB: not implemented */; }
    void grow(size_t new_capacity) { __builtin_trap() /* STUB: not implemented */; }

    static const size_t StaticCapacity = 64;
    char array[StaticCapacity];
    char *buffer = array;
    size_t size = 0;
    size_t capacity = StaticCapacity;
  } buffer{};
};

/**
 * @private This is the class that we expect to use with the string_builder
 * template. It tries to produce a compact version of the JSON element
 * as quickly as possible.
 */
class mini_formatter : public base_formatter<mini_formatter> {
public:
  simdjson_inline void print_newline();

  simdjson_inline void print_indents(size_t depth);

  simdjson_inline void print_space();
};

class pretty_formatter : public base_formatter<pretty_formatter> {
public:
  simdjson_inline void print_newline();

  simdjson_inline void print_indents(size_t depth);

  simdjson_inline void print_space();

protected:
  int indent_step = 4;
};

/**
 * @private The string_builder template allows us to construct
 * a string from a document element. It is parametrized
 * by a "formatter" which handles the details. Thus
 * the string_builder template could support both minification
 * and prettification, and various other tradeoffs.
 *
 * This is not to be confused with the simdjson::builder::string_builder
 * which is a different class.
 */
template <class formatter = mini_formatter> class string_builder {
public:
  /** Construct an initially empty builder, would print the empty string **/
  string_builder() = default;
  /** Append an element to the builder (to be printed) **/
  inline void append(simdjson::dom::element value);
  /** Append an array to the builder (to be printed) **/
  inline void append(simdjson::dom::array value);
  /** Append an object to the builder (to be printed) **/
  inline void append(simdjson::dom::object value);
  /** Reset the builder (so that it would print the empty string) **/
  simdjson_inline void clear();
  /**
   * Get access to the string. The string_view is owned by the builder
   * and it is invalid to use it after the string_builder has been
   * destroyed.
   * However you can make a copy of the string_view on memory that you
   * own.
   */
  simdjson_inline std::string_view str() const;
  /** Append a key_value_pair to the builder (to be printed) **/
  simdjson_inline void append(simdjson::dom::key_value_pair value);

private:
  formatter format{};
};

} // namespace internal

namespace dom {

/**
 * Print JSON to an output stream.
 *
 * @param out The output stream.
 * @param value The element.
 * @throw if there is an error with the underlying output stream. simdjson
 * itself will not throw.
 */
inline std::ostream &operator<<(std::ostream &out,
                                simdjson::dom::element value);
#if SIMDJSON_EXCEPTIONS
inline std::ostream &
operator<<(std::ostream &out,
           simdjson::simdjson_result<simdjson::dom::element> x);
#endif
/**
 * Print JSON to an output stream.
 *
 * @param out The output stream.
 * @param value The array.
 * @throw if there is an error with the underlying output stream. simdjson
 * itself will not throw.
 */
inline std::ostream &operator<<(std::ostream &out, simdjson::dom::array value);
#if SIMDJSON_EXCEPTIONS
inline std::ostream &
operator<<(std::ostream &out,
           simdjson::simdjson_result<simdjson::dom::array> x);
#endif
/**
 * Print JSON to an output stream.
 *
 * @param out The output stream.
 * @param value The object.
 * @throw if there is an error with the underlying output stream. simdjson
 * itself will not throw.
 */
inline std::ostream &operator<<(std::ostream &out, simdjson::dom::object value);
#if SIMDJSON_EXCEPTIONS
inline std::ostream &
operator<<(std::ostream &out,
           simdjson::simdjson_result<simdjson::dom::object> x);
#endif
} // namespace dom

/**
 * Converts JSON to a string.
 *
 *   dom::parser parser;
 *   element doc = parser.parse("   [ 1 , 2 , 3 ] "_padded);
 *   cout << to_string(doc) << endl; // prints [1,2,3]
 *
 */
template <class T> std::string to_string(T x) { __builtin_trap() /* STUB: not implemented */; }
#if SIMDJSON_EXCEPTIONS
template <class T> std::string to_string(simdjson_result<T> x) { __builtin_trap() /* STUB: not implemented */; }
#endif

/**
 * Minifies a JSON element or document, printing the smallest possible valid
 * JSON.
 *
 *   dom::parser parser;
 *   element doc = parser.parse("   [ 1 , 2 , 3 ] "_padded);
 *   cout << minify(doc) << endl; // prints [1,2,3]
 *
 */
template <class T> std::string minify(T x) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS
template <class T> std::string minify(simdjson_result<T> x) { __builtin_trap() /* STUB: not implemented */; }
#endif

/**
 * Prettifies a JSON element or document, printing the valid JSON with
 * indentation.
 *
 *   dom::parser parser;
 *   element doc = parser.parse("   [ 1 , 2 , 3 ] "_padded);
 *
 *   // Prints:
 *   // {
 *   //     [
 *   //         1,
 *   //         2,
 *   //         3
 *   //     ]
 *   // }
 *   cout << prettify(doc) << endl;
 *
 */
template <class T> std::string prettify(T x) { __builtin_trap() /* STUB: not implemented */; }

#if SIMDJSON_EXCEPTIONS
template <class T> std::string prettify(simdjson_result<T> x) { __builtin_trap() /* STUB: not implemented */; }
#endif

} // namespace simdjson

#endif
