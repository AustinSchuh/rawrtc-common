#pragma once
#include "code.h"

#include <re.h>

/// Array container.
struct rawrtc_array_container {
    size_t n_items;
    void* items[];
};

/// Translate a rawrtc return code to a string.
char const * rawrtc_code_to_str(
    enum rawrtc_code const code
);

/// Translate an re error to a rawrtc code.
enum rawrtc_code rawrtc_error_to_code(
    const int code
);

/// Duplicate a string.
/// `*destinationp` will be set to a copy of `source` and must be
/// unreferenced.
enum rawrtc_code rawrtc_strdup(
    char** const destinationp, // de-referenced
    char const * const source
);

/// Print a formatted string to a buffer.
enum rawrtc_code rawrtc_snprintf(
    char* const destinationp, // de-referenced
    size_t const size,
    char* const formatter,
    ...
);

/// Print a formatted string to a dynamically allocated buffer.
/// `*destinationp` must be unreferenced.
enum rawrtc_code rawrtc_sdprintf(
    char** const destinationp,
    char* const formatter,
    ...
);
