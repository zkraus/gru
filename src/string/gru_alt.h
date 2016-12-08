/**
 Copyright 2016 Otavio Rodolfo Piske
 
 Licensed under the Apache License, Version 2.0 (the "License");
 you may not use this file except in compliance with the License.
 You may obtain a copy of the License at
 
 http://www.apache.org/licenses/LICENSE-2.0
 
 Unless required by applicable law or agreed to in writing, software
 distributed under the License is distributed on an "AS IS" BASIS,
 WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 See the License for the specific language governing permissions and
 limitations under the License.
 */
#ifndef GRU_ALT_H
#define GRU_ALT_H

#include <string.h>

#include "common/gru_base.h"

/**
 * @brief Very simple alternatives to some safer string variables. Do not use unless 
 * libbsd or other more mature alternatives are not available
 */

#ifdef __cplusplus
extern "C" {
#endif

/**
 * Poor man's implementation of strlcpy (works just like strncpy, but copies size - 1)
 * @param dst destination buffer
 * @param src source buffer
 * @param size amount of bytes to copy
 * @return The amount of bytes copied
 */

#ifndef HAVE_STRLCPY

#if !defined(_WIN32) && !defined(_WIN64)
 size_t strlcpy(char * restrict dst, const char * restrict src, size_t size);
#else
 size_t strlcpy(char * dst, const char * src, size_t size);
#endif // !defined(_WIN32) && !defined(_WIN64)

#endif // HAVE_STRLCPY

#ifdef __cplusplus
}
#endif

#endif /* GRU_ALT_H */
